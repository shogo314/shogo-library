#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include <iostream>

#include "../../../src/graph/graph_util.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Graph<int> graph(n);
    graph.read(m, 0, false, true);
    std::cout << (has_cycle_directed(graph) ? 1 : 0) << std::endl;
}
