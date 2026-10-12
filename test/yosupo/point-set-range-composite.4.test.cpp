#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>
#include <vector>

#include "../../src/math/modint.hpp"
#include "../../src/data_structures/lazy-segtree.hpp"

// 区間代入できる遅延伝搬セグメント木で、1 点の更新を set と seg[k] = x で行う
int main() {
    int n, q;
    std::cin >> n >> q;
    using MI = modint998244353;
    using S = Affine<MI>;
    std::vector<S> v(n);
    for (auto& f : v) std::cin >> f;
    LazySegTree<acted_monoid::UpdateComposite<MI>> seg(v);
    for (int i = 0; q--; i++) {
        int op;
        std::cin >> op;
        if (op == 0) {
            int p;
            MI c, d;
            std::cin >> p >> c >> d;
            if (i % 2 == 0) {
                seg.set(p, S{c, d});
            } else {
                seg[p] = S{c, d};
            }
        } else {
            int l, r;
            MI x;
            std::cin >> l >> r >> x;
            std::cout << seg.prod(l, r)(x) << '\n';
        }
    }
}
