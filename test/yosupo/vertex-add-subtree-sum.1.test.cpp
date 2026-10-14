#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (auto& x : a) std::cin >> x;
    std::vector<int> par(n - 1);
    for (auto& p : par) std::cin >> p;
    // 親のリスト (頂点 1, ..., n-1 の親) から根が 0 の根付き木を作る
    RootedTree<int> tree(par, 0);
    // 行きがけ順で並べると、部分木は連続した区間 [in[u], in[u] + sz[u]) になる
    std::vector<int> in(n);
    for (int i = 0; i < n; i++) in[tree.preorder[i]] = i;
    std::vector<long long> init(n);
    for (int u = 0; u < n; u++) init[in[u]] = a[u];
    RSumQ<long long> seg(init);
    while (q--) {
        int t, u;
        std::cin >> t >> u;
        if (t == 0) {
            long long x;
            std::cin >> x;
            seg.apply(in[u], x);
        } else {
            std::cout << seg.prod(in[u], in[u] + tree.sz[u]) << '\n';
        }
    }
}
