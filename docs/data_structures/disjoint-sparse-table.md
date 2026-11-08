---
title: Disjoint Sparse Table
documentation_of: //src/data_structures/disjoint-sparse-table.hpp
---

変更しない列の区間積を、前計算 $O(n\log n)$、クエリ $O(1)$ で求めます。結合則と単位元を持つモノイドなら使え、冪等性や可換性は不要です。

```cpp
int a[] = {1, 2, 3, 4};
DisjointSparseTable<monoid::Sum<long long>> st(a);
long long sum = st.prod(1, 4);  // 9
DisjointSparseTable<monoid::Composite<mint>> functions(fs);
auto f = functions.prod(l, r);  // 左からの順序を保って合成
```

範囲は半開区間です。サイズ付きの範囲から各要素を `S(x)` で直接構築し、配列・`vector`・`list`・初期化リストに対応します。C++20 ではサイズ付きの入力範囲のビューも使えます。ラムダ式から作る `Monoid` と型推論も使えます。メモリは $O(n\log n)$ で、値の更新はできません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DisjointSparseTable(v = {}, m = M())` | 範囲 `v` から作る | $O(n\log n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` | `k` 番目の値 | $O(1)$ |
| `prod(l, r)` | 区間 `[l, r)` の積。空なら単位元 | $O(1)$ |
| `all_prod()` | 全体の積 | $O(1)$ |

## 関連

- 冪等な演算に限定するなら [Sparse Table](sparse-table.hpp)
- 値の更新が必要なら [セグメント木](segtree.hpp)
