---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/circular-sum.test.cpp
    title: test/unittest/data_structures/circular-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/geometry/polygon-centroid.test.cpp
    title: test/unittest/geometry/polygon-centroid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5186\u74B0\u4E0A\u306E\u533A\u9593\u548C"
    links: []
  bundledCode: "#line 2 \"src/data_structures/circular-sum.hpp\"\n\n/**\n * @file\
    \ circular-sum.hpp\n * @brief \u5186\u74B0\u4E0A\u306E\u533A\u9593\u548C\n */\n\
    \n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u5186\u74B0\u4E0A\u306E\
    \u533A\u9593\u548C\n *\n * \u5186\u74B0\u306B\u4E26\u3093\u3060 a[0], ..., a[n-1]\
    \ \u306E\u533A\u9593\u548C\u3092 O(1) \u3067\u6C42\u3081\u308B (static)\n * \u4F8B\
    :\n * CircularSum cs(a);\n * cs.sum(l, r);       // l <= r \u306A\u3089 a[l] +\
    \ ... + a[r-1]\n * cs.sum(n - 1, 3);   // r < l \u306A\u3089 1 \u5468\u307E\u305F\
    \u3050: a[n-1] + a[0] + a[1] + a[2]\n *\n * @tparam T \u5024\u306E\u578B\u3002\
    T{} \u304C 0 \u3067\u3001+ \u3068 - \u304C\u4F7F\u3048\u308C\u3070\u3088\u3044\
    \n */\ntemplate <typename T>\nclass CircularSum {\n   private:\n    long long\
    \ n;\n    // s[i] = a[0] + ... + a[i-1]\n    std::vector<T> s;\n\n   public:\n\
    \    explicit CircularSum(const std::vector<T>& v) : n(v.size()), s(n + 1, T{})\
    \ {\n        for (long long i = 0; i < n; i++) s[i + 1] = s[i] + v[i];\n    }\n\
    \n    long long size() const { return n; }\n\n    /**\n     * @brief l \u304B\u3089\
    \u6642\u8A08\u56DE\u308A\u306B r \u306E\u624B\u524D\u307E\u3067\u306E\u548C O(1)\n\
    \     * l <= r \u306A\u3089 [l, r)\u3001r < l \u306A\u3089 [l, n) \u3068 [0, r)\u3002\
    l == r \u306F\u7A7A (0)\n     * @pre 0 <= l, r <= n\n     */\n    T sum(long long\
    \ l, long long r) const {\n        assert(0 <= l && l <= n && 0 <= r && r <= n);\n\
    \        if (l <= r) return s[r] - s[l];\n        return s[n] - s[l] + s[r];\n\
    \    }\n    /**\n     * @brief 1 \u5468\u5206\u306E\u548C O(1)\n     */\n    T\
    \ all_sum() const { return s[n]; }\n};\n"
  code: "#pragma once\n\n/**\n * @file circular-sum.hpp\n * @brief \u5186\u74B0\u4E0A\
    \u306E\u533A\u9593\u548C\n */\n\n#include <cassert>\n#include <vector>\n\n/**\n\
    \ * @brief \u5186\u74B0\u4E0A\u306E\u533A\u9593\u548C\n *\n * \u5186\u74B0\u306B\
    \u4E26\u3093\u3060 a[0], ..., a[n-1] \u306E\u533A\u9593\u548C\u3092 O(1) \u3067\
    \u6C42\u3081\u308B (static)\n * \u4F8B:\n * CircularSum cs(a);\n * cs.sum(l, r);\
    \       // l <= r \u306A\u3089 a[l] + ... + a[r-1]\n * cs.sum(n - 1, 3);   //\
    \ r < l \u306A\u3089 1 \u5468\u307E\u305F\u3050: a[n-1] + a[0] + a[1] + a[2]\n\
    \ *\n * @tparam T \u5024\u306E\u578B\u3002T{} \u304C 0 \u3067\u3001+ \u3068 -\
    \ \u304C\u4F7F\u3048\u308C\u3070\u3088\u3044\n */\ntemplate <typename T>\nclass\
    \ CircularSum {\n   private:\n    long long n;\n    // s[i] = a[0] + ... + a[i-1]\n\
    \    std::vector<T> s;\n\n   public:\n    explicit CircularSum(const std::vector<T>&\
    \ v) : n(v.size()), s(n + 1, T{}) {\n        for (long long i = 0; i < n; i++)\
    \ s[i + 1] = s[i] + v[i];\n    }\n\n    long long size() const { return n; }\n\
    \n    /**\n     * @brief l \u304B\u3089\u6642\u8A08\u56DE\u308A\u306B r \u306E\
    \u624B\u524D\u307E\u3067\u306E\u548C O(1)\n     * l <= r \u306A\u3089 [l, r)\u3001\
    r < l \u306A\u3089 [l, n) \u3068 [0, r)\u3002l == r \u306F\u7A7A (0)\n     * @pre\
    \ 0 <= l, r <= n\n     */\n    T sum(long long l, long long r) const {\n     \
    \   assert(0 <= l && l <= n && 0 <= r && r <= n);\n        if (l <= r) return\
    \ s[r] - s[l];\n        return s[n] - s[l] + s[r];\n    }\n    /**\n     * @brief\
    \ 1 \u5468\u5206\u306E\u548C O(1)\n     */\n    T all_sum() const { return s[n];\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/circular-sum.hpp
  requiredBy: []
  timestamp: '2026-10-31 15:34:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/geometry/polygon-centroid.test.cpp
  - test/unittest/data_structures/circular-sum.test.cpp
documentation_of: src/data_structures/circular-sum.hpp
layout: document
title: "\u5186\u74B0\u4E0A\u306E\u533A\u9593\u548C"
---

円環に並んだ $a_0, \dots, a_{n-1}$ の区間和を $O(1)$ で求めます (static)。終わりが始まりより前なら、1 周またぐ区間として扱います。

```cpp
CircularSum cs(std::vector<long long>{1, 2, 3, 4, 5});
cs.sum(1, 3);   // 2 + 3 = 5
cs.sum(4, 2);   // 5 + 1 + 2 = 8 (1 周またぐ)
cs.sum(2, 2);   // 0
cs.all_sum();   // 15
```

値の型は、`T{}` が 0 で `+` と `-` が使えれば何でもかまいません。複数の量の和を同時に取りたいときは、`Vector<long long, 3>` のような成分ごとに足せる型を使うと 1 本にまとめられます。

## 注意

- 区間は半開区間です。閉区間 $[l, r]$ の和は `sum(l, r + 1)` です ($r = n - 1$ なら `sum(l, n)` です)。
- `sum(l, l)` は空 (0) です。1 周分は `all_sum()` か `sum(0, n)` で取ります。
- 何周もする区間や負の添字は扱いません。必要なら `divmod` ([base/functions.hpp](../base/functions.hpp)) を使って、次のように書けます。

```cpp
// 列 a[i mod n] の [l, r) の和 (l <= r、負でもよい)
auto f = [&](long long i) { auto [q, m] = divmod(i, n); return q * cs.all_sum() + cs.sum(0, m); };
f(r) - f(l);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CircularSum(v)` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `sum(l, r)` | `l <= r` なら $[l, r)$ の和、`r < l` なら $[l, n)$ と $[0, r)$ の和 ($0 \le l, r \le n$) | $O(1)$ |
| `all_sum()` | 1 周分の和 | $O(1)$ |

## 関連

- 円環でない列の累積和は `cumulative_sum` ([utility/vector_func.hpp](../utility/vector_func.hpp))
- 途中からループする配列は [おたまじゃくし配列](tadpole-array.hpp)
