---
title: ファンクショナルグラフ
documentation_of: //src/graph/functional-graph.hpp
---

$n$ 頂点 $n$ 辺で、すべての頂点の出次数が 1 の有向グラフ (頂点 $i$ から $g_i$ への辺) です。各連結成分はサイクル 1 つと、そこに流れ込む木からなります。

```cpp
FunctionalGraph fg(std::vector<int>{1, 2, 0, 0, 3});  // 0→1→2→0 のサイクルに 4→3→0 が流れ込む
int v = fg.hop(4, 10);       // 4 から 10 回移動した頂点: 2
int c = fg.hopable(4);       // 4 から到達できる頂点の個数: 5
bool b = fg.is_cycle[3];     // false
```

`FunctionalGraph(n)` で作った場合は、`read()` で入力するまで前計算が行われません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `FunctionalGraph(g)` | 頂点 `i` から `g[i]` への辺を持つグラフを作る | $O(n \log n)$ |
| `FunctionalGraph(n)` + `read(padding = -1)` | 標準入力から `g[0], ..., g[n-1]` を読む。頂点番号に `padding` を足す | $O(n \log n)$ |
| `hop(x, k)` | `x` から `k` 回移動した頂点 (`k` は `long long` でよい) | $O(\log n)$ |
| `hopable(x)` | `x` から 0 回以上の移動で到達できる頂点の個数 | $O(1)$ |

## メンバ変数

| 変数 | 内容 |
|---|---|
| `n` / `g` | 頂点数 / 各頂点の行き先 |
| `is_cycle[v]` | `v` がサイクル上にあるか |
| `depth[v]` | `v` からサイクルに入るまでの距離 (サイクル上なら 0) |
| `root[v]` | `v` から進んで最初に着くサイクル上の頂点 |
| `connected_id[v]` | `v` が属する連結成分の番号 |
| `connected_list[c]` | 連結成分 `c` の頂点のリスト |
| `cycle_list[c]` | 連結成分 `c` のサイクルの頂点を、辺をたどる順に並べたリスト |
| `root_idx[v]` | `root[v]` の `cycle_list` 上の位置 |
