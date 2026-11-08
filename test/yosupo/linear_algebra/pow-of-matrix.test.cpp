#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<std::vector<mint>> a(n, std::vector<mint>(n));
    for (auto& row : a)
        for (auto& x : row) std::cin >> x;
    Matrix<mint> B = Matrix<mint>(a).pow(k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) std::cout << B[i][j] << " \n"[j == n - 1];
    }
}
