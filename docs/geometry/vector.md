---
title: 幾何ベクトル
documentation_of: //src/geometry/vector.hpp
---

点・ベクトルを表す `Vector<T = double, Dim = 2>` と、内積・外積です。幾何の関数は、話題ごとに [直線・線分](segment.hpp)・[多角形](polygon.hpp)・[最近点対・最遠点対](point-pair.hpp) などに分けてあります。

```cpp
using P = Vector<long long>;
std::vector<P> ps(n);
for (auto& p : ps) std::cin >> p;      // "x y" を読む
P a(1, 2), b(3, -1);
long long c = cross(a, b);             // -7
long long d = dot(a, b);               // 1
Vector<double, 3> u(1.0, 0.0, 0.0), w = cross(u, Vector<double, 3>(0.0, 1.0, 0.0));  // (0, 0, 1)
```

## メンバ関数

`Vector<T, Dim>` のメンバと、`Vector` を受け取る演算子です。計算量の $d$ は次元 `Dim` です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Vector()` / `Vector(x, y, ...)` | ゼロベクトル / 成分を指定。型を省くと、成分の共通の型と個数から推論する (`Vector(2LL, 3LL)` は `Vector<long long, 2>`、`Vector(0.0, 0.0)` は `Vector<double, 2>`)。`Vector()` は `Vector<double, 2>` | $O(d)$ |
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

## 関連

- 2 次元の点・直線・線分 (交差判定、交点、射影、距離) は [直線・線分](segment.hpp)
- 多角形 (面積、重心、内外判定、凸包、切断) は [多角形](polygon.hpp)
- 最近点対・最遠点対は [最近点対・最遠点対](point-pair.hpp)
- 円は [円](circle.hpp)、偏角ソートは [偏角](angle.hpp) の `Angle` (`Angle(p) < Angle(q)` で比べる)
- 3 次元の点・直線・平面は [3 次元の直線・線分・平面](segment-3d.hpp)、球は [球](sphere.hpp)
- 傾きや比を誤差なく比べるには [有理数](../math/rational.hpp)
