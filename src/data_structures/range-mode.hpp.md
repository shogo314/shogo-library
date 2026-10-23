---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/range-mode.test.cpp
    title: test/unittest/data_structures/range-mode.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/static-range-mode-query.test.cpp
    title: test/yosupo/data_structure/static-range-mode-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u533A\u9593\u306E\u6700\u983B\u5024"
    links: []
  bundledCode: "#line 2 \"src/data_structures/range-mode.hpp\"\n\n/**\n * @file range-mode.hpp\n\
    \ * @brief \u533A\u9593\u306E\u6700\u983B\u5024\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <utility>\n#include <vector>\n\n\
    /**\n * @brief \u56FA\u5B9A\u3057\u305F\u5217\u306B\u3064\u3044\u3066\u3001\u533A\
    \u9593\u306E\u6700\u983B\u5024\u3068\u305D\u306E\u51FA\u73FE\u56DE\u6570\u3092\
    \u30AA\u30F3\u30E9\u30A4\u30F3\u3067\u7B54\u3048\u308B\n *\n * \u9577\u3055 B\
    \ \u306E\u30D6\u30ED\u30C3\u30AF\u306B\u5206\u3051\u3001\u30D6\u30ED\u30C3\u30AF\
    \u306E\u533A\u9593\u3054\u3068\u306E\u6700\u983B\u5024\u3092\u524D\u8A08\u7B97\
    \u3059\u308B\u3002\u30AF\u30A8\u30EA\u3067\u306F\u3001\u9593\u306E\u30D6\u30ED\
    \u30C3\u30AF\u306E\u6700\u983B\u5024\u304B\u3089\u59CB\u3081\u3066\u3001\n * \u7AEF\
    \u306E\u8981\u7D20\u3054\u3068\u306B\u300C\u305D\u306E\u5024\u306E\u51FA\u73FE\
    \u4F4D\u7F6E\u306E\u5217\u300D\u3067\u51FA\u73FE\u56DE\u6570\u304C 1 \u3064\u5897\
    \u3084\u305B\u308B\u304B\u3092\u8ABF\u3079\u308B (\u5897\u3084\u3059\u56DE\u6570\
    \u306E\u5408\u8A08\u306F\u7AEF\u306E\u9577\u3055\u4EE5\u4E0B)\n * \u69CB\u7BC9\
    \ O(n sqrt(n))\u3001\u30AF\u30A8\u30EA O(sqrt(n))\u3001\u30E1\u30E2\u30EA O(n)\n\
    \ * \u4F8B:\n * RangeMode rm(a);\n * auto [value, count] = rm.mode(l, r);\n *\n\
    \ * @tparam T \u5024\u306E\u578B (operator< \u3067\u6BD4\u3079\u3089\u308C\u308B\
    \u3053\u3068)\n */\ntemplate <typename T>\nclass RangeMode {\n    long long n,\
    \ B;\n    std::vector<T> vals;                      // \u5024\u306E\u7A2E\u985E\
    \ (\u6607\u9806)\n    std::vector<long long> id;                // id[i]: a[i]\
    \ \u306E vals \u3067\u306E\u756A\u53F7\n    std::vector<long long> rank;     \
    \         // rank[i]: a[i] \u3068\u540C\u3058\u5024\u306E\u3046\u3061 i \u3088\
    \u308A\u524D\u306B\u3042\u308B\u3082\u306E\u306E\u500B\u6570\n    std::vector<std::vector<long\
    \ long>> pos;  // pos[v]: \u5024 v \u306E\u51FA\u73FE\u4F4D\u7F6E (\u6607\u9806\
    )\n    // best[i][j]: \u30D6\u30ED\u30C3\u30AF i \u304B\u3089 j \u307E\u3067 (\u4E21\
    \u7AEF\u3092\u542B\u3080) \u306E\u6700\u983B\u5024\u306E\u756A\u53F7\u3068\u51FA\
    \u73FE\u56DE\u6570\n    std::vector<std::vector<std::pair<long long, long long>>>\
    \ best;\n\n   public:\n    /**\n     * @brief \u5217 a \u304B\u3089\u4F5C\u308B\
    \n     */\n    explicit RangeMode(const std::vector<T>& a) : n(a.size()), vals(a),\
    \ id(n), rank(n) {\n        std::sort(vals.begin(), vals.end());\n        vals.erase(std::unique(vals.begin(),\
    \ vals.end()), vals.end());\n        pos.resize(vals.size());\n        for (long\
    \ long i = 0; i < n; i++) {\n            id[i] = std::lower_bound(vals.begin(),\
    \ vals.end(), a[i]) - vals.begin();\n            rank[i] = pos[id[i]].size();\n\
    \            pos[id[i]].push_back(i);\n        }\n        B = std::max(1LL, static_cast<long\
    \ long>(std::sqrt(static_cast<double>(n))));\n        const long long k = (n +\
    \ B - 1) / B;\n        best.assign(k, std::vector<std::pair<long long, long long>>(k));\n\
    \        std::vector<long long> cnt(vals.size());\n        for (long long i =\
    \ 0; i < k; i++) {\n            std::fill(cnt.begin(), cnt.end(), 0);\n      \
    \      std::pair<long long, long long> cur = {-1, 0};\n            for (long long\
    \ j = i * B; j < n; j++) {\n                if (++cnt[id[j]] > cur.second) cur\
    \ = {id[j], cnt[id[j]]};\n                if (j % B == B - 1 || j == n - 1) best[i][j\
    \ / B] = cur;\n            }\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\
    \u6570\n     */\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ a[l], ..., a[r-1] \u306E\u6700\u983B\u5024\u306E 1 \u3064\u3068\u3001\u305D\u306E\
    \u51FA\u73FE\u56DE\u6570 {\u5024, \u56DE\u6570}\n     * @pre l < r\n     */\n\
    \    std::pair<T, long long> mode(long long l, long long r) const {\n        assert(0\
    \ <= l && l < r && r <= n);\n        // \u9593\u306B\u3042\u308B\u30D6\u30ED\u30C3\
    \u30AF [bl, br]\u3002\u306A\u3051\u308C\u3070\u7A7A\u306B\u3057\u3066\u3001\u3059\
    \u3079\u3066\u7AEF\u3068\u3057\u3066\u6271\u3046\n        const long long bl =\
    \ (l + B - 1) / B, br = r / B - 1;\n        long long v = -1, f = 0, mid_l = r,\
    \ mid_r = r;\n        if (bl <= br) v = best[bl][br].first, f = best[bl][br].second,\
    \ mid_l = bl * B, mid_r = (br + 1) * B;\n        // \u5DE6\u7AEF: i \u304B\u3089\
    \u53F3\u306B f + 1 \u500B\u76EE\u306E\u51FA\u73FE\u304C r \u3088\u308A\u524D\u306B\
    \u3042\u308C\u3070\u5897\u3084\u3059\n        for (long long i = l; i < mid_l;\
    \ i++) {\n            const auto& p = pos[id[i]];\n            while (rank[i]\
    \ + f < static_cast<long long>(p.size()) && p[rank[i] + f] < r) v = id[i], f++;\n\
    \        }\n        // \u53F3\u7AEF: i \u304B\u3089\u5DE6\u306B f + 1 \u500B\u76EE\
    \u306E\u51FA\u73FE\u304C l \u4EE5\u4E0A\u306A\u3089\u5897\u3084\u3059\n      \
    \  for (long long i = mid_r; i < r; i++) {\n            const auto& p = pos[id[i]];\n\
    \            while (rank[i] - f >= 0 && p[rank[i] - f] >= l) v = id[i], f++;\n\
    \        }\n        return {vals[v], f};\n    }\n};\n\ntemplate <typename T>\n\
    RangeMode(std::vector<T>) -> RangeMode<T>;\n"
  code: "#pragma once\n\n/**\n * @file range-mode.hpp\n * @brief \u533A\u9593\u306E\
    \u6700\u983B\u5024\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <cmath>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u56FA\u5B9A\
    \u3057\u305F\u5217\u306B\u3064\u3044\u3066\u3001\u533A\u9593\u306E\u6700\u983B\
    \u5024\u3068\u305D\u306E\u51FA\u73FE\u56DE\u6570\u3092\u30AA\u30F3\u30E9\u30A4\
    \u30F3\u3067\u7B54\u3048\u308B\n *\n * \u9577\u3055 B \u306E\u30D6\u30ED\u30C3\
    \u30AF\u306B\u5206\u3051\u3001\u30D6\u30ED\u30C3\u30AF\u306E\u533A\u9593\u3054\
    \u3068\u306E\u6700\u983B\u5024\u3092\u524D\u8A08\u7B97\u3059\u308B\u3002\u30AF\
    \u30A8\u30EA\u3067\u306F\u3001\u9593\u306E\u30D6\u30ED\u30C3\u30AF\u306E\u6700\
    \u983B\u5024\u304B\u3089\u59CB\u3081\u3066\u3001\n * \u7AEF\u306E\u8981\u7D20\u3054\
    \u3068\u306B\u300C\u305D\u306E\u5024\u306E\u51FA\u73FE\u4F4D\u7F6E\u306E\u5217\
    \u300D\u3067\u51FA\u73FE\u56DE\u6570\u304C 1 \u3064\u5897\u3084\u305B\u308B\u304B\
    \u3092\u8ABF\u3079\u308B (\u5897\u3084\u3059\u56DE\u6570\u306E\u5408\u8A08\u306F\
    \u7AEF\u306E\u9577\u3055\u4EE5\u4E0B)\n * \u69CB\u7BC9 O(n sqrt(n))\u3001\u30AF\
    \u30A8\u30EA O(sqrt(n))\u3001\u30E1\u30E2\u30EA O(n)\n * \u4F8B:\n * RangeMode\
    \ rm(a);\n * auto [value, count] = rm.mode(l, r);\n *\n * @tparam T \u5024\u306E\
    \u578B (operator< \u3067\u6BD4\u3079\u3089\u308C\u308B\u3053\u3068)\n */\ntemplate\
    \ <typename T>\nclass RangeMode {\n    long long n, B;\n    std::vector<T> vals;\
    \                      // \u5024\u306E\u7A2E\u985E (\u6607\u9806)\n    std::vector<long\
    \ long> id;                // id[i]: a[i] \u306E vals \u3067\u306E\u756A\u53F7\
    \n    std::vector<long long> rank;              // rank[i]: a[i] \u3068\u540C\u3058\
    \u5024\u306E\u3046\u3061 i \u3088\u308A\u524D\u306B\u3042\u308B\u3082\u306E\u306E\
    \u500B\u6570\n    std::vector<std::vector<long long>> pos;  // pos[v]: \u5024\
    \ v \u306E\u51FA\u73FE\u4F4D\u7F6E (\u6607\u9806)\n    // best[i][j]: \u30D6\u30ED\
    \u30C3\u30AF i \u304B\u3089 j \u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u306E\
    \u6700\u983B\u5024\u306E\u756A\u53F7\u3068\u51FA\u73FE\u56DE\u6570\n    std::vector<std::vector<std::pair<long\
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
    };\n\ntemplate <typename T>\nRangeMode(std::vector<T>) -> RangeMode<T>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/range-mode.hpp
  requiredBy: []
  timestamp: '2026-10-23 19:38:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/range-mode.test.cpp
  - test/yosupo/data_structure/static-range-mode-query.test.cpp
documentation_of: src/data_structures/range-mode.hpp
layout: document
title: "\u533A\u9593\u306E\u6700\u983B\u5024"
---

固定した列について、区間 $[l, r)$ の最頻値とその出現回数を、構築 $O(n \sqrt{n})$、クエリ $O(\sqrt{n})$、メモリ $O(n)$ でオンラインに答えます。

```cpp
std::vector<int> a = {3, 1, 3, 2, 1, 3};
RangeMode rm(a);
auto [v, c] = rm.mode(0, 6);  // {3, 3}
auto [w, d] = rm.mode(1, 5);  // 1 か 3 のどちらか、出現回数 2
```

最頻値が複数あるときは、そのどれかを返します。値の型は `<` で比べられれば何でもかまいません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RangeMode(a)` | 列 `a` から作る | $O(n \sqrt{n})$ |
| `size()` | 要素数 | $O(1)$ |
| `mode(l, r)` | `a[l], ..., a[r-1]` の最頻値の 1 つとその出現回数 `{値, 回数}` ($l < r$) | $O(\sqrt{n})$ |

長さ $\sqrt{n}$ 程度のブロックに分け、ブロックの区間ごとの最頻値を前計算します。クエリでは、間のブロックの最頻値から始めて、端の要素ごとに「その値の出現位置の列」を見て出現回数を 1 つ増やせるかを調べます。増やす回数の合計は端の長さ以下なので、クエリは $O(\sqrt{n})$ です。

## 関連

- 区間内の異なる値の個数は [区間内の異なる値の個数](range-count-distinct.hpp)
- 区間内の値の出現回数や k 番目に小さい値は [Wavelet Matrix](wavelet-matrix.hpp)
