---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-4-a.1.test.cpp
    title: test/aoj/dsl/dsl-4-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/utility/vector_func.test.cpp
    title: test/unittest/utility/vector_func.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/static-range-sum.test.cpp
    title: test/yosupo/data_structure/static-range-sum.test.cpp
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
    \ <cstddef>\n#include <functional>\n#include <numeric>\n#include <type_traits>\n\
    #include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include\
    \ <iterator>\n#include <set>\n#line 12 \"src/utility/traits.hpp\"\n#include <utility>\n\
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
    #line 18 \"src/utility/vector_func.hpp\"\n\n/**\n * @brief \u5024\u3092 comp \u306E\
    \u9806\u306B\u5B89\u5B9A\u30BD\u30FC\u30C8\u3057\u305F\u3068\u304D\u306E\u6DFB\
    \u5B57\u306E\u4E26\u3073 (APL \u306E grade up)\n */\ntemplate <typename T, typename\
    \ F = std::less<>>\nstd::vector<long long> argsort(const std::vector<T>& v, F\
    \ comp = F()) {\n    std::vector<long long> ret(v.size());\n    std::iota(ret.begin(),\
    \ ret.end(), 0LL);\n    std::stable_sort(ret.begin(), ret.end(), [&](long long\
    \ i, long long j) {\n        return comp(v[i], v[j]);\n    });\n    return ret;\n\
    }\n\n/**\n * @brief {v[idx[0]], v[idx[1]], ...} (Uiua \u306E select)\n */\ntemplate\
    \ <typename T, typename I, ENABLE_IF_T(std::is_integral_v<I>)>\nstd::vector<T>\
    \ select(const std::vector<T>& v, const std::vector<I>& idx) {\n    std::vector<T>\
    \ ret;\n    ret.reserve(idx.size());\n    for (I i : idx) {\n        assert(0\
    \ <= static_cast<long long>(i) && static_cast<long long>(i) < static_cast<long\
    \ long>(v.size()));\n        ret.push_back(v[i]);\n    }\n    return ret;\n}\n\
    \ntemplate <typename T>\ninline std::vector<T>& operator++(std::vector<T>& v)\
    \ {\n    for (auto& e : v) e++;\n    return v;\n}\ntemplate <typename T>\ninline\
    \ std::vector<T> operator++(std::vector<T>& v, int) {\n    auto res = v;\n   \
    \ for (auto& e : v) e++;\n    return res;\n}\ntemplate <typename T>\ninline std::vector<T>&\
    \ operator--(std::vector<T>& v) {\n    for (auto& e : v) e--;\n    return v;\n\
    }\ntemplate <typename T>\ninline std::vector<T> operator--(std::vector<T>& v,\
    \ int) {\n    auto res = v;\n    for (auto& e : v) e--;\n    return res;\n}\n\n\
    template <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\n\
    inline std::vector<T>& operator+=(std::vector<T>& v1, const std::vector<U>& v2)\
    \ {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n    }\n\
    \    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n\
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
    \ v, const U& u) {\n    if constexpr (std::is_signed_v<U>) assert(u >= 0);\n \
    \   std::vector<T> w(v);\n    v.clear();\n    for (long long i = 0; i < static_cast<long\
    \ long>(u); i++) {\n        extend(v, w);\n    }\n    return v;\n}\n\ntemplate\
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
    \ v, int base = 10) {\n    assert(base >= 2);\n    long long res = 0;\n    for\
    \ (long long d : v) {\n        assert(0 <= d && d < base);\n        res = res\
    \ * base + d;\n    }\n    return res;\n}\n\ninline std::vector<long long> radix_convert(long\
    \ long v, int base = 10) {\n    assert(v >= 0 && base >= 2);\n    std::vector<long\
    \ long> res;\n    while (v > 0) {\n        res.push_back(v % base);\n        v\
    \ /= base;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file vector_func.hpp\n * @brief vector \u306B\u5BFE\
    \u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <cstddef>\n#include <functional>\n\
    #include <numeric>\n#include <type_traits>\n#include <vector>\n\n#include \"traits.hpp\"\
    \n\n/**\n * @brief \u5024\u3092 comp \u306E\u9806\u306B\u5B89\u5B9A\u30BD\u30FC\
    \u30C8\u3057\u305F\u3068\u304D\u306E\u6DFB\u5B57\u306E\u4E26\u3073 (APL \u306E\
    \ grade up)\n */\ntemplate <typename T, typename F = std::less<>>\nstd::vector<long\
    \ long> argsort(const std::vector<T>& v, F comp = F()) {\n    std::vector<long\
    \ long> ret(v.size());\n    std::iota(ret.begin(), ret.end(), 0LL);\n    std::stable_sort(ret.begin(),\
    \ ret.end(), [&](long long i, long long j) {\n        return comp(v[i], v[j]);\n\
    \    });\n    return ret;\n}\n\n/**\n * @brief {v[idx[0]], v[idx[1]], ...} (Uiua\
    \ \u306E select)\n */\ntemplate <typename T, typename I, ENABLE_IF_T(std::is_integral_v<I>)>\n\
    std::vector<T> select(const std::vector<T>& v, const std::vector<I>& idx) {\n\
    \    std::vector<T> ret;\n    ret.reserve(idx.size());\n    for (I i : idx) {\n\
    \        assert(0 <= static_cast<long long>(i) && static_cast<long long>(i) <\
    \ static_cast<long long>(v.size()));\n        ret.push_back(v[i]);\n    }\n  \
    \  return ret;\n}\n\ntemplate <typename T>\ninline std::vector<T>& operator++(std::vector<T>&\
    \ v) {\n    for (auto& e : v) e++;\n    return v;\n}\ntemplate <typename T>\n\
    inline std::vector<T> operator++(std::vector<T>& v, int) {\n    auto res = v;\n\
    \    for (auto& e : v) e++;\n    return res;\n}\ntemplate <typename T>\ninline\
    \ std::vector<T>& operator--(std::vector<T>& v) {\n    for (auto& e : v) e--;\n\
    \    return v;\n}\ntemplate <typename T>\ninline std::vector<T> operator--(std::vector<T>&\
    \ v, int) {\n    auto res = v;\n    for (auto& e : v) e--;\n    return res;\n\
    }\n\ntemplate <typename T, typename U, ENABLE_IF_T(std::is_convertible_v<U, T>)>\n\
    inline std::vector<T>& operator+=(std::vector<T>& v1, const std::vector<U>& v2)\
    \ {\n    if (v2.size() > v1.size()) {\n        v1.resize(v2.size());\n    }\n\
    \    for (std::size_t i = 0; i < v2.size(); i++) {\n        v1[i] += v2[i];\n\
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
    \ v, const U& u) {\n    if constexpr (std::is_signed_v<U>) assert(u >= 0);\n \
    \   std::vector<T> w(v);\n    v.clear();\n    for (long long i = 0; i < static_cast<long\
    \ long>(u); i++) {\n        extend(v, w);\n    }\n    return v;\n}\n\ntemplate\
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
    \ v, int base = 10) {\n    assert(base >= 2);\n    long long res = 0;\n    for\
    \ (long long d : v) {\n        assert(0 <= d && d < base);\n        res = res\
    \ * base + d;\n    }\n    return res;\n}\n\ninline std::vector<long long> radix_convert(long\
    \ long v, int base = 10) {\n    assert(v >= 0 && base >= 2);\n    std::vector<long\
    \ long> res;\n    while (v > 0) {\n        res.push_back(v % base);\n        v\
    \ /= base;\n    }\n    std::reverse(res.begin(), res.end());\n    return res;\n\
    }\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/utility/vector_func.hpp
  requiredBy: []
  timestamp: '2026-10-30 17:07:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/utility/vector_func.test.cpp
  - test/aoj/dsl/dsl-4-a.1.test.cpp
  - test/yosupo/data_structure/static-range-sum.test.cpp
documentation_of: src/utility/vector_func.hpp
layout: document
title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570"
---

`std::vector` に演算子と便利な関数を追加します。計算量の $n$ は `v` の長さ、$m$ は `w` の長さです。

```cpp
std::vector<int> a = {1, 2, 3};
a--;                              // 0-indexed にする: {0, 1, 2}
auto s = cumulative_sum(a);       // {0, 0, 1, 3}
auto b = a | 2;                   // {0, 1, 2, 0, 1, 2}
auto idx = argsort(a, std::greater<>());  // 値の降順に並べた添字: {2, 1, 0}
auto c = select(a, idx);          // {2, 1, 0}
```

## 演算子

| 演算子 | 説明 | 計算量 |
|---|---|---|
| `++v`、`v++`、`--v`、`v--` | 全要素を ±1 (入力の 1-indexed を 0-indexed に直すときなど) | $O(n)$ |
| `v + x`、`x + v`、`v += x` | 全要素に `x` を足す | $O(n)$ |
| `v * x`、`x * v`、`v *= x` | 全要素に `x` を掛ける | $O(n)$ |
| `v + w`、`v += w` | 要素ごとの和 (短い方は 0 で埋める) | $O(\max(n, m))$ |
| `v * w`、`v *= w` | 要素ごとの積 (長い方の余りは 0 になる) | $O(\max(n, m))$ |
| `v |= w` | `w` を末尾に連結 (`extend` と同じ) | $O(m)$ |
| `v | k`、`k | v`、`v |= k` | `v` を `k` 回繰り返す (`k` は 0 以上。負なら assert で落ちる) | $O(nk)$ |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `argsort(v)` / `argsort(v, comp)` | 値を昇順 (`comp` の順) に安定ソートしたときの添字のリスト (`std::vector<long long>`)。APL の grade up。降順は `argsort(v, std::greater<>())` | $O(n \log n)$ |
| `select(v, idx)` | `{v[idx[0]], v[idx[1]], ...}`。`idx` は整数型の `vector` で、範囲外なら assert で落ちる。`select(a, argsort(b))` で `b` の昇順に `a` を並べる | $O(\lvert \mathit{idx} \rvert)$ |
| `cumulative_sum(v)` | 先頭に 0 を付けた累積和 (長さ `size + 1`) | $O(n)$ |
| `iota(n)` | `{0, 1, ..., n-1}` | $O(n)$ |
| `unique(v)` | ソートして重複を除いたコピー | $O(n \log n)$ |
| `abs(v)` | 全要素の絶対値 | $O(n)$ |
| `hamming_distance(v, w)` | 同じ長さの `v` と `w` で要素が異なる位置の数 (長さが違うと assert で落ちる) | $O(n)$ |
| `extend(v, w)` | `w` を末尾に連結 | $O(m)$ |
| `assign(v, w)` | `w` の内容で置き換える (型の変換つき) | $O(m)$ |
| `radix_convert(x, base = 10)` | 整数 `x` を `base` 進数の桁のリスト (上位桁から) にする。`x = 0` なら空のリスト。`x >= 0`、`base >= 2` でなければ assert で落ちる | $O(\log_{base} x)$ |
| `radix_convert(digits, base = 10)` | `base` 進数の桁のリスト (上位桁から) を整数に戻す。`base >= 2` で、各桁が $[0, \mathit{base})$ になければ assert で落ちる | 桁数に比例 |

## 関連

- 文字列などの列のハミング距離は [文字列アルゴリズム](../string/string.hpp)、整数のハミング距離は [ビット演算](bit.hpp) の `hamming_distance`
- コンテナ全般に使える関数 (`sorted`、`sum`、`bisect_left` など) は [コンテナに対する関数](container_func.hpp)
