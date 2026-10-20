#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_of_formal_power_series"

#include <iostream>

#include "../../src/math/fps.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    FPS<mint> f(n);
    for (auto& x : f) std::cin >> x;
    auto g = sqrt(f, n);
    if (!g) {
        std::cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) std::cout << (*g)[i] << (i + 1 == n ? '\n' : ' ');
}
