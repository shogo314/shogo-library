---
title: Link-Cut Tree
documentation_of: //src/data_structures/link-cut-tree.hpp
---

森 (頂点に値を持つ) に対して、辺の追加・削除、パス上の値の集約、頂点の値の更新をならし $O(\log n)$ で行います。モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を渡す `LinkCutTree<M>` と、可換な群 ([algebra/group.hpp](../algebra/group.hpp)) を渡して部分木の集約もできる `SubtreeLinkCutTree<G>` があります。

```cpp
LinkCutTree<monoid::Sum<long long>> lct(a);       // 頂点 i の値が a[i]、辺なし
lct.link(0, 1);
lct.link(1, 2);
long long s = lct.prod(0, 2);                     // a[0] + a[1] + a[2]
lct.cut(0, 1);

SubtreeLinkCutTree<group::Sum<long long>> st(a);
st.link(0, 1);
long long t = st.subtree_prod(1, 0);              // 0 を親としたときの 1 の部分木の和
```

`LinkCutTree` のモノイドは可換でなくてもかまいません。`prod(u, v)` は `u` の側から順に `op` でたたみます。たとえば `monoid::Composite` なら $f_u \circ \cdots \circ f_v$ になるので、`u` の側から先に適用したいときは `monoid::Reverse<monoid::Composite<T>>` を使います。

`SubtreeLinkCutTree` は、パスに含まれない子の部分木の値を足し引きして持つので、逆元のある可換な群が必要です。

木の根は操作によって変わります。`evert(v)` で `v` を根にでき、`prod(u, v)` は `u` を、`subtree_prod(v, p)` は `p` を根にします。`lca(u, v)` はその時点の根についての最小共通祖先です。

## メンバ関数

`LinkCutTree` と `SubtreeLinkCutTree` に共通です (`subtree_prod` は `SubtreeLinkCutTree` だけ)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LinkCutTree(n, m = M())` | 頂点数 `n`、辺なし、値はすべて単位元 | $O(n)$ |
| `LinkCutTree(a, m = M())` | 頂点 `i` の値が `a[i]`、辺なし | $O(n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `link(u, v)` | 辺 `(u, v)` を追加する。`u` と `v` は別の木にあること | ならし $O(\log n)$ |
| `cut(u, v)` | 辺 `(u, v)` を削除する。辺 `(u, v)` があること | ならし $O(\log n)$ |
| `connected(u, v)` | `u` と `v` が同じ木にあるか | ならし $O(\log n)$ |
| `evert(v)` | `v` を根にする | ならし $O(\log n)$ |
| `root(v)` | `v` を含む木の今の根 | ならし $O(\log n)$ |
| `lca(u, v)` | 今の根についての `u` と `v` の最小共通祖先。同じ木にあること | ならし $O(\log n)$ |
| `get(v)` | 頂点 `v` の値 | $O(1)$ |
| `set(v, x)` | 頂点 `v` の値を `x` にする | ならし $O(\log n)$ |
| `apply(v, x)` | 頂点 `v` の値を `op(get(v), x)` にする | ならし $O(\log n)$ |
| `prod(u, v)` | `u` から `v` へのパス上の頂点 (端点を含む) の値を `u` の側から順にたたんだもの。同じ木にあること。`u` が根になる | ならし $O(\log n)$ |
| `subtree_prod(v, p)` | `p` を根としたときの `v` の部分木の値の和 (`p == v` なら木全体)。同じ木にあること。`p` が根になる | ならし $O(\log n)$ |

## 関連

- 木の形が変わらないなら [HL 分解](../graph/heavy-light-decomposition.hpp) が速い
- 辺の追加だけなら [UnionFind](unionfind.hpp)
