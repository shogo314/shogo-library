#define PROBLEM "https://judge.yosupo.jp/problem/tetration_mod"

#include <iostream>

#include "../../../src/math/prime.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        long long a, b, m;
        std::cin >> a >> b >> m;
        std::cout << tetration_mod(a, b, m) << '\n';
    }
}
