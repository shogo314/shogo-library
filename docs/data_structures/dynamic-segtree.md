---
title: 動的セグメント木
documentation_of: //src/data_structures/dynamic-segtree.hpp
---

要素数が大きくても使えるセグメント木です。最初はすべて単位元で、更新したところのノードだけを作ります。添字は `long long` で、要素数が $10^{18}$ でも使えます。座標圧縮ができない (クエリがオンラインで来る) ときに使います。

```cpp
DynamicSegTree<monoid::Sum<long long>> seg(1000000000000000000);
seg.set(123456789012, 5);
seg[3] = 2;
seg.prod(0, 1000000000000000000);   // 7
long long r = seg.max_right(0, [](long long s) { return s < 7; });  // 123456789012
```

負の添字を使いたいときは、その分ずらして使います。

$N$ を要素数とします。ノードは `set` 1 回につき $O(\log N)$ 個まで作るので、メモリは更新の回数 × $O(\log N)$ です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DynamicSegTree(n, m = M())` | 要素数 `n` (`long long`)、すべて単位元で初期化 | $O(1)$ |
| `size()` | 要素数 (`long long`) | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log N)$ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | $O(\log N)$ |
| `apply(k, x)` | `k` 番目を `op(seg[k], x)` に更新 | $O(\log N)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log N)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `max_right(l, f)` | `f(prod(l, r))` が真となる最大の `r` (`f` は単調) | $O(\log N)$ |
| `min_left(r, f)` | `f(prod(l, r))` が真となる最小の `l` (`f` は単調) | $O(\log N)$ |

## 関連

- 要素数が小さいなら [セグメント木](segtree.hpp) の方が速い
- 区間作用が必要なら [動的遅延伝搬セグメント木](dynamic-lazy-segtree.hpp)
- 過去の版も使うなら [永続セグメント木](persistent-segtree.hpp) (添字は `int`)
