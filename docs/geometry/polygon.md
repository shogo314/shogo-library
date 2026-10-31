---
title: 多角形 (面積、重心、内外判定、凸性、凸包、凸多角形の切断)
documentation_of: //src/geometry/polygon.hpp
---

頂点を順に並べた `std::vector<Vector<T, 2>>` で表した多角形の関数です。整数座標でも使える関数は、外積を計算するので座標の絶対値の2乗の数倍が `T` に収まる必要があります。

```cpp
using P = Vector<long long>;
std::vector<P> ps(n);
for (auto& p : ps) std::cin >> p;      // "x y" を読む
auto hull = convex_hull(ps);           // 凸包 (反時計回り)
long long s2 = polygon_area_doubled(hull);
int k = polygon_contains(hull, P(0, 0));  // 0: 外部、1: 辺上、2: 内部
```

## 関数

| 関数 | 説明 | 整数型 | 計算量 |
|---|---|:-:|---|
| `polygon_area_doubled(poly)` | 多角形の符号付き面積の2倍 (反時計回りなら正) | ✓ | $O(n)$ |
| `polygon_area(poly)` | 多角形の面積 (`double`、向きは問わない) | ✓ | $O(n)$ |
| `polygon_centroid(poly)` | 多角形の領域の重心 (`Vector<double, 2>`、向きは問わない。面積が 0 なら assert で落ちる) | ✓ | $O(n)$ |
| `polygon_edge_moment(p, q)` | 辺 $p \to q$ の寄与 (原点と $p, q$ の三角形の面積と一次モーメント) を `PolygonMoment<T>` で返す。全辺の和が多角形の値になる | ✓ | $O(1)$ |
| `polygon_is_convex(poly)` | 多角形 (反時計回り) が凸か | ✓ | $O(n)$ |
| `polygon_contains(poly, p)` | 点が多角形 (反時計回り) の 0: 外部、1: 辺上、2: 内部 | ✓ | $O(n)$ |
| `convex_hull(ps, include_straight = false)` | 凸包 (反時計回り)。`include_straight` で 180 度の頂点を含めるか選ぶ | ✓ | $O(n \log n)$ |
| `select_convex(ps, include_straight = false)` | 順番を保った半凸包。x の昇順なら下凸包、降順なら上凸包 | ✓ | $O(n)$ |
| `convex_cut(poly, p1, p2)` | 凸多角形 (反時計回り) を直線 $p_1 p_2$ で切った、直線の左側 ($p_1$ から $p_2$ を見て左) の凸多角形。左側に何もなければ空 | 浮動小数点型のみ | $O(n)$ |

## 部分多角形の面積と重心 `PolygonMoment<T>`

部分多角形 (頂点 $u, u+1, \dots, v$ を順に結んで閉じたもの) の面積や重心をたくさん求めるときは、`polygon_edge_moment` の寄与を [円環上の区間和](../data_structures/circular-sum.hpp) で足し、閉じる辺 $v \to u$ の寄与を加えます。

```cpp
using P = Vector<long long>;
std::vector<PolygonMoment<long long>> e(n);
for (int i = 0; i < n; i++) e[i] = polygon_edge_moment(ps[i], ps[(i + 1) % n]);
CircularSum cs(e);
auto m = cs.sum(u, v) + polygon_edge_moment(ps[v], ps[u]);
m.area();      // 符号付き面積
m.centroid();  // 重心
```

`PolygonMoment<T>` は面積と一次モーメントを持つ型で、`+`・`-`・`+=`・`-=`・`==`・`!=` が使えます。`T` が整数型なら、値は `__int128_t` で持ちます (座標が $10^9$ なら `mx` は $10^{27}$ 程度になります)。

| メンバ | 説明 |
|---|---|
| `area2` | 符号付き面積 $S$ の 2 倍 (反時計回りなら正) |
| `mx` / `my` | 一次モーメントの 6 倍 ($6S g_x$ / $6S g_y$。$(g_x, g_y)$ は重心) |
| `area()` | 符号付き面積 (`double`) |
| `centroid()` | 重心 (`Vector<double, 2>`。面積が 0 なら assert で落ちる) |

浮動小数点型でも、`polygon_is_convex` や `polygon_contains` の判定は誤差を考えずに `0` と比べます。誤差が問題になる場合は、整数座標で計算してください。

## 関連

- 点・ベクトルの型は [幾何ベクトル](vector.hpp)、直線・線分は [直線・線分](segment.hpp)
- 凸包を使う最遠点対は [最近点対・最遠点対](point-pair.hpp)
- 円と多角形の共通部分の面積は [円](circle.hpp) の `circle_polygon_intersection_area`
