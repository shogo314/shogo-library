#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include <iostream>

#include "../../src/data_structures/dual-segtree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    DualSegTree<acted_monoid::UpdateMin<int>> seg(n, 2147483647);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int s, u, x;
            std::cin >> s >> u >> x;
            seg.apply(s, u + 1, x);
        } else {
            int i;
            std::cin >> i;
            std::cout << seg.get(i) << '\n';
        }
    }
}
