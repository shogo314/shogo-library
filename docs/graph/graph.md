---
title: グラフ
documentation_of: //src/graph/graph.hpp
---

隣接リストで表すグラフ `Graph<Cost = int>` です。木は [木の汎用テンプレート](tree.hpp)、二部グラフ判定・連結成分・トポロジカルソートなどの関数は [グラフに関する関数](graph_util.hpp) にあります。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);                // 1-indexed、重み付き、無向の辺を m 本読む
auto sp = g.shortest_path(0);        // sp.dist[v] が距離、sp.path(v) が経路
for (int v : g[u]) { /* u から出る辺の行き先 */ }
for (auto& e : g[u]) { /* e.src, e.dst, e.cost, e.id */ }
```

## メンバ

| メンバ | 説明 |
|---|---|
| `n` / `m` | 頂点数 / 辺数 |
| `Graph(n)` | 頂点数 `n` の空グラフ |
| `add_edge(u, v, w = 1)` | 無向辺を追加 |
| `add_directed_edge(u, v, w = 1)` | 有向辺を追加 |
| `read(m, padding = -1, weighted = false, directed = false)` | 標準入力から `m` 本の辺を読む。頂点番号に `padding` を足す |
| `g[v]` | `v` から出る辺 (`Edge`) のリスト |
| `edges()` | 全辺のリスト (`id` 順、無向辺は 1 本だけ) |

`Edge` は `src`、`dst`、`cost`、`id` (追加順の番号、無向辺は両方向で同じ) を持ち、`int` に変換すると `dst` になります。

## 最短路

いずれも `ShortestPath` を返します。`auto [dist, prev] = g.shortest_path(s);` のように受け取ることもできます。

| メンバ | 内容 |
|---|---|
| `dist[v]` | `v` への最短路長 |
| `prev[v]` | `v` への最短路上の直前の辺 (始点と未到達の頂点では `src == -1`) |
| `path(t)` | 始点から `t` への最短路を構成する辺のリスト (始点側から順に)。`t` が始点か未到達なら空。負閉路の影響を受ける頂点では assert で落ちる |

| 関数 | アルゴリズム | 未到達の頂点の距離 | 計算量 |
|---|---|---|---|
| `shortest_path(s)` | Dijkstra | `inf` (省略時 `max / 4`) | $O(m \log m)$ |
| `shortest_path(s, false)` | BFS (辺の重みを 1 とみなす) | `inf` (省略時 `max / 4`) | $O(n + m)$ |
| `bellman_ford(s)` | Bellman-Ford (負の辺も可) | `inf` (省略時 `max / 4`)。負閉路の影響を受ける頂点は `-inf` | $O(nm)$ |
| `shortest_path_01bfs(s)` | 01-BFS (辺のコストは 0 か 1 だけ。それ以外は assert で落ちる) | `inf` (省略時 `max / 4`) | $O(n + m)$ |

## 全点対間の最短路

`floyd_warshall(inf = max / 4)` は、`dist[i][j]` が `i` から `j` への最短路長である `std::vector<std::vector<Cost>>` を返します (Floyd-Warshall、$O(n^3)$)。到達できなければ `inf` です。負の辺があってもよく、`dist[i][i] < 0` となる `i` があれば負閉路があります。

```cpp
auto d = g.floyd_warshall();
bool negative_cycle = false;
for (int i = 0; i < g.n; i++) negative_cycle |= d[i][i] < 0;
```
