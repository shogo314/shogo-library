---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/combinatorics.hpp
    title: "\u7D44\u307F\u5408\u308F\u305B"
  - icon: ':heavy_check_mark:'
    path: src/math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F (NTT)"
  - icon: ':heavy_check_mark:'
    path: src/math/fps.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/combinatorial-sequences.test.cpp
    title: test/unittest/math/combinatorial-sequences.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerative_combinatorics/bell-number.test.cpp
    title: test/yosupo/enumerative_combinatorics/bell-number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerative_combinatorics/partition-function.3.test.cpp
    title: test/yosupo/enumerative_combinatorics/partition-function.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerative_combinatorics/stirling-number-of-the-first-kind.test.cpp
    title: test/yosupo/enumerative_combinatorics/stirling-number-of-the-first-kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerative_combinatorics/stirling-number-of-the-second-kind.test.cpp
    title: test/yosupo/enumerative_combinatorics/stirling-number-of-the-second-kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/bernoulli-number.test.cpp
    title: test/yosupo/number_theory/bernoulli-number.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5206\u5272\u6570\u30FB\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u30FB\
      \u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u30FB\u30D9\u30EB\u6570 (\u5F62\u5F0F\
      \u7684\u51AA\u7D1A\u6570\u3067 O(n log n))"
    links: []
  bundledCode: "#line 2 \"src/math/combinatorial-sequences.hpp\"\n\n/**\n * @file\
    \ combinatorial-sequences.hpp\n * @brief \u5206\u5272\u6570\u30FB\u30D9\u30EB\u30CC\
    \u30FC\u30A4\u6570\u30FB\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570\u30FB\u30D9\
    \u30EB\u6570 (\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u3067 O(n log n))\n */\n\n\
    #include <vector>\n\n#line 2 \"src/math/combinatorics.hpp\"\n\n/**\n * @file combinatorics.hpp\n\
    \ * @brief \u7D44\u307F\u5408\u308F\u305B\n */\n\n#include <cassert>\n#include\
    \ <numeric>\n#line 11 \"src/math/combinatorics.hpp\"\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\
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
    \ Modint factorial(long long n) {\n        extend(n);\n        return fact[n];\n\
    \    }\n    /**\n     * @brief n \u306E\u968E\u4E57\u306E\u9006\u5143\u3092\u8FD4\
    \u3059\n     * @param n\n     * @return n!^-1\n     * @note extend(n), O(1)\n\
    \     */\n    inline static Modint inverse_factorial(long long n) {\n        extend(n);\n\
    \        return inv_fact[n];\n    }\n    /**\n     * @brief n \u306E\u9006\u5143\
    \u3092\u8FD4\u3059\n     * @param n\n     * @return n^-1\n     * @note extend(n),\
    \ O(1)\n     */\n    inline static Modint inv(long long n) {\n        assert(n\
    \ > 0);\n        extend(n);\n        return inv_fact[n] * fact[n - 1];\n    }\n\
    \n    /**\n     * @brief nPr \u3092\u8FD4\u3059\n     * @param n\n     * @param\
    \ r\n     * @return nPr\n     * @note extend(n), O(1)\n     */\n    inline static\
    \ Modint P(long long n, long long r) {\n        if (r < 0 || n < r) return 0;\n\
    \        extend(n);\n        return fact[n] * inv_fact[n - r];\n    }\n    /**\n\
    \     * @brief nCr \u3092\u8FD4\u3059\n     * @param n\n     * @param r\n    \
    \ * @return nCr\n     * @note extend(n), O(1)\n     */\n    inline static Modint\
    \ C(long long n, long long r) {\n        if (r < 0 || n < r) return 0;\n     \
    \   extend(n);\n        return fact[n] * inv_fact[r] * inv_fact[n - r];\n    }\n\
    \    /**\n     * @brief nHr \u3092\u8FD4\u3059\n     * @param n\n     * @param\
    \ r\n     * @return nHr\n     * @note extend(n+r-1), O(1)\n     */\n    inline\
    \ static Modint H(long long n, long long r) {\n        if (n < 0 || r < 0) return\
    \ 0;\n        if (n == 0 && r == 0) return 1;\n        return C(n + r - 1, r);\n\
    \    }\n\n    /**\n     * @brief nPr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\
    \u7B97\u3059\u308B\n     * @param n\n     * @param r\n     * @return nPr\n   \
    \  * @note O(r)\n     */\n    inline static Modint P_loop(long long n, long long\
    \ r) {\n        if (r < 0 || n < r) return 0;\n        Modint res = 1;\n     \
    \   for (long long i = 0; i < r; ++i) {\n            res *= n - i;\n        }\n\
    \        return res;\n    }\n    /**\n     * @brief nCr \u3092\u5B9A\u7FA9\u3069\
    \u304A\u308A\u8A08\u7B97\u3059\u308B\n     * @param n\n     * @param r\n     *\
    \ @return nCr\n     * @note O(min(r, n-r))\n     */\n    inline static Modint\
    \ C_loop(long long n, long long r) {\n        if (r < 0 || n < r) return 0;\n\
    \        if (r > n - r) r = n - r;\n        extend(r);\n        return P_loop(n,\
    \ r) * inv_fact[r];\n    }\n    /**\n     * @brief nHr \u3092\u5B9A\u7FA9\u3069\
    \u304A\u308A\u8A08\u7B97\u3059\u308B\n     * @param n\n     * @param r\n     *\
    \ @return nHr\n     * @note O(r)\n     */\n    inline static Modint H_loop(long\
    \ long n, long long r) {\n        if (n < 0 || r < 0) return 0;\n        if (n\
    \ == 0 && r == 0) return 1;\n        return C_loop(n + r - 1, r);\n    }\n\n \
    \   /**\n     * @brief nCr \u3092 Lucas \u306E\u5B9A\u7406\u3092\u7528\u3044\u3066\
    \u8A08\u7B97\u3059\u308B\n     * @param n\n     * @param r\n     * @return nCr\n\
    \     * @note extend(Mod), O(log(r))\n     */\n    inline static Modint C_lucas(long\
    \ long n, long long r) {\n        if (r < 0 || n < r) return 0;\n        if (r\
    \ == 0 || n == r) return 1;\n        Modint res = 1;\n        while (r > 0) {\n\
    \            int ni = n % Modint::mod(), ri = r % Modint::mod();\n           \
    \ if (ni < ri) return 0;\n            res *= C(ni, ri);\n            n /= Modint::mod();\n\
    \            r /= Modint::mod();\n        }\n        return res;\n    }\n};\n\n\
    template <typename Modint>\nstd::vector<Modint> Combination<Modint>::fact{1, 1};\n\
    template <typename Modint>\nstd::vector<Modint> Combination<Modint>::inv_fact{1,\
    \ 1};\ntemplate <typename Modint>\nlong long Combination<Modint>::cached_mod =\
    \ 0;\n\n/**\n * @brief mod p^q \u3067\u306E\u4E8C\u9805\u4FC2\u6570\u3092\u6C42\
    \u3081\u308B\u69CB\u9020\n * @note \u524D\u8A08\u7B97O(p^q) \u53C2\u8003: https://nyaannyaan.github.io/library/modulo/arbitrary-mod-binomial.hpp\n\
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
    };\n#line 2 \"src/math/convolution.hpp\"\n\n/**\n * @file convolution.hpp\n *\
    \ @brief \u7573\u307F\u8FBC\u307F (NTT)\n */\n\n#line 9 \"src/math/convolution.hpp\"\
    \n#include <utility>\n#line 11 \"src/math/convolution.hpp\"\n\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line\
    \ 9 \"src/math/modint.hpp\"\n#include <cstdint>\n#include <iostream>\n#include\
    \ <limits>\n#include <type_traits>\n#line 14 \"src/math/modint.hpp\"\n\n#line\
    \ 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\
    \u6027\n */\n\n#include <cstddef>\n#include <iterator>\n#include <set>\n#line\
    \ 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits {\nusing std::begin,\
    \ std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 14 \"src/math/convolution.hpp\"\n\n\
    /**\n * @brief \u7573\u307F\u8FBC\u307F\n */\nnamespace internal_convolution {\n\
    /**\n * @brief \u539F\u5B50\u6839\n * @param MOD int\n * @return int\n */\ninline\
    \ int calc_primitive_root(int MOD) {\n    if (MOD == 2) return 1;\n    if (MOD\
    \ == 167772161) return 3;\n    if (MOD == 469762049) return 3;\n    if (MOD ==\
    \ 754974721) return 11;\n    if (MOD == 998244353) return 3;\n    int divs[20]\
    \ = {};\n    divs[0] = 2;\n    int cnt = 1;\n    long long x = (MOD - 1) >> 1;\n\
    \    while (x % 2 == 0) x >>= 1;\n    for (long long i = 3; i * i <= x; i += 2)\
    \ {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) divs[cnt++] = x;\n  \
    \  for (int g = 2;; ++g) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (modpow(g, (MOD - 1) / divs[i], MOD) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\
    \u306E\u30B5\u30A4\u30BA\u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\n */\n\
    inline int get_fft_size(int N, int M) {\n    int size = 1;\n    while (size <\
    \ N + M - 1) size <<= 1;\n    return size;\n}\n\n/**\n * @brief NTT\n */\ntemplate\
    \ <class mint>\nvoid trans(std::vector<mint>& v, bool inv = false) {\n    if (v.empty())\
    \ return;\n    int N = static_cast<int>(v.size());\n    int MOD = v[0].mod();\n\
    \    int PR = calc_primitive_root(MOD);\n    static bool first = true;\n    static\
    \ std::vector<long long> vbw(30), vibw(30);\n    if (first) {\n        first =\
    \ false;\n        for (int k = 0; k < 30; ++k) {\n            vbw[k] = modpow(PR,\
    \ (MOD - 1) >> (k + 1), MOD);\n            vibw[k] = modinv(vbw[k], MOD);\n  \
    \      }\n    }\n    for (int i = 0, j = 1; j < N - 1; ++j) {\n        for (int\
    \ k = N >> 1; k > (i ^= k); k >>= 1);\n        if (i > j) std::swap(v[i], v[j]);\n\
    \    }\n    for (int k = 0, t = 2; t <= N; ++k, t <<= 1) {\n        long long\
    \ bw = vbw[k];\n        if (inv) bw = vibw[k];\n        for (int i = 0; i < N;\
    \ i += t) {\n            mint w = 1;\n            for (int j = 0; j < (t >> 1);\
    \ ++j) {\n                int j1 = i + j, j2 = i + j + (t >> 1);\n           \
    \     mint c1 = v[j1], c2 = v[j2] * w;\n                v[j1] = c1 + c2;\n   \
    \             v[j2] = c1 - c2;\n                w *= bw;\n            }\n    \
    \    }\n    }\n    if (inv) {\n        long long invN = modinv(N, MOD);\n    \
    \    for (int i = 0; i < N; ++i) v[i] = v[i] * invN;\n    }\n}\n\nstatic constexpr\
    \ int MOD0 = 754974721;\nstatic constexpr int MOD1 = 167772161;\nstatic constexpr\
    \ int MOD2 = 469762049;\nusing mint0 = static_modint<MOD0>;\nusing mint1 = static_modint<MOD1>;\n\
    using mint2 = static_modint<MOD2>;\nstatic const mint1 imod0 = 95869806;    //\
    \ modinv(MOD0, MOD1);\nstatic const mint2 imod1 = 104391568;   // modinv(MOD1,\
    \ MOD2);\nstatic const mint2 imod01 = 187290749;  // imod1 / MOD0;\n\n/**\n *\
    \ @brief \u914D\u5217\u306E\u30B5\u30A4\u30BA\u304C\u5C0F\u3055\u3044\u3068\u304D\
    \u306E\u7573\u307F\u8FBC\u307F\n * @param T mint, long long\n * @param A vector<T>\n\
    \ * @param B vector<T>\n * @return vector<T>\n */\ntemplate <class T>\nstd::vector<T>\
    \ naive(const std::vector<T>& A, const std::vector<T>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<T> res(N + M - 1);\n    for (int i = 0; i < N; ++i)\n       \
    \ for (int j = 0; j < M; ++j)\n            res[i + j] += A[i] * B[j];\n    return\
    \ res;\n}\n};  // namespace internal_convolution\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n * @param A vector<mint>\n * @param B vector<mint>\n\
    \ * @return vector<mint>\n */\ntemplate <class mint>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& A, const std::vector<mint>& B) {\n    if (A.empty() || B.empty())\
    \ return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) < 30) return internal_convolution::naive(A, B);\n    int\
    \ MOD = A[0].mod();\n    int size_fft = internal_convolution::get_fft_size(N,\
    \ M);\n    if (MOD == 998244353) {\n        std::vector<mint> a(size_fft), b(size_fft),\
    \ c(size_fft);\n        for (int i = 0; i < N; ++i) a[i] = A[i];\n        for\
    \ (int i = 0; i < M; ++i) b[i] = B[i];\n        internal_convolution::trans(a),\
    \ internal_convolution::trans(b);\n        std::vector<mint> res(size_fft);\n\
    \        for (int i = 0; i < size_fft; ++i) res[i] = a[i] * b[i];\n        internal_convolution::trans(res,\
    \ true);\n        res.resize(N + M - 1);\n        return res;\n    }\n    std::vector<internal_convolution::mint0>\
    \ a0(size_fft, 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<internal_convolution::mint1>\
    \ a1(size_fft, 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<internal_convolution::mint2>\
    \ a2(size_fft, 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i <\
    \ N; ++i) {\n        a0[i] = A[i].val();\n        a1[i] = A[i].val();\n      \
    \  a2[i] = A[i].val();\n    }\n    for (int i = 0; i < M; ++i) {\n        b0[i]\
    \ = B[i].val();\n        b1[i] = B[i].val();\n        b2[i] = B[i].val();\n  \
    \  }\n    internal_convolution::trans(a0), internal_convolution::trans(a1), internal_convolution::trans(a2),\n\
    \        internal_convolution::trans(b0), internal_convolution::trans(b1), internal_convolution::trans(b2);\n\
    \    for (int i = 0; i < size_fft; ++i) {\n        c0[i] = a0[i] * b0[i];\n  \
    \      c1[i] = a1[i] * b1[i];\n        c2[i] = a2[i] * b2[i];\n    }\n    internal_convolution::trans(c0,\
    \ true), internal_convolution::trans(c1, true), internal_convolution::trans(c2,\
    \ true);\n    const mint mod0 = internal_convolution::MOD0, mod01 = mod0 * internal_convolution::MOD1;\n\
    \    std::vector<mint> res(N + M - 1);\n    for (int i = 0; i < N + M - 1; ++i)\
    \ {\n        int y0 = c0[i].val();\n        int y1 = (internal_convolution::imod0\
    \ * (c1[i] - y0)).val();\n        int y2 = (internal_convolution::imod01 * (c2[i]\
    \ - y0) - internal_convolution::imod1 * y1).val();\n        res[i] = mod01 * y2\
    \ + mod0 * y1 + y0;\n    }\n    return res;\n}\n\n/**\n * @brief long long\u306E\
    \u7573\u307F\u8FBC\u307F\n * @param A vector<long long>\n * @param B vector<long\
    \ long>\n * @return vector<long long>\n */\ninline std::vector<long long> convolution_ll(const\
    \ std::vector<long long>& A, const std::vector<long long>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) < 30) return internal_convolution::naive(A, B);\n    int\
    \ size_fft = internal_convolution::get_fft_size(N, M);\n    std::vector<internal_convolution::mint0>\
    \ a0(size_fft, 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<internal_convolution::mint1>\
    \ a1(size_fft, 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<internal_convolution::mint2>\
    \ a2(size_fft, 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i <\
    \ N; ++i) {\n        a0[i] = A[i];\n        a1[i] = A[i];\n        a2[i] = A[i];\n\
    \    }\n    for (int i = 0; i < M; ++i) {\n        b0[i] = B[i];\n        b1[i]\
    \ = B[i];\n        b2[i] = B[i];\n    }\n    internal_convolution::trans(a0),\
    \ internal_convolution::trans(a1), internal_convolution::trans(a2),\n        internal_convolution::trans(b0),\
    \ internal_convolution::trans(b1), internal_convolution::trans(b2);\n    for (int\
    \ i = 0; i < size_fft; ++i) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] =\
    \ a1[i] * b1[i];\n        c2[i] = a2[i] * b2[i];\n    }\n    internal_convolution::trans(c0,\
    \ true), internal_convolution::trans(c1, true), internal_convolution::trans(c2,\
    \ true);\n    static const long long mod0 = internal_convolution::MOD0, mod01\
    \ = mod0 * internal_convolution::MOD1;\n    static const __int128_t mod012 = static_cast<__int128_t>(mod01)\
    \ * internal_convolution::MOD2;\n    std::vector<long long> res(N + M - 1);\n\
    \    for (int i = 0; i < N + M - 1; ++i) {\n        int y0 = c0[i].val();\n  \
    \      int y1 = (internal_convolution::imod0 * (c1[i] - y0)).val();\n        int\
    \ y2 = (internal_convolution::imod01 * (c2[i] - y0) - internal_convolution::imod1\
    \ * y1).val();\n        __int128_t tmp = static_cast<__int128_t>(mod01) * y2 +\
    \ static_cast<__int128_t>(mod0) * y1 + y0;\n        if (tmp < (mod012 >> 1))\n\
    \            res[i] = tmp;\n        else\n            res[i] = tmp - mod012;\n\
    \    }\n    return res;\n}\n#line 2 \"src/math/fps.hpp\"\n\n/**\n * @file fps.hpp\n\
    \ * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n */\n\n#line 10 \"src/math/fps.hpp\"\
    \n#include <optional>\n#include <queue>\n#line 14 \"src/math/fps.hpp\"\n\n#line\
    \ 18 \"src/math/fps.hpp\"\n\ntemplate <typename mint>\nstruct FPS;\n\nnamespace\
    \ internal_fps {\ntemplate <typename mint>\nFPS<mint> gcd(const FPS<mint>& f,\
    \ const FPS<mint>& g);\n}  // namespace internal_fps\n\ntemplate <typename mint>\n\
    struct FPS : std::vector<mint> {\n    using std::vector<mint>::vector;\n\n   \
    \ // constructor\n    FPS(const std::vector<mint>& r) : std::vector<mint>(r) {}\n\
    \n    // core operator\n    inline FPS pre(long long siz) const {\n        return\
    \ FPS(begin(*this), begin(*this) + std::min(static_cast<long long>(this->size()),\
    \ siz));\n    }\n    inline FPS rev() const {\n        FPS res = *this;\n    \
    \    reverse(begin(res), end(res));\n        return res;\n    }\n    inline FPS&\
    \ normalize() {\n        while (!this->empty() && this->back() == 0) this->pop_back();\n\
    \        return *this;\n    }\n\n    // basic operator\n    inline FPS operator-()\
    \ const noexcept {\n        FPS res = (*this);\n        for (int i = 0; i < static_cast<int>(res.size());\
    \ ++i) res[i] = -res[i];\n        return res;\n    }\n    inline FPS operator+(const\
    \ mint& v) const { return FPS(*this) += v; }\n    inline FPS operator+(const FPS&\
    \ r) const { return FPS(*this) += r; }\n    inline FPS operator-(const mint& v)\
    \ const { return FPS(*this) -= v; }\n    inline FPS operator-(const FPS& r) const\
    \ { return FPS(*this) -= r; }\n    inline FPS operator*(const mint& v) const {\
    \ return FPS(*this) *= v; }\n    inline FPS operator*(const FPS& r) const { return\
    \ FPS(*this) *= r; }\n    inline FPS operator/(const mint& v) const { return FPS(*this)\
    \ /= v; }\n    inline FPS operator<<(long long x) const { return FPS(*this) <<=\
    \ x; }\n    inline FPS operator>>(long long x) const { return FPS(*this) >>= x;\
    \ }\n    inline FPS& operator+=(const mint& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += v;\n        return *this;\n    }\n    inline FPS& operator+=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (int i = 0; i < static_cast<int>(r.size()); ++i) (*this)[i] += r[i];\n\
    \        return this->normalize();\n    }\n    inline FPS& operator-=(const mint&\
    \ v) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n\
    \        return *this;\n    }\n    inline FPS& operator-=(const FPS& r) {\n  \
    \      if (r.size() > this->size()) this->resize(r.size());\n        for (int\
    \ i = 0; i < static_cast<int>(r.size()); ++i) (*this)[i] -= r[i];\n        return\
    \ this->normalize();\n    }\n    inline FPS& operator*=(const mint& v) {\n   \
    \     for (int i = 0; i < static_cast<int>(this->size()); ++i) (*this)[i] *= v;\n\
    \        return *this;\n    }\n    inline FPS& operator*=(const FPS& r) {\n  \
    \      return *this = convolution((*this), r);\n    }\n    inline FPS& operator/=(const\
    \ mint& v) {\n        assert(v != 0);\n        mint iv = v.inv();\n        for\
    \ (int i = 0; i < static_cast<int>(this->size()); ++i) (*this)[i] *= iv;\n   \
    \     return *this;\n    }\n    inline FPS& operator<<=(long long x) {\n     \
    \   FPS res(x, 0);\n        res.insert(res.end(), begin(*this), end(*this));\n\
    \        return *this = res;\n    }\n    inline FPS& operator>>=(long long x)\
    \ {\n        if (static_cast<long long>(this->size()) <= x) return *this = FPS<mint>(1,\
    \ 0);\n        FPS res;\n        res.insert(res.end(), begin(*this) + x, end(*this));\n\
    \        return *this = res;\n    }\n    inline mint eval(const mint& v) {\n \
    \       mint res = 0;\n        for (int i = static_cast<int>(this->size()) - 1;\
    \ i >= 0; --i) {\n            res *= v;\n            res += (*this)[i];\n    \
    \    }\n        return res;\n    }\n    // \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\
    \u304C 1 \u306E gcd (Half-GCD)\u3002f \u3068 g \u304C\u3068\u3082\u306B 0 \u306A\
    \u3089 0 (\u7A7A)\n    inline friend FPS gcd(const FPS& f, const FPS& g) {\n \
    \       return internal_fps::gcd(f, g);\n    }\n\n    // advanced operation\n\
    \    // df/dx\n    inline friend FPS diff(const FPS& f) {\n        int n = static_cast<int>(f.size());\n\
    \        if (n == 0) return FPS();\n        FPS res(n - 1);\n        for (int\
    \ i = 1; i < n; ++i) res[i - 1] = f[i] * i;\n        return res;\n    }\n\n  \
    \  // \\int f dx\n    inline friend FPS intg(const FPS& f) {\n        int n =\
    \ static_cast<int>(f.size());\n        FPS res(n + 1, 0);\n        for (int i\
    \ = 0; i < n; ++i) res[i + 1] = f[i] / (i + 1);\n        return res;\n    }\n\n\
    \    // inv(f), f[0] must not be 0\n    inline friend FPS inv(const FPS& f, long\
    \ long deg) {\n        assert(!f.empty() && f[0] != 0);\n        if (deg < 0)\
    \ deg = static_cast<long long>(f.size());\n        if (deg == 0) return FPS();\n\
    \        FPS res({mint(1) / f[0]});\n        for (long long i = 1; i < deg; i\
    \ <<= 1) {\n            res = (res + res - res * res * f.pre(i << 1)).pre(i <<\
    \ 1);\n        }\n        res.resize(deg);\n        return res;\n    }\n    inline\
    \ friend FPS inv(const FPS& f) {\n        return inv(f, f.size());\n    }\n\n\
    \    // division, r must be normalized (r.back() must not be 0)\n    inline FPS&\
    \ operator/=(const FPS& r) {\n        assert(!r.empty());\n        assert(r.back()\
    \ != 0);\n        this->normalize();\n        if (this->size() < r.size()) {\n\
    \            this->clear();\n            return *this;\n        }\n        const\
    \ long long need = static_cast<long long>(this->size()) - static_cast<long long>(r.size())\
    \ + 1;\n        *this = ((*this).rev().pre(need) * inv(r.rev(), need)).pre(need).rev();\n\
    \        return *this;\n    }\n    inline FPS& operator%=(const FPS& r) {\n  \
    \      return *this = divmod(*this, r).second;\n    }\n    inline FPS operator/(const\
    \ FPS& r) const { return FPS(*this) /= r; }\n    inline FPS operator%(const FPS&\
    \ r) const { return FPS(*this) %= r; }\n    // {f / g, f % g}, g must be normalized\
    \ (g.back() must not be 0)\n    inline friend std::pair<FPS, FPS> divmod(const\
    \ FPS& f, const FPS& g) {\n        assert(!g.empty());\n        assert(g.back()\
    \ != 0);\n        FPS q = f / g;\n        FPS r = f - q * g;\n        return {q,\
    \ r};\n    }\n\n    // log(f) = \\int f'/f dx, f[0] must be 1\n    inline friend\
    \ FPS log(const FPS& f, long long deg) {\n        assert(!f.empty() && f[0] ==\
    \ 1);\n        FPS res = intg(diff(f) * inv(f, deg));\n        res.resize(deg);\n\
    \        return res;\n    }\n    inline friend FPS log(const FPS& f) {\n     \
    \   return log(f, f.size());\n    }\n\n    // exp(f), f[0] must be 0\n    inline\
    \ friend FPS exp(const FPS& f, long long deg) {\n        assert(f.empty() || f[0]\
    \ == 0);\n        FPS res(1, 1);\n        for (long long i = 1; i < deg; i <<=\
    \ 1) {\n            res = res * (f.pre(i << 1) - log(res, i << 1) + 1).pre(i <<\
    \ 1);\n        }\n        res.resize(deg);\n        return res;\n    }\n    inline\
    \ friend FPS exp(const FPS& f) {\n        return exp(f, f.size());\n    }\n\n\
    \    // pow(f) = exp(e * log f)\n    inline friend FPS pow(const FPS& f, long\
    \ long e, long long deg) {\n        if (e == 0) {\n            auto ret = FPS(deg,\
    \ 0);\n            if (deg > 0) ret[0] = 1;\n            return ret;\n       \
    \ }\n        long long i = 0;\n        while (i < static_cast<long long>(f.size())\
    \ && f[i] == 0) ++i;\n        if (i == static_cast<long long>(f.size())) return\
    \ FPS(deg, 0);\n        if ((i >= 1 && e >= deg) || i * e >= deg) return FPS(deg,\
    \ 0);\n        mint k = f[i];\n        FPS res = exp(log((f >> i) / k, deg) *\
    \ e, deg) * k.pow(e) << (e * i);\n        res.resize(deg);\n        return res;\n\
    \    }\n    inline friend FPS pow(const FPS& f, long long e) {\n        return\
    \ pow(f, e, f.size());\n    }\n\n    // sqrt(f) \u306E\u5148\u982D deg \u9805\
    \ (g^2 = f)\u3002\u5E73\u65B9\u6839\u304C\u306A\u3051\u308C\u3070 std::nullopt\n\
    \    // \u6700\u521D\u306E 0 \u3067\u306A\u3044\u9805 f_i x^i \u306F\u3001i \u304C\
    \u5076\u6570\u3067 f_i \u304C\u5E73\u65B9\u5270\u4F59\u3067\u3042\u308B\u3053\u3068\
    \u3002\u6CD5\u306F\u7D20\u6570\u3067\u3042\u308B\u3053\u3068\n    inline friend\
    \ std::optional<FPS> sqrt(const FPS& f, long long deg) {\n        long long i\
    \ = 0;\n        while (i < static_cast<long long>(f.size()) && f[i] == 0) ++i;\n\
    \        if (i == static_cast<long long>(f.size()) || i / 2 >= deg) return FPS(deg,\
    \ 0);\n        if (i % 2 == 1) return std::nullopt;\n        long long r = sqrt_mod(f[i].val(),\
    \ mint::mod());\n        if (r == -1) return std::nullopt;\n        // x^i \u3092\
    \u5916\u3057\u305F g = f / x^i (g_0 != 0) \u306E\u5E73\u65B9\u6839\u3092\u30CB\
    \u30E5\u30FC\u30C8\u30F3\u6CD5\u3067\u6C42\u3081\u308B: h <- (h + g / h) / 2\n\
    \        const FPS g = f >> i;\n        const long long d = deg - i / 2;\n   \
    \     FPS h({mint(r)});\n        const mint inv2 = mint(2).inv();\n        for\
    \ (long long k = 1; k < d; k <<= 1) {\n            h = (h + (g.pre(k << 1) * inv(h,\
    \ k << 1)).pre(k << 1)) * inv2;\n        }\n        h.resize(d);\n        h <<=\
    \ i / 2;\n        return h;\n    }\n    inline friend std::optional<FPS> sqrt(const\
    \ FPS& f) {\n        return sqrt(f, f.size());\n    }\n\n    inline friend FPS\
    \ taylor_shift(FPS f, mint a) {\n        using C = Combination<mint>;\n      \
    \  int n = f.size();\n        C::extend(n);\n        for (int i = 0; i < n; i++)\
    \ f[i] *= C::factorial(i);\n        std::reverse(f.begin(), f.end());\n      \
    \  FPS<mint> g(n, 1);\n        for (int i = 1; i < n; i++) g[i] = g[i - 1] * a\
    \ * C::inv(i);\n        f = (f * g).pre(n);\n        std::reverse(f.begin(), f.end());\n\
    \        for (int i = 0; i < n; i++) f[i] *= C::inverse_factorial(i);\n      \
    \  return f;\n    }\n};\n\nnamespace internal_fps {\ntemplate <typename mint>\n\
    FPS<mint> shrink(FPS<mint> f) {\n    f.normalize();\n    return f;\n}\n\n// x^k\
    \ \u3067\u5272\u3063\u3066\u4F4E\u6B21\u306E\u9805\u3092\u6368\u3066\u308B\u3002\
    \u9577\u3055\u304C k \u4EE5\u4E0B\u306A\u3089 0 (\u7A7A)\ntemplate <typename mint>\n\
    FPS<mint> drop(const FPS<mint>& f, long long k) {\n    if (static_cast<long long>(f.size())\
    \ <= k) return FPS<mint>();\n    return FPS<mint>(f.begin() + k, f.end());\n}\n\
    \n// \u591A\u9805\u5F0F\u3092\u6210\u5206\u306B\u6301\u3064 2x2 \u884C\u5217 [[a,\
    \ b], [c, d]]\ntemplate <typename mint>\nstruct Mat {\n    FPS<mint> a, b, c,\
    \ d;\n    static Mat identity() { return {FPS<mint>{1}, FPS<mint>(), FPS<mint>(),\
    \ FPS<mint>{1}}; }\n    Mat operator*(const Mat& r) const {\n        return {shrink(a\
    \ * r.a + b * r.c), shrink(a * r.b + b * r.d), shrink(c * r.a + d * r.c), shrink(c\
    \ * r.b + d * r.d)};\n    }\n    std::pair<FPS<mint>, FPS<mint>> operator*(const\
    \ std::pair<FPS<mint>, FPS<mint>>& p) const {\n        return {shrink(a * p.first\
    \ + b * p.second), shrink(c * p.first + d * p.second)};\n    }\n};\n\n// \u4E92\
    \u9664\u6CD5\u3092 1 \u6BB5\u9032\u3081\u308B: (p, q) <- (q, p % q)\u3001m <-\
    \ [[0, 1], [1, -p / q]] m\ntemplate <typename mint>\nvoid step(Mat<mint>& m, std::pair<FPS<mint>,\
    \ FPS<mint>>& p) {\n    const FPS<mint> quo = p.first / p.second;\n    FPS<mint>\
    \ rem = shrink(p.first - p.second * quo);\n    FPS<mint> c = shrink(m.a - m.c\
    \ * quo), d = shrink(m.b - m.d * quo);\n    m = {std::move(m.c), std::move(m.d),\
    \ std::move(c), std::move(d)};\n    p = {std::move(p.second), std::move(rem)};\n\
    }\n\n// p = (f, g) (|f| = n > |g|) \u306B\u5BFE\u3057\u3001\u4E92\u9664\u6CD5\u3067\
    \u9577\u3055\u304C ceil(n / 2) \u4EE5\u4E0B\u306B\u306A\u308B\u76F4\u524D\u307E\
    \u3067\u306E\u5909\u63DB\u884C\u5217\ntemplate <typename mint>\nMat<mint> half_gcd(std::pair<FPS<mint>,\
    \ FPS<mint>> p) {\n    const long long n = p.first.size(), m = p.second.size();\n\
    \    const long long k = (n + 1) / 2;\n    if (m <= k) return Mat<mint>::identity();\n\
    \    // \u4E0A\u4F4D\u306E\u534A\u5206\u3060\u3051\u3067\u6C42\u3081\u305F\u884C\
    \u5217\u306F\u3001\u4E0A\u4F4D\u306E\u7D04\u534A\u5206\u306E\u5546\u3092\u6B63\
    \u3057\u304F\u4E0E\u3048\u308B\n    Mat<mint> m1 = half_gcd(std::make_pair(drop(p.first,\
    \ k), drop(p.second, k)));\n    p = m1 * p;\n    if (static_cast<long long>(p.second.size())\
    \ <= k) return m1;\n    step(m1, p);\n    if (static_cast<long long>(p.second.size())\
    \ <= k) return m1;\n    const long long l = static_cast<long long>(p.first.size())\
    \ - 1;\n    const long long j = 2 * k - l;\n    p = {drop(p.first, j), drop(p.second,\
    \ j)};\n    return half_gcd(std::move(p)) * m1;\n}\n\n// M (f, g) = (gcd(f, g),\
    \ 0) \u3068\u306A\u308B\u884C\u5217 M\ntemplate <typename mint>\nMat<mint> gcd_matrix(const\
    \ FPS<mint>& f, const FPS<mint>& g) {\n    std::pair<FPS<mint>, FPS<mint>> p{shrink(f),\
    \ shrink(g)};\n    if (p.first.size() < p.second.size()) {\n        Mat<mint>\
    \ m = gcd_matrix(g, f);\n        std::swap(m.a, m.b);\n        std::swap(m.c,\
    \ m.d);\n        return m;\n    }\n    Mat<mint> res = Mat<mint>::identity();\n\
    \    while (!p.second.empty()) {\n        Mat<mint> m1 = half_gcd(p);\n      \
    \  p = m1 * p;\n        if (!p.second.empty()) step(m1, p);\n        res = m1\
    \ * res;\n    }\n    return res;\n}\n// \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u304C\
    \ 1 \u306E gcd\u3002\u884C\u5217\u306F\u639B\u3051\u5408\u308F\u305B\u305A\u3001\
    \u7D44 (p, q) \u3060\u3051\u3092\u9032\u3081\u308B\ntemplate <typename mint>\n\
    FPS<mint> gcd(const FPS<mint>& f, const FPS<mint>& g) {\n    std::pair<FPS<mint>,\
    \ FPS<mint>> p{shrink(f), shrink(g)};\n    if (p.first.size() < p.second.size())\
    \ std::swap(p.first, p.second);\n    while (!p.second.empty()) {\n        Mat<mint>\
    \ m1 = half_gcd(p);\n        p = m1 * p;\n        if (!p.second.empty()) step(m1,\
    \ p);\n    }\n    if (!p.first.empty()) p.first /= p.first.back();\n    return\
    \ p.first;\n}\n}  // namespace internal_fps\n\ntemplate <typename mint>\nFPS<mint>\
    \ modpow(const FPS<mint>& f, long long n, const FPS<mint>& m) {\n    if (n ==\
    \ 0) return FPS<mint>(1, 1);\n    auto t = modpow(f, n / 2, m);\n    t = (t *\
    \ t) % m;\n    if (n & 1) t = (t * f) % m;\n    return t;\n}\n\n/**\n * @brief\
    \ a f + b g = d (d \u306F f \u3068 g \u306E\u6700\u5927\u516C\u7D04\u6570\u3067\
    \u3001\u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u304C 1) \u3068\u306A\u308B a\u3001\
    b \u3092\u6C42\u3081\u3001d \u3092\u8FD4\u3059 O(n log^2 n)\n * f \u3068 g \u304C\
    \u3068\u3082\u306B 0 \u306A\u3089 d = a = b = 0\u3002a\u3001b \u306F\u672B\u5C3E\
    \u306E 0 \u3092\u53D6\u308A\u9664\u3044\u305F\u5F62\n */\ntemplate <typename mint>\n\
    FPS<mint> extgcd(const FPS<mint>& f, const FPS<mint>& g, FPS<mint>& a, FPS<mint>&\
    \ b) {\n    using namespace internal_fps;\n    Mat<mint> m = gcd_matrix(f, g);\n\
    \    FPS<mint> d = shrink(m.a * shrink(f) + m.b * shrink(g));\n    a = std::move(m.a),\
    \ b = std::move(m.b);\n    if (d.empty()) {\n        a.clear(), b.clear();\n \
    \       return d;\n    }\n    const mint iv = d.back().inv();\n    d *= iv, a\
    \ *= iv, b *= iv;\n    return d;\n}\n\n/**\n * @brief f h \u2261 1 (mod g) \u3067\
    \u3001\u6B21\u6570\u304C g \u3088\u308A\u5C0F\u3055\u3044 h\u3002\u306A\u3051\u308C\
    \u3070 std::nullopt O(n log^2 n)\n * g \u306F 0 \u3067\u306A\u3044\u3053\u3068\
    \u3002g \u304C\u5B9A\u6570\u306A\u3089\u3059\u3079\u3066\u304C 0 \u3068\u5408\u540C\
    \u306A\u306E\u3067\u3001h = 0 (\u7A7A) \u3092\u8FD4\u3059\u3002h \u306F\u672B\u5C3E\
    \u306E 0 \u3092\u53D6\u308A\u9664\u3044\u305F\u5F62\n */\ntemplate <typename mint>\n\
    std::optional<FPS<mint>> modinv(const FPS<mint>& f, const FPS<mint>& g) {\n  \
    \  using namespace internal_fps;\n    const FPS<mint> gs = shrink(g);\n    assert(!gs.empty());\n\
    \    if (gs.size() == 1) return FPS<mint>();\n    FPS<mint> a, b;\n    const FPS<mint>\
    \ d = extgcd(shrink(f % gs), gs, a, b);\n    if (d.size() != 1) return std::nullopt;\n\
    \    return shrink(a % gs);\n}\n\n/**\n * @brief \u591A\u9805\u5F0F\u306E\u5217\
    \u306E\u7A4D f_0 f_1 ... f_{n-1} O(N log^2 N) (N \u306F\u6B21\u6570\u306E\u548C\
    )\n * \u6B21\u6570\u306E\u5C0F\u3055\u3044\u3082\u306E\u304B\u3089 2 \u3064\u305A\
    \u3064\u639B\u3051\u3066\u3044\u304F\u3002fs \u304C\u7A7A\u306A\u3089 1\n */\n\
    template <typename mint>\nFPS<mint> polynomial_product(std::vector<FPS<mint>>\
    \ fs) {\n    if (fs.empty()) return FPS<mint>(1, 1);\n    auto larger = [&](int\
    \ a, int b) { return fs[a].size() > fs[b].size(); };\n    std::priority_queue<int,\
    \ std::vector<int>, decltype(larger)> pq(larger);\n    for (int i = 0; i < static_cast<int>(fs.size());\
    \ i++) pq.push(i);\n    while (pq.size() > 1) {\n        int a = pq.top();\n \
    \       pq.pop();\n        int b = pq.top();\n        pq.pop();\n        // \u7A7A\
    \u306E\u591A\u9805\u5F0F (0) \u3068\u306E\u7A4D\u306F 0\n        fs[a] = fs[a].empty()\
    \ || fs[b].empty() ? FPS<mint>() : fs[a] * fs[b];\n        FPS<mint>().swap(fs[b]);\n\
    \        pq.push(a);\n    }\n    return fs[pq.top()];\n}\n\n/**\n * @brief \u5206\
    \u6570\u306E\u548C \u03A3_i nums[i] / dens[i] \u3092 1 \u3064\u306E\u5206\u6570\
    \ num / den \u306B\u307E\u3068\u3081\u308B O(N log^2 N) (N \u306F\u591A\u9805\u5F0F\
    \u306E\u9577\u3055\u306E\u548C)\n * \u534A\u5206\u305A\u3064\u306B\u5206\u3051\
    \u3066 a / b + c / d = (ad + cb) / bd \u3068\u307E\u3068\u3081\u308B\u3002den\
    \ \u306F dens \u306E\u7A4D\u3002\u7A7A\u306A\u3089 0 / 1\n * @return std::pair<FPS<mint>,\
    \ FPS<mint>> {num, den}\n */\ntemplate <typename mint>\nstd::pair<FPS<mint>, FPS<mint>>\
    \ sum_of_fractions(const std::vector<FPS<mint>>& nums, const std::vector<FPS<mint>>&\
    \ dens) {\n    assert(nums.size() == dens.size());\n    if (nums.empty()) return\
    \ {FPS<mint>(), FPS<mint>{1}};\n    auto rec = [&](auto&& self, long long l, long\
    \ long r) -> std::pair<FPS<mint>, FPS<mint>> {\n        if (r - l == 1) return\
    \ {nums[l], dens[l]};\n        long long m = (l + r) / 2;\n        auto [a, b]\
    \ = self(self, l, m);\n        auto [c, d] = self(self, m, r);\n        return\
    \ {a * d + c * b, b * d};\n    };\n    return rec(rec, 0, nums.size());\n}\n#line\
    \ 13 \"src/math/combinatorial-sequences.hpp\"\n\n/**\n * @brief \u5206\u5272\u6570\
    \ p(0), ..., p(n) (n \u3092\u6B63\u306E\u6574\u6570\u306E\u548C\u306B\u5206\u3051\
    \u308B\u65B9\u6CD5\u306E\u6570\u3002\u548C\u306E\u9806\u756A\u306F\u533A\u5225\
    \u3057\u306A\u3044) O(n log n)\n * \u6BCD\u95A2\u6570\u306F 1 / \u03A0_{k >= 1}\
    \ (1 - x^k)\u3002\u5206\u6BCD\u306F\u4E94\u89D2\u6570\u5B9A\u7406\u3067 \u03A3\
    _k (-1)^k x^{k(3k-1)/2} (k \u306F\u5168\u6574\u6570) \u3068\u66F8\u3051\u308B\n\
    \ */\ntemplate <typename mint>\nFPS<mint> partition_numbers(long long n) {\n \
    \   FPS<mint> f(n + 1, 0);\n    f[0] = 1;\n    for (long long k = 1;; k++) {\n\
    \        const long long a = k * (3 * k - 1) / 2, b = k * (3 * k + 1) / 2;\n \
    \       if (a > n) break;\n        const mint s = k % 2 == 1 ? mint(-1) : mint(1);\n\
    \        f[a] += s;\n        if (b <= n) f[b] += s;\n    }\n    return inv(f,\
    \ n + 1);\n}\n\n/**\n * @brief \u30D9\u30EB\u30CC\u30FC\u30A4\u6570 B_0, ...,\
    \ B_n (B_1 = -1/2 \u3068\u3059\u308B\u6D41\u5100) O(n log n)\n * \u6307\u6570\u578B\
    \u6BCD\u95A2\u6570 x / (e^x - 1) \u3092\u3001(e^x - 1) / x = \u03A3 x^k / (k+1)!\
    \ \u306E\u9006\u6570\u3068\u3057\u3066\u6C42\u3081\u308B\n */\ntemplate <typename\
    \ mint>\nFPS<mint> bernoulli_numbers(long long n) {\n    using C = Combination<mint>;\n\
    \    C::extend(n + 1);\n    FPS<mint> f(n + 1);\n    for (long long k = 0; k <=\
    \ n; k++) f[k] = C::inverse_factorial(k + 1);\n    FPS<mint> g = inv(f, n + 1);\n\
    \    for (long long k = 0; k <= n; k++) g[k] *= C::factorial(k);\n    return g;\n\
    }\n\n/**\n * @brief \u7B26\u53F7\u4ED8\u304D\u7B2C 1 \u7A2E\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u6570 s(n, 0), ..., s(n, n) (x (x-1) ... (x-n+1) = \u03A3 s(n, k)\
    \ x^k) O(n log n)\n * \u4E0B\u964D\u968E\u4E57 f_m(x) = x (x-1) ... (x-m+1) \u3092\
    \u3001f_{2m}(x) = f_m(x) f_m(x - m) \u3068 f_{m+1}(x) = f_m(x) (x - m) \u3067\u500D\
    \u3005\u306B\u4F5C\u308B\n * \u7B26\u53F7\u306A\u3057 (\u9806\u5217\u3092 k \u500B\
    \u306E\u5DE1\u56DE\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) \u306F |s(n,\
    \ k)|\n */\ntemplate <typename mint>\nFPS<mint> stirling_first(long long n) {\n\
    \    FPS<mint> f{1};\n    long long m = 0;\n    for (int bit = 62; bit >= 0; bit--)\
    \ {\n        if (m > 0) {\n            f = f * taylor_shift(f, -mint(m));\n  \
    \          m *= 2;\n        }\n        if (n >> bit & 1) {\n            f = f\
    \ * FPS<mint>{-mint(m), 1};\n            m++;\n        }\n    }\n    f.resize(n\
    \ + 1);\n    return f;\n}\n\n/**\n * @brief \u7B2C 2 \u7A2E\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u6570 S(n, 0), ..., S(n, n) (n \u500B\u306E\u533A\u5225\u3067\u304D\
    \u308B\u7389\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7A7A\u3067\
    \u306A\u3044\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) O(n log n)\n\
    \ * S(n, k) = \u03A3_{i=0}^{k} (-1)^{k-i} i^n / (i! (k-i)!) \u3092\u7573\u307F\
    \u8FBC\u307F\u3067\u6C42\u3081\u308B\n */\ntemplate <typename mint>\nFPS<mint>\
    \ stirling_second(long long n) {\n    using C = Combination<mint>;\n    C::extend(n);\n\
    \    std::vector<mint> a(n + 1), b(n + 1);\n    for (long long i = 0; i <= n;\
    \ i++) {\n        a[i] = mint(i).pow(n) * C::inverse_factorial(i);\n        b[i]\
    \ = i % 2 == 0 ? C::inverse_factorial(i) : -C::inverse_factorial(i);\n    }\n\
    \    FPS<mint> s = convolution(a, b);\n    s.resize(n + 1);\n    return s;\n}\n\
    \n/**\n * @brief \u30D9\u30EB\u6570 B_0, ..., B_n (n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u8981\u7D20\u3092\u7A7A\u3067\u306A\u3044\u90E8\u5206\u96C6\u5408\
    \u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) O(n log n)\n * \u6307\u6570\u578B\
    \u6BCD\u95A2\u6570\u306F exp(e^x - 1)\n */\ntemplate <typename mint>\nFPS<mint>\
    \ bell_numbers(long long n) {\n    using C = Combination<mint>;\n    C::extend(n);\n\
    \    FPS<mint> g(n + 1, 0);\n    for (long long k = 1; k <= n; k++) g[k] = C::inverse_factorial(k);\n\
    \    FPS<mint> f = exp(g, n + 1);\n    for (long long k = 0; k <= n; k++) f[k]\
    \ *= C::factorial(k);\n    return f;\n}\n"
  code: "#pragma once\n\n/**\n * @file combinatorial-sequences.hpp\n * @brief \u5206\
    \u5272\u6570\u30FB\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u30FB\u30B9\u30BF\u30FC\
    \u30EA\u30F3\u30B0\u6570\u30FB\u30D9\u30EB\u6570 (\u5F62\u5F0F\u7684\u51AA\u7D1A\
    \u6570\u3067 O(n log n))\n */\n\n#include <vector>\n\n#include \"combinatorics.hpp\"\
    \n#include \"convolution.hpp\"\n#include \"fps.hpp\"\n\n/**\n * @brief \u5206\u5272\
    \u6570 p(0), ..., p(n) (n \u3092\u6B63\u306E\u6574\u6570\u306E\u548C\u306B\u5206\
    \u3051\u308B\u65B9\u6CD5\u306E\u6570\u3002\u548C\u306E\u9806\u756A\u306F\u533A\
    \u5225\u3057\u306A\u3044) O(n log n)\n * \u6BCD\u95A2\u6570\u306F 1 / \u03A0_{k\
    \ >= 1} (1 - x^k)\u3002\u5206\u6BCD\u306F\u4E94\u89D2\u6570\u5B9A\u7406\u3067\
    \ \u03A3_k (-1)^k x^{k(3k-1)/2} (k \u306F\u5168\u6574\u6570) \u3068\u66F8\u3051\
    \u308B\n */\ntemplate <typename mint>\nFPS<mint> partition_numbers(long long n)\
    \ {\n    FPS<mint> f(n + 1, 0);\n    f[0] = 1;\n    for (long long k = 1;; k++)\
    \ {\n        const long long a = k * (3 * k - 1) / 2, b = k * (3 * k + 1) / 2;\n\
    \        if (a > n) break;\n        const mint s = k % 2 == 1 ? mint(-1) : mint(1);\n\
    \        f[a] += s;\n        if (b <= n) f[b] += s;\n    }\n    return inv(f,\
    \ n + 1);\n}\n\n/**\n * @brief \u30D9\u30EB\u30CC\u30FC\u30A4\u6570 B_0, ...,\
    \ B_n (B_1 = -1/2 \u3068\u3059\u308B\u6D41\u5100) O(n log n)\n * \u6307\u6570\u578B\
    \u6BCD\u95A2\u6570 x / (e^x - 1) \u3092\u3001(e^x - 1) / x = \u03A3 x^k / (k+1)!\
    \ \u306E\u9006\u6570\u3068\u3057\u3066\u6C42\u3081\u308B\n */\ntemplate <typename\
    \ mint>\nFPS<mint> bernoulli_numbers(long long n) {\n    using C = Combination<mint>;\n\
    \    C::extend(n + 1);\n    FPS<mint> f(n + 1);\n    for (long long k = 0; k <=\
    \ n; k++) f[k] = C::inverse_factorial(k + 1);\n    FPS<mint> g = inv(f, n + 1);\n\
    \    for (long long k = 0; k <= n; k++) g[k] *= C::factorial(k);\n    return g;\n\
    }\n\n/**\n * @brief \u7B26\u53F7\u4ED8\u304D\u7B2C 1 \u7A2E\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u6570 s(n, 0), ..., s(n, n) (x (x-1) ... (x-n+1) = \u03A3 s(n, k)\
    \ x^k) O(n log n)\n * \u4E0B\u964D\u968E\u4E57 f_m(x) = x (x-1) ... (x-m+1) \u3092\
    \u3001f_{2m}(x) = f_m(x) f_m(x - m) \u3068 f_{m+1}(x) = f_m(x) (x - m) \u3067\u500D\
    \u3005\u306B\u4F5C\u308B\n * \u7B26\u53F7\u306A\u3057 (\u9806\u5217\u3092 k \u500B\
    \u306E\u5DE1\u56DE\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) \u306F |s(n,\
    \ k)|\n */\ntemplate <typename mint>\nFPS<mint> stirling_first(long long n) {\n\
    \    FPS<mint> f{1};\n    long long m = 0;\n    for (int bit = 62; bit >= 0; bit--)\
    \ {\n        if (m > 0) {\n            f = f * taylor_shift(f, -mint(m));\n  \
    \          m *= 2;\n        }\n        if (n >> bit & 1) {\n            f = f\
    \ * FPS<mint>{-mint(m), 1};\n            m++;\n        }\n    }\n    f.resize(n\
    \ + 1);\n    return f;\n}\n\n/**\n * @brief \u7B2C 2 \u7A2E\u30B9\u30BF\u30FC\u30EA\
    \u30F3\u30B0\u6570 S(n, 0), ..., S(n, n) (n \u500B\u306E\u533A\u5225\u3067\u304D\
    \u308B\u7389\u3092 k \u500B\u306E\u533A\u5225\u3067\u304D\u306A\u3044\u7A7A\u3067\
    \u306A\u3044\u7BB1\u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) O(n log n)\n\
    \ * S(n, k) = \u03A3_{i=0}^{k} (-1)^{k-i} i^n / (i! (k-i)!) \u3092\u7573\u307F\
    \u8FBC\u307F\u3067\u6C42\u3081\u308B\n */\ntemplate <typename mint>\nFPS<mint>\
    \ stirling_second(long long n) {\n    using C = Combination<mint>;\n    C::extend(n);\n\
    \    std::vector<mint> a(n + 1), b(n + 1);\n    for (long long i = 0; i <= n;\
    \ i++) {\n        a[i] = mint(i).pow(n) * C::inverse_factorial(i);\n        b[i]\
    \ = i % 2 == 0 ? C::inverse_factorial(i) : -C::inverse_factorial(i);\n    }\n\
    \    FPS<mint> s = convolution(a, b);\n    s.resize(n + 1);\n    return s;\n}\n\
    \n/**\n * @brief \u30D9\u30EB\u6570 B_0, ..., B_n (n \u500B\u306E\u533A\u5225\u3067\
    \u304D\u308B\u8981\u7D20\u3092\u7A7A\u3067\u306A\u3044\u90E8\u5206\u96C6\u5408\
    \u306B\u5206\u3051\u308B\u65B9\u6CD5\u306E\u6570) O(n log n)\n * \u6307\u6570\u578B\
    \u6BCD\u95A2\u6570\u306F exp(e^x - 1)\n */\ntemplate <typename mint>\nFPS<mint>\
    \ bell_numbers(long long n) {\n    using C = Combination<mint>;\n    C::extend(n);\n\
    \    FPS<mint> g(n + 1, 0);\n    for (long long k = 1; k <= n; k++) g[k] = C::inverse_factorial(k);\n\
    \    FPS<mint> f = exp(g, n + 1);\n    for (long long k = 0; k <= n; k++) f[k]\
    \ *= C::factorial(k);\n    return f;\n}\n"
  dependsOn:
  - src/math/combinatorics.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/fps.hpp
  isVerificationFile: false
  path: src/math/combinatorial-sequences.hpp
  requiredBy: []
  timestamp: '2026-10-22 14:37:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/combinatorial-sequences.test.cpp
  - test/yosupo/enumerative_combinatorics/stirling-number-of-the-second-kind.test.cpp
  - test/yosupo/enumerative_combinatorics/bell-number.test.cpp
  - test/yosupo/enumerative_combinatorics/partition-function.3.test.cpp
  - test/yosupo/enumerative_combinatorics/stirling-number-of-the-first-kind.test.cpp
  - test/yosupo/number_theory/bernoulli-number.test.cpp
documentation_of: src/math/combinatorial-sequences.hpp
layout: document
title: "\u5206\u5272\u6570\u30FB\u30D9\u30EB\u30CC\u30FC\u30A4\u6570\u30FB\u30B9\u30BF\
  \u30FC\u30EA\u30F3\u30B0\u6570\u30FB\u30D9\u30EB\u6570"
---

数え上げでよく出る数列を、[形式的冪級数](fps.hpp) を使って $O(n \log n)$ でまとめて求めます。どれも長さ $n + 1$ の `FPS<mint>` を返します。

```cpp
using mint = modint998244353;
auto p = partition_numbers<mint>(100);  // p[100] = 190569292
auto B = bernoulli_numbers<mint>(10);   // B[1] = -1/2
auto s = stirling_first<mint>(5);       // s(5, k): x(x-1)(x-2)(x-3)(x-4) の係数
auto S = stirling_second<mint>(5);      // S(5, k)
auto bell = bell_numbers<mint>(10);     // bell[10] = 115975
```

## 関数

`mint` は [modint](modint.hpp) で、法は $n$ より大きい素数であること (階乗の逆数を使うため) です。

| 関数 | 説明 | 求め方 | 計算量 |
|---|---|---|---|
| `partition_numbers<mint>(n)` | 分割数 $p(0), \dots, p(n)$ ($k$ を正の整数の和に分ける方法の数。順番は区別しない) | 母関数 $1 / \prod_{k \ge 1} (1 - x^k)$。分母は五角数定理で $\sum_k (-1)^k x^{k(3k-1)/2}$ | $O(n \log n)$ |
| `bernoulli_numbers<mint>(n)` | ベルヌーイ数 $B_0, \dots, B_n$ ($B_1 = -1/2$ の流儀) | 指数型母関数 $x / (e^x - 1)$ | $O(n \log n)$ |
| `stirling_first<mint>(n)` | 符号付き第 1 種スターリング数 $s(n, 0), \dots, s(n, n)$ ($x (x-1) \cdots (x-n+1) = \sum_k s(n, k) x^k$) | 下降階乗を $f_{2m}(x) = f_m(x) f_m(x - m)$ で倍々に作る ([Taylor shift](fps.hpp)) | $O(n \log n)$ |
| `stirling_second<mint>(n)` | 第 2 種スターリング数 $S(n, 0), \dots, S(n, n)$ ($n$ 個の区別できる玉を $k$ 個の区別できない空でない箱に分ける方法の数) | $S(n, k) = \sum_i (-1)^{k-i} i^n / (i! (k-i)!)$ を畳み込みで | $O(n \log n)$ |
| `bell_numbers<mint>(n)` | ベル数 $B_0, \dots, B_n$ ($k$ 個の区別できる要素を空でない部分集合に分ける方法の数) | 指数型母関数 $\exp(e^x - 1)$ | $O(n \log n)$ |

- 符号なし第 1 種スターリング数 (順列を $k$ 個の巡回に分ける方法の数) は $\lvert s(n, k) \rvert = (-1)^{n-k} s(n, k)$ です。
- ベル数は $B_n = \sum_k S(n, k)$ でもあります。

## 関連

- 階乗・二項係数は [組み合わせ](combinatorics.hpp)
- 母関数の演算は [形式的冪級数](fps.hpp)
