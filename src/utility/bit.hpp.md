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
    #include <utility>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092\
    long long\u306B\u3059\u308B\n */\ninline long long btoll(std::string s, char one\
    \ = '1') {\n    long long res = 0;\n    for (char c : s) {\n        res <<= 1;\n\
    \        if (c == one) ++res;\n    }\n    return res;\n}\n\n#if __cplusplus <\
    \ 202000L\n\n// C++20 \u306E <bit> \u3068\u540C\u3058\u5024\u3092\u8FD4\u3059\
    \ (0 \u306E\u3068\u304D\u3082\u540C\u3058)\n\n/**\n * @brief \u7ACB\u3063\u3066\
    \u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n\
    \ */\ninline constexpr long long popcount(long long a) {\n    assert(a >= 0);\n\
    \    return __builtin_popcountll((unsigned long long)a);\n}\n/**\n * @brief \u5DE6\
    \u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\
    \u308B\n * __builtin_clzll\n */\ninline constexpr long long countl_zero(long long\
    \ a) {\n    assert(a >= 0);\n    return a == 0 ? 64 : __builtin_clzll((unsigned\
    \ long long)a);\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\ninline constexpr long\
    \ long countl_one(long long a) {\n    assert(a >= 0);\n    unsigned long long\
    \ x = ~(unsigned long long)a;\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
    }\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline constexpr long\
    \ long countr_zero(long long a) {\n    assert(a >= 0);\n    return a == 0 ? 64\
    \ : __builtin_ctzll((unsigned long long)a);\n}\n/**\n * @brief \u53F3\u304B\u3089\
    \u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\n\
    inline constexpr long long countr_one(long long a) {\n    assert(a >= 0);\n  \
    \  unsigned long long x = ~(unsigned long long)a;\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n/**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\
    \u8981\u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\ninline constexpr\
    \ long long bit_width(long long a) {\n    assert(a >= 0);\n    return 64 - countl_zero(a);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0A\u3052\u308B\n */\ninline constexpr long long bit_ceil(long long a)\
    \ {\n    assert(0 <= a && a <= (1LL << 62));\n    return a <= 1 ? 1 : 1LL << bit_width(a\
    \ - 1);\n}\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\
    \u5207\u308A\u4E0B\u3052\u308B\n */\ninline constexpr long long bit_floor(long\
    \ long a) {\n    assert(a >= 0);\n    return a == 0 ? 0 : 1LL << (bit_width(a)\
    \ - 1);\n}\n\n#else\n\n#include <bit>\n#define BIT_FUNC_EXPAND(func)         \
    \             \\\n    inline constexpr long long func(long long a) { \\\n    \
    \    assert(a >= 0);                            \\\n        return std::func((unsigned\
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
    \n */\ninline constexpr long long bit_ceil(long long a) {\n    // \u7D50\u679C\
    \u304C long long \u306B\u53CE\u307E\u308B\u7BC4\u56F2\u306B\u9650\u308B\n    assert(0\
    \ <= a && a <= (1LL << 62));\n    return std::bit_ceil((unsigned long long)a);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n/**\n * @brief \u5024\
    \u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u30D3\u30C3\
    \u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\n#endif\n\
    \n/**\n * @brief 2 \u3064\u306E\u6574\u6570\u306E\u30CF\u30DF\u30F3\u30B0\u8DDD\
    \u96E2 (\u30D3\u30C3\u30C8\u304C\u7570\u306A\u308B\u4F4D\u7F6E\u306E\u6570)\n\
    \ */\ninline constexpr long long hamming_distance(long long a, long long b) {\n\
    \    assert(a >= 0 && b >= 0);\n    return popcount(a ^ b);\n}\n\nnamespace internal_bit\
    \ {\n// \u7BC4\u56F2 for \u3067\u4F7F\u3046\u5217\u6319\u3002next \u3067\u6B21\
    \u306E\u5024\u306B\u9032\u307F\u3001done \u306B\u306A\u3063\u305F\u3089\u7D42\u308F\
    \u308B\ntemplate <class Next>\nstruct BitEnumeration {\n    long long first;\n\
    \    bool empty;\n    Next next;  // next(s) \u306F\u6B21\u306E\u5024\u3001\u7D42\
    \u308F\u308A\u306A\u3089 -1\n    struct iterator {\n        long long s;\n   \
    \     const Next* next;\n        constexpr long long operator*() const { return\
    \ s; }\n        constexpr iterator& operator++() {\n            s = (*next)(s);\n\
    \            return *this;\n        }\n        constexpr bool operator!=(const\
    \ iterator& other) const { return s != other.s; }\n        constexpr bool operator==(const\
    \ iterator& other) const { return s == other.s; }\n    };\n    constexpr iterator\
    \ begin() const { return {empty ? -1 : first, &next}; }\n    constexpr iterator\
    \ end() const { return {-1, &next}; }\n};\ntemplate <class Next>\nconstexpr BitEnumeration<Next>\
    \ make_bit_enumeration(long long first, bool empty, Next next) {\n    return {first,\
    \ empty, next};\n}\n}  // namespace internal_bit\n\n/**\n * @brief mask \u306E\
    \u90E8\u5206\u96C6\u5408\u3092 mask \u304B\u3089 0 \u307E\u3067\u964D\u9806\u306B\
    \u5217\u6319\u3059\u308B (0 \u3068 mask \u3092\u542B\u3080) \u5168\u4F53\u3067\
    \ O(2^popcount(mask))\n */\ninline constexpr auto subsets(long long mask) {\n\
    \    assert(mask >= 0);\n    return internal_bit::make_bit_enumeration(mask, false,\
    \ [mask](long long s) { return s == 0 ? -1 : (s - 1) & mask; });\n}\n/**\n * @brief\
    \ n \u30D3\u30C3\u30C8\u306E\u96C6\u5408\u306E\u3046\u3061 mask \u3092\u542B\u3080\
    \u3082\u306E\u3092 mask \u304B\u3089\u6607\u9806\u306B\u5217\u6319\u3059\u308B\
    \ (mask \u3068 2^n - 1 \u3092\u542B\u3080) \u5168\u4F53\u3067 O(2^(n - popcount(mask)))\n\
    \ */\ninline constexpr auto supersets(long long mask, long long n) {\n    assert(0\
    \ <= n && n <= 62 && 0 <= mask && mask < (1LL << n));\n    long long full = (1LL\
    \ << n) - 1;\n    return internal_bit::make_bit_enumeration(mask, false, [mask,\
    \ full](long long s) { return s == full ? -1 : (s + 1) | mask; });\n}\n/**\n *\
    \ @brief mask \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u4F4D\
    \u7F6E\u3092\u6607\u9806\u306B\u5217\u6319\u3059\u308B \u5168\u4F53\u3067 O(popcount(mask))\n\
    \ */\ninline constexpr auto bits(long long mask) {\n    assert(mask >= 0);\n \
    \   // \u5185\u90E8\u3067\u306F\u6B8B\u308A\u306E\u30D3\u30C3\u30C8\u3092\u6301\
    \u3061\u3001* \u3067\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E\u3092\
    \u8FD4\u3059\n    struct Bits {\n        long long mask;\n        struct iterator\
    \ {\n            long long s;\n            constexpr long long operator*() const\
    \ { return countr_zero(s); }\n            constexpr iterator& operator++() {\n\
    \                s &= s - 1;\n                return *this;\n            }\n \
    \           constexpr bool operator!=(const iterator& other) const { return s\
    \ != other.s; }\n            constexpr bool operator==(const iterator& other)\
    \ const { return s == other.s; }\n        };\n        constexpr iterator begin()\
    \ const { return {mask}; }\n        constexpr iterator end() const { return {0};\
    \ }\n    };\n    return Bits{mask};\n}\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\
    \u96C6\u5408\u306E\u3046\u3061\u3001\u3061\u3087\u3046\u3069 k \u500B\u306E\u30D3\
    \u30C3\u30C8\u304C\u7ACB\u3064\u3082\u306E\u3092\u6607\u9806\u306B\u5217\u6319\
    \u3059\u308B (Gosper's hack) \u5168\u4F53\u3067 O(C(n, k))\n * k > n \u306A\u3089\
    \u4F55\u3082\u5217\u6319\u3057\u306A\u3044\n */\ninline constexpr auto combinations_mask(long\
    \ long n, long long k) {\n    assert(0 <= n && n <= 62 && 0 <= k);\n    long long\
    \ limit = 1LL << n;\n    return internal_bit::make_bit_enumeration(k > n ? -1\
    \ : (1LL << k) - 1, k > n, [limit](long long s) {\n        if (s == 0) return\
    \ -1LL;  // k = 0 \u306E\u3068\u304D\u306F 0 \u3060\u3051\n        long long c\
    \ = s & -s, r = s + c;\n        long long t = (((r ^ s) >> 2) / c) | r;\n    \
    \    return t >= limit ? -1 : t;\n    });\n}\n\nnamespace internal_bit {\n// rest\
    \ \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8 i \u3092\u6607\u9806\u306B\
    \u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B\nstruct\
    \ ToggleOneBit {\n    long long mask, rest;\n    struct iterator {\n        long\
    \ long mask, s;\n        constexpr std::pair<long long, long long> operator*()\
    \ const {\n            long long i = countr_zero(s);\n            return {i, mask\
    \ ^ (1LL << i)};\n        }\n        constexpr iterator& operator++() {\n    \
    \        s &= s - 1;\n            return *this;\n        }\n        constexpr\
    \ bool operator!=(const iterator& other) const { return s != other.s; }\n    \
    \    constexpr bool operator==(const iterator& other) const { return s == other.s;\
    \ }\n    };\n    constexpr iterator begin() const { return {mask, rest}; }\n \
    \   constexpr iterator end() const { return {mask, 0}; }\n};\n}  // namespace\
    \ internal_bit\n\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\u3046\u3061 mask \u306B\
    \u542B\u307E\u308C\u306A\u3044\u4F4D\u7F6E i \u3092\u6607\u9806\u306B\u3001(i,\
    \ mask | (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\u4F53\u3067\
    \ O(n - popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u8DB3\u3059\
    \u9077\u79FB\u306B\u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit\
    \ add_one(long long mask, long long n) {\n    assert(0 <= n && n <= 62 && 0 <=\
    \ mask && mask < (1LL << n));\n    return {mask, ((1LL << n) - 1) ^ mask};\n}\n\
    /**\n * @brief mask \u306B\u542B\u307E\u308C\u308B\u4F4D\u7F6E i \u3092\u6607\u9806\
    \u306B\u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\
    \u4F53\u3067 O(popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u9664\
    \u3044\u305F\u96C6\u5408\u304B\u3089\u9077\u79FB\u3059\u308B\u3068\u304D\u306B\
    \u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit remove_one(long\
    \ long mask) {\n    assert(mask >= 0);\n    return {mask, mask};\n}\n"
  code: "#pragma once\n\n/**\n * @file bit.hpp\n * @brief \u30D3\u30C3\u30C8\u6F14\
    \u7B97\n */\n\n#include <cassert>\n#include <string>\n#include <utility>\n\n/**\n\
    \ * @brief 2\u9032\u6570\u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\u308B\
    \n */\ninline long long btoll(std::string s, char one = '1') {\n    long long\
    \ res = 0;\n    for (char c : s) {\n        res <<= 1;\n        if (c == one)\
    \ ++res;\n    }\n    return res;\n}\n\n#if __cplusplus < 202000L\n\n// C++20 \u306E\
    \ <bit> \u3068\u540C\u3058\u5024\u3092\u8FD4\u3059 (0 \u306E\u3068\u304D\u3082\
    \u540C\u3058)\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n * __builtin_popcountll\n */\ninline constexpr long\
    \ long popcount(long long a) {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned\
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
    \n/**\n * @brief 2 \u3064\u306E\u6574\u6570\u306E\u30CF\u30DF\u30F3\u30B0\u8DDD\
    \u96E2 (\u30D3\u30C3\u30C8\u304C\u7570\u306A\u308B\u4F4D\u7F6E\u306E\u6570)\n\
    \ */\ninline constexpr long long hamming_distance(long long a, long long b) {\n\
    \    assert(a >= 0 && b >= 0);\n    return popcount(a ^ b);\n}\n\nnamespace internal_bit\
    \ {\n// \u7BC4\u56F2 for \u3067\u4F7F\u3046\u5217\u6319\u3002next \u3067\u6B21\
    \u306E\u5024\u306B\u9032\u307F\u3001done \u306B\u306A\u3063\u305F\u3089\u7D42\u308F\
    \u308B\ntemplate <class Next>\nstruct BitEnumeration {\n    long long first;\n\
    \    bool empty;\n    Next next;  // next(s) \u306F\u6B21\u306E\u5024\u3001\u7D42\
    \u308F\u308A\u306A\u3089 -1\n    struct iterator {\n        long long s;\n   \
    \     const Next* next;\n        constexpr long long operator*() const { return\
    \ s; }\n        constexpr iterator& operator++() {\n            s = (*next)(s);\n\
    \            return *this;\n        }\n        constexpr bool operator!=(const\
    \ iterator& other) const { return s != other.s; }\n        constexpr bool operator==(const\
    \ iterator& other) const { return s == other.s; }\n    };\n    constexpr iterator\
    \ begin() const { return {empty ? -1 : first, &next}; }\n    constexpr iterator\
    \ end() const { return {-1, &next}; }\n};\ntemplate <class Next>\nconstexpr BitEnumeration<Next>\
    \ make_bit_enumeration(long long first, bool empty, Next next) {\n    return {first,\
    \ empty, next};\n}\n}  // namespace internal_bit\n\n/**\n * @brief mask \u306E\
    \u90E8\u5206\u96C6\u5408\u3092 mask \u304B\u3089 0 \u307E\u3067\u964D\u9806\u306B\
    \u5217\u6319\u3059\u308B (0 \u3068 mask \u3092\u542B\u3080) \u5168\u4F53\u3067\
    \ O(2^popcount(mask))\n */\ninline constexpr auto subsets(long long mask) {\n\
    \    assert(mask >= 0);\n    return internal_bit::make_bit_enumeration(mask, false,\
    \ [mask](long long s) { return s == 0 ? -1 : (s - 1) & mask; });\n}\n/**\n * @brief\
    \ n \u30D3\u30C3\u30C8\u306E\u96C6\u5408\u306E\u3046\u3061 mask \u3092\u542B\u3080\
    \u3082\u306E\u3092 mask \u304B\u3089\u6607\u9806\u306B\u5217\u6319\u3059\u308B\
    \ (mask \u3068 2^n - 1 \u3092\u542B\u3080) \u5168\u4F53\u3067 O(2^(n - popcount(mask)))\n\
    \ */\ninline constexpr auto supersets(long long mask, long long n) {\n    assert(0\
    \ <= n && n <= 62 && 0 <= mask && mask < (1LL << n));\n    long long full = (1LL\
    \ << n) - 1;\n    return internal_bit::make_bit_enumeration(mask, false, [mask,\
    \ full](long long s) { return s == full ? -1 : (s + 1) | mask; });\n}\n/**\n *\
    \ @brief mask \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u4F4D\
    \u7F6E\u3092\u6607\u9806\u306B\u5217\u6319\u3059\u308B \u5168\u4F53\u3067 O(popcount(mask))\n\
    \ */\ninline constexpr auto bits(long long mask) {\n    assert(mask >= 0);\n \
    \   // \u5185\u90E8\u3067\u306F\u6B8B\u308A\u306E\u30D3\u30C3\u30C8\u3092\u6301\
    \u3061\u3001* \u3067\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E\u3092\
    \u8FD4\u3059\n    struct Bits {\n        long long mask;\n        struct iterator\
    \ {\n            long long s;\n            constexpr long long operator*() const\
    \ { return countr_zero(s); }\n            constexpr iterator& operator++() {\n\
    \                s &= s - 1;\n                return *this;\n            }\n \
    \           constexpr bool operator!=(const iterator& other) const { return s\
    \ != other.s; }\n            constexpr bool operator==(const iterator& other)\
    \ const { return s == other.s; }\n        };\n        constexpr iterator begin()\
    \ const { return {mask}; }\n        constexpr iterator end() const { return {0};\
    \ }\n    };\n    return Bits{mask};\n}\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\
    \u96C6\u5408\u306E\u3046\u3061\u3001\u3061\u3087\u3046\u3069 k \u500B\u306E\u30D3\
    \u30C3\u30C8\u304C\u7ACB\u3064\u3082\u306E\u3092\u6607\u9806\u306B\u5217\u6319\
    \u3059\u308B (Gosper's hack) \u5168\u4F53\u3067 O(C(n, k))\n * k > n \u306A\u3089\
    \u4F55\u3082\u5217\u6319\u3057\u306A\u3044\n */\ninline constexpr auto combinations_mask(long\
    \ long n, long long k) {\n    assert(0 <= n && n <= 62 && 0 <= k);\n    long long\
    \ limit = 1LL << n;\n    return internal_bit::make_bit_enumeration(k > n ? -1\
    \ : (1LL << k) - 1, k > n, [limit](long long s) {\n        if (s == 0) return\
    \ -1LL;  // k = 0 \u306E\u3068\u304D\u306F 0 \u3060\u3051\n        long long c\
    \ = s & -s, r = s + c;\n        long long t = (((r ^ s) >> 2) / c) | r;\n    \
    \    return t >= limit ? -1 : t;\n    });\n}\n\nnamespace internal_bit {\n// rest\
    \ \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8 i \u3092\u6607\u9806\u306B\
    \u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B\nstruct\
    \ ToggleOneBit {\n    long long mask, rest;\n    struct iterator {\n        long\
    \ long mask, s;\n        constexpr std::pair<long long, long long> operator*()\
    \ const {\n            long long i = countr_zero(s);\n            return {i, mask\
    \ ^ (1LL << i)};\n        }\n        constexpr iterator& operator++() {\n    \
    \        s &= s - 1;\n            return *this;\n        }\n        constexpr\
    \ bool operator!=(const iterator& other) const { return s != other.s; }\n    \
    \    constexpr bool operator==(const iterator& other) const { return s == other.s;\
    \ }\n    };\n    constexpr iterator begin() const { return {mask, rest}; }\n \
    \   constexpr iterator end() const { return {mask, 0}; }\n};\n}  // namespace\
    \ internal_bit\n\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\u3046\u3061 mask \u306B\
    \u542B\u307E\u308C\u306A\u3044\u4F4D\u7F6E i \u3092\u6607\u9806\u306B\u3001(i,\
    \ mask | (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\u4F53\u3067\
    \ O(n - popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u8DB3\u3059\
    \u9077\u79FB\u306B\u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit\
    \ add_one(long long mask, long long n) {\n    assert(0 <= n && n <= 62 && 0 <=\
    \ mask && mask < (1LL << n));\n    return {mask, ((1LL << n) - 1) ^ mask};\n}\n\
    /**\n * @brief mask \u306B\u542B\u307E\u308C\u308B\u4F4D\u7F6E i \u3092\u6607\u9806\
    \u306B\u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\
    \u4F53\u3067 O(popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u9664\
    \u3044\u305F\u96C6\u5408\u304B\u3089\u9077\u79FB\u3059\u308B\u3068\u304D\u306B\
    \u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit remove_one(long\
    \ long mask) {\n    assert(mask >= 0);\n    return {mask, mask};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/bit.hpp
  requiredBy: []
  timestamp: '2026-10-18 18:08:50+09:00'
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
hamming_distance(5, 3);  // 2 (101 と 011)
for (long long s : subsets(0b101)) { }       // 5, 4, 1, 0
for (long long i : bits(0b10110)) { }        // 1, 2, 4
for (long long s : combinations_mask(4, 2)) { }  // 3, 5, 6, 9, 10, 12
```

## 関数

戻り値はどれも `long long` です。C++17 では `__builtin_*` で実装し、C++20 では `<bit>` の `std::` 版を呼びます。どちらでも同じ値を返し、0 を渡したときも C++20 の `std::` 版と同じです (`countl_zero(0)` と `countr_zero(0)` は 64、`bit_width(0)` は 0、`bit_ceil(0)` は 1、`bit_floor(0)` は 0)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `btoll(s, one = '1')` | 2 進数の文字列を `long long` にする。文字 `one` を 1、それ以外を 0 とみなす | $O(\lvert s \rvert)$ |
| `popcount(a)` | 立っているビットの数 | $O(1)$ |
| `countl_zero(a)` | 上位 (64 ビット中) から連続する 0 の数 | $O(1)$ |
| `countr_zero(a)` | 下位から連続する 0 の数 | $O(1)$ |
| `countl_one(a)` | 上位から連続する 1 の数 (`a` は 0 以上なので常に 0) | $O(1)$ |
| `countr_one(a)` | 下位から連続する 1 の数 | $O(1)$ |
| `bit_ceil(a)` | `a` 以上の最小の 2 の累乗 (`a` は $2^{62}$ 以下) | $O(1)$ |
| `bit_floor(a)` | `a` 以下の最大の 2 の累乗 | $O(1)$ |
| `bit_width(a)` | `a` を表すのに必要なビット数 | $O(1)$ |
| `hamming_distance(a, b)` | `a` と `b` でビットが異なる位置の数 (`popcount(a ^ b)`) | $O(1)$ |

## 列挙

範囲 for で使える列挙です。値はどれも `long long` で、`constexpr` の中でも使えます。

| 関数 | 列挙するもの | 計算量 (全体) |
|---|---|---|
| `subsets(mask)` | `mask` の部分集合を `mask` から 0 まで降順に (0 と `mask` を含む) | $O(2^{\mathrm{popcount}(mask)})$ |
| `supersets(mask, n)` | $n$ ビットの集合のうち `mask` を含むものを `mask` から昇順に ($2^n - 1$ を含む)。$n \le 62$ | $O(2^{n - \mathrm{popcount}(mask)})$ |
| `bits(mask)` | `mask` の立っているビットの位置を昇順に | $O(\mathrm{popcount}(mask))$ |
| `add_one(mask, n)` | $n$ ビットのうち `mask` に含まれない位置 $i$ を昇順に、$i$ と `mask | 1 << i` の組 (`std::pair<long long, long long>`) で | $O(n - \mathrm{popcount}(mask))$ |
| `remove_one(mask)` | `mask` に含まれる位置 $i$ を昇順に、$i$ と `mask ^ 1 << i` の組 (`std::pair<long long, long long>`) で | $O(\mathrm{popcount}(mask))$ |
| `combinations_mask(n, k)` | $n$ ビットの集合のうち、ちょうど $k$ 個のビットが立つものを昇順に (Gosper's hack)。$n \le 62$、$k > n$ なら何も列挙しない | $O(\binom{n}{k})$ |

`add_one` と `remove_one` は、構造化束縛で位置と集合を受け取れます。巡回セールスマン問題のように、1 つずつ要素を足していく bit DP の遷移に使えます。

```cpp
// dp[S][v] = S を訪れて v にいるときの最小コスト (配る DP)
for (long long S = 0; S < (1LL << n); S++) {
    for (long long v : bits(S)) {
        for (auto [i, T] : add_one(S, n)) chmin(dp[T][i], dp[S][v] + dist[v][i]);
    }
}
```

すべての集合について部分集合を列挙すると、全体で $O(3^n)$ です。

```cpp
// dp[S] = S を 2 つに分けたときの最小値
for (long long S = 0; S < (1LL << n); S++) {
    for (long long T : subsets(S)) chmin(dp[S], cost[T] + cost[S ^ T]);
}
```

## 関連

- 部分集合・上位集合についての和を $O(n 2^n)$ で求めるには [部分集合・上位集合のゼータ変換、メビウス変換とビット演算の畳み込み](../math/bitwise-transform.hpp)

- 文字列や配列のハミング距離は [文字列アルゴリズム](../string/string.hpp) の `hamming_distance`
- 2 進数以外の桁への変換は [vector に対する演算子と関数](vector_func.hpp) の `radix_convert`
