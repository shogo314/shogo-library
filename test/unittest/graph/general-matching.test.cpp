#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// general-matching.hpp の general_matching を、頂点集合の bit DP で求めた最大マッチングの大きさと比べる
// 自己ループ・多重辺を含むグラフで、返った辺が実際にマッチングになっているかも調べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/general-matching.hpp"

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;
    for (int rep = 0; rep < 3000 && ok; rep++) {
        int n = rng() % 12 + 1, m = rng() % (n * 2 + 1);
        Graph<int> g(n);
        std::vector<std::vector<bool>> adj(n, std::vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            g.add_edge(u, v);
            adj[u][v] = adj[v][u] = true;
        }
        // dp[S]: 頂点集合 S の中での最大マッチング。S の最小の頂点を使わないか、誰かと組ませる
        std::vector<int> dp(1 << n, 0);
        for (int S = 1; S < (1 << n); S++) {
            int v = __builtin_ctz(S);
            int T = S & ~(1 << v);
            dp[S] = dp[T];
            for (int u = v + 1; u < n; u++) {
                if ((T >> u & 1) && adj[v][u]) dp[S] = std::max(dp[S], dp[T & ~(1 << u)] + 1);
            }
        }
        auto matching = general_matching(g);
        if (static_cast<int>(matching.size()) != dp[(1 << n) - 1]) ok = false;
        std::vector<bool> used_vertex(n, false), used_edge(m, false);
        for (int i = 0; i < static_cast<int>(matching.size()); i++) {
            const auto& e = matching[i];
            if (e.src >= e.dst || e.id < 0 || e.id >= m || used_edge[e.id]) {
                ok = false;
                break;
            }
            if (i > 0 && matching[i - 1].src >= e.src) ok = false;
            if (used_vertex[e.src] || used_vertex[e.dst]) ok = false;
            used_vertex[e.src] = used_vertex[e.dst] = used_edge[e.id] = true;
            // 辺の番号が指す辺と端点が一致する
            bool found = false;
            for (const auto& f : g[e.src]) found |= f.id == e.id && f.dst == e.dst;
            if (!found) ok = false;
        }
    }
    if (ok) std::cout << "Hello World" << std::endl;
}
