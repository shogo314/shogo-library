#define PROBLEM "https://judge.yosupo.jp/problem/persistent_range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/persistent-lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;
using Seg = PersistentLazySegTree<acted_monoid::AffineSum<mint>>;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<mint> a(n);
    for (auto& x : a) std::cin >> x;
    // seg[i + 1] がクエリ i の後の版、seg[0] が初期の版
    std::vector<Seg> seg(q + 1);
    seg[0] = Seg(a);
    for (int i = 0; i < q; i++) {
        int t, k;
        std::cin >> t >> k;
        if (t == 0) {
            int l, r;
            mint b, c;
            std::cin >> l >> r >> b >> c;
            seg[i + 1] = seg[k + 1].apply(l, r, Affine<mint>{b, c});
        } else if (t == 1) {
            int s, l, r;
            std::cin >> s >> l >> r;
            seg[i + 1] = seg[k + 1].copy(seg[s + 1], l, r);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg[k + 1].prod(l, r) << '\n';
        }
    }
}
