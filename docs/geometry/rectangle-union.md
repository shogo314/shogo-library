---
title: 長方形の和集合の面積
documentation_of: //src/geometry/rectangle-union.hpp
---

軸に平行な長方形 $[l, r) \times [d, u)$ がいくつか与えられたとき、その和集合の面積を走査線で $O(n \log n)$ で求めます。

```cpp
std::vector<std::array<long long, 4>> rects = { {0, 0, 3, 4}, {1, 2, 4, 3} };  // {l, d, r, u}
long long s = rectangle_union_area(rects);  // 12 + 3 - 2 = 13
```

x の小さい順に走査し、y 方向の各区間を何枚の長方形が覆っているかをセグメント木で持ちます。覆う枚数が正のノードはその区間全体を覆われているとし、そうでなければ子の長さを足します。枚数を子に伝える必要がないので、遅延伝播は使いません。

長方形は `{l, d, r, u}` ($l \le r$、$d \le u$) で渡します。幅か高さが 0 の長方形は無視します。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `rectangle_union_area(rects)` | 長方形 `{l, d, r, u}` (`std::array<T, 4>`) の和集合の面積 (`T`) | $O(n \log n)$ |

## 関連

- 長方形の重なりの枚数の最大値は [2 次元のいもす法](../data_structures/imos-2d.hpp)
- 区間加算・区間最小値とその個数の遅延セグメント木でも同じことができる ([遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp) と `acted_monoid::AddMinCount`)
