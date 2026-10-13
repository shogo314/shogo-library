#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

#include <iostream>
#include <utility>

#include "../../src/graph/tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    Tree<int> tree(n);
    tree.read(0);
    DoublingClimbTree<int> dt = std::move(tree).build_lca(0);
    while (q--) {
        int s, t, i;
        std::cin >> s >> t >> i;
        int l = dt.lca(s, t);
        int ds = dt.unweighted_depth[s] - dt.unweighted_depth[l];
        int dist = ds + dt.unweighted_depth[t] - dt.unweighted_depth[l];
        if (i > dist) {
            std::cout << -1 << '\n';
        } else if (i <= ds) {
            std::cout << dt.hop(s, i) << '\n';
        } else {
            std::cout << dt.hop(t, dist - i) << '\n';
        }
    }
}
