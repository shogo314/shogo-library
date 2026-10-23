#define PROBLEM "https://judge.yosupo.jp/problem/range_add_range_min"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/lazy-segtree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    LazySegTree<acted_monoid::AddMin<long long>> seg(a);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            long long x;
            std::cin >> x;
            seg.apply(l, r, x);
        } else {
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
