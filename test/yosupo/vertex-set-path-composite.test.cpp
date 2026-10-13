#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

// HL 分解とセグメント木で、パス上の 1 次関数の合成を求める
// 合成は交換法則が成り立たないので、根に近づく向きの区間は逆順の積を持つセグメント木で求める

#include <iostream>
#include <vector>

#include "../../src/algebra/monoid.hpp"
#include "../../src/data_structures/segtree.hpp"
#include "../../src/graph/graph.hpp"
#include "../../src/graph/heavy-light-decomposition.hpp"
#include "../../src/math/modint.hpp"

using mint = modint998244353;
using F = Affine<mint>;

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;
    std::vector<F> f(n);
    for (auto& x : f) std::cin >> x;
    Graph<int> g(n);
    g.read(n - 1, 0);
    HeavyLightDecomposition hld(g);
    std::vector<F> init(n);
    for (int v = 0; v < n; v++) init[hld.index(v)] = f[v];
    // forward は index の昇順に適用し、backward は降順に適用する
    SegTree<monoid::Composite<mint>> forward(init);
    auto rev_op = [](const F& x, const F& y) { return monoid::Composite<mint>::op(y, x); };
    SegTree backward(init, Monoid(rev_op, monoid::Composite<mint>::e()));
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p;
            F c;
            std::cin >> p >> c;
            forward.set(hld.index(p), c);
            backward.set(hld.index(p), c);
        } else {
            int u, v;
            mint x;
            std::cin >> u >> v >> x;
            for (auto [l, r] : hld.path(u, v)) {
                x = l <= r ? forward.prod(l, r + 1)(x) : backward.prod(r, l + 1)(x);
            }
            std::cout << x << '\n';
        }
    }
}
