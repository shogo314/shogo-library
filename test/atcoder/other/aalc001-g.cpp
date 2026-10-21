#define PROBLEM "https://atcoder.jp/contests/aalc001/tasks/aalc001_g"
#define IGNORE

#include <iostream>

#include "../../../src/data_structures/lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

int main(void) {
    int n, q;
    std::cin >> n >> q;
    using MI = modint998244353;
    using A = acted_monoid::AddPowerSum<MI, 4>;
    std::vector<A::S> a(n);
    for (int i = 0; i < n; i++) {
        long long x;
        std::cin >> x;
        a[i] = A::S(MI(x));
    }
    LazySegTree<A> seg(a);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        l--;
        if (t == 1) {
            long long x;
            std::cin >> x;
            seg.apply(l, r, MI(x));
        } else {
            int k;
            std::cin >> k;
            std::cout << seg.prod(l, r)[k] << '\n';
        }
    }
}
