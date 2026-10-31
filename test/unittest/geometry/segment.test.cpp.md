---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/segment.hpp
    title: "\u76F4\u7DDA\u30FB\u7DDA\u5206 (\u4EA4\u5DEE\u5224\u5B9A\u3001\u4EA4\u70B9\
      \u3001\u5C04\u5F71\u3001\u8DDD\u96E2)"
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
  bundledCode: "#line 1 \"test/unittest/geometry/segment.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ geometry/segment.hpp \u306E\u76F4\u7DDA\u30FB\u7DDA\u5206\u306E\u95A2\u6570\
    \ (ccw\u3001\u5E73\u884C\u30FB\u76F4\u4EA4\u3001\u5C04\u5F71\u3001\u53CD\u5C04\
    \u3001\u4EA4\u70B9\u3001\u8DDD\u96E2) \u3092\u3001\u5B9A\u7FA9\u304B\u3089\u78BA\
    \u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u6210\u308A\u7ACB\u3063\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/geometry/segment.hpp\"\n\n/**\n * @file segment.hpp\n\
    \ * @brief 2 \u6B21\u5143\u306E\u70B9\u30FB\u76F4\u7DDA\u30FB\u7DDA\u5206 (\u4EA4\
    \u5DEE\u5224\u5B9A\u3001\u4EA4\u70B9\u3001\u5C04\u5F71\u3001\u8DDD\u96E2)\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <optional>\n\
    #include <type_traits>\n\n#line 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file\
    \ vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n */\n\n#include\
    \ <array>\n#line 11 \"src/geometry/vector.hpp\"\n#include <istream>\n#include\
    \ <ostream>\n#line 14 \"src/geometry/vector.hpp\"\n#include <utility>\n\n#line\
    \ 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\
    \u6027\n */\n\n#include <cstddef>\n#include <functional>\n#include <iterator>\n\
    #include <set>\n#line 14 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n#line 15 \"src/geometry/segment.hpp\"\
    \n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\
    \u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u5916\u7A4D\u3092\u8A08\u7B97\u3059\
    \u308B\u305F\u3081\u3001\u5EA7\u6A19\u306E\u7D76\u5BFE\u5024\u306E2\u4E57\u306E\
    \u6570\u500D\u304CT\u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n *\n\
    \ * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param p2\
    \ 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param q1 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return bool \u5171\
    \u6709\u70B9\u3092\u6301\u3064\u304B\n */\ntemplate <typename T>\nconstexpr bool\
    \ segments_intersect(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T,\
    \ 2>& q1, const Vector<T, 2>& q2) {\n    assert(p1 != p2 && q1 != q2 && \"segments_intersect:\
    \ degenerate segment\");\n    auto sign = [](T x) { return (x > 0) - (x < 0);\
    \ };\n    int q1_section = sign(cross(p2 - p1, q1 - p1));  // \u76F4\u7DDAp1p2\u306B\
    \u5BFE\u3057\u3066q1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int q2_section = sign(cross(p2 - p1, q2 - p1));  // \u76F4\u7DDAp1p2\u306B\
    \u5BFE\u3057\u3066q2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int p1_section = sign(cross(q2 - q1, p1 - q1));  // \u76F4\u7DDAq1q2\u306B\
    \u5BFE\u3057\u3066p1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   int p2_section = sign(cross(q2 - q1, p2 - q1));  // \u76F4\u7DDAq1q2\u306B\
    \u5BFE\u3057\u3066p2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n \
    \   if (q1_section == 0 && q2_section == 0) {\n        // 4\u70B9\u304C\u540C\u4E00\
    \u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\n        return dot(q1 - p1,\
    \ q2 - p1) <= 0 || dot(q1 - p2, q2 - p2) <= 0 || dot(p1 - q1, p2 - q1) <= 0;\n\
    \    }\n    return q1_section * q2_section <= 0 && p1_section * p2_section <=\
    \ 0;\n}\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u3068\u5171\
    \u6709\u70B9\u306E\u8A08\u7B97\n *\n * \u5171\u6709\u70B9\u306E\u5EA7\u6A19\u306F\
    \u4E00\u822C\u306B\u6574\u6570\u306B\u306A\u3089\u306A\u3044\u305F\u3081\u3001\
    \u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n * \u6574\u6570\u5EA7\u6A19\u3067\
    \u4EA4\u5DEE\u5224\u5B9A\u3060\u3051\u3057\u305F\u3044\u5834\u5408\u306F segments_intersect\
    \ \u3092\u4F7F\u3046\n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\
    \u70B91\n * @param p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param\
    \ q1 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n\
    \ * @return std::optional<Vector<T, 2>> \u5171\u6709\u70B9\u306E1\u4F8B (\u5171\
    \u6709\u70B9\u304C\u306A\u3051\u308C\u3070 std::nullopt)\n */\ntemplate <typename\
    \ T>\nconstexpr std::optional<Vector<T, 2>> segment_intersection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    static_assert(std::is_floating_point_v<T>, \"segment_intersection:\
    \ T must be a floating point type (use segments_intersect for integers)\");\n\
    \    if (!segments_intersect(p1, p2, q1, q2)) return std::nullopt;\n    if (cross(p2\
    \ - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n        // 4\u70B9\u304C\
    \u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\n        if (dot(q1\
    \ - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2, q2 - p2) <= 0) return\
    \ p2;\n        return q1;\n    }\n    T area = cross(p2 - p1, q2 - q1);      \
    \    // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\u89D2\u5F62\u306E\u7B26\
    \u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2 - q1, p1 - q1);\
    \  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n   \
    \ return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief 3\u70B9\u306E\
    \u4F4D\u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\u578B\u3067\u3082\
    \u4F7F\u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u306F\u8AA4\
    \u5DEE\u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\n *\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192c \u304C\u53CD\u6642\
    \u8A08\u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a, b \u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A\
    , 0: c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename T>\nconstexpr int\
    \ ccw(const Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T, 2>& c) {\n\
    \    Vector<T, 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n    if (cr >\
    \ 0) return 1;\n    if (cr < 0) return -1;\n    if (dot(u, v) < 0) return 2;\n\
    \    if (u.squared_norm() < v.squared_norm()) return -2;\n    return 0;\n}\n\n\
    /**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\u884C\u304B\
    \ (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\nconstexpr bool is_parallel(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    return cross(p2 - p1,\
    \ q2 - q1) == 0;\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2\
    \ \u304C\u76F4\u4EA4\u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\
    \u308B)\n */\ntemplate <typename T>\nconstexpr bool is_orthogonal(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9 p\
    \ \u304B\u3089\u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
    \u8DB3 (\u5C04\u5F71)\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n\
    \ */\ntemplate <typename T>\nconstexpr Vector<T, 2> projection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"projection: T must be a floating point type\");\n    assert(p1 != p2 && \"\
    projection: degenerate line\");\n    Vector<T, 2> d = p2 - p1;\n    return p1\
    \ + d * (dot(p - p1, d) / d.squared_norm());\n}\n/**\n * @brief \u76F4\u7DDA p1p2\
    \ \u306B\u3064\u3044\u3066\u70B9 p \u3068\u5BFE\u79F0\u306A\u70B9 (\u53CD\u5C04\
    )\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 2> reflection(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& p) {\n    return projection(p1, p2, p) * T(2) -\
    \ p;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u306E\u4EA4\
    \u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\u3002p1 != p2 \u304B\
    \u3064 q1 != q2 \u3067\u3042\u308B\u3053\u3068\n * @return std::optional<Vector<T,\
    \ 2>> \u4EA4\u70B9 (\u5E73\u884C (\u91CD\u306A\u308B\u76F4\u7DDA\u3082\u542B\u3080\
    ) \u306A\u3089 std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> line_intersection(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const\
    \ Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"line_intersection: T must be a floating point type\");\n    assert(p1 != p2\
    \ && q1 != q2 && \"line_intersection: degenerate line\");\n    Vector<T, 2> d\
    \ = p2 - p1, e = q2 - q1;\n    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n\
    \    // p1 + d t \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return\
    \ p1 + d * (cross(e, q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\
    \u7DDA p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\
    )\n */\ntemplate <typename T>\ndouble distance_point_line(const Vector<T, 2>&\
    \ p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    assert(p1 != p2 &&\
    \ \"distance_point_line: degenerate line\");\n    return std::abs(static_cast<double>(cross(p2\
    \ - p1, p - p1))) / (p2 - p1).abs();\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206\
    \ p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n\
    \ */\ntemplate <typename T>\ndouble distance_point_segment(const Vector<T, 2>&\
    \ p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    if (p1 == p2) return\
    \ (p - p1).abs();\n    // \u5782\u7DDA\u306E\u8DB3\u304C\u7DDA\u5206\u306E\u5916\
    \u306A\u3089\u3001\u8FD1\u3044\u65B9\u306E\u7AEF\u70B9\u3068\u306E\u8DDD\u96E2\
    \n    if (dot(p2 - p1, p - p1) < 0) return (p - p1).abs();\n    if (dot(p1 - p2,\
    \ p - p2) < 0) return (p - p2).abs();\n    return distance_point_line(p1, p2,\
    \ p);\n}\n/**\n * @brief \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_segments(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    if (p1 != p2 && q1 !=\
    \ q2 && segments_intersect(p1, p2, q1, q2)) return 0;\n    return std::min({distance_point_segment(p1,\
    \ p2, q1), distance_point_segment(p1, p2, q2),\n                     distance_point_segment(q1,\
    \ q2, p1), distance_point_segment(q1, q2, p2)});\n}\n#line 7 \"test/unittest/geometry/segment.test.cpp\"\
    \n\n#line 10 \"test/unittest/geometry/segment.test.cpp\"\n#include <iostream>\n\
    #include <random>\n\n#line 14 \"test/unittest/geometry/segment.test.cpp\"\n\n\
    int main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    using P = Vector<double>;\n\
    \    using L = Vector<long long>;\n    auto near = [](double a, double b) { return\
    \ std::abs(a - b) < 1e-7; };\n    for (int rep = 0; rep < 20000 && ok; rep++)\
    \ {\n        auto rnd = [&] { return static_cast<long long>(rng() % 11) - 5; };\n\
    \        L a(rnd(), rnd()), b(rnd(), rnd()), c(rnd(), rnd()), d(rnd(), rnd());\n\
    \        auto to_p = [](const L& l) { return P(static_cast<double>(l[0]), static_cast<double>(l[1]));\
    \ };\n        P pa = to_p(a), pb = to_p(b), pc = to_p(c), pd = to_p(d);\n\n  \
    \      // ccw: \u4E00\u76F4\u7DDA\u4E0A\u306E\u5834\u5408\u306F\u3001c \u304C\u76F4\
    \u7DDA\u4E0A\u306E\u3069\u3053\u306B\u3042\u308B\u304B\u3067\u5206\u3051\u308B\
    \n        if (a != b) {\n            int r = ccw(a, b, c);\n            long long\
    \ cr = cross(b - a, c - a);\n            if (cr > 0) ok = ok && r == 1;\n    \
    \        if (cr < 0) ok = ok && r == -1;\n            if (cr == 0) {\n       \
    \         // a \u3092 0\u3001b \u3092 1 \u3068\u3057\u305F\u3068\u304D\u306E c\
    \ \u306E\u4F4D\u7F6E t\n                long long t = dot(c - a, b - a), len =\
    \ (b - a).squared_norm();\n                ok = ok && r == (t < 0 ? 2 : t > len\
    \ ? -2\n                                                     : 0);\n         \
    \   }\n            ok = ok && ccw(pa, pb, pc) == r;\n        }\n        if (a\
    \ == b || c == d) continue;\n\n        ok = ok && is_parallel(a, b, c, d) == (cross(b\
    \ - a, d - c) == 0);\n        ok = ok && is_orthogonal(a, b, c, d) == (dot(b -\
    \ a, d - c) == 0);\n\n        // \u5C04\u5F71\u306F\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308A\u3001p \u3068\u306E\u5DEE\u304C\u76F4\u7DDA\u306B\u5782\u76F4\u3002\u53CD\
    \u5C04\u306F\u5C04\u5F71\u3092\u4E2D\u70B9\u3068\u3059\u308B\n        P h = projection(pa,\
    \ pb, pc);\n        ok = ok && near(cross(pb - pa, h - pa), 0) && near(dot(pb\
    \ - pa, h - pc), 0);\n        P r = reflection(pa, pb, pc);\n        ok = ok &&\
    \ near(r[0] + pc[0], 2 * h[0]) && near(r[1] + pc[1], 2 * h[1]);\n\n        //\
    \ \u4EA4\u70B9\u306F\u4E21\u65B9\u306E\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\n \
    \       auto x = line_intersection(pa, pb, pc, pd);\n        if (is_parallel(a,\
    \ b, c, d)) {\n            ok = ok && !x;\n        } else {\n            ok =\
    \ ok && x && near(cross(pb - pa, *x - pa), 0) && near(cross(pd - pc, *x - pc),\
    \ 0);\n        }\n\n        // \u70B9\u3068\u76F4\u7DDA\u306E\u8DDD\u96E2\u306F\
    \u3001\u5C04\u5F71\u307E\u3067\u306E\u8DDD\u96E2\n        ok = ok && near(distance_point_line(a,\
    \ b, c), (h - pc).abs());\n        // \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\
    \u3092\u3001\u7DDA\u5206\u4E0A\u306E\u70B9\u3092\u7D30\u304B\u304F\u8ABF\u3079\
    \u305F\u6700\u5C0F\u5024\u3068\u6BD4\u3079\u308B\n        auto brute_point_segment\
    \ = [&](P p1, P p2, P p) {\n            double best = 1e18;\n            for (int\
    \ i = 0; i <= 2000; i++) best = std::min(best, (p1 + (p2 - p1) * (i / 2000.0)\
    \ - p).abs());\n            return best;\n        };\n        double dps = distance_point_segment(a,\
    \ b, c);\n        ok = ok && dps <= brute_point_segment(pa, pb, pc) + 1e-9 &&\
    \ dps >= brute_point_segment(pa, pb, pc) - 1e-2;\n        // \u7DDA\u5206\u3069\
    \u3046\u3057\u306E\u8DDD\u96E2: \u4EA4\u308F\u308B\u306A\u3089 0\u3001\u305D\u3046\
    \u3067\u306A\u3051\u308C\u3070\u7AEF\u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\
    \u306E\u6700\u5C0F\u5024\u4EE5\u4E0B\n        double dss = distance_segments(a,\
    \ b, c, d);\n        if (segments_intersect(a, b, c, d)) {\n            ok = ok\
    \ && dss == 0;\n        } else {\n            ok = ok && dss > 0 && near(dss,\
    \ std::min({distance_point_segment(a, b, c), distance_point_segment(a, b, d),\
    \ distance_point_segment(c, d, a), distance_point_segment(c, d, b)}));\n     \
    \   }\n        ok = ok && near(distance_segments(pa, pb, pc, pd), dss);\n    }\n\
    \n    // \u4F8B\n    ok = ok && ccw(L(0, 0), L(2, 0), L(1, 1)) == 1 && ccw(L(0,\
    \ 0), L(2, 0), L(3, 0)) == -2;\n    P h = projection(P(0.0, 0.0), P(3.0, 4.0),\
    \ P(2.0, 5.0));\n    ok = ok && near(h[0], 3.12) && near(h[1], 4.16);\n    ok\
    \ = ok && near(distance_point_line(L(0, 0), L(2, 0), L(5, 3)), 3) && near(distance_point_segment(L(0,\
    \ 0), L(2, 0), L(5, 4)), 5);\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// geometry/segment.hpp \u306E\u76F4\u7DDA\u30FB\u7DDA\u5206\u306E\u95A2\u6570\
    \ (ccw\u3001\u5E73\u884C\u30FB\u76F4\u4EA4\u3001\u5C04\u5F71\u3001\u53CD\u5C04\
    \u3001\u4EA4\u70B9\u3001\u8DDD\u96E2) \u3092\u3001\u5B9A\u7FA9\u304B\u3089\u78BA\
    \u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u6210\u308A\u7ACB\u3063\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../../src/geometry/segment.hpp\"\n\n#include\
    \ <algorithm>\n#include <cmath>\n#include <iostream>\n#include <random>\n\n#include\
    \ \"../../../src/geometry/vector.hpp\"\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = true;\n    using P = Vector<double>;\n    using L = Vector<long\
    \ long>;\n    auto near = [](double a, double b) { return std::abs(a - b) < 1e-7;\
    \ };\n    for (int rep = 0; rep < 20000 && ok; rep++) {\n        auto rnd = [&]\
    \ { return static_cast<long long>(rng() % 11) - 5; };\n        L a(rnd(), rnd()),\
    \ b(rnd(), rnd()), c(rnd(), rnd()), d(rnd(), rnd());\n        auto to_p = [](const\
    \ L& l) { return P(static_cast<double>(l[0]), static_cast<double>(l[1])); };\n\
    \        P pa = to_p(a), pb = to_p(b), pc = to_p(c), pd = to_p(d);\n\n       \
    \ // ccw: \u4E00\u76F4\u7DDA\u4E0A\u306E\u5834\u5408\u306F\u3001c \u304C\u76F4\
    \u7DDA\u4E0A\u306E\u3069\u3053\u306B\u3042\u308B\u304B\u3067\u5206\u3051\u308B\
    \n        if (a != b) {\n            int r = ccw(a, b, c);\n            long long\
    \ cr = cross(b - a, c - a);\n            if (cr > 0) ok = ok && r == 1;\n    \
    \        if (cr < 0) ok = ok && r == -1;\n            if (cr == 0) {\n       \
    \         // a \u3092 0\u3001b \u3092 1 \u3068\u3057\u305F\u3068\u304D\u306E c\
    \ \u306E\u4F4D\u7F6E t\n                long long t = dot(c - a, b - a), len =\
    \ (b - a).squared_norm();\n                ok = ok && r == (t < 0 ? 2 : t > len\
    \ ? -2\n                                                     : 0);\n         \
    \   }\n            ok = ok && ccw(pa, pb, pc) == r;\n        }\n        if (a\
    \ == b || c == d) continue;\n\n        ok = ok && is_parallel(a, b, c, d) == (cross(b\
    \ - a, d - c) == 0);\n        ok = ok && is_orthogonal(a, b, c, d) == (dot(b -\
    \ a, d - c) == 0);\n\n        // \u5C04\u5F71\u306F\u76F4\u7DDA\u4E0A\u306B\u3042\
    \u308A\u3001p \u3068\u306E\u5DEE\u304C\u76F4\u7DDA\u306B\u5782\u76F4\u3002\u53CD\
    \u5C04\u306F\u5C04\u5F71\u3092\u4E2D\u70B9\u3068\u3059\u308B\n        P h = projection(pa,\
    \ pb, pc);\n        ok = ok && near(cross(pb - pa, h - pa), 0) && near(dot(pb\
    \ - pa, h - pc), 0);\n        P r = reflection(pa, pb, pc);\n        ok = ok &&\
    \ near(r[0] + pc[0], 2 * h[0]) && near(r[1] + pc[1], 2 * h[1]);\n\n        //\
    \ \u4EA4\u70B9\u306F\u4E21\u65B9\u306E\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\n \
    \       auto x = line_intersection(pa, pb, pc, pd);\n        if (is_parallel(a,\
    \ b, c, d)) {\n            ok = ok && !x;\n        } else {\n            ok =\
    \ ok && x && near(cross(pb - pa, *x - pa), 0) && near(cross(pd - pc, *x - pc),\
    \ 0);\n        }\n\n        // \u70B9\u3068\u76F4\u7DDA\u306E\u8DDD\u96E2\u306F\
    \u3001\u5C04\u5F71\u307E\u3067\u306E\u8DDD\u96E2\n        ok = ok && near(distance_point_line(a,\
    \ b, c), (h - pc).abs());\n        // \u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\
    \u3092\u3001\u7DDA\u5206\u4E0A\u306E\u70B9\u3092\u7D30\u304B\u304F\u8ABF\u3079\
    \u305F\u6700\u5C0F\u5024\u3068\u6BD4\u3079\u308B\n        auto brute_point_segment\
    \ = [&](P p1, P p2, P p) {\n            double best = 1e18;\n            for (int\
    \ i = 0; i <= 2000; i++) best = std::min(best, (p1 + (p2 - p1) * (i / 2000.0)\
    \ - p).abs());\n            return best;\n        };\n        double dps = distance_point_segment(a,\
    \ b, c);\n        ok = ok && dps <= brute_point_segment(pa, pb, pc) + 1e-9 &&\
    \ dps >= brute_point_segment(pa, pb, pc) - 1e-2;\n        // \u7DDA\u5206\u3069\
    \u3046\u3057\u306E\u8DDD\u96E2: \u4EA4\u308F\u308B\u306A\u3089 0\u3001\u305D\u3046\
    \u3067\u306A\u3051\u308C\u3070\u7AEF\u70B9\u3068\u7DDA\u5206\u306E\u8DDD\u96E2\
    \u306E\u6700\u5C0F\u5024\u4EE5\u4E0B\n        double dss = distance_segments(a,\
    \ b, c, d);\n        if (segments_intersect(a, b, c, d)) {\n            ok = ok\
    \ && dss == 0;\n        } else {\n            ok = ok && dss > 0 && near(dss,\
    \ std::min({distance_point_segment(a, b, c), distance_point_segment(a, b, d),\
    \ distance_point_segment(c, d, a), distance_point_segment(c, d, b)}));\n     \
    \   }\n        ok = ok && near(distance_segments(pa, pb, pc, pd), dss);\n    }\n\
    \n    // \u4F8B\n    ok = ok && ccw(L(0, 0), L(2, 0), L(1, 1)) == 1 && ccw(L(0,\
    \ 0), L(2, 0), L(3, 0)) == -2;\n    P h = projection(P(0.0, 0.0), P(3.0, 4.0),\
    \ P(2.0, 5.0));\n    ok = ok && near(h[0], 3.12) && near(h[1], 4.16);\n    ok\
    \ = ok && near(distance_point_line(L(0, 0), L(2, 0), L(5, 3)), 3) && near(distance_point_segment(L(0,\
    \ 0), L(2, 0), L(5, 4)), 5);\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/geometry/segment.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/geometry/segment.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 17:14:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/geometry/segment.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/geometry/segment.test.cpp
- /verify/test/unittest/geometry/segment.test.cpp.html
title: test/unittest/geometry/segment.test.cpp
---
