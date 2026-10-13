---
title: HL 分解 (Heavy-Light Decomposition)
documentation_of: //src/graph/heavy-light-decomposition.hpp
---

木の頂点を一列に並べ替えて、どのパスも $O(\log n)$ 個の区間に、どの部分木も 1 つの区間になるようにします。頂点 `v` は列の `index(v)` 番目に対応します。[セグメント木](../data_structures/segtree.hpp)・[遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp)・[Fenwick Tree](../data_structures/fenwick-tree.hpp) と組み合わせて、パスや部分木への更新とクエリを行います。前計算は $O(n)$ で、DFS は再帰を使いません。

```cpp
HeavyLightDecomposition hld(g, root);  // Graph、Tree、RootedTree から作れる
std::vector<long long> init(n);
for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];
FenwickTree<group::Sum<long long>> ft(init);

ft.apply(hld.index(v), x);             // 頂点 v に x を足す
long long sum = 0;                     // u から v へのパスの和
for (auto [l, r] : hld.path(u, v)) sum += ft.prod(std::min(l, r), std::max(l, r) + 1);
auto [l, r] = hld.subtree(v);          // 部分木の和は ft.prod(l, r)
```

## パスの分解 `path(u, v, edge = false)`

`u` から `v` へのパスを列の区間に分け、`u` 側から順に並べたリストを返します。各要素 `(a, b)` は、列の `a` 番目から `b` 番目まで (両端を含む) を `a` から `b` の向きにたどることを表します。`a > b` なら index が減る向き、つまり根に近づく向きにたどります。

1 次関数の合成のように交換法則が成り立たない演算では、向きを区別します。index の昇順に積を取るセグメント木と、降順に積を取るセグメント木 (演算の引数を入れ替えたもの) の 2 本を用意します。

```cpp
SegTree<monoid::Composite<mint>> forward(init);
SegTree backward(init, Monoid([](const F& x, const F& y) { return monoid::Composite<mint>::op(y, x); }, F()));
for (auto [a, b] : hld.path(u, v)) x = a <= b ? forward.prod(a, b + 1)(x) : backward.prod(b, a + 1)(x);
```

`edge = true` にすると辺についてのパスになります。辺 (`parent(v)`, `v`) の値を `index(v)` 番目に置き、`lca` の位置を含めません。

## メンバ

| メンバ | 説明 | 計算量 |
|---|---|---|
| `HeavyLightDecomposition(tree, root = 0)` | 木 `tree` を根 `root` で分解する。`tree.n` が頂点数で、`for (int u : tree[v])` で隣接する頂点を列挙できればよい | $O(n)$ |
| `index(v)` / `vertex(i)` | 頂点 `v` の列での位置 / 列の `i` 番目の頂点 | $O(1)$ |
| `parent(v)` / `depth(v)` / `subtree_size(v)` | 親 (根は `-1`) / 深さ (辺の本数) / 部分木の頂点数 | $O(1)$ |
| `subtree(v)` | `v` の部分木に対応する区間 `[l, r)` | $O(1)$ |
| `path(u, v, edge = false)` | `u` から `v` へのパスに対応する区間のリスト (上の説明を参照) | $O(\log n)$ |
| `lca(u, v)` | 最小共通祖先 | $O(\log n)$ |
| `dist(u, v)` | `u` と `v` の間の辺の本数 | $O(\log n)$ |
| `hop(v, k)` | `v` から根の方へ `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |
| `jump(u, v, k)` | `u` から `v` へのパスで、`u` から `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |

## 関連

- LCA やダブリングだけなら [木の汎用テンプレート](tree.hpp) の `DoublingClimbTree`
