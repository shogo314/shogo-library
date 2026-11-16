#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/segtree-beats.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    using A = beats_acted_monoid::ChminChmaxAddPowerSum<long long, 2, __int128_t>;
    long long n, q;
    std::cin >> n >> q;
    std::vector<long long> values(n);
    for (auto& x : values) std::cin >> x;
    SegTreeBeats<A> seg(values);
    while (q--) {
        int type;
        long long l, r;
        std::cin >> type >> l >> r;
        if (type == 3) {
            std::cout << static_cast<long long>(seg.prod(l, r)[1]) << '\n';
        } else {
            long long b;
            std::cin >> b;
            if (type == 0) seg.apply(l, r, A::chmin(b));
            if (type == 1) seg.apply(l, r, A::chmax(b));
            if (type == 2) seg.apply(l, r, A::add(b));
        }
    }
}
