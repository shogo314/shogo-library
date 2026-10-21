#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

// 可換でないモノイドで LinkCutTree::prod の向きを確かめる

#include <iostream>
#include <vector>

#include "../../../src/algebra/monoid.hpp"
#include "../../../src/data_structures/link-cut-tree.hpp"
#include "../../../src/math/modint.hpp"

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    using mint = modint998244353;
    // u 側の関数から先に適用するので、合成の向きを逆にする
    using M = monoid::Reverse<monoid::Composite<mint>>;
    int n, q;
    std::cin >> n >> q;
    std::vector<Affine<mint>> f(n);
    for (auto& x : f) std::cin >> x;
    LinkCutTree<M> lct(f);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        lct.link(u, v);
    }
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int u, v, w, x;
            std::cin >> u >> v >> w >> x;
            lct.cut(u, v);
            lct.link(w, x);
        } else if (t == 1) {
            int p;
            Affine<mint> g;
            std::cin >> p >> g;
            lct.set(p, g);
        } else {
            int u, v;
            mint x;
            std::cin >> u >> v >> x;
            std::cout << lct.prod(u, v)(x) << '\n';
        }
    }
}
