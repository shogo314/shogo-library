#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection_undirected"

#include <iostream>

#include "../../src/graph/graph.hpp"
#include "../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0, false, false);
    auto cycle = find_cycle_undirected(g);
    if (cycle.empty()) {
        std::cout << -1 << '\n';
        return 0;
    }
    int l = cycle.size();
    std::cout << l << '\n';
    for (int i = 0; i < l; i++) std::cout << cycle[i].src << " \n"[i + 1 == l];
    for (int i = 0; i < l; i++) std::cout << cycle[i].id << " \n"[i + 1 == l];
}
