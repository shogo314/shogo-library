---
title: 2次元セグメント木
documentation_of: //src/data_structures/segtree-2d.hpp
---

可換モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を乗せる2次元セグメント木です。更新する座標と取得する範囲をすべて先読みして、必要なノードだけを持ちます。

```cpp
std::vector<std::tuple<int, int>> sets = { {0, 1}, {2, 3} };        // set/apply する座標 (x, y)
std::vector<std::tuple<int, int, int, int>> prods = { {0, 3, 0, 4} }; // prod する範囲 (lx, rx, ly, ry)
RSumQ2D<long long> seg(3, 4, sets, prods);                         // x は [0, 3)、y は [0, 4)
seg.apply(0, 1, 5);
seg.apply(2, 3, 7);
seg.prod(0, 3, 0, 4);  // 12
```

座標が大きい場合は、先に座標圧縮してから使います。先読みしていない座標への `set`・`apply` や、先読みしていない範囲への `prod` の結果は保証されません。

## 別名

| 別名 | 実体 | 用途 |
|---|---|---|
| `RMaxQ2D<S>` | `SegTree2D<monoid::Max<S>>` | 矩形の最大値 |
| `RMinQ2D<S>` | `SegTree2D<monoid::Min<S>>` | 矩形の最小値 |
| `RSumQ2D<S>` | `SegTree2D<monoid::Sum<S>>` | 矩形和 |

## メンバ関数

$q$ を先読みしたクエリの数、$H$, $W$ を x, y 座標の範囲とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SegTree2D(h, w, set_query_indices, prod_query_indices, m = M())` | x 座標 $[0, h)$、y 座標 $[0, w)$。すべて単位元で初期化 | $O(q \log H \log W \log q)$ |
| `get(x, y)` | $(x, y)$ の値 | $O(\log q)$ |
| `set(x, y, v)` | $(x, y)$ を `v` に更新 | $O(\log H \log W \log q)$ |
| `apply(x, y, v)` | $(x, y)$ を `op(get(x, y), v)` に更新 | $O(\log H \log W \log q)$ |
| `prod(lx, rx, ly, ry)` | $[l_x, r_x) \times [l_y, r_y)$ の積 | $O(\log H \log W \log q)$ |

## 関連

- 1次元なら [セグメント木](segtree.hpp)
- 更新がなく、点の重みの矩形和なら [マージソートツリー](merge-sort-tree.hpp) でも求められる
