---
title: ワイルドカードつきのパターンマッチング
documentation_of: //src/string/wildcard-matching.hpp
---

`text` の中で `pattern` と一致する開始位置を、昇順に $O((n + m) \log (n + m))$ で求めます。`wildcard` の要素はどの要素とも一致し、`text` と `pattern` のどちらに入っていてもかまいません。文字列のほか、`vector` などの列にも使えます。

```cpp
auto pos = wildcard_pattern_matching(std::string("abcab"), std::string("a*"), '*');  // {0, 3}
auto q = wildcard_pattern_matching(std::vector<int>{1, -1, 2}, std::vector<int>{3, 2}, -1);  // {1}
```

要素を 0 でない乱数の値 $a$ に、`wildcard` を 0 に置き換えると、位置 $i$ で一致するのは $\sum_j a_{i+j} b_j (a_{i+j} - b_j)^2 = 0$ のときです。これを 3 回の畳み込み ($\bmod 998244353$) でまとめて求めます。乱数を使うので、一致しない位置を一致すると判定する確率が位置ごとに $4 / 998244353$ ほどあります。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `wildcard_pattern_matching(text, pattern, wildcard)` | `text` の中で `pattern` と一致する開始位置 (`std::vector<long long>`、昇順)。`pattern` が空なら $0, 1, \dots, n$ | $O((n + m) \log (n + m))$ |

要素の型は `std::map` のキーにするので、`<` で比べられる必要があります。

## 関連

- ワイルドカードがなければ [文字列アルゴリズム](string.hpp) の `kmp_search` ($O(n + m)$)
- 畳み込みは [畳み込み](../math/convolution.hpp)
