---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/divisor-transform.test.cpp
    title: test/unittest/divisor-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd-convolution.test.cpp
    title: test/yosupo/gcd-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lcm-convolution.test.cpp
    title: test/yosupo/lcm-convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D04\u6570\u30FB\u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB\
      \u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068 GCD\u30FBLCM \u7573\u307F\u8FBC\
      \u307F"
    links: []
  bundledCode: "#line 2 \"src/math/divisor-transform.hpp\"\n\n/**\n * @file divisor-transform.hpp\n\
    \ * @brief \u7D04\u6570\u30FB\u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3001\
    \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068 GCD\u30FBLCM \u7573\u307F\u8FBC\u307F\
    \n */\n\n#include <cassert>\n#include <vector>\n\nnamespace internal_divisor_transform\
    \ {\n// n \u4EE5\u4E0B\u306E\u7D20\u6570 (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u7BE9)\ninline std::vector<int> primes(int n) {\n    std::vector<bool>\
    \ composite(n + 1);\n    std::vector<int> res;\n    for (int i = 2; i <= n; i++)\
    \ {\n        if (composite[i]) continue;\n        res.push_back(i);\n        for\
    \ (long long j = (long long)i * i; j <= n; j += i) composite[j] = true;\n    }\n\
    \    return res;\n}\n}  // namespace internal_divisor_transform\n\n/**\n * @brief\
    \ \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{d | n} a[d] O(N\
    \ log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002\
    a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid divisor_zeta(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : internal_divisor_transform::primes(n))\
    \ {\n        for (int i = 1; i <= n / p; i++) a[i * p] += a[i];\n    }\n}\n\n\
    /**\n * @brief \u7D04\u6570\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (divisor_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size()\
    \ - 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate\
    \ <typename T>\nvoid divisor_mobius(std::vector<T>& a) {\n    int n = (int)a.size()\
    \ - 1;\n    for (int p : internal_divisor_transform::primes(n)) {\n        for\
    \ (int i = n / p; i >= 1; i--) a[i * p] -= a[i];\n    }\n}\n\n/**\n * @brief \u500D\
    \u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{n | m, m <= N} a[m] O(N\
    \ log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002\
    a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid multiple_zeta(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : internal_divisor_transform::primes(n))\
    \ {\n        for (int i = n / p; i >= 1; i--) a[i] += a[i * p];\n    }\n}\n\n\
    /**\n * @brief \u500D\u6570\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (multiple_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size()\
    \ - 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate\
    \ <typename T>\nvoid multiple_mobius(std::vector<T>& a) {\n    int n = (int)a.size()\
    \ - 1;\n    for (int p : internal_divisor_transform::primes(n)) {\n        for\
    \ (int i = 1; i <= n / p; i++) a[i] -= a[i * p];\n    }\n}\n\n/**\n * @brief GCD\
    \ \u7573\u307F\u8FBC\u307F c[k] = sum_{gcd(i, j) = k} a[i] b[j] (1 <= i, j <=\
    \ N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N + 1 \u3067\
    \u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002c[0] \u306F T()\n */\n\
    template <typename T>\nstd::vector<T> gcd_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    multiple_zeta(a);\n    multiple_zeta(b);\n\
    \    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n    multiple_mobius(a);\n\
    \    if (!a.empty()) a[0] = T();\n    return a;\n}\n\n/**\n * @brief LCM \u7573\
    \u307F\u8FBC\u307F c[k] = sum_{lcm(i, j) = k} a[i] b[j] (1 <= i, j <= N\u3001\
    k <= N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N + 1 \u3067\
    \u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002c[0] \u306F T()\u3002\
    lcm \u304C N \u3092\u8D85\u3048\u308B\u7D44\u306F\u6570\u3048\u306A\u3044\n */\n\
    template <typename T>\nstd::vector<T> lcm_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    divisor_zeta(a);\n    divisor_zeta(b);\n\
    \    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n    divisor_mobius(a);\n\
    \    if (!a.empty()) a[0] = T();\n    return a;\n}\n"
  code: "#pragma once\n\n/**\n * @file divisor-transform.hpp\n * @brief \u7D04\u6570\
    \u30FB\u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3001\u30E1\u30D3\u30A6\
    \u30B9\u5909\u63DB\u3068 GCD\u30FBLCM \u7573\u307F\u8FBC\u307F\n */\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace internal_divisor_transform {\n// n\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570 (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9)\ninline std::vector<int> primes(int n) {\n    std::vector<bool> composite(n\
    \ + 1);\n    std::vector<int> res;\n    for (int i = 2; i <= n; i++) {\n     \
    \   if (composite[i]) continue;\n        res.push_back(i);\n        for (long\
    \ long j = (long long)i * i; j <= n; j += i) composite[j] = true;\n    }\n   \
    \ return res;\n}\n}  // namespace internal_divisor_transform\n\n/**\n * @brief\
    \ \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{d | n} a[d] O(N\
    \ log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002\
    a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid divisor_zeta(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : internal_divisor_transform::primes(n))\
    \ {\n        for (int i = 1; i <= n / p; i++) a[i * p] += a[i];\n    }\n}\n\n\
    /**\n * @brief \u7D04\u6570\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (divisor_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size()\
    \ - 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate\
    \ <typename T>\nvoid divisor_mobius(std::vector<T>& a) {\n    int n = (int)a.size()\
    \ - 1;\n    for (int p : internal_divisor_transform::primes(n)) {\n        for\
    \ (int i = n / p; i >= 1; i--) a[i * p] -= a[i];\n    }\n}\n\n/**\n * @brief \u500D\
    \u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{n | m, m <= N} a[m] O(N\
    \ log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002\
    a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid multiple_zeta(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : internal_divisor_transform::primes(n))\
    \ {\n        for (int i = n / p; i >= 1; i--) a[i] += a[i * p];\n    }\n}\n\n\
    /**\n * @brief \u500D\u6570\u306E\u30E1\u30D3\u30A6\u30B9\u5909\u63DB (multiple_zeta\
    \ \u306E\u9006\u5909\u63DB) O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size()\
    \ - 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate\
    \ <typename T>\nvoid multiple_mobius(std::vector<T>& a) {\n    int n = (int)a.size()\
    \ - 1;\n    for (int p : internal_divisor_transform::primes(n)) {\n        for\
    \ (int i = 1; i <= n / p; i++) a[i] -= a[i * p];\n    }\n}\n\n/**\n * @brief GCD\
    \ \u7573\u307F\u8FBC\u307F c[k] = sum_{gcd(i, j) = k} a[i] b[j] (1 <= i, j <=\
    \ N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N + 1 \u3067\
    \u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002c[0] \u306F T()\n */\n\
    template <typename T>\nstd::vector<T> gcd_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    multiple_zeta(a);\n    multiple_zeta(b);\n\
    \    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n    multiple_mobius(a);\n\
    \    if (!a.empty()) a[0] = T();\n    return a;\n}\n\n/**\n * @brief LCM \u7573\
    \u307F\u8FBC\u307F c[k] = sum_{lcm(i, j) = k} a[i] b[j] (1 <= i, j <= N\u3001\
    k <= N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055 N + 1 \u3067\
    \u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002c[0] \u306F T()\u3002\
    lcm \u304C N \u3092\u8D85\u3048\u308B\u7D44\u306F\u6570\u3048\u306A\u3044\n */\n\
    template <typename T>\nstd::vector<T> lcm_convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n    assert(a.size() == b.size());\n    divisor_zeta(a);\n    divisor_zeta(b);\n\
    \    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n    divisor_mobius(a);\n\
    \    if (!a.empty()) a[0] = T();\n    return a;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/divisor-transform.hpp
  requiredBy: []
  timestamp: '2026-10-14 01:43:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/divisor-transform.test.cpp
  - test/yosupo/gcd-convolution.test.cpp
  - test/yosupo/lcm-convolution.test.cpp
documentation_of: src/math/divisor-transform.hpp
layout: document
title: "\u7D04\u6570\u30FB\u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3001\u30E1\
  \u30D3\u30A6\u30B9\u5909\u63DB\u3068 GCD\u30FBLCM \u7573\u307F\u8FBC\u307F"
---

添字の約数・倍数の関係で和をとる変換と、その逆変換です。配列 `a` の添字 $1, \dots, N$ ($N$ = `a.size() - 1`) を使い、`a[0]` は使いません。値の型 `T` は `+`、`-`、`*` が使えれば何でもよく、`long long` や modint を想定しています。

素数 $p$ ごとに「$i$ と $ip$ の間で足す」ことを繰り返すので、どれも $O(N \log \log N)$ です。

| 関数 | 説明 |
|---|---|
| `divisor_zeta(a)` | $a_n \leftarrow \sum_{d \mid n} a_d$ (その場で書き換える) |
| `divisor_mobius(a)` | `divisor_zeta` の逆変換 |
| `multiple_zeta(a)` | $a_n \leftarrow \sum_{n \mid m,\ m \le N} a_m$ (その場で書き換える) |
| `multiple_mobius(a)` | `multiple_zeta` の逆変換 |
| `gcd_convolution(a, b)` | $c_k = \sum_{\gcd(i, j) = k} a_i b_j$ ($1 \le i, j \le N$) を返す。`a` と `b` は同じ長さ |
| `lcm_convolution(a, b)` | $c_k = \sum_{\mathrm{lcm}(i, j) = k} a_i b_j$ ($k \le N$) を返す。lcm が $N$ を超える組は数えない |

```cpp
std::vector<long long> a = {0, 1, 2, 3, 4}, b = {0, 5, 6, 7, 8};
auto g = gcd_convolution(a, b);  // {0, 155, 52, 21, 32}
auto l = lcm_convolution(a, b);  // {0, 5, 28, 43, 100}
```

## 例: gcd が k の組の個数

$1 \le x, y \le N$ で $\gcd(x, y) = k$ となる組の個数は、`cnt[d]` を「$d$ の倍数の組の個数」$\lfloor N / d \rfloor^2$ にしてから、倍数のメビウス変換をすると求められます。

```cpp
std::vector<long long> cnt(n + 1);
for (int d = 1; d <= n; d++) cnt[d] = (long long)(n / d) * (n / d);
multiple_mobius(cnt);  // cnt[k] = gcd(x, y) = k となる組の個数
```

配列の値の gcd についても同じで、値ごとの個数を `cnt` に入れて `multiple_zeta` すると、`cnt[d]` は $d$ の倍数の個数になります。

## 関連

- 素数の列挙や素因数分解は [素数](prime.hpp)
