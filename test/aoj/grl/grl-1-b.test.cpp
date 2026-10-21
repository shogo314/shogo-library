#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include <iostream>

#include "../../../src/graph/shortest-path.hpp"

int main(void) {
    constexpr int INF = 1e8;
    int n, m, r;
    std::cin >> n >> m >> r;
    Graph<int> graph(n);
    graph.read(m, 0, true, true);
    std::vector<int> ans = bellman_ford(graph, r, INF).dist;
    for (int i = 0; i < n; i++) {
        if (ans[i] <= -INF) {
            std::cout << "NEGATIVE CYCLE" << std::endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] >= INF) {
            std::cout << "INF" << std::endl;
        } else {
            std::cout << ans[i] << std::endl;
        }
    }
}
