#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

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
    Matrix<mint> A(a);
    // inv は逆行列がないと assert で止まるので、先に行列式で確かめる
    if (A.det() == 0) {
        std::cout << -1 << '\n';
        return 0;
    }
    Matrix<mint> B = A.inv();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << B[i][j] << " \n"[j == n - 1];
    }
}
