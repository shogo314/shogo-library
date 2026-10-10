---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph.hpp
    title: "\u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: graph/graph_util.hpp
    title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
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
  bundledCode: "#line 1 \"test/unittest-graph-util.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// graph_util.hpp\
    \ \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include <iostream>\n\
    #include <numeric>\n#include <random>\n#include <tuple>\n#include <vector>\n\n\
    #line 2 \"graph/graph_util.hpp\"\n\n/**\n * @file graph_util.hpp\n * @brief \u30B0\
    \u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570\n */\n\n#include <stack>\n\n\
    #line 2 \"graph/graph.hpp\"\n\n#line 4 \"graph/graph.hpp\"\n#include <limits>\n\
    #include <queue>\n#line 7 \"graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\
    \u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\nstruct Graph {\n    /**\n\
    \     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator\
    \ int()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001int\u578B\u306B\
    \u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\
    \n     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\
    \u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\
    \u304C\u3001\n     * for (int dst : g[v]) \u3068\u3059\u308B\u3068\u3001v\u304B\
    \u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\u308C\
    \u308B\n     */\n    struct Edge {\n        int src = -1;   //!< \u59CB\u70B9\n\
    \        int dst = -1;   //!< \u7D42\u70B9\n        Cost cost = {}; //!< \u30B3\
    \u30B9\u30C8\n        int id = -1;    //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\
    \u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306Fid\u304C\
    \u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\u5B58\
    \u5728\u3059\u308B)\n        Edge() = default;\n        Edge(int src, int dst,\
    \ Cost cost = 1, int id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n  \
    \      operator int() const { return dst; }\n    };\n\n    int n;            \
    \                //!< \u9802\u70B9\u6570\n    int m;                         \
    \   //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>> g; //!< \u30B0\u30E9\
    \u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief\
    \ \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n \
    \    */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n\
    \    explicit Graph(int n) : n(n), m(0), g(n) {}\n    /**\n     * @brief \u7121\
    \u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     * @param u \u59CB\u70B9\n   \
    \  * @param v \u7D42\u70B9\n     * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\
    \u305F\u30891\n     */\n    void add_edge(int u, int v, Cost w = 1) {\n      \
    \  g[u].push_back({u, v, w, m});\n        g[v].push_back({v, u, w, m++});\n  \
    \  }\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n\
    \     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n     * @param w \u30B3\
    \u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n    void add_directed_edge(int\
    \ u, int v, Cost w = 1) {\n        g[u].push_back({u, v, w, m++});\n    }\n  \
    \  /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\
    \u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param m\
    \ \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\u756A\u53F7\u3092\u5165\
    \u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B \u7701\u7565\u3057\
    \u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\u307F\u304C\u5165\u529B\
    \u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089false\u3068\u306A\u308A\
    \u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\u308C\u308B\n     * @param\
    \ directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B \u7701\u7565\
    \u3057\u305F\u3089false\n     */\n    void read(int m, int padding = -1, bool\
    \ weighted = false, bool directed = false) {\n        for (int i = 0; i < m; i++)\
    \ {\n            int u, v;\n            std::cin >> u >> v;\n            u +=\
    \ padding, v += padding;\n            Cost c(1);\n            if (weighted)\n\
    \                std::cin >> c;\n            if (directed)\n                add_directed_edge(u,\
    \ v, c);\n            else\n                add_edge(u, v, c);\n        }\n  \
    \  }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\u8FBA\
    \u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n   \
    \  * @return std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\
    \u30C8\n     */\n    std::vector<Edge> &operator[](int v) {\n        return g[v];\n\
    \    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\
    \u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\
    \n     * @return const std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\
    \u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge> &operator[](int v) const\
    \ {\n        return g[v];\n    }\n    /**\n     * @brief \u8FBA\u306E\u30EA\u30B9\
    \u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\u30EA\u30B9\u30C8(id\u306E\
    \u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\u4EE3\u8868\u3057\u3066\
    1\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (int i = 0;\
    \ i < n; i++) {\n            for (auto &e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n    /**\n     *\
    \ @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param weighted 1\u4EE5\
    \u5916\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u5B58\u5728\u3059\u308B\u304B\
    \ \u7701\u7565\u3059\u308B\u3068true\n     * @param inf \u30B3\u30B9\u30C8\u306E\
    min\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\
    \u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068\n     * @return\
    \ std::pair<std::vector<Cost>, std::vector<Edge>> first:\u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u9577 second:\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\n     */\n    std::pair<std::vector<Cost>,\
    \ std::vector<Edge>> shortest_path(int s, bool weignted = true, Cost inf = -1)\
    \ const {\n        if (weignted)\n            return shortest_path_dijkstra(s,\
    \ inf);\n        return shortest_path_bfs(s, inf);\n    }\n    /**\n     * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param inf \u30B3\u30B9\u30C8\
    \u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F\
    \ -inf\n     * @return std::pair<std::vector<Cost>, std::vector<Edge>> first:\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 second:\u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\n     */\n    std::pair<std::vector<Cost>,\
    \ std::vector<Edge>> bellman_ford(int s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        dist[s] = Cost{};\n\n        for (int i = 1; i < n; i++) {\n\
    \            bool changed = false;\n            for (int j = 0; j < n; j++)\n\
    \                for (const auto &e : g[j]) {\n                    if (dist[e.src]\
    \ == inf)\n                        continue;\n                    if (dist[e.dst]\
    \ > dist[e.src] + e.cost) {\n                        dist[e.dst] = dist[e.src]\
    \ + e.cost;\n                        if (dist[e.dst] < -inf)\n               \
    \             dist[e.dst] = -inf;\n                        prev[e.dst] = e;\n\
    \                        changed = true;\n                    }\n            \
    \    }\n            if (!changed)\n                break;\n        }\n       \
    \ for (int i = 0; i < n; i++) {\n            bool changed = false;\n         \
    \   for (int j = 0; j < n; j++)\n                for (const auto &e : g[j]) {\n\
    \                    if (dist[e.src] == inf)\n                        continue;\n\
    \                    if (dist[e.dst] > dist[e.src] + e.cost) {\n             \
    \           dist[e.dst] = -inf;\n                        prev[e.dst] = e;\n  \
    \                      changed = true;\n                    }\n              \
    \  }\n            if (!changed)\n                break;\n        }\n        return\
    \ {dist, prev};\n    }\n\n  private:\n    std::pair<std::vector<Cost>, std::vector<Edge>>\
    \ shortest_path_bfs(int s, Cost inf) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        std::queue<int> que;\n  \
    \      dist[s] = 0;\n        que.push(s);\n        while (!que.empty()) {\n  \
    \          int u = que.front();\n            que.pop();\n            for (auto\
    \ &e : g[u]) {\n                if (dist[e.dst] == inf) {\n                  \
    \  dist[e.dst] = dist[e.src] + 1;\n                    prev[e.dst] = e;\n    \
    \                que.push(e.dst);\n                }\n            }\n        }\n\
    \        return {dist, prev};\n    }\n    std::pair<std::vector<Cost>, std::vector<Edge>>\
    \ shortest_path_dijkstra(int s, Cost inf) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        using Node = std::pair<Cost,\
    \ int>;\n        std::priority_queue<Node, std::vector<Node>, std::greater<Node>>\
    \ que;\n        dist[s] = 0;\n        que.push({0, s});\n        while (!que.empty())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if (d > dist[u])\n                continue;\n            for (auto &e : g[u])\
    \ {\n                if (dist[e.dst] == inf || dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                    dist[e.dst] = dist[e.src] + e.cost;\n               \
    \     prev[e.dst] = e;\n                    que.push({dist[e.dst], e.dst});\n\
    \                }\n            }\n        }\n        return {dist, prev};\n \
    \   }\n};\n#line 11 \"graph/graph_util.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\
    \u30890\u30681\u306B\u5F69\u8272\u3057\u305F\u7D50\u679C\u3092\u3072\u3068\u3064\
    \u8FD4\u3057\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089\
    \u7A7A\u306Evector\u3092\u8FD4\u3059\u3002\n * \u9023\u7D50\u6210\u5206\u306E\u3046\
    \u3061\u3001\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306E\u6700\u3082\u5C0F\u3055\
    \u3044\u3082\u306E\u30920\u306B\u3059\u308B\u3002\n * @return std::vector<int>\
    \ \u5404\u9802\u70B9\u306E\u5F69\u8272\u7D50\u679C\n */\ntemplate <typename Cost\
    \ = int>\nstd::vector<int> bipartite_coloring(const Graph<Cost>& graph) {\n  \
    \  std::vector<int> color(graph.n, -1);\n    for (int i = 0; i < graph.n; i++)\
    \ {\n        if (color[i] != -1) continue;\n        std::stack<int> stk;\n   \
    \     stk.push(i);\n        color[i] = 0;\n        while (!stk.empty()) {\n  \
    \          int u = stk.top();\n            stk.pop();\n            for (int v\
    \ : graph[u]) {\n                if (color[v] == -1) {\n                    color[v]\
    \ = color[u] ^ 1;\n                    stk.push(v);\n                } else {\n\
    \                    if (color[u] == color[v]) return {};\n                }\n\
    \            }\n        }\n    }\n    return color;\n}\n\n/**\n * @brief \u7121\
    \u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return\
    \ bool \u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\u3089true\u3001\u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate\
    \ <typename Cost = int>\nbool is_bipartite(const Graph<Cost>& graph) {\n    return\
    \ !bipartite_coloring(graph).empty();\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\
    \u308B\u3002\n * @return std::vector<std::vector<int>> \u300C\u540C\u3058\u9023\
    \u7D50\u6210\u5206\u3068\u306A\u308B\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u300D\
    \u306E\u30EA\u30B9\u30C8\n */\ntemplate <typename Cost = int>\nstd::vector<std::vector<int>>\
    \ connected_components(const Graph<Cost>& graph) {\n    std::vector<std::vector<int>>\
    \ groups;\n    std::vector<bool> visited(graph.n);\n    for (int i = 0; i < graph.n;\
    \ i++) {\n        if (visited[i]) continue;\n        std::stack<int> stk;\n  \
    \      stk.push(i);\n        visited[i] = true;\n        groups.push_back({i});\n\
    \        while (!stk.empty()) {\n            int u = stk.top();\n            stk.pop();\n\
    \            for (int v : graph[u]) {\n                if (visited[v]) continue;\n\
    \                visited[v] = true;\n                stk.push(v);\n          \
    \      groups.back().push_back(v);\n            }\n        }\n    }\n    return\
    \ groups;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\
    \u3066\u3001\u9023\u7D50\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\u3002\n * @return bool \u9023\u7D50\u30B0\u30E9\u30D5\u306A\
    \u3089true\u3001\u9023\u7D50\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\
    \u8FD4\u3059\u3002\n */\ntemplate <typename Cost = int>\nbool is_connected(const\
    \ Graph<Cost>& graph) {\n    return connected_components(graph).size() == 1;\n\
    }\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\
    \u6728\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return\
    \ bool \u6728\u306A\u3089true\u3001\u6728\u3067\u306A\u3044\u306A\u3089false\u3092\
    \u8FD4\u3059\u3002\n */\ntemplate <typename Cost = int>\nbool is_tree(const Graph<Cost>&\
    \ graph) {\n    return graph.m == graph.n - 1 && is_connected(graph);\n}\n\n/**\n\
    \ * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\n * @param G \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\u30B0\u30E9\u30D5\n * @return \u30BD\u30FC\u30C8\
    \u3055\u308C\u305F\u30CE\u30FC\u30C9\u756A\u53F7\u306Evector DAG\u3067\u306A\u3051\
    \u308C\u3070\u9577\u3055\u304CG.n\u672A\u6E80\u306B\u306A\u308B\n */\ntemplate\
    \ <typename Cost>\nstd::vector<int> topological_sort(const Graph<Cost>& G) {\n\
    \    std::vector<int> indeg(G.n), sorted;\n    std::queue<int> q;\n    for (int\
    \ i = 0; i < G.n; i++) {\n        for (int dst : G[i]) indeg[dst]++;\n    }\n\
    \    for (int i = 0; i < G.n; i++) {\n        if (!indeg[i]) q.push(i);\n    }\n\
    \    while (!q.empty()) {\n        int cur = q.front();\n        q.pop();\n  \
    \      for (int dst : G[cur]) {\n            if (!--indeg[dst]) q.push(dst);\n\
    \        }\n        sorted.push_back(cur);\n    }\n    return sorted;\n}\n\n/**\n\
    \ * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u30B5\u30A4\
    \u30AF\u30EB\u3092\u3082\u3064\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n * @return bool \u30B5\u30A4\u30AF\u30EB\u3092\u3082\u3064\u306A\
    \u3089true\u3001\u975E\u5DE1\u56DE\u306A\u3089false\u3092\u8FD4\u3059\u3002\n\
    \ */\ntemplate <typename Cost = int>\nbool has_cycle(const Graph<Cost>& graph)\
    \ {\n    return (int)topological_sort(graph).size() < graph.n;\n}\n/**\n * @deprecated\
    \ has_cycle \u3092\u4F7F\u3046\u3053\u3068(\u540D\u524D\u3068\u610F\u5473\u304C\
    \u9006\u306B\u8AAD\u3081\u308B\u305F\u3081\u6539\u540D\u3057\u305F)\n */\ntemplate\
    \ <typename Cost = int>\n[[deprecated(\"use has_cycle\")]] bool has_acyclic(const\
    \ Graph<Cost>& graph) {\n    return has_cycle(graph);\n}\n\n/**\n * @brief \u6700\
    \u5C0F\u30B7\u30E5\u30BF\u30A4\u30CA\u30FC\u6728\u306E\u8FBA\u91CD\u307F\u306E\
    \u7DCF\u548C\n */\ntemplate <typename Cost, typename T>\nCost minimum_steiner_tree(const\
    \ Graph<Cost>& G, const std::vector<T>& X, Cost inf = -1) {\n    if (X.empty())\
    \ return Cost{};\n    std::vector<std::vector<Cost>> dp(G.n, std::vector<Cost>(1\
    \ << X.size(), inf));\n    for (int p = 0; p < (int)X.size(); p++) dp[X[p]][1\
    \ << p] = {};\n    for (int i = 0; i < (1 << X.size()); i++) {\n        for (int\
    \ j = i; j > 0; j = (j - 1) & i) {\n            for (int k = 0; k < G.n; k++)\
    \ {\n                if (dp[k][j] != inf && dp[k][i ^ j] != inf) {\n         \
    \           if (dp[k][i] == inf || dp[k][i] > dp[k][j] + dp[k][i ^ j]) dp[k][i]\
    \ = dp[k][j] + dp[k][i ^ j];\n                }\n            }\n        }\n  \
    \      std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>,\
    \ std::greater<std::pair<Cost, int>>> que;\n        for (int k = 0; k < G.n; k++)\n\
    \            if (dp[k][i] != inf) que.emplace(dp[k][i], k);\n        while (que.size())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if (d > dp[u][i]) continue;\n            for (auto e : G[u]) {\n          \
    \      if (dp[e.dst][i] == inf || dp[e.dst][i] > d + e.cost) {\n             \
    \       dp[e.dst][i] = d + e.cost;\n                    que.emplace(d + e.cost,\
    \ e.dst);\n                }\n            }\n        }\n    }\n    Cost res =\
    \ inf;\n    for (int k = 0; k < G.n; k++) {\n        if (dp[k].back() != inf &&\
    \ (res == inf || res > dp[k].back())) res = dp[k].back();\n    }\n    return res;\n\
    }\n#line 14 \"test/unittest-graph-util.test.cpp\"\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n\n    // \u7121\u5411\u30B0\u30E9\u30D5: bipartite_coloring,\
    \ is_bipartite, connected_components, is_connected, is_tree\n    for (int rep\
    \ = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 8 + 1;\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int u = 0; u < n; u++) {\n            for (int v\
    \ = u + 1; v < n; v++) {\n                if (rng() % 3 == 0) edges.emplace_back(u,\
    \ v);\n            }\n        }\n        Graph<int> graph(n);\n        for (auto\
    \ [u, v] : edges) graph.add_edge(u, v);\n\n        // \u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u5168\u5F69\u8272\u3067\u8ABF\u3079\u308B\
    \n        bool bipartite = false;\n        for (int mask = 0; mask < (1 << n);\
    \ mask++) {\n            bool good = true;\n            for (auto [u, v] : edges)\
    \ good &= ((mask >> u & 1) != (mask >> v & 1));\n            bipartite |= good;\n\
    \        }\n        std::vector<int> color = bipartite_coloring(graph);\n    \
    \    if (bipartite != !color.empty() || bipartite != is_bipartite(graph)) ok =\
    \ false;\n        if (!color.empty()) {\n            for (auto [u, v] : edges)\
    \ if (color[u] == color[v]) ok = false;\n        }\n\n        // \u9023\u7D50\u6210\
    \u5206\u3092 Union-Find \u98A8\u306B\u611A\u76F4\u306B\u6C42\u3081\u308B\n   \
    \     std::vector<int> label(n);\n        std::iota(label.begin(), label.end(),\
    \ 0);\n        for (int t = 0; t < n; t++) {\n            for (auto [u, v] : edges)\
    \ label[u] = label[v] = std::min(label[u], label[v]);\n        }\n        auto\
    \ groups = connected_components(graph);\n        std::vector<int> seen(n);\n \
    \       for (const auto& group : groups) {\n            for (int v : group) {\n\
    \                seen[v]++;\n                if (label[v] != label[group[0]])\
    \ ok = false;\n            }\n        }\n        int num_components = 0;\n   \
    \     for (int v = 0; v < n; v++) {\n            if (seen[v] != 1) ok = false;\n\
    \            if (label[v] == v) num_components++;\n        }\n        if ((int)groups.size()\
    \ != num_components) ok = false;\n        if (is_connected(graph) != (num_components\
    \ == 1)) ok = false;\n        if (is_tree(graph) != (num_components == 1 && (int)edges.size()\
    \ == n - 1)) ok = false;\n    }\n\n    // \u6709\u5411\u30B0\u30E9\u30D5: topological_sort,\
    \ has_cycle\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n =\
    \ rng() % 8 + 1;\n        Graph<int> graph(n);\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int u = 0; u < n; u++) {\n            for (int v\
    \ = 0; v < n; v++) {\n                if (u != v && rng() % 4 == 0) {\n      \
    \              graph.add_directed_edge(u, v);\n                    edges.emplace_back(u,\
    \ v);\n                }\n            }\n        }\n        // \u9589\u8DEF\u304C\
    \u3042\u308B\u304B\u3092\u5168\u9806\u5217\u3067\u8ABF\u3079\u308B (\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C\u5B58\u5728\u3057\u306A\u3044 \u21D4\
    \ \u9589\u8DEF\u304C\u3042\u308B)\n        std::vector<int> perm(n);\n       \
    \ std::iota(perm.begin(), perm.end(), 0);\n        bool dag = false;\n       \
    \ do {\n            std::vector<int> pos(n);\n            for (int i = 0; i <\
    \ n; i++) pos[perm[i]] = i;\n            bool good = true;\n            for (auto\
    \ [u, v] : edges) good &= pos[u] < pos[v];\n            dag |= good;\n       \
    \ } while (!dag && std::next_permutation(perm.begin(), perm.end()));\n       \
    \ if (has_cycle(graph) == dag) ok = false;\n        std::vector<int> order = topological_sort(graph);\n\
    \        if (dag) {\n            if ((int)order.size() != n) ok = false;\n   \
    \         else {\n                std::vector<int> pos(n, -1);\n             \
    \   for (int i = 0; i < n; i++) pos[order[i]] = i;\n                for (auto\
    \ [u, v] : edges) if (!(pos[u] < pos[v])) ok = false;\n            }\n       \
    \ } else if ((int)order.size() >= n) {\n            ok = false;\n        }\n \
    \   }\n\n    // minimum_steiner_tree: \u8FBA\u306E\u90E8\u5206\u96C6\u5408\u3092\
    \u5168\u63A2\u7D22\u3059\u308B\n    for (int rep = 0; rep < 500 && ok; rep++)\
    \ {\n        int n = rng() % 6 + 1;\n        std::vector<std::tuple<int, int,\
    \ int>> edges;\n        // \u9023\u7D50\u306B\u3059\u308B\u305F\u3081\u3001\u307E\
    \u305A\u5168\u57DF\u6728\u3092\u4F5C\u308B\n        for (int v = 1; v < n; v++)\
    \ edges.emplace_back(rng() % v, v, rng() % 10 + 1);\n        for (int u = 0; u\
    \ < n; u++) {\n            for (int v = u + 1; v < n; v++) {\n               \
    \ if (rng() % 4 == 0) edges.emplace_back(u, v, rng() % 10 + 1);\n            }\n\
    \        }\n        if (edges.size() > 12) edges.resize(12);\n        Graph<int>\
    \ graph(n);\n        for (auto [u, v, w] : edges) graph.add_edge(u, v, w);\n \
    \       std::vector<int> terminals;\n        for (int v = 0; v < n; v++) if (rng()\
    \ % 2) terminals.push_back(v);\n\n        int best = -1;\n        int m = edges.size();\n\
    \        for (int mask = 0; mask < (1 << m); mask++) {\n            std::vector<int>\
    \ label(n);\n            std::iota(label.begin(), label.end(), 0);\n         \
    \   int cost = 0;\n            for (int i = 0; i < m; i++) if (mask >> i & 1)\
    \ cost += std::get<2>(edges[i]);\n            for (int t = 0; t < n; t++) {\n\
    \                for (int i = 0; i < m; i++) {\n                    if (!(mask\
    \ >> i & 1)) continue;\n                    auto [u, v, w] = edges[i];\n     \
    \               label[u] = label[v] = std::min(label[u], label[v]);\n        \
    \        }\n            }\n            bool connected = true;\n            for\
    \ (int v : terminals) connected &= label[v] == label[terminals[0]];\n        \
    \    if (connected && (best == -1 || cost < best)) best = cost;\n        }\n \
    \       if (terminals.empty()) best = 0;\n        if (minimum_steiner_tree(graph,\
    \ terminals) != best) ok = false;\n    }\n\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// graph_util.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <numeric>\n#include <random>\n#include <tuple>\n#include\
    \ <vector>\n\n#include \"../graph/graph_util.hpp\"\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n\n    // \u7121\u5411\u30B0\u30E9\u30D5: bipartite_coloring,\
    \ is_bipartite, connected_components, is_connected, is_tree\n    for (int rep\
    \ = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 8 + 1;\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int u = 0; u < n; u++) {\n            for (int v\
    \ = u + 1; v < n; v++) {\n                if (rng() % 3 == 0) edges.emplace_back(u,\
    \ v);\n            }\n        }\n        Graph<int> graph(n);\n        for (auto\
    \ [u, v] : edges) graph.add_edge(u, v);\n\n        // \u4E8C\u90E8\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u5168\u5F69\u8272\u3067\u8ABF\u3079\u308B\
    \n        bool bipartite = false;\n        for (int mask = 0; mask < (1 << n);\
    \ mask++) {\n            bool good = true;\n            for (auto [u, v] : edges)\
    \ good &= ((mask >> u & 1) != (mask >> v & 1));\n            bipartite |= good;\n\
    \        }\n        std::vector<int> color = bipartite_coloring(graph);\n    \
    \    if (bipartite != !color.empty() || bipartite != is_bipartite(graph)) ok =\
    \ false;\n        if (!color.empty()) {\n            for (auto [u, v] : edges)\
    \ if (color[u] == color[v]) ok = false;\n        }\n\n        // \u9023\u7D50\u6210\
    \u5206\u3092 Union-Find \u98A8\u306B\u611A\u76F4\u306B\u6C42\u3081\u308B\n   \
    \     std::vector<int> label(n);\n        std::iota(label.begin(), label.end(),\
    \ 0);\n        for (int t = 0; t < n; t++) {\n            for (auto [u, v] : edges)\
    \ label[u] = label[v] = std::min(label[u], label[v]);\n        }\n        auto\
    \ groups = connected_components(graph);\n        std::vector<int> seen(n);\n \
    \       for (const auto& group : groups) {\n            for (int v : group) {\n\
    \                seen[v]++;\n                if (label[v] != label[group[0]])\
    \ ok = false;\n            }\n        }\n        int num_components = 0;\n   \
    \     for (int v = 0; v < n; v++) {\n            if (seen[v] != 1) ok = false;\n\
    \            if (label[v] == v) num_components++;\n        }\n        if ((int)groups.size()\
    \ != num_components) ok = false;\n        if (is_connected(graph) != (num_components\
    \ == 1)) ok = false;\n        if (is_tree(graph) != (num_components == 1 && (int)edges.size()\
    \ == n - 1)) ok = false;\n    }\n\n    // \u6709\u5411\u30B0\u30E9\u30D5: topological_sort,\
    \ has_cycle\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n =\
    \ rng() % 8 + 1;\n        Graph<int> graph(n);\n        std::vector<std::pair<int,\
    \ int>> edges;\n        for (int u = 0; u < n; u++) {\n            for (int v\
    \ = 0; v < n; v++) {\n                if (u != v && rng() % 4 == 0) {\n      \
    \              graph.add_directed_edge(u, v);\n                    edges.emplace_back(u,\
    \ v);\n                }\n            }\n        }\n        // \u9589\u8DEF\u304C\
    \u3042\u308B\u304B\u3092\u5168\u9806\u5217\u3067\u8ABF\u3079\u308B (\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u304C\u5B58\u5728\u3057\u306A\u3044 \u21D4\
    \ \u9589\u8DEF\u304C\u3042\u308B)\n        std::vector<int> perm(n);\n       \
    \ std::iota(perm.begin(), perm.end(), 0);\n        bool dag = false;\n       \
    \ do {\n            std::vector<int> pos(n);\n            for (int i = 0; i <\
    \ n; i++) pos[perm[i]] = i;\n            bool good = true;\n            for (auto\
    \ [u, v] : edges) good &= pos[u] < pos[v];\n            dag |= good;\n       \
    \ } while (!dag && std::next_permutation(perm.begin(), perm.end()));\n       \
    \ if (has_cycle(graph) == dag) ok = false;\n        std::vector<int> order = topological_sort(graph);\n\
    \        if (dag) {\n            if ((int)order.size() != n) ok = false;\n   \
    \         else {\n                std::vector<int> pos(n, -1);\n             \
    \   for (int i = 0; i < n; i++) pos[order[i]] = i;\n                for (auto\
    \ [u, v] : edges) if (!(pos[u] < pos[v])) ok = false;\n            }\n       \
    \ } else if ((int)order.size() >= n) {\n            ok = false;\n        }\n \
    \   }\n\n    // minimum_steiner_tree: \u8FBA\u306E\u90E8\u5206\u96C6\u5408\u3092\
    \u5168\u63A2\u7D22\u3059\u308B\n    for (int rep = 0; rep < 500 && ok; rep++)\
    \ {\n        int n = rng() % 6 + 1;\n        std::vector<std::tuple<int, int,\
    \ int>> edges;\n        // \u9023\u7D50\u306B\u3059\u308B\u305F\u3081\u3001\u307E\
    \u305A\u5168\u57DF\u6728\u3092\u4F5C\u308B\n        for (int v = 1; v < n; v++)\
    \ edges.emplace_back(rng() % v, v, rng() % 10 + 1);\n        for (int u = 0; u\
    \ < n; u++) {\n            for (int v = u + 1; v < n; v++) {\n               \
    \ if (rng() % 4 == 0) edges.emplace_back(u, v, rng() % 10 + 1);\n            }\n\
    \        }\n        if (edges.size() > 12) edges.resize(12);\n        Graph<int>\
    \ graph(n);\n        for (auto [u, v, w] : edges) graph.add_edge(u, v, w);\n \
    \       std::vector<int> terminals;\n        for (int v = 0; v < n; v++) if (rng()\
    \ % 2) terminals.push_back(v);\n\n        int best = -1;\n        int m = edges.size();\n\
    \        for (int mask = 0; mask < (1 << m); mask++) {\n            std::vector<int>\
    \ label(n);\n            std::iota(label.begin(), label.end(), 0);\n         \
    \   int cost = 0;\n            for (int i = 0; i < m; i++) if (mask >> i & 1)\
    \ cost += std::get<2>(edges[i]);\n            for (int t = 0; t < n; t++) {\n\
    \                for (int i = 0; i < m; i++) {\n                    if (!(mask\
    \ >> i & 1)) continue;\n                    auto [u, v, w] = edges[i];\n     \
    \               label[u] = label[v] = std::min(label[u], label[v]);\n        \
    \        }\n            }\n            bool connected = true;\n            for\
    \ (int v : terminals) connected &= label[v] == label[terminals[0]];\n        \
    \    if (connected && (best == -1 || cost < best)) best = cost;\n        }\n \
    \       if (terminals.empty()) best = 0;\n        if (minimum_steiner_tree(graph,\
    \ terminals) != best) ok = false;\n    }\n\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - graph/graph_util.hpp
  - graph/graph.hpp
  isVerificationFile: true
  path: test/unittest-graph-util.test.cpp
  requiredBy: []
  timestamp: '2026-10-10 20:54:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest-graph-util.test.cpp
layout: document
redirect_from:
- /verify/test/unittest-graph-util.test.cpp
- /verify/test/unittest-graph-util.test.cpp.html
title: test/unittest-graph-util.test.cpp
---
