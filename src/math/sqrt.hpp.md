---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate-quotients.test.cpp
    title: test/yosupo/enumerate-quotients.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6574\u6570\u306E\u5E73\u65B9\u6839"
    links: []
  bundledCode: "#line 2 \"src/math/sqrt.hpp\"\n\n/**\n * @file sqrt.hpp\n * @brief\
    \ \u6574\u6570\u306E\u5E73\u65B9\u6839\n */\n\n/**\n * @brief floor(sqrt(n))\n\
    \ * @param n \u5E73\u65B9\u6839\u3092\u6C42\u3081\u305F\u3044\u6574\u6570 long\
    \ long \u578B\u3067 0 <= n < 2^63 \u3092\u6E80\u305F\u3059\n * @return long long\n\
    \ */\ninline long long sqrtll(long long n) { \n    // 3037000500 = ceil(sqrt(2^63))\n\
    \    long long le = 0, ri = 3037000500; \n    while(ri - le > 1) {\n        long\
    \ long mid = (le + ri) / 2;\n        if(mid * mid <= n) le = mid;\n        else\
    \ ri = mid;\n    }\n    return le;\n}\n"
  code: "#pragma once\n\n/**\n * @file sqrt.hpp\n * @brief \u6574\u6570\u306E\u5E73\
    \u65B9\u6839\n */\n\n/**\n * @brief floor(sqrt(n))\n * @param n \u5E73\u65B9\u6839\
    \u3092\u6C42\u3081\u305F\u3044\u6574\u6570 long long \u578B\u3067 0 <= n < 2^63\
    \ \u3092\u6E80\u305F\u3059\n * @return long long\n */\ninline long long sqrtll(long\
    \ long n) { \n    // 3037000500 = ceil(sqrt(2^63))\n    long long le = 0, ri =\
    \ 3037000500; \n    while(ri - le > 1) {\n        long long mid = (le + ri) /\
    \ 2;\n        if(mid * mid <= n) le = mid;\n        else ri = mid;\n    }\n  \
    \  return le;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/math/sqrt.hpp
  requiredBy: []
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate-quotients.test.cpp
documentation_of: src/math/sqrt.hpp
layout: document
title: "\u6574\u6570\u306E\u5E73\u65B9\u6839"
---

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sqrtll(n)` | $\lfloor \sqrt{n} \rfloor$ ($0 \le n < 2^{63}$)。浮動小数点の誤差なしで求める | $O(\log n)$ |

```cpp
long long r = sqrtll(1000000000000000000LL);  // 1000000000
long long s = sqrtll(15);                      // 3
```
