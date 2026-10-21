#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../../../src/algebra/acted-monoid.hpp"
#include "../../../src/data_structures/rbst.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using mint = modint998244353;
    int n, q;
    std::cin >> n >> q;
    std::vector<mint> a(n);
    for (auto& x : a) std::cin >> x;
    RBST<acted_monoid::AffineSum<mint>> t(a);
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 0) {
            long long i;
            mint x;
            std::cin >> i >> x;
            t.insert(i, x);
        } else if (type == 1) {
            long long i;
            std::cin >> i;
            t.erase(i);
        } else if (type == 2) {
            long long l, r;
            std::cin >> l >> r;
            t.reverse(l, r);
        } else if (type == 3) {
            long long l, r;
            mint b, c;
            std::cin >> l >> r >> b >> c;
            t.apply(l, r, Affine<mint>{b, c});
        } else {
            long long l, r;
            std::cin >> l >> r;
            std::cout << t.prod(l, r) << '\n';
        }
    }
}
