---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/argcmp.hpp
    title: "\u504F\u89D2\u30BD\u30FC\u30C8\u306E\u6BD4\u8F03\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/string/rolling-hash.hpp
    title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5"
  - icon: ':heavy_check_mark:'
    path: src/utility/binary-search.hpp
    title: "\u4E8C\u5206\u63A2\u7D22"
  - icon: ':heavy_check_mark:'
    path: src/utility/container_func.hpp
    title: "\u30B3\u30F3\u30C6\u30CA\u306B\u5BFE\u3059\u308B\u95A2\u6570 (sorted,\
      \ max, sum \u306A\u3069)"
  - icon: ':heavy_check_mark:'
    path: src/utility/repr.hpp
    title: "\u51FA\u529B\u3092\u305D\u306E\u307E\u307E\u30B3\u30F3\u30B9\u30C8\u30E9\
      \u30AF\u30BF\u306B\u4F7F\u3048\u308B\u6587\u5B57\u5217\u5316 (repr)"
  - icon: ':heavy_check_mark:'
    path: src/utility/vector_func.hpp
    title: "vector \u306B\u5BFE\u3059\u308B\u6F14\u7B97\u5B50\u3068\u95A2\u6570"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/0022.test.cpp
    title: test/aoj/0022.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-1-b.test.cpp
    title: test/aoj/alds1-1-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-14-b.test.cpp
    title: test/aoj/alds1-14-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-4-b.test.cpp
    title: test/aoj/alds1-4-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-4-d.test.cpp
    title: test/aoj/alds1-4-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-4-a.1.test.cpp
    title: test/aoj/dsl-4-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-10-c.test.cpp
    title: test/aoj/itp1-10-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-2-c.test.cpp
    title: test/aoj/itp1-2-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-4-d.test.cpp
    title: test/aoj/itp1-4-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-6-a.test.cpp
    title: test/aoj/itp1-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-3-c.test.cpp
    title: test/aoj/itp2-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-5-a.1.test.cpp
    title: test/aoj/itp2-5-a.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-5-a.2.test.cpp
    title: test/aoj/itp2-5-a.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp2-5-b.test.cpp
    title: test/aoj/itp2-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/container-func-member.test.cpp
    title: test/unittest/container-func-member.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/container-func.test.cpp
    title: test/unittest/container-func.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/functions.test.cpp
    title: test/unittest/functions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/repr.test.cpp
    title: test/unittest/repr.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/rolling-hash.test.cpp
    title: test/unittest/rolling-hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/vector-func.test.cpp
    title: test/unittest/vector-func.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate-palindromes.test.cpp
    title: test/yosupo/enumerate-palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort-points-by-argument.2.test.cpp
    title: test/yosupo/sort-points-by-argument.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-sum.test.cpp
    title: test/yosupo/static-range-sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u578B\u7279\u6027"
    links: []
  bundledCode: "#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n *\
    \ @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#include <iterator>\n\
    #include <set>\n#include <type_traits>\n#include <utility>\n\nnamespace detail\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n"
  code: "#pragma once\n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n\
    \ */\n\n#include <cstddef>\n#include <iterator>\n#include <set>\n#include <type_traits>\n\
    #include <utility>\n\nnamespace detail {\nusing std::begin, std::end;\n\ntemplate\
    \ <class T, class = void>\nstruct is_range_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
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
    \ constexpr bool is_sorted_container_v = is_sorted_container<T>::value;"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/traits.hpp
  requiredBy:
  - src/utility/repr.hpp
  - src/utility/vector_func.hpp
  - src/utility/container_func.hpp
  - src/utility/binary-search.hpp
  - src/geometry/argcmp.hpp
  - src/string/rolling-hash.hpp
  timestamp: '2026-10-13 13:03:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/vector-func.test.cpp
  - test/unittest/repr.test.cpp
  - test/unittest/functions.test.cpp
  - test/unittest/container-func-member.test.cpp
  - test/unittest/rolling-hash.test.cpp
  - test/unittest/container-func.test.cpp
  - test/aoj/0022.test.cpp
  - test/aoj/alds1-1-b.test.cpp
  - test/aoj/itp1-4-d.test.cpp
  - test/aoj/itp2-5-a.1.test.cpp
  - test/aoj/itp2-3-c.test.cpp
  - test/aoj/itp2-5-b.test.cpp
  - test/aoj/alds1-4-b.test.cpp
  - test/aoj/itp1-10-c.test.cpp
  - test/aoj/itp1-6-a.test.cpp
  - test/aoj/alds1-14-b.test.cpp
  - test/aoj/itp2-5-a.2.test.cpp
  - test/aoj/dsl-4-a.1.test.cpp
  - test/aoj/alds1-4-d.test.cpp
  - test/aoj/itp1-2-c.test.cpp
  - test/yosupo/static-range-sum.test.cpp
  - test/yosupo/enumerate-palindromes.test.cpp
  - test/yosupo/sort-points-by-argument.2.test.cpp
documentation_of: src/utility/traits.hpp
layout: document
title: "\u578B\u7279\u6027"
---

ライブラリ内のテンプレートで使う型特性とマクロです。[コンテナに対する関数](container_func.hpp) や [repr](repr.hpp) が、コンテナのメンバ関数の有無で呼び分けるのに使っています。

```cpp
static_assert(is_range_v<std::vector<int>>);
static_assert(has_sum_v<Range>);
template <class T, ENABLE_IF_T(std::is_integral_v<T>)>
T twice(T x) { return x * 2; }
```

## 型特性

| 名前 | 意味 |
|---|---|
| `is_range_v<T>` | `begin`、`end` で走査できるか |
| `is_sorted_container_v<T>` | `std::set` / `std::multiset` か |
| `has_repr_v<T>`、`has_type_str_v<T>`、`has_initializer_str_v<T>` | 同名のメンバ関数 (引数なし) を持つか |
| `has_max_v<T>`、`has_min_v<T>`、`has_sum_v<T>`、`has_product_v<T>`、`has_product_xor_v<T>` | 同上 |
| `has_reversed_v<T>`、`has_sorted_v<T>` | 同上 |
| `has_count_v<T, U>`、`has_find_v<T, U>`、`has_lower_bound_v<T, U>`、`has_upper_bound_v<T, U>` | `U` を引数に取る同名のメンバ関数を持つか |
| `mem_value_type<C>` / `mem_difference_type<C>` | `C::value_type` / `C::difference_type` |

## マクロ

| マクロ | 説明 |
|---|---|
| `ENABLE_IF_T(cond)` | テンプレート引数に書く SFINAE。`std::enable_if_t<cond, std::nullptr_t> = nullptr` になる |
| `HAS_METHOD(f)` | 引数なしのメンバ関数 `f` を持つかを調べる `has_f` / `has_f_v` を定義する |
| `HAS_METHOD_ARG(f)` | 引数を 1 つ取るメンバ関数 `f` を持つかを調べる `has_f` / `has_f_v` を定義する |
