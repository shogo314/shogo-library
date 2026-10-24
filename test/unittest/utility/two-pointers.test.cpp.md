---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/two-pointers.hpp
    title: "\u5C3A\u53D6\u308A\u6CD5"
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
  bundledCode: "#line 1 \"test/unittest/utility/two-pointers.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ utility/two-pointers.hpp \u306E two_pointers \u3092\u3001l \u3054\u3068\u306B\
    \u53F3\u3078\u4F38\u3070\u3059\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\
    \u308B\n// \u548C\u304C k \u4EE5\u4E0B\u30FB\u7A2E\u985E\u6570\u304C k \u4EE5\u4E0B\
    \ (\u72B6\u614B\u3092\u6301\u3064)\u3001\u5DEE\u304C k \u4EE5\u4E0B (\u72B6\u614B\
    \u3092\u6301\u305F\u306A\u3044\u3001\u7A7A\u306E\u533A\u9593\u3092\u542B\u3080\
    )\u3001\u5186\u74B0\u306E 3 \u901A\u308A\u3092\u8ABF\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/two-pointers.hpp\"\
    \n\n/**\n * @file two-pointers.hpp\n * @brief \u5C3A\u53D6\u308A\u6CD5\n */\n\n\
    #include <vector>\n\n/**\n * @brief \u5C3A\u53D6\u308A\u6CD5\u3067\u3001\u5404\
    \ l \u306B\u3064\u3044\u3066\u533A\u9593 [l, r) \u3092\u53F3\u306B\u4F38\u3070\
    \u305B\u308B\u3060\u3051\u4F38\u3070\u3057\u305F r \u3092\u6C42\u3081\u308B\n\
    \ *\n * can_add(l, r) \u306F\u3001\u3044\u307E\u306E\u533A\u9593 [l, r) \u306B\
    \ r \u3092\u52A0\u3048\u3066\u3082\u3088\u3044\u304B\u3092\u8FD4\u3059\u3002add(r)\
    \ \u306F r \u3092\u52A0\u3048\u305F\u3068\u304D\u3001erase(l) \u306F l \u3092\u53D6\
    \u308A\u9664\u3044\u305F\u3068\u304D\u306B\u547C\u3070\u308C\u308B\n * [l, r)\
    \ \u306B r \u3092\u52A0\u3048\u3066\u3088\u3044\u306A\u3089 [l + 1, r) \u306B\u3082\
    \u52A0\u3048\u3066\u3088\u3044 (\u533A\u9593\u3092\u5DE6\u304B\u3089\u7E2E\u3081\
    \u3066\u3082\u6761\u4EF6\u304C\u5D29\u308C\u306A\u3044) \u3053\u3068\n * can_add(l,\
    \ l) \u304C\u507D\u306A\u3089\u3001\u533A\u9593\u306F\u7A7A\u306E\u307E\u307E\
    \ r = l \u306B\u306A\u308B\u3002\u7A7A\u306E\u533A\u9593\u304B\u3089\u306F\u4F55\
    \u3082\u53D6\u308A\u9664\u304B\u306A\u3044\n *\n * \u5186\u74B0\u306E\u5217\u306F\
    \u30011 \u5468\u305A\u3089\u3057\u305F\u5199\u3057\u3092\u5F8C\u308D\u306B\u3064\
    \u306A\u3052\u305F\u9577\u3055 2n \u306E\u5217\u306B\u4F7F\u3044\u3001l < n \u306E\
    \u5206\u3092\u898B\u308B\n *\n * @param n \u5217\u306E\u9577\u3055\n * @return\
    \ \u9577\u3055 n \u306E\u5217\u3002l \u756A\u76EE\u306F [l, r) \u3092\u4F38\u3070\
    \u3057\u7D42\u3048\u305F\u3068\u304D\u306E r\n */\ntemplate <class CanAdd, class\
    \ Add, class Erase>\nstd::vector<long long> two_pointers(long long n, CanAdd can_add,\
    \ Add add, Erase erase) {\n    std::vector<long long> res(n);\n    long long r\
    \ = 0;\n    for (long long l = 0; l < n; l++) {\n        if (r < l) r = l;\n \
    \       while (r < n && can_add(l, r)) add(r++);\n        res[l] = r;\n      \
    \  if (l < r) erase(l);\n    }\n    return res;\n}\n\n/**\n * @brief \u72B6\u614B\
    \u3092\u6301\u305F\u306A\u3044\u5C3A\u53D6\u308A\u6CD5 (can_add(l, r) \u304C l\
    \ \u3068 r \u3060\u3051\u3067\u6C7A\u307E\u308B\u3068\u304D)\n */\ntemplate <class\
    \ CanAdd>\nstd::vector<long long> two_pointers(long long n, CanAdd can_add) {\n\
    \    return two_pointers(n, can_add, [](long long) {}, [](long long) {});\n}\n\
    #line 8 \"test/unittest/utility/two-pointers.test.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#include <set>\n#line 14 \"test/unittest/utility/two-pointers.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 12;\n    \
    \    std::vector<long long> a(n);\n        for (auto& x : a) x = rng() % 5;\n\
    \        long long k = static_cast<long long>(rng() % 12) - 2;\n\n        // \u548C\
    \u304C k \u4EE5\u4E0B\n        long long s = 0;\n        auto r1 = two_pointers(\n\
    \            n, [&](long long, long long r) { return s + a[r] <= k; }, [&](long\
    \ long r) { s += a[r]; }, [&](long long l) { s -= a[l]; });\n        // \u7A2E\
    \u985E\u6570\u304C k \u4EE5\u4E0B\n        std::vector<int> cnt(5);\n        long\
    \ long kinds = 0;\n        auto r2 = two_pointers(\n            n, [&](long long,\
    \ long long r) { return cnt[a[r]] > 0 || kinds < k; }, [&](long long r) { kinds\
    \ += cnt[a[r]]++ == 0; },\n            [&](long long l) { kinds -= --cnt[a[l]]\
    \ == 0; });\n        // \u30BD\u30FC\u30C8\u3057\u305F\u5217\u3067\u5DEE\u304C\
    \ k \u4EE5\u4E0B (k < 0 \u306A\u3089\u533A\u9593\u306F\u7A7A)\n        std::vector<long\
    \ long> b = a;\n        std::sort(b.begin(), b.end());\n        auto r3 = two_pointers(n,\
    \ [&](long long l, long long r) { return b[r] - b[l] <= k; });\n        ok = ok\
    \ && static_cast<int>(r1.size()) == n && static_cast<int>(r2.size()) == n && static_cast<int>(r3.size())\
    \ == n;\n        for (int l = 0; l < n && ok; l++) {\n            long long e1\
    \ = l, t = 0;\n            while (e1 < n && t + a[e1] <= k) t += a[e1++];\n  \
    \          long long e2 = l;\n            std::set<long long> st;\n          \
    \  while (e2 < n && (st.count(a[e2]) || static_cast<long long>(st.size()) < k))\
    \ st.insert(a[e2++]);\n            long long e3 = l;\n            while (e3 <\
    \ n && b[e3] - b[l] <= k) e3++;\n            ok = ok && r1[l] == e1 && r2[l] ==\
    \ e2 && r3[l] == e3;\n        }\n\n        // \u5186\u74B0: \u5468\u306E\u9577\
    \u3055 L \u306E\u5186\u5468\u4E0A\u306E\u76F8\u7570\u306A\u308B\u70B9\u306B\u3064\
    \u3044\u3066\u3001\u5404\u70B9\u304B\u3089\u6642\u8A08\u56DE\u308A\u306B\u5E45\
    \ w \u672A\u6E80\u306B\u3042\u308B\u70B9\u306E\u6570\n        long long L = 16,\
    \ w = rng() % 20;\n        std::vector<long long> c(L);\n        for (int i =\
    \ 0; i < L; i++) c[i] = i;\n        std::shuffle(c.begin(), c.end(), rng);\n \
    \       c.resize(n);\n        std::sort(c.begin(), c.end());\n        for (int\
    \ i = 0; i < n; i++) c.push_back(c[i] + L);  // 1 \u5468\u305A\u3089\u3057\u305F\
    \u5199\u3057\u3092\u3064\u306A\u3052\u308B\n        auto r4 = two_pointers(2 *\
    \ n, [&](long long l, long long r) { return c[r] - c[l] < std::min(w, L); });\n\
    \        for (int l = 0; l < n && ok; l++) {\n            long long e4 = 0;\n\
    \            for (int j = 0; j < n; j++) e4 += (c[j] - c[l] + L) % L < std::min(w,\
    \ L);\n            ok = ok && r4[l] - l == e4;\n        }\n    }\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// utility/two-pointers.hpp \u306E two_pointers \u3092\u3001l \u3054\u3068\
    \u306B\u53F3\u3078\u4F38\u3070\u3059\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\
    \u3079\u308B\n// \u548C\u304C k \u4EE5\u4E0B\u30FB\u7A2E\u985E\u6570\u304C k \u4EE5\
    \u4E0B (\u72B6\u614B\u3092\u6301\u3064)\u3001\u5DEE\u304C k \u4EE5\u4E0B (\u72B6\
    \u614B\u3092\u6301\u305F\u306A\u3044\u3001\u7A7A\u306E\u533A\u9593\u3092\u542B\
    \u3080)\u3001\u5186\u74B0\u306E 3 \u901A\u308A\u3092\u8ABF\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include\
    \ \"../../../src/utility/two-pointers.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <random>\n#include <set>\n#include <vector>\n\nint main()\
    \ {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int rep = 0;\
    \ rep < 2000 && ok; rep++) {\n        int n = rng() % 12;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = rng() % 5;\n        long long k =\
    \ static_cast<long long>(rng() % 12) - 2;\n\n        // \u548C\u304C k \u4EE5\u4E0B\
    \n        long long s = 0;\n        auto r1 = two_pointers(\n            n, [&](long\
    \ long, long long r) { return s + a[r] <= k; }, [&](long long r) { s += a[r];\
    \ }, [&](long long l) { s -= a[l]; });\n        // \u7A2E\u985E\u6570\u304C k\
    \ \u4EE5\u4E0B\n        std::vector<int> cnt(5);\n        long long kinds = 0;\n\
    \        auto r2 = two_pointers(\n            n, [&](long long, long long r) {\
    \ return cnt[a[r]] > 0 || kinds < k; }, [&](long long r) { kinds += cnt[a[r]]++\
    \ == 0; },\n            [&](long long l) { kinds -= --cnt[a[l]] == 0; });\n  \
    \      // \u30BD\u30FC\u30C8\u3057\u305F\u5217\u3067\u5DEE\u304C k \u4EE5\u4E0B\
    \ (k < 0 \u306A\u3089\u533A\u9593\u306F\u7A7A)\n        std::vector<long long>\
    \ b = a;\n        std::sort(b.begin(), b.end());\n        auto r3 = two_pointers(n,\
    \ [&](long long l, long long r) { return b[r] - b[l] <= k; });\n        ok = ok\
    \ && static_cast<int>(r1.size()) == n && static_cast<int>(r2.size()) == n && static_cast<int>(r3.size())\
    \ == n;\n        for (int l = 0; l < n && ok; l++) {\n            long long e1\
    \ = l, t = 0;\n            while (e1 < n && t + a[e1] <= k) t += a[e1++];\n  \
    \          long long e2 = l;\n            std::set<long long> st;\n          \
    \  while (e2 < n && (st.count(a[e2]) || static_cast<long long>(st.size()) < k))\
    \ st.insert(a[e2++]);\n            long long e3 = l;\n            while (e3 <\
    \ n && b[e3] - b[l] <= k) e3++;\n            ok = ok && r1[l] == e1 && r2[l] ==\
    \ e2 && r3[l] == e3;\n        }\n\n        // \u5186\u74B0: \u5468\u306E\u9577\
    \u3055 L \u306E\u5186\u5468\u4E0A\u306E\u76F8\u7570\u306A\u308B\u70B9\u306B\u3064\
    \u3044\u3066\u3001\u5404\u70B9\u304B\u3089\u6642\u8A08\u56DE\u308A\u306B\u5E45\
    \ w \u672A\u6E80\u306B\u3042\u308B\u70B9\u306E\u6570\n        long long L = 16,\
    \ w = rng() % 20;\n        std::vector<long long> c(L);\n        for (int i =\
    \ 0; i < L; i++) c[i] = i;\n        std::shuffle(c.begin(), c.end(), rng);\n \
    \       c.resize(n);\n        std::sort(c.begin(), c.end());\n        for (int\
    \ i = 0; i < n; i++) c.push_back(c[i] + L);  // 1 \u5468\u305A\u3089\u3057\u305F\
    \u5199\u3057\u3092\u3064\u306A\u3052\u308B\n        auto r4 = two_pointers(2 *\
    \ n, [&](long long l, long long r) { return c[r] - c[l] < std::min(w, L); });\n\
    \        for (int l = 0; l < n && ok; l++) {\n            long long e4 = 0;\n\
    \            for (int j = 0; j < n; j++) e4 += (c[j] - c[l] + L) % L < std::min(w,\
    \ L);\n            ok = ok && r4[l] - l == e4;\n        }\n    }\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/two-pointers.hpp
  isVerificationFile: true
  path: test/unittest/utility/two-pointers.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 23:17:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/utility/two-pointers.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/utility/two-pointers.test.cpp
- /verify/test/unittest/utility/two-pointers.test.cpp.html
title: test/unittest/utility/two-pointers.test.cpp
---
