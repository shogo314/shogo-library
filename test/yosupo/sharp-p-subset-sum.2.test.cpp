#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include <iostream>
#include <vector>

#include "../../src/math/modint.hpp"
#include "../../src/dp/subset-sum-count.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, t;
    std::cin >> n >> t;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<mint> c = count_subset_sum<mint>(a, t);
    for (int s = 1; s <= t; s++) std::cout << c[s] << " \n"[s == t];
}
