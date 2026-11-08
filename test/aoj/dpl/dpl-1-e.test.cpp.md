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
  bundledCode: "#line 1 \"test/aoj/dpl/dpl-1-e.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 2 \"src/dp/edit-distance.hpp\"\
    \n\n/**\n * @file edit-distance.hpp\n * @brief \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\
    \u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <vector>\n\n\
    /**\n * @brief s \u3092 t \u306B\u5909\u3048\u308B\u306E\u306B\u5FC5\u8981\u306A\
    \u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u306E\u6700\u5C0F\u56DE\u6570\
    \ O(nm)\n * \u8981\u7D20\u306F == \u3067\u6BD4\u3079\u308B\u3002\u30E1\u30E2\u30EA\
    \u306F O(m)\n */\ntemplate <typename R1, typename R2>\nlong long edit_distance(const\
    \ R1& s, const R2& t) {\n    auto a = std::begin(s);\n    auto b = std::begin(t);\n\
    \    long long n = std::end(s) - a, m = std::end(t) - b;\n    // dp[j] \u306F\
    \ s[0, i) \u3068 t[0, j) \u306E\u7DE8\u96C6\u8DDD\u96E2\n    std::vector<long\
    \ long> dp(m + 1);\n    for (long long j = 0; j <= m; j++) dp[j] = j;\n    for\
    \ (long long i = 1; i <= n; i++) {\n        long long diag = dp[0];  // s[0, i\
    \ - 1) \u3068 t[0, j - 1) \u306E\u7DE8\u96C6\u8DDD\u96E2\n        dp[0] = i;\n\
    \        for (long long j = 1; j <= m; j++) {\n            long long up = dp[j];\n\
    \            dp[j] = std::min({dp[j] + 1, dp[j - 1] + 1, diag + (a[i - 1] == b[j\
    \ - 1] ? 0 : 1)});\n            diag = up;\n        }\n    }\n    return dp[m];\n\
    }\n\n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001s \u3092 t \u306B\u5909\
    \u3048\u308B\u64CD\u4F5C\u5217\n */\nstruct EditDistance {\n    enum class Type\
    \ { Insert,\n                      Erase,\n                      Replace };\n\
    \    struct Operation {\n        Type type;\n        long long source_index; \
    \ //!< \u5143\u306E s \u306E\u6DFB\u5B57\u3002\u633F\u5165\u3067\u306F\u9699\u9593\
    \u306E\u4F4D\u7F6E [0, |s|]\n        long long target_index;  //!< t \u306E\u6DFB\
    \u5B57\u3002\u524A\u9664\u3067\u306F\u9699\u9593\u306E\u4F4D\u7F6E [0, |t|]\n\
    \    };\n    long long distance;\n    std::vector<Operation> operations;\n};\n\
    \n/**\n * @brief \u7DE8\u96C6\u8DDD\u96E2\u3068\u3001\u305D\u306E\u6700\u5C0F\u56DE\
    \u6570\u306E\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\u63DB\u3092\u6C42\u3081\
    \u308B\n * \u6642\u9593\u30FB\u30E1\u30E2\u30EA O(nm)\u3002\u4E00\u81F4\u3059\u308B\
    \u8981\u7D20\u3092\u901A\u904E\u3059\u308B\u64CD\u4F5C\u306F\u542B\u3081\u306A\
    \u3044\u3002\n * \u64CD\u4F5C\u9806\u306B\u3001\u5909\u66F4\u4E2D\u306E\u5217\u306E\
    \ target_index \u306E\u4F4D\u7F6E\u3078\u633F\u5165\u30FB\u524A\u9664\u30FB\u7F6E\
    \u63DB\u3059\u308B\u3002\n * \u633F\u5165\u30FB\u7F6E\u63DB\u3059\u308B\u5024\u306F\
    \ t[target_index]\u3002\n */\ntemplate <typename R1, typename R2>\nEditDistance\
    \ edit_distance_restore(const R1& s, const R2& t) {\n    auto a = std::begin(s);\n\
    \    auto b = std::begin(t);\n    const long long n = std::end(s) - a, m = std::end(t)\
    \ - b;\n    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(m\
    \ + 1));\n    for (long long i = 0; i <= n; ++i) dp[i][0] = i;\n    for (long\
    \ long j = 0; j <= m; ++j) dp[0][j] = j;\n    for (long long i = 1; i <= n; ++i)\
    \ {\n        for (long long j = 1; j <= m; ++j) {\n            dp[i][j] = std::min({dp[i\
    \ - 1][j] + 1, dp[i][j - 1] + 1,\n                                 dp[i - 1][j\
    \ - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)});\n        }\n    }\n    EditDistance\
    \ result{dp[n][m], {}};\n    result.operations.reserve(result.distance);\n   \
    \ long long i = n, j = m;\n    while (i > 0 || j > 0) {\n        if (i > 0 &&\
    \ j > 0 && dp[i][j] == dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 0 : 1)) {\n\
    \            if (!(a[i - 1] == b[j - 1])) result.operations.push_back({EditDistance::Type::Replace,\
    \ i - 1, j - 1});\n            --i, --j;\n        } else if (i > 0 && dp[i][j]\
    \ == dp[i - 1][j] + 1) {\n            result.operations.push_back({EditDistance::Type::Erase,\
    \ i - 1, j});\n            --i;\n        } else {\n            assert(j > 0);\n\
    \            result.operations.push_back({EditDistance::Type::Insert, i, j - 1});\n\
    \            --j;\n        }\n    }\n    std::reverse(result.operations.begin(),\
    \ result.operations.end());\n    return result;\n}\n#line 7 \"test/aoj/dpl/dpl-1-e.test.cpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout\
    \ << edit_distance(s, t) << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../../src/dp/edit-distance.hpp\"\
    \n\nint main() {\n    std::string s, t;\n    std::cin >> s >> t;\n    std::cout\
    \ << edit_distance(s, t) << std::endl;\n}\n"
  dependsOn:
  - src/dp/edit-distance.hpp
  isVerificationFile: true
  path: test/aoj/dpl/dpl-1-e.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 23:25:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dpl/dpl-1-e.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dpl/dpl-1-e.test.cpp
- /verify/test/aoj/dpl/dpl-1-e.test.cpp.html
title: test/aoj/dpl/dpl-1-e.test.cpp
---
