---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/rational.hpp
    title: "\u6709\u7406\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/stern-brocot.hpp
    title: "Stern\u2013Brocot \u6728\u3068\u9023\u5206\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-5-a.test.cpp
    title: test/aoj/dsl/dsl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl/ntl-1-e.test.cpp
    title: test/aoj/ntl/ntl-1-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume11/1160.test.cpp
    title: test/aoj/volume11/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/base/functions.test.cpp
    title: test/unittest/base/functions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/rational.test.cpp
    title: test/unittest/math/rational.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/stern-brocot.test.cpp
    title: test/unittest/math/stern-brocot.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/rational-approximation.test.cpp
    title: test/yosupo/number_theory/rational-approximation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_theory/stern-brocot-tree.test.cpp
    title: test/yosupo/number_theory/stern-brocot-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n\
    \ * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iterator>\n#include <limits>\n#include\
    \ <numeric>\n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <typename T1, typename T2>\ninline constexpr bool\
    \ chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr long long max(const long\
    \ long& t1, const long long& t2) {\n    return std::max<long long>(t1, t2);\n\
    }\n\ninline constexpr long long min(const long long& t1, const long long& t2)\
    \ {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\n\
    using std::lcm;\nusing std::size;\n\n#if __cplusplus >= 202002L\nusing std::midpoint;\n\
    #else\n// C++20 \u306E std::midpoint \u3068\u540C\u3058 (\u6574\u6570\u306F a\
    \ \u306E\u5074\u306B\u4E38\u3081\u3001\u3042\u3075\u308C\u306A\u3044)\ntemplate\
    \ <typename T>\ninline constexpr std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T,\
    \ bool>, T> midpoint(T a, T b) noexcept {\n    using U = std::make_unsigned_t<T>;\n\
    \    if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
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
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n"
  code: "#pragma once\n\n/**\n * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\
    \u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include <algorithm>\n#include <cmath>\n\
    #include <iterator>\n#include <limits>\n#include <numeric>\n#if __cplusplus >=\
    \ 202002L\n#include <ranges>\n#endif\n#include <type_traits>\n#include <utility>\n\
    \ntemplate <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1&\
    \ a, T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ninline constexpr long long max(const long long& t1, const\
    \ long long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
    \ long long min(const long long& t1, const long long& t2) {\n    return std::min<long\
    \ long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing\
    \ std::size;\n\n#if __cplusplus >= 202002L\nusing std::midpoint;\n#else\n// C++20\
    \ \u306E std::midpoint \u3068\u540C\u3058 (\u6574\u6570\u306F a \u306E\u5074\u306B\
    \u4E38\u3081\u3001\u3042\u3075\u308C\u306A\u3044)\ntemplate <typename T>\ninline\
    \ constexpr std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>,\
    \ T> midpoint(T a, T b) noexcept {\n    using U = std::make_unsigned_t<T>;\n \
    \   if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
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
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base/functions.hpp
  requiredBy:
  - src/math/rational.hpp
  - src/math/stern-brocot.hpp
  timestamp: '2026-10-20 02:23:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/base/functions.test.cpp
  - test/unittest/math/stern-brocot.test.cpp
  - test/unittest/math/rational.test.cpp
  - test/aoj/ntl/ntl-1-e.test.cpp
  - test/aoj/volume11/1160.test.cpp
  - test/aoj/dsl/dsl-5-a.test.cpp
  - test/yosupo/number_theory/stern-brocot-tree.test.cpp
  - test/yosupo/number_theory/rational-approximation.test.cpp
documentation_of: src/base/functions.hpp
layout: document
title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
---

コンテストでよく使う小さな関数です。

```cpp
long long x = 10;
chmin(x, 3);  // x = 3, true を返す
if (inrect(i, j, h, w)) { /* グリッドの範囲内 */ }
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chmin(a, b)` / `chmax(a, b)` | `a` を `min(a, b)` / `max(a, b)` に更新し、更新したら `true` | $O(1)$ |
| `extgcd(a, b, x, y)` | $ax + by = \gcd(a, b)$ となる `x`、`y` を求め、$\gcd(a, b)$ を返す | $O(\log \max(\lvert a \rvert, \lvert b \rvert))$ |
| `floordiv(a, b)` / `ceildiv(a, b)` | $\lfloor a / b \rfloor$ / $\lceil a / b \rceil$ ($b \ne 0$、負の数も可) | $O(1)$ |
| `divmod(a, b)` | `std::pair` で $\lfloor a / b \rfloor$ と $a - b \lfloor a / b \rfloor$ を返す ($b \ne 0$、負の数も可。余りは 0 か $b$ と同じ符号) | $O(1)$ |
| `inrange(x, a)` | $0 \le x < a$ か | $O(1)$ |
| `inrange(x, a, b)` | $a \le x < b$ か | $O(1)$ |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か | $O(1)$ |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) | $O(1)$ |
| `len(c)` | 要素数を `long long` で返す (`std::ssize` の `long long` 版)。`size()` を持つ型なら、`begin()`・`end()` のない自作の型 (ライブラリの `FastSet`・`RBST` など) にも使える。C++20 では `std::ranges::size` を使うので、`views::iota` など大きさの分かる range 全般にも使える。文字列リテラルは終端の `'\0'` も数える | $O(1)$ |
| `abs(x)` | `std::abs` | $O(1)$ |
| `gcd(a, b)` / `lcm(a, b)` | `std::gcd` / `std::lcm` | $O(\log \max(\lvert a \rvert, \lvert b \rvert))$ |
| `size(c)` | `std::size` (コンテナや配列の要素数) | $O(1)$ |
| `midpoint(a, b)` | `std::midpoint`。$a$ と $b$ の中点をあふれずに求める (整数は $a$ の側に丸める)。ポインタも可 | $O(1)$ |

`abs`、`gcd`、`lcm`、`size`、`midpoint` は `std::` 版を `using` 宣言したものなので、`std::` なしで使えます。`std::midpoint` は C++20 からなので、C++17 では同じ値を返すものを自前で用意しています。

## 関連

- 二分探索 `binary_search` は [二分探索](../utility/binary-search.hpp)
- 偏角ソートは [偏角](../geometry/angle.hpp) の `Angle`
