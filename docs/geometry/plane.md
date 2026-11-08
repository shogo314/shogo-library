---
title: 平面 (包含・平行判定、距離、直線との交点)
documentation_of: //src/geometry/plane.hpp
---

平面上の一直線上にない 3 点 `p1, p2, p3` を持つ `Plane<T>` と、平面の関数です。`T` の既定は `long long` で、3 点から座標型を推論します。

```cpp
using P = Vector<long long, 3>;
Plane plane(P(0, 0, 0), P(1, 0, 0), P(0, 1, 0));
Plane other(P(2, 3, 0), P(2, 4, 0), P(3, 3, 0));
bool same = plane == other;  // true
bool on = plane.contains(P(2, 3, 0));  // true
bool inside = plane.contains(Line(P(0, 0, 0), P(1, 1, 0)));  // true
Line outside(P(0, 0, 1), P(1, 0, 1));
bool parallel = is_parallel(outside, plane);  // true
bool contained = plane.contains(outside);    // false
using D = Vector<double, 3>;
auto x = line_plane_intersection(Line(D(0, 0, 5), D(1, 1, 4)), Plane(D(0, 0, 0), D(1, 0, 0), D(0, 1, 0)));  // (5, 5, 0)
```

係数への変換・正規化はしません。法線は `cross(p2 - p1, p3 - p1)` です。3 点が一直線上にある場合 (重複した点を含む場合も含む) は assert で落ちます。公開メンバを変更するときもこの条件を保ってください。

整数座標の外積・体積は `__int128_t` で計算し、座標の絶対値が $10^9$ 程度まで使えます。浮動小数点型の判定では誤差を考慮しません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Plane<T>(p1, p2, p3)` | 3 点を通る平面を作る | $O(1)$ |
| `contains(p)` | 点 `p` (`Vector<T, 3>`) が平面上にあるか | $O(1)$ |
| `contains(line)` | `Line<T, 3>` 全体が平面内にあるか。平行でも平面外なら `false` | $O(1)$ |
| `a == b` / `a != b` | 同じ平面か / 異なる平面か。点の選び方・順序・法線の向きによらない | $O(1)$ |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `is_parallel(line, plane)` / `is_parallel(plane, line)` | 直線と平面が平行か。直線が平面内にある場合も `true` | $O(1)$ |
| `is_parallel(a, b)` (`Plane<T>` 同士) | 平面が平行か。一致する場合も `true` | $O(1)$ |
| `distance_point_plane(plane, p)` | 点と平面の距離 (`double`)。整数型でも使える | $O(1)$ |
| `line_plane_intersection(line, plane)` | 交点を `std::optional<Vector<T, 3>>` で返す。平行 (平面に含まれる場合も含む) なら `std::nullopt`。浮動小数点型のみ | $O(1)$ |

`line` は異なる 2 点で表した `Line<T, 3>` を渡します。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `p1` / `p2` / `p3` | 平面上の一直線上にない 3 点 (`Vector<T, 3>`) |

## 関連

- 直線は [直線](line.hpp)、線分は [線分](segment.hpp)
- 三角形の有限の領域は [三角形](triangle.hpp)、球は [球](sphere.hpp)
