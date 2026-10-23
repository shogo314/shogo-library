#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include <iostream>
#include <utility>
#include <vector>

#include "../../../src/graph/rerooting-dp.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<mint> a(n), b(n - 1), c(n - 1);
    for (auto& x : a) std::cin >> x;
    Tree<int> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v >> b[i] >> c[i];
        tree.add_edge(u, v);
    }
    // 部分木の中の y についての (P(x, y) の和, y の個数) を持つ。辺 e を通ると和は b_e 倍して c_e を個数分足す
    using P = std::pair<mint, mint>;
    auto dp = rerooting_dp(
        tree,
        P{0, 0},
        [](const P& x, const P& y) { return P{x.first + y.first, x.second + y.second}; },
        [&](const P& x, int, long long id) { return P{b[id] * x.first + c[id] * x.second, x.second}; },
        [&](const P& x, long long v) { return P{x.first + a[v], x.second + 1}; });
    for (int i = 0; i < n; i++) std::cout << dp[i].first << (i + 1 < n ? ' ' : '\n');
}
