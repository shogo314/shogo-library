---
title: セグメント木
documentation_of: //src/data_structures/segtree.hpp
---

モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を渡して使うセグメント木です。1点更新・区間積を $O(\log n)$ で行います。

```cpp
SegTree<monoid::Max<int>> seg(n);
SegTree seg2(v, Monoid([](int a, int b) { return a + b; }, 0));  // ラムダ式から作る
RMinQ<long long> seg3(v);                                        // 別名を使う
```

## 別名

| 別名 | 実体 | 用途 |
|---|---|---|
| `RMaxQ<S>` | `SegTree<monoid::Max<S>>` | 区間最大値 |
| `RMinQ<S>` | `SegTree<monoid::Min<S>>` | 区間最小値 |
| `RSumQ<S>` | `SegTree<monoid::Sum<S>>` | 区間和 |
| `RProdQ<S>` | `SegTree<monoid::Prod<S>>` | 区間積 |
| `RXorQ<S>` | `SegTree<monoid::Xor<S>>` | 区間 xor |
| `RGcdQ<S>` | `SegTree<monoid::Gcd<S>>` | 区間 gcd |

別名のないものは `SegTree<monoid::...>` と書きます。使えるモノイドの一覧は [algebra/monoid.hpp](../algebra/monoid.hpp) にあります。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SegTree(n, m = M())` | 要素数 `n`、すべて単位元で初期化 | $O(n)$ |
| `SegTree(v, m = M())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(1)$ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | $O(\log n)$ |
| `apply(k, x)` | `k` 番目を `op(seg[k], x)` に更新 | $O(\log n)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log n)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `max_right(l, f)` | `f(prod(l, r))` が真となる最大の `r` (`f` は単調) | $O(\log n)$ |
| `min_left(r, f)` | `f(prod(l, r))` が真となる最小の `l` (`f` は単調) | $O(\log n)$ |
| `os << seg` | 全要素を空白区切りで出力 | $O(n)$ |

## 関連

- 区間作用が必要なら [遅延伝搬セグメント木](lazy-segtree.hpp)
- 2次元なら [2次元セグメント木](segtree-2d.hpp)
- chmin/chmax と区間和を同時に扱うなら [Segment Tree Beats](segtree-beats.hpp)
