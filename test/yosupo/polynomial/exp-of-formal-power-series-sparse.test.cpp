#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_formal_power_series_sparse"

#include <iostream>

#include "../../../src/math/fps.hpp"
#include "../../../src/math/modint.hpp"
#include "../../../src/math/sparse-fps.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, k;
    std::cin >> n >> k;
    FPS<mint> f(n);
    for (int t = 0; t < k; t++) {
        int i;
        std::cin >> i;
        std::cin >> f[i];
    }
    auto g = sparse_exp(f, n);
    for (int i = 0; i < n; i++) std::cout << g[i] << (i + 1 == n ? '\n' : ' ');
}
