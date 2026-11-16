#define PROBLEM "https://atcoder.jp/contests/abc357/tasks/abc357_f"
#define IGNORE

#include <iostream>
#include <vector>

#include "../../../src/data_structures/lazy-segtree.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    using mint = modint998244353;
    using A = acted_monoid::AddProductSum<mint>;
    long long n, q;
    std::cin >> n >> q;
    std::vector<mint> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    std::vector<A::S> values;
    for (long long i = 0; i < n; ++i) values.emplace_back(a[i], b[i]);
    LazySegTree<A> seg(values);
    while (q--) {
        int type;
        long long l, r;
        std::cin >> type >> l >> r;
        --l;
        if (type == 3) {
            std::cout << seg.prod(l, r).product_sum << '\n';
        } else {
            mint x;
            std::cin >> x;
            seg.apply(l, r, type == 1 ? A::F{x, mint(0)} : A::F{mint(0), x});
        }
    }
}
