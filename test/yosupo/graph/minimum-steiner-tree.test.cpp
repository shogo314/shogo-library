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
    std::vector<long long> w(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v >> w[i];
        g.add_edge(u, v, w[i]);
    }
    int k;
    std::cin >> k;
    std::vector<int> x(k);
    for (auto& v : x) std::cin >> v;
    auto edges = minimum_steiner_tree_restore(g, x);
    long long sum = 0;
    for (auto e : edges) sum += w[e];
    std::cout << sum << ' ' << edges.size() << '\n';
    for (int i = 0; i < static_cast<int>(edges.size()); i++) std::cout << (i ? " " : "") << edges[i];
    std::cout << '\n';
}
