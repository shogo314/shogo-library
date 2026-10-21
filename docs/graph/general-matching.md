---
title: 一般グラフの最大マッチング
documentation_of: //src/graph/general-matching.hpp
---

無向グラフ [グラフ](graph.hpp) `Graph<Cost>` の最大マッチング (端点を共有しない辺の集合で、辺の数が最大のもの) を、Edmonds の花アルゴリズムで求めます。二部グラフでなくてもかまいません。

```cpp
Graph g(n);
g.read(m, 0);                       // 無向辺を m 本読む
auto matching = general_matching(g);
std::vector<long long> mate(n, -1); // 相手の頂点 (いなければ -1)
for (auto& e : matching) mate[e.src] = e.dst, mate[e.dst] = e.src;
```

返す辺は `src < dst` の向きで、`src` の昇順に並びます。辺の番号は `id` で分かります。自己ループは無視し、多重辺があってもかまいません。

辺は `add_edge` (無向辺) で追加してください。`add_directed_edge` で片方の向きだけを入れると、正しく求まりません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `general_matching(g)` | 最大マッチングに使った辺のリスト (`std::vector<Edge>`) | $O(n^3)$ |

## 関連

- 二部グラフなら [二部グラフの最大マッチング](bipartite-matching.hpp) (Hopcroft-Karp 法、$O(m \sqrt{n})$) が速い
