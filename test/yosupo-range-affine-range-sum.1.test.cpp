#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>

#include "../src/math/modint.hpp"
#include "../src/data_structures/lazy-segtree.hpp"

int main(void) {
    int n, q; std::cin >> n >> q;
    using MI = modint998244353;
    std::vector<MI> a(n);
    for(int i = 0; i < n; i++) std::cin >> a[i];
    LazySegTree<acted_monoid::AffineSum<MI>> seg(a);
    while(q--) {
        int op; std::cin >> op;
        if(op == 0) {
            int l, r; MI b, c; std::cin >> l >> r >> b >> c;
            seg.apply(l, r, std::make_pair(b, c));
        } else {
            int l, r; std::cin >> l >> r;
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
