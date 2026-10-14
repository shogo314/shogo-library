---
title: 永続セグメント木
documentation_of: //src/data_structures/persistent-segtree.hpp
---

過去の版を残したまま更新できるセグメント木です。`set` は元の版を変えずに新しい版を返し、新しく作るノードは $O(\log n)$ 個です。版のコピーは $O(1)$ です。

```cpp
PersistentSegTree<monoid::Sum<long long>> s0(n);
auto s1 = s0.set(3, 10);     // s0 はそのまま
auto s2 = s1.apply(5, 2);    // s1 もそのまま
s2.prod(0, n);               // 12
s1.prod(0, n);               // 10

// 版を配列に並べる (矩形和: x 座標の順に点を足していき、2 つの版の差を取る)
std::vector<PersistentSegTree<monoid::Sum<long long>>> seg(N + 1);
seg[0] = PersistentSegTree<monoid::Sum<long long>>(m);
for (int i = 0; i < N; i++) seg[i + 1] = seg[i].apply(y[i], w[i]);
long long s = seg[r].prod(d, u) - seg[l].prod(d, u);
```

同じ木から作った版はノードを共有します。ノードは削除しないので、メモリは更新の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentSegTree(n, m = M())` | 要素数 `n`、すべて単位元で初期化 (単位元の部分木を共有する) | $O(\log n)$ |
| `PersistentSegTree(v, m = M())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目を `x` にした新しい版を返す | $O(\log n)$ |
| `apply(k, x)` | `k` 番目を `op(seg[k], x)` にした新しい版を返す | $O(\log n)$ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | $O(\log n)$ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `max_right(l, f)` | `f(prod(l, r))` が真となる最大の `r` (`f` は単調) | $O(\log n)$ |
| `min_left(r, f)` | `f(prod(l, r))` が真となる最小の `l` (`f` は単調) | $O(\log n)$ |
| `to_vector()` | すべての要素を並べた `std::vector<S>` | $O(n \log n)$ |
| `os << seg` | 全要素を空白区切りで出力 | $O(n \log n)$ |

## 関連

- 過去の版が要らないなら [セグメント木](segtree.hpp)
- 区間作用も必要なら [永続遅延伝搬セグメント木](persistent-lazy-segtree.hpp)
- 値を持つだけでよいなら [永続配列](persistent-array.hpp)
- 静的な矩形和だけなら [マージソートツリー](merge-sort-tree.hpp)
