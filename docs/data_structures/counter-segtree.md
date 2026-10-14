---
title: 区間内の値の個数を数えるセグメント木
documentation_of: //src/data_structures/counter-segtree.hpp
---

各ノードに部分列の値の個数 (`std::map`) を持つセグメント木です。1点更新と、区間内の特定の値の個数・`x` 以上の最小の値を求められます。

```cpp
CounterSegTree<int> cs({3, 1, 3, 2, 3});
cs.find(0, 4, 3);         // {3, 2}: [0, 4) に 3 は 2 個
*cs.lower_bound(1, 5, 2); // {2, 1}: [1, 5) で 2 以上の最小の値は 2 で、1 個
cs.set(2, 5);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CounterSegTree(v)` | 列 `v` から作る | $O(n \log^2 n)$ |
| `get(k)` | `k` 番目の値 | $O(1)$ |
| `set(k, x)` | `k` 番目を `x` に更新 | $O(\log^2 n)$ |
| `find(l, r, x)` | `{x, 区間 [l, r) の x の個数}` | $O(\log^2 n)$ |
| `lower_bound(l, r, x)` | 区間 $[l, r)$ で `x` 以上の最小の値と、その個数の `pair` (`std::optional`)。なければ `std::nullopt` | $O(\log^2 n)$ |

メモリは $O(n \log n)$ 使います。

## 関連

- 区間内でキーが範囲に入る要素の積を求めるなら [マージソートツリー](merge-sort-tree.hpp)
- 全体の値の個数を数えるだけなら [Counter](counter.hpp)
