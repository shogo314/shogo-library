---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/heavy-light-decomposition.hpp
    title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.5.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n// HeavyLightDecomposition \u306E lca \u3092\u4F7F\u3046\n\n#include <iostream>\n\
    \n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n * @brief \u30B0\
    \u30E9\u30D5\n */\n\n#include <algorithm>\n#include <cassert>\n#include <deque>\n\
    #include <functional>\n#line 13 \"src/graph/graph.hpp\"\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u30B0\u30E9\
    \u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\
    \u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\nstruct Graph {\n\
    \    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n \
    \    * operator int()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001\
    int\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\
    \u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\
    \u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\
    \u308C\u308B\u304C\u3001\n     * for (int dst : g[v]) \u3068\u3059\u308B\u3068\
    \u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\
    \u3055\u308C\u308B\n     */\n    struct Edge {\n        int src = -1;   //!< \u59CB\
    \u70B9\n        int dst = -1;   //!< \u7D42\u70B9\n        Cost cost = {}; //!<\
    \ \u30B3\u30B9\u30C8\n        int id = -1;    //!< \u8FBA\u306E\u756A\u53F7(\u8FFD\
    \u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\u5834\u5408\u306F\
    id\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\u306E\u304C2\u3064\
    \u5B58\u5728\u3059\u308B)\n        Edge() = default;\n        Edge(int src, int\
    \ dst, Cost cost = 1, int id = -1) : src(src), dst(dst), cost(cost), id(id) {}\n\
    \        operator int() const { return dst; }\n    };\n\n    /**\n     * @brief\
    \ \u6700\u77ED\u8DEF\u306E\u7D50\u679C\n     *\n     * auto [dist, prev] = g.shortest_path(s);\
    \ \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\u308C\u308B\n     */\n    struct\
    \ ShortestPath {\n        std::vector<Cost> dist;  //!< \u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u9577\n        std::vector<Edge> prev;  //!< \u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (\u59CB\
    \u70B9\u3068\u672A\u5230\u9054\u306E\u9802\u70B9\u3067\u306F src == -1)\n    \
    \    /**\n         * @brief \u59CB\u70B9\u304B\u3089 t \u3078\u306E\u6700\u77ED\
    \u8DEF\u3092\u69CB\u6210\u3059\u308B\u8FBA\u306E\u30EA\u30B9\u30C8 (\u59CB\u70B9\
    \u5074\u304B\u3089\u9806\u306B)\n         * @note t \u304C\u59CB\u70B9\u304B\u672A\
    \u5230\u9054\u306E\u9802\u70B9\u306A\u3089\u7A7A\u3002\u8CA0\u9589\u8DEF\u306E\
    \u5F71\u97FF\u3092\u53D7\u3051\u308B\u9802\u70B9\u3067\u306F\u6700\u77ED\u8DEF\
    \u304C\u5B9A\u307E\u3089\u306A\u3044 (assert \u3067\u843D\u3061\u308B)\n     \
    \    */\n        std::vector<Edge> path(int t) const {\n            std::vector<Edge>\
    \ res;\n            while (prev[t].src != -1) {\n                res.push_back(prev[t]);\n\
    \                assert(res.size() < prev.size() && \"path: negative cycle\");\n\
    \                t = prev[t].src;\n            }\n            std::reverse(res.begin(),\
    \ res.end());\n            return res;\n        }\n    };\n\n    int n;      \
    \                      //!< \u9802\u70B9\u6570\n    int m;                   \
    \         //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>> g; //!< \u30B0\
    \u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n    \
    \ * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\
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
    \ ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\
    \u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\
    \u306E\u8FBA (prev)\n     */\n    ShortestPath shortest_path(int s, bool weighted\
    \ = true, Cost inf = -1) const {\n        if (weighted)\n            return shortest_path_dijkstra(s,\
    \ inf);\n        return shortest_path_bfs(s, inf);\n    }\n    /**\n     * @brief\
    \ \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\n     *\n     * @param s \u59CB\u70B9\n     * @param inf \u30B3\u30B9\u30C8\
    \u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\
    \u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max()\
    \ / 4 \u8CA0\u9589\u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F\
    \ -inf\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\
    \u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath bellman_ford(int\
    \ s, Cost inf = std::numeric_limits<Cost>::max() / 4) const {\n        std::vector<Cost>\
    \ dist(n, inf);\n        std::vector<Edge> prev(n);\n        dist[s] = Cost{};\n\
    \n        for (int i = 1; i < n; i++) {\n            bool changed = false;\n \
    \           for (int j = 0; j < n; j++)\n                for (const auto &e :\
    \ g[j]) {\n                    if (dist[e.src] == inf)\n                     \
    \   continue;\n                    if (dist[e.dst] > dist[e.src] + e.cost) {\n\
    \                        dist[e.dst] = dist[e.src] + e.cost;\n               \
    \         if (dist[e.dst] < -inf)\n                            dist[e.dst] = -inf;\n\
    \                        prev[e.dst] = e;\n                        changed = true;\n\
    \                    }\n                }\n            if (!changed)\n       \
    \         break;\n        }\n        for (int i = 0; i < n; i++) {\n         \
    \   bool changed = false;\n            for (int j = 0; j < n; j++)\n         \
    \       for (const auto &e : g[j]) {\n                    if (dist[e.src] == inf)\n\
    \                        continue;\n                    if (dist[e.dst] > dist[e.src]\
    \ + e.cost) {\n                        dist[e.dst] = -inf;\n                 \
    \       prev[e.dst] = e;\n                        changed = true;\n          \
    \          }\n                }\n            if (!changed)\n                break;\n\
    \        }\n        return {dist, prev};\n    }\n    /**\n     * @brief \u8FBA\
    \u306E\u30B3\u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\
    \u3067\u3001\u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DEF (01-BFS) O(n + m)\n     *\n     * @param s \u59CB\u70B9\n \
    \    * @param inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\
    \ \u7701\u7565\u3059\u308B\u3068 -1\n     * @return ShortestPath \u5404\u9802\u70B9\
    \u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\
    \u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n\
    \    ShortestPath shortest_path_01bfs(int s, Cost inf = -1) const {\n        std::vector<Cost>\
    \ dist(n, inf);\n        std::vector<Edge> prev(n);\n        std::deque<int> que;\n\
    \        dist[s] = 0;\n        que.push_back(s);\n        while (!que.empty())\
    \ {\n            int u = que.front();\n            que.pop_front();\n        \
    \    for (auto &e : g[u]) {\n                assert(e.cost == 0 || e.cost == 1);\n\
    \                if (dist[e.dst] == inf || dist[e.dst] > dist[u] + e.cost) {\n\
    \                    dist[e.dst] = dist[u] + e.cost;\n                    prev[e.dst]\
    \ = e;\n                    if (e.cost == 0) que.push_front(e.dst);\n        \
    \            else que.push_back(e.dst);\n                }\n            }\n  \
    \      }\n        return {dist, prev};\n    }\n    /**\n     * @brief \u5168\u70B9\
    \u5BFE\u9593\u306E\u6700\u77ED\u8DEF\u9577 (Floyd-Warshall) O(n^3)\n     *\n \
    \    * @param inf \u672A\u5230\u9054\u3092\u8868\u3059\u5024 \u7701\u7565\u3059\
    \u308B\u3068 std::numeric_limits<Cost>::max() / 4\n     * @return std::vector<std::vector<Cost>>\
    \ dist[i][j] \u304C i \u304B\u3089 j \u3078\u306E\u6700\u77ED\u8DEF\u9577 (\u5230\
    \u9054\u3067\u304D\u306A\u3051\u308C\u3070 inf)\n     * @note \u8CA0\u306E\u8FBA\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\u3002dist[i][i] < 0 \u3068\u306A\u308B\
    \ i \u304C\u3042\u308C\u3070\u8CA0\u9589\u8DEF\u304C\u3042\u308B\n     */\n  \
    \  std::vector<std::vector<Cost>> floyd_warshall(Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) const {\n        std::vector<std::vector<Cost>> dist(n, std::vector<Cost>(n,\
    \ inf));\n        for (int i = 0; i < n; i++) dist[i][i] = Cost{};\n        for\
    \ (int i = 0; i < n; i++) {\n            for (auto &e : g[i]) dist[i][e.dst] =\
    \ std::min(dist[i][e.dst], e.cost);\n        }\n        for (int k = 0; k < n;\
    \ k++) {\n            for (int i = 0; i < n; i++) {\n                if (dist[i][k]\
    \ == inf) continue;\n                for (int j = 0; j < n; j++) {\n         \
    \           if (dist[k][j] == inf) continue;\n                    dist[i][j] =\
    \ std::min(dist[i][j], dist[i][k] + dist[k][j]);\n                }\n        \
    \    }\n        }\n        return dist;\n    }\n\n  private:\n    ShortestPath\
    \ shortest_path_bfs(int s, Cost inf) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        std::queue<int> que;\n  \
    \      dist[s] = 0;\n        que.push(s);\n        while (!que.empty()) {\n  \
    \          int u = que.front();\n            que.pop();\n            for (auto\
    \ &e : g[u]) {\n                if (dist[e.dst] == inf) {\n                  \
    \  dist[e.dst] = dist[e.src] + 1;\n                    prev[e.dst] = e;\n    \
    \                que.push(e.dst);\n                }\n            }\n        }\n\
    \        return {dist, prev};\n    }\n    ShortestPath shortest_path_dijkstra(int\
    \ s, Cost inf) const {\n        std::vector<Cost> dist(n, inf);\n        std::vector<Edge>\
    \ prev(n);\n        using Node = std::pair<Cost, int>;\n        std::priority_queue<Node,\
    \ std::vector<Node>, std::greater<Node>> que;\n        dist[s] = 0;\n        que.push({0,\
    \ s});\n        while (!que.empty()) {\n            auto [d, u] = que.top();\n\
    \            que.pop();\n            if (d > dist[u])\n                continue;\n\
    \            for (auto &e : g[u]) {\n                if (dist[e.dst] == inf ||\
    \ dist[e.dst] > dist[e.src] + e.cost) {\n                    dist[e.dst] = dist[e.src]\
    \ + e.cost;\n                    prev[e.dst] = e;\n                    que.push({dist[e.dst],\
    \ e.dst});\n                }\n            }\n        }\n        return {dist,\
    \ prev};\n    }\n};\n#line 2 \"src/graph/heavy-light-decomposition.hpp\"\n\n/**\n\
    \ * @file heavy-light-decomposition.hpp\n * @brief HL \u5206\u89E3 (Heavy-Light\
    \ Decomposition)\n */\n\n#line 12 \"src/graph/heavy-light-decomposition.hpp\"\n\
    \n/**\n * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n *\n * \u6728\u306E\
    \u9802\u70B9\u3092\u3001\u3069\u306E\u30D1\u30B9\u3082 O(log n) \u500B\u306E\u533A\
    \u9593\u306B\u5206\u304B\u308C\u3001\u3069\u306E\u90E8\u5206\u6728\u3082 1 \u3064\
    \u306E\u533A\u9593\u306B\u306A\u308B\u3088\u3046\u306B\u4E26\u3079\u66FF\u3048\
    \u308B\n * \u9802\u70B9 v \u306F\u5217\u306E index(v) \u756A\u76EE\u306B\u5BFE\
    \u5FDC\u3059\u308B\u3002\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u3068\
    \u7D44\u307F\u5408\u308F\u305B\u3066\u3001\u30D1\u30B9\u3084\u90E8\u5206\u6728\
    \u3078\u306E\u30AF\u30A8\u30EA\u3092\u884C\u3046\n * \u524D\u8A08\u7B97 O(n)\u3002\
    DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * HeavyLightDecomposition\
    \ hld(g, root);\n * for (auto [a, b] : hld.path(u, v)) sum += seg.prod(std::min(a,\
    \ b), std::max(a, b) + 1);\n * auto [l, r] = hld.subtree(v);  // \u90E8\u5206\u6728\
    \u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition {\n    int n, root;\n\
    \    std::vector<int> par, dep, sz, heavy, head, in, order;\n\npublic:\n    /**\n\
    \     * @brief \u6728 tree \u3092\u6839 root \u3067 HL \u5206\u89E3\u3059\u308B\
    \n     * @param tree Graph\u3001Tree\u3001RootedTree \u306A\u3069\u3002tree.n\
    \ \u304C\u9802\u70B9\u6570\u3001for (int u : tree[v]) \u3067 v \u306B\u96A3\u63A5\
    \u3059\u308B\u9802\u70B9\u3092\u5217\u6319\u3067\u304D\u308B\u3053\u3068\n   \
    \  */\n    template <typename G>\n    explicit HeavyLightDecomposition(const G&\
    \ tree, int root = 0)\n        : n(tree.n), root(root), par(n, -1), dep(n, 0),\
    \ sz(n, 1), heavy(n, -1), head(n), in(n), order(n) {\n        assert(0 <= root\
    \ && root < n);\n        // \u6839\u304B\u3089\u306E BFS \u9806\u3067\u89AA\u3068\
    \u6DF1\u3055\u3092\u6C7A\u3081\u308B\n        std::vector<int> bfs = {root};\n\
    \        bfs.reserve(n);\n        for (int i = 0; i < (int)bfs.size(); i++) {\n\
    \            int v = bfs[i];\n            for (int u : tree[v]) {\n          \
    \      if (u == par[v]) continue;\n                assert(u != root && par[u]\
    \ == -1 && \"HeavyLightDecomposition: not a tree\");\n                par[u] =\
    \ v;\n                dep[u] = dep[v] + 1;\n                bfs.push_back(u);\n\
    \            }\n        }\n        assert((int)bfs.size() == n && \"HeavyLightDecomposition:\
    \ not connected\");\n        // \u8449\u306E\u5074\u304B\u3089\u90E8\u5206\u6728\
    \u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u3001\u6700\u3082\u5927\u304D\u3044\
    \u5B50\u3092 heavy \u306B\u3059\u308B\n        for (int i = n - 1; i > 0; i--)\
    \ {\n            int v = bfs[i], p = par[v];\n            sz[p] += sz[v];\n  \
    \          if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;\n       \
    \ }\n        // heavy \u306A\u5B50\u3092\u6700\u5F8C\u306B\u7A4D\u3080\u3068\u3001\
    \u6B21\u306B\u53D6\u308A\u51FA\u3055\u308C\u3066 index \u304C\u9023\u7D9A\u3059\
    \u308B\n        std::vector<int> st = {root};\n        head[root] = root;\n  \
    \      int k = 0;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = k;\n            order[k++] =\
    \ v;\n            for (int u : tree[v]) {\n                if (u == par[v] ||\
    \ u == heavy[v]) continue;\n                head[u] = u;\n                st.push_back(u);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int size() const { return n; }\n    /**\n     * @brief \u9802\
    \u70B9 v \u306E\u5217\u3067\u306E\u4F4D\u7F6E\n     */\n    int index(int v) const\
    \ { return in[v]; }\n    /**\n     * @brief \u5217\u306E i \u756A\u76EE\u306E\u9802\
    \u70B9 (index \u306E\u9006)\n     */\n    int vertex(int i) const { return order[i];\
    \ }\n    /**\n     * @brief v \u306E\u89AA (\u6839\u306A\u3089 -1)\n     */\n\
    \    int parent(int v) const { return par[v]; }\n    /**\n     * @brief v \u306E\
    \u6DF1\u3055 (\u6839\u306F 0\u3001\u8FBA\u306E\u672C\u6570)\n     */\n    int\
    \ depth(int v) const { return dep[v]; }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    int subtree_size(int v) const { return sz[v]; }\n    /**\n     * @brief\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u533A\u9593 [l, r)\n     */\n    std::pair<int, int> subtree(int\
    \ v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n     * @brief u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n     */\n    int lca(int\
    \ u, int v) const {\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ < dep[head[v]]) std::swap(u, v);\n            u = par[head[u]];\n        }\n\
    \        return dep[u] < dep[v] ? u : v;\n    }\n    /**\n     * @brief u \u3068\
    \ v \u306E\u9593\u306E\u8FBA\u306E\u672C\u6570 O(log n)\n     */\n    int dist(int\
    \ u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n    /**\n\
    \     * @brief v \u304B\u3089\u6839\u306E\u65B9\u3078 k \u672C\u306E\u8FBA\u3092\
    \u9032\u3093\u3060\u9802\u70B9 (k > depth(v) \u306A\u3089 -1) O(log n)\n     */\n\
    \    int climb(int v, int k) const {\n        if (k < 0 || k > dep[v]) return\
    \ -1;\n        while (true) {\n            int h = head[v];\n            if (in[v]\
    \ - in[h] >= k) return order[in[v] - k];\n            k -= in[v] - in[h] + 1;\n\
    \            v = par[h];\n        }\n    }\n    /**\n     * @brief u \u304B\u3089\
    \ v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089 k \u672C\u306E\u8FBA\u3092\
    \u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\u3089 -1) O(log n)\n   \
    \  */\n    int jump(int u, int v, int k) const {\n        if (k < 0) return -1;\n\
    \        int w = lca(u, v);\n        int du = dep[u] - dep[w], dv = dep[v] - dep[w];\n\
    \        if (k <= du) return climb(u, k);\n        if (k <= du + dv) return climb(v,\
    \ du + dv - k);\n        return -1;\n    }\n\n    /**\n     * @brief u \u304B\u3089\
    \ v \u3078\u306E\u30D1\u30B9\u3092\u3001\u5217\u306E\u533A\u9593\u306B\u5206\u3051\
    \u3066 u \u5074\u304B\u3089\u9806\u306B\u4E26\u3079\u308B O(log n)\n     *\n \
    \    * \u5404\u8981\u7D20 (a, b) \u306F\u3001\u5217\u306E a \u756A\u76EE\u304B\
    \u3089 b \u756A\u76EE\u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u3092\u3001\
    a \u304B\u3089 b \u306E\u5411\u304D\u306B\u305F\u3069\u308B\u3053\u3068\u3092\u8868\
    \u3059\n     * a > b \u306A\u3089 index \u304C\u6E1B\u308B\u5411\u304D (\u6839\
    \u306B\u8FD1\u3065\u304F\u5411\u304D) \u306B\u305F\u3069\u308B\n     * \u4EA4\u63DB\
    \u6CD5\u5247\u304C\u6210\u308A\u7ACB\u305F\u306A\u3044\u6F14\u7B97\u3067\u306F\
    \u3001a > b \u306E\u533A\u9593\u306F\u9006\u9806\u306E\u7A4D\u3092\u4F7F\u3046\
    \n     * @param edge true \u306A\u3089\u8FBA\u306B\u3064\u3044\u3066\u306E\u30D1\
    \u30B9\u306B\u3059\u308B\u3002\u8FBA (parent(v), v) \u3092 index(v) \u756A\u76EE\
    \u306B\u5BFE\u5FDC\u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\u3092\u542B\u3081\u306A\
    \u3044\n     */\n    std::vector<std::pair<int, int>> path(int u, int v, bool\
    \ edge = false) const {\n        std::vector<std::pair<int, int>> up, down;\n\
    \        while (head[u] != head[v]) {\n            if (dep[head[u]] >= dep[head[v]])\
    \ {\n                up.emplace_back(in[u], in[head[u]]);\n                u =\
    \ par[head[u]];\n            } else {\n                down.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   if (dep[u] >= dep[v]) {\n            // v \u304C lca\n            int l =\
    \ in[v] + edge;\n            if (l <= in[u]) up.emplace_back(in[u], l);\n    \
    \    } else {\n            // u \u304C lca\n            int l = in[u] + edge;\n\
    \            if (l <= in[v]) down.emplace_back(l, in[v]);\n        }\n       \
    \ up.insert(up.end(), down.rbegin(), down.rend());\n        return up;\n    }\n\
    };\n#line 9 \"test/yosupo/lca.5.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, q;\n    std::cin >> n >> q;\n\
    \    Graph<int> g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n   \
    \     std::cin >> p;\n        g.add_edge(p, i);\n    }\n    HeavyLightDecomposition\
    \ hld(g);\n    while (q--) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        std::cout << hld.lca(u, v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n// HeavyLightDecomposition\
    \ \u306E lca \u3092\u4F7F\u3046\n\n#include <iostream>\n\n#include \"../../src/graph/graph.hpp\"\
    \n#include \"../../src/graph/heavy-light-decomposition.hpp\"\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    std::cin >> n >> q;\n    Graph<int> g(n);\n    for (int i = 1; i < n;\
    \ i++) {\n        int p;\n        std::cin >> p;\n        g.add_edge(p, i);\n\
    \    }\n    HeavyLightDecomposition hld(g);\n    while (q--) {\n        int u,\
    \ v;\n        std::cin >> u >> v;\n        std::cout << hld.lca(u, v) << '\\n';\n\
    \    }\n}\n"
  dependsOn:
  - src/graph/graph.hpp
  - src/graph/heavy-light-decomposition.hpp
  isVerificationFile: true
  path: test/yosupo/lca.5.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 20:58:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.5.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.5.test.cpp
- /verify/test/yosupo/lca.5.test.cpp.html
title: test/yosupo/lca.5.test.cpp
---
