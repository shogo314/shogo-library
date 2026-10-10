---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\
      \u308B"
    links: []
  bundledCode: "#line 2 \"base/bit.hpp\"\n#include <cassert>\n#include <string>\n\
    #include <vector>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092\
    long long\u306B\u3059\u308B\n */\ninline long long btoll(std::string s, char one\
    \ = '1') {\n    long long res = 0;\n    for (char c : s) {\n        res <<= 1;\n\
    \        if (c == one) ++res;\n    }\n    return res;\n}\n\n#if __cplusplus <\
    \ 202000L\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\
    \u6570\u3048\u308B\n * __builtin_popcountll\n */\ninline int popcount(long long\
    \ a) {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned long long)a);\n\
    }\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline int countl_zero(long\
    \ long a) {\n    assert(a >= 0);\n    return __builtin_clzll((unsigned long long)a);\n\
    }\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline int countr_zero(long\
    \ long a) {\n    assert(a >= 0);\n    return __builtin_ctzll((unsigned long long)a);\n\
    }\n\n#else\n\n#include <bit>\n#define BIT_FUNC_EXPAND(func)                  \
    \    \\\n    inline constexpr long long func(long long a) { \\\n        assert(a\
    \ >= 0);                            \\\n        return std::func((unsigned long\
    \ long)a);   \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(popcount)\n/**\n * @brief\
    \ \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\
    \u3048\u308B\n */\nBIT_FUNC_EXPAND(countl_zero)\n/**\n * @brief \u5DE6\u304B\u3089\
    \u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\n\
    BIT_FUNC_EXPAND(countl_one)\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\
    \u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_zero)\n\
    /**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_one)\n/**\n * @brief \u6574\
    \u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\u308B\
    \n */\nBIT_FUNC_EXPAND(bit_ceil)\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\
    \u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n\
    /**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\
    \u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\
    \n#endif\n"
  code: "#pragma once\n#include <cassert>\n#include <string>\n#include <vector>\n\n\
    /**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\
    \u308B\n */\ninline long long btoll(std::string s, char one = '1') {\n    long\
    \ long res = 0;\n    for (char c : s) {\n        res <<= 1;\n        if (c ==\
    \ one) ++res;\n    }\n    return res;\n}\n\n#if __cplusplus < 202000L\n\n/**\n\
    \ * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\
    \n * __builtin_popcountll\n */\ninline int popcount(long long a) {\n    assert(a\
    \ >= 0);\n    return __builtin_popcountll((unsigned long long)a);\n}\n/**\n *\
    \ @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\
    \u6570\u3048\u308B\n * __builtin_clzll\n */\ninline int countl_zero(long long\
    \ a) {\n    assert(a >= 0);\n    return __builtin_clzll((unsigned long long)a);\n\
    }\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline int countr_zero(long\
    \ long a) {\n    assert(a >= 0);\n    return __builtin_ctzll((unsigned long long)a);\n\
    }\n\n#else\n\n#include <bit>\n#define BIT_FUNC_EXPAND(func)                  \
    \    \\\n    inline constexpr long long func(long long a) { \\\n        assert(a\
    \ >= 0);                            \\\n        return std::func((unsigned long\
    \ long)a);   \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(popcount)\n/**\n * @brief\
    \ \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\
    \u3048\u308B\n */\nBIT_FUNC_EXPAND(countl_zero)\n/**\n * @brief \u5DE6\u304B\u3089\
    \u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\n\
    BIT_FUNC_EXPAND(countl_one)\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\
    \u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_zero)\n\
    /**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_one)\n/**\n * @brief \u6574\
    \u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\u308B\
    \n */\nBIT_FUNC_EXPAND(bit_ceil)\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\
    \u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n\
    /**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\
    \u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: base/bit.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/bit.hpp
layout: document
redirect_from:
- /library/base/bit.hpp
- /library/base/bit.hpp.html
title: "2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\u308B"
---
