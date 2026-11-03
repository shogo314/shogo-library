---
title: 中国人郵便配達問題
documentation_of: //src/graph/chinese-postman.hpp
---

無向グラフ [グラフ](graph.hpp) `Graph<Cost>` で、すべての辺を 1 回以上通って始点に戻る閉路の長さの最小値を求めます (中国人郵便配達問題)。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);             // 1-indexed、重み付きの無向辺を m 本読む
auto len = chinese_postman(g);   // 辺が 1 つの連結成分に入っていなければ std::nullopt
auto walk = chinese_postman_restore(g);  // 閉路そのもの (Path)。walk->cost == *len
```

すべての頂点の次数が偶数ならオイラー閉路があるので、答えは辺の重みの総和です。次数が奇数の頂点が $k$ 個あるときは、それらを 2 個ずつ組にして、組の間の最短路を余分に通ります。奇数次数の頂点ごとに Dijkstra 法で距離を求め、組にする最小コストを bit DP で求めるので、$k$ は 20 程度までにしてください。

始点はどこでもかまいません (辺を持つ頂点のどれから始めても、最小の長さは同じです)。辺を持たない頂点は無視します。辺のコストは 0 以上で、自己ループ・多重辺があってもかまいません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chinese_postman(g, inf = max / 4)` | すべての辺を 1 回以上通る閉路の長さの最小値 (`std::optional<Cost>`)。辺がすべて 1 つの連結成分に入っていなければ `std::nullopt`、辺がなければ 0 | $O(k m \log m + 2^k k)$ |
| `chinese_postman_restore(g, inf = max / 4)` | 長さが最小の閉路を 1 つ求め、[`Path<Cost>`](graph.hpp) で返す (`std::optional`)。辺は元のグラフの辺 (番号も元のもの) をたどる向きにしたもので、2 回以上通る辺は何度も現れる。辺がすべて 1 つの連結成分に入っていなければ `std::nullopt`、辺がなければ頂点 0 だけの閉路 | $O(k m \log m + 2^k k)$ |

`chinese_postman_restore` は、組にした頂点の間の最短路の辺を複製してすべての次数を偶数にしたグラフで、[オイラー路](eulerian-trail.hpp) の Hierholzer 法でオイラー閉路をたどります。

## 関連

- 最短路は [最短路](shortest-path.hpp)
