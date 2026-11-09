---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/internal/predicates.hpp
    title: "\u5E7E\u4F55\u306E\u5185\u90E8\u8A08\u7B97 (\u6574\u6570\u5EA7\u6A19\u306E\
      \u62E1\u5F35\u3001\u5411\u304D\u3001\u30CE\u30EB\u30E0)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/line.hpp
    title: "2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u76F4\u7DDA"
  - icon: ':heavy_check_mark:'
    path: src/geometry/plane.hpp
    title: "\u5E73\u9762 (\u5305\u542B\u30FB\u5E73\u884C\u5224\u5B9A\u3001\u8DDD\u96E2\
      \u3001\u76F4\u7DDA\u3068\u306E\u4EA4\u70B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/polygon.hpp
    title: "\u591A\u89D2\u5F62 (\u9762\u7A4D\u3001\u91CD\u5FC3\u3001\u5185\u5916\u5224\
      \u5B9A\u3001\u51F8\u6027\u3001\u51F8\u5305\u3001\u51F8\u591A\u89D2\u5F62\u306E\
      \u5207\u65AD)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/segment.hpp
    title: "2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u7DDA\u5206"
  - icon: ':heavy_check_mark:'
    path: src/geometry/triangle.hpp
    title: "2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u4E09\u89D2\u5F62"
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
  bundledCode: "#line 1 \"test/unittest/geometry/plane.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ 3 \u6B21\u5143\u306E\u76F4\u7DDA\u30FB\u7DDA\u5206\u30FB\u5E73\u9762\u30FB\u4E09\
    \u89D2\u5F62\u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\
    \u3079\u308B\n// \u8DDD\u96E2\u306F\u3001\u7DDA\u5206\u3084\u5E73\u9762\u306E\u30D1\
    \u30E9\u30E1\u30FC\u30BF\u306B\u3064\u3044\u3066\u51F8\u306A\u306E\u3067\u3001\
    \u4E09\u5206\u63A2\u7D22\u3067\u6700\u5C0F\u5316\u3057\u305F\u3082\u306E\u3068\
    \u6BD4\u3079\u308B\n// segment_triangle_intersect \u306F\u3001\u5E73\u9762\u3092\
    \u8CAB\u304F\u5834\u5408\u306F\u4EA4\u70B9\u3092\u6709\u7406\u6570\u3067\u6B63\
    \u78BA\u306B\u6C42\u3081\u3066\u4E09\u89D2\u5F62\u306E\u5185\u5916\u3092\u8ABF\
    \u3079\u305F\u3082\u306E\u3068\u3001\n// \u540C\u3058\u5E73\u9762\u4E0A\u306E\u5834\
    \u5408\u306F z = 0 \u306E\u5E73\u9762\u3067 2 \u6B21\u5143\u306E\u5224\u5B9A\u3092\
    \u3057\u3066\u304B\u3089\u3001\u884C\u5217\u5F0F \xB11 \u306E\u6574\u6570\u306E\
    \u884C\u5217\u3067\u7A7A\u9593\u306B\u79FB\u3057\u305F\u3082\u306E\u3068\u6BD4\
    \u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u6210\u308A\u7ACB\u3063\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#line 2 \"src/geometry/plane.hpp\"\n\n/**\n * @file plane.hpp\n\
    \ * @brief \u5E73\u9762 (\u5305\u542B\u30FB\u5E73\u884C\u5224\u5B9A\u3001\u8DDD\
    \u96E2\u3001\u76F4\u7DDA\u3068\u306E\u4EA4\u70B9)\n */\n\n#include <cassert>\n\
    #include <cmath>\n#include <optional>\n#include <type_traits>\n\n#line 2 \"src/geometry/internal/predicates.hpp\"\
    \n\n/**\n * @file predicates.hpp\n * @brief \u5E7E\u4F55\u306E\u5185\u90E8\u8A08\
    \u7B97 (\u6574\u6570\u5EA7\u6A19\u306E\u62E1\u5F35\u3001\u5411\u304D\u3001\u30CE\
    \u30EB\u30E0)\n */\n\n#line 10 \"src/geometry/internal/predicates.hpp\"\n\n#line\
    \ 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\
    \u30D9\u30AF\u30C8\u30EB\n */\n\n#include <array>\n#line 11 \"src/geometry/vector.hpp\"\
    \n#include <istream>\n#include <ostream>\n#line 14 \"src/geometry/vector.hpp\"\
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
    \ < v.squared_norm()) return -2;\n    return 0;\n}\n#line 12 \"src/geometry/internal/predicates.hpp\"\
    \n\nnamespace internal_predicates {\n// \u6574\u6570\u5EA7\u6A19\u306E\u5916\u7A4D\
    \u30FB\u4F53\u7A4D\u306E\u8A08\u7B97\u306B\u4F7F\u3046\u578B (\u5EA7\u6A19\u304C\
    \ 1e9 \u306A\u3089\u4F53\u7A4D\u306F 1e27 \u7A0B\u5EA6\u306B\u306A\u308B)\ntemplate\
    \ <typename T>\nusing Wide = std::conditional_t<std::is_integral_v<T>, __int128_t,\
    \ T>;\ntemplate <typename T, int Dim>\nconstexpr Vector<Wide<T>, Dim> widen(const\
    \ Vector<T, Dim>& p) {\n    Vector<Wide<T>, Dim> result;\n    for (int i = 0;\
    \ i < Dim; ++i) result[i] = static_cast<Wide<T>>(p[i]);\n    return result;\n\
    }\n// \u56DB\u9762\u4F53 abcd \u306E\u7B26\u53F7\u4ED8\u304D\u4F53\u7A4D\u306E\
    \ 6 \u500D\u306E\u7B26\u53F7 (d \u304C\u5E73\u9762 abc \u306E\u3001abc \u304C\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B\u898B\u3048\u308B\u5074\u306A\u3089\u6B63)\ntemplate\
    \ <typename T>\nint orient(const Vector<T, 3>& a, const Vector<T, 3>& b, const\
    \ Vector<T, 3>& c, const Vector<T, 3>& d) {\n    const auto wa = widen(a);\n \
    \   const auto v = dot(cross(widen(b) - wa, widen(c) - wa), widen(d) - wa);\n\
    \    return (v > 0) - (v < 0);\n}\ntemplate <typename T>\ndouble norm(const Vector<T,\
    \ 3>& v) {\n    const double x = static_cast<double>(v[0]), y = static_cast<double>(v[1]),\
    \ z = static_cast<double>(v[2]);\n    return std::sqrt(x * x + y * y + z * z);\n\
    }\n}  // namespace internal_predicates\n#line 2 \"src/geometry/line.hpp\"\n\n\
    /**\n * @file line.hpp\n * @brief 2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u76F4\
    \u7DDA (\u5E73\u884C\u30FB\u76F4\u4EA4\u3001\u5C04\u5F71\u30FB\u53CD\u5C04\u3001\
    \u4EA4\u70B9\u3001\u8DDD\u96E2)\n */\n\n#line 12 \"src/geometry/line.hpp\"\n\n\
    #line 15 \"src/geometry/line.hpp\"\n\n/**\n * @brief 2 \u70B9\u3067\u8868\u3059\
    \u76F4\u7DDA\u3002p1 != p2 \u304C\u5FC5\u8981\u3002\u7B49\u5024\u6BD4\u8F03\u306F\
    \u540C\u3058\u76F4\u7DDA\u304B\u3092\u5224\u5B9A\u3059\u308B\n */\ntemplate <typename\
    \ T = long long, int Dim = 2>\nstruct Line {\n    static_assert(Dim >= 2, \"dimension\
    \ must be at least 2\");\n    Vector<T, Dim> p1, p2;\n\n    constexpr Line(const\
    \ Vector<T, Dim>& p1, const Vector<T, Dim>& p2) : p1(p1), p2(p2) {\n        assert(p1\
    \ != p2 && \"Line: degenerate line\");\n    }\n    constexpr bool operator==(const\
    \ Line& other) const {\n        assert(p1 != p2 && other.p1 != other.p2 && \"\
    Line: degenerate line\");\n        using Wide = std::conditional_t<std::is_integral_v<T>,\
    \ __int128_t, T>;\n        auto on_line = [&](const Vector<T, Dim>& p) {\n   \
    \         for (int i = 0; i < Dim; ++i) {\n                for (int j = i + 1;\
    \ j < Dim; ++j) {\n                    Wide di = static_cast<Wide>(p2[i]) - p1[i],\
    \ dj = static_cast<Wide>(p2[j]) - p1[j];\n                    Wide vi = static_cast<Wide>(p[i])\
    \ - p1[i], vj = static_cast<Wide>(p[j]) - p1[j];\n                    if (di *\
    \ vj != dj * vi) return false;\n                }\n            }\n           \
    \ return true;\n        };\n        return on_line(other.p1) && on_line(other.p2);\n\
    \    }\n    constexpr bool operator!=(const Line& other) const { return !(*this\
    \ == other); }\n};\n\ntemplate <typename T, int Dim>\nLine(const Vector<T, Dim>&,\
    \ const Vector<T, Dim>&) -> Line<T, Dim>;\n\n/**\n * @brief \u76F4\u7DDA p1p2\
    \ \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\u884C\u304B (\u6574\u6570\u578B\u3067\u3082\
    \u4F7F\u3048\u308B)\n */\ntemplate <typename T>\nconstexpr bool is_parallel(const\
    \ Line<T>& first, const Line<T>& second) {\n    const auto& [p1, p2] = first;\n\
    \    const auto& [q1, q2] = second;\n    return cross(p2 - p1, q2 - q1) == 0;\n\
    }\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u76F4\u4EA4\
    \u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate\
    \ <typename T>\nconstexpr bool is_orthogonal(const Line<T>& first, const Line<T>&\
    \ second) {\n    const auto& [p1, p2] = first;\n    const auto& [q1, q2] = second;\n\
    \    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9 p \u304B\u3089\
    \u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3 (\u5C04\
    \u5F71)\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 2> projection(const Line<T>& object, const Vector<T,\
    \ 2>& p) {\n    const auto& [p1, p2] = object;\n    static_assert(std::is_floating_point_v<T>,\
    \ \"projection: T must be a floating point type\");\n    assert(p1 != p2 && \"\
    projection: degenerate line\");\n    Vector<T, 2> d = p2 - p1;\n    return p1\
    \ + d * (dot(p - p1, d) / d.squared_norm());\n}\n/**\n * @brief \u76F4\u7DDA p1p2\
    \ \u306B\u3064\u3044\u3066\u70B9 p \u3068\u5BFE\u79F0\u306A\u70B9 (\u53CD\u5C04\
    )\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 2> reflection(const Line<T>& object, const Vector<T,\
    \ 2>& p) {\n    return projection(object, p) * T(2) - p;\n}\n\n/**\n * @brief\
    \ \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u306E\u4EA4\u70B9\u3002\u6D6E\u52D5\
    \u5C0F\u6570\u70B9\u578B\u9650\u5B9A\u3002p1 != p2 \u304B\u3064 q1 != q2 \u3067\
    \u3042\u308B\u3053\u3068\n * @return std::optional<Vector<T, 2>> \u4EA4\u70B9\
    \ (\u5E73\u884C (\u91CD\u306A\u308B\u76F4\u7DDA\u3082\u542B\u3080) \u306A\u3089\
    \ std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> line_intersection(const Line<T>& first, const Line<T>& second) {\n    const\
    \ auto& [p1, p2] = first;\n    const auto& [q1, q2] = second;\n    static_assert(std::is_floating_point_v<T>,\
    \ \"line_intersection: T must be a floating point type\");\n    assert(p1 != p2\
    \ && q1 != q2 && \"line_intersection: degenerate line\");\n    Vector<T, 2> d\
    \ = p2 - p1, e = q2 - q1;\n    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n\
    \    // p1 + d t \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return\
    \ p1 + d * (cross(e, q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\
    \u7DDA p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\
    )\n */\ntemplate <typename T>\ndouble distance_point_line(const Line<T>& object,\
    \ const Vector<T, 2>& p) {\n    const auto& [p1, p2] = object;\n    assert(p1\
    \ != p2 && \"distance_point_line: degenerate line\");\n    return std::abs(static_cast<double>(cross(p2\
    \ - p1, p - p1))) / (p2 - p1).abs();\n}\n/** @brief 3 \u6B21\u5143\u306E\u76F4\
    \u7DDA\u540C\u58EB\u304C\u5E73\u884C\u304B\u3002\u4E00\u81F4\u3059\u308B\u5834\
    \u5408\u3082 true */\ntemplate <typename T>\nconstexpr bool is_parallel(const\
    \ Line<T, 3>& first, const Line<T, 3>& second) {\n    using internal_predicates::widen;\n\
    \    const auto u = widen(first.p2) - widen(first.p1), v = widen(second.p2) -\
    \ widen(second.p1);\n    assert((u[0] != 0 || u[1] != 0 || u[2] != 0) && \"is_parallel:\
    \ degenerate line\");\n    assert((v[0] != 0 || v[1] != 0 || v[2] != 0) && \"\
    is_parallel: degenerate line\");\n    const auto n = cross(u, v);\n    return\
    \ n[0] == 0 && n[1] == 0 && n[2] == 0;\n}\n\n/**\n * @brief \u70B9 p \u304B\u3089\
    \u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\u8DB3 (\u5C04\
    \u5F71)\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 3> projection(const Line<T, 3>& object, const Vector<T,\
    \ 3>& p) {\n    const auto& [p1, p2] = object;\n    static_assert(std::is_floating_point_v<T>,\
    \ \"projection: T must be a floating point type\");\n    assert(p1 != p2 && \"\
    projection: degenerate line\");\n    Vector<T, 3> d = p2 - p1;\n    return p1\
    \ + d * (dot(p - p1, d) / d.squared_norm());\n}\n\n/**\n * @brief \u70B9 p \u3068\
    \u76F4\u7DDA p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\
    \u308B)\n */\ntemplate <typename T>\ndouble distance_point_line(const Line<T,\
    \ 3>& object, const Vector<T, 3>& p) {\n    const auto& [p1, p2] = object;\n \
    \   using namespace internal_predicates;\n    assert(p1 != p2 && \"distance_point_line:\
    \ degenerate line\");\n    return norm(cross(widen(p2) - widen(p1), widen(p) -\
    \ widen(p1))) / norm(p2 - p1);\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\
    \u7DDA q1q2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\
    )\u3002p1 != p2 \u304B\u3064 q1 != q2 \u3067\u3042\u308B\u3053\u3068\n */\ntemplate\
    \ <typename T>\ndouble distance_lines(const Line<T, 3>& first, const Line<T, 3>&\
    \ second) {\n    const auto& [p1, p2] = first;\n    const auto& [q1, q2] = second;\n\
    \    using namespace internal_predicates;\n    assert(p1 != p2 && q1 != q2 &&\
    \ \"distance_lines: degenerate line\");\n    const auto n = cross(widen(p2) -\
    \ widen(p1), widen(q2) - widen(q1));\n    // \u5E73\u884C\u306A\u3089\u3001\u4E00\
    \u65B9\u306E\u76F4\u7DDA\u4E0A\u306E\u70B9\u3068\u3082\u3046\u4E00\u65B9\u306E\
    \u76F4\u7DDA\u306E\u8DDD\u96E2\n    if (n == decltype(n)()) return distance_point_line(Line(p1,\
    \ p2), q1);\n    return std::abs(static_cast<double>(dot(n, widen(q1) - widen(p1))))\
    \ / norm(n);\n}\n#line 15 \"src/geometry/plane.hpp\"\n\n/**\n * @brief \u4E00\u76F4\
    \u7DDA\u4E0A\u306B\u306A\u3044 3 \u70B9\u3067\u8868\u3059\u5E73\u9762\u3002\u7B49\
    \u5024\u6BD4\u8F03\u306F\u70B9\u306E\u9078\u3073\u65B9\u30FB\u9806\u5E8F\u306B\
    \u3088\u3089\u305A\u540C\u3058\u5E73\u9762\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \n * @tparam T \u5EA7\u6A19\u306E\u578B\u3002\u7701\u7565\u3057\u305F\u3089 long\
    \ long\n */\ntemplate <typename T = long long>\nstruct Plane {\n    Vector<T,\
    \ 3> p1, p2, p3;\n\n   private:\n    constexpr void assert_valid() const {\n \
    \       using internal_predicates::widen;\n        const auto n = cross(widen(p2)\
    \ - widen(p1), widen(p3) - widen(p1));\n        assert((n[0] != 0 || n[1] != 0\
    \ || n[2] != 0) && \"Plane: collinear points\");\n    }\n\n   public:\n    constexpr\
    \ Plane(const Vector<T, 3>& p1, const Vector<T, 3>& p2, const Vector<T, 3>& p3)\
    \ : p1(p1), p2(p2), p3(p3) {\n        assert_valid();\n    }\n    /** @brief \u70B9\
    \ p \u304C\u5E73\u9762\u4E0A\u306B\u3042\u308B\u304B\u3002\u6D6E\u52D5\u5C0F\u6570\
    \u70B9\u578B\u3067\u306F\u8AA4\u5DEE\u3092\u8003\u616E\u3057\u306A\u3044 */\n\
    \    constexpr bool contains(const Vector<T, 3>& p) const {\n        assert_valid();\n\
    \        using internal_predicates::widen;\n        const auto a = widen(p1),\
    \ n = cross(widen(p2) - a, widen(p3) - a);\n        return dot(n, widen(p) - a)\
    \ == 0;\n    }\n    /** @brief \u76F4\u7DDA\u5168\u4F53\u304C\u5E73\u9762\u5185\
    \u306B\u3042\u308B\u304B\u3002\u5E73\u9762\u3068\u5E73\u884C\u3067\u3082\u96E2\
    \u308C\u3066\u3044\u308B\u76F4\u7DDA\u306F false */\n    constexpr bool contains(const\
    \ Line<T, 3>& line) const {\n        assert((line.p1[0] != line.p2[0] || line.p1[1]\
    \ != line.p2[1] || line.p1[2] != line.p2[2]) && \"Plane::contains: degenerate\
    \ line\");\n        return contains(line.p1) && contains(line.p2);\n    }\n  \
    \  constexpr bool operator==(const Plane& other) const {\n        assert_valid();\n\
    \        other.assert_valid();\n        using internal_predicates::widen;\n  \
    \      const auto a = widen(p1), n = cross(widen(p2) - a, widen(p3) - a);\n  \
    \      return dot(n, widen(other.p1) - a) == 0 && dot(n, widen(other.p2) - a)\
    \ == 0 && dot(n, widen(other.p3) - a) == 0;\n    }\n    constexpr bool operator!=(const\
    \ Plane& other) const { return !(*this == other); }\n};\n\ntemplate <typename\
    \ T>\nPlane(const Vector<T, 3>&, const Vector<T, 3>&, const Vector<T, 3>&) ->\
    \ Plane<T>;\n\n/** @brief \u76F4\u7DDA\u3068\u5E73\u9762\u304C\u5E73\u884C\u304B\
    \u3002\u76F4\u7DDA\u304C\u5E73\u9762\u306B\u542B\u307E\u308C\u308B\u5834\u5408\
    \u3082 true */\ntemplate <typename T>\nconstexpr bool is_parallel(const Line<T,\
    \ 3>& line, const Plane<T>& plane) {\n    using internal_predicates::widen;\n\
    \    const auto d = widen(line.p2) - widen(line.p1);\n    const auto a = widen(plane.p1),\
    \ n = cross(widen(plane.p2) - a, widen(plane.p3) - a);\n    assert((d[0] != 0\
    \ || d[1] != 0 || d[2] != 0) && \"is_parallel: degenerate line\");\n    assert((n[0]\
    \ != 0 || n[1] != 0 || n[2] != 0) && \"is_parallel: degenerate plane\");\n   \
    \ return dot(n, d) == 0;\n}\n\n/** @brief \u5E73\u9762\u3068\u76F4\u7DDA\u304C\
    \u5E73\u884C\u304B\u3002\u76F4\u7DDA\u304C\u5E73\u9762\u306B\u542B\u307E\u308C\
    \u308B\u5834\u5408\u3082 true */\ntemplate <typename T>\nconstexpr bool is_parallel(const\
    \ Plane<T>& plane, const Line<T, 3>& line) {\n    return is_parallel(line, plane);\n\
    }\n\n/** @brief \u5E73\u9762\u540C\u58EB\u304C\u5E73\u884C\u304B\u3002\u4E00\u81F4\
    \u3059\u308B\u5834\u5408\u3082 true */\ntemplate <typename T>\nconstexpr bool\
    \ is_parallel(const Plane<T>& first, const Plane<T>& second) {\n    using internal_predicates::widen;\n\
    \    const auto a = widen(first.p1), n = cross(widen(first.p2) - a, widen(first.p3)\
    \ - a);\n    const auto b = widen(second.p1), u = widen(second.p2) - b, v = widen(second.p3)\
    \ - b;\n    const auto m = cross(u, v);\n    assert((n[0] != 0 || n[1] != 0 ||\
    \ n[2] != 0) && \"is_parallel: degenerate plane\");\n    assert((m[0] != 0 ||\
    \ m[1] != 0 || m[2] != 0) && \"is_parallel: degenerate plane\");\n    // \u6CD5\
    \u7DDA\u540C\u58EB\u306E\u5916\u7A4D (\u5EA7\u6A19\u306E\u5DEE\u306E 4 \u4E57\
    ) \u3092\u907F\u3051\u30013 \u4E57\u307E\u3067\u306E\u8A08\u7B97\u3067\u5224\u5B9A\
    \u3059\u308B\u3002\n    return dot(n, u) == 0 && dot(n, v) == 0;\n}\n\n/**\n *\
    \ @brief \u70B9 p \u3068\u5E73\u9762 abc \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\
    \u3067\u3082\u4F7F\u3048\u308B)\u3002a, b, c \u306F\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u306A\u3044\u3053\u3068\n */\ntemplate <typename T>\ndouble distance_point_plane(const\
    \ Plane<T>& plane, const Vector<T, 3>& p) {\n    const auto& [a, b, c] = plane;\n\
    \    using namespace internal_predicates;\n    const auto wa = widen(a);\n   \
    \ const auto n = cross(widen(b) - wa, widen(c) - wa);\n    assert(n != decltype(n)()\
    \ && \"distance_point_plane: degenerate plane\");\n    return std::abs(static_cast<double>(dot(n,\
    \ widen(p) - wa))) / norm(n);\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u5E73\
    \u9762 abc \u306E\u4EA4\u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\
    \u3002p1 != p2 \u3067\u3001a, b, c \u306F\u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3044\
    \u3053\u3068\n * @return std::optional<Vector<T, 3>> \u4EA4\u70B9 (\u5E73\u884C\
    \ (\u5E73\u9762\u306B\u542B\u307E\u308C\u308B\u5834\u5408\u3082\u542B\u3080) \u306A\
    \u3089 std::nullopt)\n */\ntemplate <typename T>\nstd::optional<Vector<T, 3>>\
    \ line_plane_intersection(const Line<T, 3>& object, const Plane<T>& plane) {\n\
    \    const auto& [p1, p2] = object;\n    const auto& [a, b, c] = plane;\n    static_assert(std::is_floating_point_v<T>,\
    \ \"line_plane_intersection: T must be a floating point type\");\n    assert(p1\
    \ != p2 && \"line_plane_intersection: degenerate line\");\n    const Vector<T,\
    \ 3> n = cross(b - a, c - a), d = p2 - p1;\n    assert((n != Vector<T, 3>()) &&\
    \ \"line_plane_intersection: degenerate plane\");\n    const T den = dot(n, d);\n\
    \    if (den == 0) return std::nullopt;\n    // p1 + d t \u304C\u5E73\u9762\u4E0A\
    \u306B\u3042\u308B t\n    return p1 + d * (dot(n, a - p1) / den);\n}\n#line 10\
    \ \"test/unittest/geometry/plane.test.cpp\"\n\n#line 13 \"test/unittest/geometry/plane.test.cpp\"\
    \n#include <iostream>\n#include <random>\n#include <vector>\n\n#line 2 \"src/geometry/polygon.hpp\"\
    \n\n/**\n * @file polygon.hpp\n * @brief \u591A\u89D2\u5F62 (\u9762\u7A4D\u3001\
    \u91CD\u5FC3\u3001\u5185\u5916\u5224\u5B9A\u3001\u51F8\u6027\u3001\u51F8\u5305\
    \u3001\u51F8\u591A\u89D2\u5F62\u306E\u5207\u65AD)\n */\n\n#include <algorithm>\n\
    #line 14 \"src/geometry/polygon.hpp\"\n\n#line 16 \"src/geometry/polygon.hpp\"\
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
    \ be a floating point type\");\n    assert(p1 != p2 && \"convex_cut: degenerate\
    \ line\");\n    std::vector<Vector<T, 2>> res;\n    const int n = static_cast<int>(polygon.size());\n\
    \    for (int i = 0; i < n; i++) {\n        const Vector<T, 2>&a = polygon[i],\
    \ &b = polygon[i + 1 == n ? 0 : i + 1];\n        T ca = cross(p2 - p1, a - p1),\
    \ cb = cross(p2 - p1, b - p1);\n        if (ca >= 0) res.push_back(a);\n     \
    \   // \u8FBA ab \u304C\u76F4\u7DDA\u3092\u307E\u305F\u3050\u306A\u3089\u3001\u4EA4\
    \u70B9\u3092\u5165\u308C\u308B\n        if ((ca > 0 && cb < 0) || (ca < 0 && cb\
    \ > 0)) res.push_back(a + (b - a) * (ca / (ca - cb)));\n    }\n    return res;\n\
    }\n#line 2 \"src/geometry/triangle.hpp\"\n\n/**\n * @file triangle.hpp\n * @brief\
    \ 2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u4E09\u89D2\u5F62\n */\n\n#line 10\
    \ \"src/geometry/triangle.hpp\"\n\n#line 2 \"src/geometry/segment.hpp\"\n\n/**\n\
    \ * @file segment.hpp\n * @brief 2 \u6B21\u5143\u30FB3 \u6B21\u5143\u306E\u7DDA\
    \u5206 (\u4EA4\u5DEE\u5224\u5B9A\u3001\u5171\u6709\u70B9\u3001\u8DDD\u96E2)\n\
    \ */\n\n#line 13 \"src/geometry/segment.hpp\"\n\n#line 16 \"src/geometry/segment.hpp\"\
    \n\n/**\n * @brief 2 \u7AEF\u70B9\u3067\u8868\u3059\u7DDA\u5206\u3002\u9577\u3055\
    \ 0 \u3082\u8A31\u3059\u3002\u7B49\u5024\u6BD4\u8F03\u3067\u306F\u7AEF\u70B9\u306E\
    \u9806\u5E8F\u3092\u7121\u8996\u3059\u308B\n */\ntemplate <typename T = long long,\
    \ int Dim = 2>\nstruct Segment {\n    static_assert(Dim >= 2, \"dimension must\
    \ be at least 2\");\n    Vector<T, Dim> p1, p2;\n\n    constexpr Segment() = default;\n\
    \    constexpr Segment(const Vector<T, Dim>& p1, const Vector<T, Dim>& p2) : p1(p1),\
    \ p2(p2) {}\n    constexpr bool operator==(const Segment& other) const {\n   \
    \     return (p1 == other.p1 && p2 == other.p2) || (p1 == other.p2 && p2 == other.p1);\n\
    \    }\n    constexpr bool operator!=(const Segment& other) const { return !(*this\
    \ == other); }\n};\n\ntemplate <typename T, int Dim>\nSegment(const Vector<T,\
    \ Dim>&, const Vector<T, Dim>&) -> Segment<T, Dim>;\n\n/**\n * @brief \u7DDA\u5206\
    \u306E\u4EA4\u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\
    \u308B\u3002\u5916\u7A4D\u3092\u8A08\u7B97\u3059\u308B\u305F\u3081\u3001\u5EA7\
    \u6A19\u306E\u7D76\u5BFE\u5024\u306E2\u4E57\u306E\u6570\u500D\u304CT\u306B\u53CE\
    \u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n *\n * @param first 1 \u672C\u76EE\
    \u306E\u7DDA\u5206\n * @param second 2 \u672C\u76EE\u306E\u7DDA\u5206\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @return bool \u5171\u6709\u70B9\u3092\u6301\u3064\
    \u304B\n */\ntemplate <typename T>\nconstexpr bool segments_intersect(const Segment<T>&\
    \ first, const Segment<T>& second) {\n    const auto& [p1, p2] = first;\n    const\
    \ auto& [q1, q2] = second;\n    assert(p1 != p2 && q1 != q2 && \"segments_intersect:\
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
    \ \u3092\u4F7F\u3046\n *\n * @param first 1 \u672C\u76EE\u306E\u7DDA\u5206\n *\
    \ @param second 2 \u672C\u76EE\u306E\u7DDA\u5206\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\n * @return std::optional<Vector<T, 2>> \u5171\u6709\u70B9\u306E1\u4F8B\
    \ (\u5171\u6709\u70B9\u304C\u306A\u3051\u308C\u3070 std::nullopt)\n */\ntemplate\
    \ <typename T>\nconstexpr std::optional<Vector<T, 2>> segment_intersection(const\
    \ Segment<T>& first, const Segment<T>& second) {\n    const auto& [p1, p2] = first;\n\
    \    const auto& [q1, q2] = second;\n    static_assert(std::is_floating_point_v<T>,\
    \ \"segment_intersection: T must be a floating point type (use segments_intersect\
    \ for integers)\");\n    if (!segments_intersect(first, second)) return std::nullopt;\n\
    \    if (cross(p2 - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n   \
    \     // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \n        if (dot(q1 - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2,\
    \ q2 - p2) <= 0) return p2;\n        return q1;\n    }\n    T area = cross(p2\
    \ - p1, q2 - q1);          // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\
    \u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2\
    \ - q1, p1 - q1);  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D\n    return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief\
    \ \u70B9 p \u3068\u7DDA\u5206 p1p2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\u3067\
    \u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename T>\ndouble distance_point_segment(const\
    \ Segment<T>& object, const Vector<T, 2>& p) {\n    const auto& [p1, p2] = object;\n\
    \    if (p1 == p2) return (p - p1).abs();\n    // \u5782\u7DDA\u306E\u8DB3\u304C\
    \u7DDA\u5206\u306E\u5916\u306A\u3089\u3001\u8FD1\u3044\u65B9\u306E\u7AEF\u70B9\
    \u3068\u306E\u8DDD\u96E2\n    if (dot(p2 - p1, p - p1) < 0) return (p - p1).abs();\n\
    \    if (dot(p1 - p2, p - p2) < 0) return (p - p2).abs();\n    return distance_point_line(Line(p1,\
    \ p2), p);\n}\n/**\n * @brief \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\
    \u8DDD\u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate\
    \ <typename T>\ndouble distance_segments(const Segment<T>& first, const Segment<T>&\
    \ second) {\n    const auto& [p1, p2] = first;\n    const auto& [q1, q2] = second;\n\
    \    if (p1 != p2 && q1 != q2 && segments_intersect(first, second)) return 0;\n\
    \    return std::min({distance_point_segment(first, q1), distance_point_segment(first,\
    \ q2),\n                     distance_point_segment(second, p1), distance_point_segment(second,\
    \ p2)});\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206 p1p2 \u306E\u8DDD\u96E2\
    \ (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_segment(const Segment<T, 3>& object, const Vector<T,\
    \ 3>& p) {\n    const auto& [p1, p2] = object;\n    using namespace internal_predicates;\n\
    \    if (p1 == p2) return norm(p - p1);\n    // \u5782\u7DDA\u306E\u8DB3\u304C\
    \u7DDA\u5206\u306E\u5916\u306A\u3089\u3001\u8FD1\u3044\u65B9\u306E\u7AEF\u70B9\
    \u3068\u306E\u8DDD\u96E2\n    if (dot(widen(p2) - widen(p1), widen(p) - widen(p1))\
    \ < 0) return norm(p - p1);\n    if (dot(widen(p1) - widen(p2), widen(p) - widen(p2))\
    \ < 0) return norm(p - p2);\n    return distance_point_line(Line(p1, p2), p);\n\
    }\n/**\n * @brief \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\u96E2\
    \ (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_segments(const Segment<T, 3>& first, const Segment<T, 3>&\
    \ second) {\n    const auto& [p1, p2] = first;\n    const auto& [q1, q2] = second;\n\
    \    double res = std::min({distance_point_segment(first, q1), distance_point_segment(first,\
    \ q2),\n                           distance_point_segment(second, p1), distance_point_segment(second,\
    \ p2)});\n    if (p1 == p2 || q1 == q2) return res;\n    // \u8DDD\u96E2\u306E\
    \ 2 \u4E57\u306F (s, t) \u2208 [0, 1]^2 \u3067\u51F8\u306A\u306E\u3067\u3001\u6700\
    \u5C0F\u306F\u5185\u90E8\u306E\u505C\u7559\u70B9\u304B\u5883\u754C (\u7AEF\u70B9\
    \u3068\u7DDA\u5206\u306E\u8DDD\u96E2) \u306B\u3042\u308B\n    using L = long double;\n\
    \    auto to = [](const Vector<T, 3>& v) { return Vector<L, 3>(v[0], v[1], v[2]);\
    \ };\n    const Vector<L, 3> d = to(p2) - to(p1), e = to(q2) - to(q1), r = to(p1)\
    \ - to(q1);\n    const L a = dot(d, d), b = dot(d, e), c = dot(e, e), f = dot(d,\
    \ r), g = dot(e, r);\n    const L den = a * c - b * b;\n    if (den > 0) {\n \
    \       // p1 + d s \u3068 q1 + e t \u304C\u6700\u3082\u8FD1\u3044 s, t\n    \
    \    const L s = (b * g - c * f) / den, t = (a * g - b * f) / den;\n        if\
    \ (0 <= s && s <= 1 && 0 <= t && t <= 1) res = std::min(res, static_cast<double>((r\
    \ + d * s - e * t).abs()));\n    }\n    return res;\n}\n#line 14 \"src/geometry/triangle.hpp\"\
    \n\n/**\n * @brief \u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3044 3 \u9802\u70B9\u3067\
    \u8868\u3059\u4E09\u89D2\u5F62\u3002\u7B49\u5024\u6BD4\u8F03\u3067\u306F\u9802\
    \u70B9\u306E\u9806\u5E8F\u3092\u7121\u8996\u3059\u308B\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\u3002\u7701\u7565\u3057\u305F\u3089 long long\n * @tparam Dim \u6B21\
    \u5143 (2 \u307E\u305F\u306F 3)\u3002\u7701\u7565\u3057\u305F\u3089 2\n */\ntemplate\
    \ <typename T = long long, int Dim = 2>\nstruct Triangle {\n    static_assert(Dim\
    \ == 2 || Dim == 3, \"Triangle: dimension must be 2 or 3\");\n    Vector<T, Dim>\
    \ p1, p2, p3;\n\n   private:\n    constexpr void assert_valid() const {\n    \
    \    using internal_predicates::widen;\n        const auto a = widen(p1), u =\
    \ widen(p2) - a, v = widen(p3) - a;\n        if constexpr (Dim == 2) {\n     \
    \       assert(cross(u, v) != 0 && \"Triangle: collinear vertices\");\n      \
    \  } else {\n            const auto n = cross(u, v);\n            assert((n[0]\
    \ != 0 || n[1] != 0 || n[2] != 0) && \"Triangle: collinear vertices\");\n    \
    \    }\n    }\n\n   public:\n    constexpr Triangle(const Vector<T, Dim>& p1,\
    \ const Vector<T, Dim>& p2, const Vector<T, Dim>& p3) : p1(p1), p2(p2), p3(p3)\
    \ {\n        assert_valid();\n    }\n    constexpr bool operator==(const Triangle&\
    \ other) const {\n        assert_valid();\n        other.assert_valid();\n   \
    \     auto has_vertex = [&](const Vector<T, Dim>& p) { return p == other.p1 ||\
    \ p == other.p2 || p == other.p3; };\n        return has_vertex(p1) && has_vertex(p2)\
    \ && has_vertex(p3);\n    }\n    constexpr bool operator!=(const Triangle& other)\
    \ const { return !(*this == other); }\n};\n\ntemplate <typename T, int Dim>\n\
    Triangle(const Vector<T, Dim>&, const Vector<T, Dim>&, const Vector<T, Dim>&)\
    \ -> Triangle<T, Dim>;\n\n/**\n * @brief \u7DDA\u5206 p1p2 \u3068\u4E09\u89D2\u5F62\
    \ abc (\u5468\u3092\u542B\u3080) \u304C\u5171\u6709\u70B9\u3092\u6301\u3064\u304B\
    \ (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u6574\u6570\u5EA7\u6A19\
    \u306A\u3089\u6B63\u78BA)\n * \u4E09\u89D2\u5F62\u306F\u9000\u5316\u3057\u3066\
    \u3044\u306A\u3044 (a, b, c \u304C\u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3044)\
    \ \u3053\u3068\n */\ntemplate <typename T>\nbool segment_triangle_intersect(const\
    \ Segment<T, 3>& object, const Triangle<T, 3>& triangle) {\n    const auto& [p1,\
    \ p2] = object;\n    const auto& [a, b, c] = triangle;\n    using internal_predicates::orient;\n\
    \    using internal_predicates::widen;\n    const auto n = cross(widen(b) - widen(a),\
    \ widen(c) - widen(a));\n    assert(n != decltype(n)() && \"segment_triangle_intersect:\
    \ degenerate triangle\");\n    const int s1 = orient(a, b, c, p1), s2 = orient(a,\
    \ b, c, p2);\n    if (s1 * s2 > 0) return false;\n    if (s1 != 0 || s2 != 0)\
    \ {\n        // \u7DDA\u5206\u304C\u5E73\u9762\u3092\u8CAB\u304F\u304B\u7247\u65B9\
    \u306E\u7AEF\u70B9\u304C\u5E73\u9762\u4E0A\u306B\u3042\u308B\u3002\u76F4\u7DDA\
    \ p1p2 \u304B\u3089\u898B\u3066\u30013 \u8FBA\u304C\u540C\u3058\u5411\u304D\u306B\
    \u56DE\u3063\u3066\u3044\u308C\u3070\u4E09\u89D2\u5F62\u3092\u901A\u308B\n   \
    \     const int o1 = orient(p1, p2, a, b), o2 = orient(p1, p2, b, c), o3 = orient(p1,\
    \ p2, c, a);\n        return !((o1 < 0 || o2 < 0 || o3 < 0) && (o1 > 0 || o2 >\
    \ 0 || o3 > 0));\n    }\n    // \u540C\u3058\u5E73\u9762\u4E0A: \u6CD5\u7DDA\u306E\
    \u6210\u5206\u304C\u6700\u3082\u5927\u304D\u3044\u8EF8\u3092\u843D\u3068\u3057\
    \u3066 2 \u6B21\u5143\u3067\u5224\u5B9A\u3059\u308B\n    int k = 0;\n    for (int\
    \ i = 1; i < 3; i++) {\n        if ((n[i] < 0 ? -n[i] : n[i]) > (n[k] < 0 ? -n[k]\
    \ : n[k])) k = i;\n    }\n    const int i0 = k == 0 ? 1 : 0, i1 = k == 2 ? 1 :\
    \ 2;\n    auto flat = [&](const Vector<T, 3>& p) { return Vector<T, 2>(p[i0],\
    \ p[i1]); };\n    const Vector<T, 2> q1 = flat(p1), q2 = flat(p2), ta = flat(a),\
    \ tb = flat(b), tc = flat(c);\n    // \u7AEF\u70B9 q1 \u304C\u4E09\u89D2\u5F62\
    \u306E\u5185\u90E8 (\u5468\u3092\u542B\u3080) \u306B\u3042\u308B\u304B\u3001\u7DDA\
    \u5206\u304C\u8FBA\u3068\u4EA4\u308F\u308B (q1 \u304C\u5916\u3067 q2 \u304C\u5185\
    \u306A\u3089\u8FBA\u3068\u4EA4\u308F\u308B)\n    // 3 \u8FBA\u304B\u3089\u898B\
    \u305F\u5411\u304D\u304C\u6DF7\u3056\u3089\u306A\u3051\u308C\u3070\u5185\u90E8\
    \u3002\u8FBA\u306E\u5EF6\u9577\u4E0A (ccw \u304C \xB12) \u306E\u70B9\u306F\u3001\
    \u6B8B\u308A\u306E 2 \u8FBA\u3067\u5411\u304D\u304C\u9006\u306B\u306A\u308B\n\
    \    bool pos = false, neg = false;\n    for (int o : {ccw(ta, tb, q1), ccw(tb,\
    \ tc, q1), ccw(tc, ta, q1)}) pos |= o == 1, neg |= o == -1;\n    if (!(pos &&\
    \ neg)) return true;\n    if (q1 == q2) return false;\n    return segments_intersect(Segment(q1,\
    \ q2), Segment(ta, tb)) || segments_intersect(Segment(q1, q2), Segment(tb, tc))\
    \ || segments_intersect(Segment(q1, q2), Segment(tc, ta));\n}\n#line 20 \"test/unittest/geometry/plane.test.cpp\"\
    \n\nusing P = Vector<long long, 3>;\n\nconstexpr Plane horizontal(P(0, 0, 0),\
    \ P(1, 0, 0), P(0, 1, 0));\nstatic_assert(std::is_same_v<std::decay_t<decltype(horizontal)>,\
    \ Plane<long long>>);\nstatic_assert(horizontal == Plane(P(3, 4, 0), P(3, 5, 0),\
    \ P(4, 4, 0)));\nstatic_assert(horizontal != Plane(P(0, 0, 1), P(1, 0, 1), P(0,\
    \ 1, 1)));\nstatic_assert(horizontal != Plane(P(0, 0, 0), P(1, 0, 0), P(0, 0,\
    \ 1)));\nstatic_assert(is_parallel(horizontal, Plane(P(0, 0, 1), P(0, 1, 1), P(1,\
    \ 0, 1))));\nstatic_assert(!is_parallel(horizontal, Plane(P(0, 0, 0), P(1, 0,\
    \ 0), P(0, 0, 1))));\nstatic_assert(horizontal.contains(P(3, -4, 0)));\nstatic_assert(!horizontal.contains(P(3,\
    \ -4, 1)));\nusing D = Vector<double, 3>;\nusing L = long double;\n\nbool ok =\
    \ true;\nvoid check(bool cond, const char* what) {\n    if (!cond) {\n       \
    \ if (ok) std::cerr << \"failed: \" << what << std::endl;\n        ok = false;\n\
    \    }\n}\nbool near(double a, double b) { return std::abs(a - b) <= 1e-6 * std::max(1.0,\
    \ std::abs(b)); }\n\n// [lo, hi] \u3067\u51F8\u306A\u95A2\u6570\u306E\u6700\u5C0F\
    \u5024\nL minimize(const std::function<L(L)>& f, L lo, L hi) {\n    for (int i\
    \ = 0; i < 80; i++) {\n        L m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) /\
    \ 3;\n        if (f(m1) < f(m2))\n            hi = m2;\n        else\n       \
    \     lo = m1;\n    }\n    return f((lo + hi) / 2);\n}\nVector<L, 3> at(const\
    \ P& p, const P& q, L t) { return Vector<L, 3>(p[0] + (q[0] - p[0]) * t, p[1]\
    \ + (q[1] - p[1]) * t, p[2] + (q[2] - p[2]) * t); }\nL dist(const Vector<L, 3>&\
    \ a, const Vector<L, 3>& b) {\n    L s = 0;\n    for (int i = 0; i < 3; i++) s\
    \ += (a[i] - b[i]) * (a[i] - b[i]);\n    return std::sqrt(s);\n}\nVector<L, 3>\
    \ to_l(const P& p) { return Vector<L, 3>(p[0], p[1], p[2]); }\n\n// \u5E73\u9762\
    \u3092\u8CAB\u304F\u5834\u5408\u306E\u611A\u76F4\u306A\u5224\u5B9A: \u4EA4\u70B9\
    \u3092 p1 * den + (p2 - p1) * num (\u306E 1/den) \u3068\u3057\u3066\u6B63\u78BA\
    \u306B\u6C42\u3081\u308B\n__int128_t vol(const P& a, const P& b, const P& c, const\
    \ P& d) {\n    __int128_t m[3][3];\n    for (int i = 0; i < 3; i++) m[0][i] =\
    \ b[i] - a[i], m[1][i] = c[i] - a[i], m[2][i] = d[i] - a[i];\n    return m[0][0]\
    \ * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2]\
    \ * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);\n}\nbool naive_crossing(const\
    \ P& p1, const P& p2, const P& a, const P& b, const P& c) {\n    __int128_t v1\
    \ = vol(a, b, c, p1), v2 = vol(a, b, c, p2);\n    if ((v1 > 0 && v2 > 0) || (v1\
    \ < 0 && v2 < 0)) return false;\n    // \u4EA4\u70B9\u306F p1 + (p2 - p1) * v1\
    \ / (v1 - v2)\u3002den \u500D\u3057\u305F\u5EA7\u6A19\u3067\u4E09\u89D2\u5F62\u306E\
    \u5185\u5916\u3092\u8ABF\u3079\u308B\n    __int128_t num = v1, den = v1 - v2;\n\
    \    if (den < 0) num = -num, den = -den;\n    using W = Vector<__int128_t, 3>;\n\
    \    auto scale = [&](const P& p) { return W(p[0] * den, p[1] * den, p[2] * den);\
    \ };\n    W q(p1[0] * den + (p2[0] - p1[0]) * num, p1[1] * den + (p2[1] - p1[1])\
    \ * num, p1[2] * den + (p2[2] - p1[2]) * num);\n    W A = scale(a), B = scale(b),\
    \ C = scale(c);\n    W n = cross(B - A, C - A);\n    __int128_t x = dot(n, cross(B\
    \ - A, q - A)), y = dot(n, cross(C - B, q - B)), z = dot(n, cross(A - C, q - C));\n\
    \    return x >= 0 && y >= 0 && z >= 0;\n}\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    auto rnd = [&](int w) { return static_cast<long long>(rng() % (2 * w + 1))\
    \ - w; };\n    auto rp = [&](int w) { return P(rnd(w), rnd(w), rnd(w)); };\n\n\
    \    for (int rep = 0; rep < 400 && ok; rep++) {\n        const int w = rng()\
    \ % 2 ? 3 : 100;\n        P p1 = rp(w), p2 = rp(w), q1 = rp(w), q2 = rp(w), p\
    \ = rp(w);\n        if (rng() % 4 == 0) q2 = q1 + (p2 - p1) * (rng() % 3);  //\
    \ \u5E73\u884C\n        // \u70B9\u3068\u7DDA\u5206\u30FB\u76F4\u7DDA\n      \
    \  {\n            L e = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p));\
    \ }, 0, 1);\n            check(near(distance_point_segment(Segment(p1, p2), p),\
    \ e), \"distance_point_segment\");\n            if (p1 != p2) {\n            \
    \    L f = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p)); }, -1000,\
    \ 1000);\n                check(near(distance_point_line(Line(p1, p2), p), f),\
    \ \"distance_point_line\");\n            }\n        }\n        // \u7DDA\u5206\
    \u3069\u3046\u3057: s \u3092\u5916\u5074\u3001t \u3092\u5185\u5074\u3067\u4E09\
    \u5206\u63A2\u7D22\u3059\u308B (\u8DDD\u96E2\u306F (s, t) \u306B\u3064\u3044\u3066\
    \u51F8)\n        {\n            L e = minimize([&](L s) { return minimize([&](L\
    \ t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, 0, 1); }, 0, 1);\n      \
    \      check(near(distance_segments(Segment(p1, p2), Segment(q1, q2)), e), \"\
    distance_segments\");\n        }\n        // \u76F4\u7DDA\u3069\u3046\u3057\n\
    \        if (p1 != p2 && q1 != q2) {\n            L e = minimize([&](L s) { return\
    \ minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, -1000, 1000);\
    \ }, -1000, 1000);\n            check(near(distance_lines(Line(p1, p2), Line(q1,\
    \ q2)), e), \"distance_lines\");\n        }\n        // \u70B9\u3068\u5E73\u9762\
    \u3001\u76F4\u7DDA\u3068\u5E73\u9762\n        {\n            P a = rp(w), b =\
    \ rp(w), c = rp(w);\n            if (cross(b - a, c - a) == P()) continue;\n \
    \           const Plane plane(a, b, c);\n            const Plane same(a + (b -\
    \ a) * 2, a + (c - a) * 3, a - (b - a) - (c - a));\n            check(plane ==\
    \ same && same == plane && plane == Plane(c, b, a), \"Plane equality\");\n   \
    \         P normal = cross(b - a, c - a);\n            check(plane.contains(a)\
    \ && plane.contains(b) && plane.contains(c), \"Plane contains defining points\"\
    );\n            check(plane.contains(a + (b - a) * 3 - (c - a) * 2), \"Plane contains\
    \ affine combination\");\n            check(!plane.contains(a + normal) && !plane.contains(a\
    \ - normal), \"Plane excludes points off plane\");\n            check(plane.contains(Line(a,\
    \ b)) && plane.contains(Line(c, c + b - a)), \"Plane contains line\");\n     \
    \       check(plane.contains(Line(b, a)), \"Plane contains reversed line\");\n\
    \            check(!plane.contains(Line(a + normal, b + normal)), \"Plane excludes\
    \ parallel line\");\n            check(!plane.contains(Line(a, a + normal)) &&\
    \ !plane.contains(Line(a + normal, a)), \"Plane excludes crossing line\");\n \
    \           const Plane shifted(a + normal, b + normal, c + normal);\n       \
    \     check(is_parallel(plane, same) && is_parallel(plane, shifted) && is_parallel(shifted,\
    \ plane), \"parallel planes\");\n            check(is_parallel(Line(a, b), plane)\
    \ && is_parallel(plane, Line(c + normal, c + normal + b - a)), \"parallel line\
    \ and plane\");\n            check(!is_parallel(Line(a, a + normal), plane) &&\
    \ !is_parallel(plane, Line(a, a + normal)), \"line crossing plane\");\n      \
    \      check(is_parallel(Line(a, b), Line(c, c - (b - a) * 3)), \"parallel lines\"\
    );\n            check(!is_parallel(Line(a, b), Line(a, c)), \"nonparallel lines\"\
    );\n            check(plane != Plane(a + normal, b + normal, c + normal), \"Plane\
    \ parallel and distinct\");\n            L e = minimize([&](L s) { return minimize([&](L\
    \ t) {\n                                          Vector<L, 3> x = to_l(a) + (to_l(b)\
    \ - to_l(a)) * s + (to_l(c) - to_l(a)) * t;\n                                \
    \          return dist(x, to_l(p));\n                                      },\n\
    \                                                      -1000, 1000); },\n    \
    \                       -1000, 1000);\n            check(near(distance_point_plane(Plane(a,\
    \ b, c), p), e), \"distance_point_plane\");\n            if (p1 == p2) continue;\n\
    \            auto to_d = [](const P& v) { return D(v[0], v[1], v[2]); };\n   \
    \         auto x = line_plane_intersection(Line(to_d(p1), to_d(p2)), Plane(to_d(a),\
    \ to_d(b), to_d(c)));\n            const bool parallel = dot(cross(b - a, c -\
    \ a), p2 - p1) == 0;\n            check(is_parallel(Line(p1, p2), plane) == parallel,\
    \ \"is_parallel and intersection\");\n            check(x.has_value() != parallel,\
    \ \"line_plane_intersection (\u5E73\u884C)\");\n            if (x) {\n       \
    \         check(distance_point_plane(Plane(to_d(a), to_d(b), to_d(c)), *x) < 1e-6,\
    \ \"line_plane_intersection (\u5E73\u9762\u4E0A)\");\n                check(distance_point_line(Line(to_d(p1),\
    \ to_d(p2)), *x) < 1e-6, \"line_plane_intersection (\u76F4\u7DDA\u4E0A)\");\n\
    \            }\n        }\n    }\n\n    // \u7DDA\u5206\u3068\u4E09\u89D2\u5F62\
    : \u5E73\u9762\u3092\u8CAB\u304F (\u307E\u305F\u306F\u7AEF\u70B9\u304C\u5E73\u9762\
    \u4E0A\u306B\u3042\u308B) \u5834\u5408\n    for (int rep = 0; rep < 200000 &&\
    \ ok; rep++) {\n        const int w = rng() % 2 ? 2 : 5;\n        P p1 = rp(w),\
    \ p2 = rp(w), a = rp(w), b = rp(w), c = rp(w);\n        if (cross(b - a, c - a)\
    \ == P()) continue;\n        if (vol(a, b, c, p1) == 0 && vol(a, b, c, p2) ==\
    \ 0) continue;\n        check(segment_triangle_intersect(Segment(p1, p2), Triangle(a,\
    \ b, c)) == naive_crossing(p1, p2, a, b, c), \"segment_triangle_intersect (\u8CAB\
    \u304F)\");\n    }\n    // \u540C\u3058\u5E73\u9762\u4E0A\u306E\u5834\u5408: z\
    \ = 0 \u3067 2 \u6B21\u5143\u306E\u5224\u5B9A\u3092\u3057\u3066\u3001\u884C\u5217\
    \u5F0F \xB11 \u306E\u884C\u5217\u3068\u5E73\u884C\u79FB\u52D5\u3067\u7A7A\u9593\
    \u306B\u79FB\u3059\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n     \
    \   const int w = rng() % 2 ? 2 : 6;\n        using V2 = Vector<long long, 2>;\n\
    \        auto r2 = [&]() { return V2(rnd(w), rnd(w)); };\n        V2 p1 = r2(),\
    \ p2 = r2(), a = r2(), b = r2(), c = r2();\n        if (cross(b - a, c - a) ==\
    \ 0) continue;\n        std::vector<V2> tri = {a, b, c};\n        if (cross(b\
    \ - a, c - a) < 0) tri = {a, c, b};\n        bool expect = polygon_contains(tri,\
    \ p1) > 0 || polygon_contains(tri, p2) > 0;\n        if (p1 != p2) expect = expect\
    \ || segments_intersect(Segment(p1, p2), Segment(a, b)) || segments_intersect(Segment(p1,\
    \ p2), Segment(b, c)) || segments_intersect(Segment(p1, p2), Segment(c, a));\n\
    \        // \u57FA\u672C\u5909\u5F62 (\u3042\u308B\u884C\u306B\u5225\u306E\u884C\
    \u306E\u6574\u6570\u500D\u3092\u8DB3\u3059) \u3092\u4F55\u56DE\u304B\u639B\u3051\
    \u305F\u884C\u5217\n        long long m[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0,\
    \ 1}};\n        for (int k = 0; k < 4; k++) {\n            int i = rng() % 3,\
    \ j = (i + 1 + rng() % 2) % 3;\n            long long f = rnd(2);\n          \
    \  for (int col = 0; col < 3; col++) m[i][col] += f * m[j][col];\n        }\n\
    \        P shift = rp(10);\n        auto lift = [&](const V2& v) {\n         \
    \   P r;\n            for (int i = 0; i < 3; i++) r[i] = m[i][0] * v[0] + m[i][1]\
    \ * v[1] + shift[i];\n            return r;\n        };\n        check(segment_triangle_intersect(Segment(lift(p1),\
    \ lift(p2)), Triangle(lift(a), lift(b), lift(c))) == expect, \"segment_triangle_intersect\
    \ (\u540C\u3058\u5E73\u9762\u4E0A)\");\n    }\n\n    // 3 \u6B21\u5143\u306E\u578B\
    \u63A8\u8AD6\u3068\u3001\u540C\u3058\u76F4\u7DDA\u30FB\u7DDA\u5206\u306E\u5224\
    \u5B9A\u3002\u306D\u3058\u308C\u306E\u4F4D\u7F6E\u3082\u533A\u5225\u3059\u308B\
    \n    {\n        Line line(P(0, 0, 0), P(1, 2, 3));\n        static_assert(std::is_same_v<decltype(line),\
    \ Line<long long, 3>>);\n        Segment segment(P(0, 0, 0), P(1, 2, 3));\n  \
    \      static_assert(std::is_same_v<decltype(segment), Segment<long long, 3>>);\n\
    \        check(line == Line(P(3, 6, 9), P(-2, -4, -6)), \"Line equality\");\n\
    \        check(line != Line(P(0, 0, 1), P(1, 2, 4)), \"Line parallel and distinct\"\
    );\n        check(line != Line(P(0, 1, 0), P(1, 1, 0)), \"Line skew\");\n    \
    \    check(segment == Segment(P(1, 2, 3), P(0, 0, 0)), \"Segment equality\");\n\
    \        check(segment != Segment(P(0, 0, 0), P(2, 4, 6)), \"Segment distinct\"\
    );\n    }\n\n    // \u5EA7\u6A19\u304C 1e9 \u3067\u3082\u4F53\u7A4D\u306E\u8A08\
    \u7B97\u304C\u3042\u3075\u308C\u306A\u3044\n    const long long G = 1000000000;\n\
    \    const Plane large(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0));\n    check(large\
    \ == Plane(P(0, 0, 0), P(G, G, 0), P(-G, G, 0)), \"Plane equality (1e9)\");\n\
    \    check(large != Plane(P(-G, -G, G), P(G, -G, G), P(0, G, G)), \"Plane distinct\
    \ (1e9)\");\n    const Plane large_shifted(P(-G, -G, G), P(0, G, G), P(G, -G,\
    \ G));\n    check(is_parallel(large, large_shifted), \"parallel planes (1e9)\"\
    );\n    check(is_parallel(Line(P(-G, G, G), P(G, G, G)), large), \"parallel line\
    \ and plane (1e9)\");\n    check(!is_parallel(Line(P(-G, -G, -G), P(G, G, G)),\
    \ large), \"nonparallel line and plane (1e9)\");\n    check(is_parallel(Line(P(-G,\
    \ -G, -G), P(G, G, G)), Line(P(G, G, G), P(0, 0, 0))), \"parallel lines (1e9)\"\
    );\n    check(near(distance_point_plane(large, P(G, G, G)), G), \"distance_point_plane\
    \ (1e9)\");\n    check(large.contains(P(G, G, 0)) && !large.contains(P(G, G, G)),\
    \ \"Plane contains point (1e9)\");\n    check(large.contains(Line(P(-G, G, 0),\
    \ P(G, G, 0))), \"Plane contains line (1e9)\");\n    check(!large.contains(Line(P(-G,\
    \ G, G), P(G, G, G))), \"Plane excludes line (1e9)\");\n    const Plane floating(D(0,\
    \ 0, 0.5), D(1, 0, 0.5), D(0, 1, 0.5));\n    static_assert(std::is_same_v<std::decay_t<decltype(floating)>,\
    \ Plane<double>>);\n    check(floating == Plane(D(2, 3, 0.5), D(3, 3, 0.5), D(2,\
    \ 4, 0.5)), \"Plane equality (double)\");\n    check(floating.contains(D(2, -3,\
    \ 0.5)) && !floating.contains(D(2, -3, 0.500001)), \"Plane contains point (double)\"\
    );\n    check(floating.contains(Line(D(1, 2, 0.5), D(3, 4, 0.5))), \"Plane contains\
    \ line (double)\");\n    check(!floating.contains(Line(D(1, 2, 1.5), D(3, 4, 1.5))),\
    \ \"Plane excludes line (double)\");\n    check(!line_plane_intersection(Line(D(0,\
    \ 0, 0.5), D(1, 0, 0.5)), floating), \"line contained in plane\");\n    check(!line_plane_intersection(Line(D(0,\
    \ 0, 1.5), D(1, 0, 1.5)), floating), \"line parallel to plane\");\n    check(is_parallel(floating,\
    \ floating) && is_parallel(Line(D(0, 0, 1.5), D(1, 0, 1.5)), floating), \"parallel\
    \ (double)\");\n    check(!is_parallel(floating, Line(D(0, 0, 0), D(0, 0, 1))),\
    \ \"nonparallel (double)\");\n    check(segment_triangle_intersect(Segment(P(0,\
    \ 0, -G), P(0, 0, G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), \"segment_triangle_intersect\
    \ (1e9)\");\n    check(!segment_triangle_intersect(Segment(P(G, G, -G), P(G, G,\
    \ G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), \"segment_triangle_intersect\
    \ (1e9, \u5916)\");\n    check(near(distance_point_line(Line(P(-G, -G, -G), P(G,\
    \ G, G)), P(G, -G, 0)), std::sqrt(2.0) * G), \"distance_point_line (1e9)\");\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// 3 \u6B21\u5143\u306E\u76F4\u7DDA\u30FB\u7DDA\u5206\u30FB\u5E73\u9762\u30FB\
    \u4E09\u89D2\u5F62\u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u6BD4\u3079\u308B\n// \u8DDD\u96E2\u306F\u3001\u7DDA\u5206\u3084\u5E73\u9762\u306E\
    \u30D1\u30E9\u30E1\u30FC\u30BF\u306B\u3064\u3044\u3066\u51F8\u306A\u306E\u3067\
    \u3001\u4E09\u5206\u63A2\u7D22\u3067\u6700\u5C0F\u5316\u3057\u305F\u3082\u306E\
    \u3068\u6BD4\u3079\u308B\n// segment_triangle_intersect \u306F\u3001\u5E73\u9762\
    \u3092\u8CAB\u304F\u5834\u5408\u306F\u4EA4\u70B9\u3092\u6709\u7406\u6570\u3067\
    \u6B63\u78BA\u306B\u6C42\u3081\u3066\u4E09\u89D2\u5F62\u306E\u5185\u5916\u3092\
    \u8ABF\u3079\u305F\u3082\u306E\u3068\u3001\n// \u540C\u3058\u5E73\u9762\u4E0A\u306E\
    \u5834\u5408\u306F z = 0 \u306E\u5E73\u9762\u3067 2 \u6B21\u5143\u306E\u5224\u5B9A\
    \u3092\u3057\u3066\u304B\u3089\u3001\u884C\u5217\u5F0F \xB11 \u306E\u6574\u6570\
    \u306E\u884C\u5217\u3067\u7A7A\u9593\u306B\u79FB\u3057\u305F\u3082\u306E\u3068\
    \u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u6210\u308A\u7ACB\u3063\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../../src/geometry/plane.hpp\"\n\n#include\
    \ <cmath>\n#include <functional>\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\n#include \"../../../src/geometry/polygon.hpp\"\n#include \"../../../src/geometry/triangle.hpp\"\
    \n#include \"../../../src/geometry/vector.hpp\"\n\nusing P = Vector<long long,\
    \ 3>;\n\nconstexpr Plane horizontal(P(0, 0, 0), P(1, 0, 0), P(0, 1, 0));\nstatic_assert(std::is_same_v<std::decay_t<decltype(horizontal)>,\
    \ Plane<long long>>);\nstatic_assert(horizontal == Plane(P(3, 4, 0), P(3, 5, 0),\
    \ P(4, 4, 0)));\nstatic_assert(horizontal != Plane(P(0, 0, 1), P(1, 0, 1), P(0,\
    \ 1, 1)));\nstatic_assert(horizontal != Plane(P(0, 0, 0), P(1, 0, 0), P(0, 0,\
    \ 1)));\nstatic_assert(is_parallel(horizontal, Plane(P(0, 0, 1), P(0, 1, 1), P(1,\
    \ 0, 1))));\nstatic_assert(!is_parallel(horizontal, Plane(P(0, 0, 0), P(1, 0,\
    \ 0), P(0, 0, 1))));\nstatic_assert(horizontal.contains(P(3, -4, 0)));\nstatic_assert(!horizontal.contains(P(3,\
    \ -4, 1)));\nusing D = Vector<double, 3>;\nusing L = long double;\n\nbool ok =\
    \ true;\nvoid check(bool cond, const char* what) {\n    if (!cond) {\n       \
    \ if (ok) std::cerr << \"failed: \" << what << std::endl;\n        ok = false;\n\
    \    }\n}\nbool near(double a, double b) { return std::abs(a - b) <= 1e-6 * std::max(1.0,\
    \ std::abs(b)); }\n\n// [lo, hi] \u3067\u51F8\u306A\u95A2\u6570\u306E\u6700\u5C0F\
    \u5024\nL minimize(const std::function<L(L)>& f, L lo, L hi) {\n    for (int i\
    \ = 0; i < 80; i++) {\n        L m1 = (2 * lo + hi) / 3, m2 = (lo + 2 * hi) /\
    \ 3;\n        if (f(m1) < f(m2))\n            hi = m2;\n        else\n       \
    \     lo = m1;\n    }\n    return f((lo + hi) / 2);\n}\nVector<L, 3> at(const\
    \ P& p, const P& q, L t) { return Vector<L, 3>(p[0] + (q[0] - p[0]) * t, p[1]\
    \ + (q[1] - p[1]) * t, p[2] + (q[2] - p[2]) * t); }\nL dist(const Vector<L, 3>&\
    \ a, const Vector<L, 3>& b) {\n    L s = 0;\n    for (int i = 0; i < 3; i++) s\
    \ += (a[i] - b[i]) * (a[i] - b[i]);\n    return std::sqrt(s);\n}\nVector<L, 3>\
    \ to_l(const P& p) { return Vector<L, 3>(p[0], p[1], p[2]); }\n\n// \u5E73\u9762\
    \u3092\u8CAB\u304F\u5834\u5408\u306E\u611A\u76F4\u306A\u5224\u5B9A: \u4EA4\u70B9\
    \u3092 p1 * den + (p2 - p1) * num (\u306E 1/den) \u3068\u3057\u3066\u6B63\u78BA\
    \u306B\u6C42\u3081\u308B\n__int128_t vol(const P& a, const P& b, const P& c, const\
    \ P& d) {\n    __int128_t m[3][3];\n    for (int i = 0; i < 3; i++) m[0][i] =\
    \ b[i] - a[i], m[1][i] = c[i] - a[i], m[2][i] = d[i] - a[i];\n    return m[0][0]\
    \ * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2]\
    \ * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);\n}\nbool naive_crossing(const\
    \ P& p1, const P& p2, const P& a, const P& b, const P& c) {\n    __int128_t v1\
    \ = vol(a, b, c, p1), v2 = vol(a, b, c, p2);\n    if ((v1 > 0 && v2 > 0) || (v1\
    \ < 0 && v2 < 0)) return false;\n    // \u4EA4\u70B9\u306F p1 + (p2 - p1) * v1\
    \ / (v1 - v2)\u3002den \u500D\u3057\u305F\u5EA7\u6A19\u3067\u4E09\u89D2\u5F62\u306E\
    \u5185\u5916\u3092\u8ABF\u3079\u308B\n    __int128_t num = v1, den = v1 - v2;\n\
    \    if (den < 0) num = -num, den = -den;\n    using W = Vector<__int128_t, 3>;\n\
    \    auto scale = [&](const P& p) { return W(p[0] * den, p[1] * den, p[2] * den);\
    \ };\n    W q(p1[0] * den + (p2[0] - p1[0]) * num, p1[1] * den + (p2[1] - p1[1])\
    \ * num, p1[2] * den + (p2[2] - p1[2]) * num);\n    W A = scale(a), B = scale(b),\
    \ C = scale(c);\n    W n = cross(B - A, C - A);\n    __int128_t x = dot(n, cross(B\
    \ - A, q - A)), y = dot(n, cross(C - B, q - B)), z = dot(n, cross(A - C, q - C));\n\
    \    return x >= 0 && y >= 0 && z >= 0;\n}\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    auto rnd = [&](int w) { return static_cast<long long>(rng() % (2 * w + 1))\
    \ - w; };\n    auto rp = [&](int w) { return P(rnd(w), rnd(w), rnd(w)); };\n\n\
    \    for (int rep = 0; rep < 400 && ok; rep++) {\n        const int w = rng()\
    \ % 2 ? 3 : 100;\n        P p1 = rp(w), p2 = rp(w), q1 = rp(w), q2 = rp(w), p\
    \ = rp(w);\n        if (rng() % 4 == 0) q2 = q1 + (p2 - p1) * (rng() % 3);  //\
    \ \u5E73\u884C\n        // \u70B9\u3068\u7DDA\u5206\u30FB\u76F4\u7DDA\n      \
    \  {\n            L e = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p));\
    \ }, 0, 1);\n            check(near(distance_point_segment(Segment(p1, p2), p),\
    \ e), \"distance_point_segment\");\n            if (p1 != p2) {\n            \
    \    L f = minimize([&](L t) { return dist(at(p1, p2, t), to_l(p)); }, -1000,\
    \ 1000);\n                check(near(distance_point_line(Line(p1, p2), p), f),\
    \ \"distance_point_line\");\n            }\n        }\n        // \u7DDA\u5206\
    \u3069\u3046\u3057: s \u3092\u5916\u5074\u3001t \u3092\u5185\u5074\u3067\u4E09\
    \u5206\u63A2\u7D22\u3059\u308B (\u8DDD\u96E2\u306F (s, t) \u306B\u3064\u3044\u3066\
    \u51F8)\n        {\n            L e = minimize([&](L s) { return minimize([&](L\
    \ t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, 0, 1); }, 0, 1);\n      \
    \      check(near(distance_segments(Segment(p1, p2), Segment(q1, q2)), e), \"\
    distance_segments\");\n        }\n        // \u76F4\u7DDA\u3069\u3046\u3057\n\
    \        if (p1 != p2 && q1 != q2) {\n            L e = minimize([&](L s) { return\
    \ minimize([&](L t) { return dist(at(p1, p2, s), at(q1, q2, t)); }, -1000, 1000);\
    \ }, -1000, 1000);\n            check(near(distance_lines(Line(p1, p2), Line(q1,\
    \ q2)), e), \"distance_lines\");\n        }\n        // \u70B9\u3068\u5E73\u9762\
    \u3001\u76F4\u7DDA\u3068\u5E73\u9762\n        {\n            P a = rp(w), b =\
    \ rp(w), c = rp(w);\n            if (cross(b - a, c - a) == P()) continue;\n \
    \           const Plane plane(a, b, c);\n            const Plane same(a + (b -\
    \ a) * 2, a + (c - a) * 3, a - (b - a) - (c - a));\n            check(plane ==\
    \ same && same == plane && plane == Plane(c, b, a), \"Plane equality\");\n   \
    \         P normal = cross(b - a, c - a);\n            check(plane.contains(a)\
    \ && plane.contains(b) && plane.contains(c), \"Plane contains defining points\"\
    );\n            check(plane.contains(a + (b - a) * 3 - (c - a) * 2), \"Plane contains\
    \ affine combination\");\n            check(!plane.contains(a + normal) && !plane.contains(a\
    \ - normal), \"Plane excludes points off plane\");\n            check(plane.contains(Line(a,\
    \ b)) && plane.contains(Line(c, c + b - a)), \"Plane contains line\");\n     \
    \       check(plane.contains(Line(b, a)), \"Plane contains reversed line\");\n\
    \            check(!plane.contains(Line(a + normal, b + normal)), \"Plane excludes\
    \ parallel line\");\n            check(!plane.contains(Line(a, a + normal)) &&\
    \ !plane.contains(Line(a + normal, a)), \"Plane excludes crossing line\");\n \
    \           const Plane shifted(a + normal, b + normal, c + normal);\n       \
    \     check(is_parallel(plane, same) && is_parallel(plane, shifted) && is_parallel(shifted,\
    \ plane), \"parallel planes\");\n            check(is_parallel(Line(a, b), plane)\
    \ && is_parallel(plane, Line(c + normal, c + normal + b - a)), \"parallel line\
    \ and plane\");\n            check(!is_parallel(Line(a, a + normal), plane) &&\
    \ !is_parallel(plane, Line(a, a + normal)), \"line crossing plane\");\n      \
    \      check(is_parallel(Line(a, b), Line(c, c - (b - a) * 3)), \"parallel lines\"\
    );\n            check(!is_parallel(Line(a, b), Line(a, c)), \"nonparallel lines\"\
    );\n            check(plane != Plane(a + normal, b + normal, c + normal), \"Plane\
    \ parallel and distinct\");\n            L e = minimize([&](L s) { return minimize([&](L\
    \ t) {\n                                          Vector<L, 3> x = to_l(a) + (to_l(b)\
    \ - to_l(a)) * s + (to_l(c) - to_l(a)) * t;\n                                \
    \          return dist(x, to_l(p));\n                                      },\n\
    \                                                      -1000, 1000); },\n    \
    \                       -1000, 1000);\n            check(near(distance_point_plane(Plane(a,\
    \ b, c), p), e), \"distance_point_plane\");\n            if (p1 == p2) continue;\n\
    \            auto to_d = [](const P& v) { return D(v[0], v[1], v[2]); };\n   \
    \         auto x = line_plane_intersection(Line(to_d(p1), to_d(p2)), Plane(to_d(a),\
    \ to_d(b), to_d(c)));\n            const bool parallel = dot(cross(b - a, c -\
    \ a), p2 - p1) == 0;\n            check(is_parallel(Line(p1, p2), plane) == parallel,\
    \ \"is_parallel and intersection\");\n            check(x.has_value() != parallel,\
    \ \"line_plane_intersection (\u5E73\u884C)\");\n            if (x) {\n       \
    \         check(distance_point_plane(Plane(to_d(a), to_d(b), to_d(c)), *x) < 1e-6,\
    \ \"line_plane_intersection (\u5E73\u9762\u4E0A)\");\n                check(distance_point_line(Line(to_d(p1),\
    \ to_d(p2)), *x) < 1e-6, \"line_plane_intersection (\u76F4\u7DDA\u4E0A)\");\n\
    \            }\n        }\n    }\n\n    // \u7DDA\u5206\u3068\u4E09\u89D2\u5F62\
    : \u5E73\u9762\u3092\u8CAB\u304F (\u307E\u305F\u306F\u7AEF\u70B9\u304C\u5E73\u9762\
    \u4E0A\u306B\u3042\u308B) \u5834\u5408\n    for (int rep = 0; rep < 200000 &&\
    \ ok; rep++) {\n        const int w = rng() % 2 ? 2 : 5;\n        P p1 = rp(w),\
    \ p2 = rp(w), a = rp(w), b = rp(w), c = rp(w);\n        if (cross(b - a, c - a)\
    \ == P()) continue;\n        if (vol(a, b, c, p1) == 0 && vol(a, b, c, p2) ==\
    \ 0) continue;\n        check(segment_triangle_intersect(Segment(p1, p2), Triangle(a,\
    \ b, c)) == naive_crossing(p1, p2, a, b, c), \"segment_triangle_intersect (\u8CAB\
    \u304F)\");\n    }\n    // \u540C\u3058\u5E73\u9762\u4E0A\u306E\u5834\u5408: z\
    \ = 0 \u3067 2 \u6B21\u5143\u306E\u5224\u5B9A\u3092\u3057\u3066\u3001\u884C\u5217\
    \u5F0F \xB11 \u306E\u884C\u5217\u3068\u5E73\u884C\u79FB\u52D5\u3067\u7A7A\u9593\
    \u306B\u79FB\u3059\n    for (int rep = 0; rep < 100000 && ok; rep++) {\n     \
    \   const int w = rng() % 2 ? 2 : 6;\n        using V2 = Vector<long long, 2>;\n\
    \        auto r2 = [&]() { return V2(rnd(w), rnd(w)); };\n        V2 p1 = r2(),\
    \ p2 = r2(), a = r2(), b = r2(), c = r2();\n        if (cross(b - a, c - a) ==\
    \ 0) continue;\n        std::vector<V2> tri = {a, b, c};\n        if (cross(b\
    \ - a, c - a) < 0) tri = {a, c, b};\n        bool expect = polygon_contains(tri,\
    \ p1) > 0 || polygon_contains(tri, p2) > 0;\n        if (p1 != p2) expect = expect\
    \ || segments_intersect(Segment(p1, p2), Segment(a, b)) || segments_intersect(Segment(p1,\
    \ p2), Segment(b, c)) || segments_intersect(Segment(p1, p2), Segment(c, a));\n\
    \        // \u57FA\u672C\u5909\u5F62 (\u3042\u308B\u884C\u306B\u5225\u306E\u884C\
    \u306E\u6574\u6570\u500D\u3092\u8DB3\u3059) \u3092\u4F55\u56DE\u304B\u639B\u3051\
    \u305F\u884C\u5217\n        long long m[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0,\
    \ 1}};\n        for (int k = 0; k < 4; k++) {\n            int i = rng() % 3,\
    \ j = (i + 1 + rng() % 2) % 3;\n            long long f = rnd(2);\n          \
    \  for (int col = 0; col < 3; col++) m[i][col] += f * m[j][col];\n        }\n\
    \        P shift = rp(10);\n        auto lift = [&](const V2& v) {\n         \
    \   P r;\n            for (int i = 0; i < 3; i++) r[i] = m[i][0] * v[0] + m[i][1]\
    \ * v[1] + shift[i];\n            return r;\n        };\n        check(segment_triangle_intersect(Segment(lift(p1),\
    \ lift(p2)), Triangle(lift(a), lift(b), lift(c))) == expect, \"segment_triangle_intersect\
    \ (\u540C\u3058\u5E73\u9762\u4E0A)\");\n    }\n\n    // 3 \u6B21\u5143\u306E\u578B\
    \u63A8\u8AD6\u3068\u3001\u540C\u3058\u76F4\u7DDA\u30FB\u7DDA\u5206\u306E\u5224\
    \u5B9A\u3002\u306D\u3058\u308C\u306E\u4F4D\u7F6E\u3082\u533A\u5225\u3059\u308B\
    \n    {\n        Line line(P(0, 0, 0), P(1, 2, 3));\n        static_assert(std::is_same_v<decltype(line),\
    \ Line<long long, 3>>);\n        Segment segment(P(0, 0, 0), P(1, 2, 3));\n  \
    \      static_assert(std::is_same_v<decltype(segment), Segment<long long, 3>>);\n\
    \        check(line == Line(P(3, 6, 9), P(-2, -4, -6)), \"Line equality\");\n\
    \        check(line != Line(P(0, 0, 1), P(1, 2, 4)), \"Line parallel and distinct\"\
    );\n        check(line != Line(P(0, 1, 0), P(1, 1, 0)), \"Line skew\");\n    \
    \    check(segment == Segment(P(1, 2, 3), P(0, 0, 0)), \"Segment equality\");\n\
    \        check(segment != Segment(P(0, 0, 0), P(2, 4, 6)), \"Segment distinct\"\
    );\n    }\n\n    // \u5EA7\u6A19\u304C 1e9 \u3067\u3082\u4F53\u7A4D\u306E\u8A08\
    \u7B97\u304C\u3042\u3075\u308C\u306A\u3044\n    const long long G = 1000000000;\n\
    \    const Plane large(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0));\n    check(large\
    \ == Plane(P(0, 0, 0), P(G, G, 0), P(-G, G, 0)), \"Plane equality (1e9)\");\n\
    \    check(large != Plane(P(-G, -G, G), P(G, -G, G), P(0, G, G)), \"Plane distinct\
    \ (1e9)\");\n    const Plane large_shifted(P(-G, -G, G), P(0, G, G), P(G, -G,\
    \ G));\n    check(is_parallel(large, large_shifted), \"parallel planes (1e9)\"\
    );\n    check(is_parallel(Line(P(-G, G, G), P(G, G, G)), large), \"parallel line\
    \ and plane (1e9)\");\n    check(!is_parallel(Line(P(-G, -G, -G), P(G, G, G)),\
    \ large), \"nonparallel line and plane (1e9)\");\n    check(is_parallel(Line(P(-G,\
    \ -G, -G), P(G, G, G)), Line(P(G, G, G), P(0, 0, 0))), \"parallel lines (1e9)\"\
    );\n    check(near(distance_point_plane(large, P(G, G, G)), G), \"distance_point_plane\
    \ (1e9)\");\n    check(large.contains(P(G, G, 0)) && !large.contains(P(G, G, G)),\
    \ \"Plane contains point (1e9)\");\n    check(large.contains(Line(P(-G, G, 0),\
    \ P(G, G, 0))), \"Plane contains line (1e9)\");\n    check(!large.contains(Line(P(-G,\
    \ G, G), P(G, G, G))), \"Plane excludes line (1e9)\");\n    const Plane floating(D(0,\
    \ 0, 0.5), D(1, 0, 0.5), D(0, 1, 0.5));\n    static_assert(std::is_same_v<std::decay_t<decltype(floating)>,\
    \ Plane<double>>);\n    check(floating == Plane(D(2, 3, 0.5), D(3, 3, 0.5), D(2,\
    \ 4, 0.5)), \"Plane equality (double)\");\n    check(floating.contains(D(2, -3,\
    \ 0.5)) && !floating.contains(D(2, -3, 0.500001)), \"Plane contains point (double)\"\
    );\n    check(floating.contains(Line(D(1, 2, 0.5), D(3, 4, 0.5))), \"Plane contains\
    \ line (double)\");\n    check(!floating.contains(Line(D(1, 2, 1.5), D(3, 4, 1.5))),\
    \ \"Plane excludes line (double)\");\n    check(!line_plane_intersection(Line(D(0,\
    \ 0, 0.5), D(1, 0, 0.5)), floating), \"line contained in plane\");\n    check(!line_plane_intersection(Line(D(0,\
    \ 0, 1.5), D(1, 0, 1.5)), floating), \"line parallel to plane\");\n    check(is_parallel(floating,\
    \ floating) && is_parallel(Line(D(0, 0, 1.5), D(1, 0, 1.5)), floating), \"parallel\
    \ (double)\");\n    check(!is_parallel(floating, Line(D(0, 0, 0), D(0, 0, 1))),\
    \ \"nonparallel (double)\");\n    check(segment_triangle_intersect(Segment(P(0,\
    \ 0, -G), P(0, 0, G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), \"segment_triangle_intersect\
    \ (1e9)\");\n    check(!segment_triangle_intersect(Segment(P(G, G, -G), P(G, G,\
    \ G)), Triangle(P(-G, -G, 0), P(G, -G, 0), P(0, G, 0))), \"segment_triangle_intersect\
    \ (1e9, \u5916)\");\n    check(near(distance_point_line(Line(P(-G, -G, -G), P(G,\
    \ G, G)), P(G, -G, 0)), std::sqrt(2.0) * G), \"distance_point_line (1e9)\");\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/geometry/plane.hpp
  - src/geometry/internal/predicates.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  - src/geometry/line.hpp
  - src/geometry/polygon.hpp
  - src/geometry/triangle.hpp
  - src/geometry/segment.hpp
  isVerificationFile: true
  path: test/unittest/geometry/plane.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 04:55:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/geometry/plane.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/geometry/plane.test.cpp
- /verify/test/unittest/geometry/plane.test.cpp.html
title: test/unittest/geometry/plane.test.cpp
---
