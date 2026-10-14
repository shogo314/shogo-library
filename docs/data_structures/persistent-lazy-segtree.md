---
title: 永続遅延伝搬セグメント木
documentation_of: //src/data_structures/persistent-lazy-segtree.hpp
---

過去の版を残したまま、区間作用・区間積を行える遅延伝搬セグメント木です。作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使います。更新は元の版を変えずに新しい版を返し、新しく作るノードは $O(\log n)$ 個です。版のコピーは $O(1)$ です。

```cpp
PersistentLazySegTree<acted_monoid::AffineSum<mint>> s0(v);
auto s1 = s0.apply(l, r, Affine<mint>{b, c});   // s0 はそのまま
s1.prod(l, r);

// 区間コピー: s1 の [l2, r2) を s0 の値に戻した版
auto s2 = s1.copy(s0, l2, r2);

// 版を配列に並べる (クエリ i の後の版を seg[i + 1] に置く)
std::vector<PersistentLazySegTree<acted_monoid::AffineSum<mint>>> seg(q + 1);
seg[0] = PersistentLazySegTree<acted_monoid::AffineSum<mint>>(v);
seg[i + 1] = seg[k + 1].copy(seg[s + 1], l, r);
```

`apply`・`set`・`copy` は、たどるノードの作用素を子に伝えた新しいノードを作ります。`get`・`prod`・`max_right`・`min_left` はノードを作らず、上の作用素を合成しながら下ります。

`copy(other, l, r)` の `other` は、自身と同じ木 (同じコンストラクタの呼び出しから更新して作った版) でなければなりません。ノードを共有するので、区間の長さによらず $O(\log n)$ です。

同じ木から作った版はノードを共有します。ノードは削除しないので、メモリは更新の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentLazySegTree(n, a = A())` | 要素数 `n`、すべて単位元で初期化 (単位元の部分木を共有する) | $O(\log n)$ |
| `PersistentLazySegTree(v, a = A())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目を `x` にした新しい版を返す | $O(\log n)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log n)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `apply(k, f)` | `k` 番目に `f` を作用させた新しい版を返す | $O(\log n)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用させた新しい版を返す | $O(\log n)$ |
| `copy(other, l, r)` | 区間 $[l, r)$ を `other` の値にした新しい版を返す | $O(\log n)$ |
| `max_right(l, g)` | `g(prod(l, r))` が真となる最大の `r` (`g` は単調) | $O(\log n)$ |
| `min_left(r, g)` | `g(prod(l, r))` が真となる最小の `l` (`g` は単調) | $O(\log n)$ |
| `to_vector()` | すべての要素を並べた `std::vector<S>` | $O(n \log n)$ |
| `os << seg` | 全要素を空白区切りで出力 | $O(n \log n)$ |

## 関連

- 過去の版が要らないなら [遅延伝搬セグメント木](lazy-segtree.hpp)
- 1点更新だけなら [永続セグメント木](persistent-segtree.hpp)
