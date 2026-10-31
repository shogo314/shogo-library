---
title: マンハッタン距離の最小全域木
documentation_of: //src/geometry/manhattan-mst.hpp
---

平面上の点の集合で、2 点を結ぶ辺の重みをマンハッタン距離 $\lvert x_i - x_j \rvert + \lvert y_i - y_j \rvert$ とした完全グラフの最小全域木を $O(n \log n)$ で求めます。

```cpp
std::vector<Vector<long long, 2>> p = { {0, 0}, {3, 1}, {1, 4} };
auto mst = manhattan_mst(p);
long long cost = mst.cost;  // 9 (0-1 の距離 4 と 0-2 の距離 5。1-2 は距離 5)
for (const auto& e : mst.edges) {
    // e.src、e.dst は点の番号、e.cost は距離
}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `manhattan_mst(points)` | マンハッタン距離の最小全域木。[グラフに関する関数](../graph/graph_util.hpp) の `minimum_spanning_tree` と同じ `MinimumSpanningTree<T>` (`cost` と `edges`) を返す | $O(n \log n)$ |

各点 $i$ について、$i$ を頂点とする 45 度ずつの 8 つの領域のそれぞれで最も近い点への辺だけを候補にすれば足ります。向きを変えながら 4 回掃いて $O(n)$ 本の候補を作り、Kruskal 法にかけます。同じ点があってもかまいません。

## 関連

- 一般のグラフの最小全域木は [グラフに関する関数](../graph/graph_util.hpp) の `minimum_spanning_tree`
- 各点から最も近い・遠い点や、最近点対・最遠点対は [マンハッタン距離](manhattan.hpp)
