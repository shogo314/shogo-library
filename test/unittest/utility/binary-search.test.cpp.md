---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/functions.hpp
    title: "\u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/utility/binary-search.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
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
  bundledCode: "#line 1 \"test/unittest/utility/binary-search.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// binary-search.hpp \u306E\u6574\u6570\u7248\u3092\u3001\u578B\u306E\u5168\
    \u7BC4\u56F2\u3092\u542B\u3080\u5883\u754C\u3067\u691C\u8A3C\u3059\u308B\n// ok\
    \ < ng \u3068 ok > ng \u306E\u4E21\u65B9\u3067\u3001\u7B54\u3048\u30FBf \u306B\
    \u6E21\u3059\u5024\u304C ok \u3068 ng \u306E\u9593\u306B\u3042\u308B\u3053\u3068\
    \u30FBf \u306E\u547C\u3073\u51FA\u3057\u56DE\u6570\u3092\u78BA\u304B\u3081\u308B\
    \n// \u3042\u3075\u308C\u306A\u3044\u3053\u3068\u306F -fsanitize=undefined \u3067\
    \u3082\u78BA\u304B\u3081\u305F\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/utility/binary-search.hpp\"\n\n/**\n\
    \ * @file binary-search.hpp\n * @brief \u4E8C\u5206\u63A2\u7D22\n */\n\n#include\
    \ <cmath>\n#include <type_traits>\n\n#line 2 \"src/base/functions.hpp\"\n\n/**\n\
    \ * @file functions.hpp\n * @brief \u6C4E\u7528\u95A2\u6570 (chmin, chmax \u306A\
    \u3069)\n */\n\n#include <algorithm>\n#line 10 \"src/base/functions.hpp\"\n#include\
    \ <iterator>\n#include <limits>\n#include <numeric>\n#if __cplusplus >= 202002L\n\
    #include <ranges>\n#endif\n#line 17 \"src/base/functions.hpp\"\n#include <utility>\n\
    \ntemplate <typename T1, typename T2>\ninline constexpr bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr bool chmax(T1&\
    \ a, T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\n\ninline constexpr long long max(const long long& t1, const\
    \ long long& t2) {\n    return std::max<long long>(t1, t2);\n}\n\ninline constexpr\
    \ long long min(const long long& t1, const long long& t2) {\n    return std::min<long\
    \ long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\nusing std::lcm;\nusing\
    \ std::size;\n\n#if __cplusplus >= 202002L\nusing std::midpoint;\n#else\n// C++20\
    \ \u306E std::midpoint \u3068\u540C\u3058 (\u6574\u6570\u306F a \u306E\u5074\u306B\
    \u4E38\u3081\u3001\u3042\u3075\u308C\u306A\u3044)\ntemplate <typename T>\ninline\
    \ constexpr std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T, bool>,\
    \ T> midpoint(T a, T b) noexcept {\n    using U = std::make_unsigned_t<T>;\n \
    \   if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
    \ - static_cast<U>(a)) >> 1));\n    return static_cast<T>(a - static_cast<T>(static_cast<U>(static_cast<U>(a)\
    \ - static_cast<U>(b)) >> 1));\n}\ntemplate <typename T>\ninline constexpr std::enable_if_t<std::is_floating_point_v<T>,\
    \ T> midpoint(T a, T b) noexcept {\n    constexpr T lo = std::numeric_limits<T>::min()\
    \ * 2;\n    constexpr T hi = std::numeric_limits<T>::max() / 2;\n    const T abs_a\
    \ = a < 0 ? -a : a, abs_b = b < 0 ? -b : b;\n    if (abs_a <= hi && abs_b <= hi)\
    \ return (a + b) / 2;\n    if (abs_a < lo) return a + b / 2;\n    if (abs_b <\
    \ lo) return a / 2 + b;\n    return a / 2 + b / 2;\n}\ntemplate <typename T>\n\
    inline constexpr std::enable_if_t<std::is_object_v<T>, T*> midpoint(T* a, T* b)\
    \ noexcept {\n    return a + (b - a) / 2;\n}\n#endif\n\n/**\n * \u8981\u7D20\u6570\
    \u3092 long long \u3067\u8FD4\u3059 (std::ssize \u306E long long \u7248)\n * size()\
    \ \u3092\u6301\u3064\u578B\u306A\u3089\u3001begin() \u3068 end() \u3092\u6301\u305F\
    \u306A\u3044\u81EA\u4F5C\u306E\u578B\u306B\u3082\u4F7F\u3048\u308B\n */\n#if __cplusplus\
    \ >= 202002L\ntemplate <typename R>\n    requires requires(R& r) { std::ranges::size(r);\
    \ }\ninline constexpr long long len(R&& r) {\n    return static_cast<long long>(std::ranges::size(r));\n\
    }\n#else\ntemplate <typename C>\ninline constexpr auto len(const C& c) -> decltype(static_cast<long\
    \ long>(std::size(c))) {\n    return static_cast<long long>(std::size(c));\n}\n\
    #endif\n\ntemplate <typename T>\nconstexpr T extgcd(const T& a, const T& b, T&\
    \ x, T& y) {\n    T d = a;\n    if (b != 0) {\n        d = extgcd(b, a % b, y,\
    \ x);\n        y -= (a / b) * x;\n    } else {\n        x = 1;\n        y = 0;\n\
    \    }\n    return d;\n}\n\n/**\n * floor(a / b) (b != 0\u3001\u8CA0\u306E\u6570\
    \u3082\u53EF)\n */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> floordiv(T1 a, T2 b) {\n    return a / b - (a % b != 0 && (a < 0) != (b\
    \ < 0));\n}\n/**\n * ceil(a / b) (b != 0\u3001\u8CA0\u306E\u6570\u3082\u53EF)\n\
    \ */\ntemplate <typename T1, typename T2>\ninline constexpr std::common_type_t<T1,\
    \ T2> ceildiv(T1 a, T2 b) {\n    return a / b + (a % b != 0 && (a < 0) == (b <\
    \ 0));\n}\n/**\n * {floor(a / b), a - b * floor(a / b)} (b != 0\u3001\u8CA0\u306E\
    \u6570\u3082\u53EF)\n * \u4F59\u308A\u306F 0 \u307E\u305F\u306F b \u3068\u540C\
    \u3058\u7B26\u53F7\u306B\u306A\u308B\n */\ntemplate <typename T1, typename T2>\n\
    inline constexpr std::pair<std::common_type_t<T1, T2>, std::common_type_t<T1,\
    \ T2>> divmod(T1 a, T2 b) {\n    std::common_type_t<T1, T2> q = floordiv(a, b);\n\
    \    return {q, a - q * b};\n}\n\n/**\n * 0 <= x < a\n */\ninline constexpr bool\
    \ inrange(long long x, long long a) {\n    return 0 <= x && x < a;\n}\n/**\n *\
    \ a <= x < b\n */\ninline constexpr bool inrange(long long x, long long a, long\
    \ long b) {\n    return a <= x && x < b;\n}\n/**\n * 0 <= x < a and 0 <= y < b\n\
    \ */\ninline constexpr bool inrect(long long x, long long y, long long a, long\
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <functional>\n#line 11 \"src/utility/traits.hpp\"\n#include <set>\n#line\
    \ 14 \"src/utility/traits.hpp\"\n\nnamespace internal_traits {\nusing std::begin,\
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
    #line 13 \"src/utility/binary-search.hpp\"\n\n/**\n * f(ok) \u304C\u771F\u3001\
    f(ng) \u304C\u507D\u3068\u3057\u3066\u3001\u5883\u754C\u3067 f \u304C\u771F\u306B\
    \u306A\u308B\u5074\u306E\u5024\u3092\u8FD4\u3059\n * \u6574\u6570\u306A\u3089\
    \ ok \u3068 ng \u306E\u5DEE\u304C 1 \u306B\u306A\u308B\u307E\u3067\u3001\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u306A\u3089 100 \u56DE\u4E8C\u5206\u3059\u308B\n\
    \ */\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
    \ N>>and std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M& ok, const N& ng, F f) {\n  \
    \  using T = std::common_type_t<M, N>;\n    using U = std::make_unsigned_t<T>;\n\
    \    T _ok = ok, _ng = ng;\n    // \u5DEE\u306F\u7B26\u53F7\u306A\u3057\u3067\u6C42\
    \u3081\u308B\u3068\u3042\u3075\u308C\u306A\u3044 (LLONG_MIN \u3068 LLONG_MAX \u306E\
    \u5DEE\u3082 U \u306B\u53CE\u307E\u308B)\n    // \u4E2D\u70B9\u306F midpoint \u3067\
    \u6C42\u3081\u308B (\u3042\u3075\u308C\u305A\u3001ok \u306E\u5074\u306B\u4E38\u3081\
    \u308B)\n    while ((_ok < _ng ? static_cast<U>(static_cast<U>(_ng) - static_cast<U>(_ok))\
    \ : static_cast<U>(static_cast<U>(_ok) - static_cast<U>(_ng))) > 1) {\n      \
    \  T mid = midpoint(_ok, _ng);\n        if (f(mid)) {\n            _ok = mid;\n\
    \        } else {\n            _ng = mid;\n        }\n    }\n    return _ok;\n\
    }\n\ntemplate <typename M, typename N, class F, ENABLE_IF_T(!std::is_integral_v<std::common_type_t<M,\
    \ N>> && std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M& ok, const N& ng, F f) {\n  \
    \  std::common_type_t<M, N> _ok = ok, _ng = ng;\n    for (int i = 0; i < 100;\
    \ i++) {\n        std::common_type_t<M, N> mid = (_ok + _ng) / 2;\n        if\
    \ (f(mid)) {\n            _ok = mid;\n        } else {\n            _ng = mid;\n\
    \        }\n    }\n    return _ok;\n}\n#line 9 \"test/unittest/utility/binary-search.test.cpp\"\
    \n\n#include <iostream>\n#line 12 \"test/unittest/utility/binary-search.test.cpp\"\
    \n#include <random>\n\nbool ok = true;\n\nvoid check(bool cond, const char* what)\
    \ {\n    if (!cond) {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n\
    \        ok = false;\n    }\n}\n\n// lo <= t < hi \u3068\u3057\u3066\u3001f(x)\
    \ = x <= t (ok = lo, ng = hi) \u3068 f(x) = x > t (ok = hi, ng = lo) \u3092\u8ABF\
    \u3079\u308B\ntemplate <typename T>\nvoid test(T lo, T hi, T t, const char* what)\
    \ {\n    long long calls = 0;\n    bool inside = true;\n    T r1 = binary_search(lo,\
    \ hi, [&](T x) {\n        calls++;\n        if (!(lo < x && x < hi)) inside =\
    \ false;\n        return x <= t;\n    });\n    check(r1 == t, what);\n    check(inside\
    \ && calls <= std::numeric_limits<T>::digits + 1, what);\n    calls = 0;\n   \
    \ T r2 = binary_search(hi, lo, [&](T x) {\n        calls++;\n        if (!(lo\
    \ < x && x < hi)) inside = false;\n        return x > t;\n    });\n    check(r2\
    \ == t + 1, what);\n    check(inside && calls <= std::numeric_limits<T>::digits\
    \ + 1, what);\n}\n\n// \u578B\u306E\u4E21\u7AEF\u3068 0 \u306E\u4ED8\u8FD1\u3092\
    \u5883\u754C\u306B\u3057\u3066\u8ABF\u3079\u308B\ntemplate <typename T>\nvoid\
    \ test_extreme(const char* what) {\n    constexpr T mn = std::numeric_limits<T>::min(),\
    \ mx = std::numeric_limits<T>::max();\n    for (T t : {mn, static_cast<T>(mn +\
    \ 1), static_cast<T>(mn / 2), static_cast<T>(0), static_cast<T>(1), static_cast<T>(mx\
    \ / 2), static_cast<T>(mx - 2), static_cast<T>(mx - 1)}) {\n        test<T>(mn,\
    \ mx, t, what);\n    }\n    if (std::numeric_limits<T>::is_signed) {\n       \
    \ for (T t : {static_cast<T>(-2), static_cast<T>(-1)}) test<T>(mn, mx, t, what);\n\
    \        test<T>(mn, static_cast<T>(0), static_cast<T>(-1), what);\n        test<T>(static_cast<T>(-1),\
    \ mx, static_cast<T>(0), what);\n    }\n}\n\n// \u5DEE\u304C 1 \u306A\u3089 f\
    \ \u3092\u547C\u3070\u305A\u306B ok \u3092\u8FD4\u3059\u3002\u5DEE\u304C 2 \u306A\
    \u3089\u771F\u3093\u4E2D\u3092 1 \u56DE\u3060\u3051\u8ABF\u3079\u308B\ntemplate\
    \ <typename T>\nvoid test_small(T a, const char* what) {\n    long long calls\
    \ = 0;\n    check(binary_search(a, static_cast<T>(a + 1), [&](T) { return calls++,\
    \ false; }) == a && calls == 0, what);\n    check(binary_search(static_cast<T>(a\
    \ + 1), a, [&](T) { return calls++, false; }) == static_cast<T>(a + 1) && calls\
    \ == 0, what);\n    T m = static_cast<T>(a + 1), b = static_cast<T>(a + 2);\n\
    \    check(binary_search(a, b, [&](T x) { return calls++, x != m; }) == a && calls\
    \ == 1, what);\n    check(binary_search(a, b, [&](T x) { return calls++, x ==\
    \ m; }) == m && calls == 2, what);\n    check(binary_search(b, a, [&](T x) { return\
    \ calls++, x != m; }) == b && calls == 3, what);\n    check(binary_search(b, a,\
    \ [&](T x) { return calls++, x == m; }) == m && calls == 4, what);\n}\n\n// constexpr\
    \ \u3067\u4F7F\u3048\u308B\nstatic_assert(binary_search(0, 1000, [](long long\
    \ m) { return m * m <= 500; }) == 22);\nstatic_assert(binary_search(std::numeric_limits<long\
    \ long>::max(), std::numeric_limits<long long>::min(), [](long long x) { return\
    \ x >= 0; }) == 0);\n\nint main() {\n    // \u901A\u5E38\u306E\u5883\u754C\u63A2\
    \u7D22\n    check(binary_search(0, 1000, [](long long m) { return m * m <= 500;\
    \ }) == 22, \"sqrt(500)\");\n    check(binary_search(0, 1000000000, [](int x)\
    \ { return static_cast<long long>(x) * x <= 1000000000; }) == 31622, \"sqrt(1e9)\"\
    );\n    check(binary_search(1000, 0, [](long long m) { return m * m >= 500; })\
    \ == 23, \"ok > ng\");\n\n    // \u8CA0\u6570\u3092\u542B\u3080\u7BC4\u56F2\u3092\
    \u611A\u76F4\u3068\u6BD4\u3079\u308B\n    std::mt19937_64 rng(314);\n    for (int\
    \ rep = 0; rep < 10000; rep++) {\n        long long lo = static_cast<long long>(rng()\
    \ % 2001) - 1000;\n        long long hi = lo + static_cast<long long>(rng() %\
    \ 1000) + 1;\n        long long t = lo + static_cast<long long>(rng() % (hi -\
    \ lo));\n        test<long long>(lo, hi, t, \"\u8CA0\u6570\u3092\u542B\u3080 long\
    \ long\");\n        test<int>(static_cast<int>(lo), static_cast<int>(hi), static_cast<int>(t),\
    \ \"\u8CA0\u6570\u3092\u542B\u3080 int\");\n    }\n\n    // \u578B\u306E\u5168\
    \u7BC4\u56F2\n    test_extreme<int>(\"int \u306E\u5168\u7BC4\u56F2\");\n    test_extreme<long\
    \ long>(\"long long \u306E\u5168\u7BC4\u56F2 (LLONG_MIN, LLONG_MAX)\");\n    test_extreme<unsigned\
    \ long long>(\"unsigned long long \u306E\u5168\u7BC4\u56F2 (0, ULLONG_MAX)\");\n\
    \    test_extreme<unsigned int>(\"unsigned int \u306E\u5168\u7BC4\u56F2\");\n\
    \    test_extreme<short>(\"short \u306E\u5168\u7BC4\u56F2\");\n\n    // \u4E21\
    \u7AEF\u306E\u5DEE\u304C 1 \u307E\u305F\u306F 2\n    for (long long a : {std::numeric_limits<long\
    \ long>::min(), -2LL, -1LL, 0LL, std::numeric_limits<long long>::max() - 2}) test_small<long\
    \ long>(a, \"\u5DEE\u304C 1, 2 \u306E long long\");\n    for (int a : {std::numeric_limits<int>::min(),\
    \ -1, 0, std::numeric_limits<int>::max() - 2}) test_small<int>(a, \"\u5DEE\u304C\
    \ 1, 2 \u306E int\");\n    for (unsigned long long a : {0ULL, 1ULL, std::numeric_limits<unsigned\
    \ long long>::max() - 2}) test_small<unsigned long long>(a, \"\u5DEE\u304C 1,\
    \ 2 \u306E unsigned long long\");\n\n    // \u578B\u304C\u9055\u3046\u3068\u304D\
    \u306F common_type \u306B\u305D\u308D\u3048\u308B\n    check(binary_search(0,\
    \ std::numeric_limits<long long>::max(), [](long long x) { return x <= 3000000000LL;\
    \ }) == 3000000000LL, \"int \u3068 long long\");\n    check(binary_search(0ULL,\
    \ std::numeric_limits<unsigned long long>::max(), [](unsigned long long x) { return\
    \ x <= (1ULL << 63); }) == (1ULL << 63), \"unsigned long long \u306E\u4E0A\u534A\
    \u5206\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// binary-search.hpp \u306E\u6574\u6570\u7248\u3092\u3001\u578B\u306E\u5168\
    \u7BC4\u56F2\u3092\u542B\u3080\u5883\u754C\u3067\u691C\u8A3C\u3059\u308B\n// ok\
    \ < ng \u3068 ok > ng \u306E\u4E21\u65B9\u3067\u3001\u7B54\u3048\u30FBf \u306B\
    \u6E21\u3059\u5024\u304C ok \u3068 ng \u306E\u9593\u306B\u3042\u308B\u3053\u3068\
    \u30FBf \u306E\u547C\u3073\u51FA\u3057\u56DE\u6570\u3092\u78BA\u304B\u3081\u308B\
    \n// \u3042\u3075\u308C\u306A\u3044\u3053\u3068\u306F -fsanitize=undefined \u3067\
    \u3082\u78BA\u304B\u3081\u305F\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/utility/binary-search.hpp\"\
    \n\n#include <iostream>\n#include <limits>\n#include <random>\n\nbool ok = true;\n\
    \nvoid check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n\
    }\n\n// lo <= t < hi \u3068\u3057\u3066\u3001f(x) = x <= t (ok = lo, ng = hi)\
    \ \u3068 f(x) = x > t (ok = hi, ng = lo) \u3092\u8ABF\u3079\u308B\ntemplate <typename\
    \ T>\nvoid test(T lo, T hi, T t, const char* what) {\n    long long calls = 0;\n\
    \    bool inside = true;\n    T r1 = binary_search(lo, hi, [&](T x) {\n      \
    \  calls++;\n        if (!(lo < x && x < hi)) inside = false;\n        return\
    \ x <= t;\n    });\n    check(r1 == t, what);\n    check(inside && calls <= std::numeric_limits<T>::digits\
    \ + 1, what);\n    calls = 0;\n    T r2 = binary_search(hi, lo, [&](T x) {\n \
    \       calls++;\n        if (!(lo < x && x < hi)) inside = false;\n        return\
    \ x > t;\n    });\n    check(r2 == t + 1, what);\n    check(inside && calls <=\
    \ std::numeric_limits<T>::digits + 1, what);\n}\n\n// \u578B\u306E\u4E21\u7AEF\
    \u3068 0 \u306E\u4ED8\u8FD1\u3092\u5883\u754C\u306B\u3057\u3066\u8ABF\u3079\u308B\
    \ntemplate <typename T>\nvoid test_extreme(const char* what) {\n    constexpr\
    \ T mn = std::numeric_limits<T>::min(), mx = std::numeric_limits<T>::max();\n\
    \    for (T t : {mn, static_cast<T>(mn + 1), static_cast<T>(mn / 2), static_cast<T>(0),\
    \ static_cast<T>(1), static_cast<T>(mx / 2), static_cast<T>(mx - 2), static_cast<T>(mx\
    \ - 1)}) {\n        test<T>(mn, mx, t, what);\n    }\n    if (std::numeric_limits<T>::is_signed)\
    \ {\n        for (T t : {static_cast<T>(-2), static_cast<T>(-1)}) test<T>(mn,\
    \ mx, t, what);\n        test<T>(mn, static_cast<T>(0), static_cast<T>(-1), what);\n\
    \        test<T>(static_cast<T>(-1), mx, static_cast<T>(0), what);\n    }\n}\n\
    \n// \u5DEE\u304C 1 \u306A\u3089 f \u3092\u547C\u3070\u305A\u306B ok \u3092\u8FD4\
    \u3059\u3002\u5DEE\u304C 2 \u306A\u3089\u771F\u3093\u4E2D\u3092 1 \u56DE\u3060\
    \u3051\u8ABF\u3079\u308B\ntemplate <typename T>\nvoid test_small(T a, const char*\
    \ what) {\n    long long calls = 0;\n    check(binary_search(a, static_cast<T>(a\
    \ + 1), [&](T) { return calls++, false; }) == a && calls == 0, what);\n    check(binary_search(static_cast<T>(a\
    \ + 1), a, [&](T) { return calls++, false; }) == static_cast<T>(a + 1) && calls\
    \ == 0, what);\n    T m = static_cast<T>(a + 1), b = static_cast<T>(a + 2);\n\
    \    check(binary_search(a, b, [&](T x) { return calls++, x != m; }) == a && calls\
    \ == 1, what);\n    check(binary_search(a, b, [&](T x) { return calls++, x ==\
    \ m; }) == m && calls == 2, what);\n    check(binary_search(b, a, [&](T x) { return\
    \ calls++, x != m; }) == b && calls == 3, what);\n    check(binary_search(b, a,\
    \ [&](T x) { return calls++, x == m; }) == m && calls == 4, what);\n}\n\n// constexpr\
    \ \u3067\u4F7F\u3048\u308B\nstatic_assert(binary_search(0, 1000, [](long long\
    \ m) { return m * m <= 500; }) == 22);\nstatic_assert(binary_search(std::numeric_limits<long\
    \ long>::max(), std::numeric_limits<long long>::min(), [](long long x) { return\
    \ x >= 0; }) == 0);\n\nint main() {\n    // \u901A\u5E38\u306E\u5883\u754C\u63A2\
    \u7D22\n    check(binary_search(0, 1000, [](long long m) { return m * m <= 500;\
    \ }) == 22, \"sqrt(500)\");\n    check(binary_search(0, 1000000000, [](int x)\
    \ { return static_cast<long long>(x) * x <= 1000000000; }) == 31622, \"sqrt(1e9)\"\
    );\n    check(binary_search(1000, 0, [](long long m) { return m * m >= 500; })\
    \ == 23, \"ok > ng\");\n\n    // \u8CA0\u6570\u3092\u542B\u3080\u7BC4\u56F2\u3092\
    \u611A\u76F4\u3068\u6BD4\u3079\u308B\n    std::mt19937_64 rng(314);\n    for (int\
    \ rep = 0; rep < 10000; rep++) {\n        long long lo = static_cast<long long>(rng()\
    \ % 2001) - 1000;\n        long long hi = lo + static_cast<long long>(rng() %\
    \ 1000) + 1;\n        long long t = lo + static_cast<long long>(rng() % (hi -\
    \ lo));\n        test<long long>(lo, hi, t, \"\u8CA0\u6570\u3092\u542B\u3080 long\
    \ long\");\n        test<int>(static_cast<int>(lo), static_cast<int>(hi), static_cast<int>(t),\
    \ \"\u8CA0\u6570\u3092\u542B\u3080 int\");\n    }\n\n    // \u578B\u306E\u5168\
    \u7BC4\u56F2\n    test_extreme<int>(\"int \u306E\u5168\u7BC4\u56F2\");\n    test_extreme<long\
    \ long>(\"long long \u306E\u5168\u7BC4\u56F2 (LLONG_MIN, LLONG_MAX)\");\n    test_extreme<unsigned\
    \ long long>(\"unsigned long long \u306E\u5168\u7BC4\u56F2 (0, ULLONG_MAX)\");\n\
    \    test_extreme<unsigned int>(\"unsigned int \u306E\u5168\u7BC4\u56F2\");\n\
    \    test_extreme<short>(\"short \u306E\u5168\u7BC4\u56F2\");\n\n    // \u4E21\
    \u7AEF\u306E\u5DEE\u304C 1 \u307E\u305F\u306F 2\n    for (long long a : {std::numeric_limits<long\
    \ long>::min(), -2LL, -1LL, 0LL, std::numeric_limits<long long>::max() - 2}) test_small<long\
    \ long>(a, \"\u5DEE\u304C 1, 2 \u306E long long\");\n    for (int a : {std::numeric_limits<int>::min(),\
    \ -1, 0, std::numeric_limits<int>::max() - 2}) test_small<int>(a, \"\u5DEE\u304C\
    \ 1, 2 \u306E int\");\n    for (unsigned long long a : {0ULL, 1ULL, std::numeric_limits<unsigned\
    \ long long>::max() - 2}) test_small<unsigned long long>(a, \"\u5DEE\u304C 1,\
    \ 2 \u306E unsigned long long\");\n\n    // \u578B\u304C\u9055\u3046\u3068\u304D\
    \u306F common_type \u306B\u305D\u308D\u3048\u308B\n    check(binary_search(0,\
    \ std::numeric_limits<long long>::max(), [](long long x) { return x <= 3000000000LL;\
    \ }) == 3000000000LL, \"int \u3068 long long\");\n    check(binary_search(0ULL,\
    \ std::numeric_limits<unsigned long long>::max(), [](unsigned long long x) { return\
    \ x <= (1ULL << 63); }) == (1ULL << 63), \"unsigned long long \u306E\u4E0A\u534A\
    \u5206\");\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/utility/binary-search.hpp
  - src/base/functions.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/utility/binary-search.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 18:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/utility/binary-search.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/utility/binary-search.test.cpp
- /verify/test/unittest/utility/binary-search.test.cpp.html
title: test/unittest/utility/binary-search.test.cpp
---
