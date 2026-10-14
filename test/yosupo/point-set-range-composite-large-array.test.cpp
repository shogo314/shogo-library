#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite_large_array"

#include <iostream>

#include "../../src/data_structures/dynamic-segtree.hpp"
#include "../../src/math/modint.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    // Composite は f∘g なので、左から順に適用するには積の順序を逆にする
    DynamicSegTree<monoid::Reverse<monoid::Composite<modint998244353>>> seg(n);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            modint998244353 c, d;
            std::cin >> p >> c >> d;
            seg[p] = Affine<modint998244353>{c, d};
        } else {
            int l, r;
            modint998244353 x;
            std::cin >> l >> r >> x;
            std::cout << seg.prod(l, r)(x) << '\n';
        }
    }
}
