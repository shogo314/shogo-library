#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

// HeavyLightDecomposition の jump を使う

#include <iostream>

#include "../../src/graph/heavy-light-decomposition.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    Tree<int> g(n);
    g.read(0);
    HeavyLightDecomposition hld(g);
    while (q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        std::cout << hld.jump(s, t, i) << '\n';
    }
}
