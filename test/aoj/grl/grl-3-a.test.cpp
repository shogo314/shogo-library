#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <iostream>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/lowlink.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    LowLink ll(g);
    for (int v : ll.articulation_points()) std::cout << v << '\n';
}
