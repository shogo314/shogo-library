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
    \ {\n    assert(a >= 0);\n    return __builtin_popcountll((unsigned long long)a);\n\
    }\n/**\n * @brief \u5DE6\u304B\u3089\u9023\u7D9A\u3057\u305F0\u306E\u30D3\u30C3\
    \u30C8\u3092\u6570\u3048\u308B\n * __builtin_clzll\n */\ninline constexpr long\
    \ long countl_zero(long long a) {\n    assert(a >= 0);\n    return a == 0 ? 64\
    \ : __builtin_clzll((unsigned long long)a);\n}\n/**\n * @brief \u5DE6\u304B\u3089\
    \u9023\u7D9A\u3057\u305F1\u306E\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n */\n\
    inline constexpr long long countl_one(long long a) {\n    assert(a >= 0);\n  \
    \  unsigned long long x = ~(unsigned long long)a;\n    return x == 0 ? 64 : __builtin_clzll(x);\n\
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
    \ long mask) {\n    assert(mask >= 0);\n    return {mask, mask};\n}\n#line 8 \"\
    test/unittest/bit.test.cpp\"\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <limits>\n#include <random>\n#line 14 \"test/unittest/bit.test.cpp\"\n#include\
    \ <type_traits>\n#line 16 \"test/unittest/bit.test.cpp\"\n#include <vector>\n\n\
    bool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond) {\n\
    \        if (ok) std::cerr << \"failed: \" << what << std::endl;\n        ok =\
    \ false;\n    }\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\n    for (int\
    \ rep = 0; rep < 100000 && ok; rep++) {\n        // 0 \u4EE5\u4E0A\u306E long\
    \ long (\u30D3\u30C3\u30C8\u6570\u3082\u3070\u3089\u3064\u304B\u305B\u308B)\n\
    \        int width = rng() % 63 + 1;\n        long long a = (long long)(rng()\
    \ >> (64 - width));\n\n        int pc = 0, clz = 0, ctz = 0;\n        for (int\
    \ i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int i = 63; i >= 0 && !(a\
    \ >> i & 1); i--) clz++;\n        for (int i = 0; i < 64 && !(a >> i & 1); i++)\
    \ ctz++;\n        check(popcount(a) == pc, \"popcount\");\n        if (a > 0)\
    \ {\n            check(countl_zero(a) == clz, \"countl_zero\");\n            check(countr_zero(a)\
    \ == ctz, \"countr_zero\");\n        }\n\n        // btoll: 2 \u9032\u6570\u306E\
    \u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\u3089)\n        std::string s;\n\
    \        for (int i = width - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';\n\
    \        check(btoll(s) == a, \"btoll\");\n        // 1 \u3092\u8868\u3059\u6587\
    \u5B57\u3092\u6307\u5B9A\u3059\u308B\n        std::string t = s;\n        for\
    \ (char& c : t) c = (c == '1') ? '#' : '.';\n        check(btoll(t, '#') == a,\
    \ \"btoll(s, one)\");\n\n        // hamming_distance: \u30D3\u30C3\u30C8\u3054\
    \u3068\u306B\u6BD4\u3079\u308B\n        long long b = (long long)(rng() >> (64\
    \ - width));\n        int hd = 0;\n        for (int i = 0; i < 63; i++) hd +=\
    \ (a >> i & 1) != (b >> i & 1);\n        check(hamming_distance(a, b) == hd, \"\
    hamming_distance\");\n    }\n\n    // countl_one / countr_one / bit_width / bit_ceil\
    \ / bit_floor \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n \
    \   for (int rep = 0; rep < 100000 && ok; rep++) {\n        int width = rng()\
    \ % 64;\n        long long a = width == 0 ? 0 : (long long)(rng() >> (64 - width));\n\
    \        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 \u306E\
    \u7D2F\u4E57\u3068\u305D\u306E\u524D\u5F8C\n        if (a < 0) a = 0;\n      \
    \  int clo = 0, cto = 0, bw = 0;\n        for (int i = 63; i >= 0 && (a >> i &\
    \ 1); i--) clo++;\n        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;\n\
    \        for (int i = 0; i < 63; i++) {\n            if (a >> i & 1) bw = i +\
    \ 1;\n        }\n        long long ceil = 1, floor = 0;\n        while (ceil <\
    \ a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 \u306A\u3089\u4F7F\u308F\u306A\
    \u3044\n        for (int i = 0; i < 63; i++) {\n            if ((1LL << i) <=\
    \ a) floor = 1LL << i;\n        }\n        check(countl_one(a) == clo, \"countl_one\"\
    );\n        check(countr_one(a) == cto, \"countr_one\");\n        check(bit_width(a)\
    \ == bw, \"bit_width\");\n        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil,\
    \ \"bit_ceil\");\n        check(bit_floor(a) == floor, \"bit_floor\");\n    }\n\
    \n    // subsets / supersets / bits / combinations_mask / add_one / remove_one\
    \ \u3092\u3001\u3059\u3079\u3066\u306E\u5024\u3092\u8ABF\u3079\u308B\u611A\u76F4\
    \u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 9;\n        long long mask = (long long)(rng()\
    \ % (1ULL << n));\n        std::vector<long long> sub, sup, pos, got;\n      \
    \  for (long long s = (1LL << n) - 1; s >= 0; s--) {\n            if ((s & mask)\
    \ == s) sub.push_back(s);  // \u964D\u9806\n        }\n        for (long long\
    \ s = 0; s < (1LL << n); s++) {\n            if ((s & mask) == mask) sup.push_back(s);\
    \  // \u6607\u9806\n        }\n        for (int i = 0; i < n; i++) {\n       \
    \     if (mask >> i & 1) pos.push_back(i);\n        }\n        got.clear();\n\
    \        for (long long s : subsets(mask)) got.push_back(s);\n        check(got\
    \ == sub, \"subsets\");\n        got.clear();\n        for (long long s : supersets(mask,\
    \ n)) got.push_back(s);\n        check(got == sup, \"supersets\");\n        got.clear();\n\
    \        for (long long i : bits(mask)) got.push_back(i);\n        check(got ==\
    \ pos, \"bits\");\n        // add_one / remove_one: 1 \u3064\u8DB3\u3057\u305F\
    \ (\u9664\u3044\u305F) \u96C6\u5408\u3068\u3001\u305D\u306E\u4F4D\u7F6E\u306E\u7D44\
    \n        std::vector<std::pair<long long, long long>> add, rem, gp;\n       \
    \ for (int i = 0; i < n; i++) {\n            if (mask >> i & 1)\n            \
    \    rem.emplace_back(i, mask ^ (1LL << i));\n            else\n             \
    \   add.emplace_back(i, mask | (1LL << i));\n        }\n        for (auto [i,\
    \ t] : add_one(mask, n)) gp.emplace_back(i, t);\n        check(gp == add, \"add_one\"\
    );\n        gp.clear();\n        for (auto [i, t] : remove_one(mask)) gp.emplace_back(i,\
    \ t);\n        check(gp == rem, \"remove_one\");\n        for (int k = 0; k <=\
    \ n + 1; k++) {\n            std::vector<long long> comb;\n            for (long\
    \ long s = 0; s < (1LL << n); s++) {\n                if (__builtin_popcountll(s)\
    \ == k) comb.push_back(s);\n            }\n            got.clear();\n        \
    \    for (long long s : combinations_mask(n, k)) got.push_back(s);\n         \
    \   check(got == comb, \"combinations_mask\");\n        }\n    }\n    {\n    \
    \    // \u5927\u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\n       \
    \ long long cnt = 0, last = -1;\n        for (long long s : combinations_mask(62,\
    \ 61)) cnt++, last = s;\n        check(cnt == 62 && last == (1LL << 62) - 2, \"\
    combinations_mask(62, 61)\");\n        cnt = 0;\n        for (long long s : supersets((1LL\
    \ << 62) - 2, 62)) cnt += s;\n        check(cnt == 2 * ((1LL << 62) - 2) + 1,\
    \ \"supersets 62 \u30D3\u30C3\u30C8\");\n        std::vector<long long> got;\n\
    \        for (long long i : bits(std::numeric_limits<long long>::max())) got.push_back(i);\n\
    \        check((long long)got.size() == 63 && got.back() == 62, \"bits(\u6700\u5927\
    \u5024)\");\n        got.clear();\n        for (long long s : subsets(0)) got.push_back(s);\n\
    \        check(got == std::vector<long long>{0}, \"subsets(0)\");\n        //\
    \ constexpr \u3067\u3082\u4F7F\u3048\u308B\n        constexpr long long sum =\
    \ [] {\n            long long r = 0;\n            for (long long s : subsets(0b1011))\
    \ r += s;\n            for (long long i : bits(0b1011)) r += i;\n            return\
    \ r;\n        }();\n        static_assert(sum == 44 + 4);\n        constexpr long\
    \ long sum2 = [] {\n            long long r = 0;\n            for (auto [i, t]\
    \ : add_one(0b0101, 4)) r += i * 100 + t;  // (1, 0111), (3, 1101)\n         \
    \   for (auto [i, t] : remove_one(0b0101)) r += i * 100 + t;  // (0, 0100), (2,\
    \ 0001)\n            return r;\n        }();\n        static_assert(sum2 == (100\
    \ + 7) + (300 + 13) + (0 + 4) + (200 + 1));\n        got.clear();\n        for\
    \ (auto [i, t] : add_one((1LL << 62) - 2, 62)) got.push_back(i), got.push_back(t);\n\
    \        check(got == std::vector<long long>{0, (1LL << 62) - 1}, \"add_one 62\
    \ \u30D3\u30C3\u30C8\");\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E\
    \ <bit> \u3068\u540C\u3058\u5024\n    check(countl_zero(0) == 64 && countr_zero(0)\
    \ == 64, \"countl_zero / countr_zero(0)\");\n    check(countl_one(0) == 0 && countr_one(0)\
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
    )\n        int width = rng() % 63 + 1;\n        long long a = (long long)(rng()\
    \ >> (64 - width));\n\n        int pc = 0, clz = 0, ctz = 0;\n        for (int\
    \ i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int i = 63; i >= 0 && !(a\
    \ >> i & 1); i--) clz++;\n        for (int i = 0; i < 64 && !(a >> i & 1); i++)\
    \ ctz++;\n        check(popcount(a) == pc, \"popcount\");\n        if (a > 0)\
    \ {\n            check(countl_zero(a) == clz, \"countl_zero\");\n            check(countr_zero(a)\
    \ == ctz, \"countr_zero\");\n        }\n\n        // btoll: 2 \u9032\u6570\u306E\
    \u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\u3089)\n        std::string s;\n\
    \        for (int i = width - 1; i >= 0; i--) s += (a >> i & 1) ? '1' : '0';\n\
    \        check(btoll(s) == a, \"btoll\");\n        // 1 \u3092\u8868\u3059\u6587\
    \u5B57\u3092\u6307\u5B9A\u3059\u308B\n        std::string t = s;\n        for\
    \ (char& c : t) c = (c == '1') ? '#' : '.';\n        check(btoll(t, '#') == a,\
    \ \"btoll(s, one)\");\n\n        // hamming_distance: \u30D3\u30C3\u30C8\u3054\
    \u3068\u306B\u6BD4\u3079\u308B\n        long long b = (long long)(rng() >> (64\
    \ - width));\n        int hd = 0;\n        for (int i = 0; i < 63; i++) hd +=\
    \ (a >> i & 1) != (b >> i & 1);\n        check(hamming_distance(a, b) == hd, \"\
    hamming_distance\");\n    }\n\n    // countl_one / countr_one / bit_width / bit_ceil\
    \ / bit_floor \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n \
    \   for (int rep = 0; rep < 100000 && ok; rep++) {\n        int width = rng()\
    \ % 64;\n        long long a = width == 0 ? 0 : (long long)(rng() >> (64 - width));\n\
    \        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng() % 2;  // 2 \u306E\
    \u7D2F\u4E57\u3068\u305D\u306E\u524D\u5F8C\n        if (a < 0) a = 0;\n      \
    \  int clo = 0, cto = 0, bw = 0;\n        for (int i = 63; i >= 0 && (a >> i &\
    \ 1); i--) clo++;\n        for (int i = 0; i < 64 && (a >> i & 1); i++) cto++;\n\
    \        for (int i = 0; i < 63; i++) {\n            if (a >> i & 1) bw = i +\
    \ 1;\n        }\n        long long ceil = 1, floor = 0;\n        while (ceil <\
    \ a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 \u306A\u3089\u4F7F\u308F\u306A\
    \u3044\n        for (int i = 0; i < 63; i++) {\n            if ((1LL << i) <=\
    \ a) floor = 1LL << i;\n        }\n        check(countl_one(a) == clo, \"countl_one\"\
    );\n        check(countr_one(a) == cto, \"countr_one\");\n        check(bit_width(a)\
    \ == bw, \"bit_width\");\n        if (a <= (1LL << 62)) check(bit_ceil(a) == ceil,\
    \ \"bit_ceil\");\n        check(bit_floor(a) == floor, \"bit_floor\");\n    }\n\
    \n    // subsets / supersets / bits / combinations_mask / add_one / remove_one\
    \ \u3092\u3001\u3059\u3079\u3066\u306E\u5024\u3092\u8ABF\u3079\u308B\u611A\u76F4\
    \u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 9;\n        long long mask = (long long)(rng()\
    \ % (1ULL << n));\n        std::vector<long long> sub, sup, pos, got;\n      \
    \  for (long long s = (1LL << n) - 1; s >= 0; s--) {\n            if ((s & mask)\
    \ == s) sub.push_back(s);  // \u964D\u9806\n        }\n        for (long long\
    \ s = 0; s < (1LL << n); s++) {\n            if ((s & mask) == mask) sup.push_back(s);\
    \  // \u6607\u9806\n        }\n        for (int i = 0; i < n; i++) {\n       \
    \     if (mask >> i & 1) pos.push_back(i);\n        }\n        got.clear();\n\
    \        for (long long s : subsets(mask)) got.push_back(s);\n        check(got\
    \ == sub, \"subsets\");\n        got.clear();\n        for (long long s : supersets(mask,\
    \ n)) got.push_back(s);\n        check(got == sup, \"supersets\");\n        got.clear();\n\
    \        for (long long i : bits(mask)) got.push_back(i);\n        check(got ==\
    \ pos, \"bits\");\n        // add_one / remove_one: 1 \u3064\u8DB3\u3057\u305F\
    \ (\u9664\u3044\u305F) \u96C6\u5408\u3068\u3001\u305D\u306E\u4F4D\u7F6E\u306E\u7D44\
    \n        std::vector<std::pair<long long, long long>> add, rem, gp;\n       \
    \ for (int i = 0; i < n; i++) {\n            if (mask >> i & 1)\n            \
    \    rem.emplace_back(i, mask ^ (1LL << i));\n            else\n             \
    \   add.emplace_back(i, mask | (1LL << i));\n        }\n        for (auto [i,\
    \ t] : add_one(mask, n)) gp.emplace_back(i, t);\n        check(gp == add, \"add_one\"\
    );\n        gp.clear();\n        for (auto [i, t] : remove_one(mask)) gp.emplace_back(i,\
    \ t);\n        check(gp == rem, \"remove_one\");\n        for (int k = 0; k <=\
    \ n + 1; k++) {\n            std::vector<long long> comb;\n            for (long\
    \ long s = 0; s < (1LL << n); s++) {\n                if (__builtin_popcountll(s)\
    \ == k) comb.push_back(s);\n            }\n            got.clear();\n        \
    \    for (long long s : combinations_mask(n, k)) got.push_back(s);\n         \
    \   check(got == comb, \"combinations_mask\");\n        }\n    }\n    {\n    \
    \    // \u5927\u304D\u3044\u30D3\u30C3\u30C8\u5E45\u3068\u5883\u754C\n       \
    \ long long cnt = 0, last = -1;\n        for (long long s : combinations_mask(62,\
    \ 61)) cnt++, last = s;\n        check(cnt == 62 && last == (1LL << 62) - 2, \"\
    combinations_mask(62, 61)\");\n        cnt = 0;\n        for (long long s : supersets((1LL\
    \ << 62) - 2, 62)) cnt += s;\n        check(cnt == 2 * ((1LL << 62) - 2) + 1,\
    \ \"supersets 62 \u30D3\u30C3\u30C8\");\n        std::vector<long long> got;\n\
    \        for (long long i : bits(std::numeric_limits<long long>::max())) got.push_back(i);\n\
    \        check((long long)got.size() == 63 && got.back() == 62, \"bits(\u6700\u5927\
    \u5024)\");\n        got.clear();\n        for (long long s : subsets(0)) got.push_back(s);\n\
    \        check(got == std::vector<long long>{0}, \"subsets(0)\");\n        //\
    \ constexpr \u3067\u3082\u4F7F\u3048\u308B\n        constexpr long long sum =\
    \ [] {\n            long long r = 0;\n            for (long long s : subsets(0b1011))\
    \ r += s;\n            for (long long i : bits(0b1011)) r += i;\n            return\
    \ r;\n        }();\n        static_assert(sum == 44 + 4);\n        constexpr long\
    \ long sum2 = [] {\n            long long r = 0;\n            for (auto [i, t]\
    \ : add_one(0b0101, 4)) r += i * 100 + t;  // (1, 0111), (3, 1101)\n         \
    \   for (auto [i, t] : remove_one(0b0101)) r += i * 100 + t;  // (0, 0100), (2,\
    \ 0001)\n            return r;\n        }();\n        static_assert(sum2 == (100\
    \ + 7) + (300 + 13) + (0 + 4) + (200 + 1));\n        got.clear();\n        for\
    \ (auto [i, t] : add_one((1LL << 62) - 2, 62)) got.push_back(i), got.push_back(t);\n\
    \        check(got == std::vector<long long>{0, (1LL << 62) - 1}, \"add_one 62\
    \ \u30D3\u30C3\u30C8\");\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E\
    \ <bit> \u3068\u540C\u3058\u5024\n    check(countl_zero(0) == 64 && countr_zero(0)\
    \ == 64, \"countl_zero / countr_zero(0)\");\n    check(countl_one(0) == 0 && countr_one(0)\
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
  timestamp: '2026-10-18 18:08:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/bit.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/bit.test.cpp
- /verify/test/unittest/bit.test.cpp.html
title: test/unittest/bit.test.cpp
---
