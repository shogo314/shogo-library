#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include <iostream>

#include "../../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<int> g(n);
    g.read(m, 0, false, true);
    auto groups = strongly_connected_components(g);
    std::cout << groups.size() << '\n';
    for (const auto& group : groups) {
        std::cout << group.size();
        for (int v : group) std::cout << ' ' << v;
        std::cout << '\n';
    }
}
