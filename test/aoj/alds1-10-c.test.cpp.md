---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/longest-common-subsequence.hpp
    title: "\u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C
  bundledCode: "#line 1 \"test/aoj/alds1-10-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"src/dp/longest-common-subsequence.hpp\"\
    \n\n/**\n * @file longest-common-subsequence.hpp\n * @brief \u6700\u9577\u5171\
    \u901A\u90E8\u5206\u5217 (LCS)\n */\n\n#include <algorithm>\n#include <iterator>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief s \u3068 t \u306E\u6700\
    \u9577\u5171\u901A\u90E8\u5206\u5217\u306E\u9577\u3055 O(nm)\n * \u8981\u7D20\u306F\
    \ == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate\
    \ <typename R1, typename R2>\nlong long longest_common_subsequence(const R1& s,\
    \ const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n \
    \   long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F s[0,\
    \ i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\n    std::vector<long long>\
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
    \ res.end());\n    return res;\n}\n#line 7 \"test/aoj/alds1-10-c.test.cpp\"\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int q;\n    std::cin >> q;\n    while (q--) {\n        std::string x, y;\n\
    \        std::cin >> x >> y;\n        std::cout << longest_common_subsequence(x,\
    \ y) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_10_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../src/dp/longest-common-subsequence.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int q;\n    std::cin >> q;\n    while (q--) {\n        std::string x, y;\n\
    \        std::cin >> x >> y;\n        std::cout << longest_common_subsequence(x,\
    \ y) << '\\n';\n    }\n}\n"
  dependsOn:
  - src/dp/longest-common-subsequence.hpp
  isVerificationFile: true
  path: test/aoj/alds1-10-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1-10-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1-10-c.test.cpp
- /verify/test/aoj/alds1-10-c.test.cpp.html
title: test/aoj/alds1-10-c.test.cpp
---
