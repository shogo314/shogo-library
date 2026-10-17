---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/container_func.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
      \ max, sum \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  - icon: ':heavy_check_mark:'
    path: src/utility/vector_func.hpp
    title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"test/aoj/dsl-4-a.1.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/utility/container_func.hpp\"\
    \n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\u30CA\u306B\
    \u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cstddef>\n#include <functional>\n\
    #include <initializer_list>\n#include <iterator>\n#include <numeric>\n#include\
    \ <type_traits>\n#line 17 \"src/utility/container_func.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#line 10 \"\
    src/utility/traits.hpp\"\n#include <set>\n#line 12 \"src/utility/traits.hpp\"\n\
    #include <utility>\n\nnamespace internal_traits {\nusing std::begin, std::end;\n\
    \ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \  return t;\n}\n\nMETHOD_EXPAND(sorted)\ntemplate <class C, ENABLE_IF_T(!has_sorted_v<C>)>\n\
    inline constexpr C sorted(C t, bool reverse = false) {\n    std::sort(t.begin(),\
    \ t.end());\n    if (reverse) std::reverse(t.begin(), t.end());\n    return t;\n\
    }\ntemplate <class C, class F, ENABLE_IF_T(!has_sorted_v<C> && std::is_invocable_r_v<bool,\
    \ F, mem_value_type<C>, mem_value_type<C>>)>\ninline constexpr C sorted(C t, F\
    \ f) {\n    std::sort(t.begin(), t.end(), f);\n    return t;\n}\n\ntemplate <class\
    \ C>\ninline constexpr void sort(C& t, bool reverse = false) {\n    std::sort(t.begin(),\
    \ t.end());\n    if (reverse) std::reverse(t.begin(), t.end());\n}\ntemplate <class\
    \ C, class F, ENABLE_IF_T(std::is_invocable_r_v<bool, F, mem_value_type<C>, mem_value_type<C>>)>\n\
    inline constexpr void sort(C& t, F f) {\n    std::sort(t.begin(), t.end(), f);\n\
    }\ntemplate <class C, class F, ENABLE_IF_T(std::is_invocable_v<F, mem_value_type<C>>)>\n\
    inline constexpr void sort_by_key(C& t, F f) {\n    std::sort(t.begin(), t.end(),\
    \ [&](const mem_value_type<C>& left, const mem_value_type<C>& right) {\n     \
    \   return f(left) < f(right);\n    });\n}\n\ntemplate <class C>\ninline constexpr\
    \ void reverse(C& t) {\n    std::reverse(t.begin(), t.end());\n}\n\nMETHOD_EXPAND(max)\n\
    template <class C, ENABLE_IF_T(!has_max_v<C> && is_sorted_container_v<C>)>\ninline\
    \ constexpr mem_value_type<C> max(const C& v) {\n    assert(v.begin() != v.end());\n\
    \    return *v.rbegin();\n}\ntemplate <class C, ENABLE_IF_T(!has_max_v<C> && !is_sorted_container_v<C>)>\n\
    inline constexpr mem_value_type<C> max(const C& v) {\n    assert(v.begin() !=\
    \ v.end());\n    return *std::max_element(v.begin(), v.end());\n}\ntemplate <typename\
    \ T>\ninline constexpr T max(const std::initializer_list<T>& v) {\n    return\
    \ std::max(v);\n}\n\nMETHOD_EXPAND(min)\ntemplate <class C, ENABLE_IF_T(!has_min_v<C>\
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
    \ it));\n}\n\ntemplate <class C, ENABLE_IF_T(std::is_integral_v<mem_value_type<C>>)>\n\
    inline constexpr mem_value_type<C> mex(const C& v) {\n    std::vector<bool> b(v.size()\
    \ + 1);\n    for (const auto& a : v) {\n        if (0 <= a && static_cast<std::size_t>(a)\
    \ < b.size()) {\n            b[a] = true;\n        }\n    }\n    mem_value_type<C>\
    \ ret = 0;  // b \u306E\u8981\u7D20\u6570\u306F v \u3088\u308A 1 \u591A\u3044\u306E\
    \u3067\u3001\u4E0B\u306E\u30EB\u30FC\u30D7\u3067\u5FC5\u305A\u898B\u3064\u304B\
    \u308B\n    for (std::size_t i = 0; i < b.size(); i++) {\n        if (!b[i]) {\n\
    \            ret = i;\n            break;\n        }\n    }\n    return ret;\n\
    }\n\ntemplate <class C>\ninline constexpr long long bisect_left(const C& v, const\
    \ mem_value_type<C>& x) {\n    return static_cast<long long>(std::distance(v.begin(),\
    \ lower_bound(v, x)));\n}\ntemplate <class C>\ninline constexpr long long bisect_right(const\
    \ C& v, const mem_value_type<C>& x) {\n    return static_cast<long long>(std::distance(v.begin(),\
    \ upper_bound(v, x)));\n}\n#line 2 \"src/utility/vector_func.hpp\"\n\n/**\n *\
    \ @file vector_func.hpp\n * @brief vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\
    \u5B50\u3068\u95A2\u6570\n */\n\n#line 10 \"src/utility/vector_func.hpp\"\n#include\
    \ <cmath>\n#line 15 \"src/utility/vector_func.hpp\"\n\n#line 17 \"src/utility/vector_func.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<long long> sorted_idx(const std::vector<T>&\
    \ v, bool reverse = false) {\n    std::vector<long long> ret(v.size());\n    std::iota(ret.begin(),\
    \ ret.end(), 0LL);\n    std::sort(ret.begin(), ret.end(), [&](long long i, long\
    \ long j) {\n        return v[i] < v[j];\n    });\n    if (reverse) std::reverse(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n\ntemplate <typename T>\ninline std::vector<T>&\
    \ operator++(std::vector<T>& v) {\n    for (auto& e : v) e++;\n    return v;\n\
    }\ntemplate <typename T>\ninline std::vector<T> operator++(std::vector<T>& v,\
    \ int) {\n    auto res = v;\n    for (auto& e : v) e++;\n    return res;\n}\n\
    template <typename T>\ninline std::vector<T>& operator--(std::vector<T>& v) {\n\
    \    for (auto& e : v) e--;\n    return v;\n}\ntemplate <typename T>\ninline std::vector<T>\
    \ operator--(std::vector<T>& v, int) {\n    auto res = v;\n    for (auto& e :\
    \ v) e--;\n    return res;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T>& operator+=(std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n   \
    \ }\n    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n\
    \    }\n    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    std::vector<T> res(v1);\n    return res += v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>&\
    \ operator+=(std::vector<T>& v, const U& u) {\n    for (T& e : v) {\n        e\
    \ += u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T>& v, const U& u) {\n\
    \    std::vector<T> res(v);\n    return res += u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator+(const U& u, const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    return res += u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T>& operator*=(std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n   \
    \ }\n    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] *= v2[i];\n\
    \    }\n    for (std::size_t i = v2.size(); i < v1.size(); i++) {\n        v1[i]\
    \ *= U(0);\n    }\n    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    std::vector<T> res(v1);\n    return res *= v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>&\
    \ operator*=(std::vector<T>& v, const U& u) {\n    for (T& e : v) {\n        e\
    \ *= u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T>& v, const U& u) {\n\
    \    std::vector<T> res(v);\n    return res *= u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator*(const U& u, const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    return res *= u;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>&\
    \ assign(std::vector<T>& v1, const std::vector<U>& v2) {\n    v1.assign(v2.begin(),\
    \ v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>&\
    \ extend(std::vector<T>& v1, const std::vector<U>& v2) {\n    v1.insert(v1.end(),\
    \ v2.begin(), v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>& operator|=(std::vector<T>&\
    \ v1, const std::vector<U>& v2) {\n    return extend(v1, v2);\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>& operator|=(std::vector<T>&\
    \ v, const U& u) {\n    std::vector<T> w(v);\n    v.clear();\n    for (int i =\
    \ 0; i < u; i++) {\n        extend(v, w);\n    }\n    return v;\n}\n\ntemplate\
    \ <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>\
    \ operator|(const std::vector<T>& v, const U& u) {\n    std::vector<T> res(v);\n\
    \    return res |= u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const U& u, const std::vector<T>& v) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T>\ninline std::vector<T>\
    \ abs(const std::vector<T>& v) {\n    std::vector<T> ret;\n    ret.reserve(v.size());\n\
    \    for (const T& e : v) ret.push_back(std::abs(e));\n    return ret;\n}\n\n\
    template <typename T>\nstd::vector<T> cumulative_sum(std::vector<T> v) {\n   \
    \ v.insert(v.begin(), T{});\n    std::vector<T> ret(v.size());\n    std::partial_sum(v.begin(),\
    \ v.end(), ret.begin());\n    return ret;\n}\n\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    std::vector<T> iota(T n) {\n    assert(n >= 0);\n    std::vector<T> ret(n);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n    return ret;\n}\n\ntemplate <typename\
    \ T, typename U>\nlong long hamming_distance(const std::vector<T>& v1, const std::vector<U>&\
    \ v2) {\n    assert(v1.size() == v2.size());\n    long long res = 0;\n    for\
    \ (std::size_t i = 0; i < v1.size(); i++) {\n        if (!(v1[i] == v2[i])) res++;\n\
    \    }\n    return res;\n}\n\ntemplate <typename T>\nstd::vector<T> unique(const\
    \ std::vector<T>& v) {\n    std::vector<T> res(v);\n    std::sort(res.begin(),\
    \ res.end());\n    res.erase(std::unique(res.begin(), res.end()), res.end());\n\
    \    return res;\n}\n\ninline long long radix_convert(const std::vector<long long>&\
    \ v, int base = 10) {\n    long long res = 0;\n    for (long long d : v) {\n \
    \       res = res * base + d;\n    }\n    return res;\n}\n\ninline std::vector<long\
    \ long> radix_convert(long long v, int base = 10) {\n    std::vector<long long>\
    \ res;\n    while (v > 0) {\n        res.push_back(v % base);\n        v /= base;\n\
    \    }\n    std::reverse(res.begin(), res.end());\n    return res;\n}\n#line 8\
    \ \"test/aoj/dsl-4-a.1.test.cpp\"\n\nint main() {\n    int n;\n    std::cin >>\
    \ n;\n    std::vector<long long> x1(n), y1(n), x2(n), y2(n);\n    std::vector<long\
    \ long> xs, ys;\n    for (int i = 0; i < n; i++) {\n        std::cin >> x1[i]\
    \ >> y1[i] >> x2[i] >> y2[i];\n        xs.push_back(x1[i]), xs.push_back(x2[i]);\n\
    \        ys.push_back(y1[i]), ys.push_back(y2[i]);\n    }\n    // \u5EA7\u6A19\
    \u5727\u7E2E\n    xs = unique(xs);\n    ys = unique(ys);\n    int w = xs.size(),\
    \ h = ys.size();\n    std::vector<std::vector<int>> imos(w, std::vector<int>(h));\n\
    \    for (int i = 0; i < n; i++) {\n        int a = bisect_left(xs, x1[i]), b\
    \ = bisect_left(xs, x2[i]);\n        int c = bisect_left(ys, y1[i]), d = bisect_left(ys,\
    \ y2[i]);\n        imos[a][c]++, imos[a][d]--, imos[b][c]--, imos[b][d]++;\n \
    \   }\n    for (int i = 0; i < w; i++)\n        for (int j = 1; j < h; j++) imos[i][j]\
    \ += imos[i][j - 1];\n    for (int i = 1; i < w; i++)\n        for (int j = 0;\
    \ j < h; j++) imos[i][j] += imos[i - 1][j];\n    long long ans = 0;\n    for (int\
    \ i = 0; i + 1 < w; i++)\n        for (int j = 0; j + 1 < h; j++) {\n        \
    \    if (imos[i][j] > 0) ans += (xs[i + 1] - xs[i]) * (ys[j + 1] - ys[j]);\n \
    \       }\n    std::cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/utility/container_func.hpp\"\
    \n#include \"../../src/utility/vector_func.hpp\"\n\nint main() {\n    int n;\n\
    \    std::cin >> n;\n    std::vector<long long> x1(n), y1(n), x2(n), y2(n);\n\
    \    std::vector<long long> xs, ys;\n    for (int i = 0; i < n; i++) {\n     \
    \   std::cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n        xs.push_back(x1[i]),\
    \ xs.push_back(x2[i]);\n        ys.push_back(y1[i]), ys.push_back(y2[i]);\n  \
    \  }\n    // \u5EA7\u6A19\u5727\u7E2E\n    xs = unique(xs);\n    ys = unique(ys);\n\
    \    int w = xs.size(), h = ys.size();\n    std::vector<std::vector<int>> imos(w,\
    \ std::vector<int>(h));\n    for (int i = 0; i < n; i++) {\n        int a = bisect_left(xs,\
    \ x1[i]), b = bisect_left(xs, x2[i]);\n        int c = bisect_left(ys, y1[i]),\
    \ d = bisect_left(ys, y2[i]);\n        imos[a][c]++, imos[a][d]--, imos[b][c]--,\
    \ imos[b][d]++;\n    }\n    for (int i = 0; i < w; i++)\n        for (int j =\
    \ 1; j < h; j++) imos[i][j] += imos[i][j - 1];\n    for (int i = 1; i < w; i++)\n\
    \        for (int j = 0; j < h; j++) imos[i][j] += imos[i - 1][j];\n    long long\
    \ ans = 0;\n    for (int i = 0; i + 1 < w; i++)\n        for (int j = 0; j + 1\
    \ < h; j++) {\n            if (imos[i][j] > 0) ans += (xs[i + 1] - xs[i]) * (ys[j\
    \ + 1] - ys[j]);\n        }\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/utility/container_func.hpp
  - src/utility/traits.hpp
  - src/utility/vector_func.hpp
  isVerificationFile: true
  path: test/aoj/dsl-4-a.1.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dsl-4-a.1.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dsl-4-a.1.test.cpp
- /verify/test/aoj/dsl-4-a.1.test.cpp.html
title: test/aoj/dsl-4-a.1.test.cpp
---
