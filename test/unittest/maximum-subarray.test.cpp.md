---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/maximum-subarray.hpp
    title: "\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (Kadane\
      \ \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
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
  bundledCode: "#line 1 \"test/unittest/maximum-subarray.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ maximum_subarray \u3092\u3001\u3059\u3079\u3066\u306E\u533A\u9593\u3092\u8ABF\
    \u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/dp/maximum-subarray.hpp\"\n\n/**\n * @file\
    \ maximum-subarray.hpp\n * @brief \u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\
    \u6700\u5927\u5024 (Kadane \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\n */\n\n\
    #include <cassert>\n\n/**\n * @brief \u7A7A\u3067\u306A\u3044\u9023\u7D9A\u90E8\
    \u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 O(n)\n * @param v begin()\u3001\
    end() \u3092\u6301\u3064\u7A7A\u3067\u306A\u3044\u30B3\u30F3\u30C6\u30CA\n */\n\
    template <class C>\nconstexpr typename C::value_type maximum_subarray(const C&\
    \ v) {\n    assert(!v.empty());\n    auto itr = v.begin();\n    // tmp \u306F\u3001\
    \u3044\u307E\u898B\u3066\u3044\u308B\u8981\u7D20\u3067\u7D42\u308F\u308B\u9023\
    \u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024\n    typename C::value_type\
    \ tmp = *itr++;\n    typename C::value_type res = tmp;\n    while (itr != v.end())\
    \ {\n        tmp += *itr;\n        if (tmp < *itr) tmp = *itr;\n        if (res\
    \ < tmp) res = tmp;\n        ++itr;\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ \u7A7A\u306E\u90E8\u5206\u5217 (\u548C init) \u3082\u8A31\u3057\u305F\u9023\u7D9A\
    \u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 O(n)\n * @param v begin()\u3001\
    end() \u3092\u6301\u3064\u30B3\u30F3\u30C6\u30CA\n * @param init \u7A7A\u306E\u90E8\
    \u5206\u5217\u306E\u548C\n */\ntemplate <class C>\nconstexpr typename C::value_type\
    \ maximum_subarray(const C& v, typename C::value_type init) {\n    typename C::value_type\
    \ res = init, tmp = init;\n    for (const auto& a : v) {\n        tmp += a;\n\
    \        if (tmp < init) tmp = init;\n        if (res < tmp) res = tmp;\n    }\n\
    \    return res;\n}\n#line 7 \"test/unittest/maximum-subarray.test.cpp\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n \
    \   if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \        ok = false;\n    }\n}\n\n// constexpr \u3067\u4F7F\u3048\u308B\u3053\u3068\
    \nstatic_assert(maximum_subarray(std::array<int, 5>{-1, 3, -2, 4, -5}) == 5);\n\
    static_assert(maximum_subarray(std::array<int, 3>{-5, -2, -9}, 0) == 0);\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    for (int rep = 0; rep < 1000; rep++)\
    \ {\n        int n = rng() % 10 + 1;\n        std::vector<long long> v(n);\n \
    \       for (auto& x : v) x = (long long)(rng() % 21) - 10;\n\n        // \u7A7A\
    \u3067\u306A\u3044\u7248\n        long long best_nonempty = v[0];\n        for\
    \ (int l = 0; l < n; l++) {\n            long long s = 0;\n            for (int\
    \ r = l; r < n; r++) {\n                s += v[r];\n                best_nonempty\
    \ = std::max(best_nonempty, s);\n            }\n        }\n        check(maximum_subarray(v)\
    \ == best_nonempty, \"maximum_subarray(c)\");\n\n        // \u7A7A\u306E\u90E8\
    \u5206\u5217\u3092\u8A31\u3059\u7248: \u5168\u533A\u9593\u306E\u548C\u306E\u6700\
    \u5927\u5024\u3068 init \u306E\u5927\u304D\u3044\u65B9\n        long long init\
    \ = (long long)(rng() % 7) - 3;\n        long long best = init;\n        for (int\
    \ l = 0; l < n; l++) {\n            long long s = init;\n            for (int\
    \ r = l; r < n; r++) {\n                s += v[r];\n                best = std::max(best,\
    \ s);\n            }\n        }\n        check(maximum_subarray(v, init) == best,\
    \ \"maximum_subarray(c, init)\");\n    }\n\n    // \u5883\u754C: \u7A7A\u3001\u3059\
    \u3079\u3066\u8CA0\n    check(maximum_subarray(std::vector<int>{}, 0) == 0, \"\
    maximum_subarray \u7A7A\");\n    check(maximum_subarray(std::vector<int>{-5, -2,\
    \ -9}) == -2, \"maximum_subarray \u3059\u3079\u3066\u8CA0\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}, 0) == 0, \"maximum_subarray \u3059\u3079\u3066\u8CA0\u3001\u7A7A\u3092\
    \u8A31\u3059\");\n    check(maximum_subarray(std::vector<int>{-2, 1, -3, 4, -1,\
    \ 2, 1, -5, 4}) == 6, \"maximum_subarray \u30C9\u30AD\u30E5\u30E1\u30F3\u30C8\u306E\
    \u4F8B\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// maximum_subarray \u3092\u3001\u3059\u3079\u3066\u306E\u533A\u9593\u3092\
    \u8ABF\u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/dp/maximum-subarray.hpp\"\n\n\
    #include <algorithm>\n#include <array>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\nbool ok = true;\n\nvoid check(bool cond, const char* what)\
    \ {\n    if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \        ok = false;\n    }\n}\n\n// constexpr \u3067\u4F7F\u3048\u308B\u3053\u3068\
    \nstatic_assert(maximum_subarray(std::array<int, 5>{-1, 3, -2, 4, -5}) == 5);\n\
    static_assert(maximum_subarray(std::array<int, 3>{-5, -2, -9}, 0) == 0);\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    for (int rep = 0; rep < 1000; rep++)\
    \ {\n        int n = rng() % 10 + 1;\n        std::vector<long long> v(n);\n \
    \       for (auto& x : v) x = (long long)(rng() % 21) - 10;\n\n        // \u7A7A\
    \u3067\u306A\u3044\u7248\n        long long best_nonempty = v[0];\n        for\
    \ (int l = 0; l < n; l++) {\n            long long s = 0;\n            for (int\
    \ r = l; r < n; r++) {\n                s += v[r];\n                best_nonempty\
    \ = std::max(best_nonempty, s);\n            }\n        }\n        check(maximum_subarray(v)\
    \ == best_nonempty, \"maximum_subarray(c)\");\n\n        // \u7A7A\u306E\u90E8\
    \u5206\u5217\u3092\u8A31\u3059\u7248: \u5168\u533A\u9593\u306E\u548C\u306E\u6700\
    \u5927\u5024\u3068 init \u306E\u5927\u304D\u3044\u65B9\n        long long init\
    \ = (long long)(rng() % 7) - 3;\n        long long best = init;\n        for (int\
    \ l = 0; l < n; l++) {\n            long long s = init;\n            for (int\
    \ r = l; r < n; r++) {\n                s += v[r];\n                best = std::max(best,\
    \ s);\n            }\n        }\n        check(maximum_subarray(v, init) == best,\
    \ \"maximum_subarray(c, init)\");\n    }\n\n    // \u5883\u754C: \u7A7A\u3001\u3059\
    \u3079\u3066\u8CA0\n    check(maximum_subarray(std::vector<int>{}, 0) == 0, \"\
    maximum_subarray \u7A7A\");\n    check(maximum_subarray(std::vector<int>{-5, -2,\
    \ -9}) == -2, \"maximum_subarray \u3059\u3079\u3066\u8CA0\");\n    check(maximum_subarray(std::vector<int>{-5,\
    \ -2, -9}, 0) == 0, \"maximum_subarray \u3059\u3079\u3066\u8CA0\u3001\u7A7A\u3092\
    \u8A31\u3059\");\n    check(maximum_subarray(std::vector<int>{-2, 1, -3, 4, -1,\
    \ 2, 1, -5, 4}) == 6, \"maximum_subarray \u30C9\u30AD\u30E5\u30E1\u30F3\u30C8\u306E\
    \u4F8B\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/maximum-subarray.hpp
  isVerificationFile: true
  path: test/unittest/maximum-subarray.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 23:11:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/maximum-subarray.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/maximum-subarray.test.cpp
- /verify/test/unittest/maximum-subarray.test.cpp.html
title: test/unittest/maximum-subarray.test.cpp
---
