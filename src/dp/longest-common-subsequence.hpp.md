---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-10-c.test.cpp
    title: test/aoj/alds1/alds1-10-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/edit-distance.test.cpp
    title: test/unittest/dp/edit-distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)"
    links: []
  bundledCode: "#line 2 \"src/dp/longest-common-subsequence.hpp\"\n\n/**\n * @file\
    \ longest-common-subsequence.hpp\n * @brief \u6700\u9577\u5171\u901A\u90E8\u5206\
    \u5217 (LCS)\n */\n\n#include <algorithm>\n#include <iterator>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief s \u3068 t \u306E\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u5217\u306E\u9577\u3055 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\
    \u308B\u3002\u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename\
    \ R2>\nlong long longest_common_subsequence(const R1& s, const R2& t) {\n    auto\
    \ a = std::begin(s);\n    auto b = std::begin(t);\n    long long n = std::end(s)\
    \ - a, m = std::end(t) - b;\n    // dp[j] \u306F s[0, i) \u3068 t[0, j) \u306E\
    \ LCS \u306E\u9577\u3055\n    std::vector<long long> dp(m + 1);\n    for (long\
    \ long i = 1; i <= n; i++) {\n        long long diag = 0;  // s[0, i - 1) \u3068\
    \ t[0, j - 1) \u306E LCS \u306E\u9577\u3055\n        for (long long j = 1; j <=\
    \ m; j++) {\n            long long up = dp[j];\n            dp[j] = a[i - 1] ==\
    \ b[j - 1] ? diag + 1 : std::max(dp[j], dp[j - 1]);\n            diag = up;\n\
    \        }\n    }\n    return dp[m];\n}\n\n/**\n * @brief s \u3068 t \u306E\u6700\
    \u9577\u5171\u901A\u90E8\u5206\u5217\u3092 1 \u3064\u6C42\u3081\u308B O(nm)\n\
    \ * s[i] == t[j] \u3068\u3057\u3066\u9078\u3093\u3060\u6DFB\u5B57\u306E\u7D44\
    \ (i, j) \u3092\u3001\u6607\u9806\u306B\u4E26\u3079\u305F\u30EA\u30B9\u30C8\u3092\
    \u8FD4\u3059\u3002\u30E1\u30E2\u30EA\u306F O(nm)\n */\ntemplate <typename R1,\
    \ typename R2>\nstd::vector<std::pair<long long, long long>> longest_common_subsequence_restore(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[i][j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\n    std::vector<std::vector<int>>\
    \ dp(n + 1, std::vector<int>(m + 1));\n    for (long long i = 1; i <= n; i++)\
    \ {\n        for (long long j = 1; j <= m; j++) {\n            dp[i][j] = a[i\
    \ - 1] == b[j - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n\
    \        }\n    }\n    // \u5F8C\u308D\u304B\u3089\u305F\u3069\u308B\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (long long i = n, j = m; i > 0 && j > 0;) {\n\
    \        if (a[i - 1] == b[j - 1]) {\n            res.emplace_back(i - 1, j -\
    \ 1);\n            i--, j--;\n        } else if (dp[i - 1][j] >= dp[i][j - 1])\
    \ {\n            i--;\n        } else {\n            j--;\n        }\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file longest-common-subsequence.hpp\n * @brief \u6700\
    \u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)\n */\n\n#include <algorithm>\n#include\
    \ <iterator>\n#include <utility>\n#include <vector>\n\n/**\n * @brief s \u3068\
    \ t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u306E\u9577\u3055 O(nm)\n\
    \ * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\u306F\
    \ O(m)\n */\ntemplate <typename R1, typename R2>\nlong long longest_common_subsequence(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\n    std::vector<long long>\
    \ dp(m + 1);\n    for (long long i = 1; i <= n; i++) {\n        long long diag\
    \ = 0;  // s[0, i - 1) \u3068 t[0, j - 1) \u306E LCS \u306E\u9577\u3055\n    \
    \    for (long long j = 1; j <= m; j++) {\n            long long up = dp[j];\n\
    \            dp[j] = a[i - 1] == b[j - 1] ? diag + 1 : std::max(dp[j], dp[j -\
    \ 1]);\n            diag = up;\n        }\n    }\n    return dp[m];\n}\n\n/**\n\
    \ * @brief s \u3068 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\u3092 1\
    \ \u3064\u6C42\u3081\u308B O(nm)\n * s[i] == t[j] \u3068\u3057\u3066\u9078\u3093\
    \u3060\u6DFB\u5B57\u306E\u7D44 (i, j) \u3092\u3001\u6607\u9806\u306B\u4E26\u3079\
    \u305F\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\u30E1\u30E2\u30EA\u306F O(nm)\n\
    \ */\ntemplate <typename R1, typename R2>\nstd::vector<std::pair<long long, long\
    \ long>> longest_common_subsequence_restore(const R1& s, const R2& t) {\n    auto\
    \ a = std::begin(s);\n    auto b = std::begin(t);\n    long long n = std::end(s)\
    \ - a, m = std::end(t) - b;\n    // dp[i][j] \u306F s[0, i) \u3068 t[0, j) \u306E\
    \ LCS \u306E\u9577\u3055\n    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m\
    \ + 1));\n    for (long long i = 1; i <= n; i++) {\n        for (long long j =\
    \ 1; j <= m; j++) {\n            dp[i][j] = a[i - 1] == b[j - 1] ? dp[i - 1][j\
    \ - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n        }\n    }\n    // \u5F8C\
    \u308D\u304B\u3089\u305F\u3069\u308B\n    std::vector<std::pair<long long, long\
    \ long>> res;\n    for (long long i = n, j = m; i > 0 && j > 0;) {\n        if\
    \ (a[i - 1] == b[j - 1]) {\n            res.emplace_back(i - 1, j - 1);\n    \
    \        i--, j--;\n        } else if (dp[i - 1][j] >= dp[i][j - 1]) {\n     \
    \       i--;\n        } else {\n            j--;\n        }\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/longest-common-subsequence.hpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/edit-distance.test.cpp
  - test/aoj/alds1/alds1-10-c.test.cpp
documentation_of: src/dp/longest-common-subsequence.hpp
layout: document
title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)"
---

2 つの列 `s`、`t` の最長共通部分列を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
std::string s = "abcbdab", t = "bdcaba";
long long k = longest_common_subsequence(s, t);        // 4
auto idx = longest_common_subsequence_restore(s, t);  // 添字の組 (i, j) のリスト。長さは 4
std::string lcs;
for (auto [i, j] : idx) lcs += s[i];                   // 共通部分列の 1 つ
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `longest_common_subsequence(s, t)` | 最長共通部分列の長さ (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |
| `longest_common_subsequence_restore(s, t)` | 最長共通部分列を 1 つ求め、`s[i] == t[j]` として選んだ添字の組 `(i, j)` を昇順に並べたリスト (`std::vector<std::pair<long long, long long>>`) | 時間 $O(nm)$、メモリ $O(nm)$ |

復元では $(n + 1)(m + 1)$ 個の `int` の表を作るので、メモリに注意してください ($n = m = 5000$ で約 100 MB)。

## 関連

- 1 つの列の最長増加部分列は [最長増加部分列 (LIS)](longest-increasing-subsequence.hpp)
- 挿入・削除・置換の最小回数は [編集距離](edit-distance.hpp)
- 連続する共通部分 (部分文字列) の最長は [最長共通部分文字列](../string/longest-common-substring.hpp)
