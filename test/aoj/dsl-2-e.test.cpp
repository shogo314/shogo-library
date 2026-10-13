#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"

#include <iostream>

#include "../../src/data_structures/dual-segtree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    DualSegTree<acted_monoid::AddSum<long long>> seg(n);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int s, u;
            long long x;
            std::cin >> s >> u >> x;
            seg.apply(s - 1, u, x);
        } else {
            int i;
            std::cin >> i;
            std::cout << seg.get(i - 1) << '\n';
        }
    }
}
