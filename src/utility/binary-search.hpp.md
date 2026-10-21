---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-4-d.test.cpp
    title: test/aoj/alds1/alds1-4-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/base/functions.test.cpp
    title: test/unittest/base/functions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E8C\u5206\u63A2\u7D22"
    links: []
  bundledCode: "#line 2 \"src/utility/binary-search.hpp\"\n\n/**\n * @file binary-search.hpp\n\
    \ * @brief \u4E8C\u5206\u63A2\u7D22\n */\n\n#include <cmath>\n#include <type_traits>\n\
    \n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief \u578B\
    \u7279\u6027\n */\n\n#include <cstddef>\n#include <iterator>\n#include <set>\n\
    #line 12 \"src/utility/traits.hpp\"\n#include <utility>\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n"
  code: "#pragma once\n\n/**\n * @file binary-search.hpp\n * @brief \u4E8C\u5206\u63A2\
    \u7D22\n */\n\n#include <cmath>\n#include <type_traits>\n\n#include \"traits.hpp\"\
    \n\n/**\n * f(ok) \u304C\u771F\u3001f(ng) \u304C\u507D\u3068\u3057\u3066\u3001\
    \u5883\u754C\u3067 f \u304C\u771F\u306B\u306A\u308B\u5074\u306E\u5024\u3092\u8FD4\
    \u3059\n * \u6574\u6570\u306A\u3089 ok \u3068 ng \u306E\u5DEE\u304C 1 \u306B\u306A\
    \u308B\u307E\u3067\u3001\u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306A\u3089 100 \u56DE\
    \u4E8C\u5206\u3059\u308B\n */\ntemplate <typename M, typename N, class F, ENABLE_IF_T(std::is_integral_v<std::common_type_t<M,\
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
    \            _ng = mid;\n        }\n    }\n    return _ok;\n}\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/utility/binary-search.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/base/functions.test.cpp
  - test/aoj/alds1/alds1-4-d.test.cpp
documentation_of: src/utility/binary-search.hpp
layout: document
title: "\u4E8C\u5206\u63A2\u7D22"
---

答えで二分探索をするための関数です。

```cpp
long long r = binary_search(0, 1000, [](long long m) { return m * m <= 500; });  // 22
double s = binary_search(0.0, 10.0, [](double m) { return m * m <= 2; });        // 1.41421...
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `binary_search(ok, ng, f)` | `f(ok)` が真、`f(ng)` が偽として、境界で `f` が真になる側の値を返す。整数なら `ok` と `ng` の差が 1 になるまで、浮動小数点数なら 100 回二分する | `f` の呼び出し $O(\log \lvert ok - ng \rvert)$ 回 (浮動小数点数なら 100 回) |

`ok` と `ng` はどちらが大きくてもかまいません。型が違う場合は `std::common_type_t` にそろえます。

## 関連

- ソート済みの列で値を探すなら [コンテナに対する関数](container_func.hpp) の `bisect_left(c, x)` / `lower_bound(c, x)`
