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
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-4-a.3.test.cpp
    title: test/aoj/dsl/dsl-4-a.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/geometry/rectangle-union.test.cpp
    title: test/unittest/geometry/rectangle-union.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
    title: test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D"
    links: []
  bundledCode: "#line 2 \"src/geometry/rectangle-union.hpp\"\n\n/**\n * @file rectangle-union.hpp\n\
    \ * @brief \u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <tuple>\n#include <vector>\n\
    \n#line 2 \"src/geometry/rectangle.hpp\"\n\n/**\n * @file rectangle.hpp\n * @brief\
    \ \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62\n */\n\n#line 9 \"src/geometry/rectangle.hpp\"\
    \n#include <istream>\n#include <type_traits>\n\n#line 2 \"src/geometry/vector.hpp\"\
    \n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n\
    \ */\n\n#include <array>\n#line 10 \"src/geometry/vector.hpp\"\n#include <cmath>\n\
    #line 12 \"src/geometry/vector.hpp\"\n#include <ostream>\n#line 14 \"src/geometry/vector.hpp\"\
    \n#include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <functional>\n\
    #include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\n#if\
    \ __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n\n// \u30B5\u30A4\u30BA\u4ED8\
    \u304D\u7BC4\u56F2\u304B\u3089\u8981\u7D20\u3092\u76F4\u63A5\u69CB\u7BC9\u3059\
    \u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u5171\u6709\u3059\u308B\
    \u3002\n#if __cplusplus >= 202002L\ntemplate <class R, class S>\nconcept sized_constructible_range\
    \ = std::ranges::input_range<R> && std::ranges::sized_range<R> &&\n          \
    \                          std::is_constructible_v<S, std::ranges::range_reference_t<R>>;\n\
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
    \ B, C, D>>;\n#line 14 \"src/geometry/rectangle-union.hpp\"\n\n/**\n * @brief\
    \ \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62 [l, r) \xD7 [d, u) \u306E\u548C\
    \u96C6\u5408\u306E\u9762\u7A4D (\u8D70\u67FB\u7DDA) O(n log n)\n *\n * x \u306E\
    \u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\u3001y \u65B9\u5411\u306E\u5404\
    \u533A\u9593\u3092\u4F55\u679A\u306E\u9577\u65B9\u5F62\u304C\u8986\u3063\u3066\
    \u3044\u308B\u304B\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u6301\u3064\
    \u3002\n * \u8986\u3046\u679A\u6570\u304C\u6B63\u306E\u533A\u9593\u3060\u3051\u3092\
    \u9577\u3055\u306B\u6570\u3048\u308B\u306E\u3067\u3001\u9045\u5EF6\u4F1D\u64AD\
    \u306F\u3044\u3089\u306A\u3044\n * @param rects \u9577\u65B9\u5F62 {l, d, r, u}\
    \ \u306E\u30EA\u30B9\u30C8 (l <= r\u3001d <= u)\n * @return T \u9762\u7A4D\n */\n\
    template <typename T>\nT rectangle_union_area(const std::vector<Rectangle<T>>&\
    \ rects) {\n    std::vector<T> ys;\n    for (const auto& [l, d, r, u] : rects)\
    \ {\n        assert(l <= r && d <= u);\n        ys.push_back(d), ys.push_back(u);\n\
    \    }\n    std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n    const int m = static_cast<int>(ys.size()) - 1;  //\
    \ y \u65B9\u5411\u306E\u533A\u9593 [ys[i], ys[i+1]) \u306E\u500B\u6570\n    if\
    \ (m <= 0) return T(0);\n    // (x, \u52A0\u3048\u308B\u679A\u6570, y \u306E\u533A\
    \u9593 [lo, hi))\n    std::vector<std::tuple<T, int, int, int>> events;\n    for\
    \ (const auto& [l, d, r, u] : rects) {\n        if (l == r || d == u) continue;\n\
    \        int lo = std::lower_bound(ys.begin(), ys.end(), d) - ys.begin(), hi =\
    \ std::lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n        events.emplace_back(l,\
    \ 1, lo, hi);\n        events.emplace_back(r, -1, lo, hi);\n    }\n    std::sort(events.begin(),\
    \ events.end());\n    int sz = 1;\n    while (sz < m) sz <<= 1;\n    std::vector<int>\
    \ cover(2 * sz, 0);  // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u5168\
    \u4F53\u3092\u8986\u3046\u9577\u65B9\u5F62\u306E\u679A\u6570\n    std::vector<T>\
    \ len(2 * sz, T(0));   // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u3067\
    \u8986\u308F\u308C\u3066\u3044\u308B\u9577\u3055\n    // \u30CE\u30FC\u30C9 k\
    \ (\u533A\u9593 [a, b)) \u306B [lo, hi) \u3092 v \u679A\u8DB3\u3059\n    auto\
    \ add = [&](auto&& self, int k, int a, int b, int lo, int hi, int v) -> void {\n\
    \        if (hi <= a || b <= lo) return;\n        if (lo <= a && b <= hi) {\n\
    \            cover[k] += v;\n        } else {\n            int c = (a + b) / 2;\n\
    \            self(self, 2 * k, a, c, lo, hi, v);\n            self(self, 2 * k\
    \ + 1, c, b, lo, hi, v);\n        }\n        if (cover[k] > 0)\n            len[k]\
    \ = ys[std::min(b, m)] - ys[std::min(a, m)];\n        else\n            len[k]\
    \ = k >= sz ? T(0) : len[2 * k] + len[2 * k + 1];\n    };\n    T res = 0;\n  \
    \  for (int i = 0; i < static_cast<int>(events.size()); i++) {\n        auto [x,\
    \ v, lo, hi] = events[i];\n        add(add, 1, 0, sz, lo, hi, v);\n        if\
    \ (i + 1 < static_cast<int>(events.size())) res += len[1] * (std::get<0>(events[i\
    \ + 1]) - x);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file rectangle-union.hpp\n * @brief \u9577\u65B9\
    \u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\n#include \"rectangle.hpp\"\
    \n\n/**\n * @brief \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62 [l, r) \xD7\
    \ [d, u) \u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (\u8D70\u67FB\u7DDA) O(n log\
    \ n)\n *\n * x \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\u3001y \u65B9\
    \u5411\u306E\u5404\u533A\u9593\u3092\u4F55\u679A\u306E\u9577\u65B9\u5F62\u304C\
    \u8986\u3063\u3066\u3044\u308B\u304B\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u6301\u3064\u3002\n * \u8986\u3046\u679A\u6570\u304C\u6B63\u306E\u533A\u9593\
    \u3060\u3051\u3092\u9577\u3055\u306B\u6570\u3048\u308B\u306E\u3067\u3001\u9045\
    \u5EF6\u4F1D\u64AD\u306F\u3044\u3089\u306A\u3044\n * @param rects \u9577\u65B9\
    \u5F62 {l, d, r, u} \u306E\u30EA\u30B9\u30C8 (l <= r\u3001d <= u)\n * @return\
    \ T \u9762\u7A4D\n */\ntemplate <typename T>\nT rectangle_union_area(const std::vector<Rectangle<T>>&\
    \ rects) {\n    std::vector<T> ys;\n    for (const auto& [l, d, r, u] : rects)\
    \ {\n        assert(l <= r && d <= u);\n        ys.push_back(d), ys.push_back(u);\n\
    \    }\n    std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n    const int m = static_cast<int>(ys.size()) - 1;  //\
    \ y \u65B9\u5411\u306E\u533A\u9593 [ys[i], ys[i+1]) \u306E\u500B\u6570\n    if\
    \ (m <= 0) return T(0);\n    // (x, \u52A0\u3048\u308B\u679A\u6570, y \u306E\u533A\
    \u9593 [lo, hi))\n    std::vector<std::tuple<T, int, int, int>> events;\n    for\
    \ (const auto& [l, d, r, u] : rects) {\n        if (l == r || d == u) continue;\n\
    \        int lo = std::lower_bound(ys.begin(), ys.end(), d) - ys.begin(), hi =\
    \ std::lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n        events.emplace_back(l,\
    \ 1, lo, hi);\n        events.emplace_back(r, -1, lo, hi);\n    }\n    std::sort(events.begin(),\
    \ events.end());\n    int sz = 1;\n    while (sz < m) sz <<= 1;\n    std::vector<int>\
    \ cover(2 * sz, 0);  // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u5168\
    \u4F53\u3092\u8986\u3046\u9577\u65B9\u5F62\u306E\u679A\u6570\n    std::vector<T>\
    \ len(2 * sz, T(0));   // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u3067\
    \u8986\u308F\u308C\u3066\u3044\u308B\u9577\u3055\n    // \u30CE\u30FC\u30C9 k\
    \ (\u533A\u9593 [a, b)) \u306B [lo, hi) \u3092 v \u679A\u8DB3\u3059\n    auto\
    \ add = [&](auto&& self, int k, int a, int b, int lo, int hi, int v) -> void {\n\
    \        if (hi <= a || b <= lo) return;\n        if (lo <= a && b <= hi) {\n\
    \            cover[k] += v;\n        } else {\n            int c = (a + b) / 2;\n\
    \            self(self, 2 * k, a, c, lo, hi, v);\n            self(self, 2 * k\
    \ + 1, c, b, lo, hi, v);\n        }\n        if (cover[k] > 0)\n            len[k]\
    \ = ys[std::min(b, m)] - ys[std::min(a, m)];\n        else\n            len[k]\
    \ = k >= sz ? T(0) : len[2 * k] + len[2 * k + 1];\n    };\n    T res = 0;\n  \
    \  for (int i = 0; i < static_cast<int>(events.size()); i++) {\n        auto [x,\
    \ v, lo, hi] = events[i];\n        add(add, 1, 0, sz, lo, hi, v);\n        if\
    \ (i + 1 < static_cast<int>(events.size())) res += len[1] * (std::get<0>(events[i\
    \ + 1]) - x);\n    }\n    return res;\n}\n"
  dependsOn:
  - src/geometry/rectangle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/geometry/rectangle-union.hpp
  requiredBy: []
  timestamp: '2026-11-08 20:13:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/geometry/rectangle-union.test.cpp
  - test/aoj/dsl/dsl-4-a.3.test.cpp
  - test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
documentation_of: src/geometry/rectangle-union.hpp
layout: document
title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D"
---

軸に平行な長方形 $[l, r) \times [d, u)$ がいくつか与えられたとき、その和集合の面積を走査線で $O(n \log n)$ で求めます。

```cpp
std::vector<Rectangle<long long>> rects = { {0, 0, 3, 4}, {1, 2, 4, 3} };  // {l, d, r, u}
long long s = rectangle_union_area(rects);  // 12 + 3 - 2 = 13
```

x の小さい順に走査し、y 方向の各区間を何枚の長方形が覆っているかをセグメント木で持ちます。覆う枚数が正のノードはその区間全体を覆われているとし、そうでなければ子の長さを足します。枚数を子に伝える必要がないので、遅延伝播は使いません。

長方形は `Rectangle<T> {left, bottom, right, top}` (`{l, d, r, u}`) ($l \le r$、$d \le u$) で渡します。幅か高さが 0 の長方形は無視します。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `rectangle_union_area(rects)` | 長方形 `{l, d, r, u}` (`Rectangle<T>`) の和集合の面積 (`T`) | $O(n \log n)$ |

## 関連

- 長方形の型と包含判定は [軸に平行な長方形](rectangle.hpp)
- 長方形の重なりの枚数の最大値は [2 次元のいもす法](../data_structures/imos-2d.hpp)
- 区間加算・区間最小値とその個数の遅延セグメント木でも同じことができる ([遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp) と `acted_monoid::AddMinCount`)
