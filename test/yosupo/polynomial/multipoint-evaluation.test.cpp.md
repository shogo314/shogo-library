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
    path: src/math/multipoint.hpp
    title: "\u591A\u70B9\u8A55\u4FA1\u30FB\u591A\u9805\u5F0F\u88DC\u9593\u30FB\u6A19\
      \u672C\u70B9\u306E\u305A\u3089\u3057 (\u7B49\u6BD4\u6570\u5217\u306E\u70B9\u3082\
      )"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "#line 1 \"test/yosupo/polynomial/multipoint-evaluation.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 2 \"src/math/fps.hpp\"\n\n/**\n\
    \ * @file fps.hpp\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <optional>\n#include <queue>\n#include\
    \ <utility>\n#line 14 \"src/math/fps.hpp\"\n\n#line 2 \"src/math/combinatorics.hpp\"\
    \n\n/**\n * @file combinatorics.hpp\n * @brief \u7D44\u307F\u5408\u308F\u305B\n\
    \ */\n\n#line 9 \"src/math/combinatorics.hpp\"\n#include <numeric>\n#line 11 \"\
    src/math/combinatorics.hpp\"\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n\
    /**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#line 10 \"src/math/modular-arithmetic.hpp\"\n#include <cmath>\n\
    #line 12 \"src/math/modular-arithmetic.hpp\"\n#include <unordered_map>\n\n/**\n\
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
    \ modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E x >= 0 (\u306A\u3051\
    \u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step \u3067 O(\u221Am) \u306E\
    \u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long long discrete_log(long\
    \ long a, long long b, long long m) {\n    assert(m >= 1);\n    a %= m, b %= m;\n\
    \    if (a < 0) a += m;\n    if (b < 0) b += m;\n    if (m == 1) return 0;\n \
    \   // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u307E\u3067\
    \u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add / (\u5272\u3063\u305F\
    \ gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a,\
    \ m)) > 1) {\n        if (b == k) return add;\n        if (b % g != 0) return\
    \ -1;\n        b /= g, m /= g, add++;\n        k = modmul(k, a / g, m);\n    }\n\
    \    // k a^x \u2261 b \u3092 x = n p - q (1 <= p <= n\u30010 <= q <= n) \u3068\
    \u66F8\u3044\u3066\u89E3\u304F\n    const long long n = static_cast<long long>(std::sqrt(static_cast<long\
    \ double>(m))) + 1;\n    std::unordered_map<long long, long long> baby;\n    baby.reserve(2\
    \ * n + 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\
    \u3001\u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\
    \u3059\u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long\
    \ long q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n\
    \    const long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k;\
    \ p <= n; p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
    \        if (it != baby.end()) return n * p - it->second + add;\n    }\n    return\
    \ -1;\n}\n\n/**\n * @brief \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^2 \u2261\
    \ a (mod p) \u3068\u306A\u308B x \u306E\u3046\u3061\u5C0F\u3055\u3044\u65B9 (\u306A\
    \u3051\u308C\u3070 -1)\n * @note \u3082\u3046\u4E00\u65B9\u306E\u89E3\u306F p\
    \ - x\u3002Tonelli-Shanks \u3067 O(log^2 p)\n */\ninline long long sqrt_mod(long\
    \ long a, long long p) {\n    assert(p >= 2);\n    a %= p;\n    if (a < 0) a +=\
    \ p;\n    if (a == 0 || p == 2) return a;\n    // \u30AA\u30A4\u30E9\u30FC\u306E\
    \u898F\u6E96: a^((p-1)/2) \u304C 1 \u3067\u306A\u3051\u308C\u3070\u5E73\u65B9\u975E\
    \u5270\u4F59\n    if (modpow(a, (p - 1) / 2, p) != 1) return -1;\n    long long\
    \ q = p - 1, s = 0;\n    while (q % 2 == 0) q /= 2, s++;\n    // \u5E73\u65B9\u975E\
    \u5270\u4F59 z \u3092\u63A2\u3059\n    long long z = 2;\n    while (modpow(z,\
    \ (p - 1) / 2, p) != p - 1) z++;\n    long long c = modpow(z, q, p), t = modpow(a,\
    \ q, p), r = modpow(a, (q + 1) / 2, p);\n    // r^2 = a t \u3092\u4FDD\u3061\u306A\
    \u304C\u3089\u3001t \u306E\u4F4D\u6570\u3092\u4E0B\u3052\u3066\u3044\u304F\n \
    \   while (t != 1) {\n        long long i = 0, tt = t;\n        while (tt != 1)\
    \ tt = modmul(tt, tt, p), i++;\n        long long b = c;\n        for (long long\
    \ j = 0; j < s - i - 1; j++) b = modmul(b, b, p);\n        s = i;\n        c =\
    \ modmul(b, b, p);\n        t = modmul(t, c, p);\n        r = modmul(r, b, p);\n\
    \    }\n    return std::min(r, p - r);\n}\n#line 13 \"src/math/combinatorics.hpp\"\
    \n\n/**\n * @brief \u7D44\u307F\u5408\u308F\u305B\n */\ntemplate <typename Modint>\n\
    class Combination {\n    static std::vector<Modint> fact, inv_fact;\n    static\
    \ long long cached_mod;  // dynamic_modint \u3067 mod \u304C\u5909\u308F\u3063\
    \u305F\u3089\u524D\u8A08\u7B97\u3092\u3084\u308A\u76F4\u3059\n\n   public:\n \
    \   /**\n     * @brief n \u307E\u3067\u306E\u968E\u4E57\u3068\u305D\u306E\u9006\
    \u5143\u3092\u524D\u8A08\u7B97\u3059\u308B\n     * @param n\n     * @note O(n)\
    \ \u5FC5\u8981\u306B\u306A\u3063\u305F\u3089\u547C\u3073\u51FA\u3055\u308C\u308B\
    \u304C\u3001\u4E88\u3081\u5927\u304D\u306An\u306B\u5BFE\u3057\u3066\u547C\u3073\
    \u51FA\u3057\u3066\u304A\u304F\u3053\u3068\u3067\u9006\u5143\u306E\u76F4\u63A5\
    \u8A08\u7B97\u3092\u6E1B\u3089\u305B\u308B\n     */\n    inline static void extend(long\
    \ long n) {\n        if (cached_mod != static_cast<long long>(Modint::mod()))\
    \ {\n            cached_mod = Modint::mod();\n            fact = {1, 1};\n   \
    \         inv_fact = {1, 1};\n        }\n        const long long m = fact.size();\n\
    \        if (n < m) return;\n        fact.resize(n + 1);\n        inv_fact.resize(n\
    \ + 1);\n        for (long long i = m; i <= n; ++i) {\n            fact[i] = fact[i\
    \ - 1] * i;\n        }\n        inv_fact[n] = fact[n].inv();\n        for (long\
    \ long i = n; i > m; --i) {\n            inv_fact[i - 1] = inv_fact[i] * i;\n\
    \        }\n    }\n\n    /**\n     * @brief n \u306E\u968E\u4E57\u3092\u8FD4\u3059\
    \n     * @param n\n     * @return n!\n     * @note extend(n), O(1)\n     */\n\
    \    inline static Modint factorial(long long n) {\n        assert(n >= 0);\n\
    \        extend(n);\n        return fact[n];\n    }\n    /**\n     * @brief n\
    \ \u306E\u968E\u4E57\u306E\u9006\u5143\u3092\u8FD4\u3059\n     * @param n\n  \
    \   * @return n!^-1\n     * @note extend(n), O(1)\n     */\n    inline static\
    \ Modint inverse_factorial(long long n) {\n        assert(n >= 0);\n        extend(n);\n\
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
    \n#include <array>\n#line 11 \"src/math/convolution.hpp\"\n#include <cstdint>\n\
    #include <type_traits>\n#line 15 \"src/math/convolution.hpp\"\n\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line\
    \ 11 \"src/math/modint.hpp\"\n#include <limits>\n#line 14 \"src/math/modint.hpp\"\
    \n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief\
    \ \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <iterator>\n#include\
    \ <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits {\n\
    using std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    using modint = dynamic_modint<-1>;\n#line 18 \"src/math/convolution.hpp\"\n\n\
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
    \ N + M - 1) size <<= 1;\n    return size;\n}\n\n/**\n * @brief x \u306E\u672B\
    \u5C3E\u306E 0 \u306E\u500B\u6570 (x > 0)\n */\nconstexpr int countr_zero(unsigned\
    \ int x) {\n    int k = 0;\n    while (!(x & 1)) x >>= 1, k++;\n    return k;\n\
    }\n\ntemplate <class T>\nstruct is_static_modint : std::false_type {};\ntemplate\
    \ <std::uint32_t Mod>\nstruct is_static_modint<static_modint<Mod>> : std::true_type\
    \ {};\n\n/**\n * @brief NTT \u306E\u56DE\u8EE2\u56E0\u5B50\u306E\u8868 (AtCoder\
    \ Library \u3068\u540C\u3058\u4F5C\u308A)\n *\n * root[i] \u306F 1 \u306E\u539F\
    \u59CB 2^i \u4E57\u6839\u3001rate2\u30FBrate3 \u306F\u57FA\u6570 2\u30FB4 \u306E\
    \u30D0\u30BF\u30D5\u30E9\u30A4\u3067\u6B21\u306E\u30D6\u30ED\u30C3\u30AF\u306B\
    \u9032\u3080\u3068\u304D\u306B\u639B\u3051\u308B\u5024\n */\ntemplate <class mint>\n\
    struct FFTInfo {\n    static constexpr int rank2 = countr_zero(mint::mod() - 1);\n\
    \    std::array<mint, rank2 + 1> root, iroot;\n    std::array<mint, std::max(0,\
    \ rank2 - 1)> rate2, irate2;\n    std::array<mint, std::max(0, rank2 - 2)> rate3,\
    \ irate3;\n\n    FFTInfo() {\n        const mint g = calc_primitive_root(mint::mod());\n\
    \        root[rank2] = g.pow((mint::mod() - 1) >> rank2);\n        iroot[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            iroot[i] = iroot[i +\
    \ 1] * iroot[i + 1];\n        }\n        mint prod = 1, iprod = 1;\n        for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n            rate2[i] = root[i + 2] * prod;\n\
    \            irate2[i] = iroot[i + 2] * iprod;\n            prod *= iroot[i +\
    \ 2];\n            iprod *= root[i + 2];\n        }\n        prod = 1, iprod =\
    \ 1;\n        for (int i = 0; i <= rank2 - 3; i++) {\n            rate3[i] = root[i\
    \ + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n            prod\
    \ *= iroot[i + 3];\n            iprod *= root[i + 3];\n        }\n    }\n};\n\n\
    /**\n * @brief NTT (\u30D3\u30C3\u30C8\u53CD\u8EE2\u306E\u4E26\u3079\u66FF\u3048\
    \u3092\u3057\u306A\u3044\u3002\u7D50\u679C\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\
    \u3057\u305F\u9806\u306B\u4E26\u3076)\u3002\u57FA\u6570 4 \u306E\u30D0\u30BF\u30D5\
    \u30E9\u30A4\u3092\u4F7F\u3046\n * a \u306E\u9577\u3055\u306F 2 \u306E\u3079\u304D\
    \u4E57\u3067\u30012^rank2 \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068\n */\ntemplate\
    \ <class mint>\nvoid butterfly(std::vector<mint>& a) {\n    const int n = static_cast<int>(a.size());\n\
    \    const int h = countr_zero(n);\n    static const FFTInfo<mint> info;\n   \
    \ int len = 0;  // a[i, i + (n >> len), i + 2 * (n >> len), ...] \u306F\u5909\u63DB\
    \u6E08\u307F\n    while (len < h) {\n        if (h - len == 1) {\n           \
    \ int p = 1 << (h - len - 1);\n            mint rot = 1;\n            for (int\
    \ s = 0; s < (1 << len); s++) {\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    mint l = a[i\
    \ + offset], r = a[i + offset + p] * rot;\n                    a[i + offset] =\
    \ l + r;\n                    a[i + offset + p] = l - r;\n                }\n\
    \                if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len++;\n        } else {\n          \
    \  int p = 1 << (h - len - 2);\n            mint rot = 1, imag = info.root[2];\n\
    \            const unsigned long long mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot, rot3 = rot2 * rot;\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    unsigned long\
    \ long a0 = a[i + offset].val();\n                    unsigned long long a1 =\
    \ 1ULL * a[i + offset + p].val() * rot.val();\n                    unsigned long\
    \ long a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n               \
    \     unsigned long long a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n\
    \                    unsigned long long a1na3imag = 1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    unsigned long long na2 = mod2 - a2;\n   \
    \                 a[i + offset] = mint(a0 + a2 + a1 + a3);\n                 \
    \   a[i + offset + p] = mint(a0 + a2 + (2 * mod2 - (a1 + a3)));\n            \
    \        a[i + offset + 2 * p] = mint(a0 + na2 + a1na3imag);\n               \
    \     a[i + offset + 3 * p] = mint(a0 + na2 + (mod2 - a1na3imag));\n         \
    \       }\n                if (s + 1 != (1 << len)) rot *= info.rate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief butterfly \u306E\u9006\u5909\u63DB (n \u3067\u5272\u3089\u306A\u3044\
    )\n */\ntemplate <class mint>\nvoid butterfly_inv(std::vector<mint>& a) {\n  \
    \  const int n = static_cast<int>(a.size());\n    const int h = countr_zero(n);\n\
    \    static const FFTInfo<mint> info;\n    int len = h;\n    while (len) {\n \
    \       if (len == 1) {\n            int p = 1 << (h - len);\n            mint\
    \ irot = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n      \
    \          int offset = s << (h - len + 1);\n                for (int i = 0; i\
    \ < p; i++) {\n                    mint l = a[i + offset], r = a[i + offset +\
    \ p];\n                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = mint(1ULL * (mint::mod() + l.val() - r.val()) * irot.val());\n      \
    \          }\n                if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len--;\n        } else {\n          \
    \  int p = 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n\
    \            for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint\
    \ irot2 = irot * irot, irot3 = irot2 * irot;\n                int offset = s <<\
    \ (h - len + 2);\n                for (int i = 0; i < p; i++) {\n            \
    \        unsigned long long a0 = a[i + offset].val();\n                    unsigned\
    \ long long a1 = a[i + offset + p].val();\n                    unsigned long long\
    \ a2 = a[i + offset + 2 * p].val();\n                    unsigned long long a3\
    \ = a[i + offset + 3 * p].val();\n                    unsigned long long a2na3iimag\
    \ = mint((mint::mod() + a2 - a3) * iimag.val()).val();\n                    a[i\
    \ + offset] = mint(a0 + a1 + a2 + a3);\n                    a[i + offset + p]\
    \ = mint((a0 + (mint::mod() - a1) + a2na3iimag) * irot.val());\n             \
    \       a[i + offset + 2 * p] = mint((a0 + a1 + (mint::mod() - a2) + (mint::mod()\
    \ - a3)) * irot2.val());\n                    a[i + offset + 3 * p] = mint((a0\
    \ + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) * irot3.val());\n       \
    \         }\n                if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len -= 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief NTT \u3067\u7573\u307F\u8FBC\u3080 (\u6CD5\u306F\u7D20\u6570\u3067\u3001\
    \u9577\u3055 N + M - 1 \u4EE5\u4E0A\u306E 2 \u306E\u3079\u304D\u4E57\u304C 2^rank2\
    \ \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068)\n * same \u306A\u3089 B \u306F A\
    \ \u3068\u540C\u3058\u3068\u307F\u306A\u3057\u3001\u5909\u63DB\u3092 1 \u56DE\u7701\
    \u304F\n */\ntemplate <class mint>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b, bool same = false) {\n    const int n = static_cast<int>(a.size()),\
    \ m = static_cast<int>(b.size());\n    const int z = get_fft_size(n, m);\n   \
    \ a.resize(z);\n    butterfly(a);\n    if (same) {\n        for (int i = 0; i\
    \ < z; i++) a[i] *= a[i];\n    } else {\n        b.resize(z);\n        butterfly(b);\n\
    \        for (int i = 0; i < z; i++) a[i] *= b[i];\n    }\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    const mint iz = mint(z).inv();\n    for (int i\
    \ = 0; i < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n/**\n * @brief mint\
    \ \u3067\u76F4\u63A5 NTT \u3067\u304D\u308B\u304B (static_modint \u3067\u3001\u6CD5\
    \u304C\u7D20\u6570\u3067\u30012^rank2 \u304C\u9577\u3055 z \u4EE5\u4E0A)\n */\n\
    template <class mint>\nconstexpr bool ntt_friendly(int z) {\n    if constexpr\
    \ (is_static_modint<mint>::value) {\n        return internal_modint::is_prime32(mint::mod())\
    \ && mint::mod() > 2 && (mint::mod() - 1) % z == 0;\n    } else {\n        return\
    \ false;\n    }\n}\n\n/**\n * @brief \u9577\u3055 61 \u4EE5\u4E0A\u306E\u7573\u307F\
    \u8FBC\u307F\u3092 mint \u3067\u76F4\u63A5 NTT \u3067\u304D\u308B\u898B\u8FBC\u307F\
    \u304C\u3042\u308B\u304B (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u6C7A\u307E\
    \u308B\u90E8\u5206\u3060\u3051)\n * \u507D\u306A\u3089 NTT \u306E\u95A2\u6570\u3092\
    \u5B9F\u4F53\u5316\u3057\u306A\u3044 (\u6CD5 - 1 \u306E 2 \u306E\u6307\u6570\u304C\
    \u5C0F\u3055\u3044\u3068\u3001\u56DE\u8EE2\u56E0\u5B50\u306E\u8868\u306E\u5916\
    \u3092\u8AAD\u3080\u3068\u3044\u3046\u8AA4\u3063\u305F\u8B66\u544A\u304C\u51FA\
    \u308B\u305F\u3081)\n */\ntemplate <class mint>\nconstexpr bool ntt_candidate()\
    \ {\n    if constexpr (is_static_modint<mint>::value) {\n        return countr_zero(mint::mod()\
    \ - 1) >= 7;\n    } else {\n        return false;\n    }\n}\n\nstatic constexpr\
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
    \ res;\n}\n};  // namespace internal_convolution\n\nnamespace internal_convolution\
    \ {\n/**\n * @brief 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\u3067\u5024 (0 \u4EE5\u4E0A MOD0 MOD1 MOD2 \u672A\
    \u6E80) \u3092\u5FA9\u5143\u3059\u308B\n * \u5024\u306F y0 + y1 MOD0 + y2 MOD0\
    \ MOD1 (0 <= y0 < MOD0\u30010 <= y1 < MOD1\u30010 <= y2 < MOD2) \u306E\u5F62\u306B\
    \u306A\u308A\u3001\u5404\u9805\u3092 f(y0, y1, y2) \u3067\u7D44\u307F\u7ACB\u3066\
    \u308B\n * A \u3068 B \u304C\u540C\u3058\u914D\u5217\u306A\u3089\u3001\u5909\u63DB\
    \u3092 1 \u56DE\u7701\u304F\n */\ntemplate <class T, class R, class F>\nstd::vector<R>\
    \ convolution_crt(const std::vector<T>& A, const std::vector<T>& B, F f) {\n \
    \   const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<mint0> a0(N), b0(M);\n    std::vector<mint1> a1(N), b1(M);\n\
    \    std::vector<mint2> a2(N), b2(M);\n    for (int i = 0; i < N; ++i) a0[i] =\
    \ A[i], a1[i] = A[i], a2[i] = A[i];\n    for (int i = 0; i < M; ++i) b0[i] = B[i],\
    \ b1[i] = B[i], b2[i] = B[i];\n    const bool same = &A == &B;\n    auto c0 =\
    \ convolution_fft(std::move(a0), std::move(b0), same);\n    auto c1 = convolution_fft(std::move(a1),\
    \ std::move(b1), same);\n    auto c2 = convolution_fft(std::move(a2), std::move(b2),\
    \ same);\n    std::vector<R> res(N + M - 1);\n    for (int i = 0; i < N + M -\
    \ 1; ++i) {\n        unsigned int y0 = c0[i].val();\n        unsigned int y1 =\
    \ (imod0 * (c1[i] - y0)).val();\n        unsigned int y2 = (imod01 * (c2[i] -\
    \ y0) - imod1 * y1).val();\n        res[i] = f(y0, y1, y2);\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief convolution_u64 \u306E 1 \u3064\u306E\u6CD5\u3067\u306E\
    \u8A08\u7B97\u3002A = A0 + A1 2^32\u3001B = B0 + B1 2^32 \u3068\u5206\u3051\u3001\
    \n * A0 B0 \u3068 A0 B1 + A1 B0 \u306E\u7573\u307F\u8FBC\u307F\u3092\u30014 \u56DE\
    \u306E\u5909\u63DB\u3068 2 \u56DE\u306E\u9006\u5909\u63DB\u3067\u6C42\u3081\u308B\
    \n */\ntemplate <class mint>\nstd::array<std::vector<mint>, 2> convolution_u64_parts(const\
    \ std::vector<unsigned long long>& A, const std::vector<unsigned long long>& B,\
    \ int z) {\n    const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<mint> a0(z), a1(z), b0(z), b1(z);\n    for (int i = 0; i < N;\
    \ ++i) a0[i] = A[i] & 0xffffffffULL, a1[i] = A[i] >> 32;\n    for (int i = 0;\
    \ i < M; ++i) b0[i] = B[i] & 0xffffffffULL, b1[i] = B[i] >> 32;\n    butterfly(a0),\
    \ butterfly(a1), butterfly(b0), butterfly(b1);\n    for (int i = 0; i < z; ++i)\
    \ {\n        const mint x0 = a0[i], x1 = a1[i];\n        a0[i] = x0 * b0[i];\n\
    \        a1[i] = x0 * b1[i] + x1 * b0[i];\n    }\n    butterfly_inv(a0), butterfly_inv(a1);\n\
    \    a0.resize(N + M - 1), a1.resize(N + M - 1);\n    const mint iz = mint(z).inv();\n\
    \    for (int i = 0; i < N + M - 1; ++i) a0[i] *= iz, a1[i] *= iz;\n    return\
    \ {a0, a1};\n}\n}  // namespace internal_convolution\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n *\n * static_modint \u3067\u6CD5\u304C NTT \u306B\u5411\
    \u304F\u7D20\u6570 (998244353 \u306A\u3069) \u306A\u3089\u3001\u305D\u306E\u6CD5\
    \u3067\u76F4\u63A5 NTT \u3059\u308B\u3002\n * \u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\u3067\u5FA9\u5143\u3059\u308B\n * @param A vector<mint>\n *\
    \ @param B vector<mint>\n * @return vector<mint>\n */\ntemplate <class mint>\n\
    std::vector<mint> convolution(const std::vector<mint>& A, const std::vector<mint>&\
    \ B) {\n    if (A.empty() || B.empty()) return {};\n    const int N = static_cast<int>(A.size()),\
    \ M = static_cast<int>(B.size());\n    if (std::min(N, M) <= 60) return internal_convolution::naive(A,\
    \ B);\n    const int z = internal_convolution::get_fft_size(N, M);\n    if constexpr\
    \ (internal_convolution::ntt_candidate<mint>()) {\n        if (internal_convolution::ntt_friendly<mint>(z))\
    \ return internal_convolution::convolution_fft(A, B, &A == &B);\n    }\n    std::vector<unsigned\
    \ int> a(N), b(M);\n    for (int i = 0; i < N; ++i) a[i] = A[i].val();\n    for\
    \ (int i = 0; i < M; ++i) b[i] = B[i].val();\n    const mint mod0 = internal_convolution::MOD0,\
    \ mod01 = mod0 * internal_convolution::MOD1;\n    return internal_convolution::convolution_crt<unsigned\
    \ int, mint>(a, &A == &B ? a : b, [&](unsigned int y0, unsigned int y1, unsigned\
    \ int y2) {\n        return mod01 * y2 + mod0 * y1 + y0;\n    });\n}\n\n/**\n\
    \ * @brief long long\u306E\u7573\u307F\u8FBC\u307F\n * \u7D50\u679C\u306E\u5404\
    \u9805\u306E\u7D76\u5BFE\u5024\u304C MOD0 MOD1 MOD2 / 2 (\u7D04 3 * 10^25) \u672A\
    \u6E80\u3067\u3001long long \u306B\u53CE\u307E\u308B\u3053\u3068\n * @param A\
    \ vector<long long>\n * @param B vector<long long>\n * @return vector<long long>\n\
    \ */\ninline std::vector<long long> convolution_ll(const std::vector<long long>&\
    \ A, const std::vector<long long>& B) {\n    if (A.empty() || B.empty()) return\
    \ {};\n    const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) <= 60) return internal_convolution::naive(A, B);\n   \
    \ static const long long mod0 = internal_convolution::MOD0, mod01 = mod0 * internal_convolution::MOD1;\n\
    \    static const __int128_t mod012 = static_cast<__int128_t>(mod01) * internal_convolution::MOD2;\n\
    \    return internal_convolution::convolution_crt<long long, long long>(A, B,\
    \ [&](unsigned int y0, unsigned int y1, unsigned int y2) {\n        __int128_t\
    \ tmp = static_cast<__int128_t>(mod01) * y2 + static_cast<__int128_t>(mod0) *\
    \ y1 + y0;\n        return static_cast<long long>(tmp < (mod012 >> 1) ? tmp :\
    \ tmp - mod012);\n    });\n}\n\n/**\n * @brief unsigned long long \u306E\u7573\
    \u307F\u8FBC\u307F\u3092 2^64 \u3067\u5272\u3063\u305F\u4F59\u308A\u3067\u6C42\
    \u3081\u308B\n * \u5404\u5024\u3092 32 \u30D3\u30C3\u30C8\u305A\u3064 2 \u3064\
    \u306B\u5206\u3051\u3001\u4E0B\u4F4D\u3069\u3046\u3057\u306E\u7A4D\u306E\u548C\
    \u3068\u3001\u4E0A\u4F4D\u3068\u4E0B\u4F4D\u306E\u7A4D\u306E\u548C\u3092 3 \u3064\
    \u306E\u6CD5\u3068\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\u3067\u6C42\u3081\u308B\
    \u3002\n * \u548C\u306E\u9805\u306E\u6570 min(|A|, |B|) \u304C 10^6 \u4EE5\u4E0B\
    \u3067\u3042\u308B\u3053\u3068 (\u548C\u304C MOD0 MOD1 MOD2 \u672A\u6E80\u306B\
    \u53CE\u307E\u308B)\n * @param A vector<unsigned long long>\n * @param B vector<unsigned\
    \ long long>\n * @return vector<unsigned long long>\n */\ninline std::vector<unsigned\
    \ long long> convolution_u64(const std::vector<unsigned long long>& A, const std::vector<unsigned\
    \ long long>& B) {\n    if (A.empty() || B.empty()) return {};\n    const int\
    \ N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n    if (std::min(N,\
    \ M) <= 60) return internal_convolution::naive(A, B);\n    assert(std::min(N,\
    \ M) <= 1000000);\n    using namespace internal_convolution;\n    const int z\
    \ = get_fft_size(N, M);\n    const auto [p0, q0] = convolution_u64_parts<mint0>(A,\
    \ B, z);\n    const auto [p1, q1] = convolution_u64_parts<mint1>(A, B, z);\n \
    \   const auto [p2, q2] = convolution_u64_parts<mint2>(A, B, z);\n    // \u5024\
    \u306F y0 + y1 MOD0 + y2 MOD0 MOD1 \u306A\u306E\u3067\u3001unsigned long long\
    \ \u3067\u8A08\u7B97\u3059\u308C\u3070 2^64 \u3067\u5272\u3063\u305F\u4F59\u308A\
    \u306B\u306A\u308B\n    constexpr unsigned long long mod01 = static_cast<unsigned\
    \ long long>(MOD0) * MOD1;\n    auto restore = [&](mint0 c0, mint1 c1, mint2 c2)\
    \ {\n        const unsigned int y0 = c0.val();\n        const unsigned int y1\
    \ = (imod0 * (c1 - y0)).val();\n        const unsigned int y2 = (imod01 * (c2\
    \ - y0) - imod1 * y1).val();\n        return y0 + static_cast<unsigned long long>(y1)\
    \ * MOD0 + y2 * mod01;\n    };\n    std::vector<unsigned long long> res(N + M\
    \ - 1);\n    for (int i = 0; i < N + M - 1; ++i) res[i] = restore(p0[i], p1[i],\
    \ p2[i]) + (restore(q0[i], q1[i], q2[i]) << 32);\n    return res;\n}\n#line 18\
    \ \"src/math/fps.hpp\"\n\ntemplate <typename mint>\nstruct FPS;\n\nnamespace internal_fps\
    \ {\ntemplate <typename mint>\nFPS<mint> gcd(const FPS<mint>& f, const FPS<mint>&\
    \ g);\n\n// \u4EE5\u4E0B\u306F\u6CD5\u304C NTT \u306B\u5411\u304F\u7D20\u6570\u306E\
    \u3068\u304D\u306E inv\u30FBexp\u3002NTT \u3057\u305F\u5024\u3092\u4F7F\u3044\u56DE\
    \u3057\u3001\u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3067\u6C5A\u308C\u306A\u3044\
    \u4FC2\u6570\u3060\u3051\u3092\u53D6\u308A\u51FA\u3059\u3002\n// butterfly \u306E\
    \u7D50\u679C\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\u3057\u305F\u9806\u306B\u4E26\
    \u3076\u306E\u3067\u3001\u9577\u3055 2m \u306E\u5909\u63DB\u306E\u524D\u534A\u306F\
    \u3001x^m - 1 \u3067\u5272\u3063\u305F\u4F59\u308A\u306E\u9577\u3055 m \u306E\u5909\
    \u63DB\u306B\u306A\u308B\n\n// \u9577\u3055 2^k \u306E NTT \u3068\u9006\u5909\u63DB\
    \ (n \u3067\u5272\u308B)\ntemplate <typename mint>\nvoid ntt(std::vector<mint>&\
    \ a) {\n    internal_convolution::butterfly(a);\n}\ntemplate <typename mint>\n\
    void intt(std::vector<mint>& a) {\n    internal_convolution::butterfly_inv(a);\n\
    \    const mint in = mint(a.size()).inv();\n    for (auto& x : a) x *= in;\n}\n\
    \n// \u9577\u3055 n \u4EE5\u4E0A\u306E\u5909\u63DB\u3092 mint \u3067\u76F4\u63A5\
    \ NTT \u3067\u304D\u308B\u304B (internal_convolution::ntt_candidate<mint>() \u306E\
    \u3068\u304D\u3060\u3051\u547C\u3076)\ntemplate <typename mint>\nbool use_ntt(long\
    \ long n) {\n    long long z = 1;\n    while (z < n) z <<= 1;\n    return z <=\
    \ (1 << 23) && internal_convolution::ntt_friendly<mint>(static_cast<int>(z));\n\
    }\n\n// 1 / f \u306E\u5148\u982D deg \u9805 (f[0] != 0\u3001deg >= 1)\u30021 \u6BB5\
    \ (m -> 2m) \u3042\u305F\u308A\u9577\u3055 2m \u306E NTT 5 \u56DE\ntemplate <typename\
    \ mint>\nstd::vector<mint> inv_ntt(const std::vector<mint>& f, long long deg)\
    \ {\n    std::vector<mint> g = {f[0].inv()};\n    for (long long m = 1; m < deg;\
    \ m <<= 1) {\n        // F G = 1 + (x^m \u4EE5\u4E0A\u306E\u9805)\u3002\u5DE1\u56DE\
    \u7573\u307F\u8FBC\u307F\u306E\u6298\u308A\u8FD4\u3057\u306F [0, m) \u306B\u3057\
    \u304B\u6765\u306A\u3044\n        std::vector<mint> F(2 * m), G(2 * m);\n    \
    \    std::copy(f.begin(), f.begin() + std::min<long long>(f.size(), 2 * m), F.begin());\n\
    \        std::copy(g.begin(), g.end(), G.begin());\n        ntt(F), ntt(G);\n\
    \        for (long long i = 0; i < 2 * m; i++) F[i] *= G[i];\n        intt(F);\n\
    \        std::fill(F.begin(), F.begin() + m, mint(0));\n        // g <- g - g\
    \ (F G - 1) \u306E [m, 2m) \u306E\u90E8\u5206\n        ntt(F);\n        for (long\
    \ long i = 0; i < 2 * m; i++) F[i] *= G[i];\n        intt(F);\n        for (long\
    \ long i = m; i < 2 * m; i++) g.push_back(-F[i]);\n    }\n    g.resize(deg);\n\
    \    return g;\n}\n\n// exp(f) \u306E\u5148\u982D deg \u9805 (f[0] == 0\u3001\
    deg >= 1)\u3002exp(f) = b \u3068 1 / b \u3092\u540C\u6642\u306B\u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\u3067\u500D\u3005\u306B\u4F38\u3070\u3059\ntemplate <typename\
    \ mint>\nstd::vector<mint> exp_ntt(const std::vector<mint>& f, long long deg)\
    \ {\n    using C = Combination<mint>;\n    C::extend(2 * deg);\n    auto at =\
    \ [&](long long i) { return i < static_cast<long long>(f.size()) ? f[i] : mint(0);\
    \ };\n    // b = exp(f) mod x^m\u3001c = 1 / b mod x^{m/2}\u3001Zc = c \u306E\u9577\
    \u3055 m \u306E\u5909\u63DB\n    std::vector<mint> b = {1, at(1)}, c = {1}, Zc\
    \ = {1, 1};\n    for (long long m = 2; m < deg; m <<= 1) {\n        std::vector<mint>\
    \ Y(b);\n        Y.resize(2 * m);\n        ntt(Y);\n        // c \u3092 1 / b\
    \ mod x^m \u306B\u4F38\u3070\u3059: c <- c - c (b c - 1)\u3002b c - 1 \u306F [m/2,\
    \ m) \u3060\u3051\u53D6\u308A\u51FA\u305B\u3070\u6298\u308A\u8FD4\u3057\u306B\u6C5A\
    \u308C\u306A\u3044\n        {\n            std::vector<mint> z(m);\n         \
    \   for (long long i = 0; i < m; i++) z[i] = Y[i] * Zc[i];\n            intt(z);\n\
    \            std::fill(z.begin(), z.begin() + m / 2, mint(0));\n            ntt(z);\n\
    \            for (long long i = 0; i < m; i++) z[i] *= -Zc[i];\n            intt(z);\n\
    \            c.insert(c.end(), z.begin() + m / 2, z.end());\n        }\n     \
    \   Zc = c;\n        Zc.resize(2 * m);\n        ntt(Zc);\n        // R = b f'\
    \ - b' (f' \u306F x^{m-1} \u672A\u6E80)\u3002x^{m-1} \u672A\u6E80\u306F 0 \u3067\
    \u3001\u5DE1\u56DE\u7573\u307F\u8FBC\u307F\u3067 [0, m-1) \u306B\u6298\u308A\u8FD4\
    \u3063\u305F x^m \u4EE5\u4E0A\u306E\u9805\u3092\u623B\u3059\n        std::vector<mint>\
    \ x(m);\n        for (long long i = 0; i < m - 1; i++) x[i] = at(i + 1) * (i +\
    \ 1);\n        ntt(x);\n        for (long long i = 0; i < m; i++) x[i] *= Y[i];\n\
    \        intt(x);\n        for (long long i = 0; i < m - 1; i++) x[i] -= b[i +\
    \ 1] * (i + 1);\n        x.resize(2 * m);\n        for (long long i = 0; i < m\
    \ - 1; i++) x[m + i] = x[i], x[i] = 0;\n        // R / b = f' - b' / b \u306E\
    \ [m - 1, 2m - 1) \u3092\u7A4D\u5206\u3059\u308B\u3068\u3001f - log b \u306E [m,\
    \ 2m)\n        ntt(x);\n        for (long long i = 0; i < 2 * m; i++) x[i] *=\
    \ Zc[i];\n        intt(x);\n        for (long long i = 2 * m - 1; i >= m; i--)\
    \ x[i] = x[i - 1] * C::inv(i) + at(i);\n        std::fill(x.begin(), x.begin()\
    \ + m, mint(0));\n        // b <- b + b (f - log b) \u306E [m, 2m)\n        ntt(x);\n\
    \        for (long long i = 0; i < 2 * m; i++) x[i] *= Y[i];\n        intt(x);\n\
    \        b.insert(b.end(), x.begin() + m, x.end());\n    }\n    b.resize(deg);\n\
    \    return b;\n}\n}  // namespace internal_fps\n\ntemplate <typename mint>\n\
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
    \        if constexpr (internal_convolution::ntt_candidate<mint>()) {\n      \
    \      if (internal_fps::use_ntt<mint>(2 * deg)) return internal_fps::inv_ntt<mint>(f,\
    \ deg);\n        }\n        FPS res({mint(1) / f[0]});\n        for (long long\
    \ i = 1; i < deg; i <<= 1) {\n            res = (res + res - res * res * f.pre(i\
    \ << 1)).pre(i << 1);\n        }\n        res.resize(deg);\n        return res;\n\
    \    }\n    inline friend FPS inv(const FPS& f) {\n        return inv(f, f.size());\n\
    \    }\n\n    // division, r must be normalized (r.back() must not be 0)\n   \
    \ inline FPS& operator/=(const FPS& r) {\n        assert(!r.empty());\n      \
    \  assert(r.back() != 0);\n        this->normalize();\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        const long long need = static_cast<long long>(this->size()) - static_cast<long\
    \ long>(r.size()) + 1;\n        *this = ((*this).rev().pre(need) * inv(r.rev(),\
    \ need)).pre(need).rev();\n        return *this;\n    }\n    inline FPS& operator%=(const\
    \ FPS& r) {\n        return *this = divmod(*this, r).second;\n    }\n    inline\
    \ FPS operator/(const FPS& r) const { return FPS(*this) /= r; }\n    inline FPS\
    \ operator%(const FPS& r) const { return FPS(*this) %= r; }\n    // {f / g, f\
    \ % g}, g must be normalized (g.back() must not be 0)\n    inline friend std::pair<FPS,\
    \ FPS> divmod(const FPS& f, const FPS& g) {\n        assert(!g.empty());\n   \
    \     assert(g.back() != 0);\n        FPS q = f / g;\n        FPS r = f - q *\
    \ g;\n        return {q, r};\n    }\n\n    // log(f) = \\int f'/f dx, f[0] must\
    \ be 1\n    inline friend FPS log(const FPS& f, long long deg) {\n        assert(!f.empty()\
    \ && f[0] == 1);\n        if (deg < 0) deg = static_cast<long long>(f.size());\n\
    \        FPS res = intg(diff(f) * inv(f, deg));\n        res.resize(deg);\n  \
    \      return res;\n    }\n    inline friend FPS log(const FPS& f) {\n       \
    \ return log(f, f.size());\n    }\n\n    // exp(f), f[0] must be 0\n    inline\
    \ friend FPS exp(const FPS& f, long long deg) {\n        assert(f.empty() || f[0]\
    \ == 0);\n        if (deg < 0) deg = static_cast<long long>(f.size());\n     \
    \   if (deg == 0) return FPS();\n        if constexpr (internal_convolution::ntt_candidate<mint>())\
    \ {\n            if (internal_fps::use_ntt<mint>(2 * deg)) return internal_fps::exp_ntt<mint>(f,\
    \ deg);\n        }\n        FPS res(1, 1);\n        for (long long i = 1; i <\
    \ deg; i <<= 1) {\n            res = res * (f.pre(i << 1) - log(res, i << 1) +\
    \ 1).pre(i << 1);\n        }\n        res.resize(deg);\n        return res;\n\
    \    }\n    inline friend FPS exp(const FPS& f) {\n        return exp(f, f.size());\n\
    \    }\n\n    // pow(f) = exp(e * log f)\n    inline friend FPS pow(const FPS&\
    \ f, long long e, long long deg) {\n        if (deg < 0) deg = static_cast<long\
    \ long>(f.size());\n        if (e == 0) {\n            auto ret = FPS(deg, 0);\n\
    \            if (deg > 0) ret[0] = 1;\n            return ret;\n        }\n  \
    \      long long i = 0;\n        while (i < static_cast<long long>(f.size()) &&\
    \ f[i] == 0) ++i;\n        if (i == static_cast<long long>(f.size())) return FPS(deg,\
    \ 0);\n        if ((i >= 1 && e >= deg) || i * e >= deg) return FPS(deg, 0);\n\
    \        mint k = f[i];\n        FPS res = exp(log((f >> i) / k, deg) * e, deg)\
    \ * k.pow(e) << (e * i);\n        res.resize(deg);\n        return res;\n    }\n\
    \    inline friend FPS pow(const FPS& f, long long e) {\n        return pow(f,\
    \ e, f.size());\n    }\n\n    // sqrt(f) (g^2 = f \u3068\u306A\u308B g) \u306E\
    \u5148\u982D deg \u9805\u3002\u6CD5\u306F\u7D20\u6570\u3067\u3042\u308B\u3053\u3068\
    \n    // f = 0 \u306A\u3089 0\u3002\u6700\u521D\u306E 0 \u3067\u306A\u3044\u9805\
    \ f_i x^i \u306E i \u304C\u5947\u6570\u304B\u3001f_i \u304C\u5E73\u65B9\u975E\u5270\
    \u4F59\u306A\u3089\u5E73\u65B9\u6839\u306F\u306A\u304F std::nullopt (deg \u306B\
    \u3088\u3089\u306A\u3044)\n    inline friend std::optional<FPS> sqrt(const FPS&\
    \ f, long long deg) {\n        if (deg < 0) deg = static_cast<long long>(f.size());\n\
    \        long long i = 0;\n        while (i < static_cast<long long>(f.size())\
    \ && f[i] == 0) ++i;\n        if (i == static_cast<long long>(f.size())) return\
    \ FPS(deg, 0);\n        if (i % 2 == 1) return std::nullopt;\n        long long\
    \ r = sqrt_mod(f[i].val(), mint::mod());\n        if (r == -1) return std::nullopt;\n\
    \        if (i / 2 >= deg) return FPS(deg, 0);\n        // x^i \u3092\u5916\u3057\
    \u305F g = f / x^i (g_0 != 0) \u306E\u5E73\u65B9\u6839\u3092\u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\u3067\u6C42\u3081\u308B: h <- (h + g / h) / 2\n        const\
    \ FPS g = f >> i;\n        const long long d = deg - i / 2;\n        FPS h({mint(r)});\n\
    \        const mint inv2 = mint(2).inv();\n        for (long long k = 1; k < d;\
    \ k <<= 1) {\n            h = (h + (g.pre(k << 1) * inv(h, k << 1)).pre(k << 1))\
    \ * inv2;\n        }\n        h.resize(d);\n        h <<= i / 2;\n        return\
    \ h;\n    }\n    inline friend std::optional<FPS> sqrt(const FPS& f) {\n     \
    \   return sqrt(f, f.size());\n    }\n\n    inline friend FPS taylor_shift(FPS\
    \ f, mint a) {\n        using C = Combination<mint>;\n        int n = f.size();\n\
    \        C::extend(n);\n        for (int i = 0; i < n; i++) f[i] *= C::factorial(i);\n\
    \        std::reverse(f.begin(), f.end());\n        FPS<mint> g(n, 1);\n     \
    \   for (int i = 1; i < n; i++) g[i] = g[i - 1] * a * C::inv(i);\n        f =\
    \ (f * g).pre(n);\n        std::reverse(f.begin(), f.end());\n        for (int\
    \ i = 0; i < n; i++) f[i] *= C::inverse_factorial(i);\n        return f;\n   \
    \ }\n};\n\nnamespace internal_fps {\ntemplate <typename mint>\nFPS<mint> shrink(FPS<mint>\
    \ f) {\n    f.normalize();\n    return f;\n}\n\n// x^k \u3067\u5272\u3063\u3066\
    \u4F4E\u6B21\u306E\u9805\u3092\u6368\u3066\u308B\u3002\u9577\u3055\u304C k \u4EE5\
    \u4E0B\u306A\u3089 0 (\u7A7A)\ntemplate <typename mint>\nFPS<mint> drop(const\
    \ FPS<mint>& f, long long k) {\n    if (static_cast<long long>(f.size()) <= k)\
    \ return FPS<mint>();\n    return FPS<mint>(f.begin() + k, f.end());\n}\n\n//\
    \ \u884C\u5217\u306E\u6210\u5206\u306E\u7A4D\u548C \u03A3_j x[i][j] y[j][k] \u3092\
    \u3001\u5404\u6210\u5206\u3092 1 \u56DE\u305A\u3064 NTT \u3057\u3066\u6C42\u3081\
    \u308B (\u6CD5\u304C NTT \u306B\u5411\u304D\u3001\u9577\u3055\u304C\u5341\u5206\
    \u9577\u3044\u3068\u304D\u3060\u3051)\n// x \u306F rows \xD7 2\u3001y \u306F 2\
    \ \xD7 cols\u3002\u7D50\u679C\u306F rows \xD7 cols\u3002\u4F7F\u3048\u306A\u3051\
    \u308C\u3070 false \u3092\u8FD4\u3059\ntemplate <typename mint>\nbool mat_mul_ntt(const\
    \ FPS<mint>* const* x, int rows, const FPS<mint>* const* y, int cols, FPS<mint>*\
    \ res) {\n    if constexpr (!internal_convolution::ntt_candidate<mint>()) {\n\
    \        return false;\n    } else {\n        long long len = 0, small = 1LL <<\
    \ 60;\n        for (int i = 0; i < rows; i++)\n            for (int j = 0; j <\
    \ 2; j++)\n                for (int k = 0; k < cols; k++) {\n                \
    \    const long long s1 = x[i * 2 + j]->size(), s2 = y[j * cols + k]->size();\n\
    \                    if (s1 == 0 || s2 == 0) continue;\n                    len\
    \ = std::max(len, s1 + s2 - 1), small = std::min(small, std::min(s1, s2));\n \
    \               }\n        // \u77ED\u3044\u3082\u306E\u306F\u666E\u901A\u306B\
    \u639B\u3051\u305F\u307B\u3046\u304C\u901F\u3044\n        if (len == 0 || small\
    \ <= 64 || !use_ntt<mint>(len)) return false;\n        long long z = 1;\n    \
    \    while (z < len) z <<= 1;\n        auto transform = [&](const FPS<mint>& f)\
    \ {\n            std::vector<mint> t(z);\n            std::copy(f.begin(), f.end(),\
    \ t.begin());\n            ntt(t);\n            return t;\n        };\n      \
    \  std::vector<std::vector<mint>> tx(rows * 2), ty(2 * cols);\n        for (int\
    \ i = 0; i < rows * 2; i++) tx[i] = transform(*x[i]);\n        for (int i = 0;\
    \ i < 2 * cols; i++) ty[i] = transform(*y[i]);\n        for (int i = 0; i < rows;\
    \ i++)\n            for (int k = 0; k < cols; k++) {\n                std::vector<mint>\
    \ t(z);\n                for (long long e = 0; e < z; e++) t[e] = tx[i * 2][e]\
    \ * ty[k][e] + tx[i * 2 + 1][e] * ty[cols + k][e];\n                intt(t);\n\
    \                t.resize(len);\n                res[i * cols + k] = shrink(FPS<mint>(std::move(t)));\n\
    \            }\n        return true;\n    }\n}\n\n// \u591A\u9805\u5F0F\u3092\u6210\
    \u5206\u306B\u6301\u3064 2x2 \u884C\u5217 [[a, b], [c, d]]\ntemplate <typename\
    \ mint>\nstruct Mat {\n    FPS<mint> a, b, c, d;\n    static Mat identity() {\
    \ return {FPS<mint>{1}, FPS<mint>(), FPS<mint>(), FPS<mint>{1}}; }\n    Mat operator*(const\
    \ Mat& r) const {\n        const FPS<mint>* x[4] = {&a, &b, &c, &d};\n       \
    \ const FPS<mint>* y[4] = {&r.a, &r.b, &r.c, &r.d};\n        Mat res;\n      \
    \  FPS<mint>* out[4] = {&res.a, &res.b, &res.c, &res.d};\n        FPS<mint> tmp[4];\n\
    \        if (mat_mul_ntt(x, 2, y, 2, tmp)) {\n            for (int i = 0; i <\
    \ 4; i++) *out[i] = std::move(tmp[i]);\n            return res;\n        }\n \
    \       return {shrink(a * r.a + b * r.c), shrink(a * r.b + b * r.d), shrink(c\
    \ * r.a + d * r.c), shrink(c * r.b + d * r.d)};\n    }\n    std::pair<FPS<mint>,\
    \ FPS<mint>> operator*(const std::pair<FPS<mint>, FPS<mint>>& p) const {\n   \
    \     const FPS<mint>* x[4] = {&a, &b, &c, &d};\n        const FPS<mint>* y[2]\
    \ = {&p.first, &p.second};\n        FPS<mint> tmp[2];\n        if (mat_mul_ntt(x,\
    \ 2, y, 1, tmp)) return {std::move(tmp[0]), std::move(tmp[1])};\n        return\
    \ {shrink(a * p.first + b * p.second), shrink(c * p.first + d * p.second)};\n\
    \    }\n};\n\n// \u4E92\u9664\u6CD5\u3092 1 \u6BB5\u9032\u3081\u308B: (p, q) <-\
    \ (q, p % q)\u3001m <- [[0, 1], [1, -p / q]] m\ntemplate <typename mint>\nvoid\
    \ step(Mat<mint>& m, std::pair<FPS<mint>, FPS<mint>>& p) {\n    const FPS<mint>\
    \ quo = p.first / p.second;\n    FPS<mint> rem = shrink(p.first - p.second * quo);\n\
    \    FPS<mint> c = shrink(m.a - m.c * quo), d = shrink(m.b - m.d * quo);\n   \
    \ m = {std::move(m.c), std::move(m.d), std::move(c), std::move(d)};\n    p = {std::move(p.second),\
    \ std::move(rem)};\n}\n\n// p = (f, g) (|f| = n > |g|) \u306B\u5BFE\u3057\u3001\
    \u4E92\u9664\u6CD5\u3067\u9577\u3055\u304C ceil(n / 2) \u4EE5\u4E0B\u306B\u306A\
    \u308B\u76F4\u524D\u307E\u3067\u306E\u5909\u63DB\u884C\u5217\ntemplate <typename\
    \ mint>\nMat<mint> half_gcd(std::pair<FPS<mint>, FPS<mint>> p) {\n    const long\
    \ long n = p.first.size(), m = p.second.size();\n    const long long k = (n +\
    \ 1) / 2;\n    if (m <= k) return Mat<mint>::identity();\n    // \u77ED\u3044\u3068\
    \u304D\u306F\u3001\u4E92\u9664\u6CD5\u3092 1 \u6BB5\u305A\u3064\u9032\u3081\u305F\
    \u307B\u3046\u304C\u901F\u3044\n    if (n <= 64) {\n        Mat<mint> res = Mat<mint>::identity();\n\
    \        while (static_cast<long long>(p.second.size()) > k) step(res, p);\n \
    \       return res;\n    }\n    // \u4E0A\u4F4D\u306E\u534A\u5206\u3060\u3051\u3067\
    \u6C42\u3081\u305F\u884C\u5217\u306F\u3001\u4E0A\u4F4D\u306E\u7D04\u534A\u5206\
    \u306E\u5546\u3092\u6B63\u3057\u304F\u4E0E\u3048\u308B\n    Mat<mint> m1 = half_gcd(std::make_pair(drop(p.first,\
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
    \ p.first;\n}\n}  // namespace internal_fps\n\n/**\n * @brief f^n mod m (m \u306F\
    \u672B\u5C3E\u304C 0 \u3067\u306A\u3044\u3053\u3068) O(d log d log n) (d \u306F\
    \ m \u306E\u6B21\u6570)\n */\ntemplate <typename mint>\nFPS<mint> modpow(const\
    \ FPS<mint>& f, long long n, const FPS<mint>& m) {\n    assert(!m.empty() && m.back()\
    \ != 0);\n    const long long d = static_cast<long long>(m.size()) - 1;  // m\
    \ \u306E\u6B21\u6570\n    if (d == 0) return FPS<mint>();\n    // h (\u6B21\u6570\
    \ 2d - 2 \u4EE5\u4E0B) \u3092 m \u3067\u5272\u3063\u305F\u4F59\u308A\u3002\u5546\
    \u306E\u6B21\u6570\u306F d - 2 \u4EE5\u4E0B\u306A\u306E\u3067\u3001rev(m) \u306E\
    \u9006\u5143\u306F d - 1 \u9805\u3042\u308C\u3070\u3088\u304F\u3001\u6700\u521D\
    \u306B 1 \u56DE\u3060\u3051\u6C42\u3081\u308B (Barrett)\n    const FPS<mint> iv\
    \ = inv(m.rev(), std::max(d - 1, 1LL));\n    auto reduce = [&](FPS<mint> h) {\n\
    \        h.normalize();\n        if (h.size() < m.size()) return h;\n        const\
    \ long long need = static_cast<long long>(h.size()) - static_cast<long long>(m.size())\
    \ + 1;\n        const FPS<mint> q = (h.rev().pre(need) * iv.pre(need)).pre(need).rev();\n\
    \        h -= q * m;\n        h.resize(std::min<long long>(h.size(), d));\n  \
    \      h.normalize();\n        return h;\n    };\n    const FPS<mint> base = f\
    \ % m;\n    FPS<mint> res(1, 1);\n    for (int bit = 62; bit >= 0; bit--) {\n\
    \        res = reduce(res * res);\n        if (n >> bit & 1) res = reduce(res\
    \ * base);\n    }\n    return res;\n}\n\n/**\n * @brief a f + b g = d (d \u306F\
    \ f \u3068 g \u306E\u6700\u5927\u516C\u7D04\u6570\u3067\u3001\u6700\u9AD8\u6B21\
    \u306E\u4FC2\u6570\u304C 1) \u3068\u306A\u308B a\u3001b \u3092\u6C42\u3081\u3001\
    d \u3092\u8FD4\u3059 O(n log^2 n)\n * f \u3068 g \u304C\u3068\u3082\u306B 0 \u306A\
    \u3089 d = a = b = 0\u3002a\u3001b \u306F\u672B\u5C3E\u306E 0 \u3092\u53D6\u308A\
    \u9664\u3044\u305F\u5F62\n */\ntemplate <typename mint>\nFPS<mint> extgcd(const\
    \ FPS<mint>& f, const FPS<mint>& g, FPS<mint>& a, FPS<mint>& b) {\n    using namespace\
    \ internal_fps;\n    Mat<mint> m = gcd_matrix(f, g);\n    FPS<mint> d = shrink(m.a\
    \ * shrink(f) + m.b * shrink(g));\n    a = std::move(m.a), b = std::move(m.b);\n\
    \    if (d.empty()) {\n        a.clear(), b.clear();\n        return d;\n    }\n\
    \    const mint iv = d.back().inv();\n    d *= iv, a *= iv, b *= iv;\n    return\
    \ d;\n}\n\n/**\n * @brief f h \u2261 1 (mod g) \u3067\u3001\u6B21\u6570\u304C\
    \ g \u3088\u308A\u5C0F\u3055\u3044 h\u3002\u306A\u3051\u308C\u3070 std::nullopt\
    \ O(n log^2 n)\n * g \u306F 0 \u3067\u306A\u3044\u3053\u3068\u3002g \u304C\u5B9A\
    \u6570\u306A\u3089\u3059\u3079\u3066\u304C 0 \u3068\u5408\u540C\u306A\u306E\u3067\
    \u3001h = 0 (\u7A7A) \u3092\u8FD4\u3059\u3002h \u306F\u672B\u5C3E\u306E 0 \u3092\
    \u53D6\u308A\u9664\u3044\u305F\u5F62\n */\ntemplate <typename mint>\nstd::optional<FPS<mint>>\
    \ modinv(const FPS<mint>& f, const FPS<mint>& g) {\n    using namespace internal_fps;\n\
    \    const FPS<mint> gs = shrink(g);\n    assert(!gs.empty());\n    if (gs.size()\
    \ == 1) return FPS<mint>();\n    FPS<mint> a, b;\n    const FPS<mint> d = extgcd(shrink(f\
    \ % gs), gs, a, b);\n    if (d.size() != 1) return std::nullopt;\n    return shrink(a\
    \ % gs);\n}\n\n/**\n * @brief \u591A\u9805\u5F0F\u306E\u5217\u306E\u7A4D f_0 f_1\
    \ ... f_{n-1} O(N log^2 N) (N \u306F\u6B21\u6570\u306E\u548C)\n * \u6B21\u6570\
    \u306E\u5C0F\u3055\u3044\u3082\u306E\u304B\u3089 2 \u3064\u305A\u3064\u639B\u3051\
    \u3066\u3044\u304F\u3002fs \u304C\u7A7A\u306A\u3089 1\n */\ntemplate <typename\
    \ mint>\nFPS<mint> polynomial_product(std::vector<FPS<mint>> fs) {\n    if (fs.empty())\
    \ return FPS<mint>(1, 1);\n    auto larger = [&](int a, int b) { return fs[a].size()\
    \ > fs[b].size(); };\n    std::priority_queue<int, std::vector<int>, decltype(larger)>\
    \ pq(larger);\n    for (int i = 0; i < static_cast<int>(fs.size()); i++) pq.push(i);\n\
    \    while (pq.size() > 1) {\n        int a = pq.top();\n        pq.pop();\n \
    \       int b = pq.top();\n        pq.pop();\n        // \u7A7A\u306E\u591A\u9805\
    \u5F0F (0) \u3068\u306E\u7A4D\u306F 0\n        fs[a] = fs[a].empty() || fs[b].empty()\
    \ ? FPS<mint>() : fs[a] * fs[b];\n        FPS<mint>().swap(fs[b]);\n        pq.push(a);\n\
    \    }\n    return fs[pq.top()];\n}\n\n/**\n * @brief \u5206\u6570\u306E\u548C\
    \ \u03A3_i nums[i] / dens[i] \u3092 1 \u3064\u306E\u5206\u6570 num / den \u306B\
    \u307E\u3068\u3081\u308B O(N log^2 N) (N \u306F\u591A\u9805\u5F0F\u306E\u9577\u3055\
    \u306E\u548C)\n * \u534A\u5206\u305A\u3064\u306B\u5206\u3051\u3066 a / b + c /\
    \ d = (ad + cb) / bd \u3068\u307E\u3068\u3081\u308B\u3002den \u306F dens \u306E\
    \u7A4D\u3002\u7A7A\u306A\u3089 0 / 1\n * @return std::pair<FPS<mint>, FPS<mint>>\
    \ {num, den}\n */\ntemplate <typename mint>\nstd::pair<FPS<mint>, FPS<mint>> sum_of_fractions(const\
    \ std::vector<FPS<mint>>& nums, const std::vector<FPS<mint>>& dens) {\n    assert(nums.size()\
    \ == dens.size());\n    if (nums.empty()) return {FPS<mint>(), FPS<mint>{1}};\n\
    \    auto rec = [&](auto&& self, long long l, long long r) -> std::pair<FPS<mint>,\
    \ FPS<mint>> {\n        if (r - l == 1) return {nums[l], dens[l]};\n        long\
    \ long m = (l + r) / 2;\n        auto [a, b] = self(self, l, m);\n        auto\
    \ [c, d] = self(self, m, r);\n        return {a * d + c * b, b * d};\n    };\n\
    \    return rec(rec, 0, nums.size());\n}\n#line 2 \"src/math/multipoint.hpp\"\n\
    \n/**\n * @file multipoint.hpp\n * @brief \u591A\u70B9\u8A55\u4FA1\u30FB\u591A\
    \u9805\u5F0F\u88DC\u9593\u30FB\u6A19\u672C\u70B9\u306E\u305A\u3089\u3057\n */\n\
    \n#line 11 \"src/math/multipoint.hpp\"\n\n#line 15 \"src/math/multipoint.hpp\"\
    \n\nnamespace internal_multipoint {\n// \u70B9 xs \u306E subproduct tree: tree[k]\
    \ \u306F\u9802\u70B9 k \u304C\u53D7\u3051\u6301\u3064\u70B9 x_i \u306B\u3064\u3044\
    \u3066 \u03A0 (x - x_i)\u3002\u8449\u306F sz + i\ntemplate <typename mint>\nstruct\
    \ SubproductTree {\n    long long n, sz;\n    std::vector<FPS<mint>> tree;\n \
    \   explicit SubproductTree(const std::vector<mint>& xs) : n(xs.size()), sz(1)\
    \ {\n        while (sz < n) sz <<= 1;\n        tree.assign(2 * sz, FPS<mint>{1});\n\
    \        for (long long i = 0; i < n; i++) tree[sz + i] = FPS<mint>{-xs[i], 1};\n\
    \        for (long long k = sz - 1; k >= 1; k--) tree[k] = tree[2 * k] * tree[2\
    \ * k + 1];\n    }\n};\n}  // namespace internal_multipoint\n\n/**\n * @brief\
    \ \u591A\u9805\u5F0F f \u306E\u3001\u70B9 xs \u3067\u306E\u5024 f(x_0), ..., f(x_{m-1})\
    \ O((n + m) log^2 (n + m))\n * subproduct tree \u306E\u6839\u304B\u3089\u3001\u5404\
    \u9802\u70B9\u306E\u591A\u9805\u5F0F\u3067\u5272\u3063\u305F\u4F59\u308A\u3092\
    \u4E0B\u308D\u3057\u3066\u3044\u304F\u3002\u4F59\u308A\u304C\u77ED\u304F\u306A\
    \u3063\u305F\u3089\u76F4\u63A5\u8A08\u7B97\u3059\u308B\n */\ntemplate <typename\
    \ mint>\nstd::vector<mint> multipoint_evaluation(const FPS<mint>& f, const std::vector<mint>&\
    \ xs) {\n    const long long m = xs.size();\n    if (m == 0) return {};\n    internal_multipoint::SubproductTree<mint>\
    \ t(xs);\n    std::vector<mint> res(m);\n    // \u9802\u70B9 k \u306B f \u306E\
    \u4F59\u308A g \u304C\u5C4A\u3044\u305F\u3068\u304D\u3001\u53D7\u3051\u6301\u3064\
    \u70B9\u306E\u5024\u3092\u6C42\u3081\u308B\n    auto rec = [&](auto&& self, long\
    \ long k, long long l, long long r, FPS<mint> g) -> void {\n        if (l >= m)\
    \ return;\n        // \u6B21\u6570\u304C\u5C0F\u3055\u3051\u308C\u3070 Horner\
    \ \u6CD5\u3067\u76F4\u63A5\u6C42\u3081\u308B\n        if (r - l <= 32) {\n   \
    \         for (long long i = l; i < std::min(r, m); i++) res[i] = g.eval(xs[i]);\n\
    \            return;\n        }\n        const long long mid = (l + r) / 2;\n\
    \        self(self, 2 * k, l, mid, g % t.tree[2 * k]);\n        self(self, 2 *\
    \ k + 1, mid, r, g % t.tree[2 * k + 1]);\n    };\n    FPS<mint> g = f;\n    g.normalize();\n\
    \    rec(rec, 1, 0, t.sz, g % t.tree[1]);\n    return res;\n}\n\n/**\n * @brief\
    \ \u70B9 (x_i, y_i) (x_i \u306F\u4E92\u3044\u306B\u7570\u306A\u308B) \u3092\u3059\
    \u3079\u3066\u901A\u308B n - 1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\u5F0F (\u9577\
    \u3055 n) O(n log^2 n)\n * g = \u03A0 (x - x_i) \u3068\u3059\u308B\u3068 f = \u03A3\
    \ y_i / g'(x_i) \u03A0_{j != i} (x - x_j)\u3002g'(x_i) \u3092\u591A\u70B9\u8A55\
    \u4FA1\u3057\u3001\u548C\u3092 subproduct tree \u306E\u4E0B\u304B\u3089\u7D44\u307F\
    \u7ACB\u3066\u308B\n */\ntemplate <typename mint>\nFPS<mint> polynomial_interpolation(const\
    \ std::vector<mint>& xs, const std::vector<mint>& ys) {\n    assert(xs.size()\
    \ == ys.size());\n    const long long n = xs.size();\n    if (n == 0) return FPS<mint>();\n\
    \    internal_multipoint::SubproductTree<mint> t(xs);\n    std::vector<mint> d\
    \ = multipoint_evaluation(diff(t.tree[1]), xs);\n    // val[k] = \u03A3_{\u9802\
    \u70B9 k \u306E\u70B9 i} c_i \u03A0_{\u9802\u70B9 k \u306E\u70B9 j != i} (x -\
    \ x_j)\u3001c_i = y_i / g'(x_i)\n    std::vector<FPS<mint>> val(2 * t.sz);\n \
    \   for (long long i = 0; i < t.sz; i++) val[t.sz + i] = i < n ? FPS<mint>{ys[i]\
    \ / d[i]} : FPS<mint>{};\n    for (long long k = t.sz - 1; k >= 1; k--) {\n  \
    \      FPS<mint> a = val[2 * k] * t.tree[2 * k + 1], b = val[2 * k + 1] * t.tree[2\
    \ * k];\n        if (a.size() < b.size()) a.resize(b.size());\n        for (size_t\
    \ i = 0; i < b.size(); i++) a[i] += b[i];\n        val[k] = a;\n    }\n    FPS<mint>\
    \ f = val[1];\n    f.resize(n);\n    return f;\n}\n\nnamespace internal_multipoint\
    \ {\n// ys = f(0), ..., f(n-1) \u304B\u3089 f(c), ..., f(c+m-1)\u3002c + k \u304C\
    \ 0 \u4EE5\u4E0A n \u672A\u6E80\u306E\u6574\u6570\u3068\u91CD\u306A\u3089\u306A\
    \u3044\u3053\u3068\n// f(c+k) = (\u03A0_{j<n} (c+k-j)) \u03A3_i a_i / (c+k-i)\u3001\
    a_i = y_i / (i! (n-1-i)! (-1)^(n-1-i))\ntemplate <typename mint>\nstd::vector<mint>\
    \ shift_no_overlap(const std::vector<mint>& ys, mint c, long long m) {\n    using\
    \ C = Combination<mint>;\n    const long long n = ys.size();\n    C::extend(n);\n\
    \    std::vector<mint> a(n);\n    for (long long i = 0; i < n; i++) {\n      \
    \  a[i] = ys[i] * C::inverse_factorial(i) * C::inverse_factorial(n - 1 - i);\n\
    \        if ((n - 1 - i) % 2 == 1) a[i] = -a[i];\n    }\n    // b_t = 1 / (c -\
    \ (n-1) + t) (t = 0, ..., n+m-2)\u3002\u9006\u6570\u306F\u307E\u3068\u3081\u3066\
    \u6C42\u3081\u308B\n    const long long len = n + m - 1;\n    std::vector<mint>\
    \ v(len), b(len), pre(len + 1, 1);\n    for (long long t = 0; t < len; t++) v[t]\
    \ = c - mint(n - 1) + mint(t), pre[t + 1] = pre[t] * v[t];\n    mint inv_all =\
    \ pre[len].inv();\n    for (long long t = len - 1; t >= 0; t--) b[t] = inv_all\
    \ * pre[t], inv_all *= v[t];\n    std::vector<mint> s = convolution(a, b);\n \
    \   // \u03A0_{j<n} (c+k-j) = v[k] v[k+1] ... v[k+n-1] \u3092\u305A\u3089\u3057\
    \u306A\u304C\u3089\u6C42\u3081\u308B\n    std::vector<mint> res(m);\n    mint\
    \ prod = 1;\n    for (long long t = 0; t < n; t++) prod *= v[t];\n    for (long\
    \ long k = 0; k < m; k++) {\n        if (k > 0) prod *= v[k + n - 1] * b[k - 1];\n\
    \        res[k] = prod * s[k + n - 1];\n    }\n    return res;\n}\n}  // namespace\
    \ internal_multipoint\n\n/**\n * @brief n - 1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\
    \u5F0F f \u306E f(0), ..., f(n-1) \u304B\u3089\u3001f(c), f(c+1), ..., f(c+m-1)\
    \ \u3092\u6C42\u3081\u308B O((n + m) log (n + m))\n * \u6CD5\u306F n + m \u3088\
    \u308A\u5927\u304D\u3044\u7D20\u6570\u3067\u3042\u308B\u3053\u3068\u3002c + k\
    \ \u304C 0 \u4EE5\u4E0A n \u672A\u6E80\u306E\u6574\u6570\u3068\u91CD\u306A\u308B\
    \ k \u306F ys \u3092\u305D\u306E\u307E\u307E\u4F7F\u3046\n */\ntemplate <typename\
    \ mint>\nstd::vector<mint> sample_point_shift(const std::vector<mint>& ys, mint\
    \ c, long long m) {\n    const long long n = ys.size();\n    std::vector<mint>\
    \ res(m);\n    if (n == 0) return res;\n    // (c + k) mod p \u304C [0, n) \u306B\
    \u5165\u308B\u304B\u3067\u533A\u5207\u308A\u3001\u5165\u3089\u306A\u3044\u533A\
    \u9593\u3054\u3068\u306B\u7573\u307F\u8FBC\u307F\u3067\u6C42\u3081\u308B\n   \
    \ const long long p = mint::mod();\n    long long k = 0;\n    while (k < m) {\n\
    \        long long x = (c.val() + k) % p;\n        if (x < n) {\n            res[k]\
    \ = ys[x];\n            k++;\n            continue;\n        }\n        // x +\
    \ len \u304C p \u304B n + p \u306B\u5C4A\u304F\u307E\u3067\u306F\u91CD\u306A\u3089\
    \u306A\u3044 (x >= n \u306A\u306E\u3067\u6B21\u306B\u91CD\u306A\u308B\u306E\u306F\
    \ x \u304C p \u306B\u623B\u3063\u305F\u3068\u304D)\n        long long len = std::min(m\
    \ - k, p - x);\n        auto part = internal_multipoint::shift_no_overlap(ys,\
    \ mint(x), len);\n        for (long long i = 0; i < len; i++) res[k + i] = part[i];\n\
    \        k += len;\n    }\n    return res;\n}\n\n/**\n * @brief \u591A\u9805\u5F0F\
    \ f \u306E\u3001\u7B49\u6BD4\u6570\u5217\u306E\u70B9 a r^i (0 <= i < m) \u3067\
    \u306E\u5024 O((n + m) log (n + m)) (chirp-z \u5909\u63DB)\n * ij = C(i + j, 2)\
    \ - C(i, 2) - C(j, 2) \u3092\u4F7F\u3046\u3068 f(a r^i) = r^{-C(i, 2)} \u03A3\
    _j (f_j a^j r^{-C(j, 2)}) r^{C(i + j, 2)} \u3068\u306A\u308A\u3001\u7573\u307F\
    \u8FBC\u307F 1 \u56DE\u3067\u6C42\u307E\u308B\n */\ntemplate <typename mint>\n\
    std::vector<mint> multipoint_evaluation_geometric(const FPS<mint>& f, mint a,\
    \ mint r, long long m) {\n    const long long n = f.size();\n    std::vector<mint>\
    \ res(m);\n    if (m == 0 || n == 0) return res;\n    if (r == 0) {\n        //\
    \ \u70B9\u306F a, 0, 0, ...\n        for (long long j = n - 1; j >= 0; j--) res[0]\
    \ = res[0] * a + f[j];\n        for (long long i = 1; i < m; i++) res[i] = f[0];\n\
    \        return res;\n    }\n    // w[k] = r^{C(k, 2)}\u3001iw[k] = r^{-C(k, 2)}\n\
    \    const long long len = n + m - 1;\n    const mint ir = r.inv();\n    std::vector<mint>\
    \ w(len), iw(std::max(n, m));\n    mint p = 1;\n    w[0] = 1;\n    for (long long\
    \ k = 0; k + 1 < len; k++) w[k + 1] = w[k] * p, p *= r;\n    p = 1;\n    iw[0]\
    \ = 1;\n    for (long long k = 0; k + 1 < static_cast<long long>(iw.size()); k++)\
    \ iw[k + 1] = iw[k] * p, p *= ir;\n    // A \u3092\u9006\u9806\u306B\u4E26\u3079\
    \u3066\u7573\u307F\u8FBC\u3080\u3068\u3001[n - 1 + i] \u304C \u03A3_j A_j w[i\
    \ + j] \u306B\u306A\u308B\n    std::vector<mint> A(n);\n    mint aj = 1;\n   \
    \ for (long long j = 0; j < n; j++) A[n - 1 - j] = f[j] * aj * iw[j], aj *= a;\n\
    \    std::vector<mint> c = convolution(A, w);\n    for (long long i = 0; i < m;\
    \ i++) res[i] = iw[i] * c[n - 1 + i];\n    return res;\n}\n\nnamespace internal_multipoint\
    \ {\n// \u03A0_{j<n} (x - a r^j) O(n log n)\n// \u524D\u534A h = \u03A0_{j<k}\
    \ (x - a r^j) \u304B\u3089\u3001\u5F8C\u534A\u306F \u03A0_{j<k} (x - a r^{j+k})\
    \ = r^{k^2} h(x r^{-k}) \u3068\u4FC2\u6570\u3092\u5909\u3048\u308B\u3060\u3051\
    \u3067\u6C42\u307E\u308B\ntemplate <typename mint>\nFPS<mint> geometric_product(mint\
    \ a, mint r, long long n) {\n    if (n == 0) return FPS<mint>{1};\n    if (n %\
    \ 2 == 1) {\n        FPS<mint> h = geometric_product(a, r, n - 1);\n        return\
    \ h * FPS<mint>{-a * r.pow(n - 1), 1};\n    }\n    const long long k = n / 2;\n\
    \    FPS<mint> h = geometric_product(a, r, k);\n    const mint rk = r.pow(k),\
    \ irk = rk.inv();\n    FPS<mint> g = h;\n    mint c = rk.pow(k);\n    for (auto&\
    \ x : g) x *= c, c *= irk;\n    return h * g;\n}\n}  // namespace internal_multipoint\n\
    \n/**\n * @brief \u7B49\u6BD4\u6570\u5217\u306E\u70B9 (a r^i, y_i) (0 <= i < n)\
    \ \u3092\u3059\u3079\u3066\u901A\u308B n - 1 \u6B21\u4EE5\u4E0B\u306E\u591A\u9805\
    \u5F0F (\u9577\u3055 n) O(n log n)\n * a r^i \u306F\u4E92\u3044\u306B\u7570\u306A\
    \u308B\u3053\u3068 (n >= 2 \u306A\u3089 a != 0\u3001r != 0)\n * f = M \u03A3_i\
    \ w_i / (x - x_i) (M = \u03A0 (x - x_j)\u3001w_i = y_i / \u03A0_{j != i} (x_i\
    \ - x_j))\u3002\n * \u548C\u306E x^k \u306E\u4FC2\u6570 -a^{-(k+1)} \u03A3_i w_i\
    \ r^{-i(k+1)} \u306F\u7B49\u6BD4\u6570\u5217\u306E\u70B9\u3067\u306E\u591A\u70B9\
    \u8A55\u4FA1\u3067\u6C42\u307E\u308B\n */\ntemplate <typename mint>\nFPS<mint>\
    \ polynomial_interpolation_geometric(mint a, mint r, const std::vector<mint>&\
    \ ys) {\n    const long long n = ys.size();\n    if (n == 0) return FPS<mint>();\n\
    \    if (n == 1) return FPS<mint>{ys[0]};\n    assert(a != 0 && r != 0);\n   \
    \ const mint ir = r.inv();\n    // pw[k] = r^k\u3001P[k] = \u03A0_{t=1}^{k} (r^t\
    \ - 1)\n    std::vector<mint> pw(n), ipw(n), P(n), iP(n);\n    pw[0] = ipw[0]\
    \ = P[0] = 1;\n    for (long long k = 1; k < n; k++) pw[k] = pw[k - 1] * r, ipw[k]\
    \ = ipw[k - 1] * ir, P[k] = P[k - 1] * (pw[k] - 1);\n    assert(P[n - 1] != 0\
    \ && \"a r^i must be distinct\");\n    iP[n - 1] = P[n - 1].inv();\n    for (long\
    \ long k = n - 1; k >= 1; k--) iP[k - 1] = iP[k] * (pw[k] - 1);\n    // \u03A0\
    _{j != i} (x_i - x_j) = a^{n-1} r^{e_i} P_i (-1)^{n-1-i} P_{n-1-i}\u3001e_i =\
    \ C(i, 2) + i (n - 1 - i)\n    // e_{i+1} - e_i = n - 2 - i \u306A\u306E\u3067\
    \u3001r^{-e_i} \u306F\u9806\u306B\u639B\u3051\u3066\u6C42\u3081\u308B\n    std::vector<mint>\
    \ W(n);\n    const mint ian = a.inv().pow(n - 1);\n    mint ire = 1;\n    for\
    \ (long long i = 0; i < n; i++) {\n        W[i] = ys[i] * ian * ire * iP[i] *\
    \ iP[n - 1 - i];\n        if ((n - 1 - i) % 2 == 1) W[i] = -W[i];\n        if\
    \ (i + 1 < n) ire *= ipw[n - 2 - i];\n    }\n    std::vector<mint> s = multipoint_evaluation_geometric(FPS<mint>(W),\
    \ ir, ir, n);\n    const mint ia = a.inv();\n    mint c = ia;\n    FPS<mint> S(n);\n\
    \    for (long long k = 0; k < n; k++) S[k] = -c * s[k], c *= ia;\n    FPS<mint>\
    \ f = (internal_multipoint::geometric_product(a, r, n) * S).pre(n);\n    f.resize(n);\n\
    \    return f;\n}\n\n/**\n * @brief \u91CD\u307F\u4ED8\u304D\u306E\u7D2F\u4E57\
    \u548C s_k = \u03A3_i w_i x_i^k (0 <= k < n) O(m log^2 m + n log n) (m \u306F\u70B9\
    \u306E\u500B\u6570)\n * \u03A3_k s_k t^k = \u03A3_i w_i / (1 - x_i t) \u306A\u306E\
    \u3067\u3001\u5206\u6570\u306E\u548C\u3092 1 \u3064\u306E\u5206\u6570\u306B\u307E\
    \u3068\u3081\u3001\u5206\u6BCD\u306E\u9006\u5143\u3092\u639B\u3051\u308B\n * (\u591A\
    \u70B9\u8A55\u4FA1\u306E\u8EE2\u7F6E\u306B\u3042\u305F\u308B\u3002\u70B9\u306F\
    \u91CD\u306A\u3063\u3066\u3082\u3088\u3044)\n */\ntemplate <typename mint>\nstd::vector<mint>\
    \ weighted_power_sums(const std::vector<mint>& xs, const std::vector<mint>& ws,\
    \ long long n) {\n    assert(xs.size() == ws.size());\n    std::vector<mint> res(n);\n\
    \    if (n == 0 || xs.empty()) return res;\n    std::vector<FPS<mint>> nums(xs.size()),\
    \ dens(xs.size());\n    for (long long i = 0; i < static_cast<long long>(xs.size());\
    \ i++) nums[i] = {ws[i]}, dens[i] = {1, -xs[i]};\n    auto [num, den] = sum_of_fractions(nums,\
    \ dens);\n    FPS<mint> s = (num * inv(den, n)).pre(n);\n    std::copy(s.begin(),\
    \ s.end(), res.begin());\n    return res;\n}\n#line 9 \"test/yosupo/polynomial/multipoint-evaluation.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    FPS<mint> f(n);\n    for (auto& x : f) std::cin >> x;\n    std::vector<mint>\
    \ xs(m);\n    for (auto& x : xs) std::cin >> x;\n    auto res = multipoint_evaluation(f,\
    \ xs);\n    for (int i = 0; i < m; i++) std::cout << res[i] << (i + 1 == m ? '\\\
    n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/math/fps.hpp\"\
    \n#include \"../../../src/math/modint.hpp\"\n#include \"../../../src/math/multipoint.hpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    FPS<mint> f(n);\n    for (auto& x : f) std::cin >> x;\n    std::vector<mint>\
    \ xs(m);\n    for (auto& x : xs) std::cin >> x;\n    auto res = multipoint_evaluation(f,\
    \ xs);\n    for (int i = 0; i < m; i++) std::cout << res[i] << (i + 1 == m ? '\\\
    n' : ' ');\n}\n"
  dependsOn:
  - src/math/fps.hpp
  - src/math/combinatorics.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/multipoint.hpp
  isVerificationFile: true
  path: test/yosupo/polynomial/multipoint-evaluation.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/polynomial/multipoint-evaluation.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial/multipoint-evaluation.test.cpp
- /verify/test/yosupo/polynomial/multipoint-evaluation.test.cpp.html
title: test/yosupo/polynomial/multipoint-evaluation.test.cpp
---
