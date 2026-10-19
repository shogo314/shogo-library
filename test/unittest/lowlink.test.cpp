#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// LowLink を、頂点や辺を 1 つ取り除いて連結成分の数を数える愚直な実装とランダムに比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/lowlink.hpp"

#include <iostream>
#include <random>
#include <vector>

#include "../../src/data_structures/unionfind.hpp"

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
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
