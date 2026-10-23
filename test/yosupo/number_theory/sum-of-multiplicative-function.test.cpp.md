---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/prime-counting.hpp
    title: "\u7D20\u6570\u306E\u500B\u6570\u30FB\u7D20\u6570\u306E\u548C (Lucy DP)\u30FB\
      \u4E57\u6CD5\u7684\u95A2\u6570\u306E\u548C"
  - icon: ':heavy_check_mark:'
    path: src/math/sqrt.hpp
    title: "\u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839"
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
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
  bundledCode: "#line 1 \"test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \n\n#include <iostream>\n\n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n\
    \ * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067\
    \ mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#include <cassert>\n#include\
    \ <cstdint>\n#line 11 \"src/math/modint.hpp\"\n#include <limits>\n#include <type_traits>\n\
    #include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <iterator>\n\
    #include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
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
    using modint = dynamic_modint<-1>;\n#line 2 \"src/math/prime-counting.hpp\"\n\n\
    /**\n * @file prime-counting.hpp\n * @brief \u7D20\u6570\u306E\u500B\u6570\u30FB\
    \u7D20\u6570\u306E\u548C (Lucy DP)\n */\n\n#line 10 \"src/math/prime-counting.hpp\"\
    \n#include <vector>\n\n#line 2 \"src/math/sqrt.hpp\"\n\n/**\n * @file sqrt.hpp\n\
    \ * @brief \u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839\n */\n\n#line\
    \ 9 \"src/math/sqrt.hpp\"\n#include <cmath>\n\n/**\n * @brief floor(sqrt(n))\n\
    \ * @param n \u5E73\u65B9\u6839\u3092\u6C42\u3081\u305F\u3044\u6574\u6570 long\
    \ long \u578B\u3067 0 <= n < 2^63 \u3092\u6E80\u305F\u3059\n * @return long long\n\
    \ */\ninline long long sqrtll(long long n) {\n    assert(n >= 0);\n    // 3037000500\
    \ = ceil(sqrt(2^63))\n    long long le = 0, ri = 3037000500;\n    while (ri -\
    \ le > 1) {\n        long long mid = (le + ri) / 2;\n        if (mid * mid <=\
    \ n)\n            le = mid;\n        else\n            ri = mid;\n    }\n    return\
    \ le;\n}\n\n/**\n * @brief floor(a^(1/k))\n *\n * \u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u3067\u8FD1\u3044\u5024\u3092\u6C42\u3081\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u639B\u3051\u7B97\u3067\u78BA\
    \u304B\u3081\u3066\u5408\u308F\u305B\u308B\n * @param a 0 <= a < 2^64\n * @param\
    \ k 1 \u4EE5\u4E0A\n * @return unsigned long long\n */\ninline unsigned long long\
    \ kth_root(unsigned long long a, long long k) {\n    assert(k >= 1);\n    if (k\
    \ == 1 || a <= 1) return a;\n    if (k >= 64) return 1;  // a < 2^64 \u306A\u306E\
    \u3067\n    // x^k <= a \u304B\n    auto fits = [&](unsigned long long x) {\n\
    \        unsigned long long p = 1;\n        for (long long i = 0; i < k; i++)\
    \ {\n            if (p > a / x) return false;\n            p *= x;\n        }\n\
    \        return true;\n    };\n    unsigned long long x = static_cast<unsigned\
    \ long long>(std::pow(static_cast<long double>(a), 1.0L / k));\n    if (x == 0)\
    \ x = 1;\n    while (!fits(x)) x--;\n    while (fits(x + 1)) x++;\n    return\
    \ x;\n}\n#line 13 \"src/math/prime-counting.hpp\"\n\n/**\n * @brief \u3059\u3079\
    \u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001v \u4EE5\u4E0B\u306E\
    \u7D20\u6570 p \u306E g(p) \u306E\u548C\u3092\u6C42\u3081\u305F\u8868 (Lucy DP)\n\
    \ *\n * g \u306F\u5B8C\u5168\u4E57\u6CD5\u7684 (g(ab) = g(a) g(b)) \u3067\u3042\
    \u308B\u3053\u3068\u3002prefix(v) \u306F g(2) + g(3) + ... + g(v) (2 \u4EE5\u4E0A\
    \ v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C)\n * \u4F8B:\
    \ \u7D20\u6570\u306E\u500B\u6570\u306A\u3089 g(p) = 1\u3001prefix(v) = v - 1\u3002\
    \u7D20\u6570\u306E\u548C\u306A\u3089 g(p) = p\u3001prefix(v) = v (v + 1) / 2 -\
    \ 1\n * O(n^(3/4) / log n)\u3001\u30E1\u30E2\u30EA O(sqrt(n))\n * \u4F8B:\n *\
    \ PrimeSumTable<__int128> t(n, [](long long v) { return (__int128)v * (v + 1)\
    \ / 2 - 1; }, [](long long p) { return (__int128)p; });\n * t(n);      // n \u4EE5\
    \u4E0B\u306E\u7D20\u6570\u306E\u548C\n * t(n / 3);  // floor(n / 3) \u4EE5\u4E0B\
    \u306E\u7D20\u6570\u306E\u548C\n *\n * @tparam T \u548C\u306E\u578B (long long\u3001\
    __int128\u3001modint \u306A\u3069)\n */\ntemplate <typename T>\nclass PrimeSumTable\
    \ {\n    long long n, sq;\n    std::vector<long long> vals;  // floor(n / k) \u306E\
    \u3068\u308B\u5024\u306E\u6607\u9806 (1, 2, ..., sq \u3068\u3001sq \u3088\u308A\
    \u5927\u304D\u3044 n / k)\n    std::vector<T> sum;           // sum[i] \u306F\
    \ vals[i] \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C\n\n    long\
    \ long index(long long v) const { return v <= sq ? v - 1 : static_cast<long long>(vals.size())\
    \ - n / v; }\n\n   public:\n    /**\n     * @brief \u8868\u3092\u4F5C\u308B\n\
    \     * @pre n >= 1\n     */\n    template <typename Prefix, typename G>\n   \
    \ PrimeSumTable(long long n, Prefix prefix, G g) : n(n), sq(sqrtll(n)) {\n   \
    \     assert(n >= 1);\n        for (long long v = 1; v <= sq; v++) vals.push_back(v);\n\
    \        for (long long k = n / (sq + 1); k >= 1; k--) vals.push_back(n / k);\n\
    \        sum.resize(vals.size());\n        // \u306F\u3058\u3081\u306F 2 \u4EE5\
    \u4E0A v \u4EE5\u4E0B\u306E\u6574\u6570\u3059\u3079\u3066\u306E\u548C\u3002\u5C0F\
    \u3055\u3044\u7D20\u6570 p \u304B\u3089\u9806\u306B\u3001\u6700\u5C0F\u7D20\u56E0\
    \u6570\u304C p \u306E\u5408\u6210\u6570\u306E\u5206\u3092\u5F15\u304F\n      \
    \  for (size_t i = 0; i < vals.size(); i++) sum[i] = prefix(vals[i]);\n      \
    \  std::vector<bool> composite(sq + 1, false);\n        for (long long p = 2;\
    \ p <= sq; p++) {\n            if (composite[p]) continue;\n            for (long\
    \ long q = p * p; q <= sq; q += p) composite[q] = true;\n            const T gp\
    \ = g(p), below = sum[p - 2];  // below \u306F p - 1 \u4EE5\u4E0B\u306E\u7D20\u6570\
    \u306E\u548C\n            const long long p2 = p * p;\n            // v >= p^2\
    \ \u306E\u5024\u3092\u3001\u5927\u304D\u3044\u65B9\u304B\u3089 (floor(v / p) \u304C\
    \u307E\u3060\u66F4\u65B0\u3055\u308C\u3066\u3044\u306A\u3044\u3046\u3061\u306B\
    ) \u66F4\u65B0\u3059\u308B\n            for (long long i = static_cast<long long>(vals.size())\
    \ - 1; i >= 0 && vals[i] >= p2; i--) {\n                sum[i] -= gp * (sum[index(vals[i]\
    \ / p)] - below);\n            }\n        }\n    }\n\n    /**\n     * @brief v\
    \ \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E g(p) \u306E\u548C O(1)\n     * @pre\
    \ v = floor(n / k) \u3068\u306A\u308B k >= 1 \u304C\u3042\u308B\u3053\u3068 (v\
    \ = 0 \u3082\u53EF)\n     */\n    T operator()(long long v) const {\n        assert(0\
    \ <= v && v <= n);\n        if (v == 0) return T(0);\n        long long i = index(v);\n\
    \        assert(vals[i] == v && \"PrimeSumTable: v \u306F floor(n / k) \u306E\u5F62\
    \u3067\u3042\u308B\u3053\u3068\");\n        return sum[i];\n    }\n    /**\n \
    \    * @brief floor(n / k) \u306E\u3068\u308B\u5024\u306E\u6607\u9806\n     */\n\
    \    const std::vector<long long>& values() const { return vals; }\n};\n\n/**\n\
    \ * @brief \u3059\u3079\u3066\u306E v = floor(n / k) \u306B\u3064\u3044\u3066\u3001\
    v \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u305F\u8868\
    \ O(n^(3/4) / log n)\n * \u4F8B: auto t = prime_count_table(n); t(n / 2);\n */\n\
    inline PrimeSumTable<long long> prime_count_table(long long n) {\n    return PrimeSumTable<long\
    \ long>(n, [](long long v) { return v - 1; }, [](long long) { return 1LL; });\n\
    }\n\n/**\n * @brief n \u4EE5\u4E0B\u306E\u7D20\u6570\u306E\u500B\u6570 \u03C0\
    (n) O(n^(3/4) / log n)\n */\ninline long long prime_count(long long n) {\n   \
    \ assert(n >= 0);\n    if (n < 2) return 0;\n    return prime_count_table(n)(n);\n\
    }\n\n/**\n * @brief \u4E57\u6CD5\u7684\u95A2\u6570 f \u306E\u548C f(1) + f(2)\
    \ + ... + f(n) (min_25 \u7BE9\u306E\u5F8C\u534A) O(n^(3/4) / log n) \u7A0B\u5EA6\
    \n *\n * prime_sum(v) \u306F v \u4EE5\u4E0B\u306E\u7D20\u6570 p \u306E f(p) \u306E\
    \u548C\u3002floor(n / k) \u306E\u3068\u308B\u5024 v \u3054\u3068\u306B 1 \u56DE\
    \u305A\u3064\u547C\u3093\u3067\u8868\u306B\u3059\u308B\u3002PrimeSumTable \u3092\
    \u7D44\u307F\u5408\u308F\u305B\u3066\u4F5C\u308B\n * f_pe(p, e) \u306F f(p^e)\
    \ (p \u306F sqrt(n) \u4EE5\u4E0B\u306E\u7D20\u6570\u3001e >= 1)\u3002f(1) = 1\
    \ \u3068\u3059\u308B\n * \u4F8B: \u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u306A\u3089\
    \ \u03C6(p) = p - 1 \u306A\u306E\u3067\u3001\u7D20\u6570\u306E\u548C\u306E\u8868\
    \ s \u3068\u500B\u6570\u306E\u8868 c \u304B\u3089 prime_sum(v) = s(v) - c(v)\u3001\
    f_pe(p, e) = p^e - p^(e-1)\n * @pre n >= 0\n */\ntemplate <typename PrimeSum,\
    \ typename F>\nauto multiplicative_sum(long long n, PrimeSum prime_sum, F f_pe)\
    \ {\n    using T = std::decay_t<decltype(prime_sum(n))>;\n    assert(n >= 0);\n\
    \    if (n == 0) return T(0);\n    const long long sq = sqrtll(n);\n    std::vector<long\
    \ long> primes;\n    std::vector<bool> composite(sq + 1, false);\n    for (long\
    \ long p = 2; p <= sq; p++) {\n        if (composite[p]) continue;\n        primes.push_back(p);\n\
    \        for (long long q = p * p; q <= sq; q += p) composite[q] = true;\n   \
    \ }\n    // below[j]: primes \u306E\u5148\u982D j \u500B\u306E f(p) \u306E\u548C\
    \n    std::vector<T> below(primes.size() + 1, T(0));\n    for (size_t j = 0; j\
    \ < primes.size(); j++) below[j + 1] = below[j] + f_pe(primes[j], 1);\n    //\
    \ prime_sum \u3092 floor(n / k) \u306E\u3068\u308B\u5024\u3054\u3068\u306B 1 \u56DE\
    \u3060\u3051\u547C\u3093\u3067\u8868\u306B\u3059\u308B (v <= sq \u306F v - 1 \u756A\
    \u76EE\u3001\u305D\u308C\u3088\u308A\u5927\u304D\u3044 n / k \u306F sq + k - 1\
    \ \u756A\u76EE)\n    std::vector<T> table(2 * sq + 1);\n    for (long long v =\
    \ 1; v <= sq; v++) table[v - 1] = prime_sum(v);\n    for (long long k = 1; n /\
    \ k > sq; k++) table[sq + k - 1] = prime_sum(n / k);\n    auto at = [&](long long\
    \ x) -> const T& { return x <= sq ? table[x - 1] : table[sq + n / x - 1]; };\n\
    \    // 2 \u4EE5\u4E0A x \u4EE5\u4E0B\u3067\u3001\u6700\u5C0F\u7D20\u56E0\u6570\
    \u304C primes[j] \u4EE5\u4E0A\u306E i \u306E f(i) \u306E\u548C\n    auto rec =\
    \ [&](auto self, long long x, size_t j) -> T {\n        // primes[j] \u4EE5\u4E0A\
    \ (primes \u3092\u4F7F\u3044\u5207\u3063\u305F\u306A\u3089\u3001primes \u306E\u3069\
    \u308C\u3088\u308A\u3082\u5927\u304D\u3044) \u306E\u7D20\u6570\u304C x \u4EE5\u4E0B\
    \u306B\u306A\u3044\n        if (j < primes.size() ? primes[j] > x : !primes.empty()\
    \ && primes.back() >= x) return T(0);\n        // \u7D20\u6570\u306E\u5206\n \
    \       T res = at(x) - below[j];\n        // \u5408\u6210\u6570\u306E\u5206:\
    \ \u6700\u5C0F\u7D20\u56E0\u6570 p \u3067 p^e \u3067\u5272\u308A\u5207\u308C\u3066\
    \ p^(e+1) \u3067\u5272\u308A\u5207\u308C\u306A\u3044\u3082\u306E\u3092\u3001p^e\
    \ \u3068\u6B8B\u308A\u306E\u7A4D\u3068\u3057\u3066\u6570\u3048\u308B\n       \
    \ for (size_t k = j; k < primes.size() && primes[k] * primes[k] <= x; k++) {\n\
    \            const long long p = primes[k];\n            if (p > x / (p * p))\
    \ {\n                // p^3 > x \u306A\u3089 e = 1 \u3060\u3051\u3067\u3001\u6B8B\
    \u308A x / p (< p^2) \u306F p \u3088\u308A\u5927\u304D\u3044\u7D20\u6570\u304B\
    \ 1 \u306A\u306E\u3067\u3001\u518D\u5E30\u305B\u305A\u306B\u6C42\u3081\u308B\n\
    \                res += f_pe(p, 1) * (at(x / p) - below[k + 1]) + f_pe(p, 2);\n\
    \                continue;\n            }\n            long long pe = p;\n   \
    \         for (long long e = 1; pe <= x / p; e++, pe *= p) {\n               \
    \ res += f_pe(p, e) * self(self, x / pe, k + 1) + f_pe(p, e + 1);\n          \
    \  }\n        }\n        return res;\n    };\n    return rec(rec, n, 0) + T(1);\n\
    }\n#line 7 \"test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp\"\
    \n\nusing mint = static_modint<469762049>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int t;\n    std::cin >> t;\n    while (t--) {\n\
    \        long long n;\n        mint a, b;\n        std::cin >> n >> a >> b;\n\
    \        // f(p) = a + b p \u306A\u306E\u3067\u3001\u7D20\u6570\u306E\u500B\u6570\
    \u306E a \u500D\u3068\u7D20\u6570\u306E\u548C\u306E b \u500D\u3092\u8DB3\u3059\
    \u3002\u500B\u6570\u306F\u6574\u6570\u306E\u8868\u3067\u8DB3\u308A\u308B\n   \
    \     auto cnt = prime_count_table(n);\n        PrimeSumTable<mint> sum(n, [](long\
    \ long v) { return mint(v) * mint(v + 1) / 2 - 1; }, [](long long p) { return\
    \ mint(p); });\n        auto f_pe = [&](long long p, long long e) { return a *\
    \ e + b * p; };\n        std::cout << multiplicative_sum(n, [&](long long v) {\
    \ return a * mint(cnt(v)) + b * sum(v); }, f_pe) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \n\n#include <iostream>\n\n#include \"../../../src/math/modint.hpp\"\n#include\
    \ \"../../../src/math/prime-counting.hpp\"\n\nusing mint = static_modint<469762049>;\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        long long n;\n   \
    \     mint a, b;\n        std::cin >> n >> a >> b;\n        // f(p) = a + b p\
    \ \u306A\u306E\u3067\u3001\u7D20\u6570\u306E\u500B\u6570\u306E a \u500D\u3068\u7D20\
    \u6570\u306E\u548C\u306E b \u500D\u3092\u8DB3\u3059\u3002\u500B\u6570\u306F\u6574\
    \u6570\u306E\u8868\u3067\u8DB3\u308A\u308B\n        auto cnt = prime_count_table(n);\n\
    \        PrimeSumTable<mint> sum(n, [](long long v) { return mint(v) * mint(v\
    \ + 1) / 2 - 1; }, [](long long p) { return mint(p); });\n        auto f_pe =\
    \ [&](long long p, long long e) { return a * e + b * p; };\n        std::cout\
    \ << multiplicative_sum(n, [&](long long v) { return a * mint(cnt(v)) + b * sum(v);\
    \ }, f_pe) << '\\n';\n    }\n}\n"
  dependsOn:
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/prime-counting.hpp
  - src/math/sqrt.hpp
  isVerificationFile: true
  path: test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 21:42:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp
- /verify/test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp.html
title: test/yosupo/number_theory/sum-of-multiplicative-function.test.cpp
---
