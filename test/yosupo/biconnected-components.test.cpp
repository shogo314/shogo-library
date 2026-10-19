#define PROBLEM "https://judge.yosupo.jp/problem/biconnected_components"

#include <iostream>

#include "../../src/graph/graph.hpp"
#include "../../src/graph/lowlink.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    LowLink ll(g);
    const auto& groups = ll.two_vertex_connected_groups();
    std::cout << groups.size() << '\n';
    for (const auto& group : groups) {
        std::cout << group.size();
        for (int v : group) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
