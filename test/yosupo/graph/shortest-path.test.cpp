#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../../src/graph/shortest-path.hpp"

#include <iostream>

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    Graph<long long> g(n);
    g.read(m, 0, true, true);
    auto sp = shortest_path(g, s);
    auto route = sp.path(t);
    if (!route) {
        std::cout << -1 << '\n';
        return 0;
    }
    std::cout << sp.dist[t] << ' ' << route->size() << '\n';
    for (auto& e : *route) {
        std::cout << e.src << ' ' << e.dst << '\n';
    }
}
