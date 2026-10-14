---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/interval-set.hpp
    title: "\u534A\u958B\u533A\u9593\u306E\u96C6\u5408"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/interval-set.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// IntervalSet\
    \ \u3092\u300C\u5404\u6574\u6570\u70B9\u304C\u8986\u308F\u308C\u3066\u3044\u308B\
    \u304B\u300D\u306E\u914D\u5217\u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n\
    #include <optional>\n#include <random>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/data_structures/interval-set.hpp\"\n\n/**\n * @file interval-set.hpp\n\
    \ * @brief \u534A\u958B\u533A\u9593\u306E\u96C6\u5408\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <functional>\n#include <iterator>\n#line 13 \"src/data_structures/interval-set.hpp\"\
    \n#include <set>\n#include <type_traits>\n#line 17 \"src/data_structures/interval-set.hpp\"\
    \n/**\n * @brief \u534A\u958B\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\n * @tparam\
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
    \    }\n        auto itr_r = data.upper_bound({r, r});\n        return std::pair<iterator,\
    \ iterator>{itr_l, itr_r};\n    }\n\n   public:\n    IntervalSet() = default;\n\
    \    /**\n     * @brief k \u304C\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\
    \n     */\n    std::optional<value_type> covered_by(key_type k) const {\n    \
    \    auto itr = data.upper_bound({k, k});\n        if (itr == data.begin()) return\
    \ {};\n        --itr;\n        if (key_comp(k, itr->second)) {\n            return\
    \ *itr;\n        }\n        return {};\n    }\n    /**\n     * @brief [l,r) \u304C\
    \u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\u533A\u9593\n     */\n\
    \    std::optional<value_type> covered_by(key_type l, key_type r) const {\n  \
    \      auto opt = find(l, r);\n        if (not opt.has_value()) {\n          \
    \  return {};\n        }\n        std::pair<iterator, iterator> p = opt.value();\n\
    \        if (p.first != std::prev(p.second)) {\n            return {};\n     \
    \   }\n        if (key_comp(l, p.first->first)) return {};\n        if (key_comp(p.first->second,\
    \ r)) return {};\n        return value_type(p.first->first, p.first->second);\n\
    \    }\n    void insert(key_type l, key_type r) {\n        assert(key_comp(l,\
    \ r));\n        auto opt = find(l, r);\n        if (not opt.has_value()) {\n \
    \           data.emplace(l, r);\n            return;\n        }\n        auto\
    \ [itr_l, itr_r] = opt.value();\n        if (key_comp(itr_l->first, l)) l = itr_l->first;\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) r = std::prev(itr_r)->second;\n\
    \        data.erase(itr_l, itr_r);\n        data.emplace(l, r);\n    }\n    void\
    \ erase(key_type l, key_type r) {\n        assert(key_comp(l, r));\n        auto\
    \ opt = find(l, r);\n        if (not opt.has_value()) {\n            return;\n\
    \        }\n        auto [itr_l, itr_r] = opt.value();\n        std::vector<value_type>\
    \ tmp;\n        if (key_comp(itr_l->first, l)) tmp.push_back({itr_l->first, l});\n\
    \        if (key_comp(r, std::prev(itr_r)->second)) tmp.push_back({r, std::prev(itr_r)->second});\n\
    \        data.erase(itr_l, itr_r);\n        while (not tmp.empty()) {\n      \
    \      data.insert(tmp.back());\n            tmp.pop_back();\n        }\n    }\n\
    \    int size() const {\n        return static_cast<int>(data.size());\n    }\n\
    \    std::vector<value_type> to_vector() const {\n        return std::vector<value_type>(data.begin(),\
    \ data.end());\n    }\n};\n#line 13 \"test/unittest/interval-set.test.cpp\"\n\n\
    // \u5EA7\u6A19 [LO, HI) \u306E\u7BC4\u56F2\u3067\u64CD\u4F5C\u3059\u308B (\u8CA0\
    \u306E\u5EA7\u6A19\u3082\u4F7F\u3046)\nconstexpr int LO = -5, HI = 20;\n\n// \u8986\
    \u308F\u308C\u3066\u3044\u308B\u70B9\u306E\u6975\u5927\u306A\u9023\u7D9A\u90E8\
    \u5206\u3092\u534A\u958B\u533A\u9593\u306E\u5217\u306B\u3059\u308B (\u63A5\u3059\
    \u308B\u533A\u9593\u306F\u307E\u3068\u3081\u3089\u308C\u308B)\nstd::vector<std::pair<long\
    \ long, long long>> runs(const std::vector<bool>& cov) {\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < (int)cov.size();) {\n      \
    \  if (!cov[i]) {\n            i++;\n            continue;\n        }\n      \
    \  int j = i;\n        while (j < (int)cov.size() && cov[j]) j++;\n        res.push_back({i\
    \ + LO, j + LO});\n        i = j;\n    }\n    return res;\n}\n\nint main() {\n\
    \    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        IntervalSet<long long> st;\n        std::vector<bool>\
    \ cov(HI - LO, false);\n        for (int t = 0; t < 30 && ok; t++) {\n       \
    \     long long l = LO + rng() % (HI - LO - 1);\n            long long r = l +\
    \ 1 + rng() % (HI - l - 1 + 1);\n            if (r > HI) r = HI;\n           \
    \ if (rng() % 3 != 0) {\n                st.insert(l, r);\n                for\
    \ (long long x = l; x < r; x++) cov[x - LO] = true;\n            } else {\n  \
    \              st.erase(l, r);\n                for (long long x = l; x < r; x++)\
    \ cov[x - LO] = false;\n            }\n            auto expect = runs(cov);\n\
    \            if (st.to_vector() != expect || st.size() != (int)expect.size())\
    \ ok = false;\n\n            // covered_by(k): k \u3092\u542B\u3080\u533A\u9593\
    \n            for (long long k = LO; k < HI; k++) {\n                std::optional<std::pair<long\
    \ long, long long>> e;\n                for (auto& iv : expect) {\n          \
    \          if (iv.first <= k && k < iv.second) e = iv;\n                }\n  \
    \              if (st.covered_by(k) != e) ok = false;\n            }\n       \
    \     // covered_by(l, r): [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3080\u533A\u9593\
    \n            for (long long a = LO; a < HI; a++) {\n                for (long\
    \ long b = a + 1; b <= HI; b++) {\n                    std::optional<std::pair<long\
    \ long, long long>> e;\n                    for (auto& iv : expect) {\n      \
    \                  if (iv.first <= a && b <= iv.second) e = iv;\n            \
    \        }\n                    if (st.covered_by(a, b) != e) ok = false;\n  \
    \              }\n            }\n        }\n    }\n    if (ok) std::cout << \"\
    Hello World\" << std::endl;\n    else std::cerr << \"failed\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// IntervalSet \u3092\u300C\u5404\u6574\u6570\u70B9\u304C\u8986\u308F\u308C\
    \u3066\u3044\u308B\u304B\u300D\u306E\u914D\u5217\u306B\u3088\u308B\u611A\u76F4\
    \u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #include <iostream>\n#include <optional>\n#include <random>\n#include <utility>\n\
    #include <vector>\n\n#include \"../../src/data_structures/interval-set.hpp\"\n\
    \n// \u5EA7\u6A19 [LO, HI) \u306E\u7BC4\u56F2\u3067\u64CD\u4F5C\u3059\u308B (\u8CA0\
    \u306E\u5EA7\u6A19\u3082\u4F7F\u3046)\nconstexpr int LO = -5, HI = 20;\n\n// \u8986\
    \u308F\u308C\u3066\u3044\u308B\u70B9\u306E\u6975\u5927\u306A\u9023\u7D9A\u90E8\
    \u5206\u3092\u534A\u958B\u533A\u9593\u306E\u5217\u306B\u3059\u308B (\u63A5\u3059\
    \u308B\u533A\u9593\u306F\u307E\u3068\u3081\u3089\u308C\u308B)\nstd::vector<std::pair<long\
    \ long, long long>> runs(const std::vector<bool>& cov) {\n    std::vector<std::pair<long\
    \ long, long long>> res;\n    for (int i = 0; i < (int)cov.size();) {\n      \
    \  if (!cov[i]) {\n            i++;\n            continue;\n        }\n      \
    \  int j = i;\n        while (j < (int)cov.size() && cov[j]) j++;\n        res.push_back({i\
    \ + LO, j + LO});\n        i = j;\n    }\n    return res;\n}\n\nint main() {\n\
    \    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        IntervalSet<long long> st;\n        std::vector<bool>\
    \ cov(HI - LO, false);\n        for (int t = 0; t < 30 && ok; t++) {\n       \
    \     long long l = LO + rng() % (HI - LO - 1);\n            long long r = l +\
    \ 1 + rng() % (HI - l - 1 + 1);\n            if (r > HI) r = HI;\n           \
    \ if (rng() % 3 != 0) {\n                st.insert(l, r);\n                for\
    \ (long long x = l; x < r; x++) cov[x - LO] = true;\n            } else {\n  \
    \              st.erase(l, r);\n                for (long long x = l; x < r; x++)\
    \ cov[x - LO] = false;\n            }\n            auto expect = runs(cov);\n\
    \            if (st.to_vector() != expect || st.size() != (int)expect.size())\
    \ ok = false;\n\n            // covered_by(k): k \u3092\u542B\u3080\u533A\u9593\
    \n            for (long long k = LO; k < HI; k++) {\n                std::optional<std::pair<long\
    \ long, long long>> e;\n                for (auto& iv : expect) {\n          \
    \          if (iv.first <= k && k < iv.second) e = iv;\n                }\n  \
    \              if (st.covered_by(k) != e) ok = false;\n            }\n       \
    \     // covered_by(l, r): [l, r) \u3092\u5B8C\u5168\u306B\u542B\u3080\u533A\u9593\
    \n            for (long long a = LO; a < HI; a++) {\n                for (long\
    \ long b = a + 1; b <= HI; b++) {\n                    std::optional<std::pair<long\
    \ long, long long>> e;\n                    for (auto& iv : expect) {\n      \
    \                  if (iv.first <= a && b <= iv.second) e = iv;\n            \
    \        }\n                    if (st.covered_by(a, b) != e) ok = false;\n  \
    \              }\n            }\n        }\n    }\n    if (ok) std::cout << \"\
    Hello World\" << std::endl;\n    else std::cerr << \"failed\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/interval-set.hpp
  isVerificationFile: true
  path: test/unittest/interval-set.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 07:02:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/interval-set.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/interval-set.test.cpp
- /verify/test/unittest/interval-set.test.cpp.html
title: test/unittest/interval-set.test.cpp
---
