---
title: 転倒数
documentation_of: //src/others/inversion-number.hpp
---

列 `a` の転倒数 ($i < j$ かつ $a_j < a_i$ となる組 $(i, j)$ の個数) を、マージソートで $O(n \log n)$ で求めます。

```cpp
long long k = inversion_number(std::vector<int>{3, 1, 4, 1, 5});  // 3 ((3, 1), (3, 1), (4, 1))
```

| 関数 | 説明 |
|---|---|
| `inversion_number(a, comp = std::less<T>())` | $i < j$ かつ `comp(a[j], a[i])` となる組の個数。答えは `long long` |

- 値は `comp` で比べられれば何でもよく、座標圧縮はいりません。等しい値の組は数えません。
- `comp` に `std::greater<T>()` を渡すと、$i < j$ かつ $a_i < a_j$ となる組の個数になります。
- 隣り合う要素の交換で `a` をソートするときの最小回数は、転倒数に等しくなります。

要素を追加しながら転倒数を更新したいときは、[Fenwick Tree](../data_structures/fenwick-tree.hpp) で「自分より大きい値の個数」を数えます。

## 関連

- 最長増加部分列は [LIS](../dp/longest-increasing-subsequence.hpp)
