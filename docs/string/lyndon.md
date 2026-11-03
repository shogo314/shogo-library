---
title: Lyndon 分解
documentation_of: //src/string/lyndon.hpp
---

列を Lyndon 文字列の辞書順で広義単調減少な並びに分ける Lyndon 分解を、Duval のアルゴリズムで $O(n)$ で求めます。Lyndon 文字列は、自分のどの真の接尾辞よりも辞書順で真に小さい文字列です。文字列のほか、`vector` などの列にも使えます (要素は `<` で比べます)。

```cpp
auto a = lyndon_factorization(std::string("abracadabra"));  // {0, 7, 10, 11} (abracad | abr | a)
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `lyndon_factorization(s)` / `lyndon_factorization(begin, end)` | Lyndon 分解 $s = w_1 w_2 \cdots w_k$ ($w_1 \ge w_2 \ge \dots \ge w_k$) の区切りの位置 $0 = a_0 < a_1 < \dots < a_k = n$ を並べた `std::vector<long long>` ($w_i$ は `s[a_{i-1}, a_i)`) | $O(n)$ |

## 関連

- 接尾辞を辞書順に並べるには [Suffix Array と LCP 配列](suffix-array.hpp)
