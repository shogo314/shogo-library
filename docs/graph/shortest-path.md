---
title: 最短路
documentation_of: //src/graph/shortest-path.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取って最短路を求める関数です。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);
auto route = shortest_path(g, s, t);       // s から t への最短路。届かなければ std::nullopt
if (route) route->cost, route->vertices, route->edges;  // 長さ、たどる頂点、たどる辺
auto sp = shortest_path_dijkstra(g, 0);    // sp.dist[v] が距離、sp.path(v) が経路
auto d = shortest_path_floyd_warshall(g);  // d[i][j] が i から j への距離
```

関数はどれも `shortest_path` で始まり、2 点間は `shortest_path(g, s, t)`、1 点から全点へは `shortest_path_<アルゴリズム>` です。

## 2 点間の最短路

| 関数 | 説明 | 計算量 |
|---|---|---|
| `shortest_path(g, s, t)` | `s` から `t` への最短路を `std::optional<Path<Cost>>` で返す (Dijkstra。`t` の距離が決まった時点で打ち切る)。届かなければ `std::nullopt`、`s == t` なら長さ 0、頂点は `s` だけ、辺は空。負の辺があると assert で落ちる | $O(m \log m)$ |

[`Path<Cost>`](graph.hpp) は経路を表す型で、`auto [cost, vertices, edges] = *shortest_path(g, s, t);` のように受け取れます。`cost` は長さ、`vertices` はたどる頂点の列 (`edges` より 1 つ多い)、`edges` はたどる辺の列です。

## 1 点から全点への最短路

| 関数 | 説明 | 未到達の頂点の距離 | 計算量 |
|---|---|---|---|
| `shortest_path_dijkstra(g, s)` | Dijkstra (負の辺があると assert で落ちる) | `inf` (省略時 `max / 4`) | $O(m \log m)$ |
| `shortest_path_bfs(g, s)` | BFS (辺の重みを 1 とみなす) | `inf` (省略時 `max / 4`) | $O(n + m)$ |
| `shortest_path_bellman_ford(g, s)` | Bellman-Ford (負の辺も可) | `inf` (省略時 `max / 4`)。負閉路の影響を受ける頂点は `-inf` | $O(nm)$ |
| `shortest_path_01bfs(g, s)` | 01-BFS (辺のコストは 0 か 1 だけ。それ以外は assert で落ちる) | `inf` (省略時 `max / 4`) | $O(n + m)$ |

`shortest_path_dijkstra(g, s)` と `shortest_path(g, s, t)` は、はじめにすべての辺のコストが 0 以上であることを assert で確かめます ($O(n + m)$)。負の辺があるときは `shortest_path_bellman_ford` を使います。

`inf` は `shortest_path_dijkstra(g, s, inf)` のように最後の引数で渡します。

いずれも `ShortestPath<Cost>` を返します。`auto [dist, prev] = shortest_path_dijkstra(g, s);` のように受け取ることもできます。

| 変数 | 説明 |
|---|---|
| `dist[v]` | `v` への最短路長 |
| `prev[v]` | `v` への最短路上の直前の辺 (始点と未到達の頂点では `src == -1`) |

| 関数 | 説明 | 計算量 |
|---|---|---|
| `path(t)` | 始点から `t` への最短路 (`std::optional<Path<Cost>>`)。`cost` は `dist[t]` (`shortest_path_bfs` では辺の本数)。`t` が始点なら長さ 0、頂点は `t` だけ、辺は空、未到達なら `std::nullopt`。負閉路の影響を受ける頂点では assert で落ちる | $O(\text{経路の辺数})$ |

`path(t)` の結果は、変数に受けてから使います。`for (const auto& e : sp.path(t)->edges)` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。

## 全点対間の最短路

| 関数 | 説明 | 計算量 |
|---|---|---|
| `shortest_path_floyd_warshall(g, inf = max / 4)` | `dist[i][j]` が `i` から `j` への最短路長である `std::vector<std::vector<Cost>>` を返す (Floyd-Warshall)。到達できなければ `inf`。負の辺があってもよい | $O(n^3)$ |

`dist[i][i] < 0` となる `i` があれば負閉路があります。負閉路があるとき、値は `-inf` より小さくならないように切り詰めるので、あふれません (負閉路の影響を受ける組の値は最短路長ではありません)。

```cpp
auto d = shortest_path_floyd_warshall(g);
bool negative_cycle = false;
for (int i = 0; i < g.size(); i++) negative_cycle |= d[i][i] < 0;
```

## 関連

- グラフの表現は [グラフ](graph.hpp)
- 木の 2 頂点間の距離は [木の汎用テンプレート](tree.hpp) の `DoublingClimbTree::dist` が速い
