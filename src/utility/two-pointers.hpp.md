---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/others/subarray-sum.hpp
    title: "\u548C\u304C\u6761\u4EF6\u3092\u6E80\u305F\u3059\u533A\u9593\u306E\u500B\
      \u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/others/subarray-sum.test.cpp
    title: test/unittest/others/subarray-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/utility/two-pointers.test.cpp
    title: test/unittest/utility/two-pointers.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5C3A\u53D6\u308A\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/utility/two-pointers.hpp\"\n\n/**\n * @file two-pointers.hpp\n\
    \ * @brief \u5C3A\u53D6\u308A\u6CD5\n */\n\n#include <vector>\n\n/**\n * @brief\
    \ \u5C3A\u53D6\u308A\u6CD5\u3067\u3001\u5404 l \u306B\u3064\u3044\u3066\u533A\u9593\
    \ [l, r) \u3092\u53F3\u306B\u4F38\u3070\u305B\u308B\u3060\u3051\u4F38\u3070\u3057\
    \u305F r \u3092\u6C42\u3081\u308B\n *\n * can_add(l, r) \u306F\u3001\u3044\u307E\
    \u306E\u533A\u9593 [l, r) \u306B r \u3092\u52A0\u3048\u3066\u3082\u3088\u3044\u304B\
    \u3092\u8FD4\u3059\u3002add(r) \u306F r \u3092\u52A0\u3048\u305F\u3068\u304D\u3001\
    erase(l) \u306F l \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306B\u547C\
    \u3070\u308C\u308B\n * [l, r) \u306B r \u3092\u52A0\u3048\u3066\u3088\u3044\u306A\
    \u3089 [l + 1, r) \u306B\u3082\u52A0\u3048\u3066\u3088\u3044 (\u533A\u9593\u3092\
    \u5DE6\u304B\u3089\u7E2E\u3081\u3066\u3082\u6761\u4EF6\u304C\u5D29\u308C\u306A\
    \u3044) \u3053\u3068\n * can_add(l, l) \u304C\u507D\u306A\u3089\u3001\u533A\u9593\
    \u306F\u7A7A\u306E\u307E\u307E r = l \u306B\u306A\u308B\u3002\u7A7A\u306E\u533A\
    \u9593\u304B\u3089\u306F\u4F55\u3082\u53D6\u308A\u9664\u304B\u306A\u3044\n *\n\
    \ * \u5186\u74B0\u306E\u5217\u306F\u30011 \u5468\u305A\u3089\u3057\u305F\u5199\
    \u3057\u3092\u5F8C\u308D\u306B\u3064\u306A\u3052\u305F\u9577\u3055 2n \u306E\u5217\
    \u306B\u4F7F\u3044\u3001l < n \u306E\u5206\u3092\u898B\u308B\n *\n * @param n\
    \ \u5217\u306E\u9577\u3055\n * @return \u9577\u3055 n \u306E\u5217\u3002l \u756A\
    \u76EE\u306F [l, r) \u3092\u4F38\u3070\u3057\u7D42\u3048\u305F\u3068\u304D\u306E\
    \ r\n */\ntemplate <class CanAdd, class Add, class Erase>\nstd::vector<long long>\
    \ two_pointers(long long n, CanAdd can_add, Add add, Erase erase) {\n    std::vector<long\
    \ long> res(n);\n    long long r = 0;\n    for (long long l = 0; l < n; l++) {\n\
    \        if (r < l) r = l;\n        while (r < n && can_add(l, r)) add(r++);\n\
    \        res[l] = r;\n        if (l < r) erase(l);\n    }\n    return res;\n}\n\
    \n/**\n * @brief \u72B6\u614B\u3092\u6301\u305F\u306A\u3044\u5C3A\u53D6\u308A\u6CD5\
    \ (can_add(l, r) \u304C l \u3068 r \u3060\u3051\u3067\u6C7A\u307E\u308B\u3068\u304D\
    )\n */\ntemplate <class CanAdd>\nstd::vector<long long> two_pointers(long long\
    \ n, CanAdd can_add) {\n    return two_pointers(n, can_add, [](long long) {},\
    \ [](long long) {});\n}\n"
  code: "#pragma once\n\n/**\n * @file two-pointers.hpp\n * @brief \u5C3A\u53D6\u308A\
    \u6CD5\n */\n\n#include <vector>\n\n/**\n * @brief \u5C3A\u53D6\u308A\u6CD5\u3067\
    \u3001\u5404 l \u306B\u3064\u3044\u3066\u533A\u9593 [l, r) \u3092\u53F3\u306B\u4F38\
    \u3070\u305B\u308B\u3060\u3051\u4F38\u3070\u3057\u305F r \u3092\u6C42\u3081\u308B\
    \n *\n * can_add(l, r) \u306F\u3001\u3044\u307E\u306E\u533A\u9593 [l, r) \u306B\
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
    \    return two_pointers(n, can_add, [](long long) {}, [](long long) {});\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/two-pointers.hpp
  requiredBy:
  - src/others/subarray-sum.hpp
  timestamp: '2026-10-24 23:17:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/utility/two-pointers.test.cpp
  - test/unittest/others/subarray-sum.test.cpp
documentation_of: src/utility/two-pointers.hpp
layout: document
title: "\u5C3A\u53D6\u308A\u6CD5"
---

尺取り法で、各 $l$ について区間 $[l, r)$ を右に伸ばせるだけ伸ばした $r$ を求めます。区間の状態は、加える・取り除くときに呼ばれる関数で更新します。

```cpp
std::vector<long long> a = {1, 2, 3, 2, 1, 4};

// 各 l から、和が 5 以下のまま右に伸ばせる r
long long s = 0;
auto r = two_pointers(
    a.size(), [&](long long l, long long r) { return s + a[r] <= 5; },  // [l, r) に r を加えてよいか
    [&](long long r) { s += a[r]; },                                     // r を加えた
    [&](long long l) { s -= a[l]; });                                    // l を取り除いた
// r = {2, 3, 4, 5, 6, 6}

// 状態を持たないなら can_add だけでよい (ソートした列で差が 2 以下)
std::vector<long long> b = {1, 2, 4, 5, 6};
auto r2 = two_pointers(b.size(), [&](long long l, long long r) { return b[r] - b[l] <= 2; });  // {2, 3, 5, 5, 5}

// 円環は 1 周ずらした写しを後ろにつなげ、l < n の分を見る (周の長さ 10 で、時計回りに幅 3 未満にある点の数)
std::vector<long long> c = {0, 4, 8, 9};
int n = c.size();
for (int i = 0; i < n; i++) c.push_back(c[i] + 10);
auto r3 = two_pointers(2 * n, [&](long long l, long long r) { return c[r] - c[l] < 3; });
// r3[l] - l = {1, 1, 3, 2}
```

- [l, r) に r を加えてよいなら [l + 1, r) にも加えてよい (区間を左から縮めても条件が崩れない) ことが必要です。
- `can_add(l, l)` が偽なら区間は空のまま $r = l$ になります。空の区間からは何も取り除きません。
- 円環で写しをつなげるとき、区間の幅が 1 周未満になる条件にすれば、同じ要素を二重に数えることはありません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `two_pointers(n, can_add, add, erase)` | 長さ `n` の列で、各 $l$ について $[l, r)$ を伸ばし終えたときの $r$ を並べた長さ `n` の列を返す。`can_add(l, r)` は $[l, r)$ に $r$ を加えてよいか、`add(r)`・`erase(l)` は加えた・取り除いたときに呼ばれる | `can_add` が $O(n)$ 回、`add`・`erase` が $n$ 回以下 |
| `two_pointers(n, can_add)` | 状態を持たない版 (`can_add(l, r)` が $l$ と $r$ だけで決まるとき) | `can_add` が $O(n)$ 回 |

## 関連

- 和が条件を満たす区間の個数は [和が条件を満たす区間の個数](../others/subarray-sum.hpp)
- 答えで二分探索をするなら [二分探索](binary-search.hpp)
