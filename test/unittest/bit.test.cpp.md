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
    \n\n// bit.hpp \u306E\u95A2\u6570\u3068\u5217\u6319\u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// C++17 (__builtin_*\
    \ \u3067\u5B9F\u88C5) \u3068 C++20 (<bit> \u3092\u547C\u3076) \u306E\u3069\u3061\
    \u3089\u3067\u3082\u540C\u3058\u7D50\u679C\u306B\u306A\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/bit.hpp\"\
    \n\n/**\n * @file bit.hpp\n * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include\
    \ <cassert>\n#include <string>\n#include <utility>\n\n/**\n * @brief 2\u9032\u6570\
    \u306E\u6587\u5B57\u5217\u3092long long\u306B\u3059\u308B\n */\ninline long long\
    \ btoll(std::string s, char one = '1') {\n    long long res = 0;\n    for (char\
    \ c : s) {\n        res <<= 1;\n        if (c == one) ++res;\n    }\n    return\
    \ res;\n}\n\n#if __cplusplus < 202000L\n\n// C++20 \u306E <bit> \u3068\u540C\u3058\
    \u5024\u3092\u8FD4\u3059 (0 \u306E\u3068\u304D\u3082\u540C\u3058)\n\n/**\n * @brief\
    \ \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n *\
    \ __builtin_popcountll\n */\ninline constexpr long long popcount(long long a)\
    \ {\n    assert(a >= 0);\n    return __builtin_popcountll(static_cast<unsigned\
    \ long long>(a));\n}\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F\
    0\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline\
    \ constexpr long long countl_zero(long long a) {\n    assert(a >= 0);\n    return\
    \ a == 0 ? 64 : __builtin_clzll(static_cast<unsigned long long>(a));\n}\n/**\n\
    \ * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\
    \u3092\u6570\u3048\u308B\n */\ninline constexpr long long countl_one(long long\
    \ a) {\n    assert(a >= 0);\n    unsigned long long x = ~static_cast<unsigned\
    \ long long>(a);\n    return x == 0 ? 64 : __builtin_clzll(x);\n}\n/**\n * @brief\
    \ \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\u30C8\u3092\u6570\
    \u3048\u308B\n * __builtin_ctzll\n */\ninline constexpr long long countr_zero(long\
    \ long a) {\n    assert(a >= 0);\n    return a == 0 ? 64 : __builtin_ctzll(static_cast<unsigned\
    \ long long>(a));\n}\n/**\n * @brief \u53F3\u304B\u3089\u9023\u7D9A\u3057\u305F\
    1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\ninline constexpr long\
    \ long countr_one(long long a) {\n    assert(a >= 0);\n    unsigned long long\
    \ x = ~static_cast<unsigned long long>(a);\n    return x == 0 ? 64 : __builtin_ctzll(x);\n\
    }\n/**\n * @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\
    \u8981\u306A\u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\ninline constexpr\
    \ long long bit_width(long long a) {\n    assert(a >= 0);\n    return 64 - countl_zero(a);\n\
    }\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\u5207\
    \u308A\u4E0A\u3052\u308B\n */\ninline constexpr long long bit_ceil(long long a)\
    \ {\n    assert(0 <= a && a <= (1LL << 62));\n    return a <= 1 ? 1 : 1LL << bit_width(a\
    \ - 1);\n}\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\u306B\
    \u5207\u308A\u4E0B\u3052\u308B\n */\ninline constexpr long long bit_floor(long\
    \ long a) {\n    assert(a >= 0);\n    return a == 0 ? 0 : 1LL << (bit_width(a)\
    \ - 1);\n}\n/**\n * @brief 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069\
    \ 1 \u3064\u306E\u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n\
    \ */\ninline constexpr bool has_single_bit(long long a) {\n    assert(a >= 0);\n\
    \    return a != 0 && (a & (a - 1)) == 0;\n}\n\n#else\n\n#include <bit>\n#define\
    \ BIT_FUNC_EXPAND(func)                                 \\\n    inline constexpr\
    \ long long func(long long a) {            \\\n        assert(a >= 0);       \
    \                                \\\n        return std::func(static_cast<unsigned\
    \ long long>(a)); \\\n    }\n\n/**\n * @brief \u7ACB\u3063\u3066\u3044\u308B\u30D3\
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
    \ <= a && a <= (1LL << 62));\n    return std::bit_ceil(static_cast<unsigned long\
    \ long>(a));\n}\n/**\n * @brief \u6574\u6570\u5024\u30922\u306E\u7D2F\u4E57\u5024\
    \u306B\u5207\u308A\u4E0B\u3052\u308B\n */\nBIT_FUNC_EXPAND(bit_floor)\n/**\n *\
    \ @brief \u5024\u3092\u8868\u73FE\u3059\u308B\u305F\u3081\u306B\u5FC5\u8981\u306A\
    \u30D3\u30C3\u30C8\u5E45\u3092\u6C42\u3081\u308B\n */\nBIT_FUNC_EXPAND(bit_width)\n\
    /**\n * @brief 2 \u306E\u7D2F\u4E57\u304B (\u3061\u3087\u3046\u3069 1 \u3064\u306E\
    \u30D3\u30C3\u30C8\u304C\u7ACB\u3063\u3066\u3044\u308B\u304B)\n */\ninline constexpr\
    \ bool has_single_bit(long long a) {\n    assert(a >= 0);\n    return std::has_single_bit(static_cast<unsigned\
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
    }\n#line 8 \"test/unittest/bit.test.cpp\"\n\n#include <algorithm>\n#include <iostream>\n\
    #include <limits>\n#include <random>\n#line 14 \"test/unittest/bit.test.cpp\"\n\
    #include <type_traits>\n#line 16 \"test/unittest/bit.test.cpp\"\n#include <vector>\n\
    \nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond)\
    \ {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n       \
    \ ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\n   \
    \ for (int rep = 0; rep < 100000 && ok; rep++) {\n        // 0 \u4EE5\u4E0A\u306E\
    \ long long (\u30D3\u30C3\u30C8\u6570\u3082\u3070\u3089\u3064\u304B\u305B\u308B\
    )\n        int width = rng() % 63 + 1;\n        long long a = static_cast<long\
    \ long>(rng() >> (64 - width));\n\n        int pc = 0, clz = 0, ctz = 0;\n   \
    \     for (int i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int i = 63;\
    \ i >= 0 && !(a >> i & 1); i--) clz++;\n        for (int i = 0; i < 64 && !(a\
    \ >> i & 1); i++) ctz++;\n        check(popcount(a) == pc, \"popcount\");\n  \
    \      if (a > 0) {\n            check(countl_zero(a) == clz, \"countl_zero\"\
    );\n            check(countr_zero(a) == ctz, \"countr_zero\");\n        }\n\n\
    \        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\
    \u3089)\n        std::string s;\n        for (int i = width - 1; i >= 0; i--)\
    \ s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) == a, \"btoll\");\n \
    \       // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\u3059\u308B\n  \
    \      std::string t = s;\n        for (char& c : t) c = (c == '1') ? '#' : '.';\n\
    \        check(btoll(t, '#') == a, \"btoll(s, one)\");\n\n        // hamming_distance:\
    \ \u30D3\u30C3\u30C8\u3054\u3068\u306B\u6BD4\u3079\u308B\n        long long b\
    \ = static_cast<long long>(rng() >> (64 - width));\n        int hd = 0;\n    \
    \    for (int i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);\n      \
    \  check(hamming_distance(a, b) == hd, \"hamming_distance\");\n    }\n\n    //\
    \ countl_one / countr_one / bit_width / bit_ceil / bit_floor \u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 100000\
    \ && ok; rep++) {\n        int width = rng() % 64;\n        long long a = width\
    \ == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));\n        if (rep %\
    \ 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 \u306E\u7D2F\u4E57\u3068\
    \u305D\u306E\u524D\u5F8C\n        if (a < 0) a = 0;\n        int clo = 0, cto\
    \ = 0, bw = 0;\n        for (int i = 63; i >= 0 && (a >> i & 1); i--) clo++;\n\
    \        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;\n        for (int\
    \ i = 0; i < 63; i++) {\n            if (a >> i & 1) bw = i + 1;\n        }\n\
    \        long long ceil = 1, floor = 0;\n        while (ceil < a && ceil <= (1LL\
    \ << 61)) ceil *= 2;  // a > 2^62 \u306A\u3089\u4F7F\u308F\u306A\u3044\n     \
    \   for (int i = 0; i < 63; i++) {\n            if ((1LL << i) <= a) floor = 1LL\
    \ << i;\n        }\n        check(countl_one(a) == clo, \"countl_one\");\n   \
    \     check(countr_one(a) == cto, \"countr_one\");\n        check(bit_width(a)\
    \ == bw, \"bit_width\");\n        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil,\
    \ \"bit_ceil\");\n        check(bit_floor(a) == floor, \"bit_floor\");\n    }\n\
    \n    // 1 \u30D3\u30C3\u30C8\u306E\u64CD\u4F5C\u30FB\u4F4D\u7F6E\u30FB\u5909\u63DB\
    \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep\
    \ = 0; rep < 100000 && ok; rep++) {\n        int width = rng() % 64;\n       \
    \ long long a = width == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));\n\
    \        if (rep % 4 == 0) a = 1LL << (rng() % 63);\n        int top = -1, low\
    \ = -1, pc = 0;\n        for (int i = 0; i < 63; i++) {\n            if (a >>\
    \ i & 1) {\n                top = i;\n                if (low < 0) low = i;\n\
    \                pc++;\n            }\n        }\n        check(has_single_bit(a)\
    \ == (pc == 1), \"has_single_bit\");\n        check(msb(a) == top && lsb(a) ==\
    \ low, \"msb / lsb\");\n        check(lowbit(a) == (low < 0 ? 0 : 1LL << low),\
    \ \"lowbit\");\n        check(parity(a) == pc % 2, \"parity\");\n        long\
    \ long i = rng() % 63;\n        bool on = a >> i & 1;\n        check(test_bit(a,\
    \ i) == on, \"test_bit\");\n        check(set_bit(a, i) == (on ? a : a + (1LL\
    \ << i)), \"set_bit\");\n        check(reset_bit(a, i) == (on ? a - (1LL << i)\
    \ : a), \"reset_bit\");\n        check(flip_bit(a, i) == (on ? a - (1LL << i)\
    \ : a + (1LL << i)), \"flip_bit\");\n\n        // lltob: \u6841\u6570\u3092\u7701\
    \u7565\u3059\u308B\u3068\u5148\u982D\u306B 0 \u3092\u4ED8\u3051\u306A\u3044\n\
    \        std::string s;\n        for (int j = std::max(top, 0); j >= 0; j--) s\
    \ += (a >> j & 1) ? '1' : '0';\n        check(lltob(a) == s && btoll(lltob(a))\
    \ == a, \"lltob\");\n        long long n = std::max(top + 1, 0) + rng() % 3;\n\
    \        if (n > 63) n = 63;\n        if (n == 0) n = 1;\n        check(lltob(a,\
    \ n) == std::string(n - s.size(), '0') + s, \"lltob(a, n)\");\n        std::string\
    \ t = lltob(a, n, '#', '.');\n        check(static_cast<long long>(t.size()) ==\
    \ n && btoll(t, '#') == a, \"lltob(a, n, one, zero)\");\n\n        // reverse_bits\
    \ / rotate_left / rotate_right: n \u30D3\u30C3\u30C8\u306E\u5404\u4F4D\u7F6E\u3092\
    \u52D5\u304B\u3059\n        long long rev = 0, rl = 0, rr = 0, k = static_cast<long\
    \ long>(rng() % 200) - 100;\n        long long km = ((k % n) + n) % n;\n     \
    \   for (int j = 0; j < n; j++) {\n            if (a >> j & 1) {\n           \
    \     rev |= 1LL << (n - 1 - j);\n                rl |= 1LL << ((j + km) % n);\n\
    \                rr |= 1LL << ((j - km + n) % n);\n            }\n        }\n\
    \        check(reverse_bits(a, n) == rev, \"reverse_bits\");\n        check(rotate_left(a,\
    \ k, n) == rl, \"rotate_left\");\n        check(rotate_right(a, k, n) == rr, \"\
    rotate_right\");\n\n        // gray_code: \u9006\u5909\u63DB\u3067\u623B\u308A\
    \u3001\u96A3\u308A\u5408\u3046\u5024\u3067 1 \u30D3\u30C3\u30C8\u3060\u3051\u5909\
    \u308F\u308B\n        check(inverse_gray_code(gray_code(a)) == a, \"inverse_gray_code\"\
    );\n        if (a < std::numeric_limits<long long>::max()) check(popcount(gray_code(a)\
    \ ^ gray_code(a + 1)) == 1, \"gray_code\");\n\n        // kth_set_bit\n      \
    \  if (pc > 0) {\n            long long kk = rng() % pc, pos = -1;\n         \
    \   for (int j = 0, c = 0; j < 63; j++) {\n                if (a >> j & 1) {\n\
    \                    if (c == kk) pos = j;\n                    c++;\n       \
    \         }\n            }\n            check(kth_set_bit(a, kk) == pos, \"kth_set_bit\"\
    );\n        }\n    }\n    // xor_upto / count_bit_upto: \u5C0F\u3055\u3044 n \u306F\
    \ 1 \u3064\u305A\u3064\u6570\u3048\u308B\n    {\n        long long x = 0;\n  \
    \      std::vector<long long> cnt(63, 0);\n        for (long long n = 0; n < 5000\
    \ && ok; n++) {\n            x ^= n;\n            check(xor_upto(n) == x, \"xor_upto\"\
    );\n            for (int i = 0; i < 63; i++) {\n                cnt[i] += n >>\
    \ i & 1;\n                check(count_bit_upto(n, i) == cnt[i], \"count_bit_upto\"\
    );\n            }\n        }\n        long long mx = std::numeric_limits<long\
    \ long>::max();\n        // \u5927\u304D\u3044 n: count_bit_upto \u306E\u548C\u306F\
    \ 0..n \u306E popcount \u306E\u548C\u3067\u30010..n \u3092 2 \u3064\u306B\u5206\
    \u3051\u3066\u6570\u3048\u3066\u3082\u540C\u3058\n        for (int rep = 0; rep\
    \ < 1000 && ok; rep++) {\n            long long n = static_cast<long long>(rng()\
    \ >> 1);\n            if (n == mx) n--;\n            long long m = static_cast<long\
    \ long>(rng() % 1000);\n            if (n < m) continue;\n            for (int\
    \ i = 0; i < 63; i++) {\n                long long direct = 0;\n             \
    \   for (long long v = n - m + 1; v <= n; v++) direct += v >> i & 1;\n       \
    \         check(count_bit_upto(n, i) - (n - m < 0 ? 0 : count_bit_upto(n - m,\
    \ i)) == direct, \"count_bit_upto \u5927\u304D\u3044 n\");\n            }\n  \
    \          long long xr = xor_upto(n - m);\n            for (long long v = n -\
    \ m + 1; v <= n; v++) xr ^= v;\n            check(xor_upto(n) == xr, \"xor_upto\
    \ \u5927\u304D\u3044 n\");\n        }\n        check(count_bit_upto(mx - 1, 62)\
    \ == mx - (1LL << 62), \"count_bit_upto \u4E0A\u9650\");\n        check(xor_upto(0)\
    \ == 0 && xor_upto(3) == 0 && xor_upto(mx - 1) == mx && xor_upto(mx) == 0, \"\
    xor_upto \u5883\u754C\");\n    }\n\n    // subsets / supersets / bits / combinations_mask\
    \ / add_one / remove_one \u3092\u3001\u3059\u3079\u3066\u306E\u5024\u3092\u8ABF\
    \u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n    for (int\
    \ rep = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 9;\n        long\
    \ long mask = static_cast<long long>(rng() % (1ULL << n));\n        std::vector<long\
    \ long> sub, sup, pos, got;\n        for (long long s = (1LL << n) - 1; s >= 0;\
    \ s--) {\n            if ((s & mask) == s) sub.push_back(s);  // \u964D\u9806\n\
    \        }\n        for (long long s = 0; s < (1LL << n); s++) {\n           \
    \ if ((s & mask) == mask) sup.push_back(s);  // \u6607\u9806\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            if (mask >> i & 1) pos.push_back(i);\n\
    \        }\n        got.clear();\n        for (long long s : subsets(mask)) got.push_back(s);\n\
    \        check(got == sub, \"subsets\");\n        got.clear();\n        for (long\
    \ long s : supersets(mask, n)) got.push_back(s);\n        check(got == sup, \"\
    supersets\");\n        got.clear();\n        for (long long i : bits(mask)) got.push_back(i);\n\
    \        check(got == pos, \"bits\");\n        // add_one / remove_one: 1 \u3064\
    \u8DB3\u3057\u305F (\u9664\u3044\u305F) \u96C6\u5408\u3068\u3001\u305D\u306E\u4F4D\
    \u7F6E\u306E\u7D44\n        std::vector<std::pair<long long, long long>> add,\
    \ rem, gp;\n        for (int i = 0; i < n; i++) {\n            if (mask >> i &\
    \ 1)\n                rem.emplace_back(i, mask ^ (1LL << i));\n            else\n\
    \                add.emplace_back(i, mask | (1LL << i));\n        }\n        for\
    \ (auto [i, t] : add_one(mask, n)) gp.emplace_back(i, t);\n        check(gp ==\
    \ add, \"add_one\");\n        gp.clear();\n        for (auto [i, t] : remove_one(mask))\
    \ gp.emplace_back(i, t);\n        check(gp == rem, \"remove_one\");\n        //\
    \ subsets_of_size: mask \u306E\u90E8\u5206\u96C6\u5408\u3067\u8981\u7D20\u6570\
    \ k \u306E\u3082\u306E (\u6607\u9806)\n        for (int k = 0; k <= n + 1; k++)\
    \ {\n            std::vector<long long> want;\n            for (long long s =\
    \ 0; s < (1LL << n); s++) {\n                if ((s & mask) == s && __builtin_popcountll(s)\
    \ == k) want.push_back(s);\n            }\n            got.clear();\n        \
    \    for (long long s : subsets_of_size(mask, k)) got.push_back(s);\n        \
    \    check(got == want, \"subsets_of_size\");\n        }\n        // next_combination_mask:\
    \ \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u6570\u304C\u540C\u3058\
    \u3067\u6B21\u306B\u5927\u304D\u3044\u5024\n        if (mask > 0) {\n        \
    \    long long want = -1;\n            for (long long s = mask + 1; s < (1LL <<\
    \ 12); s++) {\n                if (__builtin_popcountll(s) == __builtin_popcountll(mask))\
    \ {\n                    want = s;\n                    break;\n             \
    \   }\n            }\n            check(next_combination_mask(mask) == want, \"\
    next_combination_mask\");\n        }\n        for (int k = 0; k <= n + 1; k++)\
    \ {\n            std::vector<long long> comb;\n            for (long long s =\
    \ 0; s < (1LL << n); s++) {\n                if (__builtin_popcountll(s) == k)\
    \ comb.push_back(s);\n            }\n            got.clear();\n            for\
    \ (long long s : combinations_mask(n, k)) got.push_back(s);\n            check(got\
    \ == comb, \"combinations_mask\");\n        }\n    }\n    {\n        // \u5927\
    \u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\n        long long cnt\
    \ = 0, last = -1;\n        for (long long s : combinations_mask(62, 61)) cnt++,\
    \ last = s;\n        check(cnt == 62 && last == (1LL << 62) - 2, \"combinations_mask(62,\
    \ 61)\");\n        cnt = 0;\n        for (long long s : supersets((1LL << 62)\
    \ - 2, 62)) cnt += s;\n        check(cnt == 2 * ((1LL << 62) - 2) + 1, \"supersets\
    \ 62 \u30D3\u30C3\u30C8\");\n        std::vector<long long> got;\n        for\
    \ (long long i : bits(std::numeric_limits<long long>::max())) got.push_back(i);\n\
    \        check(static_cast<long long>(got.size()) == 63 && got.back() == 62, \"\
    bits(\u6700\u5927\u5024)\");\n        got.clear();\n        for (long long s :\
    \ subsets(0)) got.push_back(s);\n        check(got == std::vector<long long>{0},\
    \ \"subsets(0)\");\n        // constexpr \u3067\u3082\u4F7F\u3048\u308B\n    \
    \    constexpr long long sum = [] {\n            long long r = 0;\n          \
    \  for (long long s : subsets(0b1011)) r += s;\n            for (long long i :\
    \ bits(0b1011)) r += i;\n            return r;\n        }();\n        static_assert(sum\
    \ == 44 + 4);\n        constexpr long long sum2 = [] {\n            long long\
    \ r = 0;\n            for (auto [i, t] : add_one(0b0101, 4)) r += i * 100 + t;\
    \  // (1, 0111), (3, 1101)\n            for (auto [i, t] : remove_one(0b0101))\
    \ r += i * 100 + t;  // (0, 0100), (2, 0001)\n            return r;\n        }();\n\
    \        static_assert(sum2 == (100 + 7) + (300 + 13) + (0 + 4) + (200 + 1));\n\
    \        got.clear();\n        for (auto [i, t] : add_one((1LL << 62) - 2, 62))\
    \ got.push_back(i), got.push_back(t);\n        check(got == std::vector<long long>{0,\
    \ (1LL << 62) - 1}, \"add_one 62 \u30D3\u30C3\u30C8\");\n    }\n\n    {\n    \
    \    // subset_pairs: \u3059\u3079\u3066\u306E (S, T \u2286 S) \u3092 S \u306E\
    \u6607\u9806\u3001T \u306E\u964D\u9806\u306B\n        for (int n = 0; n <= 6 &&\
    \ ok; n++) {\n            std::vector<std::pair<long long, long long>> want, gp;\n\
    \            for (long long s = 0; s < (1LL << n); s++) {\n                for\
    \ (long long t = s; t >= 0; t--) {\n                    if ((t & s) == t) want.emplace_back(s,\
    \ t);\n                }\n            }\n            for (auto [s, t] : subset_pairs(n))\
    \ gp.emplace_back(s, t);\n            check(gp == want, \"subset_pairs\");\n \
    \       }\n        // \u5927\u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\
    \n        long long mx = std::numeric_limits<long long>::max();\n        check(next_combination_mask(mx)\
    \ == -1 && next_combination_mask(1LL << 62) == -1, \"next_combination_mask \u4E0A\
    \u9650\");\n        check(next_combination_mask((1LL << 62) - 2) == (1LL << 62)\
    \ + (1LL << 60) - 1, \"next_combination_mask 62 \u30D3\u30C3\u30C8\");\n     \
    \   std::vector<long long> got;\n        for (long long s : subsets_of_size(mx,\
    \ 62)) got.push_back(s);\n        check(static_cast<long long>(got.size()) ==\
    \ 63 && got.front() == (1LL << 62) - 1 && got.back() == mx - 1, \"subsets_of_size\
    \ 63 \u30D3\u30C3\u30C8\");\n        got.clear();\n        for (long long s :\
    \ subsets_of_size(0b1010, 0)) got.push_back(s);\n        check(got == std::vector<long\
    \ long>{0}, \"subsets_of_size(k = 0)\");\n        check(rotate_left(1, 1, 63)\
    \ == 2 && rotate_left(1LL << 62, 1, 63) == 1 && rotate_right(1, 1, 63) == (1LL\
    \ << 62), \"rotate 63 \u30D3\u30C3\u30C8\");\n        check(reverse_bits(1, 63)\
    \ == (1LL << 62) && inverse_gray_code(gray_code(mx)) == mx, \"63 \u30D3\u30C3\u30C8\
    \");\n        check(kth_set_bit(mx, 62) == 62 && kth_set_bit(1LL << 62, 0) ==\
    \ 62, \"kth_set_bit 63 \u30D3\u30C3\u30C8\");\n        check(lltob(0) == \"0\"\
    \ && lltob(5) == \"101\" && lltob(5, 5) == \"00101\" && lltob(0, 3, '#', '.')\
    \ == \"...\", \"lltob \u6C7A\u307E\u3063\u305F\u5024\");\n        check(msb(0)\
    \ == -1 && lsb(0) == -1 && lowbit(0) == 0 && msb(mx) == 62, \"msb / lsb / lowbit\
    \ \u5883\u754C\");\n        constexpr long long sum = [] {\n            long long\
    \ r = 0;\n            for (long long s : subsets_of_size(0b1101, 2)) r += s; \
    \ // 0101, 1001, 1100\n            for (auto [s, t] : subset_pairs(2)) r += s\
    \ * 10 + t;    // 3^2 = 9 \u7D44\n            return r;\n        }();\n      \
    \  static_assert(sum == (5 + 9 + 12) + (0 + 11 + 10 + 22 + 20 + 33 + 32 + 31 +\
    \ 30));\n        static_assert(has_single_bit(64) && !has_single_bit(0) && !has_single_bit(6));\n\
    \        static_assert(gray_code(5) == 7 && inverse_gray_code(7) == 5 && rotate_left(0b0011,\
    \ 3, 4) == 0b1001);\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E <bit>\
    \ \u3068\u540C\u3058\u5024\n    check(countl_zero(0) == 64 && countr_zero(0) ==\
    \ 64, \"countl_zero / countr_zero(0)\");\n    check(countl_one(0) == 0 && countr_one(0)\
    \ == 0, \"countl_one / countr_one(0)\");\n    check(bit_width(0) == 0 && bit_ceil(0)\
    \ == 1 && bit_floor(0) == 0, \"bit_width / bit_ceil / bit_floor(0)\");\n    check(bit_ceil(1LL\
    \ << 62) == (1LL << 62) && bit_ceil((1LL << 61) + 1) == (1LL << 62), \"bit_ceil\
    \ \u4E0A\u9650\");\n    check(countr_one(std::numeric_limits<long long>::max())\
    \ == 63 && bit_width(std::numeric_limits<long long>::max()) == 63, \"\u6700\u5927\
    \u5024\");\n\n    // \u623B\u308A\u5024\u306E\u578B\u306F C++17 \u3067\u3082 C++20\
    \ \u3067\u3082 long long\n    static_assert(std::is_same_v<decltype(popcount(1)),\
    \ long long>);\n    static_assert(std::is_same_v<decltype(countl_zero(1)), long\
    \ long>);\n    static_assert(std::is_same_v<decltype(countr_zero(1)), long long>);\n\
    \    static_assert(std::is_same_v<decltype(countl_one(1)), long long>);\n    static_assert(std::is_same_v<decltype(countr_one(1)),\
    \ long long>);\n    static_assert(std::is_same_v<decltype(bit_width(1)), long\
    \ long>);\n    static_assert(std::is_same_v<decltype(bit_ceil(1)), long long>);\n\
    \    static_assert(std::is_same_v<decltype(bit_floor(1)), long long>);\n    static_assert(bit_width(5)\
    \ == 3 && bit_ceil(5) == 8 && bit_floor(5) == 4 && countl_zero(0) == 64);\n\n\
    \    // \u6C7A\u307E\u3063\u305F\u5024\n    check(popcount(0) == 0 && popcount((1LL\
    \ << 62) - 1) == 62, \"popcount \u5883\u754C\");\n    check(countl_zero(1) ==\
    \ 63 && countr_zero(1LL << 62) == 62, \"countl_zero / countr_zero \u5883\u754C\
    \");\n    check(hamming_distance(5, 3) == 2 && hamming_distance(7, 7) == 0, \"\
    hamming_distance \u6C7A\u307E\u3063\u305F\u5024\");\n    check(btoll(\"\") ==\
    \ 0 && btoll(\"0\") == 0 && btoll(\"101\") == 5, \"btoll \u6C7A\u307E\u3063\u305F\
    \u5024\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// bit.hpp \u306E\u95A2\u6570\u3068\u5217\u6319\u3092\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// C++17 (__builtin_*\
    \ \u3067\u5B9F\u88C5) \u3068 C++20 (<bit> \u3092\u547C\u3076) \u306E\u3069\u3061\
    \u3089\u3067\u3082\u540C\u3058\u7D50\u679C\u306B\u306A\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/utility/bit.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include <random>\n\
    #include <string>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond)\
    \ {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n       \
    \ ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\n   \
    \ for (int rep = 0; rep < 100000 && ok; rep++) {\n        // 0 \u4EE5\u4E0A\u306E\
    \ long long (\u30D3\u30C3\u30C8\u6570\u3082\u3070\u3089\u3064\u304B\u305B\u308B\
    )\n        int width = rng() % 63 + 1;\n        long long a = static_cast<long\
    \ long>(rng() >> (64 - width));\n\n        int pc = 0, clz = 0, ctz = 0;\n   \
    \     for (int i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int i = 63;\
    \ i >= 0 && !(a >> i & 1); i--) clz++;\n        for (int i = 0; i < 64 && !(a\
    \ >> i & 1); i++) ctz++;\n        check(popcount(a) == pc, \"popcount\");\n  \
    \      if (a > 0) {\n            check(countl_zero(a) == clz, \"countl_zero\"\
    );\n            check(countr_zero(a) == ctz, \"countr_zero\");\n        }\n\n\
    \        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\
    \u3089)\n        std::string s;\n        for (int i = width - 1; i >= 0; i--)\
    \ s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) == a, \"btoll\");\n \
    \       // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\u3059\u308B\n  \
    \      std::string t = s;\n        for (char& c : t) c = (c == '1') ? '#' : '.';\n\
    \        check(btoll(t, '#') == a, \"btoll(s, one)\");\n\n        // hamming_distance:\
    \ \u30D3\u30C3\u30C8\u3054\u3068\u306B\u6BD4\u3079\u308B\n        long long b\
    \ = static_cast<long long>(rng() >> (64 - width));\n        int hd = 0;\n    \
    \    for (int i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);\n      \
    \  check(hamming_distance(a, b) == hd, \"hamming_distance\");\n    }\n\n    //\
    \ countl_one / countr_one / bit_width / bit_ceil / bit_floor \u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 100000\
    \ && ok; rep++) {\n        int width = rng() % 64;\n        long long a = width\
    \ == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));\n        if (rep %\
    \ 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 \u306E\u7D2F\u4E57\u3068\
    \u305D\u306E\u524D\u5F8C\n        if (a < 0) a = 0;\n        int clo = 0, cto\
    \ = 0, bw = 0;\n        for (int i = 63; i >= 0 && (a >> i & 1); i--) clo++;\n\
    \        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;\n        for (int\
    \ i = 0; i < 63; i++) {\n            if (a >> i & 1) bw = i + 1;\n        }\n\
    \        long long ceil = 1, floor = 0;\n        while (ceil < a && ceil <= (1LL\
    \ << 61)) ceil *= 2;  // a > 2^62 \u306A\u3089\u4F7F\u308F\u306A\u3044\n     \
    \   for (int i = 0; i < 63; i++) {\n            if ((1LL << i) <= a) floor = 1LL\
    \ << i;\n        }\n        check(countl_one(a) == clo, \"countl_one\");\n   \
    \     check(countr_one(a) == cto, \"countr_one\");\n        check(bit_width(a)\
    \ == bw, \"bit_width\");\n        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil,\
    \ \"bit_ceil\");\n        check(bit_floor(a) == floor, \"bit_floor\");\n    }\n\
    \n    // 1 \u30D3\u30C3\u30C8\u306E\u64CD\u4F5C\u30FB\u4F4D\u7F6E\u30FB\u5909\u63DB\
    \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n    for (int rep\
    \ = 0; rep < 100000 && ok; rep++) {\n        int width = rng() % 64;\n       \
    \ long long a = width == 0 ? 0 : static_cast<long long>(rng() >> (64 - width));\n\
    \        if (rep % 4 == 0) a = 1LL << (rng() % 63);\n        int top = -1, low\
    \ = -1, pc = 0;\n        for (int i = 0; i < 63; i++) {\n            if (a >>\
    \ i & 1) {\n                top = i;\n                if (low < 0) low = i;\n\
    \                pc++;\n            }\n        }\n        check(has_single_bit(a)\
    \ == (pc == 1), \"has_single_bit\");\n        check(msb(a) == top && lsb(a) ==\
    \ low, \"msb / lsb\");\n        check(lowbit(a) == (low < 0 ? 0 : 1LL << low),\
    \ \"lowbit\");\n        check(parity(a) == pc % 2, \"parity\");\n        long\
    \ long i = rng() % 63;\n        bool on = a >> i & 1;\n        check(test_bit(a,\
    \ i) == on, \"test_bit\");\n        check(set_bit(a, i) == (on ? a : a + (1LL\
    \ << i)), \"set_bit\");\n        check(reset_bit(a, i) == (on ? a - (1LL << i)\
    \ : a), \"reset_bit\");\n        check(flip_bit(a, i) == (on ? a - (1LL << i)\
    \ : a + (1LL << i)), \"flip_bit\");\n\n        // lltob: \u6841\u6570\u3092\u7701\
    \u7565\u3059\u308B\u3068\u5148\u982D\u306B 0 \u3092\u4ED8\u3051\u306A\u3044\n\
    \        std::string s;\n        for (int j = std::max(top, 0); j >= 0; j--) s\
    \ += (a >> j & 1) ? '1' : '0';\n        check(lltob(a) == s && btoll(lltob(a))\
    \ == a, \"lltob\");\n        long long n = std::max(top + 1, 0) + rng() % 3;\n\
    \        if (n > 63) n = 63;\n        if (n == 0) n = 1;\n        check(lltob(a,\
    \ n) == std::string(n - s.size(), '0') + s, \"lltob(a, n)\");\n        std::string\
    \ t = lltob(a, n, '#', '.');\n        check(static_cast<long long>(t.size()) ==\
    \ n && btoll(t, '#') == a, \"lltob(a, n, one, zero)\");\n\n        // reverse_bits\
    \ / rotate_left / rotate_right: n \u30D3\u30C3\u30C8\u306E\u5404\u4F4D\u7F6E\u3092\
    \u52D5\u304B\u3059\n        long long rev = 0, rl = 0, rr = 0, k = static_cast<long\
    \ long>(rng() % 200) - 100;\n        long long km = ((k % n) + n) % n;\n     \
    \   for (int j = 0; j < n; j++) {\n            if (a >> j & 1) {\n           \
    \     rev |= 1LL << (n - 1 - j);\n                rl |= 1LL << ((j + km) % n);\n\
    \                rr |= 1LL << ((j - km + n) % n);\n            }\n        }\n\
    \        check(reverse_bits(a, n) == rev, \"reverse_bits\");\n        check(rotate_left(a,\
    \ k, n) == rl, \"rotate_left\");\n        check(rotate_right(a, k, n) == rr, \"\
    rotate_right\");\n\n        // gray_code: \u9006\u5909\u63DB\u3067\u623B\u308A\
    \u3001\u96A3\u308A\u5408\u3046\u5024\u3067 1 \u30D3\u30C3\u30C8\u3060\u3051\u5909\
    \u308F\u308B\n        check(inverse_gray_code(gray_code(a)) == a, \"inverse_gray_code\"\
    );\n        if (a < std::numeric_limits<long long>::max()) check(popcount(gray_code(a)\
    \ ^ gray_code(a + 1)) == 1, \"gray_code\");\n\n        // kth_set_bit\n      \
    \  if (pc > 0) {\n            long long kk = rng() % pc, pos = -1;\n         \
    \   for (int j = 0, c = 0; j < 63; j++) {\n                if (a >> j & 1) {\n\
    \                    if (c == kk) pos = j;\n                    c++;\n       \
    \         }\n            }\n            check(kth_set_bit(a, kk) == pos, \"kth_set_bit\"\
    );\n        }\n    }\n    // xor_upto / count_bit_upto: \u5C0F\u3055\u3044 n \u306F\
    \ 1 \u3064\u305A\u3064\u6570\u3048\u308B\n    {\n        long long x = 0;\n  \
    \      std::vector<long long> cnt(63, 0);\n        for (long long n = 0; n < 5000\
    \ && ok; n++) {\n            x ^= n;\n            check(xor_upto(n) == x, \"xor_upto\"\
    );\n            for (int i = 0; i < 63; i++) {\n                cnt[i] += n >>\
    \ i & 1;\n                check(count_bit_upto(n, i) == cnt[i], \"count_bit_upto\"\
    );\n            }\n        }\n        long long mx = std::numeric_limits<long\
    \ long>::max();\n        // \u5927\u304D\u3044 n: count_bit_upto \u306E\u548C\u306F\
    \ 0..n \u306E popcount \u306E\u548C\u3067\u30010..n \u3092 2 \u3064\u306B\u5206\
    \u3051\u3066\u6570\u3048\u3066\u3082\u540C\u3058\n        for (int rep = 0; rep\
    \ < 1000 && ok; rep++) {\n            long long n = static_cast<long long>(rng()\
    \ >> 1);\n            if (n == mx) n--;\n            long long m = static_cast<long\
    \ long>(rng() % 1000);\n            if (n < m) continue;\n            for (int\
    \ i = 0; i < 63; i++) {\n                long long direct = 0;\n             \
    \   for (long long v = n - m + 1; v <= n; v++) direct += v >> i & 1;\n       \
    \         check(count_bit_upto(n, i) - (n - m < 0 ? 0 : count_bit_upto(n - m,\
    \ i)) == direct, \"count_bit_upto \u5927\u304D\u3044 n\");\n            }\n  \
    \          long long xr = xor_upto(n - m);\n            for (long long v = n -\
    \ m + 1; v <= n; v++) xr ^= v;\n            check(xor_upto(n) == xr, \"xor_upto\
    \ \u5927\u304D\u3044 n\");\n        }\n        check(count_bit_upto(mx - 1, 62)\
    \ == mx - (1LL << 62), \"count_bit_upto \u4E0A\u9650\");\n        check(xor_upto(0)\
    \ == 0 && xor_upto(3) == 0 && xor_upto(mx - 1) == mx && xor_upto(mx) == 0, \"\
    xor_upto \u5883\u754C\");\n    }\n\n    // subsets / supersets / bits / combinations_mask\
    \ / add_one / remove_one \u3092\u3001\u3059\u3079\u3066\u306E\u5024\u3092\u8ABF\
    \u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n    for (int\
    \ rep = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 9;\n        long\
    \ long mask = static_cast<long long>(rng() % (1ULL << n));\n        std::vector<long\
    \ long> sub, sup, pos, got;\n        for (long long s = (1LL << n) - 1; s >= 0;\
    \ s--) {\n            if ((s & mask) == s) sub.push_back(s);  // \u964D\u9806\n\
    \        }\n        for (long long s = 0; s < (1LL << n); s++) {\n           \
    \ if ((s & mask) == mask) sup.push_back(s);  // \u6607\u9806\n        }\n    \
    \    for (int i = 0; i < n; i++) {\n            if (mask >> i & 1) pos.push_back(i);\n\
    \        }\n        got.clear();\n        for (long long s : subsets(mask)) got.push_back(s);\n\
    \        check(got == sub, \"subsets\");\n        got.clear();\n        for (long\
    \ long s : supersets(mask, n)) got.push_back(s);\n        check(got == sup, \"\
    supersets\");\n        got.clear();\n        for (long long i : bits(mask)) got.push_back(i);\n\
    \        check(got == pos, \"bits\");\n        // add_one / remove_one: 1 \u3064\
    \u8DB3\u3057\u305F (\u9664\u3044\u305F) \u96C6\u5408\u3068\u3001\u305D\u306E\u4F4D\
    \u7F6E\u306E\u7D44\n        std::vector<std::pair<long long, long long>> add,\
    \ rem, gp;\n        for (int i = 0; i < n; i++) {\n            if (mask >> i &\
    \ 1)\n                rem.emplace_back(i, mask ^ (1LL << i));\n            else\n\
    \                add.emplace_back(i, mask | (1LL << i));\n        }\n        for\
    \ (auto [i, t] : add_one(mask, n)) gp.emplace_back(i, t);\n        check(gp ==\
    \ add, \"add_one\");\n        gp.clear();\n        for (auto [i, t] : remove_one(mask))\
    \ gp.emplace_back(i, t);\n        check(gp == rem, \"remove_one\");\n        //\
    \ subsets_of_size: mask \u306E\u90E8\u5206\u96C6\u5408\u3067\u8981\u7D20\u6570\
    \ k \u306E\u3082\u306E (\u6607\u9806)\n        for (int k = 0; k <= n + 1; k++)\
    \ {\n            std::vector<long long> want;\n            for (long long s =\
    \ 0; s < (1LL << n); s++) {\n                if ((s & mask) == s && __builtin_popcountll(s)\
    \ == k) want.push_back(s);\n            }\n            got.clear();\n        \
    \    for (long long s : subsets_of_size(mask, k)) got.push_back(s);\n        \
    \    check(got == want, \"subsets_of_size\");\n        }\n        // next_combination_mask:\
    \ \u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u306E\u6570\u304C\u540C\u3058\
    \u3067\u6B21\u306B\u5927\u304D\u3044\u5024\n        if (mask > 0) {\n        \
    \    long long want = -1;\n            for (long long s = mask + 1; s < (1LL <<\
    \ 12); s++) {\n                if (__builtin_popcountll(s) == __builtin_popcountll(mask))\
    \ {\n                    want = s;\n                    break;\n             \
    \   }\n            }\n            check(next_combination_mask(mask) == want, \"\
    next_combination_mask\");\n        }\n        for (int k = 0; k <= n + 1; k++)\
    \ {\n            std::vector<long long> comb;\n            for (long long s =\
    \ 0; s < (1LL << n); s++) {\n                if (__builtin_popcountll(s) == k)\
    \ comb.push_back(s);\n            }\n            got.clear();\n            for\
    \ (long long s : combinations_mask(n, k)) got.push_back(s);\n            check(got\
    \ == comb, \"combinations_mask\");\n        }\n    }\n    {\n        // \u5927\
    \u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\n        long long cnt\
    \ = 0, last = -1;\n        for (long long s : combinations_mask(62, 61)) cnt++,\
    \ last = s;\n        check(cnt == 62 && last == (1LL << 62) - 2, \"combinations_mask(62,\
    \ 61)\");\n        cnt = 0;\n        for (long long s : supersets((1LL << 62)\
    \ - 2, 62)) cnt += s;\n        check(cnt == 2 * ((1LL << 62) - 2) + 1, \"supersets\
    \ 62 \u30D3\u30C3\u30C8\");\n        std::vector<long long> got;\n        for\
    \ (long long i : bits(std::numeric_limits<long long>::max())) got.push_back(i);\n\
    \        check(static_cast<long long>(got.size()) == 63 && got.back() == 62, \"\
    bits(\u6700\u5927\u5024)\");\n        got.clear();\n        for (long long s :\
    \ subsets(0)) got.push_back(s);\n        check(got == std::vector<long long>{0},\
    \ \"subsets(0)\");\n        // constexpr \u3067\u3082\u4F7F\u3048\u308B\n    \
    \    constexpr long long sum = [] {\n            long long r = 0;\n          \
    \  for (long long s : subsets(0b1011)) r += s;\n            for (long long i :\
    \ bits(0b1011)) r += i;\n            return r;\n        }();\n        static_assert(sum\
    \ == 44 + 4);\n        constexpr long long sum2 = [] {\n            long long\
    \ r = 0;\n            for (auto [i, t] : add_one(0b0101, 4)) r += i * 100 + t;\
    \  // (1, 0111), (3, 1101)\n            for (auto [i, t] : remove_one(0b0101))\
    \ r += i * 100 + t;  // (0, 0100), (2, 0001)\n            return r;\n        }();\n\
    \        static_assert(sum2 == (100 + 7) + (300 + 13) + (0 + 4) + (200 + 1));\n\
    \        got.clear();\n        for (auto [i, t] : add_one((1LL << 62) - 2, 62))\
    \ got.push_back(i), got.push_back(t);\n        check(got == std::vector<long long>{0,\
    \ (1LL << 62) - 1}, \"add_one 62 \u30D3\u30C3\u30C8\");\n    }\n\n    {\n    \
    \    // subset_pairs: \u3059\u3079\u3066\u306E (S, T \u2286 S) \u3092 S \u306E\
    \u6607\u9806\u3001T \u306E\u964D\u9806\u306B\n        for (int n = 0; n <= 6 &&\
    \ ok; n++) {\n            std::vector<std::pair<long long, long long>> want, gp;\n\
    \            for (long long s = 0; s < (1LL << n); s++) {\n                for\
    \ (long long t = s; t >= 0; t--) {\n                    if ((t & s) == t) want.emplace_back(s,\
    \ t);\n                }\n            }\n            for (auto [s, t] : subset_pairs(n))\
    \ gp.emplace_back(s, t);\n            check(gp == want, \"subset_pairs\");\n \
    \       }\n        // \u5927\u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\
    \n        long long mx = std::numeric_limits<long long>::max();\n        check(next_combination_mask(mx)\
    \ == -1 && next_combination_mask(1LL << 62) == -1, \"next_combination_mask \u4E0A\
    \u9650\");\n        check(next_combination_mask((1LL << 62) - 2) == (1LL << 62)\
    \ + (1LL << 60) - 1, \"next_combination_mask 62 \u30D3\u30C3\u30C8\");\n     \
    \   std::vector<long long> got;\n        for (long long s : subsets_of_size(mx,\
    \ 62)) got.push_back(s);\n        check(static_cast<long long>(got.size()) ==\
    \ 63 && got.front() == (1LL << 62) - 1 && got.back() == mx - 1, \"subsets_of_size\
    \ 63 \u30D3\u30C3\u30C8\");\n        got.clear();\n        for (long long s :\
    \ subsets_of_size(0b1010, 0)) got.push_back(s);\n        check(got == std::vector<long\
    \ long>{0}, \"subsets_of_size(k = 0)\");\n        check(rotate_left(1, 1, 63)\
    \ == 2 && rotate_left(1LL << 62, 1, 63) == 1 && rotate_right(1, 1, 63) == (1LL\
    \ << 62), \"rotate 63 \u30D3\u30C3\u30C8\");\n        check(reverse_bits(1, 63)\
    \ == (1LL << 62) && inverse_gray_code(gray_code(mx)) == mx, \"63 \u30D3\u30C3\u30C8\
    \");\n        check(kth_set_bit(mx, 62) == 62 && kth_set_bit(1LL << 62, 0) ==\
    \ 62, \"kth_set_bit 63 \u30D3\u30C3\u30C8\");\n        check(lltob(0) == \"0\"\
    \ && lltob(5) == \"101\" && lltob(5, 5) == \"00101\" && lltob(0, 3, '#', '.')\
    \ == \"...\", \"lltob \u6C7A\u307E\u3063\u305F\u5024\");\n        check(msb(0)\
    \ == -1 && lsb(0) == -1 && lowbit(0) == 0 && msb(mx) == 62, \"msb / lsb / lowbit\
    \ \u5883\u754C\");\n        constexpr long long sum = [] {\n            long long\
    \ r = 0;\n            for (long long s : subsets_of_size(0b1101, 2)) r += s; \
    \ // 0101, 1001, 1100\n            for (auto [s, t] : subset_pairs(2)) r += s\
    \ * 10 + t;    // 3^2 = 9 \u7D44\n            return r;\n        }();\n      \
    \  static_assert(sum == (5 + 9 + 12) + (0 + 11 + 10 + 22 + 20 + 33 + 32 + 31 +\
    \ 30));\n        static_assert(has_single_bit(64) && !has_single_bit(0) && !has_single_bit(6));\n\
    \        static_assert(gray_code(5) == 7 && inverse_gray_code(7) == 5 && rotate_left(0b0011,\
    \ 3, 4) == 0b1001);\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E <bit>\
    \ \u3068\u540C\u3058\u5024\n    check(countl_zero(0) == 64 && countr_zero(0) ==\
    \ 64, \"countl_zero / countr_zero(0)\");\n    check(countl_one(0) == 0 && countr_one(0)\
    \ == 0, \"countl_one / countr_one(0)\");\n    check(bit_width(0) == 0 && bit_ceil(0)\
    \ == 1 && bit_floor(0) == 0, \"bit_width / bit_ceil / bit_floor(0)\");\n    check(bit_ceil(1LL\
    \ << 62) == (1LL << 62) && bit_ceil((1LL << 61) + 1) == (1LL << 62), \"bit_ceil\
    \ \u4E0A\u9650\");\n    check(countr_one(std::numeric_limits<long long>::max())\
    \ == 63 && bit_width(std::numeric_limits<long long>::max()) == 63, \"\u6700\u5927\
    \u5024\");\n\n    // \u623B\u308A\u5024\u306E\u578B\u306F C++17 \u3067\u3082 C++20\
    \ \u3067\u3082 long long\n    static_assert(std::is_same_v<decltype(popcount(1)),\
    \ long long>);\n    static_assert(std::is_same_v<decltype(countl_zero(1)), long\
    \ long>);\n    static_assert(std::is_same_v<decltype(countr_zero(1)), long long>);\n\
    \    static_assert(std::is_same_v<decltype(countl_one(1)), long long>);\n    static_assert(std::is_same_v<decltype(countr_one(1)),\
    \ long long>);\n    static_assert(std::is_same_v<decltype(bit_width(1)), long\
    \ long>);\n    static_assert(std::is_same_v<decltype(bit_ceil(1)), long long>);\n\
    \    static_assert(std::is_same_v<decltype(bit_floor(1)), long long>);\n    static_assert(bit_width(5)\
    \ == 3 && bit_ceil(5) == 8 && bit_floor(5) == 4 && countl_zero(0) == 64);\n\n\
    \    // \u6C7A\u307E\u3063\u305F\u5024\n    check(popcount(0) == 0 && popcount((1LL\
    \ << 62) - 1) == 62, \"popcount \u5883\u754C\");\n    check(countl_zero(1) ==\
    \ 63 && countr_zero(1LL << 62) == 62, \"countl_zero / countr_zero \u5883\u754C\
    \");\n    check(hamming_distance(5, 3) == 2 && hamming_distance(7, 7) == 0, \"\
    hamming_distance \u6C7A\u307E\u3063\u305F\u5024\");\n    check(btoll(\"\") ==\
    \ 0 && btoll(\"0\") == 0 && btoll(\"101\") == 5, \"btoll \u6C7A\u307E\u3063\u305F\
    \u5024\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/bit.hpp
  isVerificationFile: true
  path: test/unittest/bit.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:29:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/bit.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/bit.test.cpp
- /verify/test/unittest/bit.test.cpp.html
title: test/unittest/bit.test.cpp
---
