---
title: 編集距離 (レーベンシュタイン距離)
documentation_of: //src/dp/edit-distance.hpp
---

列 `s` を列 `t` に変えるのに必要な、1 要素の挿入・削除・置換の最小回数を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
long long d = edit_distance(std::string("kitten"), std::string("sitting"));  // 3
edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4});        // 2
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `edit_distance(s, t)` | 編集距離 (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |

## 関連

- 置換だけを許す場合 (同じ長さの列で異なる位置の数) は [文字列アルゴリズム](../string/string.hpp) の `hamming_distance`
- 挿入と削除だけを許す場合の最小回数は、[最長共通部分列 (LCS)](longest-common-subsequence.hpp) の長さ $L$ を使って $n + m - 2L$
