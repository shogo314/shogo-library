#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// MaxFlow を、頂点の分け方をすべて試して求めた最小カットと比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include <iostream>
#include <random>
#include <tuple>
#include <vector>

#include "../../src/graph/max-flow.hpp"

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 7 + 2, m = rng() % 15;
        int s = rng() % n, t = rng() % (n - 1);
        if (t >= s) t++;
        std::vector<std::tuple<int, int, long long>> es;
        MaxFlow<long long> mf(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;  // 自己ループと多重辺も含む
            long long c = rng() % 10;
            es.emplace_back(u, v, c);
            if (mf.add_edge(u, v, c) != i) ok = false;
        }
        // 最小カット: s を含み t を含まない頂点集合 S から出る辺の容量の和の最小値
        long long best = -1;
        for (int mask = 0; mask < (1 << n); mask++) {
            if (!(mask >> s & 1) || (mask >> t & 1)) continue;
            long long cut = 0;
            for (auto [u, v, c] : es) {
                if ((mask >> u & 1) && !(mask >> v & 1)) cut += c;
            }
            if (best == -1 || cut < best) best = cut;
        }
        // 上限つきで 2 回に分けて流しても、合計は同じ
        long long limit = rng() % (best + 1);
        long long f = mf.flow(s, t, limit);
        if (f != limit) ok = false;
        f += mf.flow(s, t);
        if (f != best) ok = false;

        // 各辺の流量が容量以下で、s と t 以外で流量が保存される
        std::vector<long long> balance(n);
        auto edges = mf.edges();
        for (int i = 0; i < m; i++) {
            auto [u, v, c] = es[i];
            auto e = mf.get_edge(i);
            if (e.from != u || e.to != v || e.cap != c || e.flow < 0 || e.flow > c) ok = false;
            if (edges[i].flow != e.flow) ok = false;
            balance[u] -= e.flow;
            balance[v] += e.flow;
        }
        for (int v = 0; v < n; v++) {
            if (v == s && balance[v] != -f) ok = false;
            if (v == t && balance[v] != f) ok = false;
            if (v != s && v != t && balance[v] != 0) ok = false;
        }
        // min_cut の頂点集合が最小カットになっている
        auto cut = mf.min_cut(s);
        long long cap = 0;
        for (auto [u, v, c] : es) {
            if (cut[u] && !cut[v]) cap += c;
        }
        if (!cut[s] || cut[t] || cap != f) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
    else std::cerr << "failed" << std::endl;
}
