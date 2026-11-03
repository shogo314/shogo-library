#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../../src/graph/shortest-path.hpp"

#include <iostream>

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    Graph<long long> g(n);
    g.read(m, 0, true, true);
    auto route = shortest_path(g, s, t);
    if (!route) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::cout << route->cost << ' ' << route->edges.size() << '\n';
    for (auto& e : route->edges) {
        std::cout << e.src << ' ' << e.dst << '\n';
    }
}
