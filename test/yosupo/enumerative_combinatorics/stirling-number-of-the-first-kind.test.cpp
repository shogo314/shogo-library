#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_first_kind"

#include <iostream>

#include "../../../src/math/combinatorial-sequences.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    auto f = stirling_first<mint>(n);
    for (int i = 0; i <= n; i++) std::cout << f[i] << (i == n ? '\n' : ' ');
}
