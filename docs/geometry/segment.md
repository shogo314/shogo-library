---
title: 直線・線分 (交差判定、交点、射影、距離)
documentation_of: //src/geometry/segment.hpp
---

2 次元の点 `Vector<T, 2>` ([幾何ベクトル](vector.hpp)) を使う、直線 `Line<T>`・線分 `Segment<T>` と、点・直線・線分の関数です。整数座標でも使える関数は、外積を計算するので座標の絶対値の2乗の数倍が `T` に収まる必要があります。

```cpp
using P = Vector<long long>;
Line a(P(0, 0), P(2, 2));
Line b(P(5, 5), P(-1, -1));
bool same = (a == b);  // true: 選んだ点と向きが違っても同じ直線
Segment s(P(0, 0), P(2, 2)), t(P(0, 2), P(2, 0));
bool hit = segments_intersect(s, t);  // true
bool b = segments_intersect(P(0, 0), P(2, 2), P(0, 2), P(2, 0));  // true
int k = ccw(P(0, 0), P(1, 0), P(1, 1));                           // 1 (反時計回り)
using D = Vector<double>;
auto x = line_intersection(D(0.0, 0.0), D(1.0, 1.0), D(0.0, 2.0), D(2.0, 0.0));  // (1, 1)
double d = distance_point_segment(P(0, 0), P(2, 0), P(3, 4));      // √17
```

`Line<T>` と `Segment<T>` の型を省略したときの既定は `long long` で、2 点を渡すと座標の型を推論します。`Line` は異なる 2 点が必要で、同じ点を渡すと assert で落ちます。`Segment` は長さ 0 も表せますが、交差判定・共有点の計算には使えません。距離の計算には使えます。

## メンバ関数

すべて $O(1)$ です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Line<T>(p1, p2)` | 2 点を通る直線を作る (`p1 != p2`) | $O(1)$ |
| `Segment<T>()` | 原点だけからなる長さ 0 の線分を作る | $O(1)$ |
| `Segment<T>(p1, p2)` | 2 点を端点とする線分を作る | $O(1)$ |
| `a == b` / `a != b` (`Line`) | 同じ直線か / 異なる直線か。選んだ点・方向にはよらない | $O(1)$ |
| `s == t` / `s != t` (`Segment`) | 同じ線分か / 異なる線分か。端点の順序は無視する | $O(1)$ |

公開メンバ `p1`・`p2` は `Vector<T, 2>` です。`Line` は変更後も `p1 != p2` を保ってください。

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

型を受け取る次のオーバーロードも使えます。計算量と戻り値、前提条件は上の点を渡す版と同じです。点と直線・線分の距離では、直線・線分を先に渡します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `segments_intersect(s, t)` / `segment_intersection(s, t)` | `Segment` 同士の交差判定 / 共有点 | $O(1)$ |
| `is_parallel(a, b)` / `is_orthogonal(a, b)` | `Line` 同士の平行 / 直交判定 | $O(1)$ |
| `line_intersection(a, b)` | `Line` 同士の交点 | $O(1)$ |
| `projection(a, p)` / `reflection(a, p)` | `Line` への射影 / 反射 | $O(1)$ |
| `distance_point_line(a, p)` | `Line` と点の距離 | $O(1)$ |
| `distance_point_segment(s, p)` | `Segment` と点の距離 | $O(1)$ |
| `distance_segments(s, t)` | `Segment` 同士の距離 | $O(1)$ |

浮動小数点型でも、`Line` の等値比較、`ccw` や `is_parallel` などの判定は誤差を考えずに `0` と比べます。誤差が問題になる場合は、整数座標で計算してください。

## 関連

- 点・ベクトルの型と内積・外積は [幾何ベクトル](vector.hpp)
- 多角形は [多角形](polygon.hpp)、円は [円](circle.hpp)
- x 軸・y 軸に平行な線分の交差を数えるなら [軸に平行な線分の交点の個数](axis-parallel-segments.hpp)
- 3 次元の直線・線分は [3 次元の直線・線分・平面](segment-3d.hpp)
