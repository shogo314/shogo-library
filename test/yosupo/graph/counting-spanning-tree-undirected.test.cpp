#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_undirected"

#include <iostream>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    // 行列木定理: ラプラシアン行列 L = D - A から最後の行と列を除いた行列の行列式
    Matrix<mint> D(n - 1, n - 1), A(n - 1, n - 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u == v) continue;  // 自己ループは全域木に使えない
        if (u < n - 1) D[u][u] += 1;
        if (v < n - 1) D[v][v] += 1;
        if (u < n - 1 && v < n - 1) {
            A[u][v] += 1;
            A[v][u] += 1;
        }
    }
    std::cout << (D - A).det() << '\n';
}
