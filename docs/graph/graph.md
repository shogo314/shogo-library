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

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Graph(n)` | 頂点数 `n` の空グラフ | $O(n)$ |
| `add_edge(u, v, w = 1)` | 無向辺を追加 | ならし $O(1)$ |
| `add_directed_edge(u, v, w = 1)` | 有向辺を追加 | ならし $O(1)$ |
| `read(m, padding = -1, weighted = false, directed = false)` | 標準入力から `m` 本の辺を読む。頂点番号に `padding` を足す | $O(m)$ |
| `g[v]` | `v` から出る辺 (`Edge`) のリスト | $O(1)$ |
| `edges()` | 全辺のリスト (`id` 順、無向辺は 1 本だけ) | $O(n + m)$ |

`Edge` は `src`、`dst`、`cost`、`id` (追加順の番号、無向辺は両方向で同じ) を持ち、`int` に変換すると `dst` になります。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `n` / `m` | 頂点数 / 辺数 |
| `g` | 隣接リスト (`g[v]` は `v` から出る辺のリスト) |

## 最短路

| 関数 | 説明 | 未到達の頂点の距離 | 計算量 |
|---|---|---|---|
| `shortest_path(s)` | Dijkstra | `inf` (省略時 `max / 4`) | $O(m \log m)$ |
| `shortest_path(s, false)` | BFS (辺の重みを 1 とみなす) | `inf` (省略時 `max / 4`) | $O(n + m)$ |
| `bellman_ford(s)` | Bellman-Ford (負の辺も可) | `inf` (省略時 `max / 4`)。負閉路の影響を受ける頂点は `-inf` | $O(nm)$ |
| `shortest_path_01bfs(s)` | 01-BFS (辺のコストは 0 か 1 だけ。それ以外は assert で落ちる) | `inf` (省略時 `max / 4`) | $O(n + m)$ |

いずれも `ShortestPath` を返します。`auto [dist, prev] = g.shortest_path(s);` のように受け取ることもできます。

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
| `floyd_warshall(inf = max / 4)` | `dist[i][j]` が `i` から `j` への最短路長である `std::vector<std::vector<Cost>>` を返す (Floyd-Warshall)。到達できなければ `inf`。負の辺があってもよい | $O(n^3)$ |

`dist[i][i] < 0` となる `i` があれば負閉路があります。

```cpp
auto d = g.floyd_warshall();
bool negative_cycle = false;
for (int i = 0; i < g.n; i++) negative_cycle |= d[i][i] < 0;
```

## 関連

- 木は [木の汎用テンプレート](tree.hpp)
- 二部グラフ判定・連結成分・トポロジカルソート・閉路・強連結成分分解・最小全域木などは [グラフに関する関数](graph_util.hpp)
- 関節点・橋は [lowlink](lowlink.hpp)
