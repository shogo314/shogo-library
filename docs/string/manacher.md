---
title: Manacher 法
documentation_of: //src/string/manacher.hpp
---

各位置を中心とする最長の回文の長さを $O(n)$ で求めます。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
auto r = manacher(std::string("abaaba"));              // {1, 2, 1, 1, 2, 1}
auto len = palindrome_lengths(std::string("abaaba"));  // {1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1}
```

- `s[l, r)` が回文かどうかは、`palindrome_lengths(s)[l + r - 1] >= r - l` で判定できます。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `manacher(s)` / `manacher(begin, end)` | 各 $i$ について、`s[i]` を中心とする奇数長の回文の最大の半径 `r[i]` (`s[i - r[i] + 1, i + r[i])` が回文、長さは `2 * r[i] - 1`) を並べた `std::vector<long long>` | $O(n)$ |
| `palindrome_lengths(s)` / `palindrome_lengths(begin, end)` | 長さ $2n - 1$ の `std::vector<long long>` `len`。`len[2 * i]` は `s[i]` を中心とする最長の回文の長さ、`len[2 * i + 1]` は `s[i]` と `s[i + 1]` の間を中心とする最長の回文の長さ (なければ 0) | $O(n)$ |

## 関連

- 異なる回文の種類や、各回文の出現回数を求めるには [回文木 (Eertree)](palindromic-tree.hpp)
