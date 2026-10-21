---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/functional-graph.1.test.cpp
    title: test/unittest/graph/functional-graph.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/functional-graph.2.test.cpp
    title: test/unittest/graph/functional-graph.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30D5\u30A1\u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5"
    links: []
  bundledCode: "#line 2 \"src/graph/functional-graph.hpp\"\n\n/**\n * @file functional-graph.hpp\n\
    \ * @brief \u30D5\u30A1\u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5\n\
    \ */\n#include <algorithm>\n#include <cassert>\n#include <iostream>\n#include\
    \ <type_traits>\n#include <vector>\n\n/**\n * @brief N\u9802\u70B9N\u8FBA\u306E\
    \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3001\u3059\u3079\u3066\u306E\u9802\u70B9\
    \u306E\u51FA\u6B21\u6570\u304C1\n */\nstruct FunctionalGraph {\n    long long\
    \ n;                                   //!< \u9802\u70B9\u6570\n    std::vector<long\
    \ long> g;                      //!< \u30B0\u30E9\u30D5\n    std::vector<bool>\
    \ is_cycle;                    //!< \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\
    \u70B9\u304B\n    std::vector<long long> depth;                  //!< \u30B5\u30A4\
    \u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n    std::vector<long\
    \ long> root;                   //!< \u6700\u3082\u8FD1\u3044\u30B5\u30A4\u30AF\
    \u30EB\u4E0A\u306E\u9802\u70B9\n    std::vector<std::vector<long long>> groups;\
    \    //!< \u5404\u9023\u7D50\u6210\u5206\u306E\u30EA\u30B9\u30C8\n    std::vector<std::vector<long\
    \ long>> cycles;    //!< \u5404\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30AF\
    \u30EB\n    std::vector<long long> group_id;               //!< \u305D\u306E\u9802\
    \u70B9\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306Eindex\n    std::vector<long\
    \ long> root_index;             //!< root\u306Ecycles\u4E0A\u306Eindex\n    std::vector<std::vector<long\
    \ long>> doubling;  //!< DoublingClimbTree\n\n    void build() {\n        assert(static_cast<long\
    \ long>(g.size()) == n);\n        for (long long i = 0; i < n; i++) assert(0 <=\
    \ g[i] && g[i] < n);\n        is_cycle.assign(n, false);\n        depth.assign(n,\
    \ 0);\n        root.assign(n, -1);\n        group_id.assign(n, 0);\n        root_index.assign(n,\
    \ 0);\n        groups.clear();\n        cycles.clear();\n        std::vector<bool>\
    \ visited(n);\n        for (long long i = 0; i < n; i++) {\n            if (visited[i])\
    \ continue;\n            std::vector<long long> v;\n            long long u =\
    \ i;\n            while (!visited[u]) {\n                visited[u] = true;\n\
    \                v.push_back(u);\n                u = g[u];\n            }\n \
    \           if (root[u] == -1) {\n                long long k = std::find(v.begin(),\
    \ v.end(), u) - v.begin();\n                cycles.push_back({});\n          \
    \      groups.push_back({});\n                for (long long j = 0; j < k; j++)\
    \ {\n                    is_cycle[v[j]] = false;\n                    root[v[j]]\
    \ = u;\n                    root_index[v[j]] = 0;\n                    group_id[v[j]]\
    \ = cycles.size() - 1;\n                    depth[v[j]] = k - j;\n           \
    \         groups.back().push_back(v[j]);\n                }\n                for\
    \ (long long j = k; j < static_cast<long long>(v.size()); j++) {\n           \
    \         is_cycle[v[j]] = true;\n                    root[v[j]] = v[j];\n   \
    \                 cycles.back().push_back(v[j]);\n                    root_index[v[j]]\
    \ = cycles.back().size() - 1;\n                    group_id[v[j]] = cycles.size()\
    \ - 1;\n                    depth[v[j]] = 0;\n                    groups.back().push_back(v[j]);\n\
    \                }\n            } else {\n                for (long long j = 0;\
    \ j < static_cast<long long>(v.size()); j++) {\n                    is_cycle[v[j]]\
    \ = false;\n                    root[v[j]] = root[u];\n                    root_index[v[j]]\
    \ = root_index[u];\n                    group_id[v[j]] = group_id[u];\n      \
    \              depth[v[j]] = depth[u] + static_cast<long long>(v.size()) - j;\n\
    \                    groups[group_id[u]].push_back(v[j]);\n                }\n\
    \            }\n        }\n        doubling.assign(n, {});\n        std::vector<long\
    \ long> tmp;\n        for (long long i = 0; i < n; i++) {\n            if (is_cycle[i])\
    \ continue;\n            tmp.push_back(i);\n            doubling[i].push_back(g[i]);\n\
    \        }\n        for (int k = 0; !tmp.empty(); k++) {\n            std::vector<long\
    \ long> next_tmp;\n            for (long long i : tmp) {\n                if (k\
    \ < static_cast<int>(doubling[doubling[i][k]].size())) {\n                   \
    \ doubling[i].push_back(doubling[doubling[i][k]][k]);\n                    next_tmp.push_back(i);\n\
    \                }\n            }\n            tmp.swap(next_tmp);\n        }\n\
    \    }\n\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     */\n    FunctionalGraph() : n(0), g(0) {}\n   \
    \ /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u9802\u70B9\u6570\n     */\n    explicit FunctionalGraph(long long n) : n(n),\
    \ g(n) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\
    \     * @tparam T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long long\
    \ \u3084 int)\n     * @param g i -> g[i]\n     */\n    template <typename T =\
    \ long long>\n    explicit FunctionalGraph(const std::vector<T>& g) : n(g.size()),\
    \ g(g.begin(), g.end()) {\n        static_assert(std::is_integral_v<T>, \"FunctionalGraph:\
    \ g must be a vector of integers\");\n        build();\n    }\n    /**\n     *\
    \ @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return n; }\n\
    \    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\
    \u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param\
    \ padding \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B \u7701\u7565\u3057\u305F\u3089-1\n     */\n    void read(long\
    \ long padding = -1) {\n        for (long long i = 0; i < n; i++) {\n        \
    \    std::cin >> g[i];\n            g[i] += padding;\n        }\n        build();\n\
    \    }\n    /**\n     * @brief \u9802\u70B9x\u304B\u3089k\u56DE\u79FB\u52D5\u3057\
    \u305F\u9802\u70B9\n     *\n     * @param x 0 <= x < n\n     * @param k 0 <= k\n\
    \     * @return long long \u9802\u70B9\u756A\u53F7\n     */\n    long long hop(long\
    \ long x, long long k) const {\n        assert(0 <= x && x < n && k >= 0);\n \
    \       if (k >= depth[x]) {\n            k -= depth[x];\n            x = root[x];\n\
    \            k %= cycles[group_id[x]].size();\n            long long y = root_index[x]\
    \ + k;\n            if (static_cast<long long>(cycles[group_id[x]].size()) <=\
    \ y) {\n                y -= cycles[group_id[x]].size();\n            }\n    \
    \        return cycles[group_id[x]][y];\n        }\n        for (int i = 0; k;\
    \ i++) {\n            if (k & 1) {\n                x = doubling[x][i];\n    \
    \        }\n            k >>= 1;\n        }\n        return x;\n    }\n    /**\n\
    \     * @brief \u9802\u70B9x\u304B\u30890\u56DE\u4EE5\u4E0A\u306E\u79FB\u52D5\u3067\
    \u305F\u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u500B\u6570\n     */\n\
    \    long long hopable(long long x) const {\n        assert(0 <= x && x < n);\n\
    \        return depth[x] + static_cast<long long>(cycles[group_id[x]].size());\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file functional-graph.hpp\n * @brief \u30D5\u30A1\
    \u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5\n */\n#include <algorithm>\n\
    #include <cassert>\n#include <iostream>\n#include <type_traits>\n#include <vector>\n\
    \n/**\n * @brief N\u9802\u70B9N\u8FBA\u306E\u6709\u5411\u30B0\u30E9\u30D5\u3067\
    \u3001\u3059\u3079\u3066\u306E\u9802\u70B9\u306E\u51FA\u6B21\u6570\u304C1\n */\n\
    struct FunctionalGraph {\n    long long n;                                   //!<\
    \ \u9802\u70B9\u6570\n    std::vector<long long> g;                      //!<\
    \ \u30B0\u30E9\u30D5\n    std::vector<bool> is_cycle;                    //!<\
    \ \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u304B\n    std::vector<long\
    \ long> depth;                  //!< \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\
    \u70B9\u307E\u3067\u306E\u8DDD\u96E2\n    std::vector<long long> root;       \
    \            //!< \u6700\u3082\u8FD1\u3044\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\
    \u9802\u70B9\n    std::vector<std::vector<long long>> groups;    //!< \u5404\u9023\
    \u7D50\u6210\u5206\u306E\u30EA\u30B9\u30C8\n    std::vector<std::vector<long long>>\
    \ cycles;    //!< \u5404\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30AF\u30EB\
    \n    std::vector<long long> group_id;               //!< \u305D\u306E\u9802\u70B9\
    \u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306Eindex\n    std::vector<long\
    \ long> root_index;             //!< root\u306Ecycles\u4E0A\u306Eindex\n    std::vector<std::vector<long\
    \ long>> doubling;  //!< DoublingClimbTree\n\n    void build() {\n        assert(static_cast<long\
    \ long>(g.size()) == n);\n        for (long long i = 0; i < n; i++) assert(0 <=\
    \ g[i] && g[i] < n);\n        is_cycle.assign(n, false);\n        depth.assign(n,\
    \ 0);\n        root.assign(n, -1);\n        group_id.assign(n, 0);\n        root_index.assign(n,\
    \ 0);\n        groups.clear();\n        cycles.clear();\n        std::vector<bool>\
    \ visited(n);\n        for (long long i = 0; i < n; i++) {\n            if (visited[i])\
    \ continue;\n            std::vector<long long> v;\n            long long u =\
    \ i;\n            while (!visited[u]) {\n                visited[u] = true;\n\
    \                v.push_back(u);\n                u = g[u];\n            }\n \
    \           if (root[u] == -1) {\n                long long k = std::find(v.begin(),\
    \ v.end(), u) - v.begin();\n                cycles.push_back({});\n          \
    \      groups.push_back({});\n                for (long long j = 0; j < k; j++)\
    \ {\n                    is_cycle[v[j]] = false;\n                    root[v[j]]\
    \ = u;\n                    root_index[v[j]] = 0;\n                    group_id[v[j]]\
    \ = cycles.size() - 1;\n                    depth[v[j]] = k - j;\n           \
    \         groups.back().push_back(v[j]);\n                }\n                for\
    \ (long long j = k; j < static_cast<long long>(v.size()); j++) {\n           \
    \         is_cycle[v[j]] = true;\n                    root[v[j]] = v[j];\n   \
    \                 cycles.back().push_back(v[j]);\n                    root_index[v[j]]\
    \ = cycles.back().size() - 1;\n                    group_id[v[j]] = cycles.size()\
    \ - 1;\n                    depth[v[j]] = 0;\n                    groups.back().push_back(v[j]);\n\
    \                }\n            } else {\n                for (long long j = 0;\
    \ j < static_cast<long long>(v.size()); j++) {\n                    is_cycle[v[j]]\
    \ = false;\n                    root[v[j]] = root[u];\n                    root_index[v[j]]\
    \ = root_index[u];\n                    group_id[v[j]] = group_id[u];\n      \
    \              depth[v[j]] = depth[u] + static_cast<long long>(v.size()) - j;\n\
    \                    groups[group_id[u]].push_back(v[j]);\n                }\n\
    \            }\n        }\n        doubling.assign(n, {});\n        std::vector<long\
    \ long> tmp;\n        for (long long i = 0; i < n; i++) {\n            if (is_cycle[i])\
    \ continue;\n            tmp.push_back(i);\n            doubling[i].push_back(g[i]);\n\
    \        }\n        for (int k = 0; !tmp.empty(); k++) {\n            std::vector<long\
    \ long> next_tmp;\n            for (long long i : tmp) {\n                if (k\
    \ < static_cast<int>(doubling[doubling[i][k]].size())) {\n                   \
    \ doubling[i].push_back(doubling[doubling[i][k]][k]);\n                    next_tmp.push_back(i);\n\
    \                }\n            }\n            tmp.swap(next_tmp);\n        }\n\
    \    }\n\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     */\n    FunctionalGraph() : n(0), g(0) {}\n   \
    \ /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param\
    \ n \u9802\u70B9\u6570\n     */\n    explicit FunctionalGraph(long long n) : n(n),\
    \ g(n) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n\
    \     * @tparam T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long long\
    \ \u3084 int)\n     * @param g i -> g[i]\n     */\n    template <typename T =\
    \ long long>\n    explicit FunctionalGraph(const std::vector<T>& g) : n(g.size()),\
    \ g(g.begin(), g.end()) {\n        static_assert(std::is_integral_v<T>, \"FunctionalGraph:\
    \ g must be a vector of integers\");\n        build();\n    }\n    /**\n     *\
    \ @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return n; }\n\
    \    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\
    \u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param\
    \ padding \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B \u7701\u7565\u3057\u305F\u3089-1\n     */\n    void read(long\
    \ long padding = -1) {\n        for (long long i = 0; i < n; i++) {\n        \
    \    std::cin >> g[i];\n            g[i] += padding;\n        }\n        build();\n\
    \    }\n    /**\n     * @brief \u9802\u70B9x\u304B\u3089k\u56DE\u79FB\u52D5\u3057\
    \u305F\u9802\u70B9\n     *\n     * @param x 0 <= x < n\n     * @param k 0 <= k\n\
    \     * @return long long \u9802\u70B9\u756A\u53F7\n     */\n    long long hop(long\
    \ long x, long long k) const {\n        assert(0 <= x && x < n && k >= 0);\n \
    \       if (k >= depth[x]) {\n            k -= depth[x];\n            x = root[x];\n\
    \            k %= cycles[group_id[x]].size();\n            long long y = root_index[x]\
    \ + k;\n            if (static_cast<long long>(cycles[group_id[x]].size()) <=\
    \ y) {\n                y -= cycles[group_id[x]].size();\n            }\n    \
    \        return cycles[group_id[x]][y];\n        }\n        for (int i = 0; k;\
    \ i++) {\n            if (k & 1) {\n                x = doubling[x][i];\n    \
    \        }\n            k >>= 1;\n        }\n        return x;\n    }\n    /**\n\
    \     * @brief \u9802\u70B9x\u304B\u30890\u56DE\u4EE5\u4E0A\u306E\u79FB\u52D5\u3067\
    \u305F\u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u500B\u6570\n     */\n\
    \    long long hopable(long long x) const {\n        assert(0 <= x && x < n);\n\
    \        return depth[x] + static_cast<long long>(cycles[group_id[x]].size());\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/functional-graph.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/functional-graph.2.test.cpp
  - test/unittest/graph/functional-graph.1.test.cpp
documentation_of: src/graph/functional-graph.hpp
layout: document
title: "\u30D5\u30A1\u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5"
---

$n$ 頂点 $n$ 辺で、すべての頂点の出次数が 1 の有向グラフ (頂点 $i$ から $g_i$ への辺) です。各連結成分はサイクル 1 つと、そこに流れ込む木からなります。

```cpp
FunctionalGraph fg(std::vector<int>{1, 2, 0, 0, 3});  // 0→1→2→0 のサイクルに 4→3→0 が流れ込む
long long v = fg.hop(4, 10); // 4 から 10 回移動した頂点: 2
long long c = fg.hopable(4); // 4 から到達できる頂点の個数: 5
bool b = fg.is_cycle[3];     // false
```

`FunctionalGraph(n)` で作った場合は、`read()` で入力するまで前計算が行われません。

頂点番号・個数・距離は `long long` で、メンバ変数も `long long` で持ちます。`FunctionalGraph(g)` の `g` は `std::vector<long long>` でも `std::vector<int>` でもかまいません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `FunctionalGraph(g)` | 頂点 `i` から `g[i]` への辺を持つグラフを作る | $O(n \log n)$ |
| `FunctionalGraph(n)` + `read(padding = -1)` | 標準入力から `g[0], ..., g[n-1]` を読む。頂点番号に `padding` を足す | $O(n \log n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `hop(x, k)` | `x` から `k` 回移動した頂点 | $O(\log n)$ |
| `hopable(x)` | `x` から 0 回以上の移動で到達できる頂点の個数 | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `n` / `g` | 頂点数 (`size()` と同じ) / 各頂点の行き先 |
| `is_cycle[v]` | `v` がサイクル上にあるか |
| `depth[v]` | `v` からサイクルに入るまでの距離 (サイクル上なら 0) |
| `root[v]` | `v` から進んで最初に着くサイクル上の頂点 |
| `group_id[v]` | `v` が属する連結成分の番号 |
| `groups[c]` | 連結成分 `c` の頂点のリスト |
| `cycles[c]` | 連結成分 `c` のサイクルの頂点を、辺をたどる順に並べたリスト |
| `root_index[v]` | `root[v]` の `cycles` 上の位置 |
| `doubling[v][j]` | サイクル上にない頂点 `v` から $2^j$ 回移動した頂点。サイクルに着くまでの分だけ持つ (`hop` が内部で使う) |

## 関連

- 根付き木の祖先への移動は [木](tree.hpp) の `DoublingClimbTree`
- 一般の有向グラフは [グラフ](graph.hpp)
