#define PROBLEM "https://judge.yosupo.jp/problem/connected_components_of_complement_graph"

#include <iostream>

#include "../../../src/graph/graph_util.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0);
    auto groups = complement_connected_components(g);
    std::cout << groups.size() << '\n';
    for (const auto& c : groups) {
        std::cout << c.size();
        for (auto v : c) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
