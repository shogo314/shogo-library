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
  bundledCode: "#line 1 \"test/unittest/functions.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// functions.hpp \u3068 binary-search.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/base/functions.hpp\"\n\n/**\n * @file functions.hpp\n * @brief \u6C4E\
    \u7528\u95A2\u6570 (chmin, chmax \u306A\u3069)\n */\n\n#include <algorithm>\n\
    #include <cmath>\n#include <iterator>\n#include <limits>\n#include <numeric>\n\
    #if __cplusplus >= 202002L\n#include <ranges>\n#endif\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <typename T1, typename T2>\ninline constexpr bool\
    \ chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n\
    \    }\n    return false;\n}\n\ntemplate <typename T1, typename T2>\ninline constexpr\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n\ninline constexpr long long max(const long\
    \ long& t1, const long long& t2) {\n    return std::max<long long>(t1, t2);\n\
    }\n\ninline constexpr long long min(const long long& t1, const long long& t2)\
    \ {\n    return std::min<long long>(t1, t2);\n}\n\nusing std::abs;\nusing std::gcd;\n\
    using std::lcm;\nusing std::size;\n\n#if __cplusplus >= 202002L\nusing std::midpoint;\n\
    #else\n// C++20 \u306E std::midpoint \u3068\u540C\u3058 (\u6574\u6570\u306F a\
    \ \u306E\u5074\u306B\u4E38\u3081\u3001\u3042\u3075\u308C\u306A\u3044)\ntemplate\
    \ <typename T>\ninline constexpr std::enable_if_t<std::is_integral_v<T> && !std::is_same_v<T,\
    \ bool>, T> midpoint(T a, T b) noexcept {\n    using U = std::make_unsigned_t<T>;\n\
    \    if (a <= b) return static_cast<T>(a + static_cast<T>(static_cast<U>(static_cast<U>(b)\
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
    \ long b) {\n    return 0 <= x && x < a && 0 <= y && y < b;\n}\n#line 7 \"test/unittest/functions.test.cpp\"\
    \n\n#line 9 \"test/unittest/functions.test.cpp\"\n#include <array>\n#line 11 \"\
    test/unittest/functions.test.cpp\"\n#include <cstdint>\n#include <forward_list>\n\
    #include <iostream>\n#line 15 \"test/unittest/functions.test.cpp\"\n#include <list>\n\
    #include <random>\n#include <set>\n#include <string>\n#include <string_view>\n\
    #line 22 \"test/unittest/functions.test.cpp\"\n#include <vector>\n\n#line 2 \"\
    src/utility/binary-search.hpp\"\n\n/**\n * @file binary-search.hpp\n * @brief\
    \ \u4E8C\u5206\u63A2\u7D22\n */\n\n#line 10 \"src/utility/binary-search.hpp\"\n\
    \n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#include <cstddef>\n#line 13 \"src/utility/traits.hpp\"\n\
    \nnamespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class\
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
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 12 \"src/utility/binary-search.hpp\"\n\n/**\n * f(ok) \u304C\u771F\u3001\
    f(ng) \u304C\u507D\u3068\u3057\u3066\u3001\u5883\u754C\u3067 f \u304C\u771F\u306B\
    \u306A\u308B\u5074\u306E\u5024\u3092\u8FD4\u3059\n * \u6574\u6570\u306A\u3089\
    \ ok \u3068 ng \u306E\u5DEE\u304C 1 \u306B\u306A\u308B\u307E\u3067\u3001\u6D6E\
    \u52D5\u5C0F\u6570\u70B9\u6570\u306A\u3089 100 \u56DE\u4E8C\u5206\u3059\u308B\n\
    \ */\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
    \ N>>and std::is_invocable_r_v<bool, F, std::common_type_t<M, N>>)>\ninline constexpr\
    \ std::common_type_t<M, N> binary_search(const M& ok, const N& ng, F f) {\n  \
    \  std::common_type_t<M, N> _ok = ok, _ng = ng;\n    while (std::abs(_ok - _ng)\
    \ > 1) {\n        std::common_type_t<M, N> mid = (_ok + _ng) / 2;\n        if\
    \ (f(mid)) {\n            _ok = mid;\n        } else {\n            _ng = mid;\n\
    \        }\n    }\n    return _ok;\n}\n\ntemplate <typename M, typename N, class\
    \ F, ENABLE_IF_T(!std::is_integral_v<std::common_type_t<M, N>> && std::is_invocable_r_v<bool,\
    \ F, std::common_type_t<M, N>>)>\ninline constexpr std::common_type_t<M, N> binary_search(const\
    \ M& ok, const N& ng, F f) {\n    std::common_type_t<M, N> _ok = ok, _ng = ng;\n\
    \    for (int i = 0; i < 100; i++) {\n        std::common_type_t<M, N> mid = (_ok\
    \ + _ng) / 2;\n        if (f(mid)) {\n            _ok = mid;\n        } else {\n\
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n#line 25 \"test/unittest/functions.test.cpp\"\
    \n\nbool ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond)\
    \ {\n        if (ok) std::cerr << \"failed: \" << what << std::endl;\n       \
    \ ok = false;\n    }\n}\n\n// midpoint \u306E\u7B54\u3048: (a + b) / 2 \u3092\
    \ a \u306E\u5074\u306B\u4E38\u3081\u308B\u3002__int128 \u3067\u8A08\u7B97\u3059\
    \u308B\ntemplate <typename T>\nT naive_midpoint(T a, T b) {\n    __int128 s =\
    \ static_cast<__int128>(a) + static_cast<__int128>(b);\n    return static_cast<T>(a\
    \ <= b ? floordiv(s, 2) : ceildiv(s, 2));\n}\ntemplate <typename T>\nvoid check_midpoint(std::mt19937_64&\
    \ rng) {\n    std::vector<T> xs = {std::numeric_limits<T>::min(), std::numeric_limits<T>::max(),\
    \ 0, 1, static_cast<T>(std::numeric_limits<T>::max() - 1), static_cast<T>(std::numeric_limits<T>::min()\
    \ + 1)};\n    if (std::is_signed_v<T>) xs.push_back(static_cast<T>(-1));\n   \
    \ for (int i = 0; i < 30; i++) xs.push_back(static_cast<T>(rng())), xs.push_back(static_cast<T>(static_cast<T>(rng())\
    \ >> (rng() % (8 * sizeof(T)))));\n    for (T a : xs)\n        for (T b : xs)\
    \ check(midpoint(a, b) == naive_midpoint(a, b), \"midpoint \u6574\u6570\");\n\
    \    static_assert(std::is_same_v<decltype(midpoint(T(), T())), T>);\n}\n\n//\
    \ len \u306F\u8981\u7D20\u6570\u306E\u5206\u304B\u3089\u306A\u3044\u3082\u306E\
    \ (forward_list \u3084\u6574\u6570) \u3092\u6E21\u3059\u3068\u5019\u88DC\u304B\
    \u3089\u5916\u308C\u308B\ntemplate <typename C, typename = void>\nstruct has_len\
    \ : std::false_type {};\ntemplate <typename C>\nstruct has_len<C, std::void_t<decltype(len(std::declval<C&>()))>>\
    \ : std::true_type {};\nstatic_assert(has_len<std::vector<int>>::value && has_len<int[3]>::value\
    \ && has_len<std::list<int>>::value);\nstatic_assert(!has_len<std::forward_list<int>>::value\
    \ && !has_len<int>::value);\n// size() \u3060\u3051\u3092\u6301\u3064\u81EA\u4F5C\
    \u306E\u578B (begin() \u3068 end() \u306F\u306A\u3044) \u306B\u3082\u3001C++17\
    \ \u3068 C++20 \u306E\u3069\u3061\u3089\u3067\u3082\u4F7F\u3048\u308B\nstruct\
    \ OnlySize {\n    int size() const { return 5; }\n};\nstatic_assert(has_len<OnlySize>::value\
    \ && has_len<const OnlySize>::value);\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \n    for (int rep = 0; rep < 20000 && ok; rep++) {\n        long long a = static_cast<long\
    \ long>(rng() % 21) - 10, b = static_cast<long long>(rng() % 21) - 10;\n\n   \
    \     // chmin / chmax: \u66F4\u65B0\u3057\u305F\u304B\u3092\u8FD4\u3059\n   \
    \     {\n            long long x = a;\n            bool changed = chmin(x, b);\n\
    \            check(x == std::min(a, b) && changed == (b < a), \"chmin\");\n  \
    \          x = a;\n            changed = chmax(x, b);\n            check(x ==\
    \ std::max(a, b) && changed == (b > a), \"chmax\");\n            double d = a;\n\
    \            check(chmin(d, b + 0.5) == (b + 0.5 < a) && d == std::min<double>(a,\
    \ b + 0.5), \"chmin (\u578B\u304C\u7570\u306A\u308B)\");\n        }\n\n      \
    \  // long long \u540C\u58EB\u306E max / min\n        check(max(a, b) == std::max(a,\
    \ b) && min(a, b) == std::min(a, b), \"max/min(long long, long long)\");\n   \
    \     check(max(a, 3) == std::max(a, 3LL) && min(2, b) == std::min(2LL, b), \"\
    max/min (int \u3068 long long \u306E\u6DF7\u5728)\");\n\n        // floordiv /\
    \ ceildiv: \u5B9F\u6570\u306E floor / ceil \u3068\u6BD4\u3079\u308B\n        if\
    \ (b != 0) {\n            check(floordiv(a, b) == static_cast<long long>(std::floor(static_cast<double>(a)\
    \ / b)), \"floordiv\");\n            check(ceildiv(a, b) == static_cast<long long>(std::ceil(static_cast<double>(a)\
    \ / b)), \"ceildiv\");\n            auto [q, r] = divmod(a, b);\n            check(q\
    \ == floordiv(a, b) && q * b + r == a, \"divmod\");\n            check(r == 0\
    \ || (r < 0) == (b < 0), \"divmod \u4F59\u308A\u306E\u7B26\u53F7\");\n       \
    \     check(std::abs(r) < std::abs(b), \"divmod \u4F59\u308A\u306E\u5927\u304D\
    \u3055\");\n        }\n\n        // inrange / inrect\n        {\n            long\
    \ long x = static_cast<long long>(rng() % 15) - 5;\n            check(inrange(x,\
    \ a) == (0 <= x && x < a), \"inrange(x, a)\");\n            check(inrange(x, a,\
    \ b) == (a <= x && x < b), \"inrange(x, a, b)\");\n            long long y = static_cast<long\
    \ long>(rng() % 15) - 5;\n            check(inrect(x, y, a, b) == (0 <= x && x\
    \ < a && 0 <= y && y < b), \"inrect\");\n        }\n\n        // \u6574\u6570\u306E\
    \u4E8C\u5206\u63A2\u7D22: f(ok) \u304C\u771F\u3001f(ng) \u304C\u507D\u3067\u5358\
    \u8ABF\u306A\u3068\u304D\u3001\u5883\u754C\u306E ok \u5074\u3092\u8FD4\u3059\n\
    \        {\n            long long t = static_cast<long long>(rng() % 2001) - 1000;\n\
    \            long long lo = t - static_cast<long long>(rng() % 1000) - 1, hi =\
    \ t + static_cast<long long>(rng() % 1000) + 1;\n            // f(x) = x <= t\
    \ (ok = lo, ng = hi) -> t\n            check(binary_search(lo, hi, [&](long long\
    \ x) { return x <= t; }) == t, \"binary_search \u6574\u6570 (ok < ng)\");\n  \
    \          // f(x) = x >= t (ok = hi, ng = lo) -> t\n            check(binary_search(hi,\
    \ lo, [&](long long x) { return x >= t; }) == t, \"binary_search \u6574\u6570\
    \ (ok > ng)\");\n            // \u96A3\u308A\u5408\u3046 ok, ng \u306A\u3089 ok\
    \ \u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\n            check(binary_search(t,\
    \ t + 1, [&](long long) { return true; }) == t, \"binary_search \u6574\u6570 \u96A3\
    \u63A5\");\n        }\n\n        // \u5B9F\u6570\u306E\u4E8C\u5206\u63A2\u7D22\
    \ (100 \u56DE)\n        {\n            double t = static_cast<double>(rng() %\
    \ 2000001) / 1000.0;  // [0, 2000]\n            double r = binary_search(0.0,\
    \ 3000.0, [&](double x) { return x * x <= t; });\n            check(std::abs(r\
    \ - std::sqrt(t)) < 1e-9, \"binary_search \u5B9F\u6570 sqrt\");\n            double\
    \ r2 = binary_search(3000.0, 0.0, [&](double x) { return x * x >= t; });\n   \
    \         check(std::abs(r2 - std::sqrt(t)) < 1e-9, \"binary_search \u5B9F\u6570\
    \ (ok > ng)\");\n        }\n    }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n \
    \   check(binary_search(0, 1000000000, [](int x) { return static_cast<long long>(x)\
    \ * x <= 1000000000; }) == 31622, \"binary_search sqrt(1e9)\");\n    check(!inrange(0,\
    \ 0) && inrange(0, 1) && !inrange(-1, 1), \"inrange \u5883\u754C\");\n    check(inrange(5,\
    \ 5, 6) && !inrange(6, 5, 6), \"inrange(x, a, b) \u5883\u754C\");\n    check(floordiv(7,\
    \ 2) == 3 && floordiv(-7, 2) == -4 && floordiv(7, -2) == -4 && floordiv(-7, -2)\
    \ == 3, \"floordiv \u6C7A\u307E\u3063\u305F\u5024\");\n    check(ceildiv(7, 2)\
    \ == 4 && ceildiv(-7, 2) == -3 && ceildiv(7, -2) == -3 && ceildiv(-7, -2) == 4,\
    \ \"ceildiv \u6C7A\u307E\u3063\u305F\u5024\");\n    check(floordiv(-6, 3) == -2\
    \ && ceildiv(-6, 3) == -2, \"\u5272\u308A\u5207\u308C\u308B\u5834\u5408\");\n\
    \    {\n        long long n = -7;\n        check(floordiv(n, 2) == -4 && ceildiv(n,\
    \ 2) == -3, \"long long \u3068 int \u306E\u6DF7\u5728\");\n    }\n    check(divmod(7,\
    \ 3) == std::pair(2, 1) && divmod(-7, 3) == std::pair(-3, 2), \"divmod \u6C7A\u307E\
    \u3063\u305F\u5024\");\n    check(divmod(7, -3) == std::pair(-3, -2) && divmod(-7,\
    \ -3) == std::pair(2, -1), \"divmod \u6C7A\u307E\u3063\u305F\u5024 (b < 0)\");\n\
    \    static_assert(floordiv(-1LL, 1000000000000LL) == -1 && ceildiv(1LL, 1000000000000LL)\
    \ == 1);\n    static_assert(divmod(-1LL, 1000000000000LL) == std::pair(-1LL, 999999999999LL));\n\
    \n    // midpoint: \u6574\u6570\u306F 8 \u30D3\u30C3\u30C8\u306E\u578B\u3092\u5168\
    \u7D44\u3001\u4ED6\u306F\u5883\u754C\u4ED8\u8FD1\u3068\u30E9\u30F3\u30C0\u30E0\
    \u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3068\u30DD\u30A4\u30F3\u30BF\u306F\
    \u6C7A\u307E\u3063\u305F\u5024\n    for (int a = -128; a < 128; a++)\n       \
    \ for (int b = -128; b < 128; b++) check(midpoint(static_cast<std::int8_t>(a),\
    \ static_cast<std::int8_t>(b)) == naive_midpoint(static_cast<std::int8_t>(a),\
    \ static_cast<std::int8_t>(b)), \"midpoint int8\");\n    for (int a = 0; a < 256;\
    \ a++)\n        for (int b = 0; b < 256; b++) check(midpoint(static_cast<std::uint8_t>(a),\
    \ static_cast<std::uint8_t>(b)) == naive_midpoint(static_cast<std::uint8_t>(a),\
    \ static_cast<std::uint8_t>(b)), \"midpoint uint8\");\n    check_midpoint<short>(rng);\n\
    \    check_midpoint<int>(rng);\n    check_midpoint<unsigned>(rng);\n    check_midpoint<long\
    \ long>(rng);\n    check_midpoint<unsigned long long>(rng);\n    {\n        constexpr\
    \ double M = std::numeric_limits<double>::max(), D = std::numeric_limits<double>::denorm_min();\n\
    \        check(midpoint(1.0, 4.0) == 2.5 && midpoint(-3.0, 1.0) == -1.0, \"midpoint\
    \ double\");\n        check(midpoint(M, M) == M && midpoint(-M, M) == 0.0 && midpoint(M,\
    \ M / 2) == M * 0.75, \"midpoint double \u3042\u3075\u308C\u306A\u3044\");\n \
    \       check(midpoint(D, 4.0) == 2.0 && midpoint(4.0, D) == 2.0 && midpoint(D,\
    \ D) == D, \"midpoint double \u975E\u6B63\u898F\u5316\u6570\");\n        check(midpoint(1.0f,\
    \ 2.0f) == 1.5f && std::is_same_v<decltype(midpoint(1.0f, 2.0f)), float>, \"midpoint\
    \ float\");\n        for (int rep = 0; rep < 1000; rep++) {\n            double\
    \ a = static_cast<double>(static_cast<long long>(rng() % 2000001 - 1000000)) /\
    \ 1024, b = static_cast<double>(static_cast<long long>(rng() % 2000001 - 1000000))\
    \ / 1024;\n            check(midpoint(a, b) == (a + b) / 2, \"midpoint double\
    \ \u30E9\u30F3\u30C0\u30E0\");\n        }\n        static int arr[10];\n     \
    \   check(midpoint(arr, arr + 9) == arr + 4 && midpoint(arr + 9, arr) == arr +\
    \ 5 && midpoint(arr + 3, arr + 3) == arr + 3, \"midpoint \u30DD\u30A4\u30F3\u30BF\
    \");\n    }\n    static_assert(midpoint(1, 4) == 2 && midpoint(4, 1) == 3 && midpoint(-3,\
    \ 0) == -2);\n    static_assert(midpoint(std::numeric_limits<long long>::max(),\
    \ std::numeric_limits<long long>::max() - 2) == std::numeric_limits<long long>::max()\
    \ - 1);\n    static_assert(midpoint(0u, 4294967295u) == 2147483647u && midpoint(4294967295u,\
    \ 0u) == 2147483648u);\n    static_assert(midpoint(1.0, 2.0) == 1.5);\n\n    //\
    \ len: \u8981\u7D20\u6570\u3092 long long \u3067\u8FD4\u3059\n    {\n        std::vector<int>\
    \ v(5);\n        const std::string str = \"abcd\";\n        std::set<int> st =\
    \ {3, 1, 4, 1, 5};\n        int carr[7] = {};\n        check(len(v) == 5 && len(str)\
    \ == 4 && len(st) == 4 && len(carr) == 7, \"len\");\n        check(len(std::vector<int>())\
    \ == 0 && len(std::string_view(\"xy\")) == 2 && len(\"abc\") == 4, \"len \u7A7A\
    \u30FB\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u30FB\u6587\u5B57\u5217\
    \u30EA\u30C6\u30E9\u30EB\");\n        check(len(v) - 6 == -1, \"len \u306F\u7B26\
    \u53F7\u4ED8\u304D\");\n        static_assert(std::is_same_v<decltype(len(v)),\
    \ long long>);\n        OnlySize os;\n        check(len(os) == 5 && len(OnlySize{})\
    \ == 5, \"len size() \u3060\u3051\u3092\u6301\u3064\u578B\");\n        static_assert(std::is_same_v<decltype(len(os)),\
    \ long long>);\n        static_assert(len(std::array<int, 3>{}) == 3);\n#if __cplusplus\
    \ >= 202002L\n        check(len(std::views::iota(2, 9)) == 7, \"len views::iota\"\
    );\n#endif\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// functions.hpp \u3068 binary-search.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include \"../../src/base/functions.hpp\"\n\n#include <algorithm>\n#include <array>\n\
    #include <cmath>\n#include <cstdint>\n#include <forward_list>\n#include <iostream>\n\
    #include <limits>\n#include <list>\n#include <random>\n#include <set>\n#include\
    \ <string>\n#include <string_view>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../src/utility/binary-search.hpp\"\n\nbool\
    \ ok = true;\n\nvoid check(bool cond, const char* what) {\n    if (!cond) {\n\
    \        if (ok) std::cerr << \"failed: \" << what << std::endl;\n        ok =\
    \ false;\n    }\n}\n\n// midpoint \u306E\u7B54\u3048: (a + b) / 2 \u3092 a \u306E\
    \u5074\u306B\u4E38\u3081\u308B\u3002__int128 \u3067\u8A08\u7B97\u3059\u308B\n\
    template <typename T>\nT naive_midpoint(T a, T b) {\n    __int128 s = static_cast<__int128>(a)\
    \ + static_cast<__int128>(b);\n    return static_cast<T>(a <= b ? floordiv(s,\
    \ 2) : ceildiv(s, 2));\n}\ntemplate <typename T>\nvoid check_midpoint(std::mt19937_64&\
    \ rng) {\n    std::vector<T> xs = {std::numeric_limits<T>::min(), std::numeric_limits<T>::max(),\
    \ 0, 1, static_cast<T>(std::numeric_limits<T>::max() - 1), static_cast<T>(std::numeric_limits<T>::min()\
    \ + 1)};\n    if (std::is_signed_v<T>) xs.push_back(static_cast<T>(-1));\n   \
    \ for (int i = 0; i < 30; i++) xs.push_back(static_cast<T>(rng())), xs.push_back(static_cast<T>(static_cast<T>(rng())\
    \ >> (rng() % (8 * sizeof(T)))));\n    for (T a : xs)\n        for (T b : xs)\
    \ check(midpoint(a, b) == naive_midpoint(a, b), \"midpoint \u6574\u6570\");\n\
    \    static_assert(std::is_same_v<decltype(midpoint(T(), T())), T>);\n}\n\n//\
    \ len \u306F\u8981\u7D20\u6570\u306E\u5206\u304B\u3089\u306A\u3044\u3082\u306E\
    \ (forward_list \u3084\u6574\u6570) \u3092\u6E21\u3059\u3068\u5019\u88DC\u304B\
    \u3089\u5916\u308C\u308B\ntemplate <typename C, typename = void>\nstruct has_len\
    \ : std::false_type {};\ntemplate <typename C>\nstruct has_len<C, std::void_t<decltype(len(std::declval<C&>()))>>\
    \ : std::true_type {};\nstatic_assert(has_len<std::vector<int>>::value && has_len<int[3]>::value\
    \ && has_len<std::list<int>>::value);\nstatic_assert(!has_len<std::forward_list<int>>::value\
    \ && !has_len<int>::value);\n// size() \u3060\u3051\u3092\u6301\u3064\u81EA\u4F5C\
    \u306E\u578B (begin() \u3068 end() \u306F\u306A\u3044) \u306B\u3082\u3001C++17\
    \ \u3068 C++20 \u306E\u3069\u3061\u3089\u3067\u3082\u4F7F\u3048\u308B\nstruct\
    \ OnlySize {\n    int size() const { return 5; }\n};\nstatic_assert(has_len<OnlySize>::value\
    \ && has_len<const OnlySize>::value);\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \n    for (int rep = 0; rep < 20000 && ok; rep++) {\n        long long a = static_cast<long\
    \ long>(rng() % 21) - 10, b = static_cast<long long>(rng() % 21) - 10;\n\n   \
    \     // chmin / chmax: \u66F4\u65B0\u3057\u305F\u304B\u3092\u8FD4\u3059\n   \
    \     {\n            long long x = a;\n            bool changed = chmin(x, b);\n\
    \            check(x == std::min(a, b) && changed == (b < a), \"chmin\");\n  \
    \          x = a;\n            changed = chmax(x, b);\n            check(x ==\
    \ std::max(a, b) && changed == (b > a), \"chmax\");\n            double d = a;\n\
    \            check(chmin(d, b + 0.5) == (b + 0.5 < a) && d == std::min<double>(a,\
    \ b + 0.5), \"chmin (\u578B\u304C\u7570\u306A\u308B)\");\n        }\n\n      \
    \  // long long \u540C\u58EB\u306E max / min\n        check(max(a, b) == std::max(a,\
    \ b) && min(a, b) == std::min(a, b), \"max/min(long long, long long)\");\n   \
    \     check(max(a, 3) == std::max(a, 3LL) && min(2, b) == std::min(2LL, b), \"\
    max/min (int \u3068 long long \u306E\u6DF7\u5728)\");\n\n        // floordiv /\
    \ ceildiv: \u5B9F\u6570\u306E floor / ceil \u3068\u6BD4\u3079\u308B\n        if\
    \ (b != 0) {\n            check(floordiv(a, b) == static_cast<long long>(std::floor(static_cast<double>(a)\
    \ / b)), \"floordiv\");\n            check(ceildiv(a, b) == static_cast<long long>(std::ceil(static_cast<double>(a)\
    \ / b)), \"ceildiv\");\n            auto [q, r] = divmod(a, b);\n            check(q\
    \ == floordiv(a, b) && q * b + r == a, \"divmod\");\n            check(r == 0\
    \ || (r < 0) == (b < 0), \"divmod \u4F59\u308A\u306E\u7B26\u53F7\");\n       \
    \     check(std::abs(r) < std::abs(b), \"divmod \u4F59\u308A\u306E\u5927\u304D\
    \u3055\");\n        }\n\n        // inrange / inrect\n        {\n            long\
    \ long x = static_cast<long long>(rng() % 15) - 5;\n            check(inrange(x,\
    \ a) == (0 <= x && x < a), \"inrange(x, a)\");\n            check(inrange(x, a,\
    \ b) == (a <= x && x < b), \"inrange(x, a, b)\");\n            long long y = static_cast<long\
    \ long>(rng() % 15) - 5;\n            check(inrect(x, y, a, b) == (0 <= x && x\
    \ < a && 0 <= y && y < b), \"inrect\");\n        }\n\n        // \u6574\u6570\u306E\
    \u4E8C\u5206\u63A2\u7D22: f(ok) \u304C\u771F\u3001f(ng) \u304C\u507D\u3067\u5358\
    \u8ABF\u306A\u3068\u304D\u3001\u5883\u754C\u306E ok \u5074\u3092\u8FD4\u3059\n\
    \        {\n            long long t = static_cast<long long>(rng() % 2001) - 1000;\n\
    \            long long lo = t - static_cast<long long>(rng() % 1000) - 1, hi =\
    \ t + static_cast<long long>(rng() % 1000) + 1;\n            // f(x) = x <= t\
    \ (ok = lo, ng = hi) -> t\n            check(binary_search(lo, hi, [&](long long\
    \ x) { return x <= t; }) == t, \"binary_search \u6574\u6570 (ok < ng)\");\n  \
    \          // f(x) = x >= t (ok = hi, ng = lo) -> t\n            check(binary_search(hi,\
    \ lo, [&](long long x) { return x >= t; }) == t, \"binary_search \u6574\u6570\
    \ (ok > ng)\");\n            // \u96A3\u308A\u5408\u3046 ok, ng \u306A\u3089 ok\
    \ \u3092\u305D\u306E\u307E\u307E\u8FD4\u3059\n            check(binary_search(t,\
    \ t + 1, [&](long long) { return true; }) == t, \"binary_search \u6574\u6570 \u96A3\
    \u63A5\");\n        }\n\n        // \u5B9F\u6570\u306E\u4E8C\u5206\u63A2\u7D22\
    \ (100 \u56DE)\n        {\n            double t = static_cast<double>(rng() %\
    \ 2000001) / 1000.0;  // [0, 2000]\n            double r = binary_search(0.0,\
    \ 3000.0, [&](double x) { return x * x <= t; });\n            check(std::abs(r\
    \ - std::sqrt(t)) < 1e-9, \"binary_search \u5B9F\u6570 sqrt\");\n            double\
    \ r2 = binary_search(3000.0, 0.0, [&](double x) { return x * x >= t; });\n   \
    \         check(std::abs(r2 - std::sqrt(t)) < 1e-9, \"binary_search \u5B9F\u6570\
    \ (ok > ng)\");\n        }\n    }\n\n    // \u6C7A\u307E\u3063\u305F\u5024\n \
    \   check(binary_search(0, 1000000000, [](int x) { return static_cast<long long>(x)\
    \ * x <= 1000000000; }) == 31622, \"binary_search sqrt(1e9)\");\n    check(!inrange(0,\
    \ 0) && inrange(0, 1) && !inrange(-1, 1), \"inrange \u5883\u754C\");\n    check(inrange(5,\
    \ 5, 6) && !inrange(6, 5, 6), \"inrange(x, a, b) \u5883\u754C\");\n    check(floordiv(7,\
    \ 2) == 3 && floordiv(-7, 2) == -4 && floordiv(7, -2) == -4 && floordiv(-7, -2)\
    \ == 3, \"floordiv \u6C7A\u307E\u3063\u305F\u5024\");\n    check(ceildiv(7, 2)\
    \ == 4 && ceildiv(-7, 2) == -3 && ceildiv(7, -2) == -3 && ceildiv(-7, -2) == 4,\
    \ \"ceildiv \u6C7A\u307E\u3063\u305F\u5024\");\n    check(floordiv(-6, 3) == -2\
    \ && ceildiv(-6, 3) == -2, \"\u5272\u308A\u5207\u308C\u308B\u5834\u5408\");\n\
    \    {\n        long long n = -7;\n        check(floordiv(n, 2) == -4 && ceildiv(n,\
    \ 2) == -3, \"long long \u3068 int \u306E\u6DF7\u5728\");\n    }\n    check(divmod(7,\
    \ 3) == std::pair(2, 1) && divmod(-7, 3) == std::pair(-3, 2), \"divmod \u6C7A\u307E\
    \u3063\u305F\u5024\");\n    check(divmod(7, -3) == std::pair(-3, -2) && divmod(-7,\
    \ -3) == std::pair(2, -1), \"divmod \u6C7A\u307E\u3063\u305F\u5024 (b < 0)\");\n\
    \    static_assert(floordiv(-1LL, 1000000000000LL) == -1 && ceildiv(1LL, 1000000000000LL)\
    \ == 1);\n    static_assert(divmod(-1LL, 1000000000000LL) == std::pair(-1LL, 999999999999LL));\n\
    \n    // midpoint: \u6574\u6570\u306F 8 \u30D3\u30C3\u30C8\u306E\u578B\u3092\u5168\
    \u7D44\u3001\u4ED6\u306F\u5883\u754C\u4ED8\u8FD1\u3068\u30E9\u30F3\u30C0\u30E0\
    \u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u3068\u30DD\u30A4\u30F3\u30BF\u306F\
    \u6C7A\u307E\u3063\u305F\u5024\n    for (int a = -128; a < 128; a++)\n       \
    \ for (int b = -128; b < 128; b++) check(midpoint(static_cast<std::int8_t>(a),\
    \ static_cast<std::int8_t>(b)) == naive_midpoint(static_cast<std::int8_t>(a),\
    \ static_cast<std::int8_t>(b)), \"midpoint int8\");\n    for (int a = 0; a < 256;\
    \ a++)\n        for (int b = 0; b < 256; b++) check(midpoint(static_cast<std::uint8_t>(a),\
    \ static_cast<std::uint8_t>(b)) == naive_midpoint(static_cast<std::uint8_t>(a),\
    \ static_cast<std::uint8_t>(b)), \"midpoint uint8\");\n    check_midpoint<short>(rng);\n\
    \    check_midpoint<int>(rng);\n    check_midpoint<unsigned>(rng);\n    check_midpoint<long\
    \ long>(rng);\n    check_midpoint<unsigned long long>(rng);\n    {\n        constexpr\
    \ double M = std::numeric_limits<double>::max(), D = std::numeric_limits<double>::denorm_min();\n\
    \        check(midpoint(1.0, 4.0) == 2.5 && midpoint(-3.0, 1.0) == -1.0, \"midpoint\
    \ double\");\n        check(midpoint(M, M) == M && midpoint(-M, M) == 0.0 && midpoint(M,\
    \ M / 2) == M * 0.75, \"midpoint double \u3042\u3075\u308C\u306A\u3044\");\n \
    \       check(midpoint(D, 4.0) == 2.0 && midpoint(4.0, D) == 2.0 && midpoint(D,\
    \ D) == D, \"midpoint double \u975E\u6B63\u898F\u5316\u6570\");\n        check(midpoint(1.0f,\
    \ 2.0f) == 1.5f && std::is_same_v<decltype(midpoint(1.0f, 2.0f)), float>, \"midpoint\
    \ float\");\n        for (int rep = 0; rep < 1000; rep++) {\n            double\
    \ a = static_cast<double>(static_cast<long long>(rng() % 2000001 - 1000000)) /\
    \ 1024, b = static_cast<double>(static_cast<long long>(rng() % 2000001 - 1000000))\
    \ / 1024;\n            check(midpoint(a, b) == (a + b) / 2, \"midpoint double\
    \ \u30E9\u30F3\u30C0\u30E0\");\n        }\n        static int arr[10];\n     \
    \   check(midpoint(arr, arr + 9) == arr + 4 && midpoint(arr + 9, arr) == arr +\
    \ 5 && midpoint(arr + 3, arr + 3) == arr + 3, \"midpoint \u30DD\u30A4\u30F3\u30BF\
    \");\n    }\n    static_assert(midpoint(1, 4) == 2 && midpoint(4, 1) == 3 && midpoint(-3,\
    \ 0) == -2);\n    static_assert(midpoint(std::numeric_limits<long long>::max(),\
    \ std::numeric_limits<long long>::max() - 2) == std::numeric_limits<long long>::max()\
    \ - 1);\n    static_assert(midpoint(0u, 4294967295u) == 2147483647u && midpoint(4294967295u,\
    \ 0u) == 2147483648u);\n    static_assert(midpoint(1.0, 2.0) == 1.5);\n\n    //\
    \ len: \u8981\u7D20\u6570\u3092 long long \u3067\u8FD4\u3059\n    {\n        std::vector<int>\
    \ v(5);\n        const std::string str = \"abcd\";\n        std::set<int> st =\
    \ {3, 1, 4, 1, 5};\n        int carr[7] = {};\n        check(len(v) == 5 && len(str)\
    \ == 4 && len(st) == 4 && len(carr) == 7, \"len\");\n        check(len(std::vector<int>())\
    \ == 0 && len(std::string_view(\"xy\")) == 2 && len(\"abc\") == 4, \"len \u7A7A\
    \u30FB\u4E00\u6642\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u30FB\u6587\u5B57\u5217\
    \u30EA\u30C6\u30E9\u30EB\");\n        check(len(v) - 6 == -1, \"len \u306F\u7B26\
    \u53F7\u4ED8\u304D\");\n        static_assert(std::is_same_v<decltype(len(v)),\
    \ long long>);\n        OnlySize os;\n        check(len(os) == 5 && len(OnlySize{})\
    \ == 5, \"len size() \u3060\u3051\u3092\u6301\u3064\u578B\");\n        static_assert(std::is_same_v<decltype(len(os)),\
    \ long long>);\n        static_assert(len(std::array<int, 3>{}) == 3);\n#if __cplusplus\
    \ >= 202002L\n        check(len(std::views::iota(2, 9)) == 7, \"len views::iota\"\
    );\n#endif\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/base/functions.hpp
  - src/utility/binary-search.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/functions.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 02:23:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/functions.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/functions.test.cpp
- /verify/test/unittest/functions.test.cpp.html
title: test/unittest/functions.test.cpp
---
