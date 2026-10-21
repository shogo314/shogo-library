#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>

#include "../../../src/math/modular-arithmetic.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int t;
    std::cin >> t;
    while (t--) {
        long long x, y, m;
        std::cin >> x >> y >> m;
        std::cout << discrete_log(x, y, m) << '\n';
    }
}
