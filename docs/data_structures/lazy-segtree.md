---
title: 遅延伝搬セグメント木
documentation_of: //src/data_structures/lazy-segtree.hpp
---

作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使う遅延伝搬セグメント木です。区間作用・区間積を $O(\log n)$ で行います。

```cpp
LazySegTree<acted_monoid::AffineSum<mint>> seg(v);
seg.apply(l, r, Affine<mint>{b, c});  // [l, r) の各値を b * x + c にする
RAddMinQ<long long> seg2(n);  // 別名を使う
```

ラムダ式から作る場合は `ActedMonoid(op, e, mapping, composition, id)` を渡します。`mapping` の引数は `(f, x)`、`(f, x, sz)` (`sz` は区間の長さ)、`(f, x, l, r)` のいずれかです。

```cpp
LazySegTree seg(v, ActedMonoid(
    [](long long a, long long b) { return std::min(a, b); }, INF,  // op, e
    [](long long f, long long x) { return x + f; },                // mapping
    [](long long f, long long g) { return f + g; }, 0LL));         // composition, id
```

## 別名

| 別名 | 実体 | 作用 | 取得 |
|---|---|---|---|
| `RAddSumQ<S>` | `LazySegTree<acted_monoid::AddSum<S>>` | 区間加算 | 区間和 |
| `RAddMinQ<S>` | `LazySegTree<acted_monoid::AddMin<S>>` | 区間加算 | 区間最小値 |
| `RAddMaxQ<S>` | `LazySegTree<acted_monoid::AddMax<S>>` | 区間加算 | 区間最大値 |
| `RUpdateSumQ<S>` | `LazySegTree<acted_monoid::UpdateSum<S>>` | 区間代入 | 区間和 |
| `RUpdateMinQ<S>` | `LazySegTree<acted_monoid::UpdateMin<S>>` | 区間代入 | 区間最小値 |
| `RUpdateMaxQ<S>` | `LazySegTree<acted_monoid::UpdateMax<S>>` | 区間代入 | 区間最大値 |
| `RChminMinQ<S>` | `LazySegTree<acted_monoid::ChminMin<S>>` | 区間 chmin | 区間最小値 |
| `RChmaxMaxQ<S>` | `LazySegTree<acted_monoid::ChmaxMax<S>>` | 区間 chmax | 区間最大値 |

別名のないもの (`AffineSum`、`AddMinCount` など) は `LazySegTree<acted_monoid::...>` と書きます。使える作用素付きモノイドの一覧は [algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp) にあります。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LazySegTree(n, a = A())` | 要素数 `n`、すべて単位元で初期化 | $O(n)$ |
| `LazySegTree(v, a = A())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | $O(\log n)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log n)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `apply(k, f)` | `k` 番目に `f` を作用 | $O(\log n)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用 | $O(\log n)$ |
| `max_right(l, g)` | `g(prod(l, r))` が真となる最大の `r` (`g` は単調) | $O(\log n)$ |
| `min_left(r, g)` | `g(prod(l, r))` が真となる最小の `l` (`g` は単調) | $O(\log n)$ |
| `os << seg` | 全要素を空白区切りで出力 | $O(n)$ |

## 関連

- 区間作用・1点取得だけなら [imos法](imos.hpp) (作用素が逆元を持つ場合) か [双対セグメント木](dual-segtree.hpp)
- 区間 chmin/chmax・区間加算・区間和なら [Segment Tree Beats](segtree-beats.hpp)
