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
  bundledCode: "#line 1 \"test/aoj/itp2/itp2-10-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP2_10_C\"\
    \n\n#include <iostream>\n\n#line 2 \"src/utility/bit.hpp\"\n\n/**\n * @file bit.hpp\n\
    \ * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include <cassert>\n#include\
    \ <string>\n#include <utility>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\
    \u5217\u3092long long\u306B\u3059\u308B\n */\ninline long long btoll(std::string\
    \ s, char one = '1') {\n    long long res = 0;\n    for (char c : s) {\n     \
    \   res <<= 1;\n        if (c == one) ++res;\n    }\n    return res;\n}\n\n#if\
    \ __cplusplus < 202000L\n\n// C++20 \u306E <bit> \u3068\u540C\u3058\u5024\u3092\
    \u8FD4\u3059 (0 \u306E\u3068\u304D\u3082\u540C\u3058)\n\n/**\n * @brief \u7ACB\
    \u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n\
    \ */\ninline constexpr long long popcount(long long a) {\n    assert(a >= 0);\n\
    \    return __builtin_popcountll(static_cast<unsigned long long>(a));\n}\n/**\n\
    \ * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline constexpr long long\
    \ countl_zero(long long a) {\n    assert(a >= 0);\n    return a == 0 ? 64 : __builtin_clzll(static_cast<unsigned\
    \ long long>(a));\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\ninline constexpr long\
    \ long countl_one(long long a) {\n    assert(a >= 0);\n    unsigned long long\
    \ x = ~static_cast<unsigned long long>(a);\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
    }\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_ctzll\n */\ninline constexpr long\
    \ long countr_zero(long long a) {\n    assert(a >= 0);\n    return a == 0 ? 64\
    \ : __builtin_ctzll(static_cast<unsigned long long>(a));\n}\n/**\n * @brief \u53F3\
    \u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\
    \u308B\n */\ninline constexpr long long countr_one(long long a) {\n    assert(a\
    \ >= 0);\n    unsigned long long x = ~static_cast<unsigned long long>(a);\n  \
    \  return x == 0 ? 64 : __builtin_ctzll(x);\n}\n/**\n * @brief \u5024\u3092\u8868\
    \u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u30D3\u30C3\u30C8\u5E45\
    \u3092\u6C42\u3081\u308B\n */\ninline constexpr long long bit_width(long long\
    \ a) {\n    assert(a >= 0);\n    return 64 - countl_zero(a);\n}\n/**\n * @brief\
    \ \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\
    \u308B\n */\ninline constexpr long long bit_ceil(long long a) {\n    assert(0\
    \ <= a && a <= (1LL << 62));\n    return a <= 1 ? 1 : 1LL << bit_width(a - 1);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0B\u3052\u308B\n */\ninline constexpr long long bit_floor(long long\
    \ a) {\n    assert(a >= 0);\n    return a == 0 ? 0 : 1LL << (bit_width(a) - 1);\n\
    }\n/**\n * @brief 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069 1 \u3064\
    \u306E\u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n */\ninline\
    \ constexpr bool has_single_bit(long long a) {\n    assert(a >= 0);\n    return\
    \ a != 0 && (a & (a - 1)) == 0;\n}\n\n#else\n\n#include <bit>\n#define BIT_FUNC_EXPAND(func)\
    \                                 \\\n    inline constexpr long long func(long\
    \ long a) {            \\\n        assert(a >= 0);                           \
    \            \\\n        return std::func(static_cast<unsigned long long>(a));\
    \ \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(popcount)\n/**\n * @brief \u5DE6\
    \u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\
    \u308B\n */\nBIT_FUNC_EXPAND(countl_zero)\n/**\n * @brief \u5DE6\u304B\u3089\u9023\
    \u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countl_one)\n\
    /**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\nBIT_FUNC_EXPAND(countr_zero)\n/**\n * @brief \u53F3\
    \u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\
    \u308B\n */\nBIT_FUNC_EXPAND(countr_one)\n/**\n * @brief \u6574\u6570\u5024\u3092\
    2\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\u4E0A\u3052\u308B\n */\ninline constexpr\
    \ long long bit_ceil(long long a) {\n    // \u7D50\u679C\u304C long long \u306B\
    \u53CE\u307E\u308B\u7BC4\u56F2\u306B\u9650\u308B\n    assert(0 <= a && a <= (1LL\
    \ << 62));\n    return std::bit_ceil(static_cast<unsigned long long>(a));\n}\n\
    /**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\u308A\
    \u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n/**\n * @brief \u5024\u3092\
    \u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\u30D3\u30C3\u30C8\
    \u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n/**\n * @brief\
    \ 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069 1 \u3064\u306E\u30D3\u30C3\
    \u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n */\ninline constexpr bool\
    \ has_single_bit(long long a) {\n    assert(a >= 0);\n    return std::has_single_bit(static_cast<unsigned\
    \ long long>(a));\n}\n\n#endif\n\n/**\n * @brief 2 \u3064\u306E\u6574\u6570\u306E\
    \u30CF\u30DF\u30F3\u30B0\u8DDD\u96E2 (\u30D3\u30C3\u30C8\u304C\u7570\u306A\u308B\
    \u4F4D\u7F6E\u306E\u6570)\n */\ninline constexpr long long hamming_distance(long\
    \ long a, long long b) {\n    assert(a >= 0 && b >= 0);\n    return popcount(a\
    \ ^ b);\n}\n\n/**\n * @brief \u6700\u4E0A\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\
    \u30D3\u30C3\u30C8\u306E\u4F4D\u7F6E (0 \u306A\u3089 -1)\n */\ninline constexpr\
    \ long long msb(long long a) { return bit_width(a) - 1; }\n/**\n * @brief \u6700\
    \u4E0B\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u4F4D\
    \u7F6E (0 \u306A\u3089 -1)\n */\ninline constexpr long long lsb(long long a) {\n\
    \    assert(a >= 0);\n    return a == 0 ? -1 : countr_zero(a);\n}\n/**\n * @brief\
    \ \u6700\u4E0B\u4F4D\u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3060\
    \u3051\u3092\u6B8B\u3057\u305F\u5024 a & -a (0 \u306A\u3089 0)\n */\ninline constexpr\
    \ long long lowbit(long long a) {\n    assert(a >= 0);\n    return a & -a;\n}\n\
    /**\n * @brief a \u306E i \u30D3\u30C3\u30C8\u76EE\u304C\u7ACB\u3063\u3066\u3044\
    \u308B\u304B\n */\ninline constexpr bool test_bit(long long a, long long i) {\n\
    \    assert(a >= 0 && 0 <= i && i < 63);\n    return a >> i & 1;\n}\n/**\n * @brief\
    \ a \u306E i \u30D3\u30C3\u30C8\u76EE\u3092 1 \u306B\u3057\u305F\u5024\n */\n\
    inline constexpr long long set_bit(long long a, long long i) {\n    assert(a >=\
    \ 0 && 0 <= i && i < 63);\n    return a | 1LL << i;\n}\n/**\n * @brief a \u306E\
    \ i \u30D3\u30C3\u30C8\u76EE\u3092 0 \u306B\u3057\u305F\u5024\n */\ninline constexpr\
    \ long long reset_bit(long long a, long long i) {\n    assert(a >= 0 && 0 <= i\
    \ && i < 63);\n    return a & ~(1LL << i);\n}\n/**\n * @brief a \u306E i \u30D3\
    \u30C3\u30C8\u76EE\u3092\u53CD\u8EE2\u3057\u305F\u5024\n */\ninline constexpr\
    \ long long flip_bit(long long a, long long i) {\n    assert(a >= 0 && 0 <= i\
    \ && i < 63);\n    return a ^ 1LL << i;\n}\n/**\n * @brief \u7ACB\u3063\u3066\u3044\
    \u308B\u30D3\u30C3\u30C8\u306E\u6570\u306E\u5076\u5947 (popcount(a) % 2)\n */\n\
    inline constexpr long long parity(long long a) { return popcount(a) & 1; }\n/**\n\
    \ * @brief long long \u3092 n \u6841\u306E 2 \u9032\u6570\u306E\u6587\u5B57\u5217\
    \u306B\u3059\u308B (btoll \u306E\u9006)\n * n \u3092\u7701\u7565\u3059\u308B\u3068\
    \ bit_width(a) \u6841 (0 \u306A\u3089 \"0\")\n */\ninline std::string lltob(long\
    \ long a, long long n = -1, char one = '1', char zero = '0') {\n    assert(a >=\
    \ 0);\n    if (n < 0) n = a == 0 ? 1 : bit_width(a);\n    assert(n >= bit_width(a));\n\
    \    std::string res(n, zero);\n    for (long long i = 0; i < n && i < 63; i++)\
    \ {\n        if (a >> i & 1) res[n - 1 - i] = one;\n    }\n    return res;\n}\n\
    /**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u306E\u4E26\u3073\u3092\u9006\
    \u306B\u3059\u308B (a < 2^n)\n */\ninline constexpr long long reverse_bits(long\
    \ long a, long long n) {\n    assert(0 <= n && n <= 63 && 0 <= a && bit_width(a)\
    \ <= n);\n    long long res = 0;\n    for (long long i = 0; i < n; i++) {\n  \
    \      if (a >> i & 1) res |= 1LL << (n - 1 - i);\n    }\n    return res;\n}\n\
    /**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u3092\u5DE6\u306B k \u30D3\u30C3\
    \u30C8\u5DE1\u56DE\u30B7\u30D5\u30C8\u3059\u308B (a < 2^n\u3001k \u306F\u8CA0\u3067\
    \u3082\u3088\u3044)\n */\ninline constexpr long long rotate_left(long long a,\
    \ long long k, long long n) {\n    assert(1 <= n && n <= 63 && 0 <= a && bit_width(a)\
    \ <= n);\n    k %= n;\n    if (k < 0) k += n;\n    if (k == 0) return a;\n   \
    \ unsigned long long full = (1ULL << n) - 1;\n    return static_cast<long long>((static_cast<unsigned\
    \ long long>(a) << k & full) | static_cast<unsigned long long>(a) >> (n - k));\n\
    }\n/**\n * @brief \u4E0B\u4F4D n \u30D3\u30C3\u30C8\u3092\u53F3\u306B k \u30D3\
    \u30C3\u30C8\u5DE1\u56DE\u30B7\u30D5\u30C8\u3059\u308B (a < 2^n\u3001k \u306F\u8CA0\
    \u3067\u3082\u3088\u3044)\n */\ninline constexpr long long rotate_right(long long\
    \ a, long long k, long long n) {\n    assert(1 <= n && n <= 63);\n    return rotate_left(a,\
    \ -(k % n), n);\n}\n/**\n * @brief \u30B0\u30EC\u30A4\u30B3\u30FC\u30C9 (\u96A3\
    \u308A\u5408\u3046\u5024\u3067 1 \u30D3\u30C3\u30C8\u3060\u3051\u5909\u308F\u308B\
    ) a ^ (a >> 1)\n */\ninline constexpr long long gray_code(long long a) {\n   \
    \ assert(a >= 0);\n    return a ^ a >> 1;\n}\n/**\n * @brief \u30B0\u30EC\u30A4\
    \u30B3\u30FC\u30C9\u304B\u3089\u5143\u306E\u5024\u306B\u623B\u3059 (gray_code\
    \ \u306E\u9006)\n */\ninline constexpr long long inverse_gray_code(long long g)\
    \ {\n    assert(g >= 0);\n    for (long long s = 1; s < 64; s <<= 1) g ^= g >>\
    \ s;\n    return g;\n}\n/**\n * @brief mask \u306E\u7ACB\u3063\u3066\u3044\u308B\
    \u30D3\u30C3\u30C8\u306E\u3046\u3061\u3001\u4E0B\u304B\u3089 k \u756A\u76EE (0-indexed)\
    \ \u306E\u4F4D\u7F6E O(log 64)\n */\ninline constexpr long long kth_set_bit(long\
    \ long mask, long long k) {\n    assert(mask >= 0 && 0 <= k && k < popcount(mask));\n\
    \    long long res = 0;\n    for (long long w = 32; w > 0; w >>= 1) {\n      \
    \  // \u4E0B\u4F4D w \u30D3\u30C3\u30C8\u306B\u7ACB\u3063\u3066\u3044\u308B\u30D3\
    \u30C3\u30C8\u306E\u6570\u3067\u3001\u7B54\u3048\u304C\u4E0A\u4E0B\u3069\u3061\
    \u3089\u306B\u3042\u308B\u304B\u3092\u6C7A\u3081\u308B\n        long long c =\
    \ popcount(mask & ((1LL << w) - 1));\n        if (k >= c) {\n            k -=\
    \ c;\n            mask >>= w;\n            res += w;\n        }\n    }\n    return\
    \ res;\n}\n/**\n * @brief 0 ^ 1 ^ ... ^ n\n */\ninline constexpr long long xor_upto(long\
    \ long n) {\n    assert(n >= 0);\n    // 4 \u3064\u3054\u3068\u306B\u5468\u671F\
    \u7684\u306B\u306A\u308B\n    long long r = n & 3;\n    // r \u3054\u3068\u306E\
    \u5024\u306E\u8868\u3068\u3057\u3066\u8AAD\u3081\u308B\u3088\u3046\u306B 1 \u884C\
    \u3067\u66F8\u3044\u3066\u3044\u308B\u306E\u3067\u6574\u5F62\u3057\u306A\u3044\
    \n    // clang-format off\n    return r == 0 ? n : r == 1 ? 1 : r == 2 ? n + 1\
    \ : 0;\n    // clang-format on\n}\n/**\n * @brief 0 \u4EE5\u4E0A n \u4EE5\u4E0B\
    \u306E\u6574\u6570\u306E\u3046\u3061\u3001i \u30D3\u30C3\u30C8\u76EE\u304C\u7ACB\
    \u3063\u3066\u3044\u308B\u3082\u306E\u306E\u6570\n */\ninline constexpr long long\
    \ count_bit_upto(long long n, long long i) {\n    assert(0 <= n && n < 0x7fffffffffffffffLL\
    \ && 0 <= i && i < 63);\n    // 2^(i + 1) \u3054\u3068\u306B\u3001\u5F8C\u534A\
    \u306E 2^i \u500B\u3067\u7ACB\u3064\n    unsigned long long m = static_cast<unsigned\
    \ long long>(n) + 1, half = 1ULL << i, cycle = half << 1;\n    unsigned long long\
    \ r = m % cycle;\n    return static_cast<long long>(m / cycle * half + (r > half\
    \ ? r - half : 0));\n}\n\nnamespace internal_bit {\n// \u7BC4\u56F2 for \u3067\
    \u4F7F\u3046\u5217\u6319\u3002next \u3067\u6B21\u306E\u5024\u306B\u9032\u307F\u3001\
    done \u306B\u306A\u3063\u305F\u3089\u7D42\u308F\u308B\ntemplate <class Next>\n\
    struct BitEnumeration {\n    long long first;\n    bool empty;\n    Next next;\
    \  // next(s) \u306F\u6B21\u306E\u5024\u3001\u7D42\u308F\u308A\u306A\u3089 -1\n\
    \    struct iterator {\n        long long s;\n        const Next* next;\n    \
    \    constexpr long long operator*() const { return s; }\n        constexpr iterator&\
    \ operator++() {\n            s = (*next)(s);\n            return *this;\n   \
    \     }\n        constexpr bool operator!=(const iterator& other) const { return\
    \ s != other.s; }\n        constexpr bool operator==(const iterator& other) const\
    \ { return s == other.s; }\n    };\n    constexpr iterator begin() const { return\
    \ {empty ? -1 : first, &next}; }\n    constexpr iterator end() const { return\
    \ {-1, &next}; }\n};\ntemplate <class Next>\nconstexpr BitEnumeration<Next> make_bit_enumeration(long\
    \ long first, bool empty, Next next) {\n    return {first, empty, next};\n}\n\
    }  // namespace internal_bit\n\n/**\n * @brief mask \u306E\u90E8\u5206\u96C6\u5408\
    \u3092 mask \u304B\u3089 0 \u307E\u3067\u964D\u9806\u306B\u5217\u6319\u3059\u308B\
    \ (0 \u3068 mask \u3092\u542B\u3080) \u5168\u4F53\u3067 O(2^popcount(mask))\n\
    \ */\ninline constexpr auto subsets(long long mask) {\n    assert(mask >= 0);\n\
    \    return internal_bit::make_bit_enumeration(mask, false, [mask](long long s)\
    \ { return s == 0 ? -1 : (s - 1) & mask; });\n}\n/**\n * @brief n \u30D3\u30C3\
    \u30C8\u306E\u96C6\u5408\u306E\u3046\u3061 mask \u3092\u542B\u3080\u3082\u306E\
    \u3092 mask \u304B\u3089\u6607\u9806\u306B\u5217\u6319\u3059\u308B (mask \u3068\
    \ 2^n - 1 \u3092\u542B\u3080) \u5168\u4F53\u3067 O(2^(n - popcount(mask)))\n */\n\
    inline constexpr auto supersets(long long mask, long long n) {\n    assert(0 <=\
    \ n && n <= 62 && 0 <= mask && mask < (1LL << n));\n    long long full = (1LL\
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
    \ }\n    };\n    return Bits{mask};\n}\n/**\n * @brief s \u3068\u7ACB\u3063\u3066\
    \u3044\u308B\u30D3\u30C3\u30C8\u306E\u6570\u304C\u540C\u3058\u3067\u3001s \u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u5024 (Gosper's hack)\n * long long\
    \ \u306B\u53CE\u307E\u3089\u306A\u3051\u308C\u3070 -1\n */\ninline constexpr long\
    \ long next_combination_mask(long long s) {\n    assert(s > 0);\n    unsigned\
    \ long long u = s, c = u & -u, r = u + c;\n    unsigned long long t = (((r ^ u)\
    \ >> 2) / c) | r;\n    return t > 0x7fffffffffffffffULL ? -1 : static_cast<long\
    \ long>(t);\n}\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\u96C6\u5408\u306E\u3046\
    \u3061\u3001\u3061\u3087\u3046\u3069 k \u500B\u306E\u30D3\u30C3\u30C8\u304C\u7ACB\
    \u3064\u3082\u306E\u3092\u6607\u9806\u306B\u5217\u6319\u3059\u308B (Gosper's hack)\
    \ \u5168\u4F53\u3067 O(C(n, k))\n * k > n \u306A\u3089\u4F55\u3082\u5217\u6319\
    \u3057\u306A\u3044\n */\ninline constexpr auto combinations_mask(long long n,\
    \ long long k) {\n    assert(0 <= n && n <= 62 && 0 <= k);\n    long long limit\
    \ = 1LL << n;\n    return internal_bit::make_bit_enumeration(k > n ? -1 : (1LL\
    \ << k) - 1, k > n, [limit](long long s) {\n        if (s == 0) return -1LL; \
    \ // k = 0 \u306E\u3068\u304D\u306F 0 \u3060\u3051\n        long long t = next_combination_mask(s);\n\
    \        return t >= limit ? -1 : t;\n    });\n}\n/**\n * @brief mask \u306E\u90E8\
    \u5206\u96C6\u5408\u306E\u3046\u3061\u3001\u3061\u3087\u3046\u3069 k \u500B\u306E\
    \u30D3\u30C3\u30C8\u304C\u7ACB\u3064\u3082\u306E\u3092\u6607\u9806\u306B\u5217\
    \u6319\u3059\u308B 1 \u3064\u3042\u305F\u308A O(k)\n * k > popcount(mask) \u306A\
    \u3089\u4F55\u3082\u5217\u6319\u3057\u306A\u3044\n */\ninline constexpr auto subsets_of_size(long\
    \ long mask, long long k) {\n    assert(mask >= 0 && 0 <= k);\n    // mask \u306E\
    \u4E0B\u4F4D cnt \u500B\u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\n\
    \    auto lowest = [mask](long long cnt) {\n        long long res = 0, rest =\
    \ mask;\n        for (long long j = 0; j < cnt; j++) {\n            res |= rest\
    \ & -rest;\n            rest &= rest - 1;\n        }\n        return res;\n  \
    \  };\n    bool empty = k > popcount(mask);\n    return internal_bit::make_bit_enumeration(empty\
    \ ? -1 : lowest(k), empty, [mask, k, lowest](long long s) {\n        if (s ==\
    \ 0) return -1LL;  // k = 0 \u306E\u3068\u304D\u306F 0 \u3060\u3051\n        //\
    \ mask \u306E\u5916\u306E\u30D3\u30C3\u30C8\u3092 1 \u3068\u307F\u306A\u3057\u3066\
    \u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u3092\u8DB3\u3059\u3068\u3001\u7E70\u308A\
    \u4E0A\u304C\u308A\u304C mask \u306E\u4E2D\u3060\u3051\u3092\u9032\u3080\n   \
    \     unsigned long long c = s & -s, r = ((static_cast<unsigned long long>(s)\
    \ | ~static_cast<unsigned long long>(mask)) + c) & static_cast<unsigned long long>(mask);\n\
    \        if (r == 0) return -1LL;  // \u7E70\u308A\u4E0A\u304C\u308A\u304C mask\
    \ \u306E\u6700\u4E0A\u4F4D\u3092\u8D8A\u3048\u305F\n        // \u7E70\u308A\u4E0A\
    \u304C\u308A\u3067\u6D88\u3048\u305F\u30D3\u30C3\u30C8\u3092 mask \u306E\u4E0B\
    \u4F4D\u306B\u8A70\u3081\u76F4\u3059\n        return static_cast<long long>(r)\
    \ | lowest(k - popcount(static_cast<long long>(r)));\n    });\n}\n\nnamespace\
    \ internal_bit {\n// rest \u306E\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\
    \ i \u3092\u6607\u9806\u306B\u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\
    \u6319\u3059\u308B\nstruct ToggleOneBit {\n    long long mask, rest;\n    struct\
    \ iterator {\n        long long mask, s;\n        constexpr std::pair<long long,\
    \ long long> operator*() const {\n            long long i = countr_zero(s);\n\
    \            return {i, mask ^ (1LL << i)};\n        }\n        constexpr iterator&\
    \ operator++() {\n            s &= s - 1;\n            return *this;\n       \
    \ }\n        constexpr bool operator!=(const iterator& other) const { return s\
    \ != other.s; }\n        constexpr bool operator==(const iterator& other) const\
    \ { return s == other.s; }\n    };\n    constexpr iterator begin() const { return\
    \ {mask, rest}; }\n    constexpr iterator end() const { return {mask, 0}; }\n\
    };\n}  // namespace internal_bit\n\n/**\n * @brief n \u30D3\u30C3\u30C8\u306E\u3046\
    \u3061 mask \u306B\u542B\u307E\u308C\u306A\u3044\u4F4D\u7F6E i \u3092\u6607\u9806\
    \u306B\u3001(i, mask | (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\
    \u4F53\u3067 O(n - popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\
    \u8DB3\u3059\u9077\u79FB\u306B\u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit\
    \ add_one(long long mask, long long n) {\n    assert(0 <= n && n <= 62 && 0 <=\
    \ mask && mask < (1LL << n));\n    return {mask, ((1LL << n) - 1) ^ mask};\n}\n\
    /**\n * @brief mask \u306B\u542B\u307E\u308C\u308B\u4F4D\u7F6E i \u3092\u6607\u9806\
    \u306B\u3001(i, mask ^ (1 << i)) \u306E\u7D44\u3067\u5217\u6319\u3059\u308B \u5168\
    \u4F53\u3067 O(popcount(mask))\n * bit DP \u3067 1 \u3064\u8981\u7D20\u3092\u9664\
    \u3044\u305F\u96C6\u5408\u304B\u3089\u9077\u79FB\u3059\u308B\u3068\u304D\u306B\
    \u4F7F\u3046\n */\ninline constexpr internal_bit::ToggleOneBit remove_one(long\
    \ long mask) {\n    assert(mask >= 0);\n    return {mask, mask};\n}\n\n/**\n *\
    \ @brief n \u30D3\u30C3\u30C8\u306E\u3059\u3079\u3066\u306E\u96C6\u5408 S \u3068\
    \u3001\u305D\u306E\u90E8\u5206\u96C6\u5408 T \u306E\u7D44 (S, T) \u3092\u5217\u6319\
    \u3059\u308B \u5168\u4F53\u3067 O(3^n)\n * S \u306F 0 \u304B\u3089\u6607\u9806\
    \u3001\u5404 S \u306E\u4E2D\u3067 T \u306F S \u304B\u3089 0 \u307E\u3067\u964D\
    \u9806\n */\ninline constexpr auto subset_pairs(long long n) {\n    assert(0 <=\
    \ n && n <= 62);\n    struct SubsetPairs {\n        long long n;\n        struct\
    \ iterator {\n            long long s, t;\n            constexpr std::pair<long\
    \ long, long long> operator*() const { return {s, t}; }\n            constexpr\
    \ iterator& operator++() {\n                if (t == 0) {\n                  \
    \  t = ++s;\n                } else {\n                    t = (t - 1) & s;\n\
    \                }\n                return *this;\n            }\n           \
    \ constexpr bool operator!=(const iterator& other) const { return s != other.s\
    \ || t != other.t; }\n            constexpr bool operator==(const iterator& other)\
    \ const { return s == other.s && t == other.t; }\n        };\n        constexpr\
    \ iterator begin() const { return {0, 0}; }\n        constexpr iterator end()\
    \ const { return {1LL << n, 1LL << n}; }\n    };\n    return SubsetPairs{n};\n\
    }\n#line 6 \"test/aoj/itp2/itp2-10-c.test.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
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
    \n\n#include <iostream>\n\n#include \"../../../src/utility/bit.hpp\"\n\nint main()\
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
  path: test/aoj/itp2/itp2-10-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:37:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp2/itp2-10-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp2/itp2-10-c.test.cpp
- /verify/test/aoj/itp2/itp2-10-c.test.cpp.html
title: test/aoj/itp2/itp2-10-c.test.cpp
---
