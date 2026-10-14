---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/modular-arithmetic.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ modmul\u30FBmodpow\u30FBmodinv \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\u6BD4\
    \u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file modular-arithmetic.hpp\n\
    \ * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)\n */\n\
    \n#include <cassert>\n\n/**\n * @brief a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\
    \u3067 __int128 \u3092\u4F7F\u3046\u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\
    \u308C\u306A\u3044)\n */\nconstexpr long long modmul(long long a, long long b,\
    \ long long m) {\n    long long res = static_cast<long long>(static_cast<__int128>(a)\
    \ * b % m);\n    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief\
    \ a^(-1) mod m \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\
    \u7D20\u3067\u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long\
    \ long a, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a +=\
    \ m;\n    long long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap\
    \ \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\
    \u308F\u305A\u306B\u66F8\u304F\n        long long t = a / b;\n        long long\
    \ c = a - t * b;\n        a = b, b = c;\n        long long w = u - t * v;\n  \
    \      u = v, v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\"\
    );\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n\
    \ mod m \u3092\u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E\
    \ -n \u4E57 (a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\
    \u3068)\u3002O(log |n|)\n */\nconstexpr long long modpow(long long a, long long\
    \ n, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n\
    \    if (n < 0) {\n        n = -n;\n        a = modinv(a, m);\n    }\n    long\
    \ long res = 1 % m;\n    while (n > 0) {\n        if (n & 1) res = modmul(res,\
    \ a, m);\n        a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n\
    }\n#line 7 \"test/unittest/modular-arithmetic.test.cpp\"\n\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n\nstatic_assert(modpow(2, 10, 1000) ==\
    \ 24);\nstatic_assert(modinv(3, 7) == 5);\nstatic_assert(modpow(3, -1, 7) == 5);\n\
    static_assert(modpow(5, 0, 1) == 0);\n\nint main() {\n    bool ok = true;\n  \
    \  std::mt19937_64 rng(314);\n\n    // \u5C0F\u3055\u3044\u6CD5\u3067\u611A\u76F4\
    \u306B\u6BD4\u3079\u308B (\u8CA0\u306E a \u3082)\n    for (long long m = 1; m\
    \ <= 60; m++) {\n        for (long long a = -70; a <= 70; a++) {\n           \
    \ long long r = ((a % m) + m) % m;\n            long long p = 1 % m;\n       \
    \     for (int n = 0; n <= 20; n++) {\n                if (modpow(a, n, m) !=\
    \ p) ok = false, std::cerr << \"modpow \" << a << \" \" << n << \" \" << m <<\
    \ std::endl;\n                p = p * r % m;\n            }\n            for (long\
    \ long b = -5; b <= 5; b++) {\n                if (modmul(a, b, m) != (((a * b)\
    \ % m) + m) % m) ok = false, std::cerr << \"modmul \" << a << \" \" << b << std::endl;\n\
    \            }\n            if (std::gcd(r, m) == 1) {\n                long long\
    \ x = modinv(a, m);\n                if (!(0 <= x && x < m && x * r % m == 1 %\
    \ m)) ok = false, std::cerr << \"modinv \" << a << \" \" << m << std::endl;\n\
    \                if (modpow(a, -3, m) != modpow(x, 3, m)) ok = false, std::cerr\
    \ << \"modpow neg \" << a << \" \" << m << std::endl;\n            }\n       \
    \ }\n    }\n\n    // \u5927\u304D\u3044\u6CD5 (\u7A4D\u304C long long \u306B\u53CE\
    \u307E\u3089\u306A\u3044) \u3067\u3001\u30D5\u30A7\u30EB\u30DE\u30FC\u306E\u5C0F\
    \u5B9A\u7406\u3068\u9006\u5143\u3092\u78BA\u304B\u3081\u308B\n    const long long\
    \ P = (1LL << 61) - 1;  // \u7D20\u6570\n    for (int rep = 0; rep < 1000; rep++)\
    \ {\n        long long a = rng() % (P - 1) + 1;\n        if (modpow(a, P - 1,\
    \ P) != 1) ok = false, std::cerr << \"fermat \" << a << std::endl;\n        if\
    \ (modmul(a, modinv(a, P), P) != 1) ok = false, std::cerr << \"inv \" << a <<\
    \ std::endl;\n        long long b = rng() % P;\n        if (modmul(a, b, P) !=\
    \ (long long)((__int128)a * b % P)) ok = false, std::cerr << \"mul \" << a <<\
    \ std::endl;\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// modmul\u30FBmodpow\u30FBmodinv \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../src/math/modular-arithmetic.hpp\"\n\n#include\
    \ <iostream>\n#include <numeric>\n#include <random>\n\nstatic_assert(modpow(2,\
    \ 10, 1000) == 24);\nstatic_assert(modinv(3, 7) == 5);\nstatic_assert(modpow(3,\
    \ -1, 7) == 5);\nstatic_assert(modpow(5, 0, 1) == 0);\n\nint main() {\n    bool\
    \ ok = true;\n    std::mt19937_64 rng(314);\n\n    // \u5C0F\u3055\u3044\u6CD5\
    \u3067\u611A\u76F4\u306B\u6BD4\u3079\u308B (\u8CA0\u306E a \u3082)\n    for (long\
    \ long m = 1; m <= 60; m++) {\n        for (long long a = -70; a <= 70; a++) {\n\
    \            long long r = ((a % m) + m) % m;\n            long long p = 1 % m;\n\
    \            for (int n = 0; n <= 20; n++) {\n                if (modpow(a, n,\
    \ m) != p) ok = false, std::cerr << \"modpow \" << a << \" \" << n << \" \" <<\
    \ m << std::endl;\n                p = p * r % m;\n            }\n           \
    \ for (long long b = -5; b <= 5; b++) {\n                if (modmul(a, b, m) !=\
    \ (((a * b) % m) + m) % m) ok = false, std::cerr << \"modmul \" << a << \" \"\
    \ << b << std::endl;\n            }\n            if (std::gcd(r, m) == 1) {\n\
    \                long long x = modinv(a, m);\n                if (!(0 <= x &&\
    \ x < m && x * r % m == 1 % m)) ok = false, std::cerr << \"modinv \" << a << \"\
    \ \" << m << std::endl;\n                if (modpow(a, -3, m) != modpow(x, 3,\
    \ m)) ok = false, std::cerr << \"modpow neg \" << a << \" \" << m << std::endl;\n\
    \            }\n        }\n    }\n\n    // \u5927\u304D\u3044\u6CD5 (\u7A4D\u304C\
    \ long long \u306B\u53CE\u307E\u3089\u306A\u3044) \u3067\u3001\u30D5\u30A7\u30EB\
    \u30DE\u30FC\u306E\u5C0F\u5B9A\u7406\u3068\u9006\u5143\u3092\u78BA\u304B\u3081\
    \u308B\n    const long long P = (1LL << 61) - 1;  // \u7D20\u6570\n    for (int\
    \ rep = 0; rep < 1000; rep++) {\n        long long a = rng() % (P - 1) + 1;\n\
    \        if (modpow(a, P - 1, P) != 1) ok = false, std::cerr << \"fermat \" <<\
    \ a << std::endl;\n        if (modmul(a, modinv(a, P), P) != 1) ok = false, std::cerr\
    \ << \"inv \" << a << std::endl;\n        long long b = rng() % P;\n        if\
    \ (modmul(a, b, P) != (long long)((__int128)a * b % P)) ok = false, std::cerr\
    \ << \"mul \" << a << std::endl;\n    }\n\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/unittest/modular-arithmetic.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/modular-arithmetic.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/modular-arithmetic.test.cpp
- /verify/test/unittest/modular-arithmetic.test.cpp.html
title: test/unittest/modular-arithmetic.test.cpp
---
