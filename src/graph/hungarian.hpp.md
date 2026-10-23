---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/hungarian.test.cpp
    title: test/unittest/graph/hungarian.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/assignment.test.cpp
    title: test/yosupo/graph/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5272\u5F53\u554F\u984C (\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\
      \u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/graph/hungarian.hpp\"\n\n/**\n * @file hungarian.hpp\n\
    \ * @brief \u5272\u5F53\u554F\u984C (\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5\
    )\n */\n\n#include <cassert>\n#include <limits>\n#include <vector>\n\n/**\n *\
    \ @brief hungarian \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct\
    \ Assignment {\n    T cost;                        //!< \u30B3\u30B9\u30C8\u306E\
    \u7DCF\u548C\n    std::vector<long long> match;  //!< match[i]: \u884C i \u306B\
    \u5272\u308A\u5F53\u3066\u305F\u5217\n};\n\n/**\n * @brief n \xD7 m (n <= m) \u306E\
    \u30B3\u30B9\u30C8\u884C\u5217 a \u3067\u3001\u5404\u884C\u306B\u7570\u306A\u308B\
    \u5217\u3092 1 \u3064\u305A\u3064\u5272\u308A\u5F53\u3066\u308B\u3068\u304D\u306E\
    \u30B3\u30B9\u30C8\u306E\u7DCF\u548C\u306E\u6700\u5C0F\u5024 O(n^2 m)\n *\n *\
    \ \u6700\u5927\u5316\u3057\u305F\u3044\u3068\u304D\u306F\u3001\u7B26\u53F7\u3092\
    \u53CD\u8EE2\u3057\u305F\u30B3\u30B9\u30C8\u3067\u547C\u3076\n * @param a \u30B3\
    \u30B9\u30C8\u884C\u5217 (\u8CA0\u3067\u3082\u3088\u3044)\u3002\u884C\u306E\u9577\
    \u3055\u306F\u305D\u308D\u3063\u3066\u3044\u308B\u3053\u3068\n */\ntemplate <typename\
    \ T>\nAssignment<T> hungarian(const std::vector<std::vector<T>>& a) {\n    const\
    \ long long n = a.size();\n    if (n == 0) return {T{}, {}};\n    const long long\
    \ m = a[0].size();\n    assert(n <= m);\n    for (const auto& row : a) assert(static_cast<long\
    \ long>(row.size()) == m);\n    const T inf = std::numeric_limits<T>::max() /\
    \ 4;\n    // 1 \u59CB\u307E\u308A\u3067\u6271\u3044\u3001\u5217 0 \u3092\u300C\
    \u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\u3044\u884C\u300D\u306E\
    \u7F6E\u304D\u5834\u306B\u3059\u308B\n    // u\u30FBv \u306F\u884C\u3068\u5217\
    \u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3001p[j] \u306F\u5217 j \u306B\u5272\
    \u308A\u5F53\u3066\u305F\u884C\u3001way[j] \u306F\u5897\u52A0\u8DEF\u3067\u5217\
    \ j \u306E 1 \u3064\u524D\u306E\u5217\n    std::vector<T> u(n + 1), v(m + 1);\n\
    \    std::vector<long long> p(m + 1), way(m + 1);\n    for (long long i = 1; i\
    \ <= n; i++) {\n        p[0] = i;\n        long long j0 = 0;\n        std::vector<T>\
    \ minv(m + 1, inf);\n        std::vector<bool> used(m + 1, false);\n        //\
    \ \u884C i \u304B\u3089\u3001\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\
    \u3044\u5217\u306B\u7740\u304F\u307E\u3067\u3001\u88AB\u7D04\u30B3\u30B9\u30C8\
    \u304C\u6700\u5C0F\u306E\u5217\u3092 1 \u3064\u305A\u3064\u8DB3\u3057\u3066\u3044\
    \u304F\n        do {\n            used[j0] = true;\n            const long long\
    \ i0 = p[j0];\n            T delta = inf;\n            long long j1 = 0;\n   \
    \         for (long long j = 1; j <= m; j++) {\n                if (used[j]) continue;\n\
    \                T cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n                if\
    \ (cur < minv[j]) minv[j] = cur, way[j] = j0;\n                if (minv[j] < delta)\
    \ delta = minv[j], j1 = j;\n            }\n            for (long long j = 0; j\
    \ <= m; j++) {\n                if (used[j]) {\n                    u[p[j]] +=\
    \ delta;\n                    v[j] -= delta;\n                } else {\n     \
    \               minv[j] -= delta;\n                }\n            }\n        \
    \    j0 = j1;\n        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u306B\
    \u6CBF\u3063\u3066\u5272\u308A\u5F53\u3066\u3092\u5165\u308C\u66FF\u3048\u308B\
    \n        do {\n            long long j1 = way[j0];\n            p[j0] = p[j1];\n\
    \            j0 = j1;\n        } while (j0 != 0);\n    }\n    Assignment<T> res{T{},\
    \ std::vector<long long>(n, -1)};\n    for (long long j = 1; j <= m; j++) {\n\
    \        if (p[j] != 0) res.match[p[j] - 1] = j - 1;\n    }\n    for (long long\
    \ i = 0; i < n; i++) res.cost += a[i][res.match[i]];\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file hungarian.hpp\n * @brief \u5272\u5F53\u554F\
    \u984C (\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5)\n */\n\n#include <cassert>\n\
    #include <limits>\n#include <vector>\n\n/**\n * @brief hungarian \u306E\u623B\u308A\
    \u5024\n */\ntemplate <typename T>\nstruct Assignment {\n    T cost;         \
    \               //!< \u30B3\u30B9\u30C8\u306E\u7DCF\u548C\n    std::vector<long\
    \ long> match;  //!< match[i]: \u884C i \u306B\u5272\u308A\u5F53\u3066\u305F\u5217\
    \n};\n\n/**\n * @brief n \xD7 m (n <= m) \u306E\u30B3\u30B9\u30C8\u884C\u5217\
    \ a \u3067\u3001\u5404\u884C\u306B\u7570\u306A\u308B\u5217\u3092 1 \u3064\u305A\
    \u3064\u5272\u308A\u5F53\u3066\u308B\u3068\u304D\u306E\u30B3\u30B9\u30C8\u306E\
    \u7DCF\u548C\u306E\u6700\u5C0F\u5024 O(n^2 m)\n *\n * \u6700\u5927\u5316\u3057\
    \u305F\u3044\u3068\u304D\u306F\u3001\u7B26\u53F7\u3092\u53CD\u8EE2\u3057\u305F\
    \u30B3\u30B9\u30C8\u3067\u547C\u3076\n * @param a \u30B3\u30B9\u30C8\u884C\u5217\
    \ (\u8CA0\u3067\u3082\u3088\u3044)\u3002\u884C\u306E\u9577\u3055\u306F\u305D\u308D\
    \u3063\u3066\u3044\u308B\u3053\u3068\n */\ntemplate <typename T>\nAssignment<T>\
    \ hungarian(const std::vector<std::vector<T>>& a) {\n    const long long n = a.size();\n\
    \    if (n == 0) return {T{}, {}};\n    const long long m = a[0].size();\n   \
    \ assert(n <= m);\n    for (const auto& row : a) assert(static_cast<long long>(row.size())\
    \ == m);\n    const T inf = std::numeric_limits<T>::max() / 4;\n    // 1 \u59CB\
    \u307E\u308A\u3067\u6271\u3044\u3001\u5217 0 \u3092\u300C\u307E\u3060\u5272\u308A\
    \u5F53\u3066\u3066\u3044\u306A\u3044\u884C\u300D\u306E\u7F6E\u304D\u5834\u306B\
    \u3059\u308B\n    // u\u30FBv \u306F\u884C\u3068\u5217\u306E\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3001p[j] \u306F\u5217 j \u306B\u5272\u308A\u5F53\u3066\u305F\
    \u884C\u3001way[j] \u306F\u5897\u52A0\u8DEF\u3067\u5217 j \u306E 1 \u3064\u524D\
    \u306E\u5217\n    std::vector<T> u(n + 1), v(m + 1);\n    std::vector<long long>\
    \ p(m + 1), way(m + 1);\n    for (long long i = 1; i <= n; i++) {\n        p[0]\
    \ = i;\n        long long j0 = 0;\n        std::vector<T> minv(m + 1, inf);\n\
    \        std::vector<bool> used(m + 1, false);\n        // \u884C i \u304B\u3089\
    \u3001\u307E\u3060\u5272\u308A\u5F53\u3066\u3066\u3044\u306A\u3044\u5217\u306B\
    \u7740\u304F\u307E\u3067\u3001\u88AB\u7D04\u30B3\u30B9\u30C8\u304C\u6700\u5C0F\
    \u306E\u5217\u3092 1 \u3064\u305A\u3064\u8DB3\u3057\u3066\u3044\u304F\n      \
    \  do {\n            used[j0] = true;\n            const long long i0 = p[j0];\n\
    \            T delta = inf;\n            long long j1 = 0;\n            for (long\
    \ long j = 1; j <= m; j++) {\n                if (used[j]) continue;\n       \
    \         T cur = a[i0 - 1][j - 1] - u[i0] - v[j];\n                if (cur <\
    \ minv[j]) minv[j] = cur, way[j] = j0;\n                if (minv[j] < delta) delta\
    \ = minv[j], j1 = j;\n            }\n            for (long long j = 0; j <= m;\
    \ j++) {\n                if (used[j]) {\n                    u[p[j]] += delta;\n\
    \                    v[j] -= delta;\n                } else {\n              \
    \      minv[j] -= delta;\n                }\n            }\n            j0 = j1;\n\
    \        } while (p[j0] != 0);\n        // \u5897\u52A0\u8DEF\u306B\u6CBF\u3063\
    \u3066\u5272\u308A\u5F53\u3066\u3092\u5165\u308C\u66FF\u3048\u308B\n        do\
    \ {\n            long long j1 = way[j0];\n            p[j0] = p[j1];\n       \
    \     j0 = j1;\n        } while (j0 != 0);\n    }\n    Assignment<T> res{T{},\
    \ std::vector<long long>(n, -1)};\n    for (long long j = 1; j <= m; j++) {\n\
    \        if (p[j] != 0) res.match[p[j] - 1] = j - 1;\n    }\n    for (long long\
    \ i = 0; i < n; i++) res.cost += a[i][res.match[i]];\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/hungarian.hpp
  requiredBy: []
  timestamp: '2026-10-23 13:33:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/hungarian.test.cpp
  - test/yosupo/graph/assignment.test.cpp
documentation_of: src/graph/hungarian.hpp
layout: document
title: "\u5272\u5F53\u554F\u984C (\u30CF\u30F3\u30AC\u30EA\u30A2\u30F3\u6CD5)"
---

$n \times m$ ($n \le m$) のコスト行列 `a` で、各行に異なる列を 1 つずつ割り当てるときの、コストの総和の最小値と割り当て方を求めます。重み付きの二部グラフの最小重み完全マッチングと同じです。ポテンシャルを使うハンガリアン法で $O(n^2 m)$ です。

```cpp
std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
auto res = hungarian(a);
long long cost = res.cost; // コストの総和の最小値
long long j = res.match[i]; // 行 i に割り当てた列
```

コストは負でもかまいません。最大化したいときは、符号を反転したコストで呼びます。

途中でコストの総和程度の値を扱い、`std::numeric_limits<T>::max() / 4` を無限大として使います。`int` では足りなくなりやすいので、`T` は `long long` にしてください。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `hungarian(a)` | 割当問題を解き、`Assignment<T>` を返す。`a` の行の長さはそろっていて、行の数が列の数以下であること | $O(n^2 m)$ |

`Assignment<T>` は次の 2 つを持ちます。

| 変数 | 説明 |
|---|---|
| `cost` | コストの総和 |
| `match[i]` | 行 `i` に割り当てた列 |

## 関連

- 重みのない二部グラフの最大マッチングは [二部マッチング](bipartite-matching.hpp)
- 1 つの列に複数の行を割り当てるなど、容量のあるものは [最小費用流](min-cost-flow.hpp)
