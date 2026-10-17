---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/math/rational.hpp
    title: "\u6709\u7406\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1160.test.cpp
    title: test/aoj/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-5-a.test.cpp
    title: test/aoj/dsl-5-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ntl-1-e.test.cpp
    title: test/aoj/ntl-1-e.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/functions.test.cpp
    title: test/unittest/functions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/rational.test.cpp
    title: test/unittest/rational.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n\
    \ * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iterator>\n#include <numeric>\n#include\
    \ <type_traits>\n\ntemplate <typename T1, typename T2>\ninline constexpr bool\
    \ chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr long long max(const long\
    \ long& t1, const long long& t2) {\n    return std::max<long long>(t1, t2);\n\
    }\n\ninline constexpr long long min(const long long& t1, const long long& t2)\
    \ {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\n\
    using std::lcm;\nusing std::size;\n\ntemplate <typename T>\nconstexpr T extgcd(const\
    \ T& a, const T& b, T& x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d\
    \ = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n       \
    \ x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n/**\n * floor(a / b) (b !=\
    \ 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n */\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr std::common_type_t<T1, T2> floordiv(T1 a, T2 b) {\n  \
    \  return a / b - (a % b != 0 && (a < 0) != (b < 0));\n}\n/**\n * ceil(a / b)\
    \ (b != 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n */\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr std::common_type_t<T1, T2> ceildiv(T1 a, T2 b) {\n   \
    \ return a / b + (a % b != 0 && (a < 0) == (b < 0));\n}\n\n/**\n * 0 <= x < a\n\
    \ */\ninline constexpr bool inrange(long long x, long long a) {\n    return 0\
    \ <= x && x < a;\n}\n/**\n * a <= x < b\n */\ninline constexpr bool inrange(long\
    \ long x, long long a, long long b) {\n    return a <= x && x < b;\n}\n/**\n *\
    \ 0 <= x < a and 0 <= y < b\n */\ninline constexpr bool inrect(long long x, long\
    \ long y, long long a, long long b) {\n    return 0 <= x && x < a && 0 <= y &&\
    \ y < b;\n}\n"
  code: "#pragma once\n\n/**\n * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\
    \u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include <algorithm>\n#include <cmath>\n\
    #include <iterator>\n#include <numeric>\n#include <type_traits>\n\ntemplate <typename\
    \ T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate\
    \ <typename T1, typename T2>\ninline constexpr bool chmax(T1& a, T2 b) {\n   \
    \ if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ninline constexpr long long max(const long long& t1, const long long& t2)\
    \ {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr long long\
    \ min(const long long& t1, const long long& t2) {\n    return std::min<long long>(t1,\
    \ t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing std::size;\n\
    \ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T& b, T& x, T& y)\
    \ {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y, x);\n  \
    \      y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n    }\n\
    \    return d;\n}\n\n/**\n * floor(a / b) (b != 0\u3001\u8CA0\u306E\u6570\u3082\
    \u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> floordiv(T1 a, T2 b) {\n    return a / b - (a % b != 0 && (a < 0) != (b\
    \ < 0));\n}\n/**\n * ceil(a / b) (b != 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n\
    \ */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> ceildiv(T1 a, T2 b) {\n    return a / b + (a % b != 0 && (a < 0) == (b <\
    \ 0));\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr bool inrange(long long\
    \ x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n * a <= x < b\n */\n\
    inline constexpr bool inrange(long long x, long long a, long long b) {\n    return\
    \ a <= x && x < b;\n}\n/**\n * 0 <= x < a and 0 <= y < b\n */\ninline constexpr\
    \ bool inrect(long long x, long long y, long long a, long long b) {\n    return\
    \ 0 <= x && x < a && 0 <= y && y < b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base/functions.hpp
  requiredBy:
  - src/math/rational.hpp
  timestamp: '2026-10-17 23:17:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/rational.test.cpp
  - test/unittest/functions.test.cpp
  - test/aoj/1160.test.cpp
  - test/aoj/ntl-1-e.test.cpp
  - test/aoj/dsl-5-a.test.cpp
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
| `inrange(x, a)` | $0 \le x < a$ か | $O(1)$ |
| `inrange(x, a, b)` | $a \le x < b$ か | $O(1)$ |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か | $O(1)$ |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) | $O(1)$ |

`std::abs`、`std::gcd`、`std::lcm`、`std::size` は `using` 宣言してあるので、`std::` なしで使えます。

## 関連

- 二分探索 `binary_search` は [二分探索](../utility/binary-search.hpp)
- 偏角ソートは [偏角](../geometry/angle.hpp) の `Angle`
