---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/manacher.test.cpp
    title: test/unittest/string/manacher.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/enumerate-palindromes.2.test.cpp
    title: test/yosupo/string/enumerate-palindromes.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Manacher \u6CD5\u3068\u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
      \u3059\u308B\u6700\u9577\u306E\u56DE\u6587"
    links: []
  bundledCode: "#line 2 \"src/string/manacher.hpp\"\n\n/**\n * @file manacher.hpp\n\
    \ * @brief Manacher \u6CD5\u3068\u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\
    \u308B\u6700\u9577\u306E\u56DE\u6587\n */\n\n#include <algorithm>\n#include <iterator>\n\
    #include <vector>\n\n/**\n * @brief Manacher \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u5947\u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\u306E\
    \u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i]) \u304C\u56DE\u6587) \u3092\u5404\
    \ i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n *\
    \ @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin\
    \ \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end\
    \ \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long\
    \ long> r\n */\ntemplate <typename It>\nstd::vector<long long> manacher(It begin,\
    \ It end) {\n    long long n = end - begin;\n    std::vector<long long> r(n);\n\
    \    // [l, rr] \u306F\u3001\u3053\u308C\u307E\u3067\u306B\u898B\u3064\u3051\u305F\
    \u56DE\u6587\u306E\u3046\u3061\u53F3\u7AEF\u304C\u6700\u3082\u53F3\u306B\u3042\
    \u308B\u3082\u306E\n    for (long long i = 0, l = 0, rr = -1; i < n; i++) {\n\
    \        long long k = i > rr ? 1 : std::min(r[l + rr - i], rr - i + 1);\n   \
    \     while (0 <= i - k && i + k < n && begin[i - k] == begin[i + k]) k++;\n \
    \       r[i] = k--;\n        if (i + k > rr) {\n            l = i - k;\n     \
    \       rr = i + k;\n        }\n    }\n    return r;\n}\n\n/**\n * @brief Manacher\
    \ \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\
    \u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i])\
    \ \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B\
    \ \u5168\u4F53\u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param\
    \ s \u914D\u5217\n * @return std::vector<long long> r\n */\ntemplate <typename\
    \ R>\nstd::vector<long long> manacher(const R& s) {\n    return manacher(std::begin(s),\
    \ std::end(s));\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam It \u914D\u5217\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\
    \u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> len\n */\ntemplate\
    \ <typename It>\nstd::vector<long long> palindrome_lengths(It begin, It end) {\n\
    \    long long n = end - begin;\n    if (n == 0) return {};\n    std::vector<long\
    \ long> odd = manacher(begin, end);\n    // even[i] \u306F s[i - 1] \u3068 s[i]\
    \ \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u56DE\
    \u6587\u306E\u6700\u5927\u306E\u534A\u5F84\n    std::vector<long long> even(n);\n\
    \    for (long long i = 0, l = 0, rr = -1; i < n; i++) {\n        long long k\
    \ = i > rr ? 0 : std::min(even[l + rr - i + 1], rr - i + 1);\n        while (0\
    \ <= i - k - 1 && i + k < n && begin[i - k - 1] == begin[i + k]) k++;\n      \
    \  even[i] = k--;\n        if (i + k > rr) {\n            l = i - k - 1;\n   \
    \         rr = i + k;\n        }\n    }\n    std::vector<long long> len(2 * n\
    \ - 1);\n    for (long long i = 0; i < n; i++) len[2 * i] = 2 * odd[i] - 1;\n\
    \    for (long long i = 0; i + 1 < n; i++) len[2 * i + 1] = 2 * even[i + 1];\n\
    \    return len;\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam R \u914D\u5217\
    \u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long long> len\n\
    \ */\ntemplate <typename R>\nstd::vector<long long> palindrome_lengths(const R&\
    \ s) {\n    return palindrome_lengths(std::begin(s), std::end(s));\n}\n"
  code: "#pragma once\n\n/**\n * @file manacher.hpp\n * @brief Manacher \u6CD5\u3068\
    \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u306E\u56DE\
    \u6587\n */\n\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\n\
    /**\n * @brief Manacher \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\
    \u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i -\
    \ r[i] + 1, i + r[i]) \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\
    \u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> r\n */\ntemplate <typename\
    \ It>\nstd::vector<long long> manacher(It begin, It end) {\n    long long n =\
    \ end - begin;\n    std::vector<long long> r(n);\n    // [l, rr] \u306F\u3001\u3053\
    \u308C\u307E\u3067\u306B\u898B\u3064\u3051\u305F\u56DE\u6587\u306E\u3046\u3061\
    \u53F3\u7AEF\u304C\u6700\u3082\u53F3\u306B\u3042\u308B\u3082\u306E\n    for (long\
    \ long i = 0, l = 0, rr = -1; i < n; i++) {\n        long long k = i > rr ? 1\
    \ : std::min(r[l + rr - i], rr - i + 1);\n        while (0 <= i - k && i + k <\
    \ n && begin[i - k] == begin[i + k]) k++;\n        r[i] = k--;\n        if (i\
    \ + k > rr) {\n            l = i - k;\n            rr = i + k;\n        }\n  \
    \  }\n    return r;\n}\n\n/**\n * @brief Manacher \u6CD5\n * s[i] \u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\
    \u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i]) \u304C\u56DE\u6587) \u3092\u5404\
    \ i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n *\
    \ @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long\
    \ long> r\n */\ntemplate <typename R>\nstd::vector<long long> manacher(const R&\
    \ s) {\n    return manacher(std::begin(s), std::end(s));\n}\n\n/**\n * @brief\
    \ \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u306E\u56DE\
    \u6587\u306E\u9577\u3055 \u5168\u4F53\u3067 O(N)\n * \u9577\u3055 2N - 1 \u306E\
    \u914D\u5217 len \u3092\u8FD4\u3059\u3002len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u56DE\u6587\u3001len[2i + 1] \u306F s[i] \u3068 s[i + 1] \u306E\
    \u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u306E\u6700\u9577\u306E\
    \u9577\u3055\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n\
    \ * @return std::vector<long long> len\n */\ntemplate <typename It>\nstd::vector<long\
    \ long> palindrome_lengths(It begin, It end) {\n    long long n = end - begin;\n\
    \    if (n == 0) return {};\n    std::vector<long long> odd = manacher(begin,\
    \ end);\n    // even[i] \u306F s[i - 1] \u3068 s[i] \u306E\u9593\u3092\u4E2D\u5FC3\
    \u3068\u3059\u308B\u5076\u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\u306E\
    \u534A\u5F84\n    std::vector<long long> even(n);\n    for (long long i = 0, l\
    \ = 0, rr = -1; i < n; i++) {\n        long long k = i > rr ? 0 : std::min(even[l\
    \ + rr - i + 1], rr - i + 1);\n        while (0 <= i - k - 1 && i + k < n && begin[i\
    \ - k - 1] == begin[i + k]) k++;\n        even[i] = k--;\n        if (i + k >\
    \ rr) {\n            l = i - k - 1;\n            rr = i + k;\n        }\n    }\n\
    \    std::vector<long long> len(2 * n - 1);\n    for (long long i = 0; i < n;\
    \ i++) len[2 * i] = 2 * odd[i] - 1;\n    for (long long i = 0; i + 1 < n; i++)\
    \ len[2 * i + 1] = 2 * even[i + 1];\n    return len;\n}\n\n/**\n * @brief \u5404\
    \u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\u9577\u306E\u56DE\u6587\
    \u306E\u9577\u3055 \u5168\u4F53\u3067 O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\
    \u5217 len \u3092\u8FD4\u3059\u3002len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u56DE\u6587\u3001len[2i + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\
    \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u306E\u6700\u9577\u306E\u9577\
    \u3055\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n\
    \ * @return std::vector<long long> len\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> palindrome_lengths(const R& s) {\n    return palindrome_lengths(std::begin(s),\
    \ std::end(s));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/manacher.hpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/manacher.test.cpp
  - test/yosupo/string/enumerate-palindromes.2.test.cpp
documentation_of: src/string/manacher.hpp
layout: document
title: "Manacher \u6CD5"
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
