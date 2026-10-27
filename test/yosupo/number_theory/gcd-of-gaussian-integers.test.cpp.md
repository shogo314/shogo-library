---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/gaussian-integer.hpp
    title: "\u30AC\u30A6\u30B9\u6574\u6570\u3068\u4E8C\u5E73\u65B9\u548C"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/math/prime.hpp
    title: "\u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\
      \u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9\u3001\u539F\u59CB\u6839)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_of_gaussian_integers
    links:
    - https://judge.yosupo.jp/problem/gcd_of_gaussian_integers
  bundledCode: "#line 1 \"test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_of_gaussian_integers\"\
    \n\n#include <iostream>\n\n#line 2 \"src/math/gaussian-integer.hpp\"\n\n/**\n\
    \ * @file gaussian-integer.hpp\n * @brief \u30AC\u30A6\u30B9\u6574\u6570 (a +\
    \ bi\u3001a \u3068 b \u306F\u6574\u6570) \u3068\u4E8C\u5E73\u65B9\u548C\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file modular-arithmetic.hpp\n\
    \ * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
    \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)\n */\n\n#line 10 \"src/math/modular-arithmetic.hpp\"\
    \n#include <cmath>\n#include <numeric>\n#include <unordered_map>\n\n/**\n * @brief\
    \ a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\
    \u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr\
    \ long long modmul(long long a, long long b, long long m) {\n    long long res\
    \ = static_cast<long long>(static_cast<__int128>(a) * b % m);\n    if (res < 0)\
    \ res += m;\n    return res;\n}\n\n/**\n * @brief a^(-1) mod m \u3092\u8FD4\u3059\
    \n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\
    \u3002O(log m)\n */\nconstexpr long long modinv(long long a, long long m) {\n\
    \    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    long long b = m,\
    \ u = 1, v = 0;\n    while (b) {\n        // std::swap \u306F C++17 \u3067\u306F\
    \ constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\u308F\u305A\u306B\u66F8\
    \u304F\n        long long t = a / b;\n        long long c = a - t * b;\n     \
    \   a = b, b = c;\n        long long w = u - t * v;\n        u = v, v = w;\n \
    \   }\n    assert(a == 1 && \"a and m must be coprime\");\n    u %= m;\n    if\
    \ (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n mod m \u3092\u8FD4\u3059\
    \n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E -n \u4E57 (a \u3068 m \u306F\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068)\u3002O(log |n|)\n */\n\
    constexpr long long modpow(long long a, long long n, long long m) {\n    assert(m\
    \ >= 1);\n    a %= m;\n    if (a < 0) a += m;\n    if (n < 0) {\n        n = -n;\n\
    \        a = modinv(a, m);\n    }\n    long long res = 1 % m;\n    while (n >\
    \ 0) {\n        if (n & 1) res = modmul(res, a, m);\n        a = modmul(a, a,\
    \ m);\n        n >>= 1;\n    }\n    return res;\n}\n\n/**\n * @brief a^x \u2261\
    \ b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E x >= 0 (\u306A\u3051\u308C\u3070\
    \ -1)\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u306A\u304F\u3066\
    \u3082\u3088\u3044\u3002Baby-step Giant-step \u3067 O(\u221Am) \u306E\u6642\u9593\
    \u3068\u30E1\u30E2\u30EA\n */\ninline long long discrete_log(long long a, long\
    \ long b, long long m) {\n    assert(m >= 1);\n    a %= m, b %= m;\n    if (a\
    \ < 0) a += m;\n    if (b < 0) b += m;\n    if (m == 1) return 0;\n    // a \u3068\
    \ m \u304C\u4E92\u3044\u306B\u7D20\u306B\u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092\
    \ gcd \u3067\u5272\u308B\u3002k = a^add / (\u5272\u3063\u305F gcd \u306E\u7A4D\
    ) mod m\n    long long k = 1, add = 0, g;\n    while ((g = std::gcd(a, m)) > 1)\
    \ {\n        if (b == k) return add;\n        if (b % g != 0) return -1;\n   \
    \     b /= g, m /= g, add++;\n        k = modmul(k, a / g, m);\n    }\n    //\
    \ k a^x \u2261 b \u3092 x = n p - q (1 <= p <= n\u30010 <= q <= n) \u3068\u66F8\
    \u3044\u3066\u89E3\u304F\n    const long long n = static_cast<long long>(std::sqrt(static_cast<long\
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
    \    }\n    return std::min(r, p - r);\n}\n#line 2 \"src/math/prime.hpp\"\n\n\
    /**\n * @file prime.hpp\n * @brief \u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\
    \u7D20\u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9\u3001\
    \u539F\u59CB\u6839)\n */\n\n#line 11 \"src/math/prime.hpp\"\n#include <initializer_list>\n\
    #line 16 \"src/math/prime.hpp\"\n\n#line 18 \"src/math/prime.hpp\"\n\nnamespace\
    \ internal_prime {\n\nusing u64 = unsigned long long;\n\n/**\n * @brief Pollard\
    \ \u306E \u03C1 \u6CD5 (Brent \u306E\u6539\u826F) \u3067\u5408\u6210\u6570 n \u306E\
    \ 1 \u3067\u3082 n \u3067\u3082\u306A\u3044\u7D04\u6570\u3092 1 \u3064\u898B\u3064\
    \u3051\u308B\n */\ninline u64 find_factor(u64 n) {\n    if (n % 2 == 0) return\
    \ 2;\n    constexpr u64 m = 128;\n    for (u64 c = 1;; c++) {\n        auto f\
    \ = [&](u64 x) { return (modmul(x, x, n) + c) % n; };\n        auto diff = [](u64\
    \ x, u64 y) { return x > y ? x - y : y - x; };\n        u64 x = 0, y = 2, ys =\
    \ 2, q = 1, g = 1;\n        for (u64 r = 1; g == 1; r <<= 1) {\n            x\
    \ = y;\n            for (u64 i = 0; i < r; i++) y = f(y);\n            for (u64\
    \ k = 0; k < r && g == 1; k += m) {\n                ys = y;\n               \
    \ for (u64 i = 0; i < m && i < r - k; i++) {\n                    y = f(y);\n\
    \                    q = modmul(q, diff(x, y), n);\n                }\n      \
    \          g = std::gcd(q, n);\n            }\n        }\n        if (g == n)\
    \ {\n            // \u307E\u3068\u3081\u3066\u639B\u3051\u305F\u305B\u3044\u3067\
    \ n \u306B\u306A\u3063\u305F\u306E\u3067\u30011 \u3064\u305A\u3064\u623B\u3063\
    \u3066\u78BA\u304B\u3081\u308B\n            do {\n                ys = f(ys);\n\
    \                g = std::gcd(diff(x, ys), n);\n            } while (g == 1);\n\
    \        }\n        if (g != n) return g;\n    }\n}\n\n}  // namespace internal_prime\n\
    \n/**\n * @brief n \u304C\u7D20\u6570\u304B (Miller-Rabin\u300164 bit \u3067\u6C7A\
    \u5B9A\u7684) O(log n)\n */\nconstexpr bool is_prime(long long n) {\n    using\
    \ namespace internal_prime;\n    if (n < 2) return false;\n    for (u64 p : {2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (static_cast<u64>(n)\
    \ % p == 0) return static_cast<u64>(n) == p;\n    }\n    const u64 m = n;\n  \
    \  u64 d = m - 1;\n    int s = 0;\n    while (d % 2 == 0) d /= 2, s++;\n    for\
    \ (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})\
    \ {\n        a %= m;\n        if (a == 0) continue;\n        u64 x = modpow(a,\
    \ d, m);\n        if (x == 1 || x == m - 1) continue;\n        bool composite\
    \ = true;\n        for (int i = 1; i < s; i++) {\n            x = modmul(x, x,\
    \ m);\n            if (x == m - 1) {\n                composite = false;\n   \
    \             break;\n            }\n        }\n        if (composite) return\
    \ false;\n    }\n    return true;\n}\n\n/**\n * @brief n (>= 1) \u3092\u7D20\u56E0\
    \u6570\u5206\u89E3\u3057\u3001(\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\
    \u6570\u306E\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n * Pollard \u306E\
    \ \u03C1 \u6CD5\u3092\u4F7F\u3046\u3002\u671F\u5F85 O(n^(1/4)) \u7A0B\u5EA6\n\
    \ */\ninline std::vector<std::pair<long long, long long>> factorize(long long\
    \ n) {\n    assert(n >= 1);\n    std::vector<long long> ps;\n    // \u5C0F\u3055\
    \u3044\u7D20\u56E0\u6570\u306F\u5272\u308A\u7B97\u3067\u53D6\u308A\u9664\u304F\
    \n    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n   \
    \     while (n % p == 0) {\n            ps.push_back(p);\n            n /= p;\n\
    \        }\n    }\n    std::vector<long long> st;\n    if (n > 1) st.push_back(n);\n\
    \    while (!st.empty()) {\n        long long x = st.back();\n        st.pop_back();\n\
    \        if (is_prime(x)) {\n            ps.push_back(x);\n            continue;\n\
    \        }\n        long long d = internal_prime::find_factor(x);\n        st.push_back(d);\n\
    \        st.push_back(x / d);\n    }\n    std::sort(ps.begin(), ps.end());\n \
    \   std::vector<std::pair<long long, long long>> res;\n    for (long long p :\
    \ ps) {\n        if (!res.empty() && res.back().first == p)\n            res.back().second++;\n\
    \        else\n            res.emplace_back(p, 1);\n    }\n    return res;\n}\n\
    \n/**\n * @brief n (>= 1) \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059\n */\ninline std::vector<long long> divisors(long\
    \ long n) {\n    std::vector<long long> res = {1};\n    for (auto [p, e] : factorize(n))\
    \ {\n        const long long sz = res.size();\n        long long pw = 1;\n   \
    \     for (long long i = 0; i < e; i++) {\n            pw *= p;\n            for\
    \ (long long j = 0; j < sz; j++) res.push_back(res[j] * pw);\n        }\n    }\n\
    \    std::sort(res.begin(), res.end());\n    return res;\n}\n\n/**\n * @brief\
    \ \u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u95A2\u6570 (1 \u4EE5\u4E0A n \u4EE5\u4E0B\
    \u3067 n \u3068\u4E92\u3044\u306B\u7D20\u306A\u6574\u6570\u306E\u500B\u6570)\n\
    \ */\ninline long long totient(long long n) {\n    long long res = n;\n    for\
    \ (auto [p, e] : factorize(n)) res = res / p * (p - 1);\n    return res;\n}\n\n\
    /**\n * @brief m (>= 1) \u3092\u6CD5\u3068\u3059\u308B\u6700\u5C0F\u306E\u539F\
    \u59CB\u6839 (\u306A\u3051\u308C\u3070 -1)\n * \u539F\u59CB\u6839\u304C\u3042\u308B\
    \u306E\u306F m = 1, 2, 4, p^k, 2p^k (p \u306F\u5947\u7D20\u6570) \u306E\u3068\u304D\
    \u3002m = 1 \u306A\u3089 0 \u3092\u8FD4\u3059\n * \u7D20\u56E0\u6570\u5206\u89E3\
    \u3092\u4F7F\u3046\u306E\u3067\u3001m \u304C 10^18 \u7A0B\u5EA6\u3067\u3082\u901F\
    \u3044\n */\ninline long long primitive_root(long long m) {\n    assert(m >= 1);\n\
    \    if (m == 1) return 0;\n    if (m == 2) return 1;\n    if (m == 4) return\
    \ 3;\n    auto fm = factorize(m);\n    // m = p^k \u304B 2 p^k (p \u306F\u5947\
    \u7D20\u6570) \u304B\n    if (fm.size() > 2 || (fm.size() == 2 && !(fm[0].first\
    \ == 2 && fm[0].second == 1)) || (fm.size() == 1 && fm[0].first == 2)) return\
    \ -1;\n    long long phi = m;\n    for (auto [p, e] : fm) phi = phi / p * (p -\
    \ 1);\n    auto fphi = factorize(phi);\n    // g \u306E\u4F4D\u6570\u304C \u03C6\
    (m) \u3067\u3042\u308B\u3053\u3068: \u03C6(m) \u306E\u3069\u306E\u7D20\u56E0\u6570\
    \ q \u306B\u3064\u3044\u3066\u3082 g^(\u03C6(m)/q) \u304C 1 \u3067\u306A\u3044\
    \n    for (long long g = 2;; g++) {\n        if (std::gcd(g, m) != 1) continue;\n\
    \        bool ok = true;\n        for (auto [q, e] : fphi) {\n            if (modpow(g,\
    \ phi / q, m) == 1) {\n                ok = false;\n                break;\n \
    \           }\n        }\n        if (ok) return g;\n    }\n}\n\n/**\n * @brief\
    \ \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^k \u2261 a (mod p) \u3068\u306A\u308B\
    \ x \u3092 1 \u3064\u8FD4\u3059 (\u306A\u3051\u308C\u3070 -1)\u30020^0 = 1 \u3068\
    \u3059\u308B\n *\n * g = gcd(k, p - 1) \u3068\u3057\u3066 g \u4E57\u6839 z \u3092\
    \u6C42\u3081\u3001x = z^(k/g \u306E\u9006\u6570 mod (p-1)/g) \u3068\u3059\u308B\
    \n * g \u4E57\u6839\u306F\u3001g \u306E\u7D20\u56E0\u6570 q \u3054\u3068\u306B\
    \u3001\u4F4D\u6570 q^s \u306E\u90E8\u5206\u7FA4\u306E\u4E2D\u3067 Pohlig-Hellman\
    \ \u6CD5 (q \u306E\u90E8\u5206\u306F baby-step giant-step) \u3092\u4F7F\u3063\u3066\
    \u76F4\u3059\n * O(\u03A3_q (s sqrt(q) + log^2 p)) \u306B p - 1 \u306E\u7D20\u56E0\
    \u6570\u5206\u89E3\u3092\u8DB3\u3057\u305F\u3082\u306E\n */\ninline long long\
    \ kth_root_mod(long long k, long long a, long long p) {\n    assert(k >= 0 &&\
    \ p >= 2);\n    a %= p;\n    if (a < 0) a += p;\n    if (k == 0) return a == 1\
    \ % p ? 1 : -1;\n    if (a == 0) return 0;\n    const long long m = p - 1, g =\
    \ std::gcd(k, m);\n    if (modpow(a, m / g, p) != 1) return -1;\n    long long\
    \ z = a;  // \u7D20\u56E0\u6570\u3092 1 \u3064\u305A\u3064\u51E6\u7406\u3057\u3001\
    \u6700\u5F8C\u306B z^g = a \u3068\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \    for (auto [q, e] : factorize(g)) {\n        long long s = 0, t = m, qe =\
    \ 1;\n        while (t % q == 0) t /= q, s++;\n        for (long long i = 0; i\
    \ < e; i++) qe *= q;\n        // x1 = z^r (r q^e \u2261 1 mod t) \u3068\u3059\u308B\
    \u3068 x1^(q^e) = z h (h \u306F\u4F4D\u6570 q^s \u306E\u90E8\u5206\u7FA4 H \u306E\
    \u5143)\n        const long long r = t == 1 ? 0 : modinv(qe % t, t);\n       \
    \ const long long x1 = modpow(z, r, p);\n        const long long target = modmul(z,\
    \ modinv(modpow(x1, qe, p), p), p);  // h^(-1)\u3001H \u306E\u5143\u3067 q^e \u4E57\
    \u306B\u306A\u3063\u3066\u3044\u308B\n        // H \u306E\u751F\u6210\u5143 c\
    \ = w^t (w \u306F q \u4E57\u975E\u5270\u4F59)\n        long long w = 2;\n    \
    \    while (modpow(w, m / q, p) == 1) w++;\n        const long long c = modpow(w,\
    \ t, p);\n        // target = c^d \u3068\u306A\u308B d \u3092 q \u9032\u3067 1\
    \ \u6841\u305A\u3064\u6C42\u3081\u308B (Pohlig-Hellman)\n        long long zeta\
    \ = c;  // \u4F4D\u6570 q \u306E\u5143 c^(q^(s-1))\n        for (long long i =\
    \ 0; i + 1 < s; i++) zeta = modpow(zeta, q, p);\n        const long long B = std::sqrt(static_cast<double>(q))\
    \ + 1;\n        std::unordered_map<long long, long long> baby;  // zeta^j -> j\
    \ (j < B)\n        for (long long j = 0, x = 1; j < B; j++, x = modmul(x, zeta,\
    \ p)) baby.emplace(x, j);\n        const long long giant = modinv(modpow(zeta,\
    \ B, p), p);\n        auto log_zeta = [&](long long y) {\n            for (long\
    \ long i = 0; i <= q / B + 1; i++, y = modmul(y, giant, p)) {\n              \
    \  auto it = baby.find(y);\n                if (it != baby.end()) return i * B\
    \ + it->second;\n            }\n            assert(false);\n            return\
    \ -1LL;\n        };\n        long long d = 0, qi = 1;\n        const long long\
    \ cinv = modinv(c, p);\n        for (long long i = 0; i < s; i++, qi *= q) {\n\
    \            // (target c^(-d))^(q^(s-1-i)) = zeta^(d \u306E i \u6841\u76EE)\n\
    \            long long y = modmul(target, modpow(cinv, d, p), p);\n          \
    \  for (long long j = 0; j + 1 + i < s; j++) y = modpow(y, q, p);\n          \
    \  d += log_zeta(y) * qi;\n        }\n        // d \u306F q^e \u306E\u500D\u6570\
    \u306B\u306A\u3063\u3066\u3044\u308B\n        z = modmul(x1, modpow(c, d / qe,\
    \ p), p);\n    }\n    const long long mg = m / g;\n    const long long inv = mg\
    \ == 1 ? 0 : modinv((k / g) % mg, mg);\n    return modpow(z, inv, p);\n}\n\n/**\n\
    \ * @brief \u30C6\u30C8\u30EC\u30FC\u30B7\u30E7\u30F3 a\u2191\u2191b (a \u3092\
    \ b \u500B\u91CD\u306D\u305F\u3079\u304D\u4E57 a^a^...^a\u3001a\u2191\u21910 =\
    \ 1) \u3092 m \u3067\u5272\u3063\u305F\u4F59\u308A\u30020^0 = 1 \u3068\u3059\u308B\
    \n *\n * x >= log2(m) \u306A\u3089 a^x \u2261 a^(x mod \u03C6(m) + \u03C6(m))\
    \ (mod m) \u3092\u4F7F\u3044\u3001m \u3092 \u03C6(m) \u306B\u7F6E\u304D\u63DB\u3048\
    \u3066\u518D\u5E30\u3059\u308B\u3002m \u306F O(log m) \u56DE\u3067 1 \u306B\u306A\
    \u308B\n * \u9014\u4E2D\u306E\u5024\u306F\u300C\u672C\u5F53\u306E\u5024\u304C\
    \ m \u672A\u6E80\u306A\u3089\u305D\u306E\u307E\u307E\u3001m \u4EE5\u4E0A\u306A\
    \u3089 (\u5024 mod m) + m\u300D\u3067\u6301\u3061\u3001\u672C\u5F53\u306E\u5024\
    \u304C m \u4EE5\u4E0A\u304B\u3092\u5931\u308F\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\n * O(log m \xD7 (factorize(m) + log m))\n * @pre m <= 2 \xD7 10^9\n */\n\
    inline long long tetration_mod(long long a, long long b, long long m) {\n    //\
    \ \u9014\u4E2D\u306E\u5024\u306F 2m \u672A\u6E80\u306A\u306E\u3067\u3001\u305D\
    \u306E\u7A4D\u304C\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B m \u3092\u5236\
    \u9650\u3059\u308B\n    assert(a >= 0 && b >= 0 && 1 <= m && m <= 2000000000);\n\
    \    // x \u3092\u4E0A\u306E\u5F62\u306B\u76F4\u3059\n    auto clamp = [](long\
    \ long x, long long mod) { return x < mod ? x : x % mod + mod; };\n    // a\u2191\
    \u2191b \u3092\u4E0A\u306E\u5F62\u3067\u8FD4\u3059\n    auto rec = [&](auto self,\
    \ long long b, long long mod) -> long long {\n        if (b == 0) return clamp(1,\
    \ mod);\n        // 0\u2191\u2191b \u306F b \u304C\u5076\u6570\u306A\u3089 1\u3001\
    \u5947\u6570\u306A\u3089 0\n        if (a == 0) return clamp(b % 2 == 0 ? 1 :\
    \ 0, mod);\n        // a >= 1 \u306A\u3089 a\u2191\u2191b >= 1\n        if (a\
    \ == 1 || mod == 1) return clamp(1, mod);\n        const long long e = self(self,\
    \ b - 1, totient(mod));\n        // a^e \u3092\u4E0A\u306E\u5F62\u3067\u6C42\u3081\
    \u308B (a >= 1\u3001e >= 1)\n        long long res = 1, base = clamp(a, mod);\n\
    \        for (long long k = e; k > 0; k >>= 1) {\n            if (k & 1) res =\
    \ clamp(res * base, mod);\n            if (k > 1) base = clamp(base * base, mod);\n\
    \        }\n        return res;\n    };\n    return rec(rec, b, m) % m;\n}\n\n\
    /**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\
    \u3066\u8FD4\u3059\n * \u5947\u6570\u3060\u3051\u3092\u533A\u9593\u3054\u3068\u306B\
    \u7BE9\u3046\u3002O(n log log n)\u3001\u30E1\u30E2\u30EA\u306F O(\u221An + \u7D20\
    \u6570\u306E\u500B\u6570)\n */\ninline std::vector<long long> enumerate_primes(long\
    \ long n) {\n    std::vector<long long> res;\n    if (n < 2) return res;\n   \
    \ res.push_back(2);\n    long long r = 1;\n    while ((r + 1) * (r + 1) <= n)\
    \ r++;\n    // \u221An \u4EE5\u4E0B\u306E\u5947\u7D20\u6570 p \u3068\u3001\u6B21\
    \u306B\u7BE9\u3046 p \u306E\u500D\u6570 (\u5947\u6570)\n    std::vector<char>\
    \ small(r + 1, 1);\n    std::vector<std::pair<long long, long long>> sp;\n   \
    \ for (long long i = 3; i <= r; i += 2) {\n        if (!small[i]) continue;\n\
    \        for (long long j = i * i; j <= r; j += 2 * i) small[j] = 0;\n       \
    \ sp.emplace_back(i, i * i);\n    }\n    // \u5947\u6570 2k+1 (1 <= k <= kmax)\
    \ \u3092\u3001k \u306E\u9577\u3055 B \u306E\u533A\u9593\u3054\u3068\u306B\u7BE9\
    \u3046\n    constexpr int B = 1 << 16;\n    std::vector<char> block(B);\n    const\
    \ long long kmax = (n - 1) / 2;\n    for (long long lo = 1; lo <= kmax; lo +=\
    \ B) {\n        const long long hi = std::min(lo + B, kmax + 1);\n        std::fill(block.begin(),\
    \ block.begin() + (hi - lo), 1);\n        for (auto& [p, m] : sp) {\n        \
    \    long long k = (m - 1) / 2;\n            for (; k < hi; k += p) block[k -\
    \ lo] = 0;\n            m = 2 * k + 1;\n        }\n        for (long long k =\
    \ lo; k < hi; k++) {\n            if (block[k - lo]) res.push_back(2 * k + 1);\n\
    \        }\n    }\n    return res;\n}\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u6574\
    \u6570\u306E\u6700\u5C0F\u7D20\u56E0\u6570\u3092\u524D\u8A08\u7B97\u3059\u308B\
    \u7BE9 (\u7DDA\u5F62\u7BE9)\n *\n * \u524D\u8A08\u7B97 O(n)\u3001\u7D20\u6570\u5224\
    \u5B9A O(1)\u3001\u7D20\u56E0\u6570\u5206\u89E3 O(log x)\n * \u4F8B:\n * Sieve\
    \ sv(1000000);\n * sv.is_prime(x); sv.factorize(x);\n */\nclass Sieve {\n    long\
    \ long n;\n    std::vector<int> lpf;  // \u6700\u5C0F\u7D20\u56E0\u6570 (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<long long> ps;\n\n   public:\n    explicit Sieve(long long n) :\
    \ n(n), lpf(n + 1, 0) {\n        assert(n >= 0);\n        for (int i = 2; i <=\
    \ n; i++) {\n            if (lpf[i] == 0) {\n                lpf[i] = i;\n   \
    \             ps.push_back(i);\n            }\n            for (long long p :\
    \ ps) {\n                if (p > lpf[i] || p * i > n) break;\n               \
    \ lpf[p * i] = p;\n            }\n        }\n    }\n\n    /**\n     * @brief \u524D\
    \u8A08\u7B97\u3057\u305F\u7BC4\u56F2\u306E\u4E0A\u9650 n\n     */\n    long long\
    \ limit() const { return n; }\n    /**\n     * @brief x (0 <= x <= n) \u304C\u7D20\
    \u6570\u304B O(1)\n     */\n    bool is_prime(long long x) const {\n        assert(0\
    \ <= x && x <= n);\n        return x >= 2 && lpf[x] == x;\n    }\n    /**\n  \
    \   * @brief x (2 <= x <= n) \u306E\u6700\u5C0F\u7D20\u56E0\u6570 O(1)\n     */\n\
    \    long long min_factor(long long x) const {\n        assert(2 <= x && x <=\
    \ n);\n        return lpf[x];\n    }\n    /**\n     * @brief n \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\n     */\n\
    \    const std::vector<long long>& primes() const { return ps; }\n    /**\n  \
    \   * @brief x (1 <= x <= n) \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\
    (\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\u6570\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059 O(log x)\n     */\n    std::vector<std::pair<long\
    \ long, long long>> factorize(long long x) const {\n        assert(1 <= x && x\
    \ <= n);\n        std::vector<std::pair<long long, long long>> res;\n        while\
    \ (x > 1) {\n            long long p = lpf[x], e = 0;\n            while (x %\
    \ p == 0) x /= p, e++;\n            res.emplace_back(p, e);\n        }\n     \
    \   return res;\n    }\n    /**\n     * @brief x (1 <= x <= n) \u306E\u6B63\u306E\
    \u7D04\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n     */\n\
    \    std::vector<long long> divisors(long long x) const {\n        std::vector<long\
    \ long> res = {1};\n        for (auto [p, e] : factorize(x)) {\n            const\
    \ long long sz = res.size();\n            long long pw = 1;\n            for (long\
    \ long i = 0; i < e; i++) {\n                pw *= p;\n                for (long\
    \ long j = 0; j < sz; j++) res.push_back(res[j] * pw);\n            }\n      \
    \  }\n        std::sort(res.begin(), res.end());\n        return res;\n    }\n\
    };\n#line 15 \"src/math/gaussian-integer.hpp\"\n\n/**\n * @brief \u30AC\u30A6\u30B9\
    \u6574\u6570 a + bi\n * @tparam T \u6210\u5206\u306E\u578B\u3002\u7A4D\u3084\u30CE\
    \u30EB\u30E0\u3067\u6210\u5206\u306E 2 \u4E57\u7A0B\u5EA6\u306E\u5024\u3092\u6271\
    \u3046\u306E\u3067\u3001\u305D\u308C\u304C\u3042\u3075\u308C\u306A\u3044\u578B\
    \u306B\u3059\u308B\n */\ntemplate <typename T = long long>\nstruct GaussianInteger\
    \ {\n    T a = 0, b = 0;  //!< \u5B9F\u90E8\u3068\u865A\u90E8\n\n    constexpr\
    \ GaussianInteger() = default;\n    constexpr GaussianInteger(T a, T b = 0) :\
    \ a(a), b(b) {}\n\n    /// @brief \u30CE\u30EB\u30E0 a^2 + b^2\n    constexpr\
    \ T norm() const { return a * a + b * b; }\n    /// @brief \u5171\u5F79 a - bi\n\
    \    constexpr GaussianInteger conj() const { return {a, -b}; }\n\n    friend\
    \ constexpr GaussianInteger operator+(const GaussianInteger& x, const GaussianInteger&\
    \ y) { return {x.a + y.a, x.b + y.b}; }\n    friend constexpr GaussianInteger\
    \ operator-(const GaussianInteger& x, const GaussianInteger& y) { return {x.a\
    \ - y.a, x.b - y.b}; }\n    friend constexpr GaussianInteger operator*(const GaussianInteger&\
    \ x, const GaussianInteger& y) {\n        return {x.a * y.a - x.b * y.b, x.a *\
    \ y.b + x.b * y.a};\n    }\n    /// @brief x / y \u306E\u5B9F\u90E8\u3068\u865A\
    \u90E8\u3092\u305D\u308C\u305E\u308C\u6700\u3082\u8FD1\u3044\u6574\u6570\u306B\
    \u4E38\u3081\u305F\u5546 (\u4F59\u308A x - qy \u306E\u30CE\u30EB\u30E0\u306F y\
    \ \u306E\u30CE\u30EB\u30E0\u306E\u534A\u5206\u4EE5\u4E0B)\n    friend constexpr\
    \ GaussianInteger operator/(const GaussianInteger& x, const GaussianInteger& y)\
    \ {\n        assert(y.norm() != 0);\n        const GaussianInteger num = x * y.conj();\n\
    \        const T d = y.norm();\n        // \u6700\u3082\u8FD1\u3044\u6574\u6570\
    \ floor((2n + d) / (2d))\n        auto round_div = [&](T n) {\n            T u\
    \ = 2 * n + d, v = 2 * d;\n            return u >= 0 ? u / v : -((-u + v - 1)\
    \ / v);\n        };\n        return {round_div(num.a), round_div(num.b)};\n  \
    \  }\n    friend constexpr GaussianInteger operator%(const GaussianInteger& x,\
    \ const GaussianInteger& y) { return x - x / y * y; }\n    friend constexpr bool\
    \ operator==(const GaussianInteger& x, const GaussianInteger& y) { return x.a\
    \ == y.a && x.b == y.b; }\n    friend constexpr bool operator!=(const GaussianInteger&\
    \ x, const GaussianInteger& y) { return !(x == y); }\n};\n\n/**\n * @brief \u30AC\
    \u30A6\u30B9\u6574\u6570\u306E\u6700\u5927\u516C\u7D04\u6570\u306E 1 \u3064 (\u5358\
    \u6570 \xB11, \xB1i \u500D\u306E\u9055\u3044\u3092\u9664\u3044\u3066\u6C7A\u307E\
    \u308B) O(log \u30CE\u30EB\u30E0)\n */\ntemplate <typename T>\nconstexpr GaussianInteger<T>\
    \ gaussian_gcd(GaussianInteger<T> x, GaussianInteger<T> y) {\n    while (y !=\
    \ GaussianInteger<T>(0)) {\n        x = x % y;\n        std::swap(x, y);\n   \
    \ }\n    return x;\n}\n\n/**\n * @brief n = a^2 + b^2 \u3068\u306A\u308B 0 \u4EE5\
    \u4E0A\u306E\u6574\u6570\u306E\u7D44 (a, b) \u3092\u3001a \u306E\u6607\u9806\u306B\
    \u3059\u3079\u3066\u8FD4\u3059\u3002\u8868\u305B\u306A\u3051\u308C\u3070\u7A7A\
    \n * n \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u30014 \u3067\u5272\u3063\u3066\
    \ 1 \u4F59\u308B\u7D20\u6570 p \u3092 p = \u03C0 \u03C0' (\u03C0' \u306F \u03C0\
    \ \u306E\u5171\u5F79) \u3068\u5206\u3051\u3066\u3001\u305D\u308C\u305E\u308C\u306E\
    \u9078\u3073\u65B9\u3092\u3059\u3079\u3066\u8A66\u3059\n * \u7D44\u306E\u500B\u6570\
    \u3092 K \u3068\u3057\u3066\u3001O(factorize(n) + p \u306E\u500B\u6570 \xD7 log^2\
    \ n + K)\n * @pre 0 <= n <= 10^18 \u7A0B\u5EA6 (__int128 \u3067\u3042\u3075\u308C\
    \u306A\u3044\u7BC4\u56F2)\n */\ninline std::vector<std::pair<long long, long long>>\
    \ two_square_sum(long long n) {\n    assert(n >= 0);\n    if (n == 0) return {{0,\
    \ 0}};\n    using G = GaussianInteger<__int128>;\n    std::vector<G> cand = {G(1)};\n\
    \    for (auto [p, e] : factorize(n)) {\n        if (p % 4 == 3) {\n         \
    \   // p \u306F\u30AC\u30A6\u30B9\u6574\u6570\u3067\u3082\u7D20\u6570\u306A\u306E\
    \u3067\u3001\u5076\u6570\u4E57\u3067\u306A\u3051\u308C\u3070\u8868\u305B\u306A\
    \u3044\n            if (e % 2 == 1) return {};\n            G q(1);\n        \
    \    for (long long i = 0; i < e / 2; i++) q = q * G(p);\n            for (auto&\
    \ z : cand) z = z * q;\n            continue;\n        }\n        // p = \u03C0\
    \ \u03C0'\n        G pi;\n        if (p == 2) {\n            pi = G(1, 1);\n \
    \       } else {\n            const long long t = sqrt_mod(p - 1, p);  // t^2\
    \ \u2261 -1 (mod p)\n            pi = gaussian_gcd(G(p), G(t, 1));\n        }\n\
    \        // \u03C0^j \u03C0'^(e-j) (j = 0, ..., e)\u3002p = 2 \u306A\u3089 \u03C0\
    \ \u3068 \u03C0' \u306F\u5358\u6570\u500D\u306E\u9055\u3044\u306A\u306E\u3067\
    \ 1 \u901A\u308A\n        std::vector<G> pw = {G(1)}, cpw = {G(1)};\n        for\
    \ (long long i = 0; i < e; i++) pw.push_back(pw.back() * pi), cpw.push_back(cpw.back()\
    \ * pi.conj());\n        std::vector<G> next;\n        for (const auto& z : cand)\
    \ {\n            for (long long j = 0; j <= (p == 2 ? 0 : e); j++) next.push_back(z\
    \ * (p == 2 ? pw[e] : pw[j] * cpw[e - j]));\n        }\n        cand.swap(next);\n\
    \    }\n    // \u5358\u6570\u500D\u3057\u3066\u5B9F\u90E8\u3068\u865A\u90E8\u304C\
    \ 0 \u4EE5\u4E0A\u306E\u3082\u306E\u3092\u96C6\u3081\u308B\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (auto z : cand) {\n        for (int u = 0; u\
    \ < 4; u++, z = z * G(0, 1)) {\n            if (z.a >= 0 && z.b >= 0) res.emplace_back(static_cast<long\
    \ long>(z.a), static_cast<long long>(z.b));\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    res.erase(std::unique(res.begin(), res.end()), res.end());\n\
    \    return res;\n}\n#line 6 \"test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        long long a1, b1,\
    \ a2, b2;\n        std::cin >> a1 >> b1 >> a2 >> b2;\n        auto g = gaussian_gcd(GaussianInteger<long\
    \ long>(a1, b1), GaussianInteger<long long>(a2, b2));\n        std::cout << g.a\
    \ << ' ' << g.b << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_of_gaussian_integers\"\
    \n\n#include <iostream>\n\n#include \"../../../src/math/gaussian-integer.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        long long a1, b1,\
    \ a2, b2;\n        std::cin >> a1 >> b1 >> a2 >> b2;\n        auto g = gaussian_gcd(GaussianInteger<long\
    \ long>(a1, b1), GaussianInteger<long long>(a2, b2));\n        std::cout << g.a\
    \ << ' ' << g.b << '\\n';\n    }\n}\n"
  dependsOn:
  - src/math/gaussian-integer.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/prime.hpp
  isVerificationFile: true
  path: test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp
- /verify/test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp.html
title: test/yosupo/number_theory/gcd-of-gaussian-integers.test.cpp
---
