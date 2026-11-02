#define PROBLEM "https://judge.yosupo.jp/problem/minimum_steiner_tree"

#include <iostream>
#include <vector>

#include "../../../src/graph/graph_util.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;
        std::cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    int k;
    std::cin >> k;
    std::vector<int> x(k);
    for (auto& v : x) std::cin >> v;
    // 問題の制約でグラフは連結
    const auto [cost, edges] = *minimum_steiner_tree_restore(g, x);
    std::cout << cost << ' ' << edges.size() << '\n';
    for (int i = 0; i < static_cast<int>(edges.size()); i++) std::cout << (i ? " " : "") << edges[i].id;
    std::cout << '\n';
}
