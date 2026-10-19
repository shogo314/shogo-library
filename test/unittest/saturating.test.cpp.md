---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/saturating.hpp
    title: "\u98FD\u548C\u6F14\u7B97"
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
  bundledCode: "#line 1 \"test/unittest/saturating.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// saturating.hpp\
    \ \u306E\u95A2\u6570\u3092\u3001__int128 \u3067\u8A08\u7B97\u3057\u3066\u7BC4\u56F2\
    \u306B\u4E38\u3081\u305F\u3082\u306E\u3068\u6BD4\u8F03\u3059\u308B\n// 8 \u30D3\
    \u30C3\u30C8\u306E\u578B\u306F\u5168\u7D44\u3001\u305D\u308C\u4EE5\u5916\u306F\
    \u5883\u754C\u4ED8\u8FD1\u306E\u5024\u3068\u30E9\u30F3\u30C0\u30E0\u306A\u5024\
    \u3067\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/math/saturating.hpp\"\n\n/**\n * @file saturating.hpp\n\
    \ * @brief \u98FD\u548C\u6F14\u7B97 (\u7D50\u679C\u304C\u578B\u306E\u7BC4\u56F2\
    \u3092\u8D85\u3048\u305F\u3089\u3001\u305D\u306E\u578B\u306E\u6700\u5927\u5024\
    \u30FB\u6700\u5C0F\u5024\u306B\u4E38\u3081\u308B)\n */\n\n#include <cassert>\n\
    #include <limits>\n#include <numeric>\n#include <type_traits>\n#include <utility>\n\
    \n#if __cplusplus >= 202002L\n#include <concepts>\n#endif\n\nnamespace internal_saturating\
    \ {\ntemplate <class T>\nstruct is_character : std::false_type {};\ntemplate <>\n\
    struct is_character<char> : std::true_type {};\ntemplate <>\nstruct is_character<wchar_t>\
    \ : std::true_type {};\ntemplate <>\nstruct is_character<char16_t> : std::true_type\
    \ {};\ntemplate <>\nstruct is_character<char32_t> : std::true_type {};\n#ifdef\
    \ __cpp_char8_t\ntemplate <>\nstruct is_character<char8_t> : std::true_type {};\n\
    #endif\n\n// bool \u3068\u6587\u5B57\u578B\u3092\u9664\u304F\u6574\u6570\u578B\
    \ (C++26 \u306E std::add_sat \u306A\u3069\u3068\u540C\u3058\u6761\u4EF6)\n#if\
    \ __cplusplus >= 202002L\ntemplate <class T>\nconcept integer = std::integral<T>\
    \ && !std::same_as<std::remove_cv_t<T>, bool> && !is_character<std::remove_cv_t<T>>::value;\n\
    \nusing std::cmp_greater;\nusing std::cmp_less;\n#else\ntemplate <class T>\ninline\
    \ constexpr bool integer = std::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>,\
    \ bool> && !is_character<std::remove_cv_t<T>>::value;\n\n// C++20 \u306E std::cmp_less\
    \ \u3068\u540C\u3058 (\u7B26\u53F7\u306E\u6709\u7121\u304C\u9055\u3063\u3066\u3082\
    \u5024\u3068\u3057\u3066\u6BD4\u3079\u308B)\ntemplate <class T, class U>\nconstexpr\
    \ bool cmp_less(T t, U u) noexcept {\n    if constexpr (std::is_signed_v<T> ==\
    \ std::is_signed_v<U>) {\n        return t < u;\n    } else if constexpr (std::is_signed_v<T>)\
    \ {\n        return t < 0 || std::make_unsigned_t<T>(t) < u;\n    } else {\n \
    \       return u >= 0 && t < std::make_unsigned_t<U>(u);\n    }\n}\ntemplate <class\
    \ T, class U>\nconstexpr bool cmp_greater(T t, U u) noexcept {\n    return cmp_less(u,\
    \ t);\n}\n#endif\n}  // namespace internal_saturating\n\n// C++20 \u3067\u306F\
    \ requires \u3067\u3001C++17 \u3067\u306F\u623B\u308A\u5024\u306E enable_if \u3067\
    \u6574\u6570\u578B\u306B\u5236\u9650\u3059\u308B\n#if __cplusplus >= 202002L\n\
    #define SATURATING_FUNC(cond, R) requires(cond) inline constexpr R\n#else\n#define\
    \ SATURATING_FUNC(cond, R) inline constexpr std::enable_if_t<(cond), R>\n#endif\n\
    \n// clang-format \u306F SATURATING_FUNC \u3092\u623B\u308A\u5024\u306E\u578B\u3068\
    \u8AAD\u3081\u305A\u3001\u95A2\u6570\u540D\u306E\u524D\u3067\u6539\u884C\u3057\
    \u3066\u3057\u307E\u3046\u306E\u3067\u6574\u5F62\u3057\u306A\u3044\n// clang-format\
    \ off\n\n/**\n * @brief x + y \u3092 T \u306E\u7BC4\u56F2\u306B\u4E38\u3081\u308B\
    \n */\ntemplate <class T>\nSATURATING_FUNC(internal_saturating::integer<T>, T)\
    \ saturating_add(T x, T y) noexcept {\n#ifdef __cpp_lib_saturation_arithmetic\n\
    \    return std::add_sat(x, y);\n#else\n    T res{};\n    if (!__builtin_add_overflow(x,\
    \ y, &res)) return res;\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ (y < 0) return std::numeric_limits<T>::min();\n    }\n    return std::numeric_limits<T>::max();\n\
    #endif\n}\n/**\n * @brief x - y \u3092 T \u306E\u7BC4\u56F2\u306B\u4E38\u3081\u308B\
    \n */\ntemplate <class T>\nSATURATING_FUNC(internal_saturating::integer<T>, T)\
    \ saturating_sub(T x, T y) noexcept {\n#ifdef __cpp_lib_saturation_arithmetic\n\
    \    return std::sub_sat(x, y);\n#else\n    T res{};\n    if (!__builtin_sub_overflow(x,\
    \ y, &res)) return res;\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ (y < 0) return std::numeric_limits<T>::max();\n    }\n    return std::numeric_limits<T>::min();\n\
    #endif\n}\n/**\n * @brief x * y \u3092 T \u306E\u7BC4\u56F2\u306B\u4E38\u3081\u308B\
    \n */\ntemplate <class T>\nSATURATING_FUNC(internal_saturating::integer<T>, T)\
    \ saturating_mul(T x, T y) noexcept {\n#ifdef __cpp_lib_saturation_arithmetic\n\
    \    return std::mul_sat(x, y);\n#else\n    T res{};\n    if (!__builtin_mul_overflow(x,\
    \ y, &res)) return res;\n    if constexpr (std::is_signed_v<T>) {\n        if\
    \ ((x < 0) != (y < 0)) return std::numeric_limits<T>::min();\n    }\n    return\
    \ std::numeric_limits<T>::max();\n#endif\n}\n/**\n * @brief x / y (0 \u65B9\u5411\
    \u306B\u5207\u308A\u6368\u3066) \u3092 T \u306E\u7BC4\u56F2\u306B\u4E38\u3081\u308B\
    \ (y != 0)\n * \u3042\u3075\u308C\u308B\u306E\u306F\u7B26\u53F7\u4ED8\u304D\u306E\
    \ min / -1 \u3060\u3051\u3067\u3001max \u3092\u8FD4\u3059\n */\ntemplate <class\
    \ T>\nSATURATING_FUNC(internal_saturating::integer<T>, T) saturating_div(T x,\
    \ T y) noexcept {\n    assert(y != 0);\n#ifdef __cpp_lib_saturation_arithmetic\n\
    \    return std::div_sat(x, y);\n#else\n    if constexpr (std::is_signed_v<T>)\
    \ {\n        if (x == std::numeric_limits<T>::min() && y == -1) return std::numeric_limits<T>::max();\n\
    \    }\n    return x / y;\n#endif\n}\n/**\n * @brief \u6574\u6570 x \u3092 R \u306B\
    \u5909\u63DB\u3057\u3001R \u306E\u7BC4\u56F2\u306B\u53CE\u307E\u3089\u306A\u3051\
    \u308C\u3070 R \u306E\u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u306B\u4E38\u3081\
    \u308B\n */\ntemplate <class R, class T>\nSATURATING_FUNC(internal_saturating::integer<R>\
    \ && internal_saturating::integer<T>, R) saturating_cast(T x) noexcept {\n#ifdef\
    \ __cpp_lib_saturation_arithmetic\n    return std::saturate_cast<R>(x);\n#else\n\
    \    if (internal_saturating::cmp_less(x, std::numeric_limits<R>::min())) return\
    \ std::numeric_limits<R>::min();\n    if (internal_saturating::cmp_greater(x,\
    \ std::numeric_limits<R>::max())) return std::numeric_limits<R>::max();\n    return\
    \ static_cast<R>(x);\n#endif\n}\n\n// clang-format on\n\n#undef SATURATING_FUNC\n\
    #line 8 \"test/unittest/saturating.test.cpp\"\n\n#include <cstdint>\n#include\
    \ <iostream>\n#line 12 \"test/unittest/saturating.test.cpp\"\n#include <random>\n\
    #line 15 \"test/unittest/saturating.test.cpp\"\n#include <vector>\n\nusing i128\
    \ = __int128;\nusing u128 = unsigned __int128;\n\nbool ok = true;\n\nvoid check(bool\
    \ cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr << \"\
    failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\ntemplate <class\
    \ T>\ni128 lo() { return static_cast<i128>(std::numeric_limits<T>::min()); }\n\
    template <class T>\ni128 hi() { return static_cast<i128>(std::numeric_limits<T>::max());\
    \ }\ntemplate <class T>\nT clamp128(i128 v) { return v < lo<T>() ? std::numeric_limits<T>::min()\
    \ : v > hi<T>() ? std::numeric_limits<T>::max()\n                            \
    \                                                          : static_cast<T>(v);\
    \ }\n\n// \u5883\u754C\u4ED8\u8FD1\u306E\u5024\u3068\u30E9\u30F3\u30C0\u30E0\u306A\
    \u5024\ntemplate <class T>\nstd::vector<T> samples(std::mt19937_64& rng) {\n \
    \   std::vector<T> res;\n    for (i128 d = 0; d < 4; d++) {\n        for (i128\
    \ v : {lo<T>() + d, hi<T>() - d, d, -d, hi<T>() / 2 - 1 + d, lo<T>() / 2 - 1 +\
    \ d}) {\n            if (lo<T>() <= v && v <= hi<T>()) res.push_back(static_cast<T>(v));\n\
    \        }\n    }\n    for (int i = 0; i < 40; i++) {\n        T v = static_cast<T>(rng());\n\
    \        res.push_back(v);\n        res.push_back(static_cast<T>(v >> (rng() %\
    \ (8 * sizeof(T)))));  // \u5C0F\u3055\u3044\u5024\u3082\u6DF7\u305C\u308B\n \
    \   }\n    return res;\n}\n\ntemplate <class T>\nvoid check_arith(const std::vector<T>&\
    \ xs) {\n    for (T x : xs) {\n        for (T y : xs) {\n            check(saturating_add(x,\
    \ y) == clamp128<T>(static_cast<i128>(x) + y), \"saturating_add\");\n        \
    \    check(saturating_sub(x, y) == clamp128<T>(static_cast<i128>(x) - y), \"saturating_sub\"\
    );\n            if constexpr (std::is_unsigned_v<T> && sizeof(T) == 8) {\n   \
    \             u128 p = static_cast<u128>(x) * y;\n                check(saturating_mul(x,\
    \ y) == (p > static_cast<u128>(std::numeric_limits<T>::max()) ? std::numeric_limits<T>::max()\
    \ : static_cast<T>(p)), \"saturating_mul\");\n            } else {\n         \
    \       check(saturating_mul(x, y) == clamp128<T>(static_cast<i128>(x) * y), \"\
    saturating_mul\");\n            }\n            if (y != 0) check(saturating_div(x,\
    \ y) == clamp128<T>(static_cast<i128>(x) / y), \"saturating_div\");\n        \
    \    static_assert(std::is_same_v<decltype(saturating_add(x, y)), T>);\n     \
    \   }\n    }\n}\n\ntemplate <class R, class T>\nvoid check_cast(const std::vector<T>&\
    \ xs) {\n    for (T x : xs) check(saturating_cast<R>(x) == clamp128<R>(static_cast<i128>(x)),\
    \ \"saturating_cast\");\n    static_assert(std::is_same_v<decltype(saturating_cast<R>(T())),\
    \ R>);\n}\ntemplate <class T, class... Rs>\nvoid check_cast_all(std::mt19937_64&\
    \ rng) {\n    auto xs = samples<T>(rng);\n    (check_cast<Rs>(xs), ...);\n}\n\n\
    // \u6574\u6570\u578B\u4EE5\u5916\u3092\u6E21\u3059\u3068\u5019\u88DC\u304B\u3089\
    \u5916\u308C\u308B (bool\u3001\u6587\u5B57\u578B\u3001\u6D6E\u52D5\u5C0F\u6570\
    \u70B9\u6570)\ntemplate <class T, class = void>\nstruct can_add : std::false_type\
    \ {};\ntemplate <class T>\nstruct can_add<T, std::void_t<decltype(saturating_add(std::declval<T>(),\
    \ std::declval<T>()))>> : std::true_type {};\ntemplate <class R, class T, class\
    \ = void>\nstruct can_cast : std::false_type {};\ntemplate <class R, class T>\n\
    struct can_cast<R, T, std::void_t<decltype(saturating_cast<R>(std::declval<T>()))>>\
    \ : std::true_type {};\n\nstatic_assert(can_add<int>::value && can_add<unsigned\
    \ long long>::value && can_add<std::int8_t>::value);\nstatic_assert(!can_add<bool>::value\
    \ && !can_add<char>::value && !can_add<char32_t>::value && !can_add<double>::value);\n\
    static_assert(can_cast<int, long long>::value && !can_cast<bool, int>::value &&\
    \ !can_cast<int, double>::value);\n\n// constexpr \u306E\u4E2D\u3067\u3082\u4F7F\
    \u3048\u308B\nstatic_assert(saturating_add(100, 2000000000) == 2000000100);\n\
    static_assert(saturating_add(2000000000, 2000000000) == std::numeric_limits<int>::max());\n\
    static_assert(saturating_sub(0u, 1u) == 0u);\nstatic_assert(saturating_mul(-3000000000LL,\
    \ 4000000000LL) == std::numeric_limits<long long>::min());\nstatic_assert(saturating_div(std::numeric_limits<int>::min(),\
    \ -1) == std::numeric_limits<int>::max());\nstatic_assert(saturating_cast<std::uint8_t>(-5)\
    \ == 0 && saturating_cast<std::uint8_t>(300) == 255);\nstatic_assert(saturating_cast<int>(std::numeric_limits<unsigned\
    \ long long>::max()) == std::numeric_limits<int>::max());\n\nint main() {\n  \
    \  std::mt19937_64 rng(314);\n\n    // 8 \u30D3\u30C3\u30C8\u306E\u578B\u306F\u5168\
    \u7D44\n    {\n        std::vector<std::int8_t> s;\n        std::vector<std::uint8_t>\
    \ u;\n        for (int v = -128; v < 128; v++) s.push_back(static_cast<std::int8_t>(v));\n\
    \        for (int v = 0; v < 256; v++) u.push_back(static_cast<std::uint8_t>(v));\n\
    \        check_arith(s);\n        check_arith(u);\n    }\n    check_arith(samples<short>(rng));\n\
    \    check_arith(samples<unsigned short>(rng));\n    check_arith(samples<int>(rng));\n\
    \    check_arith(samples<unsigned>(rng));\n    check_arith(samples<long>(rng));\n\
    \    check_arith(samples<long long>(rng));\n    check_arith(samples<unsigned long\
    \ long>(rng));\n\n#define CAST_TYPES std::int8_t, std::uint8_t, short, unsigned\
    \ short, int, unsigned, long long, unsigned long long\n    check_cast_all<std::int8_t,\
    \ CAST_TYPES>(rng);\n    check_cast_all<std::uint8_t, CAST_TYPES>(rng);\n    check_cast_all<short,\
    \ CAST_TYPES>(rng);\n    check_cast_all<unsigned short, CAST_TYPES>(rng);\n  \
    \  check_cast_all<int, CAST_TYPES>(rng);\n    check_cast_all<unsigned, CAST_TYPES>(rng);\n\
    \    check_cast_all<long long, CAST_TYPES>(rng);\n    check_cast_all<unsigned\
    \ long long, CAST_TYPES>(rng);\n\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// saturating.hpp \u306E\u95A2\u6570\u3092\u3001__int128 \u3067\u8A08\u7B97\
    \u3057\u3066\u7BC4\u56F2\u306B\u4E38\u3081\u305F\u3082\u306E\u3068\u6BD4\u8F03\
    \u3059\u308B\n// 8 \u30D3\u30C3\u30C8\u306E\u578B\u306F\u5168\u7D44\u3001\u305D\
    \u308C\u4EE5\u5916\u306F\u5883\u754C\u4ED8\u8FD1\u306E\u5024\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306A\u5024\u3067\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/math/saturating.hpp\"\
    \n\n#include <cstdint>\n#include <iostream>\n#include <limits>\n#include <random>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\nusing i128 =\
    \ __int128;\nusing u128 = unsigned __int128;\n\nbool ok = true;\n\nvoid check(bool\
    \ cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr << \"\
    failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\ntemplate <class\
    \ T>\ni128 lo() { return static_cast<i128>(std::numeric_limits<T>::min()); }\n\
    template <class T>\ni128 hi() { return static_cast<i128>(std::numeric_limits<T>::max());\
    \ }\ntemplate <class T>\nT clamp128(i128 v) { return v < lo<T>() ? std::numeric_limits<T>::min()\
    \ : v > hi<T>() ? std::numeric_limits<T>::max()\n                            \
    \                                                          : static_cast<T>(v);\
    \ }\n\n// \u5883\u754C\u4ED8\u8FD1\u306E\u5024\u3068\u30E9\u30F3\u30C0\u30E0\u306A\
    \u5024\ntemplate <class T>\nstd::vector<T> samples(std::mt19937_64& rng) {\n \
    \   std::vector<T> res;\n    for (i128 d = 0; d < 4; d++) {\n        for (i128\
    \ v : {lo<T>() + d, hi<T>() - d, d, -d, hi<T>() / 2 - 1 + d, lo<T>() / 2 - 1 +\
    \ d}) {\n            if (lo<T>() <= v && v <= hi<T>()) res.push_back(static_cast<T>(v));\n\
    \        }\n    }\n    for (int i = 0; i < 40; i++) {\n        T v = static_cast<T>(rng());\n\
    \        res.push_back(v);\n        res.push_back(static_cast<T>(v >> (rng() %\
    \ (8 * sizeof(T)))));  // \u5C0F\u3055\u3044\u5024\u3082\u6DF7\u305C\u308B\n \
    \   }\n    return res;\n}\n\ntemplate <class T>\nvoid check_arith(const std::vector<T>&\
    \ xs) {\n    for (T x : xs) {\n        for (T y : xs) {\n            check(saturating_add(x,\
    \ y) == clamp128<T>(static_cast<i128>(x) + y), \"saturating_add\");\n        \
    \    check(saturating_sub(x, y) == clamp128<T>(static_cast<i128>(x) - y), \"saturating_sub\"\
    );\n            if constexpr (std::is_unsigned_v<T> && sizeof(T) == 8) {\n   \
    \             u128 p = static_cast<u128>(x) * y;\n                check(saturating_mul(x,\
    \ y) == (p > static_cast<u128>(std::numeric_limits<T>::max()) ? std::numeric_limits<T>::max()\
    \ : static_cast<T>(p)), \"saturating_mul\");\n            } else {\n         \
    \       check(saturating_mul(x, y) == clamp128<T>(static_cast<i128>(x) * y), \"\
    saturating_mul\");\n            }\n            if (y != 0) check(saturating_div(x,\
    \ y) == clamp128<T>(static_cast<i128>(x) / y), \"saturating_div\");\n        \
    \    static_assert(std::is_same_v<decltype(saturating_add(x, y)), T>);\n     \
    \   }\n    }\n}\n\ntemplate <class R, class T>\nvoid check_cast(const std::vector<T>&\
    \ xs) {\n    for (T x : xs) check(saturating_cast<R>(x) == clamp128<R>(static_cast<i128>(x)),\
    \ \"saturating_cast\");\n    static_assert(std::is_same_v<decltype(saturating_cast<R>(T())),\
    \ R>);\n}\ntemplate <class T, class... Rs>\nvoid check_cast_all(std::mt19937_64&\
    \ rng) {\n    auto xs = samples<T>(rng);\n    (check_cast<Rs>(xs), ...);\n}\n\n\
    // \u6574\u6570\u578B\u4EE5\u5916\u3092\u6E21\u3059\u3068\u5019\u88DC\u304B\u3089\
    \u5916\u308C\u308B (bool\u3001\u6587\u5B57\u578B\u3001\u6D6E\u52D5\u5C0F\u6570\
    \u70B9\u6570)\ntemplate <class T, class = void>\nstruct can_add : std::false_type\
    \ {};\ntemplate <class T>\nstruct can_add<T, std::void_t<decltype(saturating_add(std::declval<T>(),\
    \ std::declval<T>()))>> : std::true_type {};\ntemplate <class R, class T, class\
    \ = void>\nstruct can_cast : std::false_type {};\ntemplate <class R, class T>\n\
    struct can_cast<R, T, std::void_t<decltype(saturating_cast<R>(std::declval<T>()))>>\
    \ : std::true_type {};\n\nstatic_assert(can_add<int>::value && can_add<unsigned\
    \ long long>::value && can_add<std::int8_t>::value);\nstatic_assert(!can_add<bool>::value\
    \ && !can_add<char>::value && !can_add<char32_t>::value && !can_add<double>::value);\n\
    static_assert(can_cast<int, long long>::value && !can_cast<bool, int>::value &&\
    \ !can_cast<int, double>::value);\n\n// constexpr \u306E\u4E2D\u3067\u3082\u4F7F\
    \u3048\u308B\nstatic_assert(saturating_add(100, 2000000000) == 2000000100);\n\
    static_assert(saturating_add(2000000000, 2000000000) == std::numeric_limits<int>::max());\n\
    static_assert(saturating_sub(0u, 1u) == 0u);\nstatic_assert(saturating_mul(-3000000000LL,\
    \ 4000000000LL) == std::numeric_limits<long long>::min());\nstatic_assert(saturating_div(std::numeric_limits<int>::min(),\
    \ -1) == std::numeric_limits<int>::max());\nstatic_assert(saturating_cast<std::uint8_t>(-5)\
    \ == 0 && saturating_cast<std::uint8_t>(300) == 255);\nstatic_assert(saturating_cast<int>(std::numeric_limits<unsigned\
    \ long long>::max()) == std::numeric_limits<int>::max());\n\nint main() {\n  \
    \  std::mt19937_64 rng(314);\n\n    // 8 \u30D3\u30C3\u30C8\u306E\u578B\u306F\u5168\
    \u7D44\n    {\n        std::vector<std::int8_t> s;\n        std::vector<std::uint8_t>\
    \ u;\n        for (int v = -128; v < 128; v++) s.push_back(static_cast<std::int8_t>(v));\n\
    \        for (int v = 0; v < 256; v++) u.push_back(static_cast<std::uint8_t>(v));\n\
    \        check_arith(s);\n        check_arith(u);\n    }\n    check_arith(samples<short>(rng));\n\
    \    check_arith(samples<unsigned short>(rng));\n    check_arith(samples<int>(rng));\n\
    \    check_arith(samples<unsigned>(rng));\n    check_arith(samples<long>(rng));\n\
    \    check_arith(samples<long long>(rng));\n    check_arith(samples<unsigned long\
    \ long>(rng));\n\n#define CAST_TYPES std::int8_t, std::uint8_t, short, unsigned\
    \ short, int, unsigned, long long, unsigned long long\n    check_cast_all<std::int8_t,\
    \ CAST_TYPES>(rng);\n    check_cast_all<std::uint8_t, CAST_TYPES>(rng);\n    check_cast_all<short,\
    \ CAST_TYPES>(rng);\n    check_cast_all<unsigned short, CAST_TYPES>(rng);\n  \
    \  check_cast_all<int, CAST_TYPES>(rng);\n    check_cast_all<unsigned, CAST_TYPES>(rng);\n\
    \    check_cast_all<long long, CAST_TYPES>(rng);\n    check_cast_all<unsigned\
    \ long long, CAST_TYPES>(rng);\n\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/math/saturating.hpp
  isVerificationFile: true
  path: test/unittest/saturating.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:29:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/saturating.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/saturating.test.cpp
- /verify/test/unittest/saturating.test.cpp.html
title: test/unittest/saturating.test.cpp
---
