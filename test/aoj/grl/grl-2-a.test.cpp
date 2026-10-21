#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include <iostream>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/graph_util.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, 0, true);
    std::cout << minimum_spanning_tree(g).cost << '\n';
}
