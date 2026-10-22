---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F (NTT)"
  - icon: ':heavy_check_mark:'
    path: src/math/linear-recurrence.hpp
    title: "\u7DDA\u5F62\u6F38\u5316\u5F0F (Bostan-Mori\u30FBBerlekamp-Massey)"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "#line 1 \"test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/math/linear-recurrence.hpp\"\
    \n\n/**\n * @file linear-recurrence.hpp\n * @brief \u7DDA\u5F62\u6F38\u5316\u5F0F\
    \ (Bostan-Mori \u306B\u3088\u308B\u7B2C k \u9805\u3001Berlekamp-Massey \u306B\u3088\
    \u308B\u6F38\u5316\u5F0F\u306E\u5FA9\u5143)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#line 12 \"src/math/linear-recurrence.hpp\"\n\
    \n#line 2 \"src/math/convolution.hpp\"\n\n/**\n * @file convolution.hpp\n * @brief\
    \ \u7573\u307F\u8FBC\u307F (NTT)\n */\n\n#line 9 \"src/math/convolution.hpp\"\n\
    #include <array>\n#include <cstdint>\n#include <type_traits>\n#line 14 \"src/math/convolution.hpp\"\
    \n\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n */\n\n#line 11 \"src/math/modint.hpp\"\n#include <limits>\n\
    #line 14 \"src/math/modint.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n\
    \ * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <iterator>\n#include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace\
    \ internal_traits {\nusing std::begin, std::end;\n\ntemplate <class T, class =\
    \ void>\nstruct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct\
    \ is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n}  // namespace internal_traits\n\ntemplate <class T>\n\
    struct is_range : internal_traits::is_range_impl<T>::type {};\ntemplate <class\
    \ T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define HAS_METHOD(func_name)\
    \                                                              \\\n    namespace\
    \ internal_traits {                                                          \
    \  \\\n    template <class T, class = void>                                  \
    \                     \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                    \\\n    template <class T>          \
    \                                                           \\\n    struct has_##func_name##_impl<T,\
    \ std::void_t<decltype(std::declval<T>().func_name())>> \\\n        : std::true_type\
    \ {};                                                               \\\n    }\
    \                                                                            \
    \          \\\n    template <class T>                                        \
    \                             \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T>::type\
    \ {};          \\\n    template <class T>                                    \
    \                                 \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                                    \\\n    namespace\
    \ internal_traits {                                                          \
    \                      \\\n    template <class T, typename U, class = void>  \
    \                                                             \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                                      \
    \  \\\n    template <class T, typename U>                                    \
    \                                         \\\n    struct has_##func_name##_impl<T,\
    \ U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>> \\\
    \n        : std::true_type {};                                               \
    \                                    \\\n    }                               \
    \                                                                           \\\
    \n    template <class T, typename U>                                         \
    \                                    \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 2 \"src/math/modular-arithmetic.hpp\"\
    \n\n/**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#line 10 \"src/math/modular-arithmetic.hpp\"\n#include <cmath>\n\
    #include <numeric>\n#include <unordered_map>\n\n/**\n * @brief a * b mod m \u3092\
    \u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\u306E\u3067 m < 2^63\
    \ \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr long long modmul(long\
    \ long a, long long b, long long m) {\n    long long res = static_cast<long long>(static_cast<__int128>(a)\
    \ * b % m);\n    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief\
    \ a^(-1) mod m \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\
    \u7D20\u3067\u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long\
    \ long a, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a +=\
    \ m;\n    long long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap\
    \ \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\
    \u308F\u305A\u306B\u66F8\u304F\n        long long t = a / b;\n        long long\
    \ c = a - t * b;\n        a = b, b = c;\n        long long w = u - t * v;\n  \
    \      u = v, v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\"\
    );\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n\
    \ mod m \u3092\u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E\
    \ -n \u4E57 (a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\
    \u3068)\u3002O(log |n|)\n */\nconstexpr long long modpow(long long a, long long\
    \ n, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n\
    \    if (n < 0) {\n        n = -n;\n        a = modinv(a, m);\n    }\n    long\
    \ long res = 1 % m;\n    while (n > 0) {\n        if (n & 1) res = modmul(res,\
    \ a, m);\n        a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n\
    }\n\n/**\n * @brief a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ x >= 0 (\u306A\u3051\u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\
    \u306B\u7D20\u3067\u306A\u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step\
    \ \u3067 O(\u221Am) \u306E\u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long\
    \ long discrete_log(long long a, long long b, long long m) {\n    assert(m >=\
    \ 1);\n    a %= m, b %= m;\n    if (a < 0) a += m;\n    if (b < 0) b += m;\n \
    \   if (m == 1) return 0;\n    // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\
    \u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add\
    \ / (\u5272\u3063\u305F gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0,\
    \ g;\n    while ((g = std::gcd(a, m)) > 1) {\n        if (b == k) return add;\n\
    \        if (b % g != 0) return -1;\n        b /= g, m /= g, add++;\n        k\
    \ = modmul(k, a / g, m);\n    }\n    // k a^x \u2261 b \u3092 x = n p - q (1 <=\
    \ p <= n\u30010 <= q <= n) \u3068\u66F8\u3044\u3066\u89E3\u304F\n    const long\
    \ long n = static_cast<long long>(std::sqrt(static_cast<long double>(m))) + 1;\n\
    \    std::unordered_map<long long, long long> baby;\n    baby.reserve(2 * n +\
    \ 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\u3001\
    \u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\u3059\
    \u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long long\
    \ q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n    const\
    \ long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k; p <= n;\
    \ p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
    \        if (it != baby.end()) return n * p - it->second + add;\n    }\n    return\
    \ -1;\n}\n\n/**\n * @brief \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^2 \u2261\
    \ a (mod p) \u3068\u306A\u308B x \u306E\u3046\u3061\u5C0F\u3055\u3044\u65B9 (\u306A\
    \u3051\u308C\u3070 -1)\n * @note \u3082\u3046\u4E00\u65B9\u306E\u89E3\u306F p\
    \ - x\u3002Tonelli-Shanks \u3067 O(log^2 p)\n */\ninline long long sqrt_mod(long\
    \ long a, long long p) {\n    assert(p >= 2);\n    a %= p;\n    if (a < 0) a +=\
    \ p;\n    if (a == 0 || p == 2) return a;\n    // \u30AA\u30A4\u30E9\u30FC\u306E\
    \u898F\u6E96: a^((p-1)/2) \u304C 1 \u3067\u306A\u3051\u308C\u3070\u5E73\u65B9\u975E\
    \u5270\u4F59\n    if (modpow(a, (p - 1) / 2, p) != 1) return -1;\n    long long\
    \ q = p - 1, s = 0;\n    while (q % 2 == 0) q /= 2, s++;\n    // \u5E73\u65B9\u975E\
    \u5270\u4F59 z \u3092\u63A2\u3059\n    long long z = 2;\n    while (modpow(z,\
    \ (p - 1) / 2, p) != p - 1) z++;\n    long long c = modpow(z, q, p), t = modpow(a,\
    \ q, p), r = modpow(a, (q + 1) / 2, p);\n    // r^2 = a t \u3092\u4FDD\u3061\u306A\
    \u304C\u3089\u3001t \u306E\u4F4D\u6570\u3092\u4E0B\u3052\u3066\u3044\u304F\n \
    \   while (t != 1) {\n        long long i = 0, tt = t;\n        while (tt != 1)\
    \ tt = modmul(tt, tt, p), i++;\n        long long b = c;\n        for (long long\
    \ j = 0; j < s - i - 1; j++) b = modmul(b, b, p);\n        s = i;\n        c =\
    \ modmul(b, b, p);\n        t = modmul(t, c, p);\n        r = modmul(r, b, p);\n\
    \    }\n    return std::min(r, p - r);\n}\n#line 17 \"src/math/convolution.hpp\"\
    \n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\n */\nnamespace internal_convolution\
    \ {\n/**\n * @brief \u539F\u5B50\u6839\n * @param MOD int\n * @return int\n */\n\
    inline int calc_primitive_root(int MOD) {\n    if (MOD == 2) return 1;\n    if\
    \ (MOD == 167772161) return 3;\n    if (MOD == 469762049) return 3;\n    if (MOD\
    \ == 754974721) return 11;\n    if (MOD == 998244353) return 3;\n    int divs[20]\
    \ = {};\n    divs[0] = 2;\n    int cnt = 1;\n    long long x = (MOD - 1) >> 1;\n\
    \    while (x % 2 == 0) x >>= 1;\n    for (long long i = 3; i * i <= x; i += 2)\
    \ {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) divs[cnt++] = x;\n  \
    \  for (int g = 2;; ++g) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (modpow(g, (MOD - 1) / divs[i], MOD) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\
    \u306E\u30B5\u30A4\u30BA\u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\n */\n\
    inline int get_fft_size(int N, int M) {\n    int size = 1;\n    while (size <\
    \ N + M - 1) size <<= 1;\n    return size;\n}\n\n/**\n * @brief x \u306E\u672B\
    \u5C3E\u306E 0 \u306E\u500B\u6570 (x > 0)\n */\nconstexpr int countr_zero(unsigned\
    \ int x) {\n    int k = 0;\n    while (!(x & 1)) x >>= 1, k++;\n    return k;\n\
    }\n\ntemplate <class T>\nstruct is_static_modint : std::false_type {};\ntemplate\
    \ <std::uint32_t Mod>\nstruct is_static_modint<static_modint<Mod>> : std::true_type\
    \ {};\n\n/**\n * @brief NTT \u306E\u56DE\u8EE2\u56E0\u5B50\u306E\u8868 (AtCoder\
    \ Library \u3068\u540C\u3058\u4F5C\u308A)\n *\n * root[i] \u306F 1 \u306E\u539F\
    \u59CB 2^i \u4E57\u6839\u3001rate2\u30FBrate3 \u306F\u57FA\u6570 2\u30FB4 \u306E\
    \u30D0\u30BF\u30D5\u30E9\u30A4\u3067\u6B21\u306E\u30D6\u30ED\u30C3\u30AF\u306B\
    \u9032\u3080\u3068\u304D\u306B\u639B\u3051\u308B\u5024\n */\ntemplate <class mint>\n\
    struct FFTInfo {\n    static constexpr int rank2 = countr_zero(mint::mod() - 1);\n\
    \    std::array<mint, rank2 + 1> root, iroot;\n    std::array<mint, std::max(0,\
    \ rank2 - 1)> rate2, irate2;\n    std::array<mint, std::max(0, rank2 - 2)> rate3,\
    \ irate3;\n\n    FFTInfo() {\n        const mint g = calc_primitive_root(mint::mod());\n\
    \        root[rank2] = g.pow((mint::mod() - 1) >> rank2);\n        iroot[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            iroot[i] = iroot[i +\
    \ 1] * iroot[i + 1];\n        }\n        mint prod = 1, iprod = 1;\n        for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n            rate2[i] = root[i + 2] * prod;\n\
    \            irate2[i] = iroot[i + 2] * iprod;\n            prod *= iroot[i +\
    \ 2];\n            iprod *= root[i + 2];\n        }\n        prod = 1, iprod =\
    \ 1;\n        for (int i = 0; i <= rank2 - 3; i++) {\n            rate3[i] = root[i\
    \ + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n            prod\
    \ *= iroot[i + 3];\n            iprod *= root[i + 3];\n        }\n    }\n};\n\n\
    /**\n * @brief NTT (\u30D3\u30C3\u30C8\u53CD\u8EE2\u306E\u4E26\u3079\u66FF\u3048\
    \u3092\u3057\u306A\u3044\u3002\u7D50\u679C\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\
    \u3057\u305F\u9806\u306B\u4E26\u3076)\u3002\u57FA\u6570 4 \u306E\u30D0\u30BF\u30D5\
    \u30E9\u30A4\u3092\u4F7F\u3046\n * a \u306E\u9577\u3055\u306F 2 \u306E\u3079\u304D\
    \u4E57\u3067\u30012^rank2 \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068\n */\ntemplate\
    \ <class mint>\nvoid butterfly(std::vector<mint>& a) {\n    const int n = static_cast<int>(a.size());\n\
    \    const int h = countr_zero(n);\n    static const FFTInfo<mint> info;\n   \
    \ int len = 0;  // a[i, i + (n >> len), i + 2 * (n >> len), ...] \u306F\u5909\u63DB\
    \u6E08\u307F\n    while (len < h) {\n        if (h - len == 1) {\n           \
    \ int p = 1 << (h - len - 1);\n            mint rot = 1;\n            for (int\
    \ s = 0; s < (1 << len); s++) {\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    mint l = a[i\
    \ + offset], r = a[i + offset + p] * rot;\n                    a[i + offset] =\
    \ l + r;\n                    a[i + offset + p] = l - r;\n                }\n\
    \                if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len++;\n        } else {\n          \
    \  int p = 1 << (h - len - 2);\n            mint rot = 1, imag = info.root[2];\n\
    \            const unsigned long long mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot, rot3 = rot2 * rot;\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    unsigned long\
    \ long a0 = a[i + offset].val();\n                    unsigned long long a1 =\
    \ 1ULL * a[i + offset + p].val() * rot.val();\n                    unsigned long\
    \ long a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n               \
    \     unsigned long long a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n\
    \                    unsigned long long a1na3imag = 1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    unsigned long long na2 = mod2 - a2;\n   \
    \                 a[i + offset] = mint(a0 + a2 + a1 + a3);\n                 \
    \   a[i + offset + p] = mint(a0 + a2 + (2 * mod2 - (a1 + a3)));\n            \
    \        a[i + offset + 2 * p] = mint(a0 + na2 + a1na3imag);\n               \
    \     a[i + offset + 3 * p] = mint(a0 + na2 + (mod2 - a1na3imag));\n         \
    \       }\n                if (s + 1 != (1 << len)) rot *= info.rate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief butterfly \u306E\u9006\u5909\u63DB (n \u3067\u5272\u3089\u306A\u3044\
    )\n */\ntemplate <class mint>\nvoid butterfly_inv(std::vector<mint>& a) {\n  \
    \  const int n = static_cast<int>(a.size());\n    const int h = countr_zero(n);\n\
    \    static const FFTInfo<mint> info;\n    int len = h;\n    while (len) {\n \
    \       if (len == 1) {\n            int p = 1 << (h - len);\n            mint\
    \ irot = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n      \
    \          int offset = s << (h - len + 1);\n                for (int i = 0; i\
    \ < p; i++) {\n                    mint l = a[i + offset], r = a[i + offset +\
    \ p];\n                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = mint(1ULL * (mint::mod() + l.val() - r.val()) * irot.val());\n      \
    \          }\n                if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len--;\n        } else {\n          \
    \  int p = 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n\
    \            for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint\
    \ irot2 = irot * irot, irot3 = irot2 * irot;\n                int offset = s <<\
    \ (h - len + 2);\n                for (int i = 0; i < p; i++) {\n            \
    \        unsigned long long a0 = a[i + offset].val();\n                    unsigned\
    \ long long a1 = a[i + offset + p].val();\n                    unsigned long long\
    \ a2 = a[i + offset + 2 * p].val();\n                    unsigned long long a3\
    \ = a[i + offset + 3 * p].val();\n                    unsigned long long a2na3iimag\
    \ = mint((mint::mod() + a2 - a3) * iimag.val()).val();\n                    a[i\
    \ + offset] = mint(a0 + a1 + a2 + a3);\n                    a[i + offset + p]\
    \ = mint((a0 + (mint::mod() - a1) + a2na3iimag) * irot.val());\n             \
    \       a[i + offset + 2 * p] = mint((a0 + a1 + (mint::mod() - a2) + (mint::mod()\
    \ - a3)) * irot2.val());\n                    a[i + offset + 3 * p] = mint((a0\
    \ + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) * irot3.val());\n       \
    \         }\n                if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len -= 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief NTT \u3067\u7573\u307F\u8FBC\u3080 (\u6CD5\u306F\u7D20\u6570\u3067\u3001\
    \u9577\u3055 N + M - 1 \u4EE5\u4E0A\u306E 2 \u306E\u3079\u304D\u4E57\u304C 2^rank2\
    \ \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068)\n * same \u306A\u3089 B \u306F A\
    \ \u3068\u540C\u3058\u3068\u307F\u306A\u3057\u3001\u5909\u63DB\u3092 1 \u56DE\u7701\
    \u304F\n */\ntemplate <class mint>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b, bool same = false) {\n    const int n = static_cast<int>(a.size()),\
    \ m = static_cast<int>(b.size());\n    const int z = get_fft_size(n, m);\n   \
    \ a.resize(z);\n    butterfly(a);\n    if (same) {\n        for (int i = 0; i\
    \ < z; i++) a[i] *= a[i];\n    } else {\n        b.resize(z);\n        butterfly(b);\n\
    \        for (int i = 0; i < z; i++) a[i] *= b[i];\n    }\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    const mint iz = mint(z).inv();\n    for (int i\
    \ = 0; i < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n/**\n * @brief mint\
    \ \u3067\u76F4\u63A5 NTT \u3067\u304D\u308B\u304B (static_modint \u3067\u3001\u6CD5\
    \u304C\u7D20\u6570\u3067\u30012^rank2 \u304C\u9577\u3055 z \u4EE5\u4E0A)\n */\n\
    template <class mint>\nconstexpr bool ntt_friendly(int z) {\n    if constexpr\
    \ (is_static_modint<mint>::value) {\n        return internal_modint::is_prime32(mint::mod())\
    \ && mint::mod() > 2 && (mint::mod() - 1) % z == 0;\n    } else {\n        return\
    \ false;\n    }\n}\n\n/**\n * @brief \u9577\u3055 61 \u4EE5\u4E0A\u306E\u7573\u307F\
    \u8FBC\u307F\u3092 mint \u3067\u76F4\u63A5 NTT \u3067\u304D\u308B\u898B\u8FBC\u307F\
    \u304C\u3042\u308B\u304B (\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\u306B\u6C7A\u307E\
    \u308B\u90E8\u5206\u3060\u3051)\n * \u507D\u306A\u3089 NTT \u306E\u95A2\u6570\u3092\
    \u5B9F\u4F53\u5316\u3057\u306A\u3044 (\u6CD5 - 1 \u306E 2 \u306E\u6307\u6570\u304C\
    \u5C0F\u3055\u3044\u3068\u3001\u56DE\u8EE2\u56E0\u5B50\u306E\u8868\u306E\u5916\
    \u3092\u8AAD\u3080\u3068\u3044\u3046\u8AA4\u3063\u305F\u8B66\u544A\u304C\u51FA\
    \u308B\u305F\u3081)\n */\ntemplate <class mint>\nconstexpr bool ntt_candidate()\
    \ {\n    if constexpr (is_static_modint<mint>::value) {\n        return countr_zero(mint::mod()\
    \ - 1) >= 7;\n    } else {\n        return false;\n    }\n}\n\nstatic constexpr\
    \ int MOD0 = 754974721;\nstatic constexpr int MOD1 = 167772161;\nstatic constexpr\
    \ int MOD2 = 469762049;\nusing mint0 = static_modint<MOD0>;\nusing mint1 = static_modint<MOD1>;\n\
    using mint2 = static_modint<MOD2>;\nstatic const mint1 imod0 = 95869806;    //\
    \ modinv(MOD0, MOD1);\nstatic const mint2 imod1 = 104391568;   // modinv(MOD1,\
    \ MOD2);\nstatic const mint2 imod01 = 187290749;  // imod1 / MOD0;\n\n/**\n *\
    \ @brief \u914D\u5217\u306E\u30B5\u30A4\u30BA\u304C\u5C0F\u3055\u3044\u3068\u304D\
    \u306E\u7573\u307F\u8FBC\u307F\n * @param T mint, long long\n * @param A vector<T>\n\
    \ * @param B vector<T>\n * @return vector<T>\n */\ntemplate <class T>\nstd::vector<T>\
    \ naive(const std::vector<T>& A, const std::vector<T>& B) {\n    if (A.empty()\
    \ || B.empty()) return {};\n    int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<T> res(N + M - 1);\n    for (int i = 0; i < N; ++i)\n       \
    \ for (int j = 0; j < M; ++j)\n            res[i + j] += A[i] * B[j];\n    return\
    \ res;\n}\n};  // namespace internal_convolution\n\nnamespace internal_convolution\
    \ {\n/**\n * @brief 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\u3067\u5024 (0 \u4EE5\u4E0A MOD0 MOD1 MOD2 \u672A\
    \u6E80) \u3092\u5FA9\u5143\u3059\u308B\n * \u5024\u306F y0 + y1 MOD0 + y2 MOD0\
    \ MOD1 (0 <= y0 < MOD0\u30010 <= y1 < MOD1\u30010 <= y2 < MOD2) \u306E\u5F62\u306B\
    \u306A\u308A\u3001\u5404\u9805\u3092 f(y0, y1, y2) \u3067\u7D44\u307F\u7ACB\u3066\
    \u308B\n * A \u3068 B \u304C\u540C\u3058\u914D\u5217\u306A\u3089\u3001\u5909\u63DB\
    \u3092 1 \u56DE\u7701\u304F\n */\ntemplate <class T, class R, class F>\nstd::vector<R>\
    \ convolution_crt(const std::vector<T>& A, const std::vector<T>& B, F f) {\n \
    \   const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<mint0> a0(N), b0(M);\n    std::vector<mint1> a1(N), b1(M);\n\
    \    std::vector<mint2> a2(N), b2(M);\n    for (int i = 0; i < N; ++i) a0[i] =\
    \ A[i], a1[i] = A[i], a2[i] = A[i];\n    for (int i = 0; i < M; ++i) b0[i] = B[i],\
    \ b1[i] = B[i], b2[i] = B[i];\n    const bool same = &A == &B;\n    auto c0 =\
    \ convolution_fft(std::move(a0), std::move(b0), same);\n    auto c1 = convolution_fft(std::move(a1),\
    \ std::move(b1), same);\n    auto c2 = convolution_fft(std::move(a2), std::move(b2),\
    \ same);\n    std::vector<R> res(N + M - 1);\n    for (int i = 0; i < N + M -\
    \ 1; ++i) {\n        unsigned int y0 = c0[i].val();\n        unsigned int y1 =\
    \ (imod0 * (c1[i] - y0)).val();\n        unsigned int y2 = (imod01 * (c2[i] -\
    \ y0) - imod1 * y1).val();\n        res[i] = f(y0, y1, y2);\n    }\n    return\
    \ res;\n}\n}  // namespace internal_convolution\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n *\n * static_modint \u3067\u6CD5\u304C NTT \u306B\u5411\
    \u304F\u7D20\u6570 (998244353 \u306A\u3069) \u306A\u3089\u3001\u305D\u306E\u6CD5\
    \u3067\u76F4\u63A5 NTT \u3059\u308B\u3002\n * \u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\u3067\u5FA9\u5143\u3059\u308B\n * @param A vector<mint>\n *\
    \ @param B vector<mint>\n * @return vector<mint>\n */\ntemplate <class mint>\n\
    std::vector<mint> convolution(const std::vector<mint>& A, const std::vector<mint>&\
    \ B) {\n    if (A.empty() || B.empty()) return {};\n    const int N = static_cast<int>(A.size()),\
    \ M = static_cast<int>(B.size());\n    if (std::min(N, M) <= 60) return internal_convolution::naive(A,\
    \ B);\n    const int z = internal_convolution::get_fft_size(N, M);\n    if constexpr\
    \ (internal_convolution::ntt_candidate<mint>()) {\n        if (internal_convolution::ntt_friendly<mint>(z))\
    \ return internal_convolution::convolution_fft(A, B, &A == &B);\n    }\n    std::vector<unsigned\
    \ int> a(N), b(M);\n    for (int i = 0; i < N; ++i) a[i] = A[i].val();\n    for\
    \ (int i = 0; i < M; ++i) b[i] = B[i].val();\n    const mint mod0 = internal_convolution::MOD0,\
    \ mod01 = mod0 * internal_convolution::MOD1;\n    return internal_convolution::convolution_crt<unsigned\
    \ int, mint>(a, &A == &B ? a : b, [&](unsigned int y0, unsigned int y1, unsigned\
    \ int y2) {\n        return mod01 * y2 + mod0 * y1 + y0;\n    });\n}\n\n/**\n\
    \ * @brief long long\u306E\u7573\u307F\u8FBC\u307F\n * \u7D50\u679C\u306E\u5404\
    \u9805\u306E\u7D76\u5BFE\u5024\u304C MOD0 MOD1 MOD2 / 2 (\u7D04 3 * 10^25) \u672A\
    \u6E80\u3067\u3001long long \u306B\u53CE\u307E\u308B\u3053\u3068\n * @param A\
    \ vector<long long>\n * @param B vector<long long>\n * @return vector<long long>\n\
    \ */\ninline std::vector<long long> convolution_ll(const std::vector<long long>&\
    \ A, const std::vector<long long>& B) {\n    if (A.empty() || B.empty()) return\
    \ {};\n    const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) <= 60) return internal_convolution::naive(A, B);\n   \
    \ static const long long mod0 = internal_convolution::MOD0, mod01 = mod0 * internal_convolution::MOD1;\n\
    \    static const __int128_t mod012 = static_cast<__int128_t>(mod01) * internal_convolution::MOD2;\n\
    \    return internal_convolution::convolution_crt<long long, long long>(A, B,\
    \ [&](unsigned int y0, unsigned int y1, unsigned int y2) {\n        __int128_t\
    \ tmp = static_cast<__int128_t>(mod01) * y2 + static_cast<__int128_t>(mod0) *\
    \ y1 + y0;\n        return static_cast<long long>(tmp < (mod012 >> 1) ? tmp :\
    \ tmp - mod012);\n    });\n}\n#line 14 \"src/math/linear-recurrence.hpp\"\n\n\
    namespace internal_linear_recurrence {\n\n/**\n * @brief bostan_mori \u3092 NTT\
    \ \u3057\u305F\u5024\u306E\u307E\u307E\u9032\u3081\u308B\u7248 (\u6CD5\u304C NTT\
    \ \u306B\u5411\u304F\u7D20\u6570\u306E\u3068\u304D)\n * \u9577\u3055 2N \u3067\
    \u5909\u63DB\u3059\u308B\u3068\u3001butterfly \u306E\u7D50\u679C\u306F\u30D3\u30C3\
    \u30C8\u53CD\u8EE2\u3057\u305F\u9806\u306B\u4E26\u3073\u3001\u4F4D\u7F6E 2i \u3068\
    \ 2i+1 \u306F\u70B9 w \u3068 -w \u3067\u306E\u5024\u306B\u306A\u308B\u3002\n *\
    \ \u305D\u3053\u3067 Q(-x) \u306F\u96A3\u3069\u3046\u3057\u3092\u5165\u308C\u66FF\
    \u3048\u308B\u3060\u3051\u3067\u5F97\u3089\u308C\u3001\u5076\u6570\u6B21\u30FB\
    \u5947\u6570\u6B21\u306E\u90E8\u5206\u306E\u5024 (\u9577\u3055 N \u306E\u5909\u63DB\
    ) \u3082\n * (F(w) + F(-w)) / 2\u3001(F(w) - F(-w)) / (2w) \u3067\u6C42\u307E\u308B\
    \u3002\u6B21\u306E\u6BB5\u306E\u9577\u3055 2N \u306E\u5909\u63DB\u306F\u3001\n\
    \ * \u6B8B\u308A\u306E\u534A\u5206 (\u70B9 w \u03C9_{2N} \u3067\u306E\u5024) \u3060\
    \u3051\u3092\u9006\u5909\u63DB\u3068\u5909\u63DB 1 \u56DE\u305A\u3064\u3067\u4F5C\
    \u308B\u30021 \u6BB5\u3042\u305F\u308A\u306E NTT \u306F\u9577\u3055 2N \u3092\
    \ 2 \u56DE\u5206\u307B\u3069\u306B\u306A\u308B\n */\ntemplate <typename mint>\n\
    mint bostan_mori_ntt(std::vector<mint> P, std::vector<mint> Q, long long k, int\
    \ h) {\n    using namespace internal_convolution;\n    static const FFTInfo<mint>\
    \ info;\n    const int N = 1 << h;\n    // half_iw[i] = 1 / (2w) (w \u306F\u9577\
    \u3055 2N \u306E\u4F4D\u7F6E 2i \u306E\u70B9 \u03C9_{2N}^{rev[i]})\u3001tw[i]\
    \ = \u03C9_{2N}^i / N\n    const mint inv2 = mint(2).inv();\n    std::vector<int>\
    \ rev(N);\n    for (int i = 1; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i &\
    \ 1) << (h - 1));\n    std::vector<mint> pw(N), half_iw(N), tw(N);\n    pw[0]\
    \ = 1, tw[0] = mint(N).inv();\n    for (int i = 1; i < N; i++) {\n        pw[i]\
    \ = pw[i - 1] * info.iroot[h + 1];\n        tw[i] = tw[i - 1] * info.root[h +\
    \ 1];\n    }\n    for (int i = 0; i < N; i++) half_iw[i] = pw[rev[i]] * inv2;\n\
    \    P.resize(2 * N), Q.resize(2 * N);\n    butterfly(P), butterfly(Q);\n    //\
    \ \u9577\u3055 N \u306E\u5909\u63DB f \u304B\u3089\u3001\u9577\u3055 2N \u306E\
    \u5909\u63DB (\u524D\u534A\u306F f \u306E\u307E\u307E) \u3092\u4F5C\u308B\n  \
    \  auto extend = [&](std::vector<mint>& f) {\n        std::vector<mint> g(f.begin(),\
    \ f.begin() + N);\n        butterfly_inv(g);\n        for (int i = 0; i < N; i++)\
    \ g[i] *= tw[i];\n        butterfly(g);\n        std::copy(g.begin(), g.end(),\
    \ f.begin() + N);\n    };\n    while (true) {\n        for (int i = 0; i < N;\
    \ i++) {\n            const mint p0 = P[2 * i], p1 = P[2 * i + 1], q0 = Q[2 *\
    \ i], q1 = Q[2 * i + 1];\n            // U = P(x) Q(-x) \u306E w, -w \u3067\u306E\
    \u5024\u306F p0 q1, p1 q0\u3002V = Q(x) Q(-x) \u306F\u3069\u3061\u3089\u3082 q0\
    \ q1\n            const mint u0 = p0 * q1, u1 = p1 * q0;\n            P[i] = (k\
    \ & 1) ? (u0 - u1) * half_iw[i] : (u0 + u1) * inv2;\n            Q[i] = q0 * q1;\n\
    \        }\n        k >>= 1;\n        if (k == 0) break;\n        extend(P), extend(Q);\n\
    \    }\n    // \u5B9A\u6570\u9805\u306F\u9577\u3055 N \u306E\u5909\u63DB\u306E\
    \u5024\u306E\u548C\u306E 1/N \u306A\u306E\u3067\u3001\u6BD4\u306F\u548C\u306E\u6BD4\
    \u306B\u306A\u308B\n    mint p = 0, q = 0;\n    for (int i = 0; i < N; i++) p\
    \ += P[i], q += Q[i];\n    return p / q;\n}\n\n}  // namespace internal_linear_recurrence\n\
    \n/**\n * @brief [x^k] P(x) / Q(x) (Q[0] != 0) \u3092 Bostan-Mori \u6CD5\u3067\
    \u6C42\u3081\u308B O(d log d log k) (d \u306F P, Q \u306E\u9577\u3055)\n * P(x)\
    \ / Q(x) = P(x) Q(-x) / (Q(x) Q(-x)) \u3067\u3001\u5206\u6BCD\u306F x^2 \u306E\
    \u591A\u9805\u5F0F\u306B\u306A\u308B\u306E\u3067\u3001k \u306E\u5076\u5947\u3067\
    \u5206\u5B50\u306E\u4FC2\u6570\u3092\u534A\u5206\u306B\u7D5E\u3063\u3066 k \u3092\
    \u534A\u5206\u306B\u3059\u308B\n */\ntemplate <typename mint>\nmint bostan_mori(std::vector<mint>\
    \ P, std::vector<mint> Q, long long k) {\n    assert(!Q.empty() && Q[0] != 0 &&\
    \ k >= 0);\n    if constexpr (internal_convolution::ntt_candidate<mint>()) {\n\
    \        const int n = static_cast<int>(std::max(P.size(), Q.size()));\n     \
    \   if (k > 0 && n > 60) {\n            int h = 0;\n            while ((1 << h)\
    \ < n) h++;\n            if (internal_convolution::ntt_friendly<mint>(2 << h))\
    \ return internal_linear_recurrence::bostan_mori_ntt(std::move(P), std::move(Q),\
    \ k, h);\n        }\n    }\n    while (k > 0 && !P.empty()) {\n        std::vector<mint>\
    \ Qm = Q;\n        for (size_t i = 1; i < Qm.size(); i += 2) Qm[i] = -Qm[i];\n\
    \        std::vector<mint> U = convolution(P, Qm), V = convolution(Q, Qm);\n \
    \       P.clear(), Q.clear();\n        for (size_t i = k & 1; i < U.size(); i\
    \ += 2) P.push_back(U[i]);\n        for (size_t i = 0; i < V.size(); i += 2) Q.push_back(V[i]);\n\
    \        k >>= 1;\n    }\n    if (P.empty()) return mint(0);\n    // k = 0 \u306A\
    \u3089 P / Q \u306E\u5B9A\u6570\u9805\n    return P[0] / Q[0];\n}\n\n/**\n * @brief\
    \ a_i = c_1 a_{i-1} + c_2 a_{i-2} + ... + c_d a_{i-d} (i >= d) \u3092\u6E80\u305F\
    \u3059\u6570\u5217\u306E\u7B2C k \u9805 (0-indexed) O(d log d log k)\n * @param\
    \ a \u521D\u3081\u306E d \u9805 a_0, ..., a_{d-1}\n * @param c \u4FC2\u6570 c_1,\
    \ ..., c_d\n */\ntemplate <typename mint>\nmint linear_recurrence_kth(const std::vector<mint>&\
    \ a, const std::vector<mint>& c, long long k) {\n    assert(a.size() == c.size()\
    \ && k >= 0);\n    const size_t d = c.size();\n    if (d == 0) return mint(0);\n\
    \    // \u6BCD\u95A2\u6570 A(x) = P(x) / Q(x)\u3002Q(x) = 1 - c_1 x - ... - c_d\
    \ x^d\u3001P(x) = A(x) Q(x) mod x^d\n    std::vector<mint> Q(d + 1);\n    Q[0]\
    \ = 1;\n    for (size_t j = 0; j < d; j++) Q[j + 1] = -c[j];\n    std::vector<mint>\
    \ P = convolution(a, Q);\n    P.resize(d);\n    return bostan_mori(P, Q, k);\n\
    }\n\n/**\n * @brief \u6570\u5217 a \u3092\u6E80\u305F\u3059\u6700\u77ED\u306E\u7DDA\
    \u5F62\u6F38\u5316\u5F0F\u306E\u4FC2\u6570 c_1, ..., c_d (a_i = c_1 a_{i-1} +\
    \ ... + c_d a_{i-d}\u3001d <= i < |a|) O(|a|^2)\n * mint \u306F\u4F53\u3067\u3042\
    \u308B\u3053\u3068\u3002\u9577\u3055 2d \u4EE5\u4E0A\u306E\u9805\u304C\u3042\u308C\
    \u3070\u3001d \u9805\u9593\u306E\u6F38\u5316\u5F0F\u3092\u6B63\u3057\u304F\u5FA9\
    \u5143\u3067\u304D\u308B\n */\ntemplate <typename mint>\nstd::vector<mint> berlekamp_massey(const\
    \ std::vector<mint>& a) {\n    // C(x) = 1 - c_1 x - ... : \u4ECA\u306E\u6F38\u5316\
    \u5F0F\u3001B(x): \u6700\u5F8C\u306B\u9577\u3055\u304C\u5909\u308F\u308B\u76F4\
    \u524D\u306E\u6F38\u5316\u5F0F\n    std::vector<mint> C = {1}, B = {1};\n    mint\
    \ b = 1;  // B \u3092\u4F7F\u3063\u305F\u3068\u304D\u306E\u98DF\u3044\u9055\u3044\
    \n    size_t len = 0, shift = 1;\n    for (size_t i = 0; i < a.size(); i++) {\n\
    \        // \u4ECA\u306E\u6F38\u5316\u5F0F\u3067 a_i \u3092\u4E88\u6E2C\u3057\u305F\
    \u3068\u304D\u306E\u98DF\u3044\u9055\u3044\n        mint delta = 0;\n        for\
    \ (size_t j = 0; j <= len && j < C.size(); j++) delta += C[j] * a[i - j];\n  \
    \      if (delta == 0) {\n            shift++;\n            continue;\n      \
    \  }\n        // C(x) -= (delta / b) x^shift B(x) \u3067\u98DF\u3044\u9055\u3044\
    \u3092\u6D88\u3059\n        std::vector<mint> T = C;\n        mint f = delta /\
    \ b;\n        if (C.size() < B.size() + shift) C.resize(B.size() + shift);\n \
    \       for (size_t j = 0; j < B.size(); j++) C[j + shift] -= f * B[j];\n    \
    \    if (2 * len <= i) {\n            len = i + 1 - len;\n            B = T, b\
    \ = delta, shift = 1;\n        } else {\n            shift++;\n        }\n   \
    \ }\n    C.resize(len + 1);\n    std::vector<mint> res(len);\n    for (size_t\
    \ j = 0; j < len; j++) res[j] = -C[j + 1];\n    return res;\n}\n#line 8 \"test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int d;\n    long long k;\n    std::cin\
    \ >> d >> k;\n    std::vector<mint> a(d), c(d);\n    for (auto& x : a) std::cin\
    \ >> x;\n    for (auto& x : c) std::cin >> x;\n    std::cout << linear_recurrence_kth(a,\
    \ c, k) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/math/linear-recurrence.hpp\"\
    \n#include \"../../../src/math/modint.hpp\"\n\nusing mint = modint998244353;\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int d;\n    long long k;\n    std::cin >> d >> k;\n    std::vector<mint>\
    \ a(d), c(d);\n    for (auto& x : a) std::cin >> x;\n    for (auto& x : c) std::cin\
    \ >> x;\n    std::cout << linear_recurrence_kth(a, c, k) << '\\n';\n}\n"
  dependsOn:
  - src/math/linear-recurrence.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 20:04:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp
- /verify/test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp.html
title: test/yosupo/other/kth-term-of-linearly-recurrent-sequence.test.cpp
---
