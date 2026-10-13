---
data:
  _extendedDependsOn:
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/enumerate-primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/math/prime.hpp\"\n\n/**\n * @file prime.hpp\n\
    \ * @brief \u7D20\u6570 (\u7D20\u6570\u5224\u5B9A\u3001\u7D20\u56E0\u6570\u5206\
    \u89E3\u3001\u7D04\u6570\u5217\u6319\u3001\u7BE9)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <initializer_list>\n#include <numeric>\n#include\
    \ <utility>\n#line 14 \"src/math/prime.hpp\"\n\nnamespace prime_detail {\n\nusing\
    \ u64 = unsigned long long;\nusing u128 = unsigned __int128;\n\nconstexpr u64\
    \ mul_mod(u64 a, u64 b, u64 m) { return static_cast<u64>(static_cast<u128>(a)\
    \ * b % m); }\nconstexpr u64 pow_mod(u64 a, u64 e, u64 m) {\n    u64 res = 1 %\
    \ m;\n    a %= m;\n    for (; e > 0; e >>= 1) {\n        if (e & 1) res = mul_mod(res,\
    \ a, m);\n        a = mul_mod(a, a, m);\n    }\n    return res;\n}\n\n/**\n *\
    \ @brief Pollard \u306E \u03C1 \u6CD5 (Brent \u306E\u6539\u826F) \u3067\u5408\u6210\
    \u6570 n \u306E 1 \u3067\u3082 n \u3067\u3082\u306A\u3044\u7D04\u6570\u3092 1\
    \ \u3064\u898B\u3064\u3051\u308B\n */\ninline u64 find_factor(u64 n) {\n    if\
    \ (n % 2 == 0) return 2;\n    constexpr u64 m = 128;\n    for (u64 c = 1;; c++)\
    \ {\n        auto f = [&](u64 x) { return (mul_mod(x, x, n) + c) % n; };\n   \
    \     auto diff = [](u64 x, u64 y) { return x > y ? x - y : y - x; };\n      \
    \  u64 x = 0, y = 2, ys = 2, q = 1, g = 1;\n        for (u64 r = 1; g == 1; r\
    \ <<= 1) {\n            x = y;\n            for (u64 i = 0; i < r; i++) y = f(y);\n\
    \            for (u64 k = 0; k < r && g == 1; k += m) {\n                ys =\
    \ y;\n                for (u64 i = 0; i < m && i < r - k; i++) {\n           \
    \         y = f(y);\n                    q = mul_mod(q, diff(x, y), n);\n    \
    \            }\n                g = std::gcd(q, n);\n            }\n        }\n\
    \        if (g == n) {\n            // \u307E\u3068\u3081\u3066\u639B\u3051\u305F\
    \u305B\u3044\u3067 n \u306B\u306A\u3063\u305F\u306E\u3067\u30011 \u3064\u305A\u3064\
    \u623B\u3063\u3066\u78BA\u304B\u3081\u308B\n            do {\n               \
    \ ys = f(ys);\n                g = std::gcd(diff(x, ys), n);\n            } while\
    \ (g == 1);\n        }\n        if (g != n) return g;\n    }\n}\n\n}  // namespace\
    \ prime_detail\n\n/**\n * @brief n \u304C\u7D20\u6570\u304B (Miller-Rabin\u3001\
    64 bit \u3067\u6C7A\u5B9A\u7684) O(log n)\n */\nconstexpr bool is_prime(long long\
    \ n) {\n    using namespace prime_detail;\n    if (n < 2) return false;\n    for\
    \ (u64 p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n        if (static_cast<u64>(n)\
    \ % p == 0) return static_cast<u64>(n) == p;\n    }\n    const u64 m = n;\n  \
    \  u64 d = m - 1;\n    int s = 0;\n    while (d % 2 == 0) d /= 2, s++;\n    for\
    \ (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})\
    \ {\n        a %= m;\n        if (a == 0) continue;\n        u64 x = pow_mod(a,\
    \ d, m);\n        if (x == 1 || x == m - 1) continue;\n        bool composite\
    \ = true;\n        for (int i = 1; i < s; i++) {\n            x = mul_mod(x, x,\
    \ m);\n            if (x == m - 1) {\n                composite = false;\n   \
    \             break;\n            }\n        }\n        if (composite) return\
    \ false;\n    }\n    return true;\n}\n\n/**\n * @brief n (>= 1) \u3092\u7D20\u56E0\
    \u6570\u5206\u89E3\u3057\u3001(\u7D20\u56E0\u6570, \u6307\u6570) \u3092\u7D20\u56E0\
    \u6570\u306E\u6607\u9806\u306B\u4E26\u3079\u3066\u8FD4\u3059\n * Pollard \u306E\
    \ \u03C1 \u6CD5\u3092\u4F7F\u3046\u3002\u671F\u5F85 O(n^(1/4)) \u7A0B\u5EA6\n\
    \ */\ninline std::vector<std::pair<long long, int>> factorize(long long n) {\n\
    \    assert(n >= 1);\n    std::vector<long long> ps;\n    // \u5C0F\u3055\u3044\
    \u7D20\u56E0\u6570\u306F\u5272\u308A\u7B97\u3067\u53D6\u308A\u9664\u304F\n   \
    \ for (long long p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {\n       \
    \ while (n % p == 0) {\n            ps.push_back(p);\n            n /= p;\n  \
    \      }\n    }\n    std::vector<long long> st;\n    if (n > 1) st.push_back(n);\n\
    \    while (!st.empty()) {\n        long long x = st.back();\n        st.pop_back();\n\
    \        if (is_prime(x)) {\n            ps.push_back(x);\n            continue;\n\
    \        }\n        long long d = prime_detail::find_factor(x);\n        st.push_back(d);\n\
    \        st.push_back(x / d);\n    }\n    std::sort(ps.begin(), ps.end());\n \
    \   std::vector<std::pair<long long, int>> res;\n    for (long long p : ps) {\n\
    \        if (!res.empty() && res.back().first == p) res.back().second++;\n   \
    \     else res.emplace_back(p, 1);\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ n (>= 1) \u306E\u6B63\u306E\u7D04\u6570\u3092\u6607\u9806\u306B\u4E26\u3079\u3066\
    \u8FD4\u3059\n */\ninline std::vector<long long> divisors(long long n) {\n   \
    \ std::vector<long long> res = {1};\n    for (auto [p, e] : factorize(n)) {\n\
    \        int sz = res.size();\n        long long pw = 1;\n        for (int i =\
    \ 0; i < e; i++) {\n            pw *= p;\n            for (int j = 0; j < sz;\
    \ j++) res.push_back(res[j] * pw);\n        }\n    }\n    std::sort(res.begin(),\
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
    \u56E0\u6570\n    std::vector<int> ps;\n\npublic:\n    explicit Sieve(int n) :\
    \ n(n), lpf(n + 1, 0) {\n        assert(n >= 0);\n        for (int i = 2; i <=\
    \ n; i++) {\n            if (lpf[i] == 0) {\n                lpf[i] = i;\n   \
    \             ps.push_back(i);\n            }\n            for (int p : ps) {\n\
    \                if (p > lpf[i] || static_cast<long long>(p) * i > n) break;\n\
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
    \        return res;\n    }\n};\n#line 7 \"test/yosupo/enumerate-primes.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, a, b;\n    std::cin >> n >> a >> b;\n    std::vector<int> ps = enumerate_primes(n);\n\
    \    std::vector<int> ans;\n    for (int i = b; i < (int)ps.size(); i += a) ans.push_back(ps[i]);\n\
    \    std::cout << ps.size() << ' ' << ans.size() << '\\n';\n    for (std::size_t\
    \ i = 0; i < ans.size(); i++) std::cout << ans[i] << \" \\n\"[i + 1 == ans.size()];\n\
    \    if (ans.empty()) std::cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <iostream>\n#include <vector>\n\n#include \"../../src/math/prime.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, a, b;\n    std::cin >> n >> a >> b;\n    std::vector<int> ps = enumerate_primes(n);\n\
    \    std::vector<int> ans;\n    for (int i = b; i < (int)ps.size(); i += a) ans.push_back(ps[i]);\n\
    \    std::cout << ps.size() << ' ' << ans.size() << '\\n';\n    for (std::size_t\
    \ i = 0; i < ans.size(); i++) std::cout << ans[i] << \" \\n\"[i + 1 == ans.size()];\n\
    \    if (ans.empty()) std::cout << '\\n';\n}\n"
  dependsOn:
  - src/math/prime.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate-primes.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 20:17:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate-primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate-primes.test.cpp
- /verify/test/yosupo/enumerate-primes.test.cpp.html
title: test/yosupo/enumerate-primes.test.cpp
---
