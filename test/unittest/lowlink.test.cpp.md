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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/lowlink.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// LowLink \u3092\u3001\u9802\u70B9\u3084\u8FBA\u3092 1 \u3064\u53D6\u308A\
    \u9664\u3044\u3066\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u6570\u3048\u308B\
    \u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/graph/lowlink.hpp\"\n\n/**\n * @file lowlink.hpp\n * @brief\
    \ lowlink (\u95A2\u7BC0\u70B9\u3001\u6A4B\u3001\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\
    \u5206\u5206\u89E3)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n * @brief\
    \ \u30B0\u30E9\u30D5\n */\n\n#line 10 \"src/graph/graph.hpp\"\n#include <deque>\n\
    #include <functional>\n#include <iostream>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#line 17 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\
    \u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\
    \u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\nclass Graph {\n\
    \   public:\n    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\
    \n     *\n     * operator int()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\
    \u3067\u3001int\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\
    \u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for (auto&\
    \ e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\
    \u5217\u6319\u3055\u308C\u308B\u304C\u3001\n     * for (int dst : g[v]) \u3068\
    \u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\
    \u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n        int\
    \ src = -1;    //!< \u59CB\u70B9\n        int dst = -1;    //!< \u7D42\u70B9\n\
    \        Cost cost = {};  //!< \u30B3\u30B9\u30C8\n        int id = -1;     //!<\
    \ \u8FBA\u306E\u756A\u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\
    \u8FBA\u306E\u5834\u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\
    \u306E\u3082\u306E\u304C2\u3064\u5B58\u5728\u3059\u308B)\n        Edge() = default;\n\
    \        Edge(int src, int dst, Cost cost = 1, int id = -1) : src(src), dst(dst),\
    \ cost(cost), id(id) {}\n        operator int() const { return dst; }\n    };\n\
    \n    /**\n     * @brief \u6700\u77ED\u8DEF\u306E\u7D50\u679C\n     *\n     *\
    \ auto [dist, prev] = g.shortest_path(s); \u306E\u3088\u3046\u306B\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct ShortestPath {\n        std::vector<Cost>\
    \ dist;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577\n       \
    \ std::vector<Edge> prev;  //!< \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u4E0A\u306E\u76F4\u524D\u306E\u8FBA (\u59CB\u70B9\u3068\u672A\u5230\u9054\u306E\
    \u9802\u70B9\u3067\u306F src == -1)\n        /**\n         * @brief \u59CB\u70B9\
    \u304B\u3089 t \u3078\u306E\u6700\u77ED\u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\
    \u306E\u30EA\u30B9\u30C8 (\u59CB\u70B9\u5074\u304B\u3089\u9806\u306B)\n      \
    \   * @note t \u304C\u59CB\u70B9\u304B\u672A\u5230\u9054\u306E\u9802\u70B9\u306A\
    \u3089\u7A7A\u3002\u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\
    \u9802\u70B9\u3067\u306F\u6700\u77ED\u8DEF\u304C\u5B9A\u307E\u3089\u306A\u3044\
    \ (assert \u3067\u843D\u3061\u308B)\n         */\n        std::vector<Edge> path(int\
    \ t) const {\n            std::vector<Edge> res;\n            while (prev[t].src\
    \ != -1) {\n                res.push_back(prev[t]);\n                assert(res.size()\
    \ < prev.size() && \"path: negative cycle\");\n                t = prev[t].src;\n\
    \            }\n            std::reverse(res.begin(), res.end());\n          \
    \  return res;\n        }\n    };\n\n    int n;                             //!<\
    \ \u9802\u70B9\u6570\n    int m;                             //!< \u8FBA\u6570\
    \n    std::vector<std::vector<Edge>> g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\
    \u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0),\
    \ m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     * @param n \u9802\u70B9\u6570\n     */\n    explicit Graph(int n) : n(n),\
    \ m(0), g(n) {}\n    /**\n     * @brief \u9802\u70B9\u6570\n     */\n    int size()\
    \ const { return n; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_edge(int u, int v, Cost w = 1) {\n        assert(0 <= u && u < n &&\
    \ 0 <= v && v < n);\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_directed_edge(int u, int v, Cost w = 1) {\n        assert(0 <= u &&\
    \ u < n && 0 <= v && v < n);\n        g[u].push_back({u, v, w, m++});\n    }\n\
    \    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\
    \u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param\
    \ m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\u756A\u53F7\u3092\u5165\
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
    \u30C8\n     */\n    std::vector<Edge>& operator[](int v) {\n        return g[v];\n\
    \    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u308B\
    \u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\
    \n     * @return const std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\
    \u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge>& operator[](int v) const\
    \ {\n        return g[v];\n    }\n    /**\n     * @brief \u8FBA\u306E\u30EA\u30B9\
    \u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\u30EA\u30B9\u30C8(id\u306E\
    \u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\u4EE3\u8868\u3057\u3066\
    1\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (int i = 0;\
    \ i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n    /**\n     *\
    \ @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param weighted 1\u4EE5\
    \u5916\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u5B58\u5728\u3059\u308B\u304B\
    \ \u7701\u7565\u3059\u308B\u3068true\n     * @param inf \u30B3\u30B9\u30C8\u306E\
    min\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\
    \u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\
    \u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath shortest_path(int\
    \ s, bool weighted = true, Cost inf = std::numeric_limits<Cost>::max() / 4) const\
    \ {\n        assert(0 <= s && s < n);\n        if (weighted)\n            return\
    \ shortest_path_dijkstra(s, inf);\n        return shortest_path_bfs(s, inf);\n\
    \    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n \
    \    * @param inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\
    \u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\
    \u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4 \u8CA0\u9589\u8DEF\
    \u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F -inf\n     * @return ShortestPath\
    \ \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA\
    \ (prev)\n     */\n    ShortestPath bellman_ford(int s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        assert(0 <= s && s < n);\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        dist[s] = Cost{};\n\n   \
    \     for (int i = 1; i < n; i++) {\n            bool changed = false;\n     \
    \       for (int j = 0; j < n; j++)\n                for (const auto& e : g[j])\
    \ {\n                    if (dist[e.src] == inf)\n                        continue;\n\
    \                    if (dist[e.dst] > dist[e.src] + e.cost) {\n             \
    \           dist[e.dst] = dist[e.src] + e.cost;\n                        if (dist[e.dst]\
    \ < -inf)\n                            dist[e.dst] = -inf;\n                 \
    \       prev[e.dst] = e;\n                        changed = true;\n          \
    \          }\n                }\n            if (!changed)\n                break;\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            bool changed =\
    \ false;\n            for (int j = 0; j < n; j++)\n                for (const\
    \ auto& e : g[j]) {\n                    if (dist[e.src] == inf)\n           \
    \             continue;\n                    if (dist[e.dst] > dist[e.src] + e.cost)\
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
    \ (prev)\n     */\n    ShortestPath shortest_path_01bfs(int s, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        assert(0 <= s && s < n);\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        std::deque<int> que;\n  \
    \      dist[s] = 0;\n        que.push_back(s);\n        while (!que.empty()) {\n\
    \            int u = que.front();\n            que.pop_front();\n            for\
    \ (auto& e : g[u]) {\n                assert(e.cost == 0 || e.cost == 1);\n  \
    \              if (dist[e.dst] == inf || dist[e.dst] > dist[u] + e.cost) {\n \
    \                   dist[e.dst] = dist[u] + e.cost;\n                    prev[e.dst]\
    \ = e;\n                    if (e.cost == 0)\n                        que.push_front(e.dst);\n\
    \                    else\n                        que.push_back(e.dst);\n   \
    \             }\n            }\n        }\n        return {dist, prev};\n    }\n\
    \    /**\n     * @brief \u5168\u70B9\u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577\
    \ (Floyd-Warshall) O(n^3)\n     *\n     * @param inf \u672A\u5230\u9054\u3092\u8868\
    \u3059\u5024 \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() /\
    \ 4\n     * @return std::vector<std::vector<Cost>> dist[i][j] \u304C i \u304B\u3089\
    \ j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\u9054\u3067\u304D\u306A\u3051\
    \u308C\u3070 inf)\n     * @note \u8CA0\u306E\u8FBA\u304C\u3042\u3063\u3066\u3082\
    \u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B i \u304C\u3042\u308C\u3070\
    \u8CA0\u9589\u8DEF\u304C\u3042\u308B\n     */\n    std::vector<std::vector<Cost>>\
    \ floyd_warshall(Cost inf = std::numeric_limits<Cost>::max() / 4) const {\n  \
    \      std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n, inf));\n  \
    \      for (int i = 0; i < n; i++) dist[i][i] = Cost{};\n        for (int i =\
    \ 0; i < n; i++) {\n            for (auto& e : g[i]) dist[i][e.dst] = std::min(dist[i][e.dst],\
    \ e.cost);\n        }\n        for (int k = 0; k < n; k++) {\n            for\
    \ (int i = 0; i < n; i++) {\n                if (dist[i][k] == inf) continue;\n\
    \                for (int j = 0; j < n; j++) {\n                    if (dist[k][j]\
    \ == inf) continue;\n                    dist[i][j] = std::min(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\n                }\n            }\n        }\n        return\
    \ dist;\n    }\n\n   private:\n    ShortestPath shortest_path_bfs(int s, Cost\
    \ inf) const {\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        std::queue<int> que;\n        dist[s] = 0;\n        que.push(s);\n\
    \        while (!que.empty()) {\n            int u = que.front();\n          \
    \  que.pop();\n            for (auto& e : g[u]) {\n                if (dist[e.dst]\
    \ == inf) {\n                    dist[e.dst] = dist[e.src] + 1;\n            \
    \        prev[e.dst] = e;\n                    que.push(e.dst);\n            \
    \    }\n            }\n        }\n        return {dist, prev};\n    }\n    ShortestPath\
    \ shortest_path_dijkstra(int s, Cost inf) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        using Node = std::pair<Cost,\
    \ int>;\n        std::priority_queue<Node, std::vector<Node>, std::greater<Node>>\
    \ que;\n        dist[s] = 0;\n        que.push({0, s});\n        while (!que.empty())\
    \ {\n            auto [d, u] = que.top();\n            que.pop();\n          \
    \  if (d > dist[u])\n                continue;\n            for (auto& e : g[u])\
    \ {\n                if (dist[e.dst] == inf || dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                    dist[e.dst] = dist[e.src] + e.cost;\n               \
    \     prev[e.dst] = e;\n                    que.push({dist[e.dst], e.dst});\n\
    \                }\n            }\n        }\n        return {dist, prev};\n \
    \   }\n};\n#line 13 \"src/graph/lowlink.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306E lowlink \u3092\u6C42\u3081\u3001\u95A2\u7BC0\u70B9\u30FB\u6A4B\
    \u30FB\u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u3092\u6C42\u3081\u308B\n *\n\
    \ * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n\
    \ + m)\n * \u591A\u91CD\u8FBA\u3068\u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u3063\
    \u3066\u3082\u3088\u3044 (\u89AA\u3078\u623B\u308B\u8FBA\u306F\u9802\u70B9\u3067\
    \u306F\u306A\u304F\u8FBA\u306E\u756A\u53F7\u3067\u533A\u5225\u3059\u308B)\n *\
    \ \u4F8B:\n * LowLink ll(g);\n * ll.articulation_points(); ll.bridges(); ll.two_edge_connected_groups();\n\
    \ *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate\
    \ <typename Cost = int>\nclass LowLink {\n    int n;\n    std::vector<bool> art,\
    \ bridge;\n    std::vector<int> arts, bridge_ids;\n    std::vector<int> comp;\n\
    \    std::vector<std::vector<int>> groups;\n\n   public:\n    std::vector<int>\
    \ ord;  //!< DFS \u3067\u8A2A\u308C\u305F\u9806\u756A\n    std::vector<int> low;\
    \  //!< DFS \u6728\u306E\u5B50\u5B6B\u304B\u3089\u3001\u6728\u306E\u8FBA\u3092\
    \u9006\u306B\u305F\u3069\u3089\u305A\u306B 1 \u672C\u306E\u5F8C\u9000\u8FBA\u3067\
    \u884C\u3051\u308B\u9802\u70B9\u306E ord \u306E\u6700\u5C0F\u5024\n\n    explicit\
    \ LowLink(const Graph<Cost>& graph) : n(graph.n), art(n), bridge(graph.m), comp(n,\
    \ -1), ord(n, -1), low(n) {\n        std::vector<int> parent(n, -1), parent_edge(n,\
    \ -1), iter(n, 0);\n        std::vector<int> st;\n        int k = 0;\n       \
    \ for (int root = 0; root < n; root++) {\n            if (ord[root] != -1) continue;\n\
    \            int root_children = 0;\n            ord[root] = low[root] = k++;\n\
    \            st.push_back(root);\n            while (!st.empty()) {\n        \
    \        int v = st.back();\n                if (iter[v] < (int)graph[v].size())\
    \ {\n                    const auto& e = graph[v][iter[v]++];\n              \
    \      if (e.id == parent_edge[v]) continue;\n                    int u = e.dst;\n\
    \                    if (ord[u] == -1) {\n                        parent[u] =\
    \ v;\n                        parent_edge[u] = e.id;\n                       \
    \ ord[u] = low[u] = k++;\n                        st.push_back(u);\n         \
    \           } else {\n                        low[v] = std::min(low[v], ord[u]);\n\
    \                    }\n                    continue;\n                }\n   \
    \             st.pop_back();\n                if (v == root) continue;\n     \
    \           int p = parent[v];\n                low[p] = std::min(low[p], low[v]);\n\
    \                if (low[v] > ord[p]) bridge[parent_edge[v]] = true;\n       \
    \         if (p == root)\n                    root_children++;\n             \
    \   else if (low[v] >= ord[p])\n                    art[p] = true;\n         \
    \   }\n            if (root_children >= 2) art[root] = true;\n        }\n    \
    \    for (int v = 0; v < n; v++) {\n            if (art[v]) arts.push_back(v);\n\
    \        }\n        for (int id = 0; id < graph.m; id++) {\n            if (bridge[id])\
    \ bridge_ids.push_back(id);\n        }\n        // \u6A4B\u3092\u901A\u3089\u305A\
    \u306B\u884C\u3051\u308B\u9802\u70B9\u3092\u307E\u3068\u3081\u308B\n        for\
    \ (int s = 0; s < n; s++) {\n            if (comp[s] != -1) continue;\n      \
    \      comp[s] = groups.size();\n            groups.push_back({s});\n        \
    \    for (int i = 0; i < (int)groups.back().size(); i++) {\n                int\
    \ v = groups.back()[i];\n                for (const auto& e : graph[v]) {\n  \
    \                  if (bridge[e.id] || comp[e.dst] != -1) continue;\n        \
    \            comp[e.dst] = comp[s];\n                    groups.back().push_back(e.dst);\n\
    \                }\n            }\n        }\n    }\n\n    /**\n     * @brief\
    \ \u9802\u70B9\u6570\n     */\n    int size() const { return n; }\n\n    /**\n\
    \     * @brief v \u304C\u95A2\u7BC0\u70B9 (\u53D6\u308A\u9664\u304F\u3068\u9023\
    \u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u9802\u70B9) \u304B\n     */\n    bool\
    \ is_articulation_point(int v) const {\n        assert(0 <= v && v < n);\n   \
    \     return art[v];\n    }\n    /**\n     * @brief \u756A\u53F7 id \u306E\u8FBA\
    \u304C\u6A4B (\u53D6\u308A\u9664\u304F\u3068\u9023\u7D50\u6210\u5206\u304C\u5897\
    \u3048\u308B\u8FBA) \u304B\n     */\n    bool is_bridge(int id) const {\n    \
    \    assert(0 <= id && id < (int)bridge.size());\n        return bridge[id];\n\
    \    }\n    /**\n     * @brief \u95A2\u7BC0\u70B9\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<int>&\
    \ articulation_points() const { return arts; }\n    /**\n     * @brief \u6A4B\u306E\
    \u8FBA\u306E\u756A\u53F7\u306E\u6607\u9806\u306E\u30EA\u30B9\u30C8\n     */\n\
    \    const std::vector<int>& bridges() const { return bridge_ids; }\n    /**\n\
    \     * @brief \u9802\u70B9 v \u304C\u5C5E\u3059\u308B\u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206\u306E\u756A\u53F7\n     */\n    int two_edge_connected_group_id(int\
    \ v) const {\n        assert(0 <= v && v < n);\n        return comp[v];\n    }\n\
    \    /**\n     * @brief \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206 (\u6A4B\u3092\
    \u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306E\u9023\u7D50\u6210\u5206) \u3054\
    \u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<std::vector<int>>&\
    \ two_edge_connected_groups() const { return groups; }\n};\n#line 7 \"test/unittest/lowlink.test.cpp\"\
    \n\n#line 9 \"test/unittest/lowlink.test.cpp\"\n#include <random>\n#line 11 \"\
    test/unittest/lowlink.test.cpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\
    \u8FBA\u306E\u8FFD\u52A0\u300D\u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\
    \u306E\u5224\u5B9A\u300D\u3092\u3059\u308B\n */\nclass UnionFind {\n   protected:\n\
    \    int _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\
    \u3089\u89AA\n    std::vector<int> parent_or_size;\n\n   public:\n    /**\n  \
    \   * @brief merge \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b))\
    \ \u3067\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\
    \u304D\u3001\n     * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\
    \u3082\u53D7\u3051\u53D6\u308C\u308B\n     */\n    struct MergeResult {\n    \
    \    int leader;   //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool\
    \ merged;  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\
    \u3082\u3068\u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit\
    \ operator bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0)\
    \ {}\n    explicit UnionFind(int n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n\
    \     * @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\
    \u306E\u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\
    \u304B\n     */\n    MergeResult merge(int a, int b) {\n        assert(0 <= a\
    \ && a < _n);\n        assert(0 <= b && b < _n);\n        int x = leader(a), y\
    \ = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = x;\n        return {x, true};\n    }\n    /**\n \
    \    * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n    \
    \ */\n    bool same(int a, int b) {\n        assert(0 <= a && a < _n);\n     \
    \   assert(0 <= b && b < _n);\n        return leader(a) == leader(b);\n    }\n\
    \    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u4EE3\u8868\u5143\n     */\n    int leader(int a) {\n        assert(0\
    \ <= a && a < _n);\n        if (parent_or_size[a] < 0) return a;\n        int\
    \ x = a;\n        while (parent_or_size[x] >= 0) {\n            x = parent_or_size[x];\n\
    \        }\n        while (parent_or_size[a] >= 0) {\n            int t = parent_or_size[a];\n\
    \            parent_or_size[a] = x;\n            a = t;\n        }\n        return\
    \ x;\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n \
    \       assert(0 <= a && a < _n);\n        return -parent_or_size[leader(a)];\n\
    \    }\n    /**\n     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\
    \u306B\u5206\u3051\u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return\
    \ \u300C\u4E00\u3064\u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    };\n#line 13 \"test/unittest/lowlink.test.cpp\"\n\n// \u9802\u70B9 skip_v \u3068\
    \u8FBA skip_e \u3092\u4F7F\u308F\u306A\u3044\u3068\u304D\u306E\u9023\u7D50\u6210\
    \u5206\u306E\u6570 (skip_v \u81EA\u8EAB\u306F\u6570\u3048\u306A\u3044)\nint count_components(int\
    \ n, const std::vector<std::pair<int, int>>& es, int skip_v, int skip_e) {\n \
    \   UnionFind uf(n);\n    for (int i = 0; i < (int)es.size(); i++) {\n       \
    \ if (i == skip_e) continue;\n        auto [u, v] = es[i];\n        if (u == skip_v\
    \ || v == skip_v) continue;\n        uf.merge(u, v);\n    }\n    int c = 0;\n\
    \    for (int v = 0; v < n; v++) c += v != skip_v && uf.leader(v) == v;\n    return\
    \ c;\n}\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n   \
    \ for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 9 + 1,\
    \ m = rng() % 14;\n        Graph<int> g(n);\n        std::vector<std::pair<int,\
    \ int>> es;\n        for (int i = 0; i < m; i++) {\n            int u = rng()\
    \ % n, v = rng() % n;  // \u81EA\u5DF1\u30EB\u30FC\u30D7\u3068\u591A\u91CD\u8FBA\
    \u3082\u542B\u3080\n            g.add_edge(u, v);\n            es.emplace_back(u,\
    \ v);\n        }\n        LowLink ll(g);\n        int base = count_components(n,\
    \ es, -1, -1);\n        std::vector<int> arts, bridges;\n        for (int v =\
    \ 0; v < n; v++) {\n            // v \u3092\u53D6\u308A\u9664\u3044\u305F\u3068\
    \u304D\u3001\u6B8B\u308A\u306E\u9802\u70B9\u306E\u9023\u7D50\u6210\u5206\u304C\
    \u5897\u3048\u308B\u304B\n            // (v \u304C\u307B\u304B\u306E\u9802\u70B9\
    \u3068\u3064\u306A\u304C\u3063\u3066\u3044\u306A\u3051\u308C\u3070\u3001v \u306E\
    \u5206\u3060\u3051 1 \u6E1B\u308B\u306E\u304C\u666E\u901A)\n            bool isolated\
    \ = true;\n            for (auto [a, b] : es) isolated &= !((a == v || b == v)\
    \ && a != b);\n            bool art = count_components(n, es, v, -1) > base -\
    \ (isolated ? 1 : 0);\n            if (art) arts.push_back(v);\n            if\
    \ (ll.is_articulation_point(v) != art) ok = false;\n        }\n        for (int\
    \ i = 0; i < m; i++) {\n            bool br = count_components(n, es, -1, i) >\
    \ base;\n            if (br) bridges.push_back(i);\n            if (ll.is_bridge(i)\
    \ != br) ok = false;\n        }\n        if (ll.articulation_points() != arts\
    \ || ll.bridges() != bridges) ok = false;\n\n        // \u4E8C\u91CD\u8FBA\u9023\
    \u7D50\u6210\u5206: \u6A4B\u3092\u3059\u3079\u3066\u53D6\u308A\u9664\u3044\u305F\
    \u3068\u304D\u306E\u9023\u7D50\u6210\u5206\u3068\u4E00\u81F4\u3059\u308B\n   \
    \     UnionFind uf(n);\n        for (int i = 0; i < m; i++) {\n            if\
    \ (!ll.is_bridge(i)) uf.merge(es[i].first, es[i].second);\n        }\n       \
    \ const auto& groups = ll.two_edge_connected_groups();\n        int total = 0;\n\
    \        for (int k = 0; k < (int)groups.size(); k++) {\n            total +=\
    \ groups[k].size();\n            for (int v : groups[k]) {\n                if\
    \ (ll.two_edge_connected_group_id(v) != k || !uf.same(v, groups[k][0])) ok = false;\n\
    \            }\n        }\n        int uf_groups = 0;\n        for (int v = 0;\
    \ v < n; v++) uf_groups += uf.leader(v) == v;\n        if (total != n || (int)groups.size()\
    \ != uf_groups) ok = false;\n    }\n\n    if (ok)\n        std::cout << \"Hello\
    \ World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// LowLink \u3092\u3001\u9802\u70B9\u3084\u8FBA\u3092 1 \u3064\u53D6\u308A\
    \u9664\u3044\u3066\u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u6570\u3048\u308B\
    \u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../src/graph/lowlink.hpp\"\n\n#include <iostream>\n#include\
    \ <random>\n#include <vector>\n\n#include \"../../src/data_structures/unionfind.hpp\"\
    \n\n// \u9802\u70B9 skip_v \u3068\u8FBA skip_e \u3092\u4F7F\u308F\u306A\u3044\u3068\
    \u304D\u306E\u9023\u7D50\u6210\u5206\u306E\u6570 (skip_v \u81EA\u8EAB\u306F\u6570\
    \u3048\u306A\u3044)\nint count_components(int n, const std::vector<std::pair<int,\
    \ int>>& es, int skip_v, int skip_e) {\n    UnionFind uf(n);\n    for (int i =\
    \ 0; i < (int)es.size(); i++) {\n        if (i == skip_e) continue;\n        auto\
    \ [u, v] = es[i];\n        if (u == skip_v || v == skip_v) continue;\n       \
    \ uf.merge(u, v);\n    }\n    int c = 0;\n    for (int v = 0; v < n; v++) c +=\
    \ v != skip_v && uf.leader(v) == v;\n    return c;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 3000 && ok; rep++)\
    \ {\n        int n = rng() % 9 + 1, m = rng() % 14;\n        Graph<int> g(n);\n\
    \        std::vector<std::pair<int, int>> es;\n        for (int i = 0; i < m;\
    \ i++) {\n            int u = rng() % n, v = rng() % n;  // \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n            g.add_edge(u,\
    \ v);\n            es.emplace_back(u, v);\n        }\n        LowLink ll(g);\n\
    \        int base = count_components(n, es, -1, -1);\n        std::vector<int>\
    \ arts, bridges;\n        for (int v = 0; v < n; v++) {\n            // v \u3092\
    \u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u3001\u6B8B\u308A\u306E\u9802\u70B9\
    \u306E\u9023\u7D50\u6210\u5206\u304C\u5897\u3048\u308B\u304B\n            // (v\
    \ \u304C\u307B\u304B\u306E\u9802\u70B9\u3068\u3064\u306A\u304C\u3063\u3066\u3044\
    \u306A\u3051\u308C\u3070\u3001v \u306E\u5206\u3060\u3051 1 \u6E1B\u308B\u306E\u304C\
    \u666E\u901A)\n            bool isolated = true;\n            for (auto [a, b]\
    \ : es) isolated &= !((a == v || b == v) && a != b);\n            bool art = count_components(n,\
    \ es, v, -1) > base - (isolated ? 1 : 0);\n            if (art) arts.push_back(v);\n\
    \            if (ll.is_articulation_point(v) != art) ok = false;\n        }\n\
    \        for (int i = 0; i < m; i++) {\n            bool br = count_components(n,\
    \ es, -1, i) > base;\n            if (br) bridges.push_back(i);\n            if\
    \ (ll.is_bridge(i) != br) ok = false;\n        }\n        if (ll.articulation_points()\
    \ != arts || ll.bridges() != bridges) ok = false;\n\n        // \u4E8C\u91CD\u8FBA\
    \u9023\u7D50\u6210\u5206: \u6A4B\u3092\u3059\u3079\u3066\u53D6\u308A\u9664\u3044\
    \u305F\u3068\u304D\u306E\u9023\u7D50\u6210\u5206\u3068\u4E00\u81F4\u3059\u308B\
    \n        UnionFind uf(n);\n        for (int i = 0; i < m; i++) {\n          \
    \  if (!ll.is_bridge(i)) uf.merge(es[i].first, es[i].second);\n        }\n   \
    \     const auto& groups = ll.two_edge_connected_groups();\n        int total\
    \ = 0;\n        for (int k = 0; k < (int)groups.size(); k++) {\n            total\
    \ += groups[k].size();\n            for (int v : groups[k]) {\n              \
    \  if (ll.two_edge_connected_group_id(v) != k || !uf.same(v, groups[k][0])) ok\
    \ = false;\n            }\n        }\n        int uf_groups = 0;\n        for\
    \ (int v = 0; v < n; v++) uf_groups += uf.leader(v) == v;\n        if (total !=\
    \ n || (int)groups.size() != uf_groups) ok = false;\n    }\n\n    if (ok)\n  \
    \      std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/lowlink.hpp
  - src/graph/graph.hpp
  - src/data_structures/unionfind.hpp
  isVerificationFile: true
  path: test/unittest/lowlink.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 16:37:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/lowlink.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/lowlink.test.cpp
- /verify/test/unittest/lowlink.test.cpp.html
title: test/unittest/lowlink.test.cpp
---
