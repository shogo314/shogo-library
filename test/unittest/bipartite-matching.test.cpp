#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// BipartiteMatching の大きさを MaxFlow と比べ、返すマッチングが正しいかを調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/bipartite-matching.hpp"

#include <iostream>
#include <random>
#include <set>
#include <utility>
#include <vector>

#include "../../src/graph/max-flow.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int l = rng() % 8 + 1, r = rng() % 8 + 1, m = rng() % 25;
        BipartiteMatching bm(l, r);
        MaxFlow<int> mf(l + r + 2);
        int s = l + r, t = l + r + 1;
        for (int u = 0; u < l; u++) mf.add_edge(s, u, 1);
        for (int v = 0; v < r; v++) mf.add_edge(l + v, t, 1);
        std::set<std::pair<int, int>> es;
        // 辺を半分ずつ追加し、途中でも solve を呼ぶ
        for (int i = 0; i < m; i++) {
            int u = rng() % l, v = rng() % r;
            bm.add_edge(u, v);
            mf.add_edge(u, l + v, 1);
            es.emplace(u, v);
            if (i == m / 2) bm.solve();
        }
        int k = bm.solve();
        if (k != mf.flow(s, t)) ok = false;
        auto match = bm.matching();
        if ((int)match.size() != k) ok = false;
        std::vector<bool> used_l(l), used_r(r);
        for (auto [u, v] : match) {
            if (!es.count({u, v}) || used_l[u] || used_r[v]) ok = false;
            used_l[u] = used_r[v] = true;
            if (bm.left_match(u) != v || bm.right_match(v) != u) ok = false;
        }
        for (int u = 0; u < l; u++) {
            if (!used_l[u] && bm.left_match(u) != -1) ok = false;
        }
        for (int v = 0; v < r; v++) {
            if (!used_r[v] && bm.right_match(v) != -1) ok = false;
        }
    }

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
