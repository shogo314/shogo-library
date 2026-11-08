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
    path: test/aoj/dsl/dsl-2-c.test.cpp
    title: test/aoj/dsl/dsl-2-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/kd-tree.test.cpp
    title: test/unittest/data_structures/kd-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: kd-tree
    links: []
  bundledCode: "#line 2 \"src/data_structures/kd-tree.hpp\"\n\n/**\n * @file kd-tree.hpp\n\
    \ * @brief kd-tree\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <numeric>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/geometry/rectangle.hpp\"\
    \n\n/**\n * @file rectangle.hpp\n * @brief \u8EF8\u306B\u5E73\u884C\u306A\u9577\
    \u65B9\u5F62\n */\n\n#line 9 \"src/geometry/rectangle.hpp\"\n#include <istream>\n\
    #include <type_traits>\n\n#line 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file\
    \ vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n */\n\n#include\
    \ <array>\n#line 10 \"src/geometry/vector.hpp\"\n#include <cmath>\n#line 12 \"\
    src/geometry/vector.hpp\"\n#include <ostream>\n#line 15 \"src/geometry/vector.hpp\"\
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
    \ B, C, D>>;\n#line 15 \"src/data_structures/kd-tree.hpp\"\n\n/**\n * @brief 2\
    \ \u6B21\u5143\u306E\u70B9\u306E\u96C6\u5408 (\u9759\u7684) \u306B\u3064\u3044\
    \u3066\u3001\u9577\u65B9\u5F62\u9818\u57DF\u306B\u5165\u308B\u70B9\u3092\u5217\
    \u6319\u3059\u308B kd-tree\n *\n * x \u3068 y \u3067\u4EA4\u4E92\u306B\u4E2D\u592E\
    \u5024\u3067\u5206\u3051\u3001\u5404\u90E8\u5206\u6728\u306E\u70B9\u3092\u56F2\
    \u3080\u9577\u65B9\u5F62\u3092\u6301\u3064\u3002\u69CB\u7BC9 O(n log n)\u3001\n\
    \ * \u5217\u6319\u306F O(\u221An + \u5217\u6319\u3059\u308B\u500B\u6570)\u3001\
    \u500B\u6570\u3092\u6570\u3048\u308B\u306E\u3082 O(\u221An)\n * \u4F8B:\n * KDTree<long\
    \ long> kd(points);  // points[i] = {x, y}\n * auto ids = kd.enumerate(Rectangle(xl,\
    \ yl, xr, yr));  // xl <= x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\u306E\u6DFB\
    \u5B57\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\n\
    class KDTree {\n    long long n;\n    std::vector<long long> ord;  // \u6728\u306E\
    \u9806\u306B\u4E26\u3079\u305F\u70B9\u306E\u6DFB\u5B57\n    std::vector<T> x,\
    \ y;         // \u6728\u306E\u9806\u306B\u4E26\u3079\u305F\u5EA7\u6A19\n    //\
    \ [l, r) \u306E\u90E8\u5206\u6728\u306E\u70B9\u3092\u56F2\u3080\u9577\u65B9\u5F62\
    \u3092\u3001\u4E2D\u592E m = (l + r) / 2 \u306E\u4F4D\u7F6E\u306B\u6301\u3064\n\
    \    std::vector<T> min_x, max_x, min_y, max_y;\n\n    void build(long long l,\
    \ long long r, bool by_x, const std::vector<std::pair<T, T>>& points) {\n    \
    \    if (l >= r) return;\n        long long m = (l + r) / 2;\n        std::nth_element(ord.begin()\
    \ + l, ord.begin() + m, ord.begin() + r, [&](long long i, long long j) {\n   \
    \         return by_x ? points[i].first < points[j].first : points[i].second <\
    \ points[j].second;\n        });\n        build(l, m, !by_x, points);\n      \
    \  build(m + 1, r, !by_x, points);\n        min_x[m] = max_x[m] = points[ord[m]].first;\n\
    \        min_y[m] = max_y[m] = points[ord[m]].second;\n        // \u5B50\u306E\
    \u90E8\u5206\u6728\u304C\u7A7A\u3067\u306A\u3051\u308C\u3070\u3001\u305D\u306E\
    \u9577\u65B9\u5F62\u3092\u5408\u308F\u305B\u308B\n        for (long long c : {l\
    \ < m ? (l + m) / 2 : -1, m + 1 < r ? (m + 1 + r) / 2 : -1}) {\n            if\
    \ (c == -1) continue;\n            min_x[m] = std::min(min_x[m], min_x[c]), max_x[m]\
    \ = std::max(max_x[m], max_x[c]);\n            min_y[m] = std::min(min_y[m], min_y[c]),\
    \ max_y[m] = std::max(max_y[m], max_y[c]);\n        }\n    }\n    // \u9577\u65B9\
    \u5F62\u306B\u5165\u308B\u70B9\u3092\u30011 \u70B9\u305A\u3064 point(i) \u3067\
    \u3001\u90E8\u5206\u6728\u3054\u3068\u5165\u308B\u306A\u3089 range(l, r) \u3067\
    \u5831\u544A\u3059\u308B (i, l, r \u306F\u6728\u306E\u9806\u306E\u4F4D\u7F6E)\n\
    \    template <typename F, typename G>\n    void query(long long l, long long\
    \ r, const Rectangle<T>& rect, const F& point, const G& range) const {\n     \
    \   const auto& [xl, yl, xr, yr] = rect;\n        if (l >= r) return;\n      \
    \  long long m = (l + r) / 2;\n        if (max_x[m] < xl || xr <= min_x[m] ||\
    \ max_y[m] < yl || yr <= min_y[m]) return;\n        if (xl <= min_x[m] && max_x[m]\
    \ < xr && yl <= min_y[m] && max_y[m] < yr) {\n            range(l, r);\n     \
    \       return;\n        }\n        if (rect.contains(x[m], y[m])) point(m);\n\
    \        query(l, m, rect, point, range);\n        query(m + 1, r, rect, point,\
    \ range);\n    }\n\n   public:\n    /**\n     * @brief \u70B9 i \u306E\u5EA7\u6A19\
    \u304C points[i] = {x, y} \u306E kd-tree \u3092\u4F5C\u308B\n     */\n    explicit\
    \ KDTree(const std::vector<std::pair<T, T>>& points)\n        : n(points.size()),\
    \ ord(n), x(n), y(n), min_x(n), max_x(n), min_y(n), max_y(n) {\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        build(0, n, true, points);\n        for (long long i\
    \ = 0; i < n; i++) x[i] = points[ord[i]].first, y[i] = points[ord[i]].second;\n\
    \    }\n    /**\n     * @brief \u70B9\u306E\u500B\u6570\n     */\n    long long\
    \ size() const { return n; }\n    /**\n     * @brief xl <= x < xr \u304B\u3064\
    \ yl <= y < yr \u306E\u70B9\u306E\u6DFB\u5B57 (\u9806\u4E0D\u540C)\n     */\n\
    \    std::vector<long long> enumerate(const Rectangle<T>& rect) const {\n    \
    \    std::vector<long long> res;\n        query(0, n, rect, [&](long long i) {\
    \ res.push_back(ord[i]); }, [&](long long l, long long r) { res.insert(res.end(),\
    \ ord.begin() + l, ord.begin() + r); });\n        return res;\n    }\n    /**\n\
    \     * @brief xl <= x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\u306E\u500B\
    \u6570\n     */\n    long long count(const Rectangle<T>& rect) const {\n     \
    \   long long res = 0;\n        query(0, n, rect, [&](long long) { res++; }, [&](long\
    \ long l, long long r) { res += r - l; });\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file kd-tree.hpp\n * @brief kd-tree\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <numeric>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../geometry/rectangle.hpp\"\n\n/**\n * @brief 2 \u6B21\
    \u5143\u306E\u70B9\u306E\u96C6\u5408 (\u9759\u7684) \u306B\u3064\u3044\u3066\u3001\
    \u9577\u65B9\u5F62\u9818\u57DF\u306B\u5165\u308B\u70B9\u3092\u5217\u6319\u3059\
    \u308B kd-tree\n *\n * x \u3068 y \u3067\u4EA4\u4E92\u306B\u4E2D\u592E\u5024\u3067\
    \u5206\u3051\u3001\u5404\u90E8\u5206\u6728\u306E\u70B9\u3092\u56F2\u3080\u9577\
    \u65B9\u5F62\u3092\u6301\u3064\u3002\u69CB\u7BC9 O(n log n)\u3001\n * \u5217\u6319\
    \u306F O(\u221An + \u5217\u6319\u3059\u308B\u500B\u6570)\u3001\u500B\u6570\u3092\
    \u6570\u3048\u308B\u306E\u3082 O(\u221An)\n * \u4F8B:\n * KDTree<long long> kd(points);\
    \  // points[i] = {x, y}\n * auto ids = kd.enumerate(Rectangle(xl, yl, xr, yr));\
    \  // xl <= x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\u306E\u6DFB\u5B57\n\
    \ *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\nclass\
    \ KDTree {\n    long long n;\n    std::vector<long long> ord;  // \u6728\u306E\
    \u9806\u306B\u4E26\u3079\u305F\u70B9\u306E\u6DFB\u5B57\n    std::vector<T> x,\
    \ y;         // \u6728\u306E\u9806\u306B\u4E26\u3079\u305F\u5EA7\u6A19\n    //\
    \ [l, r) \u306E\u90E8\u5206\u6728\u306E\u70B9\u3092\u56F2\u3080\u9577\u65B9\u5F62\
    \u3092\u3001\u4E2D\u592E m = (l + r) / 2 \u306E\u4F4D\u7F6E\u306B\u6301\u3064\n\
    \    std::vector<T> min_x, max_x, min_y, max_y;\n\n    void build(long long l,\
    \ long long r, bool by_x, const std::vector<std::pair<T, T>>& points) {\n    \
    \    if (l >= r) return;\n        long long m = (l + r) / 2;\n        std::nth_element(ord.begin()\
    \ + l, ord.begin() + m, ord.begin() + r, [&](long long i, long long j) {\n   \
    \         return by_x ? points[i].first < points[j].first : points[i].second <\
    \ points[j].second;\n        });\n        build(l, m, !by_x, points);\n      \
    \  build(m + 1, r, !by_x, points);\n        min_x[m] = max_x[m] = points[ord[m]].first;\n\
    \        min_y[m] = max_y[m] = points[ord[m]].second;\n        // \u5B50\u306E\
    \u90E8\u5206\u6728\u304C\u7A7A\u3067\u306A\u3051\u308C\u3070\u3001\u305D\u306E\
    \u9577\u65B9\u5F62\u3092\u5408\u308F\u305B\u308B\n        for (long long c : {l\
    \ < m ? (l + m) / 2 : -1, m + 1 < r ? (m + 1 + r) / 2 : -1}) {\n            if\
    \ (c == -1) continue;\n            min_x[m] = std::min(min_x[m], min_x[c]), max_x[m]\
    \ = std::max(max_x[m], max_x[c]);\n            min_y[m] = std::min(min_y[m], min_y[c]),\
    \ max_y[m] = std::max(max_y[m], max_y[c]);\n        }\n    }\n    // \u9577\u65B9\
    \u5F62\u306B\u5165\u308B\u70B9\u3092\u30011 \u70B9\u305A\u3064 point(i) \u3067\
    \u3001\u90E8\u5206\u6728\u3054\u3068\u5165\u308B\u306A\u3089 range(l, r) \u3067\
    \u5831\u544A\u3059\u308B (i, l, r \u306F\u6728\u306E\u9806\u306E\u4F4D\u7F6E)\n\
    \    template <typename F, typename G>\n    void query(long long l, long long\
    \ r, const Rectangle<T>& rect, const F& point, const G& range) const {\n     \
    \   const auto& [xl, yl, xr, yr] = rect;\n        if (l >= r) return;\n      \
    \  long long m = (l + r) / 2;\n        if (max_x[m] < xl || xr <= min_x[m] ||\
    \ max_y[m] < yl || yr <= min_y[m]) return;\n        if (xl <= min_x[m] && max_x[m]\
    \ < xr && yl <= min_y[m] && max_y[m] < yr) {\n            range(l, r);\n     \
    \       return;\n        }\n        if (rect.contains(x[m], y[m])) point(m);\n\
    \        query(l, m, rect, point, range);\n        query(m + 1, r, rect, point,\
    \ range);\n    }\n\n   public:\n    /**\n     * @brief \u70B9 i \u306E\u5EA7\u6A19\
    \u304C points[i] = {x, y} \u306E kd-tree \u3092\u4F5C\u308B\n     */\n    explicit\
    \ KDTree(const std::vector<std::pair<T, T>>& points)\n        : n(points.size()),\
    \ ord(n), x(n), y(n), min_x(n), max_x(n), min_y(n), max_y(n) {\n        std::iota(ord.begin(),\
    \ ord.end(), 0);\n        build(0, n, true, points);\n        for (long long i\
    \ = 0; i < n; i++) x[i] = points[ord[i]].first, y[i] = points[ord[i]].second;\n\
    \    }\n    /**\n     * @brief \u70B9\u306E\u500B\u6570\n     */\n    long long\
    \ size() const { return n; }\n    /**\n     * @brief xl <= x < xr \u304B\u3064\
    \ yl <= y < yr \u306E\u70B9\u306E\u6DFB\u5B57 (\u9806\u4E0D\u540C)\n     */\n\
    \    std::vector<long long> enumerate(const Rectangle<T>& rect) const {\n    \
    \    std::vector<long long> res;\n        query(0, n, rect, [&](long long i) {\
    \ res.push_back(ord[i]); }, [&](long long l, long long r) { res.insert(res.end(),\
    \ ord.begin() + l, ord.begin() + r); });\n        return res;\n    }\n    /**\n\
    \     * @brief xl <= x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\u306E\u500B\
    \u6570\n     */\n    long long count(const Rectangle<T>& rect) const {\n     \
    \   long long res = 0;\n        query(0, n, rect, [&](long long) { res++; }, [&](long\
    \ long l, long long r) { res += r - l; });\n        return res;\n    }\n};\n"
  dependsOn:
  - src/geometry/rectangle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/data_structures/kd-tree.hpp
  requiredBy: []
  timestamp: '2026-11-08 17:10:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/kd-tree.test.cpp
  - test/aoj/dsl/dsl-2-c.test.cpp
documentation_of: src/data_structures/kd-tree.hpp
layout: document
title: kd-tree
---

2 次元の点の集合 (後から変えない) について、長方形領域に入る点を列挙したり数えたりします。x と y で交互に中央値で分け、各部分木の点を囲む長方形を持ちます。

```cpp
std::vector<std::pair<long long, long long>> points = { {2, 1}, {2, 2}, {4, 2}, {6, 2} };
KDTree<long long> kd(points);
auto ids = kd.enumerate(Rectangle(2LL, 0LL, 5LL, 5LL));  // 2 <= x < 5 かつ 0 <= y < 5 の点の添字: 0, 1, 2 (順不同)
long long k = kd.count(Rectangle(2LL, 0LL, 5LL, 5LL));   // 3
```

長方形は半開区間 $[x_l, x_r) \times [y_l, y_r)$ で指定します。閉区間で与えられたら、整数座標なら右端に 1 を足してください。

`enumerate` が返す添字は順不同です。必要なら並べ替えてください。

領域 `rect` は [Rectangle](../geometry/rectangle.hpp) で渡します。座標の順序は `(left, bottom, right, top)` です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `KDTree(points)` | 点 `i` の座標が `points[i] = {x, y}` (`std::pair<T, T>`) の kd-tree を作る | $O(n \log n)$ |
| `size()` | 点の個数 | $O(1)$ |
| `enumerate(rect)` | $x_l \le x < x_r$ かつ $y_l \le y < y_r$ の点の添字 (`std::vector<long long>`、順不同) | $O(\sqrt{n} + k)$ ($k$ は列挙する個数) |
| `count(rect)` | $x_l \le x < x_r$ かつ $y_l \le y < y_r$ の点の個数 | $O(\sqrt{n})$ |

## 関連

- 数えるだけなら、[Wavelet Matrix](wavelet-matrix.hpp) でも $O(\log n)$ で数えられる (x で並べ、y の値が範囲に入る個数を数える)
- 点の追加や値の和もあるなら [2次元セグメント木](segtree-2d.hpp)
