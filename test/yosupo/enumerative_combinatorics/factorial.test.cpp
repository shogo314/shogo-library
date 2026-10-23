#define PROBLEM "https://judge.yosupo.jp/problem/factorial"

#include <iostream>

#include "../../../src/math/combinatorial-sequences.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long n;
        std::cin >> n;
        std::cout << large_factorial<mint>(n) << '\n';
    }
}
