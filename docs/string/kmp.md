---
title: KMP 法
documentation_of: //src/string/kmp.hpp
---

接頭辞関数 (KMP 法の失敗関数) と、それを使った列の検索を $O(n)$ で行います。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
auto pi = prefix_function(std::string("aabaaab"));              // {0, 1, 0, 1, 2, 2, 3}
auto pos = kmp_search(std::string("aaaa"), std::string("aa"));  // {0, 1, 2}
```

- 文字列の周期 (`s[i] == s[i + p]` がすべての i で成り立つ最小の `p`) は `n - pi[n - 1]` です。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `prefix_function(s)` / `prefix_function(begin, end)` | 各 $i$ について、`s[0, i]` (両端を含む) の接頭辞であり接尾辞でもある部分のうち、`s[0, i]` 自身を除いた最長の長さ `pi[i]` を並べた `std::vector<long long>` | $O(n)$ |
| `kmp_search(text, pattern)` | `text` の中で `pattern` が現れる開始位置を昇順に並べた `std::vector<long long>`。$n$、$m$ は `text`、`pattern` の長さ。`pattern` が空なら $0, 1, \dots, n$ | $O(n + m)$ |

## 関連

- Z-algorithm は [Z-algorithm](z-algorithm.hpp)
- 複数のパターンを同時に探すには [Aho-Corasick](aho-corasick.hpp)
- ワイルドカードを含むパターンの検索は [ワイルドカードつきのパターンマッチング](wildcard-matching.hpp)
