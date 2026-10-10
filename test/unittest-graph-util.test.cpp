#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph_util.hpp の関数を愚直な実装とランダムに比較する
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <tuple>
#include <vector>

#include "../graph/graph_util.hpp"

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
            for (auto [u, v] : edges) if (color[u] == color[v]) ok = false;
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
        if ((int)groups.size() != num_components) ok = false;
        if (is_connected(graph) != (num_components == 1)) ok = false;
        if (is_tree(graph) != (num_components == 1 && (int)edges.size() == n - 1)) ok = false;
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
        std::vector<int> order = topological_sort(graph);
        if (dag) {
            if ((int)order.size() != n) ok = false;
            else {
                std::vector<int> pos(n, -1);
                for (int i = 0; i < n; i++) pos[order[i]] = i;
                for (auto [u, v] : edges) if (!(pos[u] < pos[v])) ok = false;
            }
        } else if ((int)order.size() >= n) {
            ok = false;
        }
    }

    // minimum_steiner_tree: 辺の部分集合を全探索する
    for (int rep = 0; rep < 500 && ok; rep++) {
        int n = rng() % 6 + 1;
        std::vector<std::tuple<int, int, int>> edges;
        // 連結にするため、まず全域木を作る
        for (int v = 1; v < n; v++) edges.emplace_back(rng() % v, v, rng() % 10 + 1);
        for (int u = 0; u < n; u++) {
            for (int v = u + 1; v < n; v++) {
                if (rng() % 4 == 0) edges.emplace_back(u, v, rng() % 10 + 1);
            }
        }
        if (edges.size() > 12) edges.resize(12);
        Graph<int> graph(n);
        for (auto [u, v, w] : edges) graph.add_edge(u, v, w);
        std::vector<int> terminals;
        for (int v = 0; v < n; v++) if (rng() % 2) terminals.push_back(v);

        int best = -1;
        int m = edges.size();
        for (int mask = 0; mask < (1 << m); mask++) {
            std::vector<int> label(n);
            std::iota(label.begin(), label.end(), 0);
            int cost = 0;
            for (int i = 0; i < m; i++) if (mask >> i & 1) cost += std::get<2>(edges[i]);
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
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
