---
title: グラフに関する関数
documentation_of: //src/graph/graph_util.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取る関数です。

```cpp
Graph g(n);
g.read(m);
auto color = bipartite_coloring(g);          // 二部グラフでなければ std::nullopt
auto groups = connected_components(g);       // 連結成分ごとの頂点のリスト
auto [cost, edges] = minimum_spanning_tree(g);
```

## 関数

| 関数 | 説明 | 対象 | 計算量 |
|---|---|---|---|
| `is_bipartite(g)` | 二部グラフか | 無向 | $O(n + m)$ |
| `bipartite_coloring(g)` | 二部グラフなら各頂点を 0, 1 に彩色した結果 (`std::optional<std::vector<int>>`、各連結成分で番号最小の頂点を 0 にする)。二部グラフでなければ `std::nullopt` | 無向 | $O(n + m)$ |
| `connected_components(g)` | 連結成分ごとの頂点のリスト (`std::vector<std::vector<long long>>`) | 無向 | $O(n + m)$ |
| `complement_connected_components(g)` | 補グラフ (辺のない 2 頂点の間に辺を張ったグラフ) の連結成分ごとの頂点のリスト。補グラフは作らない | 無向 | $O(n + m)$ |
| `is_connected(g)` | 連結か | 無向 | $O(n + m)$ |
| `is_tree(g)` | 木か | 無向 | $O(n + m)$ |
| `topological_sort(g)` | トポロジカル順に並べた頂点のリスト (`std::optional<std::vector<long long>>`)。DAG でなければ `std::nullopt` | 有向 | $O(n + m)$ |
| `has_cycle_directed(g)` | 閉路を持つか。無向グラフに使うと辺が 1 本でもあれば true になる | 有向 | $O(n + m)$ |
| `has_cycle_undirected(g)` | 閉路を持つか (森でないか)。自己ループと多重辺も閉路とみなす | 無向 | $O(n + m)$ |
| `find_cycle_directed(g)` | 閉路を 1 つ求め、その辺をたどる順に並べたもの (`std::optional<std::vector<Edge>>`)。閉路がなければ `std::nullopt` | 有向 | $O(n + m)$ |
| `find_cycle_undirected(g)` | 同上。同じ辺を戻ることはなく、自己ループは長さ 1、多重辺は長さ 2 の閉路になる | 無向 | $O(n + m)$ |
| `strongly_connected_components(g)` | 強連結成分ごとの頂点のリスト (`std::vector<std::vector<long long>>`)。成分はトポロジカル順 (成分 A から B へ辺があれば A が先) に並ぶ | 有向 | $O(n + m)$ |
| `minimum_spanning_tree(g)` | 最小全域木 (Kruskal 法)。`cost` (コストの総和) と `edges` (使った辺) を持つ構造体を返す。連結でなければ最小全域森 | 無向 | $O(m \log m)$ |
| `minimum_steiner_tree(g, X, inf = max / 4)` | 頂点集合 `X` をすべて含む部分木の辺の重みの総和の最小値 (`std::optional<Cost>`)。`X` が空なら 0、`X` を連結にできなければ `std::nullopt` | 無向 | $O(3^k n + 2^k m \log m)$ ($k = \lvert X \rvert$) |
| `minimum_steiner_tree_restore(g, X, inf = max / 4)` | 頂点集合 `X` をすべて含む重み最小の部分木を 1 つ求め、その辺の番号を昇順に並べたもの (`std::optional<std::vector<long long>>`)。`X` が空なら空、`X` を連結にできなければ `std::nullopt` | 無向 | `minimum_steiner_tree` と同じ |
| `chromatic_number(g)` | 彩色数 (隣り合う頂点が同じ色にならないように塗るときの色の最小数)。頂点がなければ 0、自己ループがあれば -1。頂点数 20 程度まで。確率的なアルゴリズムでよければ、[集合の被覆](../dp/set-cover.hpp) の `min_set_cover` (独立集合で覆う、$O(2^n n)$) で速くできる | 無向 | $O(3^n)$ より速い |
| `maximum_independent_set(g)` | 最大独立集合 (どの 2 頂点も隣り合わない頂点集合で要素数が最大のもの) の頂点を昇順に返す。頂点数 64 以下 (40 程度なら十分速い)。自己ループのある頂点は選ばない | 無向 | $O(1.39^n)$ 程度 |
| `enumerate_triangles(g, f)` | 三角形 (互いに隣り合う 3 頂点) をすべて列挙し、それぞれについて `f(a, b, c)` ($a < b < c$) を呼ぶ。自己ループと多重辺はないこと | 無向 | $O(m \sqrt{m})$ |

強連結成分の番号が頂点ごとに欲しいときは、返ってきたリストから作ります。番号の小さい成分ほどトポロジカル順で前にあります。

```cpp
auto groups = strongly_connected_components(g);
std::vector<int> id(g.size());
for (int i = 0; i < static_cast<int>(groups.size()); i++) {
    for (long long v : groups[i]) id[v] = i;
}
```

閉路の辺 `*c` は、`(*c)[k].dst == (*c)[k + 1].src` (末尾の `dst` は先頭の `src`) となる順に並びます。頂点の列は各辺の `src`、辺の番号は各辺の `id` です。

```cpp
auto c = find_cycle_directed(g);
if (c) {
    for (auto& e : *c) std::cout << e.src << ' ';  // 閉路の頂点
}
```

`minimum_steiner_tree` などの `inf` は、内部の DP で「まだ作れない」を表す値です。答えになりうるどの値よりも大きくします。

`std::optional<std::vector>` を返す関数 (`bipartite_coloring`・`topological_sort`・`find_cycle_directed`・`find_cycle_undirected`・`minimum_steiner_tree_restore`) の結果は、変数に受けてから使います。`for (long long v : *topological_sort(g))` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。

最小全域木は `auto [cost, edges] = minimum_spanning_tree(g);` のように受け取れます。`edges` はコストの昇順 (同じなら辺の番号順) に並びます。グラフが連結かどうかは `edges.size() == g.size() - 1` で判定できます。

## 関連

- 関節点・橋・二重辺連結成分分解は [lowlink](lowlink.hpp)
- 2-SAT は [2-SAT](two-sat.hpp)
- 最大流は [最大流](max-flow.hpp)、最小費用流は [最小費用流](min-cost-flow.hpp)、二部マッチングは [二部マッチング](bipartite-matching.hpp)
- 最短路は [最短路](shortest-path.hpp)
- オイラー路は [オイラー路](eulerian-trail.hpp)
- 有向グラフの最小全域木 (最小全域有向木) は [最小全域有向木](minimum-arborescence.hpp)
