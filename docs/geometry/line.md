---
title: 2 次元・3 次元の直線
documentation_of: //src/geometry/line.hpp
---

直線上の異なる 2 点 `p1, p2` を持つ `Line<T, Dim>` と、直線の関数です。`T` の既定は `long long`、`Dim` の既定は 2 で、2 点から座標型と次元を推論します。

```cpp
using P = Vector<long long, 2>;
Line a(P(0, 0), P(2, 2)), b(P(5, 5), P(-1, -1));
bool same = (a == b);  // true: 点の選び方・方向によらず同じ直線
bool parallel = is_parallel(a, b);  // true
using D = Vector<double, 2>;
auto x = line_intersection(Line(D(0, 0), D(1, 1)), Line(D(0, 2), D(2, 0)));  // (1, 1)
using Q = Vector<long long, 3>;
double d = distance_lines(Line(Q(0, 0, 0), Q(1, 0, 0)), Line(Q(0, 1, 1), Q(0, 2, 1)));  // 1
```

`p1 != p2` が必要で、同じ点を渡すと assert で落ちます。公開メンバを変更するときもこの条件を保ってください。等値比較では、選んだ 2 点とその順序を無視します。浮動小数点型の判定では誤差を考慮しません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Line<T, Dim>(p1, p2)` | 2 点を通る直線を作る | $O(1)$ |
| `a == b` / `a != b` | 同じ直線か / 異なる直線か。点の選び方・方向によらない | $O(1)$ |

## 関数

`a, b, line` は同じ座標型・次元の `Line`、`p` は点です。点と直線の関数は直線を先に渡します。計算量は 2 次元・3 次元の場合です。

| 関数 | 説明 | 次元 | 計算量 |
|---|---|---|---|
| `is_parallel(a, b)` | 平行か。一致する場合も `true` | 2・3 | $O(1)$ |
| `is_orthogonal(a, b)` | 直交するか | 2 | $O(1)$ |
| `projection(line, p)` | 点から直線に下ろした垂線の足。浮動小数点型のみ | 2・3 | $O(1)$ |
| `reflection(line, p)` | 直線について対称な点。浮動小数点型のみ | 2 | $O(1)$ |
| `line_intersection(a, b)` | 交点を `std::optional<Vector<T, 2>>` で返す。平行 (一致する場合も含む) なら `std::nullopt`。浮動小数点型のみ | 2 | $O(1)$ |
| `distance_point_line(line, p)` | 点と直線の距離 (`double`) | 2・3 | $O(1)$ |
| `distance_lines(a, b)` | 直線同士の距離 (`double`)。平行でもよい | 3 | $O(1)$ |

2 次元の整数座標の関数は、外積や内積が `T` に収まる必要があります。3 次元の整数座標の関数は `__int128_t` で計算し、座標の絶対値が $10^9$ 程度まで使えます。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `p1` / `p2` | 直線上の異なる 2 点 (`Vector<T, Dim>`) |

## 関連

- 点と 3 点の位置関係 `ccw` は [幾何ベクトル](vector.hpp)
- 線分は [線分](segment.hpp)、平面との平行判定・交点は [平面](plane.hpp)
- 凸多角形を切るには [多角形](polygon.hpp) の `convex_cut(poly, p1, p2)` (向きを表す 2 点を渡す)
- 円・球との交点は [円](circle.hpp)、[球](sphere.hpp)
