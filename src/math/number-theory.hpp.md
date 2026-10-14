---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/number-theory.test.cpp
    title: test/unittest/number-theory.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/binomial-coefficient.test.cpp
    title: test/yosupo/binomial-coefficient.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/186.test.cpp
    title: test/yukicoder/186.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/187.test.cpp
    title: test/yukicoder/187.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
    links: []
  bundledCode: "#line 2 \"src/math/number-theory.hpp\"\n\n/**\n * @file number-theory.hpp\n\
    \ * @brief \u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)\n */\n\n#include\
    \ <cassert>\n#include <numeric>\n#include <optional>\n#include <vector>\n\n#line\
    \ 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file modular-arithmetic.hpp\n\
    \ * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)\n */\n\
    \n#line 9 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @brief a * b mod m \u3092\
    \u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\u306E\u3067 m < 2^63\
    \ \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr long long modmul(long\
    \ long a, long long b, long long m) {\n    long long res = static_cast<long long>(static_cast<__int128>(a)\
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
    }\n#line 14 \"src/math/number-theory.hpp\"\n\n/**\n * @brief 2\u5F0F\u306E\u9023\
    \u7ACB\u5408\u540C\u5F0F\u3092\u3001m\u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\
    \u308B\u3088\u3046\u306B\u5909\u5F62\u3059\u308B\n * @param r1 long long\n * @param\
    \ m1 long long\n * @param r2 long long\n * @param m2 long long\n * @return \u77DB\
    \u76FE\u3057\u306A\u3051\u308C\u3070 true\u3002\u77DB\u76FE\u3059\u308B\u5834\u5408\
    \u306F false \u3092\u8FD4\u3057\u3001\u5F15\u6570\u306F\u5909\u3048\u306A\u3044\
    \n */\ninline bool coprimize_simultaneous_congruence_equation(long long& r1, long\
    \ long& m1, long long& r2, long long& m2) {\n    long long g = std::gcd(m1, m2);\n\
    \    if ((r2 - r1) % g != 0) return false;\n    m1 /= g, m2 /= g;\n    long long\
    \ gi = std::gcd(g, m1);\n    long long gj = g / gi;\n    do {\n        g = std::gcd(gi,\
    \ gj);\n        gi *= g, gj /= g;\n    } while (g != 1);\n    m1 *= gi, m2 *=\
    \ gj;\n    r1 %= m1, r2 %= m2;\n    return true;\n}\n\n/**\n * @brief crt \u306E\
    \u623B\u308A\u5024\n *\n * \u89E3\u306F x + lcm * k (k \u306F\u6574\u6570) \u3068\
    \u8868\u305B\u308B\n */\nstruct CRTResult {\n    long long x;    //!< \u6700\u5C0F\
    \u306E\u975E\u8CA0\u6574\u6570\u89E3\n    long long lcm;  //!< m \u306E\u6700\u5C0F\
    \u516C\u500D\u6570\n};\n\n/**\n * @brief \u9023\u7ACB\u5408\u540C\u5F0F\u3092\u89E3\
    \u304F\n * @param r vector<long long> \u4F59\u308A\u306E\u914D\u5217\n * @param\
    \ m vector<long long> mod\u306E\u914D\u5217\n * @return std::optional<CRTResult>\
    \ (\u89E3, LCM) \u89E3\u306A\u3057\u306E\u3068\u304D\u306F std::nullopt\n */\n\
    inline std::optional<CRTResult> crt(const std::vector<long long>& r, const std::vector<long\
    \ long>& m) {\n    assert(r.size() == m.size());\n    if (r.size() == 0) return\
    \ CRTResult{0, 1};\n    int n = (int)r.size();\n    long long m_lcm = m[0];\n\
    \    long long ans = (r[0] % m[0] + m[0]) % m[0];\n    for (int i = 1; i < n;\
    \ i++) {\n        long long rr = (r[i] % m[i] + m[i]) % m[i], mm = m[i];\n   \
    \     if (!coprimize_simultaneous_congruence_equation(ans, m_lcm, rr, mm)) return\
    \ std::nullopt;\n        long long t = ((rr - ans) * modinv(m_lcm, mm)) % mm;\n\
    \        if (t < 0) t += mm;\n        ans += t * m_lcm;\n        m_lcm *= mm;\n\
    \    }\n    return CRTResult{ans, m_lcm};\n}\n\n/**\n * @brief \u9023\u7ACB\u5408\
    \u540C\u5F0F\u306E\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u89E3 % MOD\u3092\
    \u6C42\u3081\u308B\n * @param r vector<long long> \u4F59\u308A\u306E\u914D\u5217\
    \n * @param m vector<long long> mod\u306E\u914D\u5217\n * @param MOD long long\n\
    \ * @return std::optional<CRTResult> (\u6700\u5C0F\u89E3 % MOD, LCM % MOD) \u89E3\
    \u306A\u3057\u306E\u3068\u304D\u306F std::nullopt\n */\ninline std::optional<CRTResult>\
    \ crt(const std::vector<long long>& r, const std::vector<long long>& m, long long\
    \ MOD) {\n    assert(r.size() == m.size());\n    if (r.size() == 0) return CRTResult{0,\
    \ 1};\n    int n = (int)r.size();\n    std::vector<long long> r2 = r, m2 = m;\n\
    \    // m\u3092\u4E92\u3044\u306B\u7D20\u306B\u3059\u308B\n    for (int i = 1;\
    \ i < n; i++) {\n        for (int j = 0; j < i; j++) {\n            if (!coprimize_simultaneous_congruence_equation(r2[i],\
    \ m2[i], r2[j], m2[j])) return std::nullopt;\n        }\n    }\n\n    m2.push_back(MOD);\n\
    \    std::vector<long long> prod(n + 1, 1);  // m2[0] * ... * m2[i - 1] mod m2[i]\n\
    \    std::vector<long long> x(n + 1, 0);     // i\u756A\u76EE\u307E\u3067\u306E\
    \u89E3 mod m2[i]\n    for (int i = 0; i < n; i++) {\n        long long t = (r2[i]\
    \ - x[i]) * modinv(prod[i], m2[i]) % m2[i];\n        if (t < 0) t += m2[i];\n\
    \        for (int j = i + 1; j <= n; j++) {\n            (x[j] += t * prod[j])\
    \ %= m2[j];\n            (prod[j] *= m2[i]) %= m2[j];\n        }\n    }\n    return\
    \ CRTResult{x[n], prod[n]};\n}\n"
  code: "#pragma once\n\n/**\n * @file number-theory.hpp\n * @brief \u6570\u8AD6 (\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406)\n */\n\n#include <cassert>\n#include <numeric>\n\
    #include <optional>\n#include <vector>\n\n#include \"modular-arithmetic.hpp\"\n\
    \n/**\n * @brief 2\u5F0F\u306E\u9023\u7ACB\u5408\u540C\u5F0F\u3092\u3001m\u304C\
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
    \ CRTResult{x[n], prod[n]};\n}\n"
  dependsOn:
  - src/math/modular-arithmetic.hpp
  isVerificationFile: false
  path: src/math/number-theory.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:33:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/number-theory.test.cpp
  - test/yosupo/binomial-coefficient.test.cpp
  - test/yukicoder/187.test.cpp
  - test/yukicoder/186.test.cpp
documentation_of: src/math/number-theory.hpp
layout: document
title: "\u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)"
---

中国剰余定理の関数です。`modinv`、`modpow` は [mod 演算](modular-arithmetic.hpp) にあり、このファイルからも使えます。

```cpp
auto res = crt({2, 3}, {3, 5});             // res->x == 8, res->lcm == 15
```

## 中国剰余定理

$x \equiv r_i \pmod{m_i}$ をすべて満たす $x$ を求めます。`m` は互いに素でなくてもかまいません。

結果は `std::optional<CRTResult>` で、解がなければ `std::nullopt` です。`CRTResult` は解 `x` と `lcm` を持ち、解の全体は `x + lcm * k` (`k` は整数) です。

```cpp
if (auto res = crt(r, m)) {
    auto [x, lcm] = *res;
} else {
    // 解なし
}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `crt(r, m)` | `x` は最小の非負整数解、`lcm` は `m` の最小公倍数。lcm が `long long` に収まること | $O(k \log \max m)$ |
| `crt(r, m, mod)` | `x` は最小の非負整数解 % `mod`、`lcm` は `m` の最小公倍数 % `mod`。lcm が大きくてもよい | $O(k^2 \log \max m)$ |
| `coprimize_simultaneous_congruence_equation(r1, m1, r2, m2)` | 2 式の連立合同式を、mod が互いに素になるように書き換える。矛盾すれば `false` を返し、引数は変えない | $O(\log^2 \max m)$ |

## 関連

- mod 演算 (`modinv`、`modpow`) は [mod 演算](modular-arithmetic.hpp)
- 畳み込みは [畳み込み](convolution.hpp)
- 二項係数などは [組み合わせ](combinatorics.hpp)
- 一次関数の床関数の和は [floor sum](floor-sum.hpp)
- 約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込みは [約数変換](divisor-transform.hpp)
