---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base/container_func.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
      \ max, sum \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/base/io.hpp
    title: "\u7A7A\u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\
      \u30D0\u30FC\u30ED\u30FC\u30C9"
  - icon: ':heavy_check_mark:'
    path: src/base/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A
  bundledCode: "#line 1 \"test/aoj/itp1-6-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/base/container_func.hpp\"\
    \n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\u30CA\u306B\
    \u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#line 10 \"src/base/container_func.hpp\"\n#include <functional>\n\
    #include <initializer_list>\n#include <iterator>\n#include <numeric>\n#line 2\
    \ \"src/base/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\
    \n */\n\n#include <cstddef>\n#line 10 \"src/base/traits.hpp\"\n#include <set>\n\
    #include <type_traits>\n#include <utility>\n\nnamespace detail {\nusing std::begin,\
    \ std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type\
    \ {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace detail\n\n\
    template <class T>\nstruct is_range : detail::is_range_impl<T>::type {};\ntemplate\
    \ <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define\
    \ HAS_METHOD(func_name)                                                      \
    \        \\\n    namespace detail {                                          \
    \                           \\\n    template <class T, class = void>         \
    \                                              \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : detail::has_##func_name##_impl<T>::type {};                   \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace detail {              \
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
    \                                          \\\n    struct has_##func_name : detail::has_##func_name##_impl<T,\
    \ U>::type {};                                    \\\n    template <class T, typename\
    \ U>                                                                         \
    \    \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ detail {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace detail\ntemplate <class T>\nstruct is_sorted_container\
    \ : detail::is_sorted_container_impl<T>::type {};\ntemplate <class T>\ninline\
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n#line\
    \ 16 \"src/base/container_func.hpp\"\n\n#define METHOD_EXPAND(func)          \
    \                              \\\n    template <typename T, ENABLE_IF_T(has_##func##_v<T>)>\
    \          \\\n    inline constexpr auto func(const T &t) -> decltype(t.func())\
    \ { \\\n        return t.func();                                           \\\n\
    \    }\n\n#define METHOD_AND_FUNC_ARG_EXPAND(func)                           \
    \          \\\n    template <typename T, typename U, ENABLE_IF_T(has_##func##_v<T,\
    \ U>)>     \\\n    inline constexpr auto func(const T &t, const U &u)        \
    \               \\\n        -> decltype(t.func(u)) {                         \
    \                    \\\n        return t.func(u);                           \
    \                         \\\n    }                                          \
    \                              \\\n    template <typename T, typename U, ENABLE_IF_T(not\
    \ has_##func##_v<T, U>)> \\\n    inline constexpr auto func(const T &t, const\
    \ U &u)                       \\\n        -> decltype(std::func(t.begin(), t.end(),\
    \ u)) {                      \\\n        return std::func(t.begin(), t.end(),\
    \ u);                             \\\n    }\n\nMETHOD_EXPAND(reversed)\ntemplate\
    \ <class C, ENABLE_IF_T(not has_reversed_v<C>)>\ninline constexpr C reversed(C\
    \ t) {\n    std::reverse(t.begin(), t.end());\n    return t;\n}\n\nMETHOD_EXPAND(sorted)\n\
    template <class C, ENABLE_IF_T(not has_sorted_v<C>)>\ninline constexpr C sorted(C\
    \ t, bool reverse = false) {\n    std::sort(t.begin(), t.end());\n    if (reverse)\
    \ std::reverse(t.begin(), t.end());\n    return t;\n}\ntemplate <class C, class\
    \ F, ENABLE_IF_T(not has_sorted_v<C> and std::is_invocable_r_v<bool, F, mem_value_type<C>,\
    \ mem_value_type<C>>)>\ninline constexpr C sorted(C t, F f) {\n    std::sort(t.begin(),\
    \ t.end(), f);\n    return t;\n}\n\ntemplate <class C>\ninline constexpr void\
    \ sort(C &t, bool reverse = false) {\n    std::sort(t.begin(), t.end());\n   \
    \ if (reverse) std::reverse(t.begin(), t.end());\n}\ntemplate <class C, class\
    \ F, ENABLE_IF_T(std::is_invocable_r_v<bool, F, mem_value_type<C>, mem_value_type<C>>)>\n\
    inline constexpr void sort(C &t, F f) {\n    std::sort(t.begin(), t.end(), f);\n\
    }\ntemplate <class C, class F, ENABLE_IF_T(std::is_invocable_v<F, mem_value_type<C>>)>\n\
    inline constexpr void sort_by_key(C &t, F f) {\n    std::sort(t.begin(), t.end(),\
    \ [&](const mem_value_type<C> &left, const mem_value_type<C> &right) {\n     \
    \   return f(left) < f(right);\n    });\n}\n\ntemplate <class C>\ninline constexpr\
    \ void reverse(C &t) {\n    std::reverse(t.begin(), t.end());\n}\n\nMETHOD_EXPAND(max)\n\
    template <class C, ENABLE_IF_T(not has_max_v<C> and is_sorted_container_v<C>)>\n\
    inline constexpr mem_value_type<C> max(const C &v) {\n    assert(v.begin() !=\
    \ v.end());\n    return *v.rbegin();\n}\ntemplate <class C, ENABLE_IF_T(not has_max_v<C>\
    \ and not is_sorted_container_v<C>)>\ninline constexpr mem_value_type<C> max(const\
    \ C &v) {\n    assert(v.begin() != v.end());\n    return *std::max_element(v.begin(),\
    \ v.end());\n}\ntemplate <typename T>\ninline constexpr T max(const std::initializer_list<T>\
    \ &v) {\n    return std::max(v);\n}\n\nMETHOD_EXPAND(min)\ntemplate <class C,\
    \ ENABLE_IF_T(not has_max_v<C> and is_sorted_container_v<C>)>\ninline constexpr\
    \ mem_value_type<C> min(const C &v) {\n    assert(v.begin() != v.end());\n   \
    \ return *v.begin();\n}\ntemplate <class C, ENABLE_IF_T(not has_max_v<C> and not\
    \ is_sorted_container_v<C>)>\ninline constexpr mem_value_type<C> min(const C &v)\
    \ {\n    assert(v.begin() != v.end());\n    return *std::min_element(v.begin(),\
    \ v.end());\n}\ntemplate <typename T>\ninline constexpr T min(const std::initializer_list<T>\
    \ &v) {\n    return std::min(v);\n}\n\nMETHOD_EXPAND(sum)\ntemplate <class C,\
    \ ENABLE_IF_T(not has_sum_v<C>)>\ninline constexpr mem_value_type<C> sum(const\
    \ C &v) {\n    return std::accumulate(v.begin(), v.end(), mem_value_type<C>{});\n\
    }\ntemplate <typename T>\ninline constexpr T sum(const std::initializer_list<T>\
    \ &v) {\n    return std::accumulate(v.begin(), v.end(), T{});\n}\n\nMETHOD_EXPAND(product)\n\
    template <class C, ENABLE_IF_T(not has_product_v<C>)>\ninline constexpr mem_value_type<C>\
    \ product(const C &v) {\n    return std::accumulate(v.begin(), v.end(), mem_value_type<C>{1},\
    \ std::multiplies<mem_value_type<C>>());\n}\ntemplate <typename T>\ninline constexpr\
    \ T product(const std::initializer_list<T> &v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), T{1}, std::multiplies<T>());\n}\n\nMETHOD_EXPAND(product_xor)\ntemplate\
    \ <class C, ENABLE_IF_T(not has_product_xor_v<C>)>\ninline constexpr mem_value_type<C>\
    \ product_xor(const C &v) {\n    return std::accumulate(v.begin(), v.end(), mem_value_type<C>{0},\
    \ std::bit_xor<mem_value_type<C>>());\n}\ntemplate <typename T>\ninline constexpr\
    \ T product_xor(const std::initializer_list<T> &v) {\n    return std::accumulate(v.begin(),\
    \ v.end(), T{0}, std::bit_xor<T>());\n}\n\ntemplate <class C>\ninline constexpr\
    \ mem_value_type<C> maximum_subarray(const C &v) {\n    assert(not v.empty());\n\
    \    auto itr = v.begin();\n    mem_value_type<C> tmp = *itr++;\n    mem_value_type<C>\
    \ res = tmp;\n    while (itr != v.end()) {\n        tmp += *itr;\n        if (tmp\
    \ < *itr) tmp = *itr;\n        if (res < tmp) res = tmp;\n        ++itr;\n   \
    \ }\n    return res;\n}\ntemplate <class C>\ninline constexpr mem_value_type<C>\
    \ maximum_subarray(const C &v, mem_value_type<C> init) {\n    mem_value_type<C>\
    \ res = init, tmp = init;\n    for (const auto &a : v) {\n        tmp += a;\n\
    \        if (tmp < init) tmp = init;\n        if (res < tmp) res = tmp;\n    }\n\
    \    return res;\n}\n\nMETHOD_AND_FUNC_ARG_EXPAND(count)\nMETHOD_AND_FUNC_ARG_EXPAND(find)\n\
    METHOD_AND_FUNC_ARG_EXPAND(lower_bound)\nMETHOD_AND_FUNC_ARG_EXPAND(upper_bound)\n\
    \ntemplate <class C, typename T>\ninline constexpr bool contains(const C &c, const\
    \ T &t) {\n    return find(c, t) != c.end();\n}\n\ntemplate <class C>\ninline\
    \ constexpr mem_value_type<C> gcd(const C &v) {\n    mem_value_type<C> init(0);\n\
    \    for (const auto &e : v) init = std::gcd(init, e);\n    return init;\n}\n\n\
    template <class C>\ninline constexpr mem_value_type<C> average(const C &v) {\n\
    \    assert(v.size());\n    return sum(v) / v.size();\n}\n\ntemplate <class C>\n\
    inline constexpr mem_value_type<C> median(const C &v) {\n    assert(not v.empty());\n\
    \    std::vector<size_t> u(v.size());\n    std::iota(u.begin(), u.end(), 0);\n\
    \    std::sort(u.begin(), u.end(), [&](size_t a, size_t b) {\n        return v[a]\
    \ < v[b];\n    });\n    if (v.size() & 1) {\n        return v[u[v.size() / 2]];\n\
    \    }\n    // C++20\n    // return std::midpoint(v[u[v.size() / 2]], v[u[v.size()\
    \ / 2 - 1]]);\n    return (v[u[v.size() / 2]] + v[u[v.size() / 2 - 1]]) / 2;\n\
    }\n\ntemplate <class C, typename U>\ninline constexpr std::ptrdiff_t index(const\
    \ C &v, const U &x) {\n    return std::distance(v.begin(), find(v, x));\n}\n\n\
    template <class C, ENABLE_IF_T(std::is_integral_v<mem_value_type<C>>)>\ninline\
    \ constexpr mem_value_type<C> mex(const C &v) {\n    std::vector<bool> b(v.size()\
    \ + 1);\n    for (const auto &a : v) {\n        if (0 <= a and a < b.size()) {\n\
    \            b[a] = true;\n        }\n    }\n    mem_value_type<C> ret;\n    for\
    \ (size_t i = 0; i < b.size(); i++) {\n        if (not b[i]) {\n            ret\
    \ = i;\n            break;\n        }\n    }\n    return ret;\n}\n\ntemplate <class\
    \ C>\ninline constexpr mem_difference_type<C> bisect_left(const C &v, const mem_value_type<C>\
    \ &x) {\n    return std::distance(v.begin(), lower_bound(v, x));\n}\ntemplate\
    \ <class C>\ninline constexpr mem_difference_type<C> bisect_right(const C &v,\
    \ const mem_value_type<C> &x) {\n    return std::distance(v.begin(), upper_bound(v,\
    \ x));\n}\n#line 2 \"src/base/io.hpp\"\n/**\n * @file io.hpp\n * @brief \u7A7A\
    \u767D\u533A\u5207\u308A\u51FA\u529B\u3001iostream\u306E\u30AA\u30FC\u30D0\u30FC\
    \u30ED\u30FC\u30C9\n */\n\n#include <array>\n#line 11 \"src/base/io.hpp\"\n#include\
    \ <tuple>\n#line 13 \"src/base/io.hpp\"\n\n// \u30CD\u30B9\u30C8\u3057\u305F\u578B\
    \ (pair<vector<int>, int> \u306A\u3069) \u3092\u6271\u3048\u308B\u3088\u3046\u306B\
    \u5148\u306B\u5BA3\u8A00\u3057\u3066\u304A\u304F\ntemplate <typename T1, typename\
    \ T2, typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::pair<T1, T2>& p);\ntemplate <typename... Types, typename CharT,\
    \ typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::tuple<Types...>& p);\ntemplate <typename T, size_t N, typename\
    \ CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::array<T, N>& a);\ntemplate <typename T, typename CharT, typename\
    \ Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v);\ntemplate <typename T1, typename T2, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::pair<T1, T2>& p);\ntemplate <typename... Types, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::tuple<Types...>& p);\ntemplate <typename T, size_t N,\
    \ typename CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::array<T, N>& a);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::vector<T>& v);\ntemplate <typename T, typename CharT,\
    \ typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s);\n\nnamespace tuple_io {\n    template <typename\
    \ Tuple, size_t I, typename CharT, typename Traits>\n    std::basic_istream<CharT,\
    \ Traits>& read_tuple(std::basic_istream<CharT, Traits>& is, Tuple& t) {\n   \
    \     is >> std::get<I>(t);\n        if constexpr (I + 1 < std::tuple_size_v<Tuple>)\
    \ {\n            return read_tuple<Tuple, I + 1>(is, t);\n        }\n        return\
    \ is;\n    }\n    template <typename Tuple, size_t I, typename CharT, typename\
    \ Traits>\n    std::basic_ostream<CharT, Traits>& write_tuple(std::basic_ostream<CharT,\
    \ Traits>& os, const Tuple& t) {\n        os << std::get<I>(t);\n        if constexpr\
    \ (I + 1 < std::tuple_size_v<Tuple>) {\n            os << CharT(' ');\n      \
    \      return write_tuple<Tuple, I + 1>(os, t);\n        }\n        return os;\n\
    \    }\n};\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT, Traits>&\
    \ is, std::pair<T1, T2>& p) {\n    is >> p.first >> p.second;\n    return is;\n\
    }\ntemplate <typename... Types, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::tuple<Types...>&\
    \ p) {\n    return tuple_io::read_tuple<std::tuple<Types...>, 0>(is, p);\n}\n\
    template <typename T, size_t N, typename CharT, typename Traits>\nstd::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, std::array<T, N>&\
    \ a) {\n    for(auto& e : a) is >> e;\n    return is;\n}\ntemplate <typename T,\
    \ typename CharT, typename Traits>\nstd::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, std::vector<T>& v) {\n    for(auto& e : v) is >> e;\n    return\
    \ is;\n}\n\ntemplate <typename T1, typename T2, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::pair<T1, T2>& p) {\n    os << p.first << CharT(' ') << p.second;\n\
    \    return os;\n}\ntemplate <typename... Types, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::tuple<Types...>& p) {\n    return tuple_io::write_tuple<std::tuple<Types...>,\
    \ 0>(os, p);\n}\ntemplate <typename T, size_t N, typename CharT, typename Traits>\n\
    std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>&\
    \ os, const std::array<T, N>& a) {\n    for(size_t i = 0; i < N; ++i) {\n    \
    \    if(i) os << CharT(' ');\n        os << a[i];\n    }\n    return os;\n}\n\
    template <typename T, typename CharT, typename Traits>\nstd::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const std::vector<T>&\
    \ v) {\n    for(size_t i = 0; i < v.size(); ++i) {\n        if(i) os << CharT('\
    \ ');\n        os << v[i];\n    }\n    return os;\n}\ntemplate <typename T, typename\
    \ CharT, typename Traits>\nstd::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const std::set<T>& s) {\n    for(auto itr = s.begin(); itr != s.end();\
    \ ++itr) {\n        if(itr != s.begin()) os << CharT(' ');\n        os << *itr;\n\
    \    }\n    return os;\n}\n\n/**\n * @brief \u7A7A\u884C\u51FA\u529B\n */\ninline\
    \ void print() { std::cout << '\\n'; }\n/**\n * @brief \u51FA\u529B\u3057\u3066\
    \u6539\u884C\n * \n * @tparam T \u578B\n * @param x \u51FA\u529B\u3059\u308B\u5024\
    \n */\ntemplate <typename T>\nvoid print(const T& x) { std::cout << x << '\\n';\
    \ }\n/**\n * @brief \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\
    \u6539\u884C\n * \n * @tparam T 1\u3064\u76EE\u306E\u8981\u7D20\u306E\u578B\n\
    \ * @tparam Tail 2\u3064\u76EE\u4EE5\u964D\u306E\u8981\u7D20\u306E\u578B\n * @param\
    \ x 1\u3064\u76EE\u306E\u8981\u7D20\n * @param tail 2\u3064\u76EE\u4EE5\u964D\u306E\
    \u8981\u7D20\n */\ntemplate <typename T, typename... Tail>\nvoid print(const T&\
    \ x, const Tail&... tail) {\n    std::cout << x << ' ';\n    print(tail...);\n\
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
    \ << x << ' ';\n    err(tail...);\n}\n#line 9 \"test/aoj/itp1-6-a.test.cpp\"\n\
    \nint main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n \
    \   std::cin >> a;\n    std::vector<int> b = reversed(a);  // \u9006\u9806\u306B\
    \u3057\u305F\u30B3\u30D4\u30FC\n    reverse(a);                        // \u305D\
    \u306E\u5834\u3067\u9006\u9806\u306B\u3059\u308B\n    assert(a == b);\n    print(a);\
    \  // \u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\
    \n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A\"\
    \n\n#include <cassert>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../src/base/container_func.hpp\"\n#include \"../../src/base/io.hpp\"\n\nint\
    \ main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    std::cin\
    \ >> a;\n    std::vector<int> b = reversed(a);  // \u9006\u9806\u306B\u3057\u305F\
    \u30B3\u30D4\u30FC\n    reverse(a);                        // \u305D\u306E\u5834\
    \u3067\u9006\u9806\u306B\u3059\u308B\n    assert(a == b);\n    print(a);  // \u7A7A\
    \u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3066\u6539\u884C\n}\n"
  dependsOn:
  - src/base/container_func.hpp
  - src/base/traits.hpp
  - src/base/io.hpp
  isVerificationFile: true
  path: test/aoj/itp1-6-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 01:36:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/itp1-6-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/itp1-6-a.test.cpp
- /verify/test/aoj/itp1-6-a.test.cpp.html
title: test/aoj/itp1-6-a.test.cpp
---
