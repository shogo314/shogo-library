---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)"
  - icon: ':heavy_check_mark:'
    path: src/math/number-theory.hpp
    title: "\u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
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
  bundledCode: "#line 1 \"test/unittest/number-theory.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ crt (2 \u901A\u308A) \u3092\u3001\u5C0F\u3055\u3044\u7BC4\u56F2\u3067\u89E3\u3092\
    \u5168\u63A2\u7D22\u3057\u305F\u3082\u306E\u3068\u6BD4\u8F03\u3059\u308B\n// \u89E3\
    \u304C\u306A\u3044\u3068\u304D\u306B std::nullopt \u306B\u306A\u308B\u3053\u3068\
    \u3082\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/math/number-theory.hpp\"\n\n/**\n *\
    \ @file number-theory.hpp\n * @brief \u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406)\n */\n\n#include <cassert>\n#include <numeric>\n#include <optional>\n\
    #include <vector>\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file\
    \ modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\
    \u3001\u9006\u5143)\n */\n\n#line 9 \"src/math/modular-arithmetic.hpp\"\n\n/**\n\
    \ * @brief a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\
    \u3046\u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\n\
    constexpr long long modmul(long long a, long long b, long long m) {\n    long\
    \ long res = static_cast<long long>(static_cast<__int128>(a) * b % m);\n    if\
    \ (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief a^(-1) mod m \u3092\
    \u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\
    \u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long long a, long\
    \ long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    long\
    \ long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap \u306F C++17\
    \ \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\u308F\u305A\
    \u306B\u66F8\u304F\n        long long t = a / b;\n        long long c = a - t\
    \ * b;\n        a = b, b = c;\n        long long w = u - t * v;\n        u = v,\
    \ v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\");\n    u %=\
    \ m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n mod m \u3092\
    \u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E -n \u4E57 (a \u3068\
    \ m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068)\u3002O(log |n|)\n\
    \ */\nconstexpr long long modpow(long long a, long long n, long long m) {\n  \
    \  assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    if (n < 0) {\n  \
    \      n = -n;\n        a = modinv(a, m);\n    }\n    long long res = 1 % m;\n\
    \    while (n > 0) {\n        if (n & 1) res = modmul(res, a, m);\n        a =\
    \ modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n}\n#line 14 \"src/math/number-theory.hpp\"\
    \n\n/**\n * @brief 2\u5F0F\u306E\u9023\u7ACB\u5408\u540C\u5F0F\u3092\u3001m\u304C\
    \u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u3088\u3046\u306B\u5909\u5F62\u3059\
    \u308B\n * @param r1 long long\n * @param m1 long long\n * @param r2 long long\n\
    \ * @param m2 long long\n * @return \u77DB\u76FE\u3057\u306A\u3051\u308C\u3070\
    \ true\u3002\u77DB\u76FE\u3059\u308B\u5834\u5408\u306F false \u3092\u8FD4\u3057\
    \u3001\u5F15\u6570\u306F\u5909\u3048\u306A\u3044\n */\ninline bool coprimize_simultaneous_congruence_equation(long\
    \ long& r1, long long& m1, long long& r2, long long& m2) {\n    long long g =\
    \ std::gcd(m1, m2);\n    if ((r2 - r1) % g != 0) return false;\n    m1 /= g, m2\
    \ /= g;\n    long long gi = std::gcd(g, m1);\n    long long gj = g / gi;\n   \
    \ do {\n        g = std::gcd(gi, gj);\n        gi *= g, gj /= g;\n    } while\
    \ (g != 1);\n    m1 *= gi, m2 *= gj;\n    r1 %= m1, r2 %= m2;\n    return true;\n\
    }\n\n/**\n * @brief crt \u306E\u623B\u308A\u5024\n *\n * \u89E3\u306F x + lcm\
    \ * k (k \u306F\u6574\u6570) \u3068\u8868\u305B\u308B\n */\nstruct CRTResult {\n\
    \    long long x;    //!< \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u89E3\n \
    \   long long lcm;  //!< m \u306E\u6700\u5C0F\u516C\u500D\u6570\n};\n\n/**\n *\
    \ @brief \u9023\u7ACB\u5408\u540C\u5F0F\u3092\u89E3\u304F\n * @param r vector<long\
    \ long> \u4F59\u308A\u306E\u914D\u5217\n * @param m vector<long long> mod\u306E\
    \u914D\u5217\n * @return std::optional<CRTResult> (\u89E3, LCM) \u89E3\u306A\u3057\
    \u306E\u3068\u304D\u306F std::nullopt\n */\ninline std::optional<CRTResult> crt(const\
    \ std::vector<long long>& r, const std::vector<long long>& m) {\n    assert(r.size()\
    \ == m.size());\n    if (r.size() == 0) return CRTResult{0, 1};\n    int n = (int)r.size();\n\
    \    long long m_lcm = m[0];\n    long long ans = (r[0] % m[0] + m[0]) % m[0];\n\
    \    for (int i = 1; i < n; i++) {\n        long long rr = (r[i] % m[i] + m[i])\
    \ % m[i], mm = m[i];\n        if (!coprimize_simultaneous_congruence_equation(ans,\
    \ m_lcm, rr, mm)) return std::nullopt;\n        long long t = ((rr - ans) * modinv(m_lcm,\
    \ mm)) % mm;\n        if (t < 0) t += mm;\n        ans += t * m_lcm;\n       \
    \ m_lcm *= mm;\n    }\n    return CRTResult{ans, m_lcm};\n}\n\n/**\n * @brief\
    \ \u9023\u7ACB\u5408\u540C\u5F0F\u306E\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\
    \u89E3 % MOD\u3092\u6C42\u3081\u308B\n * @param r vector<long long> \u4F59\u308A\
    \u306E\u914D\u5217\n * @param m vector<long long> mod\u306E\u914D\u5217\n * @param\
    \ MOD long long\n * @return std::optional<CRTResult> (\u6700\u5C0F\u89E3 % MOD,\
    \ LCM % MOD) \u89E3\u306A\u3057\u306E\u3068\u304D\u306F std::nullopt\n */\ninline\
    \ std::optional<CRTResult> crt(const std::vector<long long>& r, const std::vector<long\
    \ long>& m, long long MOD) {\n    assert(r.size() == m.size());\n    if (r.size()\
    \ == 0) return CRTResult{0, 1};\n    int n = (int)r.size();\n    std::vector<long\
    \ long> r2 = r, m2 = m;\n    // m\u3092\u4E92\u3044\u306B\u7D20\u306B\u3059\u308B\
    \n    for (int i = 1; i < n; i++) {\n        for (int j = 0; j < i; j++) {\n \
    \           if (!coprimize_simultaneous_congruence_equation(r2[i], m2[i], r2[j],\
    \ m2[j])) return std::nullopt;\n        }\n    }\n\n    m2.push_back(MOD);\n \
    \   std::vector<long long> prod(n + 1, 1);  // m2[0] * ... * m2[i - 1] mod m2[i]\n\
    \    std::vector<long long> x(n + 1, 0);     // i\u756A\u76EE\u307E\u3067\u306E\
    \u89E3 mod m2[i]\n    for (int i = 0; i < n; i++) {\n        long long t = (r2[i]\
    \ - x[i]) * modinv(prod[i], m2[i]) % m2[i];\n        if (t < 0) t += m2[i];\n\
    \        for (int j = i + 1; j <= n; j++) {\n            (x[j] += t * prod[j])\
    \ %= m2[j];\n            (prod[j] *= m2[i]) %= m2[j];\n        }\n    }\n    return\
    \ CRTResult{x[n], prod[n]};\n}\n#line 8 \"test/unittest/number-theory.test.cpp\"\
    \n\n#include <iostream>\n#line 11 \"test/unittest/number-theory.test.cpp\"\n#include\
    \ <random>\n#line 13 \"test/unittest/number-theory.test.cpp\"\n\nint main() {\n\
    \    bool ok = true;\n    std::mt19937 rng(314);\n    constexpr long long MOD\
    \ = 1000000007;\n    for (int rep = 0; rep < 20000; rep++) {\n        int k =\
    \ rng() % 4 + 1;\n        std::vector<long long> r(k), m(k);\n        for (int\
    \ i = 0; i < k; i++) m[i] = rng() % 12 + 1, r[i] = (long long)(rng() % 30) - 10;\n\
    \        long long lcm = 1;\n        for (long long x : m) lcm = std::lcm(lcm,\
    \ x);\n        long long best = -1;\n        for (long long x = 0; x < lcm &&\
    \ best == -1; x++) {\n            bool good = true;\n            for (int i =\
    \ 0; i < k; i++) {\n                if (((x - r[i]) % m[i] + m[i]) % m[i] != 0)\
    \ good = false;\n            }\n            if (good) best = x;\n        }\n \
    \       auto a = crt(r, m);\n        auto b = crt(r, m, MOD);\n        if (best\
    \ == -1) {\n            if (a || b) ok = false, std::cerr << \"nullopt \" << rep\
    \ << std::endl;\n        } else {\n            if (!a || a->x != best || a->lcm\
    \ != lcm) ok = false, std::cerr << \"crt \" << rep << std::endl;\n           \
    \ if (!b || b->x != best % MOD || b->lcm != lcm % MOD) ok = false, std::cerr <<\
    \ \"crt mod \" << rep << std::endl;\n        }\n    }\n\n    if (ok) std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// crt (2 \u901A\u308A) \u3092\u3001\u5C0F\u3055\u3044\u7BC4\u56F2\u3067\u89E3\
    \u3092\u5168\u63A2\u7D22\u3057\u305F\u3082\u306E\u3068\u6BD4\u8F03\u3059\u308B\
    \n// \u89E3\u304C\u306A\u3044\u3068\u304D\u306B std::nullopt \u306B\u306A\u308B\
    \u3053\u3068\u3082\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\
    \u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello\
    \ World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/math/number-theory.hpp\"\
    \n\n#include <iostream>\n#include <numeric>\n#include <random>\n#include <vector>\n\
    \nint main() {\n    bool ok = true;\n    std::mt19937 rng(314);\n    constexpr\
    \ long long MOD = 1000000007;\n    for (int rep = 0; rep < 20000; rep++) {\n \
    \       int k = rng() % 4 + 1;\n        std::vector<long long> r(k), m(k);\n \
    \       for (int i = 0; i < k; i++) m[i] = rng() % 12 + 1, r[i] = (long long)(rng()\
    \ % 30) - 10;\n        long long lcm = 1;\n        for (long long x : m) lcm =\
    \ std::lcm(lcm, x);\n        long long best = -1;\n        for (long long x =\
    \ 0; x < lcm && best == -1; x++) {\n            bool good = true;\n          \
    \  for (int i = 0; i < k; i++) {\n                if (((x - r[i]) % m[i] + m[i])\
    \ % m[i] != 0) good = false;\n            }\n            if (good) best = x;\n\
    \        }\n        auto a = crt(r, m);\n        auto b = crt(r, m, MOD);\n  \
    \      if (best == -1) {\n            if (a || b) ok = false, std::cerr << \"\
    nullopt \" << rep << std::endl;\n        } else {\n            if (!a || a->x\
    \ != best || a->lcm != lcm) ok = false, std::cerr << \"crt \" << rep << std::endl;\n\
    \            if (!b || b->x != best % MOD || b->lcm != lcm % MOD) ok = false,\
    \ std::cerr << \"crt mod \" << rep << std::endl;\n        }\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/number-theory.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/unittest/number-theory.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/number-theory.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/number-theory.test.cpp
- /verify/test/unittest/number-theory.test.cpp.html
title: test/unittest/number-theory.test.cpp
---
