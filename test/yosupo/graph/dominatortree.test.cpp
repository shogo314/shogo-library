#define PROBLEM "https://judge.yosupo.jp/problem/dominatortree"

#include <iostream>

#include "../../../src/graph/dominator-tree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, s;
    std::cin >> n >> m >> s;
    Graph<int> g(n);
    g.read(m, 0, false, true);
    auto idom = dominator_tree(g, s);
    for (int v = 0; v < n; v++) std::cout << (v == s ? s : idom[v]) << " \n"[v == n - 1];
}
