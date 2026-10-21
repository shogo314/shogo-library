---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/set-cover.hpp
    title: "\u96C6\u5408\u306E\u88AB\u8986 (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
      \u3067\u8986\u3046\u6700\u5C0F\u500B\u6570\u3001\u5305\u9664\u539F\u7406)"
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
  bundledCode: "#line 1 \"test/unittest/dp/set-cover.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// min_set_cover\
    \ \u3092\u3001\u8986\u3048\u308B\u96C6\u5408\u3092\u500B\u6570\u306E\u5C0F\u3055\
    \u3044\u9806\u306B\u5E83\u3052\u3066\u3044\u304F\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u6BD4\u3079\u308B\n// \u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u65CF\u304C\
    \u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\u9589\u3058\u3066\u3044\u308B\
    \u5834\u5408\u306F min_set_partition \u3068\u3082\u6BD4\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2\
    \ \"src/dp/set-cover.hpp\"\n\n/**\n * @file set-cover.hpp\n * @brief \u96C6\u5408\
    \u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\u3067\u8986\u3046\
    \u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5305\u9664\u539F\u7406\u3001\u8981\
    \u7D20\u304C 20 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true\
    \ \u306E\u96C6\u5408 T \u3044\u304F\u3064\u304B\u3067 (\u91CD\u306A\u308A\u3092\
    \u8A31\u3057\u3066) \u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8986\
    \u3048\u306A\u3051\u308C\u3070 -1) O(2^n n)\n * feasible \u306E\u5927\u304D\u3055\
    \u306F 2^n\u3002f(S) \u3092 S \u306B\u542B\u307E\u308C\u308B\u4F7F\u3063\u3066\
    \u3088\u3044\u96C6\u5408\u306E\u6570\u3068\u3059\u308B\u3068\u3001\u5168\u4F53\
    \u3092\u8986\u3046 k \u500B\u7D44\u306E\u6570\u306F \u03A3_S (-1)^{n - |S|} f(S)^k\u3002\
    \n * \u3053\u308C\u304C 0 \u3067\u306A\u3044\u6700\u5C0F\u306E k \u3092\u6C42\u3081\
    \u308B\u3002\u6570\u306F 2 \u3064\u306E\u7D20\u6570\u306E mod \u3067\u6570\u3048\
    \u308B\u306E\u3067\u30010 \u3067\u306A\u3044\u306E\u306B 0 \u3068\u8AA4\u308B\u78BA\
    \u7387\u304C\u308F\u305A\u304B\u306B\u3042\u308B\n */\ninline long long min_set_cover(int\
    \ n, const std::vector<bool>& feasible) {\n    assert(0 <= n && n < 31);\n   \
    \ assert(static_cast<long long>(feasible.size()) == (1LL << n));\n    if (n ==\
    \ 0) return 0;\n    const int N = 1 << n;\n    // f[S] = S \u306B\u542B\u307E\u308C\
    \u308B\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u6570 (\u90E8\u5206\u96C6\
    \u5408\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB)\u30022^n \u4EE5\
    \u4E0B\u306A\u306E\u3067 mod \u3092\u53D6\u3089\u305A\u306B\u6301\u3066\u308B\n\
    \    std::vector<unsigned> f(N);\n    for (int S = 0; S < N; S++) f[S] = feasible[S];\n\
    \    for (int i = 0; i < n; i++) {\n        for (int S = 0; S < N; S++) {\n  \
    \          if (S >> i & 1) f[S] += f[S ^ (1 << i)];\n        }\n    }\n    if\
    \ (f[N - 1] == 0) return -1;\n    static constexpr unsigned long long P[2] = {998244353,\
    \ 1000000007};\n    // pw[j][S] = f[S]^k mod P[j]\n    std::vector<unsigned> pw[2]\
    \ = {std::vector<unsigned>(N, 1), std::vector<unsigned>(N, 1)};\n    // \u8986\
    \u3048\u308B\u306A\u3089\u3001\u5404\u8981\u7D20\u3092\u542B\u3080\u96C6\u5408\
    \u3092 1 \u3064\u305A\u3064\u9078\u3079\u3070 n \u500B\u4EE5\u4E0B\u3067\u8986\
    \u3048\u308B\n    for (int k = 1; k <= n; k++) {\n        bool nonzero = false;\n\
    \        for (int j = 0; j < 2; j++) {\n            unsigned long long sum = 0;\n\
    \            for (int S = 0; S < N; S++) {\n                pw[j][S] = static_cast<unsigned>(pw[j][S]\
    \ * static_cast<unsigned long long>(f[S]) % P[j]);\n                // n - |S|\
    \ \u304C\u5947\u6570\u306A\u3089\u5F15\u304F\n                sum += (__builtin_parity(S)\
    \ ^ (n & 1)) ? P[j] - pw[j][S] : pw[j][S];\n            }\n            nonzero\
    \ |= sum % P[j] != 0;\n        }\n        if (nonzero) return k;\n    }\n    return\
    \ -1;\n}\n#line 8 \"test/unittest/dp/set-cover.test.cpp\"\n\n#include <iostream>\n\
    #include <random>\n#line 12 \"test/unittest/dp/set-cover.test.cpp\"\n\n#line 2\
    \ \"src/dp/set-partition.hpp\"\n\n/**\n * @file set-partition.hpp\n * @brief \u96C6\
    \u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\u306B\u5206\
    \u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8981\u7D20\u304C 16\
    \ \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#line 10 \"src/dp/set-partition.hpp\"\
    \n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true \u306E\u96C6\
    \u5408 T \u3044\u304F\u3064\u304B\u306B\u91CD\u306A\u3089\u306A\u3044\u3088\u3046\
    \u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5206\u3051\
    \u3089\u308C\u306A\u3051\u308C\u3070 -1) O(3^n)\n * feasible \u306E\u5927\u304D\
    \u3055\u306F 2^n\u3002dp[S] = min (dp[S \\ T] + 1) \u3092\u3001T \u3092\u300C\
    S \u306E\u6700\u5C0F\u306E\u8981\u7D20\u3092\u542B\u3080 S \u306E\u90E8\u5206\u96C6\
    \u5408\u300D\u306B\u9650\u3063\u3066\u6C42\u3081\u308B\n * \u4F7F\u3063\u3066\u3088\
    \u3044\u96C6\u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\
    \u9589\u3058\u3066\u3044\u308B\u306A\u3089\u3001\u91CD\u306A\u308A\u3092\u8A31\
    \u3057\u3066\u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\u3068\u3082\
    \u4E00\u81F4\u3059\u308B\n */\ninline long long min_set_partition(int n, const\
    \ std::vector<bool>& feasible) {\n    assert(static_cast<long long>(feasible.size())\
    \ == (1LL << n));\n    const int INF = n + 1;\n    std::vector<int> dp(1 << n,\
    \ INF);\n    dp[0] = 0;\n    for (int S = 1; S < (1 << n); S++) {\n        const\
    \ int low = S & -S, rest = S ^ low;\n        // rest \u306E\u90E8\u5206\u96C6\u5408\
    \ U \u306B\u3064\u3044\u3066 T = U | low \u3092\u8A66\u3059\n        for (int\
    \ U = rest;; U = (U - 1) & rest) {\n            const int T = U | low;\n     \
    \       if (feasible[T] && dp[S ^ T] + 1 < dp[S]) dp[S] = dp[S ^ T] + 1;\n   \
    \         if (U == 0) break;\n        }\n    }\n    return dp[(1 << n) - 1] >=\
    \ INF ? -1 : dp[(1 << n) - 1];\n}\n#line 14 \"test/unittest/dp/set-cover.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % (rep < 2000\
    \ ? 9 : 13);\n        const int N = 1 << n;\n        std::vector<bool> feasible(N);\n\
    \        // \u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u591A\u3055\u3092\
    \u5909\u3048\u308B (\u5C11\u306A\u3044\u3068\u8986\u3048\u306A\u3044\u3053\u3068\
    \u304C\u3042\u308B)\n        const int density = 1 + rng() % 20;\n        for\
    \ (int S = 0; S < N; S++) feasible[S] = static_cast<int>(rng() % 100) < density;\n\
    \        const bool closed = rep % 2 == 0;\n        if (closed) {\n          \
    \  for (int S = N - 1; S > 0; S--)\n                if (feasible[S])\n       \
    \             for (int T = S; T > 0; T = (T - 1) & S) feasible[T] = true;\n  \
    \      }\n        // \u611A\u76F4: k \u500B\u3067\u8986\u3048\u308B\u96C6\u5408\
    \ (\u306E\u548C\u96C6\u5408) \u306E\u5168\u4F53\u3092\u3001k \u3092 1 \u3064\u305A\
    \u3064\u5897\u3084\u3057\u3066\u5E83\u3052\u308B\n        long long expect = n\
    \ == 0 ? 0 : -1;\n        std::vector<bool> reach(N, false);\n        reach[0]\
    \ = true;\n        std::vector<int> sets;\n        for (int S = 0; S < N; S++)\n\
    \            if (feasible[S]) sets.push_back(S);\n        for (int k = 1; k <=\
    \ n && expect == -1; k++) {\n            std::vector<bool> next = reach;\n   \
    \         for (int U = 0; U < N; U++)\n                if (reach[U])\n       \
    \             for (int T : sets) next[U | T] = true;\n            reach = next;\n\
    \            if (reach[N - 1]) expect = k;\n        }\n        long long res =\
    \ min_set_cover(n, feasible);\n        if (res != expect) ok = false, std::cerr\
    \ << \"min_set_cover \" << rep << ' ' << res << ' ' << expect << std::endl;\n\
    \        if (closed && res != min_set_partition(n, feasible)) ok = false, std::cerr\
    \ << \"min_set_partition \u3068\u306E\u9055\u3044\" << std::endl;\n    }\n   \
    \ if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// min_set_cover \u3092\u3001\u8986\u3048\u308B\u96C6\u5408\u3092\u500B\u6570\
    \u306E\u5C0F\u3055\u3044\u9806\u306B\u5E83\u3052\u3066\u3044\u304F\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n// \u4F7F\u3063\u3066\u3088\u3044\u96C6\
    \u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\u9589\u3058\
    \u3066\u3044\u308B\u5834\u5408\u306F min_set_partition \u3068\u3082\u6BD4\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/dp/set-cover.hpp\"\n\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#include \"../../../src/dp/set-partition.hpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % (rep < 2000\
    \ ? 9 : 13);\n        const int N = 1 << n;\n        std::vector<bool> feasible(N);\n\
    \        // \u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u591A\u3055\u3092\
    \u5909\u3048\u308B (\u5C11\u306A\u3044\u3068\u8986\u3048\u306A\u3044\u3053\u3068\
    \u304C\u3042\u308B)\n        const int density = 1 + rng() % 20;\n        for\
    \ (int S = 0; S < N; S++) feasible[S] = static_cast<int>(rng() % 100) < density;\n\
    \        const bool closed = rep % 2 == 0;\n        if (closed) {\n          \
    \  for (int S = N - 1; S > 0; S--)\n                if (feasible[S])\n       \
    \             for (int T = S; T > 0; T = (T - 1) & S) feasible[T] = true;\n  \
    \      }\n        // \u611A\u76F4: k \u500B\u3067\u8986\u3048\u308B\u96C6\u5408\
    \ (\u306E\u548C\u96C6\u5408) \u306E\u5168\u4F53\u3092\u3001k \u3092 1 \u3064\u305A\
    \u3064\u5897\u3084\u3057\u3066\u5E83\u3052\u308B\n        long long expect = n\
    \ == 0 ? 0 : -1;\n        std::vector<bool> reach(N, false);\n        reach[0]\
    \ = true;\n        std::vector<int> sets;\n        for (int S = 0; S < N; S++)\n\
    \            if (feasible[S]) sets.push_back(S);\n        for (int k = 1; k <=\
    \ n && expect == -1; k++) {\n            std::vector<bool> next = reach;\n   \
    \         for (int U = 0; U < N; U++)\n                if (reach[U])\n       \
    \             for (int T : sets) next[U | T] = true;\n            reach = next;\n\
    \            if (reach[N - 1]) expect = k;\n        }\n        long long res =\
    \ min_set_cover(n, feasible);\n        if (res != expect) ok = false, std::cerr\
    \ << \"min_set_cover \" << rep << ' ' << res << ' ' << expect << std::endl;\n\
    \        if (closed && res != min_set_partition(n, feasible)) ok = false, std::cerr\
    \ << \"min_set_partition \u3068\u306E\u9055\u3044\" << std::endl;\n    }\n   \
    \ if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/set-cover.hpp
  - src/dp/set-partition.hpp
  isVerificationFile: true
  path: test/unittest/dp/set-cover.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 01:08:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/dp/set-cover.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dp/set-cover.test.cpp
- /verify/test/unittest/dp/set-cover.test.cpp.html
title: test/unittest/dp/set-cover.test.cpp
---
