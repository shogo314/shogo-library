---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/interval-set.test.cpp
    title: test/unittest/data_structures/interval-set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/674.2.test.cpp
    title: test/yukicoder/674.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u534A\u958B\u533A\u9593\u306E\u96C6\u5408"
    links: []
  bundledCode: "#line 2 \"src/data_structures/interval-set.hpp\"\n\n/**\n * @file\
    \ interval-set.hpp\n * @brief \u534A\u958B\u533A\u9593\u306E\u96C6\u5408\n */\n\
    \n#include <cassert>\n#include <cstddef>\n#include <functional>\n#include <iterator>\n\
    #include <optional>\n#include <set>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n\
    \ * @brief \u578B\u7279\u6027\n */\n\n#line 13 \"src/utility/traits.hpp\"\n\n\
    namespace internal_traits {\nusing std::begin, std::end;\n\ntemplate <class T,\
    \ class = void>\nstruct is_range_impl : std::false_type {};\ntemplate <class T>\n\
    struct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
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
    #line 19 \"src/data_structures/interval-set.hpp\"\n/**\n * @brief \u534A\u958B\
    \u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n * @tparam T \u30B9\u30AB\u30E9\u30FC\
    \n */\ntemplate <typename T = long long, class Compare = std::less<T>, ENABLE_IF_T(std::is_scalar_v<T>)>\n\
    class IntervalSet {\n   public:\n    using key_type = T;\n    using value_type\
    \ = std::pair<key_type, key_type>;\n    inline constexpr static auto key_comp\
    \ = Compare();\n    struct value_compare {\n        bool operator()(const value_type&\
    \ a, const value_type& b) const {\n            return key_comp(a.first, b.first)\
    \ || (!key_comp(b.first, a.first) && key_comp(b.second, a.second));\n        }\n\
    \    };\n    inline constexpr static auto value_comp = value_compare();\n\n  \
    \ private:\n    std::set<value_type, value_compare> data;\n    using iterator\
    \ = typename decltype(data)::iterator;\n    std::optional<std::pair<iterator,\
    \ iterator>> find(key_type l, key_type r) const {\n        auto itr_l = data.upper_bound({l,\
    \ l});\n        if (itr_l == data.begin()) {\n        } else {\n            if\
    \ (!key_comp(std::prev(itr_l)->second, l)) {\n                --itr_l;\n     \
    \       }\n        }\n        if (itr_l == data.end() || key_comp(r, itr_l->first))\
    \ {\n            return {};\n        }\n        auto itr_r = data.upper_bound({r,\
    \ r});\n        return std::pair<iterator, iterator>{itr_l, itr_r};\n    }\n\n\
    \   public:\n    IntervalSet() = default;\n    /**\n     * @brief k \u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u533A\u9593\u3002\u306A\u3051\u308C\u3070 std::nullopt\n\
    \     */\n    std::optional<value_type> covered_by(key_type k) const {\n     \
    \   auto itr = data.upper_bound({k, k});\n        if (itr == data.begin()) return\
    \ {};\n        --itr;\n        if (key_comp(k, itr->second)) {\n            return\
    \ *itr;\n        }\n        return {};\n    }\n    /**\n     * @brief [l,r) \u304C\
    \u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\u3002\u306A\
    \u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<value_type> covered_by(key_type\
    \ l, key_type r) const {\n        auto opt = find(l, r);\n        if (!opt.has_value())\
    \ {\n            return {};\n        }\n        std::pair<iterator, iterator>\
    \ p = opt.value();\n        if (p.first != std::prev(p.second)) {\n          \
    \  return {};\n        }\n        if (key_comp(l, p.first->first)) return {};\n\
    \        if (key_comp(p.first->second, r)) return {};\n        return value_type(p.first->first,\
    \ p.first->second);\n    }\n    void insert(key_type l, key_type r) {\n      \
    \  assert(key_comp(l, r));\n        auto opt = find(l, r);\n        if (!opt.has_value())\
    \ {\n            data.emplace(l, r);\n            return;\n        }\n       \
    \ auto [itr_l, itr_r] = opt.value();\n        if (key_comp(itr_l->first, l)) l\
    \ = itr_l->first;\n        if (key_comp(r, std::prev(itr_r)->second)) r = std::prev(itr_r)->second;\n\
    \        data.erase(itr_l, itr_r);\n        data.emplace(l, r);\n    }\n    void\
    \ erase(key_type l, key_type r) {\n        assert(key_comp(l, r));\n        auto\
    \ opt = find(l, r);\n        if (!opt.has_value()) {\n            return;\n  \
    \      }\n        auto [itr_l, itr_r] = opt.value();\n        std::vector<value_type>\
    \ tmp;\n        if (key_comp(itr_l->first, l)) tmp.push_back({itr_l->first, l});\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) tmp.push_back({r, std::prev(itr_r)->second});\n\
    \        data.erase(itr_l, itr_r);\n        while (!tmp.empty()) {\n         \
    \   data.insert(tmp.back());\n            tmp.pop_back();\n        }\n    }\n\
    \    long long size() const {\n        return static_cast<long long>(data.size());\n\
    \    }\n    std::vector<value_type> to_vector() const {\n        return std::vector<value_type>(data.begin(),\
    \ data.end());\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file interval-set.hpp\n * @brief \u534A\u958B\u533A\
    \u9593\u306E\u96C6\u5408\n */\n\n#include <cassert>\n#include <cstddef>\n#include\
    \ <functional>\n#include <iterator>\n#include <optional>\n#include <set>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\n#include \"../utility/traits.hpp\"\
    \n/**\n * @brief \u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n * @tparam\
    \ T \u30B9\u30AB\u30E9\u30FC\n */\ntemplate <typename T = long long, class Compare\
    \ = std::less<T>, ENABLE_IF_T(std::is_scalar_v<T>)>\nclass IntervalSet {\n   public:\n\
    \    using key_type = T;\n    using value_type = std::pair<key_type, key_type>;\n\
    \    inline constexpr static auto key_comp = Compare();\n    struct value_compare\
    \ {\n        bool operator()(const value_type& a, const value_type& b) const {\n\
    \            return key_comp(a.first, b.first) || (!key_comp(b.first, a.first)\
    \ && key_comp(b.second, a.second));\n        }\n    };\n    inline constexpr static\
    \ auto value_comp = value_compare();\n\n   private:\n    std::set<value_type,\
    \ value_compare> data;\n    using iterator = typename decltype(data)::iterator;\n\
    \    std::optional<std::pair<iterator, iterator>> find(key_type l, key_type r)\
    \ const {\n        auto itr_l = data.upper_bound({l, l});\n        if (itr_l ==\
    \ data.begin()) {\n        } else {\n            if (!key_comp(std::prev(itr_l)->second,\
    \ l)) {\n                --itr_l;\n            }\n        }\n        if (itr_l\
    \ == data.end() || key_comp(r, itr_l->first)) {\n            return {};\n    \
    \    }\n        auto itr_r = data.upper_bound({r, r});\n        return std::pair<iterator,\
    \ iterator>{itr_l, itr_r};\n    }\n\n   public:\n    IntervalSet() = default;\n\
    \    /**\n     * @brief k \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\
    \u3002\u306A\u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<value_type>\
    \ covered_by(key_type k) const {\n        auto itr = data.upper_bound({k, k});\n\
    \        if (itr == data.begin()) return {};\n        --itr;\n        if (key_comp(k,\
    \ itr->second)) {\n            return *itr;\n        }\n        return {};\n \
    \   }\n    /**\n     * @brief [l,r) \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u533A\u9593\u3002\u306A\u3051\u308C\u3070 std::nullopt\n  \
    \   */\n    std::optional<value_type> covered_by(key_type l, key_type r) const\
    \ {\n        auto opt = find(l, r);\n        if (!opt.has_value()) {\n       \
    \     return {};\n        }\n        std::pair<iterator, iterator> p = opt.value();\n\
    \        if (p.first != std::prev(p.second)) {\n            return {};\n     \
    \   }\n        if (key_comp(l, p.first->first)) return {};\n        if (key_comp(p.first->second,\
    \ r)) return {};\n        return value_type(p.first->first, p.first->second);\n\
    \    }\n    void insert(key_type l, key_type r) {\n        assert(key_comp(l,\
    \ r));\n        auto opt = find(l, r);\n        if (!opt.has_value()) {\n    \
    \        data.emplace(l, r);\n            return;\n        }\n        auto [itr_l,\
    \ itr_r] = opt.value();\n        if (key_comp(itr_l->first, l)) l = itr_l->first;\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) r = std::prev(itr_r)->second;\n\
    \        data.erase(itr_l, itr_r);\n        data.emplace(l, r);\n    }\n    void\
    \ erase(key_type l, key_type r) {\n        assert(key_comp(l, r));\n        auto\
    \ opt = find(l, r);\n        if (!opt.has_value()) {\n            return;\n  \
    \      }\n        auto [itr_l, itr_r] = opt.value();\n        std::vector<value_type>\
    \ tmp;\n        if (key_comp(itr_l->first, l)) tmp.push_back({itr_l->first, l});\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) tmp.push_back({r, std::prev(itr_r)->second});\n\
    \        data.erase(itr_l, itr_r);\n        while (!tmp.empty()) {\n         \
    \   data.insert(tmp.back());\n            tmp.pop_back();\n        }\n    }\n\
    \    long long size() const {\n        return static_cast<long long>(data.size());\n\
    \    }\n    std::vector<value_type> to_vector() const {\n        return std::vector<value_type>(data.begin(),\
    \ data.end());\n    }\n};\n"
  dependsOn:
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/data_structures/interval-set.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/interval-set.test.cpp
  - test/yukicoder/674.2.test.cpp
documentation_of: src/data_structures/interval-set.hpp
layout: document
title: "\u534A\u958B\u533A\u9593\u306E\u96C6\u5408"
---

半開区間 $[l, r)$ の和集合を、重ならない区間の集合として管理します。区間を追加すると、重なる区間や接する区間は1つにまとめられます。

```cpp
IntervalSet<long long> s;
s.insert(1, 3); s.insert(3, 5); s.insert(7, 9);  // {[1, 5), [7, 9)}
s.erase(2, 4);                                  // {[1, 2), [4, 5), [7, 9)}
s.covered_by(8);                                // [7, 9)
s.covered_by(5);                                // なし (std::nullopt)
```

整数の $a$ 以上 $b$ 以下を表す場合は、$[a, b + 1)$ として追加します。

## メンバ関数

`IntervalSet<T = long long, Compare = std::less<T>>` です。$n$ を区間の個数とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `insert(l, r)` | $[l, r)$ を追加 ($l < r$) | ならし $O(\log n)$ |
| `erase(l, r)` | $[l, r)$ を取り除く ($l < r$) | ならし $O(\log n)$ |
| `covered_by(k)` | `k` を含む区間 (`std::optional<std::pair<T, T>>`)。なければ `std::nullopt` | $O(\log n)$ |
| `covered_by(l, r)` | $[l, r)$ を丸ごと含む区間 (`std::optional`)。なければ `std::nullopt` | $O(\log n)$ |
| `size()` | 区間の個数 | $O(1)$ |
| `to_vector()` | 区間の一覧 (左端の昇順) | $O(n)$ |

## 関連

- 区間への作用と 1 点取得なら [imos 法](imos.hpp)
- 値の多重集合なら [Counter](counter.hpp)
