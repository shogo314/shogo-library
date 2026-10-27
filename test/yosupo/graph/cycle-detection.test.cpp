#define PROBLEM "https://judge.yosupo.jp/problem/cycle_detection"

#include <iostream>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0, false, true);
    auto res = find_cycle_directed(g);
    if (!res) {
        std::cout << -1 << '\n';
        return 0;
    }
    auto& cycle = *res;
    std::cout << cycle.size() << '\n';
    for (auto& e : cycle) std::cout << e.id << '\n';
}
