---
title: 最短路
documentation_of: //src/graph/shortest-path.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取って最短路を求める関数です。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);
auto sp = shortest_path(g, 0);       // sp.dist[v] が距離、sp.path(v) が経路
auto d = floyd_warshall(g);          // d[i][j] が i から j への距離
```

## 単一始点の最短路

| 関数 | 説明 | 未到達の頂点の距離 | 計算量 |
|---|---|---|---|
| `shortest_path(g, s)` | Dijkstra | `inf` (省略時 `max / 4`) | $O(m \log m)$ |
| `shortest_path(g, s, false)` | BFS (辺の重みを 1 とみなす) | `inf` (省略時 `max / 4`) | $O(n + m)$ |
| `bellman_ford(g, s)` | Bellman-Ford (負の辺も可) | `inf` (省略時 `max / 4`)。負閉路の影響を受ける頂点は `-inf` | $O(nm)$ |
| `shortest_path_01bfs(g, s)` | 01-BFS (辺のコストは 0 か 1 だけ。それ以外は assert で落ちる) | `inf` (省略時 `max / 4`) | $O(n + m)$ |

`inf` は `shortest_path(g, s, weighted, inf)`、`bellman_ford(g, s, inf)`、`shortest_path_01bfs(g, s, inf)` のように最後の引数で渡します。

いずれも `ShortestPath<Cost>` を返します。`auto [dist, prev] = shortest_path(g, s);` のように受け取ることもできます。

| 変数 | 説明 |
|---|---|
| `dist[v]` | `v` への最短路長 |
| `prev[v]` | `v` への最短路上の直前の辺 (始点と未到達の頂点では `src == -1`) |

| 関数 | 説明 | 計算量 |
|---|---|---|
| `path(t)` | 始点から `t` への最短路を構成する辺のリスト (始点側から順に)。`t` が始点か未到達なら空。負閉路の影響を受ける頂点では assert で落ちる | $O(\text{経路の辺数})$ |

## 全点対間の最短路

| 関数 | 説明 | 計算量 |
|---|---|---|
| `floyd_warshall(g, inf = max / 4)` | `dist[i][j]` が `i` から `j` への最短路長である `std::vector<std::vector<Cost>>` を返す (Floyd-Warshall)。到達できなければ `inf`。負の辺があってもよい | $O(n^3)$ |

`dist[i][i] < 0` となる `i` があれば負閉路があります。

```cpp
auto d = floyd_warshall(g);
bool negative_cycle = false;
for (int i = 0; i < g.size(); i++) negative_cycle |= d[i][i] < 0;
```

## 関連

- グラフの表現は [グラフ](graph.hpp)
- 木の 2 頂点間の距離は [木の汎用テンプレート](tree.hpp) の `DoublingClimbTree::dist` が速い
