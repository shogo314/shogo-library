#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include <iostream>
#include <vector>

#include "../../../src/algebra/group.hpp"
#include "../../../src/data_structures/link-cut-tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    SubtreeLinkCutTree<group::Sum<long long>> lct(a);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        lct.link(u, v);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int u, v, w, x;
            std::cin >> u >> v >> w >> x;
            lct.cut(u, v);
            lct.link(w, x);
        } else if (t == 1) {
            int p;
            long long x;
            std::cin >> p >> x;
            lct.apply(p, x);
        } else {
            int v, p;
            std::cin >> v >> p;
            std::cout << lct.subtree_prod(v, p) << '\n';
        }
    }
}
