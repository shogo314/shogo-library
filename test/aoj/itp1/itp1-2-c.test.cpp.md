---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/utility/container_func.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
      \ max, sum \u306A\u3069)"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C
  bundledCode: "#line 1 \"test/aoj/itp1/itp1-2-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/base/io.hpp\"\n/**\n\
    \ * @file io.hpp\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\
    \u30AA\u30FC\u30D0\u30FC\u30ED\u30FC\u30C9\n */\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cstddef>\n#line 11 \"src/base/io.hpp\"\n#include <set>\n\
    #include <string>\n#include <tuple>\n#include <utility>\n#line 16 \"src/base/io.hpp\"\
    \n\nnamespace internal_io {\n// 128 bit \u306E\u5272\u308A\u7B97\u306F\u9045\u3044\
    \u306E\u3067\u300118 \u6841\u305A\u3064 64 bit \u3067\u6271\u3046\nconstexpr unsigned\
    \ long long POW10_18 = 1000000000000000000ULL;\n// \u7A7A\u767D\u3067\u533A\u5207\
    \u3089\u308C\u305F 1 \u8A9E\u3092 10 \u9032\u306E\u6574\u6570\u3068\u3057\u3066\
    \u8AAD\u3080\u3002\u6570\u3067\u306A\u3044\u3001\u307E\u305F\u306F lim \u3092\u8D85\
    \u3048\u308B\u306A\u3089 false\ntemplate <typename CharT, typename Traits>\nbool\
    \ read_u128(std::basic_istream<CharT, Traits>& is, unsigned __int128& x, bool&\
    \ neg, unsigned __int128 pos_max, unsigned __int128 neg_max) {\n    std::basic_string<CharT,\
    \ Traits> s;\n    if (!(is >> s)) return false;\n    std::size_t i = 0;\n    neg\
    \ = false;\n    if (s[0] == CharT('-') || s[0] == CharT('+')) neg = s[i++] ==\
    \ CharT('-');\n    if (i == s.size()) return false;\n    for (std::size_t j =\
    \ i; j < s.size(); j++) {\n        if (s[j] < CharT('0') || CharT('9') < s[j])\
    \ return false;\n    }\n    while (i + 1 < s.size() && s[i] == CharT('0')) i++;\n\
    \    // 39 \u6841\u306A\u3089 2^128 \u3092\u8D85\u3048\u308B\u3053\u3068\u304C\
    \u3042\u308B\u306E\u3067\u3001\u6700\u5F8C\u306E 1 \u6841\u306E\u524D\u3067\u6BD4\
    \u3079\u308B\u300240 \u6841\u4EE5\u4E0A\u306F\u5FC5\u305A\u7BC4\u56F2\u5916\n\
    \    const std::size_t len = s.size() - i;\n    if (len > 39) return false;\n\
    \    const unsigned __int128 lim = neg ? neg_max : pos_max;\n    const std::size_t\
    \ safe = len == 39 ? s.size() - 1 : s.size();\n    x = 0;\n    while (i < safe)\
    \ {\n        const std::size_t k = std::min<std::size_t>(18, safe - i);\n    \
    \    unsigned long long c = 0, p = 1;\n        for (std::size_t j = 0; j < k;\
    \ j++, i++) c = c * 10 + (s[i] - CharT('0')), p *= 10;\n        x = x * p + c;\n\
    \    }\n    if (len == 39) {\n        const unsigned d = s[i] - CharT('0');\n\
    \        if (x > lim / 10 || x * 10 > lim - d) return false;\n        x = x *\
    \ 10 + d;\n    }\n    return x <= lim;\n}\n// x < 10^18 \u3092\u66F8\u304F\u3002\
    pad \u306A\u3089 18 \u6841\u306B\u306A\u308B\u3088\u3046 0 \u3067\u57CB\u3081\u308B\
    \u3002\u672B\u5C3E\u304B\u3089\u66F8\u3044\u3066\u5148\u982D\u3092\u8FD4\u3059\
    \ninline char* write_u64(char* end, unsigned long long x, bool pad) {\n    char*\
    \ p = end;\n    do {\n        *--p = static_cast<char>('0' + x % 10);\n      \
    \  x /= 10;\n    } while (x > 0);\n    if (pad) {\n        while (p > end - 18)\
    \ *--p = '0';\n    }\n    return p;\n}\ntemplate <typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& write_u128(std::basic_ostream<CharT, Traits>&\
    \ os, unsigned __int128 x, bool neg) {\n    char buf[41];\n    char* p = buf +\
    \ 40;\n    *p = '\\0';\n    if (x < POW10_18) {\n        p = write_u64(p, static_cast<unsigned\
    \ long long>(x), false);\n    } else {\n        const unsigned __int128 q = x\
    \ / POW10_18;\n        p = write_u64(p, static_cast<unsigned long long>(x - q\
    \ * POW10_18), true);\n        if (q < POW10_18) {\n            p = write_u64(p,\
    \ static_cast<unsigned long long>(q), false);\n        } else {\n            const\
    \ unsigned long long hi = static_cast<unsigned long long>(q / POW10_18);\n   \
    \         p = write_u64(p, static_cast<unsigned long long>(q - static_cast<unsigned\
    \ __int128>(hi) * POW10_18), true);\n            p = write_u64(p, hi, false);\n\
    \        }\n    }\n    if (neg) *--p = '-';\n    return os << p;\n}\n}  // namespace\
    \ internal_io\n\n// 128 bit \u6574\u6570\u306E\u5165\u51FA\u529B (GNU \u62E1\u5F35\
    )\u3002std::basic_istream / std::basic_ostream \u306B\u306F\u7528\u610F\u3055\u308C\
    \u3066\u3044\u306A\u3044\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, __int128_t& x) {\n\
    \    const unsigned __int128 pos_max = static_cast<unsigned __int128>(-1) >> 1;\n\
    \    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u,\
    \ neg, pos_max, pos_max + 1)) {\n        x = neg ? static_cast<__int128_t>(-u)\
    \ : static_cast<__int128_t>(u);\n    } else {\n        x = 0;\n        is.setstate(std::ios_base::failbit);\n\
    \    }\n    return is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, __uint128_t& x) {\n\
    \    unsigned __int128 u;\n    bool neg;\n    if (internal_io::read_u128(is, u,\
    \ neg, static_cast<unsigned __int128>(-1), 0)) {\n        x = u;\n    } else {\n\
    \        x = 0;\n        is.setstate(std::ios_base::failbit);\n    }\n    return\
    \ is;\n}\ntemplate <typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, __int128_t x) {\n\
    \    // -x \u306F\u6700\u5C0F\u5024\u3067\u3042\u3075\u308C\u308B\u306E\u3067\u3001\
    \u7B26\u53F7\u306A\u3057\u3067\u7B26\u53F7\u3092\u53CD\u8EE2\u3059\u308B\n   \
    \ return internal_io::write_u128(os, x < 0 ? -static_cast<unsigned __int128>(x)\
    \ : static_cast<unsigned __int128>(x), x < 0);\n}\ntemplate <typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, __uint128_t x) {\n    return internal_io::write_u128(os, x, false);\n\
    }\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B (pair<vector<int>, int> \u306A\u3069\
    ) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\u5148\u306B\u5BA3\u8A00\u3057\u3066\
    \u304A\u304F\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p);\ntemplate <typename T, std::size_t N,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::array<T, N>& a);\ntemplate <typename T, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v);\ntemplate <typename T1, typename T2, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::pair<T1, T2>& p);\ntemplate <typename... Types, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::tuple<Types...>& p);\ntemplate <typename T, std::size_t\
    \ N, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s);\n\nnamespace internal_io {\ntemplate <typename\
    \ Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& read_tuple(std::basic_istream<CharT, Traits>& is, Tuple& t) {\n   \
    \ is >> std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>) {\n\
    \        return read_tuple<Tuple, I + 1>(is, t);\n    }\n    return is;\n}\ntemplate\
    \ <typename Tuple, std::size_t I, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& write_tuple(std::basic_ostream<CharT, Traits>& os, const Tuple& t)\
    \ {\n    os << std::get<I>(t);\n    if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n        os << CharT(' ');\n        return write_tuple<Tuple, I + 1>(os, t);\n\
    \    }\n    return os;\n}\n};  // namespace internal_io\n\ntemplate <typename\
    \ T1, typename T2, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::pair<T1, T2>&\
    \ p) {\n    is >> p.first >> p.second;\n    return is;\n}\ntemplate <typename...\
    \ Types, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>&\
    \ operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>& p) {\n\
    \    return internal_io::read_tuple<std::tuple<Types...>, 0>(is, p);\n}\ntemplate\
    \ <typename T, std::size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a) {\n    for (auto& e : a) is >> e;\n    return is;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v) {\n    for (auto& e : v) is >> e;\n    return\
    \ is;\n}\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::pair<T1, T2>& p) {\n    os << p.first << CharT(' ') << p.second;\n\
    \    return os;\n}\ntemplate <typename... Types, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::tuple<Types...>& p) {\n    return internal_io::write_tuple<std::tuple<Types...>,\
    \ 0>(os, p);\n}\ntemplate <typename T, std::size_t N, typename CharT, typename\
    \ Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a) {\n    for (std::size_t i = 0; i < N;\
    \ ++i) {\n        if (i) os << CharT(' ');\n        os << a[i];\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v) {\n    for (std::size_t i = 0; i < v.size(); ++i) {\n        if (i) os <<\
    \ CharT(' ');\n        os << v[i];\n    }\n    return os;\n}\ntemplate <typename\
    \ T, typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s) {\n    for (auto itr = s.begin(); itr !=\
    \ s.end(); ++itr) {\n        if (itr != s.begin()) os << CharT(' ');\n       \
    \ os << *itr;\n    }\n    return os;\n}\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\
    \n */\ninline void print() { std::cout << '\\n'; }\n/**\n * @brief \u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\
    \u308B\u5024\n */\ntemplate <typename T>\nvoid print(const T& x) { std::cout <<\
    \ x << '\\n'; }\n/**\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\
    \u3057\u3066\u6539\u884C\n *\n * @tparam T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\
    \u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\
    \n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\u76EE\u4EE5\
    \u964D\u306E\u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\nvoid print(const\
    \ T& x, const Tail&... tail) {\n    std::cout << x << ' ';\n    print(tail...);\n\
    }\n\n/**\n * @brief \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u884C\
    \u51FA\u529B\n */\ninline void err() { std::cerr << std::endl; }\n/**\n * @brief\
    \ \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u51FA\u529B\u3057\u3066\u6539\
    \u884C\n *\n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\n\
    \ */\ntemplate <typename T>\nvoid err(const T& x) { std::cerr << x << std::endl;\
    \ }\n/**\n * @brief \u6A19\u6E96\u30A8\u30E9\u30FC\u51FA\u529B\u306B\u7A7A\u767D\
    \u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n *\n * @tparam T\
    \ 1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n * @tparam Tail 2\u3064\u76EE\u4EE5\
    \u964D\u306E\u8981\u7D20\u306E\u578B\n * @param x 1\u3064\u76EE\u306E\u8981\u7D20\
    \n * @param tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\n */\ntemplate <typename\
    \ T, typename... Tail>\nvoid err(const T& x, const Tail&... tail) {\n    std::cerr\
    \ << x << ' ';\n    err(tail...);\n}\n#line 2 \"src/utility/container_func.hpp\"\
    \n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\u30CA\u306B\
    \u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\n#line 9\
    \ \"src/utility/container_func.hpp\"\n#include <cassert>\n#line 11 \"src/utility/container_func.hpp\"\
    \n#include <functional>\n#include <initializer_list>\n#include <iterator>\n#include\
    \ <numeric>\n#include <type_traits>\n#line 17 \"src/utility/container_func.hpp\"\
    \n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief\
    \ \u578B\u7279\u6027\n */\n\n#line 14 \"src/utility/traits.hpp\"\n\nnamespace\
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
    #line 19 \"src/utility/container_func.hpp\"\n\n#define METHOD_EXPAND(func)   \
    \                                     \\\n    template <typename T, ENABLE_IF_T(has_##func##_v<T>)>\
    \          \\\n    inline constexpr auto func(const T& t) -> decltype(t.func())\
    \ { \\\n        return t.func();                                           \\\n\
    \    }\n\n#define METHOD_AND_FUNC_ARG_EXPAND(func)                           \
    \       \\\n    template <typename T, typename U, ENABLE_IF_T(has_##func##_v<T,\
    \ U>)>  \\\n    inline constexpr auto func(const T& t, const U& u)           \
    \         \\\n        -> decltype(t.func(u)) {                               \
    \           \\\n        return t.func(u);                                    \
    \             \\\n    }                                                      \
    \               \\\n    template <typename T, typename U, ENABLE_IF_T(!has_##func##_v<T,\
    \ U>)> \\\n    inline constexpr auto func(const T& t, const U& u)            \
    \        \\\n        -> decltype(std::func(t.begin(), t.end(), u)) {         \
    \          \\\n        return std::func(t.begin(), t.end(), u);              \
    \            \\\n    }\n\nMETHOD_EXPAND(reversed)\ntemplate <class C, ENABLE_IF_T(!has_reversed_v<C>)>\n\
    inline constexpr C reversed(C t) {\n    std::reverse(t.begin(), t.end());\n  \
    \  return t;\n}\n\nnamespace internal_container_func {\n// comp(proj(a), proj(b))\
    \ \u3067\u6BD4\u3079\u3089\u308C\u308B\u304B\ntemplate <class C, class F, class\
    \ P, class = void>\nstruct is_projected_comp : std::false_type {};\ntemplate <class\
    \ C, class F, class P>\nstruct is_projected_comp<C, F, P, std::void_t<std::invoke_result_t<P&,\
    \ const mem_value_type<C>&>>>\n    : std::is_invocable_r<bool, F&, std::invoke_result_t<P&,\
    \ const mem_value_type<C>&>, std::invoke_result_t<P&, const mem_value_type<C>&>>\
    \ {};\n}  // namespace internal_container_func\n\nMETHOD_EXPAND(sorted)\ntemplate\
    \ <class C, class F = std::less<>, class P = internal_traits::identity, ENABLE_IF_T(!has_sorted_v<C>\
    \ && internal_container_func::is_projected_comp<C, F, P>::value)>\ninline constexpr\
    \ C sorted(C t, F comp = F(), P proj = P()) {\n    std::sort(t.begin(), t.end(),\
    \ [&](const mem_value_type<C>& a, const mem_value_type<C>& b) {\n        return\
    \ std::invoke(comp, std::invoke(proj, a), std::invoke(proj, b));\n    });\n  \
    \  return t;\n}\n\ntemplate <class C, class F = std::less<>, class P = internal_traits::identity,\
    \ ENABLE_IF_T(internal_container_func::is_projected_comp<C, F, P>::value)>\ninline\
    \ constexpr void sort(C& t, F comp = F(), P proj = P()) {\n    std::sort(t.begin(),\
    \ t.end(), [&](const mem_value_type<C>& a, const mem_value_type<C>& b) {\n   \
    \     return std::invoke(comp, std::invoke(proj, a), std::invoke(proj, b));\n\
    \    });\n}\n// sort(c, {}, proj) \u7528\u3002std::vector \u306A\u3069\u3067\u306F\
    \ ADL \u3067 std::sort(first, last, comp) \u3082\u5019\u88DC\u306B\u306A\u308A\
    \u3001\n// {} \u3092 F \u3067\u53D7\u3051\u308B\u3068 std::sort \u304C\u9078\u3070\
    \u308C\u308B\u306E\u3067\u3001{} \u304C\u6A19\u6E96\u5909\u63DB\u3067\u6E21\u308B\
    \ std::nullptr_t \u3067\u53D7\u3051\u308B\ntemplate <class C, class P, ENABLE_IF_T(internal_container_func::is_projected_comp<C,\
    \ std::less<>, P>::value)>\ninline constexpr void sort(C& t, std::nullptr_t, P\
    \ proj) {\n    sort(t, std::less<>(), proj);\n}\n\ntemplate <class C>\ninline\
    \ constexpr void reverse(C& t) {\n    std::reverse(t.begin(), t.end());\n}\n\n\
    METHOD_EXPAND(max)\ntemplate <class C, ENABLE_IF_T(!has_max_v<C> && is_sorted_container_v<C>)>\n\
    inline constexpr mem_value_type<C> max(const C& v) {\n    assert(v.begin() !=\
    \ v.end());\n    return *v.rbegin();\n}\ntemplate <class C, ENABLE_IF_T(!has_max_v<C>\
    \ && !is_sorted_container_v<C>)>\ninline constexpr mem_value_type<C> max(const\
    \ C& v) {\n    assert(v.begin() != v.end());\n    return *std::max_element(v.begin(),\
    \ v.end());\n}\ntemplate <typename T>\ninline constexpr T max(const std::initializer_list<T>&\
    \ v) {\n    return std::max(v);\n}\n\nMETHOD_EXPAND(min)\ntemplate <class C, ENABLE_IF_T(!has_min_v<C>\
    \ && is_sorted_container_v<C>)>\ninline constexpr mem_value_type<C> min(const\
    \ C& v) {\n    assert(v.begin() != v.end());\n    return *v.begin();\n}\ntemplate\
    \ <class C, ENABLE_IF_T(!has_min_v<C> && !is_sorted_container_v<C>)>\ninline constexpr\
    \ mem_value_type<C> min(const C& v) {\n    assert(v.begin() != v.end());\n   \
    \ return *std::min_element(v.begin(), v.end());\n}\ntemplate <typename T>\ninline\
    \ constexpr T min(const std::initializer_list<T>& v) {\n    return std::min(v);\n\
    }\n\nMETHOD_EXPAND(sum)\ntemplate <class C, ENABLE_IF_T(!has_sum_v<C>)>\ninline\
    \ constexpr mem_value_type<C> sum(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{});\n}\ntemplate <typename T>\ninline constexpr T\
    \ sum(const std::initializer_list<T>& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), T{});\n}\n\nMETHOD_EXPAND(product)\ntemplate <class C, ENABLE_IF_T(!has_product_v<C>)>\n\
    inline constexpr mem_value_type<C> product(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{1}, std::multiplies<mem_value_type<C>>());\n}\ntemplate\
    \ <typename T>\ninline constexpr T product(const std::initializer_list<T>& v)\
    \ {\n    return std::accumulate(v.begin(), v.end(), T{1}, std::multiplies<T>());\n\
    }\n\nMETHOD_EXPAND(product_xor)\ntemplate <class C, ENABLE_IF_T(!has_product_xor_v<C>)>\n\
    inline constexpr mem_value_type<C> product_xor(const C& v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), mem_value_type<C>{0}, std::bit_xor<mem_value_type<C>>());\n}\ntemplate\
    \ <typename T>\ninline constexpr T product_xor(const std::initializer_list<T>&\
    \ v) {\n    return std::accumulate(v.begin(), v.end(), T{0}, std::bit_xor<T>());\n\
    }\n\nMETHOD_AND_FUNC_ARG_EXPAND(count)\nMETHOD_AND_FUNC_ARG_EXPAND(find)\nMETHOD_AND_FUNC_ARG_EXPAND(lower_bound)\n\
    METHOD_AND_FUNC_ARG_EXPAND(upper_bound)\n\ntemplate <class C, typename T>\ninline\
    \ constexpr bool contains(const C& c, const T& t) {\n    return find(c, t) !=\
    \ c.end();\n}\n\ntemplate <class C>\ninline constexpr mem_value_type<C> gcd(const\
    \ C& v) {\n    mem_value_type<C> init(0);\n    for (const auto& e : v) init =\
    \ std::gcd(init, e);\n    return init;\n}\n\ntemplate <class C>\ninline constexpr\
    \ mem_value_type<C> average(const C& v) {\n    assert(v.size());\n    // v.size()\
    \ \u306F\u7B26\u53F7\u306A\u3057\u306A\u306E\u3067\u3001\u305D\u306E\u307E\u307E\
    \u5272\u308B\u3068\u8CA0\u306E\u548C\u304C\u7B26\u53F7\u306A\u3057\u306B\u5909\
    \u63DB\u3055\u308C\u3066\u58CA\u308C\u308B\n    return sum(v) / static_cast<mem_value_type<C>>(v.size());\n\
    }\n\ntemplate <class C>\ninline constexpr mem_value_type<C> median(const C& v)\
    \ {\n    assert(!v.empty());\n    std::vector<std::size_t> u(v.size());\n    std::iota(u.begin(),\
    \ u.end(), 0);\n    std::sort(u.begin(), u.end(), [&](std::size_t a, std::size_t\
    \ b) {\n        return v[a] < v[b];\n    });\n    if (v.size() & 1) {\n      \
    \  return v[u[v.size() / 2]];\n    }\n    // C++20\n    // return std::midpoint(v[u[v.size()\
    \ / 2]], v[u[v.size() / 2 - 1]]);\n    return (v[u[v.size() / 2]] + v[u[v.size()\
    \ / 2 - 1]]) / 2;\n}\n\n// x \u304C\u6700\u521D\u306B\u73FE\u308C\u308B\u4F4D\u7F6E\
    \u3002\u306A\u3051\u308C\u3070 -1\ntemplate <class C, typename U>\ninline constexpr\
    \ long long index(const C& v, const U& x) {\n    auto it = find(v, x);\n    if\
    \ (it == v.end()) return -1;\n    return static_cast<long long>(std::distance(v.begin(),\
    \ it));\n}\n\n// f(x) \u304C true \u306B\u306A\u308B\u6700\u521D\u306E\u4F4D\u7F6E\
    \u3002\u306A\u3051\u308C\u3070 -1\ntemplate <class C, class F>\ninline constexpr\
    \ long long index_if(const C& v, F f) {\n    long long i = 0;\n    for (const\
    \ auto& e : v) {\n        if (f(e)) return i;\n        i++;\n    }\n    return\
    \ -1;\n}\n\n// f(x) \u304C true \u306B\u306A\u308B\u4F4D\u7F6E\u3092\u6607\u9806\
    \u306B\u4E26\u3079\u305F\u3082\u306E\ntemplate <class C, class F>\ninline std::vector<long\
    \ long> indices_if(const C& v, F f) {\n    std::vector<long long> res;\n    long\
    \ long i = 0;\n    for (const auto& e : v) {\n        if (f(e)) res.push_back(i);\n\
    \        i++;\n    }\n    return res;\n}\n\n// f(x) \u304C true \u306B\u306A\u308B\
    \u8981\u7D20\u306E\u500B\u6570\ntemplate <class C, class F>\ninline constexpr\
    \ long long count_if(const C& v, F f) {\n    long long res = 0;\n    for (const\
    \ auto& e : v) {\n        if (f(e)) res++;\n    }\n    return res;\n}\n\ntemplate\
    \ <class C, ENABLE_IF_T(std::is_integral_v<mem_value_type<C>>)>\ninline constexpr\
    \ mem_value_type<C> mex(const C& v) {\n    std::vector<bool> b(v.size() + 1);\n\
    \    for (const auto& a : v) {\n        if (0 <= a && static_cast<std::size_t>(a)\
    \ < b.size()) {\n            b[a] = true;\n        }\n    }\n    mem_value_type<C>\
    \ ret = 0;  // b \u306E\u8981\u7D20\u6570\u306F v \u3088\u308A 1 \u591A\u3044\u306E\
    \u3067\u3001\u4E0B\u306E\u30EB\u30FC\u30D7\u3067\u5FC5\u305A\u898B\u3064\u304B\
    \u308B\n    for (std::size_t i = 0; i < b.size(); i++) {\n        if (!b[i]) {\n\
    \            ret = i;\n            break;\n        }\n    }\n    return ret;\n\
    }\n\ntemplate <class C>\ninline constexpr long long bisect_left(const C& v, const\
    \ mem_value_type<C>& x) {\n    return static_cast<long long>(std::distance(v.begin(),\
    \ lower_bound(v, x)));\n}\ntemplate <class C>\ninline constexpr long long bisect_right(const\
    \ C& v, const mem_value_type<C>& x) {\n    return static_cast<long long>(std::distance(v.begin(),\
    \ upper_bound(v, x)));\n}\n#line 8 \"test/aoj/itp1/itp1-2-c.test.cpp\"\n\nint\
    \ main() {\n    int a, b, c;\n    std::cin >> a >> b >> c;\n    std::vector<int>\
    \ v = sorted(std::vector<int>{a, b, c});\n    print(v[0], v[1], v[2]);  // \u7A7A\
    \u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_2_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/base/io.hpp\"\
    \n#include \"../../../src/utility/container_func.hpp\"\n\nint main() {\n    int\
    \ a, b, c;\n    std::cin >> a >> b >> c;\n    std::vector<int> v = sorted(std::vector<int>{a,\
    \ b, c});\n    print(v[0], v[1], v[2]);  // \u7A7A\u767D\u533A\u5207\u308A\u3067\
    \u51FA\u529B\u3057\u3066\u6539\u884C\n}\n"
  dependsOn:
  - src/base/io.hpp
  - src/utility/container_func.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/aoj/itp1/itp1-2-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 16:27:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp1/itp1-2-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp1/itp1-2-c.test.cpp
- /verify/test/aoj/itp1/itp1-2-c.test.cpp.html
title: test/aoj/itp1/itp1-2-c.test.cpp
---
