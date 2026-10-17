#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include <iostream>
#include <vector>

#include "../../src/math/bitwise-transform.hpp"
#include "../../src/math/modint.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using mint = modint998244353;
    int n;
    std::cin >> n;
    std::vector<mint> a(1 << n), b(1 << n);
    for (auto& x : a) std::cin >> x;
    for (auto& x : b) std::cin >> x;
    std::vector<mint> c = and_convolution(a, b);
    for (int i = 0; i < (1 << n); i++) std::cout << c[i] << " \n"[i + 1 == (1 << n)];
}
