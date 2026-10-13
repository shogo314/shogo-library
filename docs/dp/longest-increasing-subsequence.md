---
title: 最長増加部分列 (LIS)
documentation_of: //src/dp/longest-increasing-subsequence.hpp
---

列 `a` の最長増加部分列を求めます。どれも $O(n \log n)$ です。

```cpp
std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
int k = longest_increasing_subsequence(a);            // 4
auto idx = longest_increasing_subsequence_restore(a); // 添字のリスト。{1, 2, 4, 7} (値は 1, 4, 5, 6)
auto len = longest_increasing_subsequence_lengths(a); // {1, 1, 2, 1, 3, 4, 2, 4}
```

| 関数 | 説明 |
|---|---|
| `longest_increasing_subsequence(a, strict = true, comp = std::less<T>())` | 最長増加部分列の長さ |
| `longest_increasing_subsequence_restore(a, strict = true, comp = std::less<T>())` | 最長増加部分列を 1 つ求め、その添字を昇順に並べたリストを返す |
| `longest_increasing_subsequence_lengths(a, strict = true, comp = std::less<T>())` | `a[i]` で終わる最長増加部分列の長さを、各 `i` について並べたリスト |

- `strict = true` なら狭義単調増加 (隣り合う値が `comp(前, 後)` を満たす)、`false` なら広義単調増加 (`comp(後, 前)` を満たさない) です。
- `comp` に `std::greater<T>()` を渡すと減少列になります。`T` は `a` の要素の型で、`comp` で比べられれば何でもかまいません。

`a[i]` から始まる最長の長さが欲しいときは、`a` を逆順にして `comp` を逆にすれば求められます。
