---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/manhattan.hpp
    title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 (\u6700\u8FD1\u70B9\u5BFE\
      \u30FB\u6700\u9060\u70B9\u5BFE\u3001\u5404\u70B9\u304B\u3089\u6700\u3082\u8FD1\
      \u3044\u70B9\u30FB\u6700\u3082\u9060\u3044\u70B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/vector.hpp
    title: "\u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB"
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
  bundledCode: "#line 1 \"test/unittest/geometry/manhattan.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ geometry/manhattan.hpp \u306E\u95A2\u6570\u3092\u3001\u3059\u3079\u3066\u306E\
    \u70B9\u306E\u7D44\u3092\u8ABF\u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u6BD4\u3079\u308B\n// \u540C\u3058\u8DDD\u96E2\u306E\u70B9\u304C\u8907\u6570\u3042\
    \u308B\u3053\u3068\u304C\u3042\u308B\u306E\u3067\u3001\u6DFB\u5B57\u3067\u306F\
    \u306A\u304F\u8DDD\u96E2\u3067\u6BD4\u3079\u308B (\u6DFB\u5B57\u304C\u81EA\u5206\
    \u81EA\u8EAB\u3067\u306A\u3044\u3053\u3068\u3068\u3001\u8DDD\u96E2\u304C\u5408\
    \u3046\u3053\u3068\u3092\u78BA\u304B\u3081\u308B)\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u6210\u308A\u7ACB\u3063\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/geometry/manhattan.hpp\"\
    \n\n/**\n * @file manhattan.hpp\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\
    \u8DDD\u96E2 (\u6700\u8FD1\u70B9\u5BFE\u30FB\u6700\u9060\u70B9\u5BFE\u3001\u5404\
    \u70B9\u304B\u3089\u6700\u3082\u8FD1\u3044\u70B9\u30FB\u6700\u3082\u9060\u3044\
    \u70B9)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include\
    \ <map>\n#include <numeric>\n#include <vector>\n\n#line 2 \"src/geometry/vector.hpp\"\
    \n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n\
    \ */\n\n#include <array>\n#line 11 \"src/geometry/vector.hpp\"\n#include <istream>\n\
    #include <ostream>\n#include <type_traits>\n#include <utility>\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <functional>\n#include <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\
    \n\nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
    \ T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class\
    \ T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n#line 16 \"src/geometry/manhattan.hpp\"\
    \n\nnamespace internal_manhattan {\n/**\n * @brief \u5404\u70B9 j \u3068\u3001\
    j \u3092\u9802\u70B9\u3068\u3059\u308B 45 \u5EA6\u305A\u3064\u306E 8 \u3064\u306E\
    \u9818\u57DF\u306E\u3046\u3061 4 \u3064\u306E\u305D\u308C\u305E\u308C\u306B\u3064\
    \u3044\u3066\u3001\u305D\u306E\u9818\u57DF\u3067 j \u306B\u6700\u3082\u8FD1\u3044\
    \u70B9 i \u3092 f(j, i, \u8DDD\u96E2) \u3067\u6E21\u3059 O(n log n)\n * \u6B8B\
    \u308A\u306E 4 \u3064\u306E\u9818\u57DF\u306F\u3001\u70B9\u3092\u539F\u70B9\u306B\
    \u3064\u3044\u3066\u53CD\u8EE2\u3055\u305B\u3066\u547C\u3079\u3070\u5F97\u3089\
    \u308C\u308B\n */\ntemplate <typename T, typename F>\nvoid octant_nearest(std::vector<Vector<T,\
    \ 2>> p, F f) {\n    const long long n = p.size();\n    std::vector<long long>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n    for (int k = 0; k < 4;\
    \ k++) {\n        // x + y \u306E\u6607\u9806\u306B\u898B\u3066\u3001x - y \u306E\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u4E2D\u3067 y \u304C\u8FD1\u3044\u70B9\u3092\
    \ map \u304B\u3089\u53D6\u308A\u51FA\u3059\n        std::sort(id.begin(), id.end(),\
    \ [&](long long i, long long j) { return p[i][0] + p[i][1] < p[j][0] + p[j][1];\
    \ });\n        std::map<T, long long> sweep;  // -y -> \u70B9\n        for (long\
    \ long i : id) {\n            for (auto it = sweep.lower_bound(-p[i][1]); it !=\
    \ sweep.end(); it = sweep.erase(it)) {\n                const long long j = it->second;\n\
    \                const T dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];\n   \
    \             if (dy > dx) break;\n                f(j, i, dx + dy);\n       \
    \     }\n            sweep[-p[i][1]] = i;\n        }\n        // 4 \u3064\u306E\
    \u5411\u304D: (x, y) -> (y, x) -> (-y, x) -> (x, -y) \u3068\u5909\u3048\u308B\n\
    \        for (auto& v : p) {\n            if (k % 2 == 0) {\n                std::swap(v[0],\
    \ v[1]);\n            } else {\n                v[0] = -v[0];\n            }\n\
    \        }\n    }\n}\n}  // namespace internal_manhattan\n\n/**\n * @brief \u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u8FD1\u70B9\u5BFE\u30FB\
    \u6700\u9060\u70B9\u5BFE\u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\n\
    struct ManhattanPair {\n    T dist;          //!< \u8DDD\u96E2\n    long long\
    \ i, j;  //!< 2 \u70B9\u306E\u6DFB\u5B57 (i != j)\n};\n\n/**\n * @brief \u5404\
    \u70B9\u304B\u3089\u3001\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\
    \u6700\u3082\u8FD1\u3044\u307B\u304B\u306E\u70B9\u306E\u6DFB\u5B57 O(n log n)\n\
    \ * 8 \u3064\u306E\u9818\u57DF\u306E\u305D\u308C\u305E\u308C\u3067\u6700\u3082\
    \u8FD1\u3044\u70B9\u306E\u3046\u3061\u3001\u6700\u3082\u8FD1\u3044\u3082\u306E\
    \u3002\u70B9\u304C 1 \u500B\u306A\u3089 -1\n */\ntemplate <typename T>\nstd::vector<long\
    \ long> manhattan_nearest_points(const std::vector<Vector<T, 2>>& p) {\n    const\
    \ long long n = p.size();\n    std::vector<long long> res(n, -1);\n    std::vector<T>\
    \ best(n);\n    // \u540C\u3058\u4F4D\u7F6E\u306E\u70B9\u3069\u3046\u3057\u306F\
    \u3001\u3069\u306E\u5411\u304D\u3067\u6383\u3044\u3066\u3082\u4E26\u3076\u9806\
    \u304C\u5909\u308F\u3089\u305A\u7247\u65B9\u304B\u3089\u3057\u304B\u898B\u3064\
    \u304B\u3089\u306A\u3044\u306E\u3067\u3001\u5148\u306B\u7D44\u306B\u3059\u308B\
    \n    std::vector<long long> id(n);\n    std::iota(id.begin(), id.end(), 0);\n\
    \    std::sort(id.begin(), id.end(), [&](long long i, long long j) { return p[i]\
    \ < p[j]; });\n    for (long long k = 0; k + 1 < n; k++) {\n        if (p[id[k]]\
    \ == p[id[k + 1]]) res[id[k]] = id[k + 1], res[id[k + 1]] = id[k], best[id[k]]\
    \ = best[id[k + 1]] = 0;\n    }\n    auto update = [&](long long j, long long\
    \ i, T d) {\n        if (res[j] == -1 || d < best[j]) res[j] = i, best[j] = d;\n\
    \    };\n    internal_manhattan::octant_nearest(p, update);\n    std::vector<Vector<T,\
    \ 2>> q(p);\n    for (auto& v : q) v = -v;\n    internal_manhattan::octant_nearest(q,\
    \ update);\n    return res;\n}\n\n/**\n * @brief \u5404\u70B9\u304B\u3089\u3001\
    \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\u6700\u3082\u9060\u3044\
    \u70B9\u306E\u6DFB\u5B57 O(n)\n * |dx| + |dy| = max(|du|, |dv|) (u = x + y, v\
    \ = x - y) \u306A\u306E\u3067\u3001u \u3068 v \u304C\u6700\u5927\u30FB\u6700\u5C0F\
    \u306E\u70B9\u306E\u3069\u308C\u304B\u3002\u70B9\u304C 1 \u500B\u306A\u3089 -1\n\
    \ */\ntemplate <typename T>\nstd::vector<long long> manhattan_farthest_points(const\
    \ std::vector<Vector<T, 2>>& p) {\n    const long long n = p.size();\n    if (n\
    \ <= 1) return std::vector<long long>(n, -1);\n    // ext[0], ext[1]: u \u304C\
    \u6700\u5C0F\u30FB\u6700\u5927\u306E\u70B9\u3001ext[2], ext[3]: v \u304C\u6700\
    \u5C0F\u30FB\u6700\u5927\u306E\u70B9\n    auto u = [&](long long i) { return p[i][0]\
    \ + p[i][1]; };\n    auto v = [&](long long i) { return p[i][0] - p[i][1]; };\n\
    \    long long ext[4] = {0, 0, 0, 0};\n    for (long long i = 1; i < n; i++) {\n\
    \        if (u(i) < u(ext[0])) ext[0] = i;\n        if (u(i) > u(ext[1])) ext[1]\
    \ = i;\n        if (v(i) < v(ext[2])) ext[2] = i;\n        if (v(i) > v(ext[3]))\
    \ ext[3] = i;\n    }\n    std::vector<long long> res(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        long long b = -1;\n        T best = 0;\n       \
    \ for (long long j : ext) {\n            const T d = std::abs(p[i][0] - p[j][0])\
    \ + std::abs(p[i][1] - p[j][1]);\n            if (j != i && (b == -1 || d > best))\
    \ b = j, best = d;\n        }\n        // 4 \u70B9\u304C\u3059\u3079\u3066 i \u81EA\
    \u8EAB\u306A\u3089\u3001\u3059\u3079\u3066\u306E\u70B9\u304C\u540C\u3058\u4F4D\
    \u7F6E\u306B\u3042\u308B\n        res[i] = b == -1 ? (i == 0 ? 1 : 0) : b;\n \
    \   }\n    return res;\n}\n\n/**\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\
    \u8DDD\u96E2\u306E\u6700\u8FD1\u70B9\u5BFE (\u70B9\u306F 2 \u500B\u4EE5\u4E0A\
    ) O(n log n)\n * \u6700\u5C0F\u5168\u57DF\u6728\u306E\u8FBA\u306E\u5019\u88DC\
    \ (\u5404\u70B9\u304B\u3089 4 \u3064\u306E\u9818\u57DF\u3067\u6700\u3082\u8FD1\
    \u3044\u70B9\u3078\u306E\u8FBA) \u306B\u3001\u6700\u3082\u8FD1\u3044 2 \u70B9\u3092\
    \u7D50\u3076\u8FBA\u304C\u542B\u307E\u308C\u308B\n */\ntemplate <typename T>\n\
    ManhattanPair<T> manhattan_closest_pair(const std::vector<Vector<T, 2>>& p) {\n\
    \    assert(p.size() >= 2 && \"manhattan_closest_pair: fewer than 2 points\");\n\
    \    ManhattanPair<T> res{T(0), -1, -1};\n    internal_manhattan::octant_nearest(p,\
    \ [&](long long j, long long i, T d) {\n        if (res.i == -1 || d < res.dist)\
    \ res = {d, std::min(i, j), std::max(i, j)};\n    });\n    return res;\n}\n\n\
    /**\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u9060\
    \u70B9\u5BFE (\u70B9\u306F 2 \u500B\u4EE5\u4E0A) O(n)\n * u = x + y, v = x - y\
    \ \u306E\u6700\u5927\u3068\u6700\u5C0F\u306E\u5DEE\u306E\u3046\u3061\u5927\u304D\
    \u3044\u65B9\n */\ntemplate <typename T>\nManhattanPair<T> manhattan_farthest_pair(const\
    \ std::vector<Vector<T, 2>>& p) {\n    const long long n = p.size();\n    assert(n\
    \ >= 2 && \"manhattan_farthest_pair: fewer than 2 points\");\n    const std::vector<long\
    \ long> f = manhattan_farthest_points(p);\n    ManhattanPair<T> res{T(0), -1,\
    \ -1};\n    for (long long i = 0; i < n; i++) {\n        const long long j = f[i];\n\
    \        const T d = std::abs(p[i][0] - p[j][0]) + std::abs(p[i][1] - p[j][1]);\n\
    \        if (res.i == -1 || d > res.dist) res = {d, std::min(i, j), std::max(i,\
    \ j)};\n    }\n    return res;\n}\n#line 8 \"test/unittest/geometry/manhattan.test.cpp\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <random>\n#line 13 \"test/unittest/geometry/manhattan.test.cpp\"\
    \n\n#line 15 \"test/unittest/geometry/manhattan.test.cpp\"\n\nusing P = Vector<long\
    \ long>;\n\nlong long dist(const P& a, const P& b) { return std::abs(a[0] - b[0])\
    \ + std::abs(a[1] - b[1]); }\n\nint main() {\n    std::mt19937 rng(314);\n   \
    \ bool ok = true;\n    for (int rep = 0; rep < 20000 && ok; rep++) {\n       \
    \ const int n = rng() % 12 + 1;\n        const int ws[3] = {2, 100, 1000000000};\
    \  // \u5C0F\u3055\u3044\u3068\u540C\u3058\u70B9\u3084\u540C\u3058\u8DDD\u96E2\
    \u304C\u591A\u3044\n        const int w = ws[rng() % 3];\n        std::vector<P>\
    \ p(n);\n        for (auto& x : p) x = P(static_cast<long long>(rng() % (2 * w\
    \ + 1)) - w, static_cast<long long>(rng() % (2 * w + 1)) - w);\n\n        auto\
    \ near = manhattan_nearest_points(p);\n        auto far = manhattan_farthest_points(p);\n\
    \        for (int i = 0; i < n && ok; i++) {\n            if (n == 1) {\n    \
    \            if (near[i] != -1 || far[i] != -1) ok = false;\n                continue;\n\
    \            }\n            long long lo = -1, hi = -1;\n            for (int\
    \ j = 0; j < n; j++) {\n                if (j == i) continue;\n              \
    \  long long d = dist(p[i], p[j]);\n                if (lo == -1 || d < lo) lo\
    \ = d;\n                if (hi == -1 || d > hi) hi = d;\n            }\n     \
    \       if (near[i] < 0 || near[i] >= n || near[i] == i || dist(p[i], p[near[i]])\
    \ != lo) ok = false;\n            if (far[i] < 0 || far[i] >= n || far[i] == i\
    \ || dist(p[i], p[far[i]]) != hi) ok = false;\n        }\n        if (n < 2 ||\
    \ !ok) continue;\n        long long lo = -1, hi = -1;\n        for (int i = 0;\
    \ i < n; i++) {\n            for (int j = i + 1; j < n; j++) {\n             \
    \   long long d = dist(p[i], p[j]);\n                if (lo == -1 || d < lo) lo\
    \ = d;\n                if (hi == -1 || d > hi) hi = d;\n            }\n     \
    \   }\n        auto c = manhattan_closest_pair(p);\n        auto f = manhattan_farthest_pair(p);\n\
    \        if (c.dist != lo || !(0 <= c.i && c.i < c.j && c.j < n) || dist(p[c.i],\
    \ p[c.j]) != lo) ok = false;\n        if (f.dist != hi || !(0 <= f.i && f.i <\
    \ f.j && f.j < n) || dist(p[f.i], p[f.j]) != hi) ok = false;\n    }\n    // \u3059\
    \u3079\u3066\u540C\u3058\u70B9\n    {\n        std::vector<P> p(3, P(5, -5));\n\
    \        auto f = manhattan_farthest_points(p);\n        auto c = manhattan_closest_pair(p),\
    \ g = manhattan_farthest_pair(p);\n        for (int i = 0; i < 3; i++) {\n   \
    \         if (f[i] == i) ok = false;\n        }\n        if (c.dist != 0 || c.i\
    \ == c.j || g.dist != 0 || g.i == g.j) ok = false;\n    }\n\n    if (ok)\n   \
    \     std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// geometry/manhattan.hpp \u306E\u95A2\u6570\u3092\u3001\u3059\u3079\u3066\
    \u306E\u70B9\u306E\u7D44\u3092\u8ABF\u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\
    \u3068\u6BD4\u3079\u308B\n// \u540C\u3058\u8DDD\u96E2\u306E\u70B9\u304C\u8907\u6570\
    \u3042\u308B\u3053\u3068\u304C\u3042\u308B\u306E\u3067\u3001\u6DFB\u5B57\u3067\
    \u306F\u306A\u304F\u8DDD\u96E2\u3067\u6BD4\u3079\u308B (\u6DFB\u5B57\u304C\u81EA\
    \u5206\u81EA\u8EAB\u3067\u306A\u3044\u3053\u3068\u3068\u3001\u8DDD\u96E2\u304C\
    \u5408\u3046\u3053\u3068\u3092\u78BA\u304B\u3081\u308B)\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u6210\u308A\u7ACB\
    \u3063\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/geometry/manhattan.hpp\"\
    \n\n#include <cstdlib>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"../../../src/geometry/vector.hpp\"\n\nusing P = Vector<long long>;\n\
    \nlong long dist(const P& a, const P& b) { return std::abs(a[0] - b[0]) + std::abs(a[1]\
    \ - b[1]); }\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 20000 && ok; rep++) {\n        const int n = rng()\
    \ % 12 + 1;\n        const int ws[3] = {2, 100, 1000000000};  // \u5C0F\u3055\u3044\
    \u3068\u540C\u3058\u70B9\u3084\u540C\u3058\u8DDD\u96E2\u304C\u591A\u3044\n   \
    \     const int w = ws[rng() % 3];\n        std::vector<P> p(n);\n        for\
    \ (auto& x : p) x = P(static_cast<long long>(rng() % (2 * w + 1)) - w, static_cast<long\
    \ long>(rng() % (2 * w + 1)) - w);\n\n        auto near = manhattan_nearest_points(p);\n\
    \        auto far = manhattan_farthest_points(p);\n        for (int i = 0; i <\
    \ n && ok; i++) {\n            if (n == 1) {\n                if (near[i] != -1\
    \ || far[i] != -1) ok = false;\n                continue;\n            }\n   \
    \         long long lo = -1, hi = -1;\n            for (int j = 0; j < n; j++)\
    \ {\n                if (j == i) continue;\n                long long d = dist(p[i],\
    \ p[j]);\n                if (lo == -1 || d < lo) lo = d;\n                if\
    \ (hi == -1 || d > hi) hi = d;\n            }\n            if (near[i] < 0 ||\
    \ near[i] >= n || near[i] == i || dist(p[i], p[near[i]]) != lo) ok = false;\n\
    \            if (far[i] < 0 || far[i] >= n || far[i] == i || dist(p[i], p[far[i]])\
    \ != hi) ok = false;\n        }\n        if (n < 2 || !ok) continue;\n       \
    \ long long lo = -1, hi = -1;\n        for (int i = 0; i < n; i++) {\n       \
    \     for (int j = i + 1; j < n; j++) {\n                long long d = dist(p[i],\
    \ p[j]);\n                if (lo == -1 || d < lo) lo = d;\n                if\
    \ (hi == -1 || d > hi) hi = d;\n            }\n        }\n        auto c = manhattan_closest_pair(p);\n\
    \        auto f = manhattan_farthest_pair(p);\n        if (c.dist != lo || !(0\
    \ <= c.i && c.i < c.j && c.j < n) || dist(p[c.i], p[c.j]) != lo) ok = false;\n\
    \        if (f.dist != hi || !(0 <= f.i && f.i < f.j && f.j < n) || dist(p[f.i],\
    \ p[f.j]) != hi) ok = false;\n    }\n    // \u3059\u3079\u3066\u540C\u3058\u70B9\
    \n    {\n        std::vector<P> p(3, P(5, -5));\n        auto f = manhattan_farthest_points(p);\n\
    \        auto c = manhattan_closest_pair(p), g = manhattan_farthest_pair(p);\n\
    \        for (int i = 0; i < 3; i++) {\n            if (f[i] == i) ok = false;\n\
    \        }\n        if (c.dist != 0 || c.i == c.j || g.dist != 0 || g.i == g.j)\
    \ ok = false;\n    }\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/geometry/manhattan.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/geometry/manhattan.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 17:31:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/geometry/manhattan.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/geometry/manhattan.test.cpp
- /verify/test/unittest/geometry/manhattan.test.cpp.html
title: test/unittest/geometry/manhattan.test.cpp
---
