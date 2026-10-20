---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/set-partition.hpp
    title: "\u96C6\u5408\u306E\u5206\u5272 (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
      \u306B\u5206\u3051\u308B\u6700\u5C0F\u500B\u6570)"
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
  bundledCode: "#line 1 \"test/unittest/set-partition.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ min_set_partition \u3092\u3001\u96C6\u5408\u306E\u5206\u3051\u65B9\u3092\u3059\
    \u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\
    \n// \u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\
    \u306B\u3064\u3044\u3066\u9589\u3058\u3066\u3044\u308B\u5834\u5408\u3068\u3001\
    \u9589\u3058\u3066\u3044\u306A\u3044\u5834\u5408\u306E\u4E21\u65B9\u3092\u8A66\
    \u3059\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/dp/set-partition.hpp\"\n\n/**\n * @file set-partition.hpp\n\
    \ * @brief \u96C6\u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\
    \u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8981\u7D20\
    \u304C 16 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true\
    \ \u306E\u96C6\u5408 T \u3044\u304F\u3064\u304B\u306B\u91CD\u306A\u3089\u306A\u3044\
    \u3088\u3046\u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\
    \ (\u5206\u3051\u3089\u308C\u306A\u3051\u308C\u3070 -1) O(3^n)\n * feasible \u306E\
    \u5927\u304D\u3055\u306F 2^n\u3002dp[S] = min (dp[S \\ T] + 1) \u3092\u3001T \u3092\
    \u300CS \u306E\u6700\u5C0F\u306E\u8981\u7D20\u3092\u542B\u3080 S \u306E\u90E8\u5206\
    \u96C6\u5408\u300D\u306B\u9650\u3063\u3066\u6C42\u3081\u308B\n * \u4F7F\u3063\u3066\
    \u3088\u3044\u96C6\u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\
    \u3066\u9589\u3058\u3066\u3044\u308B\u306A\u3089\u3001\u91CD\u306A\u308A\u3092\
    \u8A31\u3057\u3066\u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\u3068\
    \u3082\u4E00\u81F4\u3059\u308B\n */\ninline long long min_set_partition(int n,\
    \ const std::vector<bool>& feasible) {\n    assert(static_cast<long long>(feasible.size())\
    \ == (1LL << n));\n    const int INF = n + 1;\n    std::vector<int> dp(1 << n,\
    \ INF);\n    dp[0] = 0;\n    for (int S = 1; S < (1 << n); S++) {\n        const\
    \ int low = S & -S, rest = S ^ low;\n        // rest \u306E\u90E8\u5206\u96C6\u5408\
    \ U \u306B\u3064\u3044\u3066 T = U | low \u3092\u8A66\u3059\n        for (int\
    \ U = rest;; U = (U - 1) & rest) {\n            const int T = U | low;\n     \
    \       if (feasible[T] && dp[S ^ T] + 1 < dp[S]) dp[S] = dp[S ^ T] + 1;\n   \
    \         if (U == 0) break;\n        }\n    }\n    return dp[(1 << n) - 1] >=\
    \ INF ? -1 : dp[(1 << n) - 1];\n}\n#line 8 \"test/unittest/set-partition.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#line 12 \"test/unittest/set-partition.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 8;\n     \
    \   std::vector<bool> feasible(1 << n);\n        for (int S = 1; S < (1 << n);\
    \ S++) feasible[S] = rng() % 3 == 0;\n        if (rep % 2 == 0) {\n          \
    \  // \u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\u9589\u3058\u3055\u305B\
    \u308B (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u90E8\u5206\u96C6\u5408\
    \u3082\u4F7F\u3063\u3066\u3088\u3044)\n            for (int S = (1 << n) - 1;\
    \ S > 0; S--)\n                if (feasible[S])\n                    for (int\
    \ T = S; T > 0; T = (T - 1) & S) feasible[T] = true;\n        }\n        // \u611A\
    \u76F4: \u8981\u7D20 i \u306B\u300C\u4F55\u756A\u76EE\u306E\u96C6\u5408\u304B\u300D\
    \u3092\u5272\u308A\u5F53\u3066\u308B\u5206\u3051\u65B9\u3092\u3059\u3079\u3066\
    \u8A66\u3059\n        long long expect = n == 0 ? 0 : -1;\n        std::vector<int>\
    \ b(n, 0);\n        while (n > 0) {\n            int k = 0;\n            for (int\
    \ x : b) k = std::max(k, x + 1);\n            std::vector<int> parts(k, 0);\n\
    \            for (int i = 0; i < n; i++) parts[b[i]] |= 1 << i;\n            bool\
    \ good = true;\n            for (int p : parts) good &= p != 0 && feasible[p];\n\
    \            if (good && (expect == -1 || k < expect)) expect = k;\n         \
    \   int i = 0;\n            while (i < n && ++b[i] == n) b[i++] = 0;\n       \
    \     if (i == n) break;\n        }\n        if (min_set_partition(n, feasible)\
    \ != expect) ok = false, std::cerr << \"min_set_partition\" << std::endl;\n  \
    \  }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// min_set_partition \u3092\u3001\u96C6\u5408\u306E\u5206\u3051\u65B9\u3092\
    \u3059\u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\
    \u308B\n// \u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u65CF\u304C\u90E8\u5206\u96C6\
    \u5408\u306B\u3064\u3044\u3066\u9589\u3058\u3066\u3044\u308B\u5834\u5408\u3068\
    \u3001\u9589\u3058\u3066\u3044\u306A\u3044\u5834\u5408\u306E\u4E21\u65B9\u3092\
    \u8A66\u3059\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\
    \u308B\n\n#include \"../../src/dp/set-partition.hpp\"\n\n#include <iostream>\n\
    #include <random>\n#include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n     \
    \   int n = rng() % 8;\n        std::vector<bool> feasible(1 << n);\n        for\
    \ (int S = 1; S < (1 << n); S++) feasible[S] = rng() % 3 == 0;\n        if (rep\
    \ % 2 == 0) {\n            // \u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\
    \u9589\u3058\u3055\u305B\u308B (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\
    \u90E8\u5206\u96C6\u5408\u3082\u4F7F\u3063\u3066\u3088\u3044)\n            for\
    \ (int S = (1 << n) - 1; S > 0; S--)\n                if (feasible[S])\n     \
    \               for (int T = S; T > 0; T = (T - 1) & S) feasible[T] = true;\n\
    \        }\n        // \u611A\u76F4: \u8981\u7D20 i \u306B\u300C\u4F55\u756A\u76EE\
    \u306E\u96C6\u5408\u304B\u300D\u3092\u5272\u308A\u5F53\u3066\u308B\u5206\u3051\
    \u65B9\u3092\u3059\u3079\u3066\u8A66\u3059\n        long long expect = n == 0\
    \ ? 0 : -1;\n        std::vector<int> b(n, 0);\n        while (n > 0) {\n    \
    \        int k = 0;\n            for (int x : b) k = std::max(k, x + 1);\n   \
    \         std::vector<int> parts(k, 0);\n            for (int i = 0; i < n; i++)\
    \ parts[b[i]] |= 1 << i;\n            bool good = true;\n            for (int\
    \ p : parts) good &= p != 0 && feasible[p];\n            if (good && (expect ==\
    \ -1 || k < expect)) expect = k;\n            int i = 0;\n            while (i\
    \ < n && ++b[i] == n) b[i++] = 0;\n            if (i == n) break;\n        }\n\
    \        if (min_set_partition(n, feasible) != expect) ok = false, std::cerr <<\
    \ \"min_set_partition\" << std::endl;\n    }\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/set-partition.hpp
  isVerificationFile: true
  path: test/unittest/set-partition.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 05:55:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/set-partition.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/set-partition.test.cpp
- /verify/test/unittest/set-partition.test.cpp.html
title: test/unittest/set-partition.test.cpp
---
