#define PROBLEM "https://judge.yosupo.jp/problem/lca"

// HeavyLightDecomposition の lca を使う

#include <iostream>

#include "../../src/graph/heavy-light-decomposition.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    Tree<int> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g.add_edge(p, i);
    }
    HeavyLightDecomposition hld(g);
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << '\n';
    }
}
