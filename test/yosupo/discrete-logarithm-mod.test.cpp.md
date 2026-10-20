---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/discrete_logarithm_mod
    links:
    - https://judge.yosupo.jp/problem/discrete_logarithm_mod
  bundledCode: "#line 1 \"test/yosupo/discrete-logarithm-mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\n\n#include <iostream>\n\
    \n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file modular-arithmetic.hpp\n\
    \ * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
    \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <numeric>\n#include <unordered_map>\n\n\
    /**\n * @brief a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\
    \u4F7F\u3046\u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n\
    \ */\nconstexpr long long modmul(long long a, long long b, long long m) {\n  \
    \  long long res = static_cast<long long>(static_cast<__int128>(a) * b % m);\n\
    \    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief a^(-1) mod m\
    \ \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\
    \u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long long\
    \ a, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n\
    \    long long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap \u306F\
    \ C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\u308F\
    \u305A\u306B\u66F8\u304F\n        long long t = a / b;\n        long long c =\
    \ a - t * b;\n        a = b, b = c;\n        long long w = u - t * v;\n      \
    \  u = v, v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\");\n\
    \    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n mod\
    \ m \u3092\u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E -n \u4E57\
    \ (a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068)\u3002\
    O(log |n|)\n */\nconstexpr long long modpow(long long a, long long n, long long\
    \ m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    if (n <\
    \ 0) {\n        n = -n;\n        a = modinv(a, m);\n    }\n    long long res =\
    \ 1 % m;\n    while (n > 0) {\n        if (n & 1) res = modmul(res, a, m);\n \
    \       a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n}\n\n\
    /**\n * @brief a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E x >=\
    \ 0 (\u306A\u3051\u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\
    \u7D20\u3067\u306A\u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step \u3067\
    \ O(\u221Am) \u306E\u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long long\
    \ discrete_log(long long a, long long b, long long m) {\n    assert(m >= 1);\n\
    \    a %= m, b %= m;\n    if (a < 0) a += m;\n    if (b < 0) b += m;\n    if (m\
    \ == 1) return 0;\n    // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\
    \u308B\u307E\u3067\u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add / (\u5272\
    \u3063\u305F gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0, g;\n    while\
    \ ((g = std::gcd(a, m)) > 1) {\n        if (b == k) return add;\n        if (b\
    \ % g != 0) return -1;\n        b /= g, m /= g, add++;\n        k = modmul(k,\
    \ a / g, m);\n    }\n    // k a^x \u2261 b \u3092 x = n p - q (1 <= p <= n\u3001\
    0 <= q <= n) \u3068\u66F8\u3044\u3066\u89E3\u304F\n    const long long n = static_cast<long\
    \ long>(std::sqrt(static_cast<long double>(m))) + 1;\n    std::unordered_map<long\
    \ long, long long> baby;\n    baby.reserve(2 * n + 2);\n    // b a^q \u3092 q\
    \ \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\u3001\u540C\u3058\u5024\u306A\
    \u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\u3059\u308B (x \u3092\u5C0F\
    \u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long long q = 0, cur = b; q <=\
    \ n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n    const long long an = modpow(a,\
    \ n, m);\n    for (long long p = 1, cur = k; p <= n; p++) {\n        cur = modmul(cur,\
    \ an, m);\n        auto it = baby.find(cur);\n        if (it != baby.end()) return\
    \ n * p - it->second + add;\n    }\n    return -1;\n}\n\n/**\n * @brief \u7D20\
    \u6570 p \u306B\u3064\u3044\u3066 x^2 \u2261 a (mod p) \u3068\u306A\u308B x \u306E\
    \u3046\u3061\u5C0F\u3055\u3044\u65B9 (\u306A\u3051\u308C\u3070 -1)\n * @note \u3082\
    \u3046\u4E00\u65B9\u306E\u89E3\u306F p - x\u3002Tonelli-Shanks \u3067 O(log^2\
    \ p)\n */\ninline long long sqrt_mod(long long a, long long p) {\n    assert(p\
    \ >= 2);\n    a %= p;\n    if (a < 0) a += p;\n    if (a == 0 || p == 2) return\
    \ a;\n    // \u30AA\u30A4\u30E9\u30FC\u306E\u898F\u6E96: a^((p-1)/2) \u304C 1\
    \ \u3067\u306A\u3051\u308C\u3070\u5E73\u65B9\u975E\u5270\u4F59\n    if (modpow(a,\
    \ (p - 1) / 2, p) != 1) return -1;\n    long long q = p - 1, s = 0;\n    while\
    \ (q % 2 == 0) q /= 2, s++;\n    // \u5E73\u65B9\u975E\u5270\u4F59 z \u3092\u63A2\
    \u3059\n    long long z = 2;\n    while (modpow(z, (p - 1) / 2, p) != p - 1) z++;\n\
    \    long long c = modpow(z, q, p), t = modpow(a, q, p), r = modpow(a, (q + 1)\
    \ / 2, p);\n    // r^2 = a t \u3092\u4FDD\u3061\u306A\u304C\u3089\u3001t \u306E\
    \u4F4D\u6570\u3092\u4E0B\u3052\u3066\u3044\u304F\n    while (t != 1) {\n     \
    \   long long i = 0, tt = t;\n        while (tt != 1) tt = modmul(tt, tt, p),\
    \ i++;\n        long long b = c;\n        for (long long j = 0; j < s - i - 1;\
    \ j++) b = modmul(b, b, p);\n        s = i;\n        c = modmul(b, b, p);\n  \
    \      t = modmul(t, c, p);\n        r = modmul(r, b, p);\n    }\n    return std::min(r,\
    \ p - r);\n}\n#line 6 \"test/yosupo/discrete-logarithm-mod.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int\
    \ t;\n    std::cin >> t;\n    while (t--) {\n        long long x, y, m;\n    \
    \    std::cin >> x >> y >> m;\n        std::cout << discrete_log(x, y, m) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/discrete_logarithm_mod\"\
    \n\n#include <iostream>\n\n#include \"../../src/math/modular-arithmetic.hpp\"\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        long long x, y, m;\n\
    \        std::cin >> x >> y >> m;\n        std::cout << discrete_log(x, y, m)\
    \ << '\\n';\n    }\n}\n"
  dependsOn:
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/yosupo/discrete-logarithm-mod.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 17:15:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/discrete-logarithm-mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/discrete-logarithm-mod.test.cpp
- /verify/test/yosupo/discrete-logarithm-mod.test.cpp.html
title: test/yosupo/discrete-logarithm-mod.test.cpp
---
