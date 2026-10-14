---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-4-a.1.test.cpp
    title: test/aoj/dsl-4-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/vector-func.test.cpp
    title: test/unittest/vector-func.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-sum.test.cpp
    title: test/yosupo/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\
      \u6570"
    links: []
  bundledCode: "#line 2 \"src/utility/vector_func.hpp\"\n\n/**\n * @file vector_func.hpp\n\
    \ * @brief vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570\
    \n */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include\
    \ <cstddef>\n#include <numeric>\n#include <type_traits>\n#include <vector>\n\n\
    #line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <iterator>\n\
    #include <set>\n#line 12 \"src/utility/traits.hpp\"\n#include <utility>\n\nnamespace\
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
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 17 \"src/utility/vector_func.hpp\"\n\ntemplate <typename T>\nstd::vector<int>\
    \ sorted_idx(const std::vector<T>& v, bool reverse = false) {\n    std::vector<int>\
    \ ret(v.size());\n    std::iota(ret.begin(), ret.end(), 0);\n    std::sort(ret.begin(),\
    \ ret.end(), [&](int i, int j) {\n        return v[i] < v[j];\n    });\n    if\
    \ (reverse) std::reverse(ret.begin(), ret.end());\n    return ret;\n}\n\ntemplate\
    \ <typename T>\ninline std::vector<T>& operator++(std::vector<T>& v) {\n    for\
    \ (auto& e : v) e++;\n    return v;\n}\ntemplate <typename T>\ninline std::vector<T>\
    \ operator++(std::vector<T>& v, int) {\n    auto res = v;\n    for (auto& e :\
    \ v) e++;\n    return res;\n}\ntemplate <typename T>\ninline std::vector<T>& operator--(std::vector<T>&\
    \ v) {\n    for (auto& e : v) e--;\n    return v;\n}\ntemplate <typename T>\n\
    inline std::vector<T> operator--(std::vector<T>& v, int) {\n    auto res = v;\n\
    \    for (auto& e : v) e--;\n    return res;\n}\n\ntemplate <typename T, typename\
    \ U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\ninline std::vector<T>& operator+=(std::vector<T>&\
    \ v1, const std::vector<U>& v2) {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n\
    \    }\n    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n\
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
    \ T>\nstd::vector<T> unique(const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n\ninline long long radix_convert(const\
    \ std::vector<long long>& v, int base = 10) {\n    long long res = 0;\n    for\
    \ (long long d : v) {\n        res = res * base + d;\n    }\n    return res;\n\
    }\n\ninline std::vector<long long> radix_convert(long long v, int base = 10) {\n\
    \    std::vector<long long> res;\n    while (v > 0) {\n        res.push_back(v\
    \ % base);\n        v /= base;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file vector_func.hpp\n * @brief vector \u306B\u5BFE\
    \u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <cstddef>\n#include <numeric>\n\
    #include <type_traits>\n#include <vector>\n\n#include \"traits.hpp\"\n\ntemplate\
    \ <typename T>\nstd::vector<int> sorted_idx(const std::vector<T>& v, bool reverse\
    \ = false) {\n    std::vector<int> ret(v.size());\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    std::sort(ret.begin(), ret.end(), [&](int i, int j) {\n\
    \        return v[i] < v[j];\n    });\n    if (reverse) std::reverse(ret.begin(),\
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
    \ T>\nstd::vector<T> unique(const std::vector<T>& v) {\n    std::vector<T> res(v);\n\
    \    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n\ninline long long radix_convert(const\
    \ std::vector<long long>& v, int base = 10) {\n    long long res = 0;\n    for\
    \ (long long d : v) {\n        res = res * base + d;\n    }\n    return res;\n\
    }\n\ninline std::vector<long long> radix_convert(long long v, int base = 10) {\n\
    \    std::vector<long long> res;\n    while (v > 0) {\n        res.push_back(v\
    \ % base);\n        v /= base;\n    }\n    std::reverse(res.begin(), res.end());\n\
    \    return res;\n}\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/utility/vector_func.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/vector-func.test.cpp
  - test/aoj/dsl-4-a.1.test.cpp
  - test/yosupo/static-range-sum.test.cpp
documentation_of: src/utility/vector_func.hpp
layout: document
title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570"
---

`std::vector` に演算子と便利な関数を追加します。

```cpp
std::vector<int> a = {1, 2, 3};
a--;                              // 0-indexed にする: {0, 1, 2}
auto s = cumulative_sum(a);       // {0, 0, 1, 3}
auto b = a | 2;                   // {0, 1, 2, 0, 1, 2}
auto idx = sorted_idx(a, true);   // 値の降順に並べた添字
```

## 演算子

| 演算子 | 説明 |
|---|---|
| `++v`、`v++`、`--v`、`v--` | 全要素を ±1 (入力の 1-indexed を 0-indexed に直すときなど) |
| `v + x`、`x + v`、`v += x` | 全要素に `x` を足す |
| `v * x`、`x * v`、`v *= x` | 全要素に `x` を掛ける |
| `v + w`、`v += w` | 要素ごとの和 (短い方は 0 で埋める) |
| `v * w`、`v *= w` | 要素ごとの積 (長い方の余りは 0 になる) |
| `v |= w` | `w` を末尾に連結 (`extend` と同じ) |
| `v | k`、`k | v`、`v |= k` | `v` を `k` 回繰り返す |

## 関数

| 関数 | 説明 |
|---|---|
| `sorted_idx(v, reverse = false)` | 値の昇順 (降順) に並べた添字のリスト |
| `cumulative_sum(v)` | 先頭に 0 を付けた累積和 (長さ `size + 1`) |
| `iota(n)` | `{0, 1, ..., n-1}` |
| `unique(v)` | ソートして重複を除いたコピー |
| `abs(v)` | 全要素の絶対値 |
| `extend(v, w)` | `w` を末尾に連結 |
| `assign(v, w)` | `w` の内容で置き換える (型の変換つき) |
| `radix_convert(x, base = 10)` | 整数 `x` を `base` 進数の桁のリスト (上位桁から) にする |
| `radix_convert(digits, base = 10)` | `base` 進数の桁のリスト (上位桁から) を整数に戻す |

## 関連

- コンテナ全般に使える関数 (`sorted`、`sum`、`bisect_left` など) は [コンテナに対する関数](container_func.hpp)
