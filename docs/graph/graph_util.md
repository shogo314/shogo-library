---
title: グラフに関する関数
documentation_of: //src/graph/graph_util.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取る関数です。

```cpp
Graph g(n);
g.read(m);
auto color = bipartite_coloring(g);          // 二部グラフでなければ空
auto groups = connected_components(g);       // 連結成分ごとの頂点のリスト
auto [cost, edges] = minimum_spanning_tree(g);
```

## 関数

| 関数 | 説明 | 対象 | 計算量 |
|---|---|---|---|
| `is_bipartite(g)` | 二部グラフか | 無向 | $O(n + m)$ |
| `bipartite_coloring(g)` | 二部グラフなら各頂点を 0, 1 に彩色した結果 (`std::vector<int>`、各連結成分で番号最小の頂点を 0 にする)。二部グラフでなければ空 | 無向 | $O(n + m)$ |
| `connected_components(g)` | 連結成分ごとの頂点のリスト (`std::vector<std::vector<long long>>`) | 無向 | $O(n + m)$ |
| `is_connected(g)` | 連結か | 無向 | $O(n + m)$ |
| `is_tree(g)` | 木か | 無向 | $O(n + m)$ |
| `topological_sort(g)` | トポロジカル順に並べた頂点のリスト (`std::vector<long long>`)。DAG でなければ空 | 有向 | $O(n + m)$ |
| `has_cycle(g)` | 閉路を持つか | 有向 | $O(n + m)$ |
| `find_cycle_directed(g)` | 閉路を 1 つ求め、その辺をたどる順に並べたもの (`std::vector<Edge>`)。閉路がなければ空 | 有向 | $O(n + m)$ |
| `find_cycle_undirected(g)` | 同上。同じ辺を戻ることはなく、自己ループは長さ 1、多重辺は長さ 2 の閉路になる | 無向 | $O(n + m)$ |
| `strongly_connected_components(g)` | 強連結成分ごとの頂点のリスト (`std::vector<std::vector<long long>>`)。成分はトポロジカル順 (成分 A から B へ辺があれば A が先) に並ぶ | 有向 | $O(n + m)$ |
| `minimum_spanning_tree(g)` | 最小全域木 (Kruskal 法)。`cost` (コストの総和) と `edges` (使った辺) を持つ構造体を返す。連結でなければ最小全域森 | 無向 | $O(m \log m)$ |
| `minimum_steiner_tree(g, X, inf = max / 4)` | 頂点集合 `X` をすべて含む部分木の辺の重みの総和の最小値 | 無向 | $O(3^k n + 2^k m \log m)$ ($k = \lvert X \rvert$) |

強連結成分の番号が頂点ごとに欲しいときは、返ってきたリストから作ります。番号の小さい成分ほどトポロジカル順で前にあります。

```cpp
auto groups = strongly_connected_components(g);
std::vector<int> id(g.size());
for (int i = 0; i < (int)groups.size(); i++) {
    for (long long v : groups[i]) id[v] = i;
}
```

閉路の辺 `c` は、`c[k].dst == c[k + 1].src` (末尾の `dst` は先頭の `src`) となる順に並びます。頂点の列は各辺の `src`、辺の番号は各辺の `id` です。

```cpp
auto c = find_cycle_directed(g);
if (!c.empty()) {
    for (auto& e : c) std::cout << e.src << ' ';  // 閉路の頂点
}
```

最小全域木は `auto [cost, edges] = minimum_spanning_tree(g);` のように受け取れます。`edges` はコストの昇順 (同じなら辺の番号順) に並びます。グラフが連結かどうかは `edges.size() == g.size() - 1` で判定できます。

## 関連

- 関節点・橋・二重辺連結成分分解は [lowlink](lowlink.hpp)
- 2-SAT は [2-SAT](two-sat.hpp)
- 最大流は [最大流](max-flow.hpp)、最小費用流は [最小費用流](min-cost-flow.hpp)、二部マッチングは [二部マッチング](bipartite-matching.hpp)
