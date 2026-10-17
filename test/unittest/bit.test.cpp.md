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
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// C++17 (__builtin_* \u3067\
    \u5B9F\u88C5) \u3068 C++20 (<bit> \u3092\u547C\u3076) \u306E\u3069\u3061\u3089\
    \u3067\u3082\u540C\u3058\u7D50\u679C\u306B\u306A\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/bit.hpp\"\
    \n\n/**\n * @file bit.hpp\n * @brief \u30D3\u30C3\u30C8\u6F14\u7B97\n */\n\n#include\
    \ <cassert>\n#include <string>\n\n/**\n * @brief 2\u9032\u6570\u306E\u6587\u5B57\
    \u5217\u3092long long\u306B\u3059\u308B\n */\ninline long long btoll(std::string\
    \ s, char one = '1') {\n    long long res = 0;\n    for (char c : s) {\n     \
    \   res <<= 1;\n        if (c == one) ++res;\n    }\n    return res;\n}\n\n#if\
    \ __cplusplus < 202000L\n\n// C++20 \u306E <bit> \u3068\u540C\u3058\u5024\u3092\
    \u8FD4\u3059 (0 \u306E\u3068\u304D\u3082\u540C\u3058)\n\n/**\n * @brief \u7ACB\
    \u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u6570\u3048\u308B\n * __builtin_popcountll\n\
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
    \    assert(a >= 0 && b >= 0);\n    return popcount(a ^ b);\n}\n#line 8 \"test/unittest/bit.test.cpp\"\
    \n\n#include <iostream>\n#include <limits>\n#include <random>\n#line 13 \"test/unittest/bit.test.cpp\"\
    \n#include <type_traits>\n\nbool ok = true;\n\nvoid check(bool cond, const char*\
    \ what) {\n    if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n        ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n        //\
    \ 0 \u4EE5\u4E0A\u306E long long (\u30D3\u30C3\u30C8\u6570\u3082\u3070\u3089\u3064\
    \u304B\u305B\u308B)\n        int width = rng() % 63 + 1;\n        long long a\
    \ = (long long)(rng() >> (64 - width));\n\n        int pc = 0, clz = 0, ctz =\
    \ 0;\n        for (int i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int\
    \ i = 63; i >= 0 && !(a >> i & 1); i--) clz++;\n        for (int i = 0; i < 64\
    \ && !(a >> i & 1); i++) ctz++;\n        check(popcount(a) == pc, \"popcount\"\
    );\n        if (a > 0) {\n            check(countl_zero(a) == clz, \"countl_zero\"\
    );\n            check(countr_zero(a) == ctz, \"countr_zero\");\n        }\n\n\
    \        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\
    \u3089)\n        std::string s;\n        for (int i = width - 1; i >= 0; i--)\
    \ s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) == a, \"btoll\");\n \
    \       // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\u3059\u308B\n  \
    \      std::string t = s;\n        for (char& c : t) c = (c == '1') ? '#' : '.';\n\
    \        check(btoll(t, '#') == a, \"btoll(s, one)\");\n\n        // hamming_distance:\
    \ \u30D3\u30C3\u30C8\u3054\u3068\u306B\u6BD4\u3079\u308B\n        long long b\
    \ = (long long)(rng() >> (64 - width));\n        int hd = 0;\n        for (int\
    \ i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);\n        check(hamming_distance(a,\
    \ b) == hd, \"hamming_distance\");\n    }\n\n    // countl_one / countr_one /\
    \ bit_width / bit_ceil / bit_floor \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n        int\
    \ width = rng() % 64;\n        long long a = width == 0 ? 0 : (long long)(rng()\
    \ >> (64 - width));\n        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng()\
    \ % 2;  // 2 \u306E\u7D2F\u4E57\u3068\u305D\u306E\u524D\u5F8C\n        if (a <\
    \ 0) a = 0;\n        int clo = 0, cto = 0, bw = 0;\n        for (int i = 63; i\
    \ >= 0 && (a >> i & 1); i--) clo++;\n        for (int i = 0; i < 64 && (a >> i\
    \ & 1); i++) cto++;\n        for (int i = 0; i < 63; i++) {\n            if (a\
    \ >> i & 1) bw = i + 1;\n        }\n        long long ceil = 1, floor = 0;\n \
    \       while (ceil < a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 \u306A\
    \u3089\u4F7F\u308F\u306A\u3044\n        for (int i = 0; i < 63; i++) {\n     \
    \       if ((1LL << i) <= a) floor = 1LL << i;\n        }\n        check(countl_one(a)\
    \ == clo, \"countl_one\");\n        check(countr_one(a) == cto, \"countr_one\"\
    );\n        check(bit_width(a) == bw, \"bit_width\");\n        if (a <= (1LL <<\
    \ 62)) check(bit_ceil(a) == ceil, \"bit_ceil\");\n        check(bit_floor(a) ==\
    \ floor, \"bit_floor\");\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E\
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
    \n\n// bit.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// C++17 (__builtin_* \u3067\
    \u5B9F\u88C5) \u3068 C++20 (<bit> \u3092\u547C\u3076) \u306E\u3069\u3061\u3089\
    \u3067\u3082\u540C\u3058\u7D50\u679C\u306B\u306A\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/utility/bit.hpp\"\
    \n\n#include <iostream>\n#include <limits>\n#include <random>\n#include <string>\n\
    #include <type_traits>\n\nbool ok = true;\n\nvoid check(bool cond, const char*\
    \ what) {\n    if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n        ok = false;\n    }\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n        //\
    \ 0 \u4EE5\u4E0A\u306E long long (\u30D3\u30C3\u30C8\u6570\u3082\u3070\u3089\u3064\
    \u304B\u305B\u308B)\n        int width = rng() % 63 + 1;\n        long long a\
    \ = (long long)(rng() >> (64 - width));\n\n        int pc = 0, clz = 0, ctz =\
    \ 0;\n        for (int i = 0; i < 63; i++) pc += a >> i & 1;\n        for (int\
    \ i = 63; i >= 0 && !(a >> i & 1); i--) clz++;\n        for (int i = 0; i < 64\
    \ && !(a >> i & 1); i++) ctz++;\n        check(popcount(a) == pc, \"popcount\"\
    );\n        if (a > 0) {\n            check(countl_zero(a) == clz, \"countl_zero\"\
    );\n            check(countr_zero(a) == ctz, \"countr_zero\");\n        }\n\n\
    \        // btoll: 2 \u9032\u6570\u306E\u6587\u5B57\u5217 (\u4E0A\u4F4D\u6841\u304B\
    \u3089)\n        std::string s;\n        for (int i = width - 1; i >= 0; i--)\
    \ s += (a >> i & 1) ? '1' : '0';\n        check(btoll(s) == a, \"btoll\");\n \
    \       // 1 \u3092\u8868\u3059\u6587\u5B57\u3092\u6307\u5B9A\u3059\u308B\n  \
    \      std::string t = s;\n        for (char& c : t) c = (c == '1') ? '#' : '.';\n\
    \        check(btoll(t, '#') == a, \"btoll(s, one)\");\n\n        // hamming_distance:\
    \ \u30D3\u30C3\u30C8\u3054\u3068\u306B\u6BD4\u3079\u308B\n        long long b\
    \ = (long long)(rng() >> (64 - width));\n        int hd = 0;\n        for (int\
    \ i = 0; i < 63; i++) hd += (a >> i & 1) != (b >> i & 1);\n        check(hamming_distance(a,\
    \ b) == hd, \"hamming_distance\");\n    }\n\n    // countl_one / countr_one /\
    \ bit_width / bit_ceil / bit_floor \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\
    \u3079\u308B\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n        int\
    \ width = rng() % 64;\n        long long a = width == 0 ? 0 : (long long)(rng()\
    \ >> (64 - width));\n        if (rep % 4 == 0) a = (1LL << (rng() % 63)) - rng()\
    \ % 2;  // 2 \u306E\u7D2F\u4E57\u3068\u305D\u306E\u524D\u5F8C\n        if (a <\
    \ 0) a = 0;\n        int clo = 0, cto = 0, bw = 0;\n        for (int i = 63; i\
    \ >= 0 && (a >> i & 1); i--) clo++;\n        for (int i = 0; i < 64 && (a >> i\
    \ & 1); i++) cto++;\n        for (int i = 0; i < 63; i++) {\n            if (a\
    \ >> i & 1) bw = i + 1;\n        }\n        long long ceil = 1, floor = 0;\n \
    \       while (ceil < a && ceil <= (1LL << 61)) ceil *= 2;  // a > 2^62 \u306A\
    \u3089\u4F7F\u308F\u306A\u3044\n        for (int i = 0; i < 63; i++) {\n     \
    \       if ((1LL << i) <= a) floor = 1LL << i;\n        }\n        check(countl_one(a)\
    \ == clo, \"countl_one\");\n        check(countr_one(a) == cto, \"countr_one\"\
    );\n        check(bit_width(a) == bw, \"bit_width\");\n        if (a <= (1LL <<\
    \ 62)) check(bit_ceil(a) == ceil, \"bit_ceil\");\n        check(bit_floor(a) ==\
    \ floor, \"bit_floor\");\n    }\n\n    // 0 \u306E\u3068\u304D\u306F C++20 \u306E\
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
  timestamp: '2026-10-17 23:17:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/bit.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/bit.test.cpp
- /verify/test/unittest/bit.test.cpp.html
title: test/unittest/bit.test.cpp
---
