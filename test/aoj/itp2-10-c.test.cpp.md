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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C
  bundledCode: "#line 1 \"test/aoj/itp2-10-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C\"\
    \n\n#include <iostream>\n\n#line 2 \"src/utility/bit.hpp\"\n\n/**\n * @file bit.hpp\n\
    \ * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include <cassert>\n#include\
    \ <string>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\
    \u3059\u308B\n */\ninline long long btoll(std::string s, char one = '1') {\n \
    \   long long res = 0;\n    for (char c : s) {\n        res <<= 1;\n        if\
    \ (c == one) ++res;\n    }\n    return res;\n}\n\n#if __cplusplus < 202000L\n\n\
    // C++20 \u306E <bit> \u3068\u540C\u3058\u5024\u3092\u8FD4\u3059 (0 \u306E\u3068\
    \u304D\u3082\u540C\u3058)\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n */\ninline constexpr\
    \ long long popcount(long long a) {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline\
    \ constexpr long long countl_zero(long long a) {\n    assert(a >= 0);\n    return\
    \ a == 0 ? 64 : __builtin_clzll((unsigned long long)a);\n}\n/**\n * @brief \u5DE6\
    \u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\
    \u308B\n */\ninline constexpr long long countl_one(long long a) {\n    assert(a\
    \ >= 0);\n    unsigned long long x = ~(unsigned long long)a;\n    return x ==\
    \ 0 ? 64 : __builtin_clzll(x);\n}\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\
    \u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n\
    \ */\ninline constexpr long long countr_zero(long long a) {\n    assert(a >= 0);\n\
    \    return a == 0 ? 64 : __builtin_ctzll((unsigned long long)a);\n}\n/**\n *\
    \ @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\
    \u6570\u3048\u308B\n */\ninline constexpr long long countr_one(long long a) {\n\
    \    assert(a >= 0);\n    unsigned long long x = ~(unsigned long long)a;\n   \
    \ return x == 0 ? 64 : __builtin_ctzll(x);\n}\n/**\n * @brief \u5024\u3092\u8868\
    \u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u30D3\u30C3\u30C8\u5E45\
    \u3092\u6C42\u3081\u308B\n */\ninline constexpr long long bit_width(long long\
    \ a) {\n    assert(a >= 0);\n    return 64 - countl_zero(a);\n}\n/**\n * @brief\
    \ \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\
    \u308B\n */\ninline constexpr long long bit_ceil(long long a) {\n    assert(0\
    \ <= a && a <= (1LL << 62));\n    return a <= 1 ? 1 : 1LL << bit_width(a - 1);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0B\u3052\u308B\n */\ninline constexpr long long bit_floor(long long\
    \ a) {\n    assert(a >= 0);\n    return a == 0 ? 0 : 1LL << (bit_width(a) - 1);\n\
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
    \n */\ninline constexpr long long bit_ceil(long long a) {\n    // \u7D50\u679C\
    \u304C long long \u306B\u53CE\u307E\u308B\u7BC4\u56F2\u306B\u9650\u308B\n    assert(0\
    \ <= a && a <= (1LL << 62));\n    return std::bit_ceil((unsigned long long)a);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n/**\n * @brief \u5024\
    \u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u30D3\u30C3\
    \u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\n#endif\n\
    #line 6 \"test/aoj/itp2-10-c.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int q;\n    std::cin >> q;\n    unsigned long\
    \ long s = 0;\n    while (q--) {\n        int op;\n        std::cin >> op;\n \
    \       if (op <= 3) {\n            int i;\n            std::cin >> i;\n     \
    \       unsigned long long b = 1ULL << i;\n            if (op == 0) std::cout\
    \ << ((s & b) ? 1 : 0) << '\\n';\n            if (op == 1) s |= b;\n         \
    \   if (op == 2) s &= ~b;\n            if (op == 3) s ^= b;\n        } else if\
    \ (op == 4) {\n            std::cout << (s == ~0ULL ? 1 : 0) << '\\n';\n     \
    \   } else if (op == 5) {\n            std::cout << (s != 0 ? 1 : 0) << '\\n';\n\
    \        } else if (op == 6) {\n            std::cout << (s == 0 ? 1 : 0) << '\\\
    n';\n        } else if (op == 7) {\n            // popcount \u306F\u975E\u8CA0\
    \u306E long long \u3092\u53D7\u3051\u53D6\u308B\u306E\u3067\u3001\u4E0A\u4F4D\
    \ 1 \u30D3\u30C3\u30C8\u3068\u6B8B\u308A\u306B\u5206\u3051\u3066\u6570\u3048\u308B\
    \n            std::cout << popcount(static_cast<long long>(s >> 1)) + static_cast<int>(s\
    \ & 1) << '\\n';\n        } else {\n            std::cout << s << '\\n';\n   \
    \     }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C\"\
    \n\n#include <iostream>\n\n#include \"../../src/utility/bit.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int\
    \ q;\n    std::cin >> q;\n    unsigned long long s = 0;\n    while (q--) {\n \
    \       int op;\n        std::cin >> op;\n        if (op <= 3) {\n           \
    \ int i;\n            std::cin >> i;\n            unsigned long long b = 1ULL\
    \ << i;\n            if (op == 0) std::cout << ((s & b) ? 1 : 0) << '\\n';\n \
    \           if (op == 1) s |= b;\n            if (op == 2) s &= ~b;\n        \
    \    if (op == 3) s ^= b;\n        } else if (op == 4) {\n            std::cout\
    \ << (s == ~0ULL ? 1 : 0) << '\\n';\n        } else if (op == 5) {\n         \
    \   std::cout << (s != 0 ? 1 : 0) << '\\n';\n        } else if (op == 6) {\n \
    \           std::cout << (s == 0 ? 1 : 0) << '\\n';\n        } else if (op ==\
    \ 7) {\n            // popcount \u306F\u975E\u8CA0\u306E long long \u3092\u53D7\
    \u3051\u53D6\u308B\u306E\u3067\u3001\u4E0A\u4F4D 1 \u30D3\u30C3\u30C8\u3068\u6B8B\
    \u308A\u306B\u5206\u3051\u3066\u6570\u3048\u308B\n            std::cout << popcount(static_cast<long\
    \ long>(s >> 1)) + static_cast<int>(s & 1) << '\\n';\n        } else {\n     \
    \       std::cout << s << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/utility/bit.hpp
  isVerificationFile: true
  path: test/aoj/itp2-10-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 03:13:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp2-10-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp2-10-c.test.cpp
- /verify/test/aoj/itp2-10-c.test.cpp.html
title: test/aoj/itp2-10-c.test.cpp
---
