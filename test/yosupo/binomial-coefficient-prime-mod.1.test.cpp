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
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::cout << Combination<mint>::C(n, k) << '\n';
    }
}
