---
title: ファンクショナルグラフ
documentation_of: //src/graph/functional-graph.hpp
---

$n$ 頂点 $n$ 辺で、すべての頂点の出次数が 1 の有向グラフ (頂点 $i$ から $g_i$ への辺) です。各連結成分はサイクル 1 つと、そこに流れ込む木からなります。

```cpp
FunctionalGraph fg(std::vector<int>{1, 2, 0, 0, 3});  // 0→1→2→0 のサイクルに 4→3→0 が流れ込む
long long v = fg.hop(4, 10); // 4 から 10 回移動した頂点: 2
long long c = fg.hopable(4); // 4 から到達できる頂点の個数: 5
bool b = fg.is_cycle(3);     // false
```

`FunctionalGraph(n)` で作った場合は、参照する前に `read()` で入力します (`size()` は入力前でも使えます)。
頂点 `v` の遷移先は `hop(v, 1)` で取得できます。

頂点番号・個数・距離は `long long` です。`FunctionalGraph(g)` の `g` は `std::vector<long long>` でも `std::vector<int>` でもかまいません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `FunctionalGraph(g)` | 頂点 `i` から `g[i]` への辺を持つグラフを作る | $O(n \log n)$ |
| `FunctionalGraph(n)` + `read(padding = -1)` | 標準入力から `g[0], ..., g[n-1]` を読む。頂点番号に `padding` を足す | $O(n \log n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `hop(x, k)` | `x` から `k` 回移動した頂点 | $O(\log n)$ |
| `hopable(x)` | `x` から 0 回以上の移動で到達できる頂点の個数 | $O(1)$ |
| `is_cycle(v)` | `v` がサイクル上にあるか | $O(1)$ |
| `depth(v)` | `v` からサイクルに入るまでの距離 (サイクル上なら 0) | $O(1)$ |
| `root(v)` | `v` から進んで最初に着くサイクル上の頂点 | $O(1)$ |
| `group_id(v)` | `v` が属する連結成分の番号 | $O(1)$ |
| `root_index(v)` | `root(v)` の、対応するサイクル内での位置 | $O(1)$ |
| `groups()` | 連結成分ごとの頂点列 (`const std::vector<std::vector<long long>>&`) | $O(1)$ |
| `cycles()` | 各連結成分のサイクルを辺をたどる順に並べた頂点列 (`const std::vector<std::vector<long long>>&`) | $O(1)$ |

## 関連

- 根付き木の祖先への移動は [木](tree.hpp) の `DoublingClimbTree`
- 一般の有向グラフは [グラフ](graph.hpp)
