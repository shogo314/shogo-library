#define PROBLEM "https://judge.yosupo.jp/problem/counting_spanning_tree_directed"

#include <iostream>

#include "../../../src/math/matrix.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m, r;
    std::cin >> n >> m >> r;
    // 有向の行列木定理: L = (入次数の対角行列) - (隣接行列) から r の行と列を除いた行列の行列式が、r を根とする有向全域木の数
    auto id = [&](int v) { return v < r ? v : v - 1; };
    Matrix<mint> L(n - 1, n - 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u == v || v == r) continue;  // 自己ループと根に入る辺は使えない
        L[id(v)][id(v)] += 1;
        if (u != r) L[id(u)][id(v)] -= 1;
    }
    std::cout << L.det() << '\n';
}
