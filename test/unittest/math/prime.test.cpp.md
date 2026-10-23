---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/math/prime.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// prime.hpp\
    \ \u306E\u95A2\u6570\u3068 Sieve \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// primitive_root \u306F\u3001\
    \u4F4D\u6570\u3092\u611A\u76F4\u306B\u6570\u3048\u3066\u6700\u5C0F\u306E\u539F\
    \u59CB\u6839\u3092\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n// kth_root_mod\
    \ \u306F\u3001\u5C0F\u3055\u3044\u7D20\u6570\u3067\u89E3\u306E\u6709\u7121\u3092\
    \u5168\u63A2\u7D22\u3068\u6BD4\u3079\u3001\u8FD4\u3057\u305F\u5024\u304C\u89E3\
    \u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3092\u78BA\u304B\u3081\u308B\n// tetration_mod\
    \ \u306F\u3001\u6307\u6570\u304C long long \u306B\u53CE\u307E\u308B\u7BC4\u56F2\
    \u3067 modpow \u3092\u4F7F\u3063\u305F\u5024\u3068\u6BD4\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2\
    \ \"src/math/prime.hpp\"\n\n/**\n * @file prime.hpp\n * @brief \u7D20\u6570 (\u7D20\
    \u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\
    \u6319\u3001\u7BE9\u3001\u539F\u59CB\u6839)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <initializer_list>\n#include <numeric>\n\
    #include <unordered_map>\n#include <utility>\n#include <vector>\n\n#line 2 \"\
    src/math/modular-arithmetic.hpp\"\n\n/**\n * @file modular-arithmetic.hpp\n *\
    \ @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
    \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)\n */\n\n#line 13 \"src/math/modular-arithmetic.hpp\"\
    \n\n/**\n * @brief a * b mod m \u3092\u8FD4\u3059 (\u9014\u4E2D\u3067 __int128\
    \ \u3092\u4F7F\u3046\u306E\u3067 m < 2^63 \u306A\u3089\u3042\u3075\u308C\u306A\
    \u3044)\n */\nconstexpr long long modmul(long long a, long long b, long long m)\
    \ {\n    long long res = static_cast<long long>(static_cast<__int128>(a) * b %\
    \ m);\n    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief a^(-1)\
    \ mod m \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\
    \u3067\u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long\
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
    }\n\n/**\n * @brief a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ x >= 0 (\u306A\u3051\u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\
    \u306B\u7D20\u3067\u306A\u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step\
    \ \u3067 O(\u221Am) \u306E\u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long\
    \ long discrete_log(long long a, long long b, long long m) {\n    assert(m >=\
    \ 1);\n    a %= m, b %= m;\n    if (a < 0) a += m;\n    if (b < 0) b += m;\n \
    \   if (m == 1) return 0;\n    // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\
    \u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add\
    \ / (\u5272\u3063\u305F gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0,\
    \ g;\n    while ((g = std::gcd(a, m)) > 1) {\n        if (b == k) return add;\n\
    \        if (b % g != 0) return -1;\n        b /= g, m /= g, add++;\n        k\
    \ = modmul(k, a / g, m);\n    }\n    // k a^x \u2261 b \u3092 x = n p - q (1 <=\
    \ p <= n\u30010 <= q <= n) \u3068\u66F8\u3044\u3066\u89E3\u304F\n    const long\
    \ long n = static_cast<long long>(std::sqrt(static_cast<long double>(m))) + 1;\n\
    \    std::unordered_map<long long, long long> baby;\n    baby.reserve(2 * n +\
    \ 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\u3001\
    \u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\u3059\
    \u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long long\
    \ q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n    const\
    \ long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k; p <= n;\
    \ p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
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
    \    }\n    return std::min(r, p - r);\n}\n#line 18 \"src/math/prime.hpp\"\n\n\
    namespace internal_prime {\n\nusing u64 = unsigned long long;\n\n/**\n * @brief\
    \ Pollard \u306E \u03C1 \u6CD5 (Brent \u306E\u6539\u826F) \u3067\u5408\u6210\u6570\
    \ n \u306E 1 \u3067\u3082 n \u3067\u3082\u306A\u3044\u7D04\u6570\u3092 1 \u3064\
    \u898B\u3064\u3051\u308B\n */\ninline u64 find_factor(u64 n) {\n    if (n % 2\
    \ == 0) return 2;\n    constexpr u64 m = 128;\n    for (u64 c = 1;; c++) {\n \
    \       auto f = [&](u64 x) { return (modmul(x, x, n) + c) % n; };\n        auto\
    \ diff = [](u64 x, u64 y) { return x > y ? x - y : y - x; };\n        u64 x =\
    \ 0, y = 2, ys = 2, q = 1, g = 1;\n        for (u64 r = 1; g == 1; r <<= 1) {\n\
    \            x = y;\n            for (u64 i = 0; i < r; i++) y = f(y);\n     \
    \       for (u64 k = 0; k < r && g == 1; k += m) {\n                ys = y;\n\
    \                for (u64 i = 0; i < m && i < r - k; i++) {\n                \
    \    y = f(y);\n                    q = modmul(q, diff(x, y), n);\n          \
    \      }\n                g = std::gcd(q, n);\n            }\n        }\n    \
    \    if (g == n) {\n            // \u307E\u3068\u3081\u3066\u639B\u3051\u305F\u305B\
    \u3044\u3067 n \u306B\u306A\u3063\u305F\u306E\u3067\u30011 \u3064\u305A\u3064\u623B\
    \u3063\u3066\u78BA\u304B\u3081\u308B\n            do {\n                ys = f(ys);\n\
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
    };\n#line 10 \"test/unittest/math/prime.test.cpp\"\n\n#include <iostream>\n#line\
    \ 13 \"test/unittest/math/prime.test.cpp\"\n#include <random>\n#line 16 \"test/unittest/math/prime.test.cpp\"\
    \n\n// constexpr \u3067\u4F7F\u3048\u308B\u3053\u3068\nstatic_assert(is_prime(998244353));\n\
    static_assert(!is_prime(1));\nstatic_assert(!is_prime(561));  // \u30AB\u30FC\u30DE\
    \u30A4\u30B1\u30EB\u6570\n\nbool naive_is_prime(long long n) {\n    if (n < 2)\
    \ return false;\n    for (long long d = 2; d * d <= n; d++) {\n        if (n %\
    \ d == 0) return false;\n    }\n    return true;\n}\n\nstd::vector<long long>\
    \ naive_divisors(long long n) {\n    std::vector<long long> res;\n    for (long\
    \ long d = 1; d <= n; d++) {\n        if (n % d == 0) res.push_back(d);\n    }\n\
    \    return res;\n}\n\nlong long naive_gcd(long long a, long long b) { return\
    \ b == 0 ? a : naive_gcd(b, a % b); }\n\n// factorize(n) \u306E\u7D50\u679C\u304C\
    \u3001\u6607\u9806\u306E\u7D20\u6570\u3067\u3001\u639B\u3051\u308B\u3068 n \u306B\
    \u306A\u308B\u304B\nbool check_factorize(long long n) {\n    auto f = factorize(n);\n\
    \    __int128 prod = 1;\n    for (std::size_t i = 0; i < f.size(); i++) {\n  \
    \      auto [p, e] = f[i];\n        if (e <= 0 || !is_prime(p)) return false;\n\
    \        if (i > 0 && f[i - 1].first >= p) return false;\n        for (int j =\
    \ 0; j < e; j++) prod *= p;\n    }\n    return prod == n;\n}\n\nint main() {\n\
    \    std::mt19937_64 rng(314);\n    bool ok = true;\n\n    // \u5C0F\u3055\u3044\
    \u6570\u306F\u3059\u3079\u3066\u611A\u76F4\u3068\u6BD4\u3079\u308B\n    const\
    \ int N = 3000;\n    Sieve sv(N);\n    std::vector<long long> naive_primes;\n\
    \    for (int n = 0; n <= N; n++) {\n        bool p = naive_is_prime(n);\n   \
    \     if (p) naive_primes.push_back(n);\n        ok = ok && is_prime(n) == p &&\
    \ sv.is_prime(n) == p;\n        ok = ok && enumerate_primes(n) == naive_primes;\n\
    \        if (n == 0) continue;\n        auto d = naive_divisors(n);\n        ok\
    \ = ok && divisors(n) == d;\n        auto sd = sv.divisors(n);\n        ok = ok\
    \ && std::vector<long long>(sd.begin(), sd.end()) == d;\n        long long phi\
    \ = 0;\n        for (int k = 1; k <= n; k++) phi += naive_gcd(k, n) == 1;\n  \
    \      ok = ok && totient(n) == phi;\n        ok = ok && check_factorize(n);\n\
    \        auto f1 = factorize(n);\n        auto f2 = sv.factorize(n);\n       \
    \ ok = ok && f1.size() == f2.size();\n        for (std::size_t i = 0; ok && i\
    \ < f1.size(); i++) ok = ok && f1[i].first == f2[i].first && f1[i].second == f2[i].second;\n\
    \        if (n >= 2) ok = ok && sv.min_factor(n) == f1[0].first;\n    }\n    ok\
    \ = ok && sv.primes() == naive_primes && sv.limit() == N;\n\n    // \u5927\u304D\
    \u3044\u7D20\u6570\u3068\u3001Miller-Rabin \u3092\u9593\u9055\u3048\u3084\u3059\
    \u3044\u5408\u6210\u6570\n    for (long long p : {1000000007LL, 998244353LL, 2305843009213693951LL,\
    \ 999999999999999989LL, 4611686018427387847LL}) {\n        ok = ok && is_prime(p)\
    \ && check_factorize(p) && factorize(p).size() == 1;\n    }\n    // 3215031751\
    \ \u3068 3825123056546413051 \u306F\u3001\u5C0F\u3055\u3044\u5E95\u3067\u306E\u5F37\
    \u64EC\u7D20\u6570\n    for (long long c : std::vector<long long>{3215031751LL,\
    \ 3825123056546413051LL, 1000000007LL * 998244353LL,\n                       \
    \                       999999937LL * 999999937LL, 4LL, 1LL << 62}) {\n      \
    \  ok = ok && !is_prime(c) && check_factorize(c);\n    }\n\n    // \u5927\u304D\
    \u3044\u6570\u306E\u7D20\u56E0\u6570\u5206\u89E3\n    for (int rep = 0; rep <\
    \ 300; rep++) {\n        long long n = rng() % 1000000000000000000LL + 1;\n  \
    \      ok = ok && check_factorize(n);\n        // 2 \u3064\u306E\u5927\u304D\u3044\
    \u7D20\u6570\u306E\u7A4D\n        long long p = rng() % 1000000000 + 1, q = rng()\
    \ % 1000000000 + 1;\n        while (!is_prime(p)) p++;\n        while (!is_prime(q))\
    \ q++;\n        auto f = factorize(p * q);\n        ok = ok && check_factorize(p\
    \ * q) && (p == q ? f.size() == 1 && f[0].second == 2 : f.size() == 2);\n    \
    \    ok = ok && divisors(p * q).size() == (p == q ? 3u : 4u);\n    }\n\n    //\
    \ primitive_root: m <= 2000 \u3067\u3001g = 1, 2, ... \u306E\u4F4D\u6570\u3092\
    \u6570\u3048\u3066\u6700\u521D\u306B \u03C6(m) \u306B\u306A\u308B\u3082\u306E\
    \ (\u306A\u3051\u308C\u3070 -1)\n    for (long long m = 1; m <= 2000 && ok; m++)\
    \ {\n        long long phi = 0;\n        for (long long x = 1; x <= m; x++) phi\
    \ += std::gcd(x, m) == 1;\n        long long expect = m == 1 ? 0 : -1;\n     \
    \   for (long long g = 1; g < m && expect == -1; g++) {\n            if (std::gcd(g,\
    \ m) != 1) continue;\n            long long order = 1, cur = g % m;\n        \
    \    while (cur != 1 % m) cur = cur * g % m, order++;\n            if (order ==\
    \ phi) expect = g;\n        }\n        if (primitive_root(m) != expect) ok = false,\
    \ std::cerr << \"primitive_root \" << m << std::endl;\n    }\n    // \u5927\u304D\
    \u3044\u7D20\u6570: \u8FD4\u3057\u305F g \u304C\u539F\u59CB\u6839 (p - 1 \u306E\
    \u3069\u306E\u7D20\u56E0\u6570 q \u3067\u3082 g^((p-1)/q) != 1) \u3067\u3001\u305D\
    \u308C\u3088\u308A\u5C0F\u3055\u3044\u6570\u306F\u539F\u59CB\u6839\u3067\u306A\
    \u3044\n    for (long long p : {998244353LL, 1000000007LL, 167772161LL, (1LL <<\
    \ 61) - 1, 999999999999999989LL}) {\n        long long g = primitive_root(p);\n\
    \        auto is_root = [&](long long h) {\n            for (auto [q, e] : factorize(p\
    \ - 1))\n                if (modpow(h, (p - 1) / q, p) == 1) return false;\n \
    \           return true;\n        };\n        ok = ok && g >= 2 && is_root(g);\n\
    \        for (long long h = 2; h < g; h++) ok = ok && !is_root(h);\n    }\n  \
    \  if (primitive_root(998244353) != 3) ok = false;\n\n    // kth_root_mod: \u5C0F\
    \u3055\u3044\u7D20\u6570\u3067\u3001x \u3092\u3059\u3079\u3066\u8A66\u3057\u3066\
    \u89E3\u304C\u3042\u308B\u304B\u3092\u8ABF\u3079\u3001\u8FD4\u3057\u305F x \u304C\
    \u89E3\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3092\u78BA\u304B\u3081\u308B\
    \n    // p - 1 \u304C 2\u30FB3 \u306E\u3079\u304D\u3092\u591A\u304F\u542B\u3080\
    \u7D20\u6570 (73 = 2^3 3^2 + 1\u300197 = 2^5 3 + 1 \u306A\u3069) \u3068\u3001\
    k \u304C p - 1 \u3088\u308A\u5927\u304D\u3044\u5834\u5408\u3082\u542B\u3081\u308B\
    \n    for (long long p : {2, 3, 5, 7, 13, 17, 19, 37, 73, 97, 101, 163, 193, 257})\
    \ {\n        for (long long k = 0; k <= 2 * p + 2 && ok; k++) {\n            for\
    \ (long long a = 0; a < p; a++) {\n                bool exists = false;\n    \
    \            for (long long x = 0; x < p && !exists; x++) {\n                \
    \    long long y = 1 % p;\n                    for (long long i = 0; i < k; i++)\
    \ y = y * x % p;\n                    if (y == a) exists = true;\n           \
    \     }\n                long long x = kth_root_mod(k, a, p);\n              \
    \  if (!exists) {\n                    if (x != -1) ok = false;\n            \
    \        continue;\n                }\n                long long y = 1 % p;\n\
    \                for (long long i = 0; i < k; i++) y = y * x % p;\n          \
    \      if (x < 0 || x >= p || y != a) ok = false;\n            }\n        }\n\
    \    }\n    // \u5927\u304D\u3044\u7D20\u6570\u3067\u3082\u3001\u8FD4\u3057\u305F\
    \ x \u304C\u89E3\u306B\u306A\u3063\u3066\u3044\u308B\u304B\n    for (int rep =\
    \ 0; rep < 300 && ok; rep++) {\n        long long p = 998244353, k = rng() % 1000000000,\
    \ x0 = rng() % p;\n        long long a = modpow(x0, k, p), x = kth_root_mod(k,\
    \ a, p);\n        if (x == -1 || modpow(x, k, p) != a) ok = false;\n    }\n\n\
    \    // tetration_mod: a\u2191\u2191(b - 1) \u304C long long \u306B\u53CE\u307E\
    \u308B\u3068\u304D\u3001a\u2191\u2191b = a^(a\u2191\u2191(b - 1)) \u3092 modpow\
    \ \u3067\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n    for (long\
    \ long a = 0; a <= 12 && ok; a++) {\n        for (long long b = 0; b <= 6; b++)\
    \ {\n            // t = a\u2191\u2191(b - 1)\u3002\u53CE\u307E\u3089\u306A\u3051\
    \u308C\u3070 -1\n            long long t = 1;\n            for (long long i =\
    \ 0; i + 1 < b && t != -1; i++) {\n                // t = a^t\n              \
    \  long long r = 1;\n                for (long long j = 0; j < t; j++) {\n   \
    \                 if (r > (1LL << 60) / std::max(a, 1LL)) {\n                \
    \        r = -1;\n                        break;\n                    }\n    \
    \                r *= a;\n                }\n                t = r;\n        \
    \    }\n            if (t == -1) continue;\n            for (long long m = 1;\
    \ m <= 60; m++) {\n                long long expect = b == 0 ? 1 % m : (a == 0\
    \ && t == 0 ? 1 % m : modpow(a, t, m));\n                if (tetration_mod(a,\
    \ b, m) != expect) ok = false;\n            }\n        }\n    }\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// prime.hpp \u306E\u95A2\u6570\u3068 Sieve \u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// primitive_root\
    \ \u306F\u3001\u4F4D\u6570\u3092\u611A\u76F4\u306B\u6570\u3048\u3066\u6700\u5C0F\
    \u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\
    \u308B\n// kth_root_mod \u306F\u3001\u5C0F\u3055\u3044\u7D20\u6570\u3067\u89E3\
    \u306E\u6709\u7121\u3092\u5168\u63A2\u7D22\u3068\u6BD4\u3079\u3001\u8FD4\u3057\
    \u305F\u5024\u304C\u89E3\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3092\u78BA\
    \u304B\u3081\u308B\n// tetration_mod \u306F\u3001\u6307\u6570\u304C long long\
    \ \u306B\u53CE\u307E\u308B\u7BC4\u56F2\u3067 modpow \u3092\u4F7F\u3063\u305F\u5024\
    \u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../../src/math/prime.hpp\"\n\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <utility>\n#include <vector>\n\
    \n// constexpr \u3067\u4F7F\u3048\u308B\u3053\u3068\nstatic_assert(is_prime(998244353));\n\
    static_assert(!is_prime(1));\nstatic_assert(!is_prime(561));  // \u30AB\u30FC\u30DE\
    \u30A4\u30B1\u30EB\u6570\n\nbool naive_is_prime(long long n) {\n    if (n < 2)\
    \ return false;\n    for (long long d = 2; d * d <= n; d++) {\n        if (n %\
    \ d == 0) return false;\n    }\n    return true;\n}\n\nstd::vector<long long>\
    \ naive_divisors(long long n) {\n    std::vector<long long> res;\n    for (long\
    \ long d = 1; d <= n; d++) {\n        if (n % d == 0) res.push_back(d);\n    }\n\
    \    return res;\n}\n\nlong long naive_gcd(long long a, long long b) { return\
    \ b == 0 ? a : naive_gcd(b, a % b); }\n\n// factorize(n) \u306E\u7D50\u679C\u304C\
    \u3001\u6607\u9806\u306E\u7D20\u6570\u3067\u3001\u639B\u3051\u308B\u3068 n \u306B\
    \u306A\u308B\u304B\nbool check_factorize(long long n) {\n    auto f = factorize(n);\n\
    \    __int128 prod = 1;\n    for (std::size_t i = 0; i < f.size(); i++) {\n  \
    \      auto [p, e] = f[i];\n        if (e <= 0 || !is_prime(p)) return false;\n\
    \        if (i > 0 && f[i - 1].first >= p) return false;\n        for (int j =\
    \ 0; j < e; j++) prod *= p;\n    }\n    return prod == n;\n}\n\nint main() {\n\
    \    std::mt19937_64 rng(314);\n    bool ok = true;\n\n    // \u5C0F\u3055\u3044\
    \u6570\u306F\u3059\u3079\u3066\u611A\u76F4\u3068\u6BD4\u3079\u308B\n    const\
    \ int N = 3000;\n    Sieve sv(N);\n    std::vector<long long> naive_primes;\n\
    \    for (int n = 0; n <= N; n++) {\n        bool p = naive_is_prime(n);\n   \
    \     if (p) naive_primes.push_back(n);\n        ok = ok && is_prime(n) == p &&\
    \ sv.is_prime(n) == p;\n        ok = ok && enumerate_primes(n) == naive_primes;\n\
    \        if (n == 0) continue;\n        auto d = naive_divisors(n);\n        ok\
    \ = ok && divisors(n) == d;\n        auto sd = sv.divisors(n);\n        ok = ok\
    \ && std::vector<long long>(sd.begin(), sd.end()) == d;\n        long long phi\
    \ = 0;\n        for (int k = 1; k <= n; k++) phi += naive_gcd(k, n) == 1;\n  \
    \      ok = ok && totient(n) == phi;\n        ok = ok && check_factorize(n);\n\
    \        auto f1 = factorize(n);\n        auto f2 = sv.factorize(n);\n       \
    \ ok = ok && f1.size() == f2.size();\n        for (std::size_t i = 0; ok && i\
    \ < f1.size(); i++) ok = ok && f1[i].first == f2[i].first && f1[i].second == f2[i].second;\n\
    \        if (n >= 2) ok = ok && sv.min_factor(n) == f1[0].first;\n    }\n    ok\
    \ = ok && sv.primes() == naive_primes && sv.limit() == N;\n\n    // \u5927\u304D\
    \u3044\u7D20\u6570\u3068\u3001Miller-Rabin \u3092\u9593\u9055\u3048\u3084\u3059\
    \u3044\u5408\u6210\u6570\n    for (long long p : {1000000007LL, 998244353LL, 2305843009213693951LL,\
    \ 999999999999999989LL, 4611686018427387847LL}) {\n        ok = ok && is_prime(p)\
    \ && check_factorize(p) && factorize(p).size() == 1;\n    }\n    // 3215031751\
    \ \u3068 3825123056546413051 \u306F\u3001\u5C0F\u3055\u3044\u5E95\u3067\u306E\u5F37\
    \u64EC\u7D20\u6570\n    for (long long c : std::vector<long long>{3215031751LL,\
    \ 3825123056546413051LL, 1000000007LL * 998244353LL,\n                       \
    \                       999999937LL * 999999937LL, 4LL, 1LL << 62}) {\n      \
    \  ok = ok && !is_prime(c) && check_factorize(c);\n    }\n\n    // \u5927\u304D\
    \u3044\u6570\u306E\u7D20\u56E0\u6570\u5206\u89E3\n    for (int rep = 0; rep <\
    \ 300; rep++) {\n        long long n = rng() % 1000000000000000000LL + 1;\n  \
    \      ok = ok && check_factorize(n);\n        // 2 \u3064\u306E\u5927\u304D\u3044\
    \u7D20\u6570\u306E\u7A4D\n        long long p = rng() % 1000000000 + 1, q = rng()\
    \ % 1000000000 + 1;\n        while (!is_prime(p)) p++;\n        while (!is_prime(q))\
    \ q++;\n        auto f = factorize(p * q);\n        ok = ok && check_factorize(p\
    \ * q) && (p == q ? f.size() == 1 && f[0].second == 2 : f.size() == 2);\n    \
    \    ok = ok && divisors(p * q).size() == (p == q ? 3u : 4u);\n    }\n\n    //\
    \ primitive_root: m <= 2000 \u3067\u3001g = 1, 2, ... \u306E\u4F4D\u6570\u3092\
    \u6570\u3048\u3066\u6700\u521D\u306B \u03C6(m) \u306B\u306A\u308B\u3082\u306E\
    \ (\u306A\u3051\u308C\u3070 -1)\n    for (long long m = 1; m <= 2000 && ok; m++)\
    \ {\n        long long phi = 0;\n        for (long long x = 1; x <= m; x++) phi\
    \ += std::gcd(x, m) == 1;\n        long long expect = m == 1 ? 0 : -1;\n     \
    \   for (long long g = 1; g < m && expect == -1; g++) {\n            if (std::gcd(g,\
    \ m) != 1) continue;\n            long long order = 1, cur = g % m;\n        \
    \    while (cur != 1 % m) cur = cur * g % m, order++;\n            if (order ==\
    \ phi) expect = g;\n        }\n        if (primitive_root(m) != expect) ok = false,\
    \ std::cerr << \"primitive_root \" << m << std::endl;\n    }\n    // \u5927\u304D\
    \u3044\u7D20\u6570: \u8FD4\u3057\u305F g \u304C\u539F\u59CB\u6839 (p - 1 \u306E\
    \u3069\u306E\u7D20\u56E0\u6570 q \u3067\u3082 g^((p-1)/q) != 1) \u3067\u3001\u305D\
    \u308C\u3088\u308A\u5C0F\u3055\u3044\u6570\u306F\u539F\u59CB\u6839\u3067\u306A\
    \u3044\n    for (long long p : {998244353LL, 1000000007LL, 167772161LL, (1LL <<\
    \ 61) - 1, 999999999999999989LL}) {\n        long long g = primitive_root(p);\n\
    \        auto is_root = [&](long long h) {\n            for (auto [q, e] : factorize(p\
    \ - 1))\n                if (modpow(h, (p - 1) / q, p) == 1) return false;\n \
    \           return true;\n        };\n        ok = ok && g >= 2 && is_root(g);\n\
    \        for (long long h = 2; h < g; h++) ok = ok && !is_root(h);\n    }\n  \
    \  if (primitive_root(998244353) != 3) ok = false;\n\n    // kth_root_mod: \u5C0F\
    \u3055\u3044\u7D20\u6570\u3067\u3001x \u3092\u3059\u3079\u3066\u8A66\u3057\u3066\
    \u89E3\u304C\u3042\u308B\u304B\u3092\u8ABF\u3079\u3001\u8FD4\u3057\u305F x \u304C\
    \u89E3\u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3092\u78BA\u304B\u3081\u308B\
    \n    // p - 1 \u304C 2\u30FB3 \u306E\u3079\u304D\u3092\u591A\u304F\u542B\u3080\
    \u7D20\u6570 (73 = 2^3 3^2 + 1\u300197 = 2^5 3 + 1 \u306A\u3069) \u3068\u3001\
    k \u304C p - 1 \u3088\u308A\u5927\u304D\u3044\u5834\u5408\u3082\u542B\u3081\u308B\
    \n    for (long long p : {2, 3, 5, 7, 13, 17, 19, 37, 73, 97, 101, 163, 193, 257})\
    \ {\n        for (long long k = 0; k <= 2 * p + 2 && ok; k++) {\n            for\
    \ (long long a = 0; a < p; a++) {\n                bool exists = false;\n    \
    \            for (long long x = 0; x < p && !exists; x++) {\n                \
    \    long long y = 1 % p;\n                    for (long long i = 0; i < k; i++)\
    \ y = y * x % p;\n                    if (y == a) exists = true;\n           \
    \     }\n                long long x = kth_root_mod(k, a, p);\n              \
    \  if (!exists) {\n                    if (x != -1) ok = false;\n            \
    \        continue;\n                }\n                long long y = 1 % p;\n\
    \                for (long long i = 0; i < k; i++) y = y * x % p;\n          \
    \      if (x < 0 || x >= p || y != a) ok = false;\n            }\n        }\n\
    \    }\n    // \u5927\u304D\u3044\u7D20\u6570\u3067\u3082\u3001\u8FD4\u3057\u305F\
    \ x \u304C\u89E3\u306B\u306A\u3063\u3066\u3044\u308B\u304B\n    for (int rep =\
    \ 0; rep < 300 && ok; rep++) {\n        long long p = 998244353, k = rng() % 1000000000,\
    \ x0 = rng() % p;\n        long long a = modpow(x0, k, p), x = kth_root_mod(k,\
    \ a, p);\n        if (x == -1 || modpow(x, k, p) != a) ok = false;\n    }\n\n\
    \    // tetration_mod: a\u2191\u2191(b - 1) \u304C long long \u306B\u53CE\u307E\
    \u308B\u3068\u304D\u3001a\u2191\u2191b = a^(a\u2191\u2191(b - 1)) \u3092 modpow\
    \ \u3067\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n    for (long\
    \ long a = 0; a <= 12 && ok; a++) {\n        for (long long b = 0; b <= 6; b++)\
    \ {\n            // t = a\u2191\u2191(b - 1)\u3002\u53CE\u307E\u3089\u306A\u3051\
    \u308C\u3070 -1\n            long long t = 1;\n            for (long long i =\
    \ 0; i + 1 < b && t != -1; i++) {\n                // t = a^t\n              \
    \  long long r = 1;\n                for (long long j = 0; j < t; j++) {\n   \
    \                 if (r > (1LL << 60) / std::max(a, 1LL)) {\n                \
    \        r = -1;\n                        break;\n                    }\n    \
    \                r *= a;\n                }\n                t = r;\n        \
    \    }\n            if (t == -1) continue;\n            for (long long m = 1;\
    \ m <= 60; m++) {\n                long long expect = b == 0 ? 1 % m : (a == 0\
    \ && t == 0 ? 1 % m : modpow(a, t, m));\n                if (tetration_mod(a,\
    \ b, m) != expect) ok = false;\n            }\n        }\n    }\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/math/prime.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/unittest/math/prime.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 19:32:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/prime.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/prime.test.cpp
- /verify/test/unittest/math/prime.test.cpp.html
title: test/unittest/math/prime.test.cpp
---
