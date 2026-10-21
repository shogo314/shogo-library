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
    \u59CB\u6839\u3092\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2\
    \ \"src/math/prime.hpp\"\n\n/**\n * @file prime.hpp\n * @brief \u7D20\u6570 (\u7D20\
    \u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\u3001\u7D04\u6570\u5217\
    \u6319\u3001\u7BE9\u3001\u539F\u59CB\u6839)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <initializer_list>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n * @file\
    \ modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\
    \u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)\n */\n\
    \n#line 10 \"src/math/modular-arithmetic.hpp\"\n#include <cmath>\n#line 12 \"\
    src/math/modular-arithmetic.hpp\"\n#include <unordered_map>\n\n/**\n * @brief\
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
    \    }\n    return std::min(r, p - r);\n}\n#line 16 \"src/math/prime.hpp\"\n\n\
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
    \ n \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\
    \u3059\n * \u5947\u6570\u3060\u3051\u3092\u533A\u9593\u3054\u3068\u306B\u7BE9\u3046\
    \u3002O(n log log n)\u3001\u30E1\u30E2\u30EA\u306F O(\u221An + \u7D20\u6570\u306E\
    \u500B\u6570)\n */\ninline std::vector<long long> enumerate_primes(long long n)\
    \ {\n    std::vector<long long> res;\n    if (n < 2) return res;\n    res.push_back(2);\n\
    \    long long r = 1;\n    while ((r + 1) * (r + 1) <= n) r++;\n    // \u221A\
    n \u4EE5\u4E0B\u306E\u5947\u7D20\u6570 p \u3068\u3001\u6B21\u306B\u7BE9\u3046\
    \ p \u306E\u500D\u6570 (\u5947\u6570)\n    std::vector<char> small(r + 1, 1);\n\
    \    std::vector<std::pair<long long, long long>> sp;\n    for (long long i =\
    \ 3; i <= r; i += 2) {\n        if (!small[i]) continue;\n        for (long long\
    \ j = i * i; j <= r; j += 2 * i) small[j] = 0;\n        sp.emplace_back(i, i *\
    \ i);\n    }\n    // \u5947\u6570 2k+1 (1 <= k <= kmax) \u3092\u3001k \u306E\u9577\
    \u3055 B \u306E\u533A\u9593\u3054\u3068\u306B\u7BE9\u3046\n    constexpr int B\
    \ = 1 << 16;\n    std::vector<char> block(B);\n    const long long kmax = (n -\
    \ 1) / 2;\n    for (long long lo = 1; lo <= kmax; lo += B) {\n        const long\
    \ long hi = std::min(lo + B, kmax + 1);\n        std::fill(block.begin(), block.begin()\
    \ + (hi - lo), 1);\n        for (auto& [p, m] : sp) {\n            long long k\
    \ = (m - 1) / 2;\n            for (; k < hi; k += p) block[k - lo] = 0;\n    \
    \        m = 2 * k + 1;\n        }\n        for (long long k = lo; k < hi; k++)\
    \ {\n            if (block[k - lo]) res.push_back(2 * k + 1);\n        }\n   \
    \ }\n    return res;\n}\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u6574\u6570\u306E\
    \u6700\u5C0F\u7D20\u56E0\u6570\u3092\u524D\u8A08\u7B97\u3059\u308B\u7BE9 (\u7DDA\
    \u5F62\u7BE9)\n *\n * \u524D\u8A08\u7B97 O(n)\u3001\u7D20\u6570\u5224\u5B9A O(1)\u3001\
    \u7D20\u56E0\u6570\u5206\u89E3 O(log x)\n * \u4F8B:\n * Sieve sv(1000000);\n *\
    \ sv.is_prime(x); sv.factorize(x);\n */\nclass Sieve {\n    long long n;\n   \
    \ std::vector<int> lpf;  // \u6700\u5C0F\u7D20\u56E0\u6570 (\u30E1\u30E2\u30EA\
    \u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n    std::vector<long\
    \ long> ps;\n\n   public:\n    explicit Sieve(long long n) : n(n), lpf(n + 1,\
    \ 0) {\n        assert(n >= 0);\n        for (int i = 2; i <= n; i++) {\n    \
    \        if (lpf[i] == 0) {\n                lpf[i] = i;\n                ps.push_back(i);\n\
    \            }\n            for (long long p : ps) {\n                if (p >\
    \ lpf[i] || p * i > n) break;\n                lpf[p * i] = p;\n            }\n\
    \        }\n    }\n\n    /**\n     * @brief \u524D\u8A08\u7B97\u3057\u305F\u7BC4\
    \u56F2\u306E\u4E0A\u9650 n\n     */\n    long long limit() const { return n; }\n\
    \    /**\n     * @brief x (0 <= x <= n) \u304C\u7D20\u6570\u304B O(1)\n     */\n\
    \    bool is_prime(long long x) const {\n        assert(0 <= x && x <= n);\n \
    \       return x >= 2 && lpf[x] == x;\n    }\n    /**\n     * @brief x (2 <= x\
    \ <= n) \u306E\u6700\u5C0F\u7D20\u56E0\u6570 O(1)\n     */\n    long long min_factor(long\
    \ long x) const {\n        assert(2 <= x && x <= n);\n        return lpf[x];\n\
    \    }\n    /**\n     * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u3092\u6607\u9806\
    \u306B\u4E26\u3079\u305F\u3082\u306E\n     */\n    const std::vector<long long>&\
    \ primes() const { return ps; }\n    /**\n     * @brief x (1 <= x <= n) \u3092\
    \u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001(\u7D20\u56E0\u6570, \u6307\u6570) \u3092\
    \u7D20\u56E0\u6570\u306E\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059 O(log\
    \ x)\n     */\n    std::vector<std::pair<long long, long long>> factorize(long\
    \ long x) const {\n        assert(1 <= x && x <= n);\n        std::vector<std::pair<long\
    \ long, long long>> res;\n        while (x > 1) {\n            long long p = lpf[x],\
    \ e = 0;\n            while (x % p == 0) x /= p, e++;\n            res.emplace_back(p,\
    \ e);\n        }\n        return res;\n    }\n    /**\n     * @brief x (1 <= x\
    \ <= n) \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\
    \u8FD4\u3059\n     */\n    std::vector<long long> divisors(long long x) const\
    \ {\n        std::vector<long long> res = {1};\n        for (auto [p, e] : factorize(x))\
    \ {\n            const long long sz = res.size();\n            long long pw =\
    \ 1;\n            for (long long i = 0; i < e; i++) {\n                pw *= p;\n\
    \                for (long long j = 0; j < sz; j++) res.push_back(res[j] * pw);\n\
    \            }\n        }\n        std::sort(res.begin(), res.end());\n      \
    \  return res;\n    }\n};\n#line 8 \"test/unittest/math/prime.test.cpp\"\n\n#include\
    \ <iostream>\n#line 11 \"test/unittest/math/prime.test.cpp\"\n#include <random>\n\
    #line 14 \"test/unittest/math/prime.test.cpp\"\n\n// constexpr \u3067\u4F7F\u3048\
    \u308B\u3053\u3068\nstatic_assert(is_prime(998244353));\nstatic_assert(!is_prime(1));\n\
    static_assert(!is_prime(561));  // \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u6570\n\
    \nbool naive_is_prime(long long n) {\n    if (n < 2) return false;\n    for (long\
    \ long d = 2; d * d <= n; d++) {\n        if (n % d == 0) return false;\n    }\n\
    \    return true;\n}\n\nstd::vector<long long> naive_divisors(long long n) {\n\
    \    std::vector<long long> res;\n    for (long long d = 1; d <= n; d++) {\n \
    \       if (n % d == 0) res.push_back(d);\n    }\n    return res;\n}\n\nlong long\
    \ naive_gcd(long long a, long long b) { return b == 0 ? a : naive_gcd(b, a % b);\
    \ }\n\n// factorize(n) \u306E\u7D50\u679C\u304C\u3001\u6607\u9806\u306E\u7D20\u6570\
    \u3067\u3001\u639B\u3051\u308B\u3068 n \u306B\u306A\u308B\u304B\nbool check_factorize(long\
    \ long n) {\n    auto f = factorize(n);\n    __int128 prod = 1;\n    for (std::size_t\
    \ i = 0; i < f.size(); i++) {\n        auto [p, e] = f[i];\n        if (e <= 0\
    \ || !is_prime(p)) return false;\n        if (i > 0 && f[i - 1].first >= p) return\
    \ false;\n        for (int j = 0; j < e; j++) prod *= p;\n    }\n    return prod\
    \ == n;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n\
    \n    // \u5C0F\u3055\u3044\u6570\u306F\u3059\u3079\u3066\u611A\u76F4\u3068\u6BD4\
    \u3079\u308B\n    const int N = 3000;\n    Sieve sv(N);\n    std::vector<long\
    \ long> naive_primes;\n    for (int n = 0; n <= N; n++) {\n        bool p = naive_is_prime(n);\n\
    \        if (p) naive_primes.push_back(n);\n        ok = ok && is_prime(n) ==\
    \ p && sv.is_prime(n) == p;\n        ok = ok && enumerate_primes(n) == naive_primes;\n\
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
    \  if (primitive_root(998244353) != 3) ok = false;\n\n    if (ok)\n        std::cout\
    \ << \"Hello World\" << std::endl;\n    else\n        std::cerr << \"failed\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// prime.hpp \u306E\u95A2\u6570\u3068 Sieve \u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// primitive_root\
    \ \u306F\u3001\u4F4D\u6570\u3092\u611A\u76F4\u306B\u6570\u3048\u3066\u6700\u5C0F\
    \u306E\u539F\u59CB\u6839\u3092\u6C42\u3081\u305F\u3082\u306E\u3068\u6BD4\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/math/prime.hpp\"\n\n#include <iostream>\n#include\
    \ <numeric>\n#include <random>\n#include <utility>\n#include <vector>\n\n// constexpr\
    \ \u3067\u4F7F\u3048\u308B\u3053\u3068\nstatic_assert(is_prime(998244353));\n\
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
    \  if (primitive_root(998244353) != 3) ok = false;\n\n    if (ok)\n        std::cout\
    \ << \"Hello World\" << std::endl;\n    else\n        std::cerr << \"failed\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/math/prime.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/unittest/math/prime.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/prime.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/prime.test.cpp
- /verify/test/unittest/math/prime.test.cpp.html
title: test/unittest/math/prime.test.cpp
---
