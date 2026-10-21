#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>

#include "../../../src/math/modular-arithmetic.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        long long y, p;
        std::cin >> y >> p;
        std::cout << sqrt_mod(y, p) << '\n';
    }
}
