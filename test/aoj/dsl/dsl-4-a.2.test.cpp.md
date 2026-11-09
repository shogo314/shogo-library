---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/rectangle.hpp
    title: "\u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62"
  - icon: ':heavy_check_mark:'
    path: src/geometry/vector.hpp
    title: "\u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: src/utility/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Grid"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"test/aoj/dsl/dsl-4-a.2.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n// Compress \u3067\u5EA7\u6A19\u5727\u7E2E\u3059\u308B\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/geometry/rectangle.hpp\"\n\n/**\n * @file rectangle.hpp\n\
    \ * @brief \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62\n */\n\n#include <cassert>\n\
    #include <istream>\n#include <type_traits>\n\n#line 2 \"src/geometry/vector.hpp\"\
    \n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n\
    \ */\n\n#include <array>\n#line 10 \"src/geometry/vector.hpp\"\n#include <cmath>\n\
    #line 12 \"src/geometry/vector.hpp\"\n#include <ostream>\n#line 14 \"src/geometry/vector.hpp\"\
    \n#include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <functional>\n\
    #include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\n#if\
    \ __cplusplus >= 202002L\n#include <concepts>\n#include <ranges>\n#endif\n\nnamespace\
    \ internal_traits {\nusing std::begin, std::end;\n\n#if __cplusplus >= 202002L\n\
    template <class T>\n    struct is_range_impl : std::bool_constant < requires(T&\
    \ t) {\n    begin(t);\n    end(t);\n}>{};\n#else\ntemplate <class T, class = void>\n\
    struct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T,\
    \ std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>> :\
    \ std::true_type {};\n#endif\n\n// \u30B5\u30A4\u30BA\u4ED8\u304D\u7BC4\u56F2\u304B\
    \u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\u308B\u3002\n#if __cplusplus\
    \ >= 202002L\ntemplate <class R, class S>\nconcept sized_constructible_range =\
    \ std::ranges::input_range<R> && std::ranges::sized_range<R> &&\n            \
    \                        std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
    \ntemplate <class R>\nauto range_size(R& r) {\n    return std::ranges::size(r);\n\
    }\ntemplate <class R>\nauto range_begin(R& r) {\n    return std::ranges::begin(r);\n\
    }\ntemplate <class R>\nusing range_value_t = std::ranges::range_value_t<R>;\n\
    #else\nusing std::size;\ntemplate <class R>\nauto range_size(R& r) -> decltype(size(r))\
    \ {\n    return size(r);\n}\ntemplate <class R>\nauto range_begin(R& r) -> decltype(begin(r))\
    \ {\n    return begin(r);\n}\ntemplate <class R>\nusing range_value_t = typename\
    \ std::iterator_traits<decltype(range_begin(std::declval<R&>()))>::value_type;\n\
    \ntemplate <class R, class S, class = void>\nstruct is_sized_constructible_range\
    \ : std::false_type {};\ntemplate <class R, class S>\nstruct is_sized_constructible_range<R,\
    \ S, std::void_t<decltype(range_size(std::declval<R&>())), decltype(++std::declval<decltype(begin(std::declval<R&>()))&>()),\
    \ decltype(begin(std::declval<R&>()) != end(std::declval<R&>())), decltype(*begin(std::declval<R&>()))>>\n\
    \    : std::is_constructible<S, decltype(*begin(std::declval<R&>()))> {};\n#endif\n\
    }  // namespace internal_traits\n\ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#if __cplusplus >= 202002L\n#define HAS_METHOD(func_name)                  \
    \                                                 \\\n    namespace internal_traits\
    \ {                                                                 \\\n    template\
    \ <class T>                                                                  \
    \        \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name();\
    \ };               \\\n    }                                                 \
    \                                          \\\n    template <class T>        \
    \                                                                  \\\n    struct\
    \ has_##func_name : std::bool_constant<internal_traits::has_##func_name##_impl<T>>\
    \ {}; \\\n    template <class T>                                             \
    \                             \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                        \\\n    namespace internal_traits\
    \ {                                                                    \\\n  \
    \  template <class T, class U>                                               \
    \                     \\\n    concept has_##func_name##_impl = requires { std::declval<T>().func_name(std::declval<U>());\
    \ }; \\\n    }                                                               \
    \                               \\\n    template <class T, class U>          \
    \                                                          \\\n    struct has_##func_name\
    \ : std::bool_constant<internal_traits::has_##func_name##_impl<T, U>> {}; \\\n\
    \    template <class T, class U>                                             \
    \                       \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T,\
    \ U>::value;\n#else\n#define HAS_METHOD(func_name)                           \
    \                                   \\\n    namespace internal_traits {      \
    \                                                      \\\n    template <class\
    \ T, class = void>                                                       \\\n\
    \    struct has_##func_name##_impl : std::false_type {};                     \
    \               \\\n    template <class T>                                   \
    \                                  \\\n    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
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
    #endif\n\nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\n\
    HAS_METHOD(max)\nHAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\n\
    HAS_METHOD(product)\nHAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\n\
    HAS_METHOD_ARG(lower_bound)\nHAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr)\
    \ std::enable_if_t<expr, std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 17 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
    \u3057\u3066\u306E\u30D9\u30AF\u30C8\u30EB\n *\n * @tparam T \u578B \u7701\u7565\
    \u3057\u305F\u3089double\n * @tparam Dim \u6B21\u5143 \u7701\u7565\u3057\u305F\
    \u30892\n */\ntemplate <typename T = double, int Dim = 2, ENABLE_IF_T(std::is_scalar_v<T>\
    \ && (Dim > 0))>\nstruct Vector {\n    std::array<T, Dim> v;  //!< \u30D9\u30AF\
    \u30C8\u30EB\u306E\u6210\u5206\u8868\u793A\n\n    /**\n     * @brief \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u30BC\u30ED\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    constexpr Vector() noexcept : v() {}\n\
    \    /**\n     * @brief \u53EF\u5909\u9577\u5F15\u6570\u306B\u3088\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u5404\u6210\u5206\u3092\
    \ T \u306B\u5909\u63DB\u3057\u3066\u5165\u308C\u308B (Vector(1, 2.5) \u306E\u3088\
    \u3046\u306B\u578B\u304C\u6DF7\u3056\u3063\u3066\u3082\u7E2E\u5C0F\u5909\u63DB\
    \u306E\u8B66\u544A\u3092\u51FA\u3055\u306A\u3044)\n     * @tparam Args\n     */\n\
    \    template <typename... Args>\n    constexpr Vector(Args... args) noexcept\
    \ : v{static_cast<T>(args)...} {}\n\n    /**\n     * @brief i\u756A\u76EE\u306E\
    \u6210\u5206\u3092\u8FD4\u3059\n     *\n     * @param i\n     * @return T&\n \
    \    */\n    constexpr T& operator[](long long i) noexcept {\n        return v[i];\n\
    \    }\n    /**\n     * @brief i\u756A\u76EE\u306E\u6210\u5206\u3092\u8FD4\u3059\
    \n     *\n     * @param i\n     * @return T&\n     */\n    constexpr const T&\
    \ operator[](long long i) const noexcept {\n        return v[i];\n    }\n\n  \
    \  /**\n     * @brief \u52A0\u7B97\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n   \
    \  * @param rhs\n     * @return Vector&\n     */\n    constexpr Vector& operator+=(const\
    \ Vector& rhs) noexcept {\n        for (int i = 0; i < Dim; i++) v[i] += rhs[i];\n\
    \        return *this;\n    }\n    /**\n     * @brief \u6E1B\u7B97\u4EE3\u5165\
    \u6F14\u7B97\u5B50\n     *\n     * @param rhs\n     * @return Vector&\n     */\n\
    \    constexpr Vector& operator-=(const Vector& rhs) noexcept {\n        for (int\
    \ i = 0; i < Dim; i++) v[i] -= rhs.v[i];\n        return *this;\n    }\n    /**\n\
    \     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n\
    \     *\n     * @param coef\n     * @return Vector&\n     */\n    constexpr Vector&\
    \ operator*=(const T& coef) noexcept {\n        for (int i = 0; i < Dim; i++)\
    \ v[i] *= coef;\n        return *this;\n    }\n    /**\n     * @brief \u30B9\u30AB\
    \u30E9\u30FC\u306E\u9006\u6570\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n \
    \    * @param coef\n     * @return Vector&\n     */\n    constexpr Vector& operator/=(const\
    \ T& coef) {\n        for (int i = 0; i < Dim; i++) {\n            if constexpr\
    \ (std::is_integral_v<T>) {\n                assert(v[i] % coef == 0 && \"Vector::operator/=\
    \ : coef must be a divisor of all elements\");\n            }\n            v[i]\
    \ /= coef;\n        }\n        return *this;\n    }\n\n    /**\n     * @brief\
    \ \u5358\u9805\u30D7\u30E9\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    constexpr Vector operator+() const noexcept {\n\
    \        return *this;\n    }\n    /**\n     * @brief \u5358\u9805\u30DE\u30A4\
    \u30CA\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    constexpr Vector operator-() const noexcept {\n        return *this * (-1);\n\
    \    }\n\n    /**\n     * @brief \u52A0\u7B97\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    friend constexpr Vector operator+(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return std::move(Vector(lhs) += rhs);\n    }\n\n    /**\n     * @brief\
    \ \u6E1B\u7B97\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n\
    \     * @return Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector\
    \ operator-(const Vector& lhs, const Vector& rhs) noexcept {\n        return std::move(Vector(lhs)\
    \ -= rhs);\n    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    friend constexpr Vector operator*(const Vector&\
    \ lhs, const T& coef) noexcept {\n        return std::move(Vector(lhs) *= coef);\n\
    \    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\u7B97\u5B50\
    \n     *\n     * @param coef\n     * @param rhs\n     * @return Vector\n     */\n\
    \    [[nodiscard]]\n    friend constexpr Vector operator*(const T& coef, const\
    \ Vector& rhs) noexcept {\n        return std::move(Vector(rhs) *= coef);\n  \
    \  }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u306E\u9006\u6570\u500D\
    \u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return\
    \ Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector operator/(const\
    \ Vector& lhs, const T& coef) {\n        return std::move(Vector(lhs) /= coef);\n\
    \    }\n\n    /**\n     * @brief \u7B49\u4FA1\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator==(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v == rhs.v;\n    }\n\n    /**\n     * @brief \u975E\u7B49\
    \u4FA1\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v != rhs.v;\n\
    \    }\n\n    /**\n     * @brief \u5C0F\u306A\u308A\u6F14\u7B97\u5B50\n     *\n\
    \     * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator<(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v < rhs.v;\n    }\n    /**\n     * @brief \u5927\u306A\
    \u308A\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator>(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v > rhs.v;\n\
    \    }\n    /**\n     * @brief \u5C0F\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n\
    \     */\n    [[nodiscard]]\n    friend constexpr bool operator<=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v <= rhs.v;\n    }\n\
    \    /**\n     * @brief \u5927\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\u7B97\
    \u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n  \
    \   */\n    [[nodiscard]]\n    friend constexpr bool operator>=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v >= rhs.v;\n    }\n\n\
    \    /**\n     * @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\
    \u306E\u8AAD\u307F\u8FBC\u307F\n     *\n     * @tparam CharT \u5165\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u5165\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_istream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Vector& rhs) {\n\
    \        for (int i = 0; i < Dim; i++) is >> rhs.v[i];\n        return is;\n \
    \   }\n    /**\n     * @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u3078\
    \u306E\u66F8\u304D\u8FBC\u307F\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_ostream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Vector& rhs)\
    \ {\n        for (int i = 0; i < Dim; i++) {\n            if (i != 0) os << CharT('\
    \ ');\n            os << rhs.v[i];\n        }\n        return os;\n    }\n\n \
    \   /**\n     * @brief \u5185\u7A4D\n     *\n     * @param lhs\n     * @param\
    \ rhs\n     * @return T\n     */\n    friend constexpr T dot(const Vector& lhs,\
    \ const Vector& rhs) noexcept {\n        T ret = 0;\n        for (int i = 0; i\
    \ < Dim; i++) ret += lhs[i] * rhs[i];\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u7D76\u5BFE\u5024\u306E2\u4E57\n     *\n     * @return T\n   \
    \  */\n    constexpr T squared_norm() const noexcept {\n        return dot(*this,\
    \ *this);\n    }\n    /**\n     * @brief \u7D76\u5BFE\u5024\n     *\n     * @return\
    \ double\n     */\n    constexpr double abs() const noexcept {\n        return\
    \ std::sqrt(squared_norm());\n    }\n};\n\n/**\n * @brief \u6210\u5206\u304B\u3089\
    \u4F5C\u308B\u3068\u304D\u306E\u63A8\u8AD6\u30AC\u30A4\u30C9\u3002\u578B\u306F\
    \u6210\u5206\u306E\u5171\u901A\u306E\u578B\u3001\u6B21\u5143\u306F\u6210\u5206\
    \u306E\u500B\u6570\u306B\u3059\u308B\n *\n * Vector(2LL, 3LL) \u306F Vector<long\
    \ long, 2>\u3001Vector(1, 2, 3) \u306F Vector<int, 3>\u3001Vector(0.0, 0.0) \u306F\
    \ Vector<double, 2>\n * (\u3053\u308C\u304C\u306A\u3044\u3068\u3001\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306E\u7701\u7565\u6642\u306E\u5024\u304B\
    \u3089 Vector<double, 2> \u306B\u306A\u3063\u3066\u3057\u307E\u3046)\n */\ntemplate\
    \ <typename T, typename... U, ENABLE_IF_T(std::is_scalar_v<T> && (std::is_scalar_v<U>\
    \ && ...))>\nVector(T, U...) -> Vector<std::common_type_t<T, U...>, 1 + sizeof...(U)>;\n\
    \n/**\n * @brief \u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\u3046\u3057\u306E\
    \u5916\u7A4D(\u5E73\u884C\u56DB\u8FBA\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D)\n *\n * @param lhs\n * @param rhs\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @return T\n */\ntemplate <typename T>\nconstexpr T cross(const Vector<T,\
    \ 2>& lhs, const Vector<T, 2>& rhs) noexcept {\n    return lhs[0] * rhs[1] - lhs[1]\
    \ * rhs[0];\n}\n/**\n * @brief \u4E09\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\
    \u3046\u3057\u306E\u5916\u7A4D\n *\n * @param lhs\n * @param rhs\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @return Vector<T, 3>\n */\ntemplate <typename T>\n\
    constexpr Vector<T, 3> cross(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs)\
    \ noexcept {\n    Vector<T, 3> ret;\n    ret[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];\n\
    \    ret[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];\n    ret[2] = lhs[0] * rhs[1]\
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n\n/**\n * @brief 3\u70B9\u306E\u4F4D\
    \u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u306F\u8AA4\u5DEE\
    \u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192c \u304C\u53CD\u6642\u8A08\
    \u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a, b \u306E\u9806\u306B\u4E00\
    \u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A, 0:\
    \ c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename T>\nconstexpr int ccw(const\
    \ Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T, 2>& c) {\n    Vector<T,\
    \ 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n    if (cr > 0) return 1;\n\
    \    if (cr < 0) return -1;\n    if (dot(u, v) < 0) return 2;\n    if (u.squared_norm()\
    \ < v.squared_norm()) return -2;\n    return 0;\n}\n#line 13 \"src/geometry/rectangle.hpp\"\
    \n\n/**\n * @brief \u534A\u958B\u9818\u57DF [left, right) \xD7 [bottom, top)\u3002\
    \u5E45\u30FB\u9AD8\u3055 0 \u3082\u8A31\u3059\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\u3002\u7701\u7565\u3057\u305F\u3089 long long\n */\ntemplate <typename\
    \ T = long long>\nstruct Rectangle {\n    T left{}, bottom{}, right{}, top{};\n\
    \n    constexpr Rectangle() = default;\n    constexpr Rectangle(T left, T bottom,\
    \ T right, T top) : left(left), bottom(bottom), right(right), top(top) {\n   \
    \     assert(left <= right && bottom <= top);\n    }\n    constexpr T width()\
    \ const { return right - left; }\n    constexpr T height() const { return top\
    \ - bottom; }\n    constexpr T area() const { return width() * height(); }\n \
    \   constexpr bool empty() const { return left == right || bottom == top; }\n\
    \    /** @brief \u5DE6\u8FBA\u30FB\u4E0B\u8FBA\u3092\u542B\u307F\u3001\u53F3\u8FBA\
    \u30FB\u4E0A\u8FBA\u3092\u542B\u307E\u306A\u3044\u5305\u542B\u5224\u5B9A */\n\
    \    constexpr bool contains(T x, T y) const {\n        return left <= x && x\
    \ < right && bottom <= y && y < top;\n    }\n    constexpr bool contains(const\
    \ Vector<T, 2>& p) const { return contains(p[0], p[1]); }\n    /** @brief 4 \u8FBA\
    \u306E\u5EA7\u6A19\u304C\u3059\u3079\u3066\u7B49\u3057\u3044\u304B (\u7A7A\u306E\
    \u9577\u65B9\u5F62\u3067\u3082\u5EA7\u6A19\u3092\u6BD4\u8F03\u3059\u308B) */\n\
    \    constexpr bool operator==(const Rectangle& other) const {\n        return\
    \ left == other.left && bottom == other.bottom && right == other.right && top\
    \ == other.top;\n    }\n    constexpr bool operator!=(const Rectangle& other)\
    \ const { return !(*this == other); }\n\n    /** @brief left bottom right top\
    \ \u306E\u9806\u306B\u8AAD\u307F\u8FBC\u3080 */\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Rectangle& rhs) {\n        if (is >> rhs.left >> rhs.bottom >>\
    \ rhs.right >> rhs.top) {\n            assert(rhs.left <= rhs.right && rhs.bottom\
    \ <= rhs.top);\n        }\n        return is;\n    }\n};\n\ntemplate <typename\
    \ A, typename B, typename C, typename D>\nRectangle(A, B, C, D) -> Rectangle<std::common_type_t<A,\
    \ B, C, D>>;\n#line 2 \"src/utility/compress.hpp\"\n\n/**\n * @file compress.hpp\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n */\n\n#include <algorithm>\n#line 11 \"\
    src/utility/compress.hpp\"\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n *\n *\
    \ \u5024\u3092 add \u3067\u767B\u9332\u3057\u3001build \u3067\u30BD\u30FC\u30C8\
    \u3068\u91CD\u8907\u9664\u53BB\u3092\u3057\u3066\u304B\u3089\u4F7F\u3046\n * \u4F8B\
    :\n * Compress<long long> cp(A);  // A \u3092\u767B\u9332\u3057\u3066 build \u307E\
    \u3067\u884C\u3046\n * long long i = cp.id(A[0]);  // 0 <= i < cp.size()\n *\n\
    \ * @tparam T \u5024\u306E\u578B (< \u3067\u6BD4\u8F03\u3067\u304D\u308B\u3053\
    \u3068)\n */\ntemplate <typename T>\nclass Compress {\n    std::vector<T> xs;\n\
    \    bool built = false;\n\n   public:\n    Compress() = default;\n    /**\n \
    \    * @brief v \u306E\u5024\u3092\u767B\u9332\u3057\u3066 build \u3059\u308B\n\
    \     */\n    explicit Compress(const std::vector<T>& v) : xs(v) { build(); }\n\
    \n    /**\n     * @brief \u5024\u3092 1 \u3064\u767B\u9332\u3059\u308B\u3002build\
    \ \u306E\u524D\u306B\u547C\u3076\n     */\n    void add(const T& x) {\n      \
    \  assert(!built);\n        xs.push_back(x);\n    }\n    /**\n     * @brief v\
    \ \u306E\u5024\u3092\u3059\u3079\u3066\u767B\u9332\u3059\u308B\u3002build \u306E\
    \u524D\u306B\u547C\u3076\n     */\n    void add(const std::vector<T>& v) {\n \
    \       assert(!built);\n        xs.insert(xs.end(), v.begin(), v.end());\n  \
    \  }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024\u3092\u30BD\u30FC\u30C8\
    \u3057\u3066\u91CD\u8907\u3092\u9664\u304F O(n log n)\n     */\n    void build()\
    \ {\n        assert(!built);\n        std::sort(xs.begin(), xs.end());\n     \
    \   xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n        built = true;\n\
    \    }\n\n    /**\n     * @brief \u7570\u306A\u308B\u5024\u306E\u500B\u6570\n\
    \     */\n    long long size() const {\n        assert(built);\n        return\
    \ xs.size();\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024 x \u306E\
    \u756A\u53F7 O(log n)\u3002\u767B\u9332\u3057\u3066\u3044\u306A\u3044\u5024\u306A\
    \u3089 assert \u3067\u843D\u3061\u308B\n     */\n    long long id(const T& x)\
    \ const {\n        const long long i = bisect_left(x);\n        assert(i < size()\
    \ && !(x < xs[i]));\n        return i;\n    }\n    /**\n     * @brief x \u4EE5\
    \u4E0A\u3067\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\
    \u308C\u3070 size()\n     */\n    long long bisect_left(const T& x) const {\n\
    \        assert(built);\n        return std::lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n    }\n    /**\n     * @brief x \u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\u308C\u3070\
    \ size()\n     */\n    long long bisect_right(const T& x) const {\n        assert(built);\n\
    \        return std::upper_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\
    \    /**\n     * @brief x \u3092\u767B\u9332\u3057\u305F\u304B O(log n)\n    \
    \ */\n    bool contains(const T& x) const {\n        const long long i = bisect_left(x);\n\
    \        return i < size() && !(x < xs[i]);\n    }\n    /**\n     * @brief \u756A\
    \u53F7 i \u306E\u5024\n     */\n    const T& operator[](long long i) const {\n\
    \        assert(built && 0 <= i && i < size());\n        return xs[i];\n    }\n\
    \    /**\n     * @brief v \u306E\u5404\u5024\u3092\u756A\u53F7\u306B\u7F6E\u304D\
    \u63DB\u3048\u305F\u5217\n     */\n    std::vector<long long> ids(const std::vector<T>&\
    \ v) const {\n        std::vector<long long> res(v.size());\n        for (long\
    \ long i = 0; i < static_cast<long long>(v.size()); i++) res[i] = id(v[i]);\n\
    \        return res;\n    }\n    /**\n     * @brief \u30BD\u30FC\u30C8\u6E08\u307F\
    \u3067\u91CD\u8907\u306E\u306A\u3044\u5024\u306E\u5217\n     */\n    const std::vector<T>&\
    \ values() const {\n        assert(built);\n        return xs;\n    }\n};\n#line\
    \ 2 \"src/utility/range.hpp\"\n\n/**\n * @file range.hpp\n * @brief Python \u306E\
    \ range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\u305D\u306E\u76F4\
    \u7A4D\u306E Grid\n */\n\n#line 11 \"src/utility/range.hpp\"\n#include <string>\n\
    #line 15 \"src/utility/range.hpp\"\n\nstruct Range {\n   public:\n    using value_type\
    \ = long long;\n    using const_reference = value_type;\n    using size_type =\
    \ long long;\n    using difference_type = std::ptrdiff_t;\n\n    const value_type\
    \ start;\n    const value_type stop;\n    const value_type step;\n\n   private:\n\
    \    const value_type norm_stop;\n\n    constexpr static value_type normalize(value_type\
    \ _start, value_type _stop, value_type _step) {\n        assert(_step != 0);\n\
    \        if (_step > 0) {\n            if (_start >= _stop) {\n              \
    \  return _start;\n            } else {\n                return _start + (_stop\
    \ - _start + _step - 1) / _step * _step;\n            }\n        } else {\n  \
    \          if (_start <= _stop) {\n                return _start;\n          \
    \  } else {\n                return _start - (_start - _stop - _step - 1) / _step\
    \ * _step;\n            }\n        }\n    }\n\n    constexpr Range(value_type\
    \ _start, value_type _stop, value_type _step, value_type _norm_stop)\n       \
    \ : start(_start), stop(_stop), step(_step), norm_stop(_norm_stop) {\n    }\n\n\
    \   public:\n    /**\n     * @brief start \u304B\u3089 stop \u306E\u624B\u524D\
    \u307E\u3067 step \u305A\u3064\u9032\u3080\u6574\u6570\u5217\n     * @pre step\
    \ != 0\n     */\n    constexpr Range(value_type _start, value_type _stop, value_type\
    \ _step)\n        : start(_start), stop(_stop), step(_step), norm_stop(normalize(_start,\
    \ _stop, _step)) {\n    }\n    constexpr Range(value_type _start, value_type _stop)\n\
    \        : start(_start), stop(_stop), step(1), norm_stop(normalize(_start, _stop,\
    \ 1)) {}\n    explicit constexpr Range(value_type _stop)\n        : start(0),\
    \ stop(_stop), step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n\
    \        : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = void;\n\
    \        using reference = Range::const_reference;\n        using iterator_category\
    \ = std::random_access_iterator_tag;\n\n       private:\n        value_type first\
    \ = 0, stop = 0, step = 1, value = 0;\n\n        constexpr bool same_range(const\
    \ const_iterator& o) const noexcept {\n            return first == o.first &&\
    \ stop == o.stop && step == o.step;\n        }\n\n       public:\n        constexpr\
    \ const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Range& range, value_type value) noexcept\n            : first(range.start),\
    \ stop(range.stop), step(range.step), value(value) {}\n        constexpr reference\
    \ base() const noexcept {\n            return value;\n        }\n        constexpr\
    \ const_iterator& operator++() noexcept {\n            value += step;\n      \
    \      return *this;\n        }\n        constexpr const_iterator operator++(int)\
    \ noexcept {\n            const_iterator ret(*this);\n            value += step;\n\
    \            return ret;\n        }\n        constexpr const_iterator& operator+=(difference_type\
    \ _n) noexcept {\n            value += _n * step;\n            return *this;\n\
    \        }\n        constexpr friend const_iterator operator+(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret += _n;\n            return ret;\n        }\n        constexpr friend\
    \ const_iterator operator+(difference_type _n, const const_iterator& i) noexcept\
    \ {\n            const_iterator ret(i);\n            ret += _n;\n            return\
    \ ret;\n        }\n        constexpr const_iterator& operator--() noexcept {\n\
    \            value -= step;\n            return *this;\n        }\n        constexpr\
    \ const_iterator operator--(int) noexcept {\n            const_iterator ret(*this);\n\
    \            value -= step;\n            return ret;\n        }\n        constexpr\
    \ const_iterator& operator-=(difference_type _n) noexcept {\n            value\
    \ -= _n * step;\n            return *this;\n        }\n        constexpr friend\
    \ const_iterator operator-(const const_iterator& i, difference_type _n) noexcept\
    \ {\n            const_iterator ret(i);\n            ret -= _n;\n            return\
    \ ret;\n        }\n        constexpr reference operator[](difference_type i) const\
    \ noexcept { return value + i * step; }\n        constexpr reference operator*()\
    \ const noexcept {\n            return value;\n        }\n        constexpr friend\
    \ bool operator!=(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            return !a.same_range(b) || a.value != b.value;\n        }\n     \
    \   constexpr friend bool operator==(const const_iterator& a, const const_iterator&\
    \ b) noexcept {\n            return !(a != b);\n        }\n        constexpr friend\
    \ bool operator<(const const_iterator& a, const const_iterator& b) noexcept {\n\
    \            assert(a.same_range(b));\n            return a.step > 0 ? a.value\
    \ < b.value : a.value > b.value;\n        }\n        constexpr friend bool operator>(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return b < a; }\n   \
    \     constexpr friend bool operator<=(const const_iterator& a, const const_iterator&\
    \ b) noexcept { return !(b < a); }\n        constexpr friend bool operator>=(const\
    \ const_iterator& a, const const_iterator& b) noexcept { return !(a < b); }\n\
    \        constexpr friend difference_type operator-(const const_iterator& a, const\
    \ const_iterator& b) {\n            assert(a.same_range(b));\n            if (a.step\
    \ > 0) {\n                return (a.value - b.value) / a.step;\n            }\
    \ else {\n                return (b.value - a.value) / (-a.step);\n          \
    \  }\n        }\n    };\n\n    constexpr const_iterator begin() const noexcept\
    \ {\n        return {*this, start};\n    }\n    constexpr const_iterator end()\
    \ const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n     *\
    \ @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr size_type count(value_type\
    \ x) const noexcept {\n        // step \u304C\u30B3\u30F3\u30D1\u30A4\u30EB\u6642\
    \u306B\u5206\u304B\u3089\u306A\u3044\u3068\u304D\u3082\u3001\u3088\u304F\u4F7F\
    \u3046 step = 1 \u3067\u306F\u5272\u308A\u7B97\u3092\u3057\u306A\u3044\n     \
    \   if (step == 1) return start <= x && x < stop;\n        if (step > 0) {\n \
    \           if (start <= x && x < stop) {\n                if ((x - start) % step\
    \ == 0) {\n                    return 1;\n                }\n            }\n \
    \       } else {\n            if (stop < x && x <= start) {\n                if\
    \ ((start - x) % (-step) == 0) {\n                    return 1;\n            \
    \    }\n            }\n        }\n        return 0;\n    }\n    /**\n     * @brief\
    \ x \u304C\u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(value_type\
    \ x) const noexcept {\n        return count(x) != 0;\n    }\n    /**\n     * @brief\
    \ x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * x \u304C\u542B\u307E\u308C\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(value_type\
    \ x) const {\n        assert(contains(x));\n        if (step == 1) return x -\
    \ start;\n        return (x - start) / step;\n    }\n    /**\n     * @brief \u8981\
    \u7D20\u304C x \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * x \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068 end() \u3092\u8FD4\u3059\n     */\n    constexpr const_iterator\
    \ find(value_type x) const noexcept {\n        if (contains(x)) {\n          \
    \  return {*this, x};\n        } else {\n            return {*this, norm_stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u4EE5\u4E0A\u306E\
    \u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n     * step > 0 \u3058\u3083\
    \u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr const_iterator lower_bound(value_type\
    \ x) const {\n        assert(step > 0);\n        if (norm_stop <= x) {\n     \
    \       return end();\n        } else if (x < start) {\n            return begin();\n\
    \        } else {\n            return {*this, start + (x - start + step - 1) /\
    \ step * step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x\
    \ \u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n     * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n\
    \    constexpr const_iterator upper_bound(value_type x) const {\n        assert(step\
    \ > 0);\n        if (norm_stop <= x) {\n            return end();\n        } else\
    \ if (x < start) {\n            return begin();\n        } else {\n          \
    \  return {*this, start + (x - start + step) / step * step};\n        }\n    }\n\
    \    /**\n     * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u8981\u7D20\u6570\n   \
    \  */\n    constexpr size_type size() const noexcept {\n        if (step > 0)\
    \ {\n            return (norm_stop - start) / step;\n        } else {\n      \
    \      return (start - norm_stop) / (-step);\n        }\n    }\n    constexpr\
    \ value_type at(size_type i) const {\n        assert(0 <= i && i < size());\n\
    \        return start + i * step;\n    }\n    constexpr value_type operator[](size_type\
    \ i) const {\n        return at(i);\n    }\n    constexpr bool empty() const noexcept\
    \ {\n        return start == norm_stop;\n    }\n    constexpr value_type sum()\
    \ const noexcept {\n        return size() * (norm_stop - step + start) / 2;\n\
    \    }\n    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\u30A8\
    \u30E9\u30FC\n     */\n    constexpr value_type min() const {\n        assert(!empty());\n\
    \        if (step > 0) {\n            return start;\n        } else {\n      \
    \      return norm_stop - step;\n        }\n    }\n    /**\n     * @brief \u6700\
    \u5927\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ value_type max() const {\n        assert(!empty());\n        if (step > 0) {\n\
    \            return norm_stop - step;\n        } else {\n            return start;\n\
    \        }\n    }\n    /**\n     * @brief \u7DCF xor\n     * \u8CA0\u3092\u542B\
    \u3080\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr value_type product_xor()\
    \ const noexcept {\n        if (empty()) return 0;\n        assert(min() >= 0);\n\
    \        Range sorted_range(sorted());\n        value_type res = 0;\n        std::make_unsigned_t<value_type>\
    \ t = 1;\n        while (t <= static_cast<std::make_unsigned_t<value_type>>(max()))\
    \ {\n            std::make_unsigned_t<value_type> tmp = 0, n = size(), m = t,\
    \ a = sorted_range.step, b = sorted_range.start;\n            while (true) {\n\
    \                if (a >= m) {\n                    tmp += n * (n - 1) / 2 * (a\
    \ / m);\n                    a %= m;\n                }\n                if (b\
    \ >= m) {\n                    tmp += n * (b / m);\n                    b %= m;\n\
    \                }\n                std::make_unsigned_t<value_type> y_max = a\
    \ * n + b;\n                if (y_max < m) break;\n                n = y_max /\
    \ m;\n                b = y_max % m;\n                std::swap(m, a);\n     \
    \       }\n            if (tmp % 2 == 1) {\n                res += t;\n      \
    \      }\n            t <<= 1;\n        }\n        return res;\n    }\n    /**\n\
    \     * @brief \u9006\u9806\u306B\u3057\u305F\u3082\u306E\n     */\n    constexpr\
    \ Range reversed() const noexcept {\n        return {norm_stop - step, start -\
    \ step, -step, start - step};\n    }\n    /**\n     * @brief step > 0 \u3060\u3068\
    \u305D\u306E\u307E\u307E step < 0 \u3060\u3068\u9006\u9806\u306B\u3057\u305F\u3082\
    \u306E\n     */\n    constexpr Range sorted() const noexcept {\n        if (step\
    \ > 0) {\n            return {start, norm_stop, step, norm_stop};\n        } else\
    \ {\n            return {norm_stop - step, start - step, -step, start - step};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C [l, r) \u3067\u3042\
    \u308B\u7BC4\u56F2\u3092\u8FD4\u3059\n     */\n    constexpr Range clipped(value_type\
    \ l, value_type r) const {\n        if (l >= r) return {};\n        r--;  // \u4EE5\
    \u4E0B\u3067\u306F r \u3092\u542B\u3080 [l, r] \u3068\u3057\u3066\u6271\u3046\n\
    \        if (step > 0) {\n            value_type _start = [&] {\n            \
    \    if (norm_stop <= l) {\n                    return norm_stop;\n          \
    \      } else if (l < start) {\n                    return start;\n          \
    \      } else {\n                    return start + (l - start + step - 1) / step\
    \ * step;\n                }\n            }();\n            value_type _stop =\
    \ [&] {\n                if (norm_stop <= r) {\n                    return norm_stop;\n\
    \                } else if (r < start) {\n                    return start;\n\
    \                } else {\n                    return start + (r - start + step)\
    \ / step * step;\n                }\n            }();\n            return {_start,\
    \ _stop, step, _stop};\n        } else {\n            value_type _start = [&]\
    \ {\n                if (start - step <= r) {\n                    return start;\n\
    \                } else if (r < norm_stop - step) {\n                    return\
    \ norm_stop;\n                } else {\n                    return norm_stop +\
    \ (r - norm_stop) / step * step;\n                }\n            }();\n      \
    \      value_type _stop = [&] {\n                if (start - step <= l) {\n  \
    \                  return start;\n                } else if (l < norm_stop - step)\
    \ {\n                    return norm_stop;\n                } else {\n       \
    \             return norm_stop + (l - norm_stop - 1) / step * step;\n        \
    \        }\n            }();\n            return {_start, _stop, step, _stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u3092 Range \u3067\u6307\
    \u5B9A\u3057\u305F\u30B3\u30F3\u30C6\u30CA\n     */\n    constexpr Range slice(const\
    \ Range& r) const {\n        if (r.empty()) return {};\n        if (r.max() <\
    \ 0) return {};\n        if (r.min() >= size()) return {};\n        Range trimmed_range(r.clipped(0,\
    \ size()));\n        if (trimmed_range.empty()) return {};\n        value_type\
    \ _step = step * trimmed_range.step;\n        value_type _start = at(trimmed_range.start);\n\
    \        value_type _stop = _start + _step * trimmed_range.size();\n        return\
    \ {_start, _stop, _step, _stop};\n    }\n\n    static std::string type_str() {\n\
    \        return \"Range\";\n    }\n    std::string initializer_str() const {\n\
    \        return \"{\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \"}\";\n    }\n    std::string repr() const\
    \ {\n        return \"Range(\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \")\";\n    }\n\n    std::vector<value_type>\
    \ to_vector() const {\n        std::vector<value_type> ret;\n        ret.reserve(size());\n\
    \        if (step > 0) {\n            for (value_type x = start; x < stop; x +=\
    \ step) {\n                ret.push_back(x);\n            }\n        } else {\n\
    \            for (value_type x = start; x > stop; x += step) {\n             \
    \   ret.push_back(x);\n            }\n        }\n        return ret;\n    }\n\
    \    constexpr friend bool operator==(const Range& a, const Range& b) noexcept\
    \ {\n        if (a.empty() && b.empty()) return true;\n        if (a.size() !=\
    \ b.size()) return false;\n        if (a.start != b.start) return false;\n   \
    \     if (a.size() == 1) return true;\n        if (a.step != b.step) return false;\n\
    \        return true;\n    }\n    constexpr friend bool operator!=(const Range&\
    \ a, const Range& b) noexcept {\n        return !(a == b);\n    }\n};\n\n/**\n\
    \ * @brief 2 \u3064\u306E Range \u306E\u76F4\u7A4D rows \xD7 cols\n * (i, j) \u3092\
    \ i \u306E\u6607\u9806\u3001\u540C\u3058 i \u3067\u306F j \u306E\u6607\u9806 (\u884C\
    \u512A\u5148) \u306B\u4E26\u3079\u305F\u3082\u306E\u3068\u3057\u3066\u6271\u3046\
    \n */\nstruct Grid {\n   public:\n    using value_type = std::pair<long long,\
    \ long long>;\n    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const Range rows;\n    const Range cols;\n\n   private:\n    const long\
    \ long width;  // cols.size() (index \u3084 at \u3067\u6BCE\u56DE\u5272\u308A\u7B97\
    \u3057\u306A\u3044\u3088\u3046\u306B\u6301\u3063\u3066\u304A\u304F)\n\n   public:\n\
    \    /**\n     * @brief [0, h) \xD7 [0, w)\n     */\n    constexpr Grid(long long\
    \ h, long long w) : rows(h), cols(w), width(cols.size()) {}\n    constexpr Grid(const\
    \ Range& _rows, const Range& _cols) : rows(_rows), cols(_cols), width(cols.size())\
    \ {}\n    constexpr Grid(const Grid& o) = default;\n    Grid& operator=(const\
    \ Grid& o) = delete;\n\n    struct const_iterator {\n       public:\n        using\
    \ difference_type = Grid::difference_type;\n        using value_type = Grid::value_type;\n\
    \        using pointer = void;\n        using reference = value_type;\n      \
    \  using iterator_category = std::forward_iterator_tag;\n\n       private:\n \
    \       const Grid* rect = nullptr;\n        long long w = 0;   // cols.size()\n\
    \        long long ic = 0;  // rows \u306E\u4F55\u756A\u76EE\u304B\n        long\
    \ long jc = 0;  // cols \u306E\u4F55\u756A\u76EE\u304B\n\n       public:\n   \
    \     constexpr const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Grid* _rect, long long _w, long long _ic, long long _jc) noexcept\n        \
    \    : rect(_rect), w(_w), ic(_ic), jc(_jc) {}\n        constexpr value_type operator*()\
    \ const noexcept {\n            return {rect->rows.start + ic * rect->rows.step,\
    \ rect->cols.start + jc * rect->cols.step};\n        }\n        constexpr const_iterator&\
    \ operator++() noexcept {\n            if (++jc == w) {\n                jc =\
    \ 0;\n                ++ic;\n            }\n            return *this;\n      \
    \  }\n        constexpr const_iterator operator++(int) noexcept {\n          \
    \  const_iterator ret(*this);\n            ++*this;\n            return ret;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return a.ic == b.ic && a.jc\
    \ == b.jc;\n        }\n        constexpr friend bool operator!=(const const_iterator&\
    \ a, const const_iterator& b) noexcept {\n            return !(a == b);\n    \
    \    }\n    };\n\n    constexpr const_iterator begin() const noexcept {\n    \
    \    return {this, width, width == 0 ? rows.size() : 0, 0};\n    }\n    constexpr\
    \ const_iterator end() const noexcept {\n        return {this, width, rows.size(),\
    \ 0};\n    }\n    /**\n     * @brief \u8981\u7D20\u6570 rows.size() * cols.size()\n\
    \     */\n    constexpr size_type size() const noexcept {\n        return rows.size()\
    \ * width;\n    }\n    constexpr bool empty() const noexcept {\n        return\
    \ rows.empty() || cols.empty();\n    }\n    /**\n     * @brief (i, j) \u304C\u542B\
    \u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(long long i, long\
    \ long j) const noexcept {\n        return rows.contains(i) && cols.contains(j);\n\
    \    }\n    constexpr bool contains(const value_type& p) const noexcept {\n  \
    \      return contains(p.first, p.second);\n    }\n    /**\n     * @brief (i,\
    \ j) \u306E\u884C\u512A\u5148\u3067\u306E\u4F4D\u7F6E (\u30B0\u30EA\u30C3\u30C9\
    \u306E\u9802\u70B9\u756A\u53F7\u306B\u4F7F\u3046)\n     * (i, j) \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(long\
    \ long i, long long j) const {\n        assert(contains(i, j));\n        return\
    \ rows.index(i) * width + cols.index(j);\n    }\n    constexpr size_type index(const\
    \ value_type& p) const {\n        return index(p.first, p.second);\n    }\n  \
    \  /**\n     * @brief \u884C\u512A\u5148\u3067 k \u756A\u76EE\u306E\u8981\u7D20\
    \ (index \u306E\u9006)\n     */\n    constexpr value_type at(size_type k) const\
    \ {\n        assert(0 <= k && k < size());\n        return {rows[k / width], cols[k\
    \ % width]};\n    }\n    constexpr value_type operator[](size_type k) const {\n\
    \        return at(k);\n    }\n\n   private:\n    // \u8FD1\u508D\u306E\u65B9\u5411\
    \ (rows\u30FBcols \u306E\u4E2D\u3067\u306E\u4F4D\u7F6E\u306E\u5DEE) \u3092 Grid\
    \ \u306E\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5148\u982D 4 \u3064\u306F\
    \u4E0A\u4E0B\u5DE6\u53F3\u3060\u3051\u3092\u4E26\u3079\u305F\u5225\u306E\u8868\
    \n    // 4 \u8FD1\u508D\u3068 8 \u8FD1\u508D\u306E\u5883\u76EE\u304C\u5206\u304B\
    \u308B\u3088\u3046\u306B 2 \u884C\u306B\u5206\u3051\u3066\u3044\u308B\u306E\u3067\
    \u6574\u5F62\u3057\u306A\u3044\n    // clang-format off\n    static constexpr\
    \ int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0},\n            \
    \                                     {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,\
    \ 1}, {1, -1}, {1, 0}, {1, 1}};\n    // clang-format on\n\n   public:\n    /**\n\
    \     * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2\
    \ for \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Grid \u306B\u542B\
    \u307E\u308C\u308B\u65B9\u5411\u3092\u30D3\u30C3\u30C8\u3067\u6301\u3063\u3066\
    \u304A\u304D\u3001\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u9806\
    \u306B\u8FD4\u3059\n     */\n    struct Neighbors {\n        long long i, j, row_step,\
    \ col_step;\n        int first;      // neighbor_dirs[first + k] \u304C\u30D3\u30C3\
    \u30C8 k \u306E\u65B9\u5411\n        unsigned mask;  // Grid \u306B\u542B\u307E\
    \u308C\u308B\u65B9\u5411\n\n        struct iterator {\n            using difference_type\
    \ = std::ptrdiff_t;\n            using value_type = Grid::value_type;\n      \
    \      using pointer = void;\n            using reference = value_type;\n    \
    \        using iterator_category = std::forward_iterator_tag;\n\n            const\
    \ Neighbors* nb = nullptr;\n            unsigned rest = 0;  // \u307E\u3060\u8FD4\
    \u3057\u3066\u3044\u306A\u3044\u65B9\u5411\n\n            constexpr value_type\
    \ operator*() const noexcept {\n                const int k = nb->first + __builtin_ctz(rest);\n\
    \                return {nb->i + neighbor_dirs[k][0] * nb->row_step, nb->j + neighbor_dirs[k][1]\
    \ * nb->col_step};\n            }\n            constexpr iterator& operator++()\
    \ noexcept {\n                rest &= rest - 1;\n                return *this;\n\
    \            }\n            constexpr iterator operator++(int) noexcept {\n  \
    \              iterator ret(*this);\n                ++*this;\n              \
    \  return ret;\n            }\n            constexpr friend bool operator==(const\
    \ iterator& a, const iterator& b) noexcept { return a.rest == b.rest; }\n    \
    \        constexpr friend bool operator!=(const iterator& a, const iterator& b)\
    \ noexcept { return a.rest != b.rest; }\n        };\n        constexpr iterator\
    \ begin() const noexcept { return {this, mask}; }\n        constexpr iterator\
    \ end() const noexcept { return {this, 0}; }\n        constexpr long long size()\
    \ const noexcept { return __builtin_popcount(mask); }\n        constexpr bool\
    \ empty() const noexcept { return mask == 0; }\n    };\n\n   private:\n    constexpr\
    \ Neighbors neighbors(long long i, long long j, int first, int last) const {\n\
    \        assert(contains(i, j));\n        unsigned mask = 0;\n        for (int\
    \ k = first; k < last; k++) {\n            if (contains(i + neighbor_dirs[k][0]\
    \ * rows.step, j + neighbor_dirs[k][1] * cols.step)) mask |= 1u << (k - first);\n\
    \        }\n        return {i, j, rows.step, cols.step, first, mask};\n    }\n\
    \n   public:\n    /**\n     * @brief (i, j) \u306E\u4E0A\u4E0B\u5DE6\u53F3\u306E\
    \u3046\u3061 Grid \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\
    \u9806\u306B\u8FD4\u3059\n     * \u96A3\u306F rows\u30FBcols \u306E\u4E2D\u3067\
    \u96A3\u308A\u5408\u3046\u8981\u7D20 (i \xB1 rows.step \u306A\u3069)\u3002(i,\
    \ j) \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr Neighbors neighbors4(long long i, long long j) const {\n       \
    \ return neighbors(i, j, 0, 4);\n    }\n    constexpr Neighbors neighbors4(const\
    \ value_type& p) const {\n        return neighbors4(p.first, p.second);\n    }\n\
    \    /**\n     * @brief (i, j) \u3092\u56F2\u3080 8 \u3064\u306E\u3046\u3061 Grid\
    \ \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\u9806\u306B\
    \u8FD4\u3059\n     */\n    constexpr Neighbors neighbors8(long long i, long long\
    \ j) const {\n        return neighbors(i, j, 4, 12);\n    }\n    constexpr Neighbors\
    \ neighbors8(const value_type& p) const {\n        return neighbors8(p.first,\
    \ p.second);\n    }\n\n    static std::string type_str() {\n        return \"\
    Grid\";\n    }\n    std::string initializer_str() const {\n        return \"{\"\
    \ + rows.initializer_str() + \", \" + cols.initializer_str() + \"}\";\n    }\n\
    \    std::string repr() const {\n        return \"Grid(\" + rows.repr() + \",\
    \ \" + cols.repr() + \")\";\n    }\n\n    constexpr friend bool operator==(const\
    \ Grid& a, const Grid& b) noexcept {\n        if (a.empty() && b.empty()) return\
    \ true;\n        return a.rows == b.rows && a.cols == b.cols;\n    }\n    constexpr\
    \ friend bool operator!=(const Grid& a, const Grid& b) noexcept {\n        return\
    \ !(a == b);\n    }\n};\n#line 11 \"test/aoj/dsl/dsl-4-a.2.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<Rectangle<long long>> rects(n);\n\
    \    Compress<long long> cx, cy;\n    for (int i = 0; i < n; i++) {\n        std::cin\
    \ >> rects[i];\n        cx.add(rects[i].left), cx.add(rects[i].right);\n     \
    \   cy.add(rects[i].bottom), cy.add(rects[i].top);\n    }\n    cx.build();\n \
    \   cy.build();\n    int w = cx.size(), h = cy.size();\n    std::vector<std::vector<int>>\
    \ imos(w, std::vector<int>(h));\n    for (int i = 0; i < n; i++) {\n        int\
    \ a = cx.id(rects[i].left), b = cx.id(rects[i].right);\n        int c = cy.id(rects[i].bottom),\
    \ d = cy.id(rects[i].top);\n        imos[a][c]++, imos[a][d]--, imos[b][c]--,\
    \ imos[b][d]++;\n    }\n    for (auto [i, j] : Grid(Range(w), Range(1, h))) imos[i][j]\
    \ += imos[i][j - 1];\n    for (auto [i, j] : Grid(Range(1, w), Range(h))) imos[i][j]\
    \ += imos[i - 1][j];\n    long long ans = 0;\n    for (auto [i, j] : Grid(w -\
    \ 1, h - 1)) {\n        if (imos[i][j] > 0) ans += (cx[i + 1] - cx[i]) * (cy[j\
    \ + 1] - cy[j]);\n    }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n// Compress \u3067\u5EA7\u6A19\u5727\u7E2E\u3059\u308B\n\n#include <iostream>\n\
    #include <vector>\n\n#include \"../../../src/geometry/rectangle.hpp\"\n#include\
    \ \"../../../src/utility/compress.hpp\"\n#include \"../../../src/utility/range.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<Rectangle<long\
    \ long>> rects(n);\n    Compress<long long> cx, cy;\n    for (int i = 0; i < n;\
    \ i++) {\n        std::cin >> rects[i];\n        cx.add(rects[i].left), cx.add(rects[i].right);\n\
    \        cy.add(rects[i].bottom), cy.add(rects[i].top);\n    }\n    cx.build();\n\
    \    cy.build();\n    int w = cx.size(), h = cy.size();\n    std::vector<std::vector<int>>\
    \ imos(w, std::vector<int>(h));\n    for (int i = 0; i < n; i++) {\n        int\
    \ a = cx.id(rects[i].left), b = cx.id(rects[i].right);\n        int c = cy.id(rects[i].bottom),\
    \ d = cy.id(rects[i].top);\n        imos[a][c]++, imos[a][d]--, imos[b][c]--,\
    \ imos[b][d]++;\n    }\n    for (auto [i, j] : Grid(Range(w), Range(1, h))) imos[i][j]\
    \ += imos[i][j - 1];\n    for (auto [i, j] : Grid(Range(1, w), Range(h))) imos[i][j]\
    \ += imos[i - 1][j];\n    long long ans = 0;\n    for (auto [i, j] : Grid(w -\
    \ 1, h - 1)) {\n        if (imos[i][j] > 0) ans += (cx[i + 1] - cx[i]) * (cy[j\
    \ + 1] - cy[j]);\n    }\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/geometry/rectangle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  - src/utility/compress.hpp
  - src/utility/range.hpp
  isVerificationFile: true
  path: test/aoj/dsl/dsl-4-a.2.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 04:55:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl/dsl-4-a.2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl/dsl-4-a.2.test.cpp
- /verify/test/aoj/dsl/dsl-4-a.2.test.cpp.html
title: test/aoj/dsl/dsl-4-a.2.test.cpp
---
