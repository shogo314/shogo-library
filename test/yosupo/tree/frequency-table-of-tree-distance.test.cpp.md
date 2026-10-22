---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/centroid-decomposition.hpp
    title: "\u91CD\u5FC3\u5206\u89E3"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/shortest-path.hpp
    title: "\u6700\u77ED\u8DEF"
  - icon: ':heavy_check_mark:'
    path: src/graph/tree.hpp
    title: "\u6728\u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
  - icon: ':heavy_check_mark:'
    path: src/math/convolution.hpp
    title: "\u7573\u307F\u8FBC\u307F (NTT)"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/math/modular-arithmetic.hpp
    title: "mod \u6F14\u7B97 (\u7A4D\u3001\u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\
      \u6563\u5BFE\u6570\u3001\u5E73\u65B9\u6839)"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/yosupo/tree/frequency-table-of-tree-distance.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/graph/centroid-decomposition.hpp\"\
    \n\n/**\n * @file centroid-decomposition.hpp\n * @brief \u91CD\u5FC3\u5206\u89E3\
    \n */\n\n#include <cassert>\n#include <utility>\n#line 11 \"src/graph/centroid-decomposition.hpp\"\
    \n\n#line 2 \"src/graph/tree.hpp\"\n\n/**\n * @file tree.hpp\n * @brief \u6728\
    \u306E\u6C4E\u7528\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n */\n\n#include <algorithm>\n\
    #line 10 \"src/graph/tree.hpp\"\n#include <stack>\n#include <type_traits>\n#line\
    \ 14 \"src/graph/tree.hpp\"\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file\
    \ graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 11 \"src/graph/graph.hpp\"\
    \n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n\
    \ * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B \u7701\u7565\u3057\
    \u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\u672A\u5230\u9054\u3092\
    \u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\u3088\u3046\u306B\
    )\n */\ntemplate <typename Cost = long long>\nclass Graph {\n   public:\n    /**\n\
    \     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator\
    \ long long()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u6574\
    \u6570\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306B\
    dst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e :\
    \ g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\
    \u6319\u3055\u308C\u308B\u304C\u3001\n     * for (long long dst : g[v]) \u3068\
    \u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\
    \u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n        long\
    \ long src = -1;  //!< \u59CB\u70B9\n        long long dst = -1;  //!< \u7D42\u70B9\
    \n        Cost cost = {};      //!< \u30B3\u30B9\u30C8\n        long long id =\
    \ -1;   //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\
    \u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\
    \u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\u3059\u308B)\n       \
    \ Edge() = default;\n        Edge(long long src, long long dst, Cost cost = 1,\
    \ long long id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n        operator\
    \ long long() const { return dst; }\n    };\n\n    long long n;              \
    \         //!< \u9802\u70B9\u6570\n    long long m;                       //!<\
    \ \u8FBA\u6570\n    std::vector<std::vector<Edge>> g;  //!< \u30B0\u30E9\u30D5\
    \u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief \u30C7\
    \u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n\
    \    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit\
    \ Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n     * @brief \u9802\u70B9\
    \u6570\n     */\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\
    \n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\
    \u3057\u305F\u30891\n     */\n    void add_edge(long long u, long long v, Cost\
    \ w = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        g[u].push_back({u,\
    \ v, w, m});\n        g[v].push_back({v, u, w, m++});\n    }\n    /**\n     *\
    \ @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\
    \u70B9\n     * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\
    \u7565\u3057\u305F\u30891\n     */\n    void add_directed_edge(long long u, long\
    \ long v, Cost w = 1) {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n\
    \        g[u].push_back({u, v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\
    \u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\
    \u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param m \u8FBA\u306E\u6570\n   \
    \  * @param padding \u9802\u70B9\u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\
    \u304F\u3064\u305A\u3089\u3059\u304B \u7701\u7565\u3057\u305F\u3089-1\n     *\
    \ @param weighted \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\u3055\u308C\u308B\
    \u304B \u7701\u7565\u3057\u305F\u3089false\u3068\u306A\u308A\u3001\u91CD\u307F\
    1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\u308C\u308B\n     * @param directed \u6709\
    \u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B \u7701\u7565\u3057\u305F\u3089\
    false\n     */\n    void read(long long m, long long padding = -1, bool weighted\
    \ = false, bool directed = false) {\n        for (long long i = 0; i < m; i++)\
    \ {\n            long long u, v;\n            std::cin >> u >> v;\n          \
    \  u += padding, v += padding;\n            Cost c(1);\n            if (weighted)\n\
    \                std::cin >> c;\n            if (directed)\n                add_directed_edge(u,\
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
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n#line 2 \"src/graph/shortest-path.hpp\"\
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
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n */\ntemplate <typename Cost = long long>\n\
    ShortestPath<Cost> shortest_path(const Graph<Cost>& graph, long long s, bool weighted\
    \ = true, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    assert(0 <=\
    \ s && s < graph.n);\n    if (weighted)\n        return internal_shortest_path::dijkstra(graph,\
    \ s, inf);\n    return internal_shortest_path::bfs(graph, s, inf);\n}\n\n/**\n\
    \ * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\n *\n * @param s \u59CB\u70B9\n * @param inf \u30B3\u30B9\u30C8\u306E\
    min\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\
    \u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
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
    \ \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n */\ntemplate\
    \ <typename Cost = long long>\nstd::vector<std::vector<Cost>> floyd_warshall(const\
    \ Graph<Cost>& graph, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n   \
    \ const long long n = graph.n;\n    std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n    for (long long i = 0; i < n; i++) dist[i][i] = Cost{};\n    for\
    \ (long long i = 0; i < n; i++) {\n        for (auto& e : graph[i]) dist[i][e.dst]\
    \ = std::min(dist[i][e.dst], e.cost);\n    }\n    for (long long k = 0; k < n;\
    \ k++) {\n        for (long long i = 0; i < n; i++) {\n            if (dist[i][k]\
    \ == inf) continue;\n            for (long long j = 0; j < n; j++) {\n       \
    \         if (dist[k][j] == inf) continue;\n                dist[i][j] = std::min(dist[i][j],\
    \ dist[i][k] + dist[k][j]);\n            }\n        }\n    }\n    return dist;\n\
    }\n#line 17 \"src/graph/tree.hpp\"\n\ntemplate <typename>\nclass RootedTree;\n\
    template <typename>\nclass DoublingClimbTree;\n\n/**\n * @brief \u6839\u306A\u3057\
    \u6728\n *\n * @tparam Cost = long long \u8FBA\u306E\u91CD\u307F\n *\n * Graph<Cost>\u3092\
    \u7D99\u627F\u3057\u3001\u3059\u3079\u3066\u7121\u5411\u8FBA\u3067\u8868\u3059\
    \n */\ntemplate <typename Cost = long long>\nstruct Tree : private Graph<Cost>\
    \ {\n    // Graph<Cost>* g = new Tree<Cost>(); \u304C\u3067\u304D\u3066\u3057\u307E\
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
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\n *\n * @tparam Cost = long\
    \ long \u8FBA\u306E\u30B3\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\n\
    class RootedTree : private Tree<Cost> {\n   public:\n    using Edge = typename\
    \ Tree<Cost>::Edge;\n    using Tree<Cost>::n;\n    using Tree<Cost>::size;\n \
    \   using Tree<Cost>::m;\n    using Tree<Cost>::g;\n    using Tree<Cost>::operator[];\n\
    \    using Tree<Cost>::edges;\n    using Tree<Cost>::graph;\n\n    long long root;\
    \                                           //!< \u6839\n    std::vector<Edge>\
    \ par;                                    //!< \u89AA\u3078\u5411\u304B\u3046\u8FBA\
    \n    std::vector<std::vector<Edge>> child;                     //!< \u5B50\u3078\
    \u5411\u304B\u3046\u8FBA\u306E\u30EA\u30B9\u30C8\n    std::vector<Cost> depth;\
    \                                  //!< \u6DF1\u3055\u306E\u30EA\u30B9\u30C8\n\
    \    std::vector<Cost> height;                                 //!< \u90E8\u5206\
    \u6728\u306E\u9AD8\u3055\u306E\u30EA\u30B9\u30C8\n    std::vector<long long> unweighted_depth;\
    \                  //!< \u91CD\u307F\u306A\u3057\u306E\u6DF1\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> unweighted_height;                 //!<\
    \ \u91CD\u307F\u306A\u3057\u306E\u90E8\u5206\u6728\u306E\u9AD8\u3055\u306E\u30EA\
    \u30B9\u30C8\n    std::vector<long long> sz;                                //!<\
    \ \u90E8\u5206\u6728\u306E\u9802\u70B9\u6570\u306E\u30EA\u30B9\u30C8\n    std::vector<long\
    \ long> preorder;                          //!< \u5148\u884C\u9806\u5DE1\u56DE\
    \n    std::vector<long long> postorder;                         //!< \u5F8C\u884C\
    \u9806\u5DE1\u56DE\n    std::vector<std::pair<long long, long long>> euler_tour;\
    \  //!< \u30AA\u30A4\u30E9\u30FC\u30C4\u30A2\u30FC DFS\u4E2D\u306B\u3068\u304A\
    \u3063\u305F\u9802\u70B9\u306E(\u9802\u70B9\u756A\u53F7,\u305D\u306E\u9802\u70B9\
    \u3092\u901A\u3063\u305F\u56DE\u6570)\u306E\u30EA\u30B9\u30C8\n\n    RootedTree()\
    \ = delete;\n\n    /**\n     * @brief \u89AA\u306E\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u304B\u3089\u6839\u304C0\u306E\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @tparam\
    \ T \u9802\u70B9\u756A\u53F7\u306E\u6574\u6570\u578B (long long \u3084 int)\n\
    \     * @param par_ \u9802\u70B90\u4EE5\u5916\u306E\u89AA\u306E\u9802\u70B9\u306E\
    \u30EA\u30B9\u30C8\n     * @param padding = -1 par\u306E\u9802\u70B9\u756A\u53F7\
    \u3092\u3044\u304F\u3064\u305A\u3089\u3059\u304B\n     */\n    template <typename\
    \ T = long long>\n    explicit RootedTree(const std::vector<T>& par_, long long\
    \ padding = -1) : Tree<Cost>(par_.size() + 1), root(0) {\n        static_assert(std::is_integral_v<T>,\
    \ \"RootedTree: par_ must be a vector of integers\");\n        for (long long\
    \ i = 0; i < static_cast<long long>(par_.size()); i++) {\n            this->add_edge(i\
    \ + 1, par_[i] + padding);\n        }\n        build();\n    }\n    /**\n    \
    \ * @brief Tree\u304B\u3089\u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\
    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u30B3\u30D4\u30FC)\n     *\n     *\
    \ @param tree Tree \u9802\u70B9\u65701\u4EE5\u4E0A\n     * @param root \u6839\n\
    \     */\n    RootedTree(const Tree<Cost>& tree, long long root) : Tree<Cost>(tree),\
    \ root(root) {\n        build();\n    }\n    /**\n     * @brief Tree\u304B\u3089\
    \u6839\u4ED8\u304D\u6728\u3092\u69CB\u7BC9\u3059\u308B\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF(\u30E0\u30FC\u30D6)\n     *\n     * @param tree Tree\n    \
    \ * @param root \u6839\n     */\n    RootedTree(Tree<Cost>&& tree, long long root)\
    \ : Tree<Cost>(std::move(tree)), root(root) {\n        build();\n    }\n\n   \
    \ /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
    \ \u30C0\u30D6\u30EA\u30F3\u30B0\u6E08\u307F\u6839\u4ED8\u304D\u6728\u306E\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\n     */\n    [[nodiscard]]\n    DoublingClimbTree<Cost>\
    \ build_lca() const& {\n        return DoublingClimbTree<Cost>(*this);\n    }\n\
    \n    /**\n     * @brief \u30C0\u30D6\u30EA\u30F3\u30B0LCA\u304C\u4F7F\u3048\u308B\
    \u6839\u4ED8\u304D\u6728\u3092\u5F97\u308B\n     *\n     * @return DoublingClimbTree<Cost>\
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
    \ Cost = long long \u8FBA\u306E\u91CD\u307F(\u6CE8: hop\u3067\u306F\u6839\u306E\
    \u91CD\u307F\u306F\u8003\u3048\u306A\u3044)\n */\ntemplate <typename Cost = long\
    \ long>\nclass DoublingClimbTree : private RootedTree<Cost> {\n   public:\n  \
    \  using Edge = typename RootedTree<Cost>::Edge;\n    using RootedTree<Cost>::n;\n\
    \    using RootedTree<Cost>::size;\n    using RootedTree<Cost>::m;\n    using\
    \ RootedTree<Cost>::g;\n    using RootedTree<Cost>::operator[];\n    using RootedTree<Cost>::edges;\n\
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
    \                }\n            }\n        }\n    }\n};\n#line 13 \"src/graph/centroid-decomposition.hpp\"\
    \n\n/**\n * @brief \u91CD\u5FC3\u5206\u89E3\n *\n * \u6728\u306E\u91CD\u5FC3\u3092\
    \u53D6\u308A\u9664\u3044\u3066\u3001\u6B8B\u3063\u305F\u90E8\u5206\u6728\u305D\
    \u308C\u305E\u308C\u3067\u540C\u3058\u3053\u3068\u3092\u304F\u308A\u8FD4\u3059\
    \u3002\u53D6\u308A\u9664\u3044\u305F\u91CD\u5FC3\u3092\u89AA\u5B50\u306B\u3057\
    \u305F\u6728 (\u91CD\u5FC3\u6728) \u306E\u6DF1\u3055\u306F O(log n)\n * \u91CD\
    \u5FC3 c \u306E\u6210\u5206 (c \u3092\u53D6\u308A\u9664\u304F\u76F4\u524D\u306B\
    \ c \u3092\u542B\u3093\u3067\u3044\u305F\u90E8\u5206\u6728) \u306F\u3001c \u304B\
    \u3089 level \u304C c \u3088\u308A\u5927\u304D\u3044\u9802\u70B9\u3060\u3051\u3092\
    \u305F\u3069\u3063\u3066\u5F97\u3089\u308C\u308B\n * \u524D\u8A08\u7B97 O(n log\
    \ n)\u3002DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n *\
    \ CentroidDecomposition cd(tree);  // tree \u306F Tree<Cost>\n * for (long long\
    \ c : cd.order()) {\n *     for (auto& sub : cd.subtrees(tree, c)) {\n *     \
    \    for (auto [v, d] : sub) { ... }  // c \u3092\u901A\u308B\u30D1\u30B9\u3092\
    \u3001c \u306E\u5148\u306E\u90E8\u5206\u6728\u3054\u3068\u306B\u6570\u3048\u308B\
    \n *     }\n * }\n */\nclass CentroidDecomposition {\n    long long n;\n    //\
    \ \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\u6301\u3061\u3001\u516C\u958B\
    \u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\u308B\n    std::vector<int>\
    \ par, lev;\n    std::vector<long long> ord;\n\n   public:\n    /**\n     * @brief\
    \ \u6728 tree \u3092\u91CD\u5FC3\u5206\u89E3\u3059\u308B\n     */\n    template\
    \ <typename Cost>\n    explicit CentroidDecomposition(const Tree<Cost>& tree)\
    \ : n(tree.size()), par(n, -1), lev(n, -1) {\n        ord.reserve(n);\n      \
    \  // \u6210\u5206\u306E\u9802\u70B9\u3092 1 \u3064\u3068\u3001\u305D\u306E\u6210\
    \u5206\u306E\u91CD\u5FC3\u306E\u89AA (\u91CD\u5FC3\u6728\u3067\u306E\u89AA) \u3092\
    \u7A4D\u3080\n        std::vector<std::pair<int, int>> st;\n        if (n > 0)\
    \ st.emplace_back(0, -1);\n        std::vector<int> bfs, bfs_par(n), sz(n);\n\
    \        while (!st.empty()) {\n            auto [s, p] = st.back();\n       \
    \     st.pop_back();\n            int depth = p == -1 ? 0 : lev[p] + 1;\n    \
    \        // s \u3092\u542B\u3080\u6210\u5206\u3092 BFS \u3067\u5217\u6319\u3059\
    \u308B (\u53D6\u308A\u9664\u3044\u305F\u9802\u70B9\u306F lev \u304C\u6C7A\u307E\
    \u3063\u3066\u3044\u308B)\n            bfs.assign(1, s);\n            bfs_par[s]\
    \ = -1;\n            for (int i = 0; i < static_cast<int>(bfs.size()); i++) {\n\
    \                int v = bfs[i];\n                for (long long u : tree[v])\
    \ {\n                    if (u == bfs_par[v] || lev[u] != -1) continue;\n    \
    \                bfs_par[u] = v;\n                    bfs.push_back(u);\n    \
    \            }\n            }\n            int total = bfs.size();\n         \
    \   for (int i = total - 1; i >= 0; i--) {\n                int v = bfs[i];\n\
    \                sz[v] = 1;\n                for (long long u : tree[v]) {\n \
    \                   if (u != bfs_par[v] && lev[u] == -1) sz[v] += sz[u];\n   \
    \             }\n            }\n            // s \u304B\u3089\u3001\u5927\u304D\
    \u3055\u304C\u534A\u5206\u3092\u8D85\u3048\u308B\u5B50\u306E\u65B9\u3078\u9032\
    \u3080\u3002\u9032\u3081\u306A\u304F\u306A\u3063\u305F\u3068\u3053\u308D\u304C\
    \u91CD\u5FC3\n            int c = s;\n            while (true) {\n           \
    \     int next = -1;\n                for (long long u : tree[c]) {\n        \
    \            if (u != bfs_par[c] && lev[u] == -1 && sz[u] * 2 > total) next =\
    \ u;\n                }\n                if (next == -1) break;\n            \
    \    c = next;\n            }\n            par[c] = p;\n            lev[c] = depth;\n\
    \            ord.push_back(c);\n            for (long long u : tree[c]) {\n  \
    \              if (lev[u] == -1) st.emplace_back(u, c);\n            }\n     \
    \   }\n        assert(static_cast<long long>(ord.size()) == n && \"CentroidDecomposition:\
    \ not connected\");\n    }\n\n    /**\n     * @brief \u9802\u70B9\u6570\u3092\u8FD4\
    \u3059\n     */\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ \u91CD\u5FC3\u6728\u306E\u6839 (\u6700\u521D\u306B\u53D6\u308A\u9664\u3044\u305F\
    \u91CD\u5FC3)\n     */\n    long long root() const {\n        assert(n > 0);\n\
    \        return ord[0];\n    }\n    /**\n     * @brief \u91CD\u5FC3\u6728\u3067\
    \u306E v \u306E\u89AA (\u6839\u306A\u3089 -1)\n     */\n    long long parent(long\
    \ long v) const {\n        assert(0 <= v && v < n);\n        return par[v];\n\
    \    }\n    /**\n     * @brief \u91CD\u5FC3\u6728\u3067\u306E v \u306E\u6DF1\u3055\
    \ (\u6839\u306A\u3089 0)\u3002O(log n) \u4EE5\u4E0B\u306B\u306A\u308B\n     */\n\
    \    long long level(long long v) const {\n        assert(0 <= v && v < n);\n\
    \        return lev[v];\n    }\n    /**\n     * @brief \u91CD\u5FC3\u3092\u53D6\
    \u308A\u9664\u3044\u305F\u9806\u306B\u4E26\u3079\u305F\u5217 (\u91CD\u5FC3\u6728\
    \u306E\u89AA\u306F\u5B50\u3088\u308A\u524D\u306B\u3042\u308B)\n     */\n    const\
    \ std::vector<long long>& order() const { return ord; }\n\n    /**\n     * @brief\
    \ \u91CD\u5FC3 c \u306E\u6210\u5206\u304B\u3089 c \u3092\u53D6\u308A\u9664\u3044\
    \u305F\u3001\u305D\u308C\u305E\u308C\u306E\u90E8\u5206\u6728\u306E (\u9802\u70B9\
    , c \u304B\u3089\u306E\u8DDD\u96E2) \u306E\u4E00\u89A7\u3092\u8FD4\u3059\n   \
    \  *\n     * \u8DDD\u96E2\u306F\u8FBA\u306E\u91CD\u307F\u306E\u548C (\u91CD\u307F\
    \u306A\u3057\u3067\u8AAD\u3093\u3060\u6728\u306A\u3089\u8FBA\u306E\u6570)\u3002\
    \u3059\u3079\u3066\u306E c \u3067\u5408\u308F\u305B\u3066 O(n log n)\n     */\n\
    \    template <typename Cost>\n    std::vector<std::vector<std::pair<long long,\
    \ Cost>>> subtrees(const Tree<Cost>& tree, long long c) const {\n        assert(0\
    \ <= c && c < n);\n        std::vector<std::vector<std::pair<long long, Cost>>>\
    \ res;\n        for (const auto& e : tree[c]) {\n            if (lev[e.dst] <=\
    \ lev[c]) continue;\n            // c \u306E\u5148\u306E\u90E8\u5206\u6728\u3092\
    \u3001\u89AA\u3092\u305F\u3069\u3089\u306A\u3044\u3088\u3046\u306B BFS \u3059\u308B\
    \n            std::vector<std::pair<long long, Cost>> sub = {{e.dst, e.cost}};\n\
    \            std::vector<long long> from = {c};\n            for (int i = 0; i\
    \ < static_cast<int>(sub.size()); i++) {\n                auto [v, d] = sub[i];\n\
    \                for (const auto& f : tree[v]) {\n                    if (f.dst\
    \ == from[i] || lev[f.dst] <= lev[c]) continue;\n                    sub.emplace_back(f.dst,\
    \ d + f.cost);\n                    from.push_back(v);\n                }\n  \
    \          }\n            res.push_back(std::move(sub));\n        }\n        return\
    \ res;\n    }\n};\n#line 2 \"src/math/convolution.hpp\"\n\n/**\n * @file convolution.hpp\n\
    \ * @brief \u7573\u307F\u8FBC\u307F (NTT)\n */\n\n#line 9 \"src/math/convolution.hpp\"\
    \n#include <array>\n#include <cstdint>\n#line 14 \"src/math/convolution.hpp\"\n\
    \n#line 2 \"src/math/modint.hpp\"\n\n/**\n * @file modint.hpp\n * @brief \u56DB\
    \u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\
    \u30AF\u30E9\u30B9\n */\n\n#line 14 \"src/math/modint.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
    \n\n/**\n * @file traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n\
    #include <iterator>\n#include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace\
    \ internal_traits {\nusing std::begin, std::end;\n\ntemplate <class T, class =\
    \ void>\nstruct is_range_impl : std::false_type {};\ntemplate <class T>\nstruct\
    \ is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()), end(std::declval<T&>()))>>\
    \ : std::true_type {};\n}  // namespace internal_traits\n\ntemplate <class T>\n\
    struct is_range : internal_traits::is_range_impl<T>::type {};\ntemplate <class\
    \ T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\n#define HAS_METHOD(func_name)\
    \                                                              \\\n    namespace\
    \ internal_traits {                                                          \
    \  \\\n    template <class T, class = void>                                  \
    \                     \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                    \\\n    template <class T>          \
    \                                                           \\\n    struct has_##func_name##_impl<T,\
    \ std::void_t<decltype(std::declval<T>().func_name())>> \\\n        : std::true_type\
    \ {};                                                               \\\n    }\
    \                                                                            \
    \          \\\n    template <class T>                                        \
    \                             \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T>::type\
    \ {};          \\\n    template <class T>                                    \
    \                                 \\\n    inline constexpr bool has_##func_name##_v\
    \ = has_##func_name<T>::value;\n\n#define HAS_METHOD_ARG(func_name)          \
    \                                                                    \\\n    namespace\
    \ internal_traits {                                                          \
    \                      \\\n    template <class T, typename U, class = void>  \
    \                                                             \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                                      \
    \  \\\n    template <class T, typename U>                                    \
    \                                         \\\n    struct has_##func_name##_impl<T,\
    \ U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>> \\\
    \n        : std::true_type {};                                               \
    \                                    \\\n    }                               \
    \                                                                           \\\
    \n    template <class T, typename U>                                         \
    \                                    \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 2 \"src/math/modular-arithmetic.hpp\"\
    \n\n/**\n * @file modular-arithmetic.hpp\n * @brief mod \u6F14\u7B97 (\u7A4D\u3001\
    \u51AA\u4E57\u3001\u9006\u5143\u3001\u96E2\u6563\u5BFE\u6570\u3001\u5E73\u65B9\
    \u6839)\n */\n\n#line 10 \"src/math/modular-arithmetic.hpp\"\n#include <cmath>\n\
    #include <numeric>\n#include <unordered_map>\n\n/**\n * @brief a * b mod m \u3092\
    \u8FD4\u3059 (\u9014\u4E2D\u3067 __int128 \u3092\u4F7F\u3046\u306E\u3067 m < 2^63\
    \ \u306A\u3089\u3042\u3075\u308C\u306A\u3044)\n */\nconstexpr long long modmul(long\
    \ long a, long long b, long long m) {\n    long long res = static_cast<long long>(static_cast<__int128>(a)\
    \ * b % m);\n    if (res < 0) res += m;\n    return res;\n}\n\n/**\n * @brief\
    \ a^(-1) mod m \u3092\u8FD4\u3059\n * @note a \u3068 m \u306F\u4E92\u3044\u306B\
    \u7D20\u3067\u3042\u308B\u3053\u3068\u3002O(log m)\n */\nconstexpr long long modinv(long\
    \ long a, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a +=\
    \ m;\n    long long b = m, u = 1, v = 0;\n    while (b) {\n        // std::swap\
    \ \u306F C++17 \u3067\u306F constexpr \u3067\u306A\u3044\u306E\u3067\u3001\u4F7F\
    \u308F\u305A\u306B\u66F8\u304F\n        long long t = a / b;\n        long long\
    \ c = a - t * b;\n        a = b, b = c;\n        long long w = u - t * v;\n  \
    \      u = v, v = w;\n    }\n    assert(a == 1 && \"a and m must be coprime\"\
    );\n    u %= m;\n    if (u < 0) u += m;\n    return u;\n}\n\n/**\n * @brief a^n\
    \ mod m \u3092\u8FD4\u3059\n * @note n \u304C\u8CA0\u306A\u3089 a^(-1) \u306E\
    \ -n \u4E57 (a \u3068 m \u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\
    \u3068)\u3002O(log |n|)\n */\nconstexpr long long modpow(long long a, long long\
    \ n, long long m) {\n    assert(m >= 1);\n    a %= m;\n    if (a < 0) a += m;\n\
    \    if (n < 0) {\n        n = -n;\n        a = modinv(a, m);\n    }\n    long\
    \ long res = 1 % m;\n    while (n > 0) {\n        if (n & 1) res = modmul(res,\
    \ a, m);\n        a = modmul(a, a, m);\n        n >>= 1;\n    }\n    return res;\n\
    }\n\n/**\n * @brief a^x \u2261 b (mod m) \u3068\u306A\u308B\u6700\u5C0F\u306E\
    \ x >= 0 (\u306A\u3051\u308C\u3070 -1)\n * @note a \u3068 m \u306F\u4E92\u3044\
    \u306B\u7D20\u3067\u306A\u304F\u3066\u3082\u3088\u3044\u3002Baby-step Giant-step\
    \ \u3067 O(\u221Am) \u306E\u6642\u9593\u3068\u30E1\u30E2\u30EA\n */\ninline long\
    \ long discrete_log(long long a, long long b, long long m) {\n    assert(m >=\
    \ 1);\n    a %= m, b %= m;\n    if (a < 0) a += m;\n    if (b < 0) b += m;\n \
    \   if (m == 1) return 0;\n    // a \u3068 m \u304C\u4E92\u3044\u306B\u7D20\u306B\
    \u306A\u308B\u307E\u3067\u4E21\u8FBA\u3092 gcd \u3067\u5272\u308B\u3002k = a^add\
    \ / (\u5272\u3063\u305F gcd \u306E\u7A4D) mod m\n    long long k = 1, add = 0,\
    \ g;\n    while ((g = std::gcd(a, m)) > 1) {\n        if (b == k) return add;\n\
    \        if (b % g != 0) return -1;\n        b /= g, m /= g, add++;\n        k\
    \ = modmul(k, a / g, m);\n    }\n    // k a^x \u2261 b \u3092 x = n p - q (1 <=\
    \ p <= n\u30010 <= q <= n) \u3068\u66F8\u3044\u3066\u89E3\u304F\n    const long\
    \ long n = static_cast<long long>(std::sqrt(static_cast<long double>(m))) + 1;\n\
    \    std::unordered_map<long long, long long> baby;\n    baby.reserve(2 * n +\
    \ 2);\n    // b a^q \u3092 q \u306E\u5C0F\u3055\u3044\u9806\u306B\u5165\u308C\u3001\
    \u540C\u3058\u5024\u306A\u3089\u5927\u304D\u3044 q \u3067\u4E0A\u66F8\u304D\u3059\
    \u308B (x \u3092\u5C0F\u3055\u304F\u3059\u308B\u305F\u3081)\n    for (long long\
    \ q = 0, cur = b; q <= n; q++, cur = modmul(cur, a, m)) baby[cur] = q;\n    const\
    \ long long an = modpow(a, n, m);\n    for (long long p = 1, cur = k; p <= n;\
    \ p++) {\n        cur = modmul(cur, an, m);\n        auto it = baby.find(cur);\n\
    \        if (it != baby.end()) return n * p - it->second + add;\n    }\n    return\
    \ -1;\n}\n\n/**\n * @brief \u7D20\u6570 p \u306B\u3064\u3044\u3066 x^2 \u2261\
    \ a (mod p) \u3068\u306A\u308B x \u306E\u3046\u3061\u5C0F\u3055\u3044\u65B9 (\u306A\
    \u3051\u308C\u3070 -1)\n * @note \u3082\u3046\u4E00\u65B9\u306E\u89E3\u306F p\
    \ - x\u3002Tonelli-Shanks \u3067 O(log^2 p)\n */\ninline long long sqrt_mod(long\
    \ long a, long long p) {\n    assert(p >= 2);\n    a %= p;\n    if (a < 0) a +=\
    \ p;\n    if (a == 0 || p == 2) return a;\n    // \u30AA\u30A4\u30E9\u30FC\u306E\
    \u898F\u6E96: a^((p-1)/2) \u304C 1 \u3067\u306A\u3051\u308C\u3070\u5E73\u65B9\u975E\
    \u5270\u4F59\n    if (modpow(a, (p - 1) / 2, p) != 1) return -1;\n    long long\
    \ q = p - 1, s = 0;\n    while (q % 2 == 0) q /= 2, s++;\n    // \u5E73\u65B9\u975E\
    \u5270\u4F59 z \u3092\u63A2\u3059\n    long long z = 2;\n    while (modpow(z,\
    \ (p - 1) / 2, p) != p - 1) z++;\n    long long c = modpow(z, q, p), t = modpow(a,\
    \ q, p), r = modpow(a, (q + 1) / 2, p);\n    // r^2 = a t \u3092\u4FDD\u3061\u306A\
    \u304C\u3089\u3001t \u306E\u4F4D\u6570\u3092\u4E0B\u3052\u3066\u3044\u304F\n \
    \   while (t != 1) {\n        long long i = 0, tt = t;\n        while (tt != 1)\
    \ tt = modmul(tt, tt, p), i++;\n        long long b = c;\n        for (long long\
    \ j = 0; j < s - i - 1; j++) b = modmul(b, b, p);\n        s = i;\n        c =\
    \ modmul(b, b, p);\n        t = modmul(t, c, p);\n        r = modmul(r, b, p);\n\
    \    }\n    return std::min(r, p - r);\n}\n#line 17 \"src/math/convolution.hpp\"\
    \n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\n */\nnamespace internal_convolution\
    \ {\n/**\n * @brief \u539F\u5B50\u6839\n * @param MOD int\n * @return int\n */\n\
    inline int calc_primitive_root(int MOD) {\n    if (MOD == 2) return 1;\n    if\
    \ (MOD == 167772161) return 3;\n    if (MOD == 469762049) return 3;\n    if (MOD\
    \ == 754974721) return 11;\n    if (MOD == 998244353) return 3;\n    int divs[20]\
    \ = {};\n    divs[0] = 2;\n    int cnt = 1;\n    long long x = (MOD - 1) >> 1;\n\
    \    while (x % 2 == 0) x >>= 1;\n    for (long long i = 3; i * i <= x; i += 2)\
    \ {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n            while\
    \ (x % i == 0) x /= i;\n        }\n    }\n    if (x > 1) divs[cnt++] = x;\n  \
    \  for (int g = 2;; ++g) {\n        bool ok = true;\n        for (int i = 0; i\
    \ < cnt; i++) {\n            if (modpow(g, (MOD - 1) / divs[i], MOD) == 1) {\n\
    \                ok = false;\n                break;\n            }\n        }\n\
    \        if (ok) return g;\n    }\n}\n\n/**\n * @brief \u7573\u307F\u8FBC\u307F\
    \u306E\u30B5\u30A4\u30BA\u30922\u306E\u3079\u304D\u4E57\u306B\u3059\u308B\n */\n\
    inline int get_fft_size(int N, int M) {\n    int size = 1;\n    while (size <\
    \ N + M - 1) size <<= 1;\n    return size;\n}\n\n/**\n * @brief x \u306E\u672B\
    \u5C3E\u306E 0 \u306E\u500B\u6570 (x > 0)\n */\nconstexpr int countr_zero(unsigned\
    \ int x) {\n    int k = 0;\n    while (!(x & 1)) x >>= 1, k++;\n    return k;\n\
    }\n\ntemplate <class T>\nstruct is_static_modint : std::false_type {};\ntemplate\
    \ <std::uint32_t Mod>\nstruct is_static_modint<static_modint<Mod>> : std::true_type\
    \ {};\n\n/**\n * @brief NTT \u306E\u56DE\u8EE2\u56E0\u5B50\u306E\u8868 (AtCoder\
    \ Library \u3068\u540C\u3058\u4F5C\u308A)\n *\n * root[i] \u306F 1 \u306E\u539F\
    \u59CB 2^i \u4E57\u6839\u3001rate2\u30FBrate3 \u306F\u57FA\u6570 2\u30FB4 \u306E\
    \u30D0\u30BF\u30D5\u30E9\u30A4\u3067\u6B21\u306E\u30D6\u30ED\u30C3\u30AF\u306B\
    \u9032\u3080\u3068\u304D\u306B\u639B\u3051\u308B\u5024\n */\ntemplate <class mint>\n\
    struct FFTInfo {\n    static constexpr int rank2 = countr_zero(mint::mod() - 1);\n\
    \    std::array<mint, rank2 + 1> root, iroot;\n    std::array<mint, std::max(0,\
    \ rank2 - 1)> rate2, irate2;\n    std::array<mint, std::max(0, rank2 - 2)> rate3,\
    \ irate3;\n\n    FFTInfo() {\n        const mint g = calc_primitive_root(mint::mod());\n\
    \        root[rank2] = g.pow((mint::mod() - 1) >> rank2);\n        iroot[rank2]\
    \ = root[rank2].inv();\n        for (int i = rank2 - 1; i >= 0; i--) {\n     \
    \       root[i] = root[i + 1] * root[i + 1];\n            iroot[i] = iroot[i +\
    \ 1] * iroot[i + 1];\n        }\n        mint prod = 1, iprod = 1;\n        for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n            rate2[i] = root[i + 2] * prod;\n\
    \            irate2[i] = iroot[i + 2] * iprod;\n            prod *= iroot[i +\
    \ 2];\n            iprod *= root[i + 2];\n        }\n        prod = 1, iprod =\
    \ 1;\n        for (int i = 0; i <= rank2 - 3; i++) {\n            rate3[i] = root[i\
    \ + 3] * prod;\n            irate3[i] = iroot[i + 3] * iprod;\n            prod\
    \ *= iroot[i + 3];\n            iprod *= root[i + 3];\n        }\n    }\n};\n\n\
    /**\n * @brief NTT (\u30D3\u30C3\u30C8\u53CD\u8EE2\u306E\u4E26\u3079\u66FF\u3048\
    \u3092\u3057\u306A\u3044\u3002\u7D50\u679C\u306F\u30D3\u30C3\u30C8\u53CD\u8EE2\
    \u3057\u305F\u9806\u306B\u4E26\u3076)\u3002\u57FA\u6570 4 \u306E\u30D0\u30BF\u30D5\
    \u30E9\u30A4\u3092\u4F7F\u3046\n * a \u306E\u9577\u3055\u306F 2 \u306E\u3079\u304D\
    \u4E57\u3067\u30012^rank2 \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068\n */\ntemplate\
    \ <class mint>\nvoid butterfly(std::vector<mint>& a) {\n    const int n = static_cast<int>(a.size());\n\
    \    const int h = countr_zero(n);\n    static const FFTInfo<mint> info;\n   \
    \ int len = 0;  // a[i, i + (n >> len), i + 2 * (n >> len), ...] \u306F\u5909\u63DB\
    \u6E08\u307F\n    while (len < h) {\n        if (h - len == 1) {\n           \
    \ int p = 1 << (h - len - 1);\n            mint rot = 1;\n            for (int\
    \ s = 0; s < (1 << len); s++) {\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    mint l = a[i\
    \ + offset], r = a[i + offset + p] * rot;\n                    a[i + offset] =\
    \ l + r;\n                    a[i + offset + p] = l - r;\n                }\n\
    \                if (s + 1 != (1 << len)) rot *= info.rate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len++;\n        } else {\n          \
    \  int p = 1 << (h - len - 2);\n            mint rot = 1, imag = info.root[2];\n\
    \            const unsigned long long mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \            for (int s = 0; s < (1 << len); s++) {\n                mint rot2\
    \ = rot * rot, rot3 = rot2 * rot;\n                int offset = s << (h - len);\n\
    \                for (int i = 0; i < p; i++) {\n                    unsigned long\
    \ long a0 = a[i + offset].val();\n                    unsigned long long a1 =\
    \ 1ULL * a[i + offset + p].val() * rot.val();\n                    unsigned long\
    \ long a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n               \
    \     unsigned long long a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n\
    \                    unsigned long long a1na3imag = 1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    unsigned long long na2 = mod2 - a2;\n   \
    \                 a[i + offset] = mint(a0 + a2 + a1 + a3);\n                 \
    \   a[i + offset + p] = mint(a0 + a2 + (2 * mod2 - (a1 + a3)));\n            \
    \        a[i + offset + 2 * p] = mint(a0 + na2 + a1na3imag);\n               \
    \     a[i + offset + 3 * p] = mint(a0 + na2 + (mod2 - a1na3imag));\n         \
    \       }\n                if (s + 1 != (1 << len)) rot *= info.rate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len += 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief butterfly \u306E\u9006\u5909\u63DB (n \u3067\u5272\u3089\u306A\u3044\
    )\n */\ntemplate <class mint>\nvoid butterfly_inv(std::vector<mint>& a) {\n  \
    \  const int n = static_cast<int>(a.size());\n    const int h = countr_zero(n);\n\
    \    static const FFTInfo<mint> info;\n    int len = h;\n    while (len) {\n \
    \       if (len == 1) {\n            int p = 1 << (h - len);\n            mint\
    \ irot = 1;\n            for (int s = 0; s < (1 << (len - 1)); s++) {\n      \
    \          int offset = s << (h - len + 1);\n                for (int i = 0; i\
    \ < p; i++) {\n                    mint l = a[i + offset], r = a[i + offset +\
    \ p];\n                    a[i + offset] = l + r;\n                    a[i + offset\
    \ + p] = mint(1ULL * (mint::mod() + l.val() - r.val()) * irot.val());\n      \
    \          }\n                if (s + 1 != (1 << (len - 1))) irot *= info.irate2[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len--;\n        } else {\n          \
    \  int p = 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n\
    \            for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint\
    \ irot2 = irot * irot, irot3 = irot2 * irot;\n                int offset = s <<\
    \ (h - len + 2);\n                for (int i = 0; i < p; i++) {\n            \
    \        unsigned long long a0 = a[i + offset].val();\n                    unsigned\
    \ long long a1 = a[i + offset + p].val();\n                    unsigned long long\
    \ a2 = a[i + offset + 2 * p].val();\n                    unsigned long long a3\
    \ = a[i + offset + 3 * p].val();\n                    unsigned long long a2na3iimag\
    \ = mint((mint::mod() + a2 - a3) * iimag.val()).val();\n                    a[i\
    \ + offset] = mint(a0 + a1 + a2 + a3);\n                    a[i + offset + p]\
    \ = mint((a0 + (mint::mod() - a1) + a2na3iimag) * irot.val());\n             \
    \       a[i + offset + 2 * p] = mint((a0 + a1 + (mint::mod() - a2) + (mint::mod()\
    \ - a3)) * irot2.val());\n                    a[i + offset + 3 * p] = mint((a0\
    \ + (mint::mod() - a1) + (mint::mod() - a2na3iimag)) * irot3.val());\n       \
    \         }\n                if (s + 1 != (1 << (len - 2))) irot *= info.irate3[countr_zero(~static_cast<unsigned\
    \ int>(s))];\n            }\n            len -= 2;\n        }\n    }\n}\n\n/**\n\
    \ * @brief NTT \u3067\u7573\u307F\u8FBC\u3080 (\u6CD5\u306F\u7D20\u6570\u3067\u3001\
    \u9577\u3055 N + M - 1 \u4EE5\u4E0A\u306E 2 \u306E\u3079\u304D\u4E57\u304C 2^rank2\
    \ \u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068)\n * same \u306A\u3089 B \u306F A\
    \ \u3068\u540C\u3058\u3068\u307F\u306A\u3057\u3001\u5909\u63DB\u3092 1 \u56DE\u7701\
    \u304F\n */\ntemplate <class mint>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b, bool same = false) {\n    const int n = static_cast<int>(a.size()),\
    \ m = static_cast<int>(b.size());\n    const int z = get_fft_size(n, m);\n   \
    \ a.resize(z);\n    butterfly(a);\n    if (same) {\n        for (int i = 0; i\
    \ < z; i++) a[i] *= a[i];\n    } else {\n        b.resize(z);\n        butterfly(b);\n\
    \        for (int i = 0; i < z; i++) a[i] *= b[i];\n    }\n    butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    const mint iz = mint(z).inv();\n    for (int i\
    \ = 0; i < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n/**\n * @brief mint\
    \ \u3067\u76F4\u63A5 NTT \u3067\u304D\u308B\u304B (static_modint \u3067\u3001\u6CD5\
    \u304C\u7D20\u6570\u3067\u30012^rank2 \u304C\u9577\u3055 z \u4EE5\u4E0A)\n */\n\
    template <class mint>\nconstexpr bool ntt_friendly(int z) {\n    if constexpr\
    \ (is_static_modint<mint>::value) {\n        return internal_modint::is_prime32(mint::mod())\
    \ && mint::mod() > 2 && (mint::mod() - 1) % z == 0;\n    } else {\n        return\
    \ false;\n    }\n}\n\nstatic constexpr int MOD0 = 754974721;\nstatic constexpr\
    \ int MOD1 = 167772161;\nstatic constexpr int MOD2 = 469762049;\nusing mint0 =\
    \ static_modint<MOD0>;\nusing mint1 = static_modint<MOD1>;\nusing mint2 = static_modint<MOD2>;\n\
    static const mint1 imod0 = 95869806;    // modinv(MOD0, MOD1);\nstatic const mint2\
    \ imod1 = 104391568;   // modinv(MOD1, MOD2);\nstatic const mint2 imod01 = 187290749;\
    \  // imod1 / MOD0;\n\n/**\n * @brief \u914D\u5217\u306E\u30B5\u30A4\u30BA\u304C\
    \u5C0F\u3055\u3044\u3068\u304D\u306E\u7573\u307F\u8FBC\u307F\n * @param T mint,\
    \ long long\n * @param A vector<T>\n * @param B vector<T>\n * @return vector<T>\n\
    \ */\ntemplate <class T>\nstd::vector<T> naive(const std::vector<T>& A, const\
    \ std::vector<T>& B) {\n    if (A.empty() || B.empty()) return {};\n    int N\
    \ = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n    std::vector<T>\
    \ res(N + M - 1);\n    for (int i = 0; i < N; ++i)\n        for (int j = 0; j\
    \ < M; ++j)\n            res[i + j] += A[i] * B[j];\n    return res;\n}\n};  //\
    \ namespace internal_convolution\n\nnamespace internal_convolution {\n/**\n *\
    \ @brief 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\u3067\u5024 (0 \u4EE5\u4E0A MOD0 MOD1 MOD2 \u672A\u6E80) \u3092\
    \u5FA9\u5143\u3059\u308B\n * \u5024\u306F y0 + y1 MOD0 + y2 MOD0 MOD1 (0 <= y0\
    \ < MOD0\u30010 <= y1 < MOD1\u30010 <= y2 < MOD2) \u306E\u5F62\u306B\u306A\u308A\
    \u3001\u5404\u9805\u3092 f(y0, y1, y2) \u3067\u7D44\u307F\u7ACB\u3066\u308B\n\
    \ * A \u3068 B \u304C\u540C\u3058\u914D\u5217\u306A\u3089\u3001\u5909\u63DB\u3092\
    \ 1 \u56DE\u7701\u304F\n */\ntemplate <class T, class R, class F>\nstd::vector<R>\
    \ convolution_crt(const std::vector<T>& A, const std::vector<T>& B, F f) {\n \
    \   const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    std::vector<mint0> a0(N), b0(M);\n    std::vector<mint1> a1(N), b1(M);\n\
    \    std::vector<mint2> a2(N), b2(M);\n    for (int i = 0; i < N; ++i) a0[i] =\
    \ A[i], a1[i] = A[i], a2[i] = A[i];\n    for (int i = 0; i < M; ++i) b0[i] = B[i],\
    \ b1[i] = B[i], b2[i] = B[i];\n    const bool same = &A == &B;\n    auto c0 =\
    \ convolution_fft(std::move(a0), std::move(b0), same);\n    auto c1 = convolution_fft(std::move(a1),\
    \ std::move(b1), same);\n    auto c2 = convolution_fft(std::move(a2), std::move(b2),\
    \ same);\n    std::vector<R> res(N + M - 1);\n    for (int i = 0; i < N + M -\
    \ 1; ++i) {\n        unsigned int y0 = c0[i].val();\n        unsigned int y1 =\
    \ (imod0 * (c1[i] - y0)).val();\n        unsigned int y2 = (imod01 * (c2[i] -\
    \ y0) - imod1 * y1).val();\n        res[i] = f(y0, y1, y2);\n    }\n    return\
    \ res;\n}\n}  // namespace internal_convolution\n\n/**\n * @brief modint\u306E\
    \u7573\u307F\u8FBC\u307F\n *\n * static_modint \u3067\u6CD5\u304C NTT \u306B\u5411\
    \u304F\u7D20\u6570 (998244353 \u306A\u3069) \u306A\u3089\u3001\u305D\u306E\u6CD5\
    \u3067\u76F4\u63A5 NTT \u3059\u308B\u3002\n * \u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 3 \u3064\u306E\u6CD5\u3067\u7573\u307F\u8FBC\u307F\u3001\u4E2D\u56FD\u5270\
    \u4F59\u5B9A\u7406\u3067\u5FA9\u5143\u3059\u308B\n * @param A vector<mint>\n *\
    \ @param B vector<mint>\n * @return vector<mint>\n */\ntemplate <class mint>\n\
    std::vector<mint> convolution(const std::vector<mint>& A, const std::vector<mint>&\
    \ B) {\n    if (A.empty() || B.empty()) return {};\n    const int N = static_cast<int>(A.size()),\
    \ M = static_cast<int>(B.size());\n    if (std::min(N, M) <= 60) return internal_convolution::naive(A,\
    \ B);\n    const int z = internal_convolution::get_fft_size(N, M);\n    if constexpr\
    \ (internal_convolution::is_static_modint<mint>::value) {\n        if (internal_convolution::ntt_friendly<mint>(z))\
    \ return internal_convolution::convolution_fft(A, B, &A == &B);\n    }\n    std::vector<unsigned\
    \ int> a(N), b(M);\n    for (int i = 0; i < N; ++i) a[i] = A[i].val();\n    for\
    \ (int i = 0; i < M; ++i) b[i] = B[i].val();\n    const mint mod0 = internal_convolution::MOD0,\
    \ mod01 = mod0 * internal_convolution::MOD1;\n    return internal_convolution::convolution_crt<unsigned\
    \ int, mint>(a, &A == &B ? a : b, [&](unsigned int y0, unsigned int y1, unsigned\
    \ int y2) {\n        return mod01 * y2 + mod0 * y1 + y0;\n    });\n}\n\n/**\n\
    \ * @brief long long\u306E\u7573\u307F\u8FBC\u307F\n * \u7D50\u679C\u306E\u5404\
    \u9805\u306E\u7D76\u5BFE\u5024\u304C MOD0 MOD1 MOD2 / 2 (\u7D04 3 * 10^25) \u672A\
    \u6E80\u3067\u3001long long \u306B\u53CE\u307E\u308B\u3053\u3068\n * @param A\
    \ vector<long long>\n * @param B vector<long long>\n * @return vector<long long>\n\
    \ */\ninline std::vector<long long> convolution_ll(const std::vector<long long>&\
    \ A, const std::vector<long long>& B) {\n    if (A.empty() || B.empty()) return\
    \ {};\n    const int N = static_cast<int>(A.size()), M = static_cast<int>(B.size());\n\
    \    if (std::min(N, M) <= 60) return internal_convolution::naive(A, B);\n   \
    \ static const long long mod0 = internal_convolution::MOD0, mod01 = mod0 * internal_convolution::MOD1;\n\
    \    static const __int128_t mod012 = static_cast<__int128_t>(mod01) * internal_convolution::MOD2;\n\
    \    return internal_convolution::convolution_crt<long long, long long>(A, B,\
    \ [&](unsigned int y0, unsigned int y1, unsigned int y2) {\n        __int128_t\
    \ tmp = static_cast<__int128_t>(mod01) * y2 + static_cast<__int128_t>(mod0) *\
    \ y1 + y0;\n        return static_cast<long long>(tmp < (mod012 >> 1) ? tmp :\
    \ tmp - mod012);\n    });\n}\n#line 8 \"test/yosupo/tree/frequency-table-of-tree-distance.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    long long n;\n    std::cin >> n;\n    Tree<int> tree(n);\n    tree.read(0);\n\
    \    CentroidDecomposition cd(tree);\n    std::vector<long long> ans(n, 0);\n\
    \    // cnt[d] \u306F\u8DDD\u96E2 d \u306E\u9802\u70B9\u306E\u500B\u6570\u3002\
    \u81EA\u5206\u81EA\u8EAB\u3068\u306E\u7573\u307F\u8FBC\u307F\u3067\u3001\u8DDD\
    \u96E2\u306E\u548C\u3054\u3068\u306E\u7D44\u306E\u500B\u6570\u306B\u306A\u308B\
    \n    auto add = [&](const std::vector<long long>& cnt, long long sign) {\n  \
    \      auto sq = convolution_ll(cnt, cnt);\n        for (long long d = 0; d <\
    \ static_cast<long long>(sq.size()) && d < n; d++) ans[d] += sign * sq[d];\n \
    \   };\n    for (long long c : cd.order()) {\n        std::vector<long long> all\
    \ = {1};  // c \u81EA\u8EAB\n        for (const auto& sub : cd.subtrees(tree,\
    \ c)) {\n            std::vector<long long> cnt;\n            for (auto [v, d]\
    \ : sub) {\n                if (static_cast<long long>(cnt.size()) <= d) cnt.resize(d\
    \ + 1);\n                if (static_cast<long long>(all.size()) <= d) all.resize(d\
    \ + 1);\n                cnt[d]++;\n                all[d]++;\n            }\n\
    \            // \u540C\u3058\u90E8\u5206\u6728\u306E\u4E2D\u306E 2 \u9802\u70B9\
    \u3092\u7D50\u3076\u30D1\u30B9\u306F c \u3092\u901A\u3089\u306A\u3044\u306E\u3067\
    \u5F15\u304F\n            add(cnt, -1);\n        }\n        add(all, 1);\n   \
    \ }\n    // \u9806\u5E8F\u4ED8\u304D\u306E\u7D44\u3092\u6570\u3048\u305F\u306E\
    \u3067 2 \u3067\u5272\u308B\n    for (long long d = 1; d < n; d++) std::cout <<\
    \ ans[d] / 2 << \" \\n\"[d + 1 == n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/graph/centroid-decomposition.hpp\"\
    \n#include \"../../../src/math/convolution.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    long long n;\n    std::cin >> n;\n    Tree<int>\
    \ tree(n);\n    tree.read(0);\n    CentroidDecomposition cd(tree);\n    std::vector<long\
    \ long> ans(n, 0);\n    // cnt[d] \u306F\u8DDD\u96E2 d \u306E\u9802\u70B9\u306E\
    \u500B\u6570\u3002\u81EA\u5206\u81EA\u8EAB\u3068\u306E\u7573\u307F\u8FBC\u307F\
    \u3067\u3001\u8DDD\u96E2\u306E\u548C\u3054\u3068\u306E\u7D44\u306E\u500B\u6570\
    \u306B\u306A\u308B\n    auto add = [&](const std::vector<long long>& cnt, long\
    \ long sign) {\n        auto sq = convolution_ll(cnt, cnt);\n        for (long\
    \ long d = 0; d < static_cast<long long>(sq.size()) && d < n; d++) ans[d] += sign\
    \ * sq[d];\n    };\n    for (long long c : cd.order()) {\n        std::vector<long\
    \ long> all = {1};  // c \u81EA\u8EAB\n        for (const auto& sub : cd.subtrees(tree,\
    \ c)) {\n            std::vector<long long> cnt;\n            for (auto [v, d]\
    \ : sub) {\n                if (static_cast<long long>(cnt.size()) <= d) cnt.resize(d\
    \ + 1);\n                if (static_cast<long long>(all.size()) <= d) all.resize(d\
    \ + 1);\n                cnt[d]++;\n                all[d]++;\n            }\n\
    \            // \u540C\u3058\u90E8\u5206\u6728\u306E\u4E2D\u306E 2 \u9802\u70B9\
    \u3092\u7D50\u3076\u30D1\u30B9\u306F c \u3092\u901A\u3089\u306A\u3044\u306E\u3067\
    \u5F15\u304F\n            add(cnt, -1);\n        }\n        add(all, 1);\n   \
    \ }\n    // \u9806\u5E8F\u4ED8\u304D\u306E\u7D44\u3092\u6570\u3048\u305F\u306E\
    \u3067 2 \u3067\u5272\u308B\n    for (long long d = 1; d < n; d++) std::cout <<\
    \ ans[d] / 2 << \" \\n\"[d + 1 == n];\n}\n"
  dependsOn:
  - src/graph/centroid-decomposition.hpp
  - src/graph/tree.hpp
  - src/graph/graph.hpp
  - src/graph/shortest-path.hpp
  - src/math/convolution.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  - src/math/modular-arithmetic.hpp
  isVerificationFile: true
  path: test/yosupo/tree/frequency-table-of-tree-distance.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 15:13:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree/frequency-table-of-tree-distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree/frequency-table-of-tree-distance.test.cpp
- /verify/test/yosupo/tree/frequency-table-of-tree-distance.test.cpp.html
title: test/yosupo/tree/frequency-table-of-tree-distance.test.cpp
---
