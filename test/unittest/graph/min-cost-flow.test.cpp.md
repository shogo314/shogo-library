---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/min-cost-flow.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)"
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
  bundledCode: "#line 1 \"test/unittest/graph/min-cost-flow.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ MinCostFlow \u3092\u3001Bellman-Ford \u6CD5\u3067 1 \u305A\u3064\u6D41\u3059\
    \u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u578B\u3092\u7701\u3044\
    \u305F\u3068\u304D\u306B long long \u306B\u306A\u308B\u3053\u3068\u3082 static_assert\
    \ \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/min-cost-flow.hpp\"\n\n\
    /**\n * @file min-cost-flow.hpp\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual\
    \ \u6CD5)\n */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\n\
    /**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41 (primal-dual \u6CD5)\n *\n * \u8FBA\
    \u306E\u30B3\u30B9\u30C8\u306F 0 \u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3002\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u4F7F\u3044\u3001\u6700\u77ED\u8DEF\
    \u3092 Dijkstra \u6CD5\u3067\u6C42\u3081\u308B\n * \u6700\u77ED\u8DEF 1 \u672C\
    \u3054\u3068\u306B Dijkstra \u6CD5\u3092 1 \u56DE\u884C\u3046\u306E\u3067 O(F\
    \ (n + m) log m) (F \u306F\u6D41\u91CF)\u3002\u5B9F\u969B\u306B\u306F\u30011 \u672C\
    \u306E\u8DEF\u3067\u591A\u304F\u6D41\u308C\u308B\u3053\u3068\u304C\u591A\u3044\
    \n * \u4F8B:\n * MinCostFlow<int, long long> mcf(n);\n * mcf.add_edge(0, 1, 5,\
    \ 3);\n * auto [f, c] = mcf.flow(s, t, limit);\n *\n * @tparam Cap \u5BB9\u91CF\
    \u306E\u578B \u7701\u7565\u3057\u305F\u3089 long long\n * @tparam Cost \u30B3\u30B9\
    \u30C8\u306E\u578B\u3002\u30B3\u30B9\u30C8\u306E\u7DCF\u548C\u304C\u53CE\u307E\
    \u308B\u3053\u3068 \u7701\u7565\u3057\u305F\u3089 long long\n */\ntemplate <typename\
    \ Cap = long long, typename Cost = long long>\nclass MinCostFlow {\n   public:\n\
    \    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\n     */\n    struct Edge {\n\
    \        long long from, to;\n        Cap cap;    //!< \u5BB9\u91CF\n        Cap\
    \ flow;   //!< \u6D41\u308C\u3066\u3044\u308B\u91CF\n        Cost cost;  //!<\
    \ 1 \u3060\u3051\u6D41\u3057\u305F\u3068\u304D\u306E\u30B3\u30B9\u30C8\n    };\n\
    \n   private:\n    // \u5185\u90E8\u306E\u8FBA\u3068\u914D\u5217\u306F int \u3067\
    \u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\
    \u308B\n    struct InnerEdge {\n        int to, rev;\n        Cap cap;  // \u6B8B\
    \u308A\u306E\u5BB9\u91CF\n        Cost cost;\n    };\n    long long n;\n    std::vector<std::vector<InnerEdge>>\
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
    \        return res;\n    }\n};\n#line 8 \"test/unittest/graph/min-cost-flow.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <tuple>\n#include <type_traits>\n\
    #line 14 \"test/unittest/graph/min-cost-flow.test.cpp\"\n\n// Bellman-Ford \u6CD5\
    \u3067 1 \u305A\u3064\u6D41\u3059\u611A\u76F4\u306A\u6700\u5C0F\u8CBB\u7528\u6D41\
    \nstruct Naive {\n    struct E {\n        int to, rev, cap, cost;\n    };\n  \
    \  int n;\n    std::vector<std::vector<E>> g;\n    Naive(int n, const std::vector<std::tuple<int,\
    \ int, int, int>>& es) : n(n), g(n) {\n        for (auto [u, v, c, d] : es) {\n\
    \            int a = g[u].size(), b = g[v].size() + (u == v);\n            g[u].push_back({v,\
    \ b, c, d});\n            g[v].push_back({u, a, 0, -d});\n        }\n    }\n \
    \   // \u6D41\u91CF k = 0, 1, ... \u3054\u3068\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\
    \ (\u4ECA\u306E\u6D41\u308C\u304B\u3089\u306E\u5897\u5206)\n    std::vector<long\
    \ long> flow(int s, int t) {\n        std::vector<long long> res = {0};\n    \
    \    const long long INF = 1LL << 60;\n        while (true) {\n            std::vector<long\
    \ long> dist(n, INF);\n            std::vector<int> pv(n, -1), pe(n, -1);\n  \
    \          dist[s] = 0;\n            for (int it = 0; it < n; it++) {\n      \
    \          for (int v = 0; v < n; v++) {\n                    if (dist[v] == INF)\
    \ continue;\n                    for (int i = 0; i < static_cast<int>(g[v].size());\
    \ i++) {\n                        auto& e = g[v][i];\n                       \
    \ if (e.cap > 0 && dist[v] + e.cost < dist[e.to]) {\n                        \
    \    dist[e.to] = dist[v] + e.cost;\n                            pv[e.to] = v;\n\
    \                            pe[e.to] = i;\n                        }\n      \
    \              }\n                }\n            }\n            if (dist[t] ==\
    \ INF) break;\n            for (int v = t; v != s; v = pv[v]) {\n            \
    \    auto& e = g[pv[v]][pe[v]];\n                e.cap--;\n                g[v][e.rev].cap++;\n\
    \            }\n            res.push_back(res.back() + dist[t]);\n        }\n\
    \        return res;\n    }\n};\n\n// \u6298\u308C\u7DDA sl \u304C\u3001\u6D41\
    \u91CF\u3054\u3068\u306E\u6700\u5C0F\u30B3\u30B9\u30C8 expected[base + k] - expected[base]\
    \ \u3068\u4E00\u81F4\u3057\u3001\u50BE\u304D\u304C\u771F\u306B\u5897\u52A0\u3059\
    \u308B\u304B\nbool check_slope(const std::vector<std::pair<int, long long>>& sl,\
    \ const std::vector<long long>& expected, int base) {\n    if (sl.empty() || sl[0]\
    \ != std::make_pair(0, 0LL)) return false;\n    for (int i = 0; i + 1 < static_cast<int>(sl.size());\
    \ i++) {\n        auto [f0, c0] = sl[i];\n        auto [f1, c1] = sl[i + 1];\n\
    \        if (f0 >= f1 || base + f1 >= static_cast<int>(expected.size())) return\
    \ false;\n        for (int k = f0; k <= f1; k++) {\n            // \u9802\u70B9\
    \u306E\u9593\u306F\u7DDA\u5F62\n            long long num = static_cast<long long>(k\
    \ - f0) * (c1 - c0);\n            if (num % (f1 - f0) != 0 || c0 + num / (f1 -\
    \ f0) != expected[base + k] - expected[base]) return false;\n        }\n     \
    \   if (i + 2 < static_cast<int>(sl.size())) {\n            auto [f2, c2] = sl[i\
    \ + 2];\n            if ((c1 - c0) * (f2 - f1) >= (c2 - c1) * (f1 - f0)) return\
    \ false;\n        }\n    }\n    return true;\n}\n\nstatic_assert(std::is_same_v<decltype(MinCostFlow(3)),\
    \ MinCostFlow<long long, long long>>);\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 6 + 2, m = rng() % 13;\n        int s = rng() % n, t = rng()\
    \ % (n - 1);\n        if (t >= s) t++;\n        std::vector<std::tuple<int, int,\
    \ int, int>> es;\n        MinCostFlow<int, long long> mcf(n);\n        for (int\
    \ i = 0; i < m; i++) {\n            int u = rng() % n, v = rng() % n;  // \u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n         \
    \   int c = rng() % 6, d = rng() % 10;\n            es.emplace_back(u, v, c, d);\n\
    \            if (mcf.add_edge(u, v, c, d) != i) ok = false;\n        }\n     \
    \   Naive nv(n, es);\n        std::vector<long long> expected = nv.flow(s, t);\n\
    \        int max_flow = expected.size() - 1;\n\n        // \u4E0A\u9650\u3064\u304D\
    \u3067 2 \u56DE\u306B\u5206\u3051\u3066\u6D41\u3059\n        int limit = rng()\
    \ % (max_flow + 1);\n        auto sl1 = mcf.slope(s, t, limit);\n        auto\
    \ sl2 = mcf.slope(s, t);\n        ok = ok && check_slope(sl1, expected, 0) &&\
    \ check_slope(sl2, expected, limit);\n        if (sl1.back().first != limit ||\
    \ limit + sl2.back().first != max_flow) ok = false;\n\n        // \u5404\u8FBA\
    \u306E\u6D41\u91CF\u304C\u5BB9\u91CF\u4EE5\u4E0B\u3067\u3001\u6D41\u91CF\u304C\
    \u4FDD\u5B58\u3055\u308C\u3001\u30B3\u30B9\u30C8\u306E\u548C\u304C\u5408\u3046\
    \n        std::vector<long long> balance(n);\n        long long total = 0;\n \
    \       auto edges = mcf.edges();\n        for (int i = 0; i < m; i++) {\n   \
    \         auto [u, v, c, d] = es[i];\n            auto e = mcf.get_edge(i);\n\
    \            if (e.from != u || e.to != v || e.cap != c || e.cost != d || e.flow\
    \ < 0 || e.flow > c) ok = false;\n            if (edges[i].flow != e.flow) ok\
    \ = false;\n            balance[u] -= e.flow;\n            balance[v] += e.flow;\n\
    \            total += static_cast<long long>(e.flow) * d;\n        }\n       \
    \ for (int v = 0; v < n; v++) {\n            long long want = v == s ? -max_flow\
    \ : v == t ? max_flow\n                                                      \
    \   : 0;\n            if (balance[v] != want) ok = false;\n        }\n       \
    \ if (total != expected[max_flow]) ok = false;\n    }\n\n    // \u6D41\u3057\u305F\
    \u5F8C\u3067\u3001\u5225\u306E s, t \u304B\u3089\u7D9A\u3051\u3066\u6D41\u3059\
    \ (\u30B3\u30B9\u30C8\u304C\u8CA0\u306E\u8DEF\u3092\u4F7F\u3046\u3053\u3068\u3082\
    \u3042\u308B)\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n\
    \ = rng() % 6 + 2, m = rng() % 13;\n        std::vector<std::tuple<int, int, int,\
    \ int>> es;\n        MinCostFlow<int, long long> mcf(n);\n        for (int i =\
    \ 0; i < m; i++) {\n            int u = rng() % n, v = rng() % n;\n          \
    \  int c = rng() % 6, d = rng() % 10;\n            es.emplace_back(u, v, c, d);\n\
    \            mcf.add_edge(u, v, c, d);\n        }\n        Naive nv(n, es);\n\
    \        for (int it = 0; it < 3 && ok; it++) {\n            int s = rng() % n,\
    \ t = rng() % (n - 1);\n            if (t >= s) t++;\n            auto sl = mcf.slope(s,\
    \ t);\n            auto expected = nv.flow(s, t);\n            ok = ok && check_slope(sl,\
    \ expected, 0) && sl.back().first == static_cast<int>(expected.size()) - 1;\n\
    \        }\n    }\n\n    // \u4F8B\n    MinCostFlow<int, int> mcf(4);\n    mcf.add_edge(0,\
    \ 1, 2, 1);\n    mcf.add_edge(0, 2, 1, 2);\n    mcf.add_edge(1, 2, 1, 1);\n  \
    \  mcf.add_edge(1, 3, 1, 3);\n    mcf.add_edge(2, 3, 2, 1);\n    ok = ok && mcf.slope(0,\
    \ 3) == std::vector<std::pair<int, int>>{{0, 0}, {2, 6}, {3, 10}};\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// MinCostFlow \u3092\u3001Bellman-Ford \u6CD5\u3067 1 \u305A\u3064\u6D41\u3059\
    \u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\u3079\u308B\n// \u578B\u3092\u7701\u3044\
    \u305F\u3068\u304D\u306B long long \u306B\u306A\u308B\u3053\u3068\u3082 static_assert\
    \ \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/min-cost-flow.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <tuple>\n#include <type_traits>\n\
    #include <vector>\n\n// Bellman-Ford \u6CD5\u3067 1 \u305A\u3064\u6D41\u3059\u611A\
    \u76F4\u306A\u6700\u5C0F\u8CBB\u7528\u6D41\nstruct Naive {\n    struct E {\n \
    \       int to, rev, cap, cost;\n    };\n    int n;\n    std::vector<std::vector<E>>\
    \ g;\n    Naive(int n, const std::vector<std::tuple<int, int, int, int>>& es)\
    \ : n(n), g(n) {\n        for (auto [u, v, c, d] : es) {\n            int a =\
    \ g[u].size(), b = g[v].size() + (u == v);\n            g[u].push_back({v, b,\
    \ c, d});\n            g[v].push_back({u, a, 0, -d});\n        }\n    }\n    //\
    \ \u6D41\u91CF k = 0, 1, ... \u3054\u3068\u306E\u6700\u5C0F\u30B3\u30B9\u30C8\
    \ (\u4ECA\u306E\u6D41\u308C\u304B\u3089\u306E\u5897\u5206)\n    std::vector<long\
    \ long> flow(int s, int t) {\n        std::vector<long long> res = {0};\n    \
    \    const long long INF = 1LL << 60;\n        while (true) {\n            std::vector<long\
    \ long> dist(n, INF);\n            std::vector<int> pv(n, -1), pe(n, -1);\n  \
    \          dist[s] = 0;\n            for (int it = 0; it < n; it++) {\n      \
    \          for (int v = 0; v < n; v++) {\n                    if (dist[v] == INF)\
    \ continue;\n                    for (int i = 0; i < static_cast<int>(g[v].size());\
    \ i++) {\n                        auto& e = g[v][i];\n                       \
    \ if (e.cap > 0 && dist[v] + e.cost < dist[e.to]) {\n                        \
    \    dist[e.to] = dist[v] + e.cost;\n                            pv[e.to] = v;\n\
    \                            pe[e.to] = i;\n                        }\n      \
    \              }\n                }\n            }\n            if (dist[t] ==\
    \ INF) break;\n            for (int v = t; v != s; v = pv[v]) {\n            \
    \    auto& e = g[pv[v]][pe[v]];\n                e.cap--;\n                g[v][e.rev].cap++;\n\
    \            }\n            res.push_back(res.back() + dist[t]);\n        }\n\
    \        return res;\n    }\n};\n\n// \u6298\u308C\u7DDA sl \u304C\u3001\u6D41\
    \u91CF\u3054\u3068\u306E\u6700\u5C0F\u30B3\u30B9\u30C8 expected[base + k] - expected[base]\
    \ \u3068\u4E00\u81F4\u3057\u3001\u50BE\u304D\u304C\u771F\u306B\u5897\u52A0\u3059\
    \u308B\u304B\nbool check_slope(const std::vector<std::pair<int, long long>>& sl,\
    \ const std::vector<long long>& expected, int base) {\n    if (sl.empty() || sl[0]\
    \ != std::make_pair(0, 0LL)) return false;\n    for (int i = 0; i + 1 < static_cast<int>(sl.size());\
    \ i++) {\n        auto [f0, c0] = sl[i];\n        auto [f1, c1] = sl[i + 1];\n\
    \        if (f0 >= f1 || base + f1 >= static_cast<int>(expected.size())) return\
    \ false;\n        for (int k = f0; k <= f1; k++) {\n            // \u9802\u70B9\
    \u306E\u9593\u306F\u7DDA\u5F62\n            long long num = static_cast<long long>(k\
    \ - f0) * (c1 - c0);\n            if (num % (f1 - f0) != 0 || c0 + num / (f1 -\
    \ f0) != expected[base + k] - expected[base]) return false;\n        }\n     \
    \   if (i + 2 < static_cast<int>(sl.size())) {\n            auto [f2, c2] = sl[i\
    \ + 2];\n            if ((c1 - c0) * (f2 - f1) >= (c2 - c1) * (f1 - f0)) return\
    \ false;\n        }\n    }\n    return true;\n}\n\nstatic_assert(std::is_same_v<decltype(MinCostFlow(3)),\
    \ MinCostFlow<long long, long long>>);\n\nint main() {\n    std::mt19937 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n     \
    \   int n = rng() % 6 + 2, m = rng() % 13;\n        int s = rng() % n, t = rng()\
    \ % (n - 1);\n        if (t >= s) t++;\n        std::vector<std::tuple<int, int,\
    \ int, int>> es;\n        MinCostFlow<int, long long> mcf(n);\n        for (int\
    \ i = 0; i < m; i++) {\n            int u = rng() % n, v = rng() % n;  // \u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n         \
    \   int c = rng() % 6, d = rng() % 10;\n            es.emplace_back(u, v, c, d);\n\
    \            if (mcf.add_edge(u, v, c, d) != i) ok = false;\n        }\n     \
    \   Naive nv(n, es);\n        std::vector<long long> expected = nv.flow(s, t);\n\
    \        int max_flow = expected.size() - 1;\n\n        // \u4E0A\u9650\u3064\u304D\
    \u3067 2 \u56DE\u306B\u5206\u3051\u3066\u6D41\u3059\n        int limit = rng()\
    \ % (max_flow + 1);\n        auto sl1 = mcf.slope(s, t, limit);\n        auto\
    \ sl2 = mcf.slope(s, t);\n        ok = ok && check_slope(sl1, expected, 0) &&\
    \ check_slope(sl2, expected, limit);\n        if (sl1.back().first != limit ||\
    \ limit + sl2.back().first != max_flow) ok = false;\n\n        // \u5404\u8FBA\
    \u306E\u6D41\u91CF\u304C\u5BB9\u91CF\u4EE5\u4E0B\u3067\u3001\u6D41\u91CF\u304C\
    \u4FDD\u5B58\u3055\u308C\u3001\u30B3\u30B9\u30C8\u306E\u548C\u304C\u5408\u3046\
    \n        std::vector<long long> balance(n);\n        long long total = 0;\n \
    \       auto edges = mcf.edges();\n        for (int i = 0; i < m; i++) {\n   \
    \         auto [u, v, c, d] = es[i];\n            auto e = mcf.get_edge(i);\n\
    \            if (e.from != u || e.to != v || e.cap != c || e.cost != d || e.flow\
    \ < 0 || e.flow > c) ok = false;\n            if (edges[i].flow != e.flow) ok\
    \ = false;\n            balance[u] -= e.flow;\n            balance[v] += e.flow;\n\
    \            total += static_cast<long long>(e.flow) * d;\n        }\n       \
    \ for (int v = 0; v < n; v++) {\n            long long want = v == s ? -max_flow\
    \ : v == t ? max_flow\n                                                      \
    \   : 0;\n            if (balance[v] != want) ok = false;\n        }\n       \
    \ if (total != expected[max_flow]) ok = false;\n    }\n\n    // \u6D41\u3057\u305F\
    \u5F8C\u3067\u3001\u5225\u306E s, t \u304B\u3089\u7D9A\u3051\u3066\u6D41\u3059\
    \ (\u30B3\u30B9\u30C8\u304C\u8CA0\u306E\u8DEF\u3092\u4F7F\u3046\u3053\u3068\u3082\
    \u3042\u308B)\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n\
    \ = rng() % 6 + 2, m = rng() % 13;\n        std::vector<std::tuple<int, int, int,\
    \ int>> es;\n        MinCostFlow<int, long long> mcf(n);\n        for (int i =\
    \ 0; i < m; i++) {\n            int u = rng() % n, v = rng() % n;\n          \
    \  int c = rng() % 6, d = rng() % 10;\n            es.emplace_back(u, v, c, d);\n\
    \            mcf.add_edge(u, v, c, d);\n        }\n        Naive nv(n, es);\n\
    \        for (int it = 0; it < 3 && ok; it++) {\n            int s = rng() % n,\
    \ t = rng() % (n - 1);\n            if (t >= s) t++;\n            auto sl = mcf.slope(s,\
    \ t);\n            auto expected = nv.flow(s, t);\n            ok = ok && check_slope(sl,\
    \ expected, 0) && sl.back().first == static_cast<int>(expected.size()) - 1;\n\
    \        }\n    }\n\n    // \u4F8B\n    MinCostFlow<int, int> mcf(4);\n    mcf.add_edge(0,\
    \ 1, 2, 1);\n    mcf.add_edge(0, 2, 1, 2);\n    mcf.add_edge(1, 2, 1, 1);\n  \
    \  mcf.add_edge(1, 3, 1, 3);\n    mcf.add_edge(2, 3, 2, 1);\n    ok = ok && mcf.slope(0,\
    \ 3) == std::vector<std::pair<int, int>>{{0, 0}, {2, 6}, {3, 10}};\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/min-cost-flow.hpp
  isVerificationFile: true
  path: test/unittest/graph/min-cost-flow.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 13:41:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/min-cost-flow.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/min-cost-flow.test.cpp
- /verify/test/unittest/graph/min-cost-flow.test.cpp.html
title: test/unittest/graph/min-cost-flow.test.cpp
---
