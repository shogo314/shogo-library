---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/monoid-unionfind.hpp
    title: "\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u3092\u4E57\u305B\u308BUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-unionfind.hpp
    title: "\u6C38\u7D9AUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/potentialized-unionfind.hpp
    title: "\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\u304DUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_util.hpp
    title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/graph/two-sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-11-d.1.test.cpp
    title: test/aoj/alds1/alds1-11-d.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-11-d.2.test.cpp
    title: test/aoj/alds1/alds1-11-d.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-1-b.1.test.cpp
    title: test/aoj/dsl/dsl-1-b.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-1-b.2.test.cpp
    title: test/aoj/dsl/dsl-1-b.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl-2-a.test.cpp
    title: test/aoj/grl/grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl-4-a.test.cpp
    title: test/aoj/grl/grl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume29/2971.test.cpp
    title: test/aoj/volume29/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/algebra/mapping.test.cpp
    title: test/unittest/algebra/mapping.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/algebra/monoid.test.cpp
    title: test/unittest/algebra/monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/find-cycle.test.cpp
    title: test/unittest/data_structures/find-cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/graph-util.test.cpp
    title: test/unittest/data_structures/graph-util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/monoid-unionfind.test.cpp
    title: test/unittest/data_structures/monoid-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/persistent-unionfind.test.cpp
    title: test/unittest/data_structures/persistent-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/potentialized-unionfind.test.cpp
    title: test/unittest/data_structures/potentialized-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/unionfind.test.cpp
    title: test/unittest/data_structures/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/lowlink.test.cpp
    title: test/unittest/graph/lowlink.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/two-sat.test.cpp
    title: test/unittest/graph/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/persistent-unionfind.test.cpp
    title: test/yosupo/data_structure/persistent-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/unionfind-with-potential-non-commutative-group.test.cpp
    title: test/yosupo/data_structure/unionfind-with-potential-non-commutative-group.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/unionfind.test.cpp
    title: test/yosupo/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/chromatic-number.test.cpp
    title: test/yosupo/graph/chromatic-number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/cycle-detection-undirected.test.cpp
    title: test/yosupo/graph/cycle-detection-undirected.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/cycle-detection.test.cpp
    title: test/yosupo/graph/cycle-detection.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/minimum-spanning-tree.1.test.cpp
    title: test/yosupo/graph/minimum-spanning-tree.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/minimum-spanning-tree.2.test.cpp
    title: test/yosupo/graph/minimum-spanning-tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/scc.test.cpp
    title: test/yosupo/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/other/two-sat.test.cpp
    title: test/yosupo/other/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/674.1.test.cpp
    title: test/yukicoder/674.1.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: UnionFind
    links: []
  bundledCode: "#line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n\
    \ * @brief UnionFind\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace internal_unionfind {\n/**\n * @brief\
    \ \u5404\u8981\u7D20\u306E\u4EE3\u8868\u5143\u304B\u3089\u3001\u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u8981\u7D20\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\
    \n * @param leader \u8981\u7D20 a \u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\
    \u6570\n */\ntemplate <typename F>\nstd::vector<std::vector<long long>> groups(long\
    \ long n, F leader) {\n    std::vector<long long> leader_buf(n), group_size(n);\n\
    \    for (long long i = 0; i < n; i++) {\n        leader_buf[i] = leader(i);\n\
    \        group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<long\
    \ long>> result(n);\n    for (long long i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n\
    \    }\n    for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(std::remove_if(result.begin(), result.end(), [&](const\
    \ std::vector<long long>& v) { return v.empty(); }), result.end());\n    return\
    \ result;\n}\n}  // namespace internal_unionfind\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\u300D\
    \u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\u3092\
    \u3059\u308B\n */\nclass UnionFind {\n   protected:\n    long long _n;\n    //\
    \ \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<int> parent_or_size;\n\n   public:\n    /**\n     * @brief merge\
    \ \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b)) \u3067\u65B0\u3057\
    \u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\u304D\u3001\n   \
    \  * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct MergeResult {\n        long long leader;\
    \  //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool merged;     \
    \  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\u3082\u3068\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit operator\
    \ bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0) {}\n    explicit\
    \ UnionFind(long long n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     *\
    \ @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\u306E\
    \u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = static_cast<int>(x);\n        return {x, true};\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\
    \u304B\n     */\n    bool same(long long a, long long b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) ==\
    \ leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int x = static_cast<int>(a);\n        while (parent_or_size[x]\
    \ >= 0) {\n            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    long long size(long long a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n\
    #include <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nnamespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\
    \u8868\u5143\u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20\
    \ a \u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename\
    \ F>\nstd::vector<std::vector<long long>> groups(long long n, F leader) {\n  \
    \  std::vector<long long> leader_buf(n), group_size(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        leader_buf[i] = leader(i);\n        group_size[leader_buf[i]]++;\n\
    \    }\n    std::vector<std::vector<long long>> result(n);\n    for (long long\
    \ i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n    }\n   \
    \ for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(std::remove_if(result.begin(), result.end(), [&](const\
    \ std::vector<long long>& v) { return v.empty(); }), result.end());\n    return\
    \ result;\n}\n}  // namespace internal_unionfind\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\u300D\
    \u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\u3092\
    \u3059\u308B\n */\nclass UnionFind {\n   protected:\n    long long _n;\n    //\
    \ \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<int> parent_or_size;\n\n   public:\n    /**\n     * @brief merge\
    \ \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b)) \u3067\u65B0\u3057\
    \u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\u304D\u3001\n   \
    \  * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct MergeResult {\n        long long leader;\
    \  //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool merged;     \
    \  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\u3082\u3068\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit operator\
    \ bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0) {}\n    explicit\
    \ UnionFind(long long n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     *\
    \ @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\u306E\
    \u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = static_cast<int>(x);\n        return {x, true};\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\
    \u304B\n     */\n    bool same(long long a, long long b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) ==\
    \ leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int x = static_cast<int>(a);\n        while (parent_or_size[x]\
    \ >= 0) {\n            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    long long size(long long a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/unionfind.hpp
  requiredBy:
  - src/graph/graph_util.hpp
  - src/graph/two-sat.hpp
  - src/data_structures/persistent-unionfind.hpp
  - src/data_structures/potentialized-unionfind.hpp
  - src/data_structures/monoid-unionfind.hpp
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/two-sat.test.cpp
  - test/unittest/graph/lowlink.test.cpp
  - test/unittest/data_structures/unionfind.test.cpp
  - test/unittest/data_structures/persistent-unionfind.test.cpp
  - test/unittest/data_structures/find-cycle.test.cpp
  - test/unittest/data_structures/monoid-unionfind.test.cpp
  - test/unittest/data_structures/potentialized-unionfind.test.cpp
  - test/unittest/data_structures/graph-util.test.cpp
  - test/unittest/algebra/mapping.test.cpp
  - test/unittest/algebra/monoid.test.cpp
  - test/aoj/grl/grl-4-a.test.cpp
  - test/aoj/grl/grl-2-a.test.cpp
  - test/aoj/alds1/alds1-11-d.2.test.cpp
  - test/aoj/alds1/alds1-11-d.1.test.cpp
  - test/aoj/dsl/dsl-1-b.2.test.cpp
  - test/aoj/dsl/dsl-1-b.1.test.cpp
  - test/aoj/volume29/2971.test.cpp
  - test/yosupo/graph/cycle-detection-undirected.test.cpp
  - test/yosupo/graph/minimum-spanning-tree.2.test.cpp
  - test/yosupo/graph/minimum-spanning-tree.1.test.cpp
  - test/yosupo/graph/chromatic-number.test.cpp
  - test/yosupo/graph/scc.test.cpp
  - test/yosupo/graph/cycle-detection.test.cpp
  - test/yosupo/data_structure/unionfind.test.cpp
  - test/yosupo/data_structure/persistent-unionfind.test.cpp
  - test/yosupo/data_structure/unionfind-with-potential-non-commutative-group.test.cpp
  - test/yosupo/other/two-sat.test.cpp
  - test/yukicoder/674.1.test.cpp
documentation_of: src/data_structures/unionfind.hpp
layout: document
title: UnionFind
---

無向グラフに辺を追加しながら、2頂点が連結かどうかを判定します。経路圧縮と union by size を行います。

```cpp
UnionFind uf(n);
uf.merge(0, 1);
uf.merge(1, 2);
bool b = uf.same(0, 2);   // true
long long s = uf.size(0); // 3
auto g = uf.groups();     // 連結成分ごとの頂点のリスト

// Kruskal 法: 新しく統合できた辺だけ使う
if (uf.merge(u, v)) cost += w;
auto [r, merged] = uf.merge(u, v);  // 代表元も受け取る
```

## メンバ関数

計算量の $\alpha(n)$ はアッカーマン関数の逆関数で、実質定数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `UnionFind(n)` | 頂点数 `n`、辺なしで初期化 | $O(n)$ |
| `merge(a, b)` | 辺 $(a, b)$ を追加し、`MergeResult` を返す (下記) | $O(\alpha(n))$ |
| `same(a, b)` | `a` と `b` が連結か | $O(\alpha(n))$ |
| `leader(a)` | `a` の属する連結成分の代表元 | $O(\alpha(n))$ |
| `size(a)` | `a` の属する連結成分の頂点数 | $O(\alpha(n))$ |
| `groups()` | 連結成分ごとの頂点のリスト | $O(n)$ |

## `MergeResult`

`merge` の戻り値です。`std::set::insert` と同じく、統合の途中で分かる 2 つの情報をどちらも返します。

| 変数 | 説明 |
|---|---|
| `leader` | 統合後の代表元 |
| `merged` | 新しく統合したか (もともと同じ連結成分なら `false`) |

`explicit operator bool` が `merged` を返すので、`if (uf.merge(a, b))` と書けます。

## 関連

- 連結成分ごとに値 (和・最小値など) を持つなら [可換モノイドを乗せるUnionFind](monoid-unionfind.hpp)
- 頂点間のポテンシャルの差を管理するなら [ポテンシャル付きUnionFind](potentialized-unionfind.hpp)
- 過去の版も使うなら [永続UnionFind](persistent-unionfind.hpp)
