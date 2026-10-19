#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

// graph.hpp の Graph のデフォルトコンストラクタと、const でない operator[] を検証する
// 01-BFS と Floyd-Warshall を、Dijkstra と Bellman-Ford の結果と比べる
// 問題の入力は使わず、すべて一致したら Hello World を出力する

#include "../../src/graph/graph.hpp"

#include <iostream>
#include <limits>
#include <random>
#include <vector>

int main() {
    std::mt19937_64 rng(314);
    bool ok = true;

    Graph<int> empty;
    if (empty.n != 0 || empty.m != 0 || !empty.g.empty()) ok = false;

    for (int rep = 0; rep < 1000 && ok; rep++) {
        int n = rng() % 8 + 1, m = rng() % 12;
        Graph<long long> g(n);
        std::vector<std::vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = rng() % n, v = rng() % n;
            long long w = rng() % 100;
            g.add_directed_edge(u, v, w);
            adj[u].push_back(v);
        }
        for (int v = 0; v < n; v++) {
            // const でない operator[] は隣接リストそのものへの参照を返す
            std::vector<Graph<long long>::Edge>& es = g[v];
            if (&es != &g.g[v] || es.size() != adj[v].size()) ok = false;
            for (int i = 0; i < static_cast<int>(es.size()); i++) {
                if (es[i].src != v || es[i].dst != adj[v][i] || static_cast<int>(es[i]) != adj[v][i]) ok = false;
            }
            // 参照を通して書き換えると、グラフに反映される
            for (auto& e : g[v]) e.cost += 1;
            for (int i = 0; i < static_cast<int>(es.size()); i++) {
                if (g.g[v][i].cost != es[i].cost) ok = false;
            }
        }
        // const な operator[] と同じものを指す
        const Graph<long long>& cg = g;
        for (int v = 0; v < n; v++) {
            if (&cg[v] != &g[v]) ok = false;
        }
    }

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
            auto a = g.shortest_path_01bfs(s);
            auto b = g.shortest_path(s);
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
        auto d = g.floyd_warshall();
        bool negative = false;
        for (int s = 0; s < n; s++) {
            auto b = g.bellman_ford(s);
            for (int t = 0; t < n; t++) negative |= b.dist[t] == -inf;
        }
        bool negative_fw = false;
        for (int i = 0; i < n; i++) negative_fw |= d[i][i] < 0;
        if (negative != negative_fw) ok = false;
        if (!negative) {
            for (int s = 0; s < n; s++) {
                auto b = g.bellman_ford(s);
                if (d[s] != b.dist) ok = false;
            }
        }
    }

    if (ok) std::cout << "Hello World" << std::endl;
}
