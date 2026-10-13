#define PROBLEM "https://judge.yosupo.jp/problem/range_set_range_composite"

#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

#include "../../src/math/modint.hpp"
#include "../../src/data_structures/lazy-segtree.hpp"

// Composite の積は f∘g (右の関数を先に適用する) なので、添字を反転して i 番目を n - 1 - i 番目に置く
int main() {
    int n, q;
    std::cin >> n >> q;
    using mint = modint998244353;
    std::vector<Affine<mint>> f(n);
    for (int i = 0; i < n; i++) std::cin >> f[n - 1 - i];
    LazySegTree<acted_monoid::UpdateComposite<mint>> seg(f);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        std::tie(l, r) = std::make_pair(n - r, n - l);
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
