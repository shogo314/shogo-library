#define PROBLEM "https://judge.yosupo.jp/problem/characteristic_polynomial"

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<mint>> a(n, std::vector<mint>(n));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    auto p = Matrix<mint>(a).characteristic_polynomial();
    for (int i = 0; i <= n; i++) std::cout << p[i] << " \n"[i == n];
}
