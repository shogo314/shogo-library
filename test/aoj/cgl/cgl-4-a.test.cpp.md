---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon.hpp
    title: "\u591A\u89D2\u5F62 (\u9762\u7A4D\u3001\u91CD\u5FC3\u3001\u5185\u5916\u5224\
      \u5B9A\u3001\u51F8\u6027\u3001\u51F8\u5305\u3001\u51F8\u591A\u89D2\u5F62\u306E\
      \u5207\u65AD)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"test/aoj/cgl/cgl-4-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include <iostream>\n\n#line 2 \"src/geometry/polygon.hpp\"\n\n/**\n * @file\
    \ polygon.hpp\n * @brief \u591A\u89D2\u5F62 (\u9762\u7A4D\u3001\u91CD\u5FC3\u3001\
    \u5185\u5916\u5224\u5B9A\u3001\u51F8\u6027\u3001\u51F8\u5305\u3001\u51F8\u591A\
    \u89D2\u5F62\u306E\u5207\u65AD)\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\
    \u4F55\u30D9\u30AF\u30C8\u30EB\n */\n\n#include <array>\n#line 11 \"src/geometry/vector.hpp\"\
    \n#include <istream>\n#include <ostream>\n#line 15 \"src/geometry/vector.hpp\"\
    \n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief\
    \ \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <functional>\n#include\
    \ <iterator>\n#include <set>\n#line 14 \"src/utility/traits.hpp\"\n\nnamespace\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n#line 16 \"src/geometry/polygon.hpp\"\
    \n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\
    \u306E2\u500D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\
    \u70B9\u306E\u5EA7\u6A19\n * @return T \u9762\u7A4D\u306E2\u500D(\u53CD\u6642\u8A08\
    \u56DE\u308A\u306A\u3089\u6B63\u3001\u6642\u8A08\u56DE\u308A\u306A\u3089\u8CA0\
    )\n */\ntemplate <typename T>\nT polygon_area_doubled(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    T ret = 0;\n    for (int i = 0; i < static_cast<int>(polygon.size());\
    \ i++) {\n        int j = i + 1;\n        if (j == static_cast<int>(polygon.size()))\
    \ j = 0;\n        ret += cross(polygon[i], polygon[j]);\n    }\n    return ret;\n\
    }\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u9762\u7A4D\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u9806\u756A\
    \u3001\u53CD\u6642\u8A08\u56DE\u308A\u304B\u6642\u8A08\u56DE\u308A\u304B\u306F\
    \u554F\u308F\u306A\u3044)\n * @return double \u9762\u7A4D\n */\ntemplate <typename\
    \ T>\ndouble polygon_area(const std::vector<Vector<T, 2>>& polygon) {\n    return\
    \ std::abs(polygon_area_doubled(polygon)) / 2.;\n}\n\n/**\n * @brief \u591A\u89D2\
    \u5F62\u306E\u9762\u7A4D\u3068\u4E00\u6B21\u30E2\u30FC\u30E1\u30F3\u30C8 (polygon_edge_moment\
    \ \u306E\u623B\u308A\u5024)\n * \u8FBA\u3054\u3068\u306E\u5024\u3092\u8DB3\u3059\
    \u3068\u3001\u591A\u89D2\u5F62\u5168\u4F53\u306E\u5024\u306B\u306A\u308B\u3002\
    + \u3068 - \u304C\u3042\u308B\u306E\u3067\u3001CircularSum \u306A\u3069\u306E\u7D2F\
    \u7A4D\u548C\u306B\u8F09\u305B\u3089\u308C\u308B\n *\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\u3002\u6574\u6570\u578B\u306A\u3089\u5024\u306F __int128_t \u3067\
    \u6301\u3064 (\u5EA7\u6A19\u304C 1e9 \u306A\u3089 mx \u306F 1e27 \u7A0B\u5EA6\u306B\
    \u306A\u308B)\n */\ntemplate <typename T>\nstruct PolygonMoment {\n    using W\
    \ = std::conditional_t<std::is_integral_v<T>, __int128_t, T>;\n    W area2 = 0;\
    \       //!< \u7B26\u53F7\u4ED8\u304D\u9762\u7A4D S \u306E 2 \u500D (\u53CD\u6642\
    \u8A08\u56DE\u308A\u306A\u3089\u6B63)\n    W mx = 0, my = 0;  //!< \u4E00\u6B21\
    \u30E2\u30FC\u30E1\u30F3\u30C8\u306E 6 \u500D (6S gx, 6S gy\u3002(gx, gy) \u306F\
    \u91CD\u5FC3)\n\n    PolygonMoment& operator+=(const PolygonMoment& rhs) {\n \
    \       area2 += rhs.area2, mx += rhs.mx, my += rhs.my;\n        return *this;\n\
    \    }\n    PolygonMoment& operator-=(const PolygonMoment& rhs) {\n        area2\
    \ -= rhs.area2, mx -= rhs.mx, my -= rhs.my;\n        return *this;\n    }\n  \
    \  friend PolygonMoment operator+(PolygonMoment lhs, const PolygonMoment& rhs)\
    \ { return lhs += rhs; }\n    friend PolygonMoment operator-(PolygonMoment lhs,\
    \ const PolygonMoment& rhs) { return lhs -= rhs; }\n    friend bool operator==(const\
    \ PolygonMoment& lhs, const PolygonMoment& rhs) {\n        return lhs.area2 ==\
    \ rhs.area2 && lhs.mx == rhs.mx && lhs.my == rhs.my;\n    }\n    friend bool operator!=(const\
    \ PolygonMoment& lhs, const PolygonMoment& rhs) { return !(lhs == rhs); }\n\n\
    \    /**\n     * @brief \u7B26\u53F7\u4ED8\u304D\u9762\u7A4D (\u53CD\u6642\u8A08\
    \u56DE\u308A\u306A\u3089\u6B63)\n     */\n    double area() const { return static_cast<double>(area2)\
    \ / 2; }\n    /**\n     * @brief \u91CD\u5FC3 (\u9762\u7A4D\u304C 0 \u306A\u3089\
    \ assert \u3067\u843D\u3061\u308B)\n     */\n    Vector<double, 2> centroid()\
    \ const {\n        assert(area2 != 0 && \"PolygonMoment::centroid: area must be\
    \ nonzero\");\n        const double a = static_cast<double>(area2) * 3;\n    \
    \    return Vector<double, 2>(static_cast<double>(mx) / a, static_cast<double>(my)\
    \ / a);\n    }\n};\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u8FBA p\u2192q \u306E\
    \u5BC4\u4E0E (\u539F\u70B9\u3068 p, q \u3067\u3067\u304D\u308B\u4E09\u89D2\u5F62\
    \u306E\u9762\u7A4D\u3068\u4E00\u6B21\u30E2\u30FC\u30E1\u30F3\u30C8)\n * \u5168\
    \u8FBA\u306E\u5BC4\u4E0E\u306E\u548C\u304C\u591A\u89D2\u5F62\u306E\u5024\u306B\
    \u306A\u308B\u3002\u90E8\u5206\u591A\u89D2\u5F62\u306E\u30AF\u30A8\u30EA\u306F\
    \u3001\u5BC4\u4E0E\u306E\u7D2F\u7A4D\u548C (CircularSum \u306A\u3069) \u3067\u6C42\
    \u3081\u3089\u308C\u308B\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n */\ntemplate\
    \ <typename T>\nPolygonMoment<T> polygon_edge_moment(const Vector<T, 2>& p, const\
    \ Vector<T, 2>& q) {\n    using W = typename PolygonMoment<T>::W;\n    const W\
    \ c = static_cast<W>(p[0]) * q[1] - static_cast<W>(p[1]) * q[0];\n    return {c,\
    \ (static_cast<W>(p[0]) + q[0]) * c, (static_cast<W>(p[1]) + q[1]) * c};\n}\n\n\
    /**\n * @brief \u591A\u89D2\u5F62 (\u306E\u9818\u57DF) \u306E\u91CD\u5FC3\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\
    \u6A19(\u9806\u756A\u3001\u53CD\u6642\u8A08\u56DE\u308A\u304B\u6642\u8A08\u56DE\
    \u308A\u304B\u306F\u554F\u308F\u306A\u3044\u3002\u9762\u7A4D\u304C 0 \u306A\u3089\
    \ assert \u3067\u843D\u3061\u308B)\n * @return Vector<double, 2> \u91CD\u5FC3\n\
    \ */\ntemplate <typename T>\nVector<double, 2> polygon_centroid(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    const int n = static_cast<int>(polygon.size());\n    PolygonMoment<T>\
    \ m;\n    for (int i = 0; i < n; i++) m += polygon_edge_moment(polygon[i], polygon[i\
    \ + 1 == n ? 0 : i + 1]);\n    return m.centroid();\n}\n\n/**\n * @brief \u591A\
    \u89D2\u5F62\u306E\u51F8\u6027\u5224\u5B9A\n *\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\
    \u308A)\n * @return true \u51F8\n * @return false \u51F9\n */\ntemplate <typename\
    \ T>\nbool polygon_is_convex(const std::vector<Vector<T, 2>>& polygon) {\n   \
    \ int n = polygon.size();\n    for (int i = 0; i < n; i++) {\n        int j =\
    \ i + 1;\n        if (j == n) j = 0;\n        int k = j + 1;\n        if (k ==\
    \ n) k = 0;\n        if (cross(polygon[j] - polygon[i], polygon[k] - polygon[j])\
    \ < 0) return false;\n    }\n    return true;\n}\n\n/**\n * @brief \u70B9\u306E\
    \u591A\u89D2\u5F62\u5185\u5305\u542B\u5224\u5B9A\n *\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\
    \u56DE\u308A)\n * @param p \u70B9\u306E\u5EA7\u6A19\n * @return int 0: \u5916\u90E8\
    , 1: \u8FBA\u4E0A, 2: \u5185\u90E8\n */\ntemplate <typename T>\nint polygon_contains(const\
    \ std::vector<Vector<T, 2>>& polygon, const Vector<T, 2>& p) {\n    bool in =\
    \ false;\n    for (int i = 0; i < static_cast<int>(polygon.size()); i++) {\n \
    \       int j = i + 1;\n        if (j == static_cast<int>(polygon.size())) j =\
    \ 0;\n        Vector<T> v1 = polygon[i] - p, v2 = polygon[j] - p;\n        if\
    \ (v1[1] > v2[1]) std::swap(v1, v2);\n        T c = cross(v1, v2);\n        if\
    \ (v1[1] <= 0 && v2[1] > 0 && c < 0) in = !in;\n        if (c == 0 && dot(v1,\
    \ v2) <= 0) return 1;\n    }\n    return in ? 2 : 0;\n}\n\n/**\n * @brief \u591A\
    \u89D2\u5F62\u306E\u534A\u51F8\u5305\n * \u4E0E\u3048\u3089\u308C\u305F\u9802\u70B9\
    \u30EA\u30B9\u30C8\u306E\u9806\u756A\u3092\u4FDD\u3063\u3066\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u51F8\u5305\u3092\u69CB\u6210\u3059\u308B\n * x\u306E\u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308C\u3070\u4E0B\u51F8\
    \u5305\u3001x\u306E\u964D\u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\
    \u308C\u3070\u4E0A\u51F8\u5305\u304C\u5F97\u3089\u308C\u308B\n *\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n\
    \ * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\u70B9\u3092\
    \u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T, 2>> \u534A\
    \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> select_convex(const std::vector<Vector<T,\
    \ 2>>& points, bool include_straight = false) {\n    std::vector<Vector<T, 2>>\
    \ ret;\n    for (auto& p : points) {\n        while (static_cast<int>(ret.size())\
    \ >= 2) {\n            T c = cross(ret.back() - ret[static_cast<int>(ret.size())\
    \ - 2], p - ret.back());\n            if (c > 0 || (c == 0 && include_straight))\
    \ break;\n            ret.pop_back();\n        }\n        ret.push_back(p);\n\
    \    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u5305\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\
    \u30B9\u30C8\n * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\
    \u70B9\u3092\u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T,\
    \ 2>> \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\
    \u308A)\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_hull(const\
    \ std::vector<Vector<T, 2>>& _points, bool include_straight = false) {\n    std::vector<Vector<T,\
    \ 2>> points = _points;\n    std::sort(points.begin(), points.end());\n    points.erase(std::unique(points.begin(),\
    \ points.end()), points.end());\n    std::vector<Vector<T, 2>> ret = select_convex(points,\
    \ include_straight);\n    std::reverse(points.begin(), points.end());\n    std::vector<Vector<T,\
    \ 2>> tmp = select_convex(points, include_straight);\n    // \u5168\u70B9\u304C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\u4E0B\u5074\u3068\
    \u4E0A\u5074\u304C\u540C\u3058\u70B9\u5217\u306B\u306A\u308B\u306E\u3067\u7247\
    \u65B9\u3060\u3051\u4F7F\u3046\n    if (ret.size() == points.size() && tmp.size()\
    \ == points.size()) return ret;\n    for (int i = 1; i < static_cast<int>(tmp.size())\
    \ - 1; i++) ret.push_back(tmp[i]);\n    return ret;\n}\n\n/**\n * @brief \u51F8\
    \u591A\u89D2\u5F62\u3092\u76F4\u7DDA p1p2 \u3067\u5207\u308A\u3001\u76F4\u7DDA\
    \u306E\u5DE6\u5074 (p1 \u304B\u3089 p2 \u3092\u898B\u3066\u5DE6) \u306E\u90E8\u5206\
    \u3092\u8FD4\u3059\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u51F8\u591A\u89D2\u5F62\
    \u306E\u9802\u70B9\u306E\u5EA7\u6A19 (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return\
    \ std::vector<Vector<T, 2>> \u5DE6\u5074\u306E\u51F8\u591A\u89D2\u5F62\u306E\u9802\
    \u70B9 (\u53CD\u6642\u8A08\u56DE\u308A)\u3002\u76F4\u7DDA\u4E0A\u306E\u9802\u70B9\
    \u3082\u542B\u3080\u3002\u5DE6\u5074\u306B\u4F55\u3082\u306A\u3051\u308C\u3070\
    \u7A7A\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_cut(const\
    \ std::vector<Vector<T, 2>>& polygon, const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2) {\n    static_assert(std::is_floating_point_v<T>, \"convex_cut: T must\
    \ be a floating point type\");\n    std::vector<Vector<T, 2>> res;\n    const\
    \ int n = static_cast<int>(polygon.size());\n    for (int i = 0; i < n; i++) {\n\
    \        const Vector<T, 2>&a = polygon[i], &b = polygon[i + 1 == n ? 0 : i +\
    \ 1];\n        T ca = cross(p2 - p1, a - p1), cb = cross(p2 - p1, b - p1);\n \
    \       if (ca >= 0) res.push_back(a);\n        // \u8FBA ab \u304C\u76F4\u7DDA\
    \u3092\u307E\u305F\u3050\u306A\u3089\u3001\u4EA4\u70B9\u3092\u5165\u308C\u308B\
    \n        if ((ca > 0 && cb < 0) || (ca < 0 && cb > 0)) res.push_back(a + (b -\
    \ a) * (ca / (ca - cb)));\n    }\n    return res;\n}\n#line 7 \"test/aoj/cgl/cgl-4-a.test.cpp\"\
    \n\nint main(void) {\n    int n;\n    std::cin >> n;\n    std::vector<Vector<int>>\
    \ points(n);\n    for (int i = 0; i < n; ++i) std::cin >> points[i];\n    std::vector<Vector<int>>\
    \ polygon = convex_hull(points, true);\n    int j = 0;\n    for (int i = 0; i\
    \ < static_cast<int>(polygon.size()); i++) {\n        if (polygon[i][1] < polygon[j][1])\
    \ j = i;\n        if (polygon[i][1] == polygon[j][1] && polygon[i][0] < polygon[j][0])\
    \ j = i;\n    }\n    std::rotate(polygon.begin(), polygon.begin() + j, polygon.end());\n\
    \    std::cout << polygon.size() << '\\n';\n    for (auto& p : polygon) std::cout\
    \ << p << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n#include <iostream>\n\n#include \"../../../src/geometry/polygon.hpp\"\n#include\
    \ \"../../../src/geometry/vector.hpp\"\n\nint main(void) {\n    int n;\n    std::cin\
    \ >> n;\n    std::vector<Vector<int>> points(n);\n    for (int i = 0; i < n; ++i)\
    \ std::cin >> points[i];\n    std::vector<Vector<int>> polygon = convex_hull(points,\
    \ true);\n    int j = 0;\n    for (int i = 0; i < static_cast<int>(polygon.size());\
    \ i++) {\n        if (polygon[i][1] < polygon[j][1]) j = i;\n        if (polygon[i][1]\
    \ == polygon[j][1] && polygon[i][0] < polygon[j][0]) j = i;\n    }\n    std::rotate(polygon.begin(),\
    \ polygon.begin() + j, polygon.end());\n    std::cout << polygon.size() << '\\\
    n';\n    for (auto& p : polygon) std::cout << p << '\\n';\n}"
  dependsOn:
  - src/geometry/polygon.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/aoj/cgl/cgl-4-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 17:14:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/cgl/cgl-4-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/cgl/cgl-4-a.test.cpp
- /verify/test/aoj/cgl/cgl-4-a.test.cpp.html
title: test/aoj/cgl/cgl-4-a.test.cpp
---
