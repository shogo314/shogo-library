---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base/traits.hpp
    title: base/traits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base/vector_func.hpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <cstddef>\n#include <numeric>\n#include <vector>\n\n#line 2 \"base/traits.hpp\"\
    \n\n#line 4 \"base/traits.hpp\"\n#include <iterator>\n#include <set>\n#include\
    \ <type_traits>\n#include <utility>\n\nnamespace detail {\nusing std::begin, std::end;\n\
    \ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ 9 \"base/vector_func.hpp\"\n\ntemplate <typename T>\nstd::vector<std::ptrdiff_t>\
    \ sorted_idx(const std::vector<T> &v, bool reverse = false) {\n    std::vector<std::ptrdiff_t>\
    \ ret(v.size());\n    std::iota(ret.begin(), ret.end(), 0);\n    std::sort(ret.begin(),\
    \ ret.end(), [&](std::ptrdiff_t i, std::ptrdiff_t j) {\n        return v[i] <\
    \ v[j];\n    });\n    if (reverse) std::reverse(ret.begin(), ret.end());\n   \
    \ return ret;\n}\n\ntemplate <typename T>\ninline std::vector<T> &operator++(std::vector<T>\
    \ &v) {\n    for (auto &e : v) e++;\n    return v;\n}\ntemplate <typename T>\n\
    inline std::vector<T> operator++(std::vector<T> &v, int) {\n    auto res = v;\n\
    \    for (auto &e : v) e++;\n    return res;\n}\ntemplate <typename T>\ninline\
    \ std::vector<T> &operator--(std::vector<T> &v) {\n    for (auto &e : v) e--;\n\
    \    return v;\n}\ntemplate <typename T>\ninline std::vector<T> operator--(std::vector<T>\
    \ &v, int) {\n    auto res = v;\n    for (auto &e : v) e--;\n    return res;\n\
    }\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\n\
    inline std::vector<T> &operator+=(std::vector<T> &v1, const std::vector<U> &v2)\
    \ {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n    }\n\
    \    for (size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n    }\n\
    \    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T> &v1, const std::vector<U>\
    \ &v2) {\n    std::vector<T> res(v1);\n    return res += v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ &operator+=(std::vector<T> &v, const U &u) {\n    for (T &e : v) {\n       \
    \ e += u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const std::vector<T> &v, const U &u) {\n\
    \    std::vector<T> res(v);\n    return res += u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator+(const U &u, const std::vector<T> &v) {\n    std::vector<T> res(v);\n\
    \    return res += u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> &operator*=(std::vector<T> &v1, const std::vector<U>\
    \ &v2) {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n  \
    \  }\n    for (size_t i = 0; i < v2.size(); i++) {\n        v1[i] *= v2[i];\n\
    \    }\n    for (size_t i = v2.size(); i < v1.size(); i++) {\n        v1[i] *=\
    \ U(0);\n    }\n    return v1;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T> &v1, const std::vector<U>\
    \ &v2) {\n    std::vector<T> res(v1);\n    return res *= v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ &operator*=(std::vector<T> &v, const U &u) {\n    for (T &e : v) {\n       \
    \ e *= u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T> &v, const U &u) {\n\
    \    std::vector<T> res(v);\n    return res *= u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator*(const U &u, const std::vector<T> &v) {\n    std::vector<T> res(v);\n\
    \    return res *= u;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>\
    \ &assign(std::vector<T> &v1, const std::vector<U> &v2) {\n    v1.assign(v2.begin(),\
    \ v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>\
    \ &extend(std::vector<T> &v1, const std::vector<U> &v2) {\n    v1.insert(v1.end(),\
    \ v2.begin(), v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T> &operator|=(std::vector<T>\
    \ &v1, const std::vector<U> &v2) {\n    return extend(v1, v2);\n}\n\ntemplate\
    \ <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>\
    \ &operator|=(std::vector<T> &v, const U &u) {\n    std::vector<T> w(v);\n   \
    \ v.clear();\n    for (int i = 0; i < u; i++) {\n        extend(v, w);\n    }\n\
    \    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const std::vector<T> &v, const U &u) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const U &u, const std::vector<T> &v) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T>\ninline std::vector<T>\
    \ abs(const std::vector<T> &v) {\n    std::vector<T> ret;\n    ret.reserve(v.size());\n\
    \    for (const T &e : v) ret.push_back(std::abs(e));\n    return ret;\n}\n\n\
    template <typename T>\nstd::vector<T> cumulative_sum(std::vector<T> v) {\n   \
    \ v.insert(v.begin(), T{});\n    std::vector<T> ret(v.size());\n    std::partial_sum(v.begin(),\
    \ v.end(), ret.begin());\n    return ret;\n}\n\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    std::vector<T> iota(T n) {\n    assert(n >= 0);\n    std::vector<T> ret(n);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n    return ret;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> unique(const std::vector<T> &v) {\n    std::vector<T> res(v);\n\
    \    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n\ninline long long radix_convert(const\
    \ std::vector<long long> &v, int base = 10) {\n    long long res = 0;\n    for\
    \ (int i = v.size() - 1; i >= 0; i--) {\n        res <<= base;\n        res +=\
    \ v[i];\n    }\n    return res;\n}\n\ninline std::vector<long long> radix_convert(long\
    \ long v, int base = 10) {\n    std::vector<long long> res;\n    while (v > 0)\
    \ {\n        res.push_back(v % base);\n        v /= base;\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <cstddef>\n\
    #include <numeric>\n#include <vector>\n\n#include \"traits.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<std::ptrdiff_t> sorted_idx(const std::vector<T> &v, bool reverse\
    \ = false) {\n    std::vector<std::ptrdiff_t> ret(v.size());\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    std::sort(ret.begin(), ret.end(), [&](std::ptrdiff_t i,\
    \ std::ptrdiff_t j) {\n        return v[i] < v[j];\n    });\n    if (reverse)\
    \ std::reverse(ret.begin(), ret.end());\n    return ret;\n}\n\ntemplate <typename\
    \ T>\ninline std::vector<T> &operator++(std::vector<T> &v) {\n    for (auto &e\
    \ : v) e++;\n    return v;\n}\ntemplate <typename T>\ninline std::vector<T> operator++(std::vector<T>\
    \ &v, int) {\n    auto res = v;\n    for (auto &e : v) e++;\n    return res;\n\
    }\ntemplate <typename T>\ninline std::vector<T> &operator--(std::vector<T> &v)\
    \ {\n    for (auto &e : v) e--;\n    return v;\n}\ntemplate <typename T>\ninline\
    \ std::vector<T> operator--(std::vector<T> &v, int) {\n    auto res = v;\n   \
    \ for (auto &e : v) e--;\n    return res;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T> &operator+=(std::vector<T>\
    \ &v1, const std::vector<U> &v2) {\n    if (v2.size() > v1.size()) {\n       \
    \ v1.resize(v2.size());\n    }\n    for (size_t i = 0; i < v2.size(); i++) {\n\
    \        v1[i] += v2[i];\n    }\n    return v1;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T> operator+(const\
    \ std::vector<T> &v1, const std::vector<U> &v2) {\n    std::vector<T> res(v1);\n\
    \    return res += v2;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> &operator+=(std::vector<T> &v, const U &u) {\n \
    \   for (T &e : v) {\n        e += u;\n    }\n    return v;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator+(const std::vector<T> &v, const U &u) {\n    std::vector<T> res(v);\n\
    \    return res += u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator+(const U &u, const std::vector<T> &v) {\n\
    \    std::vector<T> res(v);\n    return res += u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ &operator*=(std::vector<T> &v1, const std::vector<U> &v2) {\n    if (v2.size()\
    \ > v1.size()) {\n        v1.resize(v2.size());\n    }\n    for (size_t i = 0;\
    \ i < v2.size(); i++) {\n        v1[i] *= v2[i];\n    }\n    for (size_t i = v2.size();\
    \ i < v1.size(); i++) {\n        v1[i] *= U(0);\n    }\n    return v1;\n}\n\n\
    template <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\n\
    inline std::vector<T> operator*(const std::vector<T> &v1, const std::vector<U>\
    \ &v2) {\n    std::vector<T> res(v1);\n    return res *= v2;\n}\n\ntemplate <typename\
    \ T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ &operator*=(std::vector<T> &v, const U &u) {\n    for (T &e : v) {\n       \
    \ e *= u;\n    }\n    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U,\
    \ T>)>\ninline std::vector<T> operator*(const std::vector<T> &v, const U &u) {\n\
    \    std::vector<T> res(v);\n    return res *= u;\n}\n\ntemplate <typename T,\
    \ typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>\
    \ operator*(const U &u, const std::vector<T> &v) {\n    std::vector<T> res(v);\n\
    \    return res *= u;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>\
    \ &assign(std::vector<T> &v1, const std::vector<U> &v2) {\n    v1.assign(v2.begin(),\
    \ v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename U>\ninline std::vector<T>\
    \ &extend(std::vector<T> &v1, const std::vector<U> &v2) {\n    v1.insert(v1.end(),\
    \ v2.begin(), v2.end());\n    return v1;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T> &operator|=(std::vector<T>\
    \ &v1, const std::vector<U> &v2) {\n    return extend(v1, v2);\n}\n\ntemplate\
    \ <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\ninline std::vector<T>\
    \ &operator|=(std::vector<T> &v, const U &u) {\n    std::vector<T> w(v);\n   \
    \ v.clear();\n    for (int i = 0; i < u; i++) {\n        extend(v, w);\n    }\n\
    \    return v;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const std::vector<T> &v, const U &u) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_integral_v<U>)>\n\
    inline std::vector<T> operator|(const U &u, const std::vector<T> &v) {\n    std::vector<T>\
    \ res(v);\n    return res |= u;\n}\n\ntemplate <typename T>\ninline std::vector<T>\
    \ abs(const std::vector<T> &v) {\n    std::vector<T> ret;\n    ret.reserve(v.size());\n\
    \    for (const T &e : v) ret.push_back(std::abs(e));\n    return ret;\n}\n\n\
    template <typename T>\nstd::vector<T> cumulative_sum(std::vector<T> v) {\n   \
    \ v.insert(v.begin(), T{});\n    std::vector<T> ret(v.size());\n    std::partial_sum(v.begin(),\
    \ v.end(), ret.begin());\n    return ret;\n}\n\ntemplate <typename T, ENABLE_IF_T(std::is_integral_v<T>)>\n\
    std::vector<T> iota(T n) {\n    assert(n >= 0);\n    std::vector<T> ret(n);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n    return ret;\n}\n\ntemplate <typename\
    \ T>\nstd::vector<T> unique(const std::vector<T> &v) {\n    std::vector<T> res(v);\n\
    \    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n\ninline long long radix_convert(const\
    \ std::vector<long long> &v, int base = 10) {\n    long long res = 0;\n    for\
    \ (int i = v.size() - 1; i >= 0; i--) {\n        res <<= base;\n        res +=\
    \ v[i];\n    }\n    return res;\n}\n\ninline std::vector<long long> radix_convert(long\
    \ long v, int base = 10) {\n    std::vector<long long> res;\n    while (v > 0)\
    \ {\n        res.push_back(v % base);\n        v /= base;\n    }\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n"
  dependsOn:
  - base/traits.hpp
  isVerificationFile: false
  path: base/vector_func.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: base/vector_func.hpp
layout: document
redirect_from:
- /library/base/vector_func.hpp
- /library/base/vector_func.hpp.html
title: base/vector_func.hpp
---
