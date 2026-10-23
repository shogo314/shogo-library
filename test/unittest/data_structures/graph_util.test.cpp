#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph_util.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/graph_util.hpp"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <tuple>
#include <vector>

#include "../../../src/data_structures/unionfind.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;

    // 無向グラフ: bipartite_coloring, is_bipartite, connected_components, is_connected, is_tree
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8 + 1;
        std::vector<std::pair<int, int>> edges;
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (rng() % 3 == 0) edges.emplace_back(u, v);
            }
        }
        Graph<int> graph(n);
        for (auto [u, v] : edges) graph.add_edge(u, v);

        // 二部グラフかどうかを全彩色で調べる
        bool bipartite = false;
        for (int mask = 0; mask < (1 << n); mask++) {
            bool good = true;
            for (auto [u, v] : edges) good &= ((mask >> u & 1) != (mask >> v & 1));
            bipartite |= good;
        }
        std::vector<int> color = bipartite_coloring(graph);
        if (bipartite != !color.empty() || bipartite != is_bipartite(graph)) ok = false;
        if (!color.empty()) {
            for (auto [u, v] : edges)
                if (color[u] == color[v]) ok = false;
        }

        // 連結成分を Union-Find 風に愚直に求める
        std::vector<int> label(n);
        std::iota(label.begin(), label.end(), 0);
        for (int t = 0; t < n; t++) {
            for (auto [u, v] : edges) label[u] = label[v] = std::min(label[u], label[v]);
        }
        auto groups = connected_components(graph);
        std::vector<int> seen(n);
        for (const auto& group : groups) {
            for (int v : group) {
                seen[v]++;
                if (label[v] != label[group[0]]) ok = false;
            }
        }
        int num_components = 0;
        for (int v = 0; v < n; v++) {
            if (seen[v] != 1) ok = false;
            if (label[v] == v) num_components++;
        }
        if (static_cast<int>(groups.size()) != num_components) ok = false;
        if (is_connected(graph) != (num_components == 1)) ok = false;
        if (is_tree(graph) != (num_components == 1 && static_cast<int>(edges.size()) == n - 1)) ok = false;
    }

    // 有向グラフ: topological_sort, has_cycle
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 8 + 1;
        Graph<int> graph(n);
        std::vector<std::pair<int, int>> edges;
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u != v && rng() % 4 == 0) {
                    graph.add_directed_edge(u, v);
                    edges.emplace_back(u, v);
                }
            }
        }
        // 閉路があるかを全順列で調べる (トポロジカル順序が存在しない ⇔ 閉路がある)
        std::vector<int> perm(n);
        std::iota(perm.begin(), perm.end(), 0);
        bool dag = false;
        do {
            std::vector<int> pos(n);
            for (int i = 0; i < n; i++) pos[perm[i]] = i;
            bool good = true;
            for (auto [u, v] : edges) good &= pos[u] < pos[v];
            dag |= good;
        } while (!dag && std::next_permutation(perm.begin(), perm.end()));
        if (has_cycle(graph) == dag) ok = false;
        // DAG でなければ途中まで: 閉路からたどり着ける頂点 (閉路上の頂点から到達できる頂点) 以外がちょうど並ぶ
        std::vector<long long> order = topological_sort(graph);
        std::vector<std::vector<bool>> reach(n, std::vector<bool>(n, false));
        for (auto [u, v] : edges) reach[u][v] = true;
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (reach[i][k] && reach[k][j]) reach[i][j] = true;
        std::vector<bool> tainted(n, false);
        for (int c = 0; c < n; c++) {
            if (!reach[c][c]) continue;
            for (int v = 0; v < n; v++)
                if (reach[c][v]) tainted[v] = true;
        }
        int expected = 0;
        for (int v = 0; v < n; v++) expected += !tainted[v];
        if (dag != (expected == n)) ok = false;
        if (static_cast<int>(order.size()) != expected) ok = false;
        std::vector<int> pos(n, -1);
        for (int i = 0; i < static_cast<int>(order.size()); i++) {
            if (tainted[order[i]] || pos[order[i]] != -1) ok = false;
            pos[order[i]] = i;
        }
        for (auto [u, v] : edges)
            if (pos[u] != -1 && pos[v] != -1 && !(pos[u] < pos[v])) ok = false;
    }

    {
        Graph<int> graph(0);
        if (!topological_sort(graph).empty() || has_cycle(graph)) ok = false;
    }

    // 有向グラフ: strongly_connected_components (自己ループ・多重辺を含む)
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 9 + 1;
        int m = rng() % 20;
        Graph<int> graph(n);
        std::vector<std::pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            graph.add_directed_edge(u, v);
            edges.emplace_back(u, v);
        }
        // 愚直: 到達可能性 (自分自身には常に到達できる)
        std::vector<std::vector<bool>> reach(n, std::vector<bool>(n));
        for (int s = 0; s < n; s++) {
            std::vector<int> stk = {s};
            reach[s][s] = true;
            while (!stk.empty()) {
                int u = stk.back();
                stk.pop_back();
                for (auto [a, b] : edges) {
                    if (a == u && !reach[s][b]) {
                        reach[s][b] = true;
                        stk.push_back(b);
                    }
                }
            }
        }
        std::vector<std::vector<long long>> groups = strongly_connected_components(graph);
        std::vector<int> id(n, -1);
        int total = 0;
        for (int i = 0; i < static_cast<int>(groups.size()); i++) {
            for (int v : groups[i]) {
                if (id[v] != -1) ok = false;  // 2 つの成分に入っている
                id[v] = i;
                total++;
            }
        }
        if (total != n) ok = false;
        // 同じ成分 ⇔ 互いに到達できる
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if ((id[u] == id[v]) != (reach[u][v] && reach[v][u])) ok = false;
            }
        }
        // 成分はトポロジカル順に並ぶ
        for (auto [u, v] : edges) {
            if (id[u] > id[v]) ok = false;
        }
    }

    // minimum_steiner_tree・minimum_steiner_tree_restore: 辺の部分集合を全探索する
    // 重み 0 の辺も混ぜる (復元で同じ辺を 2 回数えないか)
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 6 + 1;
        std::vector<std::tuple<int, int, int>> edges;
        // 連結にするため、まず全域木を作る
        for (int v = 1; v < n; v++) edges.emplace_back(rng() % v, v, rng() % 10);
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (rng() % 4 == 0) edges.emplace_back(u, v, rng() % 10);
            }
        }
        if (edges.size() > 12) edges.resize(12);
        Graph<int> graph(n);
        for (auto [u, v, w] : edges) graph.add_edge(u, v, w);
        std::vector<int> terminals;
        for (int v = 0; v < n; v++)
            if (rng() % 2) terminals.push_back(v);

        int best = -1;
        int m = edges.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            std::vector<int> label(n);
            std::iota(label.begin(), label.end(), 0);
            int cost = 0;
            for (int i = 0; i < m; i++)
                if (mask >> i & 1) cost += std::get<2>(edges[i]);
            for (int t = 0; t < n; t++) {
                for (int i = 0; i < m; i++) {
                    if (!(mask >> i & 1)) continue;
                    auto [u, v, w] = edges[i];
                    label[u] = label[v] = std::min(label[u], label[v]);
                }
            }
            bool connected = true;
            for (int v : terminals) connected &= label[v] == label[terminals[0]];
            if (connected && (best == -1 || cost < best)) best = cost;
        }
        if (terminals.empty()) best = 0;
        if (minimum_steiner_tree(graph, terminals) != best) ok = false;
        // 復元: 辺の番号が昇順で重複がなく、重みの和が最小で、terminals をつなぐ
        auto used = minimum_steiner_tree_restore(graph, terminals);
        if (!std::is_sorted(used.begin(), used.end()) || std::adjacent_find(used.begin(), used.end()) != used.end()) ok = false;
        int cost = 0;
        UnionFind uf(n);
        for (auto i : used) {
            auto [u, v, w] = edges[i];
            cost += w;
            uf.merge(u, v);
        }
        if (cost != best) ok = false;
        for (int v : terminals)
            if (!uf.same(v, terminals[0])) ok = false;
    }

    // maximum_independent_set: 頂点の部分集合を全探索する。自己ループ・多重辺も混ぜる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 11, m = n == 0 ? 0 : rng() % (2 * n + 1);
        Graph<int> graph(n);
        std::vector<int> adj(n, 0);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % (rng() % 8 == 0 ? n : n);
            if (rng() % 10 == 0) v = u;
            graph.add_edge(u, v);
            adj[u] |= 1 << v, adj[v] |= 1 << u;
        }
        auto independent = [&](int S) {
            for (int v = 0; v < n; v++)
                if ((S >> v & 1) && (adj[v] & S)) return false;
            return true;
        };
        int best = 0;
        for (int S = 0; S < (1 << n); S++)
            if (independent(S)) best = std::max(best, __builtin_popcount(S));
        auto res = maximum_independent_set(graph);
        int S = 0;
        for (auto v : res) S |= 1 << v;
        if (static_cast<int>(res.size()) != best || __builtin_popcount(S) != best || !independent(S) || !std::is_sorted(res.begin(), res.end())) ok = false;
    }

    // minimum_spanning_tree: 辺の部分集合をすべて試して最小のコストの全域森と比べる
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 6 + 1, m = rng() % 9;
        Graph<int> graph(n);
        for (int i = 0; i < m; i++) graph.add_edge(rng() % n, rng() % n, rng() % 10);
        auto es = graph.edges();
        auto comps = connected_components(graph);
        int need = n - static_cast<int>(comps.size());  // 全域森の辺の本数
        int best = -1;
        for (int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) != need) continue;
            UnionFind uf(n);
            bool forest = true;
            int cost = 0;
            for (int i = 0; i < m; i++) {
                if (!(mask >> i & 1)) continue;
                if (!uf.merge(es[i].src, es[i].dst)) forest = false;
                cost += es[i].cost;
            }
            if (forest && (best == -1 || cost < best)) best = cost;
        }
        auto mst = minimum_spanning_tree(graph);
        if (mst.cost != best || static_cast<int>(mst.edges.size()) != need) ok = false;
        UnionFind uf(n);
        int sum = 0;
        for (const auto& e : mst.edges) {
            if (!uf.merge(e.src, e.dst)) ok = false;
            sum += e.cost;
        }
        if (sum != mst.cost) ok = false;
    }

    // chromatic_number: 色の数 k を小さい順に、k 色での塗り方をすべて試して最初に塗れた k と比べる
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 8;
        Graph<int> g(n);
        std::vector<std::pair<int, int>> es;
        for (int u = 0; u < n; u++)
            for (int v = u + 1; v < n; v++)
                if (rng() % 3 == 0) g.add_edge(u, v), es.emplace_back(u, v);
        long long expect = 0;
        for (int k = n == 0 ? 0 : 1; k <= n && expect == 0 && n > 0; k++) {
            std::vector<int> c(n, 0);
            while (true) {
                bool good = true;
                for (auto [u, v] : es) good &= c[u] != c[v];
                if (good) {
                    expect = k;
                    break;
                }
                int i = 0;
                while (i < n && ++c[i] == k) c[i++] = 0;
                if (i == n) break;
            }
        }
        if (chromatic_number(g) != expect) ok = false, std::cerr << "chromatic_number" << std::endl;
    }
    {
        // 自己ループがあれば塗れない
        Graph<int> g(2);
        g.add_edge(0, 0);
        if (chromatic_number(g) != -1) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
