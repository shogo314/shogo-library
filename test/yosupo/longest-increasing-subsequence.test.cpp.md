---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/longest-increasing-subsequence.hpp
    title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo/longest-increasing-subsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#line 2 \"src/dp/longest-increasing-subsequence.hpp\"\n\n/**\n * @file longest-increasing-subsequence.hpp\n\
    \ * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)\n */\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\n/**\n * @brief a[i] \u3067\u7D42\u308F\
    \u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\u3092\u3001\
    \u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B O(n log n)\n * @param strict\
    \ true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C)\
    \ \u304C\u6210\u308A\u7ACB\u3064)\u3001false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    )\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\
    \u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\u306A\u308B\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nstd::vector<long long> longest_increasing_subsequence_lengths(const\
    \ std::vector<T>& a, bool strict = true,\n                                   \
    \                           Compare comp = Compare()) {\n    // tail[k] \u306F\
    \u3001\u9577\u3055 k + 1 \u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u672B\u5C3E\
    \u3068\u3057\u3066\u6700\u3082\u5C0F\u3055\u3044\u5024\n    std::vector<T> tail;\n\
    \    std::vector<long long> res(a.size());\n    for (long long i = 0; i < static_cast<long\
    \ long>(a.size()); i++) {\n        auto it = strict ? std::lower_bound(tail.begin(),\
    \ tail.end(), a[i], comp)\n                         : std::upper_bound(tail.begin(),\
    \ tail.end(), a[i], comp);\n        res[i] = it - tail.begin() + 1;\n        if\
    \ (it == tail.end())\n            tail.push_back(a[i]);\n        else\n      \
    \      *it = a[i];\n    }\n    return res;\n}\n\n/**\n * @brief \u6700\u9577\u5897\
    \u52A0\u90E8\u5206\u5217\u306E\u9577\u3055 O(n log n)\n * @param strict true \u306A\
    \u3089\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C) \u304C\u6210\u308A\
    \u7ACB\u3064)\u3001false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u5F8C\
    , \u524D) \u304C\u6210\u308A\u7ACB\u305F\u306A\u3044)\n * @param comp \u5927\u5C0F\
    \u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6E1B\u5C11\
    \u5217\u306B\u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\n\
    long long longest_increasing_subsequence(const std::vector<T>& a, bool strict\
    \ = true, Compare comp = Compare()) {\n    // tail[k] \u306F\u3001\u9577\u3055\
    \ k + 1 \u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u672B\u5C3E\u3068\u3057\u3066\
    \u6700\u3082\u5C0F\u3055\u3044\u5024\n    std::vector<T> tail;\n    for (const\
    \ T& x : a) {\n        auto it = strict ? std::lower_bound(tail.begin(), tail.end(),\
    \ x, comp)\n                         : std::upper_bound(tail.begin(), tail.end(),\
    \ x, comp);\n        if (it == tail.end())\n            tail.push_back(x);\n \
    \       else\n            *it = x;\n    }\n    return tail.size();\n}\n\n/**\n\
    \ * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u3092 1 \u3064\u6C42\u3081\
    \u3001\u305D\u306E\u6DFB\u5B57\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\u3092\
    \u8FD4\u3059 O(n log n)\n * @param strict true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\
    \u5897\u52A0 (comp(\u524D, \u5F8C) \u304C\u6210\u308A\u7ACB\u3064)\u3001false\
    \ \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044)\n * @param comp \u5927\u5C0F\u306E\u6BD4\
    \u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\
    \u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\nstd::vector<long\
    \ long> longest_increasing_subsequence_restore(const std::vector<T>& a, bool strict\
    \ = true,\n                                                              Compare\
    \ comp = Compare()) {\n    std::vector<long long> len = longest_increasing_subsequence_lengths(a,\
    \ strict, comp);\n    long long k = len.empty() ? 0 : *std::max_element(len.begin(),\
    \ len.end());\n    // \u5F8C\u308D\u304B\u3089\u3001\u9577\u3055\u304C 1 \u305A\
    \u3064\u6E1B\u308A\u3001\u5024\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6DFB\
    \u5B57\u3092\u9078\u3076\n    std::vector<long long> res(k);\n    long long last\
    \ = -1;\n    for (long long i = static_cast<long long>(a.size()) - 1; i >= 0 &&\
    \ k > 0; i--) {\n        if (len[i] != k) continue;\n        if (last != -1 &&\
    \ !(strict ? comp(a[i], a[last]) : !comp(a[last], a[i]))) continue;\n        res[--k]\
    \ = i;\n        last = i;\n    }\n    return res;\n}\n#line 4 \"test/yosupo/longest-increasing-subsequence.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/yosupo/longest-increasing-subsequence.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for (auto& x\
    \ : a) std::cin >> x;\n    std::vector<long long> idx = longest_increasing_subsequence_restore(a);\n\
    \    std::cout << idx.size() << '\\n';\n    for (long long i = 0; i < (long long)idx.size();\
    \ i++) std::cout << idx[i] << \" \\n\"[i + 1 == (long long)idx.size()];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../../src/dp/longest-increasing-subsequence.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for (auto& x\
    \ : a) std::cin >> x;\n    std::vector<long long> idx = longest_increasing_subsequence_restore(a);\n\
    \    std::cout << idx.size() << '\\n';\n    for (long long i = 0; i < (long long)idx.size();\
    \ i++) std::cout << idx[i] << \" \\n\"[i + 1 == (long long)idx.size()];\n}\n"
  dependsOn:
  - src/dp/longest-increasing-subsequence.hpp
  isVerificationFile: true
  path: test/yosupo/longest-increasing-subsequence.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/longest-increasing-subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/longest-increasing-subsequence.test.cpp
- /verify/test/yosupo/longest-increasing-subsequence.test.cpp.html
title: test/yosupo/longest-increasing-subsequence.test.cpp
---
