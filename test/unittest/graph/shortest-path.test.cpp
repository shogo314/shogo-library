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
                if (a.dist[t] == std::numeric_limits<int>::max() / 4) continue;
                int len = 0;
                for (auto& e : a.path(t)) len += e.cost;
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

    if (ok) std::cout << "Hello World" << std::endl;
}
