---
title: Z-algorithm
documentation_of: //src/string/z-algorithm.hpp
---

各 $i$ について、列 `s` と `s[i:]` の最長共通接頭辞の長さを $O(n)$ で求めます。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
auto z = z_algorithm(std::string("aabaab"));  // {6, 1, 0, 3, 1, 0}
```

パターン `p` の出現位置は、区切りの文字 (どちらにも現れない値) をはさんで `p + '$' + s` の Z 配列を作り、`z[m + 1 + i] >= m` となる `i` を探せば求められます。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `z_algorithm(s)` / `z_algorithm(begin, end)` | 各 $i$ について、`s` と `s[i:]` の最長共通接頭辞の長さ `z[i]` を並べた `std::vector<long long>` (`z[0]` は `s` の長さ) | $O(n)$ |

## 関連

- 接頭辞関数と KMP 法は [KMP 法](kmp.hpp)
- 接尾辞どうしの最長共通接頭辞は [Suffix Array と LCP 配列](suffix-array.hpp)
- 部分文字列の一致判定をハッシュで行うには [ローリングハッシュ](rolling-hash.hpp)
