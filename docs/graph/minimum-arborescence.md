---
title: 最小全域有向木
documentation_of: //src/graph/minimum-arborescence.hpp
---

有向グラフ [グラフ](graph.hpp) `Graph<Cost>` で、根 `root` からすべての頂点へ到達できる全域木 (全域有向木) のうち、辺のコストの総和が最小のものを求めます。Chu-Liu/Edmonds 法を、ヒープと巻き戻しのできる Union-Find で $O(m \log m)$ にしたものです。

```cpp
Graph<long long> g(n);
g.read(m, 0, true, true);                 // 重み付きの有向辺を m 本読む
auto res = minimum_arborescence(g, root); // 到達できない頂点があれば std::nullopt
if (res) {
    long long cost = res->cost;
    long long p = res->parent_edge[v].src; // v の親 (v != root)
}
```

負のコストの辺、自己ループ、多重辺があってもかまいません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `minimum_arborescence(g, root)` | `root` を根とする最小全域有向木 (`std::optional<MinimumArborescence<Cost>>`)。`root` から到達できない頂点があれば `std::nullopt` | $O(m \log m)$ |

`MinimumArborescence<Cost>` は次の 2 つを持ちます。

| 変数 | 説明 |
|---|---|
| `cost` | 使った辺のコストの総和 |
| `parent_edge[v]` | 親から `v` に入る辺 (`Edge`、元のグラフの辺)。根では `src == -1` |

## 関連

- 無向グラフの最小全域木は [グラフに関する関数](graph_util.hpp) の `minimum_spanning_tree`
