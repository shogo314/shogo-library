#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include <iostream>
#include <vector>

#include "../../src/math/matrix.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<mint>> a(n, std::vector<mint>(n));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    std::cout << Matrix<mint>(a).det() << '\n';
}
