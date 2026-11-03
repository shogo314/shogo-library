#define PROBLEM "https://judge.yosupo.jp/problem/eulerian_trail_directed"

#include <iostream>

#include "../../../src/graph/eulerian-trail.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        Graph<int> g(n);
        g.read(m, 0, false, true);
        auto res = eulerian_trail_directed(g);
        if (!res) {
            std::cout << "No\n";
            continue;
        }
        const auto& [cost, vertices, edges] = *res;
        std::cout << "Yes\n";
        for (int i = 0; i <= m; i++) std::cout << vertices[i] << " \n"[i == m];
        for (int i = 0; i < m; i++) std::cout << edges[i].id << " \n"[i == m - 1];
        if (m == 0) std::cout << '\n';
    }
}
