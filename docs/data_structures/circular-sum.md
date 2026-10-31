---
title: 円環上の区間和
documentation_of: //src/data_structures/circular-sum.hpp
---

円環に並んだ $a_0, \dots, a_{n-1}$ の区間和を $O(1)$ で求めます (static)。終わりが始まりより前なら、1 周またぐ区間として扱います。

```cpp
CircularSum cs(std::vector<long long>{1, 2, 3, 4, 5});
cs.sum(1, 3);   // 2 + 3 = 5
cs.sum(4, 2);   // 5 + 1 + 2 = 8 (1 周またぐ)
cs.sum(2, 2);   // 0
cs.all_sum();   // 15
```

値の型は、`T{}` が 0 で `+` と `-` が使えれば何でもかまいません。複数の量の和を同時に取りたいときは、`Vector<long long, 3>` のような成分ごとに足せる型を使うと 1 本にまとめられます。

## 注意

- 区間は半開区間です。閉区間 $[l, r]$ の和は `sum(l, r + 1)` です ($r = n - 1$ なら `sum(l, n)` です)。
- `sum(l, l)` は空 (0) です。1 周分は `all_sum()` か `sum(0, n)` で取ります。
- 何周もする区間や負の添字は扱いません。必要なら `divmod` ([base/functions.hpp](../base/functions.hpp)) を使って、次のように書けます。

```cpp
// 列 a[i mod n] の [l, r) の和 (l <= r、負でもよい)
auto f = [&](long long i) { auto [q, m] = divmod(i, n); return q * cs.all_sum() + cs.sum(0, m); };
f(r) - f(l);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CircularSum(v)` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `sum(l, r)` | `l <= r` なら $[l, r)$ の和、`r < l` なら $[l, n)$ と $[0, r)$ の和 ($0 \le l, r \le n$) | $O(1)$ |
| `all_sum()` | 1 周分の和 | $O(1)$ |

## 関連

- 円環でない列の累積和は `cumulative_sum` ([utility/vector_func.hpp](../utility/vector_func.hpp))
- 途中からループする配列は [おたまじゃくし配列](tadpole-array.hpp)
