---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-1-b.test.cpp
    title: test/aoj/alds1/alds1-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-4-b.test.cpp
    title: test/aoj/alds1/alds1-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-4-a.1.test.cpp
    title: test/aoj/dsl/dsl-4-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-10-c.test.cpp
    title: test/aoj/itp1/itp1-10-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-2-c.test.cpp
    title: test/aoj/itp1/itp1-2-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-4-d.test.cpp
    title: test/aoj/itp1/itp1-4-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1/itp1-6-a.test.cpp
    title: test/aoj/itp1/itp1-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-3-c.test.cpp
    title: test/aoj/itp2/itp2-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-5-a.1.test.cpp
    title: test/aoj/itp2/itp2-5-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-5-a.2.test.cpp
    title: test/aoj/itp2/itp2-5-a.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2/itp2-5-b.test.cpp
    title: test/aoj/itp2/itp2-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/utility/container-func-member.test.cpp
    title: test/unittest/utility/container-func-member.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/utility/container-func.test.cpp
    title: test/unittest/utility/container-func.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570\
      \ (sorted, max, sum \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/utility/container_func.hpp\"\n\n/**\n * @file container_func.hpp\n\
    \ * @brief \u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
    \ max, sum \u306A\u3069)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <cstddef>\n#include <functional>\n#include <initializer_list>\n#include <iterator>\n\
    #include <numeric>\n#include <type_traits>\n#include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\
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
    \ upper_bound(v, x)));\n}\n"
  code: "#pragma once\n\n/**\n * @file container_func.hpp\n * @brief \u30B3\u30F3\u30C6\
    \u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted, max, sum \u306A\u3069)\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <cstddef>\n#include <functional>\n\
    #include <initializer_list>\n#include <iterator>\n#include <numeric>\n#include\
    \ <type_traits>\n#include <vector>\n\n#include \"traits.hpp\"\n\n#define METHOD_EXPAND(func)\
    \                                        \\\n    template <typename T, ENABLE_IF_T(has_##func##_v<T>)>\
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
    \ upper_bound(v, x)));\n}\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/utility/container_func.hpp
  requiredBy: []
  timestamp: '2026-10-18 01:03:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/utility/container-func-member.test.cpp
  - test/unittest/utility/container-func.test.cpp
  - test/aoj/alds1/alds1-1-b.test.cpp
  - test/aoj/alds1/alds1-4-b.test.cpp
  - test/aoj/dsl/dsl-4-a.1.test.cpp
  - test/aoj/itp2/itp2-5-a.1.test.cpp
  - test/aoj/itp2/itp2-3-c.test.cpp
  - test/aoj/itp2/itp2-5-b.test.cpp
  - test/aoj/itp2/itp2-5-a.2.test.cpp
  - test/aoj/itp1/itp1-4-d.test.cpp
  - test/aoj/itp1/itp1-10-c.test.cpp
  - test/aoj/itp1/itp1-6-a.test.cpp
  - test/aoj/itp1/itp1-2-c.test.cpp
documentation_of: src/utility/container_func.hpp
layout: document
title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted, max,\
  \ sum \u306A\u3069)"
---

コンテナ全体を受け取る Python 風の関数です。`begin()`、`end()` を持つコンテナならたいてい使えます。

コンテナが同名のメンバ関数を持つ場合は、そちらを呼びます。そのときの計算量はメンバ関数の計算量になります ([Range](range.hpp) の `sum` は $O(1)$ など)。`find`、`count`、`lower_bound`、`upper_bound` は `std::set` などではメンバ関数を、それ以外では `std::` のアルゴリズムを使います。

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};
auto w = sorted(v);            // {1, 1, 3, 4, 5}
int s = sum(v), mx = max(v);   // 14, 5
long long i = bisect_left(w, 3);  // 2
bool b = contains(v, 4);       // true
auto odd = indices_if(v, [](int x) { return x % 2 == 1; });  // {0, 1, 3, 4}
```

## 並べ替え

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sorted(c, reverse = false)` / `sorted(c, comp)` | ソートしたコピーを返す | $O(n \log n)$ |
| `reversed(c)` | 逆順にしたコピーを返す | $O(n)$ |
| `sort(c, reverse = false)` / `sort(c, comp)` | その場でソート | $O(n \log n)$ |
| `sort_by_key(c, key)` | `key(x)` の昇順にその場でソート (比較のたびに `key` を呼ぶ) | `key` の呼び出し $O(n \log n)$ 回 |
| `reverse(c)` | その場で逆順にする | $O(n)$ |

## 集計

| 関数 | 説明 | 計算量 |
|---|---|---|
| `max(c)` / `min(c)` | 最大値 / 最小値。`max({a, b, c})` のように初期化子リストも渡せる | $O(n)$ (`set` などソート済みのコンテナでは $O(1)$) |
| `sum(c)` | 総和 | $O(n)$ |
| `product(c)` | 総積 | $O(n)$ |
| `product_xor(c)` | 総 xor | $O(n)$ |
| `gcd(c)` | 全要素の gcd (空なら 0) | $O(n \log \max)$ |
| `average(c)` | 平均 (`sum(c) / size`、整数型なら 0 方向に切り捨て) | $O(n)$ |
| `median(c)` | 中央値 (要素数が偶数なら中央 2 つの平均) | $O(n \log n)$ |
| `mex(c)` | 含まれない最小の非負整数 | $O(n)$ |

## 検索

| 関数 | 説明 | 計算量 |
|---|---|---|
| `find(c, x)` | `x` を指すイテレータ (なければ `end()`) | $O(n)$ (`set` などでは $O(\log n)$) |
| `count(c, x)` | `x` の個数 | $O(n)$ (`multiset` などでは $O(\log n + k)$、$k$ は個数) |
| `contains(c, x)` | `x` を含むか | `find` と同じ |
| `index(c, x)` | `x` が最初に現れる位置 (`long long`。なければ `-1`) | $O(n)$ |
| `index_if(c, f)` | `f(x)` が `true` になる最初の位置 (`long long`。なければ `-1`) | $O(n)$ |
| `indices_if(c, f)` | `f(x)` が `true` になる位置を昇順に並べたもの (`std::vector<long long>`) | $O(n)$ |
| `count_if(c, f)` | `f(x)` が `true` になる要素の個数 (`long long`) | $O(n)$ |
| `lower_bound(c, x)` / `upper_bound(c, x)` | イテレータを返す | $O(\log n)$ |
| `bisect_left(c, x)` / `bisect_right(c, x)` | 添字を `long long` で返す (Python の `bisect`) | $O(\log n)$ (`set` などでは位置を数えるので $O(n)$) |

位置は、`set` などでは先頭から数えた順番です。

条件を満たす候補が 1 つだけのときに選ぶ、といった処理は `indices_if` で書けます。

```cpp
// t と長さが同じで 1 文字だけ違う名前が、ちょうど 1 つあればその位置
auto cand = indices_if(names, [&](const std::string& s) { return s.size() == t.size() && hamming_distance(s, t) == 1; });
if (cand.size() == 1) vote[cand[0]]++;
```

## 関連

- `hamming_distance` は [文字列アルゴリズム](../string/string.hpp)
- `std::vector` に対する演算子と関数は [vector に対する演算子と関数](vector_func.hpp)
