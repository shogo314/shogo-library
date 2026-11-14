---
title: 部分配列の和の最大値 (Kadane のアルゴリズム)
documentation_of: //src/dp/maximum-subarray.hpp
---

部分配列の和の最大値を $O(n)$ で求めます。`v[i]` で終わる部分配列の和の最大値を前から順に更新する DP です。

```cpp
std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
int s = maximum_subarray(v);   // 6 ({4, -1, 2, 1})
std::vector<int> w = {-5, -2, -9};
int t = maximum_subarray(w);    // -2 (空でない部分配列)
int u = maximum_subarray(w, 0); // 0 (空の部分配列を許す)
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `maximum_subarray(c)` | 空でない部分配列の和の最大値 | $O(n)$ |
| `maximum_subarray(c, init)` | 空の部分配列 (和 `init`) も許した部分配列の和の最大値 | $O(n)$ |

- `c` は `begin()`、`end()` を持つコンテナで、戻り値の型は要素の型です。
- `maximum_subarray(c)` では `c` が空であってはいけません。

## 関連

- 値の更新があったり、区間ごとに求めたりする場合は、[モノイド](../algebra/monoid.hpp) の `MaxSubarraySum` をセグメント木に乗せる
