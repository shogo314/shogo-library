---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/two-sat.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-11-d.1.test.cpp
    title: test/aoj/alds1-11-d.1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-2-a.test.cpp
    title: test/aoj/grl-2-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-4-a.test.cpp
    title: test/aoj/grl-4-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph-util.test.cpp
    title: test/unittest/graph-util.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/two-sat.test.cpp
    title: test/unittest/two-sat.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/minimum-spanning-tree.2.test.cpp
    title: test/yosupo/minimum-spanning-tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two-sat.test.cpp
    title: test/yosupo/two-sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
    links: []
  bundledCode: "#line 2 \"src/graph/graph_util.hpp\"\n\n/**\n * @file graph_util.hpp\n\
    \ * @brief \u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570\n */\n\n#include\
    \ <algorithm>\n#include <functional>\n#include <queue>\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file\
    \ graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\
    \n#include <cassert>\n#include <deque>\n#line 12 \"src/graph/graph.hpp\"\n#include\
    \ <iostream>\n#include <limits>\n#line 17 \"src/graph/graph.hpp\"\n\n/**\n * @brief\
    \ \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost\
    \ \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost = int>\n\
    struct Graph {\n    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\
    \n     *\n     * operator int()\u3092\u5B9A\u7FA9\u3057\u3066\u3044\u308B\u306E\
    \u3067\u3001int\u578B\u306B\u30AD\u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\
    \u306Bdst\u306B\u306A\u308B\n     * \u4F8B\u3048\u3070\u3001\n     * for (auto&\
    \ e : g[v]) \u3092\u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\
    \u5217\u6319\u3055\u308C\u308B\u304C\u3001\n     * for (int dst : g[v]) \u3068\
    \u3059\u308B\u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\
    \u304C\u5217\u6319\u3055\u308C\u308B\n     */\n    struct Edge {\n        int\
    \ src = -1;   //!< \u59CB\u70B9\n        int dst = -1;   //!< \u7D42\u70B9\n \
    \       Cost cost = {}; //!< \u30B3\u30B9\u30C8\n        int id = -1;    //!<\
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
    \  return res;\n        }\n    };\n\n    int n;                            //!<\
    \ \u9802\u70B9\u6570\n    int m;                            //!< \u8FBA\u6570\n\
    \    std::vector<std::vector<Edge>> g; //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\
    \u30EA\u30B9\u30C8\u8868\u73FE\n\n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\
    \u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    Graph() : n(0),\
    \ m(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     * @param n \u9802\u70B9\u6570\n     */\n    explicit Graph(int n) : n(n),\
    \ m(0), g(n) {}\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\
    \u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n     * @param\
    \ w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n    void add_edge(int\
    \ u, int v, Cost w = 1) {\n        g[u].push_back({u, v, w, m});\n        g[v].push_back({v,\
    \ u, w, m++});\n    }\n    /**\n     * @brief \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\
    \u3059\u308B\n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n   \
    \  * @param w \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n  \
    \  void add_directed_edge(int u, int v, Cost w = 1) {\n        g[u].push_back({u,\
    \ v, w, m++});\n    }\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\u3092\u6A19\
    \u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\u3063\u3066\u8FFD\u52A0\u3059\
    \u308B\n     * @param m \u8FBA\u306E\u6570\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     * @param weighted \u8FBA\u306E\u91CD\
    \u307F\u304C\u5165\u529B\u3055\u308C\u308B\u304B \u7701\u7565\u3057\u305F\u3089\
    false\u3068\u306A\u308A\u3001\u91CD\u307F1\u3067\u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u308B\n     * @param directed \u6709\u5411\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B \u7701\u7565\u3057\u305F\u3089false\n     */\n    void read(int m,\
    \ int padding = -1, bool weighted = false, bool directed = false) {\n        for\
    \ (int i = 0; i < m; i++) {\n            int u, v;\n            std::cin >> u\
    \ >> v;\n            u += padding, v += padding;\n            Cost c(1);\n   \
    \         if (weighted)\n                std::cin >> c;\n            if (directed)\n\
    \                add_directed_edge(u, v, c);\n            else\n             \
    \   add_edge(u, v, c);\n        }\n    }\n    /**\n     * @brief \u3042\u308B\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return std::vector<Edge>& v\u304B\u3089\u51FA\
    \u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<Edge> &operator[](int\
    \ v) {\n        return g[v];\n    }\n    /**\n     * @brief \u3042\u308B\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u8FBA\u3092\u5217\u6319\u3059\u308B\n     * @param\
    \ v \u9802\u70B9\u756A\u53F7\n     * @return const std::vector<Edge>& v\u304B\u3089\
    \u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n     */\n    const std::vector<Edge>\
    \ &operator[](int v) const {\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\n  \
    \   */\n    std::vector<Edge> edges() const {\n        std::vector<Edge> res(m);\n\
    \        for (int i = 0; i < n; i++) {\n            for (auto &e : g[i]) {\n \
    \               res[e.id] = e;\n            }\n        }\n        return res;\n\
    \    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\n \
    \    * @param weighted 1\u4EE5\u5916\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\
    \u5B58\u5728\u3059\u308B\u304B \u7701\u7565\u3059\u308B\u3068true\n     * @param\
    \ inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\u5230\u9054\u306E\
    \u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B \u7701\u7565\u3059\
    \u308B\u3068\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath shortest_path(int\
    \ s, bool weighted = true, Cost inf = -1) const {\n        if (weighted)\n   \
    \         return shortest_path_dijkstra(s, inf);\n        return shortest_path_bfs(s,\
    \ inf);\n    }\n    /**\n     * @brief \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\
    \u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\n     *\n     * @param s \u59CB\u70B9\
    \n     * @param inf \u30B3\u30B9\u30C8\u306Emin\u306E\u5358\u4F4D\u5143 \u672A\
    \u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2\u306Finf\u306B\u306A\u308B\
    \ \u7701\u7565\u3059\u308B\u3068 std::numeric_limits<Cost>::max() / 4 \u8CA0\u9589\
    \u8DEF\u306E\u5F71\u97FF\u3092\u53D7\u3051\u308B\u70B9\u306F -inf\n     * @return\
    \ ShortestPath \u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u9577 (dist) \u3068\
    \u3001\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\
    \u306E\u8FBA (prev)\n     */\n    ShortestPath bellman_ford(int s, Cost inf =\
    \ std::numeric_limits<Cost>::max() / 4) const {\n        std::vector<Cost> dist(n,\
    \ inf);\n        std::vector<Edge> prev(n);\n        dist[s] = Cost{};\n\n   \
    \     for (int i = 1; i < n; i++) {\n            bool changed = false;\n     \
    \       for (int j = 0; j < n; j++)\n                for (const auto &e : g[j])\
    \ {\n                    if (dist[e.src] == inf)\n                        continue;\n\
    \                    if (dist[e.dst] > dist[e.src] + e.cost) {\n             \
    \           dist[e.dst] = dist[e.src] + e.cost;\n                        if (dist[e.dst]\
    \ < -inf)\n                            dist[e.dst] = -inf;\n                 \
    \       prev[e.dst] = e;\n                        changed = true;\n          \
    \          }\n                }\n            if (!changed)\n                break;\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            bool changed =\
    \ false;\n            for (int j = 0; j < n; j++)\n                for (const\
    \ auto &e : g[j]) {\n                    if (dist[e.src] == inf)\n           \
    \             continue;\n                    if (dist[e.dst] > dist[e.src] + e.cost)\
    \ {\n                        dist[e.dst] = -inf;\n                        prev[e.dst]\
    \ = e;\n                        changed = true;\n                    }\n     \
    \           }\n            if (!changed)\n                break;\n        }\n\
    \        return {dist, prev};\n    }\n    /**\n     * @brief \u8FBA\u306E\u30B3\
    \u30B9\u30C8\u304C 0 \u304B 1 \u3060\u3051\u306E\u30B0\u30E9\u30D5\u3067\u3001\
    \u3042\u308B\u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\
    \u8DEF (01-BFS) O(n + m)\n     *\n     * @param s \u59CB\u70B9\n     * @param\
    \ inf \u672A\u5230\u9054\u306E\u9802\u70B9\u3078\u306E\u8DDD\u96E2 \u7701\u7565\
    \u3059\u308B\u3068 -1\n     * @return ShortestPath \u5404\u9802\u70B9\u3078\u306E\
    \u6700\u77ED\u8DEF\u9577 (dist) \u3068\u3001\u5404\u9802\u70B9\u3078\u306E\u6700\
    \u77ED\u8DEF\u4E0A\u306E\u76F4\u524D\u306E\u8FBA (prev)\n     */\n    ShortestPath\
    \ shortest_path_01bfs(int s, Cost inf = -1) const {\n        std::vector<Cost>\
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
    \ prev};\n    }\n};\n#line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n *\
    \ @file unionfind.hpp\n * @brief UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\
    \u8FBA\u306E\u8FFD\u52A0\u300D\u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\
    \u306E\u5224\u5B9A\u300D\u3092\u3059\u308B\n */\nstruct UnionFind {\n   protected:\n\
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
    };\n#line 17 \"src/graph/graph_util.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\
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
    \ Graph<Cost>& graph) {\n    return has_cycle(graph);\n}\n\n/**\n * @brief \u6709\
    \u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\
    \u308B\n *\n * Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3092\u518D\u5E30\
    \u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n + m)\n *\n * @return std::vector<std::vector<int>>\
    \ \u5F37\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u3002\n * \u6210\u5206\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u306B\
    \u4E26\u3076 (\u6210\u5206 A \u304B\u3089\u6210\u5206 B \u3078\u8FBA\u304C\u3042\
    \u308C\u3070 A \u304C B \u3088\u308A\u524D)\n */\ntemplate <typename Cost = int>\n\
    std::vector<std::vector<int>> strongly_connected_components(const Graph<Cost>&\
    \ graph) {\n    const int n = graph.n;\n    std::vector<int> ord(n, -1), low(n),\
    \ comp(n, -1), iter(n, 0);\n    std::vector<int> visiting;  // \u6210\u5206\u304C\
    \u307E\u3060\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u8A2A\u554F\u6E08\u307F\
    \u306E\u9802\u70B9\n    std::vector<int> call;      // DFS \u306E\u547C\u3073\u51FA\
    \u3057\u30B9\u30BF\u30C3\u30AF\n    int now = 0, k = 0;\n    for (int s = 0; s\
    \ < n; s++) {\n        if (ord[s] != -1) continue;\n        ord[s] = low[s] =\
    \ now++;\n        visiting.push_back(s);\n        call.push_back(s);\n       \
    \ while (!call.empty()) {\n            int v = call.back();\n            if (iter[v]\
    \ < (int)graph[v].size()) {\n                int to = graph[v][iter[v]++].dst;\n\
    \                if (ord[to] == -1) {\n                    ord[to] = low[to] =\
    \ now++;\n                    visiting.push_back(to);\n                    call.push_back(to);\n\
    \                } else if (comp[to] == -1) {\n                    low[v] = std::min(low[v],\
    \ ord[to]);\n                }\n                continue;\n            }\n   \
    \         call.pop_back();\n            if (!call.empty()) low[call.back()] =\
    \ std::min(low[call.back()], low[v]);\n            if (low[v] == ord[v]) {\n \
    \               while (true) {\n                    int u = visiting.back();\n\
    \                    visiting.pop_back();\n                    comp[u] = k;\n\
    \                    if (u == v) break;\n                }\n                k++;\n\
    \            }\n        }\n    }\n    // Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u306F\u6210\u5206\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u306E\u9006\u306B\u898B\u3064\u3051\u308B\u306E\u3067\u3001\u9006\u9806\u306B\
    \u4E26\u3079\u308B\n    std::vector<std::vector<int>> groups(k);\n    for (int\
    \ v = 0; v < n; v++) groups[k - 1 - comp[v]].push_back(v);\n    return groups;\n\
    }\n\n/**\n * @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u7D50\u679C\n */\ntemplate\
    \ <typename Cost>\nstruct MinimumSpanningTree {\n    Cost cost;              \
    \                        //!< \u4F7F\u3063\u305F\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u306E\u7DCF\u548C\n    std::vector<typename Graph<Cost>::Edge> edges;  //!< \u4F7F\
    \u3063\u305F\u8FBA (\u30B3\u30B9\u30C8\u306E\u6607\u9806\u3001\u540C\u3058\u30B3\
    \u30B9\u30C8\u306A\u3089\u8FBA\u306E\u756A\u53F7\u9806)\n};\n\n/**\n * @brief\
    \ \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal\
    \ \u6CD5) O(m log m)\n *\n * \u9023\u7D50\u3067\u306A\u3051\u308C\u3070\u3001\u5404\
    \u9023\u7D50\u6210\u5206\u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u5408\u308F\
    \u305B\u305F\u3082\u306E (\u6700\u5C0F\u5168\u57DF\u68EE) \u3092\u8FD4\u3059\n\
    \ * \u9023\u7D50\u304B\u3069\u3046\u304B\u306F edges.size() == n - 1 \u3067\u5224\
    \u5B9A\u3067\u304D\u308B\n */\ntemplate <typename Cost = int>\nMinimumSpanningTree<Cost>\
    \ minimum_spanning_tree(const Graph<Cost>& graph) {\n    auto es = graph.edges();\n\
    \    std::stable_sort(es.begin(), es.end(), [](const auto& a, const auto& b) {\
    \ return a.cost < b.cost; });\n    UnionFind uf(graph.n);\n    MinimumSpanningTree<Cost>\
    \ res{Cost{}, {}};\n    for (const auto& e : es) {\n        if (uf.merge(e.src,\
    \ e.dst)) {\n            res.cost += e.cost;\n            res.edges.push_back(e);\n\
    \        }\n    }\n    return res;\n}\n\n/**\n * @brief \u6700\u5C0F\u30B7\u30E5\
    \u30BF\u30A4\u30CA\u30FC\u6728\u306E\u8FBA\u91CD\u307F\u306E\u7DCF\u548C\n */\n\
    template <typename Cost, typename T>\nCost minimum_steiner_tree(const Graph<Cost>&\
    \ G, const std::vector<T>& X, Cost inf = -1) {\n    if (X.empty()) return Cost{};\n\
    \    std::vector<std::vector<Cost>> dp(G.n, std::vector<Cost>(1 << X.size(), inf));\n\
    \    for (int p = 0; p < (int)X.size(); p++) dp[X[p]][1 << p] = {};\n    for (int\
    \ i = 0; i < (1 << X.size()); i++) {\n        for (int j = i; j > 0; j = (j -\
    \ 1) & i) {\n            for (int k = 0; k < G.n; k++) {\n                if (dp[k][j]\
    \ != inf && dp[k][i ^ j] != inf) {\n                    if (dp[k][i] == inf ||\
    \ dp[k][i] > dp[k][j] + dp[k][i ^ j]) dp[k][i] = dp[k][j] + dp[k][i ^ j];\n  \
    \              }\n            }\n        }\n        std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>, std::greater<std::pair<Cost, int>>>\
    \ que;\n        for (int k = 0; k < G.n; k++)\n            if (dp[k][i] != inf)\
    \ que.emplace(dp[k][i], k);\n        while (que.size()) {\n            auto [d,\
    \ u] = que.top();\n            que.pop();\n            if (d > dp[u][i]) continue;\n\
    \            for (auto e : G[u]) {\n                if (dp[e.dst][i] == inf ||\
    \ dp[e.dst][i] > d + e.cost) {\n                    dp[e.dst][i] = d + e.cost;\n\
    \                    que.emplace(d + e.cost, e.dst);\n                }\n    \
    \        }\n        }\n    }\n    Cost res = inf;\n    for (int k = 0; k < G.n;\
    \ k++) {\n        if (dp[k].back() != inf && (res == inf || res > dp[k].back()))\
    \ res = dp[k].back();\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file graph_util.hpp\n * @brief \u30B0\u30E9\u30D5\
    \u306B\u95A2\u3059\u308B\u95A2\u6570\n */\n\n#include <algorithm>\n#include <functional>\n\
    #include <queue>\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    #include \"graph.hpp\"\n#include \"../data_structures/unionfind.hpp\"\n\n/**\n\
    \ * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u306A\u30890\u30681\u306B\u5F69\u8272\u3057\u305F\u7D50\u679C\
    \u3092\u3072\u3068\u3064\u8FD4\u3057\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\
    \u306A\u3044\u306A\u3089\u7A7A\u306Evector\u3092\u8FD4\u3059\u3002\n * \u9023\u7D50\
    \u6210\u5206\u306E\u3046\u3061\u3001\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306E\
    \u6700\u3082\u5C0F\u3055\u3044\u3082\u306E\u30920\u306B\u3059\u308B\u3002\n *\
    \ @return std::vector<int> \u5404\u9802\u70B9\u306E\u5F69\u8272\u7D50\u679C\n\
    \ */\ntemplate <typename Cost = int>\nstd::vector<int> bipartite_coloring(const\
    \ Graph<Cost>& graph) {\n    std::vector<int> color(graph.n, -1);\n    for (int\
    \ i = 0; i < graph.n; i++) {\n        if (color[i] != -1) continue;\n        std::stack<int>\
    \ stk;\n        stk.push(i);\n        color[i] = 0;\n        while (!stk.empty())\
    \ {\n            int u = stk.top();\n            stk.pop();\n            for (int\
    \ v : graph[u]) {\n                if (color[v] == -1) {\n                   \
    \ color[v] = color[u] ^ 1;\n                    stk.push(v);\n               \
    \ } else {\n                    if (color[u] == color[v]) return {};\n       \
    \         }\n            }\n        }\n    }\n    return color;\n}\n\n/**\n *\
    \ @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\
    \n * @return bool \u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\u3089true\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n\
    \ */\ntemplate <typename Cost = int>\nbool is_bipartite(const Graph<Cost>& graph)\
    \ {\n    return !bipartite_coloring(graph).empty();\n}\n\n/**\n * @brief \u7121\
    \u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3059\u308B\u3002\n * @return std::vector<std::vector<int>> \u300C\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u3068\u306A\u308B\u9802\u70B9\u306E\u30EA\
    \u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n */\ntemplate <typename Cost = int>\n\
    std::vector<std::vector<int>> connected_components(const Graph<Cost>& graph) {\n\
    \    std::vector<std::vector<int>> groups;\n    std::vector<bool> visited(graph.n);\n\
    \    for (int i = 0; i < graph.n; i++) {\n        if (visited[i]) continue;\n\
    \        std::stack<int> stk;\n        stk.push(i);\n        visited[i] = true;\n\
    \        groups.push_back({i});\n        while (!stk.empty()) {\n            int\
    \ u = stk.top();\n            stk.pop();\n            for (int v : graph[u]) {\n\
    \                if (visited[v]) continue;\n                visited[v] = true;\n\
    \                stk.push(v);\n                groups.back().push_back(v);\n \
    \           }\n        }\n    }\n    return groups;\n}\n\n/**\n * @brief \u7121\
    \u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u30B0\u30E9\
    \u30D5\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return\
    \ bool \u9023\u7D50\u30B0\u30E9\u30D5\u306A\u3089true\u3001\u9023\u7D50\u30B0\u30E9\
    \u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate\
    \ <typename Cost = int>\nbool is_connected(const Graph<Cost>& graph) {\n    return\
    \ connected_components(graph).size() == 1;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u6728\u304B\u3069\u3046\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u6728\u306A\u3089true\u3001\u6728\
    \u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename\
    \ Cost = int>\nbool is_tree(const Graph<Cost>& graph) {\n    return graph.m ==\
    \ graph.n - 1 && is_connected(graph);\n}\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\
    \u30D5\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\
    \n * @param G \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\
    \u30B0\u30E9\u30D5\n * @return \u30BD\u30FC\u30C8\u3055\u308C\u305F\u30CE\u30FC\
    \u30C9\u756A\u53F7\u306Evector DAG\u3067\u306A\u3051\u308C\u3070\u9577\u3055\u304C\
    G.n\u672A\u6E80\u306B\u306A\u308B\n */\ntemplate <typename Cost>\nstd::vector<int>\
    \ topological_sort(const Graph<Cost>& G) {\n    std::vector<int> indeg(G.n), sorted;\n\
    \    std::queue<int> q;\n    for (int i = 0; i < G.n; i++) {\n        for (int\
    \ dst : G[i]) indeg[dst]++;\n    }\n    for (int i = 0; i < G.n; i++) {\n    \
    \    if (!indeg[i]) q.push(i);\n    }\n    while (!q.empty()) {\n        int cur\
    \ = q.front();\n        q.pop();\n        for (int dst : G[cur]) {\n         \
    \   if (!--indeg[dst]) q.push(dst);\n        }\n        sorted.push_back(cur);\n\
    \    }\n    return sorted;\n}\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\
    \u306B\u3064\u3044\u3066\u3001\u30B5\u30A4\u30AF\u30EB\u3092\u3082\u3064\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u30B5\
    \u30A4\u30AF\u30EB\u3092\u3082\u3064\u306A\u3089true\u3001\u975E\u5DE1\u56DE\u306A\
    \u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename Cost = int>\nbool\
    \ has_cycle(const Graph<Cost>& graph) {\n    return (int)topological_sort(graph).size()\
    \ < graph.n;\n}\n/**\n * @deprecated has_cycle \u3092\u4F7F\u3046\u3053\u3068\
    (\u540D\u524D\u3068\u610F\u5473\u304C\u9006\u306B\u8AAD\u3081\u308B\u305F\u3081\
    \u6539\u540D\u3057\u305F)\n */\ntemplate <typename Cost = int>\n[[deprecated(\"\
    use has_cycle\")]] bool has_acyclic(const Graph<Cost>& graph) {\n    return has_cycle(graph);\n\
    }\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3059\u308B\n *\n * Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n +\
    \ m)\n *\n * @return std::vector<std::vector<int>> \u5F37\u9023\u7D50\u6210\u5206\
    \u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3002\n * \u6210\u5206\u306F\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u306B\u4E26\u3076 (\u6210\u5206 A \u304B\
    \u3089\u6210\u5206 B \u3078\u8FBA\u304C\u3042\u308C\u3070 A \u304C B \u3088\u308A\
    \u524D)\n */\ntemplate <typename Cost = int>\nstd::vector<std::vector<int>> strongly_connected_components(const\
    \ Graph<Cost>& graph) {\n    const int n = graph.n;\n    std::vector<int> ord(n,\
    \ -1), low(n), comp(n, -1), iter(n, 0);\n    std::vector<int> visiting;  // \u6210\
    \u5206\u304C\u307E\u3060\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u8A2A\u554F\
    \u6E08\u307F\u306E\u9802\u70B9\n    std::vector<int> call;      // DFS \u306E\u547C\
    \u3073\u51FA\u3057\u30B9\u30BF\u30C3\u30AF\n    int now = 0, k = 0;\n    for (int\
    \ s = 0; s < n; s++) {\n        if (ord[s] != -1) continue;\n        ord[s] =\
    \ low[s] = now++;\n        visiting.push_back(s);\n        call.push_back(s);\n\
    \        while (!call.empty()) {\n            int v = call.back();\n         \
    \   if (iter[v] < (int)graph[v].size()) {\n                int to = graph[v][iter[v]++].dst;\n\
    \                if (ord[to] == -1) {\n                    ord[to] = low[to] =\
    \ now++;\n                    visiting.push_back(to);\n                    call.push_back(to);\n\
    \                } else if (comp[to] == -1) {\n                    low[v] = std::min(low[v],\
    \ ord[to]);\n                }\n                continue;\n            }\n   \
    \         call.pop_back();\n            if (!call.empty()) low[call.back()] =\
    \ std::min(low[call.back()], low[v]);\n            if (low[v] == ord[v]) {\n \
    \               while (true) {\n                    int u = visiting.back();\n\
    \                    visiting.pop_back();\n                    comp[u] = k;\n\
    \                    if (u == v) break;\n                }\n                k++;\n\
    \            }\n        }\n    }\n    // Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u306F\u6210\u5206\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\
    \u306E\u9006\u306B\u898B\u3064\u3051\u308B\u306E\u3067\u3001\u9006\u9806\u306B\
    \u4E26\u3079\u308B\n    std::vector<std::vector<int>> groups(k);\n    for (int\
    \ v = 0; v < n; v++) groups[k - 1 - comp[v]].push_back(v);\n    return groups;\n\
    }\n\n/**\n * @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u7D50\u679C\n */\ntemplate\
    \ <typename Cost>\nstruct MinimumSpanningTree {\n    Cost cost;              \
    \                        //!< \u4F7F\u3063\u305F\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u306E\u7DCF\u548C\n    std::vector<typename Graph<Cost>::Edge> edges;  //!< \u4F7F\
    \u3063\u305F\u8FBA (\u30B3\u30B9\u30C8\u306E\u6607\u9806\u3001\u540C\u3058\u30B3\
    \u30B9\u30C8\u306A\u3089\u8FBA\u306E\u756A\u53F7\u9806)\n};\n\n/**\n * @brief\
    \ \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728 (Kruskal\
    \ \u6CD5) O(m log m)\n *\n * \u9023\u7D50\u3067\u306A\u3051\u308C\u3070\u3001\u5404\
    \u9023\u7D50\u6210\u5206\u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\u5408\u308F\
    \u305B\u305F\u3082\u306E (\u6700\u5C0F\u5168\u57DF\u68EE) \u3092\u8FD4\u3059\n\
    \ * \u9023\u7D50\u304B\u3069\u3046\u304B\u306F edges.size() == n - 1 \u3067\u5224\
    \u5B9A\u3067\u304D\u308B\n */\ntemplate <typename Cost = int>\nMinimumSpanningTree<Cost>\
    \ minimum_spanning_tree(const Graph<Cost>& graph) {\n    auto es = graph.edges();\n\
    \    std::stable_sort(es.begin(), es.end(), [](const auto& a, const auto& b) {\
    \ return a.cost < b.cost; });\n    UnionFind uf(graph.n);\n    MinimumSpanningTree<Cost>\
    \ res{Cost{}, {}};\n    for (const auto& e : es) {\n        if (uf.merge(e.src,\
    \ e.dst)) {\n            res.cost += e.cost;\n            res.edges.push_back(e);\n\
    \        }\n    }\n    return res;\n}\n\n/**\n * @brief \u6700\u5C0F\u30B7\u30E5\
    \u30BF\u30A4\u30CA\u30FC\u6728\u306E\u8FBA\u91CD\u307F\u306E\u7DCF\u548C\n */\n\
    template <typename Cost, typename T>\nCost minimum_steiner_tree(const Graph<Cost>&\
    \ G, const std::vector<T>& X, Cost inf = -1) {\n    if (X.empty()) return Cost{};\n\
    \    std::vector<std::vector<Cost>> dp(G.n, std::vector<Cost>(1 << X.size(), inf));\n\
    \    for (int p = 0; p < (int)X.size(); p++) dp[X[p]][1 << p] = {};\n    for (int\
    \ i = 0; i < (1 << X.size()); i++) {\n        for (int j = i; j > 0; j = (j -\
    \ 1) & i) {\n            for (int k = 0; k < G.n; k++) {\n                if (dp[k][j]\
    \ != inf && dp[k][i ^ j] != inf) {\n                    if (dp[k][i] == inf ||\
    \ dp[k][i] > dp[k][j] + dp[k][i ^ j]) dp[k][i] = dp[k][j] + dp[k][i ^ j];\n  \
    \              }\n            }\n        }\n        std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>, std::greater<std::pair<Cost, int>>>\
    \ que;\n        for (int k = 0; k < G.n; k++)\n            if (dp[k][i] != inf)\
    \ que.emplace(dp[k][i], k);\n        while (que.size()) {\n            auto [d,\
    \ u] = que.top();\n            que.pop();\n            if (d > dp[u][i]) continue;\n\
    \            for (auto e : G[u]) {\n                if (dp[e.dst][i] == inf ||\
    \ dp[e.dst][i] > d + e.cost) {\n                    dp[e.dst][i] = d + e.cost;\n\
    \                    que.emplace(d + e.cost, e.dst);\n                }\n    \
    \        }\n        }\n    }\n    Cost res = inf;\n    for (int k = 0; k < G.n;\
    \ k++) {\n        if (dp[k].back() != inf && (res == inf || res > dp[k].back()))\
    \ res = dp[k].back();\n    }\n    return res;\n}\n"
  dependsOn:
  - src/graph/graph.hpp
  - src/data_structures/unionfind.hpp
  isVerificationFile: false
  path: src/graph/graph_util.hpp
  requiredBy:
  - src/graph/two-sat.hpp
  timestamp: '2026-10-13 20:34:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/two-sat.test.cpp
  - test/unittest/graph-util.test.cpp
  - test/aoj/grl-4-a.test.cpp
  - test/aoj/grl-2-a.test.cpp
  - test/aoj/alds1-11-d.1.test.cpp
  - test/yosupo/two-sat.test.cpp
  - test/yosupo/minimum-spanning-tree.2.test.cpp
  - test/yosupo/scc.test.cpp
documentation_of: src/graph/graph_util.hpp
layout: document
title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
---

[グラフ](graph.hpp) `Graph<Cost>` を受け取る関数です。

| 関数 | 対象 | 説明 | 計算量 |
|---|---|---|---|
| `is_bipartite(g)` | 無向 | 二部グラフか | $O(n + m)$ |
| `bipartite_coloring(g)` | 無向 | 二部グラフなら各頂点を 0, 1 に彩色した結果 (各連結成分で番号最小の頂点を 0 にする)。二部グラフでなければ空 | $O(n + m)$ |
| `connected_components(g)` | 無向 | 連結成分ごとの頂点のリスト | $O(n + m)$ |
| `is_connected(g)` | 無向 | 連結か | $O(n + m)$ |
| `is_tree(g)` | 無向 | 木か | $O(n + m)$ |
| `topological_sort(g)` | 有向 | トポロジカル順に並べた頂点のリスト。DAG でなければ長さが `n` 未満になる | $O(n + m)$ |
| `has_cycle(g)` | 有向 | 閉路を持つか | $O(n + m)$ |
| `strongly_connected_components(g)` | 有向 | 強連結成分ごとの頂点のリスト。成分はトポロジカル順 (成分 A から B へ辺があれば A が先) に並ぶ | $O(n + m)$ |
| `minimum_spanning_tree(g)` | 無向 | 最小全域木 (Kruskal 法)。`cost` (コストの総和) と `edges` (使った辺) を持つ構造体を返す。連結でなければ最小全域森 | $O(m \log m)$ |
| `minimum_steiner_tree(g, X, inf = -1)` | 無向 | 頂点集合 `X` をすべて含む部分木の辺の重みの総和の最小値 | $O(3^k n + 2^k m \log m)$ ($k = \lvert X \rvert$) |

強連結成分の番号が頂点ごとに欲しいときは、返ってきたリストから作ります。番号の小さい成分ほどトポロジカル順で前にあります。

```cpp
auto groups = strongly_connected_components(g);
std::vector<int> id(g.n);
for (int i = 0; i < (int)groups.size(); i++) {
    for (int v : groups[i]) id[v] = i;
}
```

最小全域木は `auto [cost, edges] = minimum_spanning_tree(g);` のように受け取れます。`edges` はコストの昇順 (同じなら辺の番号順) に並びます。グラフが連結かどうかは `edges.size() == g.n - 1` で判定できます。

## 関連

- 関節点・橋・二重辺連結成分分解は [lowlink](lowlink.hpp)
- 2-SAT は [2-SAT](two-sat.hpp)
