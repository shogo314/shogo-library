---
title: グラフに関する関数
documentation_of: //src/graph/graph_util.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取る関数です。

| 関数 | 対象 | 説明 | 計算量 |
|---|---|---|---|
| `is_bipartite(g)` | 無向 | 二部グラフか | $O(n + m)$ |
| `bipartite_coloring(g)` | 無向 | 二部グラフなら各頂点を 0, 1 に彩色した結果 (各連結成分で番号最小の頂点を 0 にする)。二部グラフでなければ空 | $O(n + m)$ |
| `connected_components(g)` | 無向 | 連結成分ごとの頂点のリスト | $O(n + m)$ |
| `is_connected(g)` | 無向 | 連結か | $O(n + m)$ |
| `is_tree(g)` | 無向 | 木か | $O(n + m)$ |
| `topological_sort(g)` | 有向 | トポロジカル順に並べた頂点のリスト。DAG でなければ長さが `n` 未満になる | $O(n + m)$ |
| `has_cycle(g)` | 有向 | 閉路を持つか | $O(n + m)$ |
| `strongly_connected_components(g)` | 有向 | 強連結成分ごとの頂点のリスト。成分はトポロジカル順 (成分 A から B へ辺があれば A が先) に並ぶ | $O(n + m)$ |
| `minimum_steiner_tree(g, X, inf = -1)` | 無向 | 頂点集合 `X` をすべて含む部分木の辺の重みの総和の最小値 | $O(3^k n + 2^k m \log m)$ ($k = \lvert X \rvert$) |

強連結成分の番号が頂点ごとに欲しいときは、返ってきたリストから作ります。番号の小さい成分ほどトポロジカル順で前にあります。

```cpp
auto groups = strongly_connected_components(g);
std::vector<int> id(g.n);
for (int i = 0; i < (int)groups.size(); i++) {
    for (int v : groups[i]) id[v] = i;
}
```
