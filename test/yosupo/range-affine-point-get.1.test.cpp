#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include <iostream>
#include <vector>

#include "../../src/data_structures/lazy-segtree.hpp"
#include "../../src/math/modint.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    using mint = modint998244353;
    std::vector<mint> a(n);
    for (auto& x : a) std::cin >> x;
    LazySegTree<acted_monoid::AffineSum<mint>> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int l, r;
            mint b, c;
            std::cin >> l >> r >> b >> c;
            seg.apply(l, r, Affine<mint>{b, c});
        } else {
            int i;
            std::cin >> i;
            std::cout << seg.get(i) << '\n';
        }
    }
}
