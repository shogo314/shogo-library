---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0022.test.cpp
    title: test/aoj/0022.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/maximum-subarray.test.cpp
    title: test/unittest/maximum-subarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024\
      \ (Kadane \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
    links: []
  bundledCode: "#line 2 \"src/dp/maximum-subarray.hpp\"\n\n/**\n * @file maximum-subarray.hpp\n\
    \ * @brief \u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024\
    \ (Kadane \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)\n */\n\n#include <cassert>\n\
    \n/**\n * @brief \u7A7A\u3067\u306A\u3044\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\
    \u306E\u6700\u5927\u5024 O(n)\n * @param v begin()\u3001end() \u3092\u6301\u3064\
    \u7A7A\u3067\u306A\u3044\u30B3\u30F3\u30C6\u30CA\n */\ntemplate <class C>\nconstexpr\
    \ typename C::value_type maximum_subarray(const C& v) {\n    assert(!v.empty());\n\
    \    auto itr = v.begin();\n    // tmp \u306F\u3001\u3044\u307E\u898B\u3066\u3044\
    \u308B\u8981\u7D20\u3067\u7D42\u308F\u308B\u9023\u7D9A\u90E8\u5206\u5217\u306E\
    \u548C\u306E\u6700\u5927\u5024\n    typename C::value_type tmp = *itr++;\n   \
    \ typename C::value_type res = tmp;\n    while (itr != v.end()) {\n        tmp\
    \ += *itr;\n        if (tmp < *itr) tmp = *itr;\n        if (res < tmp) res =\
    \ tmp;\n        ++itr;\n    }\n    return res;\n}\n\n/**\n * @brief \u7A7A\u306E\
    \u90E8\u5206\u5217 (\u548C init) \u3082\u8A31\u3057\u305F\u9023\u7D9A\u90E8\u5206\
    \u5217\u306E\u548C\u306E\u6700\u5927\u5024 O(n)\n * @param v begin()\u3001end()\
    \ \u3092\u6301\u3064\u30B3\u30F3\u30C6\u30CA\n * @param init \u7A7A\u306E\u90E8\
    \u5206\u5217\u306E\u548C\n */\ntemplate <class C>\nconstexpr typename C::value_type\
    \ maximum_subarray(const C& v, typename C::value_type init) {\n    typename C::value_type\
    \ res = init, tmp = init;\n    for (const auto& a : v) {\n        tmp += a;\n\
    \        if (tmp < init) tmp = init;\n        if (res < tmp) res = tmp;\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file maximum-subarray.hpp\n * @brief \u9023\u7D9A\
    \u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (Kadane \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0)\n */\n\n#include <cassert>\n\n/**\n * @brief \u7A7A\u3067\
    \u306A\u3044\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024\
    \ O(n)\n * @param v begin()\u3001end() \u3092\u6301\u3064\u7A7A\u3067\u306A\u3044\
    \u30B3\u30F3\u30C6\u30CA\n */\ntemplate <class C>\nconstexpr typename C::value_type\
    \ maximum_subarray(const C& v) {\n    assert(!v.empty());\n    auto itr = v.begin();\n\
    \    // tmp \u306F\u3001\u3044\u307E\u898B\u3066\u3044\u308B\u8981\u7D20\u3067\
    \u7D42\u308F\u308B\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\
    \u5024\n    typename C::value_type tmp = *itr++;\n    typename C::value_type res\
    \ = tmp;\n    while (itr != v.end()) {\n        tmp += *itr;\n        if (tmp\
    \ < *itr) tmp = *itr;\n        if (res < tmp) res = tmp;\n        ++itr;\n   \
    \ }\n    return res;\n}\n\n/**\n * @brief \u7A7A\u306E\u90E8\u5206\u5217 (\u548C\
    \ init) \u3082\u8A31\u3057\u305F\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\
    \u6700\u5927\u5024 O(n)\n * @param v begin()\u3001end() \u3092\u6301\u3064\u30B3\
    \u30F3\u30C6\u30CA\n * @param init \u7A7A\u306E\u90E8\u5206\u5217\u306E\u548C\n\
    \ */\ntemplate <class C>\nconstexpr typename C::value_type maximum_subarray(const\
    \ C& v, typename C::value_type init) {\n    typename C::value_type res = init,\
    \ tmp = init;\n    for (const auto& a : v) {\n        tmp += a;\n        if (tmp\
    \ < init) tmp = init;\n        if (res < tmp) res = tmp;\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/maximum-subarray.hpp
  requiredBy: []
  timestamp: '2026-10-15 23:11:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/maximum-subarray.test.cpp
  - test/aoj/0022.test.cpp
documentation_of: src/dp/maximum-subarray.hpp
layout: document
title: "\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (Kadane\
  \ \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0)"
---

連続部分列の和の最大値を $O(n)$ で求めます。`v[i]` で終わる連続部分列の和の最大値を前から順に更新する DP です。

```cpp
std::vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
int s = maximum_subarray(v);   // 6 ({4, -1, 2, 1})
std::vector<int> w = {-5, -2, -9};
int t = maximum_subarray(w);    // -2 (空でない部分列)
int u = maximum_subarray(w, 0); // 0 (空の部分列を許す)
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `maximum_subarray(c)` | 空でない連続部分列の和の最大値 | $O(n)$ |
| `maximum_subarray(c, init)` | 空の部分列 (和 `init`) も許した連続部分列の和の最大値 | $O(n)$ |

- `c` は `begin()`、`end()` を持つコンテナで、戻り値の型は要素の型です。
- `maximum_subarray(c)` では `c` が空であってはいけません。

## 関連

- 値の更新があったり、区間ごとに求めたりする場合は、[モノイド](../algebra/monoid.hpp) の `MaxSubarraySum` をセグメント木に乗せる
