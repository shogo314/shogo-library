---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/math/saturating.test.cpp
    title: test/unittest/math/saturating.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u98FD\u548C\u6F14\u7B97 (\u7D50\u679C\u304C\u578B\u306E\u7BC4\
      \u56F2\u3092\u8D85\u3048\u305F\u3089\u3001\u305D\u306E\u578B\u306E\u6700\u5927\
      \u5024\u30FB\u6700\u5C0F\u5024\u306B\u4E38\u3081\u308B)"
    links: []
  bundledCode: "#line 2 \"src/math/saturating.hpp\"\n\n/**\n * @file saturating.hpp\n\
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
    \ static_cast<R>(x);\n#endif\n}\n\n// clang-format on\n\n#undef SATURATING_FUNC\n"
  code: "#pragma once\n\n/**\n * @file saturating.hpp\n * @brief \u98FD\u548C\u6F14\
    \u7B97 (\u7D50\u679C\u304C\u578B\u306E\u7BC4\u56F2\u3092\u8D85\u3048\u305F\u3089\
    \u3001\u305D\u306E\u578B\u306E\u6700\u5927\u5024\u30FB\u6700\u5C0F\u5024\u306B\
    \u4E38\u3081\u308B)\n */\n\n#include <cassert>\n#include <limits>\n#include <numeric>\n\
    #include <type_traits>\n#include <utility>\n\n#if __cplusplus >= 202002L\n#include\
    \ <concepts>\n#endif\n\nnamespace internal_saturating {\ntemplate <class T>\n\
    struct is_character : std::false_type {};\ntemplate <>\nstruct is_character<char>\
    \ : std::true_type {};\ntemplate <>\nstruct is_character<wchar_t> : std::true_type\
    \ {};\ntemplate <>\nstruct is_character<char16_t> : std::true_type {};\ntemplate\
    \ <>\nstruct is_character<char32_t> : std::true_type {};\n#ifdef __cpp_char8_t\n\
    template <>\nstruct is_character<char8_t> : std::true_type {};\n#endif\n\n// bool\
    \ \u3068\u6587\u5B57\u578B\u3092\u9664\u304F\u6574\u6570\u578B (C++26 \u306E std::add_sat\
    \ \u306A\u3069\u3068\u540C\u3058\u6761\u4EF6)\n#if __cplusplus >= 202002L\ntemplate\
    \ <class T>\nconcept integer = std::integral<T> && !std::same_as<std::remove_cv_t<T>,\
    \ bool> && !is_character<std::remove_cv_t<T>>::value;\n\nusing std::cmp_greater;\n\
    using std::cmp_less;\n#else\ntemplate <class T>\ninline constexpr bool integer\
    \ = std::is_integral_v<T> && !std::is_same_v<std::remove_cv_t<T>, bool> && !is_character<std::remove_cv_t<T>>::value;\n\
    \n// C++20 \u306E std::cmp_less \u3068\u540C\u3058 (\u7B26\u53F7\u306E\u6709\u7121\
    \u304C\u9055\u3063\u3066\u3082\u5024\u3068\u3057\u3066\u6BD4\u3079\u308B)\ntemplate\
    \ <class T, class U>\nconstexpr bool cmp_less(T t, U u) noexcept {\n    if constexpr\
    \ (std::is_signed_v<T> == std::is_signed_v<U>) {\n        return t < u;\n    }\
    \ else if constexpr (std::is_signed_v<T>) {\n        return t < 0 || std::make_unsigned_t<T>(t)\
    \ < u;\n    } else {\n        return u >= 0 && t < std::make_unsigned_t<U>(u);\n\
    \    }\n}\ntemplate <class T, class U>\nconstexpr bool cmp_greater(T t, U u) noexcept\
    \ {\n    return cmp_less(u, t);\n}\n#endif\n}  // namespace internal_saturating\n\
    \n// C++20 \u3067\u306F requires \u3067\u3001C++17 \u3067\u306F\u623B\u308A\u5024\
    \u306E enable_if \u3067\u6574\u6570\u578B\u306B\u5236\u9650\u3059\u308B\n#if __cplusplus\
    \ >= 202002L\n#define SATURATING_FUNC(cond, R) requires(cond) inline constexpr\
    \ R\n#else\n#define SATURATING_FUNC(cond, R) inline constexpr std::enable_if_t<(cond),\
    \ R>\n#endif\n\n// clang-format \u306F SATURATING_FUNC \u3092\u623B\u308A\u5024\
    \u306E\u578B\u3068\u8AAD\u3081\u305A\u3001\u95A2\u6570\u540D\u306E\u524D\u3067\
    \u6539\u884C\u3057\u3066\u3057\u307E\u3046\u306E\u3067\u6574\u5F62\u3057\u306A\
    \u3044\n// clang-format off\n\n/**\n * @brief x + y \u3092 T \u306E\u7BC4\u56F2\
    \u306B\u4E38\u3081\u308B\n */\ntemplate <class T>\nSATURATING_FUNC(internal_saturating::integer<T>,\
    \ T) saturating_add(T x, T y) noexcept {\n#ifdef __cpp_lib_saturation_arithmetic\n\
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
    \ static_cast<R>(x);\n#endif\n}\n\n// clang-format on\n\n#undef SATURATING_FUNC\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/saturating.hpp
  requiredBy: []
  timestamp: '2026-10-19 12:29:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/math/saturating.test.cpp
documentation_of: src/math/saturating.hpp
layout: document
title: "\u98FD\u548C\u6F14\u7B97"
---

整数の四則演算と型変換で、結果が型の範囲を超えたら、その型の最大値・最小値に丸める関数です。オーバーフローせずに `INF` 同士を足したいときなどに使います。どれも `constexpr` で、C++26 の `std::add_sat`、`std::sub_sat`、`std::mul_sat`、`std::div_sat`、`std::saturate_cast` と同じ値を返します。

```cpp
saturating_add(2000000000, 2000000000);  // 2147483647
saturating_sub(0u, 1u);                  // 0
saturating_mul(-3000000000LL, 4000000000LL);  // LLONG_MIN
saturating_div(INT_MIN, -1);             // 2147483647
saturating_cast<uint8_t>(300);           // 255
saturating_cast<int>(-5LL);              // -5
```

## 関数

引数と戻り値は、bool と文字型 (`char` など) を除く整数型です。四則演算の 2 つの引数は同じ型でなければなりません (`saturating_add(x, 1)` で `x` が `long long` なら `1LL` と書く)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `saturating_add(x, y)` | $x + y$ を範囲に丸める | $O(1)$ |
| `saturating_sub(x, y)` | $x - y$ を範囲に丸める (符号なしなら下限は 0) | $O(1)$ |
| `saturating_mul(x, y)` | $xy$ を範囲に丸める | $O(1)$ |
| `saturating_div(x, y)` | `x / y` (0 方向に切り捨て)。あふれるのは符号付きの最小値 / -1 だけで、そのときは最大値 ($y \ne 0$) | $O(1)$ |
| `saturating_cast<R>(x)` | `x` を `R` に変換し、範囲外なら `R` の最大値・最小値に丸める (符号の有無が違っても値として比べる) | $O(1)$ |

C++26 では `std::` 版を呼びます。C++17・C++20 では `__builtin_add_overflow` などで実装し、`saturating_cast` の比較には C++20 の `std::cmp_less` を使います (C++17 では同じものを自前で用意しています)。引数の型の制限は、C++20 では `requires`、C++17 では `enable_if` で行うので、整数型でない引数はオーバーロードの候補から外れます。

## 関連

- 整数の切り捨て・切り上げの割り算は [汎用関数](../base/functions.hpp) の `floordiv`、`ceildiv`、`divmod`
