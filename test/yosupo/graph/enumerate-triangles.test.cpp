#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_triangles"

#include <iostream>
#include <vector>

#include "../../../src/graph/graph_util.hpp"
#include "../../../src/math/modint.hpp"

using mint = modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<mint> x(n);
    for (auto& v : x) std::cin >> v;
    Graph<int> g(n);
    g.read(m, 0);
    mint ans = 0;
    enumerate_triangles(g, [&](long long a, long long b, long long c) { ans += x[a] * x[b] * x[c]; });
    std::cout << ans << '\n';
}
