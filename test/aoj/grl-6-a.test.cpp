#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include <iostream>

#include "../../src/graph/max-flow.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    MaxFlow<int> mf(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        mf.add_edge(u, v, c);
    }
    std::cout << mf.flow(0, n - 1) << '\n';
}
