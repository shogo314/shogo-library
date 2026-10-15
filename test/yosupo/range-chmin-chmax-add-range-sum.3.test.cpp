#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree-beats.hpp"

int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
    int n, q;
    std::cin >> n >> q;
    std::vector<A::S> v(n);
    for (int i = 0; i < n; i++) {
        long long a;
        std::cin >> a;
        v[i] = A::S(a);
    }
    RChminChmaxAddSumQ<long long> seg(v);
    while (q--) {
        int op, l, r;
        std::cin >> op >> l >> r;
        if (op == 3) {
            std::cout << seg.prod(l, r).sum << '\n';
            continue;
        }
        long long b;
        std::cin >> b;
        if (op == 0) seg.apply(l, r, A::chmin(b));
        if (op == 1) seg.apply(l, r, A::chmax(b));
        if (op == 2) seg.apply(l, r, A::add(b));
    }
}
