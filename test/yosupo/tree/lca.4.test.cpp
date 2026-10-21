#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <iostream>
#include <vector>

#include "../../../src/graph/tree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> par(n - 1);
    for (auto& p : par) std::cin >> p;
    const RootedTree<int> rooted(par, 0);
    // const な RootedTree からコピーして作る 2 通り
    DoublingClimbTree<int> t1 = rooted.build_lca();
    DoublingClimbTree<int> t2(rooted);
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        int a = t1.lca(u, v);
        if (a != t2.lca(u, v)) return 1;
        std::cout << a << '\n';
    }
}
