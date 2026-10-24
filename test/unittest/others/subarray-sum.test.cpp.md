---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/others/subarray-sum.hpp
    title: "\u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\
      \u6570"
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
  bundledCode: "#line 1 \"test/unittest/others/subarray-sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ subarray-sum.hpp \u306E count_subarrays_with_sum\u30FBcount_subarrays_with_sum_at_most\
    \ \u3092\u3001\u3059\u3079\u3066\u306E\u533A\u9593\u306E\u548C\u3092\u8ABF\u3079\
    \u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u8981\u7D20\u304C\
    \u3059\u3079\u3066 0 \u4EE5\u4E0A\u306E\u5217 (\u5C3A\u53D6\u308A\u6CD5) \u3068\
    \u8CA0\u3092\u542B\u3080\u5217 (\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8) \u306E\u4E21\
    \u65B9\u3067\u3001k \u3082\u8CA0\u304B\u3089\u6B63\u307E\u3067\u8ABF\u3079\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/others/subarray-sum.hpp\"\n\n/**\n * @file subarray-sum.hpp\n *\
    \ @brief \u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\
    \u6570\n */\n\n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\
    \n#line 2 \"src/utility/two-pointers.hpp\"\n\n/**\n * @file two-pointers.hpp\n\
    \ * @brief \u5C3A\u53D6\u308A\u6CD5\n */\n\n#line 9 \"src/utility/two-pointers.hpp\"\
    \n\n/**\n * @brief \u5C3A\u53D6\u308A\u6CD5\u3067\u3001\u5404 l \u306B\u3064\u3044\
    \u3066\u533A\u9593 [l, r) \u3092\u53F3\u306B\u4F38\u3070\u305B\u308B\u3060\u3051\
    \u4F38\u3070\u3057\u305F r \u3092\u6C42\u3081\u308B\n *\n * can_add(l, r) \u306F\
    \u3001\u3044\u307E\u306E\u533A\u9593 [l, r) \u306B r \u3092\u52A0\u3048\u3066\u3082\
    \u3088\u3044\u304B\u3092\u8FD4\u3059\u3002add(r) \u306F r \u3092\u52A0\u3048\u305F\
    \u3068\u304D\u3001erase(l) \u306F l \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\
    \u304D\u306B\u547C\u3070\u308C\u308B\n * [l, r) \u306B r \u3092\u52A0\u3048\u3066\
    \u3088\u3044\u306A\u3089 [l + 1, r) \u306B\u3082\u52A0\u3048\u3066\u3088\u3044\
    \ (\u533A\u9593\u3092\u5DE6\u304B\u3089\u7E2E\u3081\u3066\u3082\u6761\u4EF6\u304C\
    \u5D29\u308C\u306A\u3044) \u3053\u3068\n * can_add(l, l) \u304C\u507D\u306A\u3089\
    \u3001\u533A\u9593\u306F\u7A7A\u306E\u307E\u307E r = l \u306B\u306A\u308B\u3002\
    \u7A7A\u306E\u533A\u9593\u304B\u3089\u306F\u4F55\u3082\u53D6\u308A\u9664\u304B\
    \u306A\u3044\n *\n * \u5186\u74B0\u306E\u5217\u306F\u30011 \u5468\u305A\u3089\u3057\
    \u305F\u5199\u3057\u3092\u5F8C\u308D\u306B\u3064\u306A\u3052\u305F\u9577\u3055\
    \ 2n \u306E\u5217\u306B\u4F7F\u3044\u3001l < n \u306E\u5206\u3092\u898B\u308B\n\
    \ *\n * @param n \u5217\u306E\u9577\u3055\n * @return \u9577\u3055 n \u306E\u5217\
    \u3002l \u756A\u76EE\u306F [l, r) \u3092\u4F38\u3070\u3057\u7D42\u3048\u305F\u3068\
    \u304D\u306E r\n */\ntemplate <class CanAdd, class Add, class Erase>\nstd::vector<long\
    \ long> two_pointers(long long n, CanAdd can_add, Add add, Erase erase) {\n  \
    \  std::vector<long long> res(n);\n    long long r = 0;\n    for (long long l\
    \ = 0; l < n; l++) {\n        if (r < l) r = l;\n        while (r < n && can_add(l,\
    \ r)) add(r++);\n        res[l] = r;\n        if (l < r) erase(l);\n    }\n  \
    \  return res;\n}\n\n/**\n * @brief \u72B6\u614B\u3092\u6301\u305F\u306A\u3044\
    \u5C3A\u53D6\u308A\u6CD5 (can_add(l, r) \u304C l \u3068 r \u3060\u3051\u3067\u6C7A\
    \u307E\u308B\u3068\u304D)\n */\ntemplate <class CanAdd>\nstd::vector<long long>\
    \ two_pointers(long long n, CanAdd can_add) {\n    return two_pointers(n, can_add,\
    \ [](long long) {}, [](long long) {});\n}\n#line 13 \"src/others/subarray-sum.hpp\"\
    \n\nnamespace internal_subarray_sum {\n// i < j \u304B\u3064 p[j] - p[i] <= k\
    \ \u3068\u306A\u308B\u7D44 (i, j) \u306E\u500B\u6570\n// p \u304C\u5E83\u7FA9\u5358\
    \u8ABF\u5897\u52A0\u306A\u3089\u5C3A\u53D6\u308A\u6CD5\u3067 O(n)\u3001\u305D\u3046\
    \u3067\u306A\u3051\u308C\u3070\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u3067 O(n log\
    \ n) (\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044)\ntemplate <typename T>\nlong\
    \ long count_pairs_at_most(std::vector<T> p, T k) {\n    const int n = p.size();\n\
    \    long long res = 0;\n    if (std::is_sorted(p.begin(), p.end())) {\n     \
    \   // i \u3054\u3068\u306B\u3001p[j] - p[i] <= k \u3068\u306A\u308B j \u306F\
    \ [i, r[i]) (p \u304C\u5358\u8ABF\u306A\u306E\u3067\u3001i \u3092\u5897\u3084\u3057\
    \u3066\u3082\u6761\u4EF6\u306F\u5D29\u308C\u306A\u3044)\n        const auto r\
    \ = two_pointers(n, [&](long long i, long long j) { return p[j] - p[i] <= k; });\n\
    \        for (int i = 0; i < n; i++) res += std::max(r[i] - i - 1, 0LL);\n   \
    \     return res;\n    }\n    std::vector<T> buf(n);\n    for (int w = 1; w <\
    \ n; w *= 2) {\n        for (int l = 0; l < n; l += 2 * w) {\n            const\
    \ int m = std::min(l + w, n), r = std::min(l + 2 * w, n);\n            // \u5DE6\
    \u306E [l, m) \u3068\u53F3\u306E [m, r) \u306F\u305D\u308C\u305E\u308C\u6607\u9806\
    \u3002\u53F3\u306E\u5404 p[j] \u306B\u3064\u3044\u3066\u3001\u5DE6\u3067 p[i]\
    \ >= p[j] - k \u3068\u306A\u308B\u3082\u306E\u3092\u6570\u3048\u308B\n       \
    \     for (int i = l, j = m; j < r; j++) {\n                while (i < m && p[i]\
    \ < p[j] - k) i++;\n                res += m - i;\n            }\n           \
    \ std::merge(p.begin() + l, p.begin() + m, p.begin() + m, p.begin() + r, buf.begin()\
    \ + l);\n            std::copy(buf.begin() + l, buf.begin() + r, p.begin() + l);\n\
    \        }\n    }\n    return res;\n}\n// \u5148\u982D\u306B 0 \u3092\u4ED8\u3051\
    \u305F\u7D2F\u7A4D\u548C\ntemplate <typename T>\nstd::vector<T> prefix_sums(const\
    \ std::vector<T>& a) {\n    std::vector<T> p(a.size() + 1, T{});\n    for (size_t\
    \ i = 0; i < a.size(); i++) p[i + 1] = p[i] + a[i];\n    return p;\n}\n}  // namespace\
    \ internal_subarray_sum\n\n/**\n * @brief \u548C\u304C k \u4EE5\u4E0B\u306E\u533A\
    \u9593 [l, r) (l < r) \u306E\u500B\u6570\n * \u7D2F\u7A4D\u548C P \u306B\u3064\
    \u3044\u3066\u3001l < r \u304B\u3064 P[r] - P[l] <= k \u3068\u306A\u308B\u7D44\
    \u3092\u6570\u3048\u308B\u3002\u8981\u7D20\u304C\u3059\u3079\u3066 0 \u4EE5\u4E0A\
    \u306A\u3089\u5C3A\u53D6\u308A\u6CD5\u3067 O(n)\u3001\u305D\u3046\u3067\u306A\u3051\
    \u308C\u3070 O(n log n)\n */\ntemplate <typename T>\nlong long count_subarrays_with_sum_at_most(const\
    \ std::vector<T>& a, T k) {\n    return internal_subarray_sum::count_pairs_at_most(internal_subarray_sum::prefix_sums(a),\
    \ k);\n}\n\n/**\n * @brief \u548C\u304C\u3061\u3087\u3046\u3069 k \u306E\u533A\
    \u9593 [l, r) (l < r) \u306E\u500B\u6570\n * (\u548C\u304C k \u4EE5\u4E0B\u306E\
    \u500B\u6570) - (\u548C\u304C k - 1 \u4EE5\u4E0B\u306E\u500B\u6570) \u3067\u6C42\
    \u3081\u308B\u3002\u8981\u7D20\u304C\u3059\u3079\u3066 0 \u4EE5\u4E0A\u306A\u3089\
    \ O(n)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 O(n log n)\n * @note \u8981\
    \u7D20\u306F\u6574\u6570\u578B\u3067\u3042\u308B\u3053\u3068\n */\ntemplate <typename\
    \ T>\nlong long count_subarrays_with_sum(const std::vector<T>& a, T k) {\n   \
    \ static_assert(std::is_integral_v<T>, \"count_subarrays_with_sum: T must be an\
    \ integer type\");\n    const auto p = internal_subarray_sum::prefix_sums(a);\n\
    \    return internal_subarray_sum::count_pairs_at_most(p, k) - internal_subarray_sum::count_pairs_at_most(p,\
    \ k - 1);\n}\n#line 8 \"test/unittest/others/subarray-sum.test.cpp\"\n\n#include\
    \ <iostream>\n#include <random>\n#line 12 \"test/unittest/others/subarray-sum.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 15;\n    \
    \    bool nonneg = rep % 2 == 0;\n        std::vector<long long> a(n);\n     \
    \   for (auto& x : a) x = nonneg ? static_cast<long long>(rng() % 4) : static_cast<long\
    \ long>(rng() % 9) - 4;\n        for (long long k = -10; k <= 15; k++) {\n   \
    \         long long eq = 0, le = 0;\n            for (int l = 0; l < n; l++) {\n\
    \                long long s = 0;\n                for (int r = l + 1; r <= n;\
    \ r++) {\n                    s += a[r - 1];\n                    eq += s == k,\
    \ le += s <= k;\n                }\n            }\n            if (count_subarrays_with_sum(a,\
    \ k) != eq || count_subarrays_with_sum_at_most(a, k) != le) ok = false;\n    \
    \    }\n    }\n    // \u4F8B: AtCoder AWC 0185 C \u306E\u5165\u529B\u4F8B 1\n\
    \    if (count_subarrays_with_sum(std::vector<long long>{1, 2, 3, 2, 1, 4}, 5LL)\
    \ != 3) ok = false;\n    // double \u3067\u3082 k \u4EE5\u4E0B\u306E\u500B\u6570\
    \u306F\u6570\u3048\u3089\u308C\u308B\n    if (count_subarrays_with_sum_at_most(std::vector<double>{0.5,\
    \ -1.5, 2.0}, 0.5) != 4) ok = false;\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// subarray-sum.hpp \u306E count_subarrays_with_sum\u30FBcount_subarrays_with_sum_at_most\
    \ \u3092\u3001\u3059\u3079\u3066\u306E\u533A\u9593\u306E\u548C\u3092\u8ABF\u3079\
    \u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u8981\u7D20\u304C\
    \u3059\u3079\u3066 0 \u4EE5\u4E0A\u306E\u5217 (\u5C3A\u53D6\u308A\u6CD5) \u3068\
    \u8CA0\u3092\u542B\u3080\u5217 (\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8) \u306E\u4E21\
    \u65B9\u3067\u3001k \u3082\u8CA0\u304B\u3089\u6B63\u307E\u3067\u8ABF\u3079\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../../src/others/subarray-sum.hpp\"\n\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 15;\n        bool nonneg = rep % 2 == 0;\n        std::vector<long\
    \ long> a(n);\n        for (auto& x : a) x = nonneg ? static_cast<long long>(rng()\
    \ % 4) : static_cast<long long>(rng() % 9) - 4;\n        for (long long k = -10;\
    \ k <= 15; k++) {\n            long long eq = 0, le = 0;\n            for (int\
    \ l = 0; l < n; l++) {\n                long long s = 0;\n                for\
    \ (int r = l + 1; r <= n; r++) {\n                    s += a[r - 1];\n       \
    \             eq += s == k, le += s <= k;\n                }\n            }\n\
    \            if (count_subarrays_with_sum(a, k) != eq || count_subarrays_with_sum_at_most(a,\
    \ k) != le) ok = false;\n        }\n    }\n    // \u4F8B: AtCoder AWC 0185 C \u306E\
    \u5165\u529B\u4F8B 1\n    if (count_subarrays_with_sum(std::vector<long long>{1,\
    \ 2, 3, 2, 1, 4}, 5LL) != 3) ok = false;\n    // double \u3067\u3082 k \u4EE5\u4E0B\
    \u306E\u500B\u6570\u306F\u6570\u3048\u3089\u308C\u308B\n    if (count_subarrays_with_sum_at_most(std::vector<double>{0.5,\
    \ -1.5, 2.0}, 0.5) != 4) ok = false;\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/others/subarray-sum.hpp
  - src/utility/two-pointers.hpp
  isVerificationFile: true
  path: test/unittest/others/subarray-sum.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 23:17:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/others/subarray-sum.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/others/subarray-sum.test.cpp
- /verify/test/unittest/others/subarray-sum.test.cpp.html
title: test/unittest/others/subarray-sum.test.cpp
---
