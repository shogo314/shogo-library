---
title: 最長共通部分文字列
documentation_of: //src/string/longest-common-substring.hpp
---

2 つの列 `s`、`t` に共通して現れる、最も長い連続する部分列 (部分文字列) を 1 つ求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `operator<` で比べます)。

```cpp
auto [i, j, len] = longest_common_substring(std::string("abracadabra"), std::string("cadabx"));
// i = 4, j = 0, len = 5 ("cadab")
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `longest_common_substring(s, t)` | `s[i, i + len) == t[j, j + len)` となる最長の `(i, j, len)` を 1 つ求め、`std::tuple<long long, long long, long long>` で返す。共通部分がなければ `(0, 0, 0)` | $O((n + m) \log (n + m))$ |

`s`、区切り、`t` の順につないだ列の [Suffix Array と LCP 配列](suffix-array.hpp) を作り、辞書順で隣り合う接尾辞のうち、片方が `s`、もう片方が `t` から始まるものの LCP の最大を取ります。区切りの値は 1 回しか現れないので、LCP が区切りをまたぐことはありません。計算量の $\log$ は座標圧縮の分です。

## 関連

- 連続でなくてよい共通部分列は [最長共通部分列 (LCS)](../dp/longest-common-subsequence.hpp)
