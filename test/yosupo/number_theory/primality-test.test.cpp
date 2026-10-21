#define PROBLEM "https://judge.yosupo.jp/problem/primality_test"

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int q;
    std::cin >> q;
    while (q--) {
        long long n;
        std::cin >> n;
        std::cout << (is_prime(n) ? "Yes" : "No") << '\n';
    }
}
