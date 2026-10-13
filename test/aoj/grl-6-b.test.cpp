#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include <iostream>

#include "../../src/graph/min-cost-flow.hpp"

int main() {
    int n, m, f;
    std::cin >> n >> m >> f;
    MinCostFlow<int, int> mcf(n);
    for (int i = 0; i < m; i++) {
        int u, v, c, d;
        std::cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }
    auto [flow, cost] = mcf.flow(0, n - 1, f);
    std::cout << (flow == f ? cost : -1) << '\n';
}
