---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/prime-counting.test.cpp
    title: test/unittest/prime-counting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/quotients.test.cpp
    title: test/unittest/quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate-quotients.2.test.cpp
    title: test/yosupo/enumerate-quotients.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5546\u306E\u5217\u6319 (floor(n / i) \u304C\u540C\u3058\u5024\
      \u306B\u306A\u308B i \u306E\u533A\u9593)"
    links: []
  bundledCode: "#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n\
    \ * @brief \u5546\u306E\u5217\u6319 (floor(n / i) \u304C\u540C\u3058\u5024\u306B\
    \u306A\u308B i \u306E\u533A\u9593)\n */\n\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief \u5546 q = floor(n / i) \u3068\u3001\u305D\u308C\u3092\u3068\u308B\
    \ i \u306E\u533A\u9593 [l, r]\n */\nstruct QuotientRange {\n    long long q; \
    \ //!< \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080\
    )\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u3080)\n};\n\n\
    /**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\u9593\
    \u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806) \u306B\
    \ f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i <= r \u306A\u3089 floor(n\
    \ / i) == q\n */\ntemplate <typename F>\nvoid for_each_quotient(long long n, F\
    \ f) {\n    assert(n >= 0);\n    for (long long l = 1; l <= n;) {\n        long\
    \ long q = n / l, r = n / q;\n        f(q, l, r);\n        l = r + 1;\n    }\n\
    }\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\u6607\u9806\u3001\u3064\u307E\
    \u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\u9593\u306E\u500B\u6570\u306F\
    \ 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange> enumerate_quotients(long\
    \ long n) {\n    std::vector<QuotientRange> res;\n    for_each_quotient(n, [&](long\
    \ long q, long long l, long long r) { res.push_back({q, l, r}); });\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n/**\n * @file quotients.hpp\n * @brief \u5546\u306E\u5217\
    \u6319 (floor(n / i) \u304C\u540C\u3058\u5024\u306B\u306A\u308B i \u306E\u533A\
    \u9593)\n */\n\n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u5546\
    \ q = floor(n / i) \u3068\u3001\u305D\u308C\u3092\u3068\u308B i \u306E\u533A\u9593\
    \ [l, r]\n */\nstruct QuotientRange {\n    long long q;  //!< \u5546\n    long\
    \ long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080)\n    long long r;\
    \  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u3080)\n};\n\n/**\n * @brief i\
    \ = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\u3051\
    \u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806) \u306B f(q, l, r) \u3092\
    \u547C\u3076 O(sqrt(n))\n * l <= i <= r \u306A\u3089 floor(n / i) == q\n */\n\
    template <typename F>\nvoid for_each_quotient(long long n, F f) {\n    assert(n\
    \ >= 0);\n    for (long long l = 1; l <= n;) {\n        long long q = n / l, r\
    \ = n / q;\n        f(q, l, r);\n        l = r + 1;\n    }\n}\n\n/**\n * @brief\
    \ i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\
    \u3051\u305F\u3082\u306E (i \u306E\u6607\u9806\u3001\u3064\u307E\u308A\u5546\u306E\
    \u964D\u9806) O(sqrt(n))\n * \u533A\u9593\u306E\u500B\u6570\u306F 2 sqrt(n) \u4EE5\
    \u4E0B\n */\ninline std::vector<QuotientRange> enumerate_quotients(long long n)\
    \ {\n    std::vector<QuotientRange> res;\n    for_each_quotient(n, [&](long long\
    \ q, long long l, long long r) { res.push_back({q, l, r}); });\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/quotients.hpp
  requiredBy: []
  timestamp: '2026-10-14 03:19:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/quotients.test.cpp
  - test/unittest/prime-counting.test.cpp
  - test/yosupo/enumerate-quotients.2.test.cpp
documentation_of: src/math/quotients.hpp
layout: document
title: "\u5546\u306E\u5217\u6319"
---

$i = 1, 2, \dots, n$ を、商 $\lfloor n / i \rfloor$ が同じ値になる区間に分けます。商がとる値は $O(\sqrt{n})$ 種類しかないので (区間の個数は $2\sqrt{n}$ 以下)、$\sum_{i=1}^{n} f(\lfloor n/i \rfloor)$ のような和を、区間ごとにまとめて $O(\sqrt{n})$ で計算できます。

例えば $n = 10$ では、次の 5 つの区間に分かれます。

| 商 `q` | 10 | 5 | 3 | 2 | 1 |
|---|---|---|---|---|---|
| 区間 `[l, r]` | [1, 1] | [2, 2] | [3, 3] | [4, 5] | [6, 10] |

```cpp
// sum_{i=1}^{n} floor(n / i) (= 約数の個数の和 d(1) + ... + d(n))
long long sum = 0;
for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l + 1); });

for (auto [q, l, r] : enumerate_quotients(10)) {
    // (10, 1, 1), (5, 2, 2), (3, 3, 3), (2, 4, 5), (1, 6, 10) の順
}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `for_each_quotient(n, f)` | 区間ごとに `f(q, l, r)` を呼ぶ。$l \le i \le r$ なら $\lfloor n/i \rfloor = q$ | $O(\sqrt{n})$ |
| `enumerate_quotients(n)` | 区間を `QuotientRange` (メンバ `q`、`l`、`r`) のリストで返す | $O(\sqrt{n})$ |

- 区間 `[l, r]` は右端を含む閉区間です (このライブラリの他の区間は半開区間 `[l, r)` ですが、ここでは $r = \lfloor n/q \rfloor$ がそのまま求まるので閉区間にしています)。区間の長さは `r - l + 1` です。
- どちらも $i$ の昇順 (商の降順) に並びます。商の昇順が欲しいときは逆にたどります。
- 区間の右端は $r = \lfloor n / \lfloor n/l \rfloor \rfloor$ で求めています。

## 使い方の例

- $\sum_{i=1}^{n} i \lfloor n/i \rfloor$ (約数の和の総和): 区間ごとに $q \cdot (l + \dots + r)$ を足します。
- $\sum_{i=1}^{n} (n \bmod i)$: $n \bmod i = n - i \lfloor n/i \rfloor$ なので、$n^2$ から上の和を引きます。

## 関連

- 一次関数の床関数の和 $\sum \lfloor (ai + b)/m \rfloor$ は [floor sum](floor-sum.hpp)
- すべての $\lfloor n / k \rfloor$ について素数の個数・和を求めるには [素数の個数・素数の和](prime-counting.hpp)
