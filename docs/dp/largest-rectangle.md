---
title: ヒストグラム・グリッドの最大長方形と最大正方形
documentation_of: //src/dp/largest-rectangle.hpp
---

ヒストグラムに含まれる長方形の最大面積と、グリッドで使えるマスだけからなる長方形・正方形の最大の大きさを求めます。

```cpp
long long a = largest_rectangle_in_histogram(std::vector<int>{2, 1, 3, 5, 3, 4, 2, 1});  // 12

std::vector<std::string> g = {"..#..", "#....", "...#.", "...#."};
auto f = [&](long long i, long long j) { return g[i][j] == '.'; };
long long r = largest_rectangle(4, 5, f);  // 6
long long s = largest_square(4, 5, f);     // 2 (2 × 2)
```

- `largest_rectangle_in_histogram` は、高さが単調増加になるようにスタックを持ちます。棒が取り除かれるとき、その棒の高さの長方形の幅が決まります。
- `largest_rectangle` は、各行を底辺として、上に続く使えるマスの個数をヒストグラムにします。
- `largest_square` は、各マスを右下とする正方形の辺の長さの最大値を DP で求めます (上・左・左上の最小値 + 1)。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `largest_rectangle_in_histogram(h)` | 高さ `h[i]` (0 以上) の幅 1 の棒が並んだヒストグラムに含まれる長方形の面積の最大値 (`long long`) | $O(n)$ |
| `largest_rectangle(h, w, f)` | `h` 行 `w` 列のグリッドで、`f(i, j)` が真のマスだけからなる長方形のマスの個数の最大値 | $O(hw)$ |
| `largest_square(h, w, f)` | 同じく、正方形の辺の長さの最大値 (面積はその 2 乗) | $O(hw)$ |

## 関連

- グリッドの近傍をたどるには [Python の range のような整数列と、その直積の Rect](../utility/range.hpp) の `Rect`
