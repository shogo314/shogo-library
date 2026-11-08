---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graph/chinese-postman.hpp
    title: "\u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/graph/chinese-postman.test.cpp
    title: test/unittest/graph/chinese-postman.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/eulerian-trail-directed.test.cpp
    title: test/yosupo/graph/eulerian-trail-directed.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/graph/eulerian-trail-undirected.test.cpp
    title: test/yosupo/graph/eulerian-trail-undirected.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30AA\u30A4\u30E9\u30FC\u8DEF"
    links: []
  bundledCode: "#line 2 \"src/graph/eulerian-trail.hpp\"\n\n/**\n * @file eulerian-trail.hpp\n\
    \ * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF\n */\n\n#include <algorithm>\n#include\
    \ <cstdlib>\n#include <optional>\n#include <utility>\n#include <vector>\n\n#line\
    \ 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n * @brief \u30B0\u30E9\
    \u30D5\n */\n\n#include <cassert>\n#include <iostream>\n#line 12 \"src/graph/graph.hpp\"\
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
    \ long long() const { return dst; }\n    };\n\n   private:\n    long long n; \
    \                      //!< \u9802\u70B9\u6570\n    long long m;             \
    \          //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>> g;  //!< \u30B0\
    \u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\n   public:\n \
    \   /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\
    \u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n     * @brief\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\
    \n     */\n    explicit Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n  \
    \   * @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief \u8FBA\u6570 (\u7121\u5411\u8FBA\u306F 1 \u672C\
    \u3068\u6570\u3048\u308B)\n     */\n    long long edge_count() const { return\
    \ m; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\
    \n     * @param u \u59CB\u70B9\n     * @param v \u7D42\u70B9\n     * @param w\
    \ \u30B3\u30B9\u30C8 \u7701\u7565\u3057\u305F\u30891\n     */\n    void add_edge(long\
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
    \u6319\u3059\u308B\n     * @param v \u9802\u70B9\u756A\u53F7\n     * @return const\
    \ std::vector<Edge>& v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u30EA\u30B9\u30C8\n\
    \     */\n    const std::vector<Edge>& operator[](long long v) const {\n     \
    \   assert(0 <= v && v < n);\n        return g[v];\n    }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u30EA\u30B9\u30C8\n     * @return std::vector<Edge> \u8FBA\u306E\
    \u30EA\u30B9\u30C8(id\u306E\u6607\u9806)\n     *\n     * \u7121\u5411\u8FBA\u306F\
    \u4EE3\u8868\u3057\u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\
    \u305D\u306E src \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\
    \n     * \u6709\u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\
    \u304D\u306E\u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res(m);\n        for (long long i\
    \ = 0; i < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id]\
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n\n/**\n * @brief\
    \ \u7D4C\u8DEF (\u8DEF\u30FB\u9589\u8DEF)\u3002\u9577\u3055 cost\u3001\u305F\u3069\
    \u308B\u9802\u70B9\u306E\u5217 vertices\u3001\u305F\u3069\u308B\u8FBA\u306E\u5217\
    \ edges\n *\n * edges[k] \u306F vertices[k] \u304B\u3089 vertices[k + 1] \u3078\
    \u5411\u304B\u3046 (edges[k].src == vertices[k]\u3001edges[k].dst == vertices[k\
    \ + 1])\n * vertices \u306F edges \u3088\u308A 1 \u3064\u591A\u3044\u3002\u8FBA\
    \u304C\u306A\u304F\u3066\u3082\u59CB\u70B9 1 \u3064\u304C\u5165\u308B\u3002\u9589\
    \u8DEF\u306A\u3089 vertices.front() == vertices.back()\n * auto [cost, vertices,\
    \ edges] = *shortest_path(g, s, t); \u306E\u3088\u3046\u306B\u53D7\u3051\u53D6\
    \u308C\u308B\n */\ntemplate <typename Cost>\nstruct Path {\n    Cost cost;   \
    \                                   //!< \u9577\u3055 (\u8FBA\u306E\u30B3\u30B9\
    \u30C8\u306E\u548C)\n    std::vector<long long> vertices;                //!<\
    \ \u305F\u3069\u308B\u9802\u70B9 (\u59CB\u70B9\u304B\u3089\u9806\u306B)\n    std::vector<typename\
    \ Graph<Cost>::Edge> edges;  //!< \u305F\u3069\u308B\u8FBA (\u59CB\u70B9\u5074\
    \u304B\u3089\u9806\u306B)\n};\n\nnamespace internal_graph {\n/**\n * @brief \u59CB\
    \u70B9 s \u3068\u3001s \u304B\u3089\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u8FBA edges \u304B\u3089 Path \u3092\u4F5C\u308B\u3002cost \u306F\u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u548C\n */\ntemplate <typename Cost>\nPath<Cost> make_path(long\
    \ long s, std::vector<typename Graph<Cost>::Edge> edges) {\n    Path<Cost> res{Cost{},\
    \ {s}, std::move(edges)};\n    for (const auto& e : res.edges) {\n        assert(e.src\
    \ == res.vertices.back());\n        res.cost += e.cost;\n        res.vertices.push_back(e.dst);\n\
    \    }\n    return res;\n}\n}  // namespace internal_graph\n#line 15 \"src/graph/eulerian-trail.hpp\"\
    \n\nnamespace internal_eulerian_trail {\n\n/**\n * @brief s \u304B\u3089 Hierholzer\
    \ \u6CD5\u3067\u305F\u3069\u308A\u3001\u4F7F\u3063\u305F\u8FBA\u3092\u305F\u3069\
    \u308B\u9806\u306B\u4E26\u3079\u308B\n *\n * \u8FBA\u3092\u756A\u53F7\u3067\u4F7F\
    \u7528\u6E08\u307F\u306B\u3059\u308B\u306E\u3067\u3001\u7121\u5411\u8FBA (\u540C\
    \u3058\u756A\u53F7\u306E\u8FBA\u304C 2 \u672C\u3042\u308B) \u3082 1 \u56DE\u3057\
    \u304B\u901A\u3089\u306A\u3044\n * \u3059\u3079\u3066\u306E\u8FBA\u3092\u4F7F\u3048\
    \u306A\u3051\u308C\u3070 (\u9023\u7D50\u3067\u306A\u3051\u308C\u3070) std::nullopt\
    \ \u3092\u8FD4\u3059\n */\ntemplate <typename Cost>\nstd::optional<std::vector<typename\
    \ Graph<Cost>::Edge>> hierholzer(const Graph<Cost>& graph, long long s) {\n  \
    \  using Edge = typename Graph<Cost>::Edge;\n    std::vector<int> iter(graph.size(),\
    \ 0);\n    std::vector<bool> used(graph.edge_count(), false);\n    std::vector<Edge>\
    \ res;\n    // (\u4ECA\u3044\u308B\u9802\u70B9, \u305D\u3053\u3078\u6765\u308B\
    \u306E\u306B\u4F7F\u3063\u305F\u8FBA)\u3002\u59CB\u70B9\u3067\u306F\u8FBA\u306E\
    \ src == -1\n    std::vector<std::pair<long long, Edge>> st = {{s, Edge()}};\n\
    \    while (!st.empty()) {\n        long long v = st.back().first;\n        int&\
    \ it = iter[v];\n        while (it < static_cast<int>(graph[v].size()) && used[graph[v][it].id])\
    \ it++;\n        if (it == static_cast<int>(graph[v].size())) {\n            if\
    \ (st.back().second.src != -1) res.push_back(st.back().second);\n            st.pop_back();\n\
    \        } else {\n            const Edge& e = graph[v][it++];\n            used[e.id]\
    \ = true;\n            st.push_back({e.dst, e});\n        }\n    }\n    if (static_cast<long\
    \ long>(res.size()) != graph.edge_count()) return std::nullopt;\n    std::reverse(res.begin(),\
    \ res.end());\n    return res;\n}\n\n// \u8FBA\u304C\u306A\u3044\u30B0\u30E9\u30D5\
    \u306E\u30AA\u30A4\u30E9\u30FC\u8DEF\u3002\u9802\u70B9 0 \u3060\u3051\u306E\u8DEF\
    \ (\u9802\u70B9\u3082\u306A\u3051\u308C\u3070\u7A7A)\ntemplate <typename Cost>\n\
    Path<Cost> empty_trail(const Graph<Cost>& graph) {\n    if (graph.size() == 0)\
    \ return {Cost{}, {}, {}};\n    return {Cost{}, {0}, {}};\n}\n\n}  // namespace\
    \ internal_eulerian_trail\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\
    \u30AA\u30A4\u30E9\u30FC\u8DEF (\u3059\u3079\u3066\u306E\u8FBA\u3092\u3061\u3087\
    \u3046\u3069 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF) \u3092 1 \u3064\u6C42\u3081\
    \u308B\n *\n * Hierholzer \u6CD5 O(n + m)\n * @return std::optional<Path<Cost>>\
    \ \u8DEF (\u9577\u3055\u306F\u3059\u3079\u3066\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u306E\u548C\u3001\u305F\u3069\u308B\u9802\u70B9\u3001\u305F\u3069\u308B\u8FBA\
    )\u3002\u30AA\u30A4\u30E9\u30FC\u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n\
    \ * \u8FBA\u304C\u306A\u3044\u3068\u304D\u306F\u3001\u9802\u70B9 0 \u3060\u3051\
    \u306E\u8DEF\u3092\u8FD4\u3059 (\u9802\u70B9\u3082\u306A\u3051\u308C\u3070\u9802\
    \u70B9\u306E\u5217\u3082\u7A7A)\u3002\u59CB\u70B9\u3068\u7D42\u70B9\u304C\u540C\
    \u3058\u306B\u306A\u308B\u306E\u306F\u3001\u9589\u8DEF\u3068\u3057\u3066\u56DE\
    \u308C\u308B\u3068\u304D\u3060\u3051\n */\ntemplate <typename Cost = long long>\n\
    std::optional<Path<Cost>> eulerian_trail_directed(const Graph<Cost>& graph) {\n\
    \    if (graph.edge_count() == 0) return internal_eulerian_trail::empty_trail(graph);\n\
    \    std::vector<long long> diff(graph.size(), 0);  // \u51FA\u6B21\u6570 - \u5165\
    \u6B21\u6570\n    for (long long v = 0; v < graph.size(); v++) {\n        for\
    \ (long long u : graph[v]) diff[v]++, diff[u]--;\n    }\n    // \u51FA\u6B21\u6570\
    \u304C 1 \u591A\u3044\u9802\u70B9\u304C\u3042\u308C\u3070\u305D\u3053\u304B\u3089\
    \u59CB\u3081\u308B\u3002\u306A\u3051\u308C\u3070\u8FBA\u3092\u6301\u3064\u9802\
    \u70B9\u304B\u3089\n    long long s = -1, plus = 0;\n    for (long long v = 0;\
    \ v < graph.size(); v++) {\n        if (std::abs(diff[v]) > 1) return std::nullopt;\n\
    \        if (diff[v] == 1) s = v, plus++;\n    }\n    if (plus > 1) return std::nullopt;\n\
    \    for (long long v = 0; s == -1; v++) {\n        if (!graph[v].empty()) s =\
    \ v;\n    }\n    auto trail = internal_eulerian_trail::hierholzer(graph, s);\n\
    \    if (!trail) return std::nullopt;\n    return internal_graph::make_path<Cost>(s,\
    \ std::move(*trail));\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\
    \u30AA\u30A4\u30E9\u30FC\u8DEF (\u3059\u3079\u3066\u306E\u8FBA\u3092\u3061\u3087\
    \u3046\u3069 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF) \u3092 1 \u3064\u6C42\u3081\
    \u308B\n *\n * Hierholzer \u6CD5 O(n + m)\n * @return std::optional<Path<Cost>>\
    \ \u8DEF (\u9577\u3055\u306F\u3059\u3079\u3066\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u306E\u548C\u3001\u305F\u3069\u308B\u9802\u70B9\u3001\u8FBA\u306F\u305F\u3069\
    \u308B\u5411\u304D\u306B\u3057\u305F\u3082\u306E)\u3002\u30AA\u30A4\u30E9\u30FC\
    \u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n * \u8FBA\u304C\u306A\u3044\
    \u3068\u304D\u306F\u3001\u9802\u70B9 0 \u3060\u3051\u306E\u8DEF\u3092\u8FD4\u3059\
    \ (\u9802\u70B9\u3082\u306A\u3051\u308C\u3070\u9802\u70B9\u306E\u5217\u3082\u7A7A\
    )\u3002\u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u591A\u91CD\u8FBA\u304C\u3042\u3063\
    \u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost = long long>\nstd::optional<Path<Cost>>\
    \ eulerian_trail_undirected(const Graph<Cost>& graph) {\n    if (graph.edge_count()\
    \ == 0) return internal_eulerian_trail::empty_trail(graph);\n    // \u6B21\u6570\
    \u304C\u5947\u6570\u306E\u9802\u70B9\u304C 2 \u500B\u306A\u3089\u305D\u306E\u4E00\
    \u65B9\u304B\u3089\u30010 \u500B\u306A\u3089\u8FBA\u3092\u6301\u3064\u9802\u70B9\
    \u304B\u3089\u59CB\u3081\u308B\n    long long s = -1, odd = 0;\n    for (long\
    \ long v = 0; v < graph.size(); v++) {\n        if (graph[v].size() % 2 == 1)\
    \ s = v, odd++;\n    }\n    if (odd > 2) return std::nullopt;\n    for (long long\
    \ v = 0; s == -1; v++) {\n        if (!graph[v].empty()) s = v;\n    }\n    auto\
    \ trail = internal_eulerian_trail::hierholzer(graph, s);\n    if (!trail) return\
    \ std::nullopt;\n    return internal_graph::make_path<Cost>(s, std::move(*trail));\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file eulerian-trail.hpp\n * @brief \u30AA\u30A4\u30E9\
    \u30FC\u8DEF\n */\n\n#include <algorithm>\n#include <cstdlib>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n#include \"graph.hpp\"\n\nnamespace internal_eulerian_trail\
    \ {\n\n/**\n * @brief s \u304B\u3089 Hierholzer \u6CD5\u3067\u305F\u3069\u308A\
    \u3001\u4F7F\u3063\u305F\u8FBA\u3092\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\
    \u308B\n *\n * \u8FBA\u3092\u756A\u53F7\u3067\u4F7F\u7528\u6E08\u307F\u306B\u3059\
    \u308B\u306E\u3067\u3001\u7121\u5411\u8FBA (\u540C\u3058\u756A\u53F7\u306E\u8FBA\
    \u304C 2 \u672C\u3042\u308B) \u3082 1 \u56DE\u3057\u304B\u901A\u3089\u306A\u3044\
    \n * \u3059\u3079\u3066\u306E\u8FBA\u3092\u4F7F\u3048\u306A\u3051\u308C\u3070\
    \ (\u9023\u7D50\u3067\u306A\u3051\u308C\u3070) std::nullopt \u3092\u8FD4\u3059\
    \n */\ntemplate <typename Cost>\nstd::optional<std::vector<typename Graph<Cost>::Edge>>\
    \ hierholzer(const Graph<Cost>& graph, long long s) {\n    using Edge = typename\
    \ Graph<Cost>::Edge;\n    std::vector<int> iter(graph.size(), 0);\n    std::vector<bool>\
    \ used(graph.edge_count(), false);\n    std::vector<Edge> res;\n    // (\u4ECA\
    \u3044\u308B\u9802\u70B9, \u305D\u3053\u3078\u6765\u308B\u306E\u306B\u4F7F\u3063\
    \u305F\u8FBA)\u3002\u59CB\u70B9\u3067\u306F\u8FBA\u306E src == -1\n    std::vector<std::pair<long\
    \ long, Edge>> st = {{s, Edge()}};\n    while (!st.empty()) {\n        long long\
    \ v = st.back().first;\n        int& it = iter[v];\n        while (it < static_cast<int>(graph[v].size())\
    \ && used[graph[v][it].id]) it++;\n        if (it == static_cast<int>(graph[v].size()))\
    \ {\n            if (st.back().second.src != -1) res.push_back(st.back().second);\n\
    \            st.pop_back();\n        } else {\n            const Edge& e = graph[v][it++];\n\
    \            used[e.id] = true;\n            st.push_back({e.dst, e});\n     \
    \   }\n    }\n    if (static_cast<long long>(res.size()) != graph.edge_count())\
    \ return std::nullopt;\n    std::reverse(res.begin(), res.end());\n    return\
    \ res;\n}\n\n// \u8FBA\u304C\u306A\u3044\u30B0\u30E9\u30D5\u306E\u30AA\u30A4\u30E9\
    \u30FC\u8DEF\u3002\u9802\u70B9 0 \u3060\u3051\u306E\u8DEF (\u9802\u70B9\u3082\u306A\
    \u3051\u308C\u3070\u7A7A)\ntemplate <typename Cost>\nPath<Cost> empty_trail(const\
    \ Graph<Cost>& graph) {\n    if (graph.size() == 0) return {Cost{}, {}, {}};\n\
    \    return {Cost{}, {0}, {}};\n}\n\n}  // namespace internal_eulerian_trail\n\
    \n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u30AA\u30A4\u30E9\u30FC\u8DEF\
    \ (\u3059\u3079\u3066\u306E\u8FBA\u3092\u3061\u3087\u3046\u3069 1 \u56DE\u305A\
    \u3064\u901A\u308B\u8DEF) \u3092 1 \u3064\u6C42\u3081\u308B\n *\n * Hierholzer\
    \ \u6CD5 O(n + m)\n * @return std::optional<Path<Cost>> \u8DEF (\u9577\u3055\u306F\
    \u3059\u3079\u3066\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u548C\u3001\u305F\
    \u3069\u308B\u9802\u70B9\u3001\u305F\u3069\u308B\u8FBA)\u3002\u30AA\u30A4\u30E9\
    \u30FC\u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n * \u8FBA\u304C\u306A\
    \u3044\u3068\u304D\u306F\u3001\u9802\u70B9 0 \u3060\u3051\u306E\u8DEF\u3092\u8FD4\
    \u3059 (\u9802\u70B9\u3082\u306A\u3051\u308C\u3070\u9802\u70B9\u306E\u5217\u3082\
    \u7A7A)\u3002\u59CB\u70B9\u3068\u7D42\u70B9\u304C\u540C\u3058\u306B\u306A\u308B\
    \u306E\u306F\u3001\u9589\u8DEF\u3068\u3057\u3066\u56DE\u308C\u308B\u3068\u304D\
    \u3060\u3051\n */\ntemplate <typename Cost = long long>\nstd::optional<Path<Cost>>\
    \ eulerian_trail_directed(const Graph<Cost>& graph) {\n    if (graph.edge_count()\
    \ == 0) return internal_eulerian_trail::empty_trail(graph);\n    std::vector<long\
    \ long> diff(graph.size(), 0);  // \u51FA\u6B21\u6570 - \u5165\u6B21\u6570\n \
    \   for (long long v = 0; v < graph.size(); v++) {\n        for (long long u :\
    \ graph[v]) diff[v]++, diff[u]--;\n    }\n    // \u51FA\u6B21\u6570\u304C 1 \u591A\
    \u3044\u9802\u70B9\u304C\u3042\u308C\u3070\u305D\u3053\u304B\u3089\u59CB\u3081\
    \u308B\u3002\u306A\u3051\u308C\u3070\u8FBA\u3092\u6301\u3064\u9802\u70B9\u304B\
    \u3089\n    long long s = -1, plus = 0;\n    for (long long v = 0; v < graph.size();\
    \ v++) {\n        if (std::abs(diff[v]) > 1) return std::nullopt;\n        if\
    \ (diff[v] == 1) s = v, plus++;\n    }\n    if (plus > 1) return std::nullopt;\n\
    \    for (long long v = 0; s == -1; v++) {\n        if (!graph[v].empty()) s =\
    \ v;\n    }\n    auto trail = internal_eulerian_trail::hierholzer(graph, s);\n\
    \    if (!trail) return std::nullopt;\n    return internal_graph::make_path<Cost>(s,\
    \ std::move(*trail));\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\
    \u30AA\u30A4\u30E9\u30FC\u8DEF (\u3059\u3079\u3066\u306E\u8FBA\u3092\u3061\u3087\
    \u3046\u3069 1 \u56DE\u305A\u3064\u901A\u308B\u8DEF) \u3092 1 \u3064\u6C42\u3081\
    \u308B\n *\n * Hierholzer \u6CD5 O(n + m)\n * @return std::optional<Path<Cost>>\
    \ \u8DEF (\u9577\u3055\u306F\u3059\u3079\u3066\u306E\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u306E\u548C\u3001\u305F\u3069\u308B\u9802\u70B9\u3001\u8FBA\u306F\u305F\u3069\
    \u308B\u5411\u304D\u306B\u3057\u305F\u3082\u306E)\u3002\u30AA\u30A4\u30E9\u30FC\
    \u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n * \u8FBA\u304C\u306A\u3044\
    \u3068\u304D\u306F\u3001\u9802\u70B9 0 \u3060\u3051\u306E\u8DEF\u3092\u8FD4\u3059\
    \ (\u9802\u70B9\u3082\u306A\u3051\u308C\u3070\u9802\u70B9\u306E\u5217\u3082\u7A7A\
    )\u3002\u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u591A\u91CD\u8FBA\u304C\u3042\u3063\
    \u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost = long long>\nstd::optional<Path<Cost>>\
    \ eulerian_trail_undirected(const Graph<Cost>& graph) {\n    if (graph.edge_count()\
    \ == 0) return internal_eulerian_trail::empty_trail(graph);\n    // \u6B21\u6570\
    \u304C\u5947\u6570\u306E\u9802\u70B9\u304C 2 \u500B\u306A\u3089\u305D\u306E\u4E00\
    \u65B9\u304B\u3089\u30010 \u500B\u306A\u3089\u8FBA\u3092\u6301\u3064\u9802\u70B9\
    \u304B\u3089\u59CB\u3081\u308B\n    long long s = -1, odd = 0;\n    for (long\
    \ long v = 0; v < graph.size(); v++) {\n        if (graph[v].size() % 2 == 1)\
    \ s = v, odd++;\n    }\n    if (odd > 2) return std::nullopt;\n    for (long long\
    \ v = 0; s == -1; v++) {\n        if (!graph[v].empty()) s = v;\n    }\n    auto\
    \ trail = internal_eulerian_trail::hierholzer(graph, s);\n    if (!trail) return\
    \ std::nullopt;\n    return internal_graph::make_path<Cost>(s, std::move(*trail));\n\
    }\n"
  dependsOn:
  - src/graph/graph.hpp
  isVerificationFile: false
  path: src/graph/eulerian-trail.hpp
  requiredBy:
  - src/graph/chinese-postman.hpp
  timestamp: '2026-11-09 05:14:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/graph/chinese-postman.test.cpp
  - test/yosupo/graph/eulerian-trail-undirected.test.cpp
  - test/yosupo/graph/eulerian-trail-directed.test.cpp
documentation_of: src/graph/eulerian-trail.hpp
layout: document
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF"
---

[グラフ](graph.hpp) `Graph<Cost>` のすべての辺をちょうど 1 回ずつ通る路 (オイラー路) を、Hierholzer 法で 1 つ求めます。

```cpp
Graph g(n);
g.read(m, 0, false, true);               // 有向辺を m 本読む
auto trail = eulerian_trail_directed(g); // なければ std::nullopt
if (trail) {
    trail->vertices;                     // 通る頂点の列 (m + 1 個)
    trail->edges;                        // 通る辺の列 (m 本)
}
```

返すのは経路 [`Path<Cost>`](graph.hpp) (`std::optional`) で、`cost` はすべての辺のコストの和です。辺はたどる順に並び、向きもたどる向きです (`edges[k]` は `vertices[k]` から `vertices[k + 1]` へ)。辺の番号は `id` で分かります。

辺が 1 本もないときは、頂点 0 だけの路を返します (オイラー路は自明に存在します。頂点もなければ頂点の列も空)。

結果は、変数に受けてから使います。`for (const auto& e : eulerian_trail_directed(g)->edges)` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。

始点と終点が同じ路 (オイラー閉路) が欲しいときは、返った路で `vertices.front() == vertices.back()` かを確かめます。オイラー閉路があれば、必ず閉路になった路が返ります。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `eulerian_trail_directed(g)` | 有向グラフのオイラー路 (`std::optional<Path<Cost>>`)。なければ `std::nullopt` | $O(n + m)$ |
| `eulerian_trail_undirected(g)` | 無向グラフのオイラー路 (`std::optional<Path<Cost>>`)。なければ `std::nullopt`。自己ループ・多重辺があってもよい | $O(n + m)$ |

## 関連

- 閉路を 1 つ求めるのは [グラフに関する関数](graph_util.hpp) の `find_cycle_directed`・`find_cycle_undirected`
- すべての辺を 1 回以上通る最短の閉路は [中国人郵便配達問題](chinese-postman.hpp)
