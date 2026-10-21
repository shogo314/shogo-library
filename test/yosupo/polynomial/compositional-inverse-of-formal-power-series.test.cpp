#define PROBLEM "https://judge.yosupo.jp/problem/compositional_inverse_of_formal_power_series"

#include <iostream>

#include "../../../src/math/fps-composition.hpp"
#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    FPS<mint> a(n);
    for (auto& x : a) std::cin >> x;
    auto b = compositional_inverse(a, n);
    for (int i = 0; i < n; i++) std::cout << b[i] << (i + 1 == n ? '\n' : ' ');
}
