---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/divisor-transform.hpp
    title: "\u7D04\u6570\u30FB\u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB\u3001\
      \u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068 GCD\u30FBLCM \u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143)"
  - icon: ':heavy_check_mark:'
    path: src/math/prime.hpp
    title: "\u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\
      \u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "#line 1 \"test/yosupo/gcd-convolution.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/math/divisor-transform.hpp\"\n\n/**\n * @file\
    \ divisor-transform.hpp\n * @brief \u7D04\u6570\u30FB\u500D\u6570\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB\u3001\u30E1\u30D3\u30A6\u30B9\u5909\u63DB\u3068 GCD\u30FBLCM\
    \ \u7573\u307F\u8FBC\u307F\n */\n\n#include <cassert>\n#line 10 \"src/math/divisor-transform.hpp\"\
    \n\n#line 2 \"src/math/prime.hpp\"\n\n/**\n * @file prime.hpp\n * @brief \u7D20\
    \u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\u89E3\u3001\u7D04\
    \u6570\u5217\u6319\u3001\u7BE9)\n */\n\n#include <algorithm>\n#line 10 \"src/math/prime.hpp\"\
    \n#include <initializer_list>\n#include <numeric>\n#include <utility>\n#line 14\
    \ \"src/math/prime.hpp\"\n\n#line 2 \"src/math/modular-arithmetic.hpp\"\n\n/**\n\
    \ * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\
    \u4E57\u3001\u9006\u5143)\n */\n\n#line 9 \"src/math/modular-arithmetic.hpp\"\n\
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
    \       a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n}\n#line\
    \ 16 \"src/math/prime.hpp\"\n\nnamespace internal_prime {\n\nusing u64 = unsigned\
    \ long long;\n\n/**\n * @brief Pollard \u306E \u03C1 \u6CD5 (Brent \u306E\u6539\
    \u826F) \u3067\u5408\u6210\u6570 n \u306E 1 \u3067\u3082 n \u3067\u3082\u306A\u3044\
    \u7D04\u6570\u3092 1 \u3064\u898B\u3064\u3051\u308B\n */\ninline u64 find_factor(u64\
    \ n) {\n    if (n % 2 == 0) return 2;\n    constexpr u64 m = 128;\n    for (u64\
    \ c = 1;; c++) {\n        auto f = [&](u64 x) { return (modmul(x, x, n) + c) %\
    \ n; };\n        auto diff = [](u64 x, u64 y) { return x > y ? x - y : y - x;\
    \ };\n        u64 x = 0, y = 2, ys = 2, q = 1, g = 1;\n        for (u64 r = 1;\
    \ g == 1; r <<= 1) {\n            x = y;\n            for (u64 i = 0; i < r; i++)\
    \ y = f(y);\n            for (u64 k = 0; k < r && g == 1; k += m) {\n        \
    \        ys = y;\n                for (u64 i = 0; i < m && i < r - k; i++) {\n\
    \                    y = f(y);\n                    q = modmul(q, diff(x, y),\
    \ n);\n                }\n                g = std::gcd(q, n);\n            }\n\
    \        }\n        if (g == n) {\n            // \u307E\u3068\u3081\u3066\u639B\
    \u3051\u305F\u305B\u3044\u3067 n \u306B\u306A\u3063\u305F\u306E\u3067\u30011 \u3064\
    \u305A\u3064\u623B\u3063\u3066\u78BA\u304B\u3081\u308B\n            do {\n   \
    \             ys = f(ys);\n                g = std::gcd(diff(x, ys), n);\n   \
    \         } while (g == 1);\n        }\n        if (g != n) return g;\n    }\n\
    }\n\n}  // namespace internal_prime\n\n/**\n * @brief n \u304C\u7D20\u6570\u304B\
    \ (Miller-Rabin\u300164 bit \u3067\u6C7A\u5B9A\u7684) O(log n)\n */\nconstexpr\
    \ bool is_prime(long long n) {\n    using namespace internal_prime;\n    if (n\
    \ < 2) return false;\n    for (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31,\
    \ 37}) {\n        if (static_cast<u64>(n) % p == 0) return static_cast<u64>(n)\
    \ == p;\n    }\n    const u64 m = n;\n    u64 d = m - 1;\n    int s = 0;\n   \
    \ while (d % 2 == 0) d /= 2, s++;\n    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL,\
    \ 450775ULL, 9780504ULL, 1795265022ULL}) {\n        a %= m;\n        if (a ==\
    \ 0) continue;\n        u64 x = modpow(a, d, m);\n        if (x == 1 || x == m\
    \ - 1) continue;\n        bool composite = true;\n        for (int i = 1; i <\
    \ s; i++) {\n            x = modmul(x, x, m);\n            if (x == m - 1) {\n\
    \                composite = false;\n                break;\n            }\n \
    \       }\n        if (composite) return false;\n    }\n    return true;\n}\n\n\
    /**\n * @brief n (>= 1) \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001(\u7D20\
    \u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\u6570\u306E\u6607\u9806\u306B\u4E26\
    \u3079\u3066\u8FD4\u3059\n * Pollard \u306E \u03C1 \u6CD5\u3092\u4F7F\u3046\u3002\
    \u671F\u5F85 O(n^(1/4)) \u7A0B\u5EA6\n */\ninline std::vector<std::pair<long long,\
    \ int>> factorize(long long n) {\n    assert(n >= 1);\n    std::vector<long long>\
    \ ps;\n    // \u5C0F\u3055\u3044\u7D20\u56E0\u6570\u306F\u5272\u308A\u7B97\u3067\
    \u53D6\u308A\u9664\u304F\n    for (long long p : {2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37}) {\n        while (n % p == 0) {\n            ps.push_back(p);\n\
    \            n /= p;\n        }\n    }\n    std::vector<long long> st;\n    if\
    \ (n > 1) st.push_back(n);\n    while (!st.empty()) {\n        long long x = st.back();\n\
    \        st.pop_back();\n        if (is_prime(x)) {\n            ps.push_back(x);\n\
    \            continue;\n        }\n        long long d = internal_prime::find_factor(x);\n\
    \        st.push_back(d);\n        st.push_back(x / d);\n    }\n    std::sort(ps.begin(),\
    \ ps.end());\n    std::vector<std::pair<long long, int>> res;\n    for (long long\
    \ p : ps) {\n        if (!res.empty() && res.back().first == p)\n            res.back().second++;\n\
    \        else\n            res.emplace_back(p, 1);\n    }\n    return res;\n}\n\
    \n/**\n * @brief n (>= 1) \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059\n */\ninline std::vector<long long> divisors(long\
    \ long n) {\n    std::vector<long long> res = {1};\n    for (auto [p, e] : factorize(n))\
    \ {\n        int sz = res.size();\n        long long pw = 1;\n        for (int\
    \ i = 0; i < e; i++) {\n            pw *= p;\n            for (int j = 0; j <\
    \ sz; j++) res.push_back(res[j] * pw);\n        }\n    }\n    std::sort(res.begin(),\
    \ res.end());\n    return res;\n}\n\n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E\
    \ \u03C6 \u95A2\u6570 (1 \u4EE5\u4E0A n \u4EE5\u4E0B\u3067 n \u3068\u4E92\u3044\
    \u306B\u7D20\u306A\u6574\u6570\u306E\u500B\u6570)\n */\ninline long long totient(long\
    \ long n) {\n    long long res = n;\n    for (auto [p, e] : factorize(n)) res\
    \ = res / p * (p - 1);\n    return res;\n}\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\
    \u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n * \u5947\u6570\
    \u3060\u3051\u3092\u533A\u9593\u3054\u3068\u306B\u7BE9\u3046\u3002O(n log log\
    \ n)\u3001\u30E1\u30E2\u30EA\u306F O(\u221An + \u7D20\u6570\u306E\u500B\u6570\
    )\n */\ninline std::vector<int> enumerate_primes(int n) {\n    std::vector<int>\
    \ res;\n    if (n < 2) return res;\n    res.push_back(2);\n    int r = 1;\n  \
    \  while (static_cast<long long>(r + 1) * (r + 1) <= n) r++;\n    // \u221An \u4EE5\
    \u4E0B\u306E\u5947\u7D20\u6570 p \u3068\u3001\u6B21\u306B\u7BE9\u3046 p \u306E\
    \u500D\u6570 (\u5947\u6570)\n    std::vector<char> small(r + 1, 1);\n    std::vector<std::pair<int,\
    \ long long>> sp;\n    for (int i = 3; i <= r; i += 2) {\n        if (!small[i])\
    \ continue;\n        for (int j = i * i; j <= r; j += 2 * i) small[j] = 0;\n \
    \       sp.emplace_back(i, static_cast<long long>(i) * i);\n    }\n    // \u5947\
    \u6570 2k+1 (1 <= k <= kmax) \u3092\u3001k \u306E\u9577\u3055 B \u306E\u533A\u9593\
    \u3054\u3068\u306B\u7BE9\u3046\n    constexpr int B = 1 << 16;\n    std::vector<char>\
    \ block(B);\n    const long long kmax = (n - 1) / 2;\n    for (long long lo =\
    \ 1; lo <= kmax; lo += B) {\n        const long long hi = std::min(lo + B, kmax\
    \ + 1);\n        std::fill(block.begin(), block.begin() + (hi - lo), 1);\n   \
    \     for (auto& [p, m] : sp) {\n            long long k = (m - 1) / 2;\n    \
    \        for (; k < hi; k += p) block[k - lo] = 0;\n            m = 2 * k + 1;\n\
    \        }\n        for (long long k = lo; k < hi; k++) {\n            if (block[k\
    \ - lo]) res.push_back(2 * k + 1);\n        }\n    }\n    return res;\n}\n\n/**\n\
    \ * @brief n \u4EE5\u4E0B\u306E\u6574\u6570\u306E\u6700\u5C0F\u7D20\u56E0\u6570\
    \u3092\u524D\u8A08\u7B97\u3059\u308B\u7BE9 (\u7DDA\u5F62\u7BE9)\n *\n * \u524D\
    \u8A08\u7B97 O(n)\u3001\u7D20\u6570\u5224\u5B9A O(1)\u3001\u7D20\u56E0\u6570\u5206\
    \u89E3 O(log x)\n * \u4F8B:\n * Sieve sv(1000000);\n * sv.is_prime(x); sv.factorize(x);\n\
    \ */\nclass Sieve {\n    int n;\n    std::vector<int> lpf;  // \u6700\u5C0F\u7D20\
    \u56E0\u6570\n    std::vector<int> ps;\n\n   public:\n    explicit Sieve(int n)\
    \ : n(n), lpf(n + 1, 0) {\n        assert(n >= 0);\n        for (int i = 2; i\
    \ <= n; i++) {\n            if (lpf[i] == 0) {\n                lpf[i] = i;\n\
    \                ps.push_back(i);\n            }\n            for (int p : ps)\
    \ {\n                if (p > lpf[i] || static_cast<long long>(p) * i > n) break;\n\
    \                lpf[p * i] = p;\n            }\n        }\n    }\n\n    /**\n\
    \     * @brief \u524D\u8A08\u7B97\u3057\u305F\u7BC4\u56F2\u306E\u4E0A\u9650 n\n\
    \     */\n    int limit() const { return n; }\n    /**\n     * @brief x (0 <=\
    \ x <= n) \u304C\u7D20\u6570\u304B O(1)\n     */\n    bool is_prime(int x) const\
    \ {\n        assert(0 <= x && x <= n);\n        return x >= 2 && lpf[x] == x;\n\
    \    }\n    /**\n     * @brief x (2 <= x <= n) \u306E\u6700\u5C0F\u7D20\u56E0\u6570\
    \ O(1)\n     */\n    int min_factor(int x) const {\n        assert(2 <= x && x\
    \ <= n);\n        return lpf[x];\n    }\n    /**\n     * @brief n \u4EE5\u4E0B\
    \u306E\u7D20\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\n   \
    \  */\n    const std::vector<int>& primes() const { return ps; }\n    /**\n  \
    \   * @brief x (1 <= x <= n) \u3092\u7D20\u56E0\u6570\u5206\u89E3\u3057\u3001\
    (\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\u6570\u306E\u6607\u9806\u306B\
    \u4E26\u3079\u3066\u8FD4\u3059 O(log x)\n     */\n    std::vector<std::pair<int,\
    \ int>> factorize(int x) const {\n        assert(1 <= x && x <= n);\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (x > 1) {\n            int p = lpf[x], e = 0;\n  \
    \          while (x % p == 0) x /= p, e++;\n            res.emplace_back(p, e);\n\
    \        }\n        return res;\n    }\n    /**\n     * @brief x (1 <= x <= n)\
    \ \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\
    \u3059\n     */\n    std::vector<int> divisors(int x) const {\n        std::vector<int>\
    \ res = {1};\n        for (auto [p, e] : factorize(x)) {\n            int sz =\
    \ res.size();\n            int pw = 1;\n            for (int i = 0; i < e; i++)\
    \ {\n                pw *= p;\n                for (int j = 0; j < sz; j++) res.push_back(res[j]\
    \ * pw);\n            }\n        }\n        std::sort(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n#line 12 \"src/math/divisor-transform.hpp\"\n\
    \n/**\n * @brief \u7D04\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{d\
    \ | n} a[d] O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\
    \u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename\
    \ T>\nvoid divisor_zeta(std::vector<T>& a) {\n    int n = (int)a.size() - 1;\n\
    \    for (int p : enumerate_primes(n)) {\n        for (int i = 1; i <= n / p;\
    \ i++) a[i * p] += a[i];\n    }\n}\n\n/**\n * @brief \u7D04\u6570\u306E\u30E1\u30D3\
    \u30A6\u30B9\u5909\u63DB (divisor_zeta \u306E\u9006\u5909\u63DB) O(N log log N)\n\
    \ * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\
    \u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid divisor_mobius(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : enumerate_primes(n))\
    \ {\n        for (int i = n / p; i >= 1; i--) a[i * p] -= a[i];\n    }\n}\n\n\
    /**\n * @brief \u500D\u6570\u306E\u30BC\u30FC\u30BF\u5909\u63DB a[n] <- sum_{n\
    \ | m, m <= N} a[m] O(N log log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() -\
    \ 1) \u3092\u4F7F\u3046\u3002a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate\
    \ <typename T>\nvoid multiple_zeta(std::vector<T>& a) {\n    int n = (int)a.size()\
    \ - 1;\n    for (int p : enumerate_primes(n)) {\n        for (int i = n / p; i\
    \ >= 1; i--) a[i] += a[i * p];\n    }\n}\n\n/**\n * @brief \u500D\u6570\u306E\u30E1\
    \u30D3\u30A6\u30B9\u5909\u63DB (multiple_zeta \u306E\u9006\u5909\u63DB) O(N log\
    \ log N)\n * \u6DFB\u5B57 1, ..., N (N = a.size() - 1) \u3092\u4F7F\u3046\u3002\
    a[0] \u306F\u5909\u3048\u306A\u3044\n */\ntemplate <typename T>\nvoid multiple_mobius(std::vector<T>&\
    \ a) {\n    int n = (int)a.size() - 1;\n    for (int p : enumerate_primes(n))\
    \ {\n        for (int i = 1; i <= n / p; i++) a[i] -= a[i * p];\n    }\n}\n\n\
    /**\n * @brief GCD \u7573\u307F\u8FBC\u307F c[k] = sum_{gcd(i, j) = k} a[i] b[j]\
    \ (1 <= i, j <= N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\u9577\u3055\
    \ N + 1 \u3067\u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002c[0] \u306F\
    \ T()\n */\ntemplate <typename T>\nstd::vector<T> gcd_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size());\n    multiple_zeta(a);\n\
    \    multiple_zeta(b);\n    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n\
    \    multiple_mobius(a);\n    if (!a.empty()) a[0] = T();\n    return a;\n}\n\n\
    /**\n * @brief LCM \u7573\u307F\u8FBC\u307F c[k] = sum_{lcm(i, j) = k} a[i] b[j]\
    \ (1 <= i, j <= N\u3001k <= N) O(N log log N)\n * a \u3068 b \u306F\u540C\u3058\
    \u9577\u3055 N + 1 \u3067\u3001\u6DFB\u5B57 0 \u306F\u4F7F\u308F\u306A\u3044\u3002\
    c[0] \u306F T()\u3002lcm \u304C N \u3092\u8D85\u3048\u308B\u7D44\u306F\u6570\u3048\
    \u306A\u3044\n */\ntemplate <typename T>\nstd::vector<T> lcm_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    assert(a.size() == b.size());\n    divisor_zeta(a);\n\
    \    divisor_zeta(b);\n    for (int i = 1; i < (int)a.size(); i++) a[i] *= b[i];\n\
    \    divisor_mobius(a);\n    if (!a.empty()) a[0] = T();\n    return a;\n}\n#line\
    \ 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n */\n\n#line 9 \"src/math/modint.hpp\"\n#include <cstdint>\n#line\
    \ 11 \"src/math/modint.hpp\"\n#include <limits>\n#include <type_traits>\n#line\
    \ 14 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format off\n\
    static constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166, 7429,\
    \  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128,  5212,\
    \  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,  8028,\
    \ 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,  1074,\
    \  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729, 10239,\n\
    \      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487, 3266,\
    \  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,  1882,\
    \  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n     7447,\
    \  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41, 19875,  3110,\
    \ 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,  1169,  3315,\
    \   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,  5354, 4447,\
    \ 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,   429,  1930, 14873,\
    \  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850, 55637,  1753,  4178,\
    \ 8466,   222,  2579,  2743,  2031,  2226,\n     2276,   374, 2132,  813, 23788,\
    \  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,   165,  1375, 10018,\n\
    \    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,  5788,   434, 8085,\
    \ 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195, 8344,  6232,  9183,\
    \  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115,   368,   566,\n     5674,\
    \   411,  522, 1027,  8215,  2050,  6544, 10049,   614,   774, 2333,  3007, 35201,\
    \  4706,  1152,  1785,\n     1028,  1540, 3743,  493,  4474,  2521, 26845,  8354,\
    \   864, 18915, 5465,  2447,    42,  4511,  1660,   166,\n     1249,  6259, 2553,\
    \  304,   272,  7286,    73,  6554,   899,  2816, 5197, 13330,  7054,  2818, \
    \ 3199,   811,\n      922,   350, 7514, 4452,  3449,  2663,  4708,   418,  1621,\
    \  1171, 3471,    88, 11345,   412,  1559,   194,\n};\n// clang-format on\n\n\
    static constexpr bool is_SPRP(std::uint32_t n, std::uint32_t a) noexcept {\n \
    \   std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while ((d & 1) ==\
    \ 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur = 1;\n  \
    \  std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur = (cur * a)\
    \ % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n        pw >>= 1;\n\
    \    }\n    if (cur == 1) return true;\n    for (std::uint32_t r = 0; r < s; ++r)\
    \ {\n        if (cur == n - 1) return true;\n        cur = (cur * cur) % n;\n\
    \    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\u306A\u3057\
    \u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek and J.\
    \ Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine Word,\u201D\
    \ presented at the Conference on Current Trends in Theory and Practice of Informatics,\
    \ 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t x) noexcept\
    \ {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n    if (x % 2\
    \ == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n    if (x < 121)\
    \ return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n\
    \    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) & 0xff;\n    return\
    \ is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\n/// @brief\
    \ static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP \u306B\u3088\
    \u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\u30B9\ntemplate\
    \ <class Modint>\nclass modint_base {\n   public:\n    /// @brief \u4FDD\u6301\
    \u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\n    ///\
    \ @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr modint_base()\
    \ noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>\
    \ && std::is_signed_v<SignedIntegral>>* = nullptr>\n    constexpr modint_base(SignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, std::enable_if_t<std::is_integral_v<UnsignedIntegral>\
    \ && std::is_unsigned_v<UnsignedIntegral>>* = nullptr>\n    constexpr modint_base(UnsignedIntegral\
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
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr static_modint(SignedIntegral value) noexcept\n   \
    \     : base_type{value} {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\
    \uFF1A @f$O(\\log value)@f$\n    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n\
    \    [[nodiscard]]\n    constexpr static_modint inv() const noexcept {\n     \
    \   if constexpr (internal_modint::is_prime32(Mod)) {\n            assert(this->m_value\
    \ != 0 && \"The inverse element of zero does not exist.\");\n            return\
    \ this->pow(Mod - 2);\n        } else {\n            return base_type::inv();\n\
    \        }\n    }\n};\n\n/// @brief \u5B9F\u884C\u6642\u306B\u6CD5\u304C\u6C7A\
    \u307E\u308B\u3068\u304D\u3001\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\
    \u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n/// @tparam ID \u3053\
    \u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\u5B9A\u3059\u308B\u3053\u3068\u304C\
    \u3067\u304D\u307E\u3059\ntemplate <int ID>\nclass dynamic_modint : public modint_base<dynamic_modint<ID>>\
    \ {\n   private:\n    using base_type = modint_base<dynamic_modint<ID>>;\n\n \
    \  public:\n    using typename base_type::value_type;\n\n    /// @brief \u6CD5\
    \u3092\u53D6\u5F97\u3057\u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n\
    \    static value_type mod() noexcept {\n        return modulus;\n    }\n\n  \
    \  /// @brief \u6CD5\u3092\u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param\
    \ m \u65B0\u3057\u3044\u6CD5\n    static void set_mod(value_type m) noexcept {\n\
    \        assert(m > 0 && m <= std::numeric_limits<value_type>::max() / 2);\n \
    \       modulus = m;\n    }\n\n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\
    \u307E\u3059\u3002\n    constexpr dynamic_modint() noexcept\n        : base_type{}\
    \ {}\n\n    /// @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\
    \u307E\u3059\u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\
    \n    template <class SignedIntegral, std::enable_if_t<std::is_integral_v<SignedIntegral>>*\
    \ = nullptr>\n    constexpr dynamic_modint(SignedIntegral value) noexcept\n  \
    \      : base_type{value} {}\n\n   private:\n    inline static value_type modulus\
    \ = 998244353;\n};\n\nusing modint998244353 = static_modint<998244353>;\nusing\
    \ modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    #line 8 \"test/yosupo/gcd-convolution.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    using mint = modint998244353;\n  \
    \  int n;\n    std::cin >> n;\n    std::vector<mint> a(n + 1), b(n + 1);\n   \
    \ for (int i = 1; i <= n; i++) std::cin >> a[i];\n    for (int i = 1; i <= n;\
    \ i++) std::cin >> b[i];\n    std::vector<mint> c = gcd_convolution(a, b);\n \
    \   for (int i = 1; i <= n; i++) std::cout << c[i] << \" \\n\"[i == n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../src/math/divisor-transform.hpp\"\
    \n#include \"../../src/math/modint.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    using mint = modint998244353;\n  \
    \  int n;\n    std::cin >> n;\n    std::vector<mint> a(n + 1), b(n + 1);\n   \
    \ for (int i = 1; i <= n; i++) std::cin >> a[i];\n    for (int i = 1; i <= n;\
    \ i++) std::cin >> b[i];\n    std::vector<mint> c = gcd_convolution(a, b);\n \
    \   for (int i = 1; i <= n; i++) std::cout << c[i] << \" \\n\"[i == n];\n}\n"
  dependsOn:
  - src/math/divisor-transform.hpp
  - src/math/prime.hpp
  - src/math/modular-arithmetic.hpp
  - src/math/modint.hpp
  isVerificationFile: true
  path: test/yosupo/gcd-convolution.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/gcd-convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd-convolution.test.cpp
- /verify/test/yosupo/gcd-convolution.test.cpp.html
title: test/yosupo/gcd-convolution.test.cpp
---
