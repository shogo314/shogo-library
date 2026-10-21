#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"

// コストがすべて 1 の有向グラフで shortest_path_01bfs を使う

#include <iostream>
#include <limits>

#include "../../../src/graph/shortest-path.hpp"

int main() {
    int n;
    std::cin >> n;
    Graph<int> g(n);
    for (int i = 0; i < n; i++) {
        int u, k;
        std::cin >> u >> k;
        for (int j = 0; j < k; j++) {
            int v;
            std::cin >> v;
            g.add_directed_edge(u - 1, v - 1, 1);
        }
    }
    const int inf = std::numeric_limits<int>::max() / 4;
    auto dist = shortest_path_01bfs(g, 0, inf).dist;
    for (int v = 0; v < n; v++) std::cout << v + 1 << ' ' << (dist[v] == inf ? -1 : dist[v]) << '\n';
}
