---
title: グラフ
documentation_of: //src/graph/graph.hpp
---

隣接リストで表すグラフ `Graph<Cost = int>` です。メンバ関数はグラフを作る・たどる操作だけで、アルゴリズムは `Graph` を受け取る関数として別のファイルにあります。最短路は [最短路](shortest-path.hpp)、二部グラフ判定・連結成分・トポロジカルソートなどは [グラフに関する関数](graph_util.hpp) です。木は [木の汎用テンプレート](tree.hpp) を使います。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);                // 1-indexed、重み付き、無向の辺を m 本読む
for (long long v : g[u]) { /* u から出る辺の行き先 */ }
for (auto& e : g[u]) { /* e.src, e.dst, e.cost, e.id */ }
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Graph(n)` | 頂点数 `n` の空グラフ | $O(n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `add_edge(u, v, w = 1)` | 無向辺を追加 | ならし $O(1)$ |
| `add_directed_edge(u, v, w = 1)` | 有向辺を追加 | ならし $O(1)$ |
| `read(m, padding = -1, weighted = false, directed = false)` | 標準入力から `m` 本の辺を読む。頂点番号に `padding` を足す | $O(m)$ |
| `g[v]` | `v` から出る辺 (`Edge`) のリスト | $O(1)$ |
| `edges()` | 全辺のリスト (`id` 順、無向辺は 1 本だけ) | $O(n + m)$ |

`Edge` は `src`、`dst`、`cost`、`id` (追加順の番号、無向辺は両方向で同じ) を持ち、`long long` に変換すると `dst` になります。`src`・`dst`・`id` は `long long` です。

頂点番号・辺の番号・頂点数 (`n`・`m`・`size()`) は `long long` です。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `n` / `m` | 頂点数 (`size()` と同じ) / 辺数 |
| `g` | 隣接リスト (`g[v]` は `v` から出る辺のリスト) |

## 関連

- 最短路 (Dijkstra・BFS・Bellman-Ford・01-BFS・Floyd-Warshall) は [最短路](shortest-path.hpp)
- 木は [木の汎用テンプレート](tree.hpp)
- 二部グラフ判定・連結成分・トポロジカルソート・閉路・強連結成分分解・最小全域木などは [グラフに関する関数](graph_util.hpp)
- 関節点・橋は [lowlink](lowlink.hpp)
