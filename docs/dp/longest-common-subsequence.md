---
title: 最長共通部分列 (LCS)
documentation_of: //src/dp/longest-common-subsequence.hpp
---

2 つの列 `s`、`t` の最長共通部分列を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
std::string s = "abcbdab", t = "bdcaba";
long long k = longest_common_subsequence(s, t);        // 4
auto idx = longest_common_subsequence_restore(s, t);  // 添字の組 (i, j) のリスト。長さは 4
std::string lcs;
for (auto [i, j] : idx) lcs += s[i];                   // 共通部分列の 1 つ
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `longest_common_subsequence(s, t)` | 最長共通部分列の長さ (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |
| `longest_common_subsequence_restore(s, t)` | 最長共通部分列を 1 つ求め、`s[i] == t[j]` として選んだ添字の組 `(i, j)` を昇順に並べたリスト (`std::vector<std::pair<long long, long long>>`) | 時間 $O(nm)$、メモリ $O(nm)$ |

復元では $(n + 1)(m + 1)$ 個の `int` の表を作るので、メモリに注意してください ($n = m = 5000$ で約 100 MB)。

## 関連

- 1 つの列の最長増加部分列は [最長増加部分列 (LIS)](longest-increasing-subsequence.hpp)
- 挿入・削除・置換の最小回数は [編集距離](edit-distance.hpp)
