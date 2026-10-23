---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/hungarian.hpp
    title: "\u5272\u5F53\u554F\u984C (\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5)"
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
  bundledCode: "#line 1 \"test/unittest/graph/hungarian.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ hungarian.hpp \u306E hungarian \u3092\u3001\u5217\u306E\u9078\u3073\u65B9\u306E\
    \u5168\u63A2\u7D22\u3068\u6BD4\u3079\u308B\n// \u8CA0\u306E\u30B3\u30B9\u30C8\u3068\
    \u3001\u884C\u3088\u308A\u5217\u304C\u591A\u3044\u9577\u65B9\u5F62\u306E\u884C\
    \u5217\u3092\u542B\u3081\u3066\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/hungarian.hpp\"\
    \n\n/**\n * @file hungarian.hpp\n * @brief \u5272\u5F53\u554F\u984C (\u30CF\u30F3\
    \u30AC\u30EA\u30A2\u30F3\u6CD5)\n */\n\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n\n/**\n * @brief hungarian \u306E\u623B\u308A\u5024\n */\n\
    template <typename T>\nstruct Assignment {\n    T cost;                      \
    \  //!< \u30B3\u30B9\u30C8\u306E\u7DCF\u548C\n    std::vector<long long> match;\
    \  //!< match[i]: \u884C i \u306B\u5272\u308A\u5F53\u3066\u305F\u5217\n};\n\n\
    /**\n * @brief n \xD7 m (n <= m) \u306E\u30B3\u30B9\u30C8\u884C\u5217 a \u3067\
    \u3001\u5404\u884C\u306B\u7570\u306A\u308B\u5217\u3092 1 \u3064\u305A\u3064\u5272\
    \u308A\u5F53\u3066\u308B\u3068\u304D\u306E\u30B3\u30B9\u30C8\u306E\u7DCF\u548C\
    \u306E\u6700\u5C0F\u5024 O(n^2 m)\n *\n * \u6700\u5927\u5316\u3057\u305F\u3044\
    \u3068\u304D\u306F\u3001\u7B26\u53F7\u3092\u53CD\u8EE2\u3057\u305F\u30B3\u30B9\
    \u30C8\u3067\u547C\u3076\n * @param a \u30B3\u30B9\u30C8\u884C\u5217 (\u8CA0\u3067\
    \u3082\u3088\u3044)\u3002\u884C\u306E\u9577\u3055\u306F\u305D\u308D\u3063\u3066\
    \u3044\u308B\u3053\u3068\n */\ntemplate <typename T>\nAssignment<T> hungarian(const\
    \ std::vector<std::vector<T>>& a) {\n    const long long n = a.size();\n    if\
    \ (n == 0) return {T{}, {}};\n    const long long m = a[0].size();\n    assert(n\
    \ <= m);\n    for (const auto& row : a) assert(static_cast<long long>(row.size())\
    \ == m);\n    const T inf = std::numeric_limits<T>::max() / 4;\n    // 1 \u59CB\
    \u307E\u308A\u3067\u6271\u3044\u3001\u5217 0 \u3092\u300C\u307E\u3060\u5272\u308A\
    \u5F53\u3066\u3066\u3044\u306A\u3044\u884C\u300D\u306E\u7F6E\u304D\u5834\u306B\
    \u3059\u308B\n    // u\u30FBv \u306F\u884C\u3068\u5217\u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3001p[j] \u306F\u5217 j \u306B\u5272\u308A\u5F53\u3066\u305F\
    \u884C\u3001way[j] \u306F\u5897\u52A0\u8DEF\u3067\u5217 j \u306E 1 \u3064\u524D\
    \u306E\u5217\n    std::vector<T> u(n + 1), v(m + 1);\n    std::vector<long long>\
    \ p(m + 1), way(m + 1);\n    for (long long i = 1; i <= n; i++) {\n        p[0]\
    \ = i;\n        long long j0 = 0;\n        std::vector<T> minv(m + 1, inf);\n\
    \        std::vector<bool> used(m + 1, false);\n        // \u884C i \u304B\u3089\
    \u3001\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\u3044\u5217\u306B\
    \u7740\u304F\u307E\u3067\u3001\u88AB\u7D04\u30B3\u30B9\u30C8\u304C\u6700\u5C0F\
    \u306E\u5217\u3092 1 \u3064\u305A\u3064\u8DB3\u3057\u3066\u3044\u304F\n      \
    \  do {\n            used[j0] = true;\n            const long long i0 = p[j0];\n\
    \            T delta = inf;\n            long long j1 = 0;\n            for (long\
    \ long j = 1; j <= m; j++) {\n                if (used[j]) continue;\n       \
    \         T cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n                if (cur <\
    \ minv[j]) minv[j] = cur, way[j] = j0;\n                if (minv[j] < delta) delta\
    \ = minv[j], j1 = j;\n            }\n            for (long long j = 0; j <= m;\
    \ j++) {\n                if (used[j]) {\n                    u[p[j]] += delta;\n\
    \                    v[j] -= delta;\n                } else {\n              \
    \      minv[j] -= delta;\n                }\n            }\n            j0 = j1;\n\
    \        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u306B\u6CBF\u3063\
    \u3066\u5272\u308A\u5F53\u3066\u3092\u5165\u308C\u66FF\u3048\u308B\n        do\
    \ {\n            long long j1 = way[j0];\n            p[j0] = p[j1];\n       \
    \     j0 = j1;\n        } while (j0 != 0);\n    }\n    Assignment<T> res{T{},\
    \ std::vector<long long>(n, -1)};\n    for (long long j = 1; j <= m; j++) {\n\
    \        if (p[j] != 0) res.match[p[j] - 1] = j - 1;\n    }\n    for (long long\
    \ i = 0; i < n; i++) res.cost += a[i][res.match[i]];\n    return res;\n}\n#line\
    \ 8 \"test/unittest/graph/hungarian.test.cpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#line 12 \"test/unittest/graph/hungarian.test.cpp\"\n#include <numeric>\n\
    #include <random>\n#line 15 \"test/unittest/graph/hungarian.test.cpp\"\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int rep\
    \ = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 6, m = n + rng() %\
    \ 3;\n        if (m == 0) m = 1;\n        std::vector<std::vector<long long>>\
    \ a(n, std::vector<long long>(m));\n        for (auto& row : a)\n            for\
    \ (auto& x : row) x = static_cast<long long>(rng() % 21) - 10;\n        // m \u500B\
    \u306E\u5217\u304B\u3089\u4E26\u3079\u66FF\u3048\u3067\u5148\u982D n \u500B\u3092\
    \u9078\u3076\n        std::vector<int> perm(m);\n        std::iota(perm.begin(),\
    \ perm.end(), 0);\n        long long best = std::numeric_limits<long long>::max();\n\
    \        do {\n            long long s = 0;\n            for (int i = 0; i < n;\
    \ i++) s += a[i][perm[i]];\n            best = std::min(best, s);\n        } while\
    \ (std::next_permutation(perm.begin(), perm.end()));\n        if (n == 0) best\
    \ = 0;\n        auto res = hungarian(a);\n        if (res.cost != best) ok = false;\n\
    \        // match \u304C\u7570\u306A\u308B\u5217\u3067\u3001cost \u3068\u4E00\u81F4\
    \u3059\u308B\n        if (static_cast<int>(res.match.size()) != n) ok = false;\n\
    \        std::vector<bool> used(m, false);\n        long long s = 0;\n       \
    \ for (int i = 0; i < n && ok; i++) {\n            long long j = res.match[i];\n\
    \            if (j < 0 || j >= m || used[j]) {\n                ok = false;\n\
    \                break;\n            }\n            used[j] = true;\n        \
    \    s += a[i][j];\n        }\n        if (s != res.cost) ok = false;\n    }\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// hungarian.hpp \u306E hungarian \u3092\u3001\u5217\u306E\u9078\u3073\u65B9\
    \u306E\u5168\u63A2\u7D22\u3068\u6BD4\u3079\u308B\n// \u8CA0\u306E\u30B3\u30B9\u30C8\
    \u3068\u3001\u884C\u3088\u308A\u5217\u304C\u591A\u3044\u9577\u65B9\u5F62\u306E\
    \u884C\u5217\u3092\u542B\u3081\u3066\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/hungarian.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include <numeric>\n\
    #include <random>\n#include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 6, m = n + rng() % 3;\n        if (m == 0) m = 1;\n      \
    \  std::vector<std::vector<long long>> a(n, std::vector<long long>(m));\n    \
    \    for (auto& row : a)\n            for (auto& x : row) x = static_cast<long\
    \ long>(rng() % 21) - 10;\n        // m \u500B\u306E\u5217\u304B\u3089\u4E26\u3079\
    \u66FF\u3048\u3067\u5148\u982D n \u500B\u3092\u9078\u3076\n        std::vector<int>\
    \ perm(m);\n        std::iota(perm.begin(), perm.end(), 0);\n        long long\
    \ best = std::numeric_limits<long long>::max();\n        do {\n            long\
    \ long s = 0;\n            for (int i = 0; i < n; i++) s += a[i][perm[i]];\n \
    \           best = std::min(best, s);\n        } while (std::next_permutation(perm.begin(),\
    \ perm.end()));\n        if (n == 0) best = 0;\n        auto res = hungarian(a);\n\
    \        if (res.cost != best) ok = false;\n        // match \u304C\u7570\u306A\
    \u308B\u5217\u3067\u3001cost \u3068\u4E00\u81F4\u3059\u308B\n        if (static_cast<int>(res.match.size())\
    \ != n) ok = false;\n        std::vector<bool> used(m, false);\n        long long\
    \ s = 0;\n        for (int i = 0; i < n && ok; i++) {\n            long long j\
    \ = res.match[i];\n            if (j < 0 || j >= m || used[j]) {\n           \
    \     ok = false;\n                break;\n            }\n            used[j]\
    \ = true;\n            s += a[i][j];\n        }\n        if (s != res.cost) ok\
    \ = false;\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/hungarian.hpp
  isVerificationFile: true
  path: test/unittest/graph/hungarian.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 13:33:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/hungarian.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/hungarian.test.cpp
- /verify/test/unittest/graph/hungarian.test.cpp.html
title: test/unittest/graph/hungarian.test.cpp
---
