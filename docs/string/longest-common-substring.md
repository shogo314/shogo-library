---
title: 最長共通部分文字列と、最長の繰り返し部分文字列
documentation_of: //src/string/longest-common-substring.hpp
---

2 つの列 `s`、`t` に共通して現れる、最も長い連続する部分列 (部分文字列) を 1 つ求めます。$n$、$m$ は `s`、`t` の長さです。また、1 つの列の中に 2 回以上現れる最も長い部分文字列も、重なってよい場合と重ならない場合のそれぞれで求めます。文字列のほか、`vector` などの列にも使えます (要素は `operator<` で比べます)。

```cpp
auto [i, j, len] = longest_common_substring(std::string("abracadabra"), std::string("cadabx"));
// i = 4, j = 0, len = 5 ("cadab")

auto [a, b, l1] = longest_repeated_substring(std::string("ababa"));                // a = 0, b = 2, l1 = 3 ("aba"、重なってよい)
auto [c, d, l2] = longest_non_overlapping_repeated_substring(std::string("ababa"));  // l2 = 2 ("ab" か "ba")
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `longest_common_substring(s, t)` | `s[i, i + len) == t[j, j + len)` となる最長の `(i, j, len)` を 1 つ求め、`std::tuple<long long, long long, long long>` で返す。共通部分がなければ `(0, 0, 0)` | $O((n + m) \log (n + m))$ |
| `longest_repeated_substring(s)` | `s` の中に 2 回以上現れる (重なってよい) 最長の部分文字列。`s[i, i + len) == s[j, j + len)`、$i < j$ となる `(i, j, len)` を 1 つ返す。なければ `(0, 0, 0)` | $O(n \log n)$ |
| `longest_non_overlapping_repeated_substring(s)` | 同じく、重ならずに 2 回以上現れるもの ($i + \mathit{len} \le j$) | $O(n \log n)$ |

`s`、区切り、`t` の順につないだ列の [Suffix Array と LCP 配列](suffix-array.hpp) を作り、辞書順で隣り合う接尾辞のうち、片方が `s`、もう片方が `t` から始まるものの LCP の最大を取ります。区切りの値は 1 回しか現れないので、LCP が区切りをまたぐことはありません。計算量の $\log$ は座標圧縮の分です。

`longest_repeated_substring` は、`s` の Suffix Array で辞書順に隣り合う接尾辞の LCP の最大です。

`longest_non_overlapping_repeated_substring` は、長さ $L$ で二分探索します (長さ $L$ のものがあれば、先頭を切れば $L - 1$ のものもあるので単調です)。$L$ を固定したら、辞書順で隣り合う LCP が $L$ 以上の連続した区間ごとに、開始位置の最小と最大の差が $L$ 以上かを見ます。

## 関連

- 連続でなくてよい共通部分列は [最長共通部分列 (LCS)](../dp/longest-common-subsequence.hpp)
- 1 つの文字列を固定して、多くの文字列との最長共通部分文字列の長さを求めるなら [Suffix Automaton](suffix-automaton.hpp) の `match_lengths`
