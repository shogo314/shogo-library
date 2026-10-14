---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl-1-d.test.cpp
    title: test/aoj/dpl-1-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/longest-increasing-subsequence.test.cpp
    title: test/unittest/longest-increasing-subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/longest-increasing-subsequence.test.cpp
    title: test/yosupo/longest-increasing-subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
    links: []
  bundledCode: "#line 2 \"src/dp/longest-increasing-subsequence.hpp\"\n\n/**\n * @file\
    \ longest-increasing-subsequence.hpp\n * @brief \u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217 (LIS)\n */\n\n#include <algorithm>\n#include <functional>\n#include\
    \ <vector>\n\n/**\n * @brief a[i] \u3067\u7D42\u308F\u308B\u6700\u9577\u5897\u52A0\
    \u90E8\u5206\u5217\u306E\u9577\u3055\u3092\u3001\u5404 i \u306B\u3064\u3044\u3066\
    \u6C42\u3081\u308B O(n log n)\n * @param strict true \u306A\u3089\u72ED\u7FA9\u5358\
    \u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C) \u304C\u6210\u308A\u7ACB\u3064)\u3001\
    false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044)\n * @param comp \u5927\u5C0F\u306E\u6BD4\
    \u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\
    \u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\nstd::vector<int>\
    \ longest_increasing_subsequence_lengths(const std::vector<T>& a, bool strict\
    \ = true,\n                                                         Compare comp\
    \ = Compare()) {\n    // tail[k] \u306F\u3001\u9577\u3055 k + 1 \u306E\u5897\u52A0\
    \u90E8\u5206\u5217\u306E\u672B\u5C3E\u3068\u3057\u3066\u6700\u3082\u5C0F\u3055\
    \u3044\u5024\n    std::vector<T> tail;\n    std::vector<int> res(a.size());\n\
    \    for (int i = 0; i < (int)a.size(); i++) {\n        auto it = strict ? std::lower_bound(tail.begin(),\
    \ tail.end(), a[i], comp)\n                         : std::upper_bound(tail.begin(),\
    \ tail.end(), a[i], comp);\n        res[i] = it - tail.begin() + 1;\n        if\
    \ (it == tail.end()) tail.push_back(a[i]);\n        else *it = a[i];\n    }\n\
    \    return res;\n}\n\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\
    \u306E\u9577\u3055 O(n log n)\n * @param strict true \u306A\u3089\u72ED\u7FA9\u5358\
    \u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C) \u304C\u6210\u308A\u7ACB\u3064)\u3001\
    false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044)\n * @param comp \u5927\u5C0F\u306E\u6BD4\
    \u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\
    \u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\nint\
    \ longest_increasing_subsequence(const std::vector<T>& a, bool strict = true,\
    \ Compare comp = Compare()) {\n    // tail[k] \u306F\u3001\u9577\u3055 k + 1 \u306E\
    \u5897\u52A0\u90E8\u5206\u5217\u306E\u672B\u5C3E\u3068\u3057\u3066\u6700\u3082\
    \u5C0F\u3055\u3044\u5024\n    std::vector<T> tail;\n    for (const T& x : a) {\n\
    \        auto it = strict ? std::lower_bound(tail.begin(), tail.end(), x, comp)\n\
    \                         : std::upper_bound(tail.begin(), tail.end(), x, comp);\n\
    \        if (it == tail.end()) tail.push_back(x);\n        else *it = x;\n   \
    \ }\n    return tail.size();\n}\n\n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\
    \u5206\u5217\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\u6DFB\u5B57\u306E\u6607\
    \u9806\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059 O(n log n)\n * @param strict\
    \ true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C)\
    \ \u304C\u6210\u308A\u7ACB\u3064)\u3001false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    )\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\
    \u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\u306A\u308B\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nstd::vector<int> longest_increasing_subsequence_restore(const\
    \ std::vector<T>& a, bool strict = true,\n                                   \
    \                      Compare comp = Compare()) {\n    std::vector<int> len =\
    \ longest_increasing_subsequence_lengths(a, strict, comp);\n    int k = len.empty()\
    \ ? 0 : *std::max_element(len.begin(), len.end());\n    // \u5F8C\u308D\u304B\u3089\
    \u3001\u9577\u3055\u304C 1 \u305A\u3064\u6E1B\u308A\u3001\u5024\u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6DFB\u5B57\u3092\u9078\u3076\n    std::vector<int> res(k);\n\
    \    int last = -1;\n    for (int i = (int)a.size() - 1; i >= 0 && k > 0; i--)\
    \ {\n        if (len[i] != k) continue;\n        if (last != -1 && !(strict ?\
    \ comp(a[i], a[last]) : !comp(a[last], a[i]))) continue;\n        res[--k] = i;\n\
    \        last = i;\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file longest-increasing-subsequence.hpp\n * @brief\
    \ \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)\n */\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n\n/**\n * @brief a[i] \u3067\u7D42\u308F\
    \u308B\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\u3092\u3001\
    \u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B O(n log n)\n * @param strict\
    \ true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u524D, \u5F8C)\
    \ \u304C\u6210\u308A\u7ACB\u3064)\u3001false \u306A\u3089\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    )\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\
    \u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\u306A\u308B\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nstd::vector<int> longest_increasing_subsequence_lengths(const\
    \ std::vector<T>& a, bool strict = true,\n                                   \
    \                      Compare comp = Compare()) {\n    // tail[k] \u306F\u3001\
    \u9577\u3055 k + 1 \u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u672B\u5C3E\u3068\
    \u3057\u3066\u6700\u3082\u5C0F\u3055\u3044\u5024\n    std::vector<T> tail;\n \
    \   std::vector<int> res(a.size());\n    for (int i = 0; i < (int)a.size(); i++)\
    \ {\n        auto it = strict ? std::lower_bound(tail.begin(), tail.end(), a[i],\
    \ comp)\n                         : std::upper_bound(tail.begin(), tail.end(),\
    \ a[i], comp);\n        res[i] = it - tail.begin() + 1;\n        if (it == tail.end())\
    \ tail.push_back(a[i]);\n        else *it = a[i];\n    }\n    return res;\n}\n\
    \n/**\n * @brief \u6700\u9577\u5897\u52A0\u90E8\u5206\u5217\u306E\u9577\u3055\
    \ O(n log n)\n * @param strict true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\u5897\
    \u52A0 (comp(\u524D, \u5F8C) \u304C\u6210\u308A\u7ACB\u3064)\u3001false \u306A\
    \u3089\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\u6210\u308A\
    \u7ACB\u305F\u306A\u3044)\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002\
    std::greater<T>() \u3092\u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\u306A\u308B\
    \n */\ntemplate <typename T, typename Compare = std::less<T>>\nint longest_increasing_subsequence(const\
    \ std::vector<T>& a, bool strict = true, Compare comp = Compare()) {\n    // tail[k]\
    \ \u306F\u3001\u9577\u3055 k + 1 \u306E\u5897\u52A0\u90E8\u5206\u5217\u306E\u672B\
    \u5C3E\u3068\u3057\u3066\u6700\u3082\u5C0F\u3055\u3044\u5024\n    std::vector<T>\
    \ tail;\n    for (const T& x : a) {\n        auto it = strict ? std::lower_bound(tail.begin(),\
    \ tail.end(), x, comp)\n                         : std::upper_bound(tail.begin(),\
    \ tail.end(), x, comp);\n        if (it == tail.end()) tail.push_back(x);\n  \
    \      else *it = x;\n    }\n    return tail.size();\n}\n\n/**\n * @brief \u6700\
    \u9577\u5897\u52A0\u90E8\u5206\u5217\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\
    \u6DFB\u5B57\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\u3092\u8FD4\u3059 O(n log\
    \ n)\n * @param strict true \u306A\u3089\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0 (comp(\u524D\
    , \u5F8C) \u304C\u6210\u308A\u7ACB\u3064)\u3001false \u306A\u3089\u5E83\u7FA9\u5358\
    \u8ABF\u5897\u52A0 (comp(\u5F8C, \u524D) \u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    )\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\
    \u6E21\u3059\u3068\u6E1B\u5C11\u5217\u306B\u306A\u308B\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nstd::vector<int> longest_increasing_subsequence_restore(const\
    \ std::vector<T>& a, bool strict = true,\n                                   \
    \                      Compare comp = Compare()) {\n    std::vector<int> len =\
    \ longest_increasing_subsequence_lengths(a, strict, comp);\n    int k = len.empty()\
    \ ? 0 : *std::max_element(len.begin(), len.end());\n    // \u5F8C\u308D\u304B\u3089\
    \u3001\u9577\u3055\u304C 1 \u305A\u3064\u6E1B\u308A\u3001\u5024\u304C\u6761\u4EF6\
    \u3092\u6E80\u305F\u3059\u6DFB\u5B57\u3092\u9078\u3076\n    std::vector<int> res(k);\n\
    \    int last = -1;\n    for (int i = (int)a.size() - 1; i >= 0 && k > 0; i--)\
    \ {\n        if (len[i] != k) continue;\n        if (last != -1 && !(strict ?\
    \ comp(a[i], a[last]) : !comp(a[last], a[i]))) continue;\n        res[--k] = i;\n\
    \        last = i;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/longest-increasing-subsequence.hpp
  requiredBy: []
  timestamp: '2026-10-14 06:59:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/longest-increasing-subsequence.test.cpp
  - test/aoj/dpl-1-d.test.cpp
  - test/yosupo/longest-increasing-subsequence.test.cpp
documentation_of: src/dp/longest-increasing-subsequence.hpp
layout: document
title: "\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217 (LIS)"
---

列 `a` の最長増加部分列を求めます。どれも $O(n \log n)$ です。

```cpp
std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
int k = longest_increasing_subsequence(a);            // 4
auto idx = longest_increasing_subsequence_restore(a); // 添字のリスト。{1, 2, 4, 7} (値は 1, 4, 5, 6)
auto len = longest_increasing_subsequence_lengths(a); // {1, 1, 2, 1, 3, 4, 2, 4}
```

| 関数 | 説明 |
|---|---|
| `longest_increasing_subsequence(a, strict = true, comp = std::less<T>())` | 最長増加部分列の長さ |
| `longest_increasing_subsequence_restore(a, strict = true, comp = std::less<T>())` | 最長増加部分列を 1 つ求め、その添字を昇順に並べたリストを返す |
| `longest_increasing_subsequence_lengths(a, strict = true, comp = std::less<T>())` | `a[i]` で終わる最長増加部分列の長さを、各 `i` について並べたリスト |

- `strict = true` なら狭義単調増加 (隣り合う値が `comp(前, 後)` を満たす)、`false` なら広義単調増加 (`comp(後, 前)` を満たさない) です。
- `comp` に `std::greater<T>()` を渡すと減少列になります。`T` は `a` の要素の型で、`comp` で比べられれば何でもかまいません。

`a[i]` から始まる最長の長さが欲しいときは、`a` を逆順にして `comp` を逆にすれば求められます。
