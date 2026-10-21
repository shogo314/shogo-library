#define PROBLEM "https://judge.yosupo.jp/problem/composition_of_formal_power_series"

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
    FPS<mint> a(n), b(n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    auto c = composition(a, b, n);
    for (int i = 0; i < n; i++) std::cout << c[i] << (i + 1 == n ? '\n' : ' ');
}
