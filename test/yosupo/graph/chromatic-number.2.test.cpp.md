---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/set-cover.hpp
    title: "\u96C6\u5408\u306E\u88AB\u8986 (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
      \u3067\u8986\u3046\u6700\u5C0F\u500B\u6570\u3001\u5305\u9664\u539F\u7406)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/yosupo/graph/chromatic-number.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n// \u72EC\u7ACB\
    \u96C6\u5408\u3067\u9802\u70B9\u5168\u4F53\u3092\u8986\u3046\u6700\u5C0F\u500B\
    \u6570\u3068\u3057\u3066\u3001\u5305\u9664\u539F\u7406\u306E min_set_cover \u3067\
    \u6C42\u3081\u308B\n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/dp/set-cover.hpp\"\
    \n\n/**\n * @file set-cover.hpp\n * @brief \u96C6\u5408\u3092\u300C\u4F7F\u3063\
    \u3066\u3088\u3044\u96C6\u5408\u300D\u3067\u8986\u3046\u3068\u304D\u306E\u6700\
    \u5C0F\u500B\u6570 (\u5305\u9664\u539F\u7406\u3001\u8981\u7D20\u304C 20 \u500B\
    \u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#line 10 \"src/dp/set-cover.hpp\"\
    \n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true \u306E\u96C6\
    \u5408 T \u3044\u304F\u3064\u304B\u3067 (\u91CD\u306A\u308A\u3092\u8A31\u3057\u3066\
    ) \u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8986\u3048\u306A\u3051\
    \u308C\u3070 -1) O(2^n n)\n * feasible \u306E\u5927\u304D\u3055\u306F 2^n\u3002\
    f(S) \u3092 S \u306B\u542B\u307E\u308C\u308B\u4F7F\u3063\u3066\u3088\u3044\u96C6\
    \u5408\u306E\u6570\u3068\u3059\u308B\u3068\u3001\u5168\u4F53\u3092\u8986\u3046\
    \ k \u500B\u7D44\u306E\u6570\u306F \u03A3_S (-1)^{n - |S|} f(S)^k\u3002\n * \u3053\
    \u308C\u304C 0 \u3067\u306A\u3044\u6700\u5C0F\u306E k \u3092\u6C42\u3081\u308B\
    \u3002\u6570\u306F 2 \u3064\u306E\u7D20\u6570\u306E mod \u3067\u6570\u3048\u308B\
    \u306E\u3067\u30010 \u3067\u306A\u3044\u306E\u306B 0 \u3068\u8AA4\u308B\u78BA\u7387\
    \u304C\u308F\u305A\u304B\u306B\u3042\u308B\n */\ninline long long min_set_cover(int\
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
    \ -1;\n}\n#line 9 \"test/yosupo/graph/chromatic-number.2.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int\
    \ n, m;\n    std::cin >> n >> m;\n    std::vector<int> adj(n, 0);\n    for (int\
    \ i = 0; i < m; i++) {\n        int u, v;\n        std::cin >> u >> v;\n     \
    \   adj[u] |= 1 << v, adj[v] |= 1 << u;\n    }\n    // indep[S]: S \u304C\u72EC\
    \u7ACB\u96C6\u5408\u304B (\u6700\u5C0F\u306E\u9802\u70B9\u3092\u9664\u3044\u305F\
    \u96C6\u5408\u304C\u72EC\u7ACB\u3067\u3001\u6700\u5C0F\u306E\u9802\u70B9\u304C\
    \u305D\u308C\u3068\u96A3\u308A\u5408\u308F\u306A\u3044)\n    std::vector<bool>\
    \ indep(1 << n, false);\n    indep[0] = true;\n    for (int S = 1; S < (1 << n);\
    \ S++) {\n        const int v = __builtin_ctz(S), rest = S & (S - 1);\n      \
    \  indep[S] = indep[rest] && !(adj[v] & rest);\n    }\n    std::cout << min_set_cover(n,\
    \ indep) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    // \u72EC\u7ACB\u96C6\u5408\u3067\u9802\u70B9\u5168\u4F53\u3092\u8986\u3046\u6700\
    \u5C0F\u500B\u6570\u3068\u3057\u3066\u3001\u5305\u9664\u539F\u7406\u306E min_set_cover\
    \ \u3067\u6C42\u3081\u308B\n\n#include <iostream>\n#include <vector>\n\n#include\
    \ \"../../../src/dp/set-cover.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    std::vector<int> adj(n, 0);\n    for (int i = 0; i < m; i++) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        adj[u] |= 1 << v, adj[v] |= 1 <<\
    \ u;\n    }\n    // indep[S]: S \u304C\u72EC\u7ACB\u96C6\u5408\u304B (\u6700\u5C0F\
    \u306E\u9802\u70B9\u3092\u9664\u3044\u305F\u96C6\u5408\u304C\u72EC\u7ACB\u3067\
    \u3001\u6700\u5C0F\u306E\u9802\u70B9\u304C\u305D\u308C\u3068\u96A3\u308A\u5408\
    \u308F\u306A\u3044)\n    std::vector<bool> indep(1 << n, false);\n    indep[0]\
    \ = true;\n    for (int S = 1; S < (1 << n); S++) {\n        const int v = __builtin_ctz(S),\
    \ rest = S & (S - 1);\n        indep[S] = indep[rest] && !(adj[v] & rest);\n \
    \   }\n    std::cout << min_set_cover(n, indep) << '\\n';\n}\n"
  dependsOn:
  - src/dp/set-cover.hpp
  isVerificationFile: true
  path: test/yosupo/graph/chromatic-number.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 01:08:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/chromatic-number.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/chromatic-number.2.test.cpp
- /verify/test/yosupo/graph/chromatic-number.2.test.cpp.html
title: test/yosupo/graph/chromatic-number.2.test.cpp
---
