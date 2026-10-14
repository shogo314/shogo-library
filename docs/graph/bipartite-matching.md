---
title: 二部グラフの最大マッチング (Hopcroft-Karp 法)
documentation_of: //src/graph/bipartite-matching.hpp
---

左側の頂点 $0, \dots, l-1$ と右側の頂点 $0, \dots, r-1$ の間に辺がある二部グラフの、最大マッチングを求めます。Hopcroft-Karp 法で $O(m \sqrt{n})$ です。増加路を探す DFS は再帰を使わないので、増加路が長くてもスタックがあふれません。

```cpp
BipartiteMatching bm(l, r);
bm.add_edge(0, 1);                  // 左 0 と右 1 の間の辺
int k = bm.solve();                 // 最大マッチングの大きさ
for (auto [u, v] : bm.matching()) { /* 左 u と右 v がマッチした */ }
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `BipartiteMatching(l, r)` | 左側の頂点が `l` 個、右側の頂点が `r` 個で、辺のない状態 | $O(l + r)$ |
| `add_edge(u, v)` | 左側の頂点 `u` と右側の頂点 `v` の間に辺を追加する | ならし $O(1)$ |
| `solve()` | 最大マッチングを求め、その辺の本数を返す | $O(m \sqrt{n})$ ($n = l + r$) |
| `matching()` | マッチングの辺 `(左側の頂点, 右側の頂点)` のリスト (左側の頂点の昇順) | $O(l)$ |
| `left_match(u)` | 左側の頂点 `u` とマッチした右側の頂点 (なければ `-1`) | $O(1)$ |
| `right_match(v)` | 右側の頂点 `v` とマッチした左側の頂点 (なければ `-1`) | $O(1)$ |

辺を追加してからもう一度 `solve()` を呼ぶと、前回のマッチングを広げます。

## 関連

- 容量のある一般のグラフは [最大流](max-flow.hpp)
