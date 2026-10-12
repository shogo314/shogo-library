#define PROBLEM "https://yukicoder.me/problems/no/1641"

#include <iostream>
#include <vector>

#include "../../src/data_structures/segtree.hpp"
#include "../../src/graph/tree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n >> q;
    std::vector<int> c(n);
    for (auto& x : c) std::cin >> x;
    Tree<int> tree(n);
    tree.read();
    // 部分木は行きがけ順で連続する区間になる
    RootedTree<int> rooted = std::move(tree).set_root(0);
    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[rooted.preorder[i]] = i;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) v[pos[i]] = c[i];
    SegTree<monoid::Xor<int>> seg(v);
    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        x--;
        if (t == 1) {
            seg.apply(pos[x], y);
        } else {
            std::cout << seg.prod(pos[x], pos[x] + rooted.sz[x]) << '\n';
        }
    }
}
