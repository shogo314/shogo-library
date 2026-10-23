#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/sortable-segtree.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> p(n);
    std::vector<Affine<mint>> f(n);
    for (int i = 0; i < n; i++) std::cin >> p[i] >> f[i].a >> f[i].b;
    // Composite は f∘g なので、左から順に適用するには積の順序を逆にする
    SortableSegTree<monoid::Reverse<monoid::Composite<mint>>> st(p, f, 1LL << 30);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            long long i, key;
            mint a, b;
            std::cin >> i >> key >> a >> b;
            st.set(i, key, Affine<mint>{a, b});
        } else if (t == 1) {
            long long l, r;
            mint x;
            std::cin >> l >> r >> x;
            std::cout << st.prod(l, r)(x) << '\n';
        } else {
            long long l, r;
            std::cin >> l >> r;
            st.sort(l, r, t == 3);
        }
    }
}
