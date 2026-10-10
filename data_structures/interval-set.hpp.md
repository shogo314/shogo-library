---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"data_structures/interval-set.hpp\"\n#include <cassert>\n\
    #include <functional>\n#include <iostream>\n#include <iterator>\n#include <limits>\n\
    #include <optional>\n#include <set>\n#include <type_traits>\n#include <vector>\n\
    /**\n * @brief \u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n * @tparam\
    \ T \u30B9\u30AB\u30E9\u30FC\n */\ntemplate <typename T = long long, class Compare\
    \ = std::less<T>, std::enable_if_t<std::is_scalar_v<T>>* = nullptr>\nstruct IntervalSet\
    \ {\n   public:\n    using key_type = T;\n    using value_type = std::pair<key_type,\
    \ key_type>;\n    inline constexpr static auto key_comp = Compare();\n    struct\
    \ value_compare {\n        bool operator()(const value_type& a, const value_type&\
    \ b) const {\n            return key_comp(a.first, b.first) or (not key_comp(b.first,\
    \ a.first) and key_comp(b.second, a.second));\n        }\n    };\n    inline constexpr\
    \ static auto value_comp = value_compare();\n\n   private:\n    std::set<value_type,\
    \ value_compare> data;\n    using iterator = typename decltype(data)::iterator;\n\
    \    std::optional<std::pair<iterator, iterator>> find(key_type l, key_type r)\
    \ const {\n        auto itr_l = data.upper_bound({l, l});\n        if (itr_l ==\
    \ data.begin()) {\n        } else {\n            if (not key_comp(std::prev(itr_l)->second,\
    \ l)) {\n                --itr_l;\n            }\n        }\n        if (itr_l\
    \ == data.end() or key_comp(r, itr_l->first)) {\n            return {};\n    \
    \    }\n        if (key_comp(itr_l->first, l)) l = itr_l->first;\n        auto\
    \ itr_r = data.upper_bound({r, r});\n        return std::pair<iterator, iterator>{itr_l,\
    \ itr_r};\n    }\n\n   public:\n    IntervalSet() = default;\n    /**\n     *\
    \ @brief k \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\n     */\n \
    \   std::optional<value_type> covered_by(key_type k) const {\n        auto itr\
    \ = data.upper_bound({k, k});\n        if (itr == data.begin()) return {};\n \
    \       --itr;\n        if (key_comp(k, itr->second)) {\n            return *itr;\n\
    \        }\n        return {};\n    }\n    /**\n     * @brief [l,r) \u304C\u5B8C\
    \u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\n     */\n    std::optional<value_type>\
    \ covered_by(key_type l, key_type r) const {\n        auto opt = find(l, r);\n\
    \        if (not opt.has_value()) {\n            return {};\n        }\n     \
    \   std::pair<iterator, iterator> p = opt.value();\n        if (p.first != std::prev(p.second))\
    \ {\n            return {};\n        }\n        if (key_comp(l, p.first->first))\
    \ return {};\n        if (key_comp(p.first->second, r)) return {};\n        return\
    \ value_type(p.first->first, p.first->second);\n    }\n    void insert(key_type\
    \ l, key_type r) {\n        assert(key_comp(l, r));\n        auto opt = find(l,\
    \ r);\n        if (not opt.has_value()) {\n            data.emplace(l, r);\n \
    \           return;\n        }\n        auto [itr_l, itr_r] = opt.value();\n \
    \       if (key_comp(itr_l->first, l)) l = itr_l->first;\n        if (key_comp(r,\
    \ std::prev(itr_r)->second)) r = std::prev(itr_r)->second;\n        data.erase(itr_l,\
    \ itr_r);\n        data.emplace(l, r);\n    };\n    void erase(key_type l, key_type\
    \ r) {\n        assert(key_comp(l, r));\n        auto opt = find(l, r);\n    \
    \    if (not opt.has_value()) {\n            return;\n        }\n        auto\
    \ [itr_l, itr_r] = opt.value();\n        std::vector<value_type> tmp;\n      \
    \  if (key_comp(itr_l->first, l)) tmp.push_back({itr_l->first, l});\n        if\
    \ (key_comp(r, std::prev(itr_r)->second)) tmp.push_back({r, std::prev(itr_r)->second});\n\
    \        data.erase(itr_l, itr_r);\n        while (not tmp.empty()) {\n      \
    \      data.insert(tmp.back());\n            tmp.pop_back();\n        }\n    }\n\
    \    std::size_t size() const {\n        return data.size();\n    }\n    std::vector<value_type>\
    \ to_vector() const {\n        return std::vector<value_type>(data.begin(), data.end());\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <functional>\n#include <iostream>\n\
    #include <iterator>\n#include <limits>\n#include <optional>\n#include <set>\n\
    #include <type_traits>\n#include <vector>\n/**\n * @brief \u534A\u958B\u533A\u9593\
    \u3092\u7BA1\u7406\u3059\u308B\n * @tparam T \u30B9\u30AB\u30E9\u30FC\n */\ntemplate\
    \ <typename T = long long, class Compare = std::less<T>, std::enable_if_t<std::is_scalar_v<T>>*\
    \ = nullptr>\nstruct IntervalSet {\n   public:\n    using key_type = T;\n    using\
    \ value_type = std::pair<key_type, key_type>;\n    inline constexpr static auto\
    \ key_comp = Compare();\n    struct value_compare {\n        bool operator()(const\
    \ value_type& a, const value_type& b) const {\n            return key_comp(a.first,\
    \ b.first) or (not key_comp(b.first, a.first) and key_comp(b.second, a.second));\n\
    \        }\n    };\n    inline constexpr static auto value_comp = value_compare();\n\
    \n   private:\n    std::set<value_type, value_compare> data;\n    using iterator\
    \ = typename decltype(data)::iterator;\n    std::optional<std::pair<iterator,\
    \ iterator>> find(key_type l, key_type r) const {\n        auto itr_l = data.upper_bound({l,\
    \ l});\n        if (itr_l == data.begin()) {\n        } else {\n            if\
    \ (not key_comp(std::prev(itr_l)->second, l)) {\n                --itr_l;\n  \
    \          }\n        }\n        if (itr_l == data.end() or key_comp(r, itr_l->first))\
    \ {\n            return {};\n        }\n        if (key_comp(itr_l->first, l))\
    \ l = itr_l->first;\n        auto itr_r = data.upper_bound({r, r});\n        return\
    \ std::pair<iterator, iterator>{itr_l, itr_r};\n    }\n\n   public:\n    IntervalSet()\
    \ = default;\n    /**\n     * @brief k \u304C\u542B\u307E\u308C\u3066\u3044\u308B\
    \u533A\u9593\n     */\n    std::optional<value_type> covered_by(key_type k) const\
    \ {\n        auto itr = data.upper_bound({k, k});\n        if (itr == data.begin())\
    \ return {};\n        --itr;\n        if (key_comp(k, itr->second)) {\n      \
    \      return *itr;\n        }\n        return {};\n    }\n    /**\n     * @brief\
    \ [l,r) \u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\
    \n     */\n    std::optional<value_type> covered_by(key_type l, key_type r) const\
    \ {\n        auto opt = find(l, r);\n        if (not opt.has_value()) {\n    \
    \        return {};\n        }\n        std::pair<iterator, iterator> p = opt.value();\n\
    \        if (p.first != std::prev(p.second)) {\n            return {};\n     \
    \   }\n        if (key_comp(l, p.first->first)) return {};\n        if (key_comp(p.first->second,\
    \ r)) return {};\n        return value_type(p.first->first, p.first->second);\n\
    \    }\n    void insert(key_type l, key_type r) {\n        assert(key_comp(l,\
    \ r));\n        auto opt = find(l, r);\n        if (not opt.has_value()) {\n \
    \           data.emplace(l, r);\n            return;\n        }\n        auto\
    \ [itr_l, itr_r] = opt.value();\n        if (key_comp(itr_l->first, l)) l = itr_l->first;\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) r = std::prev(itr_r)->second;\n\
    \        data.erase(itr_l, itr_r);\n        data.emplace(l, r);\n    };\n    void\
    \ erase(key_type l, key_type r) {\n        assert(key_comp(l, r));\n        auto\
    \ opt = find(l, r);\n        if (not opt.has_value()) {\n            return;\n\
    \        }\n        auto [itr_l, itr_r] = opt.value();\n        std::vector<value_type>\
    \ tmp;\n        if (key_comp(itr_l->first, l)) tmp.push_back({itr_l->first, l});\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) tmp.push_back({r, std::prev(itr_r)->second});\n\
    \        data.erase(itr_l, itr_r);\n        while (not tmp.empty()) {\n      \
    \      data.insert(tmp.back());\n            tmp.pop_back();\n        }\n    }\n\
    \    std::size_t size() const {\n        return data.size();\n    }\n    std::vector<value_type>\
    \ to_vector() const {\n        return std::vector<value_type>(data.begin(), data.end());\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/interval-set.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/interval-set.hpp
layout: document
redirect_from:
- /library/data_structures/interval-set.hpp
- /library/data_structures/interval-set.hpp.html
title: "\u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B"
---
