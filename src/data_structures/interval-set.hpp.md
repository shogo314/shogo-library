---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/interval-set.test.cpp
    title: test/unittest/interval-set.test.cpp
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
    #include <vector>\n/**\n * @brief \u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\
    \u308B\n * @tparam T \u30B9\u30AB\u30E9\u30FC\n */\ntemplate <typename T = long\
    \ long, class Compare = std::less<T>, std::enable_if_t<std::is_scalar_v<T>>* =\
    \ nullptr>\nclass IntervalSet {\n   public:\n    using key_type = T;\n    using\
    \ value_type = std::pair<key_type, key_type>;\n    inline constexpr static auto\
    \ key_comp = Compare();\n    struct value_compare {\n        bool operator()(const\
    \ value_type& a, const value_type& b) const {\n            return key_comp(a.first,\
    \ b.first) || (!key_comp(b.first, a.first) && key_comp(b.second, a.second));\n\
    \        }\n    };\n    inline constexpr static auto value_comp = value_compare();\n\
    \n   private:\n    std::set<value_type, value_compare> data;\n    using iterator\
    \ = typename decltype(data)::iterator;\n    std::optional<std::pair<iterator,\
    \ iterator>> find(key_type l, key_type r) const {\n        auto itr_l = data.upper_bound({l,\
    \ l});\n        if (itr_l == data.begin()) {\n        } else {\n            if\
    \ (!key_comp(std::prev(itr_l)->second, l)) {\n                --itr_l;\n     \
    \       }\n        }\n        if (itr_l == data.end() || key_comp(r, itr_l->first))\
    \ {\n            return {};\n        }\n        auto itr_r = data.upper_bound({r,\
    \ r});\n        return std::pair<iterator, iterator>{itr_l, itr_r};\n    }\n\n\
    \   public:\n    IntervalSet() = default;\n    /**\n     * @brief k \u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u533A\u9593\n     */\n    std::optional<value_type>\
    \ covered_by(key_type k) const {\n        auto itr = data.upper_bound({k, k});\n\
    \        if (itr == data.begin()) return {};\n        --itr;\n        if (key_comp(k,\
    \ itr->second)) {\n            return *itr;\n        }\n        return {};\n \
    \   }\n    /**\n     * @brief [l,r) \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u533A\u9593\n     */\n    std::optional<value_type> covered_by(key_type\
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
    \    int size() const {\n        return static_cast<int>(data.size());\n    }\n\
    \    std::vector<value_type> to_vector() const {\n        return std::vector<value_type>(data.begin(),\
    \ data.end());\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file interval-set.hpp\n * @brief \u534A\u958B\u533A\
    \u9593\u306E\u96C6\u5408\n */\n\n#include <cassert>\n#include <cstddef>\n#include\
    \ <functional>\n#include <iterator>\n#include <optional>\n#include <set>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n/**\n * @brief \u534A\u958B\
    \u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n * @tparam T \u30B9\u30AB\u30E9\u30FC\
    \n */\ntemplate <typename T = long long, class Compare = std::less<T>, std::enable_if_t<std::is_scalar_v<T>>*\
    \ = nullptr>\nclass IntervalSet {\n   public:\n    using key_type = T;\n    using\
    \ value_type = std::pair<key_type, key_type>;\n    inline constexpr static auto\
    \ key_comp = Compare();\n    struct value_compare {\n        bool operator()(const\
    \ value_type& a, const value_type& b) const {\n            return key_comp(a.first,\
    \ b.first) || (!key_comp(b.first, a.first) && key_comp(b.second, a.second));\n\
    \        }\n    };\n    inline constexpr static auto value_comp = value_compare();\n\
    \n   private:\n    std::set<value_type, value_compare> data;\n    using iterator\
    \ = typename decltype(data)::iterator;\n    std::optional<std::pair<iterator,\
    \ iterator>> find(key_type l, key_type r) const {\n        auto itr_l = data.upper_bound({l,\
    \ l});\n        if (itr_l == data.begin()) {\n        } else {\n            if\
    \ (!key_comp(std::prev(itr_l)->second, l)) {\n                --itr_l;\n     \
    \       }\n        }\n        if (itr_l == data.end() || key_comp(r, itr_l->first))\
    \ {\n            return {};\n        }\n        auto itr_r = data.upper_bound({r,\
    \ r});\n        return std::pair<iterator, iterator>{itr_l, itr_r};\n    }\n\n\
    \   public:\n    IntervalSet() = default;\n    /**\n     * @brief k \u304C\u542B\
    \u307E\u308C\u3066\u3044\u308B\u533A\u9593\n     */\n    std::optional<value_type>\
    \ covered_by(key_type k) const {\n        auto itr = data.upper_bound({k, k});\n\
    \        if (itr == data.begin()) return {};\n        --itr;\n        if (key_comp(k,\
    \ itr->second)) {\n            return *itr;\n        }\n        return {};\n \
    \   }\n    /**\n     * @brief [l,r) \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B\u533A\u9593\n     */\n    std::optional<value_type> covered_by(key_type\
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
    \    int size() const {\n        return static_cast<int>(data.size());\n    }\n\
    \    std::vector<value_type> to_vector() const {\n        return std::vector<value_type>(data.begin(),\
    \ data.end());\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/interval-set.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/interval-set.test.cpp
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
| `covered_by(k)` | `k` を含む区間 (`std::optional<std::pair<T, T>>`) | $O(\log n)$ |
| `covered_by(l, r)` | $[l, r)$ を丸ごと含む区間 (`std::optional`) | $O(\log n)$ |
| `size()` | 区間の個数 | $O(1)$ |
| `to_vector()` | 区間の一覧 (左端の昇順) | $O(n)$ |

## 関連

- 区間への作用と 1 点取得なら [imos 法](imos.hpp)
- 値の多重集合なら [Counter](counter.hpp)
