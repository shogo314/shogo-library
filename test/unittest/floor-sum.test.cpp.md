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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/floor-sum.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// floor_sum \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/math/floor-sum.hpp\"\n\n/**\n * @file\
    \ floor-sum.hpp\n * @brief floor sum (\u4E00\u6B21\u95A2\u6570\u306E\u5E8A\u95A2\
    \u6570\u306E\u548C)\n */\n\n#include <cassert>\n#include <utility>\n\nnamespace\
    \ internal_floor_sum {\n// a, b, m, n \u304C\u3059\u3079\u3066\u975E\u8CA0\u306E\
    \u3068\u304D\u3002\u9014\u4E2D\u306E\u5024\u306F 2^64 \u3067\u5272\u3063\u305F\
    \u4F59\u308A\u3067\u8A08\u7B97\u3059\u308B\ninline unsigned long long floor_sum_unsigned(unsigned\
    \ long long n, unsigned long long m, unsigned long long a,\n                 \
    \                            unsigned long long b) {\n    unsigned long long res\
    \ = 0;\n    while (true) {\n        if (a >= m) {\n            res += n * (n -\
    \ 1) / 2 * (a / m);\n            a %= m;\n        }\n        if (b >= m) {\n \
    \           res += n * (b / m);\n            b %= m;\n        }\n        unsigned\
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
    \  long long a2 = a % m + m;\n        res -= static_cast<unsigned long long>(n)\
    \ * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n    if (b < 0) {\n\
    \        long long b2 = b % m + m;\n        res -= static_cast<unsigned long long>(n)\
    \ * ((b2 - b) / m);\n        b = b2;\n    }\n    return res + internal_floor_sum::floor_sum_unsigned(n,\
    \ m, a, b);\n}\n#line 7 \"test/unittest/floor-sum.test.cpp\"\n\n#include <iostream>\n\
    #include <random>\n\nlong long floor_div(long long a, long long b) { return a\
    \ / b - ((a % b != 0) && ((a < 0) != (b < 0))); }\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 100000 && ok; rep++)\
    \ {\n        long long n = rng() % 30;\n        long long m = rng() % 30 + 1;\n\
    \        long long a = (long long)(rng() % 201) - 100;\n        long long b =\
    \ (long long)(rng() % 201) - 100;\n        long long expected = 0;\n        for\
    \ (long long i = 0; i < n; i++) expected += floor_div(a * i + b, m);\n       \
    \ ok = ok && floor_sum(n, m, a, b) == expected;\n    }\n    // \u5927\u304D\u3044\
    \u5024\n    ok = ok && floor_sum(1000000000, 1000000000, 999999999, 999999999)\
    \ == 499999999500000000LL;\n    ok = ok && floor_sum(0, 5, 3, 2) == 0;\n    ok\
    \ = ok && floor_sum(4, 10, 6, 3) == 3;\n\n    if (ok)\n        std::cout << \"\
    Hello World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// floor_sum \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/math/floor-sum.hpp\"\n\n#include\
    \ <iostream>\n#include <random>\n\nlong long floor_div(long long a, long long\
    \ b) { return a / b - ((a % b != 0) && ((a < 0) != (b < 0))); }\n\nint main()\
    \ {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep\
    \ < 100000 && ok; rep++) {\n        long long n = rng() % 30;\n        long long\
    \ m = rng() % 30 + 1;\n        long long a = (long long)(rng() % 201) - 100;\n\
    \        long long b = (long long)(rng() % 201) - 100;\n        long long expected\
    \ = 0;\n        for (long long i = 0; i < n; i++) expected += floor_div(a * i\
    \ + b, m);\n        ok = ok && floor_sum(n, m, a, b) == expected;\n    }\n   \
    \ // \u5927\u304D\u3044\u5024\n    ok = ok && floor_sum(1000000000, 1000000000,\
    \ 999999999, 999999999) == 499999999500000000LL;\n    ok = ok && floor_sum(0,\
    \ 5, 3, 2) == 0;\n    ok = ok && floor_sum(4, 10, 6, 3) == 3;\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/math/floor-sum.hpp
  isVerificationFile: true
  path: test/unittest/floor-sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/floor-sum.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/floor-sum.test.cpp
- /verify/test/unittest/floor-sum.test.cpp.html
title: test/unittest/floor-sum.test.cpp
---
