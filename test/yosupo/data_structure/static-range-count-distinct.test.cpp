#define PROBLEM "https://judge.yosupo.jp/problem/static_range_count_distinct"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/range-count-distinct.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (auto& x : a) std::cin >> x;
    RangeCountDistinct rcd(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << rcd.count(l, r) << '\n';
    }
}
