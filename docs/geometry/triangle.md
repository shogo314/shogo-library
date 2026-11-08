---
title: 2 次元・3 次元の三角形
documentation_of: //src/geometry/triangle.hpp
---

一直線上にない 3 頂点を持つ `Triangle<T, Dim>` です。頂点の順序を保持し、等値比較では順序によらず同じ三角形かを判定します。

```cpp
using P = Vector<long long, 2>;
Triangle triangle(P(0, 0), P(3, 0), P(0, 4));  // Triangle<long long, 2>
Triangle reversed(P(0, 4), P(3, 0), P(0, 0));
bool same = (triangle == reversed);  // true
using Q = Vector<double, 3>;
Triangle spatial(Q(0, 0, 0), Q(1, 0, 0), Q(0, 1, 1));  // Triangle<double, 3>
```

`T` の既定は `long long`、`Dim` の既定は 2 で、次元は 2 または 3 に限ります。3 頂点を渡すと座標型と次元を推論します。一直線上の 3 点や重複した頂点は assert で落ちます。公開メンバを変更するときも、この条件を保ってください。

整数座標の退化判定は `__int128_t` で計算します。座標の絶対値が $10^9$ 程度まで使えます。浮動小数点型では、退化判定・等値比較ともに誤差を考慮しません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Triangle<T, Dim>(p1, p2, p3)` | 3 頂点から三角形を作る | $O(1)$ |
| `a == b` / `a != b` | 同じ三角形か / 異なる三角形か。頂点の順序は無視する | $O(1)$ |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `segment_triangle_intersect(segment, triangle)` | 3 次元の線分と三角形 (周と内部) が共有点を持つか。同じ平面上の場合・長さ 0 の線分も扱う | $O(1)$ |

`segment` は `Segment<T, 3>`、`triangle` は `Triangle<T, 3>` です。整数座標では誤差なく判定します。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `p1` / `p2` / `p3` | 一直線上にない 3 頂点 (`Vector<T, Dim>`) |

## 関連

- 2 次元の内接円・外接円は [円](circle.hpp) の `incircle(triangle)`・`circumcircle(triangle)`
- 線分の型と距離は [線分](segment.hpp)、三角形を含む無限の平面は [平面](plane.hpp)
- 多角形の面積・包含判定は [多角形](polygon.hpp)
