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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/geometry/angle.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ geometry/angle.hpp \u306E Angle \u3092\u3001atan2 \u3067\u6C42\u3081\u305F\u504F\
    \u89D2\u3068\u6BD4\u3079\u3066\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u6210\u308A\u7ACB\u3063\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/geometry/angle.hpp\"\
    \n\n/**\n * @file angle.hpp\n * @brief \u504F\u89D2\n */\n\n#include <cassert>\n\
    #include <cmath>\n#include <istream>\n#include <ostream>\n#include <type_traits>\n\
    #include <utility>\n\n/**\n * @brief 2 \u6B21\u5143\u30D9\u30AF\u30C8\u30EB (x,\
    \ y) \u306E\u504F\u89D2\n *\n * x \u8EF8\u6B63\u65B9\u5411\u3092 0 \u3068\u3057\
    \u3066\u53CD\u6642\u8A08\u56DE\u308A\u306B\u6E2C\u308A\u3001\u5468\u56DE\u6570\
    \ turn \u3068\u5408\u308F\u305B\u3066 2\u03C0 * turn + [0, 2\u03C0) \u306E\u5024\
    \u3068\u3057\u3066\u6BD4\u3079\u308B\u3002\u96F6\u30D9\u30AF\u30C8\u30EB\u306F\
    \ x \u8EF8\u6B63\u65B9\u5411\u3068\u540C\u3058\u504F\u89D2\u3068\u3057\u3066\u6271\
    \u3046\n * \u5916\u7A4D\u3067\u6BD4\u3079\u308B\u306E\u3067\u3001\u6574\u6570\u578B\
    \u306A\u3089\u8AA4\u5DEE\u306A\u304F\u6BD4\u3079\u3089\u308C\u308B (\u5EA7\u6A19\
    \u306E\u7D76\u5BFE\u5024\u306E 2 \u4E57\u304C T \u306B\u53CE\u307E\u308B\u5FC5\
    \u8981\u304C\u3042\u308B)\n *\n * std::sort(ps.begin(), ps.end(), [](const auto&\
    \ a, const auto& b) { return Angle(a) < Angle(b); });\n *\n * @tparam T \u5EA7\
    \u6A19\u306E\u578B\n */\ntemplate <typename T>\nstruct Angle {\n    T x;     \
    \            //!< x \u5EA7\u6A19\n    T y;                 //!< y \u5EA7\u6A19\
    \n    long long turn = 0;  //!< \u5468\u56DE\u6570\n\n    /**\n     * @brief \u504F\
    \u89D2 0 (\u96F6\u30D9\u30AF\u30C8\u30EB)\n     */\n    constexpr Angle() noexcept\
    \ : x(), y() {}\n    /**\n     * @brief \u30D9\u30AF\u30C8\u30EB (x, y) \u306E\
    \u504F\u89D2\u306B 2\u03C0 * turn \u3092\u8DB3\u3057\u305F\u3082\u306E\n     */\n\
    \    constexpr Angle(T x, T y, long long turn = 0) noexcept : x(x), y(y), turn(turn)\
    \ {}\n    /**\n     * @brief p[0], p[1] \u3092 x, y \u3068\u3059\u308B (Vector<T,\
    \ 2> \u3084 std::array<T, 2> \u304B\u3089\u4F5C\u308B)\n     */\n    template\
    \ <typename P, typename = decltype(std::declval<const P&>()[0])>\n    constexpr\
    \ explicit Angle(const P& p) noexcept : x(p[0]), y(p[1]) {}\n    /**\n     * @brief\
    \ p.first, p.second \u3092 x, y \u3068\u3059\u308B\n     */\n    constexpr explicit\
    \ Angle(const std::pair<T, T>& p) noexcept : x(p.first), y(p.second) {}\n\n  \
    \  /**\n     * @brief \u96F6\u30D9\u30AF\u30C8\u30EB\u304B\n     */\n    constexpr\
    \ bool is_zero() const noexcept { return x == 0 && y == 0; }\n    /**\n     *\
    \ @brief \u5468\u56DE\u6570\u3092\u9664\u3044\u305F\u504F\u89D2\u304C [0, \u03C0\
    ) \u306A\u3089 0\u3001[\u03C0, 2\u03C0) \u306A\u3089 1\n     */\n    constexpr\
    \ int half() const noexcept { return y < 0 || (y == 0 && x < 0); }\n    /**\n\
    \     * @brief \u504F\u89D2 (\u30E9\u30B8\u30A2\u30F3\u30012\u03C0 * turn + [0,\
    \ 2\u03C0))\n     */\n    double radian() const {\n        const double pi = std::acos(-1.0);\n\
    \        double t = std::atan2(static_cast<double>(y), static_cast<double>(x));\n\
    \        return (t < 0 ? t + 2 * pi : t) + 2 * pi * static_cast<double>(turn);\n\
    \    }\n    /**\n     * @brief 2\u03C0 \u3092\u8DB3\u3057\u305F\u504F\u89D2\n\
    \     */\n    constexpr Angle next_turn() const noexcept { return Angle(x, y,\
    \ turn + 1); }\n    /**\n     * @brief \u03C0 \u3092\u8DB3\u3057\u305F\u504F\u89D2\
    \ (\u9006\u5411\u304D\u306E\u30D9\u30AF\u30C8\u30EB)\u3002\u96F6\u30D9\u30AF\u30C8\
    \u30EB\u306B\u306F\u4F7F\u3048\u306A\u3044\n     */\n    constexpr Angle opposite()\
    \ const noexcept {\n        assert(!is_zero() && \"Angle::opposite: zero vector\"\
    );\n        return Angle(-x, -y, turn + half());\n    }\n\n    /**\n     * @brief\
    \ \u7B26\u53F7\u3092\u53CD\u8EE2\u3057\u305F\u504F\u89D2 (x \u8EF8\u306B\u3064\
    \u3044\u3066\u6298\u308A\u8FD4\u3057\u305F\u30D9\u30AF\u30C8\u30EB)\n     */\n\
    \    constexpr Angle operator-() const noexcept {\n        // \u5468\u56DE\u6570\
    \u3092\u9664\u3044\u305F\u504F\u89D2\u304C 0 \u306A\u3089 -2\u03C0 * turn\u3001\
    \u305D\u3046\u3067\u306A\u3051\u308C\u3070 2\u03C0 \u3092\u8DB3\u3057\u3066 [0,\
    \ 2\u03C0) \u306B\u53CE\u3081\u308B\n        bool on_zero = y == 0 && x >= 0;\n\
    \        return Angle(x, -y, -turn - !on_zero);\n    }\n    /**\n     * @brief\
    \ \u504F\u89D2\u306E\u548C (\u8907\u7D20\u6570\u3068\u3057\u3066\u306E\u7A4D)\n\
    \     *\n     * \u5EA7\u6A19\u306F a \u3068 b \u306E\u5EA7\u6A19\u306E\u7A4D\u306E\
    \u5927\u304D\u3055\u306B\u306A\u308B\u3002\u96F6\u30D9\u30AF\u30C8\u30EB\u306F\
    \u504F\u89D2 0 \u3068\u3057\u3066\u6271\u3044\u3001\u3082\u3046\u4E00\u65B9\u306E\
    \u30D9\u30AF\u30C8\u30EB\u3092\u8FD4\u3059\n     */\n    friend constexpr Angle\
    \ operator+(const Angle& a, const Angle& b) noexcept {\n        if (a.is_zero())\
    \ return Angle(b.x, b.y, a.turn + b.turn);\n        if (b.is_zero()) return Angle(a.x,\
    \ a.y, a.turn + b.turn);\n        Angle c(a.x * b.x - a.y * b.y, a.x * b.y + a.y\
    \ * b.x, a.turn + b.turn);\n        // \u5468\u56DE\u6570\u3092\u9664\u3044\u305F\
    \u504F\u89D2\u306E\u548C\u304C 2\u03C0 \u4EE5\u4E0A\u306A\u3089\u7E70\u308A\u4E0A\
    \u3052\u308B\n        // \u4E21\u65B9 [\u03C0, 2\u03C0) \u306A\u3089\u5FC5\u305A\
    \u3001\u7247\u65B9\u3060\u3051\u306A\u3089\u548C\u306F [\u03C0, 3\u03C0) \u306A\
    \u306E\u3067\u7D50\u679C\u304C [0, \u03C0) \u306E\u3068\u304D\n        if (a.half()\
    \ && b.half()) c.turn++;\n        if (a.half() != b.half() && c.half() == 0) c.turn++;\n\
    \        return c;\n    }\n    /**\n     * @brief \u504F\u89D2\u306E\u5DEE (a\
    \ \u304B\u3089 b \u3078\u53CD\u6642\u8A08\u56DE\u308A\u306B\u56DE\u3059\u89D2\u306F\
    \ b - a)\n     */\n    friend constexpr Angle operator-(const Angle& a, const\
    \ Angle& b) noexcept { return a + (-b); }\n    constexpr Angle& operator+=(const\
    \ Angle& rhs) noexcept { return *this = *this + rhs; }\n    constexpr Angle& operator-=(const\
    \ Angle& rhs) noexcept { return *this = *this - rhs; }\n\n    friend constexpr\
    \ bool operator<(const Angle& a, const Angle& b) noexcept {\n        if (a.turn\
    \ != b.turn) return a.turn < b.turn;\n        // \u96F6\u30D9\u30AF\u30C8\u30EB\
    \u306F\u5916\u7A4D\u3067\u6BD4\u3079\u3089\u308C\u306A\u3044\u306E\u3067\u3001\
    \u504F\u89D2 0 (x \u8EF8\u6B63\u65B9\u5411) \u3068\u3057\u3066\u5148\u306B\u5224\
    \u5B9A\u3059\u308B\n        if (b.is_zero()) return false;                   //\
    \ \u504F\u89D2 0 \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306F\u306A\u3044\n\
    \        if (a.is_zero()) return !(b.y == 0 && b.x > 0);  // b \u306E\u504F\u89D2\
    \u304C 0 \u3088\u308A\u5927\u304D\u3044\u304B\n        if (a.half() != b.half())\
    \ return a.half() < b.half();\n        return b.x * a.y < a.x * b.y;\n    }\n\
    \    friend constexpr bool operator>(const Angle& a, const Angle& b) noexcept\
    \ { return b < a; }\n    friend constexpr bool operator<=(const Angle& a, const\
    \ Angle& b) noexcept { return !(b < a); }\n    friend constexpr bool operator>=(const\
    \ Angle& a, const Angle& b) noexcept { return !(a < b); }\n    /**\n     * @brief\
    \ \u504F\u89D2\u304C\u7B49\u3057\u3044\u304B (\u30D9\u30AF\u30C8\u30EB\u3068\u3057\
    \u3066\u7B49\u3057\u3044\u304B\u3067\u306F\u306A\u3044)\n     */\n    friend constexpr\
    \ bool operator==(const Angle& a, const Angle& b) noexcept { return !(a < b) &&\
    \ !(b < a); }\n    friend constexpr bool operator!=(const Angle& a, const Angle&\
    \ b) noexcept { return !(a == b); }\n\n    /**\n     * @brief x, y \u3092\u8AAD\
    \u3080 (\u5468\u56DE\u6570\u306F 0 \u306B\u3059\u308B)\n     */\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Angle& rhs) {\n        rhs.turn = 0;\n        return is >> rhs.x\
    \ >> rhs.y;\n    }\n    /**\n     * @brief x, y \u3092\u7A7A\u767D\u533A\u5207\
    \u308A\u3067\u66F8\u304F (\u5468\u56DE\u6570\u306F\u66F8\u304B\u306A\u3044)\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Angle& rhs)\
    \ {\n        return os << rhs.x << CharT(' ') << rhs.y;\n    }\n};\n\ntemplate\
    \ <typename P, typename = decltype(std::declval<const P&>()[0])>\nAngle(const\
    \ P&) -> Angle<std::remove_cv_t<std::remove_reference_t<decltype(std::declval<const\
    \ P&>()[0])>>>;\ntemplate <typename T>\nAngle(const std::pair<T, T>&) -> Angle<T>;\n\
    #line 7 \"test/unittest/geometry/angle.test.cpp\"\n\n#include <array>\n#line 10\
    \ \"test/unittest/geometry/angle.test.cpp\"\n#include <iostream>\n#include <sstream>\n\
    #line 13 \"test/unittest/geometry/angle.test.cpp\"\n#include <vector>\n\n#line\
    \ 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\
    \u30D9\u30AF\u30C8\u30EB\n */\n\n#line 15 \"src/geometry/vector.hpp\"\n\n#line\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n#line 16 \"test/unittest/geometry/angle.test.cpp\"\
    \n\nint main() {\n    bool ok = true;\n    const double pi = std::acos(-1.0);\n\
    \    // \u504F\u89D2\u3092 [0, 2\u03C0) \u3067\u8FD4\u3059\u3002\u96F6\u30D9\u30AF\
    \u30C8\u30EB\u306F 0\n    auto arg = [&](int x, int y) {\n        double t = std::atan2(static_cast<double>(y),\
    \ static_cast<double>(x));\n        return t < 0 ? t + 2 * pi : t;\n    };\n \
    \   std::vector<std::pair<int, int>> ps;\n    for (int x = -4; x <= 4; x++) {\n\
    \        for (int y = -4; y <= 4; y++) ps.emplace_back(x, y);\n    }\n    for\
    \ (auto [ax, ay] : ps) {\n        Angle<long long> a(ax, ay);\n        ok = ok\
    \ && std::abs(a.radian() - arg(ax, ay)) < 1e-12;\n        ok = ok && a.is_zero()\
    \ == (ax == 0 && ay == 0);\n        ok = ok && a.half() == (arg(ax, ay) >= pi\
    \ - 1e-12);\n        for (auto [bx, by] : ps) {\n            Angle<long long>\
    \ b(bx, by);\n            double ta = arg(ax, ay), tb = arg(bx, by);\n       \
    \     bool lt = ta < tb - 1e-12, eq = std::abs(ta - tb) < 1e-12;\n           \
    \ ok = ok && (a < b) == lt && (b > a) == lt;\n            ok = ok && (a == b)\
    \ == eq && (a != b) == !eq;\n            ok = ok && (a <= b) == (lt || eq) &&\
    \ (b >= a) == (lt || eq);\n        }\n    }\n\n    // \u5468\u56DE\u6570\u3092\
    \u4ED8\u3051\u305F\u3068\u304D\u306E\u6BD4\u8F03\u3001\u548C\u30FB\u5DEE\u30FB\
    \u7B26\u53F7\u53CD\u8EE2\u30FBopposite\u30FBnext_turn \u3092 radian \u3068\u6BD4\
    \u3079\u308B\n    for (auto [ax, ay] : ps) {\n        for (int at = -1; at <=\
    \ 1; at++) {\n            Angle<long long> a(ax, ay, at);\n            double\
    \ ta = a.radian();\n            ok = ok && std::abs(ta - (arg(ax, ay) + 2 * pi\
    \ * at)) < 1e-9;\n            ok = ok && std::abs(a.next_turn().radian() - (ta\
    \ + 2 * pi)) < 1e-9;\n            ok = ok && std::abs((-a).radian() + ta) < 1e-9;\n\
    \            if (!a.is_zero()) ok = ok && std::abs(a.opposite().radian() - (ta\
    \ + pi)) < 1e-9;\n            for (auto [bx, by] : ps) {\n                for\
    \ (int bt = -1; bt <= 1; bt++) {\n                    Angle<long long> b(bx, by,\
    \ bt);\n                    double tb = b.radian();\n                    bool\
    \ lt = ta < tb - 1e-9, eq = std::abs(ta - tb) < 1e-9;\n                    ok\
    \ = ok && (a < b) == lt && (a == b) == eq;\n                    ok = ok && std::abs((a\
    \ + b).radian() - (ta + tb)) < 1e-9;\n                    ok = ok && std::abs((a\
    \ - b).radian() - (ta - tb)) < 1e-9;\n                    Angle<long long> c =\
    \ a;\n                    c += b;\n                    ok = ok && c == a + b;\n\
    \                    c -= b;\n                    ok = ok && c == a;\n       \
    \         }\n            }\n        }\n    }\n    // [\u03B8, \u03B8 + \u03C0\
    ) \u306E\u5224\u5B9A\u306F a <= b && b < a.opposite() \u3067\u3082 b - a < \u03C0\
    \ \u3067\u3082\u66F8\u3051\u308B\n    {\n        Angle<long long> a(1, 1), on(2,\
    \ 2), in(-1, 1), out(-1, -1), back(-3, -3);\n        ok = ok && a <= on && on\
    \ < a.opposite() && a <= in && in < a.opposite();\n        ok = ok && !(back <\
    \ a.opposite()) && !(out < a.opposite());\n        ok = ok && on - a < Angle<long\
    \ long>(-1, 0) && in - a < Angle<long long>(-1, 0);\n        ok = ok && !(back\
    \ - a < Angle<long long>(-1, 0)) && !(out - a < Angle<long long>(-1, 0));\n  \
    \  }\n    // \u5165\u51FA\u529B\u306F x y (\u5468\u56DE\u6570\u306F\u8AAD\u307F\
    \u66F8\u304D\u3057\u306A\u3044)\n    {\n        std::istringstream is(\"3 -4 -5\
    \ 6\");\n        Angle<long long> a(0, 0, 5), b;\n        is >> a >> b;\n    \
    \    ok = ok && a.x == 3 && a.y == -4 && a.turn == 0 && b.x == -5 && b.y == 6;\n\
    \        std::ostringstream os;\n        os << Angle<long long>(-1, 2, 3);\n \
    \       ok = ok && os.str() == \"-1 2\";\n    }\n\n    // Vector\u3001std::array\u3001\
    std::pair \u304B\u3089\u4F5C\u308C\u308B\n    Vector<long long> v(-3, 2);\n  \
    \  std::array<long long, 2> w{-3, 2};\n    std::pair<long long, long long> p(-3,\
    \ 2);\n    Angle av(v), aw(w), ap(p);\n    ok = ok && av.x == -3 && av.y == 2\
    \ && aw.x == -3 && aw.y == 2 && ap.x == -3 && ap.y == 2;\n    ok = ok && av ==\
    \ Angle<long long>(-6, 4);\n    // \u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u3082\
    \u4F7F\u3048\u308B\n    ok = ok && Angle(1.0, 1.0) < Angle(-1.0, 0.0) && !(Angle(0.0,\
    \ 0.0) < Angle(2.0, 0.0));\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// geometry/angle.hpp \u306E Angle \u3092\u3001atan2 \u3067\u6C42\u3081\u305F\
    \u504F\u89D2\u3068\u6BD4\u3079\u3066\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u6210\u308A\u7ACB\
    \u3063\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/geometry/angle.hpp\"\
    \n\n#include <array>\n#include <cmath>\n#include <iostream>\n#include <sstream>\n\
    #include <utility>\n#include <vector>\n\n#include \"../../../src/geometry/vector.hpp\"\
    \n\nint main() {\n    bool ok = true;\n    const double pi = std::acos(-1.0);\n\
    \    // \u504F\u89D2\u3092 [0, 2\u03C0) \u3067\u8FD4\u3059\u3002\u96F6\u30D9\u30AF\
    \u30C8\u30EB\u306F 0\n    auto arg = [&](int x, int y) {\n        double t = std::atan2(static_cast<double>(y),\
    \ static_cast<double>(x));\n        return t < 0 ? t + 2 * pi : t;\n    };\n \
    \   std::vector<std::pair<int, int>> ps;\n    for (int x = -4; x <= 4; x++) {\n\
    \        for (int y = -4; y <= 4; y++) ps.emplace_back(x, y);\n    }\n    for\
    \ (auto [ax, ay] : ps) {\n        Angle<long long> a(ax, ay);\n        ok = ok\
    \ && std::abs(a.radian() - arg(ax, ay)) < 1e-12;\n        ok = ok && a.is_zero()\
    \ == (ax == 0 && ay == 0);\n        ok = ok && a.half() == (arg(ax, ay) >= pi\
    \ - 1e-12);\n        for (auto [bx, by] : ps) {\n            Angle<long long>\
    \ b(bx, by);\n            double ta = arg(ax, ay), tb = arg(bx, by);\n       \
    \     bool lt = ta < tb - 1e-12, eq = std::abs(ta - tb) < 1e-12;\n           \
    \ ok = ok && (a < b) == lt && (b > a) == lt;\n            ok = ok && (a == b)\
    \ == eq && (a != b) == !eq;\n            ok = ok && (a <= b) == (lt || eq) &&\
    \ (b >= a) == (lt || eq);\n        }\n    }\n\n    // \u5468\u56DE\u6570\u3092\
    \u4ED8\u3051\u305F\u3068\u304D\u306E\u6BD4\u8F03\u3001\u548C\u30FB\u5DEE\u30FB\
    \u7B26\u53F7\u53CD\u8EE2\u30FBopposite\u30FBnext_turn \u3092 radian \u3068\u6BD4\
    \u3079\u308B\n    for (auto [ax, ay] : ps) {\n        for (int at = -1; at <=\
    \ 1; at++) {\n            Angle<long long> a(ax, ay, at);\n            double\
    \ ta = a.radian();\n            ok = ok && std::abs(ta - (arg(ax, ay) + 2 * pi\
    \ * at)) < 1e-9;\n            ok = ok && std::abs(a.next_turn().radian() - (ta\
    \ + 2 * pi)) < 1e-9;\n            ok = ok && std::abs((-a).radian() + ta) < 1e-9;\n\
    \            if (!a.is_zero()) ok = ok && std::abs(a.opposite().radian() - (ta\
    \ + pi)) < 1e-9;\n            for (auto [bx, by] : ps) {\n                for\
    \ (int bt = -1; bt <= 1; bt++) {\n                    Angle<long long> b(bx, by,\
    \ bt);\n                    double tb = b.radian();\n                    bool\
    \ lt = ta < tb - 1e-9, eq = std::abs(ta - tb) < 1e-9;\n                    ok\
    \ = ok && (a < b) == lt && (a == b) == eq;\n                    ok = ok && std::abs((a\
    \ + b).radian() - (ta + tb)) < 1e-9;\n                    ok = ok && std::abs((a\
    \ - b).radian() - (ta - tb)) < 1e-9;\n                    Angle<long long> c =\
    \ a;\n                    c += b;\n                    ok = ok && c == a + b;\n\
    \                    c -= b;\n                    ok = ok && c == a;\n       \
    \         }\n            }\n        }\n    }\n    // [\u03B8, \u03B8 + \u03C0\
    ) \u306E\u5224\u5B9A\u306F a <= b && b < a.opposite() \u3067\u3082 b - a < \u03C0\
    \ \u3067\u3082\u66F8\u3051\u308B\n    {\n        Angle<long long> a(1, 1), on(2,\
    \ 2), in(-1, 1), out(-1, -1), back(-3, -3);\n        ok = ok && a <= on && on\
    \ < a.opposite() && a <= in && in < a.opposite();\n        ok = ok && !(back <\
    \ a.opposite()) && !(out < a.opposite());\n        ok = ok && on - a < Angle<long\
    \ long>(-1, 0) && in - a < Angle<long long>(-1, 0);\n        ok = ok && !(back\
    \ - a < Angle<long long>(-1, 0)) && !(out - a < Angle<long long>(-1, 0));\n  \
    \  }\n    // \u5165\u51FA\u529B\u306F x y (\u5468\u56DE\u6570\u306F\u8AAD\u307F\
    \u66F8\u304D\u3057\u306A\u3044)\n    {\n        std::istringstream is(\"3 -4 -5\
    \ 6\");\n        Angle<long long> a(0, 0, 5), b;\n        is >> a >> b;\n    \
    \    ok = ok && a.x == 3 && a.y == -4 && a.turn == 0 && b.x == -5 && b.y == 6;\n\
    \        std::ostringstream os;\n        os << Angle<long long>(-1, 2, 3);\n \
    \       ok = ok && os.str() == \"-1 2\";\n    }\n\n    // Vector\u3001std::array\u3001\
    std::pair \u304B\u3089\u4F5C\u308C\u308B\n    Vector<long long> v(-3, 2);\n  \
    \  std::array<long long, 2> w{-3, 2};\n    std::pair<long long, long long> p(-3,\
    \ 2);\n    Angle av(v), aw(w), ap(p);\n    ok = ok && av.x == -3 && av.y == 2\
    \ && aw.x == -3 && aw.y == 2 && ap.x == -3 && ap.y == 2;\n    ok = ok && av ==\
    \ Angle<long long>(-6, 4);\n    // \u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u3067\u3082\
    \u4F7F\u3048\u308B\n    ok = ok && Angle(1.0, 1.0) < Angle(-1.0, 0.0) && !(Angle(0.0,\
    \ 0.0) < Angle(2.0, 0.0));\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/geometry/angle.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/geometry/angle.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 17:14:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/geometry/angle.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/geometry/angle.test.cpp
- /verify/test/unittest/geometry/angle.test.cpp.html
title: test/unittest/geometry/angle.test.cpp
---
