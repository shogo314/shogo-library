---
title: 球 (直線との交点、球どうしの交わり、共通部分の体積、大円距離)
documentation_of: //src/geometry/sphere.hpp
---

中心 `c` と半径 `r` を持つ球 `Sphere<T = double>` と、球に関する関数です。点は [幾何ベクトル](vector.hpp) の `Vector<T, 3>` を使います。

```cpp
using D = Vector<double, 3>;
Sphere s1(D(0.0, 0.0, 0.0), 2.0), s2(D(2.0, 0.0, 0.0), 2.0);
auto ps = sphere_line_intersection(s1, Line(D(-5.0, 0.0, 0.0), D(5.0, 0.0, 0.0)));  // (-2, 0, 0), (2, 0, 0)
auto c = sphere_sphere_intersection(s1, s2);      // 中心 (1, 0, 0)、法線 (1, 0, 0)、半径 √3 の円
double v = sphere_sphere_intersection_volume(s1, s2);  // 10π/3
double d = great_circle_distance(lat1, lon1, lat2, lon2, 6378.1);  // 緯度・経度 (ラジアン) から地球上の距離
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Sphere()` / `Sphere(c, r)` | 中心が原点で半径 0 の球 / 中心 `c`、半径 `r` の球 | $O(1)$ |
| `is >> sphere` | "x y z r" の順に読み込む | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `c` | 中心 (`Vector<T, 3>`) |
| `r` | 半径 |

`sphere_line_intersection` の `line` は `Line<T, 3>` です。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sphere_line_intersection(s, line, eps = 1e-9)` | 球と直線 $p_1 p_2$ の交点 (0〜2個)。座標の辞書順 (x、y、z の順に比較) に並べる。$p_1 = p_2$ なら assert で落ちる | $O(1)$ |
| `sphere_sphere_intersection(s1, s2, eps = 1e-9)` | 2つの球面が交わってできる円を `std::optional<SpaceCircle<T>>` で返す。交わらない (離れている、一方が他方の内部、同心で半径が違う) なら `std::nullopt`、接するなら半径 0 の円 (中心が接点)。同じ球は assert で落ちる | $O(1)$ |
| `sphere_sphere_intersection_volume(s1, s2)` | 2つの球の共通部分の体積 | $O(1)$ |
| `great_circle_distance(lat1, lon1, lat2, lon2, r = 1)` | 半径 $r$ の球面上の 2 点 (緯度・経度はラジアン) の最短距離 (大円距離) | $O(1)$ |

- すべて浮動小数点型のみです。
- `sphere_line_intersection` は、2 次元の `circle_line_intersection` と同じく座標順に並べます。直線を表す 2 点を逆順にしても交点の並びは同じです。光線が最初に当たる点を選ぶときは、全交点について進行方向のパラメータを調べ、条件を満たす最小のものを選びます。
- 接する (交点が 1 個) かどうかは、距離の差が `eps` 以下かで判定します。`sphere_sphere_intersection` は、中心間の距離と半径の差がともに `eps` 以下なら同じ球とみなします。
- 緯度・経度が度で与えられたら、`x * std::acos(-1.0) / 180` でラジアンにします。経度は東経を正、西経を負にします。

## 空間内の円 `SpaceCircle<T>`

`sphere_sphere_intersection` の戻り値です。

| 変数 | 説明 |
|---|---|
| `c` | 中心 (`Vector<T, 3>`) |
| `n` | 円を含む平面の単位法線ベクトル (`s1` の中心から `s2` の中心への向き) |
| `r` | 半径 (接するなら 0) |

## 関連

- 直線の距離・射影は [直線](line.hpp)、平面との距離・交点は [平面](plane.hpp)
- 2 次元の円は [円](circle.hpp)
