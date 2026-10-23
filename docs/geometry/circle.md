---
title: 円 (位置関係、交点、接線、内接円、外接円、共通部分の面積、最小包含円)
documentation_of: //src/geometry/circle.hpp
---

中心 `c` と半径 `r` を持つ円 `Circle<T = double>` と、円に関する関数です。点は [幾何ベクトル](vector.hpp) の `Vector<T, 2>` を使います。

```cpp
Circle c1(Vector(0.0, 0.0), 2.0), c2(Vector(2.0, 0.0), 2.0);
int k = circle_relation(c1, c2);                 // 2 (2点で交わる)
auto ps = circle_circle_intersection(c1, c2);    // (1, -√3), (1, √3)
Circle out = circumcircle(Vector(0.0, 3.0), Vector(4.0, 0.0), Vector(0.0, 0.0));  // 中心 (2, 1.5)、半径 2.5
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Circle()` / `Circle(c, r)` | 中心が原点で半径 0 の円 / 中心 `c`、半径 `r` の円 | $O(1)$ |
| `is >> circle` | "x y r" の順に読み込む | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `c` | 中心 (`Vector<T, 2>`) |
| `r` | 半径 |

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `circle_relation(c1, c2)` | 2つの円の位置関係を、共通接線の本数で返す。4: 離れている、3: 外接、2: 2点で交わる、1: 内接、0: 一方が他方の内部 (2つの円が一致する場合は 1) | ✓ | $O(1)$ |
| `incircle(a, b, c)` | 三角形 $abc$ の内接円 | 浮動小数点型のみ | $O(1)$ |
| `circumcircle(a, b, c)` | 三角形 $abc$ の外接円 (3点は一直線上にないこと) | 浮動小数点型のみ | $O(1)$ |
| `circle_line_intersection(c, p1, p2, eps = 1e-9)` | 円と直線 $p_1 p_2$ の交点 (0〜2個) | 浮動小数点型のみ | $O(1)$ |
| `circle_circle_intersection(c1, c2, eps = 1e-9)` | 2つの円の交点 (0〜2個)。中心が同じなら空 | 浮動小数点型のみ | $O(1)$ |
| `tangent_points(c, p, eps = 1e-9)` | 点 $p$ から円に引いた接線の接点 (0〜2個)。$p$ が円の内部なら空、円周上なら $p$ だけ | 浮動小数点型のみ | $O(1)$ |
| `common_tangents(c1, c2, eps = 1e-9)` | 2つの円の共通接線 (0〜4本、本数は `circle_relation` と同じ)。各接線を (`c1` との接点, `c2` との接点) の `std::pair` で返す。中心が同じなら空 | 浮動小数点型のみ | $O(1)$ |
| `circle_circle_intersection_area(c1, c2)` | 2つの円の共通部分の面積 | 浮動小数点型のみ | $O(1)$ |
| `circle_polygon_intersection_area(c, poly)` | 円と多角形の共通部分の面積。多角形は凸でなくてもよく、向きも問わない | 浮動小数点型のみ | $O(n)$ |
| `minimum_enclosing_circle(points)` | 点の集合 (1 個以上) を含む最小の円 (`EnclosingCircle<T>`)。Welzl の乱択アルゴリズム | 使える (判定が正確になる) | 期待 $O(n)$ |

- 交点や接点は `std::vector` で返し、座標の昇順 (x が小さい順、同じなら y が小さい順) に並べます。
- `common_tangents` は `c1` との接点の座標の昇順に並べます。2つの円が接する点での接線は、2つの接点が同じ点になります (接線は中心を結ぶ直線に垂直です)。
- 交点が 1 個 (接する) かどうかは、距離の差が `eps` 以下かで判定します。例えば `circle_line_intersection` では、中心と直線の距離と半径の差を見ます。
- `circle_relation` は誤差を考えずに比べます。座標と半径が整数なら `Circle<long long>` を使うと正確です。

## 最小包含円 `EnclosingCircle<T>`

`minimum_enclosing_circle` は、円周上にあって円を決める 1 〜 3 点で円を表した `EnclosingCircle<T>` を返します。座標が整数なら、点が円周上にあるかを正確に判定できます。

```cpp
std::vector<Vector<long long, 2>> p = {{0, 0}, {4, 0}, {0, 4}, {1, 1}};
auto c = minimum_enclosing_circle(p);
int s = c.side(Vector<long long, 2>(4, 4));  // 0 (円周上)
Circle<double> d = c.circle();               // 中心 (2, 2)、半径 2√2
```

| 関数・変数 | 説明 | 計算量 |
|---|---|---|
| `support` | 円を決める点 (1 点なら半径 0、2 点ならそれを直径とする円、3 点ならその外接円) | |
| `side(p)` | 点 `p` が内側なら -1、円周上なら 0、外側なら 1。整数型なら `__int128` で正確に判定し、浮動小数点型では誤差を考えない | $O(1)$ |
| `circle()` | 中心と半径 (`Circle<double>`) | $O(1)$ |

3 点のときの判定は、incircle の行列式を三角形の向きで符号を合わせて使います。行列式の項は座標の差の 4 乗程度になるので、整数座標の絶対値が $10^8$ 程度までなら `__int128` であふれません。

## 関連

- 直線・線分の交点や距離は [幾何ベクトル](vector.hpp)
