---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/bin-packing.test.cpp
    title: test/unittest/dp/bin-packing.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u74F6\u8A70\u3081\u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\
      \u30F3\u30B0) \u306E\u6700\u5C0F\u306E\u74F6\u306E\u6570 (\u54C1\u7269\u304C\
      \ 20 \u500B\u7A0B\u5EA6\u307E\u3067)"
    links: []
  bundledCode: "#line 2 \"src/dp/bin-packing.hpp\"\n\n/**\n * @file bin-packing.hpp\n\
    \ * @brief \u74F6\u8A70\u3081\u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\u30F3\
    \u30B0) \u306E\u6700\u5C0F\u306E\u74F6\u306E\u6570 (\u54C1\u7269\u304C 20 \u500B\
    \u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <utility>\n#include <vector>\n\n/**\n\
    \ * @brief \u5BB9\u91CF C \u306E\u74F6\u306B\u91CD\u3055 w_i \u306E\u54C1\u7269\
    \u3092\u3059\u3079\u3066\u8A70\u3081\u308B\u306E\u306B\u5FC5\u8981\u306A\u74F6\
    \u306E\u6700\u5C0F\u500B\u6570 (\u5165\u3089\u306A\u3044\u54C1\u7269\u304C\u3042\
    \u308C\u3070 -1) O(2^n n)\n * \u54C1\u7269\u3092 1 \u3064\u305A\u3064\u5165\u308C\
    \u308B\u9806\u756A\u3092\u3059\u3079\u3066\u8A66\u3057\u3001\u300C\u6700\u5F8C\
    \u306E\u74F6\u306B\u5165\u308B\u306A\u3089\u5165\u308C\u3001\u5165\u3089\u306A\
    \u3051\u308C\u3070\u65B0\u3057\u3044\u74F6\u3092\u958B\u3051\u308B\u300D\u3068\
    \u3059\u308B\n * \u6700\u9069\u306A\u8A70\u3081\u65B9\u3082\u74F6\u3054\u3068\u306B\
    \u9806\u306B\u5165\u308C\u308C\u3070\u518D\u73FE\u3067\u304D\u308B\u306E\u3067\
    \u3001\u54C1\u7269\u306E\u96C6\u5408\u3054\u3068\u306B (\u74F6\u306E\u6570, \u6700\
    \u5F8C\u306E\u74F6\u306E\u91CD\u3055) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\u3092\
    \u6301\u3066\u3070\u3088\u3044\n */\ninline long long bin_packing(const std::vector<long\
    \ long>& w, long long C) {\n    const int n = w.size();\n    for (long long x\
    \ : w)\n        if (x > C) return -1;\n    // dp[S] = \u96C6\u5408 S \u3092\u8A70\
    \u3081\u305F\u3068\u304D\u306E (\u74F6\u306E\u6570, \u6700\u5F8C\u306E\u74F6\u306B\
    \u5165\u3063\u3066\u3044\u308B\u91CD\u3055) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\
    \u3002\u6700\u521D\u306F\u6700\u5F8C\u306E\u74F6\u304C\u6E80\u676F\u3068\u307F\
    \u306A\u3059\n    std::vector<std::pair<int, long long>> dp(1 << n, {n + 1, 0});\n\
    \    dp[0] = {0, C};\n    for (int S = 0; S < (1 << n); S++) {\n        auto [bins,\
    \ fill] = dp[S];\n        if (bins > n) continue;\n        for (int i = 0; i <\
    \ n; i++) {\n            if (S >> i & 1) continue;\n            std::pair<int,\
    \ long long> next = fill + w[i] <= C ? std::make_pair(bins, fill + w[i]) : std::make_pair(bins\
    \ + 1, w[i]);\n            if (next < dp[S | 1 << i]) dp[S | 1 << i] = next;\n\
    \        }\n    }\n    return dp[(1 << n) - 1].first;\n}\n"
  code: "#pragma once\n\n/**\n * @file bin-packing.hpp\n * @brief \u74F6\u8A70\u3081\
    \u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\u30F3\u30B0) \u306E\u6700\u5C0F\u306E\
    \u74F6\u306E\u6570 (\u54C1\u7269\u304C 20 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\
    \n#include <utility>\n#include <vector>\n\n/**\n * @brief \u5BB9\u91CF C \u306E\
    \u74F6\u306B\u91CD\u3055 w_i \u306E\u54C1\u7269\u3092\u3059\u3079\u3066\u8A70\u3081\
    \u308B\u306E\u306B\u5FC5\u8981\u306A\u74F6\u306E\u6700\u5C0F\u500B\u6570 (\u5165\
    \u3089\u306A\u3044\u54C1\u7269\u304C\u3042\u308C\u3070 -1) O(2^n n)\n * \u54C1\
    \u7269\u3092 1 \u3064\u305A\u3064\u5165\u308C\u308B\u9806\u756A\u3092\u3059\u3079\
    \u3066\u8A66\u3057\u3001\u300C\u6700\u5F8C\u306E\u74F6\u306B\u5165\u308B\u306A\
    \u3089\u5165\u308C\u3001\u5165\u3089\u306A\u3051\u308C\u3070\u65B0\u3057\u3044\
    \u74F6\u3092\u958B\u3051\u308B\u300D\u3068\u3059\u308B\n * \u6700\u9069\u306A\u8A70\
    \u3081\u65B9\u3082\u74F6\u3054\u3068\u306B\u9806\u306B\u5165\u308C\u308C\u3070\
    \u518D\u73FE\u3067\u304D\u308B\u306E\u3067\u3001\u54C1\u7269\u306E\u96C6\u5408\
    \u3054\u3068\u306B (\u74F6\u306E\u6570, \u6700\u5F8C\u306E\u74F6\u306E\u91CD\u3055\
    ) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\u3092\u6301\u3066\u3070\u3088\u3044\n */\n\
    inline long long bin_packing(const std::vector<long long>& w, long long C) {\n\
    \    const int n = w.size();\n    for (long long x : w)\n        if (x > C) return\
    \ -1;\n    // dp[S] = \u96C6\u5408 S \u3092\u8A70\u3081\u305F\u3068\u304D\u306E\
    \ (\u74F6\u306E\u6570, \u6700\u5F8C\u306E\u74F6\u306B\u5165\u3063\u3066\u3044\u308B\
    \u91CD\u3055) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\u3002\u6700\u521D\u306F\u6700\
    \u5F8C\u306E\u74F6\u304C\u6E80\u676F\u3068\u307F\u306A\u3059\n    std::vector<std::pair<int,\
    \ long long>> dp(1 << n, {n + 1, 0});\n    dp[0] = {0, C};\n    for (int S = 0;\
    \ S < (1 << n); S++) {\n        auto [bins, fill] = dp[S];\n        if (bins >\
    \ n) continue;\n        for (int i = 0; i < n; i++) {\n            if (S >> i\
    \ & 1) continue;\n            std::pair<int, long long> next = fill + w[i] <=\
    \ C ? std::make_pair(bins, fill + w[i]) : std::make_pair(bins + 1, w[i]);\n  \
    \          if (next < dp[S | 1 << i]) dp[S | 1 << i] = next;\n        }\n    }\n\
    \    return dp[(1 << n) - 1].first;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/bin-packing.hpp
  requiredBy: []
  timestamp: '2026-10-21 05:55:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/bin-packing.test.cpp
documentation_of: src/dp/bin-packing.hpp
layout: document
title: "\u74F6\u8A70\u3081\u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\u30F3\u30B0\
  )"
---

容量 $C$ の瓶に重さ $w_i$ の品物をすべて詰めるのに必要な瓶の最小個数を、品物が $n$ 個のとき $O(2^n n)$ で求めます。$n$ は 20 程度までです。

```cpp
long long k = bin_packing({3, 4, 4, 4, 2, 9, 2}, 10);  // 3 (9 / 4+4+2 / 3+4+2)
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `bin_packing(w, C)` | 容量 `C` の瓶に `w` (`std::vector<long long>`) の品物をすべて詰めるのに必要な瓶の最小個数。`C` を超える品物があれば -1、品物がなければ 0 | $O(2^n n)$ |

品物を 1 つずつ入れる順番をすべて試し、「最後の瓶に入るなら入れ、入らなければ新しい瓶を開ける」とする DP です。最適な詰め方も、瓶ごとに順に入れる並べ方で再現できます。品物の集合ごとに (使った瓶の数, 最後の瓶に入っている重さ) の辞書順最小を持てば十分です。同じ瓶の数なら、最後の瓶が軽い方が必ず得だからです。

重さの合計という 1 つの数で状態がまとまるのは瓶詰め問題に特有の性質です。一般の「使ってよい集合」で分ける問題 (彩色数など) は、[集合の分割](set-partition.hpp) の $O(3^n)$ の DP を使います。

## 関連

- 一般の集合族で分ける最小個数は [集合の分割](set-partition.hpp)、覆う最小個数は [集合の被覆](set-cover.hpp)、彩色数は [グラフに関する関数](../graph/graph_util.hpp) の `chromatic_number`
- 1 つの瓶 (ナップサック) に入る価値の最大は [ナップサック問題](knapsack.hpp)
