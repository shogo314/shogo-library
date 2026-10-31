---
title: 球 (直線との交点、球どうしの交わり、共通部分の体積、大円距離)
documentation_of: //src/geometry/sphere.hpp
---

中心 `c` と半径 `r` を持つ球 `Sphere<T = double>` と、球に関する関数です。点は [幾何ベクトル](vector.hpp) の `Vector<T, 3>` を使います。

```cpp
using D = Vector<double, 3>;
Sphere s1(D(0.0, 0.0, 0.0), 2.0), s2(D(2.0, 0.0, 0.0), 2.0);
auto ps = sphere_line_intersection(s1, D(-5.0, 0.0, 0.0), D(5.0, 0.0, 0.0));  // (-2, 0, 0), (2, 0, 0)
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

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sphere_line_intersection(s, p1, p2, eps = 1e-9)` | 球と直線 $p_1 p_2$ の交点 (0〜2個)。$p_1$ から $p_2$ の向きに順に並べる。$p_1 = p_2$ なら assert で落ちる | $O(1)$ |
| `sphere_sphere_intersection(s1, s2, eps = 1e-9)` | 2つの球面が交わってできる円を `std::optional<SpaceCircle<T>>` で返す。交わらない (離れている、一方が他方の内部、同心で半径が違う) なら `std::nullopt`、接するなら半径 0 の円 (中心が接点)。同じ球は assert で落ちる | $O(1)$ |
| `sphere_sphere_intersection_volume(s1, s2)` | 2つの球の共通部分の体積 | $O(1)$ |
| `great_circle_distance(lat1, lon1, lat2, lon2, r = 1)` | 半径 $r$ の球面上の 2 点 (緯度・経度はラジアン) の最短距離 (大円距離) | $O(1)$ |

- すべて浮動小数点型のみです。
- `sphere_line_intersection` は、2 次元の `circle_line_intersection` (座標の昇順) と違い、直線の向きの順に並べます。光線 ($p_1$ から $p_2$ の向きの半直線) が最初に当たる点は、パラメータが 0 以上の最初の点です。
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

- 点・直線・平面の距離や交点は [3 次元の直線・線分・平面](segment-3d.hpp)
- 2 次元の円は [円](circle.hpp)
