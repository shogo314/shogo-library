#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation"

#include <iostream>
#include <vector>

#include "../../../src/math/modint.hpp"
#include "../../../src/math/multipoint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<mint> xs(n), ys(n);
    for (auto& x : xs) std::cin >> x;
    for (auto& y : ys) std::cin >> y;
    auto f = polynomial_interpolation(xs, ys);
    for (int i = 0; i < n; i++) std::cout << f[i] << (i + 1 == n ? '\n' : ' ');
}
