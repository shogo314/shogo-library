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
| `find_cycle_directed(g)` | 有向 | 閉路を 1 つ求め、その辺をたどる順に並べたもの (`std::vector<Edge>`)。閉路がなければ空 | $O(n + m)$ |
| `find_cycle_undirected(g)` | 無向 | 同上。同じ辺を戻ることはなく、自己ループは長さ 1、多重辺は長さ 2 の閉路になる | $O(n + m)$ |
| `strongly_connected_components(g)` | 有向 | 強連結成分ごとの頂点のリスト。成分はトポロジカル順 (成分 A から B へ辺があれば A が先) に並ぶ | $O(n + m)$ |
| `minimum_spanning_tree(g)` | 無向 | 最小全域木 (Kruskal 法)。`cost` (コストの総和) と `edges` (使った辺) を持つ構造体を返す。連結でなければ最小全域森 | $O(m \log m)$ |
| `minimum_steiner_tree(g, X, inf = max / 4)` | 無向 | 頂点集合 `X` をすべて含む部分木の辺の重みの総和の最小値 | $O(3^k n + 2^k m \log m)$ ($k = \lvert X \rvert$) |

強連結成分の番号が頂点ごとに欲しいときは、返ってきたリストから作ります。番号の小さい成分ほどトポロジカル順で前にあります。

```cpp
auto groups = strongly_connected_components(g);
std::vector<int> id(g.n);
for (int i = 0; i < (int)groups.size(); i++) {
    for (int v : groups[i]) id[v] = i;
}
```

閉路の辺 `c` は、`c[k].dst == c[k + 1].src` (末尾の `dst` は先頭の `src`) となる順に並びます。頂点の列は各辺の `src`、辺の番号は各辺の `id` です。

```cpp
auto c = find_cycle_directed(g);
if (!c.empty()) {
    for (auto& e : c) std::cout << e.src << ' ';  // 閉路の頂点
}
```

最小全域木は `auto [cost, edges] = minimum_spanning_tree(g);` のように受け取れます。`edges` はコストの昇順 (同じなら辺の番号順) に並びます。グラフが連結かどうかは `edges.size() == g.n - 1` で判定できます。

## 関連

- 関節点・橋・二重辺連結成分分解は [lowlink](lowlink.hpp)
- 2-SAT は [2-SAT](two-sat.hpp)
- 最大流は [最大流](max-flow.hpp)、最小費用流は [最小費用流](min-cost-flow.hpp)、二部マッチングは [二部マッチング](bipartite-matching.hpp)
