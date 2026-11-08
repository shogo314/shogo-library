---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/prime-counting.test.cpp
    title: test/unittest/math/prime-counting.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/quotients-linear.test.cpp
    title: test/unittest/math/quotients-linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/quotients.test.cpp
    title: test/unittest/math/quotients.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/enumerate-quotients.2.test.cpp
    title: test/yosupo/number_theory/enumerate-quotients.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5546\u306E\u5217\u6319 (floor(n / i)\u30FBfloor((a x + b) /\
      \ m) \u304C\u4E00\u5B9A\u306E\u533A\u9593)"
    links: []
  bundledCode: "#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n\
    \ * @brief \u5546\u306E\u5217\u6319 (floor(n / i)\u30FBfloor((a x + b) / m) \u304C\
    \u4E00\u5B9A\u306E\u533A\u9593)\n */\n\n#include <cassert>\n#include <limits>\n\
    #include <vector>\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n\
    \ * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iterator>\n#line 12 \"src/base/functions.hpp\"\
    \n#include <numeric>\n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\
    #include <type_traits>\n#include <utility>\n\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a\
    \ = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T1, typename T2>\ninline constexpr bool chmax(T1& a, T2 b) {\n    if (a < b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\ninline\
    \ constexpr long long max(const long long& t1, const long long& t2) {\n    return\
    \ std::max<long long>(t1, t2);\n}\n\ninline constexpr long long min(const long\
    \ long& t1, const long long& t2) {\n    return std::min<long long>(t1, t2);\n\
    }\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing std::size;\n\n#if\
    \ __cplusplus >= 202002L\nusing std::midpoint;\n#else\n// C++20 \u306E std::midpoint\
    \ \u3068\u540C\u3058 (\u6574\u6570\u306F a \u306E\u5074\u306B\u4E38\u3081\u3001\
    \u3042\u3075\u308C\u306A\u3044)\ntemplate <typename T>\ninline constexpr std::enable_if_t<std::is_integral_v<T>\
    \ && !std::is_same_v<T, bool>, T> midpoint(T a, T b) noexcept {\n    using U =\
    \ std::make_unsigned_t<T>;\n    if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
    \ - static_cast<U>(a)) >> 1));\n    return static_cast<T>(a - static_cast<T>(static_cast<U>(static_cast<U>(a)\
    \ - static_cast<U>(b)) >> 1));\n}\ntemplate <typename T>\ninline constexpr std::enable_if_t<std::is_floating_point_v<T>,\
    \ T> midpoint(T a, T b) noexcept {\n    constexpr T lo = std::numeric_limits<T>::min()\
    \ * 2;\n    constexpr T hi = std::numeric_limits<T>::max() / 2;\n    const T abs_a\
    \ = a < 0 ? -a : a, abs_b = b < 0 ? -b : b;\n    if (abs_a <= hi && abs_b <= hi)\
    \ return (a + b) / 2;\n    if (abs_a < lo) return a + b / 2;\n    if (abs_b <\
    \ lo) return a / 2 + b;\n    return a / 2 + b / 2;\n}\ntemplate <typename T>\n\
    inline constexpr std::enable_if_t<std::is_object_v<T>, T*> midpoint(T* a, T* b)\
    \ noexcept {\n    return a + (b - a) / 2;\n}\n#endif\n\n/**\n * \u8981\u7D20\u6570\
    \u3092 long long \u3067\u8FD4\u3059 (std::ssize \u306E long long \u7248)\n * size()\
    \ \u3092\u6301\u3064\u578B\u306A\u3089\u3001begin() \u3068 end() \u3092\u6301\u305F\
    \u306A\u3044\u81EA\u4F5C\u306E\u578B\u306B\u3082\u4F7F\u3048\u308B\n */\n#if __cplusplus\
    \ >= 202002L\ntemplate <typename R>\n    requires requires(R& r) { std::ranges::size(r);\
    \ }\ninline constexpr long long len(R&& r) {\n    return static_cast<long long>(std::ranges::size(r));\n\
    }\n#else\ntemplate <typename C>\ninline constexpr auto len(const C& c) -> decltype(static_cast<long\
    \ long>(std::size(c))) {\n    return static_cast<long long>(std::size(c));\n}\n\
    #endif\n\ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T& b, T&\
    \ x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y,\
    \ x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n\
    \    }\n    return d;\n}\n\n/**\n * floor(a / b) (b != 0\u3001\u8CA0\u306E\u6570\
    \u3082\u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> floordiv(T1 a, T2 b) {\n    return a / b - (a % b != 0 && (a < 0) != (b\
    \ < 0));\n}\n/**\n * ceil(a / b) (b != 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n\
    \ */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> ceildiv(T1 a, T2 b) {\n    return a / b + (a % b != 0 && (a < 0) == (b <\
    \ 0));\n}\n/**\n * {floor(a / b), a - b * floor(a / b)} (b != 0\u3001\u8CA0\u306E\
    \u6570\u3082\u53EF)\n * \u4F59\u308A\u306F 0 \u307E\u305F\u306F b \u3068\u540C\
    \u3058\u7B26\u53F7\u306B\u306A\u308B\n */\ntemplate <typename T1, typename T2>\n\
    inline constexpr std::pair<std::common_type_t<T1, T2>, std::common_type_t<T1,\
    \ T2>> divmod(T1 a, T2 b) {\n    std::common_type_t<T1, T2> q = floordiv(a, b);\n\
    \    return {q, a - q * b};\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr bool\
    \ inrange(long long x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n *\
    \ a <= x < b\n */\ninline constexpr bool inrange(long long x, long long a, long\
    \ long b) {\n    return a <= x && x < b;\n}\n/**\n * 0 <= x < a and 0 <= y < b\n\
    \ */\ninline constexpr bool inrect(long long x, long long y, long long a, long\
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n#line 13 \"src/math/quotients.hpp\"\
    \n\n/**\n * @brief \u5546 q \u3068\u3001\u305D\u308C\u3092\u3068\u308B\u6DFB\u5B57\
    \u306E\u533A\u9593 [l, r)\n */\nstruct QuotientRange {\n    long long q;  //!<\
    \ \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080\
    )\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u307E\u306A\u3044\
    )\n};\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806)\
    \ \u306B f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i < r \u306A\u3089\
    \ floor(n / i) == q\n * @pre 0 <= n < std::numeric_limits<long long>::max()\n\
    \ */\ntemplate <typename F>\nvoid for_each_quotient(long long n, F f) {\n    assert(0\
    \ <= n && n < std::numeric_limits<long long>::max());\n    for (long long l =\
    \ 1; l <= n;) {\n        long long q = n / l, r = n / q + 1;\n        f(q, l,\
    \ r);\n        l = r;\n    }\n}\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n\
    \ / i) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\
    \u6607\u9806\u3001\u3064\u307E\u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\
    \u9593\u306E\u500B\u6570\u306F 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange>\
    \ enumerate_quotients(long long n) {\n    std::vector<QuotientRange> res;\n  \
    \  for_each_quotient(n, [&](long long q, long long l, long long r) { res.push_back({q,\
    \ l, r}); });\n    return res;\n}\n\n/**\n * @brief x = 0, ..., n - 1 \u3092 floor((a\
    \ x + b) / m) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\u3051\u3001x \u306E\u6607\
    \u9806\u306B f(q, l, r) \u3092\u547C\u3076 O(\u533A\u9593\u6570)\n * @pre n >=\
    \ 0\u3001m >= 1\u3001\u5404\u5546\u304C long long \u306B\u53CE\u307E\u308B\u3053\
    \u3068\u3002a, b \u306F\u8CA0\u3067\u3082\u3088\u3044\n */\ntemplate <typename\
    \ F>\nvoid for_each_quotient_linear(long long n, long long m, long long a, long\
    \ long b, F f) {\n    assert(n >= 0 && m >= 1);\n    const __int128_t slope =\
    \ a;\n    for (long long l = 0; l < n;) {\n        auto [q, rem] = divmod(slope\
    \ * l + b, static_cast<__int128_t>(m));\n        assert(std::numeric_limits<long\
    \ long>::min() <= q && q <= std::numeric_limits<long long>::max());\n        __int128_t\
    \ length = n - l;\n        // \u6B63\u306E\u50BE\u304D\u3067\u306F\u6B21\u306E\
    \u5546\u306B\u5C4A\u304F\u307E\u3067\u3001\u8CA0\u306E\u50BE\u304D\u3067\u306F\
    \u4F59\u308A\u304C\u8CA0\u306B\u306A\u308B\u307E\u3067\u9032\u3080\n        if\
    \ (a > 0) chmin(length, ceildiv(m - rem, slope));\n        if (a < 0) chmin(length,\
    \ rem / (-slope) + 1);\n        const long long r = l + static_cast<long long>(length);\n\
    \        f(static_cast<long long>(q), l, r);\n        l = r;\n    }\n}\n\n/**\n\
    \ * @brief x = 0, ..., n - 1 \u3092 floor((a x + b) / m) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u305F\u3082\u306E (x \u306E\u6607\u9806) O(\u533A\u9593\
    \u6570)\n * @pre n >= 0\u3001m >= 1\u3001\u5404\u5546\u304C long long \u306B\u53CE\
    \u307E\u308B\u3053\u3068\u3002a, b \u306F\u8CA0\u3067\u3082\u3088\u3044\n */\n\
    inline std::vector<QuotientRange> enumerate_quotients_linear(long long n, long\
    \ long m, long long a, long long b) {\n    std::vector<QuotientRange> res;\n \
    \   for_each_quotient_linear(n, m, a, b, [&](long long q, long long l, long long\
    \ r) { res.push_back({q, l, r}); });\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file quotients.hpp\n * @brief \u5546\u306E\u5217\
    \u6319 (floor(n / i)\u30FBfloor((a x + b) / m) \u304C\u4E00\u5B9A\u306E\u533A\u9593\
    )\n */\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\n#include\
    \ \"../base/functions.hpp\"\n\n/**\n * @brief \u5546 q \u3068\u3001\u305D\u308C\
    \u3092\u3068\u308B\u6DFB\u5B57\u306E\u533A\u9593 [l, r)\n */\nstruct QuotientRange\
    \ {\n    long long q;  //!< \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\
    \u7AEF (\u542B\u3080)\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\
    \u307E\u306A\u3044)\n};\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\
    \u5024\u3067\u533A\u9593\u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\
    \u964D\u9806) \u306B f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i < r \u306A\
    \u3089 floor(n / i) == q\n * @pre 0 <= n < std::numeric_limits<long long>::max()\n\
    \ */\ntemplate <typename F>\nvoid for_each_quotient(long long n, F f) {\n    assert(0\
    \ <= n && n < std::numeric_limits<long long>::max());\n    for (long long l =\
    \ 1; l <= n;) {\n        long long q = n / l, r = n / q + 1;\n        f(q, l,\
    \ r);\n        l = r;\n    }\n}\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n\
    \ / i) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\
    \u6607\u9806\u3001\u3064\u307E\u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\
    \u9593\u306E\u500B\u6570\u306F 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange>\
    \ enumerate_quotients(long long n) {\n    std::vector<QuotientRange> res;\n  \
    \  for_each_quotient(n, [&](long long q, long long l, long long r) { res.push_back({q,\
    \ l, r}); });\n    return res;\n}\n\n/**\n * @brief x = 0, ..., n - 1 \u3092 floor((a\
    \ x + b) / m) \u306E\u5024\u3067\u533A\u9593\u306B\u5206\u3051\u3001x \u306E\u6607\
    \u9806\u306B f(q, l, r) \u3092\u547C\u3076 O(\u533A\u9593\u6570)\n * @pre n >=\
    \ 0\u3001m >= 1\u3001\u5404\u5546\u304C long long \u306B\u53CE\u307E\u308B\u3053\
    \u3068\u3002a, b \u306F\u8CA0\u3067\u3082\u3088\u3044\n */\ntemplate <typename\
    \ F>\nvoid for_each_quotient_linear(long long n, long long m, long long a, long\
    \ long b, F f) {\n    assert(n >= 0 && m >= 1);\n    const __int128_t slope =\
    \ a;\n    for (long long l = 0; l < n;) {\n        auto [q, rem] = divmod(slope\
    \ * l + b, static_cast<__int128_t>(m));\n        assert(std::numeric_limits<long\
    \ long>::min() <= q && q <= std::numeric_limits<long long>::max());\n        __int128_t\
    \ length = n - l;\n        // \u6B63\u306E\u50BE\u304D\u3067\u306F\u6B21\u306E\
    \u5546\u306B\u5C4A\u304F\u307E\u3067\u3001\u8CA0\u306E\u50BE\u304D\u3067\u306F\
    \u4F59\u308A\u304C\u8CA0\u306B\u306A\u308B\u307E\u3067\u9032\u3080\n        if\
    \ (a > 0) chmin(length, ceildiv(m - rem, slope));\n        if (a < 0) chmin(length,\
    \ rem / (-slope) + 1);\n        const long long r = l + static_cast<long long>(length);\n\
    \        f(static_cast<long long>(q), l, r);\n        l = r;\n    }\n}\n\n/**\n\
    \ * @brief x = 0, ..., n - 1 \u3092 floor((a x + b) / m) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u305F\u3082\u306E (x \u306E\u6607\u9806) O(\u533A\u9593\
    \u6570)\n * @pre n >= 0\u3001m >= 1\u3001\u5404\u5546\u304C long long \u306B\u53CE\
    \u307E\u308B\u3053\u3068\u3002a, b \u306F\u8CA0\u3067\u3082\u3088\u3044\n */\n\
    inline std::vector<QuotientRange> enumerate_quotients_linear(long long n, long\
    \ long m, long long a, long long b) {\n    std::vector<QuotientRange> res;\n \
    \   for_each_quotient_linear(n, m, a, b, [&](long long q, long long l, long long\
    \ r) { res.push_back({q, l, r}); });\n    return res;\n}\n"
  dependsOn:
  - src/base/functions.hpp
  isVerificationFile: false
  path: src/math/quotients.hpp
  requiredBy: []
  timestamp: '2026-11-09 03:52:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/quotients-linear.test.cpp
  - test/unittest/math/quotients.test.cpp
  - test/unittest/math/prime-counting.test.cpp
  - test/yosupo/number_theory/enumerate-quotients.2.test.cpp
documentation_of: src/math/quotients.hpp
layout: document
title: "\u5546\u306E\u5217\u6319"
---

$\lfloor n / i \rfloor$、または $\lfloor (ax+b)/m \rfloor$ が同じ値になる最大の半開区間を列挙します。$\lfloor n / i \rfloor$ がとる値は $O(\sqrt{n})$ 種類しかないので (区間の個数は $2\sqrt{n}$ 以下)、$\sum_{i=1}^{n} f(\lfloor n/i \rfloor)$ のような和を、区間ごとにまとめて $O(\sqrt{n})$ で計算できます。

例えば $n = 10$ では、次の 5 つの区間に分かれます。

| 商 `q` | 10 | 5 | 3 | 2 | 1 |
|---|---|---|---|---|---|
| 区間 `[l, r)` | [1, 2) | [2, 3) | [3, 4) | [4, 6) | [6, 11) |

```cpp
// sum_{i=1}^{n} floor(n / i) (= 約数の個数の和 d(1) + ... + d(n))
long long sum = 0;
for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l); });

for (auto [q, l, r] : enumerate_quotients(10)) {
    // (10, 1, 2), (5, 2, 3), (3, 3, 4), (2, 4, 6), (1, 6, 11) の順
}

// floor(x / 3) が同じになる区間 (0 <= x < 10)
for (auto [q, l, r] : enumerate_quotients_linear(10, 3, 1, 0)) {
    // (0, 0, 3), (1, 3, 6), (2, 6, 9), (3, 9, 10) の順
}

// sum_{x=0}^{n-1} floor((a*x+b)/m)
long long linear_sum = 0;
for_each_quotient_linear(n, m, a, b, [&](long long q, long long l, long long r) { linear_sum += q * (r - l); });
```

`_linear` 版の引数順は `floor_sum(n, m, a, b)` と同じです。対象は `0 <= x < n` で、`a`、`b` は負でもよく、床関数は負の無限大方向への切り捨てです。`n >= 0`、`m >= 1`、各商が `long long` に収まることが前提です。中間計算には `__int128` を使います。

どちらの版も添字の昇順に列挙し、`n = 0` では区間を返しません。`_linear` 版の商は `a > 0` なら昇順、`a < 0` なら降順です。`a = 0` で `n > 0` なら全域を 1 区間として返します。以下では `_linear` 版の出力区間数を $K$ とします。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `for_each_quotient(n, f)` | 区間ごとに `f(q, l, r)` を呼ぶ。$l \le i < r$ なら $\lfloor n/i \rfloor = q$ | $O(\sqrt{n})$ |
| `enumerate_quotients(n)` | 区間を `QuotientRange` (メンバ `q`、`l`、`r`) のリストで返す | $O(\sqrt{n})$ |
| `for_each_quotient_linear(n, m, a, b, f)` | $\lfloor (ax+b)/m \rfloor$ が一定の区間ごとに `f(q, l, r)` を呼ぶ | $O(K)$ |
| `enumerate_quotients_linear(n, m, a, b)` | 上の区間を `QuotientRange` のリストで返す | $O(K)$ |

- 区間 `[l, r)` は右端を含まない半開区間です。区間の長さは `r - l` です。
- $\lfloor n/i \rfloor$ の版の前提は `0 <= n < std::numeric_limits<long long>::max()` です。商は降順に並びます。商の昇順が欲しいときは逆にたどります。
- $\lfloor n/i \rfloor$ の区間の右端は $r = \lfloor n / \lfloor n/l \rfloor \rfloor + 1$ で求めています。
- `_linear` 版は $K \le n$ ですが、平方根程度になる保証はありません。`for_each_quotient_linear` の追加領域は $O(1)$、`enumerate_quotients_linear` は $O(K)$ です (コールバックの時間・領域は除く)。
- `a = 1, b = 0` のとき区間数は $\lceil n/m\rceil$ です。異なる正整数の `m` を $D$ 個処理する総区間数は $O(D+n\log(D+1))$ になります。

## 使い方の例

- $\sum_{i=1}^{n} i \lfloor n/i \rfloor$ (約数の和の総和): 区間ごとに $q \cdot (l + \dots + (r-1))$ を足します。
- $\sum_{i=1}^{n} (n \bmod i)$: $n \bmod i = n - i \lfloor n/i \rfloor$ なので、$n^2$ から上の和を引きます。

## 関連

- 一次関数の床関数の和 $\sum \lfloor (ai + b)/m \rfloor$ は [floor sum](floor-sum.hpp)
- すべての $\lfloor n / k \rfloor$ について素数の個数・和を求めるには [素数の個数・素数の和](prime-counting.hpp)
