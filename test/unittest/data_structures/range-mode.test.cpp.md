---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/range-mode.hpp
    title: "\u533A\u9593\u306E\u6700\u983B\u5024"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/range-mode.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// range-mode.hpp \u306E RangeMode \u3092\u3001\u533A\u9593\u306E\u5024\u3092\
    \u6570\u3048\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u8FD4\
    \u3057\u305F\u5024\u306E\u51FA\u73FE\u56DE\u6570\u304C\u6700\u5927\u3067\u3001\
    \u305D\u306E\u56DE\u6570\u3068\u4E00\u81F4\u3059\u308B\u304B\u3092\u78BA\u304B\
    \u3081\u308B (\u6700\u983B\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u3069\u308C\
    \u3067\u3082\u3088\u3044)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/range-mode.hpp\"\n\n\
    /**\n * @file range-mode.hpp\n * @brief \u533A\u9593\u306E\u6700\u983B\u5024\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u56FA\u5B9A\u3057\u305F\u5217\u306B\u3064\
    \u3044\u3066\u3001\u533A\u9593\u306E\u6700\u983B\u5024\u3068\u305D\u306E\u51FA\
    \u73FE\u56DE\u6570\u3092\u30AA\u30F3\u30E9\u30A4\u30F3\u3067\u7B54\u3048\u308B\
    \n *\n * \u9577\u3055 B \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u3001\
    \u30D6\u30ED\u30C3\u30AF\u306E\u533A\u9593\u3054\u3068\u306E\u6700\u983B\u5024\
    \u3092\u524D\u8A08\u7B97\u3059\u308B\u3002\u30AF\u30A8\u30EA\u3067\u306F\u3001\
    \u9593\u306E\u30D6\u30ED\u30C3\u30AF\u306E\u6700\u983B\u5024\u304B\u3089\u59CB\
    \u3081\u3066\u3001\n * \u7AEF\u306E\u8981\u7D20\u3054\u3068\u306B\u300C\u305D\u306E\
    \u5024\u306E\u51FA\u73FE\u4F4D\u7F6E\u306E\u5217\u300D\u3067\u51FA\u73FE\u56DE\
    \u6570\u304C 1 \u3064\u5897\u3084\u305B\u308B\u304B\u3092\u8ABF\u3079\u308B (\u5897\
    \u3084\u3059\u56DE\u6570\u306E\u5408\u8A08\u306F\u7AEF\u306E\u9577\u3055\u4EE5\
    \u4E0B)\n * \u69CB\u7BC9 O(n sqrt(n))\u3001\u30AF\u30A8\u30EA O(sqrt(n))\u3001\
    \u30E1\u30E2\u30EA O(n)\n * \u4F8B:\n * RangeMode rm(a);\n * auto [value, count]\
    \ = rm.mode(l, r);\n *\n * @tparam T \u5024\u306E\u578B (operator< \u3067\u6BD4\
    \u3079\u3089\u308C\u308B\u3053\u3068)\n */\ntemplate <typename T>\nclass RangeMode\
    \ {\n    long long n, B;\n    std::vector<T> vals;                      // \u5024\
    \u306E\u7A2E\u985E (\u6607\u9806)\n    std::vector<long long> id;            \
    \    // id[i]: a[i] \u306E vals \u3067\u306E\u756A\u53F7\n    std::vector<long\
    \ long> rank;              // rank[i]: a[i] \u3068\u540C\u3058\u5024\u306E\u3046\
    \u3061 i \u3088\u308A\u524D\u306B\u3042\u308B\u3082\u306E\u306E\u500B\u6570\n\
    \    std::vector<std::vector<long long>> pos;  // pos[v]: \u5024 v \u306E\u51FA\
    \u73FE\u4F4D\u7F6E (\u6607\u9806)\n    // best[i][j]: \u30D6\u30ED\u30C3\u30AF\
    \ i \u304B\u3089 j \u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u306E\u6700\u983B\
    \u5024\u306E\u756A\u53F7\u3068\u51FA\u73FE\u56DE\u6570\n    std::vector<std::vector<std::pair<long\
    \ long, long long>>> best;\n\n   public:\n    /**\n     * @brief \u5217 a \u304B\
    \u3089\u4F5C\u308B\n     */\n    explicit RangeMode(const std::vector<T>& a) :\
    \ n(a.size()), vals(a), id(n), rank(n) {\n        std::sort(vals.begin(), vals.end());\n\
    \        vals.erase(std::unique(vals.begin(), vals.end()), vals.end());\n    \
    \    pos.resize(vals.size());\n        for (long long i = 0; i < n; i++) {\n \
    \           id[i] = std::lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();\n\
    \            rank[i] = pos[id[i]].size();\n            pos[id[i]].push_back(i);\n\
    \        }\n        B = std::max(1LL, static_cast<long long>(std::sqrt(static_cast<double>(n))));\n\
    \        const long long k = (n + B - 1) / B;\n        best.assign(k, std::vector<std::pair<long\
    \ long, long long>>(k));\n        std::vector<long long> cnt(vals.size());\n \
    \       for (long long i = 0; i < k; i++) {\n            std::fill(cnt.begin(),\
    \ cnt.end(), 0);\n            std::pair<long long, long long> cur = {-1, 0};\n\
    \            for (long long j = i * B; j < n; j++) {\n                if (++cnt[id[j]]\
    \ > cur.second) cur = {id[j], cnt[id[j]]};\n                if (j % B == B - 1\
    \ || j == n - 1) best[i][j / B] = cur;\n            }\n        }\n    }\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief a[l], ..., a[r-1] \u306E\u6700\u983B\u5024\u306E\
    \ 1 \u3064\u3068\u3001\u305D\u306E\u51FA\u73FE\u56DE\u6570 {\u5024, \u56DE\u6570\
    }\n     * @pre l < r\n     */\n    std::pair<T, long long> mode(long long l, long\
    \ long r) const {\n        assert(0 <= l && l < r && r <= n);\n        // \u9593\
    \u306B\u3042\u308B\u30D6\u30ED\u30C3\u30AF [bl, br]\u3002\u306A\u3051\u308C\u3070\
    \u7A7A\u306B\u3057\u3066\u3001\u3059\u3079\u3066\u7AEF\u3068\u3057\u3066\u6271\
    \u3046\n        const long long bl = (l + B - 1) / B, br = r / B - 1;\n      \
    \  long long v = -1, f = 0, mid_l = r, mid_r = r;\n        if (bl <= br) v = best[bl][br].first,\
    \ f = best[bl][br].second, mid_l = bl * B, mid_r = (br + 1) * B;\n        // \u5DE6\
    \u7AEF: i \u304B\u3089\u53F3\u306B f + 1 \u500B\u76EE\u306E\u51FA\u73FE\u304C\
    \ r \u3088\u308A\u524D\u306B\u3042\u308C\u3070\u5897\u3084\u3059\n        for\
    \ (long long i = l; i < mid_l; i++) {\n            const auto& p = pos[id[i]];\n\
    \            while (rank[i] + f < static_cast<long long>(p.size()) && p[rank[i]\
    \ + f] < r) v = id[i], f++;\n        }\n        // \u53F3\u7AEF: i \u304B\u3089\
    \u5DE6\u306B f + 1 \u500B\u76EE\u306E\u51FA\u73FE\u304C l \u4EE5\u4E0A\u306A\u3089\
    \u5897\u3084\u3059\n        for (long long i = mid_r; i < r; i++) {\n        \
    \    const auto& p = pos[id[i]];\n            while (rank[i] - f >= 0 && p[rank[i]\
    \ - f] >= l) v = id[i], f++;\n        }\n        return {vals[v], f};\n    }\n\
    };\n\ntemplate <typename T>\nRangeMode(std::vector<T>) -> RangeMode<T>;\n#line\
    \ 8 \"test/unittest/data_structures/range-mode.test.cpp\"\n\n#include <iostream>\n\
    #include <map>\n#include <random>\n#include <string>\n#line 14 \"test/unittest/data_structures/range-mode.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 60 + 1, kinds\
    \ = rng() % 8 + 1;\n        std::vector<int> a(n);\n        for (auto& x : a)\
    \ x = static_cast<int>(rng() % kinds) * 1000 - 3000;\n        RangeMode rm(a);\n\
    \        if (rm.size() != n) ok = false;\n        for (int l = 0; l < n; l++)\
    \ {\n            std::map<int, long long> cnt;\n            long long mx = 0;\n\
    \            for (int r = l + 1; r <= n; r++) {\n                mx = std::max(mx,\
    \ ++cnt[a[r - 1]]);\n                auto [v, c] = rm.mode(l, r);\n          \
    \      if (c != mx || cnt[v] != mx) ok = false;\n            }\n        }\n  \
    \  }\n    // \u6587\u5B57\u5217\u3067\u3082\u4F7F\u3048\u308B\n    std::vector<std::string>\
    \ s = {\"b\", \"a\", \"b\", \"c\", \"a\", \"b\"};\n    RangeMode rs(s);\n    if\
    \ (rs.mode(0, 6) != std::make_pair(std::string(\"b\"), 3LL) || rs.mode(1, 5).second\
    \ != 2) ok = false;\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// range-mode.hpp \u306E RangeMode \u3092\u3001\u533A\u9593\u306E\u5024\u3092\
    \u6570\u3048\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u8FD4\
    \u3057\u305F\u5024\u306E\u51FA\u73FE\u56DE\u6570\u304C\u6700\u5927\u3067\u3001\
    \u305D\u306E\u56DE\u6570\u3068\u4E00\u81F4\u3059\u308B\u304B\u3092\u78BA\u304B\
    \u3081\u308B (\u6700\u983B\u5024\u304C\u8907\u6570\u3042\u308C\u3070\u3069\u308C\
    \u3067\u3082\u3088\u3044)\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/data_structures/range-mode.hpp\"\
    \n\n#include <iostream>\n#include <map>\n#include <random>\n#include <string>\n\
    #include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok\
    \ = true;\n    for (int rep = 0; rep < 300 && ok; rep++) {\n        int n = rng()\
    \ % 60 + 1, kinds = rng() % 8 + 1;\n        std::vector<int> a(n);\n        for\
    \ (auto& x : a) x = static_cast<int>(rng() % kinds) * 1000 - 3000;\n        RangeMode\
    \ rm(a);\n        if (rm.size() != n) ok = false;\n        for (int l = 0; l <\
    \ n; l++) {\n            std::map<int, long long> cnt;\n            long long\
    \ mx = 0;\n            for (int r = l + 1; r <= n; r++) {\n                mx\
    \ = std::max(mx, ++cnt[a[r - 1]]);\n                auto [v, c] = rm.mode(l, r);\n\
    \                if (c != mx || cnt[v] != mx) ok = false;\n            }\n   \
    \     }\n    }\n    // \u6587\u5B57\u5217\u3067\u3082\u4F7F\u3048\u308B\n    std::vector<std::string>\
    \ s = {\"b\", \"a\", \"b\", \"c\", \"a\", \"b\"};\n    RangeMode rs(s);\n    if\
    \ (rs.mode(0, 6) != std::make_pair(std::string(\"b\"), 3LL) || rs.mode(1, 5).second\
    \ != 2) ok = false;\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/range-mode.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/range-mode.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 19:38:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/range-mode.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/range-mode.test.cpp
- /verify/test/unittest/data_structures/range-mode.test.cpp.html
title: test/unittest/data_structures/range-mode.test.cpp
---
