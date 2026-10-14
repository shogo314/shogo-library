---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/bit.hpp
    title: "\u30D3\u30C3\u30C8\u6F14\u7B97"
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
  bundledCode: "#line 1 \"test/unittest/bit.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// bit.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/bit.hpp\"\
    \n\n/**\n * @file bit.hpp\n * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include\
    \ <cassert>\n#include <string>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\
    \u5217\u3092long long\u306B\u3059\u308B\n */\ninline long long btoll(std::string\
    \ s, char one = '1') {\n    long long res = 0;\n    for (char c : s) {\n     \
    \   res <<= 1;\n        if (c == one) ++res;\n    }\n    return res;\n}\n\n#if\
    \ __cplusplus < 202000L\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n */\ninline constexpr\
    \ int popcount(long long a) {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline\
    \ constexpr int countl_zero(long long a) {\n    assert(a >= 0);\n    return __builtin_clzll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline\
    \ constexpr int countr_zero(long long a) {\n    assert(a >= 0);\n    return __builtin_ctzll((unsigned\
    \ long long)a);\n}\n\n#else\n\n#include <bit>\n#define BIT_FUNC_EXPAND(func) \
    \                     \\\n    inline constexpr long long func(long long a) { \\\
    \n        assert(a >= 0);                            \\\n        return std::func((unsigned\
    \ long long)a);   \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(popcount)\n/**\n *\
    \ @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\
    \u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countl_zero)\n/**\n * @brief \u5DE6\u304B\
    \u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\
    \n */\nBIT_FUNC_EXPAND(countl_one)\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\
    \u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_zero)\n\
    /**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_one)\n/**\n * @brief \u6574\
    \u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\u308B\
    \n */\nBIT_FUNC_EXPAND(bit_ceil)\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\
    \u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n\
    /**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\
    \u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\
    \n#endif\n#line 7 \"test/unittest/bit.test.cpp\"\n\n#include <iostream>\n#include\
    \ <random>\n#line 11 \"test/unittest/bit.test.cpp\"\n\nbool ok = true;\n\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n\n    for (int rep = 0; rep < 100000\
    \ && ok; rep++) {\n        // 0 \u4EE5\u4E0A\u306E long long (\u30D3\u30C3\u30C8\
    \u6570\u3082\u3070\u3089\u3064\u304B\u305B\u308B)\n        int width = rng() %\
    \ 63 + 1;\n        long long a = (long long)(rng() >> (64 - width));\n\n     \
    \   int pc = 0, clz = 0, ctz = 0;\n        for (int i = 0; i < 63; i++) pc +=\
    \ a >> i & 1;\n        for (int i = 63; i >= 0 && !(a >> i & 1); i--) clz++;\n\
    \        for (int i = 0; i < 64 && !(a >> i & 1); i++) ctz++;\n        check(popcount(a)\
    \ == pc, \"popcount\");\n        if (a > 0) {\n            check(countl_zero(a)\
    \ == clz, \"countl_zero\");\n            check(countr_zero(a) == ctz, \"countr_zero\"\
    );\n        }\n\n        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\
    \u4F4D\u6841\u304B\u3089)\n        std::string s;\n        for (int i = width\
    \ - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) ==\
    \ a, \"btoll\");\n        // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\
    \u3059\u308B\n        std::string t = s;\n        for (char& c : t) c = (c ==\
    \ '1') ? '#' : '.';\n        check(btoll(t, '#') == a, \"btoll(s, one)\");\n \
    \   }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n    check(popcount(0) == 0 &&\
    \ popcount((1LL << 62) - 1) == 62, \"popcount \u5883\u754C\");\n    check(countl_zero(1)\
    \ == 63 && countr_zero(1LL << 62) == 62, \"countl_zero / countr_zero \u5883\u754C\
    \");\n    check(btoll(\"\") == 0 && btoll(\"0\") == 0 && btoll(\"101\") == 5,\
    \ \"btoll \u6C7A\u307E\u3063\u305F\u5024\");\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// bit.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/utility/bit.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <string>\n\nbool ok = true;\n\
    \nvoid check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n\
    }\n\nint main() {\n    std::mt19937_64 rng(314);\n\n    for (int rep = 0; rep\
    \ < 100000 && ok; rep++) {\n        // 0 \u4EE5\u4E0A\u306E long long (\u30D3\u30C3\
    \u30C8\u6570\u3082\u3070\u3089\u3064\u304B\u305B\u308B)\n        int width = rng()\
    \ % 63 + 1;\n        long long a = (long long)(rng() >> (64 - width));\n\n   \
    \     int pc = 0, clz = 0, ctz = 0;\n        for (int i = 0; i < 63; i++) pc +=\
    \ a >> i & 1;\n        for (int i = 63; i >= 0 && !(a >> i & 1); i--) clz++;\n\
    \        for (int i = 0; i < 64 && !(a >> i & 1); i++) ctz++;\n        check(popcount(a)\
    \ == pc, \"popcount\");\n        if (a > 0) {\n            check(countl_zero(a)\
    \ == clz, \"countl_zero\");\n            check(countr_zero(a) == ctz, \"countr_zero\"\
    );\n        }\n\n        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\
    \u4F4D\u6841\u304B\u3089)\n        std::string s;\n        for (int i = width\
    \ - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) ==\
    \ a, \"btoll\");\n        // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\
    \u3059\u308B\n        std::string t = s;\n        for (char& c : t) c = (c ==\
    \ '1') ? '#' : '.';\n        check(btoll(t, '#') == a, \"btoll(s, one)\");\n \
    \   }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n    check(popcount(0) == 0 &&\
    \ popcount((1LL << 62) - 1) == 62, \"popcount \u5883\u754C\");\n    check(countl_zero(1)\
    \ == 63 && countr_zero(1LL << 62) == 62, \"countl_zero / countr_zero \u5883\u754C\
    \");\n    check(btoll(\"\") == 0 && btoll(\"0\") == 0 && btoll(\"101\") == 5,\
    \ \"btoll \u6C7A\u307E\u3063\u305F\u5024\");\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/bit.hpp
  isVerificationFile: true
  path: test/unittest/bit.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 16:39:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/bit.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/bit.test.cpp
- /verify/test/unittest/bit.test.cpp.html
title: test/unittest/bit.test.cpp
---
