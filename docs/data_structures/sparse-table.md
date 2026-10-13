---
title: Sparse Table
documentation_of: //src/data_structures/sparse-table.hpp
---

値を変更しない列の区間積を、前計算 $O(n \log n)$、クエリ $O(1)$ で求めるデータ構造です。冪等な (`op(x, x) = x` となる) [モノイド](../algebra/monoid.hpp) を渡して使います。

```cpp
SparseTable<monoid::Min<int>> st(a);
int m = st.prod(l, r);  // min(a[l], ..., a[r-1])
```

使えるモノイドは `monoid::Min`、`Max`、`Gcd`、`And`、`Or`、`MinWith`、`MaxWith` などです。`Sum` や `MinCount` のように冪等でないものは、重なった区間を 2 回数えてしまうので使えません。

## メンバ

| メンバ | 説明 |
|---|---|
| `SparseTable(v)` | 列 `v` から作る。$O(n \log n)$ |
| `size()` | 要素数 |
| `get(k)` | `v[k]` |
| `prod(l, r)` | `v[l]` から `v[r-1]` までの積。`l = r` なら単位元。$O(1)$ |
| `all_prod()` | すべての要素の積 |

ラムダ式から作ったモノイドも渡せます。

```cpp
SparseTable st(v, Monoid([](int a, int b) { return std::max(a, b); }, 0));
```

## 関連

- 値の変更が必要なら [セグメント木](segtree.hpp)
