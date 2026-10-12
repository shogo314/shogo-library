---
title: グラフ
documentation_of: //src/graph/graph.hpp
---

隣接リストで表すグラフ `Graph<Cost = int>` です。木は [木の汎用テンプレート](tree.hpp)、二部グラフ判定・連結成分・トポロジカルソートなどの関数は [グラフに関する関数](graph_util.hpp) にあります。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);                // 1-indexed、重み付き、無向の辺を m 本読む
auto [dist, prev] = g.shortest_path(0);
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

いずれも `{各頂点への距離, 各頂点への最短路の直前の辺}` を返します。直前の辺を `src` でたどると経路を復元できます。

| 関数 | アルゴリズム | 未到達の頂点の距離 | 計算量 |
|---|---|---|---|
| `shortest_path(s)` | Dijkstra | `inf` (省略時 `-1`) | $O(m \log m)$ |
| `shortest_path(s, false)` | BFS (辺の重みを 1 とみなす) | `inf` (省略時 `-1`) | $O(n + m)$ |
| `bellman_ford(s)` | Bellman-Ford (負の辺も可) | `inf` (省略時 `max / 4`)。負閉路の影響を受ける頂点は `-inf` | $O(nm)$ |
