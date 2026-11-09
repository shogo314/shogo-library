---
title: HL 分解 (Heavy-Light Decomposition)
documentation_of: //src/graph/heavy-light-decomposition.hpp
---

木の頂点を一列に並べ替えて、どのパスも $O(\log n)$ 個の区間に、どの部分木も 1 つの区間になるようにします。頂点 `v` は列の `index(v)` 番目に対応します。[セグメント木](../data_structures/segtree.hpp)・[遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp)・[Fenwick Tree](../data_structures/fenwick-tree.hpp) と組み合わせて、パスや部分木への更新とクエリを行います。前計算は $O(n)$ で、DFS は再帰を使いません。

```cpp
HeavyLightDecomposition hld(tree, root);  // tree は Tree<Cost>
std::vector<long long> init(n);
for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];
FenwickTree<group::Sum<long long>> ft(init);

ft.apply(hld.index(v), x);             // 頂点 v に x を足す
long long sum = 0;                     // u から v へのパスの和
for (auto [l, r, reverse] : hld.path(u, v)) sum += ft.prod(l, r);
auto [l, r] = hld.subtree(v);          // 部分木の和は ft.prod(l, r)
```

## パスの分解 `path(u, v, edge = false)`

`u` から `v` へのパスを列の区間に分け、`u` 側から順に遅延列挙する range を返します。各要素は `HeavyLightDecomposition::PathSegment {l, r, reverse}` です。区間は常に `l < r` の半開区間 `[l, r)` で、`reverse = false` なら `l` から `r - 1` へ、`true` なら `r - 1` から `l` へたどります。頂点のパスでは `u = v` のときも 1 頂点の区間を返し、辺のパスでは空の range を返します。

range は値を返す input iterator を持ちます。`u` 側の区間を順次返し、`v` 側の区間だけを固定長バッファに退避して逆順に返すため、ヒープ確保はありません。退避する区間数は $O(\log n)$ です。途中で `break` すると残りの走査は行いませんが、最初の区間を返すまでに `v` 側の区間を退避する場合があります。

同じ range を繰り返し走査でき、iterator のコピーも独立して進められます。iterator のコピーには退避中の区間数に比例する時間がかかります。後置 increment は変更前の値を参照するプロキシを返し、退避した区間のコピーを省きます。走査中は元の `HeavyLightDecomposition` を有効なまま保持し、変更しないでください。

`size()`・添字アクセス・逆順走査はありません。保存が必要なら、明示的に `vector` に変換します。

```cpp
auto segments = hld.path(u, v);
std::vector<HeavyLightDecomposition::PathSegment> saved(segments.begin(), segments.end());
```

1 次関数の合成のように交換法則が成り立たない演算では、向きを区別します。index の昇順に適用するセグメント木と、降順に適用するセグメント木の 2 本を用意します。`monoid::Composite` の積は $f \circ g$ ($g$ を先に適用) なので、昇順に適用する側は積の順序を逆にした `monoid::Reverse` を使います。

```cpp
SegTree<monoid::Reverse<monoid::Composite<mint>>> forward(init);
SegTree<monoid::Composite<mint>> backward(init);
for (auto [l, r, reverse] : hld.path(u, v)) x = reverse ? backward.prod(l, r)(x) : forward.prod(l, r)(x);
```

`edge = true` にすると辺についてのパスになります。辺 (`parent(v)`, `v`) の値を `index(v)` 番目に置き、`lca` の位置を含めません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `HeavyLightDecomposition(tree, root = 0)` | 木 `tree` (`Tree<Cost>`) を根 `root` で分解する | $O(n)$ |
| `index(v)` / `vertex(i)` | 頂点 `v` の列での位置 / 列の `i` 番目の頂点 | $O(1)$ |
| `parent(v)` / `depth(v)` / `subtree_size(v)` | 親 (根は `-1`) / 深さ (辺の本数) / 部分木の頂点数 | $O(1)$ |
| `subtree(v)` | `v` の部分木に対応する区間 `[l, r)` | $O(1)$ |
| `path(u, v, edge = false)` | `u` から `v` へのパスに対応する半開区間と向きを持つ `PathSegment` の遅延 range (上の説明を参照) | 構築 $O(1)$、全走査 $O(\log n)$ |
| `lca(u, v)` | 最小共通祖先 | $O(\log n)$ |
| `dist(u, v)` | `u` と `v` の間の辺の本数 | $O(\log n)$ |
| `hop(v, k)` | `v` から根の方へ `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |
| `jump(u, v, k)` | `u` から `v` へのパスで、`u` から `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |

頂点番号・列での位置・深さ・個数は `long long` で受け取り、`long long` で返します (`path` と `subtree` の区間の端も `long long`)。

## 関連

- LCA やダブリングだけなら [木の汎用テンプレート](tree.hpp) の `DoublingClimbTree`
- 木のパスを重心で分けて数えるなら [重心分解](centroid-decomposition.hpp)
- 指定した頂点とその LCA だけに圧縮した木を作るなら [Auxiliary Tree](auxiliary-tree.hpp)
