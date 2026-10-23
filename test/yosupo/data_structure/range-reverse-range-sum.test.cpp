#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <iostream>
#include <vector>

#include "../../../src/algebra/monoid.hpp"
#include "../../../src/data_structures/rbst.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    RBST<monoid::Sum<long long>> t(a);
    while (q--) {
        int type;
        long long l, r;
        std::cin >> type >> l >> r;
        if (type == 0) {
            t.reverse(l, r);
        } else {
            std::cout << t.prod(l, r) << '\n';
        }
    }
}
