---
title: 支配木
documentation_of: //src/graph/dominator-tree.hpp
---

有向グラフ [グラフ](graph.hpp) `Graph<Cost>` で、根 `root` から各頂点 `v` への直近支配点を求めます。`root` から `v` へのどの道も通る頂点を `v` の支配点といい、そのうち `v` 以外で `v` に最も近いものが直近支配点です。直近支配点を親とすると、`root` を根とする木 (支配木) になります。Lengauer–Tarjan 法で求めます。

```cpp
Graph<int> g(n);
g.read(m, 0, false, true);          // 重みなしの有向辺を m 本読む
auto idom = dominator_tree(g, root); // idom[v]: v の直近支配点
```

自己ループと多重辺があってもかまいません。辺のコストは使いません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `dominator_tree(g, root)` | 各頂点の直近支配点 (`std::vector<long long>`)。`root` と、`root` から到達できない頂点は `-1` | $O(m \log n)$ |

## 関連

- 無向グラフの関節点 (取り除くと連結でなくなる頂点) は [lowlink](lowlink.hpp)
