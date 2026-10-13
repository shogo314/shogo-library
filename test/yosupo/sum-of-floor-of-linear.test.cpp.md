---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/floor-sum.hpp
    title: "floor sum (\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\u6570\u306E\u548C\
      )"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum-of-floor-of-linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#include <iostream>\n\
    \n#line 2 \"src/math/floor-sum.hpp\"\n\n/**\n * @file floor-sum.hpp\n * @brief\
    \ floor sum (\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\u6570\u306E\u548C)\n */\n\
    \n#include <cassert>\n#include <utility>\n\nnamespace internal_floor_sum {\n//\
    \ a, b, m, n \u304C\u3059\u3079\u3066\u975E\u8CA0\u306E\u3068\u304D\u3002\u9014\
    \u4E2D\u306E\u5024\u306F 2^64 \u3067\u5272\u3063\u305F\u4F59\u308A\u3067\u8A08\
    \u7B97\u3059\u308B\ninline unsigned long long floor_sum_unsigned(unsigned long\
    \ long n, unsigned long long m, unsigned long long a,\n                      \
    \                       unsigned long long b) {\n    unsigned long long res =\
    \ 0;\n    while (true) {\n        if (a >= m) {\n            res += n * (n - 1)\
    \ / 2 * (a / m);\n            a %= m;\n        }\n        if (b >= m) {\n    \
    \        res += n * (b / m);\n            b %= m;\n        }\n        unsigned\
    \ long long y_max = a * n + b;\n        if (y_max < m) break;\n        // y =\
    \ (a x + b) / m \u306E\u683C\u5B50\u70B9\u3092\u3001x \u3068 y \u3092\u5165\u308C\
    \u66FF\u3048\u3066\u6570\u3048\u76F4\u3059\n        n = y_max / m;\n        b\
    \ = y_max % m;\n        std::swap(m, a);\n    }\n    return res;\n}\n}  // namespace\
    \ internal_floor_sum\n\n/**\n * @brief sum_{i=0}^{n-1} floor((a i + b) / m) \u3092\
    \u8FD4\u3059 O(log m)\n *\n * a, b \u306F\u8CA0\u3067\u3082\u3088\u3044\u3002\u7B54\
    \u3048\u3068\u9014\u4E2D\u306E\u5024 (a, b \u3092 [0, m) \u306B\u76F4\u3057\u305F\
    \u5F8C\u306E a n + b \u306A\u3069) \u304C long long \u306B\u53CE\u307E\u308B\u3053\
    \u3068\n * @param n 0 \u4EE5\u4E0A\n * @param m 1 \u4EE5\u4E0A\n */\ninline long\
    \ long floor_sum(long long n, long long m, long long a, long long b) {\n    assert(0\
    \ <= n && 1 <= m);\n    unsigned long long res = 0;\n    if (a < 0) {\n      \
    \  long long a2 = a % m + m;\n        res -= (unsigned long long)n * (n - 1) /\
    \ 2 * ((a2 - a) / m);\n        a = a2;\n    }\n    if (b < 0) {\n        long\
    \ long b2 = b % m + m;\n        res -= (unsigned long long)n * ((b2 - b) / m);\n\
    \        b = b2;\n    }\n    return res + internal_floor_sum::floor_sum_unsigned(n,\
    \ m, a, b);\n}\n#line 6 \"test/yosupo/sum-of-floor-of-linear.test.cpp\"\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        long long n, m, a,\
    \ b;\n        std::cin >> n >> m >> a >> b;\n        std::cout << floor_sum(n,\
    \ m, a, b) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include <iostream>\n\n#include \"../../src/math/floor-sum.hpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int\
    \ t;\n    std::cin >> t;\n    while (t--) {\n        long long n, m, a, b;\n \
    \       std::cin >> n >> m >> a >> b;\n        std::cout << floor_sum(n, m, a,\
    \ b) << '\\n';\n    }\n}\n"
  dependsOn:
  - src/math/floor-sum.hpp
  isVerificationFile: true
  path: test/yosupo/sum-of-floor-of-linear.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 00:37:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum-of-floor-of-linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum-of-floor-of-linear.test.cpp
- /verify/test/yosupo/sum-of-floor-of-linear.test.cpp.html
title: test/yosupo/sum-of-floor-of-linear.test.cpp
---
