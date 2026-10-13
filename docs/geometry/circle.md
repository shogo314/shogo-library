---
title: 円 (位置関係、交点、接線、内接円、外接円)
documentation_of: //src/geometry/circle.hpp
---

中心 `c` と半径 `r` を持つ円 `Circle<T = double>` と、円に関する関数です。点は [幾何ベクトル](vector.hpp) の `Vector<T, 2>` を使います。

```cpp
Circle c1(Vector(0.0, 0.0), 2.0), c2(Vector(2.0, 0.0), 2.0);
int k = circle_relation(c1, c2);                 // 2 (2点で交わる)
auto ps = circle_circle_intersection(c1, c2);    // (1, -√3), (1, √3)
Circle out = circumcircle(Vector(0.0, 3.0), Vector(4.0, 0.0), Vector(0.0, 0.0));  // 中心 (2, 1.5)、半径 2.5
```

| メンバ・関数 | 説明 | 整数型 |
|---|---|:-:|
| `Circle(c, r)` | 中心 `c`、半径 `r` の円。`is >> circle` で "x y r" の順に読み込む | ✓ |
| `circle_relation(c1, c2)` | 2つの円の位置関係を、共通接線の本数で返す。4: 離れている、3: 外接、2: 2点で交わる、1: 内接、0: 一方が他方の内部 (2つの円が一致する場合は 1) | ✓ |
| `incircle(a, b, c)` | 三角形 $abc$ の内接円 | 浮動小数点型のみ |
| `circumcircle(a, b, c)` | 三角形 $abc$ の外接円 (3点は一直線上にないこと) | 浮動小数点型のみ |
| `circle_line_intersection(c, p1, p2, eps = 1e-9)` | 円と直線 $p_1 p_2$ の交点 (0〜2個) | 浮動小数点型のみ |
| `circle_circle_intersection(c1, c2, eps = 1e-9)` | 2つの円の交点 (0〜2個)。中心が同じなら空 | 浮動小数点型のみ |
| `tangent_points(c, p, eps = 1e-9)` | 点 $p$ から円に引いた接線の接点 (0〜2個)。$p$ が円の内部なら空、円周上なら $p$ だけ | 浮動小数点型のみ |

- 交点や接点は `std::vector` で返し、座標の昇順 (x が小さい順、同じなら y が小さい順) に並べます。
- 交点が 1 個 (接する) かどうかは、距離の差が `eps` 以下かで判定します。例えば `circle_line_intersection` では、中心と直線の距離と半径の差を見ます。
- `circle_relation` は誤差を考えずに比べます。座標と半径が整数なら `Circle<long long>` を使うと正確です。

## 関連

- 直線・線分の交点や距離は [幾何ベクトル](vector.hpp)
