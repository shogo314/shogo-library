---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/math/modint.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// modint\
    \ \u306E ++\u30FB--\u30FB\u5358\u9805\u306E +\u3001\u5408\u6210\u6570\u306E\u6CD5\
    \u3067\u306E\u9006\u5143\u3001\u7D20\u6570\u5224\u5B9A (internal_modint::is_prime32)\
    \ \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\u6BD4\u8F03\u3059\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2\
    \ \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\
    \u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\
    \u30B9\n */\n\n#include <cassert>\n#include <cstdint>\n#include <iostream>\n#include\
    \ <limits>\n#include <type_traits>\n#include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
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
    using modint = dynamic_modint<-1>;\n#line 7 \"test/unittest/math/modint.test.cpp\"\
    \n\n#line 10 \"test/unittest/math/modint.test.cpp\"\n#include <random>\n\nbool\
    \ naive_is_prime(std::uint32_t x) {\n    if (x < 2) return false;\n    for (std::uint64_t\
    \ d = 2; d * d <= x; d++) {\n        if (x % d == 0) return false;\n    }\n  \
    \  return true;\n}\n\nlong long naive_inv(long long a, long long m) {\n    for\
    \ (long long x = 1; x < m; x++) {\n        if (a * x % m == 1) return x;\n   \
    \ }\n    return -1;\n}\n\n// ++\u30FB--\u30FB\u5358\u9805\u306E + \u3092\u3001\
    \u5024\u3092\u611A\u76F4\u306B\u8DB3\u3057\u5F15\u304D\u3057\u305F\u3082\u306E\
    \u3068\u6BD4\u3079\u308B\ntemplate <class M>\nbool check_inc_dec(long long mod,\
    \ std::mt19937_64& rng) {\n    bool ok = true;\n    for (int rep = 0; rep < 200;\
    \ rep++) {\n        long long x = (rep < 4) ? (rep < 2 ? rep : mod - 4 + rep)\
    \ : static_cast<long long>(rng() % mod);\n        if (x < 0 || x >= mod) x = 0;\n\
    \        M a = x;\n        // \u524D\u7F6E: \u5909\u66F4\u5F8C\u306E\u81EA\u8EAB\
    \u3092\u8FD4\u3059\n        M& r1 = ++a;\n        if (&r1 != &a || static_cast<long\
    \ long>(a.val()) != (x + 1) % mod) ok = false;\n        M& r2 = --a;\n       \
    \ if (&r2 != &a || static_cast<long long>(a.val()) != x) ok = false;\n       \
    \ // \u5F8C\u7F6E: \u5909\u66F4\u524D\u306E\u5024\u3092\u8FD4\u3059\n        M\
    \ b = a++;\n        if (static_cast<long long>(b.val()) != x || static_cast<long\
    \ long>(a.val()) != (x + 1) % mod) ok = false;\n        M c = a--;\n        if\
    \ (static_cast<long long>(c.val()) != (x + 1) % mod || static_cast<long long>(a.val())\
    \ != x) ok = false;\n        // 0 \u304B\u3089 -- \u3059\u308B\u3068 mod - 1 \u306B\
    \u306A\u308B\n        M z = 0;\n        --z;\n        if (static_cast<long long>(z.val())\
    \ != mod - 1) ok = false;\n        M w = z++;\n        if (static_cast<long long>(w.val())\
    \ != mod - 1 || z.val() != 0) ok = false;\n        // \u5358\u9805\u306E + \u306F\
    \u305D\u306E\u307E\u307E\u306E\u5024\n        if ((+a).val() != a.val()) ok =\
    \ false;\n    }\n    return ok;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n\n    if (!check_inc_dec<static_modint<998244353>>(998244353,\
    \ rng)) ok = false, std::cerr << \"inc/dec 998244353\" << std::endl;\n    if (!check_inc_dec<static_modint<7>>(7,\
    \ rng)) ok = false, std::cerr << \"inc/dec 7\" << std::endl;\n    if (!check_inc_dec<static_modint<2>>(2,\
    \ rng)) ok = false, std::cerr << \"inc/dec 2\" << std::endl;\n    using D = dynamic_modint<314>;\n\
    \    for (long long m : {2LL, 3LL, 10LL, 1000000007LL}) {\n        D::set_mod(m);\n\
    \        if (!check_inc_dec<D>(m, rng)) ok = false, std::cerr << \"inc/dec dynamic\
    \ \" << m << std::endl;\n    }\n\n    // \u7D20\u6570\u5224\u5B9A: \u5C0F\u3055\
    \u3044\u6570\u306F\u3059\u3079\u3066\u3001\u5927\u304D\u3044\u6570\u306F 2^32\
    \ \u4ED8\u8FD1\u3068\u4E71\u6570\u3067\u78BA\u304B\u3081\u308B\n    for (std::uint32_t\
    \ x = 0; x < 200000; x++) {\n        if (internal_modint::is_prime32(x) != naive_is_prime(x))\
    \ ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n    }\n    for\
    \ (std::uint32_t x = 4294967295u; x > 4294967295u - 3000; x--) {\n        if (internal_modint::is_prime32(x)\
    \ != naive_is_prime(x)) ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n\
    \    }\n    for (int rep = 0; rep < 3000; rep++) {\n        std::uint32_t x =\
    \ static_cast<std::uint32_t>(rng());\n        if (internal_modint::is_prime32(x)\
    \ != naive_is_prime(x)) ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n\
    \    }\n    // \u5F37\u64EC\u7D20\u6570 (\u5C0F\u3055\u3044\u5E95\u3067\u306F\u7D20\
    \u6570\u3068\u8AA4\u5224\u5B9A\u3055\u308C\u3084\u3059\u3044\u5408\u6210\u6570\
    ) \u3082\u542B\u3081\u308B\n    for (std::uint32_t x : {2047u, 3215031751u, 1373653u,\
    \ 25326001u, 3825123056u, 464155845u, 1122004669u, 1795265022u, 998244353u, 1000000007u,\
    \ 4294967291u}) {\n        if (internal_modint::is_prime32(x) != naive_is_prime(x))\
    \ ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n    }\n    // \u30B3\
    \u30F3\u30D1\u30A4\u30EB\u6642\u306B\u3082\u4F7F\u3048\u308B\n    static_assert(internal_modint::is_prime32(998244353u));\n\
    \    static_assert(!internal_modint::is_prime32(1000000000u));\n\n    // \u5408\
    \u6210\u6570\u306E\u6CD5\u306E static_modint \u3067\u306F\u3001\u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n   \
    \ {\n        using M = static_modint<1000>;\n        for (int a = 1; a < 1000;\
    \ a++) {\n            long long e = naive_inv(a, 1000);\n            if (e ==\
    \ -1) continue;  // \u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u3082\u306E\u306F\
    \u9006\u5143\u304C\u306A\u3044\n            if (static_cast<long long>(M(a).inv().val())\
    \ != e) ok = false, std::cerr << \"inv mod 1000 \" << a << std::endl;\n      \
    \  }\n    }\n    {\n        using M = static_modint<998244353>;\n        for (int\
    \ rep = 0; rep < 1000; rep++) {\n            M a = static_cast<long long>(rng()\
    \ % 998244352 + 1);\n            if ((a * a.inv()).val() != 1) ok = false;\n \
    \       }\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// modint \u306E ++\u30FB--\u30FB\u5358\u9805\u306E +\u3001\u5408\u6210\u6570\
    \u306E\u6CD5\u3067\u306E\u9006\u5143\u3001\u7D20\u6570\u5224\u5B9A (internal_modint::is_prime32)\
    \ \u3092\u611A\u76F4\u306A\u8A08\u7B97\u3068\u6BD4\u8F03\u3059\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include\
    \ \"../../../src/math/modint.hpp\"\n\n#include <cstdint>\n#include <iostream>\n\
    #include <random>\n\nbool naive_is_prime(std::uint32_t x) {\n    if (x < 2) return\
    \ false;\n    for (std::uint64_t d = 2; d * d <= x; d++) {\n        if (x % d\
    \ == 0) return false;\n    }\n    return true;\n}\n\nlong long naive_inv(long\
    \ long a, long long m) {\n    for (long long x = 1; x < m; x++) {\n        if\
    \ (a * x % m == 1) return x;\n    }\n    return -1;\n}\n\n// ++\u30FB--\u30FB\u5358\
    \u9805\u306E + \u3092\u3001\u5024\u3092\u611A\u76F4\u306B\u8DB3\u3057\u5F15\u304D\
    \u3057\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\ntemplate <class M>\nbool check_inc_dec(long\
    \ long mod, std::mt19937_64& rng) {\n    bool ok = true;\n    for (int rep = 0;\
    \ rep < 200; rep++) {\n        long long x = (rep < 4) ? (rep < 2 ? rep : mod\
    \ - 4 + rep) : static_cast<long long>(rng() % mod);\n        if (x < 0 || x >=\
    \ mod) x = 0;\n        M a = x;\n        // \u524D\u7F6E: \u5909\u66F4\u5F8C\u306E\
    \u81EA\u8EAB\u3092\u8FD4\u3059\n        M& r1 = ++a;\n        if (&r1 != &a ||\
    \ static_cast<long long>(a.val()) != (x + 1) % mod) ok = false;\n        M& r2\
    \ = --a;\n        if (&r2 != &a || static_cast<long long>(a.val()) != x) ok =\
    \ false;\n        // \u5F8C\u7F6E: \u5909\u66F4\u524D\u306E\u5024\u3092\u8FD4\u3059\
    \n        M b = a++;\n        if (static_cast<long long>(b.val()) != x || static_cast<long\
    \ long>(a.val()) != (x + 1) % mod) ok = false;\n        M c = a--;\n        if\
    \ (static_cast<long long>(c.val()) != (x + 1) % mod || static_cast<long long>(a.val())\
    \ != x) ok = false;\n        // 0 \u304B\u3089 -- \u3059\u308B\u3068 mod - 1 \u306B\
    \u306A\u308B\n        M z = 0;\n        --z;\n        if (static_cast<long long>(z.val())\
    \ != mod - 1) ok = false;\n        M w = z++;\n        if (static_cast<long long>(w.val())\
    \ != mod - 1 || z.val() != 0) ok = false;\n        // \u5358\u9805\u306E + \u306F\
    \u305D\u306E\u307E\u307E\u306E\u5024\n        if ((+a).val() != a.val()) ok =\
    \ false;\n    }\n    return ok;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n\n    if (!check_inc_dec<static_modint<998244353>>(998244353,\
    \ rng)) ok = false, std::cerr << \"inc/dec 998244353\" << std::endl;\n    if (!check_inc_dec<static_modint<7>>(7,\
    \ rng)) ok = false, std::cerr << \"inc/dec 7\" << std::endl;\n    if (!check_inc_dec<static_modint<2>>(2,\
    \ rng)) ok = false, std::cerr << \"inc/dec 2\" << std::endl;\n    using D = dynamic_modint<314>;\n\
    \    for (long long m : {2LL, 3LL, 10LL, 1000000007LL}) {\n        D::set_mod(m);\n\
    \        if (!check_inc_dec<D>(m, rng)) ok = false, std::cerr << \"inc/dec dynamic\
    \ \" << m << std::endl;\n    }\n\n    // \u7D20\u6570\u5224\u5B9A: \u5C0F\u3055\
    \u3044\u6570\u306F\u3059\u3079\u3066\u3001\u5927\u304D\u3044\u6570\u306F 2^32\
    \ \u4ED8\u8FD1\u3068\u4E71\u6570\u3067\u78BA\u304B\u3081\u308B\n    for (std::uint32_t\
    \ x = 0; x < 200000; x++) {\n        if (internal_modint::is_prime32(x) != naive_is_prime(x))\
    \ ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n    }\n    for\
    \ (std::uint32_t x = 4294967295u; x > 4294967295u - 3000; x--) {\n        if (internal_modint::is_prime32(x)\
    \ != naive_is_prime(x)) ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n\
    \    }\n    for (int rep = 0; rep < 3000; rep++) {\n        std::uint32_t x =\
    \ static_cast<std::uint32_t>(rng());\n        if (internal_modint::is_prime32(x)\
    \ != naive_is_prime(x)) ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n\
    \    }\n    // \u5F37\u64EC\u7D20\u6570 (\u5C0F\u3055\u3044\u5E95\u3067\u306F\u7D20\
    \u6570\u3068\u8AA4\u5224\u5B9A\u3055\u308C\u3084\u3059\u3044\u5408\u6210\u6570\
    ) \u3082\u542B\u3081\u308B\n    for (std::uint32_t x : {2047u, 3215031751u, 1373653u,\
    \ 25326001u, 3825123056u, 464155845u, 1122004669u, 1795265022u, 998244353u, 1000000007u,\
    \ 4294967291u}) {\n        if (internal_modint::is_prime32(x) != naive_is_prime(x))\
    \ ok = false, std::cerr << \"is_prime32 \" << x << std::endl;\n    }\n    // \u30B3\
    \u30F3\u30D1\u30A4\u30EB\u6642\u306B\u3082\u4F7F\u3048\u308B\n    static_assert(internal_modint::is_prime32(998244353u));\n\
    \    static_assert(!internal_modint::is_prime32(1000000000u));\n\n    // \u5408\
    \u6210\u6570\u306E\u6CD5\u306E static_modint \u3067\u306F\u3001\u62E1\u5F35\u30E6\
    \u30FC\u30AF\u30EA\u30C3\u30C9\u3067\u9006\u5143\u3092\u6C42\u3081\u308B\n   \
    \ {\n        using M = static_modint<1000>;\n        for (int a = 1; a < 1000;\
    \ a++) {\n            long long e = naive_inv(a, 1000);\n            if (e ==\
    \ -1) continue;  // \u4E92\u3044\u306B\u7D20\u3067\u306A\u3044\u3082\u306E\u306F\
    \u9006\u5143\u304C\u306A\u3044\n            if (static_cast<long long>(M(a).inv().val())\
    \ != e) ok = false, std::cerr << \"inv mod 1000 \" << a << std::endl;\n      \
    \  }\n    }\n    {\n        using M = static_modint<998244353>;\n        for (int\
    \ rep = 0; rep < 1000; rep++) {\n            M a = static_cast<long long>(rng()\
    \ % 998244352 + 1);\n            if ((a * a.inv()).val() != 1) ok = false;\n \
    \       }\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/math/modint.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/math/modint.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/modint.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/modint.test.cpp
- /verify/test/unittest/math/modint.test.cpp.html
title: test/unittest/math/modint.test.cpp
---
