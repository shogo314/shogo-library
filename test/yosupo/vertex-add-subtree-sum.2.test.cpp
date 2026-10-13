#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

// HL 分解の subtree と Fenwick Tree で、点加算と部分木の和を求める

#include <iostream>
#include <vector>

#include "../../src/algebra/group.hpp"
#include "../../src/data_structures/fenwick-tree.hpp"
#include "../../src/graph/graph.hpp"
#include "../../src/graph/heavy-light-decomposition.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    Graph<int> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        std::cin >> p;
        g.add_edge(p, i);
    }
    HeavyLightDecomposition hld(g);
    std::vector<long long> init(n);
    for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];
    FenwickTree<group::Sum<long long>> ft(init);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int u;
            long long x;
            std::cin >> u >> x;
            ft.apply(hld.index(u), x);
        } else {
            int u;
            std::cin >> u;
            auto [l, r] = hld.subtree(u);
            std::cout << ft.prod(l, r) << '\n';
        }
    }
}
