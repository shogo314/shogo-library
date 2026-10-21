#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"

#include <iostream>

#include "../../../src/graph/bipartite-matching.hpp"

int main() {
    int x, y, m;
    std::cin >> x >> y >> m;
    BipartiteMatching bm(x, y);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        bm.add_edge(u, v);
    }
    std::cout << bm.solve() << '\n';
}
