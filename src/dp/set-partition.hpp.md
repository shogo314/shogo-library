---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/set-partition.test.cpp
    title: test/unittest/dp/set-partition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96C6\u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
      \u300D\u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8981\
      \u7D20\u304C 16 \u500B\u7A0B\u5EA6\u307E\u3067)"
    links: []
  bundledCode: "#line 2 \"src/dp/set-partition.hpp\"\n\n/**\n * @file set-partition.hpp\n\
    \ * @brief \u96C6\u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\
    \u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8981\u7D20\
    \u304C 16 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true\
    \ \u306E\u96C6\u5408 T \u3044\u304F\u3064\u304B\u306B\u91CD\u306A\u3089\u306A\u3044\
    \u3088\u3046\u306B\u5206\u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\
    \ (\u5206\u3051\u3089\u308C\u306A\u3051\u308C\u3070 -1) O(3^n)\n * feasible \u306E\
    \u5927\u304D\u3055\u306F 2^n\u3002dp[S] = min (dp[S \\ T] + 1) \u3092\u3001T \u3092\
    \u300CS \u306E\u6700\u5C0F\u306E\u8981\u7D20\u3092\u542B\u3080 S \u306E\u90E8\u5206\
    \u96C6\u5408\u300D\u306B\u9650\u3063\u3066\u6C42\u3081\u308B\n * \u4F7F\u3063\u3066\
    \u3088\u3044\u96C6\u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\
    \u3066\u9589\u3058\u3066\u3044\u308B\u306A\u3089\u3001\u91CD\u306A\u308A\u3092\
    \u8A31\u3057\u3066\u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\u3068\
    \u3082\u4E00\u81F4\u3059\u308B\n */\ninline long long min_set_partition(int n,\
    \ const std::vector<bool>& feasible) {\n    assert(static_cast<long long>(feasible.size())\
    \ == (1LL << n));\n    const int INF = n + 1;\n    std::vector<int> dp(1 << n,\
    \ INF);\n    dp[0] = 0;\n    for (int S = 1; S < (1 << n); S++) {\n        const\
    \ int low = S & -S, rest = S ^ low;\n        // rest \u306E\u90E8\u5206\u96C6\u5408\
    \ U \u306B\u3064\u3044\u3066 T = U | low \u3092\u8A66\u3059\n        for (int\
    \ U = rest;; U = (U - 1) & rest) {\n            const int T = U | low;\n     \
    \       if (feasible[T] && dp[S ^ T] + 1 < dp[S]) dp[S] = dp[S ^ T] + 1;\n   \
    \         if (U == 0) break;\n        }\n    }\n    return dp[(1 << n) - 1] >=\
    \ INF ? -1 : dp[(1 << n) - 1];\n}\n"
  code: "#pragma once\n\n/**\n * @file set-partition.hpp\n * @brief \u96C6\u5408\u3092\
    \u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\u306B\u5206\u3051\u308B\
    \u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8981\u7D20\u304C 16 \u500B\u7A0B\
    \u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#include <vector>\n\n/**\n * @brief\
    \ {0, ..., n-1} \u3092\u3001feasible[T] \u304C true \u306E\u96C6\u5408 T \u3044\
    \u304F\u3064\u304B\u306B\u91CD\u306A\u3089\u306A\u3044\u3088\u3046\u306B\u5206\
    \u3051\u308B\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5206\u3051\u3089\u308C\
    \u306A\u3051\u308C\u3070 -1) O(3^n)\n * feasible \u306E\u5927\u304D\u3055\u306F\
    \ 2^n\u3002dp[S] = min (dp[S \\ T] + 1) \u3092\u3001T \u3092\u300CS \u306E\u6700\
    \u5C0F\u306E\u8981\u7D20\u3092\u542B\u3080 S \u306E\u90E8\u5206\u96C6\u5408\u300D\
    \u306B\u9650\u3063\u3066\u6C42\u3081\u308B\n * \u4F7F\u3063\u3066\u3088\u3044\u96C6\
    \u5408\u65CF\u304C\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\u9589\u3058\
    \u3066\u3044\u308B\u306A\u3089\u3001\u91CD\u306A\u308A\u3092\u8A31\u3057\u3066\
    \u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570\u3068\u3082\u4E00\u81F4\
    \u3059\u308B\n */\ninline long long min_set_partition(int n, const std::vector<bool>&\
    \ feasible) {\n    assert(static_cast<long long>(feasible.size()) == (1LL << n));\n\
    \    const int INF = n + 1;\n    std::vector<int> dp(1 << n, INF);\n    dp[0]\
    \ = 0;\n    for (int S = 1; S < (1 << n); S++) {\n        const int low = S &\
    \ -S, rest = S ^ low;\n        // rest \u306E\u90E8\u5206\u96C6\u5408 U \u306B\
    \u3064\u3044\u3066 T = U | low \u3092\u8A66\u3059\n        for (int U = rest;;\
    \ U = (U - 1) & rest) {\n            const int T = U | low;\n            if (feasible[T]\
    \ && dp[S ^ T] + 1 < dp[S]) dp[S] = dp[S ^ T] + 1;\n            if (U == 0) break;\n\
    \        }\n    }\n    return dp[(1 << n) - 1] >= INF ? -1 : dp[(1 << n) - 1];\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/set-partition.hpp
  requiredBy: []
  timestamp: '2026-10-21 05:55:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/set-partition.test.cpp
documentation_of: src/dp/set-partition.hpp
layout: document
title: "\u96C6\u5408\u306E\u5206\u5272 (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
  \u306B\u5206\u3051\u308B\u6700\u5C0F\u500B\u6570)"
---

$\lbrace 0, \dots, n - 1 \rbrace$ を、「使ってよい集合」いくつかに重ならないように分けるときの最小個数を $O(3^n)$ で求めます。$n$ は 16 程度まで (3^16 ≈ 4 × 10^7) です。

```cpp
// 品物を、重さの和が C 以下の組に分ける (瓶詰め問題と同じ)
std::vector<bool> feasible(1 << n);
for (int S = 0; S < (1 << n); S++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) if (S >> i & 1) sum += w[i];
    feasible[S] = sum <= C;
}
long long k = min_set_partition(n, feasible);
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `min_set_partition(n, feasible)` | `feasible[T]` (大きさ $2^n$ の `std::vector<bool>`) が `true` の集合 $T$ に、全体を重ならないように分けるときの最小個数。分けられなければ -1、$n = 0$ なら 0 | $O(3^n)$ |

- $\mathrm{dp}_S = \min (\mathrm{dp}_{S \setminus T} + 1)$ を、$T$ を「$S$ の最小の要素を含む $S$ の部分集合」に限って求めます。どの分け方でも最小の要素を含む組はちょうど 1 つなので、こう限っても答えは変わらず、列挙は半分になります。
- 使ってよい集合族が部分集合について閉じている (使ってよい集合の部分集合も使ってよい) なら、重なりを許して覆うときの最小個数とも一致します。
- 包除原理で「覆う $k$ 個組の数」を数えれば $O(2^n n)$ にできますが、数が大きくなるので素数の mod で数える必要があり、まれに誤ります。ここでは誤りのない $O(3^n)$ の方法にしています。

## 関連

- 彩色数は [グラフに関する関数](../graph/graph_util.hpp) の `chromatic_number` (隣り合わない頂点に絞って速くしたもの)
- 瓶詰め問題は [瓶詰め問題](bin-packing.hpp) の方が速い ($O(2^n n)$)
- 部分集合の和の変換は [ビット演算の畳み込み](../math/bitwise-transform.hpp)
