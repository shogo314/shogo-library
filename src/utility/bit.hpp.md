---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-10-c.test.cpp
    title: test/aoj/itp2-10-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/bit.test.cpp
    title: test/unittest/bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30D3\u30C3\u30C8\u6F14\u7B97"
    links: []
  bundledCode: "#line 2 \"src/utility/bit.hpp\"\n\n/**\n * @file bit.hpp\n * @brief\
    \ \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include <cassert>\n#include <string>\n\
    \n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\
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
  code: "#pragma once\n\n/**\n * @file bit.hpp\n * @brief \u30D3\u30C3\u30C8\u6F14\
    \u7B97\n */\n\n#include <cassert>\n#include <string>\n\n/**\n * @brief 2\u9032\
    \u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\u308B\n */\ninline long\
    \ long btoll(std::string s, char one = '1') {\n    long long res = 0;\n    for\
    \ (char c : s) {\n        res <<= 1;\n        if (c == one) ++res;\n    }\n  \
    \  return res;\n}\n\n#if __cplusplus < 202000L\n\n/**\n * @brief \u7ACB\u3063\u3066\
    \u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n\
    \ */\ninline int popcount(long long a) {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline\
    \ int countl_zero(long long a) {\n    assert(a >= 0);\n    return __builtin_clzll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline\
    \ int countr_zero(long long a) {\n    assert(a >= 0);\n    return __builtin_ctzll((unsigned\
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
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/bit.hpp
  requiredBy: []
  timestamp: '2026-10-13 13:03:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/bit.test.cpp
  - test/aoj/itp2-10-c.test.cpp
documentation_of: src/utility/bit.hpp
layout: document
title: "\u30D3\u30C3\u30C8\u6F14\u7B97"
---

ビット演算の関数です。引数は `long long` で、負の値を渡すと assert で落ちます。そのため、最上位ビット (63 ビット目) が立った 64 ビットの値 (`unsigned long long` のビット集合など) は直接渡せません。

```cpp
btoll("1011");          // 11
btoll("#.#", '#');      // 5 ('#' を 1 とみなす)
popcount(13);           // 3
countl_zero(1);         // 63
countr_zero(8);         // 3
```

## 関数

| 関数 | 説明 | C++17 | C++20 |
|---|---|:-:|:-:|
| `btoll(s, one = '1')` | 2 進数の文字列を `long long` にする。文字 `one` を 1、それ以外を 0 とみなす | ✓ | ✓ |
| `popcount(a)` | 立っているビットの数 | ✓ | ✓ |
| `countl_zero(a)` | 上位 (64 ビット中) から連続する 0 の数 | ✓ | ✓ |
| `countr_zero(a)` | 下位から連続する 0 の数 | ✓ | ✓ |
| `countl_one(a)` | 上位から連続する 1 の数 | | ✓ |
| `countr_one(a)` | 下位から連続する 1 の数 | | ✓ |
| `bit_ceil(a)` | `a` 以上の最小の 2 の累乗 | | ✓ |
| `bit_floor(a)` | `a` 以下の最大の 2 の累乗 | | ✓ |
| `bit_width(a)` | `a` を表すのに必要なビット数 | | ✓ |

C++17 では `__builtin_*` で実装しているので、`countl_zero(0)` と `countr_zero(0)` は未定義動作です。C++20 では `<bit>` の `std::` 版を呼びます。
