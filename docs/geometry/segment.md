---
title: 2 次元・3 次元の線分
documentation_of: //src/geometry/segment.hpp
---

2 端点 `p1, p2` を持つ `Segment<T, Dim>` と、線分の関数です。`T` の既定は `long long`、`Dim` の既定は 2 で、2 点から座標型と次元を推論します。

```cpp
using P = Vector<long long, 2>;
Segment s(P(0, 0), P(2, 2)), t(P(0, 2), P(2, 0));
bool hit = segments_intersect(s, t);  // true
bool same = s == Segment(P(2, 2), P(0, 0));  // true
using Q = Vector<long long, 3>;
double d = distance_segments(Segment(Q(0, 0, 0), Q(2, 0, 0)), Segment(Q(1, 1, 1), Q(1, 1, 3)));  // √2
```

長さ 0 の線分も表せますが、`segments_intersect`・`segment_intersection` は長さ 0 の線分を受け取ると assert で落ちます。距離の計算には使えます。浮動小数点型の判定では誤差を考慮しません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Segment<T, Dim>()` | 原点だけからなる長さ 0 の線分を作る | $O(1)$ |
| `Segment<T, Dim>(p1, p2)` | 2 点を端点とする線分を作る | $O(1)$ |
| `s == t` / `s != t` | 同じ線分か / 異なる線分か。端点の順序は無視する | $O(1)$ |

## 関数

`s, t` は同じ座標型・次元の `Segment`、`p` は点です。点と線分の関数は線分を先に渡します。

| 関数 | 説明 | 次元 | 計算量 |
|---|---|---|---|
| `segments_intersect(s, t)` | 共有点を持つか。端点で接する場合・重なる場合も `true`。整数型でも使える | 2 | $O(1)$ |
| `segment_intersection(s, t)` | 共有点の 1 つを `std::optional<Vector<T, 2>>` で返す。共有点がなければ `std::nullopt`。浮動小数点型のみ | 2 | $O(1)$ |
| `distance_point_segment(s, p)` | 点と線分の距離 (`double`)。整数型でも使える | 2・3 | $O(1)$ |
| `distance_segments(s, t)` | 線分同士の距離 (`double`)。整数型でも使える | 2・3 | $O(1)$ |

2 次元の整数座標では外積や内積が `T` に収まる必要があります。3 次元では整数の外積・内積を `__int128_t` で計算し、座標の絶対値が $10^9$ 程度まで使えます。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `p1` / `p2` | 2 端点 (`Vector<T, Dim>`) |

## 関連

- 直線は [直線](line.hpp)、3 点の位置関係 `ccw` は [幾何ベクトル](vector.hpp)
- 3 次元の線分と三角形の交差は [三角形](triangle.hpp)
- 軸に平行な線分の交点の個数は [軸に平行な線分](axis-parallel-segments.hpp)
