#define PROBLEM "https://judge.yosupo.jp/problem/static_range_mode_query"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/range-mode.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    RangeMode rm(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        auto [v, c] = rm.mode(l, r);
        std::cout << v << ' ' << c << '\n';
    }
}
