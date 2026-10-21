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
        auto trail = eulerian_trail_directed(g);
        if (m == 0) {
            std::cout << "Yes\n0\n\n";
            continue;
        }
        if (trail.empty()) {
            std::cout << "No\n";
            continue;
        }
        std::cout << "Yes\n";
        for (auto& e : trail) std::cout << e.src << ' ';
        std::cout << trail.back().dst << '\n';
        for (int i = 0; i < m; i++) std::cout << trail[i].id << " \n"[i == m - 1];
    }
}
