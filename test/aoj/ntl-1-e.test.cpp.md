---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"test/aoj/ntl-1-e.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n * @file\
    \ functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069\
    )\n */\n\n#include <algorithm>\n#include <cmath>\n#include <iterator>\n#include\
    \ <numeric>\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmin(T1\
    \ &a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ bool chmax(T1 &a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr long long max(const long\
    \ long &t1, const long long &t2) {\n    return std::max<long long>(t1, t2);\n\
    }\n\ninline constexpr long long min(const long long &t1, const long long &t2)\
    \ {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\n\
    using std::lcm;\nusing std::size;\n\ntemplate <typename T>\nconstexpr T extgcd(const\
    \ T &a, const T &b, T &x, T &y) {\n    T d = a;\n    if (b != 0) {\n        d\
    \ = extgcd(b, a % b, y, x);\n        y -= (a / b) * x;\n    } else {\n       \
    \ x = 1;\n        y = 0;\n    }\n    return d;\n}\n\n/**\n * 0 <= x < a\n */\n\
    inline constexpr bool inrange(long long x, long long a) {\n    return 0 <= x and\
    \ x < a;\n}\n/**\n * a <= x < b\n */\ninline constexpr bool inrange(long long\
    \ x, long long a, long long b) {\n    return a <= x and x < b;\n}\n/**\n * 0 <=\
    \ x < a and 0 <= y < b\n */\ninline constexpr bool inrect(long long x, long long\
    \ y, long long a, long long b) {\n    return 0 <= x and x < a and 0 <= y and y\
    \ < b;\n}\n#line 6 \"test/aoj/ntl-1-e.test.cpp\"\n\nint main() {\n    long long\
    \ a, b;\n    std::cin >> a >> b;\n    long long x, y;\n    // extgcd \u306E\u89E3\
    \u306F |x| + |y| \u304C\u6700\u5C0F\u3067\u3001\u540C\u3058\u306A\u3089 x <= y\
    \ \u3092\u6E80\u305F\u3059 (\u554F\u984C\u304C\u8981\u6C42\u3059\u308B\u89E3\u3068\
    \u4E00\u81F4\u3059\u308B)\n    extgcd(a, b, x, y);\n    std::cout << x << ' '\
    \ << y << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../../src/base/functions.hpp\"\n\nint main()\
    \ {\n    long long a, b;\n    std::cin >> a >> b;\n    long long x, y;\n    //\
    \ extgcd \u306E\u89E3\u306F |x| + |y| \u304C\u6700\u5C0F\u3067\u3001\u540C\u3058\
    \u306A\u3089 x <= y \u3092\u6E80\u305F\u3059 (\u554F\u984C\u304C\u8981\u6C42\u3059\
    \u308B\u89E3\u3068\u4E00\u81F4\u3059\u308B)\n    extgcd(a, b, x, y);\n    std::cout\
    \ << x << ' ' << y << '\\n';\n}\n"
  dependsOn:
  - src/base/functions.hpp
  isVerificationFile: true
  path: test/aoj/ntl-1-e.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 13:03:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ntl-1-e.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ntl-1-e.test.cpp
- /verify/test/aoj/ntl-1-e.test.cpp.html
title: test/aoj/ntl-1-e.test.cpp
---
