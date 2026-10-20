---
title: Auxiliary Tree (虚树)
documentation_of: //src/graph/auxiliary-tree.hpp
---

木の頂点を $k$ 個指定すると、それらと、それらの LCA だけを残して圧縮した木 (Auxiliary Tree、虚树) を $O(k \log n)$ で作ります。頂点は $2k - 1$ 個以下です。「クエリごとに $k$ 個の頂点が与えられ、それらについての木 DP をする」問題で、全体を $O(\sum k \log n)$ にできます。

```cpp
Tree<int> tree(n);
tree.read();
AuxiliaryTree aux(tree, 0);              // 根 0 で前計算する (中で HL 分解を作る)
auto t = aux.build({3, 5, 8});           // 指定した頂点と、その LCA だけの木
for (long long i = t.size() - 1; i > 0; i--) {
    long long v = t.vertices[i], p = t.vertices[t.parent[i]];
    long long w = aux.hld().dist(v, p);  // 圧縮した辺の、元の木での辺の本数
    dp[t.parent[i]] += dp[i];            // 子から親への DP
}
```

- 圧縮した木の辺は、元の木のパスを 1 本にまとめたものです。辺の長さ (元の木での辺の本数) や LCA は `hld()` の [HL 分解](heavy-light-decomposition.hpp) で求めます。重みつきの長さが必要なら、根からの重みつきの距離を別に求めておき、差をとります。
- `vertices` は HL 分解の列の順 (DFS の行きがけ順の 1 つ) に並ぶので、`parent[i] < i` です。後ろから回すと子から親への DP、前から回すと親から子への DP になります。
- 頂点を DFS 順に並べ、隣り合う頂点の LCA を足すと、LCA について閉じた集合になります。そのとき、各頂点の親は DFS 順で 1 つ前の頂点との LCA です。

## メンバ関数

頂点番号・添字・個数は `long long` です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `AuxiliaryTree(tree, root = 0)` | 木 `tree` ([`Tree<Cost>`](tree.hpp)) を根 `root` で前計算する | $O(n)$ |
| `build(vs)` | 頂点 `vs` (`std::vector<long long>`、重複してもよい) とその LCA だけの木 `Result` を返す。`vs` が空なら頂点のない木 | $O(k \log n)$ |
| `hld()` | 前計算に使った [HL 分解](heavy-light-decomposition.hpp) (`lca`・`dist`・`depth` などを使う) | $O(1)$ |

## `Result` のメンバ

| メンバ | 説明 |
|---|---|
| `vertices` | 圧縮した木の頂点 (元の木の頂点番号)。先頭が根 |
| `parent` | `parent[i]` は `vertices[i]` の親の、`vertices` の中での添字 (根は -1) |
| `size()` | 頂点の個数 |

## 関連

- LCA・距離・パスや部分木のクエリは [HL 分解](heavy-light-decomposition.hpp)
- 木全体の DP は [全方位木 DP](rerooting-dp.hpp)
