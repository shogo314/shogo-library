#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include <iostream>
#include <vector>

#include "../../../src/utility/vector_func.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    // s[i] = a[0] + ... + a[i-1]
    std::vector<long long> s = cumulative_sum(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << s[r] - s[l] << '\n';
    }
}
