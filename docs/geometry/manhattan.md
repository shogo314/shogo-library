---
title: マンハッタン距離 (最近点対・最遠点対、各点から最も近い点・最も遠い点)
documentation_of: //src/geometry/manhattan.hpp
---

平面上の点の集合で、マンハッタン距離 $\lvert x_i - x_j \rvert + \lvert y_i - y_j \rvert$ が最も近い・最も遠い点を、完全グラフを作らずに求めます。

```cpp
std::vector<Vector<long long, 2>> p = { {0, 0}, {3, 1}, {1, 4}, {1, 1} };
auto near = manhattan_nearest_points(p);   // {3, 3, 3, 0 か 1} (点 3 からは点 0 と点 1 がどちらも距離 2)
auto far = manhattan_farthest_points(p);   // {2, 2, 0 か 1, 2} (点 2 からは点 0 と点 1 がどちらも距離 5)
auto c = manhattan_closest_pair(p);        // c.dist = 2、c.i = 0、c.j = 3
auto f = manhattan_farthest_pair(p);       // f.dist = 5
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `manhattan_nearest_points(ps)` | 各点から最も近いほかの点の添字の `std::vector<long long>`。点が 1 個なら `{-1}` | $O(n \log n)$ |
| `manhattan_farthest_points(ps)` | 各点から最も遠い点の添字の `std::vector<long long>` (自分自身は除く)。点が 1 個なら `{-1}` | $O(n)$ |
| `manhattan_closest_pair(ps)` | 最近点対の距離と添字 (`.dist`、`.i`、`.j`。$i < j$)。点は 2 個以上 | $O(n \log n)$ |
| `manhattan_farthest_pair(ps)` | 最遠点対の距離と添字 (`.dist`、`.i`、`.j`。$i < j$)。点は 2 個以上 | $O(n)$ |

- 同じ位置の点があってもかまいません (距離 0 の相手として扱います)。最も近い・遠い点が複数あるとき、どれを返すかは決めていません。
- 最も近い点は、[マンハッタン距離の最小全域木](manhattan-mst.hpp) と同じく、各点を頂点とする 45 度ずつの 8 つの領域のそれぞれで最も近い点を、点を掃いて求めます。
- 最も遠い点は、$\lvert dx \rvert + \lvert dy \rvert = \max(\lvert du \rvert, \lvert dv \rvert)$ ($u = x + y$、$v = x - y$) なので、$u$ と $v$ が最大・最小の 4 点のどれかです。
- チェビシェフ距離 $\max(\lvert dx \rvert, \lvert dy \rvert)$ の場合は、点を $(x + y, x - y)$ に移すとマンハッタン距離の 2 倍になります。

## 関連

- 最小全域木は [マンハッタン距離の最小全域木](manhattan-mst.hpp)
- ユークリッド距離の最近点対・最遠点対は [最近点対・最遠点対](point-pair.hpp)
