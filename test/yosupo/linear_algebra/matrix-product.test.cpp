#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<mint>> a(n, std::vector<mint>(m)), b(m, std::vector<mint>(k));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    for (auto& row : b)
        for (auto& x : row) std::cin >> x;
    Matrix<mint> C = Matrix<mint>(a) * Matrix<mint>(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) std::cout << C[i][j] << " \n"[j == k - 1];
    }
}
