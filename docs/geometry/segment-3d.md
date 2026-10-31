---
title: 3 次元の直線・線分・平面 (距離、直線と平面の交点、線分と三角形の交差)
documentation_of: //src/geometry/segment-3d.hpp
---

3 次元の点 `Vector<T, 3>` ([幾何ベクトル](vector.hpp)) を使う、点・直線・線分・平面の関数です。2 次元の同じ名前の関数 (`distance_point_line` など) を 3 次元に広げたものです。

```cpp
using P = Vector<long long, 3>;
double d = distance_segments(P(0, 0, 0), P(2, 0, 0), P(1, 1, 1), P(1, 1, 3));   // √2
bool hit = segment_triangle_intersect(P(0, 0, -1), P(0, 0, 1), P(-1, -1, 0), P(1, -1, 0), P(0, 1, 0));  // true
using D = Vector<double, 3>;
auto x = line_plane_intersection(D(0.0, 0.0, 5.0), D(1.0, 1.0, 4.0), D(0.0, 0.0, 0.0), D(1.0, 0.0, 0.0), D(0.0, 1.0, 0.0));  // (5, 5, 0)
```

平面は、一直線上にない 3 点 $a, b, c$ で表します (法線は `cross(b - a, c - a)`)。

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `distance_point_line(p1, p2, p)` | 点 $p$ と直線 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_point_segment(p1, p2, p)` | 点 $p$ と線分 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_lines(p1, p2, q1, q2)` | 直線 $p_1 p_2$ と $q_1 q_2$ の距離 (`double`、平行でもよい) | ✓ | $O(1)$ |
| `distance_segments(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ の距離 (`double`、長さ 0 の線分でもよい) | ✓ | $O(1)$ |
| `distance_point_plane(a, b, c, p)` | 点 $p$ と平面 $abc$ の距離 (`double`) | ✓ | $O(1)$ |
| `projection(p1, p2, p)` | 点 $p$ から直線 $p_1 p_2$ に下ろした垂線の足 | 浮動小数点型のみ | $O(1)$ |
| `line_plane_intersection(p1, p2, a, b, c)` | 直線 $p_1 p_2$ と平面 $abc$ の交点を `std::optional` で返す (平行 (平面に含まれる場合も含む) なら `std::nullopt`) | 浮動小数点型のみ | $O(1)$ |
| `segment_triangle_intersect(p1, p2, a, b, c)` | 線分 $p_1 p_2$ と三角形 $abc$ (周と内部) が共有点を持つか。同じ平面上にある場合も扱う | ✓ (正確) | $O(1)$ |

- 直線の 2 点が同じ点のときや、平面・三角形の 3 点が一直線上にあるときは assert で落ちます (`distance_point_segment` と `distance_segments` は長さ 0 の線分でもかまいません)。
- 整数型の座標では、外積や体積を `__int128_t` で計算します。座標の絶対値が $10^9$ 程度まで使えます。`segment_triangle_intersect` は整数座標なら誤差なく判定します。
- 浮動小数点型でも、`line_plane_intersection` の平行の判定は誤差を考えずに `0` と比べます。

## 関連

- 2 次元の直線・線分は [直線・線分](segment.hpp)、点・ベクトルの型は [幾何ベクトル](vector.hpp)
- 球は [球](sphere.hpp)
