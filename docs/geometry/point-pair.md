---
title: 最近点対・最遠点対
documentation_of: //src/geometry/point-pair.hpp
---

2 次元の点の集合から、最も近い 2 点と最も遠い 2 点を求めます。整数座標なら、距離の 2 乗を誤差なく求められます。

```cpp
using P = Vector<long long>;
std::vector<P> ps = { {0, 0}, {3, 4}, {1, 1}, {-2, 5} };
auto c = closest_point_pair_squared(ps);  // c.squared_dist = 2、c.i = 0、c.j = 2
auto f = farthest_point_pair(ps);         // f.dist = √29、f.i = 0、f.j = 3
```

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `closest_point_pair_squared(ps)` | 最近点対の距離の2乗と添字 (`.squared_dist`、`.i`、`.j`。添字は `long long`)。点は 2 個以上 (でなければ assert で落ちる) | ✓ | $O(n \log^2 n)$ |
| `closest_point_pair(ps)` | 最近点対の距離と添字 (`.dist`、`.i`、`.j`。添字は `long long`)。点は 2 個以上 (でなければ assert で落ちる) | ✓ | $O(n \log^2 n)$ |
| `farthest_point_pair_squared(ps)` | 最遠点対の距離の2乗と添字 (`.squared_dist`、`.i`、`.j`。$i \ne j$)。凸包を作り、回転キャリパー法で調べる。点は 2 個以上 | ✓ | $O(n \log n)$ |
| `farthest_point_pair(ps)` | 最遠点対の距離と添字 (`.dist`、`.i`、`.j`)。凸多角形の直径にも使える | ✓ | $O(n \log n)$ |

- 戻り値の添字 `i`・`j` は、入力の点の添字です。
- `farthest_point_pair_squared` は、座標の差の 2 乗の和の 2 倍が `T` に収まる必要があります。

## 関連

- 点・ベクトルの型は [幾何ベクトル](vector.hpp)
- 最遠点対が使う凸包は [多角形](polygon.hpp) の `convex_hull`
