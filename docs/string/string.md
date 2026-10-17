---
title: 文字列アルゴリズム (Z-algorithm、KMP、Manacher)
documentation_of: //src/string/string.hpp
---

Z-algorithm・KMP 法・Manacher 法を $O(n)$ で行います。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。結果は `hamming_distance` だけ `long long`、ほかは `std::vector<long long>` で返します。

```cpp
auto z = z_algorithm(std::string("aabaab"));        // {6, 1, 0, 3, 1, 0}
auto pi = prefix_function(std::string("aabaaab"));  // {0, 1, 0, 1, 2, 2, 3}
auto pos = kmp_search(std::string("aaaa"), std::string("aa"));  // {0, 1, 2}
auto r = manacher(std::string("abaaba"));           // {1, 2, 1, 1, 2, 1}
auto len = palindrome_lengths(std::string("abaaba"));  // {1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1}
long long d = hamming_distance(std::string("karolin"), std::string("kathrin"));  // 3
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `z_algorithm(s)` / `z_algorithm(begin, end)` | 各 $i$ について、`s` と `s[i:]` の最長共通接頭辞の長さ `z[i]` を並べた `vector<long long>` (`z[0]` は `s` の長さ) | $O(n)$ |
| `prefix_function(s)` / `prefix_function(begin, end)` | 各 $i$ について、`s[0, i]` (両端を含む) の接頭辞であり接尾辞でもある部分のうち、`s[0, i]` 自身を除いた最長の長さ `pi[i]` (KMP 法の失敗関数) | $O(n)$ |
| `kmp_search(text, pattern)` | `text` の中で `pattern` が現れる開始位置を昇順に並べたもの (KMP 法)。$n$、$m$ は `text`、`pattern` の長さ。`pattern` が空なら $0, 1, \dots, n$ | $O(n + m)$ |
| `manacher(s)` / `manacher(begin, end)` | 各 $i$ について、`s[i]` を中心とする奇数長の回文の最大の半径 `r[i]` (`s[i - r[i] + 1, i + r[i])` が回文、長さは `2 * r[i] - 1`) | $O(n)$ |
| `palindrome_lengths(s)` / `palindrome_lengths(begin, end)` | 長さ $2n - 1$ の `len`。`len[2 * i]` は `s[i]` を中心とする最長の回文の長さ、`len[2 * i + 1]` は `s[i]` と `s[i + 1]` の間を中心とする最長の回文の長さ (なければ 0) | $O(n)$ |
| `hamming_distance(s, t)` | 同じ長さの `s` と `t` で要素が異なる位置の数 (長さが違うと assert で落ちる) | $O(n)$ |

- `s[l, r)` が回文かどうかは、`palindrome_lengths(s)[l + r - 1] >= r - l` で判定できます。
- 文字列の周期 (`s[i] == s[i + p]` がすべての i で成り立つ最小の `p`) は `n - pi[n - 1]` です。

## 関連

- 接尾辞を辞書順に並べるには [Suffix Array と LCP 配列](suffix-array.hpp)
- 部分文字列の一致判定をハッシュで行うには [ローリングハッシュ](rolling-hash.hpp)
- 複数の文字列の接頭辞を扱うには [Trie](trie.hpp)
- 2 つの列の最長共通部分文字列は [最長共通部分文字列](longest-common-substring.hpp)
- 整数のハミング距離は [ビット演算](../utility/bit.hpp) の `hamming_distance`
