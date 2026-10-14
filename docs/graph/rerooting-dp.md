---
title: 全方位木DP
documentation_of: //src/graph/rerooting-dp.hpp
---

[木](tree.hpp) `Tree<Cost>` のすべての頂点について、その頂点を根としたときの木 DP の値を $O(n)$ で求めます。

例: 各頂点から最も遠い頂点までの距離 (下の `farthest_node_dist` と同じ)

```cpp
Tree<long long> t(n);
t.read(-1, true);
auto dp = rerooting_dp(
    t, 0LL,
    [](long long a, long long b) { return std::max(a, b); },  // merge: 子の中で最大
    [](long long x, long long c, long long) { return x + c; },  // addedge: 辺の重みを足す
    [](long long a, long long) { return a; });                  // addnode: そのまま
```

## `rerooting_dp<E, V = E>(tree, e, merge, addedge, addnode)` の引数

頂点 $u$ の子を $v_1, v_2, \dots$ とすると、次のように計算した `dp[u]` (型 `V`) を全頂点について返します。

$$\mathrm{dp}[u] = \mathrm{addnode}(\mathrm{merge}(\mathrm{addedge}(\mathrm{dp}[v_1], \mathrm{cost}_1, \mathrm{id}_1), \mathrm{merge}(\mathrm{addedge}(\mathrm{dp}[v_2], \dots), \dots)), u)$$

| 引数 | 型 | 意味 |
|---|---|---|
| `e` | `E` | `merge` の単位元 (子がないときの値) |
| `merge(a, b)` | `(E, E) -> E` | 子からの値をまとめる。可換かつ結合的であること |
| `addedge(x, cost, id)` | `(V, Cost, long long) -> E` | 子の DP 値 `x` に、子へ向かう辺 (重み `cost`、番号 `id`) の分を加える |
| `addnode(a, u)` | `(E, long long) -> V` | まとめた値 `a` に頂点 `u` の分を加えて、`u` の DP 値にする |

辺の番号 `id` と頂点 `u` は `long long` で渡します。`int` で受け取る関数でもかまいません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `rerooting_dp<E, V = E>(tree, e, merge, addedge, addnode)` | 各頂点を根としたときの DP 値 (上の説明を参照) | $O(n)$ (`merge`・`addedge`・`addnode` の呼び出しが $O(n)$ 回) |
| `farthest_node_dist(tree)` | 各頂点から最も遠い頂点までの距離 (重み付き) | $O(n)$ |
| `distance_sums(tree)` | 各頂点から他のすべての頂点への距離の合計 (重み付き) | $O(n)$ |
| `connected_subgraph_count<V>(tree)` | 各頂点について、その頂点を含む連結な部分グラフ (頂点集合) の個数。`V` は `mint` など | $O(n)$ |

## 関連

- 木の直径・LCA などは [木の汎用テンプレート](tree.hpp)
