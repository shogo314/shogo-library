---
title: Z-algorithm
documentation_of: //src/string/string.hpp
---

| 関数 | 説明 | 計算量 |
|---|---|---|
| `z_algorithm(s)` / `z_algorithm(first, last)` | 各 $i$ について、`s` と `s[i:]` の最長共通接頭辞の長さ `z[i]` を並べた `vector<int>` (`z[0]` は `s` の長さ) | $O(n)$ |

文字列のほか、`vector` などの列にも使えます。

```cpp
auto z = z_algorithm(std::string("aabaab"));  // {6, 1, 0, 3, 1, 0}
```

パターン `p` の出現位置を求めるには、区切り文字をはさんで連結した `p + '$' + s` の Z 配列で、値が `p.size()` 以上の位置を探します。
