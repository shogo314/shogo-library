#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>
#include <vector>

#include "../../src/data_structures/lazy-segtree.hpp"

// 遅延伝搬セグメント木の 1 点への作用 apply(k, f) で点加算する
int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    LazySegTree<acted_monoid::AddSum<long long>> seg(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            seg.apply(p, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << seg.prod(l, r) << '\n';
        }
    }
}
