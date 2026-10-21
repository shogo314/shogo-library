#define PROBLEM "https://judge.yosupo.jp/problem/directedmst"

#include <iostream>

#include "../../../src/graph/minimum-arborescence.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m, s;
    std::cin >> n >> m >> s;
    Graph<long long> g(n);
    g.read(m, 0, true, true);
    auto res = minimum_arborescence(g, s);
    std::cout << res->cost << '\n';
    for (int v = 0; v < n; v++) std::cout << (v == s ? s : res->parent_edge[v].src) << " \n"[v == n - 1];
}
