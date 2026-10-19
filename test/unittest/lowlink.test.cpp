#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// LowLink を、頂点や辺を 1 つ取り除いて連結成分の数を数える愚直な実装とランダムに比べる
// 二重頂点連結成分は、単純閉路をすべて列挙して同じ閉路に乗る辺をまとめる愚直な実装と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/lowlink.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <set>
#include <vector>

#include "../../src/data_structures/unionfind.hpp"
#include "../../src/graph/heavy-light-decomposition.hpp"

// 頂点 skip_v と辺 skip_e を使わないときの連結成分の数 (skip_v 自身は数えない)
int count_components(int n, const std::vector<std::pair<int, int>>& es, int skip_v, int skip_e) {
    UnionFind uf(n);
    for (int i = 0; i < static_cast<int>(es.size()); i++) {
        if (i == skip_e) continue;
        auto [u, v] = es[i];
        if (u == skip_v || v == skip_v) continue;
        uf.merge(u, v);
    }
    int c = 0;
    for (int v = 0; v < n; v++) c += v != skip_v && uf.leader(v) == v;
    return c;
}

// 単純閉路をすべて列挙し、同じ閉路に乗る辺を同じ組にする (多重辺 2 本の閉路も数える)
// 自己ループ以外の辺の組分けを、辺ごとの代表の番号で返す (自己ループは -1)
std::vector<int> naive_edge_blocks(int n, const std::vector<std::pair<int, int>>& es) {
    int m = es.size();
    UnionFind uf(m);
    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        auto [u, v] = es[i];
        if (u == v) continue;
        adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);
    }
    // s を閉路の最小の頂点として、s から出て s に戻る道を探す
    for (int s = 0; s < n; s++) {
        std::vector<bool> used(n, false);
        std::vector<int> path;  // 通った辺
        std::function<void(int)> dfs = [&](int v) {
            for (auto [u, id] : adj[v]) {
                if (!path.empty() && id == path.back()) continue;
                if (u == s && !path.empty()) {
                    for (int e : path) uf.merge(e, id);
                    continue;
                }
                if (u < s || used[u]) continue;
                used[u] = true, path.push_back(id);
                dfs(u);
                used[u] = false, path.pop_back();
            }
        };
        used[s] = true;
        dfs(s);
    }
    std::vector<int> res(m);
    for (int i = 0; i < m; i++) res[i] = es[i].first == es[i].second ? -1 : uf.leader(i);
    return res;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 9 + 1, m = rng() % 14;
        Graph<int> g(n);
        std::vector<std::pair<int, int>> es;
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;  // 自己ループと多重辺も含む
            g.add_edge(u, v);
            es.emplace_back(u, v);
        }
        LowLink ll(g);
        int base = count_components(n, es, -1, -1);
        std::vector<long long> arts, bridges;
        for (int v = 0; v < n; v++) {
            // v を取り除いたとき、残りの頂点の連結成分が増えるか
            // (v がほかの頂点とつながっていなければ、v の分だけ 1 減るのが普通)
            bool isolated = true;
            for (auto [a, b] : es) isolated &= !((a == v || b == v) && a != b);
            bool art = count_components(n, es, v, -1) > base - (isolated ? 1 : 0);
            if (art) arts.push_back(v);
            if (ll.is_articulation_point(v) != art) ok = false;
        }
        for (int i = 0; i < m; i++) {
            bool br = count_components(n, es, -1, i) > base;
            if (br) bridges.push_back(i);
            if (ll.is_bridge(i) != br) ok = false;
        }
        if (ll.articulation_points() != arts || ll.bridges() != bridges) ok = false;

        // 二重辺連結成分: 橋をすべて取り除いたときの連結成分と一致する
        UnionFind uf(n);
        for (int i = 0; i < m; i++) {
            if (!ll.is_bridge(i)) uf.merge(es[i].first, es[i].second);
        }
        const auto& groups = ll.two_edge_connected_groups();
        int total = 0;
        for (int k = 0; k < static_cast<int>(groups.size()); k++) {
            total += groups[k].size();
            for (int v : groups[k]) {
                if (ll.two_edge_connected_group_id(v) != k || !uf.same(v, groups[k][0])) ok = false;
            }
        }
        int uf_groups = 0;
        for (int v = 0; v < n; v++) uf_groups += uf.leader(v) == v;
        if (total != n || static_cast<int>(groups.size()) != uf_groups) ok = false;

        // 二重頂点連結成分: 辺の組分けが愚直な実装と一致する
        std::vector<int> naive = naive_edge_blocks(n, es);
        const auto& bc = ll.two_vertex_connected_groups();
        const auto& bce = ll.two_vertex_connected_edge_groups();
        if (bc.size() != bce.size()) ok = false;
        for (int i = 0; i < m && ok; i++) {
            for (int j = 0; j < m; j++) {
                if (naive[i] == -1 || naive[j] == -1) continue;
                if ((naive[i] == naive[j]) != (ll.two_vertex_connected_group_id(i) == ll.two_vertex_connected_group_id(j))) ok = false;
            }
            if ((naive[i] == -1) != (ll.two_vertex_connected_group_id(i) == -1)) ok = false;
        }
        // 成分の頂点は辺の端点で、辺のない成分はほかの頂点とつながっていない 1 頂点
        std::vector<int> block_count(n, 0);
        for (int b = 0; b < static_cast<int>(bc.size()) && ok; b++) {
            std::set<long long> ends;
            for (long long id : bce[b]) {
                if (ll.two_vertex_connected_group_id(id) != b) ok = false;
                ends.insert(es[id].first), ends.insert(es[id].second);
            }
            std::set<long long> vs(bc[b].begin(), bc[b].end());
            if (vs.size() != bc[b].size()) ok = false;
            if (bce[b].empty()) {
                if (bc[b].size() != 1) ok = false;
            } else if (vs != ends) {
                ok = false;
            }
            for (long long v : bc[b]) block_count[v]++;
        }
        for (int v = 0; v < n; v++) {
            // 関節点はちょうど 2 つ以上の成分に入り、それ以外はちょうど 1 つ
            if ((block_count[v] >= 2) != ll.is_articulation_point(v) || block_count[v] == 0) ok = false;
        }
        // Block-Cut Tree は森で、元の頂点の次数は入っている成分の数
        Tree<int> t = ll.block_cut_tree();
        if (t.n != n + static_cast<long long>(bc.size())) ok = false;
        UnionFind tuf(t.n);
        for (long long v = 0; v < t.n; v++) {
            for (const auto& e : t[v]) {
                if (v < e.dst && !tuf.merge(v, e.dst)) ok = false;  // 閉路があれば木ではない
            }
        }
        for (int v = 0; v < n; v++) {
            if (static_cast<int>(t[v].size()) != block_count[v]) ok = false;
        }
    }

    // 連結なグラフで、u から v へのどの道も通る頂点 (u, v 以外) の個数は、
    // Block-Cut Tree 上の u と v を結ぶパスにある元の頂点の個数 (端を除く) と一致する。HL 分解に渡せることも確かめる
    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 9 + 1, m = n - 1 + rng() % 6;
        Graph<int> g(n);
        std::vector<std::pair<int, int>> es;
        for (int v = 1; v < n; v++) {
            int p = rng() % v;
            g.add_edge(p, v), es.emplace_back(p, v);
        }
        while (static_cast<int>(es.size()) < m) {
            int u = rng() % n, v = rng() % n;
            g.add_edge(u, v), es.emplace_back(u, v);
        }
        LowLink ll(g);
        HeavyLightDecomposition hld(ll.block_cut_tree());
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (u == v) continue;
                int must = 0;
                for (int x = 0; x < n; x++) {
                    if (x == u || x == v) continue;
                    UnionFind uf(n);
                    for (auto [a, b] : es) {
                        if (a != x && b != x) uf.merge(a, b);
                    }
                    must += !uf.same(u, v);
                }
                // パスは 元の頂点 - 成分 - 元の頂点 - ... と交互に並ぶ
                if (hld.dist(u, v) / 2 - 1 != must) ok = false;
            }
        }
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
