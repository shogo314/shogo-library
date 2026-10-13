---
title: Fenwick Tree (Binary Indexed Tree)
documentation_of: //src/data_structures/fenwick-tree.hpp
---

1 点への作用と区間積を $O(\log n)$ で行うデータ構造です。[セグメント木](segtree.hpp) よりできることは少ないですが、コードが短く定数倍が軽いです。可換な [群](../algebra/group.hpp) を渡して使います。

```cpp
FenwickTree<group::Sum<long long>> ft(n);   // すべて 0
FenwickTree<group::Sum<long long>> ft2(a);  // a で初期化する (O(n))
ft.apply(i, x);                             // a[i] += x
long long s = ft.prod(l, r);                // a[l] + ... + a[r-1]
int k = ft.max_right([&](long long v) { return v <= w; });  // 先頭からの和が w 以下になる最大の長さ
```

## メンバ

| メンバ | 説明 |
|---|---|
| `FenwickTree(n)` | 要素数 `n` で、すべての要素が単位元 |
| `FenwickTree(v)` | `v` を初期値にする。$O(n)$ |
| `size()` | 要素数 |
| `apply(k, x)` | `a[k]` を `op(a[k], x)` にする。$O(\log n)$ |
| `prefix_prod(r)` | `a[0]` から `a[r-1]` までの積。$O(\log n)$ |
| `prod(l, r)` | `a[l]` から `a[r-1]` までの積。逆元を使う。$O(\log n)$ |
| `all_prod()` | すべての要素の積 |
| `get(k)` | `a[k]`。逆元を使う。$O(\log n)$ |
| `set(k, x)` | `a[k]` を `x` にする。逆元を使う。$O(\log n)$ |
| `max_right(f)` | `f(prefix_prod(r))` が真になる最大の `r`。`f` は単調で `f(e())` が真であること。$O(\log n)$ |

逆元を使わない `apply`・`prefix_prod`・`all_prod`・`max_right` だけなら、可換なモノイド (`monoid::Max<T>` など) でも使えます。

`max_right` は、要素が非負のときの「先頭から和が `w` 以下になる最大の長さ」や、個数を数える BIT での「`k` 番目に小さい値」に使えます。

ラムダ式から作った群も渡せます。

```cpp
FenwickTree ft(v, Group([](int a, int b) { return a ^ b; }, 0, [](int a) { return a; }));
```

## 関連

- 区間への作用や非可換な演算が必要なら [セグメント木](segtree.hpp)、[遅延伝搬セグメント木](lazy-segtree.hpp)
