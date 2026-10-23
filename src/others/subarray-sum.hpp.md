---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/others/subarray-sum.test.cpp
    title: test/unittest/others/subarray-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\
      \u500B\u6570"
    links: []
  bundledCode: "#line 2 \"src/others/subarray-sum.hpp\"\n\n/**\n * @file subarray-sum.hpp\n\
    \ * @brief \u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\
    \u6570\n */\n\n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\
    \nnamespace internal_subarray_sum {\n// i < j \u304B\u3064 p[j] - p[i] <= k \u3068\
    \u306A\u308B\u7D44 (i, j) \u306E\u500B\u6570\n// p \u304C\u5E83\u7FA9\u5358\u8ABF\
    \u5897\u52A0\u306A\u3089\u5C3A\u53D6\u308A\u6CD5\u3067 O(n)\u3001\u305D\u3046\u3067\
    \u306A\u3051\u308C\u3070\u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u3067 O(n log n)\
    \ (\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044)\ntemplate <typename T>\nlong long\
    \ count_pairs_at_most(std::vector<T> p, T k) {\n    const int n = p.size();\n\
    \    long long res = 0;\n    if (std::is_sorted(p.begin(), p.end())) {\n     \
    \   // j \u3054\u3068\u306B\u3001i < j \u304B\u3064 p[i] >= p[j] - k \u3068\u306A\
    \u308B\u6700\u5C0F\u306E i (\u306A\u3051\u308C\u3070 j\u3002j \u304C\u5897\u3048\
    \u308B\u3068 i \u3082\u5897\u3048\u308B)\n        for (int i = 0, j = 0; j < n;\
    \ j++) {\n            while (i < j && p[i] < p[j] - k) i++;\n            res +=\
    \ j - i;\n        }\n        return res;\n    }\n    std::vector<T> buf(n);\n\
    \    for (int w = 1; w < n; w *= 2) {\n        for (int l = 0; l < n; l += 2 *\
    \ w) {\n            const int m = std::min(l + w, n), r = std::min(l + 2 * w,\
    \ n);\n            // \u5DE6\u306E [l, m) \u3068\u53F3\u306E [m, r) \u306F\u305D\
    \u308C\u305E\u308C\u6607\u9806\u3002\u53F3\u306E\u5404 p[j] \u306B\u3064\u3044\
    \u3066\u3001\u5DE6\u3067 p[i] >= p[j] - k \u3068\u306A\u308B\u3082\u306E\u3092\
    \u6570\u3048\u308B\n            for (int i = l, j = m; j < r; j++) {\n       \
    \         while (i < m && p[i] < p[j] - k) i++;\n                res += m - i;\n\
    \            }\n            std::merge(p.begin() + l, p.begin() + m, p.begin()\
    \ + m, p.begin() + r, buf.begin() + l);\n            std::copy(buf.begin() + l,\
    \ buf.begin() + r, p.begin() + l);\n        }\n    }\n    return res;\n}\n// \u5148\
    \u982D\u306B 0 \u3092\u4ED8\u3051\u305F\u7D2F\u7A4D\u548C\ntemplate <typename\
    \ T>\nstd::vector<T> prefix_sums(const std::vector<T>& a) {\n    std::vector<T>\
    \ p(a.size() + 1, T{});\n    for (size_t i = 0; i < a.size(); i++) p[i + 1] =\
    \ p[i] + a[i];\n    return p;\n}\n}  // namespace internal_subarray_sum\n\n/**\n\
    \ * @brief \u548C\u304C k \u4EE5\u4E0B\u306E\u533A\u9593 [l, r) (l < r) \u306E\
    \u500B\u6570\n * \u7D2F\u7A4D\u548C P \u306B\u3064\u3044\u3066\u3001l < r \u304B\
    \u3064 P[r] - P[l] <= k \u3068\u306A\u308B\u7D44\u3092\u6570\u3048\u308B\u3002\
    \u8981\u7D20\u304C\u3059\u3079\u3066 0 \u4EE5\u4E0A\u306A\u3089\u5C3A\u53D6\u308A\
    \u6CD5\u3067 O(n)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 O(n log n)\n\
    \ */\ntemplate <typename T>\nlong long count_subarrays_with_sum_at_most(const\
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
    \ k - 1);\n}\n"
  code: "#pragma once\n\n/**\n * @file subarray-sum.hpp\n * @brief \u548C\u304C\u6761\
    \u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\u6570\n */\n\n#include\
    \ <algorithm>\n#include <type_traits>\n#include <vector>\n\nnamespace internal_subarray_sum\
    \ {\n// i < j \u304B\u3064 p[j] - p[i] <= k \u3068\u306A\u308B\u7D44 (i, j) \u306E\
    \u500B\u6570\n// p \u304C\u5E83\u7FA9\u5358\u8ABF\u5897\u52A0\u306A\u3089\u5C3A\
    \u53D6\u308A\u6CD5\u3067 O(n)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u30DE\
    \u30FC\u30B8\u30BD\u30FC\u30C8\u3067 O(n log n) (\u518D\u5E30\u3092\u4F7F\u308F\
    \u306A\u3044)\ntemplate <typename T>\nlong long count_pairs_at_most(std::vector<T>\
    \ p, T k) {\n    const int n = p.size();\n    long long res = 0;\n    if (std::is_sorted(p.begin(),\
    \ p.end())) {\n        // j \u3054\u3068\u306B\u3001i < j \u304B\u3064 p[i] >=\
    \ p[j] - k \u3068\u306A\u308B\u6700\u5C0F\u306E i (\u306A\u3051\u308C\u3070 j\u3002\
    j \u304C\u5897\u3048\u308B\u3068 i \u3082\u5897\u3048\u308B)\n        for (int\
    \ i = 0, j = 0; j < n; j++) {\n            while (i < j && p[i] < p[j] - k) i++;\n\
    \            res += j - i;\n        }\n        return res;\n    }\n    std::vector<T>\
    \ buf(n);\n    for (int w = 1; w < n; w *= 2) {\n        for (int l = 0; l < n;\
    \ l += 2 * w) {\n            const int m = std::min(l + w, n), r = std::min(l\
    \ + 2 * w, n);\n            // \u5DE6\u306E [l, m) \u3068\u53F3\u306E [m, r) \u306F\
    \u305D\u308C\u305E\u308C\u6607\u9806\u3002\u53F3\u306E\u5404 p[j] \u306B\u3064\
    \u3044\u3066\u3001\u5DE6\u3067 p[i] >= p[j] - k \u3068\u306A\u308B\u3082\u306E\
    \u3092\u6570\u3048\u308B\n            for (int i = l, j = m; j < r; j++) {\n \
    \               while (i < m && p[i] < p[j] - k) i++;\n                res +=\
    \ m - i;\n            }\n            std::merge(p.begin() + l, p.begin() + m,\
    \ p.begin() + m, p.begin() + r, buf.begin() + l);\n            std::copy(buf.begin()\
    \ + l, buf.begin() + r, p.begin() + l);\n        }\n    }\n    return res;\n}\n\
    // \u5148\u982D\u306B 0 \u3092\u4ED8\u3051\u305F\u7D2F\u7A4D\u548C\ntemplate <typename\
    \ T>\nstd::vector<T> prefix_sums(const std::vector<T>& a) {\n    std::vector<T>\
    \ p(a.size() + 1, T{});\n    for (size_t i = 0; i < a.size(); i++) p[i + 1] =\
    \ p[i] + a[i];\n    return p;\n}\n}  // namespace internal_subarray_sum\n\n/**\n\
    \ * @brief \u548C\u304C k \u4EE5\u4E0B\u306E\u533A\u9593 [l, r) (l < r) \u306E\
    \u500B\u6570\n * \u7D2F\u7A4D\u548C P \u306B\u3064\u3044\u3066\u3001l < r \u304B\
    \u3064 P[r] - P[l] <= k \u3068\u306A\u308B\u7D44\u3092\u6570\u3048\u308B\u3002\
    \u8981\u7D20\u304C\u3059\u3079\u3066 0 \u4EE5\u4E0A\u306A\u3089\u5C3A\u53D6\u308A\
    \u6CD5\u3067 O(n)\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070 O(n log n)\n\
    \ */\ntemplate <typename T>\nlong long count_subarrays_with_sum_at_most(const\
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
    \ k - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/others/subarray-sum.hpp
  requiredBy: []
  timestamp: '2026-10-23 22:04:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/others/subarray-sum.test.cpp
documentation_of: src/others/subarray-sum.hpp
layout: document
title: "\u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\u6570"
---

列 `a` の区間 $[l, r)$ ($l < r$) のうち、和がちょうど $k$ のものと $k$ 以下のものの個数を数えます。

```cpp
std::vector<long long> a = {1, 2, 3, 2, 1, 4};
long long x = count_subarrays_with_sum(a, 5LL);           // 3 ([2, 3]、[3, 2]、[1, 4])
long long y = count_subarrays_with_sum_at_most(a, 3LL);   // 7
```

`k` は列の要素と同じ型で渡します (`long long` の列なら `5LL`)。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `count_subarrays_with_sum(a, k)` | 和がちょうど `k` の区間の個数。要素は整数型であること | 要素がすべて 0 以上なら $O(n)$、そうでなければ $O(n \log n)$ |
| `count_subarrays_with_sum_at_most(a, k)` | 和が `k` 以下の区間の個数。要素は浮動小数点型でもよい | 要素がすべて 0 以上なら $O(n)$、そうでなければ $O(n \log n)$ |

- 累積和 $P$ (先頭に 0 を付けたもの) について、$l < r$ かつ $P_r - P_l \le k$ となる組を数えます。要素がすべて 0 以上なら $P$ は単調なので尺取り法で、そうでなければ [転倒数](inversion-number.hpp) と同じマージソートで数えます。
- ちょうど $k$ の個数は、($k$ 以下の個数) $-$ ($k - 1$ 以下の個数) で求めます。
- 和が $k$ 以上の個数は、(区間の総数 $n(n+1)/2$) $-$ ($k - 1$ 以下の個数) で求められます。
- $n = 10^6$ で、要素が正なら 0.04 秒、負を含むなら 0.3 秒ほどです。

## 関連

- 和が最大の区間は [連続部分列の和の最大値](../dp/maximum-subarray.hpp)
- 累積和は [vector の関数](../utility/vector_func.hpp) の `cumulative_sum`
