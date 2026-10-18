---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-6-a.test.cpp
    title: test/aoj/grl-6-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/bipartite-matching.test.cpp
    title: test/unittest/bipartite-matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/max-flow.test.cpp
    title: test/unittest/max-flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5927\u6D41 (Dinic \u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/graph/max-flow.hpp\"\n\n/**\n * @file max-flow.hpp\n\
    \ * @brief \u6700\u5927\u6D41 (Dinic \u6CD5)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief \u6700\u5927\u6D41 (Dinic \u6CD5)\n *\n * O(n^2 m)\
    \ \u3060\u304C\u3001\u5B9F\u969B\u306B\u306F\u305A\u3063\u3068\u901F\u3044\u3053\
    \u3068\u304C\u591A\u3044\u3002\u5BB9\u91CF\u304C\u3059\u3079\u3066 1 \u306A\u3089\
    \ O(m min(m^(1/2), n^(2/3)))\n * \u4F8B:\n * MaxFlow<long long> mf(n);\n * mf.add_edge(0,\
    \ 1, 5);\n * long long f = mf.flow(s, t);\n *\n * @tparam Cap \u5BB9\u91CF\u306E\
    \u578B\n */\ntemplate <typename Cap>\nclass MaxFlow {\n   public:\n    /**\n \
    \    * @brief \u8FBA\u306E\u60C5\u5831\n     */\n    struct Edge {\n        long\
    \ long from, to;\n        Cap cap;   //!< \u5BB9\u91CF\n        Cap flow;  //!<\
    \ \u6D41\u308C\u3066\u3044\u308B\u91CF\n    };\n\n   private:\n    // \u5185\u90E8\
    \u306E\u8FBA\u3068\u914D\u5217\u306F int \u3067\u6301\u3061\u3001\u516C\u958B\u3059\
    \u308B\u95A2\u6570\u3067 long long \u306B\u3059\u308B\n    struct InnerEdge {\n\
    \        int to, rev;\n        Cap cap;  // \u6B8B\u308A\u306E\u5BB9\u91CF\n \
    \   };\n    long long n;\n    std::vector<std::vector<InnerEdge>> g;\n    std::vector<std::pair<int,\
    \ int>> pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\u304C g \u306E\u3069\u3053\u306B\
    \u3042\u308B\u304B\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int\
    \ t) {\n        level.assign(n, -1);\n        level[s] = 0;\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (const auto& e : g[v])\
    \ {\n                if (e.cap > 0 && level[e.to] == -1) {\n                 \
    \   level[e.to] = level[v] + 1;\n                    que.push(e.to);\n       \
    \         }\n            }\n        }\n        return level[t] != -1;\n    }\n\
    \    // v \u304B\u3089 t \u3078\u3001up \u3092\u4E0A\u9650\u3068\u3057\u3066\u30EC\
    \u30D9\u30EB\u30B0\u30E9\u30D5\u4E0A\u3067\u6D41\u3059\n    Cap dfs(int v, int\
    \ t, Cap up) {\n        if (v == t) return up;\n        Cap res = 0;\n       \
    \ for (int& i = iter[v]; i < static_cast<int>(g[v].size()); i++) {\n         \
    \   InnerEdge& e = g[v][i];\n            if (e.cap <= 0 || level[e.to] != level[v]\
    \ + 1) continue;\n            Cap d = dfs(e.to, t, std::min(up - res, e.cap));\n\
    \            if (d <= 0) continue;\n            e.cap -= d;\n            g[e.to][e.rev].cap\
    \ += d;\n            res += d;\n            if (res == up) return res;\n     \
    \   }\n        // \u3053\u308C\u4EE5\u4E0A\u6D41\u305B\u306A\u3044\u306E\u3067\
    \u3001\u3053\u306E\u30D5\u30A7\u30FC\u30BA\u3067\u306F\u4F7F\u308F\u306A\u3044\
    \n        level[v] = n;\n        return res;\n    }\n\n   public:\n    explicit\
    \ MaxFlow(long long n = 0) : n(n), g(n) {}\n\n    long long size() const { return\
    \ n; }\n\n    /**\n     * @brief from \u304B\u3089 to \u3078\u306E\u5BB9\u91CF\
    \ cap \u306E\u8FBA\u3092\u8FFD\u52A0\u3057\u3001\u8FBA\u306E\u756A\u53F7 (\u8FFD\
    \u52A0\u3057\u305F\u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059\n     */\n    long\
    \ long add_edge(long long from, long long to, Cap cap) {\n        assert(0 <=\
    \ from && from < n && 0 <= to && to < n && cap >= 0);\n        long long id =\
    \ pos.size();\n        int from_id = g[from].size();\n        int to_id = g[to].size()\
    \ + (from == to);\n        pos.emplace_back(from, from_id);\n        g[from].push_back({static_cast<int>(to),\
    \ to_id, cap});\n        g[to].push_back({static_cast<int>(from), from_id, 0});\n\
    \        return id;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\u3001\
    limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u3067\u304D\u308B\u3060\u3051\u6D41\
    \u3057\u3001\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n     * \u4F55\u5EA6\u3082\
    \u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\
    \u52A0\u3057\u3066\u6D41\u3059\n     */\n    Cap flow(long long s, long long t,\
    \ Cap limit = std::numeric_limits<Cap>::max()) {\n        assert(0 <= s && s <\
    \ n && 0 <= t && t < n && s != t);\n        Cap res = 0;\n        while (res <\
    \ limit && bfs(s, t)) {\n            iter.assign(n, 0);\n            Cap f = dfs(s,\
    \ t, limit - res);\n            if (f == 0) break;\n            res += f;\n  \
    \      }\n        return res;\n    }\n\n    /**\n     * @brief \u756A\u53F7 i\
    \ \u306E\u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long long i) const\
    \ {\n        assert(0 <= i && i < static_cast<long long>(pos.size()));\n     \
    \   const auto& e = g[pos[i].first][pos[i].second];\n        const auto& re =\
    \ g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n\
    \    }\n    /**\n     * @brief \u756A\u53F7 i \u306E\u8FBA\u306E\u5BB9\u91CF\u3092\
    \ new_cap \u306B\u3001\u6D41\u308C\u3066\u3044\u308B\u91CF\u3092 new_flow \u306B\
    \u5909\u3048\u308B\n     * \u307B\u304B\u306E\u8FBA\u306E\u6D41\u91CF\u306F\u5909\
    \u3048\u306A\u3044\u306E\u3067\u3001\u6D41\u91CF\u306E\u4FDD\u5B58\u5247\u304C\
    \u5D29\u308C\u308B\u3053\u3068\u304C\u3042\u308B\n     */\n    void change_edge(long\
    \ long i, Cap new_cap, Cap new_flow) {\n        assert(0 <= i && i < static_cast<long\
    \ long>(pos.size()) && 0 <= new_flow && new_flow <= new_cap);\n        auto& e\
    \ = g[pos[i].first][pos[i].second];\n        auto& re = g[e.to][e.rev];\n    \
    \    e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8FBA\u306E\u60C5\u5831 (\u8FFD\u52A0\u3057\
    \u305F\u9806)\n     */\n    std::vector<Edge> edges() const {\n        std::vector<Edge>\
    \ res;\n        for (long long i = 0; i < static_cast<long long>(pos.size());\
    \ i++) res.push_back(get_edge(i));\n        return res;\n    }\n\n    /**\n  \
    \   * @brief \u76F4\u524D\u306E flow(s, t) \u306E\u5F8C\u3067\u3001\u6B8B\u4F59\
    \u30B0\u30E9\u30D5\u3067 s \u304B\u3089\u884C\u3051\u308B\u9802\u70B9\u304B\n\
    \     * flow(s, t) \u3067\u6D41\u3057\u304D\u3063\u3066\u3044\u308C\u3070\u3001\
    true \u306E\u9802\u70B9\u306E\u96C6\u5408\u304C\u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \ s \u5074\u306B\u306A\u308B\n     */\n    std::vector<bool> min_cut(long long\
    \ s) const {\n        std::vector<bool> visited(n);\n        std::vector<long\
    \ long> st = {s};\n        visited[s] = true;\n        while (!st.empty()) {\n\
    \            long long v = st.back();\n            st.pop_back();\n          \
    \  for (const auto& e : g[v]) {\n                if (e.cap > 0 && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    st.push_back(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @file max-flow.hpp\n * @brief \u6700\u5927\u6D41\
    \ (Dinic \u6CD5)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u6700\
    \u5927\u6D41 (Dinic \u6CD5)\n *\n * O(n^2 m) \u3060\u304C\u3001\u5B9F\u969B\u306B\
    \u306F\u305A\u3063\u3068\u901F\u3044\u3053\u3068\u304C\u591A\u3044\u3002\u5BB9\
    \u91CF\u304C\u3059\u3079\u3066 1 \u306A\u3089 O(m min(m^(1/2), n^(2/3)))\n * \u4F8B\
    :\n * MaxFlow<long long> mf(n);\n * mf.add_edge(0, 1, 5);\n * long long f = mf.flow(s,\
    \ t);\n *\n * @tparam Cap \u5BB9\u91CF\u306E\u578B\n */\ntemplate <typename Cap>\n\
    class MaxFlow {\n   public:\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\n\
    \     */\n    struct Edge {\n        long long from, to;\n        Cap cap;   //!<\
    \ \u5BB9\u91CF\n        Cap flow;  //!< \u6D41\u308C\u3066\u3044\u308B\u91CF\n\
    \    };\n\n   private:\n    // \u5185\u90E8\u306E\u8FBA\u3068\u914D\u5217\u306F\
    \ int \u3067\u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long\
    \ long \u306B\u3059\u308B\n    struct InnerEdge {\n        int to, rev;\n    \
    \    Cap cap;  // \u6B8B\u308A\u306E\u5BB9\u91CF\n    };\n    long long n;\n \
    \   std::vector<std::vector<InnerEdge>> g;\n    std::vector<std::pair<int, int>>\
    \ pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\u304C g \u306E\u3069\u3053\u306B\u3042\
    \u308B\u304B\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t)\
    \ {\n        level.assign(n, -1);\n        level[s] = 0;\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (const auto& e : g[v])\
    \ {\n                if (e.cap > 0 && level[e.to] == -1) {\n                 \
    \   level[e.to] = level[v] + 1;\n                    que.push(e.to);\n       \
    \         }\n            }\n        }\n        return level[t] != -1;\n    }\n\
    \    // v \u304B\u3089 t \u3078\u3001up \u3092\u4E0A\u9650\u3068\u3057\u3066\u30EC\
    \u30D9\u30EB\u30B0\u30E9\u30D5\u4E0A\u3067\u6D41\u3059\n    Cap dfs(int v, int\
    \ t, Cap up) {\n        if (v == t) return up;\n        Cap res = 0;\n       \
    \ for (int& i = iter[v]; i < static_cast<int>(g[v].size()); i++) {\n         \
    \   InnerEdge& e = g[v][i];\n            if (e.cap <= 0 || level[e.to] != level[v]\
    \ + 1) continue;\n            Cap d = dfs(e.to, t, std::min(up - res, e.cap));\n\
    \            if (d <= 0) continue;\n            e.cap -= d;\n            g[e.to][e.rev].cap\
    \ += d;\n            res += d;\n            if (res == up) return res;\n     \
    \   }\n        // \u3053\u308C\u4EE5\u4E0A\u6D41\u305B\u306A\u3044\u306E\u3067\
    \u3001\u3053\u306E\u30D5\u30A7\u30FC\u30BA\u3067\u306F\u4F7F\u308F\u306A\u3044\
    \n        level[v] = n;\n        return res;\n    }\n\n   public:\n    explicit\
    \ MaxFlow(long long n = 0) : n(n), g(n) {}\n\n    long long size() const { return\
    \ n; }\n\n    /**\n     * @brief from \u304B\u3089 to \u3078\u306E\u5BB9\u91CF\
    \ cap \u306E\u8FBA\u3092\u8FFD\u52A0\u3057\u3001\u8FBA\u306E\u756A\u53F7 (\u8FFD\
    \u52A0\u3057\u305F\u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059\n     */\n    long\
    \ long add_edge(long long from, long long to, Cap cap) {\n        assert(0 <=\
    \ from && from < n && 0 <= to && to < n && cap >= 0);\n        long long id =\
    \ pos.size();\n        int from_id = g[from].size();\n        int to_id = g[to].size()\
    \ + (from == to);\n        pos.emplace_back(from, from_id);\n        g[from].push_back({static_cast<int>(to),\
    \ to_id, cap});\n        g[to].push_back({static_cast<int>(from), from_id, 0});\n\
    \        return id;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\u3001\
    limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u3067\u304D\u308B\u3060\u3051\u6D41\
    \u3057\u3001\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n     * \u4F55\u5EA6\u3082\
    \u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\
    \u52A0\u3057\u3066\u6D41\u3059\n     */\n    Cap flow(long long s, long long t,\
    \ Cap limit = std::numeric_limits<Cap>::max()) {\n        assert(0 <= s && s <\
    \ n && 0 <= t && t < n && s != t);\n        Cap res = 0;\n        while (res <\
    \ limit && bfs(s, t)) {\n            iter.assign(n, 0);\n            Cap f = dfs(s,\
    \ t, limit - res);\n            if (f == 0) break;\n            res += f;\n  \
    \      }\n        return res;\n    }\n\n    /**\n     * @brief \u756A\u53F7 i\
    \ \u306E\u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long long i) const\
    \ {\n        assert(0 <= i && i < static_cast<long long>(pos.size()));\n     \
    \   const auto& e = g[pos[i].first][pos[i].second];\n        const auto& re =\
    \ g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n\
    \    }\n    /**\n     * @brief \u756A\u53F7 i \u306E\u8FBA\u306E\u5BB9\u91CF\u3092\
    \ new_cap \u306B\u3001\u6D41\u308C\u3066\u3044\u308B\u91CF\u3092 new_flow \u306B\
    \u5909\u3048\u308B\n     * \u307B\u304B\u306E\u8FBA\u306E\u6D41\u91CF\u306F\u5909\
    \u3048\u306A\u3044\u306E\u3067\u3001\u6D41\u91CF\u306E\u4FDD\u5B58\u5247\u304C\
    \u5D29\u308C\u308B\u3053\u3068\u304C\u3042\u308B\n     */\n    void change_edge(long\
    \ long i, Cap new_cap, Cap new_flow) {\n        assert(0 <= i && i < static_cast<long\
    \ long>(pos.size()) && 0 <= new_flow && new_flow <= new_cap);\n        auto& e\
    \ = g[pos[i].first][pos[i].second];\n        auto& re = g[e.to][e.rev];\n    \
    \    e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8FBA\u306E\u60C5\u5831 (\u8FFD\u52A0\u3057\
    \u305F\u9806)\n     */\n    std::vector<Edge> edges() const {\n        std::vector<Edge>\
    \ res;\n        for (long long i = 0; i < static_cast<long long>(pos.size());\
    \ i++) res.push_back(get_edge(i));\n        return res;\n    }\n\n    /**\n  \
    \   * @brief \u76F4\u524D\u306E flow(s, t) \u306E\u5F8C\u3067\u3001\u6B8B\u4F59\
    \u30B0\u30E9\u30D5\u3067 s \u304B\u3089\u884C\u3051\u308B\u9802\u70B9\u304B\n\
    \     * flow(s, t) \u3067\u6D41\u3057\u304D\u3063\u3066\u3044\u308C\u3070\u3001\
    true \u306E\u9802\u70B9\u306E\u96C6\u5408\u304C\u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \ s \u5074\u306B\u306A\u308B\n     */\n    std::vector<bool> min_cut(long long\
    \ s) const {\n        std::vector<bool> visited(n);\n        std::vector<long\
    \ long> st = {s};\n        visited[s] = true;\n        while (!st.empty()) {\n\
    \            long long v = st.back();\n            st.pop_back();\n          \
    \  for (const auto& e : g[v]) {\n                if (e.cap > 0 && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    st.push_back(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/max-flow.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/bipartite-matching.test.cpp
  - test/unittest/max-flow.test.cpp
  - test/aoj/grl-6-a.test.cpp
documentation_of: src/graph/max-flow.hpp
layout: document
title: "\u6700\u5927\u6D41 (Dinic \u6CD5)"
---

有向グラフの最大流を Dinic 法で求める `MaxFlow<Cap>` です。`Cap` は容量の型です。計算量は $O(n^2 m)$ ですが、実際にはずっと速いことが多いです。容量がすべて 1 なら $O(m \min(\sqrt{m}, n^{2/3}))$ です。

```cpp
MaxFlow<long long> mf(n);
long long id = mf.add_edge(0, 1, 5);  // 0 から 1 へ容量 5 の辺。辺の番号を返す
long long f = mf.flow(s, t);        // s から t へ流せるだけ流す
auto e = mf.get_edge(id);           // e.from, e.to, e.cap, e.flow
std::vector<bool> S = mf.min_cut(s);  // 最小カットの s 側
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MaxFlow(n)` | 頂点数 `n`、辺のない状態 | $O(n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `add_edge(from, to, cap)` | `from` から `to` へ容量 `cap` の辺を追加し、辺の番号 (追加した順に 0, 1, ...) を返す | ならし $O(1)$ |
| `flow(s, t)` | `s` から `t` へできるだけ流し、流した量を返す | $O(n^2 m)$ |
| `flow(s, t, limit)` | 流す量の上限を `limit` にする | $O(n^2 m)$ |
| `get_edge(i)` | 番号 `i` の辺の `from`、`to`、`cap` (容量)、`flow` (流れている量) | $O(1)$ |
| `edges()` | すべての辺の情報 (追加した順) | $O(m)$ |
| `change_edge(i, new_cap, new_flow)` | 番号 `i` の辺の容量を `new_cap`、流れている量を `new_flow` に変える ($0 \le$ `new_flow` $\le$ `new_cap`)。ほかの辺の流量は変えないので、流量の保存則が崩れることがある | $O(1)$ |
| `min_cut(s)` | 残余グラフで `s` から行ける頂点か。`flow(s, t)` で流しきった後なら、`true` の頂点の集合が最小カットの `s` 側になる | $O(n + m)$ |

頂点番号と辺の番号 (`add_edge` の戻り値、`Edge` の `from`・`to`) は `long long` です。

`flow` を何度も呼ぶと、前回までの流れに追加して流します。辺を追加してから、もう一度 `flow` を呼ぶこともできます。

流す処理の DFS は再帰を使います。再帰の深さは、`s` から `t` への (容量が残っている辺だけを使った) 最短路の辺の本数までです。

## 関連

- 二部グラフの最大マッチングだけなら、より速い [二部マッチング](bipartite-matching.hpp)
- 辺にコストがあるときは [最小費用流](min-cost-flow.hpp)
