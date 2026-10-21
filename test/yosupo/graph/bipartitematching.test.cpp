#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include <iostream>

#include "../../../src/graph/bipartite-matching.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int l, r, m;
    std::cin >> l >> r >> m;
    BipartiteMatching bm(l, r);
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        bm.add_edge(a, b);
    }
    std::cout << bm.solve() << '\n';
    for (auto [a, b] : bm.matching()) std::cout << a << ' ' << b << '\n';
}
