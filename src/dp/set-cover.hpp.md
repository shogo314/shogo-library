---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/set-cover.test.cpp
    title: test/unittest/dp/set-cover.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/chromatic-number.2.test.cpp
    title: test/yosupo/graph/chromatic-number.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u96C6\u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
      \u300D\u3067\u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5305\u9664\
      \u539F\u7406\u3001\u8981\u7D20\u304C 20 \u500B\u7A0B\u5EA6\u307E\u3067)"
    links: []
  bundledCode: "#line 2 \"src/dp/set-cover.hpp\"\n\n/**\n * @file set-cover.hpp\n\
    \ * @brief \u96C6\u5408\u3092\u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\
    \u3067\u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5305\u9664\u539F\
    \u7406\u3001\u8981\u7D20\u304C 20 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#include\
    \ <cassert>\n#include <vector>\n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T]\
    \ \u304C true \u306E\u96C6\u5408 T \u3044\u304F\u3064\u304B\u3067 (\u91CD\u306A\
    \u308A\u3092\u8A31\u3057\u3066) \u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\
    \u6570 (\u8986\u3048\u306A\u3051\u308C\u3070 -1) O(2^n n)\n * feasible \u306E\u5927\
    \u304D\u3055\u306F 2^n\u3002f(S) \u3092 S \u306B\u542B\u307E\u308C\u308B\u4F7F\
    \u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u6570\u3068\u3059\u308B\u3068\u3001\
    \u5168\u4F53\u3092\u8986\u3046 k \u500B\u7D44\u306E\u6570\u306F \u03A3_S (-1)^{n\
    \ - |S|} f(S)^k\u3002\n * \u3053\u308C\u304C 0 \u3067\u306A\u3044\u6700\u5C0F\u306E\
    \ k \u3092\u6C42\u3081\u308B\u3002\u6570\u306F 2 \u3064\u306E\u7D20\u6570\u306E\
    \ mod \u3067\u6570\u3048\u308B\u306E\u3067\u30010 \u3067\u306A\u3044\u306E\u306B\
    \ 0 \u3068\u8AA4\u308B\u78BA\u7387\u304C\u308F\u305A\u304B\u306B\u3042\u308B\n\
    \ */\ninline long long min_set_cover(int n, const std::vector<bool>& feasible)\
    \ {\n    assert(0 <= n && n < 31);\n    assert(static_cast<long long>(feasible.size())\
    \ == (1LL << n));\n    if (n == 0) return 0;\n    const int N = 1 << n;\n    //\
    \ f[S] = S \u306B\u542B\u307E\u308C\u308B\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
    \u306E\u6570 (\u90E8\u5206\u96C6\u5408\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\
    \u30BF\u5909\u63DB)\u30022^n \u4EE5\u4E0B\u306A\u306E\u3067 mod \u3092\u53D6\u3089\
    \u305A\u306B\u6301\u3066\u308B\n    std::vector<unsigned> f(N);\n    for (int\
    \ S = 0; S < N; S++) f[S] = feasible[S];\n    for (int i = 0; i < n; i++) {\n\
    \        for (int S = 0; S < N; S++) {\n            if (S >> i & 1) f[S] += f[S\
    \ ^ (1 << i)];\n        }\n    }\n    if (f[N - 1] == 0) return -1;\n    static\
    \ constexpr unsigned long long P[2] = {998244353, 1000000007};\n    // pw[j][S]\
    \ = f[S]^k mod P[j]\n    std::vector<unsigned> pw[2] = {std::vector<unsigned>(N,\
    \ 1), std::vector<unsigned>(N, 1)};\n    // \u8986\u3048\u308B\u306A\u3089\u3001\
    \u5404\u8981\u7D20\u3092\u542B\u3080\u96C6\u5408\u3092 1 \u3064\u305A\u3064\u9078\
    \u3079\u3070 n \u500B\u4EE5\u4E0B\u3067\u8986\u3048\u308B\n    for (int k = 1;\
    \ k <= n; k++) {\n        bool nonzero = false;\n        for (int j = 0; j < 2;\
    \ j++) {\n            unsigned long long sum = 0;\n            for (int S = 0;\
    \ S < N; S++) {\n                pw[j][S] = static_cast<unsigned>(pw[j][S] * static_cast<unsigned\
    \ long long>(f[S]) % P[j]);\n                // n - |S| \u304C\u5947\u6570\u306A\
    \u3089\u5F15\u304F\n                sum += (__builtin_parity(S) ^ (n & 1)) ? P[j]\
    \ - pw[j][S] : pw[j][S];\n            }\n            nonzero |= sum % P[j] !=\
    \ 0;\n        }\n        if (nonzero) return k;\n    }\n    return -1;\n}\n"
  code: "#pragma once\n\n/**\n * @file set-cover.hpp\n * @brief \u96C6\u5408\u3092\
    \u300C\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u300D\u3067\u8986\u3046\u3068\
    \u304D\u306E\u6700\u5C0F\u500B\u6570 (\u5305\u9664\u539F\u7406\u3001\u8981\u7D20\
    \u304C 20 \u500B\u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief {0, ..., n-1} \u3092\u3001feasible[T] \u304C true\
    \ \u306E\u96C6\u5408 T \u3044\u304F\u3064\u304B\u3067 (\u91CD\u306A\u308A\u3092\
    \u8A31\u3057\u3066) \u8986\u3046\u3068\u304D\u306E\u6700\u5C0F\u500B\u6570 (\u8986\
    \u3048\u306A\u3051\u308C\u3070 -1) O(2^n n)\n * feasible \u306E\u5927\u304D\u3055\
    \u306F 2^n\u3002f(S) \u3092 S \u306B\u542B\u307E\u308C\u308B\u4F7F\u3063\u3066\
    \u3088\u3044\u96C6\u5408\u306E\u6570\u3068\u3059\u308B\u3068\u3001\u5168\u4F53\
    \u3092\u8986\u3046 k \u500B\u7D44\u306E\u6570\u306F \u03A3_S (-1)^{n - |S|} f(S)^k\u3002\
    \n * \u3053\u308C\u304C 0 \u3067\u306A\u3044\u6700\u5C0F\u306E k \u3092\u6C42\u3081\
    \u308B\u3002\u6570\u306F 2 \u3064\u306E\u7D20\u6570\u306E mod \u3067\u6570\u3048\
    \u308B\u306E\u3067\u30010 \u3067\u306A\u3044\u306E\u306B 0 \u3068\u8AA4\u308B\u78BA\
    \u7387\u304C\u308F\u305A\u304B\u306B\u3042\u308B\n */\ninline long long min_set_cover(int\
    \ n, const std::vector<bool>& feasible) {\n    assert(0 <= n && n < 31);\n   \
    \ assert(static_cast<long long>(feasible.size()) == (1LL << n));\n    if (n ==\
    \ 0) return 0;\n    const int N = 1 << n;\n    // f[S] = S \u306B\u542B\u307E\u308C\
    \u308B\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\u306E\u6570 (\u90E8\u5206\u96C6\
    \u5408\u306B\u3064\u3044\u3066\u306E\u30BC\u30FC\u30BF\u5909\u63DB)\u30022^n \u4EE5\
    \u4E0B\u306A\u306E\u3067 mod \u3092\u53D6\u3089\u305A\u306B\u6301\u3066\u308B\n\
    \    std::vector<unsigned> f(N);\n    for (int S = 0; S < N; S++) f[S] = feasible[S];\n\
    \    for (int i = 0; i < n; i++) {\n        for (int S = 0; S < N; S++) {\n  \
    \          if (S >> i & 1) f[S] += f[S ^ (1 << i)];\n        }\n    }\n    if\
    \ (f[N - 1] == 0) return -1;\n    static constexpr unsigned long long P[2] = {998244353,\
    \ 1000000007};\n    // pw[j][S] = f[S]^k mod P[j]\n    std::vector<unsigned> pw[2]\
    \ = {std::vector<unsigned>(N, 1), std::vector<unsigned>(N, 1)};\n    // \u8986\
    \u3048\u308B\u306A\u3089\u3001\u5404\u8981\u7D20\u3092\u542B\u3080\u96C6\u5408\
    \u3092 1 \u3064\u305A\u3064\u9078\u3079\u3070 n \u500B\u4EE5\u4E0B\u3067\u8986\
    \u3048\u308B\n    for (int k = 1; k <= n; k++) {\n        bool nonzero = false;\n\
    \        for (int j = 0; j < 2; j++) {\n            unsigned long long sum = 0;\n\
    \            for (int S = 0; S < N; S++) {\n                pw[j][S] = static_cast<unsigned>(pw[j][S]\
    \ * static_cast<unsigned long long>(f[S]) % P[j]);\n                // n - |S|\
    \ \u304C\u5947\u6570\u306A\u3089\u5F15\u304F\n                sum += (__builtin_parity(S)\
    \ ^ (n & 1)) ? P[j] - pw[j][S] : pw[j][S];\n            }\n            nonzero\
    \ |= sum % P[j] != 0;\n        }\n        if (nonzero) return k;\n    }\n    return\
    \ -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/set-cover.hpp
  requiredBy: []
  timestamp: '2026-10-22 01:08:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/set-cover.test.cpp
  - test/yosupo/graph/chromatic-number.2.test.cpp
documentation_of: src/dp/set-cover.hpp
layout: document
title: "\u96C6\u5408\u306E\u88AB\u8986 (\u4F7F\u3063\u3066\u3088\u3044\u96C6\u5408\
  \u3067\u8986\u3046\u6700\u5C0F\u500B\u6570\u3001\u5305\u9664\u539F\u7406)"
---

$\lbrace 0, \dots, n - 1 \rbrace$ を、「使ってよい集合」いくつかで (重なりを許して) 覆うときの最小個数を、包除原理で $O(2^n n)$ で求めます。$n$ は 20 程度まで使えます。数を素数の mod で数えるので、まれに誤ります (下を参照)。

```cpp
// 彩色数: 独立集合で頂点全体を覆う最小個数
std::vector<bool> indep(1 << n);
indep[0] = true;
for (int S = 1; S < (1 << n); S++) {
    int v = __builtin_ctz(S), rest = S & (S - 1);
    indep[S] = indep[rest] && !(adj[v] & rest);  // adj[v] は v と隣り合う頂点の集合
}
long long k = min_set_cover(n, indep);
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `min_set_cover(n, feasible)` | `feasible[T]` (大きさ $2^n$ の `std::vector<bool>`) が `true` の集合 $T$ いくつかで、全体を重なりを許して覆うときの最小個数。覆えなければ -1、$n = 0$ なら 0 | $O(2^n n)$ |

- $f(S)$ を「$S$ に含まれる使ってよい集合の数」とすると (部分集合についてのゼータ変換)、和集合が全体になる $k$ 個組 $(T_1, \dots, T_k)$ の数は、包除原理により $\sum_S (-1)^{n - \lvert S \rvert} f(S)^k$ です。これが 0 でない最小の $k$ が答えです。覆えるなら $k \le n$ なので、$k = 1, \dots, n$ と $f(S)^k$ を順に掛けて調べます。
- 組の数は大きくなるので、998244353 と 1000000007 の 2 つの素数の mod で数えます。本当は 0 でないのに両方の mod で 0 になると、答えを大きく誤ります。
- 使ってよい集合族が部分集合について閉じている (彩色数の独立集合など) なら、[集合の分割](set-partition.hpp) の `min_set_partition` と答えが一致します。誤りがあってはいけないときや、$n$ が小さいときは、そちらの $O(3^n)$ の方法も使えます。

## 関連

- 重ならないように分ける最小個数 (誤りのない $O(3^n)$) は [集合の分割](set-partition.hpp)
- 彩色数は [グラフに関する関数](../graph/graph_util.hpp) の `chromatic_number` (誤りのない方法)
- 部分集合についてのゼータ変換は [ビット演算の畳み込み](../math/bitwise-transform.hpp)
