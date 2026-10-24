---
title: 2次元セグメント木
documentation_of: //src/data_structures/segtree-2d.hpp
---

可換モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を乗せる2次元セグメント木です。更新する点を先読みし、点の値の更新と長方形の範囲の積を $O(\log^2 P)$ で行います。

```cpp
std::vector<std::pair<long long, long long>> points = { {0, 1}, {2, 3}, {-1000000000000, 5} };  // set/apply する点 (x, y)
RSumQ2D<long long> seg(points);
seg.apply(0, 1, 5);
seg.apply(2, 3, 7);
seg.prod(0, 3, 0, 4);  // [0, 3) x [0, 4) の和: 12
seg.get(2, 3);         // 7
```

座標は中で圧縮するので、大きな座標や負の座標もそのまま渡せます。`prod` の範囲は先読みせず、どんな範囲でも求められます。

## 注意

- `set`・`apply` は、コンストラクタで渡した点にしか使えません (違えば assert で落ちます)。`get` は渡していない点なら単位元を返します。
- 内部ノードの値を子の値から作るので、モノイドは可換である必要があります。逆元は使わないので、Max・Min も乗ります。
- 長方形への加算と点の取得は、長方形の 4 隅を点として渡し、差分を `apply` して $(x, y)$ 以下の範囲の和を `prod` で求めると解けます。

## 別名

| 別名 | 実体 | 用途 |
|---|---|---|
| `RMaxQ2D<S>` | `SegTree2D<monoid::Max<S>>` | 長方形の最大値 |
| `RMinQ2D<S>` | `SegTree2D<monoid::Min<S>>` | 長方形の最小値 |
| `RSumQ2D<S>` | `SegTree2D<monoid::Sum<S>>` | 長方形の和 |

## メンバ関数

$P$ を渡した点の数とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SegTree2D(points, m = M())` | 点の列 `points` を先読みする。すべて単位元で初期化 | $O(P \log P)$ |
| `get(x, y)` | $(x, y)$ の値 | $O(\log P)$ |
| `set(x, y, v)` | $(x, y)$ を `v` に更新 | $O(\log^2 P)$ |
| `apply(x, y, v)` | $(x, y)$ を `op(get(x, y), v)` に更新 | $O(\log^2 P)$ |
| `prod(lx, rx, ly, ry)` | $[l_x, r_x) \times [l_y, r_y)$ にある点の値の積 | $O(\log^2 P)$ |

メモリは $O(P \log P)$ です。

## 関連

- 1次元なら [セグメント木](segtree.hpp)
- 更新がなく、点の重みの長方形の和なら [マージソートツリー](merge-sort-tree.hpp) でも求められる
