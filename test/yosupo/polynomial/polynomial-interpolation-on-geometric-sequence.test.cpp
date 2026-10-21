#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_interpolation_on_geometric_sequence"

#include <iostream>
#include <vector>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/math/multipoint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    mint a, r;
    std::cin >> n >> a >> r;
    std::vector<mint> ys(n);
    for (auto& y : ys) std::cin >> y;
    auto f = polynomial_interpolation_geometric(a, r, ys);
    for (int i = 0; i < n; i++) std::cout << f[i] << (i + 1 == n ? "" : " ");
    std::cout << '\n';
}
