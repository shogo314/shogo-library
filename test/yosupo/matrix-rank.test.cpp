#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include <iostream>

#include "../../src/math/matrix.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Matrix<mint> A(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) std::cin >> A[i][j];
    std::cout << A.rank() << '\n';
}
