#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

// FenwickTree で点加算と区間和を行う

#include <iostream>
#include <vector>

#include "../../src/algebra/group.hpp"
#include "../../src/data_structures/fenwick-tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    FenwickTree<group::Sum<long long>> ft(a);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            ft.apply(p, x);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << ft.prod(l, r) << '\n';
        }
    }
}
