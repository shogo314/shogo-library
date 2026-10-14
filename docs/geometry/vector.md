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
std::sort(ps.begin(), ps.end(), [](const P& a, const P& b) { return Angle(a) < Angle(b); });  // 偏角ソート (angle.hpp)
```

## メンバ関数

`Vector<T, Dim>` のメンバと、`Vector` を受け取る演算子です。計算量の $d$ は次元 `Dim` です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Vector()` / `Vector(x, y, ...)` | ゼロベクトル / 成分を指定 | $O(d)$ |
| `p[i]` | `i` 番目の成分 | $O(1)$ |
| `+`、`-` (単項・二項)、`+=`、`-=` | 加減算 | $O(d)$ |
| `p * c`、`c * p`、`p / c`、`*=`、`/=` | スカラー倍 (整数型で割り切れない除算は assert で落ちる) | $O(d)$ |
| `==`、`!=`、`<`、`<=`、`>`、`>=` | 成分の辞書式順序で比較 | $O(d)$ |
| `dot(p, q)` | 内積 | $O(d)$ |
| `p.squared_norm()` | 長さの2乗 | $O(d)$ |
| `p.abs()` | 長さ (`double`) | $O(d)$ |
| `is >> p`、`os << p` | 成分を空白区切りで入出力 | $O(d)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `v` | 成分 (`std::array<T, Dim>`) |

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `cross(p, q)` | 外積。2次元ではスカラー (符号付き面積)、3次元ではベクトル | ✓ | $O(1)$ |
| `segments_intersect(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ が共有点を持つか | ✓ | $O(1)$ |
| `segment_intersection(p1, p2, q1, q2)` | 共有点の1つを `std::optional` で返す (共有点がなければ `std::nullopt`) | 浮動小数点型のみ | $O(1)$ |
| `ccw(a, b, c)` | 3点の位置関係。1: $a \to b \to c$ が反時計回り、-1: 時計回り、2: $c, a, b$ の順に一直線上、-2: $a, b, c$ の順に一直線上、0: $c$ が線分 $ab$ 上 | ✓ | $O(1)$ |
| `is_parallel(p1, p2, q1, q2)` / `is_orthogonal(p1, p2, q1, q2)` | 直線 $p_1 p_2$ と $q_1 q_2$ が平行か / 直交するか | ✓ | $O(1)$ |
| `projection(p1, p2, p)` | 点 $p$ から直線 $p_1 p_2$ に下ろした垂線の足 | 浮動小数点型のみ | $O(1)$ |
| `reflection(p1, p2, p)` | 直線 $p_1 p_2$ について $p$ と対称な点 | 浮動小数点型のみ | $O(1)$ |
| `line_intersection(p1, p2, q1, q2)` | 直線 $p_1 p_2$ と $q_1 q_2$ の交点を `std::optional` で返す (平行なら `std::nullopt`) | 浮動小数点型のみ | $O(1)$ |
| `distance_point_line(p1, p2, p)` | 点 $p$ と直線 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_point_segment(p1, p2, p)` | 点 $p$ と線分 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_segments(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ の距離 (`double`、交われば 0) | ✓ | $O(1)$ |
| `polygon_area_doubled(poly)` | 多角形の符号付き面積の2倍 (反時計回りなら正) | ✓ | $O(n)$ |
| `polygon_area(poly)` | 多角形の面積 (`double`、向きは問わない) | ✓ | $O(n)$ |
| `polygon_is_convex(poly)` | 多角形 (反時計回り) が凸か | ✓ | $O(n)$ |
| `polygon_contains(poly, p)` | 点が多角形 (反時計回り) の 0: 外部、1: 辺上、2: 内部 | ✓ | $O(n)$ |
| `convex_hull(ps, include_straight = false)` | 凸包 (反時計回り)。`include_straight` で 180 度の頂点を含めるか選ぶ | ✓ | $O(n \log n)$ |
| `select_convex(ps, include_straight = false)` | 順番を保った半凸包。x の昇順なら下凸包、降順なら上凸包 | ✓ | $O(n)$ |
| `closest_point_pair_squared(ps)` | 最近点対の距離の2乗と添字 (`.squared_dist`、`.i`、`.j`) | ✓ | $O(n \log^2 n)$ |
| `closest_point_pair(ps)` | 最近点対の距離と添字 (`.dist`、`.i`、`.j`) | ✓ | $O(n \log^2 n)$ |

浮動小数点型でも、`ccw` や `is_parallel` などの判定は誤差を考えずに `0` と比べます。誤差が問題になる場合は、整数座標で計算してください。

## 関連

- 円の交点・接線・内接円・外接円は [円](circle.hpp)
- 偏角ソートは [偏角](angle.hpp) の `Angle` (`Angle(p) < Angle(q)` で比べる)
- 傾きや比を誤差なく比べるには [有理数](../math/rational.hpp)
