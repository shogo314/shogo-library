#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include <iostream>
#include <vector>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Matrix<mint> A(n, m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) std::cin >> A[i][j];
    std::vector<mint> b(n);
    for (auto& x : b) std::cin >> x;
    auto sol = A.solve(b);
    if (!sol) {
        std::cout << -1 << '\n';
        return 0;
    }
    auto print = [&](const std::vector<mint>& v) {
        for (int j = 0; j < m; j++) std::cout << v[j] << (j + 1 == m ? '\n' : ' ');
    };
    std::cout << sol->basis.size() << '\n';
    print(sol->x);
    for (const auto& v : sol->basis) print(v);
}
