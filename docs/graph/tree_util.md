---
title: 木に関する関数
documentation_of: //src/graph/tree_util.hpp
---

[木](tree.hpp) `Tree<Cost>` を受け取る関数です。

```cpp
Tree<long long> t(n);
t.read(-1, true);
auto path = tree_diameter(t);  // 直径を構成する辺 (端点から順に)
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `tree_diameter(tree, weighted = true)` | 直径を構成する辺のリスト (`std::vector<Edge>`、端点から順に)。頂点が 1 つなら空。`weighted = false` なら辺の本数で測る | $O(n)$ |

辺の重みは非負を仮定します。

## 関連

- 各頂点から最も遠い頂点までの距離 (`farthest_node_dist`) や距離の和 (`distance_sums`) は [全方位木DP](rerooting-dp.hpp) にあります
- `Graph` を受け取る関数は [グラフに関する関数](graph_util.hpp)
