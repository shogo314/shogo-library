#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D"

// HL 分解の辺のパスと Fenwick Tree で、辺への加算と根からのパスの和を求める
// 辺 (parent(v), v) の値を index(v) 番目に置く

#include <algorithm>
#include <iostream>

#include "../../src/algebra/group.hpp"
#include "../../src/data_structures/fenwick-tree.hpp"
#include "../../src/graph/heavy-light-decomposition.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    Tree<int> g(n);
    for (int v = 0; v < n; v++) {
        int k;
        std::cin >> k;
        for (int i = 0; i < k; i++) {
            int c;
            std::cin >> c;
            g.add_edge(v, c);
        }
    }
    HeavyLightDecomposition hld(g, 0);
    FenwickTree<group::Sum<long long>> ft(n);
    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int v;
            long long w;
            std::cin >> v >> w;
            ft.apply(hld.index(v), w);
        } else {
            int u;
            std::cin >> u;
            long long sum = 0;
            for (auto [l, r] : hld.path(0, u, true)) sum += ft.prod(std::min(l, r), std::max(l, r) + 1);
            std::cout << sum << '\n';
        }
    }
}
