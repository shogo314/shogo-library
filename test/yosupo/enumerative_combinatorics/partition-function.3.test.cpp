#define PROBLEM "https://judge.yosupo.jp/problem/partition_function"

#include <iostream>

#include "../../../src/math/combinatorial-sequences.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    auto f = partition_numbers<mint>(n);
    for (int i = 0; i <= n; i++) std::cout << f[i] << (i == n ? '\n' : ' ');
}
