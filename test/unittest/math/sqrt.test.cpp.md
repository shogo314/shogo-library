---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/sqrt.hpp
    title: "\u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839"
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
  bundledCode: "#line 1 \"test/unittest/math/sqrt.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// sqrtll \u3092\u3001\u5C0F\u3055\u3044 n \u3067\u306F\u5168\u90E8\u3001\u5927\
    \u304D\u3044 n \u3067\u306F\u5883\u754C\u306E\u524D\u5F8C\u3067\u78BA\u304B\u3081\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u6B63\u3057\u3051\u308C\u3070 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/math/sqrt.hpp\"\n\n/**\n * @file sqrt.hpp\n * @brief \u6574\u6570\
    \u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839\n */\n\n#include <cassert>\n#include\
    \ <cmath>\n\n/**\n * @brief floor(sqrt(n))\n * @param n \u5E73\u65B9\u6839\u3092\
    \u6C42\u3081\u305F\u3044\u6574\u6570 long long \u578B\u3067 0 <= n < 2^63 \u3092\
    \u6E80\u305F\u3059\n * @return long long\n */\ninline long long sqrtll(long long\
    \ n) {\n    assert(n >= 0);\n    // 3037000500 = ceil(sqrt(2^63))\n    long long\
    \ le = 0, ri = 3037000500;\n    while (ri - le > 1) {\n        long long mid =\
    \ (le + ri) / 2;\n        if (mid * mid <= n)\n            le = mid;\n       \
    \ else\n            ri = mid;\n    }\n    return le;\n}\n\n/**\n * @brief floor(a^(1/k))\n\
    \ *\n * \u6D6E\u52D5\u5C0F\u6570\u70B9\u3067\u8FD1\u3044\u5024\u3092\u6C42\u3081\
    \u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\
    \u306B\u639B\u3051\u7B97\u3067\u78BA\u304B\u3081\u3066\u5408\u308F\u305B\u308B\
    \n * @param a 0 <= a < 2^64\n * @param k 1 \u4EE5\u4E0A\n * @return unsigned long\
    \ long\n */\ninline unsigned long long kth_root(unsigned long long a, long long\
    \ k) {\n    assert(k >= 1);\n    if (k == 1 || a <= 1) return a;\n    if (k >=\
    \ 64) return 1;  // a < 2^64 \u306A\u306E\u3067\n    // x^k <= a \u304B\n    auto\
    \ fits = [&](unsigned long long x) {\n        unsigned long long p = 1;\n    \
    \    for (long long i = 0; i < k; i++) {\n            if (p > a / x) return false;\n\
    \            p *= x;\n        }\n        return true;\n    };\n    unsigned long\
    \ long x = static_cast<unsigned long long>(std::pow(static_cast<long double>(a),\
    \ 1.0L / k));\n    if (x == 0) x = 1;\n    while (!fits(x)) x--;\n    while (fits(x\
    \ + 1)) x++;\n    return x;\n}\n#line 7 \"test/unittest/math/sqrt.test.cpp\"\n\
    \n#include <iostream>\n#include <limits>\n#include <random>\n\n// s = floor(sqrt(n))\
    \ \u304B (__int128 \u3067 2 \u4E57\u3057\u3066\u3042\u3075\u308C\u306A\u3044\u3088\
    \u3046\u306B\u6BD4\u3079\u308B)\nbool is_floor_sqrt(long long n, long long s)\
    \ {\n    return s >= 0 && static_cast<__int128>(s) * s <= n && static_cast<__int128>(s\
    \ + 1) * (s + 1) > n;\n}\n\nint main() {\n    bool ok = true;\n    for (long long\
    \ n = 0; n <= 1000000; n++) {\n        if (!is_floor_sqrt(n, sqrtll(n))) ok =\
    \ false, std::cerr << n << std::endl;\n    }\n    // \u5E73\u65B9\u6570\u3068\u305D\
    \u306E\u524D\u5F8C\n    for (long long s : {1000000LL, 999999999LL, 3037000499LL})\
    \ {\n        for (long long n : {s * s - 1, s * s, s * s + 1}) {\n           \
    \ if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n << std::endl;\n\
    \        }\n    }\n    const long long mx = std::numeric_limits<long long>::max();\n\
    \    if (!is_floor_sqrt(mx, sqrtll(mx))) ok = false, std::cerr << \"max\" << std::endl;\n\
    \    std::mt19937_64 rng(314);\n    for (int rep = 0; rep < 100000; rep++) {\n\
    \        long long n = rng() >> 1;\n        if (!is_floor_sqrt(n, sqrtll(n)))\
    \ ok = false, std::cerr << n << std::endl;\n    }\n\n    if (ok) std::cout <<\
    \ \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// sqrtll \u3092\u3001\u5C0F\u3055\u3044 n \u3067\u306F\u5168\u90E8\u3001\u5927\
    \u304D\u3044 n \u3067\u306F\u5883\u754C\u306E\u524D\u5F8C\u3067\u78BA\u304B\u3081\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u6B63\u3057\u3051\u308C\u3070 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/math/sqrt.hpp\"\n\n#include <iostream>\n#include <limits>\n\
    #include <random>\n\n// s = floor(sqrt(n)) \u304B (__int128 \u3067 2 \u4E57\u3057\
    \u3066\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B\u6BD4\u3079\u308B)\nbool\
    \ is_floor_sqrt(long long n, long long s) {\n    return s >= 0 && static_cast<__int128>(s)\
    \ * s <= n && static_cast<__int128>(s + 1) * (s + 1) > n;\n}\n\nint main() {\n\
    \    bool ok = true;\n    for (long long n = 0; n <= 1000000; n++) {\n       \
    \ if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n << std::endl;\n\
    \    }\n    // \u5E73\u65B9\u6570\u3068\u305D\u306E\u524D\u5F8C\n    for (long\
    \ long s : {1000000LL, 999999999LL, 3037000499LL}) {\n        for (long long n\
    \ : {s * s - 1, s * s, s * s + 1}) {\n            if (!is_floor_sqrt(n, sqrtll(n)))\
    \ ok = false, std::cerr << n << std::endl;\n        }\n    }\n    const long long\
    \ mx = std::numeric_limits<long long>::max();\n    if (!is_floor_sqrt(mx, sqrtll(mx)))\
    \ ok = false, std::cerr << \"max\" << std::endl;\n    std::mt19937_64 rng(314);\n\
    \    for (int rep = 0; rep < 100000; rep++) {\n        long long n = rng() >>\
    \ 1;\n        if (!is_floor_sqrt(n, sqrtll(n))) ok = false, std::cerr << n <<\
    \ std::endl;\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/math/sqrt.hpp
  isVerificationFile: true
  path: test/unittest/math/sqrt.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 04:30:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/sqrt.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/sqrt.test.cpp
- /verify/test/unittest/math/sqrt.test.cpp.html
title: test/unittest/math/sqrt.test.cpp
---
