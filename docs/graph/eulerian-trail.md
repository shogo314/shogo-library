---
title: オイラー路
documentation_of: //src/graph/eulerian-trail.hpp
---

[グラフ](graph.hpp) `Graph<Cost>` のすべての辺をちょうど 1 回ずつ通る路 (オイラー路) を、Hierholzer 法で 1 つ求めます。

```cpp
Graph g(n);
g.read(m, 0, false, true);               // 有向辺を m 本読む
auto trail = eulerian_trail_directed(g); // なければ空
if (!trail.empty()) {
    std::vector<long long> vs;           // 通る頂点の列 (m + 1 個)
    for (auto& e : trail) vs.push_back(e.src);
    vs.push_back(trail.back().dst);
}
```

返すのは辺のリストで、たどる順に並び、向きもたどる向きです (`trail[k].dst == trail[k + 1].src`)。辺の番号は `id` で分かります。

辺が 1 本もないときも空を返します (オイラー路は自明に存在します)。区別したいときは `g.m == 0` を見てください。

始点と終点が同じ路 (オイラー閉路) が欲しいときは、返った路で `trail.front().src == trail.back().dst` かを確かめます。オイラー閉路があれば、必ず閉路になった路が返ります。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `eulerian_trail_directed(g)` | 有向グラフのオイラー路 (`std::vector<Edge>`)。なければ空 | $O(n + m)$ |
| `eulerian_trail_undirected(g)` | 無向グラフのオイラー路 (`std::vector<Edge>`)。なければ空。自己ループ・多重辺があってもよい | $O(n + m)$ |

## 関連

- 閉路を 1 つ求めるのは [グラフに関する関数](graph_util.hpp) の `find_cycle_directed`・`find_cycle_undirected`
