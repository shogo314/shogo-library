#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum_large_array"

#include <iostream>

#include "../../../src/data_structures/dynamic-lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    DynamicLazySegTree<acted_monoid::AffineSum<modint998244353>> seg(n);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            modint998244353 b, c;
            std::cin >> b >> c;
            seg.apply(l, r, Affine<modint998244353>{b, c});
        } else {
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
