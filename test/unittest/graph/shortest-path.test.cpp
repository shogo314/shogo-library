#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// shortest-path.hpp の 01-BFS と Floyd-Warshall を、Dijkstra と Bellman-Ford の結果と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../../src/graph/shortest-path.hpp"

#include <iostream>
#include <limits>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    // shortest_path_01bfs: コスト 0 / 1 のグラフで Dijkstra と比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 10 + 1, m = rng() % 25;
        Graph<int> g(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n, w = rng() % 2;
            if (rng() % 2)
                g.add_edge(u, v, w);
            else
                g.add_directed_edge(u, v, w);
        }
        for (int s = 0; s < n; s++) {
            auto a = shortest_path_01bfs(g, s);
            auto b = shortest_path(g, s);
            if (a.dist != b.dist) ok = false;
            // prev をたどった経路の長さが dist と一致する
            for (int t = 0; t < n; t++) {
                // 未到達なら path は nullopt
                auto p = a.path(t);
                if (p.has_value() != (a.dist[t] != std::numeric_limits<int>::max() / 4)) ok = false;
                if (!p) continue;
                if (t == s && !p->empty()) ok = false;
                int len = 0;
                for (auto& e : *p) len += e.cost;
                if (len != a.dist[t]) ok = false;
            }
        }
    }

    // floyd_warshall: 負の辺を含む有向グラフで、各始点からの Bellman-Ford と比べる
    for (int rep = 0; rep < 2000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 20;
        Graph<long long> g(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            long long w = static_cast<long long>(rng() % 21) - 3;
            g.add_directed_edge(u, v, w);
        }
        const long long inf = std::numeric_limits<long long>::max() / 4;
        auto d = floyd_warshall(g);
        bool negative = false;
        for (int s = 0; s < n; s++) {
            auto b = bellman_ford(g, s);
            for (int t = 0; t < n; t++) negative |= b.dist[t] == -inf;
        }
        bool negative_fw = false;
        for (int i = 0; i < n; i++) negative_fw |= d[i][i] < 0;
        if (negative != negative_fw) ok = false;
        if (!negative) {
            for (int s = 0; s < n; s++) {
                auto b = bellman_ford(g, s);
                if (d[s] != b.dist) ok = false;
            }
        }
    }

    // floyd_warshall: 負閉路があっても値は -inf 以上に収まり、あふれない。dist[i][i] < 0 で負閉路を判定できる
    for (int n : {2, 10, 40}) {
        const long long inf = std::numeric_limits<long long>::max() / 4;
        Graph<long long> g(n);
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) g.add_directed_edge(u, v, -1000000000000000LL);
        }
        auto d = floyd_warshall(g);
        for (int i = 0; i < n; i++) {
            if (d[i][i] >= 0) ok = false;
            for (int j = 0; j < n; j++) {
                if (d[i][j] < -inf || d[i][j] >= 0) ok = false;
            }
        }
    }
    {
        // 負閉路に届かない頂点の値は変わらない
        Graph<long long> g(4);
        g.add_directed_edge(0, 1, -5);
        g.add_directed_edge(1, 0, -5);
        g.add_directed_edge(2, 3, 7);
        auto d = floyd_warshall(g);
        const long long inf = std::numeric_limits<long long>::max() / 4;
        if (d[2][3] != 7 || d[3][2] != inf || d[2][0] != inf || d[0][0] >= 0 || d[2][2] != 0) ok = false;
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
