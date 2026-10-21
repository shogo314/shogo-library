---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
  - icon: ':heavy_check_mark:'
    path: src/graph/lowlink.hpp
    title: "lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\u7D50\
      \u6210\u5206\u5206\u89E3\u3001\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\
      \u5206\u89E3\u3001Block-Cut Tree)"
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path.hpp
    title: "\u6700\u77ED\u8DEF"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
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
  bundledCode: "#line 1 \"test/unittest/graph/lowlink.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ LowLink \u3092\u3001\u9802\u70B9\u3084\u8FBA\u3092 1 \u3064\u53D6\u308A\u9664\
    \u3044\u3066\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u6570\u3048\u308B\u611A\
    \u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\
    \n// \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306F\u3001\u5358\u7D14\u9589\
    \u8DEF\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u3066\u540C\u3058\u9589\u8DEF\
    \u306B\u4E57\u308B\u8FBA\u3092\u307E\u3068\u3081\u308B\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/lowlink.hpp\"\n\n/**\n * @file\
    \ lowlink.hpp\n * @brief lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\
    \u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u3001\u4E8C\u91CD\u9802\u70B9\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\u3001Block-Cut Tree)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n\
    \ * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\
    \n#include <iostream>\n#line 11 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\
    \u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\nclass Graph\
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
    \u308B\n     */\n    std::vector<Edge> edges() const {\n        std::vector<Edge>\
    \ res(m);\n        for (long long i = 0; i < n; i++) {\n            for (auto&\
    \ e : g[i]) {\n                res[e.id] = e;\n            }\n        }\n    \
    \    return res;\n    }\n};\n#line 2 \"src/graph/tree.hpp\"\n\n/**\n * @file tree.hpp\n\
    \ * @brief \u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\
    \n#line 10 \"src/graph/tree.hpp\"\n#include <stack>\n#include <type_traits>\n\
    #include <utility>\n#line 14 \"src/graph/tree.hpp\"\n\n#line 2 \"src/graph/shortest-path.hpp\"\
    \n\n/**\n * @file shortest-path.hpp\n * @brief \u6700\u77ED\u8DEF\n */\n\n#line\
    \ 10 \"src/graph/shortest-path.hpp\"\n#include <deque>\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#line 16 \"src/graph/shortest-path.hpp\"\n\
    \n#line 18 \"src/graph/shortest-path.hpp\"\n\n/**\n * @brief \u6700\u77ED\u8DEF\
    \u306E\u7D50\u679C\n *\n * auto [dist, prev] = shortest_path(g, s); \u306E\u3088\
    \u3046\u306B\u53D7\u3051\u53D6\u308C\u308B\n */\ntemplate <typename Cost>\nstruct\
    \ ShortestPath {\n    using Edge = typename Graph<Cost>::Edge;\n    std::vector<Cost>\
    \ dist;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\n    std::vector<Edge>\
    \ prev;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\
    \u524D\u306E\u8FBA (\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3067\
    \u306F src == -1)\n    /**\n     * @brief \u59CB\u70B9\u304B\u3089 t \u3078\u306E\
    \u6700\u77ED\u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\
    \ (\u59CB\u70B9\u5074\u304B\u3089\u9806\u306B)\n     * @note t \u304C\u59CB\u70B9\
    \u304B\u672A\u5230\u9054\u306E\u9802\u70B9\u306A\u3089\u7A7A\u3002\u8CA0\u9589\
    \u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u9802\u70B9\u3067\u306F\u6700\
    \u77ED\u8DEF\u304C\u5B9A\u307E\u3089\u306A\u3044 (assert \u3067\u843D\u3061\u308B\
    )\n     */\n    std::vector<Edge> path(long long t) const {\n        std::vector<Edge>\
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
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost = int>\nShortestPath<Cost>\
    \ shortest_path(const Graph<Cost>& graph, long long s, bool weighted = true, Cost\
    \ inf = std::numeric_limits<Cost>::max() / 4) {\n    assert(0 <= s && s < graph.n);\n\
    \    if (weighted)\n        return internal_shortest_path::dijkstra(graph, s,\
    \ inf);\n    return internal_shortest_path::bfs(graph, s, inf);\n}\n\n/**\n *\
    \ @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\n *\n * @param s \u59CB\u70B9\n * @param inf \u30B3\u30B9\u30C8\u306E\
    min\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\
    \u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F\
    \ -inf\n * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost = int>\nShortestPath<Cost>\
    \ bellman_ford(const Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    assert(0 <= s && s < graph.n);\n    const long long n = graph.n;\n\
    \    std::vector<Cost> dist(n, inf);\n    std::vector<typename Graph<Cost>::Edge>\
    \ prev(n);\n    dist[s] = Cost{};\n\n    for (long long i = 1; i < n; i++) {\n\
    \        bool changed = false;\n        for (long long j = 0; j < n; j++)\n  \
    \          for (const auto& e : graph[j]) {\n                if (dist[e.src] ==\
    \ inf)\n                    continue;\n                if (dist[e.dst] > dist[e.src]\
    \ + e.cost) {\n                    dist[e.dst] = dist[e.src] + e.cost;\n     \
    \               if (dist[e.dst] < -inf)\n                        dist[e.dst] =\
    \ -inf;\n                    prev[e.dst] = e;\n                    changed = true;\n\
    \                }\n            }\n        if (!changed)\n            break;\n\
    \    }\n    for (long long i = 0; i < n; i++) {\n        bool changed = false;\n\
    \        for (long long j = 0; j < n; j++)\n            for (const auto& e : graph[j])\
    \ {\n                if (dist[e.src] == inf)\n                    continue;\n\
    \                if (dist[e.dst] > dist[e.src] + e.cost) {\n                 \
    \   dist[e.dst] = -inf;\n                    prev[e.dst] = e;\n              \
    \      changed = true;\n                }\n            }\n        if (!changed)\n\
    \            break;\n    }\n    return {dist, prev};\n}\n\n/**\n * @brief \u8FBA\
    \u306E\u30B3\u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\
    \u3067\u3001\u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DEF (01-BFS) O(n + m)\n *\n * @param s \u59CB\u70B9\n * @param\
    \ inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\
    \u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4\n * @return ShortestPath\
    \ \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\
    \ (prev)\n */\ntemplate <typename Cost = int>\nShortestPath<Cost> shortest_path_01bfs(const\
    \ Graph<Cost>& graph, long long s, Cost inf = std::numeric_limits<Cost>::max()\
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
    \ \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n */\ntemplate\
    \ <typename Cost = int>\nstd::vector<std::vector<Cost>> floyd_warshall(const Graph<Cost>&\
    \ graph, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    const long long\
    \ n = graph.n;\n    std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n    for (long long i = 0; i < n; i++) dist[i][i] = Cost{};\n    for\
    \ (long long i = 0; i < n; i++) {\n        for (auto& e : graph[i]) dist[i][e.dst]\
    \ = std::min(dist[i][e.dst], e.cost);\n    }\n    for (long long k = 0; k < n;\
    \ k++) {\n        for (long long i = 0; i < n; i++) {\n            if (dist[i][k]\
    \ == inf) continue;\n            for (long long j = 0; j < n; j++) {\n       \
    \         if (dist[k][j] == inf) continue;\n                dist[i][j] = std::min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n            }\n        }\n    }\n    return dist;\n\
    }\n#line 17 \"src/graph/tree.hpp\"\n\ntemplate <typename>\nclass RootedTree;\n\
    template <typename>\nclass DoublingClimbTree;\n\n/**\n * @brief \u6839\u306A\u3057\
    \u6728\n *\n * @tparam Cost = int \u8FBA\u306E\u91CD\u307F\n *\n * Graph<Cost>\u3092\
    \u7D99\u627F\u3057\u3001\u3059\u3079\u3066\u7121\u5411\u8FBA\u3067\u8868\u3059\
    \n */\ntemplate <typename Cost = int>\nstruct Tree : private Graph<Cost> {\n \
    \   // Graph<Cost>* g = new Tree<Cost>(); \u304C\u3067\u304D\u3066\u3057\u307E\
    \u3046\u3068\u3001delete\u6642\u306B\u30E1\u30E2\u30EA\u30EA\u30FC\u30AF\u304C\
    \u767A\u751F\n    // \u56DE\u907F\u3059\u308B\u305F\u3081private\u7D99\u627F\u306B\
    \u3057\u3066\u3001\u30E1\u30F3\u30D0\u3092\u3059\u3079\u3066using\u5BA3\u8A00\n\
    \    using Edge = typename Graph<Cost>::Edge;\n    using Graph<Cost>::n;\n   \
    \ using Graph<Cost>::size;\n    using Graph<Cost>::m;\n    using Graph<Cost>::g;\n\
    \    using Graph<Cost>::Graph;\n    using Graph<Cost>::add_edge;\n    using Graph<Cost>::add_directed_edge;\n\
    \    using Graph<Cost>::operator[];\n    using Graph<Cost>::edges;\n\n    /**\n\
    \     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param\
    \ n \u30CE\u30FC\u30C9\u6570\n     */\n    explicit Tree(long long n = 0) : Graph<Cost>(n)\
    \ {}\n\n    /**\n     * @brief Graph \u3068\u3057\u3066\u898B\u308B\n     *\n\
    \     * Graph \u3092\u53D7\u3051\u53D6\u308B\u95A2\u6570 (shortest_path \u306A\
    \u3069) \u306B\u6E21\u3059\u3068\u304D\u306B\u4F7F\u3046\n     * @return const\
    \ Graph<Cost>& \u3053\u306E\u6728\u3092\u8868\u3059\u30B0\u30E9\u30D5\n     */\n\
    \    const Graph<Cost>& graph() const { return *this; }\n\n    /**\n     * @brief\
    \ \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\
    \u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param padding  = -1 \u9802\
    \u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\
    \u3059\u304B\n     * @param weighted = false \u8FBA\u306E\u91CD\u307F\u304C\u5165\
    \u529B\u3055\u308C\u308B\u304B\n     */\n    void read(long long padding = -1,\
    \ bool weighted = false) {\n        Graph<Cost>::read(this->n - 1, padding, weighted,\
    \ false);\n    }\n\n    /**\n     * @brief \u6728\u306E\u76F4\u5F84\n     *\n\
    \     * @param weighted = true \u91CD\u307F\u4ED8\u304D\u304B\n     * @return\
    \ std::vector<Edge> \u76F4\u5F84\u3092\u69CB\u6210\u3059\u308B\u8FBA\u306E\u30EA\
    \u30B9\u30C8\n     */\n    std::vector<Edge> diameter(bool weighted = true) const\
    \ {\n        std::vector<Cost> dist = shortest_path(graph(), 0, weighted).dist;\n\
    \        long long u = std::max_element(dist.begin(), dist.end()) - dist.begin();\n\
    \        auto sp = shortest_path(graph(), u, weighted);\n        long long v =\
    \ std::max_element(sp.dist.begin(), sp.dist.end()) - sp.dist.begin();\n      \
    \  return sp.path(v);\n    }\n\n    /**\n     * @brief \u6839\u4ED8\u304D\u6728\
    \u306B\u3059\u308B\n     *\n     * @param root \u6839\n     * @return RootedTree<Cost>\
    \ \u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n\
    \    [[nodiscard]]\n    RootedTree<Cost> set_root(long long root) const& {\n \
    \       return RootedTree<Cost>(*this, root);\n    }\n    /**\n     * @brief \u6839\
    \u4ED8\u304D\u6728\u306B\u3057\u3066\u8FD4\u3059\n     *\n     * @param root \u6839\
    \n     * @return RootedTree<Cost> \u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\
    \u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    RootedTree<Cost> set_root(long\
    \ long root) && {\n        return RootedTree<Cost>(std::move(*this), root);\n\
    \    }\n\n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\
    \u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u8FD4\u3059\n     *\n     * @param\
    \ root \u6839\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca(long\
    \ long root) const& {\n        RootedTree rooted_tree(*this, root);\n        return\
    \ DoublingClimbTree<Cost>(std::move(rooted_tree));\n    }\n    /**\n     * @brief\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\
    \u3092\u8FD4\u3059\n     *\n     * @param root \u6839\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca(long long root) && {\n        RootedTree rooted_tree(std::move(*this),\
    \ root);\n        return DoublingClimbTree<Cost>(std::move(rooted_tree));\n  \
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\n *\n * @tparam Cost = int\
    \ \u8FBA\u306E\u30B3\u30B9\u30C8\n */\ntemplate <typename Cost = int>\nclass RootedTree\
    \ : private Tree<Cost> {\n   public:\n    using Edge = typename Tree<Cost>::Edge;\n\
    \    using Tree<Cost>::n;\n    using Tree<Cost>::size;\n    using Tree<Cost>::m;\n\
    \    using Tree<Cost>::g;\n    using Tree<Cost>::operator[];\n    using Tree<Cost>::edges;\n\
    \    using Tree<Cost>::graph;\n\n    long long root;                         \
    \                  //!< \u6839\n    std::vector<Edge> par;                   \
    \                 //!< \u89AA\u3078\u5411\u304B\u3046\u8FBA\n    std::vector<std::vector<Edge>>\
    \ child;                     //!< \u5B50\u3078\u5411\u304B\u3046\u8FBA\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<Cost> depth;                                  //!<\
    \ \u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> height;        \
    \                         //!< \u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> unweighted_depth;                  //!<\
    \ \u91CD\u307F\u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long\
    \ long> unweighted_height;                 //!< \u91CD\u307F\u306A\u3057\u306E\
    \u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long\
    \ long> sz;                                //!< \u90E8\u5206\u6728\u306E\u9802\
    \u70B9\u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> preorder;   \
    \                       //!< \u5148\u884C\u9806\u5DE1\u56DE\n    std::vector<long\
    \ long> postorder;                         //!< \u5F8C\u884C\u9806\u5DE1\u56DE\
    \n    std::vector<std::pair<long long, long long>> euler_tour;  //!< \u30AA\u30A4\
    \u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\u3063\u305F\u9802\u70B9\
    \u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\u3092\u901A\u3063\u305F\
    \u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n    RootedTree() = delete;\n\n    /**\n\
    \     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\
    \u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\u53F7\
    \u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\u70B9\
    0\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * @param\
    \ padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\u305A\
    \u3089\u3059\u304B\n     */\n    template <typename T = long long>\n    explicit\
    \ RootedTree(const std::vector<T>& par_, long long padding = -1) : Tree<Cost>(par_.size()\
    \ + 1), root(0) {\n        static_assert(std::is_integral_v<T>, \"RootedTree:\
    \ par_ must be a vector of integers\");\n        for (long long i = 0; i < static_cast<long\
    \ long>(par_.size()); i++) {\n            this->add_edge(i + 1, par_[i] + padding);\n\
    \        }\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\
    \u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree \u9802\u70B9\
    \u65701\u4EE5\u4E0A\n     * @param root \u6839\n     */\n    RootedTree(const\
    \ Tree<Cost>& tree, long long root) : Tree<Cost>(tree), root(root) {\n       \
    \ build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\
    \u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30E0\
    \u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\n  \
    \   */\n    RootedTree(Tree<Cost>&& tree, long long root) : Tree<Cost>(std::move(tree)),\
    \ root(root) {\n        build();\n    }\n\n    /**\n     * @brief \u30C0\u30D6\
    \u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\u304D\u6728\u3092\u5F97\
    \u308B\n     *\n     * @return DoublingClimbTree<Cost> \u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost> build_lca() const&\
    \ {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\n    /**\n     *\
    \ @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\u6839\u4ED8\
    \u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() && {\n        return DoublingClimbTree<Cost>(std::move(*this));\n\
    \    }\n\n   private:\n    void build() {\n        long long n = this->n;\n  \
    \      assert(n > 0);\n        assert(0 <= root && root < n);\n        par.resize(n);\n\
    \        par[root] = {root, -1, 0, -1};\n        child.resize(n);\n        depth.resize(n);\n\
    \        unweighted_depth.resize(n);\n        height.resize(n);\n        unweighted_height.resize(n);\n\
    \        sz.resize(n);\n        std::vector<int> iter(n);\n        std::stack<std::pair<int,\
    \ int>> stk;\n        stk.emplace(root, 0);\n        while (!stk.empty()) {\n\
    \            auto [u, cnt] = stk.top();\n            stk.pop();\n            euler_tour.emplace_back(u,\
    \ cnt);\n            if (iter[u] == 0) preorder.push_back(u);\n            while\
    \ (iter[u] < static_cast<int>(this->g[u].size()) && this->g[u][iter[u]].dst ==\
    \ par[u]) iter[u]++;\n            if (iter[u] == static_cast<int>(this->g[u].size()))\
    \ {\n                postorder.push_back(u);\n                sz[u] = 1;\n   \
    \             height[u] = 0;\n                unweighted_height[u] = 0;\n    \
    \            for (auto& e : child[u]) {\n                    sz[u] += sz[e.dst];\n\
    \                    if (height[u] < height[e.dst] + e.cost) {\n             \
    \           height[u] = height[e.dst] + e.cost;\n                    }\n     \
    \               if (unweighted_height[u] < unweighted_height[e.dst] + 1) {\n \
    \                       unweighted_height[u] = unweighted_height[e.dst] + 1;\n\
    \                    }\n                }\n            } else {\n            \
    \    auto& e = this->g[u][iter[u]++];\n                par[e.dst] = {e.dst, u,\
    \ e.cost, e.id};\n                child[u].push_back(e);\n                depth[e.dst]\
    \ = depth[u] + e.cost;\n                unweighted_depth[e.dst] = unweighted_depth[u]\
    \ + 1;\n                stk.emplace(u, cnt + 1);\n                stk.emplace(e.dst,\
    \ 0);\n            }\n        }\n    }\n};\n\n/**\n * @brief \u89AA\u9802\u70B9\
    \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\n *\n * @tparam\
    \ Cost = int \u8FBA\u306E\u91CD\u307F(\u6CE8: hop\u3067\u306F\u6839\u306E\u91CD\
    \u307F\u306F\u8003\u3048\u306A\u3044)\n */\ntemplate <typename Cost = int>\nclass\
    \ DoublingClimbTree : private RootedTree<Cost> {\n   public:\n    using Edge =\
    \ typename RootedTree<Cost>::Edge;\n    using RootedTree<Cost>::n;\n    using\
    \ RootedTree<Cost>::size;\n    using RootedTree<Cost>::m;\n    using RootedTree<Cost>::g;\n\
    \    using RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n\
    \    using RootedTree<Cost>::graph;\n    using RootedTree<Cost>::root;\n    using\
    \ RootedTree<Cost>::par;\n    using RootedTree<Cost>::child;\n    using RootedTree<Cost>::depth;\n\
    \    using RootedTree<Cost>::height;\n    using RootedTree<Cost>::unweighted_depth;\n\
    \    using RootedTree<Cost>::unweighted_height;\n    using RootedTree<Cost>::sz;\n\
    \    using RootedTree<Cost>::preorder;\n    using RootedTree<Cost>::postorder;\n\
    \    using RootedTree<Cost>::euler_tour;\n\n    long long h;                 \
    \                      //!< \u30C0\u30D6\u30EA\u30F3\u30B0\u306E\u56DE\u6570\n\
    \    std::vector<std::vector<long long>> doubling_par;  //!< j\u304B\u3089(1<<i)\u9802\
    \u70B9\u767B\u3063\u305F\u9802\u70B9(\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\
    \u306F-1)\n\n    DoublingClimbTree() = delete;\n\n    /**\n     * @brief RootedTree\u304B\
    \u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\
    \u30FC)\n     *\n     * @param tree RootedTree\n     */\n    explicit DoublingClimbTree(const\
    \ RootedTree<Cost>& tree) : RootedTree<Cost>(tree) {\n        build();\n    }\n\
    \n    /**\n     * @brief RootedTree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\
    \u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree RootedTree\n\
    \     */\n    DoublingClimbTree(RootedTree<Cost>&& tree) : RootedTree<Cost>(std::move(tree))\
    \ {\n        build();\n    }\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\
    \u306E\u30EA\u30B9\u30C8\u304B\u3089\u6839\u304C0\u306E\u30C0\u30D6\u30EA\u30F3\
    \u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam T \u9802\u70B9\u756A\
    \u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n     * @param par_ \u9802\
    \u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n  \
    \   * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\u3092\u3044\u304F\u3064\
    \u305A\u3089\u3059\u304B\n     */\n    template <typename T = long long>\n   \
    \ explicit DoublingClimbTree(const std::vector<T>& par_, long long padding = -1)\
    \ : RootedTree<Cost>(par_, padding) {\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\
    \u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF(\u30B3\u30D4\u30FC)\n     *\n     * @param tree Tree\n     * @param root\
    \ \u6839\n     */\n    DoublingClimbTree(const Tree<Cost>& tree, long long root)\
    \ : RootedTree<Cost>(tree, root) {\n        build();\n    }\n    /**\n     * @brief\
    \ Tree\u304B\u3089\u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\
    \u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    (\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n     * @param root \u6839\
    \n     */\n    DoublingClimbTree(Tree<Cost>&& tree, long long root) : RootedTree<Cost>(std::move(tree),\
    \ root) {\n        build();\n    }\n\n    /**\n     * @brief \u9802\u70B9u\u304B\
    \u3089k\u56DE\u3092\u6839\u306E\u65B9\u5411\u306B\u9061\u3063\u305F\u9802\u70B9\
    \n     *\n     * @param u \u5143\u306E\u9802\u70B9\n     * @param k \u767B\u308B\
    \u6BB5\u6570\n     * @return long long k\u56DE\u767B\u3063\u305F\u9802\u70B9\n\
    \     */\n    long long hop(long long u, long long k) const {\n        assert(0\
    \ <= u && u < this->n && k >= 0);\n        if (k > this->unweighted_depth[u])\
    \ return -1;\n        for (long long i = 0; i < h; i++) {\n            if (k >>\
    \ i & 1) u = doubling_par[i][u];\n            if (u == -1) return -1;\n      \
    \  }\n        return u;\n    }\n\n    /**\n     * @brief \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n     *\n     * @param u \u9802\u70B91\n     * @param v \u9802\u70B9\
    2\n     * @return long long LCA\u306E\u9802\u70B9\u756A\u53F7\n     */\n    long\
    \ long lca(long long u, long long v) const {\n        assert(0 <= u && u < this->n\
    \ && 0 <= v && v < this->n);\n        if (this->unweighted_depth[u] > this->unweighted_depth[v])\
    \ std::swap(u, v);\n        v = hop(v, this->unweighted_depth[v] - this->unweighted_depth[u]);\n\
    \        if (u == v) return u;\n        for (long long i = h - 1; i >= 0; i--)\
    \ {\n            long long nu = doubling_par[i][u];\n            long long nv\
    \ = doubling_par[i][v];\n            if (nu == -1) continue;\n            if (nu\
    \ != nv) {\n                u = nu;\n                v = nv;\n            }\n\
    \        }\n        return this->par[u];\n    }\n\n    /**\n     * @brief \u9802\
    \u70B9\u9593\u8DDD\u96E2(\u91CD\u307F\u4ED8\u304D)\n     *\n     * @param u \u9802\
    \u70B91\n     * @param v \u9802\u70B92\n     * @return Cost u\u3068v\u9593\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u8FBA\u306E\u91CD\u307F\u306E\u548C\n     */\n\
    \    Cost dist(long long u, long long v) const {\n        return this->depth[u]\
    \ + this->depth[v] - this->depth[lca(u, v)] * 2;\n    }\n\n   private:\n    void\
    \ build() {\n        long long n = this->n;\n        h = 1;\n        while ((1LL\
    \ << h) < n) h++;\n        doubling_par.assign(h, std::vector<long long>(n, -1));\n\
    \        for (long long i = 0; i < n; i++) doubling_par[0][i] = this->par[i];\n\
    \        for (long long i = 0; i < h - 1; i++) {\n            for (long long j\
    \ = 0; j < n; j++) {\n                if (doubling_par[i][j] != -1) {\n      \
    \              doubling_par[i + 1][j] = doubling_par[i][doubling_par[i][j]];\n\
    \                }\n            }\n        }\n    }\n};\n#line 14 \"src/graph/lowlink.hpp\"\
    \n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E lowlink \u3092\u6C42\u3081\
    \u3001\u95A2\u7BC0\u70B9\u30FB\u6A4B\u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u30FB\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\
    \u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\
    \u3002O(n + m)\n * \u591A\u91CD\u8FBA\u3068\u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044 (\u89AA\u3078\u623B\u308B\u8FBA\u306F\u9802\
    \u70B9\u3067\u306F\u306A\u304F\u8FBA\u306E\u756A\u53F7\u3067\u533A\u5225\u3059\
    \u308B)\n * \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u3069\u306E\u4E8C\u91CD\u9802\
    \u70B9\u9023\u7D50\u6210\u5206\u306E\u8FBA\u306B\u3082\u5165\u308C\u306A\u3044\
    \n * \u4F8B:\n * LowLink ll(g);\n * ll.articulation_points(); ll.bridges(); ll.two_edge_connected_groups();\n\
    \ * ll.two_vertex_connected_groups(); ll.block_cut_tree();\n *\n * @tparam Cost\
    \ \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\n\
    class LowLink {\n    long long n;\n    std::vector<bool> art, bridge;\n    std::vector<long\
    \ long> arts, bridge_ids;\n    std::vector<int> comp;\n    std::vector<std::vector<long\
    \ long>> groups;\n    std::vector<std::vector<long long>> bc_groups, bc_edge_groups;\n\
    \    std::vector<long long> bc_edge_id;\n\n   public:\n    std::vector<long long>\
    \ ord;  //!< DFS \u3067\u8A2A\u308C\u305F\u9806\u756A\n    std::vector<long long>\
    \ low;  //!< DFS \u6728\u306E\u5B50\u5B6B\u304B\u3089\u3001\u6728\u306E\u8FBA\u3092\
    \u9006\u306B\u305F\u3069\u3089\u305A\u306B 1 \u672C\u306E\u5F8C\u9000\u8FBA\u3067\
    \u884C\u3051\u308B\u9802\u70B9\u306E ord \u306E\u6700\u5C0F\u5024\n\n    explicit\
    \ LowLink(const Graph<Cost>& graph) : n(graph.n), art(n), bridge(graph.m), comp(n,\
    \ -1), bc_edge_id(graph.m, -1), ord(n, -1), low(n) {\n        std::vector<int>\
    \ parent(n, -1), parent_edge(n, -1), iter(n, 0);\n        std::vector<long long>\
    \ st;\n        // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3092\u4F5C\
    \u308B\u305F\u3081\u306B\u3001\u901A\u3063\u305F\u8FBA (\u6728\u306E\u8FBA\u3068\
    \u3001\u5B50\u5B6B\u304B\u3089\u7956\u5148\u3078\u306E\u5F8C\u9000\u8FBA) \u3092\
    \u7A4D\u3080\n        std::vector<long long> edge_st, edge_src(graph.m), edge_dst(graph.m),\
    \ last_block(n, -1);\n        auto push_edge = [&](long long id, long long a,\
    \ long long b) {\n            edge_st.push_back(id);\n            edge_src[id]\
    \ = a, edge_dst[id] = b;\n        };\n        long long k = 0;\n        for (long\
    \ long root = 0; root < n; root++) {\n            if (ord[root] != -1) continue;\n\
    \            int root_children = 0;\n            ord[root] = low[root] = k++;\n\
    \            st.push_back(root);\n            while (!st.empty()) {\n        \
    \        long long v = st.back();\n                if (iter[v] < static_cast<int>(graph[v].size()))\
    \ {\n                    const auto& e = graph[v][iter[v]++];\n              \
    \      if (e.id == parent_edge[v]) continue;\n                    long long u\
    \ = e.dst;\n                    if (ord[u] == -1) {\n                        parent[u]\
    \ = v;\n                        parent_edge[u] = e.id;\n                     \
    \   ord[u] = low[u] = k++;\n                        st.push_back(u);\n       \
    \                 push_edge(e.id, v, u);\n                    } else {\n     \
    \                   low[v] = std::min(low[v], ord[u]);\n                     \
    \   // \u5F8C\u9000\u8FBA\u306F\u5B50\u5B6B\u306E\u5074\u304B\u3089\u898B\u305F\
    \u3068\u304D\u306B 1 \u56DE\u3060\u3051\u7A4D\u3080 (\u81EA\u5DF1\u30EB\u30FC\u30D7\
    \u306F\u7A4D\u307E\u306A\u3044)\n                        if (ord[u] < ord[v])\
    \ push_edge(e.id, v, u);\n                    }\n                    continue;\n\
    \                }\n                st.pop_back();\n                if (v == root)\
    \ continue;\n                long long p = parent[v];\n                low[p]\
    \ = std::min(low[p], low[v]);\n                if (low[v] > ord[p]) bridge[parent_edge[v]]\
    \ = true;\n                if (low[v] >= ord[p]) {\n                    // \u89AA\
    \u3068\u306E\u8FBA\u307E\u3067\u304C 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\
    \u7D50\u6210\u5206\n                    long long b = bc_groups.size();\n    \
    \                bc_groups.emplace_back();\n                    bc_edge_groups.emplace_back();\n\
    \                    while (true) {\n                        long long id = edge_st.back();\n\
    \                        edge_st.pop_back();\n                        bc_edge_id[id]\
    \ = b;\n                        bc_edge_groups[b].push_back(id);\n           \
    \             for (long long w : {edge_src[id], edge_dst[id]}) {\n           \
    \                 if (last_block[w] != b) last_block[w] = b, bc_groups[b].push_back(w);\n\
    \                        }\n                        if (id == parent_edge[v])\
    \ break;\n                    }\n                }\n                if (p == root)\n\
    \                    root_children++;\n                else if (low[v] >= ord[p])\n\
    \                    art[p] = true;\n            }\n            if (root_children\
    \ >= 2) art[root] = true;\n            // \u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\
    \u5206\n            if (root_children == 0) {\n                bc_groups.push_back({root});\n\
    \                bc_edge_groups.emplace_back();\n            }\n        }\n  \
    \      for (long long v = 0; v < n; v++) {\n            if (art[v]) arts.push_back(v);\n\
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
    \ long>>& two_edge_connected_groups() const { return groups; }\n\n    /**\n  \
    \   * @brief \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\
    \u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     * \u95A2\u7BC0\u70B9\u306F\u8907\u6570\
    \u306E\u6210\u5206\u306B\u5165\u308B\u3002\u307B\u304B\u306E\u9802\u70B9\u3068\
    \u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306F\u3001\u305D\
    \u308C\u3060\u3051\u3067 1 \u3064\u306E\u6210\u5206\u306B\u306A\u308B\n     */\n\
    \    const std::vector<std::vector<long long>>& two_vertex_connected_groups()\
    \ const { return bc_groups; }\n    /**\n     * @brief \u4E8C\u91CD\u9802\u70B9\
    \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8FBA\u306E\u756A\u53F7\u306E\u30EA\
    \u30B9\u30C8 (two_vertex_connected_groups() \u3068\u540C\u3058\u9806)\n     *\
    \ \u81EA\u5DF1\u30EB\u30FC\u30D7\u4EE5\u5916\u306E\u8FBA\u306F\u3061\u3087\u3046\
    \u3069 1 \u3064\u306E\u6210\u5206\u306B\u5165\u308B\n     */\n    const std::vector<std::vector<long\
    \ long>>& two_vertex_connected_edge_groups() const { return bc_edge_groups; }\n\
    \    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\u304C\u5C5E\u3059\u308B\u4E8C\
    \u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306E\u756A\u53F7 (\u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306A\u3089 -1)\n     */\n    long long two_vertex_connected_group_id(long\
    \ long id) const {\n        assert(0 <= id && id < static_cast<long long>(bc_edge_id.size()));\n\
    \        return bc_edge_id[id];\n    }\n    /**\n     * @brief Block-Cut Tree\n\
    \     * \u9802\u70B9 0, ..., n - 1 \u306F\u5143\u306E\u9802\u70B9\u3001\u9802\u70B9\
    \ n + b \u306F\u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206 b \u3067\u3001\u5143\
    \u306E\u9802\u70B9\u3068\u3001\u305D\u308C\u3092\u542B\u3080\u6210\u5206\u3092\
    \u8FBA\u3067\u7D50\u3076\n     * \u5143\u306E\u30B0\u30E9\u30D5\u304C\u9023\u7D50\
    \u306A\u3089\u6728\u3001\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u68EE\u306B\
    \u306A\u308B (\u68EE\u306E\u3068\u304D\u306F\u3001\u9023\u7D50\u3067\u3042\u308B\
    \u3053\u3068\u3092\u524D\u63D0\u3068\u3059\u308B\u6728\u306E\u95A2\u6570\u306B\
    \u306F\u6E21\u305B\u306A\u3044)\n     */\n    Tree<int> block_cut_tree() const\
    \ {\n        Tree<int> res(n + static_cast<long long>(bc_groups.size()));\n  \
    \      for (long long b = 0; b < static_cast<long long>(bc_groups.size()); b++)\
    \ {\n            for (long long v : bc_groups[b]) res.add_edge(v, n + b);\n  \
    \      }\n        return res;\n    }\n};\n#line 8 \"test/unittest/graph/lowlink.test.cpp\"\
    \n\n#line 12 \"test/unittest/graph/lowlink.test.cpp\"\n#include <random>\n#include\
    \ <set>\n#line 15 \"test/unittest/graph/lowlink.test.cpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\nnamespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\
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
    \ a) { return leader(a); });\n    }\n};\n#line 2 \"src/graph/heavy-light-decomposition.hpp\"\
    \n\n/**\n * @file heavy-light-decomposition.hpp\n * @brief HL \u5206\u89E3 (Heavy-Light\
    \ Decomposition)\n */\n\n#line 12 \"src/graph/heavy-light-decomposition.hpp\"\n\
    \n#line 14 \"src/graph/heavy-light-decomposition.hpp\"\n\n/**\n * @brief HL \u5206\
    \u89E3 (Heavy-Light Decomposition)\n *\n * \u6728\u306E\u9802\u70B9\u3092\u3001\
    \u3069\u306E\u30D1\u30B9\u3082 O(log n) \u500B\u306E\u533A\u9593\u306B\u5206\u304B\
    \u308C\u3001\u3069\u306E\u90E8\u5206\u6728\u3082 1 \u3064\u306E\u533A\u9593\u306B\
    \u306A\u308B\u3088\u3046\u306B\u4E26\u3079\u66FF\u3048\u308B\n * \u9802\u70B9\
    \ v \u306F\u5217\u306E index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u3002\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u3068\u7D44\u307F\u5408\u308F\
    \u305B\u3066\u3001\u30D1\u30B9\u3084\u90E8\u5206\u6728\u3078\u306E\u30AF\u30A8\
    \u30EA\u3092\u884C\u3046\n * \u524D\u8A08\u7B97 O(n)\u3002DFS \u306F\u518D\u5E30\
    \u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * HeavyLightDecomposition hld(tree,\
    \ root);  // tree \u306F Tree<Cost>\n * for (auto [a, b] : hld.path(u, v)) sum\
    \ += seg.prod(std::min(a, b), std::max(a, b) + 1);\n * auto [l, r] = hld.subtree(v);\
    \  // \u90E8\u5206\u6728\u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition\
    \ {\n    long long n, root;\n    // \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\
    \u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\
    \u308B\n    std::vector<int> par, dep, sz, heavy, head, in, order;\n\n   public:\n\
    \    /**\n     * @brief \u6728 tree \u3092\u6839 root \u3067 HL \u5206\u89E3\u3059\
    \u308B\n     */\n    template <typename Cost>\n    explicit HeavyLightDecomposition(const\
    \ Tree<Cost>& tree, long long root = 0)\n        : n(tree.size()), root(root),\
    \ par(n, -1), dep(n, 0), sz(n, 1), heavy(n, -1), head(n), in(n), order(n) {\n\
    \        assert(0 <= root && root < n);\n        // \u6839\u304B\u3089\u306E BFS\
    \ \u9806\u3067\u89AA\u3068\u6DF1\u3055\u3092\u6C7A\u3081\u308B\n        std::vector<int>\
    \ bfs = {static_cast<int>(root)};\n        bfs.reserve(n);\n        for (int i\
    \ = 0; i < static_cast<int>(bfs.size()); i++) {\n            int v = bfs[i];\n\
    \            for (long long u : tree[v]) {\n                if (u == par[v]) continue;\n\
    \                assert(u != root && par[u] == -1 && \"HeavyLightDecomposition:\
    \ not a tree\");\n                par[u] = v;\n                dep[u] = dep[v]\
    \ + 1;\n                bfs.push_back(u);\n            }\n        }\n        assert(static_cast<long\
    \ long>(bfs.size()) == n && \"HeavyLightDecomposition: not connected\");\n   \
    \     // \u8449\u306E\u5074\u304B\u3089\u90E8\u5206\u6728\u306E\u5927\u304D\u3055\
    \u3092\u6C42\u3081\u3001\u6700\u3082\u5927\u304D\u3044\u5B50\u3092 heavy \u306B\
    \u3059\u308B\n        for (int i = n - 1; i > 0; i--) {\n            int v = bfs[i],\
    \ p = par[v];\n            sz[p] += sz[v];\n            if (heavy[p] == -1 ||\
    \ sz[v] > sz[heavy[p]]) heavy[p] = v;\n        }\n        // heavy \u306A\u5B50\
    \u3092\u6700\u5F8C\u306B\u7A4D\u3080\u3068\u3001\u6B21\u306B\u53D6\u308A\u51FA\
    \u3055\u308C\u3066 index \u304C\u9023\u7D9A\u3059\u308B\n        std::vector<int>\
    \ st = {static_cast<int>(root)};\n        head[root] = root;\n        int k =\
    \ 0;\n        while (!st.empty()) {\n            int v = st.back();\n        \
    \    st.pop_back();\n            in[v] = k;\n            order[k++] = v;\n   \
    \         for (long long u : tree[v]) {\n                if (u == par[v] || u\
    \ == heavy[v]) continue;\n                head[u] = u;\n                st.push_back(u);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ \u9802\u70B9 v \u306E\u5217\u3067\u306E\u4F4D\u7F6E\n     */\n    long long\
    \ index(long long v) const { return in[v]; }\n    /**\n     * @brief \u5217\u306E\
    \ i \u756A\u76EE\u306E\u9802\u70B9 (index \u306E\u9006)\n     */\n    long long\
    \ vertex(long long i) const { return order[i]; }\n    /**\n     * @brief v \u306E\
    \u89AA (\u6839\u306A\u3089 -1)\n     */\n    long long parent(long long v) const\
    \ { return par[v]; }\n    /**\n     * @brief v \u306E\u6DF1\u3055 (\u6839\u306F\
    \ 0\u3001\u8FBA\u306E\u672C\u6570)\n     */\n    long long depth(long long v)\
    \ const { return dep[v]; }\n    /**\n     * @brief v \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n     */\n    long long\
    \ subtree_size(long long v) const { return sz[v]; }\n    /**\n     * @brief v\
    \ \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u533A\u9593 [l, r)\n     */\n    std::pair<long long, long\
    \ long> subtree(long long v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n\
    \     * @brief u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n\
    \     */\n    long long lca(long long u, long long v) const {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n);\n        while (head[u] != head[v]) {\n \
    \           if (dep[head[u]] < dep[head[v]]) std::swap(u, v);\n            u =\
    \ par[head[u]];\n        }\n        return dep[u] < dep[v] ? u : v;\n    }\n \
    \   /**\n     * @brief u \u3068 v \u306E\u9593\u306E\u8FBA\u306E\u672C\u6570 O(log\
    \ n)\n     */\n    long long dist(long long u, long long v) const { return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)]; }\n    /**\n     * @brief v \u304B\u3089\u6839\
    \u306E\u65B9\u3078 k \u672C\u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k\
    \ > depth(v) \u306A\u3089 -1) O(log n)\n     */\n    long long hop(long long v,\
    \ long long k) const {\n        assert(0 <= v && v < n && k >= 0);\n        if\
    \ (k > dep[v]) return -1;\n        while (true) {\n            long long h = head[v];\n\
    \            if (in[v] - in[h] >= k) return order[in[v] - k];\n            k -=\
    \ in[v] - in[h] + 1;\n            v = par[h];\n        }\n    }\n    /**\n   \
    \  * @brief u \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089\
    \ k \u672C\u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\
    \u3089 -1) O(log n)\n     */\n    long long jump(long long u, long long v, long\
    \ long k) const {\n        assert(0 <= u && u < n && 0 <= v && v < n && k >= 0);\n\
    \        long long w = lca(u, v);\n        long long du = dep[u] - dep[w], dv\
    \ = dep[v] - dep[w];\n        if (k <= du) return hop(u, k);\n        if (k <=\
    \ du + dv) return hop(v, du + dv - k);\n        return -1;\n    }\n\n    /**\n\
    \     * @brief u \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3092\u3001\u5217\u306E\
    \u533A\u9593\u306B\u5206\u3051\u3066 u \u5074\u304B\u3089\u9806\u306B\u4E26\u3079\
    \u308B O(log n)\n     *\n     * \u5404\u8981\u7D20 (a, b) \u306F\u3001\u5217\u306E\
    \ a \u756A\u76EE\u304B\u3089 b \u756A\u76EE\u307E\u3067 (\u4E21\u7AEF\u3092\u542B\
    \u3080) \u3092\u3001a \u304B\u3089 b \u306E\u5411\u304D\u306B\u305F\u3069\u308B\
    \u3053\u3068\u3092\u8868\u3059\n     * \u5411\u304D\u3092\u8868\u3059\u305F\u3081\
    \u3001\u3053\u306E\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u4ED6\u306E\u533A\u9593\
    \ (\u534A\u958B\u533A\u9593 [l, r)) \u3068\u9055\u3063\u3066\u9589\u533A\u9593\
    \u306B\u306A\u3063\u3066\u3044\u308B\n     * a > b \u306A\u3089 index \u304C\u6E1B\
    \u308B\u5411\u304D (\u6839\u306B\u8FD1\u3065\u304F\u5411\u304D) \u306B\u305F\u3069\
    \u308B\n     * \u4EA4\u63DB\u6CD5\u5247\u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\
    \u6F14\u7B97\u3067\u306F\u3001a > b \u306E\u533A\u9593\u306F\u9006\u9806\u306E\
    \u7A4D\u3092\u4F7F\u3046\n     * @param edge true \u306A\u3089\u8FBA\u306B\u3064\
    \u3044\u3066\u306E\u30D1\u30B9\u306B\u3059\u308B\u3002\u8FBA (parent(v), v) \u3092\
    \ index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\
    \u3092\u542B\u3081\u306A\u3044\n     */\n    std::vector<std::pair<long long,\
    \ long long>> path(long long u, long long v, bool edge = false) const {\n    \
    \    assert(0 <= u && u < n && 0 <= v && v < n);\n        std::vector<std::pair<long\
    \ long, long long>> up, down;\n        while (head[u] != head[v]) {\n        \
    \    if (dep[head[u]] >= dep[head[v]]) {\n                up.emplace_back(in[u],\
    \ in[head[u]]);\n                u = par[head[u]];\n            } else {\n   \
    \             down.emplace_back(in[head[v]], in[v]);\n                v = par[head[v]];\n\
    \            }\n        }\n        if (dep[u] >= dep[v]) {\n            // v \u304C\
    \ lca\n            long long l = in[v] + edge;\n            if (l <= in[u]) up.emplace_back(in[u],\
    \ l);\n        } else {\n            // u \u304C lca\n            long long l\
    \ = in[u] + edge;\n            if (l <= in[v]) down.emplace_back(l, in[v]);\n\
    \        }\n        up.insert(up.end(), down.rbegin(), down.rend());\n       \
    \ return up;\n    }\n};\n#line 18 \"test/unittest/graph/lowlink.test.cpp\"\n\n\
    // \u9802\u70B9 skip_v \u3068\u8FBA skip_e \u3092\u4F7F\u308F\u306A\u3044\u3068\
    \u304D\u306E\u9023\u7D50\u6210\u5206\u306E\u6570 (skip_v \u81EA\u8EAB\u306F\u6570\
    \u3048\u306A\u3044)\nint count_components(int n, const std::vector<std::pair<int,\
    \ int>>& es, int skip_v, int skip_e) {\n    UnionFind uf(n);\n    for (int i =\
    \ 0; i < static_cast<int>(es.size()); i++) {\n        if (i == skip_e) continue;\n\
    \        auto [u, v] = es[i];\n        if (u == skip_v || v == skip_v) continue;\n\
    \        uf.merge(u, v);\n    }\n    int c = 0;\n    for (int v = 0; v < n; v++)\
    \ c += v != skip_v && uf.leader(v) == v;\n    return c;\n}\n\n// \u5358\u7D14\u9589\
    \u8DEF\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u3001\u540C\u3058\u9589\u8DEF\
    \u306B\u4E57\u308B\u8FBA\u3092\u540C\u3058\u7D44\u306B\u3059\u308B (\u591A\u91CD\
    \u8FBA 2 \u672C\u306E\u9589\u8DEF\u3082\u6570\u3048\u308B)\n// \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u4EE5\u5916\u306E\u8FBA\u306E\u7D44\u5206\u3051\u3092\u3001\u8FBA\
    \u3054\u3068\u306E\u4EE3\u8868\u306E\u756A\u53F7\u3067\u8FD4\u3059 (\u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u306F -1)\nstd::vector<int> naive_edge_blocks(int n, const\
    \ std::vector<std::pair<int, int>>& es) {\n    int m = es.size();\n    UnionFind\
    \ uf(m);\n    std::vector<std::vector<std::pair<int, int>>> adj(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        auto [u, v] = es[i];\n        if (u == v) continue;\n\
    \        adj[u].emplace_back(v, i), adj[v].emplace_back(u, i);\n    }\n    //\
    \ s \u3092\u9589\u8DEF\u306E\u6700\u5C0F\u306E\u9802\u70B9\u3068\u3057\u3066\u3001\
    s \u304B\u3089\u51FA\u3066 s \u306B\u623B\u308B\u9053\u3092\u63A2\u3059\n    for\
    \ (int s = 0; s < n; s++) {\n        std::vector<bool> used(n, false);\n     \
    \   std::vector<int> path;  // \u901A\u3063\u305F\u8FBA\n        std::function<void(int)>\
    \ dfs = [&](int v) {\n            for (auto [u, id] : adj[v]) {\n            \
    \    if (!path.empty() && id == path.back()) continue;\n                if (u\
    \ == s && !path.empty()) {\n                    for (int e : path) uf.merge(e,\
    \ id);\n                    continue;\n                }\n                if (u\
    \ < s || used[u]) continue;\n                used[u] = true, path.push_back(id);\n\
    \                dfs(u);\n                used[u] = false, path.pop_back();\n\
    \            }\n        };\n        used[s] = true;\n        dfs(s);\n    }\n\
    \    std::vector<int> res(m);\n    for (int i = 0; i < m; i++) res[i] = es[i].first\
    \ == es[i].second ? -1 : uf.leader(i);\n    return res;\n}\n\nint main() {\n \
    \   std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        int n = rng() % 9 + 1, m = rng() % 14;\n        Graph<int>\
    \ g(n);\n        std::vector<std::pair<int, int>> es;\n        for (int i = 0;\
    \ i < m; i++) {\n            int u = rng() % n, v = rng() % n;  // \u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n            g.add_edge(u,\
    \ v);\n            es.emplace_back(u, v);\n        }\n        LowLink ll(g);\n\
    \        int base = count_components(n, es, -1, -1);\n        std::vector<long\
    \ long> arts, bridges;\n        for (int v = 0; v < n; v++) {\n            //\
    \ v \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u3001\u6B8B\u308A\u306E\u9802\
    \u70B9\u306E\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u304B\n         \
    \   // (v \u304C\u307B\u304B\u306E\u9802\u70B9\u3068\u3064\u306A\u304C\u3063\u3066\
    \u3044\u306A\u3051\u308C\u3070\u3001v \u306E\u5206\u3060\u3051 1 \u6E1B\u308B\u306E\
    \u304C\u666E\u901A)\n            bool isolated = true;\n            for (auto\
    \ [a, b] : es) isolated &= !((a == v || b == v) && a != b);\n            bool\
    \ art = count_components(n, es, v, -1) > base - (isolated ? 1 : 0);\n        \
    \    if (art) arts.push_back(v);\n            if (ll.is_articulation_point(v)\
    \ != art) ok = false;\n        }\n        for (int i = 0; i < m; i++) {\n    \
    \        bool br = count_components(n, es, -1, i) > base;\n            if (br)\
    \ bridges.push_back(i);\n            if (ll.is_bridge(i) != br) ok = false;\n\
    \        }\n        if (ll.articulation_points() != arts || ll.bridges() != bridges)\
    \ ok = false;\n\n        // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206: \u6A4B\
    \u3092\u3059\u3079\u3066\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\
    \u7D50\u6210\u5206\u3068\u4E00\u81F4\u3059\u308B\n        UnionFind uf(n);\n \
    \       for (int i = 0; i < m; i++) {\n            if (!ll.is_bridge(i)) uf.merge(es[i].first,\
    \ es[i].second);\n        }\n        const auto& groups = ll.two_edge_connected_groups();\n\
    \        int total = 0;\n        for (int k = 0; k < static_cast<int>(groups.size());\
    \ k++) {\n            total += groups[k].size();\n            for (int v : groups[k])\
    \ {\n                if (ll.two_edge_connected_group_id(v) != k || !uf.same(v,\
    \ groups[k][0])) ok = false;\n            }\n        }\n        int uf_groups\
    \ = 0;\n        for (int v = 0; v < n; v++) uf_groups += uf.leader(v) == v;\n\
    \        if (total != n || static_cast<int>(groups.size()) != uf_groups) ok =\
    \ false;\n\n        // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206: \u8FBA\
    \u306E\u7D44\u5206\u3051\u304C\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u4E00\u81F4\
    \u3059\u308B\n        std::vector<int> naive = naive_edge_blocks(n, es);\n   \
    \     const auto& bc = ll.two_vertex_connected_groups();\n        const auto&\
    \ bce = ll.two_vertex_connected_edge_groups();\n        if (bc.size() != bce.size())\
    \ ok = false;\n        for (int i = 0; i < m && ok; i++) {\n            for (int\
    \ j = 0; j < m; j++) {\n                if (naive[i] == -1 || naive[j] == -1)\
    \ continue;\n                if ((naive[i] == naive[j]) != (ll.two_vertex_connected_group_id(i)\
    \ == ll.two_vertex_connected_group_id(j))) ok = false;\n            }\n      \
    \      if ((naive[i] == -1) != (ll.two_vertex_connected_group_id(i) == -1)) ok\
    \ = false;\n        }\n        // \u6210\u5206\u306E\u9802\u70B9\u306F\u8FBA\u306E\
    \u7AEF\u70B9\u3067\u3001\u8FBA\u306E\u306A\u3044\u6210\u5206\u306F\u307B\u304B\
    \u306E\u9802\u70B9\u3068\u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044 1 \u9802\
    \u70B9\n        std::vector<int> block_count(n, 0);\n        for (int b = 0; b\
    \ < static_cast<int>(bc.size()) && ok; b++) {\n            std::set<long long>\
    \ ends;\n            for (long long id : bce[b]) {\n                if (ll.two_vertex_connected_group_id(id)\
    \ != b) ok = false;\n                ends.insert(es[id].first), ends.insert(es[id].second);\n\
    \            }\n            std::set<long long> vs(bc[b].begin(), bc[b].end());\n\
    \            if (vs.size() != bc[b].size()) ok = false;\n            if (bce[b].empty())\
    \ {\n                if (bc[b].size() != 1) ok = false;\n            } else if\
    \ (vs != ends) {\n                ok = false;\n            }\n            for\
    \ (long long v : bc[b]) block_count[v]++;\n        }\n        for (int v = 0;\
    \ v < n; v++) {\n            // \u95A2\u7BC0\u70B9\u306F\u3061\u3087\u3046\u3069\
    \ 2 \u3064\u4EE5\u4E0A\u306E\u6210\u5206\u306B\u5165\u308A\u3001\u305D\u308C\u4EE5\
    \u5916\u306F\u3061\u3087\u3046\u3069 1 \u3064\n            if ((block_count[v]\
    \ >= 2) != ll.is_articulation_point(v) || block_count[v] == 0) ok = false;\n \
    \       }\n        // Block-Cut Tree \u306F\u68EE\u3067\u3001\u5143\u306E\u9802\
    \u70B9\u306E\u6B21\u6570\u306F\u5165\u3063\u3066\u3044\u308B\u6210\u5206\u306E\
    \u6570\n        Tree<int> t = ll.block_cut_tree();\n        if (t.n != n + static_cast<long\
    \ long>(bc.size())) ok = false;\n        UnionFind tuf(t.n);\n        for (long\
    \ long v = 0; v < t.n; v++) {\n            for (const auto& e : t[v]) {\n    \
    \            if (v < e.dst && !tuf.merge(v, e.dst)) ok = false;  // \u9589\u8DEF\
    \u304C\u3042\u308C\u3070\u6728\u3067\u306F\u306A\u3044\n            }\n      \
    \  }\n        for (int v = 0; v < n; v++) {\n            if (static_cast<int>(t[v].size())\
    \ != block_count[v]) ok = false;\n        }\n    }\n\n    // \u9023\u7D50\u306A\
    \u30B0\u30E9\u30D5\u3067\u3001u \u304B\u3089 v \u3078\u306E\u3069\u306E\u9053\u3082\
    \u901A\u308B\u9802\u70B9 (u, v \u4EE5\u5916) \u306E\u500B\u6570\u306F\u3001\n\
    \    // Block-Cut Tree \u4E0A\u306E u \u3068 v \u3092\u7D50\u3076\u30D1\u30B9\u306B\
    \u3042\u308B\u5143\u306E\u9802\u70B9\u306E\u500B\u6570 (\u7AEF\u3092\u9664\u304F\
    ) \u3068\u4E00\u81F4\u3059\u308B\u3002HL \u5206\u89E3\u306B\u6E21\u305B\u308B\u3053\
    \u3068\u3082\u78BA\u304B\u3081\u308B\n    for (int rep = 0; rep < 1000 && ok;\
    \ rep++) {\n        int n = rng() % 9 + 1, m = n - 1 + rng() % 6;\n        Graph<int>\
    \ g(n);\n        std::vector<std::pair<int, int>> es;\n        for (int v = 1;\
    \ v < n; v++) {\n            int p = rng() % v;\n            g.add_edge(p, v),\
    \ es.emplace_back(p, v);\n        }\n        while (static_cast<int>(es.size())\
    \ < m) {\n            int u = rng() % n, v = rng() % n;\n            g.add_edge(u,\
    \ v), es.emplace_back(u, v);\n        }\n        LowLink ll(g);\n        HeavyLightDecomposition\
    \ hld(ll.block_cut_tree());\n        for (int u = 0; u < n; u++) {\n         \
    \   for (int v = 0; v < n; v++) {\n                if (u == v) continue;\n   \
    \             int must = 0;\n                for (int x = 0; x < n; x++) {\n \
    \                   if (x == u || x == v) continue;\n                    UnionFind\
    \ uf(n);\n                    for (auto [a, b] : es) {\n                     \
    \   if (a != x && b != x) uf.merge(a, b);\n                    }\n           \
    \         must += !uf.same(u, v);\n                }\n                // \u30D1\
    \u30B9\u306F \u5143\u306E\u9802\u70B9 - \u6210\u5206 - \u5143\u306E\u9802\u70B9\
    \ - ... \u3068\u4EA4\u4E92\u306B\u4E26\u3076\n                if (hld.dist(u,\
    \ v) / 2 - 1 != must) ok = false;\n            }\n        }\n    }\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// LowLink \u3092\u3001\u9802\u70B9\u3084\u8FBA\u3092 1 \u3064\u53D6\u308A\
    \u9664\u3044\u3066\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u6570\u3048\u308B\
    \u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\
    \u308B\n// \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206\u306F\u3001\u5358\u7D14\
    \u9589\u8DEF\u3092\u3059\u3079\u3066\u5217\u6319\u3057\u3066\u540C\u3058\u9589\
    \u8DEF\u306B\u4E57\u308B\u8FBA\u3092\u307E\u3068\u3081\u308B\u611A\u76F4\u306A\
    \u5B9F\u88C5\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/lowlink.hpp\"\
    \n\n#include <algorithm>\n#include <functional>\n#include <iostream>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\n#include \"../../../src/data_structures/unionfind.hpp\"\
    \n#include \"../../../src/graph/heavy-light-decomposition.hpp\"\n\n// \u9802\u70B9\
    \ skip_v \u3068\u8FBA skip_e \u3092\u4F7F\u308F\u306A\u3044\u3068\u304D\u306E\u9023\
    \u7D50\u6210\u5206\u306E\u6570 (skip_v \u81EA\u8EAB\u306F\u6570\u3048\u306A\u3044\
    )\nint count_components(int n, const std::vector<std::pair<int, int>>& es, int\
    \ skip_v, int skip_e) {\n    UnionFind uf(n);\n    for (int i = 0; i < static_cast<int>(es.size());\
    \ i++) {\n        if (i == skip_e) continue;\n        auto [u, v] = es[i];\n \
    \       if (u == skip_v || v == skip_v) continue;\n        uf.merge(u, v);\n \
    \   }\n    int c = 0;\n    for (int v = 0; v < n; v++) c += v != skip_v && uf.leader(v)\
    \ == v;\n    return c;\n}\n\n// \u5358\u7D14\u9589\u8DEF\u3092\u3059\u3079\u3066\
    \u5217\u6319\u3057\u3001\u540C\u3058\u9589\u8DEF\u306B\u4E57\u308B\u8FBA\u3092\
    \u540C\u3058\u7D44\u306B\u3059\u308B (\u591A\u91CD\u8FBA 2 \u672C\u306E\u9589\u8DEF\
    \u3082\u6570\u3048\u308B)\n// \u81EA\u5DF1\u30EB\u30FC\u30D7\u4EE5\u5916\u306E\
    \u8FBA\u306E\u7D44\u5206\u3051\u3092\u3001\u8FBA\u3054\u3068\u306E\u4EE3\u8868\
    \u306E\u756A\u53F7\u3067\u8FD4\u3059 (\u81EA\u5DF1\u30EB\u30FC\u30D7\u306F -1)\n\
    std::vector<int> naive_edge_blocks(int n, const std::vector<std::pair<int, int>>&\
    \ es) {\n    int m = es.size();\n    UnionFind uf(m);\n    std::vector<std::vector<std::pair<int,\
    \ int>>> adj(n);\n    for (int i = 0; i < m; i++) {\n        auto [u, v] = es[i];\n\
    \        if (u == v) continue;\n        adj[u].emplace_back(v, i), adj[v].emplace_back(u,\
    \ i);\n    }\n    // s \u3092\u9589\u8DEF\u306E\u6700\u5C0F\u306E\u9802\u70B9\u3068\
    \u3057\u3066\u3001s \u304B\u3089\u51FA\u3066 s \u306B\u623B\u308B\u9053\u3092\u63A2\
    \u3059\n    for (int s = 0; s < n; s++) {\n        std::vector<bool> used(n, false);\n\
    \        std::vector<int> path;  // \u901A\u3063\u305F\u8FBA\n        std::function<void(int)>\
    \ dfs = [&](int v) {\n            for (auto [u, id] : adj[v]) {\n            \
    \    if (!path.empty() && id == path.back()) continue;\n                if (u\
    \ == s && !path.empty()) {\n                    for (int e : path) uf.merge(e,\
    \ id);\n                    continue;\n                }\n                if (u\
    \ < s || used[u]) continue;\n                used[u] = true, path.push_back(id);\n\
    \                dfs(u);\n                used[u] = false, path.pop_back();\n\
    \            }\n        };\n        used[s] = true;\n        dfs(s);\n    }\n\
    \    std::vector<int> res(m);\n    for (int i = 0; i < m; i++) res[i] = es[i].first\
    \ == es[i].second ? -1 : uf.leader(i);\n    return res;\n}\n\nint main() {\n \
    \   std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 3000\
    \ && ok; rep++) {\n        int n = rng() % 9 + 1, m = rng() % 14;\n        Graph<int>\
    \ g(n);\n        std::vector<std::pair<int, int>> es;\n        for (int i = 0;\
    \ i < m; i++) {\n            int u = rng() % n, v = rng() % n;  // \u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n            g.add_edge(u,\
    \ v);\n            es.emplace_back(u, v);\n        }\n        LowLink ll(g);\n\
    \        int base = count_components(n, es, -1, -1);\n        std::vector<long\
    \ long> arts, bridges;\n        for (int v = 0; v < n; v++) {\n            //\
    \ v \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u3001\u6B8B\u308A\u306E\u9802\
    \u70B9\u306E\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u304B\n         \
    \   // (v \u304C\u307B\u304B\u306E\u9802\u70B9\u3068\u3064\u306A\u304C\u3063\u3066\
    \u3044\u306A\u3051\u308C\u3070\u3001v \u306E\u5206\u3060\u3051 1 \u6E1B\u308B\u306E\
    \u304C\u666E\u901A)\n            bool isolated = true;\n            for (auto\
    \ [a, b] : es) isolated &= !((a == v || b == v) && a != b);\n            bool\
    \ art = count_components(n, es, v, -1) > base - (isolated ? 1 : 0);\n        \
    \    if (art) arts.push_back(v);\n            if (ll.is_articulation_point(v)\
    \ != art) ok = false;\n        }\n        for (int i = 0; i < m; i++) {\n    \
    \        bool br = count_components(n, es, -1, i) > base;\n            if (br)\
    \ bridges.push_back(i);\n            if (ll.is_bridge(i) != br) ok = false;\n\
    \        }\n        if (ll.articulation_points() != arts || ll.bridges() != bridges)\
    \ ok = false;\n\n        // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206: \u6A4B\
    \u3092\u3059\u3079\u3066\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\
    \u7D50\u6210\u5206\u3068\u4E00\u81F4\u3059\u308B\n        UnionFind uf(n);\n \
    \       for (int i = 0; i < m; i++) {\n            if (!ll.is_bridge(i)) uf.merge(es[i].first,\
    \ es[i].second);\n        }\n        const auto& groups = ll.two_edge_connected_groups();\n\
    \        int total = 0;\n        for (int k = 0; k < static_cast<int>(groups.size());\
    \ k++) {\n            total += groups[k].size();\n            for (int v : groups[k])\
    \ {\n                if (ll.two_edge_connected_group_id(v) != k || !uf.same(v,\
    \ groups[k][0])) ok = false;\n            }\n        }\n        int uf_groups\
    \ = 0;\n        for (int v = 0; v < n; v++) uf_groups += uf.leader(v) == v;\n\
    \        if (total != n || static_cast<int>(groups.size()) != uf_groups) ok =\
    \ false;\n\n        // \u4E8C\u91CD\u9802\u70B9\u9023\u7D50\u6210\u5206: \u8FBA\
    \u306E\u7D44\u5206\u3051\u304C\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u4E00\u81F4\
    \u3059\u308B\n        std::vector<int> naive = naive_edge_blocks(n, es);\n   \
    \     const auto& bc = ll.two_vertex_connected_groups();\n        const auto&\
    \ bce = ll.two_vertex_connected_edge_groups();\n        if (bc.size() != bce.size())\
    \ ok = false;\n        for (int i = 0; i < m && ok; i++) {\n            for (int\
    \ j = 0; j < m; j++) {\n                if (naive[i] == -1 || naive[j] == -1)\
    \ continue;\n                if ((naive[i] == naive[j]) != (ll.two_vertex_connected_group_id(i)\
    \ == ll.two_vertex_connected_group_id(j))) ok = false;\n            }\n      \
    \      if ((naive[i] == -1) != (ll.two_vertex_connected_group_id(i) == -1)) ok\
    \ = false;\n        }\n        // \u6210\u5206\u306E\u9802\u70B9\u306F\u8FBA\u306E\
    \u7AEF\u70B9\u3067\u3001\u8FBA\u306E\u306A\u3044\u6210\u5206\u306F\u307B\u304B\
    \u306E\u9802\u70B9\u3068\u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3044 1 \u9802\
    \u70B9\n        std::vector<int> block_count(n, 0);\n        for (int b = 0; b\
    \ < static_cast<int>(bc.size()) && ok; b++) {\n            std::set<long long>\
    \ ends;\n            for (long long id : bce[b]) {\n                if (ll.two_vertex_connected_group_id(id)\
    \ != b) ok = false;\n                ends.insert(es[id].first), ends.insert(es[id].second);\n\
    \            }\n            std::set<long long> vs(bc[b].begin(), bc[b].end());\n\
    \            if (vs.size() != bc[b].size()) ok = false;\n            if (bce[b].empty())\
    \ {\n                if (bc[b].size() != 1) ok = false;\n            } else if\
    \ (vs != ends) {\n                ok = false;\n            }\n            for\
    \ (long long v : bc[b]) block_count[v]++;\n        }\n        for (int v = 0;\
    \ v < n; v++) {\n            // \u95A2\u7BC0\u70B9\u306F\u3061\u3087\u3046\u3069\
    \ 2 \u3064\u4EE5\u4E0A\u306E\u6210\u5206\u306B\u5165\u308A\u3001\u305D\u308C\u4EE5\
    \u5916\u306F\u3061\u3087\u3046\u3069 1 \u3064\n            if ((block_count[v]\
    \ >= 2) != ll.is_articulation_point(v) || block_count[v] == 0) ok = false;\n \
    \       }\n        // Block-Cut Tree \u306F\u68EE\u3067\u3001\u5143\u306E\u9802\
    \u70B9\u306E\u6B21\u6570\u306F\u5165\u3063\u3066\u3044\u308B\u6210\u5206\u306E\
    \u6570\n        Tree<int> t = ll.block_cut_tree();\n        if (t.n != n + static_cast<long\
    \ long>(bc.size())) ok = false;\n        UnionFind tuf(t.n);\n        for (long\
    \ long v = 0; v < t.n; v++) {\n            for (const auto& e : t[v]) {\n    \
    \            if (v < e.dst && !tuf.merge(v, e.dst)) ok = false;  // \u9589\u8DEF\
    \u304C\u3042\u308C\u3070\u6728\u3067\u306F\u306A\u3044\n            }\n      \
    \  }\n        for (int v = 0; v < n; v++) {\n            if (static_cast<int>(t[v].size())\
    \ != block_count[v]) ok = false;\n        }\n    }\n\n    // \u9023\u7D50\u306A\
    \u30B0\u30E9\u30D5\u3067\u3001u \u304B\u3089 v \u3078\u306E\u3069\u306E\u9053\u3082\
    \u901A\u308B\u9802\u70B9 (u, v \u4EE5\u5916) \u306E\u500B\u6570\u306F\u3001\n\
    \    // Block-Cut Tree \u4E0A\u306E u \u3068 v \u3092\u7D50\u3076\u30D1\u30B9\u306B\
    \u3042\u308B\u5143\u306E\u9802\u70B9\u306E\u500B\u6570 (\u7AEF\u3092\u9664\u304F\
    ) \u3068\u4E00\u81F4\u3059\u308B\u3002HL \u5206\u89E3\u306B\u6E21\u305B\u308B\u3053\
    \u3068\u3082\u78BA\u304B\u3081\u308B\n    for (int rep = 0; rep < 1000 && ok;\
    \ rep++) {\n        int n = rng() % 9 + 1, m = n - 1 + rng() % 6;\n        Graph<int>\
    \ g(n);\n        std::vector<std::pair<int, int>> es;\n        for (int v = 1;\
    \ v < n; v++) {\n            int p = rng() % v;\n            g.add_edge(p, v),\
    \ es.emplace_back(p, v);\n        }\n        while (static_cast<int>(es.size())\
    \ < m) {\n            int u = rng() % n, v = rng() % n;\n            g.add_edge(u,\
    \ v), es.emplace_back(u, v);\n        }\n        LowLink ll(g);\n        HeavyLightDecomposition\
    \ hld(ll.block_cut_tree());\n        for (int u = 0; u < n; u++) {\n         \
    \   for (int v = 0; v < n; v++) {\n                if (u == v) continue;\n   \
    \             int must = 0;\n                for (int x = 0; x < n; x++) {\n \
    \                   if (x == u || x == v) continue;\n                    UnionFind\
    \ uf(n);\n                    for (auto [a, b] : es) {\n                     \
    \   if (a != x && b != x) uf.merge(a, b);\n                    }\n           \
    \         must += !uf.same(u, v);\n                }\n                // \u30D1\
    \u30B9\u306F \u5143\u306E\u9802\u70B9 - \u6210\u5206 - \u5143\u306E\u9802\u70B9\
    \ - ... \u3068\u4EA4\u4E92\u306B\u4E26\u3076\n                if (hld.dist(u,\
    \ v) / 2 - 1 != must) ok = false;\n            }\n        }\n    }\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/lowlink.hpp
  - src/graph/graph.hpp
  - src/graph/tree.hpp
  - src/graph/shortest-path.hpp
  - src/data_structures/unionfind.hpp
  - src/graph/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: test/unittest/graph/lowlink.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 01:35:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/lowlink.test.cpp
- /verify/test/unittest/graph/lowlink.test.cpp.html
title: test/unittest/graph/lowlink.test.cpp
---
