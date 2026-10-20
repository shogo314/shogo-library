---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/lagrange-interpolation.test.cpp
    title: test/unittest/lagrange-interpolation.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (\u6A19\u672C\
      \u70B9\u304C 0, 1, ..., n-1 \u306E\u3068\u304D)"
    links: []
  bundledCode: "#line 2 \"src/math/lagrange-interpolation.hpp\"\n\n/**\n * @file lagrange-interpolation.hpp\n\
    \ * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (\u6A19\u672C\u70B9\
    \u304C 0, 1, ..., n-1 \u306E\u3068\u304D)\n */\n\n#include <vector>\n\n/**\n *\
    \ @brief n - 1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F f \u306E f(0), f(1),\
    \ ..., f(n-1) \u304B\u3089 f(x) \u3092\u6C42\u3081\u308B O(n)\n * mint \u306F\u4F53\
    \u3067\u3001n - 1 \u4EE5\u4E0B\u306E\u6B63\u306E\u6574\u6570\u304C 0 \u306B\u306A\
    \u3089\u306A\u3044\u3053\u3068 (\u6CD5\u304C n \u4EE5\u4E0A\u306E\u7D20\u6570\u306A\
    \u3069)\n * f(x) = \u03A3_i y_i \u03A0_{j != i} (x - j) / (i - j) \u3092\u3001\
    (x - j) \u306E\u524D\u5F8C\u304B\u3089\u306E\u7A4D\u3068\u968E\u4E57\u306E\u9006\
    \u6570\u3067\u8A08\u7B97\u3059\u308B\n */\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ std::vector<mint>& y, mint x) {\n    const int n = y.size();\n    if (n == 0)\
    \ return mint(0);\n    // pre[i] = \u03A0_{j < i} (x - j)\u3001suf[i] = \u03A0\
    _{j >= i} (x - j) (x \u304C\u6A19\u672C\u70B9\u3067\u3082\u3001\u81EA\u5206\u306E\
    \u56E0\u5B50\u3092\u98DB\u3070\u3059\u306E\u3067\u5272\u308A\u7B97\u306F\u3044\
    \u3089\u306A\u3044)\n    std::vector<mint> pre(n + 1, 1), suf(n + 1, 1);\n   \
    \ for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (x - i);\n    for (int i =\
    \ n - 1; i >= 0; i--) suf[i] = suf[i + 1] * (x - i);\n    // inv_fact[i] = 1 /\
    \ i!\n    std::vector<mint> inv_fact(n, 1);\n    mint fact = 1;\n    for (int\
    \ i = 1; i < n; i++) fact *= i;\n    inv_fact[n - 1] = fact.inv();\n    for (int\
    \ i = n - 1; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i;\n    mint res = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        // \u03A0_{j != i} (i - j) = i! (n\
    \ - 1 - i)! (-1)^(n - 1 - i)\n        mint t = y[i] * pre[i] * suf[i + 1] * inv_fact[i]\
    \ * inv_fact[n - 1 - i];\n        res += (n - 1 - i) % 2 == 0 ? t : -t;\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file lagrange-interpolation.hpp\n * @brief \u30E9\
    \u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593 (\u6A19\u672C\u70B9\u304C 0, 1, ...,\
    \ n-1 \u306E\u3068\u304D)\n */\n\n#include <vector>\n\n/**\n * @brief n - 1 \u6B21\
    \u4EE5\u4E0B\u306E\u591A\u9805\u5F0F f \u306E f(0), f(1), ..., f(n-1) \u304B\u3089\
    \ f(x) \u3092\u6C42\u3081\u308B O(n)\n * mint \u306F\u4F53\u3067\u3001n - 1 \u4EE5\
    \u4E0B\u306E\u6B63\u306E\u6574\u6570\u304C 0 \u306B\u306A\u3089\u306A\u3044\u3053\
    \u3068 (\u6CD5\u304C n \u4EE5\u4E0A\u306E\u7D20\u6570\u306A\u3069)\n * f(x) =\
    \ \u03A3_i y_i \u03A0_{j != i} (x - j) / (i - j) \u3092\u3001(x - j) \u306E\u524D\
    \u5F8C\u304B\u3089\u306E\u7A4D\u3068\u968E\u4E57\u306E\u9006\u6570\u3067\u8A08\
    \u7B97\u3059\u308B\n */\ntemplate <typename mint>\nmint lagrange_interpolation(const\
    \ std::vector<mint>& y, mint x) {\n    const int n = y.size();\n    if (n == 0)\
    \ return mint(0);\n    // pre[i] = \u03A0_{j < i} (x - j)\u3001suf[i] = \u03A0\
    _{j >= i} (x - j) (x \u304C\u6A19\u672C\u70B9\u3067\u3082\u3001\u81EA\u5206\u306E\
    \u56E0\u5B50\u3092\u98DB\u3070\u3059\u306E\u3067\u5272\u308A\u7B97\u306F\u3044\
    \u3089\u306A\u3044)\n    std::vector<mint> pre(n + 1, 1), suf(n + 1, 1);\n   \
    \ for (int i = 0; i < n; i++) pre[i + 1] = pre[i] * (x - i);\n    for (int i =\
    \ n - 1; i >= 0; i--) suf[i] = suf[i + 1] * (x - i);\n    // inv_fact[i] = 1 /\
    \ i!\n    std::vector<mint> inv_fact(n, 1);\n    mint fact = 1;\n    for (int\
    \ i = 1; i < n; i++) fact *= i;\n    inv_fact[n - 1] = fact.inv();\n    for (int\
    \ i = n - 1; i > 0; i--) inv_fact[i - 1] = inv_fact[i] * i;\n    mint res = 0;\n\
    \    for (int i = 0; i < n; i++) {\n        // \u03A0_{j != i} (i - j) = i! (n\
    \ - 1 - i)! (-1)^(n - 1 - i)\n        mint t = y[i] * pre[i] * suf[i + 1] * inv_fact[i]\
    \ * inv_fact[n - 1 - i];\n        res += (n - 1 - i) % 2 == 0 ? t : -t;\n    }\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/lagrange-interpolation.hpp
  requiredBy: []
  timestamp: '2026-10-20 17:46:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/lagrange-interpolation.test.cpp
documentation_of: src/math/lagrange-interpolation.hpp
layout: document
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
---

$n - 1$ 次以下の多項式 $f$ について、$f(0), f(1), \dots, f(n - 1)$ から任意の $x$ での値 $f(x)$ を $O(n)$ で求めます。「答えが $N$ の多項式になると分かっているが、$N$ が大きい」ときに、小さい $N$ で愚直に求めた値から答えを求めるのに使います。

```cpp
using mint = modint998244353;
// 1^3 + 2^3 + ... + m^3 は m の 4 次式なので、m = 0, ..., 4 の値から m = 10^12 の値が分かる
std::vector<mint> y(5);
for (int m = 0; m < 5; m++) y[m] = mint(m) * m * m + (m > 0 ? y[m - 1] : mint(0));
mint s = lagrange_interpolation(y, mint(1000000000000LL));
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `lagrange_interpolation(y, x)` | $f(0), \dots, f(n - 1)$ が `y` の $n - 1$ 次以下の多項式 $f$ の $f(x)$。`y` が空なら 0 | $O(n)$ |

- `mint` は体で、$n - 1$ 以下の正の整数が 0 にならないこと (法が $n$ 以上の素数など) が必要です。
- $f(x) = \sum_i y_i \prod_{j \ne i} (x - j) / (i - j)$ を、$(x - j)$ の前後からの積と階乗の逆数で計算します。分母は $i! (n - 1 - i)! (-1)^{n - 1 - i}$ です。$x$ が標本点 ($0$ 以上 $n$ 未満の整数) でも正しく計算できます。

## 関連

- 線形漸化式を満たす数列の遠くの項は [線形漸化式](linear-recurrence.hpp)
