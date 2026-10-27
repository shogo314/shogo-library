---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/combinatorics.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
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
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient
  bundledCode: "#line 1 \"test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\n\
    #include <iostream>\n\n#line 2 \"src/math/combinatorics.hpp\"\n\n/**\n * @file\
    \ combinatorics.hpp\n * @brief \u7D44\u307F\u5408\u308F\u305B\n */\n\n#include\
    \ <cassert>\n#include <numeric>\n#include <vector>\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\
    \n\n/**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#include <algorithm>\n#line 10 \"src/math/modular-arithmetic.hpp\"\
    \n#include <cmath>\n#line 12 \"src/math/modular-arithmetic.hpp\"\n#include <unordered_map>\n\
    \n/**\n * @brief a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\
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
    \ p - r);\n}\n#line 13 \"src/math/combinatorics.hpp\"\n\n/**\n * @brief \u7D44\
    \u307F\u5408\u308F\u305B\n */\ntemplate <typename Modint>\nclass Combination {\n\
    \    static std::vector<Modint> fact, inv_fact;\n    static long long cached_mod;\
    \  // dynamic_modint \u3067 mod \u304C\u5909\u308F\u3063\u305F\u3089\u524D\u8A08\
    \u7B97\u3092\u3084\u308A\u76F4\u3059\n\n   public:\n    /**\n     * @brief n \u307E\
    \u3067\u306E\u968E\u4E57\u3068\u305D\u306E\u9006\u5143\u3092\u524D\u8A08\u7B97\
    \u3059\u308B\n     * @param n\n     * @note O(n) \u5FC5\u8981\u306B\u306A\u3063\
    \u305F\u3089\u547C\u3073\u51FA\u3055\u308C\u308B\u304C\u3001\u4E88\u3081\u5927\
    \u304D\u306An\u306B\u5BFE\u3057\u3066\u547C\u3073\u51FA\u3057\u3066\u304A\u304F\
    \u3053\u3068\u3067\u9006\u5143\u306E\u76F4\u63A5\u8A08\u7B97\u3092\u6E1B\u3089\
    \u305B\u308B\n     */\n    inline static void extend(long long n) {\n        if\
    \ (cached_mod != static_cast<long long>(Modint::mod())) {\n            cached_mod\
    \ = Modint::mod();\n            fact = {1, 1};\n            inv_fact = {1, 1};\n\
    \        }\n        const long long m = fact.size();\n        if (n < m) return;\n\
    \        fact.resize(n + 1);\n        inv_fact.resize(n + 1);\n        for (long\
    \ long i = m; i <= n; ++i) {\n            fact[i] = fact[i - 1] * i;\n       \
    \ }\n        inv_fact[n] = fact[n].inv();\n        for (long long i = n; i > m;\
    \ --i) {\n            inv_fact[i - 1] = inv_fact[i] * i;\n        }\n    }\n\n\
    \    /**\n     * @brief n \u306E\u968E\u4E57\u3092\u8FD4\u3059\n     * @param\
    \ n\n     * @return n!\n     * @note extend(n), O(1)\n     */\n    inline static\
    \ Modint factorial(long long n) {\n        assert(n >= 0);\n        extend(n);\n\
    \        return fact[n];\n    }\n    /**\n     * @brief n \u306E\u968E\u4E57\u306E\
    \u9006\u5143\u3092\u8FD4\u3059\n     * @param n\n     * @return n!^-1\n     *\
    \ @note extend(n), O(1)\n     */\n    inline static Modint inverse_factorial(long\
    \ long n) {\n        assert(n >= 0);\n        extend(n);\n        return inv_fact[n];\n\
    \    }\n    /**\n     * @brief n \u306E\u9006\u5143\u3092\u8FD4\u3059\n     *\
    \ @param n\n     * @return n^-1\n     * @note extend(n), O(1)\n     */\n    inline\
    \ static Modint inv(long long n) {\n        assert(n > 0);\n        extend(n);\n\
    \        return inv_fact[n] * fact[n - 1];\n    }\n\n    /**\n     * @brief nPr\
    \ \u3092\u8FD4\u3059\n     * @param n\n     * @param r\n     * @return nPr\n \
    \    * @note extend(n), O(1)\n     */\n    inline static Modint P(long long n,\
    \ long long r) {\n        if (r < 0 || n < r) return 0;\n        extend(n);\n\
    \        return fact[n] * inv_fact[n - r];\n    }\n    /**\n     * @brief nCr\
    \ \u3092\u8FD4\u3059\n     * @param n\n     * @param r\n     * @return nCr\n \
    \    * @note extend(n), O(1)\n     */\n    inline static Modint C(long long n,\
    \ long long r) {\n        if (r < 0 || n < r) return 0;\n        extend(n);\n\
    \        return fact[n] * inv_fact[r] * inv_fact[n - r];\n    }\n    /**\n   \
    \  * @brief nHr \u3092\u8FD4\u3059\n     * @param n\n     * @param r\n     * @return\
    \ nHr\n     * @note extend(n+r-1), O(1)\n     */\n    inline static Modint H(long\
    \ long n, long long r) {\n        if (n < 0 || r < 0) return 0;\n        if (n\
    \ == 0 && r == 0) return 1;\n        return C(n + r - 1, r);\n    }\n\n    /**\n\
    \     * @brief nPr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\u3059\u308B\
    \n     * @param n\n     * @param r\n     * @return nPr\n     * @note O(r)\n  \
    \   */\n    inline static Modint P_loop(long long n, long long r) {\n        if\
    \ (r < 0 || n < r) return 0;\n        Modint res = 1;\n        for (long long\
    \ i = 0; i < r; ++i) {\n            res *= n - i;\n        }\n        return res;\n\
    \    }\n    /**\n     * @brief nCr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\
    \u3059\u308B\n     * @param n\n     * @param r\n     * @return nCr\n     * @note\
    \ O(min(r, n-r))\n     */\n    inline static Modint C_loop(long long n, long long\
    \ r) {\n        if (r < 0 || n < r) return 0;\n        if (r > n - r) r = n -\
    \ r;\n        extend(r);\n        return P_loop(n, r) * inv_fact[r];\n    }\n\
    \    /**\n     * @brief nHr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\u3059\
    \u308B\n     * @param n\n     * @param r\n     * @return nHr\n     * @note O(r)\n\
    \     */\n    inline static Modint H_loop(long long n, long long r) {\n      \
    \  if (n < 0 || r < 0) return 0;\n        if (n == 0 && r == 0) return 1;\n  \
    \      return C_loop(n + r - 1, r);\n    }\n\n    /**\n     * @brief nCr \u3092\
    \ Lucas \u306E\u5B9A\u7406\u3092\u7528\u3044\u3066\u8A08\u7B97\u3059\u308B\n \
    \    * @param n\n     * @param r\n     * @return nCr\n     * @note extend(Mod),\
    \ O(log(r))\n     */\n    inline static Modint C_lucas(long long n, long long\
    \ r) {\n        if (r < 0 || n < r) return 0;\n        if (r == 0 || n == r) return\
    \ 1;\n        Modint res = 1;\n        while (r > 0) {\n            int ni = n\
    \ % Modint::mod(), ri = r % Modint::mod();\n            if (ni < ri) return 0;\n\
    \            res *= C(ni, ri);\n            n /= Modint::mod();\n            r\
    \ /= Modint::mod();\n        }\n        return res;\n    }\n};\n\ntemplate <typename\
    \ Modint>\nstd::vector<Modint> Combination<Modint>::fact{1, 1};\ntemplate <typename\
    \ Modint>\nstd::vector<Modint> Combination<Modint>::inv_fact{1, 1};\ntemplate\
    \ <typename Modint>\nlong long Combination<Modint>::cached_mod = 0;\n\n/**\n *\
    \ @brief mod p^q \u3067\u306E\u4E8C\u9805\u4FC2\u6570\u3092\u6C42\u3081\u308B\u69CB\
    \u9020\n * @note \u524D\u8A08\u7B97O(p^q) \u53C2\u8003: https://nyaannyaan.github.io/library/modulo/arbitrary-mod-binomial.hpp\n\
    \ */\nstruct CombinationPQ {\n    int p, q;\n    int pq;\n    std::vector<int>\
    \ fact_p, inv_fact_p;\n    int delta;\n    CombinationPQ(int p, int q) : p(p),\
    \ q(q) {\n        pq = 1;\n        for (int i = 0; i < q; i++) pq *= p;\n    \
    \    fact_p.resize(pq);\n        fact_p[0] = 1;\n        for (int i = 1; i < pq;\
    \ i++) {\n            if (i % p == 0)\n                fact_p[i] = fact_p[i -\
    \ 1];\n            else\n                fact_p[i] = static_cast<long long>(fact_p[i\
    \ - 1]) * i % pq;\n        }\n        inv_fact_p.resize(pq);\n        inv_fact_p[pq\
    \ - 1] = modinv(fact_p[pq - 1], pq);\n        for (int i = pq - 1; i > 0; i--)\
    \ {\n            if (i % p == 0)\n                inv_fact_p[i - 1] = inv_fact_p[i];\n\
    \            else\n                inv_fact_p[i - 1] = static_cast<long long>(inv_fact_p[i])\
    \ * i % pq;\n        }\n        if (p == 2 && q >= 3)\n            delta = 1;\n\
    \        else\n            delta = -1;\n    }\n    /**\n     * @brief nCr mod\
    \ p^q \u3092\u8FD4\u3059\n     * @param n long long\n     * @param r long long\n\
    \     * @return nCr mod p^q\n     * @note O(log(n))\n     */\n    int C(long long\
    \ n, long long r) {\n        if (r < 0 || n < r) return 0;\n        long long\
    \ m = n - r;\n        int ans = 1;\n        std::vector<int> epsilon;\n      \
    \  while (n > 0) {\n            ans = static_cast<long long>(ans) * fact_p[n %\
    \ pq] % pq;\n            ans = static_cast<long long>(ans) * inv_fact_p[m % pq]\
    \ % pq;\n            ans = static_cast<long long>(ans) * inv_fact_p[r % pq] %\
    \ pq;\n            n /= p;\n            m /= p;\n            r /= p;\n       \
    \     epsilon.push_back(n - m - r);\n        }\n        if (delta == -1 && static_cast<int>(epsilon.size())\
    \ >= q && std::accumulate(epsilon.begin() + q - 1, epsilon.end(), 0) % 2 == 1)\
    \ ans = pq - ans;\n        if (ans == pq) ans = 0;\n        int e = std::accumulate(epsilon.begin(),\
    \ epsilon.end(), 0);\n        if (e >= q)\n            ans = 0;\n        else\
    \ {\n            for (int i = 0; i < e; i++) {\n                ans = static_cast<long\
    \ long>(ans) * p % pq;\n            }\n        }\n        return ans;\n    }\n\
    };\n#line 2 \"src/math/number-theory.hpp\"\n\n/**\n * @file number-theory.hpp\n\
    \ * @brief \u6570\u8AD6 (\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406)\n */\n\n#line 10\
    \ \"src/math/number-theory.hpp\"\n#include <optional>\n#line 12 \"src/math/number-theory.hpp\"\
    \n\n#line 14 \"src/math/number-theory.hpp\"\n\n/**\n * @brief 2\u5F0F\u306E\u9023\
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
    \ CRTResult{0, 1};\n    int n = static_cast<int>(r.size());\n    long long m_lcm\
    \ = m[0];\n    long long ans = (r[0] % m[0] + m[0]) % m[0];\n    for (int i =\
    \ 1; i < n; i++) {\n        long long rr = (r[i] % m[i] + m[i]) % m[i], mm = m[i];\n\
    \        if (!coprimize_simultaneous_congruence_equation(ans, m_lcm, rr, mm))\
    \ return std::nullopt;\n        long long t = ((rr - ans) * modinv(m_lcm, mm))\
    \ % mm;\n        if (t < 0) t += mm;\n        ans += t * m_lcm;\n        m_lcm\
    \ *= mm;\n    }\n    return CRTResult{ans, m_lcm};\n}\n\n/**\n * @brief \u9023\
    \u7ACB\u5408\u540C\u5F0F\u306E\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\u89E3\
    \ % MOD\u3092\u6C42\u3081\u308B\n * @param r vector<long long> \u4F59\u308A\u306E\
    \u914D\u5217\n * @param m vector<long long> mod\u306E\u914D\u5217\n * @param MOD\
    \ long long\n * @return std::optional<CRTResult> (\u6700\u5C0F\u89E3 % MOD, LCM\
    \ % MOD) \u89E3\u306A\u3057\u306E\u3068\u304D\u306F std::nullopt\n */\ninline\
    \ std::optional<CRTResult> crt(const std::vector<long long>& r, const std::vector<long\
    \ long>& m, long long MOD) {\n    assert(r.size() == m.size());\n    if (r.size()\
    \ == 0) return CRTResult{0, 1 % MOD};\n    int n = static_cast<int>(r.size());\n\
    \    std::vector<long long> r2 = r, m2 = m;\n    // m\u3092\u4E92\u3044\u306B\u7D20\
    \u306B\u3059\u308B\n    for (int i = 1; i < n; i++) {\n        for (int j = 0;\
    \ j < i; j++) {\n            if (!coprimize_simultaneous_congruence_equation(r2[i],\
    \ m2[i], r2[j], m2[j])) return std::nullopt;\n        }\n    }\n\n    m2.push_back(MOD);\n\
    \    std::vector<long long> prod(n + 1, 1);  // m2[0] * ... * m2[i - 1] mod m2[i]\n\
    \    std::vector<long long> x(n + 1, 0);     // i\u756A\u76EE\u307E\u3067\u306E\
    \u89E3 mod m2[i]\n    for (int i = 0; i < n; i++) {\n        long long t = (r2[i]\
    \ - x[i]) * modinv(prod[i], m2[i]) % m2[i];\n        if (t < 0) t += m2[i];\n\
    \        for (int j = i + 1; j <= n; j++) {\n            (x[j] += t * prod[j])\
    \ %= m2[j];\n            (prod[j] *= m2[i]) %= m2[j];\n        }\n    }\n    return\
    \ CRTResult{x[n], prod[n]};\n}\n#line 7 \"test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp\"\
    \n\nint main() {\n    int t, m;\n    std::cin >> t >> m;\n    std::vector<std::pair<int,\
    \ int>> factors;\n    {\n        int mm = m;\n        for (int i = 2; i * i <=\
    \ mm; ++i) {\n            if (mm % i == 0) {\n                int cnt = 0;\n \
    \               while (mm % i == 0) {\n                    mm /= i;\n        \
    \            cnt++;\n                }\n                factors.emplace_back(i,\
    \ cnt);\n            }\n        }\n        if (mm > 1) factors.emplace_back(mm,\
    \ 1);\n    }\n    std::vector<CombinationPQ> combpq;\n    for (long long i = 0;\
    \ i < static_cast<long long>(factors.size()); ++i) {\n        auto [p, e] = factors[i];\n\
    \        combpq.emplace_back(p, e);\n    }\n    while (t--) {\n        long long\
    \ n, k;\n        std::cin >> n >> k;\n        std::vector<long long> x, y;\n \
    \       for (long long i = 0; i < static_cast<long long>(factors.size()); ++i)\
    \ {\n            x.push_back(combpq[i].C(n, k));\n            y.push_back(combpq[i].pq);\n\
    \        }\n        std::cout << crt(x, y)->x << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient\"\n\
    \n#include <iostream>\n\n#include \"../../../src/math/combinatorics.hpp\"\n#include\
    \ \"../../../src/math/number-theory.hpp\"\n\nint main() {\n    int t, m;\n   \
    \ std::cin >> t >> m;\n    std::vector<std::pair<int, int>> factors;\n    {\n\
    \        int mm = m;\n        for (int i = 2; i * i <= mm; ++i) {\n          \
    \  if (mm % i == 0) {\n                int cnt = 0;\n                while (mm\
    \ % i == 0) {\n                    mm /= i;\n                    cnt++;\n    \
    \            }\n                factors.emplace_back(i, cnt);\n            }\n\
    \        }\n        if (mm > 1) factors.emplace_back(mm, 1);\n    }\n    std::vector<CombinationPQ>\
    \ combpq;\n    for (long long i = 0; i < static_cast<long long>(factors.size());\
    \ ++i) {\n        auto [p, e] = factors[i];\n        combpq.emplace_back(p, e);\n\
    \    }\n    while (t--) {\n        long long n, k;\n        std::cin >> n >> k;\n\
    \        std::vector<long long> x, y;\n        for (long long i = 0; i < static_cast<long\
    \ long>(factors.size()); ++i) {\n            x.push_back(combpq[i].C(n, k));\n\
    \            y.push_back(combpq[i].pq);\n        }\n        std::cout << crt(x,\
    \ y)->x << std::endl;\n    }\n}\n"
  dependsOn:
  - src/math/combinatorics.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/number-theory.hpp
  isVerificationFile: true
  path: test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp
- /verify/test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp.html
title: test/yosupo/enumerative_combinatorics/binomial-coefficient.test.cpp
---
