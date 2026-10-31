---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path.hpp
    title: "\u6700\u77ED\u8DEF"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/chinese-postman.test.cpp
    title: test/unittest/graph/chinese-postman.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C"
    links: []
  bundledCode: "#line 2 \"src/graph/chinese-postman.hpp\"\n\n/**\n * @file chinese-postman.hpp\n\
    \ * @brief \u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <optional>\n#include\
    \ <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n * @brief\
    \ \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\n#include <iostream>\n\
    #line 11 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\
    \u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\
    \u578B \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\
    \u672A\u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\
    \u3044\u3088\u3046\u306B)\n */\ntemplate <typename Cost = long long>\nclass Graph\
    \ {\n   public:\n    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\
    \n     *\n     * operator long long()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\
    \u306E\u3067\u3001\u6574\u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\
    \u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\
    \n     * for (auto& e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\
    \u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\u304C\u3001\n     * for (long\
    \ long dst : g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\
    \u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct\
    \ Edge {\n        long long src = -1;  //!< \u59CB\u70B9\n        long long dst\
    \ = -1;  //!< \u7D42\u70B9\n        Cost cost = {};      //!< \u30B3\u30B9\u30C8\
    \n        long long id = -1;   //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\
    \u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\
    \u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\
    \u3059\u308B)\n        Edge() = default;\n        Edge(long long src, long long\
    \ dst, Cost cost = 1, long long id = -1) : src(src), dst(dst), cost(cost), id(id)\
    \ {}\n        operator long long() const { return dst; }\n    };\n\n    long long\
    \ n;                       //!< \u9802\u70B9\u6570\n    long long m;         \
    \              //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>> g;  //!<\
    \ \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n\
    \     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n   \
    \  */\n    explicit Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n     *\
    \ @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return n; }\n\
    \    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n   \
    \  * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n     * @param w \u30B3\
    \u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n    void add_edge(long\
    \ long u, long long v, Cost w = 1) {\n        assert(0 <= u && u < n && 0 <= v\
    \ && v < n);\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_directed_edge(long long u, long long v, Cost w = 1) {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m++});\n\
    \    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\
    \u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n   \
    \  * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\u756A\u53F7\
    \u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B \u7701\
    \u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\u307F\u304C\
    \u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089false\u3068\
    \u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\u308C\u308B\
    \n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\
    \ \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(long long m, long\
    \ long padding = -1, bool weighted = false, bool directed = false) {\n       \
    \ for (long long i = 0; i < m; i++) {\n            long long u, v;\n         \
    \   std::cin >> u >> v;\n            u += padding, v += padding;\n           \
    \ Cost c(1);\n            if (weighted)\n                std::cin >> c;\n    \
    \        if (directed)\n                add_directed_edge(u, v, c);\n        \
    \    else\n                add_edge(u, v, c);\n        }\n    }\n    /**\n   \
    \  * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return std::vector<Edge>&\
    \ v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<Edge>&\
    \ operator[](long long v) {\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\
    \u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const std::vector<Edge>&\
    \ v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    const\
    \ std::vector<Edge>& operator[](long long v) const {\n        return g[v];\n \
    \   }\n    /**\n     * @brief \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge>\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\
    \u8FBA\u306F\u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\
    \u308B\u3002\u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\
    \u306A\u3044\n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\
    \u306E\u5411\u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n\
    \    std::vector<Edge> edges() const {\n        std::vector<Edge> res(m);\n  \
    \      for (long long i = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n\
    \                res[e.id] = e;\n            }\n        }\n        return res;\n\
    \    }\n};\n#line 2 \"src/graph/shortest-path.hpp\"\n\n/**\n * @file shortest-path.hpp\n\
    \ * @brief \u6700\u77ED\u8DEF\n */\n\n#line 10 \"src/graph/shortest-path.hpp\"\
    \n#include <deque>\n#include <functional>\n#line 14 \"src/graph/shortest-path.hpp\"\
    \n#include <queue>\n#include <utility>\n#line 17 \"src/graph/shortest-path.hpp\"\
    \n\n#line 19 \"src/graph/shortest-path.hpp\"\n\n/**\n * @brief \u6700\u77ED\u8DEF\
    \u306E\u7D50\u679C\n *\n * auto [dist, prev] = shortest_path(g, s); \u306E\u3088\
    \u3046\u306B\u53D7\u3051\u53D6\u308C\u308B\n */\ntemplate <typename Cost>\nstruct\
    \ ShortestPath {\n    using Edge = typename Graph<Cost>::Edge;\n    std::vector<Cost>\
    \ dist;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\n    std::vector<Edge>\
    \ prev;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\
    \u524D\u306E\u8FBA (\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3067\
    \u306F src == -1)\n    /**\n     * @brief \u59CB\u70B9\u304B\u3089 t \u3078\u306E\
    \u6700\u77ED\u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\
    \ (\u59CB\u70B9\u5074\u304B\u3089\u9806\u306B)\n     * @return std::optional<std::vector<Edge>>\
    \ t \u304C\u59CB\u70B9\u306A\u3089\u7A7A\u3001\u672A\u5230\u9054\u306A\u3089 std::nullopt\n\
    \     * @note \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u9802\
    \u70B9\u3067\u306F\u6700\u77ED\u8DEF\u304C\u5B9A\u307E\u3089\u306A\u3044 (assert\
    \ \u3067\u843D\u3061\u308B)\n     */\n    std::optional<std::vector<Edge>> path(long\
    \ long t) const {\n        // \u76F4\u524D\u306E\u8FBA\u304C\u306A\u3044\u306E\
    \u306F\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3002\u59CB\u70B9\
    \u306E\u8DDD\u96E2\u306F 0 \u3067\u3001\u672A\u5230\u9054\u306E\u8DDD\u96E2 inf\
    \ \u306F\u6B63\u306A\u306E\u3067\u533A\u5225\u3067\u304D\u308B\n        if (prev[t].src\
    \ == -1 && dist[t] != Cost{}) return std::nullopt;\n        std::vector<Edge>\
    \ res;\n        while (prev[t].src != -1) {\n            res.push_back(prev[t]);\n\
    \            assert(res.size() < prev.size() && \"path: negative cycle\");\n \
    \           t = prev[t].src;\n        }\n        std::reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n};\n\nnamespace internal_shortest_path {\n\ntemplate\
    \ <typename Cost>\nShortestPath<Cost> bfs(const Graph<Cost>& graph, long long\
    \ s, Cost inf) {\n    std::vector<Cost> dist(graph.n, inf);\n    std::vector<typename\
    \ Graph<Cost>::Edge> prev(graph.n);\n    std::queue<long long> que;\n    dist[s]\
    \ = 0;\n    que.push(s);\n    while (!que.empty()) {\n        long long u = que.front();\n\
    \        que.pop();\n        for (auto& e : graph[u]) {\n            if (dist[e.dst]\
    \ == inf) {\n                dist[e.dst] = dist[e.src] + 1;\n                prev[e.dst]\
    \ = e;\n                que.push(e.dst);\n            }\n        }\n    }\n  \
    \  return {dist, prev};\n}\n\ntemplate <typename Cost>\nShortestPath<Cost> dijkstra(const\
    \ Graph<Cost>& graph, long long s, Cost inf) {\n    std::vector<Cost> dist(graph.n,\
    \ inf);\n    std::vector<typename Graph<Cost>::Edge> prev(graph.n);\n    using\
    \ Node = std::pair<Cost, long long>;\n    std::priority_queue<Node, std::vector<Node>,\
    \ std::greater<Node>> que;\n    dist[s] = 0;\n    que.push({0, s});\n    while\
    \ (!que.empty()) {\n        auto [d, u] = que.top();\n        que.pop();\n   \
    \     if (d > dist[u])\n            continue;\n        for (auto& e : graph[u])\
    \ {\n            if (dist[e.dst] == inf || dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                dist[e.dst] = dist[e.src] + e.cost;\n                prev[e.dst]\
    \ = e;\n                que.push({dist[e.dst], e.dst});\n            }\n     \
    \   }\n    }\n    return {dist, prev};\n}\n\n}  // namespace internal_shortest_path\n\
    \n/**\n * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DEF\n *\n * @param s \u59CB\u70B9\n * @param weighted 1\u4EE5\u5916\
    \u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u5B58\u5728\u3059\u308B\u304B \u7701\
    \u7565\u3059\u308B\u3068true\n * @param inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\
    \u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306F\
    inf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n * @note weighted \u306A\u3089 Dijkstra\
    \ \u306A\u306E\u3067\u3001\u8CA0\u306E\u8FBA\u304C\u3042\u308B\u3068 assert \u3067\
    \u843D\u3061\u308B (\u8CA0\u306E\u8FBA\u304C\u3042\u308B\u306A\u3089 bellman_ford)\n\
    \ */\ntemplate <typename Cost = long long>\nShortestPath<Cost> shortest_path(const\
    \ Graph<Cost>& graph, long long s, bool weighted = true, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.n);\n    if (weighted) {\n        for\
    \ (long long v = 0; v < graph.n; v++) {\n            for (const auto& e : graph[v])\
    \ assert(!(e.cost < Cost{}) && \"shortest_path: negative edge (use bellman_ford)\"\
    );\n        }\n        return internal_shortest_path::dijkstra(graph, s, inf);\n\
    \    }\n    return internal_shortest_path::bfs(graph, s, inf);\n}\n\n/**\n * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\n *\n * @param s \u59CB\u70B9\n * @param inf \u30B3\u30B9\u30C8\u306Emin\u306E\
    \u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\
    \u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F\
    \ -inf\n * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost = long long>\n\
    ShortestPath<Cost> bellman_ford(const Graph<Cost>& graph, long long s, Cost inf\
    \ = std::numeric_limits<Cost>::max() / 4) {\n    assert(0 <= s && s < graph.n);\n\
    \    const long long n = graph.n;\n    std::vector<Cost> dist(n, inf);\n    std::vector<typename\
    \ Graph<Cost>::Edge> prev(n);\n    dist[s] = Cost{};\n\n    for (long long i =\
    \ 1; i < n; i++) {\n        bool changed = false;\n        for (long long j =\
    \ 0; j < n; j++)\n            for (const auto& e : graph[j]) {\n             \
    \   if (dist[e.src] == inf)\n                    continue;\n                if\
    \ (dist[e.dst] > dist[e.src] + e.cost) {\n                    dist[e.dst] = dist[e.src]\
    \ + e.cost;\n                    if (dist[e.dst] < -inf)\n                   \
    \     dist[e.dst] = -inf;\n                    prev[e.dst] = e;\n            \
    \        changed = true;\n                }\n            }\n        if (!changed)\n\
    \            break;\n    }\n    for (long long i = 0; i < n; i++) {\n        bool\
    \ changed = false;\n        for (long long j = 0; j < n; j++)\n            for\
    \ (const auto& e : graph[j]) {\n                if (dist[e.src] == inf)\n    \
    \                continue;\n                if (dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                    dist[e.dst] = -inf;\n                    prev[e.dst]\
    \ = e;\n                    changed = true;\n                }\n            }\n\
    \        if (!changed)\n            break;\n    }\n    return {dist, prev};\n\
    }\n\n/**\n * @brief \u8FBA\u306E\u30B3\u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\
    \u306E\u30B0\u30E9\u30D5\u3067\u3001\u3042\u308B\u9802\u70B9\u304B\u3089\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF (01-BFS) O(n + m)\n *\n * @param s\
    \ \u59CB\u70B9\n * @param inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2 \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() /\
    \ 4\n * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\
    \ (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\
    \u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost = long long>\nShortestPath<Cost>\
    \ shortest_path_01bfs(const Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.n);\n    std::vector<Cost> dist(graph.n,\
    \ inf);\n    std::vector<typename Graph<Cost>::Edge> prev(graph.n);\n    std::deque<long\
    \ long> que;\n    dist[s] = 0;\n    que.push_back(s);\n    while (!que.empty())\
    \ {\n        long long u = que.front();\n        que.pop_front();\n        for\
    \ (auto& e : graph[u]) {\n            assert(e.cost == 0 || e.cost == 1);\n  \
    \          if (dist[e.dst] == inf || dist[e.dst] > dist[u] + e.cost) {\n     \
    \           dist[e.dst] = dist[u] + e.cost;\n                prev[e.dst] = e;\n\
    \                if (e.cost == 0)\n                    que.push_front(e.dst);\n\
    \                else\n                    que.push_back(e.dst);\n           \
    \ }\n        }\n    }\n    return {dist, prev};\n}\n\n/**\n * @brief \u5168\u70B9\
    \u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577 (Floyd-Warshall) O(n^3)\n *\n * @param\
    \ inf \u672A\u5230\u9054\u3092\u8868\u3059\u5024 \u7701\u7565\u3059\u308B\u3068\
    \ std::numeric_limits<Cost>::max() / 4\n * @return std::vector<std::vector<Cost>>\
    \ dist[i][j] \u304C i \u304B\u3089 j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\
    \u9054\u3067\u304D\u306A\u3051\u308C\u3070 inf)\n * @note \u8CA0\u306E\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B i\
    \ \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n * \u8CA0\u9589\
    \u8DEF\u304C\u3042\u308B\u3068\u304D\u306E\u5024\u306F -inf \u4EE5\u4E0A\u306B\
    \u5207\u308A\u8A70\u3081\u308B\u306E\u3067\u3001\u3042\u3075\u308C\u306A\u3044\
    \ (\u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u7D44\u306E\u5024\
    \u306F\u6700\u77ED\u8DEF\u9577\u3067\u306F\u306A\u3044)\n */\ntemplate <typename\
    \ Cost = long long>\nstd::vector<std::vector<Cost>> floyd_warshall(const Graph<Cost>&\
    \ graph, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    const long long\
    \ n = graph.n;\n    std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n    for (long long i = 0; i < n; i++) dist[i][i] = Cost{};\n    for\
    \ (long long i = 0; i < n; i++) {\n        for (auto& e : graph[i]) dist[i][e.dst]\
    \ = std::min(dist[i][e.dst], e.cost);\n    }\n    for (long long k = 0; k < n;\
    \ k++) {\n        for (long long i = 0; i < n; i++) {\n            if (dist[i][k]\
    \ == inf) continue;\n            for (long long j = 0; j < n; j++) {\n       \
    \         if (dist[k][j] == inf) continue;\n                // dist \u306F -inf\
    \ \u4EE5\u4E0A inf \u4EE5\u4E0B\u306A\u306E\u3067\u3001\u548C\u306F -2 inf \u4EE5\
    \u4E0A\u3067\u3042\u3075\u308C\u306A\u3044\n                Cost d = dist[i][k]\
    \ + dist[k][j];\n                if (d < -inf) d = -inf;\n                if (d\
    \ < dist[i][j]) dist[i][j] = d;\n            }\n        }\n    }\n    return dist;\n\
    }\n#line 16 \"src/graph/chinese-postman.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u3067\u3001\u3059\u3079\u3066\u306E\u8FBA\u3092 1 \u56DE\u4EE5\u4E0A\
    \u901A\u3063\u3066\u59CB\u70B9\u306B\u623B\u308B\u9589\u8DEF\u306E\u9577\u3055\
    \u306E\u6700\u5C0F\u5024 (\u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C\
    )\n *\n * \u6B21\u6570\u304C\u5947\u6570\u306E\u9802\u70B9 (k \u500B) \u3092 2\
    \ \u500B\u305A\u3064\u7D44\u306B\u3057\u3066\u3001\u7D44\u306E\u9593\u306E\u6700\
    \u77ED\u8DEF\u3092\u4F59\u5206\u306B\u901A\u308C\u3070\u3088\u3044\u3002\n * \u5947\
    \u6570\u6B21\u6570\u306E\u9802\u70B9\u3054\u3068\u306B Dijkstra \u6CD5\u3067\u8DDD\
    \u96E2\u3092\u6C42\u3081\u3001\u7D44\u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u3092 bit DP \u3067\u6C42\u3081\u308B\u3002O(k m log m + 2^k k)\n * \u59CB\
    \u70B9\u306F\u3069\u3053\u3067\u3082\u3088\u3044 (\u8FBA\u3092\u6301\u3064\u9802\
    \u70B9\u306E\u3069\u308C\u304B\u3089\u59CB\u3081\u3066\u3082\u540C\u3058\u9577\
    \u3055\u306B\u306A\u308B)\n * @param inf \u5230\u9054\u3067\u304D\u306A\u3044\u3053\
    \u3068\u3092\u8868\u3059\u5024 \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n * @return std::optional<Cost> \u8FBA\u304C\u3059\u3079\u3066 1 \u3064\u306E\
    \u9023\u7D50\u6210\u5206\u306B\u5165\u3063\u3066\u3044\u306A\u3051\u308C\u3070\
    \ std::nullopt\u3002\u8FBA\u304C\u306A\u3051\u308C\u3070 0\n * @note \u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306F 0 \u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3002k \u306F\
    \ 20 \u7A0B\u5EA6\u307E\u3067\u3002\u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u591A\u91CD\
    \u8FBA\u304C\u3042\u3063\u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost\
    \ = long long>\nstd::optional<Cost> chinese_postman(const Graph<Cost>& graph,\
    \ Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    const long long n =\
    \ graph.n;\n    Cost total{};\n    for (const auto& e : graph.edges()) {\n   \
    \     assert(e.cost >= Cost{});\n        total += e.cost;\n    }\n    std::vector<long\
    \ long> odd;\n    long long some = -1;  // \u8FBA\u3092\u6301\u3064\u9802\u70B9\
    \u306E 1 \u3064\n    for (long long v = 0; v < n; v++) {\n        if (!graph[v].empty())\
    \ some = v;\n        // \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u96A3\u63A5\u30EA\
    \u30B9\u30C8\u306B 2 \u56DE\u5165\u308B\u306E\u3067\u3001\u6B21\u6570\u306B 2\
    \ \u3068\u6570\u3048\u3089\u308C\u308B\n        if (graph[v].size() % 2 == 1)\
    \ odd.push_back(v);\n    }\n    if (some == -1) return Cost{};\n    // \u8FBA\u3092\
    \u6301\u3064\u9802\u70B9\u304C\u3059\u3079\u3066\u9023\u7D50\u304B\n    std::vector<Cost>\
    \ d = shortest_path(graph, some, true, inf).dist;\n    for (long long v = 0; v\
    \ < n; v++) {\n        if (!graph[v].empty() && d[v] == inf) return std::nullopt;\n\
    \    }\n    const int k = static_cast<int>(odd.size());\n    assert(k < 31);\n\
    \    std::vector<std::vector<Cost>> dist(k);\n    for (int i = 0; i < k; i++)\
    \ {\n        std::vector<Cost> di = shortest_path(graph, odd[i], true, inf).dist;\n\
    \        for (int j = 0; j < k; j++) dist[i].push_back(di[odd[j]]);\n    }\n \
    \   // dp[S]: \u5947\u6570\u6B21\u6570\u306E\u9802\u70B9\u306E\u96C6\u5408 S \u3092\
    \u7D44\u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\u3002S \u306E\u6700\u5C0F\
    \u306E\u9802\u70B9\u306E\u76F8\u624B\u3092\u6C7A\u3081\u308B\n    std::vector<Cost>\
    \ dp(1 << k, inf);\n    dp[0] = Cost{};\n    for (int S = 1; S < (1 << k); S++)\
    \ {\n        if (__builtin_popcount(S) % 2 == 1) continue;\n        int i = __builtin_ctz(S);\n\
    \        for (int j = i + 1; j < k; j++) {\n            if (!(S >> j & 1)) continue;\n\
    \            int T = S ^ (1 << i) ^ (1 << j);\n            if (dp[T] != inf) dp[S]\
    \ = std::min(dp[S], dp[T] + dist[i][j]);\n        }\n    }\n    return total +\
    \ dp[(1 << k) - 1];\n}\n"
  code: "#pragma once\n\n/**\n * @file chinese-postman.hpp\n * @brief \u4E2D\u56FD\
    \u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <optional>\n#include <vector>\n\n#include\
    \ \"graph.hpp\"\n#include \"shortest-path.hpp\"\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u3067\u3001\u3059\u3079\u3066\u306E\u8FBA\u3092 1 \u56DE\u4EE5\
    \u4E0A\u901A\u3063\u3066\u59CB\u70B9\u306B\u623B\u308B\u9589\u8DEF\u306E\u9577\
    \u3055\u306E\u6700\u5C0F\u5024 (\u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\
    \u984C)\n *\n * \u6B21\u6570\u304C\u5947\u6570\u306E\u9802\u70B9 (k \u500B) \u3092\
    \ 2 \u500B\u305A\u3064\u7D44\u306B\u3057\u3066\u3001\u7D44\u306E\u9593\u306E\u6700\
    \u77ED\u8DEF\u3092\u4F59\u5206\u306B\u901A\u308C\u3070\u3088\u3044\u3002\n * \u5947\
    \u6570\u6B21\u6570\u306E\u9802\u70B9\u3054\u3068\u306B Dijkstra \u6CD5\u3067\u8DDD\
    \u96E2\u3092\u6C42\u3081\u3001\u7D44\u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\
    \u30C8\u3092 bit DP \u3067\u6C42\u3081\u308B\u3002O(k m log m + 2^k k)\n * \u59CB\
    \u70B9\u306F\u3069\u3053\u3067\u3082\u3088\u3044 (\u8FBA\u3092\u6301\u3064\u9802\
    \u70B9\u306E\u3069\u308C\u304B\u3089\u59CB\u3081\u3066\u3082\u540C\u3058\u9577\
    \u3055\u306B\u306A\u308B)\n * @param inf \u5230\u9054\u3067\u304D\u306A\u3044\u3053\
    \u3068\u3092\u8868\u3059\u5024 \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n * @return std::optional<Cost> \u8FBA\u304C\u3059\u3079\u3066 1 \u3064\u306E\
    \u9023\u7D50\u6210\u5206\u306B\u5165\u3063\u3066\u3044\u306A\u3051\u308C\u3070\
    \ std::nullopt\u3002\u8FBA\u304C\u306A\u3051\u308C\u3070 0\n * @note \u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306F 0 \u4EE5\u4E0A\u3067\u3042\u308B\u3053\u3068\u3002k \u306F\
    \ 20 \u7A0B\u5EA6\u307E\u3067\u3002\u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u591A\u91CD\
    \u8FBA\u304C\u3042\u3063\u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost\
    \ = long long>\nstd::optional<Cost> chinese_postman(const Graph<Cost>& graph,\
    \ Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    const long long n =\
    \ graph.n;\n    Cost total{};\n    for (const auto& e : graph.edges()) {\n   \
    \     assert(e.cost >= Cost{});\n        total += e.cost;\n    }\n    std::vector<long\
    \ long> odd;\n    long long some = -1;  // \u8FBA\u3092\u6301\u3064\u9802\u70B9\
    \u306E 1 \u3064\n    for (long long v = 0; v < n; v++) {\n        if (!graph[v].empty())\
    \ some = v;\n        // \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u96A3\u63A5\u30EA\
    \u30B9\u30C8\u306B 2 \u56DE\u5165\u308B\u306E\u3067\u3001\u6B21\u6570\u306B 2\
    \ \u3068\u6570\u3048\u3089\u308C\u308B\n        if (graph[v].size() % 2 == 1)\
    \ odd.push_back(v);\n    }\n    if (some == -1) return Cost{};\n    // \u8FBA\u3092\
    \u6301\u3064\u9802\u70B9\u304C\u3059\u3079\u3066\u9023\u7D50\u304B\n    std::vector<Cost>\
    \ d = shortest_path(graph, some, true, inf).dist;\n    for (long long v = 0; v\
    \ < n; v++) {\n        if (!graph[v].empty() && d[v] == inf) return std::nullopt;\n\
    \    }\n    const int k = static_cast<int>(odd.size());\n    assert(k < 31);\n\
    \    std::vector<std::vector<Cost>> dist(k);\n    for (int i = 0; i < k; i++)\
    \ {\n        std::vector<Cost> di = shortest_path(graph, odd[i], true, inf).dist;\n\
    \        for (int j = 0; j < k; j++) dist[i].push_back(di[odd[j]]);\n    }\n \
    \   // dp[S]: \u5947\u6570\u6B21\u6570\u306E\u9802\u70B9\u306E\u96C6\u5408 S \u3092\
    \u7D44\u306B\u3059\u308B\u6700\u5C0F\u30B3\u30B9\u30C8\u3002S \u306E\u6700\u5C0F\
    \u306E\u9802\u70B9\u306E\u76F8\u624B\u3092\u6C7A\u3081\u308B\n    std::vector<Cost>\
    \ dp(1 << k, inf);\n    dp[0] = Cost{};\n    for (int S = 1; S < (1 << k); S++)\
    \ {\n        if (__builtin_popcount(S) % 2 == 1) continue;\n        int i = __builtin_ctz(S);\n\
    \        for (int j = i + 1; j < k; j++) {\n            if (!(S >> j & 1)) continue;\n\
    \            int T = S ^ (1 << i) ^ (1 << j);\n            if (dp[T] != inf) dp[S]\
    \ = std::min(dp[S], dp[T] + dist[i][j]);\n        }\n    }\n    return total +\
    \ dp[(1 << k) - 1];\n}\n"
  dependsOn:
  - src/graph/graph.hpp
  - src/graph/shortest-path.hpp
  isVerificationFile: false
  path: src/graph/chinese-postman.hpp
  requiredBy: []
  timestamp: '2026-10-31 18:12:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/chinese-postman.test.cpp
documentation_of: src/graph/chinese-postman.hpp
layout: document
title: "\u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C"
---

無向グラフ [グラフ](graph.hpp) `Graph<Cost>` で、すべての辺を 1 回以上通って始点に戻る閉路の長さの最小値を求めます (中国人郵便配達問題)。

```cpp
Graph<long long> g(n);
g.read(m, -1, true);             // 1-indexed、重み付きの無向辺を m 本読む
auto len = chinese_postman(g);   // 辺が 1 つの連結成分に入っていなければ std::nullopt
```

すべての頂点の次数が偶数ならオイラー閉路があるので、答えは辺の重みの総和です。次数が奇数の頂点が $k$ 個あるときは、それらを 2 個ずつ組にして、組の間の最短路を余分に通ります。奇数次数の頂点ごとに Dijkstra 法で距離を求め、組にする最小コストを bit DP で求めるので、$k$ は 20 程度までにしてください。

始点はどこでもかまいません (辺を持つ頂点のどれから始めても、最小の長さは同じです)。辺を持たない頂点は無視します。辺のコストは 0 以上で、自己ループ・多重辺があってもかまいません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chinese_postman(g, inf = max / 4)` | すべての辺を 1 回以上通る閉路の長さの最小値 (`std::optional<Cost>`)。辺がすべて 1 つの連結成分に入っていなければ `std::nullopt`、辺がなければ 0 | $O(k m \log m + 2^k k)$ |

## 関連

- 閉路そのもの (辺の列) が欲しいときは、組にした頂点の間の最短路の辺を足したグラフで [オイラー路](eulerian-trail.hpp) を求める
- 最短路は [最短路](shortest-path.hpp)
