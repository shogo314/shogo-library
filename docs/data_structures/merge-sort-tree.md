---
title: マージソートツリー
documentation_of: //src/data_structures/merge-sort-tree.hpp
---

各要素が値 `value[i]` とキー `key[i]` を持つ列に対して、「添字が $[l, r)$ で、キーが $[a, b)$ に入る要素の値の積」を求めます。更新はできません。

```cpp
std::vector<long long> value = {1, 2, 3, 4, 5};
std::vector<long long> key   = {5, 1, 4, 2, 3};
MergeSortTree<> mst(value, key);           // 値は long long の和
mst.prod(1, 4, 2, 5);                      // i ∈ [1, 4) かつ key ∈ [2, 5) → 3 + 4 = 7
mst.prod(0, 5, std::nullopt, 3);           // key < 3 → 2 + 4 = 6
MergeSortTree mst2(value, key, group::Sum<long long>());  // 群の値と key の型から推論する
```

点の重みの矩形和 (x を添字、y をキーにする) や、区間内で閾値未満の値の個数・和などに使えます。

## テンプレート引数

`MergeSortTree<G = group::Sum<long long>, K = long long, Comp = std::less<K>>`

| 引数 | 説明 |
|---|---|
| `G` | 値の可換群 ([algebra/group.hpp](../algebra/group.hpp))。逆元を使って積を求める |
| `K` | キーの型 |
| `Comp` | キーの比較関数 |

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MergeSortTree(value, key, g = G())` | 値の列とキーの列から作る | $O(n \log n)$ |
| `MergeSortTree(value_key, g = G())` | `(値, キー)` の `pair` の列から作る | $O(n \log n)$ |
| `prod(l, r, a, b)` | $l \le i < r$ かつ $a \le \mathrm{key}_i < b$ の $\mathrm{value}_i$ の積。どの引数も `std::nullopt` (省略) にでき、`l`、`r` は 0、`n`、`a`、`b` は $-\infty$、$+\infty$ になる | $O(\log^2 n)$ |

## 関連

- 更新もしたい場合は [2次元セグメント木](segtree-2d.hpp)
