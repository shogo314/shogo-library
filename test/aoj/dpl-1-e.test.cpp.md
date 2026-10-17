---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/edit-distance.hpp
    title: "\u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
      \u30F3\u8DDD\u96E2)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
  bundledCode: "#line 1 \"test/aoj/dpl-1-e.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"src/dp/edit-distance.hpp\"\
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
    \            diag = up;\n        }\n    }\n    return dp[m];\n}\n#line 7 \"test/aoj/dpl-1-e.test.cpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout\
    \ << edit_distance(s, t) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../src/dp/edit-distance.hpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout\
    \ << edit_distance(s, t) << std::endl;\n}\n"
  dependsOn:
  - src/dp/edit-distance.hpp
  isVerificationFile: true
  path: test/aoj/dpl-1-e.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dpl-1-e.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dpl-1-e.test.cpp
- /verify/test/aoj/dpl-1-e.test.cpp.html
title: test/aoj/dpl-1-e.test.cpp
---
