#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <iostream>

#include "../../src/math/combinatorics.hpp"
#include "../../src/math/modint.hpp"

// 法が実行時に与えられるので dynamic_modint を使う
using mint = modint;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    long long m;
    std::cin >> t >> m;
    mint::set_mod(m);
    using C = Combination<mint>;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        // C を使わず、階乗とその逆元から直接計算する
        mint ans = 0;
        if (0 <= k && k <= n) ans = C::factorial(n) * C::inverse_factorial(k) * C::inverse_factorial(n - k);
        std::cout << ans << '\n';
    }
}
