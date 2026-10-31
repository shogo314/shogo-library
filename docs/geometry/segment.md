---
title: 直線・線分 (交差判定、交点、射影、距離)
documentation_of: //src/geometry/segment.hpp
---

2 次元の点 `Vector<T, 2>` ([幾何ベクトル](vector.hpp)) を使う、点・直線・線分の関数です。整数座標でも使える関数は、外積を計算するので座標の絶対値の2乗の数倍が `T` に収まる必要があります。

```cpp
using P = Vector<long long>;
bool b = segments_intersect(P(0, 0), P(2, 2), P(0, 2), P(2, 0));  // true
int k = ccw(P(0, 0), P(1, 0), P(1, 1));                           // 1 (反時計回り)
using D = Vector<double>;
auto x = line_intersection(D(0.0, 0.0), D(1.0, 1.0), D(0.0, 2.0), D(2.0, 0.0));  // (1, 1)
double d = distance_point_segment(P(0, 0), P(2, 0), P(3, 4));      // √17
```

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `segments_intersect(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ が共有点を持つか (長さ 0 の線分は assert で落ちる) | ✓ | $O(1)$ |
| `segment_intersection(p1, p2, q1, q2)` | 共有点の1つを `std::optional` で返す (共有点がなければ `std::nullopt`。長さ 0 の線分は assert で落ちる) | 浮動小数点型のみ | $O(1)$ |
| `ccw(a, b, c)` | 3点の位置関係。1: $a \to b \to c$ が反時計回り、-1: 時計回り、2: $c, a, b$ の順に一直線上、-2: $a, b, c$ の順に一直線上、0: $c$ が線分 $ab$ 上 | ✓ | $O(1)$ |
| `is_parallel(p1, p2, q1, q2)` / `is_orthogonal(p1, p2, q1, q2)` | 直線 $p_1 p_2$ と $q_1 q_2$ が平行か / 直交するか | ✓ | $O(1)$ |
| `projection(p1, p2, p)` | 点 $p$ から直線 $p_1 p_2$ に下ろした垂線の足 | 浮動小数点型のみ | $O(1)$ |
| `reflection(p1, p2, p)` | 直線 $p_1 p_2$ について $p$ と対称な点 | 浮動小数点型のみ | $O(1)$ |
| `line_intersection(p1, p2, q1, q2)` | 直線 $p_1 p_2$ と $q_1 q_2$ の交点を `std::optional` で返す (平行 (重なる直線も含む) なら `std::nullopt`。$p_1 = p_2$ や $q_1 = q_2$ は assert で落ちる) | 浮動小数点型のみ | $O(1)$ |
| `distance_point_line(p1, p2, p)` | 点 $p$ と直線 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_point_segment(p1, p2, p)` | 点 $p$ と線分 $p_1 p_2$ の距離 (`double`) | ✓ | $O(1)$ |
| `distance_segments(p1, p2, q1, q2)` | 線分 $p_1 p_2$ と $q_1 q_2$ の距離 (`double`、交われば 0) | ✓ | $O(1)$ |

浮動小数点型でも、`ccw` や `is_parallel` などの判定は誤差を考えずに `0` と比べます。誤差が問題になる場合は、整数座標で計算してください。

## 関連

- 点・ベクトルの型と内積・外積は [幾何ベクトル](vector.hpp)
- 多角形は [多角形](polygon.hpp)、円は [円](circle.hpp)
- x 軸・y 軸に平行な線分の交差を数えるなら [軸に平行な線分の交点の個数](axis-parallel-segments.hpp)
- 3 次元の直線・線分は [3 次元の直線・線分・平面](segment-3d.hpp)
