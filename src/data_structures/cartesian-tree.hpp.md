---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/cartesian-tree.test.cpp
    title: test/unittest/data_structures/cartesian-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree/cartesian-tree.test.cpp
    title: test/yosupo/tree/cartesian-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Cartesian \u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/cartesian-tree.hpp\"\n\n/**\n * @file\
    \ cartesian-tree.hpp\n * @brief Cartesian \u6728\n */\n\n#include <functional>\n\
    #include <vector>\n\n/**\n * @brief cartesian_tree \u306E\u623B\u308A\u5024\n\
    \ */\nstruct CartesianTree {\n    long long root;                 //!< \u6839\
    \ (\u5217\u304C\u7A7A\u306A\u3089 -1)\n    std::vector<long long> parent;  //!<\
    \ \u89AA (\u6839\u306F -1)\n    std::vector<long long> left;    //!< \u5DE6\u306E\
    \u5B50 (\u306A\u3051\u308C\u3070 -1)\n    std::vector<long long> right;   //!<\
    \ \u53F3\u306E\u5B50 (\u306A\u3051\u308C\u3070 -1)\n};\n\n/**\n * @brief \u5217\
    \ a \u306E Cartesian \u6728 (\u6700\u5C0F\u306E\u8981\u7D20\u3092\u6839\u3068\u3057\
    \u3001\u305D\u306E\u5DE6\u3068\u53F3\u306E\u90E8\u5206\u5217\u306E Cartesian \u6728\
    \u3092\u305D\u308C\u305E\u308C\u5DE6\u3068\u53F3\u306E\u5B50\u306B\u3057\u305F\
    \u4E8C\u5206\u6728) O(n)\n *\n * \u4E2D\u9593\u9806\u306B\u4E26\u3079\u308B\u3068\
    \u5143\u306E\u5217\u306B\u306A\u308B\u3002\u533A\u9593 [l, r) \u306E\u6700\u5C0F\
    \u5024\u306E\u4F4D\u7F6E\u306F\u3001l \u3068 r - 1 \u306E LCA\n * \u540C\u3058\
    \u5024\u304C\u3042\u308B\u3068\u304D\u306F\u3001\u5DE6\u306B\u3042\u308B\u3082\
    \u306E\u3092\u5148\u7956\u306B\u3059\u308B\n * @param comp \u6BD4\u8F03\u95A2\u6570\
    \u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u6700\u5927\u306E\u8981\u7D20\
    \u304C\u6839\u306B\u306A\u308B\n */\ntemplate <typename T, typename Compare =\
    \ std::less<T>>\nCartesianTree cartesian_tree(const std::vector<T>& a, Compare\
    \ comp = Compare()) {\n    const long long n = a.size();\n    CartesianTree res{-1,\
    \ std::vector<long long>(n, -1), std::vector<long long>(n, -1), std::vector<long\
    \ long>(n, -1)};\n    // \u53F3\u7AEF\u304B\u3089\u6839\u3078\u306E\u9053 (\u6839\
    \u304C\u5148\u982D)\n    std::vector<long long> stk;\n    for (long long i = 0;\
    \ i < n; i++) {\n        long long last = -1;\n        while (!stk.empty() &&\
    \ comp(a[i], a[stk.back()])) {\n            last = stk.back();\n            stk.pop_back();\n\
    \        }\n        if (last != -1) res.parent[last] = i, res.left[i] = last;\n\
    \        if (!stk.empty()) res.parent[i] = stk.back(), res.right[stk.back()] =\
    \ i;\n        stk.push_back(i);\n    }\n    if (n > 0) res.root = stk.front();\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file cartesian-tree.hpp\n * @brief Cartesian \u6728\
    \n */\n\n#include <functional>\n#include <vector>\n\n/**\n * @brief cartesian_tree\
    \ \u306E\u623B\u308A\u5024\n */\nstruct CartesianTree {\n    long long root; \
    \                //!< \u6839 (\u5217\u304C\u7A7A\u306A\u3089 -1)\n    std::vector<long\
    \ long> parent;  //!< \u89AA (\u6839\u306F -1)\n    std::vector<long long> left;\
    \    //!< \u5DE6\u306E\u5B50 (\u306A\u3051\u308C\u3070 -1)\n    std::vector<long\
    \ long> right;   //!< \u53F3\u306E\u5B50 (\u306A\u3051\u308C\u3070 -1)\n};\n\n\
    /**\n * @brief \u5217 a \u306E Cartesian \u6728 (\u6700\u5C0F\u306E\u8981\u7D20\
    \u3092\u6839\u3068\u3057\u3001\u305D\u306E\u5DE6\u3068\u53F3\u306E\u90E8\u5206\
    \u5217\u306E Cartesian \u6728\u3092\u305D\u308C\u305E\u308C\u5DE6\u3068\u53F3\u306E\
    \u5B50\u306B\u3057\u305F\u4E8C\u5206\u6728) O(n)\n *\n * \u4E2D\u9593\u9806\u306B\
    \u4E26\u3079\u308B\u3068\u5143\u306E\u5217\u306B\u306A\u308B\u3002\u533A\u9593\
    \ [l, r) \u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E\u306F\u3001l \u3068 r - 1\
    \ \u306E LCA\n * \u540C\u3058\u5024\u304C\u3042\u308B\u3068\u304D\u306F\u3001\u5DE6\
    \u306B\u3042\u308B\u3082\u306E\u3092\u5148\u7956\u306B\u3059\u308B\n * @param\
    \ comp \u6BD4\u8F03\u95A2\u6570\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\
    \u6700\u5927\u306E\u8981\u7D20\u304C\u6839\u306B\u306A\u308B\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nCartesianTree cartesian_tree(const std::vector<T>&\
    \ a, Compare comp = Compare()) {\n    const long long n = a.size();\n    CartesianTree\
    \ res{-1, std::vector<long long>(n, -1), std::vector<long long>(n, -1), std::vector<long\
    \ long>(n, -1)};\n    // \u53F3\u7AEF\u304B\u3089\u6839\u3078\u306E\u9053 (\u6839\
    \u304C\u5148\u982D)\n    std::vector<long long> stk;\n    for (long long i = 0;\
    \ i < n; i++) {\n        long long last = -1;\n        while (!stk.empty() &&\
    \ comp(a[i], a[stk.back()])) {\n            last = stk.back();\n            stk.pop_back();\n\
    \        }\n        if (last != -1) res.parent[last] = i, res.left[i] = last;\n\
    \        if (!stk.empty()) res.parent[i] = stk.back(), res.right[stk.back()] =\
    \ i;\n        stk.push_back(i);\n    }\n    if (n > 0) res.root = stk.front();\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/cartesian-tree.hpp
  requiredBy: []
  timestamp: '2026-10-23 19:15:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/cartesian-tree.test.cpp
  - test/yosupo/tree/cartesian-tree.test.cpp
documentation_of: src/data_structures/cartesian-tree.hpp
layout: document
title: "Cartesian \u6728"
---

列 `a` の Cartesian 木を $O(n)$ で作ります。最小の要素を根とし、その左の部分列と右の部分列の Cartesian 木をそれぞれ左と右の子にした二分木です。中間順に並べると元の列になり、区間 $[l, r)$ の最小値の位置は $l$ と $r - 1$ の LCA になります。

```cpp
std::vector<int> a = {3, 1, 4, 1, 5};
auto t = cartesian_tree(a);                        // 最小を根にする
long long r = t.root;                               // 1 (同じ値なら左にあるものが先祖)
long long p = t.parent[2];                          // 3
auto u = cartesian_tree(a, std::greater<int>());    // 最大を根にする
```

同じ値があるときは、左にあるものを先祖にします。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `cartesian_tree(a, comp = std::less<T>())` | 列 `a` の Cartesian 木 (`CartesianTree`)。`comp` で前に来る要素ほど根に近い | $O(n)$ |

`CartesianTree` は次の 4 つを持ちます。

| 変数 | 説明 |
|---|---|
| `root` | 根 (列が空なら -1) |
| `parent[i]` | 親 (根は -1) |
| `left[i]` | 左の子 (なければ -1) |
| `right[i]` | 右の子 (なければ -1) |

## 関連

- 区間の最小値を $O(1)$ で求めるだけなら [Sparse Table](sparse-table.hpp)
