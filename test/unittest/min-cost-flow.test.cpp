#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// MinCostFlow を、Bellman-Ford 法で 1 ずつ流す愚直な方法と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/min-cost-flow.hpp"

#include <iostream>
#include <random>
#include <tuple>
#include <vector>

// Bellman-Ford 法で 1 ずつ流す愚直な最小費用流
struct Naive {
    struct E {
        int to, rev, cap, cost;
    };
    int n;
    std::vector<std::vector<E>> g;
    Naive(int n, const std::vector<std::tuple<int, int, int, int>>& es) : n(n), g(n) {
        for (auto [u, v, c, d] : es) {
            int a = g[u].size(), b = g[v].size() + (u == v);
            g[u].push_back({v, b, c, d});
            g[v].push_back({u, a, 0, -d});
        }
    }
    // 流量 k = 0, 1, ... ごとの最小コスト (今の流れからの増分)
    std::vector<long long> flow(int s, int t) {
        std::vector<long long> res = {0};
        const long long INF = 1LL << 60;
        while (true) {
            std::vector<long long> dist(n, INF);
            std::vector<int> pv(n, -1), pe(n, -1);
            dist[s] = 0;
            for (int it = 0; it < n; it++) {
                for (int v = 0; v < n; v++) {
                    if (dist[v] == INF) continue;
                    for (int i = 0; i < static_cast<int>(g[v].size()); i++) {
                        auto& e = g[v][i];
                        if (e.cap > 0 && dist[v] + e.cost < dist[e.to]) {
                            dist[e.to] = dist[v] + e.cost;
                            pv[e.to] = v;
                            pe[e.to] = i;
                        }
                    }
                }
            }
            if (dist[t] == INF) break;
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap--;
                g[v][e.rev].cap++;
            }
            res.push_back(res.back() + dist[t]);
        }
        return res;
    }
};

// 折れ線 sl が、流量ごとの最小コスト expected[base + k] - expected[base] と一致し、傾きが真に増加するか
bool check_slope(const std::vector<std::pair<int, long long>>& sl, const std::vector<long long>& expected, int base) {
    if (sl.empty() || sl[0] != std::make_pair(0, 0LL)) return false;
    for (int i = 0; i + 1 < static_cast<int>(sl.size()); i++) {
        auto [f0, c0] = sl[i];
        auto [f1, c1] = sl[i + 1];
        if (f0 >= f1 || base + f1 >= static_cast<int>(expected.size())) return false;
        for (int k = f0; k <= f1; k++) {
            // 頂点の間は線形
            long long num = static_cast<long long>(k - f0) * (c1 - c0);
            if (num % (f1 - f0) != 0 || c0 + num / (f1 - f0) != expected[base + k] - expected[base]) return false;
        }
        if (i + 2 < static_cast<int>(sl.size())) {
            auto [f2, c2] = sl[i + 2];
            if ((c1 - c0) * (f2 - f1) >= (c2 - c1) * (f1 - f0)) return false;
        }
    }
    return true;
}

int main() {
    std::mt19937 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 6 + 2, m = rng() % 13;
        int s = rng() % n, t = rng() % (n - 1);
        if (t >= s) t++;
        std::vector<std::tuple<int, int, int, int>> es;
        MinCostFlow<int, long long> mcf(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;  // 自己ループと多重辺も含む
            int c = rng() % 6, d = rng() % 10;
            es.emplace_back(u, v, c, d);
            if (mcf.add_edge(u, v, c, d) != i) ok = false;
        }
        Naive nv(n, es);
        std::vector<long long> expected = nv.flow(s, t);
        int max_flow = expected.size() - 1;

        // 上限つきで 2 回に分けて流す
        int limit = rng() % (max_flow + 1);
        auto sl1 = mcf.slope(s, t, limit);
        auto sl2 = mcf.slope(s, t);
        ok = ok && check_slope(sl1, expected, 0) && check_slope(sl2, expected, limit);
        if (sl1.back().first != limit || limit + sl2.back().first != max_flow) ok = false;

        // 各辺の流量が容量以下で、流量が保存され、コストの和が合う
        std::vector<long long> balance(n);
        long long total = 0;
        auto edges = mcf.edges();
        for (int i = 0; i < m; i++) {
            auto [u, v, c, d] = es[i];
            auto e = mcf.get_edge(i);
            if (e.from != u || e.to != v || e.cap != c || e.cost != d || e.flow < 0 || e.flow > c) ok = false;
            if (edges[i].flow != e.flow) ok = false;
            balance[u] -= e.flow;
            balance[v] += e.flow;
            total += static_cast<long long>(e.flow) * d;
        }
        for (int v = 0; v < n; v++) {
            long long want = v == s ? -max_flow : v == t ? max_flow
                                                         : 0;
            if (balance[v] != want) ok = false;
        }
        if (total != expected[max_flow]) ok = false;
    }

    // 流した後で、別の s, t から続けて流す (コストが負の路を使うこともある)
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 6 + 2, m = rng() % 13;
        std::vector<std::tuple<int, int, int, int>> es;
        MinCostFlow<int, long long> mcf(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            int c = rng() % 6, d = rng() % 10;
            es.emplace_back(u, v, c, d);
            mcf.add_edge(u, v, c, d);
        }
        Naive nv(n, es);
        for (int it = 0; it < 3 && ok; it++) {
            int s = rng() % n, t = rng() % (n - 1);
            if (t >= s) t++;
            auto sl = mcf.slope(s, t);
            auto expected = nv.flow(s, t);
            ok = ok && check_slope(sl, expected, 0) && sl.back().first == static_cast<int>(expected.size()) - 1;
        }
    }

    // 例
    MinCostFlow<int, int> mcf(4);
    mcf.add_edge(0, 1, 2, 1);
    mcf.add_edge(0, 2, 1, 2);
    mcf.add_edge(1, 2, 1, 1);
    mcf.add_edge(1, 3, 1, 3);
    mcf.add_edge(2, 3, 2, 1);
    ok = ok && mcf.slope(0, 3) == std::vector<std::pair<int, int>>{{0, 0}, {2, 6}, {3, 10}};

    if (ok)
        std::cout << "Hello World" << std::endl;
    else
        std::cerr << "failed" << std::endl;
}
