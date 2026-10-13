#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

// HL 分解と Fenwick Tree で、点加算とパスの和を求める

#include <algorithm>
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
    g.read(n - 1, 0);
    HeavyLightDecomposition hld(g);
    std::vector<long long> init(n);
    for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];
    FenwickTree<group::Sum<long long>> ft(init);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;
            ft.apply(hld.index(p), x);
        } else {
            int u, v;
            std::cin >> u >> v;
            long long sum = 0;
            for (auto [l, r] : hld.path(u, v)) sum += ft.prod(std::min(l, r), std::max(l, r) + 1);
            std::cout << sum << '\n';
        }
    }
}
