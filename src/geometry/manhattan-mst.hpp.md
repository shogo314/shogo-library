---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/geometry/manhattan.hpp
    title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 (\u6700\u8FD1\u70B9\u5BFE\
      \u30FB\u6700\u9060\u70B9\u5BFE\u3001\u5404\u70B9\u304B\u3089\u6700\u3082\u8FD1\
      \u3044\u70B9\u30FB\u6700\u3082\u9060\u3044\u70B9)"
  - icon: ':heavy_check_mark:'
    path: src/geometry/vector.hpp
    title: "\u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph_util.hpp
    title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/geometry/manhattan-mst.test.cpp
    title: test/unittest/geometry/manhattan-mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/geo/manhattanmst.test.cpp
    title: test/yosupo/geo/manhattanmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\
      \u5168\u57DF\u6728"
    links: []
  bundledCode: "#line 2 \"src/geometry/manhattan-mst.hpp\"\n\n/**\n * @file manhattan-mst.hpp\n\
    \ * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\u5168\
    \u57DF\u6728\n */\n\n#include <vector>\n\n#line 2 \"src/graph/graph_util.hpp\"\
    \n\n/**\n * @file graph_util.hpp\n * @brief \u30B0\u30E9\u30D5\u306B\u95A2\u3059\
    \u308B\u95A2\u6570\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <functional>\n#include <limits>\n#include <optional>\n#include <queue>\n#include\
    \ <stack>\n#include <utility>\n#line 17 \"src/graph/graph_util.hpp\"\n\n#line\
    \ 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n * @brief\
    \ UnionFind\n */\n\n#line 12 \"src/data_structures/unionfind.hpp\"\n\nnamespace\
    \ internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\u8868\u5143\
    \u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\u7D20\u306E\
    \u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20 a \u306E\u4EE3\
    \u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename F>\nstd::vector<std::vector<long\
    \ long>> groups(long long n, F leader) {\n    std::vector<long long> leader_buf(n),\
    \ group_size(n);\n    for (long long i = 0; i < n; i++) {\n        leader_buf[i]\
    \ = leader(i);\n        group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<long\
    \ long>> result(n);\n    for (long long i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n\
    \    }\n    for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
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
    \ a) { return leader(a); });\n    }\n};\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n\
    \ * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 9 \"src/graph/graph.hpp\"\
    \n#include <iostream>\n#line 11 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\
    \u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u578B \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\
    \u307F\u306E\u548C\u3084\u672A\u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\
    \u3075\u308C\u306B\u304F\u3044\u3088\u3046\u306B)\n */\ntemplate <typename Cost\
    \ = long long>\nclass Graph {\n   public:\n    /**\n     * @brief \u6709\u5411\
    \u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator long long()\u3092\u5B9A\
    \u7FA9\u3057\u3066\u3044\u308B\u306E\u3067\u3001\u6574\u6570\u578B\u306B\u30AD\
    \u30E3\u30B9\u30C8\u3059\u308B\u3068\u52DD\u624B\u306Bdst\u306B\u306A\u308B\n\
    \     * \u4F8B\u3048\u3070\u3001\n     * for (auto& e : g[v]) \u3092\u3059\u308B\
    \u3068\u3001v\u304B\u3089\u51FA\u308B\u8FBA\u304C\u5217\u6319\u3055\u308C\u308B\
    \u304C\u3001\n     * for (long long dst : g[v]) \u3068\u3059\u308B\u3068\u3001\
    v\u304B\u3089\u51FA\u308B\u8FBA\u306E\u884C\u304D\u5148\u304C\u5217\u6319\u3055\
    \u308C\u308B\n     */\n    struct Edge {\n        long long src = -1;  //!< \u59CB\
    \u70B9\n        long long dst = -1;  //!< \u7D42\u70B9\n        Cost cost = {};\
    \      //!< \u30B3\u30B9\u30C8\n        long long id = -1;   //!< \u8FBA\u306E\
    \u756A\u53F7(\u8FFD\u52A0\u3055\u308C\u305F\u9806\u3001\u7121\u5411\u8FBA\u306E\
    \u5834\u5408\u306Fid\u304C\u540C\u3058\u3067\u65B9\u5411\u304C\u9006\u306E\u3082\
    \u306E\u304C2\u3064\u5B58\u5728\u3059\u308B)\n        Edge() = default;\n    \
    \    Edge(long long src, long long dst, Cost cost = 1, long long id = -1) : src(src),\
    \ dst(dst), cost(cost), id(id) {}\n        operator long long() const { return\
    \ dst; }\n    };\n\n    long long n;                       //!< \u9802\u70B9\u6570\
    \n    long long m;                       //!< \u8FBA\u6570\n    std::vector<std::vector<Edge>>\
    \ g;  //!< \u30B0\u30E9\u30D5\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u8868\u73FE\n\
    \n    /**\n     * @brief \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\n     */\n    Graph() : n(0), m(0), g(0) {}\n    /**\n    \
    \ * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\
    \u6570\n     */\n    explicit Graph(long long n) : n(n), m(0), g(n) {}\n    /**\n\
    \     * @brief \u9802\u70B9\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief \u7121\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\
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
    \    return res;\n    }\n};\n#line 20 \"src/graph/graph_util.hpp\"\n\n/**\n *\
    \ @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u306A\u30890\u30681\u306B\u5F69\u8272\u3057\u305F\u7D50\u679C\
    \u3092\u3072\u3068\u3064\u8FD4\u3057\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\
    \u306A\u3044\u306A\u3089std::nullopt\u3092\u8FD4\u3059\u3002\n * \u9023\u7D50\u6210\
    \u5206\u306E\u3046\u3061\u3001\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306E\u6700\
    \u3082\u5C0F\u3055\u3044\u3082\u306E\u30920\u306B\u3059\u308B\u3002\n * @return\
    \ std::optional<std::vector<int>> \u5404\u9802\u70B9\u306E\u5F69\u8272\u7D50\u679C\
    \n */\ntemplate <typename Cost = long long>\nstd::optional<std::vector<int>> bipartite_coloring(const\
    \ Graph<Cost>& graph) {\n    std::vector<int> color(graph.n, -1);\n    for (long\
    \ long i = 0; i < graph.n; i++) {\n        if (color[i] != -1) continue;\n   \
    \     std::stack<long long> stk;\n        stk.push(i);\n        color[i] = 0;\n\
    \        while (!stk.empty()) {\n            long long u = stk.top();\n      \
    \      stk.pop();\n            for (long long v : graph[u]) {\n              \
    \  if (color[v] == -1) {\n                    color[v] = color[u] ^ 1;\n     \
    \               stk.push(v);\n                } else {\n                    if\
    \ (color[u] == color[v]) return std::nullopt;\n                }\n           \
    \ }\n        }\n    }\n    return color;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u306A\u3089true\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\
    \u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename\
    \ Cost = long long>\nbool is_bipartite(const Graph<Cost>& graph) {\n    return\
    \ bipartite_coloring(graph).has_value();\n}\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u6210\u5206\u5206\u89E3\
    \u3059\u308B\u3002\n * @return std::vector<std::vector<long long>> \u300C\u540C\
    \u3058\u9023\u7D50\u6210\u5206\u3068\u306A\u308B\u9802\u70B9\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\n\
    std::vector<std::vector<long long>> connected_components(const Graph<Cost>& graph)\
    \ {\n    std::vector<std::vector<long long>> groups;\n    std::vector<bool> visited(graph.n);\n\
    \    for (long long i = 0; i < graph.n; i++) {\n        if (visited[i]) continue;\n\
    \        std::stack<long long> stk;\n        stk.push(i);\n        visited[i]\
    \ = true;\n        groups.push_back({i});\n        while (!stk.empty()) {\n  \
    \          long long u = stk.top();\n            stk.pop();\n            for (long\
    \ long v : graph[u]) {\n                if (visited[v]) continue;\n          \
    \      visited[v] = true;\n                stk.push(v);\n                groups.back().push_back(v);\n\
    \            }\n        }\n    }\n    return groups;\n}\n\n/**\n * @brief \u7121\
    \u5411\u30B0\u30E9\u30D5\u306E\u88DC\u30B0\u30E9\u30D5 (\u8FBA\u306E\u306A\u3044\
    \ 2 \u9802\u70B9\u306E\u9593\u306B\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5\
    ) \u3092\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B O(n + m)\n * \u307E\u3060\
    \u3069\u306E\u6210\u5206\u306B\u3082\u5165\u3063\u3066\u3044\u306A\u3044\u9802\
    \u70B9\u306E\u5217\u3092\u6301\u3061\u3001\u53D6\u308A\u51FA\u3057\u305F\u9802\
    \u70B9\u3068\u96A3\u308A\u5408\u308F\u306A\u3044\u3082\u306E\u3092\u540C\u3058\
    \u6210\u5206\u306B\u79FB\u3059\n */\ntemplate <typename Cost = long long>\nstd::vector<std::vector<long\
    \ long>> complement_connected_components(const Graph<Cost>& graph) {\n    const\
    \ long long n = graph.n;\n    std::vector<long long> rest(n);\n    for (long long\
    \ i = 0; i < n; i++) rest[i] = i;\n    std::vector<bool> adj(n, false);\n    std::vector<std::vector<long\
    \ long>> groups;\n    while (!rest.empty()) {\n        groups.push_back({rest.back()});\n\
    \        rest.pop_back();\n        // groups.back() \u306E i \u756A\u76EE\u306E\
    \u9802\u70B9\u3092\u53D6\u308A\u51FA\u3057\u3001rest \u306E\u3046\u3061\u96A3\u308A\
    \u5408\u308F\u306A\u3044\u3082\u306E\u3092\u6210\u5206\u306B\u79FB\u3059\n   \
    \     for (long long i = 0; i < static_cast<long long>(groups.back().size());\
    \ i++) {\n            const long long u = groups.back()[i];\n            for (long\
    \ long v : graph[u]) adj[v] = true;\n            std::vector<long long> keep;\n\
    \            for (long long v : rest) {\n                if (adj[v]) {\n     \
    \               keep.push_back(v);\n                } else {\n               \
    \     groups.back().push_back(v);\n                }\n            }\n        \
    \    rest.swap(keep);\n            for (long long v : graph[u]) adj[v] = false;\n\
    \        }\n    }\n    return groups;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u30B0\u30E9\u30D5\u304B\u3069\
    \u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u9023\u7D50\
    \u30B0\u30E9\u30D5\u306A\u3089true\u3001\u9023\u7D50\u30B0\u30E9\u30D5\u3067\u306A\
    \u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename Cost\
    \ = long long>\nbool is_connected(const Graph<Cost>& graph) {\n    return connected_components(graph).size()\
    \ == 1;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\
    \u3001\u6728\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return\
    \ bool \u6728\u306A\u3089true\u3001\u6728\u3067\u306A\u3044\u306A\u3089false\u3092\
    \u8FD4\u3059\u3002\n */\ntemplate <typename Cost = long long>\nbool is_tree(const\
    \ Graph<Cost>& graph) {\n    return graph.m == graph.n - 1 && is_connected(graph);\n\
    }\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u3059\u308B\n * @return std::optional<std::vector<long\
    \ long>> \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u306B\u4E26\u3079\u305F\u9802\
    \u70B9\u306E\u30EA\u30B9\u30C8\u3002DAG \u3067\u306A\u3051\u308C\u3070 std::nullopt\n\
    \ */\ntemplate <typename Cost = long long>\nstd::optional<std::vector<long long>>\
    \ topological_sort(const Graph<Cost>& graph) {\n    std::vector<int> indeg(graph.n);\n\
    \    std::vector<long long> sorted;\n    std::queue<long long> q;\n    for (long\
    \ long i = 0; i < graph.n; i++) {\n        for (long long dst : graph[i]) indeg[dst]++;\n\
    \    }\n    for (long long i = 0; i < graph.n; i++) {\n        if (!indeg[i])\
    \ q.push(i);\n    }\n    while (!q.empty()) {\n        long long cur = q.front();\n\
    \        q.pop();\n        for (long long dst : graph[cur]) {\n            if\
    \ (!--indeg[dst]) q.push(dst);\n        }\n        sorted.push_back(cur);\n  \
    \  }\n    if (static_cast<long long>(sorted.size()) < graph.n) return std::nullopt;\n\
    \    return sorted;\n}\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306B\u3064\
    \u3044\u3066\u3001\u30B5\u30A4\u30AF\u30EB\u3092\u3082\u3064\u304B\u3069\u3046\
    \u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * \u7121\u5411\u30B0\u30E9\u30D5\u306B\
    \u306F\u4F7F\u3048\u306A\u3044 (\u8FBA\u304C 1 \u672C\u3067\u3082\u3042\u308C\u3070\
    \ true \u306B\u306A\u308B)\u3002\u7121\u5411\u30B0\u30E9\u30D5\u306F has_cycle_undirected\n\
    \ * @return bool \u30B5\u30A4\u30AF\u30EB\u3092\u3082\u3064\u306A\u3089true\u3001\
    \u975E\u5DE1\u56DE\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename\
    \ Cost = long long>\nbool has_cycle_directed(const Graph<Cost>& graph) {\n   \
    \ return !topological_sort(graph).has_value();\n}\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u9589\u8DEF\u3092\u3082\u3064\
    \u304B (\u68EE\u3067\u306A\u3044\u304B) \u3092\u5224\u5B9A\u3059\u308B\n *\n *\
    \ \u8FBA\u306E\u6570\u304C n - (\u9023\u7D50\u6210\u5206\u306E\u6570) \u3088\u308A\
    \u591A\u3044\u304B\u3067\u5224\u5B9A\u3059\u308B\u3002\u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u3068\u591A\u91CD\u8FBA\u3082\u9589\u8DEF\u3068\u307F\u306A\u3059\u3002\
    O(n + m)\n */\ntemplate <typename Cost = long long>\nbool has_cycle_undirected(const\
    \ Graph<Cost>& graph) {\n    return graph.m > graph.n - static_cast<long long>(connected_components(graph).size());\n\
    }\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\
    \u6C42\u3081\u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\
    \u884C\u3046\u3002O(n + m)\n * @return std::optional<std::vector<Edge>> \u9589\
    \u8DEF\u306E\u8FBA\u3092\u3001\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u3082\u306E (e[k].dst == e[k + 1].src\u3001\u672B\u5C3E\u306E dst \u306F\u5148\
    \u982D\u306E src)\u3002\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n\
    \ * \u81EA\u5DF1\u30EB\u30FC\u30D7\u306F\u9577\u3055 1 \u306E\u9589\u8DEF\u306B\
    \u306A\u308B\u3002\u9802\u70B9\u306E\u5217\u306F\u5404\u8FBA\u306E src \u3067\u5F97\
    \u3089\u308C\u308B\n */\ntemplate <typename Cost = long long>\nstd::optional<std::vector<typename\
    \ Graph<Cost>::Edge>> find_cycle_directed(const Graph<Cost>& graph) {\n    using\
    \ Edge = typename Graph<Cost>::Edge;\n    // state: 0 \u306F\u672A\u8A2A\u554F\
    \u30011 \u306F DFS \u306E\u30B9\u30BF\u30C3\u30AF\u4E0A\u30012 \u306F\u63A2\u7D22\
    \u6E08\u307F\n    std::vector<int> state(graph.n, 0), iter(graph.n, 0);\n    std::vector<Edge>\
    \ in(graph.n);  // DFS \u6728\u3067 v \u306B\u5165\u308B\u8FBA\n    for (long\
    \ long root = 0; root < graph.n; root++) {\n        if (state[root]) continue;\n\
    \        std::vector<long long> st = {root};\n        state[root] = 1;\n     \
    \   while (!st.empty()) {\n            long long v = st.back();\n            if\
    \ (iter[v] == static_cast<int>(graph[v].size())) {\n                state[v] =\
    \ 2;\n                st.pop_back();\n                continue;\n            }\n\
    \            const Edge& e = graph[v][iter[v]++];\n            long long u = e.dst;\n\
    \            if (state[u] == 0) {\n                state[u] = 1;\n           \
    \     in[u] = e;\n                st.push_back(u);\n            } else if (state[u]\
    \ == 1) {\n                // u \u306F\u30B9\u30BF\u30C3\u30AF\u4E0A\u306B\u3042\
    \u308B\u306E\u3067\u3001u \u304B\u3089 v \u3078\u306E\u6728\u306E\u8FBA\u3068\
    \ e \u3067\u9589\u8DEF\u306B\u306A\u308B\n                std::vector<Edge> res\
    \ = {e};\n                for (long long w = v; w != u; w = in[w].src) res.push_back(in[w]);\n\
    \                std::reverse(res.begin(), res.end());\n                return\
    \ res;\n            }\n        }\n    }\n    return std::nullopt;\n}\n\n/**\n\
    \ * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u3092 1 \u3064\u6C42\
    \u3081\u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\
    \u3046\u3002O(n + m)\n * @return std::optional<std::vector<Edge>> \u9589\u8DEF\
    \u306E\u8FBA\u3092\u3001\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\u3082\
    \u306E (e[k].dst == e[k + 1].src\u3001\u672B\u5C3E\u306E dst \u306F\u5148\u982D\
    \u306E src)\u3002\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070 std::nullopt\n * \u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u306F\u9577\u3055 1\u3001\u591A\u91CD\u8FBA\u306F\u9577\
    \u3055 2 \u306E\u9589\u8DEF\u306B\u306A\u308B (\u540C\u3058\u8FBA\u3092\u623B\u308B\
    \u3053\u3068\u306F\u306A\u3044)\u3002\u9802\u70B9\u306E\u5217\u306F\u5404\u8FBA\
    \u306E src \u3067\u5F97\u3089\u308C\u308B\n */\ntemplate <typename Cost = long\
    \ long>\nstd::optional<std::vector<typename Graph<Cost>::Edge>> find_cycle_undirected(const\
    \ Graph<Cost>& graph) {\n    using Edge = typename Graph<Cost>::Edge;\n    std::vector<int>\
    \ state(graph.n, 0), iter(graph.n, 0);\n    std::vector<Edge> in(graph.n);\n \
    \   for (long long root = 0; root < graph.n; root++) {\n        if (state[root])\
    \ continue;\n        std::vector<long long> st = {root};\n        state[root]\
    \ = 1;\n        while (!st.empty()) {\n            long long v = st.back();\n\
    \            if (iter[v] == static_cast<int>(graph[v].size())) {\n           \
    \     state[v] = 2;\n                st.pop_back();\n                continue;\n\
    \            }\n            const Edge& e = graph[v][iter[v]++];\n           \
    \ // \u89AA\u3078\u623B\u308B\u8FBA\u306F\u3001\u9802\u70B9\u3067\u306F\u306A\u304F\
    \u8FBA\u306E\u756A\u53F7\u3067\u533A\u5225\u3059\u308B (\u591A\u91CD\u8FBA\u3092\
    \u9589\u8DEF\u3068\u3057\u3066\u898B\u3064\u3051\u308B\u305F\u3081)\n        \
    \    if (e.id == in[v].id) continue;  // \u6839\u3067\u306F in[v].id == -1\n \
    \           long long u = e.dst;\n            if (state[u] == 0) {\n         \
    \       state[u] = 1;\n                in[u] = e;\n                st.push_back(u);\n\
    \            } else if (state[u] == 1) {\n                // u \u306F v \u306E\
    \u7956\u5148 (\u304B v \u81EA\u8EAB) \u306A\u306E\u3067\u3001u \u304B\u3089 v\
    \ \u3078\u306E\u6728\u306E\u8FBA\u3068 e \u3067\u9589\u8DEF\u306B\u306A\u308B\n\
    \                std::vector<Edge> res = {e};\n                for (long long\
    \ w = v; w != u; w = in[w].src) res.push_back(in[w]);\n                std::reverse(res.begin(),\
    \ res.end());\n                return res;\n            }\n            // state[u]\
    \ == 2 \u306B\u306F\u306A\u3089\u306A\u3044 (\u306A\u308B\u306A\u3089\u3001u \u306E\
    \u5074\u3067\u3053\u306E\u8FBA\u306B\u3088\u308A\u9589\u8DEF\u304C\u898B\u3064\
    \u304B\u3063\u3066\u3044\u308B)\n        }\n    }\n    return std::nullopt;\n\
    }\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\u3059\u308B\n *\n * Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\u3092\u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n +\
    \ m)\n *\n * @return std::vector<std::vector<long long>> \u5F37\u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3002\n * \u6210\u5206\
    \u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u306B\u4E26\u3076 (\u6210\u5206\
    \ A \u304B\u3089\u6210\u5206 B \u3078\u8FBA\u304C\u3042\u308C\u3070 A \u304C B\
    \ \u3088\u308A\u524D)\n */\ntemplate <typename Cost = long long>\nstd::vector<std::vector<long\
    \ long>> strongly_connected_components(const Graph<Cost>& graph) {\n    const\
    \ long long n = graph.n;\n    std::vector<int> ord(n, -1), low(n), comp(n, -1),\
    \ iter(n, 0);\n    std::vector<long long> visiting;  // \u6210\u5206\u304C\u307E\
    \u3060\u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u8A2A\u554F\u6E08\u307F\u306E\
    \u9802\u70B9\n    std::vector<long long> call;      // DFS \u306E\u547C\u3073\u51FA\
    \u3057\u30B9\u30BF\u30C3\u30AF\n    int now = 0, k = 0;\n    for (long long s\
    \ = 0; s < n; s++) {\n        if (ord[s] != -1) continue;\n        ord[s] = low[s]\
    \ = now++;\n        visiting.push_back(s);\n        call.push_back(s);\n     \
    \   while (!call.empty()) {\n            long long v = call.back();\n        \
    \    if (iter[v] < static_cast<int>(graph[v].size())) {\n                long\
    \ long to = graph[v][iter[v]++].dst;\n                if (ord[to] == -1) {\n \
    \                   ord[to] = low[to] = now++;\n                    visiting.push_back(to);\n\
    \                    call.push_back(to);\n                } else if (comp[to]\
    \ == -1) {\n                    low[v] = std::min(low[v], ord[to]);\n        \
    \        }\n                continue;\n            }\n            call.pop_back();\n\
    \            if (!call.empty()) low[call.back()] = std::min(low[call.back()],\
    \ low[v]);\n            if (low[v] == ord[v]) {\n                while (true)\
    \ {\n                    long long u = visiting.back();\n                    visiting.pop_back();\n\
    \                    comp[u] = k;\n                    if (u == v) break;\n  \
    \              }\n                k++;\n            }\n        }\n    }\n    //\
    \ Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306F\u6210\u5206\u3092\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u306E\u9006\u306B\u898B\u3064\u3051\u308B\
    \u306E\u3067\u3001\u9006\u9806\u306B\u4E26\u3079\u308B\n    std::vector<std::vector<long\
    \ long>> groups(k);\n    for (long long v = 0; v < n; v++) groups[k - 1 - comp[v]].push_back(v);\n\
    \    return groups;\n}\n\n/**\n * @brief \u6700\u5C0F\u5168\u57DF\u6728\u306E\u7D50\
    \u679C\n */\ntemplate <typename Cost>\nstruct MinimumSpanningTree {\n    Cost\
    \ cost;                                      //!< \u4F7F\u3063\u305F\u8FBA\u306E\
    \u30B3\u30B9\u30C8\u306E\u7DCF\u548C\n    std::vector<typename Graph<Cost>::Edge>\
    \ edges;  //!< \u4F7F\u3063\u305F\u8FBA (\u30B3\u30B9\u30C8\u306E\u6607\u9806\u3001\
    \u540C\u3058\u30B3\u30B9\u30C8\u306A\u3089\u8FBA\u306E\u756A\u53F7\u9806)\n};\n\
    \n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728\
    \ (Kruskal \u6CD5) O(m log m)\n *\n * \u9023\u7D50\u3067\u306A\u3051\u308C\u3070\
    \u3001\u5404\u9023\u7D50\u6210\u5206\u306E\u6700\u5C0F\u5168\u57DF\u6728\u3092\
    \u5408\u308F\u305B\u305F\u3082\u306E (\u6700\u5C0F\u5168\u57DF\u68EE) \u3092\u8FD4\
    \u3059\n * \u9023\u7D50\u304B\u3069\u3046\u304B\u306F edges.size() == n - 1 \u3067\
    \u5224\u5B9A\u3067\u304D\u308B\n */\ntemplate <typename Cost = long long>\nMinimumSpanningTree<Cost>\
    \ minimum_spanning_tree(const Graph<Cost>& graph) {\n    auto es = graph.edges();\n\
    \    std::stable_sort(es.begin(), es.end(), [](const auto& a, const auto& b) {\
    \ return a.cost < b.cost; });\n    UnionFind uf(graph.n);\n    MinimumSpanningTree<Cost>\
    \ res{Cost{}, {}};\n    for (const auto& e : es) {\n        if (uf.merge(e.src,\
    \ e.dst)) {\n            res.cost += e.cost;\n            res.edges.push_back(e);\n\
    \        }\n    }\n    return res;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306E\u5F69\u8272\u6570 (\u96A3\u308A\u5408\u3046\u9802\u70B9\u304C\u540C\
    \u3058\u8272\u306B\u306A\u3089\u306A\u3044\u3088\u3046\u306B\u5857\u308B\u3068\
    \u304D\u306E\u8272\u306E\u6700\u5C0F\u6570\u3002\u9802\u70B9\u6570 20 \u7A0B\u5EA6\
    \u307E\u3067) O(3^n)\n * \u72EC\u7ACB\u96C6\u5408\u306E\u8868\u3092 O(2^n) \u3067\
    \u4F5C\u308A\u3001dp[S] = min (dp[S \\ T] + 1) \u3092\u3001T \u3092\u300CS \u306E\
    \u6700\u5C0F\u306E\u9802\u70B9 v \u3092\u542B\u307F\u3001v \u3068\u96A3\u308A\u5408\
    \u308F\u306A\u3044 S \u306E\u9802\u70B9\u304B\u3089\u306A\u308B\u72EC\u7ACB\u96C6\
    \u5408\u300D\u306B\u9650\u3063\u3066\u6C42\u3081\u308B\n * \u679D\u5208\u308A\u3067\
    \u901F\u304F\u306A\u308B\u306E\u306F\u5B9A\u6570\u500D\u3060\u3051\u3067\u3001\
    2 \u9802\u70B9\u305A\u3064\u8FBA\u3067\u7D50\u3093\u3060\u30B0\u30E9\u30D5\u306A\
    \u3069\u3067\u306F\u5185\u5074\u306E\u30EB\u30FC\u30D7\u304C 3^n / 2 \u56DE\u8FD1\
    \u304F\u307E\u308F\u308B\n * \u9802\u70B9\u304C\u306A\u3051\u308C\u3070 0\u3002\
    \u81EA\u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u308C\u3070\u5857\u308C\u306A\u3044\
    \u306E\u3067 -1\n */\ntemplate <typename Cost = long long>\nlong long chromatic_number(const\
    \ Graph<Cost>& graph) {\n    const int n = graph.n;\n    if (n == 0) return 0;\n\
    \    assert(n <= 30);\n    std::vector<int> adj(n, 0);\n    for (int v = 0; v\
    \ < n; v++) {\n        for (const auto& e : graph[v]) {\n            if (e.dst\
    \ == v) return -1;\n            adj[v] |= 1 << e.dst;\n        }\n    }\n    //\
    \ indep[S]: S \u304C\u72EC\u7ACB\u96C6\u5408\u304B (\u6700\u5C0F\u306E\u9802\u70B9\
    \u3092\u9664\u3044\u305F\u96C6\u5408\u304C\u72EC\u7ACB\u3067\u3001\u6700\u5C0F\
    \u306E\u9802\u70B9\u304C\u305D\u308C\u3068\u96A3\u308A\u5408\u308F\u306A\u3044\
    )\n    std::vector<bool> indep(1 << n, false);\n    indep[0] = true;\n    for\
    \ (int S = 1; S < (1 << n); S++) {\n        const int v = __builtin_ctz(S), rest\
    \ = S & (S - 1);\n        indep[S] = indep[rest] && !(adj[v] & rest);\n    }\n\
    \    std::vector<int> dp(1 << n, n + 1);\n    dp[0] = 0;\n    for (int S = 1;\
    \ S < (1 << n); S++) {\n        if (indep[S]) {\n            dp[S] = 1;\n    \
    \        continue;\n        }\n        const int v = __builtin_ctz(S), low = 1\
    \ << v, cand = S & ~adj[v] & ~low;\n        for (int U = cand;; U = (U - 1) &\
    \ cand) {\n            const int T = U | low;\n            if (indep[T] && dp[S\
    \ ^ T] + 1 < dp[S]) dp[S] = dp[S ^ T] + 1;\n            if (U == 0) break;\n \
    \       }\n    }\n    return dp[(1 << n) - 1];\n}\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306E\u6700\u5927\u72EC\u7ACB\u96C6\u5408 (\u3069\u306E 2 \u9802\
    \u70B9\u3082\u96A3\u308A\u5408\u308F\u306A\u3044\u9802\u70B9\u96C6\u5408\u3067\
    \u3001\u8981\u7D20\u6570\u304C\u6700\u5927\u306E\u3082\u306E) \u3092 1 \u3064\u6C42\
    \u3081\u3001\u9802\u70B9\u3092\u6607\u9806\u306B\u8FD4\u3059 (\u9802\u70B9\u6570\
    \ 64 \u4EE5\u4E0B)\n * \u6B21\u6570 1 \u4EE5\u4E0B\u306E\u9802\u70B9\u306F\u9078\
    \u3093\u3067\u3088\u3044\u306E\u3067\u9078\u3073\u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070\u6B21\u6570\u6700\u5927\u306E\u9802\u70B9\u3092\u9078\u3076\
    \u304B\u9078\u3070\u306A\u3044\u304B\u3067\u5206\u5C90\u3059\u308B\u3002O(1.39^n)\
    \ \u7A0B\u5EA6 (n = 40 \u3067\u5341\u5206\u901F\u3044)\n * @note \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u306E\u3042\u308B\u9802\u70B9\u306F\u9078\u3070\u306A\u3044\n */\n\
    template <typename Cost = long long>\nstd::vector<long long> maximum_independent_set(const\
    \ Graph<Cost>& graph) {\n    const int n = graph.n;\n    assert(n <= 64);\n  \
    \  using u64 = unsigned long long;\n    std::vector<u64> adj(n, 0);\n    u64 all\
    \ = n == 64 ? ~0ULL : (1ULL << n) - 1;\n    for (int u = 0; u < n; u++) {\n  \
    \      for (const auto& e : graph[u]) {\n            if (e.dst == u) {\n     \
    \           all &= ~(1ULL << u);\n            } else {\n                adj[u]\
    \ |= 1ULL << e.dst;\n            }\n        }\n    }\n    u64 best = 0;\n    //\
    \ rest: \u307E\u3060\u6C7A\u3081\u3066\u3044\u306A\u3044\u9802\u70B9\u3001cur:\
    \ \u9078\u3093\u3060\u9802\u70B9\n    auto rec = [&](auto self, u64 rest, u64\
    \ cur) -> void {\n        if (__builtin_popcountll(cur) + __builtin_popcountll(rest)\
    \ <= __builtin_popcountll(best)) return;\n        if (rest == 0) {\n         \
    \   best = cur;\n            return;\n        }\n        int v = -1, deg = -1;\n\
    \        for (u64 r = rest; r; r &= r - 1) {\n            const int u = __builtin_ctzll(r),\
    \ d = __builtin_popcountll(adj[u] & rest);\n            if (d <= 1) {\n      \
    \          // \u6B21\u6570 1 \u4EE5\u4E0B\u306A\u3089\u9078\u3093\u3067\u3082\u640D\
    \u3092\u3057\u306A\u3044\n                self(self, rest & ~adj[u] & ~(1ULL <<\
    \ u), cur | 1ULL << u);\n                return;\n            }\n            if\
    \ (d > deg) v = u, deg = d;\n        }\n        self(self, rest & ~adj[v] & ~(1ULL\
    \ << v), cur | 1ULL << v);\n        self(self, rest & ~(1ULL << v), cur);\n  \
    \  };\n    rec(rec, all, 0);\n    std::vector<long long> res;\n    for (int v\
    \ = 0; v < n; v++)\n        if (best >> v & 1) res.push_back(v);\n    return res;\n\
    }\n\n/**\n * @brief \u5358\u7D14\u306A\u7121\u5411\u30B0\u30E9\u30D5\u306E\u4E09\
    \u89D2\u5F62 (\u4E92\u3044\u306B\u96A3\u308A\u5408\u3046 3 \u9802\u70B9) \u3092\
    \u3059\u3079\u3066\u5217\u6319\u3057\u3001\u305D\u308C\u305E\u308C\u306B\u3064\
    \u3044\u3066 f(a, b, c) (a < b < c) \u3092\u547C\u3076 O(m sqrt(m))\n * \u8FBA\
    \u3092\u6B21\u6570\u306E\u5C0F\u3055\u3044\u65B9\u304B\u3089\u5927\u304D\u3044\
    \u65B9\u3078\u5411\u3051\u308B\u3068\u3001\u5404\u9802\u70B9\u304B\u3089\u51FA\
    \u308B\u8FBA\u306F O(sqrt(m)) \u672C\u306B\u306A\u308B\n * @note \u81EA\u5DF1\u30EB\
    \u30FC\u30D7\u3068\u591A\u91CD\u8FBA\u306F\u306A\u3044\u3053\u3068\n */\ntemplate\
    \ <typename Cost, typename F>\nvoid enumerate_triangles(const Graph<Cost>& graph,\
    \ F f) {\n    const long long n = graph.n;\n    auto less = [&](long long u, long\
    \ long v) {\n        return graph[u].size() != graph[v].size() ? graph[u].size()\
    \ < graph[v].size() : u < v;\n    };\n    std::vector<std::vector<long long>>\
    \ out(n);\n    for (long long u = 0; u < n; u++) {\n        for (const auto& e\
    \ : graph[u])\n            if (less(u, e.dst)) out[u].push_back(e.dst);\n    }\n\
    \    std::vector<bool> mark(n, false);\n    for (long long u = 0; u < n; u++)\
    \ {\n        for (long long v : out[u]) mark[v] = true;\n        for (long long\
    \ v : out[u]) {\n            for (long long w : out[v]) {\n                if\
    \ (!mark[w]) continue;\n                long long t[3] = {u, v, w};\n        \
    \        std::sort(t, t + 3);\n                f(t[0], t[1], t[2]);\n        \
    \    }\n        }\n        for (long long v : out[u]) mark[v] = false;\n    }\n\
    }\n\nnamespace internal_graph_util {\n/**\n * @brief minimum_steiner_tree \u306E\
    \ DP\n * dp[k][i]: \u9802\u70B9 k \u3092\u542B\u307F\u3001X \u306E\u90E8\u5206\
    \u96C6\u5408 i \u3092\u3059\u3079\u3066\u542B\u3080\u90E8\u5206\u6728\u306E\u91CD\
    \u307F\u306E\u6700\u5C0F\u5024\n * from[k][i]: \u5FA9\u5143\u7528\u3002type \u304C\
    \ -1 \u306A\u3089 X \u306E\u9802\u70B9\u305D\u306E\u3082\u306E\u30010 \u306A\u3089\
    \ i \u3092 x \u3068 i ^ x \u306B\u5206\u3051\u305F\u30011 \u306A\u3089\u9802\u70B9\
    \ x \u304B\u3089\u8FBA id \u3092\u901A\u3063\u3066\u6765\u305F\n */\nstruct SteinerFrom\
    \ {\n    int type = -1;\n    long long x = -1, id = -1;\n};\ntemplate <typename\
    \ Cost>\nstruct SteinerDP {\n    std::vector<std::vector<Cost>> dp;\n    std::vector<std::vector<SteinerFrom>>\
    \ from;\n};\ntemplate <typename Cost, typename T>\nSteinerDP<Cost> steiner_dp(const\
    \ Graph<Cost>& graph, const std::vector<T>& X, Cost inf, bool restore) {\n   \
    \ for (const auto& x : X) assert(0 <= x && x < graph.n);\n    const int full =\
    \ 1 << X.size();\n    SteinerDP<Cost> res;\n    auto& dp = res.dp;\n    dp.assign(graph.n,\
    \ std::vector<Cost>(full, inf));\n    if (restore) res.from.assign(graph.n, std::vector<SteinerFrom>(full));\n\
    \    for (int p = 0; p < static_cast<int>(X.size()); p++) dp[X[p]][1 << p] = {};\n\
    \    for (int i = 0; i < full; i++) {\n        for (int j = i; j > 0; j = (j -\
    \ 1) & i) {\n            for (long long k = 0; k < graph.n; k++) {\n         \
    \       if (dp[k][j] != inf && dp[k][i ^ j] != inf) {\n                    if\
    \ (dp[k][i] == inf || dp[k][i] > dp[k][j] + dp[k][i ^ j]) {\n                \
    \        dp[k][i] = dp[k][j] + dp[k][i ^ j];\n                        if (restore)\
    \ res.from[k][i] = {0, j, -1};\n                    }\n                }\n   \
    \         }\n        }\n        std::priority_queue<std::pair<Cost, long long>,\
    \ std::vector<std::pair<Cost, long long>>, std::greater<std::pair<Cost, long long>>>\
    \ que;\n        for (long long k = 0; k < graph.n; k++)\n            if (dp[k][i]\
    \ != inf) que.emplace(dp[k][i], k);\n        while (que.size()) {\n          \
    \  auto [d, u] = que.top();\n            que.pop();\n            if (d > dp[u][i])\
    \ continue;\n            for (auto e : graph[u]) {\n                if (dp[e.dst][i]\
    \ == inf || dp[e.dst][i] > d + e.cost) {\n                    dp[e.dst][i] = d\
    \ + e.cost;\n                    if (restore) res.from[e.dst][i] = {1, u, e.id};\n\
    \                    que.emplace(d + e.cost, e.dst);\n                }\n    \
    \        }\n        }\n    }\n    return res;\n}\n}  // namespace internal_graph_util\n\
    \nnamespace internal_graph_util {\n/**\n * @brief steiner_dp \u306E\u7D50\u679C\
    \u304B\u3089\u3001X \u3092\u3059\u3079\u3066\u542B\u3080\u90E8\u5206\u6728\u306E\
    \u91CD\u307F\u304C\u6700\u5C0F\u306B\u306A\u308B\u6839\u3092\u8FD4\u3059\u3002\
    X \u3092\u9023\u7D50\u306B\u3067\u304D\u306A\u3051\u308C\u3070 -1\n */\ntemplate\
    \ <typename Cost>\nlong long steiner_root(const std::vector<std::vector<Cost>>&\
    \ dp, Cost inf) {\n    long long root = -1;\n    for (long long k = 0; k < static_cast<long\
    \ long>(dp.size()); k++) {\n        if (dp[k].back() != inf && (root == -1 ||\
    \ dp[root].back() > dp[k].back())) root = k;\n    }\n    return root;\n}\n}  //\
    \ namespace internal_graph_util\n\n/**\n * @brief \u9802\u70B9\u96C6\u5408 X \u3092\
    \u3059\u3079\u3066\u542B\u3080\u90E8\u5206\u6728\u306E\u8FBA\u306E\u91CD\u307F\
    \u306E\u7DCF\u548C\u306E\u6700\u5C0F\u5024 O(3^k n + 2^k m log m) (k = |X|)\n\
    \ * @param inf \u5185\u90E8\u306E DP \u3067\u300C\u307E\u3060\u4F5C\u308C\u306A\
    \u3044\u300D\u3092\u8868\u3059\u5024\u3002\u7B54\u3048\u306B\u306A\u308A\u3046\
    \u308B\u3069\u306E\u5024\u3088\u308A\u3082\u5927\u304D\u304F\u3059\u308B\u3053\
    \u3068\n * @return std::optional<Cost> \u6700\u5C0F\u5024\u3002X \u3092\u9023\u7D50\
    \u306B\u3067\u304D\u306A\u3051\u308C\u3070 std::nullopt\n * @note \u7121\u5411\
    \u30B0\u30E9\u30D5\u3002X \u304C\u7A7A\u306A\u3089 0\n */\ntemplate <typename\
    \ Cost, typename T>\nstd::optional<Cost> minimum_steiner_tree(const Graph<Cost>&\
    \ graph, const std::vector<T>& X, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    if (X.empty()) return Cost{};\n    const auto dp = internal_graph_util::steiner_dp(graph,\
    \ X, inf, false).dp;\n    const long long root = internal_graph_util::steiner_root(dp,\
    \ inf);\n    if (root == -1) return std::nullopt;\n    return dp[root].back();\n\
    }\n\n/**\n * @brief \u9802\u70B9\u96C6\u5408 X \u3092\u3059\u3079\u3066\u542B\u3080\
    \u91CD\u307F\u6700\u5C0F\u306E\u90E8\u5206\u6728\u3092 1 \u3064\u6C42\u3081\u3001\
    \u305D\u306E\u8FBA\u306E\u756A\u53F7\u3092\u6607\u9806\u306B\u8FD4\u3059\n * \u8A08\
    \u7B97\u91CF\u306F minimum_steiner_tree \u3068\u540C\u3058\n * @param inf minimum_steiner_tree\
    \ \u3068\u540C\u3058\n * @return std::optional<std::vector<long long>> \u8FBA\u306E\
    \u756A\u53F7\u306E\u30EA\u30B9\u30C8\u3002X \u3092\u9023\u7D50\u306B\u3067\u304D\
    \u306A\u3051\u308C\u3070 std::nullopt\n * @note \u7121\u5411\u30B0\u30E9\u30D5\
    \u3002X \u304C\u7A7A\u306A\u3089\u7A7A\u306E vector\n */\ntemplate <typename Cost,\
    \ typename T>\nstd::optional<std::vector<long long>> minimum_steiner_tree_restore(const\
    \ Graph<Cost>& graph, const std::vector<T>& X, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    if (X.empty()) return std::vector<long long>{};\n    const auto\
    \ [dp, from] = internal_graph_util::steiner_dp(graph, X, inf, true);\n    const\
    \ long long root = internal_graph_util::steiner_root(dp, inf);\n    if (root ==\
    \ -1) return std::nullopt;\n    // \u8FBA\u306E\u91CD\u307F\u304C 0 \u3060\u3068\
    \u540C\u3058\u8FBA\u3092 2 \u56DE\u4F7F\u3046\u3053\u3068\u304C\u3042\u308B\u306E\
    \u3067\u3001\u6700\u5F8C\u306B\u91CD\u8907\u3092\u9664\u304F\n    std::vector<long\
    \ long> res;\n    std::vector<std::pair<long long, int>> stk = {{root, static_cast<int>(dp[root].size())\
    \ - 1}};\n    while (!stk.empty()) {\n        auto [k, i] = stk.back();\n    \
    \    stk.pop_back();\n        const auto& f = from[k][i];\n        if (f.type\
    \ == 0) {\n            stk.emplace_back(k, static_cast<int>(f.x));\n         \
    \   stk.emplace_back(k, i ^ static_cast<int>(f.x));\n        } else if (f.type\
    \ == 1) {\n            res.push_back(f.id);\n            stk.emplace_back(f.x,\
    \ i);\n        }\n    }\n    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 2 \"src/geometry/manhattan.hpp\"\
    \n\n/**\n * @file manhattan.hpp\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\
    \u8DDD\u96E2 (\u6700\u8FD1\u70B9\u5BFE\u30FB\u6700\u9060\u70B9\u5BFE\u3001\u5404\
    \u70B9\u304B\u3089\u6700\u3082\u8FD1\u3044\u70B9\u30FB\u6700\u3082\u9060\u3044\
    \u70B9)\n */\n\n#line 10 \"src/geometry/manhattan.hpp\"\n#include <cmath>\n#include\
    \ <map>\n#include <numeric>\n#line 14 \"src/geometry/manhattan.hpp\"\n\n#line\
    \ 2 \"src/geometry/vector.hpp\"\n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\
    \u30D9\u30AF\u30C8\u30EB\n */\n\n#include <array>\n#line 11 \"src/geometry/vector.hpp\"\
    \n#include <istream>\n#include <ostream>\n#include <type_traits>\n#line 15 \"\
    src/geometry/vector.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file\
    \ traits.hpp\n * @brief \u578B\u7279\u6027\n */\n\n#include <cstddef>\n#line 10\
    \ \"src/utility/traits.hpp\"\n#include <iterator>\n#include <set>\n#line 14 \"\
    src/utility/traits.hpp\"\n\nnamespace internal_traits {\nusing std::begin, std::end;\n\
    \ntemplate <class T, class = void>\nstruct is_range_impl : std::false_type {};\n\
    template <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \nnamespace internal_traits {\n// \u5C04\u5F71 (proj) \u306E\u65E2\u5B9A\u5024\
    \n#if __cplusplus >= 202002L\nusing identity = std::identity;\n#else\nstruct identity\
    \ {\n    using is_transparent = void;\n    template <class T>\n    constexpr T&&\
    \ operator()(T&& x) const noexcept {\n        return std::forward<T>(x);\n   \
    \ }\n};\n#endif\n}  // namespace internal_traits\n\ntemplate <class C>\nusing\
    \ mem_value_type = typename C::value_type;\ntemplate <class C>\nusing mem_difference_type\
    \ = typename C::difference_type;\n\nnamespace internal_traits {\ntemplate <class\
    \ T, class = void>\nstruct is_sorted_container_impl : std::false_type {};\ntemplate\
    \ <class T>\nstruct is_sorted_container_impl<std::set<T>> : std::true_type {};\n\
    template <class T>\nstruct is_sorted_container_impl<std::multiset<T>> : std::true_type\
    \ {};\n}  // namespace internal_traits\ntemplate <class T>\nstruct is_sorted_container\
    \ : internal_traits::is_sorted_container_impl<T>::type {};\ntemplate <class T>\n\
    inline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 17 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
    \u3057\u3066\u306E\u30D9\u30AF\u30C8\u30EB\n *\n * @tparam T \u578B \u7701\u7565\
    \u3057\u305F\u3089double\n * @tparam Dim \u6B21\u5143 \u7701\u7565\u3057\u305F\
    \u30892\n */\ntemplate <typename T = double, int Dim = 2, ENABLE_IF_T(std::is_scalar_v<T>\
    \ && (Dim > 0))>\nstruct Vector {\n    std::array<T, Dim> v;  //!< \u30D9\u30AF\
    \u30C8\u30EB\u306E\u6210\u5206\u8868\u793A\n\n    /**\n     * @brief \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * \u30BC\u30ED\
    \u30D9\u30AF\u30C8\u30EB\n     */\n    constexpr Vector() noexcept : v() {}\n\
    \    /**\n     * @brief \u53EF\u5909\u9577\u5F15\u6570\u306B\u3088\u308B\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u5404\u6210\u5206\u3092\
    \ T \u306B\u5909\u63DB\u3057\u3066\u5165\u308C\u308B (Vector(1, 2.5) \u306E\u3088\
    \u3046\u306B\u578B\u304C\u6DF7\u3056\u3063\u3066\u3082\u7E2E\u5C0F\u5909\u63DB\
    \u306E\u8B66\u544A\u3092\u51FA\u3055\u306A\u3044)\n     * @tparam Args\n     */\n\
    \    template <typename... Args>\n    constexpr Vector(Args... args) noexcept\
    \ : v{static_cast<T>(args)...} {}\n\n    /**\n     * @brief i\u756A\u76EE\u306E\
    \u6210\u5206\u3092\u8FD4\u3059\n     *\n     * @param i\n     * @return T&\n \
    \    */\n    constexpr T& operator[](long long i) noexcept {\n        return v[i];\n\
    \    }\n    /**\n     * @brief i\u756A\u76EE\u306E\u6210\u5206\u3092\u8FD4\u3059\
    \n     *\n     * @param i\n     * @return T&\n     */\n    constexpr const T&\
    \ operator[](long long i) const noexcept {\n        return v[i];\n    }\n\n  \
    \  /**\n     * @brief \u52A0\u7B97\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n   \
    \  * @param rhs\n     * @return Vector&\n     */\n    constexpr Vector& operator+=(const\
    \ Vector& rhs) noexcept {\n        for (int i = 0; i < Dim; i++) v[i] += rhs[i];\n\
    \        return *this;\n    }\n    /**\n     * @brief \u6E1B\u7B97\u4EE3\u5165\
    \u6F14\u7B97\u5B50\n     *\n     * @param rhs\n     * @return Vector&\n     */\n\
    \    constexpr Vector& operator-=(const Vector& rhs) noexcept {\n        for (int\
    \ i = 0; i < Dim; i++) v[i] -= rhs.v[i];\n        return *this;\n    }\n    /**\n\
    \     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n\
    \     *\n     * @param coef\n     * @return Vector&\n     */\n    constexpr Vector&\
    \ operator*=(const T& coef) noexcept {\n        for (int i = 0; i < Dim; i++)\
    \ v[i] *= coef;\n        return *this;\n    }\n    /**\n     * @brief \u30B9\u30AB\
    \u30E9\u30FC\u306E\u9006\u6570\u500D\u4EE3\u5165\u6F14\u7B97\u5B50\n     *\n \
    \    * @param coef\n     * @return Vector&\n     */\n    constexpr Vector& operator/=(const\
    \ T& coef) {\n        for (int i = 0; i < Dim; i++) {\n            if constexpr\
    \ (std::is_integral_v<T>) {\n                assert(v[i] % coef == 0 && \"Vector::operator/=\
    \ : coef must be a divisor of all elements\");\n            }\n            v[i]\
    \ /= coef;\n        }\n        return *this;\n    }\n\n    /**\n     * @brief\
    \ \u5358\u9805\u30D7\u30E9\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    constexpr Vector operator+() const noexcept {\n\
    \        return *this;\n    }\n    /**\n     * @brief \u5358\u9805\u30DE\u30A4\
    \u30CA\u30B9\u6F14\u7B97\u5B50\n     *\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    constexpr Vector operator-() const noexcept {\n        return *this * (-1);\n\
    \    }\n\n    /**\n     * @brief \u52A0\u7B97\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return Vector\n     */\n    [[nodiscard]]\n\
    \    friend constexpr Vector operator+(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return std::move(Vector(lhs) += rhs);\n    }\n\n    /**\n     * @brief\
    \ \u6E1B\u7B97\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n\
    \     * @return Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector\
    \ operator-(const Vector& lhs, const Vector& rhs) noexcept {\n        return std::move(Vector(lhs)\
    \ -= rhs);\n    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return Vector\n\
    \     */\n    [[nodiscard]]\n    friend constexpr Vector operator*(const Vector&\
    \ lhs, const T& coef) noexcept {\n        return std::move(Vector(lhs) *= coef);\n\
    \    }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u500D\u6F14\u7B97\u5B50\
    \n     *\n     * @param coef\n     * @param rhs\n     * @return Vector\n     */\n\
    \    [[nodiscard]]\n    friend constexpr Vector operator*(const T& coef, const\
    \ Vector& rhs) noexcept {\n        return std::move(Vector(rhs) *= coef);\n  \
    \  }\n\n    /**\n     * @brief \u30B9\u30AB\u30E9\u30FC\u306E\u9006\u6570\u500D\
    \u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param coef\n     * @return\
    \ Vector\n     */\n    [[nodiscard]]\n    friend constexpr Vector operator/(const\
    \ Vector& lhs, const T& coef) {\n        return std::move(Vector(lhs) /= coef);\n\
    \    }\n\n    /**\n     * @brief \u7B49\u4FA1\u6F14\u7B97\u5B50\n     *\n    \
    \ * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator==(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v == rhs.v;\n    }\n\n    /**\n     * @brief \u975E\u7B49\
    \u4FA1\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v != rhs.v;\n\
    \    }\n\n    /**\n     * @brief \u5C0F\u306A\u308A\u6F14\u7B97\u5B50\n     *\n\
    \     * @param lhs\n     * @param rhs\n     * @return bool\n     */\n    [[nodiscard]]\n\
    \    friend constexpr bool operator<(const Vector& lhs, const Vector& rhs) noexcept\
    \ {\n        return lhs.v < rhs.v;\n    }\n    /**\n     * @brief \u5927\u306A\
    \u308A\u6F14\u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     *\
    \ @return bool\n     */\n    [[nodiscard]]\n    friend constexpr bool operator>(const\
    \ Vector& lhs, const Vector& rhs) noexcept {\n        return lhs.v > rhs.v;\n\
    \    }\n    /**\n     * @brief \u5C0F\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\
    \u7B97\u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n\
    \     */\n    [[nodiscard]]\n    friend constexpr bool operator<=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v <= rhs.v;\n    }\n\
    \    /**\n     * @brief \u5927\u306A\u308A\u30A4\u30B3\u30FC\u30EB\u6F14\u7B97\
    \u5B50\n     *\n     * @param lhs\n     * @param rhs\n     * @return bool\n  \
    \   */\n    [[nodiscard]]\n    friend constexpr bool operator>=(const Vector&\
    \ lhs, const Vector& rhs) noexcept {\n        return lhs.v >= rhs.v;\n    }\n\n\
    \    /**\n     * @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\
    \u306E\u8AAD\u307F\u8FBC\u307F\n     *\n     * @tparam CharT \u5165\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u5165\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_istream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Vector& rhs) {\n\
    \        for (int i = 0; i < Dim; i++) is >> rhs.v[i];\n        return is;\n \
    \   }\n    /**\n     * @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u3078\
    \u306E\u66F8\u304D\u8FBC\u307F\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n   \
    \  * @param is\n     * @param rhs\n     * @return std::basic_ostream<CharT, Traits>&\n\
    \     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const Vector& rhs)\
    \ {\n        for (int i = 0; i < Dim; i++) {\n            if (i != 0) os << CharT('\
    \ ');\n            os << rhs.v[i];\n        }\n        return os;\n    }\n\n \
    \   /**\n     * @brief \u5185\u7A4D\n     *\n     * @param lhs\n     * @param\
    \ rhs\n     * @return T\n     */\n    friend constexpr T dot(const Vector& lhs,\
    \ const Vector& rhs) noexcept {\n        T ret = 0;\n        for (int i = 0; i\
    \ < Dim; i++) ret += lhs[i] * rhs[i];\n        return ret;\n    }\n\n    /**\n\
    \     * @brief \u7D76\u5BFE\u5024\u306E2\u4E57\n     *\n     * @return T\n   \
    \  */\n    constexpr T squared_norm() const noexcept {\n        return dot(*this,\
    \ *this);\n    }\n    /**\n     * @brief \u7D76\u5BFE\u5024\n     *\n     * @return\
    \ double\n     */\n    constexpr double abs() const noexcept {\n        return\
    \ std::sqrt(squared_norm());\n    }\n};\n\n/**\n * @brief \u6210\u5206\u304B\u3089\
    \u4F5C\u308B\u3068\u304D\u306E\u63A8\u8AD6\u30AC\u30A4\u30C9\u3002\u578B\u306F\
    \u6210\u5206\u306E\u5171\u901A\u306E\u578B\u3001\u6B21\u5143\u306F\u6210\u5206\
    \u306E\u500B\u6570\u306B\u3059\u308B\n *\n * Vector(2LL, 3LL) \u306F Vector<long\
    \ long, 2>\u3001Vector(1, 2, 3) \u306F Vector<int, 3>\u3001Vector(0.0, 0.0) \u306F\
    \ Vector<double, 2>\n * (\u3053\u308C\u304C\u306A\u3044\u3068\u3001\u30C6\u30F3\
    \u30D7\u30EC\u30FC\u30C8\u5F15\u6570\u306E\u7701\u7565\u6642\u306E\u5024\u304B\
    \u3089 Vector<double, 2> \u306B\u306A\u3063\u3066\u3057\u307E\u3046)\n */\ntemplate\
    \ <typename T, typename... U, ENABLE_IF_T(std::is_scalar_v<T> && (std::is_scalar_v<U>\
    \ && ...))>\nVector(T, U...) -> Vector<std::common_type_t<T, U...>, 1 + sizeof...(U)>;\n\
    \n/**\n * @brief \u4E8C\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\u3046\u3057\u306E\
    \u5916\u7A4D(\u5E73\u884C\u56DB\u8FBA\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D)\n *\n * @param lhs\n * @param rhs\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @return T\n */\ntemplate <typename T>\nconstexpr T cross(const Vector<T,\
    \ 2>& lhs, const Vector<T, 2>& rhs) noexcept {\n    return lhs[0] * rhs[1] - lhs[1]\
    \ * rhs[0];\n}\n/**\n * @brief \u4E09\u6B21\u5143\u30D9\u30AF\u30C8\u30EB\u3069\
    \u3046\u3057\u306E\u5916\u7A4D\n *\n * @param lhs\n * @param rhs\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @return Vector<T, 3>\n */\ntemplate <typename T>\n\
    constexpr Vector<T, 3> cross(const Vector<T, 3>& lhs, const Vector<T, 3>& rhs)\
    \ noexcept {\n    Vector<T, 3> ret;\n    ret[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];\n\
    \    ret[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];\n    ret[2] = lhs[0] * rhs[1]\
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n#line 16 \"src/geometry/manhattan.hpp\"\
    \n\nnamespace internal_manhattan {\n/**\n * @brief \u5404\u70B9 j \u3068\u3001\
    j \u3092\u9802\u70B9\u3068\u3059\u308B 45 \u5EA6\u305A\u3064\u306E 8 \u3064\u306E\
    \u9818\u57DF\u306E\u3046\u3061 4 \u3064\u306E\u305D\u308C\u305E\u308C\u306B\u3064\
    \u3044\u3066\u3001\u305D\u306E\u9818\u57DF\u3067 j \u306B\u6700\u3082\u8FD1\u3044\
    \u70B9 i \u3092 f(j, i, \u8DDD\u96E2) \u3067\u6E21\u3059 O(n log n)\n * \u6B8B\
    \u308A\u306E 4 \u3064\u306E\u9818\u57DF\u306F\u3001\u70B9\u3092\u539F\u70B9\u306B\
    \u3064\u3044\u3066\u53CD\u8EE2\u3055\u305B\u3066\u547C\u3079\u3070\u5F97\u3089\
    \u308C\u308B\n */\ntemplate <typename T, typename F>\nvoid octant_nearest(std::vector<Vector<T,\
    \ 2>> p, F f) {\n    const long long n = p.size();\n    std::vector<long long>\
    \ id(n);\n    std::iota(id.begin(), id.end(), 0);\n    for (int k = 0; k < 4;\
    \ k++) {\n        // x + y \u306E\u6607\u9806\u306B\u898B\u3066\u3001x - y \u306E\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u4E2D\u3067 y \u304C\u8FD1\u3044\u70B9\u3092\
    \ map \u304B\u3089\u53D6\u308A\u51FA\u3059\n        std::sort(id.begin(), id.end(),\
    \ [&](long long i, long long j) { return p[i][0] + p[i][1] < p[j][0] + p[j][1];\
    \ });\n        std::map<T, long long> sweep;  // -y -> \u70B9\n        for (long\
    \ long i : id) {\n            for (auto it = sweep.lower_bound(-p[i][1]); it !=\
    \ sweep.end(); it = sweep.erase(it)) {\n                const long long j = it->second;\n\
    \                const T dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];\n   \
    \             if (dy > dx) break;\n                f(j, i, dx + dy);\n       \
    \     }\n            sweep[-p[i][1]] = i;\n        }\n        // 4 \u3064\u306E\
    \u5411\u304D: (x, y) -> (y, x) -> (-y, x) -> (x, -y) \u3068\u5909\u3048\u308B\n\
    \        for (auto& v : p) {\n            if (k % 2 == 0) {\n                std::swap(v[0],\
    \ v[1]);\n            } else {\n                v[0] = -v[0];\n            }\n\
    \        }\n    }\n}\n}  // namespace internal_manhattan\n\n/**\n * @brief \u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u8FD1\u70B9\u5BFE\u30FB\
    \u6700\u9060\u70B9\u5BFE\u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\n\
    struct ManhattanPair {\n    T dist;          //!< \u8DDD\u96E2\n    long long\
    \ i, j;  //!< 2 \u70B9\u306E\u6DFB\u5B57 (i != j)\n};\n\n/**\n * @brief \u5404\
    \u70B9\u304B\u3089\u3001\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\
    \u6700\u3082\u8FD1\u3044\u307B\u304B\u306E\u70B9\u306E\u6DFB\u5B57 O(n log n)\n\
    \ * 8 \u3064\u306E\u9818\u57DF\u306E\u305D\u308C\u305E\u308C\u3067\u6700\u3082\
    \u8FD1\u3044\u70B9\u306E\u3046\u3061\u3001\u6700\u3082\u8FD1\u3044\u3082\u306E\
    \u3002\u70B9\u304C 1 \u500B\u306A\u3089 -1\n */\ntemplate <typename T>\nstd::vector<long\
    \ long> manhattan_nearest_points(const std::vector<Vector<T, 2>>& p) {\n    const\
    \ long long n = p.size();\n    std::vector<long long> res(n, -1);\n    std::vector<T>\
    \ best(n);\n    // \u540C\u3058\u4F4D\u7F6E\u306E\u70B9\u3069\u3046\u3057\u306F\
    \u3001\u3069\u306E\u5411\u304D\u3067\u6383\u3044\u3066\u3082\u4E26\u3076\u9806\
    \u304C\u5909\u308F\u3089\u305A\u7247\u65B9\u304B\u3089\u3057\u304B\u898B\u3064\
    \u304B\u3089\u306A\u3044\u306E\u3067\u3001\u5148\u306B\u7D44\u306B\u3059\u308B\
    \n    std::vector<long long> id(n);\n    std::iota(id.begin(), id.end(), 0);\n\
    \    std::sort(id.begin(), id.end(), [&](long long i, long long j) { return p[i]\
    \ < p[j]; });\n    for (long long k = 0; k + 1 < n; k++) {\n        if (p[id[k]]\
    \ == p[id[k + 1]]) res[id[k]] = id[k + 1], res[id[k + 1]] = id[k], best[id[k]]\
    \ = best[id[k + 1]] = 0;\n    }\n    auto update = [&](long long j, long long\
    \ i, T d) {\n        if (res[j] == -1 || d < best[j]) res[j] = i, best[j] = d;\n\
    \    };\n    internal_manhattan::octant_nearest(p, update);\n    std::vector<Vector<T,\
    \ 2>> q(p);\n    for (auto& v : q) v = -v;\n    internal_manhattan::octant_nearest(q,\
    \ update);\n    return res;\n}\n\n/**\n * @brief \u5404\u70B9\u304B\u3089\u3001\
    \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u3067\u6700\u3082\u9060\u3044\
    \u70B9\u306E\u6DFB\u5B57 O(n)\n * |dx| + |dy| = max(|du|, |dv|) (u = x + y, v\
    \ = x - y) \u306A\u306E\u3067\u3001u \u3068 v \u304C\u6700\u5927\u30FB\u6700\u5C0F\
    \u306E\u70B9\u306E\u3069\u308C\u304B\u3002\u70B9\u304C 1 \u500B\u306A\u3089 -1\n\
    \ */\ntemplate <typename T>\nstd::vector<long long> manhattan_farthest_points(const\
    \ std::vector<Vector<T, 2>>& p) {\n    const long long n = p.size();\n    if (n\
    \ <= 1) return std::vector<long long>(n, -1);\n    // ext[0], ext[1]: u \u304C\
    \u6700\u5C0F\u30FB\u6700\u5927\u306E\u70B9\u3001ext[2], ext[3]: v \u304C\u6700\
    \u5C0F\u30FB\u6700\u5927\u306E\u70B9\n    auto u = [&](long long i) { return p[i][0]\
    \ + p[i][1]; };\n    auto v = [&](long long i) { return p[i][0] - p[i][1]; };\n\
    \    long long ext[4] = {0, 0, 0, 0};\n    for (long long i = 1; i < n; i++) {\n\
    \        if (u(i) < u(ext[0])) ext[0] = i;\n        if (u(i) > u(ext[1])) ext[1]\
    \ = i;\n        if (v(i) < v(ext[2])) ext[2] = i;\n        if (v(i) > v(ext[3]))\
    \ ext[3] = i;\n    }\n    std::vector<long long> res(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        long long b = -1;\n        T best = 0;\n       \
    \ for (long long j : ext) {\n            const T d = std::abs(p[i][0] - p[j][0])\
    \ + std::abs(p[i][1] - p[j][1]);\n            if (j != i && (b == -1 || d > best))\
    \ b = j, best = d;\n        }\n        // 4 \u70B9\u304C\u3059\u3079\u3066 i \u81EA\
    \u8EAB\u306A\u3089\u3001\u3059\u3079\u3066\u306E\u70B9\u304C\u540C\u3058\u4F4D\
    \u7F6E\u306B\u3042\u308B\n        res[i] = b == -1 ? (i == 0 ? 1 : 0) : b;\n \
    \   }\n    return res;\n}\n\n/**\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\
    \u8DDD\u96E2\u306E\u6700\u8FD1\u70B9\u5BFE (\u70B9\u306F 2 \u500B\u4EE5\u4E0A\
    ) O(n log n)\n * \u6700\u5C0F\u5168\u57DF\u6728\u306E\u8FBA\u306E\u5019\u88DC\
    \ (\u5404\u70B9\u304B\u3089 4 \u3064\u306E\u9818\u57DF\u3067\u6700\u3082\u8FD1\
    \u3044\u70B9\u3078\u306E\u8FBA) \u306B\u3001\u6700\u3082\u8FD1\u3044 2 \u70B9\u3092\
    \u7D50\u3076\u8FBA\u304C\u542B\u307E\u308C\u308B\n */\ntemplate <typename T>\n\
    ManhattanPair<T> manhattan_closest_pair(const std::vector<Vector<T, 2>>& p) {\n\
    \    assert(p.size() >= 2 && \"manhattan_closest_pair: fewer than 2 points\");\n\
    \    ManhattanPair<T> res{T(0), -1, -1};\n    internal_manhattan::octant_nearest(p,\
    \ [&](long long j, long long i, T d) {\n        if (res.i == -1 || d < res.dist)\
    \ res = {d, std::min(i, j), std::max(i, j)};\n    });\n    return res;\n}\n\n\
    /**\n * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u9060\
    \u70B9\u5BFE (\u70B9\u306F 2 \u500B\u4EE5\u4E0A) O(n)\n * u = x + y, v = x - y\
    \ \u306E\u6700\u5927\u3068\u6700\u5C0F\u306E\u5DEE\u306E\u3046\u3061\u5927\u304D\
    \u3044\u65B9\n */\ntemplate <typename T>\nManhattanPair<T> manhattan_farthest_pair(const\
    \ std::vector<Vector<T, 2>>& p) {\n    const long long n = p.size();\n    assert(n\
    \ >= 2 && \"manhattan_farthest_pair: fewer than 2 points\");\n    const std::vector<long\
    \ long> f = manhattan_farthest_points(p);\n    ManhattanPair<T> res{T(0), -1,\
    \ -1};\n    for (long long i = 0; i < n; i++) {\n        const long long j = f[i];\n\
    \        const T d = std::abs(p[i][0] - p[j][0]) + std::abs(p[i][1] - p[j][1]);\n\
    \        if (res.i == -1 || d > res.dist) res = {d, std::min(i, j), std::max(i,\
    \ j)};\n    }\n    return res;\n}\n#line 13 \"src/geometry/manhattan-mst.hpp\"\
    \n\n/**\n * @brief \u70B9\u306E\u96C6\u5408\u3067\u30012 \u70B9\u3092\u7D50\u3076\
    \u8FBA\u306E\u91CD\u307F\u3092\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\
    \ |dx| + |dy| \u3068\u3057\u305F\u5B8C\u5168\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\
    \u5168\u57DF\u6728 O(n log n)\n *\n * \u5404\u70B9 i \u306B\u3064\u3044\u3066\u3001\
    i \u3092\u9802\u70B9\u3068\u3059\u308B 45 \u5EA6\u305A\u3064\u306E 8 \u3064\u306E\
    \u9818\u57DF\u306E\u305D\u308C\u305E\u308C\u3067\u6700\u3082\u8FD1\u3044\u70B9\
    \u3078\u306E\u8FBA\u3060\u3051\u3092\u5019\u88DC\u306B\u3059\u308C\u3070\u3088\
    \u3044\u3002\n * \u5411\u304D\u3092\u5909\u3048\u306A\u304C\u3089 4 \u56DE\u6383\
    \u3044\u3066 O(n) \u672C\u306E\u5019\u88DC\u3092\u4F5C\u308A\u3001Kruskal \u6CD5\
    \u306B\u304B\u3051\u308B\n * @return \u6700\u5C0F\u5168\u57DF\u6728 (\u8FBA\u306E\
    \ src\u3001dst \u306F\u70B9\u306E\u756A\u53F7\u3001cost \u306F\u8DDD\u96E2)\n\
    \ */\ntemplate <typename T>\nMinimumSpanningTree<T> manhattan_mst(const std::vector<Vector<T,\
    \ 2>>& p) {\n    Graph<T> g(p.size());\n    internal_manhattan::octant_nearest(p,\
    \ [&](long long j, long long i, T d) { g.add_edge(i, j, d); });\n    return minimum_spanning_tree(g);\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file manhattan-mst.hpp\n * @brief \u30DE\u30F3\u30CF\
    \u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\u5168\u57DF\u6728\n */\n\n#include\
    \ <vector>\n\n#include \"../graph/graph_util.hpp\"\n#include \"manhattan.hpp\"\
    \n#include \"vector.hpp\"\n\n/**\n * @brief \u70B9\u306E\u96C6\u5408\u3067\u3001\
    2 \u70B9\u3092\u7D50\u3076\u8FBA\u306E\u91CD\u307F\u3092\u30DE\u30F3\u30CF\u30C3\
    \u30BF\u30F3\u8DDD\u96E2 |dx| + |dy| \u3068\u3057\u305F\u5B8C\u5168\u30B0\u30E9\
    \u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728 O(n log n)\n *\n * \u5404\u70B9 i \u306B\
    \u3064\u3044\u3066\u3001i \u3092\u9802\u70B9\u3068\u3059\u308B 45 \u5EA6\u305A\
    \u3064\u306E 8 \u3064\u306E\u9818\u57DF\u306E\u305D\u308C\u305E\u308C\u3067\u6700\
    \u3082\u8FD1\u3044\u70B9\u3078\u306E\u8FBA\u3060\u3051\u3092\u5019\u88DC\u306B\
    \u3059\u308C\u3070\u3088\u3044\u3002\n * \u5411\u304D\u3092\u5909\u3048\u306A\u304C\
    \u3089 4 \u56DE\u6383\u3044\u3066 O(n) \u672C\u306E\u5019\u88DC\u3092\u4F5C\u308A\
    \u3001Kruskal \u6CD5\u306B\u304B\u3051\u308B\n * @return \u6700\u5C0F\u5168\u57DF\
    \u6728 (\u8FBA\u306E src\u3001dst \u306F\u70B9\u306E\u756A\u53F7\u3001cost \u306F\
    \u8DDD\u96E2)\n */\ntemplate <typename T>\nMinimumSpanningTree<T> manhattan_mst(const\
    \ std::vector<Vector<T, 2>>& p) {\n    Graph<T> g(p.size());\n    internal_manhattan::octant_nearest(p,\
    \ [&](long long j, long long i, T d) { g.add_edge(i, j, d); });\n    return minimum_spanning_tree(g);\n\
    }\n"
  dependsOn:
  - src/graph/graph_util.hpp
  - src/data_structures/unionfind.hpp
  - src/graph/graph.hpp
  - src/geometry/manhattan.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: false
  path: src/geometry/manhattan-mst.hpp
  requiredBy: []
  timestamp: '2026-10-31 17:31:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/geometry/manhattan-mst.test.cpp
  - test/yosupo/geo/manhattanmst.test.cpp
documentation_of: src/geometry/manhattan-mst.hpp
layout: document
title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\u5168\u57DF\
  \u6728"
---

平面上の点の集合で、2 点を結ぶ辺の重みをマンハッタン距離 $\lvert x_i - x_j \rvert + \lvert y_i - y_j \rvert$ とした完全グラフの最小全域木を $O(n \log n)$ で求めます。

```cpp
std::vector<Vector<long long, 2>> p = { {0, 0}, {3, 1}, {1, 4} };
auto mst = manhattan_mst(p);
long long cost = mst.cost;  // 9 (0-1 の距離 4 と 0-2 の距離 5。1-2 は距離 5)
for (const auto& e : mst.edges) {
    // e.src、e.dst は点の番号、e.cost は距離
}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `manhattan_mst(points)` | マンハッタン距離の最小全域木。[グラフに関する関数](../graph/graph_util.hpp) の `minimum_spanning_tree` と同じ `MinimumSpanningTree<T>` (`cost` と `edges`) を返す | $O(n \log n)$ |

各点 $i$ について、$i$ を頂点とする 45 度ずつの 8 つの領域のそれぞれで最も近い点への辺だけを候補にすれば足ります。向きを変えながら 4 回掃いて $O(n)$ 本の候補を作り、Kruskal 法にかけます。同じ点があってもかまいません。

## 関連

- 一般のグラフの最小全域木は [グラフに関する関数](../graph/graph_util.hpp) の `minimum_spanning_tree`
- 各点から最も近い・遠い点や、最近点対・最遠点対は [マンハッタン距離](manhattan.hpp)
