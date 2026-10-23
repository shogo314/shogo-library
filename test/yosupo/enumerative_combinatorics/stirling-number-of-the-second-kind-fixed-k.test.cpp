#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind_fixed_k"

#include <iostream>

#include "../../../src/math/combinatorial-sequences.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    long long n, k;
    std::cin >> n >> k;
    auto s = stirling_second_column<mint>(n, k);
    for (long long i = k; i <= n; i++) std::cout << s[i] << " \n"[i == n];
}
