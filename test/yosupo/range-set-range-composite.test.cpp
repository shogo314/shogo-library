#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include <iostream>
#include <vector>

#include "../../src/math/modint.hpp"
#include "../../src/data_structures/lazy-segtree.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    using mint = modint998244353;
    std::vector<Affine<mint>> f(n);
    for (auto& x : f) std::cin >> x;
    LazySegTree<acted_monoid::UpdateComposite<mint>> seg(f);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 0) {
            mint c, d;
            std::cin >> c >> d;
            seg.apply(l, r, Affine<mint>{c, d});
        } else {
            mint x;
            std::cin >> x;
            std::cout << seg.prod(l, r)(x) << '\n';
        }
    }
}
