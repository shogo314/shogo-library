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
  bundledCode: "#line 1 \"test/unittest/fps.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// FPS \u306E\u5358\u9805\u306E -\u3001\u5B9A\u6570\u3092\u5F15\u304F -\u3001\
    eval\u3001gcd\u3001modpow \u3092\u611A\u76F4\u306A\u591A\u9805\u5F0F\u6F14\u7B97\
    \u3068\u6BD4\u8F03\u3059\u308B\n// FPS \u306E + \u3068 - \u306F\u7D50\u679C\u306E\
    \u672B\u5C3E\u306E 0 \u3092\u53D6\u308A\u9664\u304F (\u4ED5\u69D8) \u306E\u3067\
    \u3001\u591A\u9805\u5F0F\u3068\u3057\u3066\u306E\u6BD4\u8F03\u306F\u672B\u5C3E\
    \u306E 0 \u3092\u9664\u3044\u3066\u884C\u3046\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#line 2 \"src/math/fps.hpp\"\n\n/**\n * @file\
    \ fps.hpp\n * @brief \u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#line 2 \"src/math/combinatorics.hpp\"\n\n/**\n * @file combinatorics.hpp\n\
    \ * @brief \u7D44\u307F\u5408\u308F\u305B\n */\n\n#line 9 \"src/math/combinatorics.hpp\"\
    \n#include <numeric>\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file\
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
    \ modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n}\n#line 12 \"src/math/combinatorics.hpp\"\
    \n\n/**\n * @brief \u7D44\u307F\u5408\u308F\u305B\n */\ntemplate <typename Modint>\n\
    class Combination {\n    static std::vector<Modint> fact, inv_fact;\n    static\
    \ long long cached_mod; // dynamic_modint \u3067 mod \u304C\u5909\u308F\u3063\u305F\
    \u3089\u524D\u8A08\u7B97\u3092\u3084\u308A\u76F4\u3059\n\npublic:\n    /**\n \
    \    * @brief n \u307E\u3067\u306E\u968E\u4E57\u3068\u305D\u306E\u9006\u5143\u3092\
    \u524D\u8A08\u7B97\u3059\u308B\n     * @param n\n     * @note O(n) \u5FC5\u8981\
    \u306B\u306A\u3063\u305F\u3089\u547C\u3073\u51FA\u3055\u308C\u308B\u304C\u3001\
    \u4E88\u3081\u5927\u304D\u306An\u306B\u5BFE\u3057\u3066\u547C\u3073\u51FA\u3057\
    \u3066\u304A\u304F\u3053\u3068\u3067\u9006\u5143\u306E\u76F4\u63A5\u8A08\u7B97\
    \u3092\u6E1B\u3089\u305B\u308B\n     */\n    inline static void extend(int n)\
    \ {\n        if (cached_mod != (long long)Modint::mod()) {\n            cached_mod\
    \ = Modint::mod();\n            fact = {1, 1};\n            inv_fact = {1, 1};\n\
    \        }\n        int m = fact.size();\n        if (n < m) return;\n       \
    \ fact.resize(n + 1);\n        inv_fact.resize(n + 1);\n        for (int i = m;\
    \ i <= n; ++i) {\n            fact[i] = fact[i - 1] * i;\n        }\n        inv_fact[n]\
    \ = fact[n].inv();\n        for (int i = n; i > m; --i) {\n            inv_fact[i\
    \ - 1] = inv_fact[i] * i;\n        }\n    }\n    \n    /**\n     * @brief n \u306E\
    \u968E\u4E57\u3092\u8FD4\u3059\n     * @param n\n     * @return n!\n     * @note\
    \ extend(n), O(1)\n     */\n    inline static Modint factorial(int n) {\n    \
    \    extend(n);\n        return fact[n];\n    }\n    /**\n     * @brief n \u306E\
    \u968E\u4E57\u306E\u9006\u5143\u3092\u8FD4\u3059\n     * @param n\n     * @return\
    \ n!^-1\n     * @note extend(n), O(1)\n     */\n    inline static Modint inverse_factorial(int\
    \ n) {\n        extend(n);\n        return inv_fact[n];\n    }\n    /**\n    \
    \ * @brief n \u306E\u9006\u5143\u3092\u8FD4\u3059\n     * @param n\n     * @return\
    \ n^-1\n     * @note extend(n), O(1)\n     */\n    inline static Modint inv(int\
    \ n) {\n        assert(n > 0);\n        extend(n);\n        return inv_fact[n]\
    \ * fact[n - 1];\n    }\n\n    /**\n     * @brief nPr \u3092\u8FD4\u3059\n   \
    \  * @param n\n     * @param r\n     * @return nPr\n     * @note extend(n), O(1)\n\
    \     */\n    inline static Modint P(int n, int r) {\n        if (r < 0 || n <\
    \ r) return 0;\n        extend(n);\n        return fact[n] * inv_fact[n - r];\n\
    \    }\n    /**\n     * @brief nCr \u3092\u8FD4\u3059\n     * @param n\n     *\
    \ @param r\n     * @return nCr\n     * @note extend(n), O(1)\n     */\n    inline\
    \ static Modint C(int n, int r) {\n        if (r < 0 || n < r) return 0;\n   \
    \     extend(n);\n        return fact[n] * inv_fact[r] * inv_fact[n - r];\n  \
    \  }\n    /**\n     * @brief nHr \u3092\u8FD4\u3059\n     * @param n\n     * @param\
    \ r\n     * @return nHr\n     * @note extend(n+r-1), O(1)\n     */\n    inline\
    \ static Modint H(int n, int r) {\n        if (n < 0 || r < 0) return 0;\n   \
    \     if (n == 0 && r == 0) return 1;\n        return C(n + r - 1, r);\n    }\n\
    \n    /**\n     * @brief nPr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\u3059\
    \u308B\n     * @param n\n     * @param r\n     * @return nPr\n     * @note O(r)\n\
    \     */\n    inline static Modint P_loop(long long n, int r) {\n        if (r\
    \ < 0 || n < r) return 0;\n        Modint res = 1;\n        for (int i = 0; i\
    \ < r; ++i) {\n            res *= n - i;\n        }\n        return res;\n   \
    \ }\n    /**\n     * @brief nCr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\
    \u3059\u308B\n     * @param n\n     * @param r\n     * @return nCr\n     * @note\
    \ O(min(r, n-r))\n     */\n    inline static Modint C_loop(long long n, long long\
    \ r) {\n        if (r < 0 || n < r) return 0;\n        if(r > n - r) r = n - r;\n\
    \        extend(r);\n        return P_loop(n, r) * inv_fact[r];\n    }\n    /**\n\
    \     * @brief nHr \u3092\u5B9A\u7FA9\u3069\u304A\u308A\u8A08\u7B97\u3059\u308B\
    \n     * @param n\n     * @param r\n     * @return nHr\n     * @note O(r)\n  \
    \   */\n    inline static Modint H_loop(long long n, long long r) {\n        if\
    \ (n < 0 || r < 0) return 0;\n        if (n == 0 && r == 0) return 1;\n      \
    \  return C_loop(n + r - 1, r);\n    }\n\n    /**\n     * @brief nCr \u3092 Lucas\
    \ \u306E\u5B9A\u7406\u3092\u7528\u3044\u3066\u8A08\u7B97\u3059\u308B\n     * @param\
    \ n\n     * @param r\n     * @return nCr\n     * @note extend(Mod), O(log(r))\n\
    \     */\n    inline static Modint C_lucas(long long n, long long r) {\n     \
    \   if (r < 0 || n < r) return 0;\n        if (r == 0 || n == r) return 1;\n \
    \       Modint res = 1;\n        while(r > 0) {\n            int ni = n % Modint::mod(),\
    \ ri = r % Modint::mod();\n            if (ni < ri) return 0;\n            res\
    \ *= C(ni, ri);\n            n /= Modint::mod();\n            r /= Modint::mod();\n\
    \        }\n        return res;\n    }\n};\n\ntemplate <typename Modint>\nstd::vector<Modint>\
    \ Combination<Modint>::fact{1, 1};\ntemplate <typename Modint>\nstd::vector<Modint>\
    \ Combination<Modint>::inv_fact{1, 1};\ntemplate <typename Modint>\nlong long\
    \ Combination<Modint>::cached_mod = 0;\n\n/**\n * @brief mod p^q \u3067\u306E\u4E8C\
    \u9805\u4FC2\u6570\u3092\u6C42\u3081\u308B\u69CB\u9020\n * @note \u524D\u8A08\u7B97\
    O(p^q) \u53C2\u8003: https://nyaannyaan.github.io/library/modulo/arbitrary-mod-binomial.hpp\n\
    \ */\nstruct CombinationPQ {\n    int p, q;\n    int pq;\n    std::vector<int>\
    \ fact_p, inv_fact_p;\n    int delta;\n    CombinationPQ(int p, int q) : p(p),\
    \ q(q) {\n        pq = 1;\n        for(int i = 0; i < q; i++) pq *= p;\n     \
    \   fact_p.resize(pq);\n        fact_p[0] = 1;\n        for(int i = 1; i < pq;\
    \ i++) {\n            if(i % p == 0) fact_p[i] = fact_p[i - 1];\n            else\
    \ fact_p[i] = (long long)fact_p[i - 1] * i % pq;\n        }\n        inv_fact_p.resize(pq);\n\
    \        inv_fact_p[pq - 1] = modinv(fact_p[pq - 1], pq);\n        for(int i =\
    \ pq - 1; i > 0; i--) {\n            if(i % p == 0) inv_fact_p[i - 1] = inv_fact_p[i];\n\
    \            else inv_fact_p[i - 1] = (long long)inv_fact_p[i] * i % pq;\n   \
    \     }\n        if(p == 2 && q >= 3) delta = 1;\n        else delta = -1;\n \
    \   }\n    /**\n     * @brief nCr mod p^q \u3092\u8FD4\u3059\n     * @param n\
    \ long long\n     * @param r long long\n     * @return nCr mod p^q\n     * @note\
    \ O(log(n))\n     */\n    int C(long long n, long long r) {\n        if(r < 0\
    \ || n < r) return 0;\n        long long m = n - r;\n        int ans = 1;\n  \
    \      std::vector<int> epsilon;\n        while(n > 0) {\n            ans = (long\
    \ long)ans * fact_p[n % pq] % pq;\n            ans = (long long)ans * inv_fact_p[m\
    \ % pq] % pq;\n            ans = (long long)ans * inv_fact_p[r % pq] % pq;\n \
    \           n /= p;\n            m /= p;\n            r /= p;\n            epsilon.push_back(n\
    \ - m - r);\n        }\n        if(delta == -1 && (int)epsilon.size() >= q &&\
    \ std::accumulate(epsilon.begin()+q-1, epsilon.end(), 0) % 2 == 1) ans = pq -\
    \ ans;\n        if(ans == pq) ans = 0;\n        int e = std::accumulate(epsilon.begin(),\
    \ epsilon.end(), 0);\n        if(e >= q) ans = 0;\n        else {\n          \
    \  for(int i = 0; i < e; i++) {\n                ans = (long long)ans * p % pq;\n\
    \            }\n        }\n        return ans;\n    }\n};\n#line 2 \"src/math/convolution.hpp\"\
    \n\n/**\n * @file convolution.hpp\n * @brief \u7573\u307F\u8FBC\u307F (NTT)\n\
    \ */\n\n#line 9 \"src/math/convolution.hpp\"\n#include <utility>\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line\
    \ 10 \"src/math/modint.hpp\"\n#include <limits>\n#include <type_traits>\n#include\
    \ <cstdint>\n#line 14 \"src/math/modint.hpp\"\n\nnamespace detail {\n    static\
    \ constexpr std::uint16_t prime32_bases[] {\n        15591,  2018,  166, 7429,\
    \  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128,  5212,\
    \  2657,\n         2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n         3185,  1333, 6227,\
    \ 5298,  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580, \
    \ 4729, 10239,\n          746,  2951,  556, 2206,  3778,   481,  1522,  3476,\
    \   481,  2487, 3266,  5633,   488,  3373,  6441,  3344,\n           17, 15105,\
    \ 1490, 4154,  2036,  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,  \
    \ 903,   737,  1887,\n         7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,\
    \  4304,   177,   41, 19875,  3110, 13221,  8726,   571,\n         7043,  6943,\
    \ 1199,  352,  6435,   165,  1169,  3315,   978,   233, 3003,  2562,  2994, 10587,\
    \ 10030,  2377,\n         1902,  5354, 4447, 1555,   263, 27027,  2283,   305,\
    \   669,  1912,  601,  6186,   429,  1930, 14873,  1784,\n         1661,   524,\
    \ 3577,  236,  2360,  6146,  2850, 55637,  1753,  4178, 8466,   222,  2579,  2743,\
    \  2031,  2226,\n         2276,   374, 2132,  813, 23788,  1610,  4422,  5159,\
    \  1725,  3597, 3366, 14336,   579,   165,  1375, 10018,\n        12616,  9816,\
    \ 1371,  536,  1867, 10864,   857,  2206,  5788,   434, 8085, 17618,   727,  3639,\
    \  1595,  4944,\n         2129,  2029, 8195, 8344,  6232,  9183,  8126,  1870,\
    \  3296,  7455, 8947, 25017,   541, 19115,   368,   566,\n         5674,   411,\
    \  522, 1027,  8215,  2050,  6544, 10049,   614,   774, 2333,  3007, 35201,  4706,\
    \  1152,  1785,\n         1028,  1540, 3743,  493,  4474,  2521, 26845,  8354,\
    \   864, 18915, 5465,  2447,    42,  4511,  1660,   166,\n         1249,  6259,\
    \ 2553,  304,   272,  7286,    73,  6554,   899,  2816, 5197, 13330,  7054,  2818,\
    \  3199,   811,\n          922,   350, 7514, 4452,  3449,  2663,  4708,   418,\
    \  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n    };\n\n    static\
    \ constexpr bool is_SPRP(std::uint32_t n, std::uint32_t a) noexcept {\n      \
    \  std::uint32_t d = n - 1;\n        std::uint32_t s = 0;\n        while ((d &\
    \ 1) == 0) {\n            ++s;\n            d >>= 1;\n        }\n        std::uint64_t\
    \ cur = 1;\n        std::uint64_t pw = d;\n        while (pw) {\n            if\
    \ (pw & 1) cur = (cur * a) % n;\n            a = (static_cast<std::uint64_t>(a)\
    \ * a) % n;\n            pw >>= 1;\n        }\n        if (cur == 1) return true;\n\
    \        for (std::uint32_t r = 0; r < s; ++r) {\n            if (cur == n - 1)\
    \ return true;\n            cur = (cur * cur) % n;\n        }\n        return\
    \ false;\n    }\n\n    // 32\u30D3\u30C3\u30C8\u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u306E\u7D20\u6570\u5224\u5B9A\n    // \u53C2\u8003: M. Forisek and J. Jancina,\
    \ \u201CFast Primality Testing for Integers That Fit into a Machine Word,\u201D\
    \ presented at the Conference on Current Trends in Theory and Practice of Informatics,\
    \ 2015.\n    [[nodiscard]]\n    static constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n        if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \        if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \        if (x < 121) return (x > 1);\n        std::uint64_t h = x;\n        h\
    \ = ((h >> 16) ^ h) * 0x45d9f3b;\n        h = ((h >> 16) ^ h) * 0x45d9f3b;\n \
    \       h = ((h >> 16) ^ h) & 0xff;\n        return is_SPRP(x, prime32_bases[h]);\n\
    \    }\n}\n\n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\
    \u3092 CRTP \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\
    \u30B9\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\
    \u30E9\u30B9\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\
    \u30AF\u30E9\u30B9\ntemplate <class Modint>\nclass modint_base {\npublic:\n  \
    \  /// @brief \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type\
    \ = std::uint32_t;\n\n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    constexpr modint_base() noexcept\n        : m_value{ 0 } {}\n\n  \
    \  /// @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral> &&\
    \ std::is_signed_v<SignedIntegral>>* = nullptr>\n    constexpr modint_base(SignedIntegral\
    \ value) noexcept\n        : m_value{ static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod()) } {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, std::enable_if_t<std::is_integral_v<UnsignedIntegral>\
    \ && std::is_unsigned_v<UnsignedIntegral>>* = nullptr>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{ static_cast<value_type>(value % Modint::mod())\
    \ } {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept\
    \ {\n        return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
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
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{ x } /= y);\n\
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
    \ Modint& x, const Modint& y) noexcept {\n        return not (x == y);\n    }\n\
    \n    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
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
    \    }\n\nprotected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\u30D1\
    \u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\nclass\
    \ static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\nprivate:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\npublic:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr static_modint(SignedIntegral value) noexcept\n   \
    \     : base_type{value} {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\
    \uFF1A @f$O(\\log value)@f$\n    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n\
    \    [[nodiscard]]\n    constexpr static_modint inv() const noexcept {\n     \
    \   if constexpr (detail::is_prime32(Mod)) {\n            assert(this->m_value\
    \ != 0 && \"The inverse element of zero does not exist.\");\n            return\
    \ this->pow(Mod - 2);\n        }\n        else {\n            return base_type::inv();\n\
    \        }\n    }\n};\n\n/// @brief \u5B9F\u884C\u6642\u306B\u6CD5\u304C\u6C7A\
    \u307E\u308B\u3068\u304D\u3001\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\
    \u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n/// @tparam ID \u3053\
    \u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\u5B9A\u3059\u308B\u3053\u3068\u304C\
    \u3067\u304D\u307E\u3059\ntemplate <int ID>\nclass dynamic_modint : public modint_base<dynamic_modint<ID>>\
    \ {\nprivate:\n    using base_type = modint_base<dynamic_modint<ID>>;\n\npublic:\n\
    \    using typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\
    \u5F97\u3057\u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n  \
    \  static value_type mod() noexcept {\n        return modulus;\n    }\n\n    ///\
    \ @brief \u6CD5\u3092\u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\
    \u3057\u3044\u6CD5\n    static void set_mod(value_type m) noexcept {\n       \
    \ assert(m > 0 && m <= std::numeric_limits<value_type>::max() / 2);\n        modulus\
    \ = m;\n    }\n\n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\
    \n    constexpr dynamic_modint() noexcept\n        : base_type{} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr dynamic_modint(SignedIntegral value) noexcept\n  \
    \      : base_type{value} {}\n\nprivate:\n    inline static value_type modulus\
    \ = 998244353;\n};\n\nusing modint998244353 = static_modint<998244353>;\nusing\
    \ modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    #line 13 \"src/math/convolution.hpp\"\n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\
    \n */\nnamespace NTT {\n    /**\n     * @brief \u539F\u5B50\u6839\n     * @param\
    \ MOD int\n     * @return int\n     */\n    inline int calc_primitive_root(int\
    \ MOD) {\n        if (MOD == 2) return 1;\n        if (MOD == 167772161) return\
    \ 3;\n        if (MOD == 469762049) return 3;\n        if (MOD == 754974721) return\
    \ 11;\n        if (MOD == 998244353) return 3;\n        int divs[20] = {};\n \
    \       divs[0] = 2;\n        int cnt = 1;\n        long long x = (MOD - 1) >>\
    \ 1;\n        while (x % 2 == 0) x >>= 1;\n        for (long long i = 3; i * i\
    \ <= x; i += 2) {\n            if (x % i == 0) {\n                divs[cnt ++]\
    \ = i;\n                while (x % i == 0) x /= i;\n            }\n        }\n\
    \        if (x > 1) divs[cnt++] = x;\n        for (int g = 2;; ++ g) {\n     \
    \       bool ok = true;\n            for (int i = 0; i < cnt; i++) {\n       \
    \         if (modpow(g, (MOD - 1) / divs[i], MOD) == 1) {\n                  \
    \  ok = false;\n                    break;\n                }\n            }\n\
    \            if (ok) return g;\n        }\n    }\n\n    /**\n     * @brief \u7573\
    \u307F\u8FBC\u307F\u306E\u30B5\u30A4\u30BA\u30922\u306E\u3079\u304D\u4E57\u306B\
    \u3059\u308B\n     */\n    inline int get_fft_size(int N, int M) {\n        int\
    \ size = 1;\n        while (size < N + M - 1) size <<= 1;\n        return size;\n\
    \    }\n\n    /**\n     * @brief NTT\n     */\n    template<class mint> void trans(std::vector<mint>&\
    \ v, bool inv = false) {\n        if (v.empty()) return;\n        int N = (int)\
    \ v.size();\n        int MOD = v[0].mod();\n        int PR = calc_primitive_root(MOD);\n\
    \        static bool first = true;\n        static std::vector<long long> vbw(30),\
    \ vibw(30);\n        if (first) {\n            first = false;\n            for\
    \ (int k = 0; k < 30; ++ k) {\n                vbw[k] = modpow(PR, (MOD - 1) >>\
    \ (k + 1), MOD);\n                vibw[k] = modinv(vbw[k], MOD);\n           \
    \ }\n        }\n        for (int i = 0, j = 1; j < N - 1; ++ j) {\n          \
    \  for (int k = N >> 1; k > (i ^= k); k >>= 1);\n            if (i > j) std::swap(v[i],\
    \ v[j]);\n        }\n        for (int k = 0, t = 2; t <= N; ++ k, t <<= 1) {\n\
    \            long long bw = vbw[k];\n            if (inv) bw = vibw[k];\n    \
    \        for (int i = 0; i < N; i += t) {\n                mint w = 1;\n     \
    \           for (int j = 0; j < (t >> 1); ++ j) {\n                    int j1\
    \ = i + j, j2 = i + j + (t >> 1);\n                    mint c1 = v[j1], c2 = v[j2]\
    \ * w;\n                    v[j1] = c1 + c2;\n                    v[j2] = c1 -\
    \ c2;\n                    w *= bw;\n                }\n            }\n      \
    \  }\n        if (inv) {\n            long long invN = modinv(N, MOD);\n     \
    \       for (int i = 0; i < N; ++ i) v[i] = v[i] * invN;\n        }\n    }\n\n\
    \    static constexpr int MOD0 = 754974721;\n    static constexpr int MOD1 = 167772161;\n\
    \    static constexpr int MOD2 = 469762049;\n    using mint0 = static_modint<MOD0>;\n\
    \    using mint1 = static_modint<MOD1>;\n    using mint2 = static_modint<MOD2>;\n\
    \    static const mint1 imod0 = 95869806; // modinv(MOD0, MOD1);\n    static const\
    \ mint2 imod1 = 104391568; // modinv(MOD1, MOD2);\n    static const mint2 imod01\
    \ = 187290749; // imod1 / MOD0;\n\n    /**\n     * @brief \u914D\u5217\u306E\u30B5\
    \u30A4\u30BA\u304C\u5C0F\u3055\u3044\u3068\u304D\u306E\u7573\u307F\u8FBC\u307F\
    \n     * @param T mint, long long\n     * @param A vector<T>\n     * @param B\
    \ vector<T>\n     * @return vector<T>\n     */\n    template<class T> std::vector<T>\
    \ naive\n    (const std::vector<T>& A, const std::vector<T>& B) {\n        if\
    \ (A.empty() || B.empty()) return {};\n        int N = (int) A.size(), M = (int)\
    \ B.size();\n        std::vector<T> res(N + M - 1);\n        for (int i = 0; i\
    \ < N; ++ i)\n            for (int j = 0; j < M; ++ j)\n                res[i\
    \ + j] += A[i] * B[j];\n        return res;\n    }\n};\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n * @param A vector<mint>\n * @param B vector<mint>\n\
    \ * @return vector<mint>\n */\ntemplate<class mint> std::vector<mint> convolution\n\
    (const std::vector<mint>& A, const std::vector<mint>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = (int) A.size(), M = (int) B.size();\n\
    \    if (std::min(N, M) < 30) return NTT::naive(A, B);\n    int MOD = A[0].mod();\n\
    \    int size_fft = NTT::get_fft_size(N, M);\n    if (MOD == 998244353) {\n  \
    \      std::vector<mint> a(size_fft), b(size_fft), c(size_fft);\n        for (int\
    \ i = 0; i < N; ++i) a[i] = A[i];\n        for (int i = 0; i < M; ++i) b[i] =\
    \ B[i];\n        NTT::trans(a), NTT::trans(b);\n        std::vector<mint> res(size_fft);\n\
    \        for (int i = 0; i < size_fft; ++i) res[i] = a[i] * b[i];\n        NTT::trans(res,\
    \ true);\n        res.resize(N + M - 1);\n        return res;\n    }\n    std::vector<NTT::mint0>\
    \ a0(size_fft, 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<NTT::mint1>\
    \ a1(size_fft, 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<NTT::mint2>\
    \ a2(size_fft, 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i <\
    \ N; ++ i) {\n        a0[i] = A[i].val();\n        a1[i] = A[i].val();\n     \
    \   a2[i] = A[i].val();\n    }\n    for (int i = 0; i < M; ++ i) {\n        b0[i]\
    \ = B[i].val();\n        b1[i] = B[i].val();\n        b2[i] = B[i].val();\n  \
    \  }\n    NTT::trans(a0), NTT::trans(a1), NTT::trans(a2), \n    NTT::trans(b0),\
    \ NTT::trans(b1), NTT::trans(b2);\n    for (int i = 0; i < size_fft; ++i) {\n\
    \        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] * b1[i];\n        c2[i]\
    \ = a2[i] * b2[i];\n    }\n    NTT::trans(c0, true), NTT::trans(c1, true), NTT::trans(c2,\
    \ true);\n    const mint mod0 = NTT::MOD0, mod01 = mod0 * NTT::MOD1;\n    std::vector<mint>\
    \ res(N + M - 1);\n    for (int i = 0; i < N + M - 1; ++ i) {\n        int y0\
    \ = c0[i].val();\n        int y1 = (NTT::imod0 * (c1[i] - y0)).val();\n      \
    \  int y2 = (NTT::imod01 * (c2[i] - y0) - NTT::imod1 * y1).val();\n        res[i]\
    \ = mod01 * y2 + mod0 * y1 + y0;\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ long long\u306E\u7573\u307F\u8FBC\u307F\n * @param A vector<long long>\n * @param\
    \ B vector<long long>\n * @return vector<long long>\n */\ninline std::vector<long\
    \ long> convolution_ll\n(const std::vector<long long>& A, const std::vector<long\
    \ long>& B) {\n    if (A.empty() || B.empty()) return {};\n    int N = (int) A.size(),\
    \ M = (int) B.size();\n    if (std::min(N, M) < 30) return NTT::naive(A, B);\n\
    \    int size_fft = NTT::get_fft_size(N, M);\n    std::vector<NTT::mint0> a0(size_fft,\
    \ 0), b0(size_fft, 0), c0(size_fft, 0);\n    std::vector<NTT::mint1> a1(size_fft,\
    \ 0), b1(size_fft, 0), c1(size_fft, 0);\n    std::vector<NTT::mint2> a2(size_fft,\
    \ 0), b2(size_fft, 0), c2(size_fft, 0);\n    for (int i = 0; i < N; ++ i) {\n\
    \        a0[i] = A[i];\n        a1[i] = A[i];\n        a2[i] = A[i];\n    }\n\
    \    for (int i = 0; i < M; ++ i) {\n        b0[i] = B[i];\n        b1[i] = B[i];\n\
    \        b2[i] = B[i];\n    }\n    NTT::trans(a0), NTT::trans(a1), NTT::trans(a2),\
    \ \n    NTT::trans(b0), NTT::trans(b1), NTT::trans(b2);\n    for (int i = 0; i\
    \ < size_fft; ++ i) {\n        c0[i] = a0[i] * b0[i];\n        c1[i] = a1[i] *\
    \ b1[i];\n        c2[i] = a2[i] * b2[i];\n    }\n    NTT::trans(c0, true), NTT::trans(c1,\
    \ true), NTT::trans(c2, true);\n    static const long long mod0 = NTT::MOD0, mod01\
    \ = mod0 * NTT::MOD1;\n    static const __int128_t mod012 = (__int128_t)mod01\
    \ * NTT::MOD2;\n    std::vector<long long> res(N + M - 1);\n    for (int i = 0;\
    \ i < N + M - 1; ++ i) {\n        int y0 = c0[i].val();\n        int y1 = (NTT::imod0\
    \ * (c1[i] - y0)).val();\n        int y2 = (NTT::imod01 * (c2[i] - y0) - NTT::imod1\
    \ * y1).val();\n        __int128_t tmp = (__int128_t)mod01 * y2 + (__int128_t)mod0\
    \ * y1 + y0;\n        if(tmp < (mod012 >> 1)) res[i] = tmp;\n        else res[i]\
    \ = tmp - mod012;\n    }\n    return res;\n}\n#line 13 \"src/math/fps.hpp\"\n\n\
    template <typename mint> struct FPS : std::vector<mint> {\n    using std::vector<mint>::vector;\n\
    \ \n    // constructor\n    FPS(const std::vector<mint>& r) : std::vector<mint>(r)\
    \ {}\n \n    // core operator\n    inline FPS pre(int siz) const {\n        return\
    \ FPS(begin(*this), begin(*this) + std::min((int)this->size(), siz));\n    }\n\
    \    inline FPS rev() const {\n        FPS res = *this;\n        reverse(begin(res),\
    \ end(res));\n        return res;\n    }\n    inline FPS& normalize() {\n    \
    \    while (!this->empty() && this->back() == 0) this->pop_back();\n        return\
    \ *this;\n    }\n \n    // basic operator\n    inline FPS operator - () const\
    \ noexcept {\n        FPS res = (*this);\n        for (int i = 0; i < (int)res.size();\
    \ ++i) res[i] = -res[i];\n        return res;\n    }\n    inline FPS operator\
    \ + (const mint& v) const { return FPS(*this) += v; }\n    inline FPS operator\
    \ + (const FPS& r) const { return FPS(*this) += r; }\n    inline FPS operator\
    \ - (const mint& v) const { return FPS(*this) -= v; }\n    inline FPS operator\
    \ - (const FPS& r) const { return FPS(*this) -= r; }\n    inline FPS operator\
    \ * (const mint& v) const { return FPS(*this) *= v; }\n    inline FPS operator\
    \ * (const FPS& r) const { return FPS(*this) *= r; }\n    inline FPS operator\
    \ / (const mint& v) const { return FPS(*this) /= v; }\n    inline FPS operator\
    \ << (int x) const { return FPS(*this) <<= x; }\n    inline FPS operator >> (int\
    \ x) const { return FPS(*this) >>= x; }\n    inline FPS& operator += (const mint&\
    \ v) {\n        if (this->empty()) this->resize(1);\n        (*this)[0] += v;\n\
    \        return *this;\n    }\n    inline FPS& operator += (const FPS& r) {\n\
    \        if (r.size() > this->size()) this->resize(r.size());\n        for (int\
    \ i = 0; i < (int)r.size(); ++i) (*this)[i] += r[i];\n        return this->normalize();\n\
    \    }\n    inline FPS& operator -= (const mint& v) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= v;\n        return *this;\n    }\n \
    \   inline FPS& operator -= (const FPS& r) {\n        if (r.size() > this->size())\
    \ this->resize(r.size());\n        for (int i = 0; i < (int)r.size(); ++i) (*this)[i]\
    \ -= r[i];\n        return this->normalize();\n    }\n    inline FPS& operator\
    \ *= (const mint& v) {\n        for (int i = 0; i < (int)this->size(); ++i) (*this)[i]\
    \ *= v;\n        return *this;\n    }\n    inline FPS& operator *= (const FPS&\
    \ r) {\n        return *this = convolution((*this), r);\n    }\n    inline FPS&\
    \ operator /= (const mint& v) {\n        assert(v != 0);\n        mint iv = v.inv();\n\
    \        for (int i = 0; i < (int)this->size(); ++i) (*this)[i] *= iv;\n     \
    \   return *this;\n    }\n    inline FPS& operator <<= (int x) {\n        FPS\
    \ res(x, 0);\n        res.insert(res.end(), begin(*this), end(*this));\n     \
    \   return *this = res;\n    }\n    inline FPS& operator >>= (int x) {\n     \
    \   if((int) this->size() <= x) return *this = FPS<mint> (1, 0);\n        FPS\
    \ res;\n        res.insert(res.end(), begin(*this) + x, end(*this));\n       \
    \ return *this = res;\n    }\n    inline mint eval(const mint& v){\n        mint\
    \ res = 0;\n        for (int i = (int)this->size()-1; i >= 0; --i) {\n       \
    \     res *= v;\n            res += (*this)[i];\n        }\n        return res;\n\
    \    }\n    inline friend FPS gcd(const FPS& f, const FPS& g) {\n        if (g.empty())\
    \ return f;\n        return gcd(g, f % g);\n    }\n \n    // advanced operation\n\
    \    // df/dx\n    inline friend FPS diff(const FPS& f) {\n        int n = (int)f.size();\n\
    \        if (n == 0) return FPS();\n        FPS res(n-1);\n        for (int i\
    \ = 1; i < n; ++i) res[i-1] = f[i] * i;\n        return res;\n    }\n \n    //\
    \ \\int f dx\n    inline friend FPS intg(const FPS& f) {\n        int n = (int)f.size();\n\
    \        FPS res(n+1, 0);\n        for (int i = 0; i < n; ++i) res[i+1] = f[i]\
    \ / (i+1);\n        return res;\n    }\n \n    // inv(f), f[0] must not be 0\n\
    \    inline friend FPS inv(const FPS& f, int deg) {\n        assert(!f.empty()\
    \ && f[0] != 0);\n        if (deg < 0) deg = (int)f.size();\n        if (deg ==\
    \ 0) return FPS();\n        FPS res({mint(1) / f[0]});\n        for (int i = 1;\
    \ i < deg; i <<= 1) {\n            res = (res + res - res * res * f.pre(i << 1)).pre(i\
    \ << 1);\n        }\n        res.resize(deg);\n        return res;\n    }\n  \
    \  inline friend FPS inv(const FPS& f) {\n        return inv(f, f.size());\n \
    \   }\n \n    // division, r must be normalized (r.back() must not be 0)\n   \
    \ inline FPS& operator /= (const FPS& r) {\n        assert(!r.empty());\n    \
    \    assert(r.back() != 0);\n        this->normalize();\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        int need = (int)this->size() - (int)r.size() + 1;\n        *this\
    \ = ((*this).rev().pre(need) * inv(r.rev(), need)).pre(need).rev();\n        return\
    \ *this;\n    }\n    inline FPS& operator %= (const FPS &r) {\n        assert(!r.empty());\n\
    \        assert(r.back() != 0);\n        this->normalize();\n        FPS q = (*this)\
    \ / r;\n        return *this -= q * r;\n    }\n    inline FPS operator / (const\
    \ FPS& r) const { return FPS(*this) /= r; }\n    inline FPS operator % (const\
    \ FPS& r) const { return FPS(*this) %= r; }\n \n    // log(f) = \\int f'/f dx,\
    \ f[0] must be 1\n    inline friend FPS log(const FPS& f, int deg) {\n       \
    \ assert(!f.empty() && f[0] == 1);\n        FPS res = intg(diff(f) * inv(f, deg));\n\
    \        res.resize(deg);\n        return res;\n    }\n    inline friend FPS log(const\
    \ FPS& f) {\n        return log(f, f.size());\n    }\n \n    // exp(f), f[0] must\
    \ be 0\n    inline friend FPS exp(const FPS& f, int deg) {\n        assert(f.empty()\
    \ || f[0] == 0);\n        FPS res(1, 1);\n        for (int i = 1; i < deg; i <<=\
    \ 1) {\n            res = res * (f.pre(i<<1) - log(res, i<<1) + 1).pre(i<<1);\n\
    \        }\n        res.resize(deg);\n        return res;\n    }\n    inline friend\
    \ FPS exp(const FPS& f) {\n        return exp(f, f.size());\n    }\n \n    //\
    \ pow(f) = exp(e * log f)\n    inline friend FPS pow(const FPS& f, long long e,\
    \ int deg) {\n        if(e == 0) {\n            auto ret = FPS(deg, 0);\n    \
    \        if (deg > 0) ret[0] = 1;\n            return ret;\n        }\n      \
    \  long long i = 0;\n        while (i < (int)f.size() && f[i] == 0) ++i;\n   \
    \     if (i == (int)f.size()) return FPS(deg, 0);\n        if ((i >= 1 and e >=\
    \ deg) or i * e >= deg) return FPS(deg, 0);\n        mint k = f[i];\n        FPS\
    \ res = exp(log((f >> i) / k, deg) * e, deg) * k.pow(e) << (e * i);\n        res.resize(deg);\n\
    \        return res;\n    }\n    inline friend FPS pow(const FPS& f, long long\
    \ e) {\n        return pow(f, e, f.size());\n    }\n\n    inline friend FPS taylor_shift(FPS\
    \ f, mint a) {\n        using C = Combination<mint>;\n        int n = f.size();\n\
    \        C::extend(n);\n        for(int i = 0; i < n; i ++) f[i] *= C::factorial(i);\n\
    \        std::reverse(f.begin(), f.end());\n        FPS<mint> g(n, 1);\n     \
    \   for(int i = 1; i < n; i ++) g[i] = g[i - 1] * a * C::inv(i);\n        f =\
    \ (f * g).pre(n);\n        std::reverse(f.begin(), f.end());\n        for(int\
    \ i = 0; i < n; i ++) f[i] *= C::inverse_factorial(i);\n        return f;\n  \
    \  }\n};\n\ntemplate <typename mint> FPS<mint> modpow(const FPS<mint> &f, long\
    \ long n, const FPS<mint> &m) {\n    if (n == 0) return FPS<mint>(1, 1);\n   \
    \ auto t = modpow(f, n / 2, m);\n    t = (t * t) % m;\n    if (n & 1) t = (t *\
    \ f) % m;\n    return t;\n}\n#line 12 \"test/unittest/fps.test.cpp\"\n\nusing\
    \ mint = static_modint<998244353>;\nusing F = FPS<mint>;\nusing P = std::vector<mint>;\n\
    \nP trim(P a) {\n    while (!a.empty() && a.back() == 0) a.pop_back();\n    return\
    \ a;\n}\nP naive_mul(const P& a, const P& b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    P c(a.size() + b.size() - 1);\n    for (size_t i = 0; i < a.size();\
    \ i++)\n        for (size_t j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];\n\
    \    return c;\n}\n// \u591A\u9805\u5F0F\u306E\u4F59\u308A (b \u306F\u672B\u5C3E\
    \u304C 0 \u3067\u306A\u3044\u3053\u3068)\nP naive_mod(P a, const P& b) {\n   \
    \ a = trim(a);\n    while (a.size() >= b.size()) {\n        mint c = a.back()\
    \ / b.back();\n        size_t s = a.size() - b.size();\n        for (size_t i\
    \ = 0; i < b.size(); i++) a[s + i] -= c * b[i];\n        a = trim(a);\n    }\n\
    \    return a;\n}\n// \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u3092 1 \u306B\u3059\
    \u308B\nP monic(P a) {\n    a = trim(a);\n    if (a.empty()) return a;\n    mint\
    \ c = a.back().inv();\n    for (auto& x : a) x *= c;\n    return a;\n}\nP naive_gcd(P\
    \ a, P b) {\n    a = trim(a), b = trim(b);\n    while (!b.empty()) {\n       \
    \ P r = naive_mod(a, b);\n        a = b;\n        b = r;\n    }\n    return monic(a);\n\
    }\nP random_poly(std::mt19937_64& rng, int n, bool nonzero_lead) {\n    P a(n);\n\
    \    for (auto& x : a) x = (long long)(rng() % 998244353);\n    if (rng() % 4\
    \ == 0)\n        for (auto& x : a) x = (long long)(rng() % 3);  // 0 \u3092\u591A\
    \u3081\u306B\u542B\u3080\n    if (nonzero_lead && n > 0 && a.back() == 0) a.back()\
    \ = 1;\n    return a;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool\
    \ ok = true;\n\n    for (int rep = 0; rep < 300; rep++) {\n        int n = rng()\
    \ % 8;\n        P a = random_poly(rng, n, false);\n        F f(a);\n        //\
    \ \u5358\u9805\u306E -: \u5404\u4FC2\u6570\u306E\u7B26\u53F7\u3092\u53CD\u8EE2\
    \u3057\u3001\u9577\u3055\u306F\u5909\u308F\u3089\u306A\u3044\n        F g = -f;\n\
    \        if (g.size() != a.size()) ok = false;\n        for (size_t i = 0; i <\
    \ a.size(); i++)\n            if (g[i] != -a[i]) ok = false;\n        // \u5B9A\
    \u6570\u3092\u5F15\u304F: \u5B9A\u6570\u9805\u304B\u3089\u5F15\u304F (\u7A7A\u306A\
    \u3089\u9577\u3055 1 \u306B\u306A\u308B)\u3002\u9577\u3055\u306F\u305D\u308C\u4EE5\
    \u5916\u5909\u308F\u3089\u306A\u3044\n        mint c = (long long)(rng() % 998244353);\n\
    \        F h = f - c;\n        P e = a.empty() ? P{-c} : a;\n        if (!a.empty())\
    \ e[0] -= c;\n        if (P(h) != e) ok = false;\n        F h2 = f;\n        h2\
    \ -= c;\n        if (P(h2) != e) ok = false;\n        // \u5B9A\u6570\u3092\u8DB3\
    \u3059\u306E\u3068\u6253\u3061\u6D88\u3057\u5408\u3046\n        if (P(f - c +\
    \ c) != (a.empty() ? P{0} : a)) ok = false;\n        // eval: f(x) \u3092\u611A\
    \u76F4\u306B\u8A08\u7B97\u3057\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\
    \n        for (int t = 0; t < 5; t++) {\n            mint x = (t == 0) ? mint(0)\
    \ : mint((long long)(rng() % 998244353));\n            mint s = 0, pw = 1;\n \
    \           for (auto& coef : a) s += coef * pw, pw *= x;\n            if (f.eval(x)\
    \ != s) ok = false;\n        }\n    }\n    if (!ok) std::cerr << \"unary minus\
    \ / minus const / eval\" << std::endl;\n\n    // gcd: \u5171\u901A\u56E0\u5B50\
    \ h \u3092\u639B\u3051\u305F 2 \u3064\u306E\u591A\u9805\u5F0F\u306E gcd \u304C\
    \ h \u306E\u5B9A\u6570\u500D\u306B\u306A\u308B\u3002NTT \u3092\u4F7F\u3046\u9577\
    \u3055\u3082\u542B\u3081\u308B\n    for (int rep = 0; rep < 150 && ok; rep++)\
    \ {\n        int big = (rep % 5 == 0) ? 40 : 0;\n        P h = random_poly(rng,\
    \ rng() % 5 + 1 + big / 4, true);\n        P x = random_poly(rng, rng() % 6 +\
    \ 1 + big, true);\n        P y = random_poly(rng, rng() % 6 + 1 + big, true);\n\
    \        P a = trim(naive_mul(h, x)), b = trim(naive_mul(h, y));\n        F d\
    \ = gcd(F(a), F(b));\n        if (monic(P(d)) != naive_gcd(a, b)) ok = false,\
    \ std::cerr << \"gcd \" << rep << std::endl;\n        // \u5F15\u6570\u306E\u9806\
    \u3092\u5165\u308C\u66FF\u3048\u3066\u3082\u540C\u3058 (\u5B9A\u6570\u500D\u3092\
    \u9664\u3044\u3066)\n        if (monic(P(gcd(F(b), F(a)))) != naive_gcd(a, b))\
    \ ok = false;\n        // \u5272\u308A\u5207\u308B\n        if (!trim(P(F(a) %\
    \ d)).empty() || !trim(P(F(b) % d)).empty()) ok = false;\n    }\n    // \u7247\
    \u65B9\u304C 0 (\u7A7A) \u306A\u3089\u3001\u3082\u3046\u7247\u65B9\u3092\u8FD4\
    \u3059\n    {\n        P a = {1, 2, 3};\n        if (monic(P(gcd(F(a), F())))\
    \ != monic(a)) ok = false;\n        if (monic(P(gcd(F(), F(a)))) != monic(a))\
    \ ok = false;\n    }\n\n    // modpow: f^n mod m \u3092\u3001\u611A\u76F4\u306B\
    \u639B\u3051\u3066\u4F59\u308A\u3092\u53D6\u3063\u305F\u3082\u306E\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 200 && ok; rep++) {\n        int deg_m\
    \ = rng() % 6 + 1;  // m \u306E\u6B21\u6570\u306F 1 \u4EE5\u4E0A\n        if (rep\
    \ % 10 == 0) deg_m = 40;\n        P m = random_poly(rng, deg_m + 1, true);\n \
    \       P f = random_poly(rng, rng() % 8, false);\n        long long n = (rep\
    \ % 3 == 0) ? (long long)(rng() % 1000000000000LL) : (long long)(rng() % 20);\n\
    \        F got = modpow(F(f), n, F(m));\n        // \u611A\u76F4: \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u611A\u76F4\u306A\u639B\u3051\u7B97\u3068\
    \u4F59\u308A\u3067\u884C\u3046\n        P res = naive_mod(P{1}, m), base = naive_mod(f,\
    \ m);\n        for (long long k = n; k > 0; k >>= 1) {\n            if (k & 1)\
    \ res = naive_mod(naive_mul(res, base), m);\n            base = naive_mod(naive_mul(base,\
    \ base), m);\n        }\n        if (trim(P(got)) != trim(res)) ok = false, std::cerr\
    \ << \"modpow \" << rep << std::endl;\n    }\n    // n = 0 \u306F 1\n    if (P(modpow(F(P{5,\
    \ 6}), 0, F(P{1, 1, 1}))) != P{1}) ok = false;\n\n    if (ok) std::cout << \"\
    Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// FPS \u306E\u5358\u9805\u306E -\u3001\u5B9A\u6570\u3092\u5F15\u304F -\u3001\
    eval\u3001gcd\u3001modpow \u3092\u611A\u76F4\u306A\u591A\u9805\u5F0F\u6F14\u7B97\
    \u3068\u6BD4\u8F03\u3059\u308B\n// FPS \u306E + \u3068 - \u306F\u7D50\u679C\u306E\
    \u672B\u5C3E\u306E 0 \u3092\u53D6\u308A\u9664\u304F (\u4ED5\u69D8) \u306E\u3067\
    \u3001\u591A\u9805\u5F0F\u3068\u3057\u3066\u306E\u6BD4\u8F03\u306F\u672B\u5C3E\
    \u306E 0 \u3092\u9664\u3044\u3066\u884C\u3046\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#include \"../../src/math/fps.hpp\"\n\nusing\
    \ mint = static_modint<998244353>;\nusing F = FPS<mint>;\nusing P = std::vector<mint>;\n\
    \nP trim(P a) {\n    while (!a.empty() && a.back() == 0) a.pop_back();\n    return\
    \ a;\n}\nP naive_mul(const P& a, const P& b) {\n    if (a.empty() || b.empty())\
    \ return {};\n    P c(a.size() + b.size() - 1);\n    for (size_t i = 0; i < a.size();\
    \ i++)\n        for (size_t j = 0; j < b.size(); j++) c[i + j] += a[i] * b[j];\n\
    \    return c;\n}\n// \u591A\u9805\u5F0F\u306E\u4F59\u308A (b \u306F\u672B\u5C3E\
    \u304C 0 \u3067\u306A\u3044\u3053\u3068)\nP naive_mod(P a, const P& b) {\n   \
    \ a = trim(a);\n    while (a.size() >= b.size()) {\n        mint c = a.back()\
    \ / b.back();\n        size_t s = a.size() - b.size();\n        for (size_t i\
    \ = 0; i < b.size(); i++) a[s + i] -= c * b[i];\n        a = trim(a);\n    }\n\
    \    return a;\n}\n// \u6700\u9AD8\u6B21\u306E\u4FC2\u6570\u3092 1 \u306B\u3059\
    \u308B\nP monic(P a) {\n    a = trim(a);\n    if (a.empty()) return a;\n    mint\
    \ c = a.back().inv();\n    for (auto& x : a) x *= c;\n    return a;\n}\nP naive_gcd(P\
    \ a, P b) {\n    a = trim(a), b = trim(b);\n    while (!b.empty()) {\n       \
    \ P r = naive_mod(a, b);\n        a = b;\n        b = r;\n    }\n    return monic(a);\n\
    }\nP random_poly(std::mt19937_64& rng, int n, bool nonzero_lead) {\n    P a(n);\n\
    \    for (auto& x : a) x = (long long)(rng() % 998244353);\n    if (rng() % 4\
    \ == 0)\n        for (auto& x : a) x = (long long)(rng() % 3);  // 0 \u3092\u591A\
    \u3081\u306B\u542B\u3080\n    if (nonzero_lead && n > 0 && a.back() == 0) a.back()\
    \ = 1;\n    return a;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool\
    \ ok = true;\n\n    for (int rep = 0; rep < 300; rep++) {\n        int n = rng()\
    \ % 8;\n        P a = random_poly(rng, n, false);\n        F f(a);\n        //\
    \ \u5358\u9805\u306E -: \u5404\u4FC2\u6570\u306E\u7B26\u53F7\u3092\u53CD\u8EE2\
    \u3057\u3001\u9577\u3055\u306F\u5909\u308F\u3089\u306A\u3044\n        F g = -f;\n\
    \        if (g.size() != a.size()) ok = false;\n        for (size_t i = 0; i <\
    \ a.size(); i++)\n            if (g[i] != -a[i]) ok = false;\n        // \u5B9A\
    \u6570\u3092\u5F15\u304F: \u5B9A\u6570\u9805\u304B\u3089\u5F15\u304F (\u7A7A\u306A\
    \u3089\u9577\u3055 1 \u306B\u306A\u308B)\u3002\u9577\u3055\u306F\u305D\u308C\u4EE5\
    \u5916\u5909\u308F\u3089\u306A\u3044\n        mint c = (long long)(rng() % 998244353);\n\
    \        F h = f - c;\n        P e = a.empty() ? P{-c} : a;\n        if (!a.empty())\
    \ e[0] -= c;\n        if (P(h) != e) ok = false;\n        F h2 = f;\n        h2\
    \ -= c;\n        if (P(h2) != e) ok = false;\n        // \u5B9A\u6570\u3092\u8DB3\
    \u3059\u306E\u3068\u6253\u3061\u6D88\u3057\u5408\u3046\n        if (P(f - c +\
    \ c) != (a.empty() ? P{0} : a)) ok = false;\n        // eval: f(x) \u3092\u611A\
    \u76F4\u306B\u8A08\u7B97\u3057\u305F\u3082\u306E\u3068\u4E00\u81F4\u3059\u308B\
    \n        for (int t = 0; t < 5; t++) {\n            mint x = (t == 0) ? mint(0)\
    \ : mint((long long)(rng() % 998244353));\n            mint s = 0, pw = 1;\n \
    \           for (auto& coef : a) s += coef * pw, pw *= x;\n            if (f.eval(x)\
    \ != s) ok = false;\n        }\n    }\n    if (!ok) std::cerr << \"unary minus\
    \ / minus const / eval\" << std::endl;\n\n    // gcd: \u5171\u901A\u56E0\u5B50\
    \ h \u3092\u639B\u3051\u305F 2 \u3064\u306E\u591A\u9805\u5F0F\u306E gcd \u304C\
    \ h \u306E\u5B9A\u6570\u500D\u306B\u306A\u308B\u3002NTT \u3092\u4F7F\u3046\u9577\
    \u3055\u3082\u542B\u3081\u308B\n    for (int rep = 0; rep < 150 && ok; rep++)\
    \ {\n        int big = (rep % 5 == 0) ? 40 : 0;\n        P h = random_poly(rng,\
    \ rng() % 5 + 1 + big / 4, true);\n        P x = random_poly(rng, rng() % 6 +\
    \ 1 + big, true);\n        P y = random_poly(rng, rng() % 6 + 1 + big, true);\n\
    \        P a = trim(naive_mul(h, x)), b = trim(naive_mul(h, y));\n        F d\
    \ = gcd(F(a), F(b));\n        if (monic(P(d)) != naive_gcd(a, b)) ok = false,\
    \ std::cerr << \"gcd \" << rep << std::endl;\n        // \u5F15\u6570\u306E\u9806\
    \u3092\u5165\u308C\u66FF\u3048\u3066\u3082\u540C\u3058 (\u5B9A\u6570\u500D\u3092\
    \u9664\u3044\u3066)\n        if (monic(P(gcd(F(b), F(a)))) != naive_gcd(a, b))\
    \ ok = false;\n        // \u5272\u308A\u5207\u308B\n        if (!trim(P(F(a) %\
    \ d)).empty() || !trim(P(F(b) % d)).empty()) ok = false;\n    }\n    // \u7247\
    \u65B9\u304C 0 (\u7A7A) \u306A\u3089\u3001\u3082\u3046\u7247\u65B9\u3092\u8FD4\
    \u3059\n    {\n        P a = {1, 2, 3};\n        if (monic(P(gcd(F(a), F())))\
    \ != monic(a)) ok = false;\n        if (monic(P(gcd(F(), F(a)))) != monic(a))\
    \ ok = false;\n    }\n\n    // modpow: f^n mod m \u3092\u3001\u611A\u76F4\u306B\
    \u639B\u3051\u3066\u4F59\u308A\u3092\u53D6\u3063\u305F\u3082\u306E\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 200 && ok; rep++) {\n        int deg_m\
    \ = rng() % 6 + 1;  // m \u306E\u6B21\u6570\u306F 1 \u4EE5\u4E0A\n        if (rep\
    \ % 10 == 0) deg_m = 40;\n        P m = random_poly(rng, deg_m + 1, true);\n \
    \       P f = random_poly(rng, rng() % 8, false);\n        long long n = (rep\
    \ % 3 == 0) ? (long long)(rng() % 1000000000000LL) : (long long)(rng() % 20);\n\
    \        F got = modpow(F(f), n, F(m));\n        // \u611A\u76F4: \u7E70\u308A\
    \u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u611A\u76F4\u306A\u639B\u3051\u7B97\u3068\
    \u4F59\u308A\u3067\u884C\u3046\n        P res = naive_mod(P{1}, m), base = naive_mod(f,\
    \ m);\n        for (long long k = n; k > 0; k >>= 1) {\n            if (k & 1)\
    \ res = naive_mod(naive_mul(res, base), m);\n            base = naive_mod(naive_mul(base,\
    \ base), m);\n        }\n        if (trim(P(got)) != trim(res)) ok = false, std::cerr\
    \ << \"modpow \" << rep << std::endl;\n    }\n    // n = 0 \u306F 1\n    if (P(modpow(F(P{5,\
    \ 6}), 0, F(P{1, 1, 1}))) != P{1}) ok = false;\n\n    if (ok) std::cout << \"\
    Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/fps.hpp
  - src/math/combinatorics.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/unittest/fps.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 07:01:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/fps.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/fps.test.cpp
- /verify/test/unittest/fps.test.cpp.html
title: test/unittest/fps.test.cpp
---
