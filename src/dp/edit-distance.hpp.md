---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/dpl-1-e.test.cpp
    title: test/aoj/dpl/dpl-1-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/edit-distance.test.cpp
    title: test/unittest/dp/edit-distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\
      \u30BF\u30A4\u30F3\u8DDD\u96E2)"
    links: []
  bundledCode: "#line 2 \"src/dp/edit-distance.hpp\"\n\n/**\n * @file edit-distance.hpp\n\
    \ * @brief \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\
    \u30A4\u30F3\u8DDD\u96E2)\n */\n\n#include <algorithm>\n#include <iterator>\n\
    #include <vector>\n\n/**\n * @brief s \u3092 t \u306B\u5909\u3048\u308B\u306E\u306B\
    \u5FC5\u8981\u306A\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u306E\u6700\
    \u5C0F\u56DE\u6570 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\
    \u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong\
    \ long edit_distance(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    // dp[j] \u306F s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\
    \n    std::vector<long long> dp(m + 1);\n    for (long long j = 0; j <= m; j++)\
    \ dp[j] = j;\n    for (long long i = 1; i <= n; i++) {\n        long long diag\
    \ = dp[0];  // s[0, i - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n\
    \        dp[0] = i;\n        for (long long j = 1; j <= m; j++) {\n          \
    \  long long up = dp[j];\n            dp[j] = std::min({dp[j] + 1, dp[j - 1] +\
    \ 1, diag + (a[i - 1] == b[j - 1] ? 0 : 1)});\n            diag = up;\n      \
    \  }\n    }\n    return dp[m];\n}\n"
  code: "#pragma once\n\n/**\n * @file edit-distance.hpp\n * @brief \u7DE8\u96C6\u8DDD\
    \u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n\
    \ */\n\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\n/**\n\
    \ * @brief s \u3092 t \u306B\u5909\u3048\u308B\u306E\u306B\u5FC5\u8981\u306A\u633F\
    \u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u306E\u6700\u5C0F\u56DE\u6570 O(nm)\n\
    \ * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\u306F\
    \ O(m)\n */\ntemplate <typename R1, typename R2>\nlong long edit_distance(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\n    std::vector<long\
    \ long> dp(m + 1);\n    for (long long j = 0; j <= m; j++) dp[j] = j;\n    for\
    \ (long long i = 1; i <= n; i++) {\n        long long diag = dp[0];  // s[0, i\
    \ - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n        dp[0] = i;\n\
    \        for (long long j = 1; j <= m; j++) {\n            long long up = dp[j];\n\
    \            dp[j] = std::min({dp[j] + 1, dp[j - 1] + 1, diag + (a[i - 1] == b[j\
    \ - 1] ? 0 : 1)});\n            diag = up;\n        }\n    }\n    return dp[m];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/edit-distance.hpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/edit-distance.test.cpp
  - test/aoj/dpl/dpl-1-e.test.cpp
documentation_of: src/dp/edit-distance.hpp
layout: document
title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
  \u30F3\u8DDD\u96E2)"
---

列 `s` を列 `t` に変えるのに必要な、1 要素の挿入・削除・置換の最小回数を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
long long d = edit_distance(std::string("kitten"), std::string("sitting"));  // 3
edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4});        // 2
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `edit_distance(s, t)` | 編集距離 (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |

## 関連

- 置換だけを許す場合 (同じ長さの列で異なる位置の数) は [文字列アルゴリズム](../string/string.hpp) の `hamming_distance`
- 挿入と削除だけを許す場合の最小回数は、[最長共通部分列 (LCS)](longest-common-subsequence.hpp) の長さ $L$ を使って $n + m - 2L$
