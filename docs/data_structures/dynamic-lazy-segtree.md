---
title: 動的遅延伝搬セグメント木
documentation_of: //src/data_structures/dynamic-lazy-segtree.hpp
---

要素数が大きくても使える遅延伝搬セグメント木です。作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使います。最初はすべて単位元で、更新したところのノードだけを作ります。添字は `long long` で、要素数が $10^{18}$ でも使えます。

```cpp
DynamicLazySegTree<acted_monoid::AddSum<long long>> seg(1000000000000000000);
seg.apply(0, 1000000000000000000, 1);   // すべてに 1 を足す
seg.prod(10, 20);                       // 10
seg.set(15, 100);
seg.prod(10, 20);                       // 109
```

負の添字を使いたいときは、その分ずらして使います。

`mapping` に渡す区間の長さや位置も `long long` になります。

`apply`・`set` は、たどるノードの作用素を子に伝えます。このとき、まだ作っていない子も作ります。`get`・`prod`・`max_right`・`min_left` はノードを作らず、上の作用素を合成しながら下ります。まだ作っていない部分木は、すべて単位元として扱います。

$N$ を要素数とします。メモリは更新の回数 × $O(\log N)$ です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DynamicLazySegTree(n, a = A())` | 要素数 `n` (`long long`)、すべて単位元で初期化 | $O(1)$ |
| `size()` | 要素数 (`long long`) | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log N)$ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | $O(\log N)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log N)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `apply(k, f)` | `k` 番目に `f` を作用 | $O(\log N)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用 | $O(\log N)$ |
| `max_right(l, g)` | `g(prod(l, r))` が真となる最大の `r` (`g` は単調) | $O(\log N)$ |
| `min_left(r, g)` | `g(prod(l, r))` が真となる最小の `l` (`g` は単調) | $O(\log N)$ |

## 関連

- 要素数が小さいなら [遅延伝搬セグメント木](lazy-segtree.hpp) の方が速い
- 1点更新だけなら [動的セグメント木](dynamic-segtree.hpp)
- 過去の版も使うなら [永続遅延伝搬セグメント木](persistent-lazy-segtree.hpp)
