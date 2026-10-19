---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/edit-distance.hpp
    title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
      \u30F3\u8DDD\u96E2)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/edit-distance.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ edit_distance \u3068 longest_common_subsequence\u3001\u305D\u306E\u5FA9\u5143\
    \u3092\u3001\u518D\u5E30\u306B\u3088\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/dp/edit-distance.hpp\"\
    \n\n/**\n * @file edit-distance.hpp\n * @brief \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\
    \u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n */\n\n#include\
    \ <algorithm>\n#include <iterator>\n#include <vector>\n\n/**\n * @brief s \u3092\
    \ t \u306B\u5909\u3048\u308B\u306E\u306B\u5FC5\u8981\u306A\u633F\u5165\u30FB\u524A\
    \u9664\u30FB\u7F6E\u63DB\u306E\u6700\u5C0F\u56DE\u6570 O(nm)\n * \u8981\u7D20\u306F\
    \ == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate\
    \ <typename R1, typename R2>\nlong long edit_distance(const R1& s, const R2& t)\
    \ {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n    long long n\
    \ = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F s[0, i) \u3068\
    \ t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\n    std::vector<long long> dp(m + 1);\n\
    \    for (long long j = 0; j <= m; j++) dp[j] = j;\n    for (long long i = 1;\
    \ i <= n; i++) {\n        long long diag = dp[0];  // s[0, i - 1) \u3068 t[0,\
    \ j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n        dp[0] = i;\n        for (long\
    \ long j = 1; j <= m; j++) {\n            long long up = dp[j];\n            dp[j]\
    \ = std::min({dp[j] + 1, dp[j - 1] + 1, diag + (a[i - 1] == b[j - 1] ? 0 : 1)});\n\
    \            diag = up;\n        }\n    }\n    return dp[m];\n}\n#line 7 \"test/unittest/edit-distance.test.cpp\"\
    \n\n#line 9 \"test/unittest/edit-distance.test.cpp\"\n#include <iostream>\n#include\
    \ <random>\n#include <string>\n#line 13 \"test/unittest/edit-distance.test.cpp\"\
    \n\n#line 2 \"src/dp/longest-common-subsequence.hpp\"\n\n/**\n * @file longest-common-subsequence.hpp\n\
    \ * @brief \u6700\u9577\u5171\u901A\u90E8\u5206\u5217 (LCS)\n */\n\n#line 10 \"\
    src/dp/longest-common-subsequence.hpp\"\n#include <utility>\n#line 12 \"src/dp/longest-common-subsequence.hpp\"\
    \n\n/**\n * @brief s \u3068 t \u306E\u6700\u9577\u5171\u901A\u90E8\u5206\u5217\
    \u306E\u9577\u3055 O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\
    \u30E1\u30E2\u30EA\u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong\
    \ long longest_common_subsequence(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    // dp[j] \u306F s[0, i) \u3068 t[0, j) \u306E LCS \u306E\u9577\u3055\
    \n    std::vector<long long> dp(m + 1);\n    for (long long i = 1; i <= n; i++)\
    \ {\n        long long diag = 0;  // s[0, i - 1) \u3068 t[0, j - 1) \u306E LCS\
    \ \u306E\u9577\u3055\n        for (long long j = 1; j <= m; j++) {\n         \
    \   long long up = dp[j];\n            dp[j] = a[i - 1] == b[j - 1] ? diag + 1\
    \ : std::max(dp[j], dp[j - 1]);\n            diag = up;\n        }\n    }\n  \
    \  return dp[m];\n}\n\n/**\n * @brief s \u3068 t \u306E\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u5217\u3092 1 \u3064\u6C42\u3081\u308B O(nm)\n * s[i] == t[j] \u3068\
    \u3057\u3066\u9078\u3093\u3060\u6DFB\u5B57\u306E\u7D44 (i, j) \u3092\u3001\u6607\
    \u9806\u306B\u4E26\u3079\u305F\u30EA\u30B9\u30C8\u3092\u8FD4\u3059\u3002\u30E1\
    \u30E2\u30EA\u306F O(nm)\n */\ntemplate <typename R1, typename R2>\nstd::vector<std::pair<long\
    \ long, long long>> longest_common_subsequence_restore(const R1& s, const R2&\
    \ t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n    long long\
    \ n = std::end(s) - a, m = std::end(t) - b;\n    // dp[i][j] \u306F s[0, i) \u3068\
    \ t[0, j) \u306E LCS \u306E\u9577\u3055\n    std::vector<std::vector<int>> dp(n\
    \ + 1, std::vector<int>(m + 1));\n    for (long long i = 1; i <= n; i++) {\n \
    \       for (long long j = 1; j <= m; j++) {\n            dp[i][j] = a[i - 1]\
    \ == b[j - 1] ? dp[i - 1][j - 1] + 1 : std::max(dp[i - 1][j], dp[i][j - 1]);\n\
    \        }\n    }\n    // \u5F8C\u308D\u304B\u3089\u305F\u3069\u308B\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (long long i = n, j = m; i > 0 && j > 0;) {\n\
    \        if (a[i - 1] == b[j - 1]) {\n            res.emplace_back(i - 1, j -\
    \ 1);\n            i--, j--;\n        } else if (dp[i - 1][j] >= dp[i][j - 1])\
    \ {\n            i--;\n        } else {\n            j--;\n        }\n    }\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n}\n#line 15 \"test/unittest/edit-distance.test.cpp\"\
    \n\n// s[i:] \u3068 t[j:] \u306E\u7DE8\u96C6\u8DDD\u96E2\nint naive_edit(const\
    \ std::string& s, const std::string& t, int i, int j) {\n    if (i == static_cast<int>(s.size()))\
    \ return t.size() - j;\n    if (j == static_cast<int>(t.size())) return s.size()\
    \ - i;\n    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);\n    res\
    \ = std::min(res, naive_edit(s, t, i + 1, j) + 1);\n    res = std::min(res, naive_edit(s,\
    \ t, i, j + 1) + 1);\n    return res;\n}\n\n// s[i:] \u3068 t[j:] \u306E LCS \u306E\
    \u9577\u3055\nint naive_lcs(const std::string& s, const std::string& t, int i,\
    \ int j) {\n    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size()))\
    \ return 0;\n    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t,\
    \ i, j + 1));\n    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1,\
    \ j + 1) + 1);\n    return res;\n}\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 8, m = rng() % 8;\n        int k = rng() % 3 + 1;\n      \
    \  std::string s(n, 'a'), t(m, 'a');\n        for (auto& c : s) c = 'a' + rng()\
    \ % k;\n        for (auto& c : t) c = 'a' + rng() % k;\n\n        ok = ok && edit_distance(s,\
    \ t) == naive_edit(s, t, 0, 0);\n        int len = naive_lcs(s, t, 0, 0);\n  \
    \      ok = ok && longest_common_subsequence(s, t) == len;\n\n        // \u5FA9\
    \u5143: \u9577\u3055\u304C\u6700\u9577\u3067\u3001\u6DFB\u5B57\u304C\u4E21\u65B9\
    \u3068\u3082\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\u3057\u3001\u8981\u7D20\u304C\
    \u4E00\u81F4\u3059\u308B\n        auto idx = longest_common_subsequence_restore(s,\
    \ t);\n        ok = ok && static_cast<int>(idx.size()) == len;\n        for (int\
    \ p = 0; p < static_cast<int>(idx.size()) && ok; p++) {\n            auto [i,\
    \ j] = idx[p];\n            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] ==\
    \ t[j];\n            if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second\
    \ < j;\n        }\n    }\n\n    // \u4F8B\n    ok = ok && edit_distance(std::string(\"\
    kitten\"), std::string(\"sitting\")) == 3;\n    ok = ok && edit_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<int>{2, 3, 4}) == 2;\n    ok = ok && edit_distance(std::string(\"\
    \"), std::string(\"abc\")) == 3;\n    ok = ok && longest_common_subsequence(std::string(\"\
    abcbdab\"), std::string(\"bdcaba\")) == 4;\n    ok = ok && longest_common_subsequence(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{3, 1, 2}) == 2;\n    ok = ok && longest_common_subsequence_restore(std::string(\"\
    \"), std::string(\"abc\")).empty();\n\n    if (ok)\n        std::cout << \"Hello\
    \ World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// edit_distance \u3068 longest_common_subsequence\u3001\u305D\u306E\u5FA9\
    \u5143\u3092\u3001\u518D\u5E30\u306B\u3088\u308B\u611A\u76F4\u306A\u65B9\u6CD5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/dp/edit-distance.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #include <vector>\n\n#include \"../../src/dp/longest-common-subsequence.hpp\"\n\
    \n// s[i:] \u3068 t[j:] \u306E\u7DE8\u96C6\u8DDD\u96E2\nint naive_edit(const std::string&\
    \ s, const std::string& t, int i, int j) {\n    if (i == static_cast<int>(s.size()))\
    \ return t.size() - j;\n    if (j == static_cast<int>(t.size())) return s.size()\
    \ - i;\n    int res = naive_edit(s, t, i + 1, j + 1) + (s[i] != t[j]);\n    res\
    \ = std::min(res, naive_edit(s, t, i + 1, j) + 1);\n    res = std::min(res, naive_edit(s,\
    \ t, i, j + 1) + 1);\n    return res;\n}\n\n// s[i:] \u3068 t[j:] \u306E LCS \u306E\
    \u9577\u3055\nint naive_lcs(const std::string& s, const std::string& t, int i,\
    \ int j) {\n    if (i == static_cast<int>(s.size()) || j == static_cast<int>(t.size()))\
    \ return 0;\n    int res = std::max(naive_lcs(s, t, i + 1, j), naive_lcs(s, t,\
    \ i, j + 1));\n    if (s[i] == t[j]) res = std::max(res, naive_lcs(s, t, i + 1,\
    \ j + 1) + 1);\n    return res;\n}\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 8, m = rng() % 8;\n        int k = rng() % 3 + 1;\n      \
    \  std::string s(n, 'a'), t(m, 'a');\n        for (auto& c : s) c = 'a' + rng()\
    \ % k;\n        for (auto& c : t) c = 'a' + rng() % k;\n\n        ok = ok && edit_distance(s,\
    \ t) == naive_edit(s, t, 0, 0);\n        int len = naive_lcs(s, t, 0, 0);\n  \
    \      ok = ok && longest_common_subsequence(s, t) == len;\n\n        // \u5FA9\
    \u5143: \u9577\u3055\u304C\u6700\u9577\u3067\u3001\u6DFB\u5B57\u304C\u4E21\u65B9\
    \u3068\u3082\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\u3057\u3001\u8981\u7D20\u304C\
    \u4E00\u81F4\u3059\u308B\n        auto idx = longest_common_subsequence_restore(s,\
    \ t);\n        ok = ok && static_cast<int>(idx.size()) == len;\n        for (int\
    \ p = 0; p < static_cast<int>(idx.size()) && ok; p++) {\n            auto [i,\
    \ j] = idx[p];\n            ok = 0 <= i && i < n && 0 <= j && j < m && s[i] ==\
    \ t[j];\n            if (p > 0) ok = ok && idx[p - 1].first < i && idx[p - 1].second\
    \ < j;\n        }\n    }\n\n    // \u4F8B\n    ok = ok && edit_distance(std::string(\"\
    kitten\"), std::string(\"sitting\")) == 3;\n    ok = ok && edit_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<int>{2, 3, 4}) == 2;\n    ok = ok && edit_distance(std::string(\"\
    \"), std::string(\"abc\")) == 3;\n    ok = ok && longest_common_subsequence(std::string(\"\
    abcbdab\"), std::string(\"bdcaba\")) == 4;\n    ok = ok && longest_common_subsequence(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{3, 1, 2}) == 2;\n    ok = ok && longest_common_subsequence_restore(std::string(\"\
    \"), std::string(\"abc\")).empty();\n\n    if (ok)\n        std::cout << \"Hello\
    \ World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/dp/edit-distance.hpp
  - src/dp/longest-common-subsequence.hpp
  isVerificationFile: true
  path: test/unittest/edit-distance.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:29:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/edit-distance.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/edit-distance.test.cpp
- /verify/test/unittest/edit-distance.test.cpp.html
title: test/unittest/edit-distance.test.cpp
---
