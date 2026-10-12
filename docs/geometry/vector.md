---
title: 幾何ベクトル
documentation_of: //src/geometry/vector.hpp
---

点・ベクトルを表す `Vector<T = double, Dim = 2>` と、それを使う幾何の関数です。整数座標でも使える関数は、外積を計算するので座標の絶対値の2乗の数倍が `T` に収まる必要があります。

```cpp
using P = Vector<long long>;
std::vector<P> ps(n);
for (auto& p : ps) std::cin >> p;      // "x y" を読む
auto hull = convex_hull(ps);           // 凸包 (反時計回り)
long long s2 = polygon_area_doubled(hull);
std::sort(ps.begin(), ps.end(), P::ArgSortComp());  // 偏角ソート
```

## `Vector<T, Dim>` のメンバ

| メンバ | 説明 |
|---|---|
| `Vector()` / `Vector(x, y, ...)` | ゼロベクトル / 成分を指定 |
| `p[i]` | `i` 番目の成分 |
| `+`、`-` (単項・二項)、`+=`、`-=` | 加減算 |
| `p * c`、`c * p`、`p / c`、`*=`、`/=` | スカラー倍 (整数型で割り切れない除算は assert で落ちる) |
| `==`、`!=`、`<`、`<=`、`>`、`>=` | 成分の辞書式順序で比較 |
| `dot(p, q)` | 内積 |
| `p.squared_norm()` | 長さの2乗 |
| `p.abs()` | 長さ (`double`) |
| `Vector::ArgSortComp` | 偏角ソートの比較関数 (2次元、x 軸正方向から反時計回り、ゼロベクトルは x 軸正方向と同じ扱い) |
| `is >> p`、`os << p` | 成分を空白区切りで入出力 |

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `cross(p, q)` | 外積。2次元ではスカラー (符号付き面積)、3次元ではベクトル | ✓ | $O(1)$ |
| `segments_intersect(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ が共有点を持つか | ✓ | $O(1)$ |
| `segment_intersect(p1, p2, q1, q2)` | 共有点の1つを `std::optional` で返す (共有点がなければ `std::nullopt`) | 浮動小数点型のみ | $O(1)$ |
| `polygon_area_doubled(poly)` | 多角形の符号付き面積の2倍 (反時計回りなら正) | ✓ | $O(n)$ |
| `polygon_area(poly)` | 多角形の面積 (`double`、向きは問わない) | ✓ | $O(n)$ |
| `polygon_is_convex(poly)` | 多角形 (反時計回り) が凸か | ✓ | $O(n)$ |
| `polygon_contains(poly, p)` | 点が多角形 (反時計回り) の 0: 外部、1: 辺上、2: 内部 | ✓ | $O(n)$ |
| `convex_hull(ps, include_straight = false)` | 凸包 (反時計回り)。`include_straight` で 180 度の頂点を含めるか選ぶ | ✓ | $O(n \log n)$ |
| `select_convex(ps, include_straight = false)` | 順番を保った半凸包。x の昇順なら下凸包、降順なら上凸包 | ✓ | $O(n)$ |
| `closest_point_pair_squared(ps)` | 最近点対の距離の2乗と添字 (`.squared_dist`、`.i`、`.j`) | ✓ | $O(n \log^2 n)$ |
| `closest_point_pair(ps)` | 最近点対の距離と添字 (`.dist`、`.i`、`.j`) | ✓ | $O(n \log^2 n)$ |
