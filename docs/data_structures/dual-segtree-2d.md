---
title: 2次元双対セグメント木 (長方形作用、1点取得)
documentation_of: //src/data_structures/dual-segtree-2d.hpp
---

作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使う2次元双対セグメント木です。値を取得する点を先読みし、長方形への作用と1点の取得を $O(\log^2 P)$ で行います。

```cpp
std::vector<std::pair<long long, long long>> points = { {1, 2}, {3, 4}, {-1000000000000, 0} };  // get する点 (x, y)
RAddQ2D<long long> seg(points);
seg.apply(0, 4, 0, 3, 5);  // [0, 4) x [0, 3) に 5 を足す
seg.apply(1, 4, 2, 5, 7);  // [1, 4) x [2, 5) に 7 を足す
seg.get(1, 2);             // 12
seg.get(3, 4);             // 7

RChminQ2D<int> seg2(points, 1000000000);  // 長方形 chmin、初期値を指定する
```

座標は中で圧縮するので、大きな座標や負の座標もそのまま渡せます。`apply` の範囲は先読みせず、どんな範囲でも作用させられます。

## 注意

- 作用素を下へ伝えないので、作用素の合成 (`composition`) は可換である必要があります。加算・chmin・chmax は使えますが、代入やアフィン変換は使えません。
- `get` は、コンストラクタで渡した点にしか使えません (違えば assert で落ちます)。
- 値は `mapping(作用素の合成, 初期値)` で求めます。`mapping` が区間の長さを使う作用素付きモノイドでは、長さ 1 として作用します。
- 長方形への加算と点の取得では、[2次元セグメント木](segtree-2d.hpp) で4隅への加算に直すよりも、先読みする点が取得する点だけで済むので速く、メモリも少なくて済みます。

## 別名

| 別名 | 実体 | 作用 |
|---|---|---|
| `RAddQ2D<S>` | `DualSegTree2D<acted_monoid::AddMin<S>>` | 長方形加算 |
| `RChminQ2D<S>` | `DualSegTree2D<acted_monoid::ChminMin<S>>` | 長方形 chmin |
| `RChmaxQ2D<S>` | `DualSegTree2D<acted_monoid::ChmaxMax<S>>` | 長方形 chmax |

[双対セグメント木](dual-segtree.hpp) の別名と同じく、`mapping` が区間の長さを使わない `Min` 系を実体にしています。

## メンバ関数

$P$ を渡した点の数とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DualSegTree2D<A>(points)` | 点の列 `points` を先読みする。各点は `S()` で初期化 | $O(P \log P)$ |
| `DualSegTree2D<A>(points, x)` | 各点を `x` で初期化 | $O(P \log P)$ |
| `apply(lx, rx, ly, ry, f)` | $[l_x, r_x) \times [l_y, r_y)$ にある点の値に `f` を作用 | $O(\log^2 P)$ |
| `get(x, y)` | $(x, y)$ の値 | $O(\log^2 P)$ |

メモリは $O(P \log P)$ です。

## 関連

- 1次元なら [双対セグメント木](dual-segtree.hpp)
- 1点更新・長方形の積なら [2次元セグメント木](segtree-2d.hpp)
- 加算がすべて取得より前なら [2 次元のいもす法](imos-2d.hpp)
