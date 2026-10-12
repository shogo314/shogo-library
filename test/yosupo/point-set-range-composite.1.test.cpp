#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../../src/math/modint.hpp"
#include "../../src/data_structures/segtree.hpp"

int main(void) {
    int n, q; std::cin >> n >> q;
    using S = Affine<modint998244353>;
    std::vector<S> v(n);
    for(int i = 0; i < n; i++) std::cin >> v[i];
    SegTree<monoid::Composite<modint998244353>> seg(v);
    while(q--) {
        int op; std::cin >> op;
        if(op == 0) {
            int p; modint998244353 c, d; std::cin >> p >> c >> d;
            seg.set(p, S{c, d});
        } else {
            int l, r; modint998244353 x; std::cin >> l >> r >> x;
            S f = seg.prod(l, r);
            std::cout << f(x) << '\n';
        }
    }
}