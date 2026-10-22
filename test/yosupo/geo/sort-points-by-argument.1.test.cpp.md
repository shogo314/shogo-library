---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/angle.hpp
    title: "\u504F\u89D2"
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
    PROBLEM: https://judge.yosupo.jp/problem/sort_points_by_argument
    links:
    - https://judge.yosupo.jp/problem/sort_points_by_argument
  bundledCode: "#line 1 \"test/yosupo/geo/sort-points-by-argument.1.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/geometry/angle.hpp\"\
    \n\n/**\n * @file angle.hpp\n * @brief \u504F\u89D2\n */\n\n#include <cmath>\n\
    #include <type_traits>\n#include <utility>\n\n/**\n * @brief 2 \u6B21\u5143\u30D9\
    \u30AF\u30C8\u30EB (x, y) \u306E\u504F\u89D2\n *\n * x \u8EF8\u6B63\u65B9\u5411\
    \u3092 0 \u3068\u3057\u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B [0, 2\u03C0) \u3067\
    \u6BD4\u3079\u308B\u3002\u96F6\u30D9\u30AF\u30C8\u30EB\u306F x \u8EF8\u6B63\u65B9\
    \u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\u3066\u6271\u3046\n * \u5916\u7A4D\
    \u3067\u6BD4\u3079\u308B\u306E\u3067\u3001\u6574\u6570\u578B\u306A\u3089\u8AA4\
    \u5DEE\u306A\u304F\u6BD4\u3079\u3089\u308C\u308B (\u5EA7\u6A19\u306E\u7D76\u5BFE\
    \u5024\u306E 2 \u4E57\u304C T \u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\
    \u308B)\n *\n * std::sort(ps.begin(), ps.end(), [](const auto& a, const auto&\
    \ b) { return Angle(a) < Angle(b); });\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n */\ntemplate <typename T>\nstruct Angle {\n    T x;  //!< x \u5EA7\u6A19\n\
    \    T y;  //!< y \u5EA7\u6A19\n\n    /**\n     * @brief \u504F\u89D2 0 (\u96F6\
    \u30D9\u30AF\u30C8\u30EB)\n     */\n    constexpr Angle() noexcept : x(), y()\
    \ {}\n    /**\n     * @brief \u30D9\u30AF\u30C8\u30EB (x, y) \u306E\u504F\u89D2\
    \n     */\n    constexpr Angle(T x, T y) noexcept : x(x), y(y) {}\n    /**\n \
    \    * @brief p[0], p[1] \u3092 x, y \u3068\u3059\u308B (Vector<T, 2> \u3084 std::array<T,\
    \ 2> \u304B\u3089\u4F5C\u308B)\n     */\n    template <typename P, typename =\
    \ decltype(std::declval<const P&>()[0])>\n    constexpr explicit Angle(const P&\
    \ p) noexcept : x(p[0]), y(p[1]) {}\n    /**\n     * @brief p.first, p.second\
    \ \u3092 x, y \u3068\u3059\u308B\n     */\n    constexpr explicit Angle(const\
    \ std::pair<T, T>& p) noexcept : x(p.first), y(p.second) {}\n\n    /**\n     *\
    \ @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\n     */\n    constexpr bool is_zero()\
    \ const noexcept { return x == 0 && y == 0; }\n    /**\n     * @brief \u504F\u89D2\
    \u304C [0, \u03C0) \u306A\u3089 0\u3001[\u03C0, 2\u03C0) \u306A\u3089 1\n    \
    \ */\n    constexpr int half() const noexcept { return y < 0 || (y == 0 && x <\
    \ 0); }\n    /**\n     * @brief \u504F\u89D2 (\u30E9\u30B8\u30A2\u30F3\u3001[0,\
    \ 2\u03C0))\n     */\n    double radian() const {\n        double t = std::atan2(static_cast<double>(y),\
    \ static_cast<double>(x));\n        return t < 0 ? t + 2 * std::acos(-1.0) : t;\n\
    \    }\n\n    friend constexpr bool operator<(const Angle& a, const Angle& b)\
    \ noexcept {\n        // \u96F6\u30D9\u30AF\u30C8\u30EB\u306F\u5916\u7A4D\u3067\
    \u6BD4\u3079\u3089\u308C\u306A\u3044\u306E\u3067\u3001\u504F\u89D2 0 (x \u8EF8\
    \u6B63\u65B9\u5411) \u3068\u3057\u3066\u5148\u306B\u5224\u5B9A\u3059\u308B\n \
    \       if (b.is_zero()) return false;                   // \u504F\u89D2 0 \u3088\
    \u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\n        if (a.is_zero())\
    \ return !(b.y == 0 && b.x > 0);  // b \u306E\u504F\u89D2\u304C 0 \u3088\u308A\
    \u5927\u304D\u3044\u304B\n        if (a.half() != b.half()) return a.half() <\
    \ b.half();\n        return b.x * a.y < a.x * b.y;\n    }\n    friend constexpr\
    \ bool operator>(const Angle& a, const Angle& b) noexcept { return b < a; }\n\
    \    friend constexpr bool operator<=(const Angle& a, const Angle& b) noexcept\
    \ { return !(b < a); }\n    friend constexpr bool operator>=(const Angle& a, const\
    \ Angle& b) noexcept { return !(a < b); }\n    /**\n     * @brief \u504F\u89D2\
    \u304C\u7B49\u3057\u3044\u304B (\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u7B49\
    \u3057\u3044\u304B\u3067\u306F\u306A\u3044)\n     */\n    friend constexpr bool\
    \ operator==(const Angle& a, const Angle& b) noexcept { return !(a < b) && !(b\
    \ < a); }\n    friend constexpr bool operator!=(const Angle& a, const Angle& b)\
    \ noexcept { return !(a == b); }\n};\n\ntemplate <typename P, typename = decltype(std::declval<const\
    \ P&>()[0])>\nAngle(const P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n\
    #line 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\
    \u4F55\u30D9\u30AF\u30C8\u30EB\n */\n\n#line 9 \"src/geometry/vector.hpp\"\n#include\
    \ <array>\n#include <cassert>\n#line 12 \"src/geometry/vector.hpp\"\n#include\
    \ <istream>\n#include <limits>\n#include <numeric>\n#include <optional>\n#include\
    \ <ostream>\n#include <stack>\n#line 21 \"src/geometry/vector.hpp\"\n\n#line 2\
    \ \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\
    \u6027\n */\n\n#include <cstddef>\n#include <iterator>\n#include <set>\n#line\
    \ 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits {\nusing std::begin,\
    \ std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    #line 23 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\
    \u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\
    \u5916\u7A4D\u3092\u8A08\u7B97\u3059\u308B\u305F\u3081\u3001\u5EA7\u6A19\u306E\
    \u7D76\u5BFE\u5024\u306E2\u4E57\u306E\u6570\u500D\u304CT\u306B\u53CE\u307E\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B91\n * @param p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B9\
    2\n * @param q1 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ q2 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\n * @return bool \u5171\u6709\u70B9\u3092\u6301\u3064\u304B\n */\n\
    template <typename T>\nconstexpr bool segments_intersect(const Vector<T, 2>& p1,\
    \ const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n\
    \    assert(p1 != p2 && q1 != q2 && \"segments_intersect: degenerate segment\"\
    );\n    auto sign = [](T x) { return (x > 0) - (x < 0); };\n    int q1_section\
    \ = sign(cross(p2 - p1, q1 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int q2_section =\
    \ sign(cross(p2 - p1, q2 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p1_section =\
    \ sign(cross(q2 - q1, p1 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p2_section =\
    \ sign(cross(q2 - q1, p2 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    if (q1_section ==\
    \ 0 && q2_section == 0) {\n        // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \u306B\u3042\u308B\u5834\u5408\n        return dot(q1 - p1, q2 - p1) <= 0 || dot(q1\
    \ - p2, q2 - p2) <= 0 || dot(p1 - q1, p2 - q1) <= 0;\n    }\n    return q1_section\
    \ * q2_section <= 0 && p1_section * p2_section <= 0;\n}\n\n/**\n * @brief \u7DDA\
    \u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u3068\u5171\u6709\u70B9\u306E\u8A08\u7B97\
    \n *\n * \u5171\u6709\u70B9\u306E\u5EA7\u6A19\u306F\u4E00\u822C\u306B\u6574\u6570\
    \u306B\u306A\u3089\u306A\u3044\u305F\u3081\u3001\u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u578B\u9650\u5B9A\n * \u6574\u6570\u5EA7\u6A19\u3067\u4EA4\u5DEE\u5224\u5B9A\u3060\
    \u3051\u3057\u305F\u3044\u5834\u5408\u306F segments_intersect \u3092\u4F7F\u3046\
    \n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param q1 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return std::optional<Vector<T,\
    \ 2>> \u5171\u6709\u70B9\u306E1\u4F8B (\u5171\u6709\u70B9\u304C\u306A\u3051\u308C\
    \u3070 std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> segment_intersection(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const\
    \ Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"segment_intersection: T must be a floating point type (use segments_intersect\
    \ for integers)\");\n    if (!segments_intersect(p1, p2, q1, q2)) return std::nullopt;\n\
    \    if (cross(p2 - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n   \
    \     // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \n        if (dot(q1 - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2,\
    \ q2 - p2) <= 0) return p2;\n        return q1;\n    }\n    T area = cross(p2\
    \ - p1, q2 - q1);          // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\
    \u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2\
    \ - q1, p1 - q1);  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D\n    return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief\
    \ 3\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\
    \u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\
    \u3067\u306F\u8AA4\u5DEE\u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192\
    c \u304C\u53CD\u6642\u8A08\u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a,\
    \ b \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A, 0: c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename\
    \ T>\nconstexpr int ccw(const Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T,\
    \ 2>& c) {\n    Vector<T, 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n\
    \    if (cr > 0) return 1;\n    if (cr < 0) return -1;\n    if (dot(u, v) < 0)\
    \ return 2;\n    if (u.squared_norm() < v.squared_norm()) return -2;\n    return\
    \ 0;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\
    \u884C\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate\
    \ <typename T>\nconstexpr bool is_parallel(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    return cross(p2\
    \ - p1, q2 - q1) == 0;\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA\
    \ q1q2 \u304C\u76F4\u4EA4\u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B)\n */\ntemplate <typename T>\nconstexpr bool is_orthogonal(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9\
    \ p \u304B\u3089\u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
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
    \u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n * @return std::optional<Vector<T,\
    \ 2>> \u4EA4\u70B9 (\u5E73\u884C\u306A\u3089 std::nullopt)\n */\ntemplate <typename\
    \ T>\nconstexpr std::optional<Vector<T, 2>> line_intersection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    static_assert(std::is_floating_point_v<T>, \"line_intersection: T\
    \ must be a floating point type\");\n    Vector<T, 2> d = p2 - p1, e = q2 - q1;\n\
    \    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n    // p1 + d t\
    \ \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return p1 + d * (cross(e,\
    \ q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\u7DDA p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_line(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& p) {\n    assert(p1 != p2 && \"distance_point_line: degenerate\
    \ line\");\n    return std::abs(static_cast<double>(cross(p2 - p1, p - p1))) /\
    \ (p2 - p1).abs();\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206 p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_segment(const Vector<T, 2>& p1, const Vector<T, 2>&\
    \ p2, const Vector<T, 2>& p) {\n    if (p1 == p2) return (p - p1).abs();\n   \
    \ // \u5782\u7DDA\u306E\u8DB3\u304C\u7DDA\u5206\u306E\u5916\u306A\u3089\u3001\u8FD1\
    \u3044\u65B9\u306E\u7AEF\u70B9\u3068\u306E\u8DDD\u96E2\n    if (dot(p2 - p1, p\
    \ - p1) < 0) return (p - p1).abs();\n    if (dot(p1 - p2, p - p2) < 0) return\
    \ (p - p2).abs();\n    return distance_point_line(p1, p2, p);\n}\n/**\n * @brief\
    \ \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\
    \u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename T>\ndouble distance_segments(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    if (p1 != p2 && q1 != q2 && segments_intersect(p1, p2, q1, q2))\
    \ return 0;\n    return std::min({distance_point_segment(p1, p2, q1), distance_point_segment(p1,\
    \ p2, q2),\n                     distance_point_segment(q1, q2, p1), distance_point_segment(q1,\
    \ q2, p2)});\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\
    \u9762\u7A4D\u306E2\u500D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param\
    \ polygon \u9802\u70B9\u306E\u5EA7\u6A19\n * @return T \u9762\u7A4D\u306E2\u500D\
    (\u53CD\u6642\u8A08\u56DE\u308A\u306A\u3089\u6B63\u3001\u6642\u8A08\u56DE\u308A\
    \u306A\u3089\u8CA0)\n */\ntemplate <typename T>\nT polygon_area_doubled(const\
    \ std::vector<Vector<T, 2>>& polygon) {\n    T ret = 0;\n    for (int i = 0; i\
    \ < static_cast<int>(polygon.size()); i++) {\n        int j = i + 1;\n       \
    \ if (j == static_cast<int>(polygon.size())) j = 0;\n        ret += cross(polygon[i],\
    \ polygon[j]);\n    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon\
    \ \u9802\u70B9\u306E\u5EA7\u6A19(\u9806\u756A\u3001\u53CD\u6642\u8A08\u56DE\u308A\
    \u304B\u6642\u8A08\u56DE\u308A\u304B\u306F\u554F\u308F\u306A\u3044)\n * @return\
    \ double \u9762\u7A4D\n */\ntemplate <typename T>\ndouble polygon_area(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    return std::abs(polygon_area_doubled(polygon)) / 2.;\n\
    }\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u6027\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return true \u51F8\n * @return false \u51F9\
    \n */\ntemplate <typename T>\nbool polygon_is_convex(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    int n = polygon.size();\n    for (int i = 0; i < n; i++)\
    \ {\n        int j = i + 1;\n        if (j == n) j = 0;\n        int k = j + 1;\n\
    \        if (k == n) k = 0;\n        if (cross(polygon[j] - polygon[i], polygon[k]\
    \ - polygon[j]) < 0) return false;\n    }\n    return true;\n}\n\n/**\n * @brief\
    \ \u70B9\u306E\u591A\u89D2\u5F62\u5185\u5305\u542B\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @param p \u70B9\u306E\u5EA7\u6A19\n * @return\
    \ int 0: \u5916\u90E8, 1: \u8FBA\u4E0A, 2: \u5185\u90E8\n */\ntemplate <typename\
    \ T>\nint polygon_contains(const std::vector<Vector<T, 2>>& polygon, const Vector<T,\
    \ 2>& p) {\n    bool in = false;\n    for (int i = 0; i < static_cast<int>(polygon.size());\
    \ i++) {\n        int j = i + 1;\n        if (j == static_cast<int>(polygon.size()))\
    \ j = 0;\n        Vector<T> v1 = polygon[i] - p, v2 = polygon[j] - p;\n      \
    \  if (v1[1] > v2[1]) std::swap(v1, v2);\n        T c = cross(v1, v2);\n     \
    \   if (v1[1] <= 0 && v2[1] > 0 && c < 0) in = !in;\n        if (c == 0 && dot(v1,\
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
    \ - 1; i++) ret.push_back(tmp[i]);\n    return ret;\n}\n\n/**\n * @brief closest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct ClosestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief closest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct ClosestPair\
    \ {\n    double dist;     //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n * @return ClosestPairSquared<T>\
    \ \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57\n\
    \ */\ntemplate <typename T>\nClosestPairSquared<T> closest_point_pair_squared(const\
    \ std::vector<Vector<T, 2>>& points) {\n    std::vector<int> sorted_idx(points.size());\n\
    \    std::iota(sorted_idx.begin(), sorted_idx.end(), 0);\n    std::sort(sorted_idx.begin(),\
    \ sorted_idx.end(), [&](int i, int j) {\n        return points[i][0] < points[j][0];\n\
    \    });\n    std::vector<int> left(1, 0);                                   \
    \     // \u5DE6\u7AEF\n    std::vector<int> right(1, points.size());         \
    \                  // \u53F3\u7AEF\n    std::vector<int> mid(1, points.size()\
    \ / 2);                         // \u4E2D\u592E\n    std::vector<int> par(1, -1);\
    \                                        // \u89AA\n    std::vector<T> min_dist_squared(1,\
    \ std::numeric_limits<T>::max());  // \u6700\u5C0F\u8DDD\u96E2\u306E2\u4E57\n\
    \    std::vector<std::pair<int, int>> min_dist_pair(1, {-1, -1});        // \u6700\
    \u5C0F\u8DDD\u96E2\u306E\u70B9\u5BFE\n    std::stack<int> stk;\n    stk.push(~0);\n\
    \    stk.push(0);\n    while (!stk.empty()) {\n        int u = stk.top();\n  \
    \      stk.pop();\n        if (u >= 0) {\n            // \u884C\u304D\u304C\u3051\
    \n            if (left[u] + 1 < mid[u]) {\n                int v = left.size();\n\
    \                left.push_back(left[u]);\n                right.push_back(mid[u]);\n\
    \                mid.push_back((left[u] + mid[u]) / 2);\n                par.push_back(u);\n\
    \                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n            if (mid[u] + 1 < right[u])\
    \ {\n                int v = left.size();\n                left.push_back(mid[u]);\n\
    \                right.push_back(right[u]);\n                mid.push_back((mid[u]\
    \ + right[u]) / 2);\n                par.push_back(u);\n                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n        } else {\n            //\
    \ \u5E30\u308A\u304C\u3051\n            u = ~u;\n            std::vector<int>\
    \ cand;\n            for (int i = left[u]; i < right[u]; i++) {\n            \
    \    T dx = points[sorted_idx[i]][0] - points[sorted_idx[mid[u]]][0];\n      \
    \          if (dx * dx < min_dist_squared[u]) cand.push_back(i);\n           \
    \ }\n            std::sort(cand.begin(), cand.end(), [&](int i, int j) {\n   \
    \             return points[sorted_idx[i]][1] < points[sorted_idx[j]][1];\n  \
    \          });\n            for (int i = 0; i < static_cast<int>(cand.size());\
    \ i++) {\n                for (int j = i + 1; j < static_cast<int>(cand.size());\
    \ j++) {\n                    T dx = points[sorted_idx[cand[j]]][0] - points[sorted_idx[cand[i]]][0];\n\
    \                    T dy = points[sorted_idx[cand[j]]][1] - points[sorted_idx[cand[i]]][1];\n\
    \                    if (dy * dy >= min_dist_squared[u]) break;\n            \
    \        T d = dx * dx + dy * dy;\n                    if (d < min_dist_squared[u])\
    \ {\n                        min_dist_squared[u] = d;\n                      \
    \  min_dist_pair[u] = {sorted_idx[cand[i]], sorted_idx[cand[j]]};\n          \
    \          }\n                }\n            }\n            if (par[u] != -1 &&\
    \ min_dist_squared[u] < min_dist_squared[par[u]]) {\n                min_dist_squared[par[u]]\
    \ = min_dist_squared[u];\n                min_dist_pair[par[u]] = min_dist_pair[u];\n\
    \            }\n        }\n    }\n    return {min_dist_squared[0], min_dist_pair[0].first,\
    \ min_dist_pair[0].second};\n}\n\n/**\n * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\
    \u30C8\n * @return ClosestPair \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\
    \u6DFB\u5B57\n */\ntemplate <typename T>\nClosestPair closest_point_pair(const\
    \ std::vector<Vector<T, 2>>& points) {\n    auto [d2, i, j] = closest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief farthest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct FarthestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief farthest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct FarthestPair\
    \ {\n    double dist;     //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u9060\u70B9\u5BFE (\u51F8\u5305\u3092\u4F5C\u308A\u3001\u56DE\
    \u8EE2\u30AD\u30E3\u30EA\u30D1\u30FC\u6CD5\u3067\u5BFE\u8E60\u70B9\u306E\u7D44\
    \u3092\u8ABF\u3079\u308B) O(n log n)\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B\u3002\u5EA7\u6A19\u306E\u5DEE\u306E2\u4E57\u306E\u548C\u306E2\u500D\
    \u304C T \u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\
    \u4EE5\u4E0A)\n * @return FarthestPairSquared<T> \u6700\u9060\u70B9\u5BFE\u306E\
    \u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57 (i != j)\n */\ntemplate <typename\
    \ T>\nFarthestPairSquared<T> farthest_point_pair_squared(const std::vector<Vector<T,\
    \ 2>>& points) {\n    const int n = static_cast<int>(points.size());\n    assert(n\
    \ >= 2);\n    // \u51F8\u5305\u306E\u9802\u70B9\u3092\u3001\u3082\u3068\u306E\u6DFB\
    \u5B57\u306B\u623B\u305B\u308B\u3088\u3046\u306B\u3057\u3066\u304A\u304F\n   \
    \ std::vector<std::pair<Vector<T, 2>, int>> sorted(n);\n    for (int i = 0; i\
    \ < n; i++) sorted[i] = {points[i], i};\n    std::sort(sorted.begin(), sorted.end());\n\
    \    auto index_of = [&](const Vector<T, 2>& p) {\n        return std::lower_bound(sorted.begin(),\
    \ sorted.end(), std::make_pair(p, -1))->second;\n    };\n    std::vector<Vector<T,\
    \ 2>> hull = convex_hull(points);\n    const int k = static_cast<int>(hull.size());\n\
    \    if (k == 1) return {T(0), sorted[0].second, sorted[1].second};  // \u3059\
    \u3079\u3066\u540C\u3058\u70B9\n    FarthestPairSquared<T> res{T(0), -1, -1};\n\
    \    auto update = [&](int a, int b) {\n        T d = (hull[a] - hull[b]).squared_norm();\n\
    \        if (res.i == -1 || d > res.squared_dist) res = {d, a, b};\n    };\n \
    \   if (k == 2) {\n        update(0, 1);\n    } else {\n        // \u8FBA i\u2192\
    i+1 \u306B\u5BFE\u3057\u3066\u3001\u6700\u3082\u9060\u3044\u9802\u70B9 j \u3092\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u9032\u3081\u3066\u3044\u304F\n        int\
    \ j = 1;\n        for (int i = 0; i < k; i++) {\n            int ni = i + 1 ==\
    \ k ? 0 : i + 1;\n            while (true) {\n                int nj = j + 1 ==\
    \ k ? 0 : j + 1;\n                if (cross(hull[ni] - hull[i], hull[nj] - hull[j])\
    \ > 0)\n                    j = nj;\n                else\n                  \
    \  break;\n            }\n            update(i, j);\n            update(ni, j);\n\
    \        }\n    }\n    return {res.squared_dist, index_of(hull[res.i]), index_of(hull[res.j])};\n\
    }\n\n/**\n * @brief \u6700\u9060\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\u4EE5\u4E0A)\n\
    \ * @return FarthestPair \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\u6DFB\
    \u5B57\n */\ntemplate <typename T>\nFarthestPair farthest_point_pair(const std::vector<Vector<T,\
    \ 2>>& points) {\n    auto [d2, i, j] = farthest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief \u51F8\
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
    \ a) * (ca / (ca - cb)));\n    }\n    return res;\n}\n/**\n * @deprecated closest_point_pair_squared\
    \ \u3092\u4F7F\u3046\u3053\u3068(\u7DB4\u308A\u306E\u8AA4\u308A\u3092\u76F4\u3057\
    \u3066\u6539\u540D\u3057\u305F)\n */\ntemplate <typename T>\n[[deprecated(\"use\
    \ closest_point_pair_squared\")]] ClosestPairSquared<T> closest_point_pair_squred(const\
    \ std::vector<Vector<T, 2>>& points) {\n    return closest_point_pair_squared(points);\n\
    }\n#line 9 \"test/yosupo/geo/sort-points-by-argument.1.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    using P = Vector<long long>;\n    std::vector<P>\
    \ ps(n);\n    for (auto& p : ps) std::cin >> p;\n    // Angle \u306F x \u8EF8\u6B63\
    \u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A ([0, 2\u03C0)) \u306B\u6BD4\
    \u3079\u308B\n    std::sort(ps.begin(), ps.end(), [](const P& a, const P& b) {\
    \ return Angle(a) < Angle(b); });\n    // \u554F\u984C\u306F x <= 0, y = 0 \u306E\
    \u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0, \u03C0]) \u306A\u306E\
    \u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\u3059\n    std::stable_partition(ps.begin(),\
    \ ps.end(), [](const P& p) { return p[1] < 0; });\n    for (const auto& p : ps)\
    \ std::cout << p << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sort_points_by_argument\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../../src/geometry/angle.hpp\"\n#include \"../../../src/geometry/vector.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n    using P = Vector<long long>;\n\
    \    std::vector<P> ps(n);\n    for (auto& p : ps) std::cin >> p;\n    // Angle\
    \ \u306F x \u8EF8\u6B63\u65B9\u5411\u304B\u3089\u53CD\u6642\u8A08\u56DE\u308A\
    \ ([0, 2\u03C0)) \u306B\u6BD4\u3079\u308B\n    std::sort(ps.begin(), ps.end(),\
    \ [](const P& a, const P& b) { return Angle(a) < Angle(b); });\n    // \u554F\u984C\
    \u306F x <= 0, y = 0 \u306E\u534A\u76F4\u7DDA\u306E\u76F4\u5F8C\u304B\u3089 ((-\u03C0\
    , \u03C0]) \u306A\u306E\u3067\u3001y < 0 \u306E\u70B9\u3092\u5148\u982D\u306B\u79FB\
    \u3059\n    std::stable_partition(ps.begin(), ps.end(), [](const P& p) { return\
    \ p[1] < 0; });\n    for (const auto& p : ps) std::cout << p << '\\n';\n}\n"
  dependsOn:
  - src/geometry/angle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/yosupo/geo/sort-points-by-argument.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 13:36:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/geo/sort-points-by-argument.1.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/geo/sort-points-by-argument.1.test.cpp
- /verify/test/yosupo/geo/sort-points-by-argument.1.test.cpp.html
title: test/yosupo/geo/sort-points-by-argument.1.test.cpp
---
