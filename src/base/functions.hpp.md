---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n\
    \ * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iterator>\n#include <numeric>\n\ntemplate\
    \ <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b) {\n   \
    \ if (a > b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1& a, T2\
    \ b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ninline constexpr long long max(const long long& t1, const long\
    \ long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
    \ long long min(const long long& t1, const long long& t2) {\n    return std::min<long\
    \ long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing\
    \ std::size;\n\ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T&\
    \ b, T& x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a %\
    \ b, y, x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n       \
    \ y = 0;\n    }\n    return d;\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr\
    \ bool inrange(long long x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n\
    \ * a <= x < b\n */\ninline constexpr bool inrange(long long x, long long a, long\
    \ long b) {\n    return a <= x && x < b;\n}\n/**\n * 0 <= x < a and 0 <= y < b\n\
    \ */\ninline constexpr bool inrect(long long x, long long y, long long a, long\
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n"
  code: "#pragma once\n\n/**\n * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\
    \u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include <algorithm>\n#include <cmath>\n\
    #include <iterator>\n#include <numeric>\n\ntemplate <typename T1, typename T2>\n\
    inline constexpr bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <typename T1, typename\
    \ T2>\ninline constexpr bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a\
    \ = b;\n        return true;\n    }\n    return false;\n}\n\ninline constexpr\
    \ long long max(const long long& t1, const long long& t2) {\n    return std::max<long\
    \ long>(t1, t2);\n}\n\ninline constexpr long long min(const long long& t1, const\
    \ long long& t2) {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\n\
    using std::gcd;\nusing std::lcm;\nusing std::size;\n\ntemplate <typename T>\n\
    constexpr T extgcd(const T& a, const T& b, T& x, T& y) {\n    T d = a;\n    if\
    \ (b != 0) {\n        d = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n\
    \    } else {\n        x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n/**\n\
    \ * 0 <= x < a\n */\ninline constexpr bool inrange(long long x, long long a) {\n\
    \    return 0 <= x && x < a;\n}\n/**\n * a <= x < b\n */\ninline constexpr bool\
    \ inrange(long long x, long long a, long long b) {\n    return a <= x && x < b;\n\
    }\n/**\n * 0 <= x < a and 0 <= y < b\n */\ninline constexpr bool inrect(long long\
    \ x, long long y, long long a, long long b) {\n    return 0 <= x && x < a && 0\
    \ <= y && y < b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base/functions.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:34:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
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

| 関数 | 説明 |
|---|---|
| `chmin(a, b)` / `chmax(a, b)` | `a` を `min(a, b)` / `max(a, b)` に更新し、更新したら `true` |
| `extgcd(a, b, x, y)` | $ax + by = \gcd(a, b)$ となる `x`、`y` を求め、$\gcd(a, b)$ を返す |
| `inrange(x, a)` | $0 \le x < a$ か |
| `inrange(x, a, b)` | $a \le x < b$ か |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) |

`std::abs`、`std::gcd`、`std::lcm`、`std::size` は `using` 宣言してあるので、`std::` なしで使えます。

## 関連

- 二分探索 `binary_search` は [二分探索](../utility/binary-search.hpp)
- 偏角ソートは [偏角](../geometry/angle.hpp) の `Angle`
