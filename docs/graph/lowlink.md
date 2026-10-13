---
title: lowlink (関節点、橋、二重辺連結成分分解)
documentation_of: //src/graph/lowlink.hpp
---

無向の [グラフ](graph.hpp) について、DFS の lowlink を求め、関節点・橋・二重辺連結成分を求めます。DFS は再帰を使わないので、深いグラフでもスタックがあふれません。$O(n + m)$ です。

多重辺と自己ループがあってもかまいません。親へ戻る辺は、頂点ではなく辺の番号で区別しています。

```cpp
Graph<int> g(n);
g.read(m, 0);
LowLink ll(g);
for (int v : ll.articulation_points()) { /* 関節点 */ }
for (int id : ll.bridges()) { auto e = g.edges()[id]; /* 橋 e.src - e.dst */ }
auto groups = ll.two_edge_connected_groups();
```

## メンバ

| メンバ | 説明 |
|---|---|
| `LowLink(g)` | 無向グラフ `g` から求める |
| `articulation_points()` | 関節点 (取り除くと連結成分が増える頂点) の番号の昇順のリスト |
| `is_articulation_point(v)` | `v` が関節点か |
| `bridges()` | 橋 (取り除くと連結成分が増える辺) の辺の番号 (`Edge::id`) の昇順のリスト |
| `is_bridge(id)` | 番号 `id` の辺が橋か |
| `two_edge_connected_groups()` | 二重辺連結成分 (橋をすべて取り除いたときの連結成分) ごとの頂点のリスト |
| `two_edge_connected_group_id(v)` | `v` が属する二重辺連結成分の番号 (`two_edge_connected_groups()` の添字) |
| `ord[v]` / `low[v]` | DFS で訪れた順番 / lowlink の値 |

## 関連

- 有向グラフの強連結成分分解は [グラフに関する関数](graph_util.hpp) の `strongly_connected_components`
