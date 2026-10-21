---
title: kd-tree
documentation_of: //src/data_structures/kd-tree.hpp
---

2 次元の点の集合 (後から変えない) について、長方形領域に入る点を列挙したり数えたりします。x と y で交互に中央値で分け、各部分木の点を囲む長方形を持ちます。

```cpp
std::vector<std::pair<long long, long long>> points = { {2, 1}, {2, 2}, {4, 2}, {6, 2} };
KDTree<long long> kd(points);
auto ids = kd.enumerate(2, 5, 0, 5);  // 2 <= x < 5 かつ 0 <= y < 5 の点の添字: 0, 1, 2 (順不同)
long long k = kd.count(2, 5, 0, 5);   // 3
```

長方形は半開区間 $[x_l, x_r) \times [y_l, y_r)$ で指定します。閉区間で与えられたら、整数座標なら右端に 1 を足してください。

`enumerate` が返す添字は順不同です。必要なら並べ替えてください。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `KDTree(points)` | 点 `i` の座標が `points[i] = {x, y}` (`std::pair<T, T>`) の kd-tree を作る | $O(n \log n)$ |
| `size()` | 点の個数 | $O(1)$ |
| `enumerate(xl, xr, yl, yr)` | $x_l \le x < x_r$ かつ $y_l \le y < y_r$ の点の添字 (`std::vector<long long>`、順不同) | $O(\sqrt{n} + k)$ ($k$ は列挙する個数) |
| `count(xl, xr, yl, yr)` | $x_l \le x < x_r$ かつ $y_l \le y < y_r$ の点の個数 | $O(\sqrt{n})$ |

## 関連

- 数えるだけなら、[Wavelet Matrix](wavelet-matrix.hpp) でも $O(\log n)$ で数えられる (x で並べ、y の値が範囲に入る個数を数える)
- 点の追加や値の和もあるなら [2次元セグメント木](segtree-2d.hpp)
