#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"

// graph_util の minimum_spanning_tree (Kruskal 法) を使う

#include <iostream>

#include "../../../src/graph/graph.hpp"
#include "../../../src/graph/graph_util.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    Graph<long long> g(n);
    g.read(m, 0, true);
    auto mst = minimum_spanning_tree(g);
    std::cout << mst.cost << '\n';
    for (int i = 0; i < static_cast<int>(mst.edges.size()); i++) std::cout << mst.edges[i].id << " \n"[i + 1 == static_cast<int>(mst.edges.size())];
    if (mst.edges.empty()) std::cout << '\n';
}
