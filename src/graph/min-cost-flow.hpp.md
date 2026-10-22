---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl/grl-6-b.test.cpp
    title: test/aoj/grl/grl-6-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/min-cost-flow.test.cpp
    title: test/unittest/graph/min-cost-flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)"
    links: []
  bundledCode: "#line 2 \"src/graph/min-cost-flow.hpp\"\n\n/**\n * @file min-cost-flow.hpp\n\
    \ * @brief \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u6700\
    \u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)\n *\n * \u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306F 0 \u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3002\u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3092\u4F7F\u3044\u3001\u6700\u77ED\u8DEF\u3092 Dijkstra \u6CD5\
    \u3067\u6C42\u3081\u308B\n * \u6700\u77ED\u8DEF 1 \u672C\u3054\u3068\u306B Dijkstra\
    \ \u6CD5\u3092 1 \u56DE\u884C\u3046\u306E\u3067 O(F (n + m) log m) (F \u306F\u6D41\
    \u91CF)\u3002\u5B9F\u969B\u306B\u306F\u30011 \u672C\u306E\u8DEF\u3067\u591A\u304F\
    \u6D41\u308C\u308B\u3053\u3068\u304C\u591A\u3044\n * \u4F8B:\n * MinCostFlow<int,\
    \ long long> mcf(n);\n * mcf.add_edge(0, 1, 5, 3);\n * auto [f, c] = mcf.flow(s,\
    \ t, limit);\n *\n * @tparam Cap \u5BB9\u91CF\u306E\u578B \u7701\u7565\u3057\u305F\
    \u3089 long long\n * @tparam Cost \u30B3\u30B9\u30C8\u306E\u578B\u3002\u30B3\u30B9\
    \u30C8\u306E\u7DCF\u548C\u304C\u53CE\u307E\u308B\u3053\u3068 \u7701\u7565\u3057\
    \u305F\u3089 long long\n */\ntemplate <typename Cap = long long, typename Cost\
    \ = long long>\nclass MinCostFlow {\n   public:\n    /**\n     * @brief \u8FBA\
    \u306E\u60C5\u5831\n     */\n    struct Edge {\n        long long from, to;\n\
    \        Cap cap;    //!< \u5BB9\u91CF\n        Cap flow;   //!< \u6D41\u308C\u3066\
    \u3044\u308B\u91CF\n        Cost cost;  //!< 1 \u3060\u3051\u6D41\u3057\u305F\u3068\
    \u304D\u306E\u30B3\u30B9\u30C8\n    };\n\n   private:\n    // \u5185\u90E8\u306E\
    \u8FBA\u3068\u914D\u5217\u306F int \u3067\u6301\u3061\u3001\u516C\u958B\u3059\u308B\
    \u95A2\u6570\u3067 long long \u306B\u3059\u308B\n    struct InnerEdge {\n    \
    \    int to, rev;\n        Cap cap;  // \u6B8B\u308A\u306E\u5BB9\u91CF\n     \
    \   Cost cost;\n    };\n    long long n;\n    std::vector<std::vector<InnerEdge>>\
    \ g;\n    std::vector<std::pair<int, int>> pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\
    \u304C g \u306E\u3069\u3053\u306B\u3042\u308B\u304B\n    // \u30DD\u30C6\u30F3\
    \u30B7\u30E3\u30EB\u3002\u5BB9\u91CF\u304C\u6B8B\u3063\u3066\u3044\u308B\u3059\
    \u3079\u3066\u306E\u8FBA (v, u) \u3067 cost - dual[u] + dual[v] >= 0 \u3092\u4FDD\
    \u3064\n    std::vector<Cost> dual;\n    std::vector<Cost> dist;\n    std::vector<int>\
    \ prev_v, prev_e;\n    std::vector<bool> vis;\n    bool flowed = false;\n\n  \
    \  // s \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u3092\u6C42\u3081\u3001\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u66F4\u65B0\u3059\u308B\u3002t \u306B\u884C\
    \u3051\u306A\u3051\u308C\u3070 false\n    bool dual_ref(int s, int t) {\n    \
    \    std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());\n\
    \        std::fill(vis.begin(), vis.end(), false);\n        using P = std::pair<Cost,\
    \ int>;\n        std::priority_queue<P, std::vector<P>, std::greater<P>> que;\n\
    \        dist[s] = 0;\n        que.emplace(0, s);\n        while (!que.empty())\
    \ {\n            int v = que.top().second;\n            que.pop();\n         \
    \   if (vis[v]) continue;\n            vis[v] = true;\n            if (v == t)\
    \ break;\n            for (int i = 0; i < static_cast<int>(g[v].size()); i++)\
    \ {\n                const auto& e = g[v][i];\n                if (vis[e.to] ||\
    \ e.cap == 0) continue;\n                Cost c = e.cost - dual[e.to] + dual[v];\n\
    \                if (dist[e.to] - dist[v] > c) {\n                    dist[e.to]\
    \ = dist[v] + c;\n                    prev_v[e.to] = v;\n                    prev_e[e.to]\
    \ = i;\n                    que.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n        if (!vis[t]) return false;\n        // \u78BA\
    \u5B9A\u3057\u305F\u9802\u70B9\u3060\u3051\u66F4\u65B0\u3059\u308B\u3002\u78BA\
    \u5B9A\u3057\u3066\u3044\u306A\u3044\u9802\u70B9 u \u306F dist[u] >= dist[t] \u306A\
    \u306E\u3067\u3001\u6761\u4EF6\u306F\u4FDD\u305F\u308C\u308B\n        for (int\
    \ v = 0; v < n; v++) {\n            if (vis[v]) dual[v] -= dist[t] - dist[v];\n\
    \        }\n        return true;\n    }\n\n   public:\n    explicit MinCostFlow(long\
    \ long n = 0) : n(n), g(n), dual(n), dist(n), prev_v(n), prev_e(n), vis(n) {}\n\
    \n    long long size() const { return n; }\n\n    /**\n     * @brief from \u304B\
    \u3089 to \u3078\u306E\u5BB9\u91CF cap\u3001\u30B3\u30B9\u30C8 cost \u306E\u8FBA\
    \u3092\u8FFD\u52A0\u3057\u3001\u8FBA\u306E\u756A\u53F7 (\u8FFD\u52A0\u3057\u305F\
    \u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059\n     * flow \u3084 slope \u3092\u547C\
    \u3093\u3060\u5F8C\u306B\u306F\u8FFD\u52A0\u3067\u304D\u306A\u3044\n     */\n\
    \    long long add_edge(long long from, long long to, Cap cap, Cost cost) {\n\
    \        assert(0 <= from && from < n && 0 <= to && to < n && cap >= 0 && cost\
    \ >= 0);\n        assert(!flowed && \"MinCostFlow: add_edge after flow\");\n \
    \       long long id = pos.size();\n        int from_id = g[from].size();\n  \
    \      int to_id = g[to].size() + (from == to);\n        pos.emplace_back(from,\
    \ from_id);\n        g[from].push_back({static_cast<int>(to), to_id, cap, cost});\n\
    \        g[to].push_back({static_cast<int>(from), from_id, 0, -cost});\n     \
    \   return id;\n    }\n\n    /**\n     * @brief \u6D41\u91CF\u3068\u30B3\u30B9\
    \u30C8\u306E\u95A2\u4FC2\u3092\u8868\u3059\u6298\u308C\u7DDA\u306E\u9802\u70B9\
    \ (\u6D41\u91CF, \u30B3\u30B9\u30C8) \u306E\u30EA\u30B9\u30C8\n     *\n     *\
    \ s \u304B\u3089 t \u3078\u3001limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u6D41\
    \u91CF\u304C\u6700\u5927\u306B\u306A\u308B\u307E\u3067\u6D41\u3059\n     * \u6700\
    \u521D\u306F (0, 0)\u3001\u6700\u5F8C\u306F (\u6D41\u3057\u305F\u91CF, \u305D\u306E\
    \u3068\u304D\u306E\u6700\u5C0F\u30B3\u30B9\u30C8)\u3002\u50BE\u304D\u304C\u5909\
    \u308F\u308B\u70B9\u3060\u3051\u3092\u4E26\u3079\u308B\n     * \u4F55\u5EA6\u3082\
    \u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\
    \u52A0\u3057\u3066\u6D41\u3059 (\u305D\u308C\u305E\u308C\u306E\u547C\u3073\u51FA\
    \u3057\u306E\u4E2D\u3067\u306E\u91CF\u3092\u8FD4\u3059)\n     */\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(long long s, long long t, Cap limit = std::numeric_limits<Cap>::max())\
    \ {\n        assert(0 <= s && s < n && 0 <= t && t < n && s != t);\n        flowed\
    \ = true;\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow =\
    \ 0;\n        std::vector<std::pair<Cap, Cost>> res = {{0, 0}};\n        while\
    \ (flow < limit) {\n            if (!dual_ref(s, t)) break;\n            Cap c\
    \ = limit - flow;\n            for (long long v = t; v != s; v = prev_v[v]) c\
    \ = std::min(c, g[prev_v[v]][prev_e[v]].cap);\n            for (long long v =\
    \ t; v != s; v = prev_v[v]) {\n                auto& e = g[prev_v[v]][prev_e[v]];\n\
    \                e.cap -= c;\n                g[v][e.rev].cap += c;\n        \
    \    }\n            // \u6700\u77ED\u8DEF\u306E\u4E0A\u3067 cost - dual[to] +\
    \ dual[from] = 0 \u306A\u306E\u3067\u3001\u548C\u3092\u3068\u308B\u3068 1 \u3042\
    \u305F\u308A\u306E\u30B3\u30B9\u30C8\u306B\u306A\u308B\n            Cost d = dual[t]\
    \ - dual[s];\n            flow += c;\n            cost += c * d;\n           \
    \ if (res.size() >= 2 && prev_cost_per_flow == d) res.pop_back();\n          \
    \  res.emplace_back(flow, cost);\n            prev_cost_per_flow = d;\n      \
    \  }\n        return res;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\
    \u3001limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u6D41\u91CF\u304C\u6700\u5927\
    \u306B\u306A\u308B\u307E\u3067\u6D41\u3057\u3001(\u6D41\u3057\u305F\u91CF, \u305D\
    \u306E\u4E2D\u3067\u306E\u6700\u5C0F\u30B3\u30B9\u30C8) \u3092\u8FD4\u3059\n \
    \    * \u4F55\u5EA6\u3082\u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\
    \u6D41\u308C\u306B\u8FFD\u52A0\u3057\u3066\u6D41\u3059\n     */\n    std::pair<Cap,\
    \ Cost> flow(long long s, long long t, Cap limit = std::numeric_limits<Cap>::max())\
    \ {\n        return slope(s, t, limit).back();\n    }\n\n    /**\n     * @brief\
    \ \u756A\u53F7 i \u306E\u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long\
    \ long i) const {\n        assert(0 <= i && i < static_cast<long long>(pos.size()));\n\
    \        const auto& e = g[pos[i].first][pos[i].second];\n        const auto&\
    \ re = g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap,\
    \ e.cost};\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8FBA\u306E\
    \u60C5\u5831 (\u8FFD\u52A0\u3057\u305F\u9806)\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res;\n        for (long long i =\
    \ 0; i < static_cast<long long>(pos.size()); i++) res.push_back(get_edge(i));\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file min-cost-flow.hpp\n * @brief \u6700\u5C0F\u8CBB\
    \u7528\u6D41 (primal-dual \u6CD5)\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual\
    \ \u6CD5)\n *\n * \u8FBA\u306E\u30B3\u30B9\u30C8\u306F 0 \u4EE5\u4E0A\u3067\u3042\
    \u308B\u3053\u3068\u3002\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u4F7F\u3044\
    \u3001\u6700\u77ED\u8DEF\u3092 Dijkstra \u6CD5\u3067\u6C42\u3081\u308B\n * \u6700\
    \u77ED\u8DEF 1 \u672C\u3054\u3068\u306B Dijkstra \u6CD5\u3092 1 \u56DE\u884C\u3046\
    \u306E\u3067 O(F (n + m) log m) (F \u306F\u6D41\u91CF)\u3002\u5B9F\u969B\u306B\
    \u306F\u30011 \u672C\u306E\u8DEF\u3067\u591A\u304F\u6D41\u308C\u308B\u3053\u3068\
    \u304C\u591A\u3044\n * \u4F8B:\n * MinCostFlow<int, long long> mcf(n);\n * mcf.add_edge(0,\
    \ 1, 5, 3);\n * auto [f, c] = mcf.flow(s, t, limit);\n *\n * @tparam Cap \u5BB9\
    \u91CF\u306E\u578B \u7701\u7565\u3057\u305F\u3089 long long\n * @tparam Cost \u30B3\
    \u30B9\u30C8\u306E\u578B\u3002\u30B3\u30B9\u30C8\u306E\u7DCF\u548C\u304C\u53CE\
    \u307E\u308B\u3053\u3068 \u7701\u7565\u3057\u305F\u3089 long long\n */\ntemplate\
    \ <typename Cap = long long, typename Cost = long long>\nclass MinCostFlow {\n\
    \   public:\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\n     */\n    struct\
    \ Edge {\n        long long from, to;\n        Cap cap;    //!< \u5BB9\u91CF\n\
    \        Cap flow;   //!< \u6D41\u308C\u3066\u3044\u308B\u91CF\n        Cost cost;\
    \  //!< 1 \u3060\u3051\u6D41\u3057\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\n\
    \    };\n\n   private:\n    // \u5185\u90E8\u306E\u8FBA\u3068\u914D\u5217\u306F\
    \ int \u3067\u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long\
    \ long \u306B\u3059\u308B\n    struct InnerEdge {\n        int to, rev;\n    \
    \    Cap cap;  // \u6B8B\u308A\u306E\u5BB9\u91CF\n        Cost cost;\n    };\n\
    \    long long n;\n    std::vector<std::vector<InnerEdge>> g;\n    std::vector<std::pair<int,\
    \ int>> pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\u304C g \u306E\u3069\u3053\u306B\
    \u3042\u308B\u304B\n    // \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3002\u5BB9\u91CF\
    \u304C\u6B8B\u3063\u3066\u3044\u308B\u3059\u3079\u3066\u306E\u8FBA (v, u) \u3067\
    \ cost - dual[u] + dual[v] >= 0 \u3092\u4FDD\u3064\n    std::vector<Cost> dual;\n\
    \    std::vector<Cost> dist;\n    std::vector<int> prev_v, prev_e;\n    std::vector<bool>\
    \ vis;\n    bool flowed = false;\n\n    // s \u304B\u3089 t \u3078\u306E\u6700\
    \u77ED\u8DEF\u3092\u6C42\u3081\u3001\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\
    \u66F4\u65B0\u3059\u308B\u3002t \u306B\u884C\u3051\u306A\u3051\u308C\u3070 false\n\
    \    bool dual_ref(int s, int t) {\n        std::fill(dist.begin(), dist.end(),\
    \ std::numeric_limits<Cost>::max());\n        std::fill(vis.begin(), vis.end(),\
    \ false);\n        using P = std::pair<Cost, int>;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> que;\n        dist[s] = 0;\n        que.emplace(0,\
    \ s);\n        while (!que.empty()) {\n            int v = que.top().second;\n\
    \            que.pop();\n            if (vis[v]) continue;\n            vis[v]\
    \ = true;\n            if (v == t) break;\n            for (int i = 0; i < static_cast<int>(g[v].size());\
    \ i++) {\n                const auto& e = g[v][i];\n                if (vis[e.to]\
    \ || e.cap == 0) continue;\n                Cost c = e.cost - dual[e.to] + dual[v];\n\
    \                if (dist[e.to] - dist[v] > c) {\n                    dist[e.to]\
    \ = dist[v] + c;\n                    prev_v[e.to] = v;\n                    prev_e[e.to]\
    \ = i;\n                    que.emplace(dist[e.to], e.to);\n                }\n\
    \            }\n        }\n        if (!vis[t]) return false;\n        // \u78BA\
    \u5B9A\u3057\u305F\u9802\u70B9\u3060\u3051\u66F4\u65B0\u3059\u308B\u3002\u78BA\
    \u5B9A\u3057\u3066\u3044\u306A\u3044\u9802\u70B9 u \u306F dist[u] >= dist[t] \u306A\
    \u306E\u3067\u3001\u6761\u4EF6\u306F\u4FDD\u305F\u308C\u308B\n        for (int\
    \ v = 0; v < n; v++) {\n            if (vis[v]) dual[v] -= dist[t] - dist[v];\n\
    \        }\n        return true;\n    }\n\n   public:\n    explicit MinCostFlow(long\
    \ long n = 0) : n(n), g(n), dual(n), dist(n), prev_v(n), prev_e(n), vis(n) {}\n\
    \n    long long size() const { return n; }\n\n    /**\n     * @brief from \u304B\
    \u3089 to \u3078\u306E\u5BB9\u91CF cap\u3001\u30B3\u30B9\u30C8 cost \u306E\u8FBA\
    \u3092\u8FFD\u52A0\u3057\u3001\u8FBA\u306E\u756A\u53F7 (\u8FFD\u52A0\u3057\u305F\
    \u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059\n     * flow \u3084 slope \u3092\u547C\
    \u3093\u3060\u5F8C\u306B\u306F\u8FFD\u52A0\u3067\u304D\u306A\u3044\n     */\n\
    \    long long add_edge(long long from, long long to, Cap cap, Cost cost) {\n\
    \        assert(0 <= from && from < n && 0 <= to && to < n && cap >= 0 && cost\
    \ >= 0);\n        assert(!flowed && \"MinCostFlow: add_edge after flow\");\n \
    \       long long id = pos.size();\n        int from_id = g[from].size();\n  \
    \      int to_id = g[to].size() + (from == to);\n        pos.emplace_back(from,\
    \ from_id);\n        g[from].push_back({static_cast<int>(to), to_id, cap, cost});\n\
    \        g[to].push_back({static_cast<int>(from), from_id, 0, -cost});\n     \
    \   return id;\n    }\n\n    /**\n     * @brief \u6D41\u91CF\u3068\u30B3\u30B9\
    \u30C8\u306E\u95A2\u4FC2\u3092\u8868\u3059\u6298\u308C\u7DDA\u306E\u9802\u70B9\
    \ (\u6D41\u91CF, \u30B3\u30B9\u30C8) \u306E\u30EA\u30B9\u30C8\n     *\n     *\
    \ s \u304B\u3089 t \u3078\u3001limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u6D41\
    \u91CF\u304C\u6700\u5927\u306B\u306A\u308B\u307E\u3067\u6D41\u3059\n     * \u6700\
    \u521D\u306F (0, 0)\u3001\u6700\u5F8C\u306F (\u6D41\u3057\u305F\u91CF, \u305D\u306E\
    \u3068\u304D\u306E\u6700\u5C0F\u30B3\u30B9\u30C8)\u3002\u50BE\u304D\u304C\u5909\
    \u308F\u308B\u70B9\u3060\u3051\u3092\u4E26\u3079\u308B\n     * \u4F55\u5EA6\u3082\
    \u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\
    \u52A0\u3057\u3066\u6D41\u3059 (\u305D\u308C\u305E\u308C\u306E\u547C\u3073\u51FA\
    \u3057\u306E\u4E2D\u3067\u306E\u91CF\u3092\u8FD4\u3059)\n     */\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(long long s, long long t, Cap limit = std::numeric_limits<Cap>::max())\
    \ {\n        assert(0 <= s && s < n && 0 <= t && t < n && s != t);\n        flowed\
    \ = true;\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow =\
    \ 0;\n        std::vector<std::pair<Cap, Cost>> res = {{0, 0}};\n        while\
    \ (flow < limit) {\n            if (!dual_ref(s, t)) break;\n            Cap c\
    \ = limit - flow;\n            for (long long v = t; v != s; v = prev_v[v]) c\
    \ = std::min(c, g[prev_v[v]][prev_e[v]].cap);\n            for (long long v =\
    \ t; v != s; v = prev_v[v]) {\n                auto& e = g[prev_v[v]][prev_e[v]];\n\
    \                e.cap -= c;\n                g[v][e.rev].cap += c;\n        \
    \    }\n            // \u6700\u77ED\u8DEF\u306E\u4E0A\u3067 cost - dual[to] +\
    \ dual[from] = 0 \u306A\u306E\u3067\u3001\u548C\u3092\u3068\u308B\u3068 1 \u3042\
    \u305F\u308A\u306E\u30B3\u30B9\u30C8\u306B\u306A\u308B\n            Cost d = dual[t]\
    \ - dual[s];\n            flow += c;\n            cost += c * d;\n           \
    \ if (res.size() >= 2 && prev_cost_per_flow == d) res.pop_back();\n          \
    \  res.emplace_back(flow, cost);\n            prev_cost_per_flow = d;\n      \
    \  }\n        return res;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\
    \u3001limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u6D41\u91CF\u304C\u6700\u5927\
    \u306B\u306A\u308B\u307E\u3067\u6D41\u3057\u3001(\u6D41\u3057\u305F\u91CF, \u305D\
    \u306E\u4E2D\u3067\u306E\u6700\u5C0F\u30B3\u30B9\u30C8) \u3092\u8FD4\u3059\n \
    \    * \u4F55\u5EA6\u3082\u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\
    \u6D41\u308C\u306B\u8FFD\u52A0\u3057\u3066\u6D41\u3059\n     */\n    std::pair<Cap,\
    \ Cost> flow(long long s, long long t, Cap limit = std::numeric_limits<Cap>::max())\
    \ {\n        return slope(s, t, limit).back();\n    }\n\n    /**\n     * @brief\
    \ \u756A\u53F7 i \u306E\u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long\
    \ long i) const {\n        assert(0 <= i && i < static_cast<long long>(pos.size()));\n\
    \        const auto& e = g[pos[i].first][pos[i].second];\n        const auto&\
    \ re = g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap,\
    \ e.cost};\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8FBA\u306E\
    \u60C5\u5831 (\u8FFD\u52A0\u3057\u305F\u9806)\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res;\n        for (long long i =\
    \ 0; i < static_cast<long long>(pos.size()); i++) res.push_back(get_edge(i));\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/min-cost-flow.hpp
  requiredBy: []
  timestamp: '2026-10-22 13:41:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/min-cost-flow.test.cpp
  - test/aoj/grl/grl-6-b.test.cpp
documentation_of: src/graph/min-cost-flow.hpp
layout: document
title: "\u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)"
---

有向グラフの最小費用流を求める `MinCostFlow<Cap = long long, Cost = long long>` です。`Cap` は容量の型、`Cost` はコストの型で、省くとどちらも `long long` になります (`MinCostFlow mcf(n);` と書けます)。辺のコストは 0 以上とします。

ポテンシャルを使い、残余グラフの最短路を Dijkstra 法で求めては流します。最短路 1 本ごとに $O((n + m) \log m)$ かかり、最短路の本数は流量 $F$ 以下なので、全体で $O(F (n + m) \log m)$ です。

```cpp
MinCostFlow<int, long long> mcf(n);
long long id = mcf.add_edge(0, 1, 5, 3);  // 0 から 1 へ容量 5、コスト 3 の辺。辺の番号を返す
auto [f, c] = mcf.flow(s, t, limit);   // limit を上限として流量が最大になるまで流す。f は流量、c は最小コスト
auto e = mcf.get_edge(id);              // e.from, e.to, e.cap, e.flow, e.cost
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MinCostFlow(n)` | 頂点数 `n`、辺のない状態 | $O(n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `add_edge(from, to, cap, cost)` | `from` から `to` へ容量 `cap`、1 あたりのコスト `cost` (0 以上) の辺を追加し、辺の番号 (追加した順に 0, 1, ...) を返す | ならし $O(1)$ |
| `flow(s, t)` / `flow(s, t, limit)` | `s` から `t` へ、流量が最大になるまで (`limit` があればそれを上限として) 流し、(流量, そのときの最小コスト) を返す | $O(F (n + m) \log m)$ ($F$ は流した量) |
| `slope(s, t)` / `slope(s, t, limit)` | `flow` と同じように流し、流量とコストの関係を表す折れ線の頂点 (流量, コスト) を並べたものを返す | $O(F (n + m) \log m)$ |
| `get_edge(i)` | 番号 `i` の辺の `from`、`to`、`cap` (容量)、`flow` (流れている量)、`cost` | $O(1)$ |
| `edges()` | すべての辺の情報 (追加した順) | $O(m)$ |

- 頂点番号と辺の番号 (`add_edge` の戻り値、`Edge` の `from`・`to`) は `long long` です。
- `slope` の返す折れ線は (0, 0) から始まり、傾きが変わる点だけを並べます。流量 $x$ を流すときの最小コストは、折れ線の $x$ での値です。傾き (1 あたりのコスト) は単調に増えます。
- `flow` と `slope` は何度も呼べます。前回までの流れに追加して流し、返す値はその呼び出しの中で流した量とコストです。`s` と `t` が前回と違ってもかまいません。
- `flow` や `slope` を呼んだ後に `add_edge` はできません。

## 例

流量をちょうど $F$ にしたいときは、`limit` を $F$ にして、流量が $F$ になったかを確かめます。

```cpp
auto [f, c] = mcf.flow(s, t, F);
if (f < F) {
    // F だけ流すことはできない
}
```

流量を自由に選んでコストを最小にしたいとき (コストが負の辺を含む問題を変形した場合など) は、`slope` の頂点のうちコストが最小のものを選びます。

## 関連

- コストのない最大流は [最大流](max-flow.hpp)
