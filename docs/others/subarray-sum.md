---
title: 和が条件を満たす区間の個数
documentation_of: //src/others/subarray-sum.hpp
---

列 `a` の区間 $[l, r)$ ($l < r$) のうち、和がちょうど $k$ のものと $k$ 以下のものの個数を数えます。

```cpp
std::vector<long long> a = {1, 2, 3, 2, 1, 4};
long long x = count_subarrays_with_sum(a, 5LL);           // 3 ([2, 3]、[3, 2]、[1, 4])
long long y = count_subarrays_with_sum_at_most(a, 3LL);   // 7
```

`k` は列の要素と同じ型で渡します (`long long` の列なら `5LL`)。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `count_subarrays_with_sum(a, k)` | 和がちょうど `k` の区間の個数。要素は整数型であること | 要素がすべて 0 以上なら $O(n)$、そうでなければ $O(n \log n)$ |
| `count_subarrays_with_sum_at_most(a, k)` | 和が `k` 以下の区間の個数。要素は浮動小数点型でもよい | 要素がすべて 0 以上なら $O(n)$、そうでなければ $O(n \log n)$ |

- 累積和 $P$ (先頭に 0 を付けたもの) について、$l < r$ かつ $P_r - P_l \le k$ となる組を数えます。要素がすべて 0 以上なら $P$ は単調なので尺取り法で、そうでなければ [転倒数](inversion-number.hpp) と同じマージソートで数えます。
- ちょうど $k$ の個数は、($k$ 以下の個数) $-$ ($k - 1$ 以下の個数) で求めます。
- 和が $k$ 以上の個数は、(区間の総数 $n(n+1)/2$) $-$ ($k - 1$ 以下の個数) で求められます。
- $n = 10^6$ で、要素が正なら 0.04 秒、負を含むなら 0.3 秒ほどです。

## 関連

- 和が最大の区間は [連続部分列の和の最大値](../dp/maximum-subarray.hpp)
- 累積和は [vector の関数](../utility/vector_func.hpp) の `cumulative_sum`
