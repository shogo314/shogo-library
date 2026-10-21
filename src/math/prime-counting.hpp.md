---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/sqrt.hpp
    title: "\u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/prime-counting.test.cpp
    title: test/unittest/math/prime-counting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/counting-primes.test.cpp
    title: test/yosupo/number_theory/counting-primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u7D20\u6570\u306E\u500B\u6570\u30FB\u7D20\u6570\u306E\u548C\
      \ (Lucy DP)"
    links: []
  bundledCode: "#line 2 \"src/math/prime-counting.hpp\"\n\n/**\n * @file prime-counting.hpp\n\
    \ * @brief \u7D20\u6570\u306E\u500B\u6570\u30FB\u7D20\u6570\u306E\u548C (Lucy\
    \ DP)\n */\n\n#include <cassert>\n#include <vector>\n\n#line 2 \"src/math/sqrt.hpp\"\
    \n\n/**\n * @file sqrt.hpp\n * @brief \u6574\u6570\u306E\u5E73\u65B9\u6839\u30FB\
    k \u4E57\u6839\n */\n\n#line 9 \"src/math/sqrt.hpp\"\n#include <cmath>\n\n/**\n\
    \ * @brief floor(sqrt(n))\n * @param n \u5E73\u65B9\u6839\u3092\u6C42\u3081\u305F\
    \u3044\u6574\u6570 long long \u578B\u3067 0 <= n < 2^63 \u3092\u6E80\u305F\u3059\
    \n * @return long long\n */\ninline long long sqrtll(long long n) {\n    assert(n\
    \ >= 0);\n    // 3037000500 = ceil(sqrt(2^63))\n    long long le = 0, ri = 3037000500;\n\
    \    while (ri - le > 1) {\n        long long mid = (le + ri) / 2;\n        if\
    \ (mid * mid <= n)\n            le = mid;\n        else\n            ri = mid;\n\
    \    }\n    return le;\n}\n\n/**\n * @brief floor(a^(1/k))\n *\n * \u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u3067\u8FD1\u3044\u5024\u3092\u6C42\u3081\u3001\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u639B\u3051\
    \u7B97\u3067\u78BA\u304B\u3081\u3066\u5408\u308F\u305B\u308B\n * @param a 0 <=\
    \ a < 2^64\n * @param k 1 \u4EE5\u4E0A\n * @return unsigned long long\n */\ninline\
    \ unsigned long long kth_root(unsigned long long a, long long k) {\n    assert(k\
    \ >= 1);\n    if (k == 1 || a <= 1) return a;\n    if (k >= 64) return 1;  //\
    \ a < 2^64 \u306A\u306E\u3067\n    // x^k <= a \u304B\n    auto fits = [&](unsigned\
    \ long long x) {\n        unsigned long long p = 1;\n        for (long long i\
    \ = 0; i < k; i++) {\n            if (p > a / x) return false;\n            p\
    \ *= x;\n        }\n        return true;\n    };\n    unsigned long long x = static_cast<unsigned\
    \ long long>(std::pow(static_cast<long double>(a), 1.0L / k));\n    if (x == 0)\
    \ x = 1;\n    while (!fits(x)) x--;\n    while (fits(x + 1)) x++;\n    return\
    \ x;\n}\n#line 12 \"src/math/prime-counting.hpp\"\n\n/**\n * @brief \u3059\u3079\
    \u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001v \u4EE5\u4E0B\u306E\
    \u7D20\u6570 p \u306E g(p) \u306E\u548C\u3092\u6C42\u3081\u305F\u8868 (Lucy DP)\n\
    \ *\n * g \u306F\u5B8C\u5168\u4E57\u6CD5\u7684 (g(ab) = g(a) g(b)) \u3067\u3042\
    \u308B\u3053\u3068\u3002prefix(v) \u306F g(2) + g(3) + ... + g(v) (2 \u4EE5\u4E0A\
    \ v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C)\n * \u4F8B:\
    \ \u7D20\u6570\u306E\u500B\u6570\u306A\u3089 g(p) = 1\u3001prefix(v) = v - 1\u3002\
    \u7D20\u6570\u306E\u548C\u306A\u3089 g(p) = p\u3001prefix(v) = v (v + 1) / 2 -\
    \ 1\n * O(n^(3/4) / log n)\u3001\u30E1\u30E2\u30EA O(sqrt(n))\n * \u4F8B:\n *\
    \ PrimeSumTable<__int128> t(n, [](long long v) { return (__int128)v * (v + 1)\
    \ / 2 - 1; }, [](long long p) { return (__int128)p; });\n * t(n);      // n \u4EE5\
    \u4E0B\u306E\u7D20\u6570\u306E\u548C\n * t(n / 3);  // floor(n / 3) \u4EE5\u4E0B\
    \u306E\u7D20\u6570\u306E\u548C\n *\n * @tparam T \u548C\u306E\u578B (long long\u3001\
    __int128\u3001modint \u306A\u3069)\n */\ntemplate <typename T>\nclass PrimeSumTable\
    \ {\n    long long n, sq;\n    std::vector<long long> vals;  // floor(n / k) \u306E\
    \u3068\u308B\u5024\u306E\u6607\u9806 (1, 2, ..., sq \u3068\u3001sq \u3088\u308A\
    \u5927\u304D\u3044 n / k)\n    std::vector<T> sum;           // sum[i] \u306F\
    \ vals[i] \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C\n\n    long\
    \ long index(long long v) const { return v <= sq ? v - 1 : static_cast<long long>(vals.size())\
    \ - n / v; }\n\n   public:\n    /**\n     * @brief \u8868\u3092\u4F5C\u308B\n\
    \     * @pre n >= 1\n     */\n    template <typename Prefix, typename G>\n   \
    \ PrimeSumTable(long long n, Prefix prefix, G g) : n(n), sq(sqrtll(n)) {\n   \
    \     assert(n >= 1);\n        for (long long v = 1; v <= sq; v++) vals.push_back(v);\n\
    \        for (long long k = n / (sq + 1); k >= 1; k--) vals.push_back(n / k);\n\
    \        sum.resize(vals.size());\n        // \u306F\u3058\u3081\u306F 2 \u4EE5\
    \u4E0A v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C\u3002\u5C0F\
    \u3055\u3044\u7D20\u6570 p \u304B\u3089\u9806\u306B\u3001\u6700\u5C0F\u7D20\u56E0\
    \u6570\u304C p \u306E\u5408\u6210\u6570\u306E\u5206\u3092\u5F15\u304F\n      \
    \  for (size_t i = 0; i < vals.size(); i++) sum[i] = prefix(vals[i]);\n      \
    \  std::vector<bool> composite(sq + 1, false);\n        for (long long p = 2;\
    \ p <= sq; p++) {\n            if (composite[p]) continue;\n            for (long\
    \ long q = p * p; q <= sq; q += p) composite[q] = true;\n            const T gp\
    \ = g(p), below = sum[p - 2];  // below \u306F p - 1 \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u306E\u548C\n            const long long p2 = p * p;\n            // v >= p^2\
    \ \u306E\u5024\u3092\u3001\u5927\u304D\u3044\u65B9\u304B\u3089 (floor(v / p) \u304C\
    \u307E\u3060\u66F4\u65B0\u3055\u308C\u3066\u3044\u306A\u3044\u3046\u3061\u306B\
    ) \u66F4\u65B0\u3059\u308B\n            for (long long i = static_cast<long long>(vals.size())\
    \ - 1; i >= 0 && vals[i] >= p2; i--) {\n                sum[i] -= gp * (sum[index(vals[i]\
    \ / p)] - below);\n            }\n        }\n    }\n\n    /**\n     * @brief v\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C O(1)\n     * @pre\
    \ v = floor(n / k) \u3068\u306A\u308B k >= 1 \u304C\u3042\u308B\u3053\u3068 (v\
    \ = 0 \u3082\u53EF)\n     */\n    T operator()(long long v) const {\n        assert(0\
    \ <= v && v <= n);\n        if (v == 0) return T(0);\n        long long i = index(v);\n\
    \        assert(vals[i] == v && \"PrimeSumTable: v \u306F floor(n / k) \u306E\u5F62\
    \u3067\u3042\u308B\u3053\u3068\");\n        return sum[i];\n    }\n    /**\n \
    \    * @brief floor(n / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\n     */\n\
    \    const std::vector<long long>& values() const { return vals; }\n};\n\n/**\n\
    \ * @brief \u3059\u3079\u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001\
    v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u305F\u8868\
    \ O(n^(3/4) / log n)\n * \u4F8B: auto t = prime_count_table(n); t(n / 2);\n */\n\
    inline PrimeSumTable<long long> prime_count_table(long long n) {\n    return PrimeSumTable<long\
    \ long>(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });\n\
    }\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570 \u03C0\
    (n) O(n^(3/4) / log n)\n */\ninline long long prime_count(long long n) {\n   \
    \ assert(n >= 0);\n    if (n < 2) return 0;\n    return prime_count_table(n)(n);\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file prime-counting.hpp\n * @brief \u7D20\u6570\u306E\
    \u500B\u6570\u30FB\u7D20\u6570\u306E\u548C (Lucy DP)\n */\n\n#include <cassert>\n\
    #include <vector>\n\n#include \"sqrt.hpp\"\n\n/**\n * @brief \u3059\u3079\u3066\
    \u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001v \u4EE5\u4E0B\u306E\u7D20\
    \u6570 p \u306E g(p) \u306E\u548C\u3092\u6C42\u3081\u305F\u8868 (Lucy DP)\n *\n\
    \ * g \u306F\u5B8C\u5168\u4E57\u6CD5\u7684 (g(ab) = g(a) g(b)) \u3067\u3042\u308B\
    \u3053\u3068\u3002prefix(v) \u306F g(2) + g(3) + ... + g(v) (2 \u4EE5\u4E0A v\
    \ \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C)\n * \u4F8B: \u7D20\
    \u6570\u306E\u500B\u6570\u306A\u3089 g(p) = 1\u3001prefix(v) = v - 1\u3002\u7D20\
    \u6570\u306E\u548C\u306A\u3089 g(p) = p\u3001prefix(v) = v (v + 1) / 2 - 1\n *\
    \ O(n^(3/4) / log n)\u3001\u30E1\u30E2\u30EA O(sqrt(n))\n * \u4F8B:\n * PrimeSumTable<__int128>\
    \ t(n, [](long long v) { return (__int128)v * (v + 1) / 2 - 1; }, [](long long\
    \ p) { return (__int128)p; });\n * t(n);      // n \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u306E\u548C\n * t(n / 3);  // floor(n / 3) \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\
    \u548C\n *\n * @tparam T \u548C\u306E\u578B (long long\u3001__int128\u3001modint\
    \ \u306A\u3069)\n */\ntemplate <typename T>\nclass PrimeSumTable {\n    long long\
    \ n, sq;\n    std::vector<long long> vals;  // floor(n / k) \u306E\u3068\u308B\
    \u5024\u306E\u6607\u9806 (1, 2, ..., sq \u3068\u3001sq \u3088\u308A\u5927\u304D\
    \u3044 n / k)\n    std::vector<T> sum;           // sum[i] \u306F vals[i] \u4EE5\
    \u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C\n\n    long long index(long\
    \ long v) const { return v <= sq ? v - 1 : static_cast<long long>(vals.size())\
    \ - n / v; }\n\n   public:\n    /**\n     * @brief \u8868\u3092\u4F5C\u308B\n\
    \     * @pre n >= 1\n     */\n    template <typename Prefix, typename G>\n   \
    \ PrimeSumTable(long long n, Prefix prefix, G g) : n(n), sq(sqrtll(n)) {\n   \
    \     assert(n >= 1);\n        for (long long v = 1; v <= sq; v++) vals.push_back(v);\n\
    \        for (long long k = n / (sq + 1); k >= 1; k--) vals.push_back(n / k);\n\
    \        sum.resize(vals.size());\n        // \u306F\u3058\u3081\u306F 2 \u4EE5\
    \u4E0A v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C\u3002\u5C0F\
    \u3055\u3044\u7D20\u6570 p \u304B\u3089\u9806\u306B\u3001\u6700\u5C0F\u7D20\u56E0\
    \u6570\u304C p \u306E\u5408\u6210\u6570\u306E\u5206\u3092\u5F15\u304F\n      \
    \  for (size_t i = 0; i < vals.size(); i++) sum[i] = prefix(vals[i]);\n      \
    \  std::vector<bool> composite(sq + 1, false);\n        for (long long p = 2;\
    \ p <= sq; p++) {\n            if (composite[p]) continue;\n            for (long\
    \ long q = p * p; q <= sq; q += p) composite[q] = true;\n            const T gp\
    \ = g(p), below = sum[p - 2];  // below \u306F p - 1 \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u306E\u548C\n            const long long p2 = p * p;\n            // v >= p^2\
    \ \u306E\u5024\u3092\u3001\u5927\u304D\u3044\u65B9\u304B\u3089 (floor(v / p) \u304C\
    \u307E\u3060\u66F4\u65B0\u3055\u308C\u3066\u3044\u306A\u3044\u3046\u3061\u306B\
    ) \u66F4\u65B0\u3059\u308B\n            for (long long i = static_cast<long long>(vals.size())\
    \ - 1; i >= 0 && vals[i] >= p2; i--) {\n                sum[i] -= gp * (sum[index(vals[i]\
    \ / p)] - below);\n            }\n        }\n    }\n\n    /**\n     * @brief v\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C O(1)\n     * @pre\
    \ v = floor(n / k) \u3068\u306A\u308B k >= 1 \u304C\u3042\u308B\u3053\u3068 (v\
    \ = 0 \u3082\u53EF)\n     */\n    T operator()(long long v) const {\n        assert(0\
    \ <= v && v <= n);\n        if (v == 0) return T(0);\n        long long i = index(v);\n\
    \        assert(vals[i] == v && \"PrimeSumTable: v \u306F floor(n / k) \u306E\u5F62\
    \u3067\u3042\u308B\u3053\u3068\");\n        return sum[i];\n    }\n    /**\n \
    \    * @brief floor(n / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\n     */\n\
    \    const std::vector<long long>& values() const { return vals; }\n};\n\n/**\n\
    \ * @brief \u3059\u3079\u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001\
    v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u305F\u8868\
    \ O(n^(3/4) / log n)\n * \u4F8B: auto t = prime_count_table(n); t(n / 2);\n */\n\
    inline PrimeSumTable<long long> prime_count_table(long long n) {\n    return PrimeSumTable<long\
    \ long>(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });\n\
    }\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570 \u03C0\
    (n) O(n^(3/4) / log n)\n */\ninline long long prime_count(long long n) {\n   \
    \ assert(n >= 0);\n    if (n < 2) return 0;\n    return prime_count_table(n)(n);\n\
    }\n"
  dependsOn:
  - src/math/sqrt.hpp
  isVerificationFile: false
  path: src/math/prime-counting.hpp
  requiredBy: []
  timestamp: '2026-10-22 04:30:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/prime-counting.test.cpp
  - test/yosupo/number_theory/counting-primes.test.cpp
documentation_of: src/math/prime-counting.hpp
layout: document
title: "\u7D20\u6570\u306E\u500B\u6570\u30FB\u7D20\u6570\u306E\u548C (Lucy DP)"
---

$n$ 以下の素数の個数 $\pi(n)$ を、篩を使わずに $O(n^{3/4} / \log n)$ で求めます ($n = 10^{11}$ で 0.2 秒程度)。同じ計算で、すべての $v = \lfloor n / k \rfloor$ について「$v$ 以下の素数の個数」や「$v$ 以下の素数 $p$ の $g(p)$ の和」($g$ は完全乗法的) をまとめて求めた表も作れます。乗法的関数の和を求めるときの土台になります。

```cpp
long long c = prime_count(100000000000LL);  // π(10^11) = 4118054813

auto t = prime_count_table(n);  // すべての floor(n / k) についての π
t(n);                           // π(n)
t(n / 3);                       // π(floor(n / 3))

// 素数の和 (g(p) = p)。prefix(v) は 2 以上 v 以下の整数すべての g の和
PrimeSumTable<__int128> s(n, [](long long v) { return (__int128)v * (v + 1) / 2 - 1; },
                             [](long long p) { return (__int128)p; });
s(n);                           // n 以下の素数の和
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `prime_count(n)` | $n$ 以下の素数の個数 $\pi(n)$ ($n \ge 0$) | $O(n^{3/4} / \log n)$ |
| `prime_count_table(n)` | すべての $v = \lfloor n / k \rfloor$ について $\pi(v)$ を求めた `PrimeSumTable<long long>` ($n \ge 1$) | $O(n^{3/4} / \log n)$ |

## `PrimeSumTable<T>`

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PrimeSumTable<T>(n, prefix, g)` | すべての $v = \lfloor n / k \rfloor$ について $\sum_{p \le v,\ p \text{ は素数}} g(p)$ を求める ($n \ge 1$)。`g` は完全乗法的 ($g(ab) = g(a) g(b)$) な関数で、`prefix(v)` は $g(2) + g(3) + \dots + g(v)$ (2 以上 $v$ 以下の整数すべての和) を返す関数 | $O(n^{3/4} / \log n)$、メモリ $O(\sqrt{n})$ |
| `t(v)` | $v$ 以下の素数 $p$ の $g(p)$ の和。$v$ は $\lfloor n / k \rfloor$ の形 (または 0) であること | $O(1)$ |
| `values()` | $\lfloor n / k \rfloor$ のとる値を昇順に並べたもの | $O(1)$ |

- `T` は `long long`、`__int128`、`modint` など、足し算・引き算・掛け算ができる型です。素数の和は $n = 10^{11}$ で $10^{20}$ を超えるので、`__int128` か `modint` を使います。
- 2 以上 $v$ 以下の整数すべての和から始めて、小さい素数 $p$ から順に「最小素因数が $p$ の合成数」の分を引いていきます (Lucy DP)。$p^2 \le v$ の値だけを更新するので、計算量が $O(n^{3/4} / \log n)$ になります。
- $g(p) = p^k$ の表をいくつか組み合わせれば、$p$ の多項式で表される $g(p)$ の和も求められます。

## 関連

- 小さい $n$ までの素数の列挙や素因数分解は [素数](prime.hpp)
- $\lfloor n / k \rfloor$ の値ごとの区間は [商の列挙](quotients.hpp)
