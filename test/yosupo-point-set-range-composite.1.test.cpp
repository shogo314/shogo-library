#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include <iostream>

#include "../math/modint.hpp"
#include "../data_structures/segtree.hpp"

int main(void) {
    int n, q; std::cin >> n >> q;
    using S = std::pair<modint998244353, modint998244353>;
    std::vector<S> v(n);
    for(int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;
    SegTree<monoid::Composite<modint998244353>> seg(v);
    while(q--) {
        int op; std::cin >> op;
        if(op == 0) {
            int p; modint998244353 c, d; std::cin >> p >> c >> d;
            seg.set(p, std::make_pair(c, d));
        } else {
            int l, r; modint998244353 x; std::cin >> l >> r >> x;
            S f = seg.prod(l, r);
            std::cout << f.first * x + f.second << '\n';
        }
    }
}