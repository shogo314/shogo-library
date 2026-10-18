---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/lowlink.hpp
    title: "lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\u7D50\
      \u6210\u5206\u5206\u89E3)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two-edge-connected-components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #include <iostream>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n\
    \ * @brief \u30B0\u30E9\u30D5\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <deque>\n#include <functional>\n#line 13 \"src/graph/graph.hpp\"\n#include\
    \ <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\n/**\n *\
    \ @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam\
    \ Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost\
    \ = int>\nclass Graph {\n   public:\n    /**\n     * @brief \u6709\u5411\u8FBA\
    \u306E\u69CB\u9020\u4F53\n     *\n     * operator long long()\u3092\u5B9A\u7FA9\
    \u3057\u3066\u3044\u308B\u306E\u3067\u3001\u6574\u6570\u578B\u306B\u30AD\u30E3\
    \u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\n     *\
    \ \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\u3068\
    \u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\u304C\
    \u3001\n     * for (long long dst : g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\
    \u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\u308C\
    \u308B\n     */\n    struct Edge {\n        long long src = -1;  //!< \u59CB\u70B9\
    \n        long long dst = -1;  //!< \u7D42\u70B9\n        Cost cost = {};    \
    \  //!< \u30B3\u30B9\u30C8\n        long long id = -1;   //!< \u8FBA\u306E\u756A\
    \u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\
    \u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\
    \u304C2\u3064\u5B58\u5728\u3059\u308B)\n        Edge() = default;\n        Edge(long\
    \ long src, long long dst, Cost cost = 1, long long id = -1) : src(src), dst(dst),\
    \ cost(cost), id(id) {}\n        operator long long() const { return dst; }\n\
    \    };\n\n    /**\n     * @brief \u6700\u77ED\u8DEF\u306E\u7D50\u679C\n     *\n\
    \     * auto [dist, prev] = g.shortest_path(s); \u306E\u3088\u3046\u306B\u53D7\
    \u3051\u53D6\u308C\u308B\n     */\n    struct ShortestPath {\n        std::vector<Cost>\
    \ dist;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\n       \
    \ std::vector<Edge> prev;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u4E0A\u306E\u76F4\u524D\u306E\u8FBA (\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\
    \u9802\u70B9\u3067\u306F src == -1)\n        /**\n         * @brief \u59CB\u70B9\
    \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\
    \u306E\u30EA\u30B9\u30C8 (\u59CB\u70B9\u5074\u304B\u3089\u9806\u306B)\n      \
    \   * @note t \u304C\u59CB\u70B9\u304B\u672A\u5230\u9054\u306E\u9802\u70B9\u306A\
    \u3089\u7A7A\u3002\u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\
    \u9802\u70B9\u3067\u306F\u6700\u77ED\u8DEF\u304C\u5B9A\u307E\u3089\u306A\u3044\
    \ (assert \u3067\u843D\u3061\u308B)\n         */\n        std::vector<Edge> path(long\
    \ long t) const {\n            std::vector<Edge> res;\n            while (prev[t].src\
    \ != -1) {\n                res.push_back(prev[t]);\n                assert(res.size()\
    \ < prev.size() && \"path: negative cycle\");\n                t = prev[t].src;\n\
    \            }\n            std::reverse(res.begin(), res.end());\n          \
    \  return res;\n        }\n    };\n\n    long long n;                       //!<\
    \ \u9802\u70B9\u6570\n    long long m;                       //!< \u8FBA\u6570\
    \n    std::vector<std::vector<Edge>> g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\
    \u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0),\
    \ m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     * @param n \u9802\u70B9\u6570\n     */\n    explicit Graph(long long n)\
    \ : n(n), m(0), g(n) {}\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n\
    \    long long size() const { return n; }\n    /**\n     * @brief \u7121\u5411\
    \u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param\
    \ v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u3089\
    1\n     */\n    void add_edge(long long u, long long v, Cost w = 1) {\n      \
    \  assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v,\
    \ w, m});\n        g[v].push_back({v, u, w, m++});\n    }\n    /**\n     * @brief\
    \ \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\
    \n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\
    \u3057\u305F\u30891\n     */\n    void add_directed_edge(long long u, long long\
    \ v, Cost w = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n    \
    \    g[u].push_back({u, v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\
    \u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\
    \u3066\u8FFD\u52A0\u3059\u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param\
    \ padding \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted\
    \ \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\
    \u3057\u305F\u3089false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\
    \u8FFD\u52A0\u3055\u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n\
    \    void read(long long m, long long padding = -1, bool weighted = false, bool\
    \ directed = false) {\n        for (long long i = 0; i < m; i++) {\n         \
    \   long long u, v;\n            std::cin >> u >> v;\n            u += padding,\
    \ v += padding;\n            Cost c(1);\n            if (weighted)\n         \
    \       std::cin >> c;\n            if (directed)\n                add_directed_edge(u,\
    \ v, c);\n            else\n                add_edge(u, v, c);\n        }\n  \
    \  }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\
    \u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n   \
    \  * @return std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\
    \u30C8\n     */\n    std::vector<Edge>& operator[](long long v) {\n        return\
    \ g[v];\n    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\
    \u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\
    \u53F7\n     * @return const std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\
    \u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge>& operator[](long\
    \ long v) const {\n        return g[v];\n    }\n    /**\n     * @brief \u8FBA\u306E\
    \u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\u30EA\u30B9\u30C8\
    (id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\u4EE3\u8868\u3057\
    \u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (long long i\
    \ = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n    /**\n     *\
    \ @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param weighted 1\u4EE5\
    \u5916\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u5B58\u5728\u3059\u308B\u304B\
    \ \u7701\u7565\u3059\u308B\u3068true\n     * @param inf \u30B3\u30B9\u30C8\u306E\
    min\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\
    \u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath shortest_path(long\
    \ long s, bool weighted = true, Cost inf = std::numeric_limits<Cost>::max() /\
    \ 4) const {\n        assert(0 <= s && s < n);\n        if (weighted)\n      \
    \      return shortest_path_dijkstra(s, inf);\n        return shortest_path_bfs(s,\
    \ inf);\n    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\
    \n     * @param inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\
    \u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B\
    \ \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4 \u8CA0\u9589\
    \u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F -inf\n     * @return\
    \ ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\
    \u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\
    \u306E\u8FBA (prev)\n     */\n    ShortestPath bellman_ford(long long s, Cost\
    \ inf = std::numeric_limits<Cost>::max() / 4) const {\n        assert(0 <= s &&\
    \ s < n);\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        dist[s] = Cost{};\n\n        for (long long i = 1; i < n;\
    \ i++) {\n            bool changed = false;\n            for (long long j = 0;\
    \ j < n; j++)\n                for (const auto& e : g[j]) {\n                \
    \    if (dist[e.src] == inf)\n                        continue;\n            \
    \        if (dist[e.dst] > dist[e.src] + e.cost) {\n                        dist[e.dst]\
    \ = dist[e.src] + e.cost;\n                        if (dist[e.dst] < -inf)\n \
    \                           dist[e.dst] = -inf;\n                        prev[e.dst]\
    \ = e;\n                        changed = true;\n                    }\n     \
    \           }\n            if (!changed)\n                break;\n        }\n\
    \        for (long long i = 0; i < n; i++) {\n            bool changed = false;\n\
    \            for (long long j = 0; j < n; j++)\n                for (const auto&\
    \ e : g[j]) {\n                    if (dist[e.src] == inf)\n                 \
    \       continue;\n                    if (dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                        dist[e.dst] = -inf;\n                        prev[e.dst]\
    \ = e;\n                        changed = true;\n                    }\n     \
    \           }\n            if (!changed)\n                break;\n        }\n\
    \        return {dist, prev};\n    }\n    /**\n     * @brief \u8FBA\u306E\u30B3\
    \u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\u3001\
    \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF (01-BFS) O(n + m)\n     *\n     * @param s \u59CB\u70B9\n     * @param\
    \ inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\
    \u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n     * @return ShortestPath\
    \ \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\
    \ (prev)\n     */\n    ShortestPath shortest_path_01bfs(long long s, Cost inf\
    \ = std::numeric_limits<Cost>::max() / 4) const {\n        assert(0 <= s && s\
    \ < n);\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge> prev(n);\n\
    \        std::deque<long long> que;\n        dist[s] = 0;\n        que.push_back(s);\n\
    \        while (!que.empty()) {\n            long long u = que.front();\n    \
    \        que.pop_front();\n            for (auto& e : g[u]) {\n              \
    \  assert(e.cost == 0 || e.cost == 1);\n                if (dist[e.dst] == inf\
    \ || dist[e.dst] > dist[u] + e.cost) {\n                    dist[e.dst] = dist[u]\
    \ + e.cost;\n                    prev[e.dst] = e;\n                    if (e.cost\
    \ == 0)\n                        que.push_front(e.dst);\n                    else\n\
    \                        que.push_back(e.dst);\n                }\n          \
    \  }\n        }\n        return {dist, prev};\n    }\n    /**\n     * @brief \u5168\
    \u70B9\u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577 (Floyd-Warshall) O(n^3)\n   \
    \  *\n     * @param inf \u672A\u5230\u9054\u3092\u8868\u3059\u5024 \u7701\u7565\
    \u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n     * @return std::vector<std::vector<Cost>>\
    \ dist[i][j] \u304C i \u304B\u3089 j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\
    \u9054\u3067\u304D\u306A\u3051\u308C\u3070 inf)\n     * @note \u8CA0\u306E\u8FBA\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B\
    \ i \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n     */\n  \
    \  std::vector<std::vector<Cost>> floyd_warshall(Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n        for (long long i = 0; i < n; i++) dist[i][i] = Cost{};\n   \
    \     for (long long i = 0; i < n; i++) {\n            for (auto& e : g[i]) dist[i][e.dst]\
    \ = std::min(dist[i][e.dst], e.cost);\n        }\n        for (long long k = 0;\
    \ k < n; k++) {\n            for (long long i = 0; i < n; i++) {\n           \
    \     if (dist[i][k] == inf) continue;\n                for (long long j = 0;\
    \ j < n; j++) {\n                    if (dist[k][j] == inf) continue;\n      \
    \              dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n \
    \               }\n            }\n        }\n        return dist;\n    }\n\n \
    \  private:\n    ShortestPath shortest_path_bfs(long long s, Cost inf) const {\n\
    \        std::vector<Cost> dist(n, inf);\n        std::vector<Edge> prev(n);\n\
    \        std::queue<long long> que;\n        dist[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            long long u = que.front();\n    \
    \        que.pop();\n            for (auto& e : g[u]) {\n                if (dist[e.dst]\
    \ == inf) {\n                    dist[e.dst] = dist[e.src] + 1;\n            \
    \        prev[e.dst] = e;\n                    que.push(e.dst);\n            \
    \    }\n            }\n        }\n        return {dist, prev};\n    }\n    ShortestPath\
    \ shortest_path_dijkstra(long long s, Cost inf) const {\n        std::vector<Cost>\
    \ dist(n, inf);\n        std::vector<Edge> prev(n);\n        using Node = std::pair<Cost,\
    \ long long>;\n        std::priority_queue<Node, std::vector<Node>, std::greater<Node>>\
    \ que;\n        dist[s] = 0;\n        que.push({0, s});\n        while (!que.empty())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if (d > dist[u])\n                continue;\n            for (auto& e : g[u])\
    \ {\n                if (dist[e.dst] == inf || dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                    dist[e.dst] = dist[e.src] + e.cost;\n               \
    \     prev[e.dst] = e;\n                    que.push({dist[e.dst], e.dst});\n\
    \                }\n            }\n        }\n        return {dist, prev};\n \
    \   }\n};\n#line 2 \"src/graph/lowlink.hpp\"\n\n/**\n * @file lowlink.hpp\n *\
    \ @brief lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u5206\u89E3)\n */\n\n#line 11 \"src/graph/lowlink.hpp\"\n\n\
    #line 13 \"src/graph/lowlink.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\
    \u306E lowlink \u3092\u6C42\u3081\u3001\u95A2\u7BC0\u70B9\u30FB\u6A4B\u30FB\u4E8C\
    \u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\n *\n * DFS \u3092\
    \u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n + m)\n * \u591A\
    \u91CD\u8FBA\u3068\u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u3063\u3066\u3082\
    \u3088\u3044 (\u89AA\u3078\u623B\u308B\u8FBA\u306F\u9802\u70B9\u3067\u306F\u306A\
    \u304F\u8FBA\u306E\u756A\u53F7\u3067\u533A\u5225\u3059\u308B)\n * \u4F8B:\n *\
    \ LowLink ll(g);\n * ll.articulation_points(); ll.bridges(); ll.two_edge_connected_groups();\n\
    \ *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate\
    \ <typename Cost = int>\nclass LowLink {\n    long long n;\n    std::vector<bool>\
    \ art, bridge;\n    std::vector<long long> arts, bridge_ids;\n    std::vector<int>\
    \ comp;\n    std::vector<std::vector<long long>> groups;\n\n   public:\n    std::vector<long\
    \ long> ord;  //!< DFS \u3067\u8A2A\u308C\u305F\u9806\u756A\n    std::vector<long\
    \ long> low;  //!< DFS \u6728\u306E\u5B50\u5B6B\u304B\u3089\u3001\u6728\u306E\u8FBA\
    \u3092\u9006\u306B\u305F\u3069\u3089\u305A\u306B 1 \u672C\u306E\u5F8C\u9000\u8FBA\
    \u3067\u884C\u3051\u308B\u9802\u70B9\u306E ord \u306E\u6700\u5C0F\u5024\n\n  \
    \  explicit LowLink(const Graph<Cost>& graph) : n(graph.n), art(n), bridge(graph.m),\
    \ comp(n, -1), ord(n, -1), low(n) {\n        std::vector<int> parent(n, -1), parent_edge(n,\
    \ -1), iter(n, 0);\n        std::vector<long long> st;\n        long long k =\
    \ 0;\n        for (long long root = 0; root < n; root++) {\n            if (ord[root]\
    \ != -1) continue;\n            int root_children = 0;\n            ord[root]\
    \ = low[root] = k++;\n            st.push_back(root);\n            while (!st.empty())\
    \ {\n                long long v = st.back();\n                if (iter[v] < static_cast<int>(graph[v].size()))\
    \ {\n                    const auto& e = graph[v][iter[v]++];\n              \
    \      if (e.id == parent_edge[v]) continue;\n                    long long u\
    \ = e.dst;\n                    if (ord[u] == -1) {\n                        parent[u]\
    \ = v;\n                        parent_edge[u] = e.id;\n                     \
    \   ord[u] = low[u] = k++;\n                        st.push_back(u);\n       \
    \             } else {\n                        low[v] = std::min(low[v], ord[u]);\n\
    \                    }\n                    continue;\n                }\n   \
    \             st.pop_back();\n                if (v == root) continue;\n     \
    \           long long p = parent[v];\n                low[p] = std::min(low[p],\
    \ low[v]);\n                if (low[v] > ord[p]) bridge[parent_edge[v]] = true;\n\
    \                if (p == root)\n                    root_children++;\n      \
    \          else if (low[v] >= ord[p])\n                    art[p] = true;\n  \
    \          }\n            if (root_children >= 2) art[root] = true;\n        }\n\
    \        for (long long v = 0; v < n; v++) {\n            if (art[v]) arts.push_back(v);\n\
    \        }\n        for (long long id = 0; id < graph.m; id++) {\n           \
    \ if (bridge[id]) bridge_ids.push_back(id);\n        }\n        // \u6A4B\u3092\
    \u901A\u3089\u305A\u306B\u884C\u3051\u308B\u9802\u70B9\u3092\u307E\u3068\u3081\
    \u308B\n        for (long long s = 0; s < n; s++) {\n            if (comp[s] !=\
    \ -1) continue;\n            comp[s] = groups.size();\n            groups.push_back({s});\n\
    \            for (long long i = 0; i < static_cast<long long>(groups.back().size());\
    \ i++) {\n                long long v = groups.back()[i];\n                for\
    \ (const auto& e : graph[v]) {\n                    if (bridge[e.id] || comp[e.dst]\
    \ != -1) continue;\n                    comp[e.dst] = comp[s];\n             \
    \       groups.back().push_back(e.dst);\n                }\n            }\n  \
    \      }\n    }\n\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    long\
    \ long size() const { return n; }\n\n    /**\n     * @brief v \u304C\u95A2\u7BC0\
    \u70B9 (\u53D6\u308A\u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\
    \u308B\u9802\u70B9) \u304B\n     */\n    bool is_articulation_point(long long\
    \ v) const {\n        assert(0 <= v && v < n);\n        return art[v];\n    }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u6A4B (\u53D6\u308A\
    \u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u8FBA) \u304B\
    \n     */\n    bool is_bridge(long long id) const {\n        assert(0 <= id &&\
    \ id < static_cast<long long>(bridge.size()));\n        return bridge[id];\n \
    \   }\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<long\
    \ long>& articulation_points() const { return arts; }\n    /**\n     * @brief\
    \ \u6A4B\u306E\u8FBA\u306E\u756A\u53F7\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\
    \n     */\n    const std::vector<long long>& bridges() const { return bridge_ids;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7\n     */\n    long long two_edge_connected_group_id(long\
    \ long v) const {\n        assert(0 <= v && v < n);\n        return comp[v];\n\
    \    }\n    /**\n     * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (\u6A4B\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\u7D50\u6210\u5206\
    ) \u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_edge_connected_groups() const { return groups; }\n};\n#line 7 \"\
    test/yosupo/two-edge-connected-components.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    Graph<int> g(n);\n    g.read(m, 0);\n    LowLink ll(g);\n    const auto&\
    \ groups = ll.two_edge_connected_groups();\n    std::cout << groups.size() <<\
    \ '\\n';\n    for (const auto& group : groups) {\n        std::cout << group.size();\n\
    \        for (int v : group) std::cout << ' ' << v;\n        std::cout << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n\n#include \"../../src/graph/graph.hpp\"\n#include \"\
    ../../src/graph/lowlink.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n  \
    \  std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    Graph<int> g(n);\n    g.read(m, 0);\n    LowLink ll(g);\n    const auto&\
    \ groups = ll.two_edge_connected_groups();\n    std::cout << groups.size() <<\
    \ '\\n';\n    for (const auto& group : groups) {\n        std::cout << group.size();\n\
    \        for (int v : group) std::cout << ' ' << v;\n        std::cout << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - src/graph/graph.hpp
  - src/graph/lowlink.hpp
  isVerificationFile: true
  path: test/yosupo/two-edge-connected-components.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two-edge-connected-components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two-edge-connected-components.test.cpp
- /verify/test/yosupo/two-edge-connected-components.test.cpp.html
title: test/yosupo/two-edge-connected-components.test.cpp
---
