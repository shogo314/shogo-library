#define PROBLEM "https://judge.yosupo.jp/problem/static_range_lis_query"

#include <iostream>
#include <vector>

#include "../../../src/data_structures/range-lis.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n);
    for (auto& x : p) std::cin >> x;
    RangeLIS rl(p);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << rl.lis(l, r) << '\n';
    }
}
