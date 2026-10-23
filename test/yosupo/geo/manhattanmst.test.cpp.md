---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  - icon: ':heavy_check_mark:'
    path: src/geometry/manhattan-mst.hpp
    title: "\u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\u5168\
      \u57DF\u6728"
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
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/yosupo/geo/manhattanmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include <iostream>\n#include\
    \ <vector>\n\n#line 2 \"src/geometry/manhattan-mst.hpp\"\n\n/**\n * @file manhattan-mst.hpp\n\
    \ * @brief \u30DE\u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2\u306E\u6700\u5C0F\u5168\
    \u57DF\u6728\n */\n\n#include <algorithm>\n#include <map>\n#include <numeric>\n\
    #line 12 \"src/geometry/manhattan-mst.hpp\"\n\n#line 2 \"src/graph/graph_util.hpp\"\
    \n\n/**\n * @file graph_util.hpp\n * @brief \u30B0\u30E9\u30D5\u306B\u95A2\u3059\
    \u308B\u95A2\u6570\n */\n\n#line 9 \"src/graph/graph_util.hpp\"\n#include <cassert>\n\
    #include <functional>\n#include <limits>\n#include <queue>\n#include <stack>\n\
    #include <utility>\n#line 16 \"src/graph/graph_util.hpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
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
    \ a) { return leader(a); });\n    }\n};\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n\
    \ * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#line 11 \"src/graph/graph.hpp\"\
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
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n#line 19 \"\
    src/graph/graph_util.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\
    \u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\u30890\u30681\u306B\
    \u5F69\u8272\u3057\u305F\u7D50\u679C\u3092\u3072\u3068\u3064\u8FD4\u3057\u3001\
    \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089\u7A7A\u306Evector\u3092\
    \u8FD4\u3059\u3002\n * \u9023\u7D50\u6210\u5206\u306E\u3046\u3061\u3001\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306E\u6700\u3082\u5C0F\u3055\u3044\u3082\u306E\u3092\
    0\u306B\u3059\u308B\u3002\n * @return std::vector<int> \u5404\u9802\u70B9\u306E\
    \u5F69\u8272\u7D50\u679C\n */\ntemplate <typename Cost = long long>\nstd::vector<int>\
    \ bipartite_coloring(const Graph<Cost>& graph) {\n    std::vector<int> color(graph.n,\
    \ -1);\n    for (long long i = 0; i < graph.n; i++) {\n        if (color[i] !=\
    \ -1) continue;\n        std::stack<long long> stk;\n        stk.push(i);\n  \
    \      color[i] = 0;\n        while (!stk.empty()) {\n            long long u\
    \ = stk.top();\n            stk.pop();\n            for (long long v : graph[u])\
    \ {\n                if (color[v] == -1) {\n                    color[v] = color[u]\
    \ ^ 1;\n                    stk.push(v);\n                } else {\n         \
    \           if (color[u] == color[v]) return {};\n                }\n        \
    \    }\n        }\n    }\n    return color;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\
    \u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u306A\u3089true\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\
    \u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename\
    \ Cost = long long>\nbool is_bipartite(const Graph<Cost>& graph) {\n    return\
    \ !bipartite_coloring(graph).empty();\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306B\u3064\u3044\u3066\u3001\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\
    \u308B\u3002\n * @return std::vector<std::vector<long long>> \u300C\u540C\u3058\
    \u9023\u7D50\u6210\u5206\u3068\u306A\u308B\u9802\u70B9\u306E\u30EA\u30B9\u30C8\
    \u300D\u306E\u30EA\u30B9\u30C8\n */\ntemplate <typename Cost = long long>\nstd::vector<std::vector<long\
    \ long>> connected_components(const Graph<Cost>& graph) {\n    std::vector<std::vector<long\
    \ long>> groups;\n    std::vector<bool> visited(graph.n);\n    for (long long\
    \ i = 0; i < graph.n; i++) {\n        if (visited[i]) continue;\n        std::stack<long\
    \ long> stk;\n        stk.push(i);\n        visited[i] = true;\n        groups.push_back({i});\n\
    \        while (!stk.empty()) {\n            long long u = stk.top();\n      \
    \      stk.pop();\n            for (long long v : graph[u]) {\n              \
    \  if (visited[v]) continue;\n                visited[v] = true;\n           \
    \     stk.push(v);\n                groups.back().push_back(v);\n            }\n\
    \        }\n    }\n    return groups;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\
    \u30D5\u306E\u88DC\u30B0\u30E9\u30D5 (\u8FBA\u306E\u306A\u3044 2 \u9802\u70B9\u306E\
    \u9593\u306B\u8FBA\u3092\u5F35\u3063\u305F\u30B0\u30E9\u30D5) \u3092\u9023\u7D50\
    \u6210\u5206\u5206\u89E3\u3059\u308B O(n + m)\n * \u307E\u3060\u3069\u306E\u6210\
    \u5206\u306B\u3082\u5165\u3063\u3066\u3044\u306A\u3044\u9802\u70B9\u306E\u5217\
    \u3092\u6301\u3061\u3001\u53D6\u308A\u51FA\u3057\u305F\u9802\u70B9\u3068\u96A3\
    \u308A\u5408\u308F\u306A\u3044\u3082\u306E\u3092\u540C\u3058\u6210\u5206\u306B\
    \u79FB\u3059\n */\ntemplate <typename Cost = long long>\nstd::vector<std::vector<long\
    \ long>> complement_connected_components(const Graph<Cost>& graph) {\n    const\
    \ long long n = graph.n;\n    std::vector<long long> rest(n);\n    for (long long\
    \ i = 0; i < n; i++) rest[i] = i;\n    std::vector<bool> adj(n, false);\n    std::vector<std::vector<long\
    \ long>> groups;\n    while (!rest.empty()) {\n        groups.push_back({rest.back()});\n\
    \        rest.pop_back();\n        // groups.back() \u306E i \u756A\u76EE\u306E\
    \u9802\u70B9\u3092\u53D6\u308A\u51FA\u3057\u3001rest \u306E\u3046\u3061\u96A3\u308A\
    \u5408\u308F\u306A\u3044\u3082\u306E\u3092\u6210\u5206\u306B\u79FB\u3059\n   \
    \     for (size_t i = 0; i < groups.back().size(); i++) {\n            const long\
    \ long u = groups.back()[i];\n            for (long long v : graph[u]) adj[v]\
    \ = true;\n            std::vector<long long> keep;\n            for (long long\
    \ v : rest) {\n                if (adj[v]) {\n                    keep.push_back(v);\n\
    \                } else {\n                    groups.back().push_back(v);\n \
    \               }\n            }\n            rest.swap(keep);\n            for\
    \ (long long v : graph[u]) adj[v] = false;\n        }\n    }\n    return groups;\n\
    }\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\
    \u9023\u7D50\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\
    \u308B\u3002\n * @return bool \u9023\u7D50\u30B0\u30E9\u30D5\u306A\u3089true\u3001\
    \u9023\u7D50\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\
    \u3002\n */\ntemplate <typename Cost = long long>\nbool is_connected(const Graph<Cost>&\
    \ graph) {\n    return connected_components(graph).size() == 1;\n}\n\n/**\n *\
    \ @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u6728\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u6728\
    \u306A\u3089true\u3001\u6728\u3067\u306A\u3044\u306A\u3089false\u3092\u8FD4\u3059\
    \u3002\n */\ntemplate <typename Cost = long long>\nbool is_tree(const Graph<Cost>&\
    \ graph) {\n    return graph.m == graph.n - 1 && is_connected(graph);\n}\n\n/**\n\
    \ * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3059\u308B\n * @return std::vector<long long> \u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\u306B\u4E26\u3079\u305F\u9802\u70B9\u306E\u30EA\
    \u30B9\u30C8\u3002DAG \u3067\u306A\u3051\u308C\u3070\u9014\u4E2D\u307E\u3067 (\u9589\
    \u8DEF\u304B\u3089\u305F\u3069\u308A\u7740\u3051\u306A\u3044\u9802\u70B9\u3060\
    \u3051) \u3092\u4E26\u3079\u305F\u3082\u306E\u3067\u3001\u9577\u3055\u304C n \u3088\
    \u308A\u77ED\u304F\u306A\u308B\n */\ntemplate <typename Cost = long long>\nstd::vector<long\
    \ long> topological_sort(const Graph<Cost>& graph) {\n    std::vector<int> indeg(graph.n);\n\
    \    std::vector<long long> sorted;\n    std::queue<long long> q;\n    for (long\
    \ long i = 0; i < graph.n; i++) {\n        for (long long dst : graph[i]) indeg[dst]++;\n\
    \    }\n    for (long long i = 0; i < graph.n; i++) {\n        if (!indeg[i])\
    \ q.push(i);\n    }\n    while (!q.empty()) {\n        long long cur = q.front();\n\
    \        q.pop();\n        for (long long dst : graph[cur]) {\n            if\
    \ (!--indeg[dst]) q.push(dst);\n        }\n        sorted.push_back(cur);\n  \
    \  }\n    return sorted;\n}\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306B\
    \u3064\u3044\u3066\u3001\u30B5\u30A4\u30AF\u30EB\u3092\u3082\u3064\u304B\u3069\
    \u3046\u304B\u3092\u5224\u5B9A\u3059\u308B\u3002\n * @return bool \u30B5\u30A4\
    \u30AF\u30EB\u3092\u3082\u3064\u306A\u3089true\u3001\u975E\u5DE1\u56DE\u306A\u3089\
    false\u3092\u8FD4\u3059\u3002\n */\ntemplate <typename Cost = long long>\nbool\
    \ has_cycle(const Graph<Cost>& graph) {\n    return static_cast<long long>(topological_sort(graph).size())\
    \ < graph.n;\n}\n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\
    \u3092 1 \u3064\u6C42\u3081\u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\u308F\
    \u305A\u306B\u884C\u3046\u3002O(n + m)\n * @return std::vector<Edge> \u9589\u8DEF\
    \u306E\u8FBA\u3092\u3001\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\u3082\
    \u306E (e[k].dst == e[k + 1].src\u3001\u672B\u5C3E\u306E dst \u306F\u5148\u982D\
    \u306E src)\u3002\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070\u7A7A\n * \u81EA\u5DF1\
    \u30EB\u30FC\u30D7\u306F\u9577\u3055 1 \u306E\u9589\u8DEF\u306B\u306A\u308B\u3002\
    \u9802\u70B9\u306E\u5217\u306F\u5404\u8FBA\u306E src \u3067\u5F97\u3089\u308C\u308B\
    \n */\ntemplate <typename Cost = long long>\nstd::vector<typename Graph<Cost>::Edge>\
    \ find_cycle_directed(const Graph<Cost>& graph) {\n    using Edge = typename Graph<Cost>::Edge;\n\
    \    // state: 0 \u306F\u672A\u8A2A\u554F\u30011 \u306F DFS \u306E\u30B9\u30BF\
    \u30C3\u30AF\u4E0A\u30012 \u306F\u63A2\u7D22\u6E08\u307F\n    std::vector<int>\
    \ state(graph.n, 0), iter(graph.n, 0);\n    std::vector<Edge> in(graph.n);  //\
    \ DFS \u6728\u3067 v \u306B\u5165\u308B\u8FBA\n    for (long long root = 0; root\
    \ < graph.n; root++) {\n        if (state[root]) continue;\n        std::vector<long\
    \ long> st = {root};\n        state[root] = 1;\n        while (!st.empty()) {\n\
    \            long long v = st.back();\n            if (iter[v] == static_cast<int>(graph[v].size()))\
    \ {\n                state[v] = 2;\n                st.pop_back();\n         \
    \       continue;\n            }\n            const Edge& e = graph[v][iter[v]++];\n\
    \            long long u = e.dst;\n            if (state[u] == 0) {\n        \
    \        state[u] = 1;\n                in[u] = e;\n                st.push_back(u);\n\
    \            } else if (state[u] == 1) {\n                // u \u306F\u30B9\u30BF\
    \u30C3\u30AF\u4E0A\u306B\u3042\u308B\u306E\u3067\u3001u \u304B\u3089 v \u3078\u306E\
    \u6728\u306E\u8FBA\u3068 e \u3067\u9589\u8DEF\u306B\u306A\u308B\n            \
    \    std::vector<Edge> res = {e};\n                for (long long w = v; w !=\
    \ u; w = in[w].src) res.push_back(in[w]);\n                std::reverse(res.begin(),\
    \ res.end());\n                return res;\n            }\n        }\n    }\n\
    \    return {};\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\u9589\
    \u8DEF\u3092 1 \u3064\u6C42\u3081\u308B\n *\n * DFS \u3092\u518D\u5E30\u3092\u4F7F\
    \u308F\u305A\u306B\u884C\u3046\u3002O(n + m)\n * @return std::vector<Edge> \u9589\
    \u8DEF\u306E\u8FBA\u3092\u3001\u305F\u3069\u308B\u9806\u306B\u4E26\u3079\u305F\
    \u3082\u306E (e[k].dst == e[k + 1].src\u3001\u672B\u5C3E\u306E dst \u306F\u5148\
    \u982D\u306E src)\u3002\u9589\u8DEF\u304C\u306A\u3051\u308C\u3070\u7A7A\n * \u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u306F\u9577\u3055 1\u3001\u591A\u91CD\u8FBA\u306F\u9577\
    \u3055 2 \u306E\u9589\u8DEF\u306B\u306A\u308B (\u540C\u3058\u8FBA\u3092\u623B\u308B\
    \u3053\u3068\u306F\u306A\u3044)\u3002\u9802\u70B9\u306E\u5217\u306F\u5404\u8FBA\
    \u306E src \u3067\u5F97\u3089\u308C\u308B\n */\ntemplate <typename Cost = long\
    \ long>\nstd::vector<typename Graph<Cost>::Edge> find_cycle_undirected(const Graph<Cost>&\
    \ graph) {\n    using Edge = typename Graph<Cost>::Edge;\n    std::vector<int>\
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
    \u304B\u3063\u3066\u3044\u308B)\n        }\n    }\n    return {};\n}\n\n/**\n\
    \ * @brief \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\u3059\u308B\n *\n * Tarjan \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3092\
    \u518D\u5E30\u3092\u4F7F\u308F\u305A\u306B\u884C\u3046\u3002O(n + m)\n *\n * @return\
    \ std::vector<std::vector<long long>> \u5F37\u9023\u7D50\u6210\u5206\u3054\u3068\
    \u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8\u3002\n * \u6210\u5206\u306F\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u9806\u306B\u4E26\u3076 (\u6210\u5206 A \u304B\u3089\u6210\
    \u5206 B \u3078\u8FBA\u304C\u3042\u308C\u3070 A \u304C B \u3088\u308A\u524D)\n\
    \ */\ntemplate <typename Cost = long long>\nstd::vector<std::vector<long long>>\
    \ strongly_connected_components(const Graph<Cost>& graph) {\n    const long long\
    \ n = graph.n;\n    std::vector<int> ord(n, -1), low(n), comp(n, -1), iter(n,\
    \ 0);\n    std::vector<long long> visiting;  // \u6210\u5206\u304C\u307E\u3060\
    \u6C7A\u307E\u3063\u3066\u3044\u306A\u3044\u8A2A\u554F\u6E08\u307F\u306E\u9802\
    \u70B9\n    std::vector<long long> call;      // DFS \u306E\u547C\u3073\u51FA\u3057\
    \u30B9\u30BF\u30C3\u30AF\n    int now = 0, k = 0;\n    for (long long s = 0; s\
    \ < n; s++) {\n        if (ord[s] != -1) continue;\n        ord[s] = low[s] =\
    \ now++;\n        visiting.push_back(s);\n        call.push_back(s);\n       \
    \ while (!call.empty()) {\n            long long v = call.back();\n          \
    \  if (iter[v] < static_cast<int>(graph[v].size())) {\n                long long\
    \ to = graph[v][iter[v]++].dst;\n                if (ord[to] == -1) {\n      \
    \              ord[to] = low[to] = now++;\n                    visiting.push_back(to);\n\
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
    \u307E\u3067) O(3^n) \u3088\u308A\u5C11\u3057\u901F\u3044\n * \u72EC\u7ACB\u96C6\
    \u5408\u306E\u8868\u3092 O(2^n) \u3067\u4F5C\u308A\u3001dp[S] = min (dp[S \\ T]\
    \ + 1) \u3092\u3001T \u3092\u300CS \u306E\u6700\u5C0F\u306E\u9802\u70B9 v \u3092\
    \u542B\u307F\u3001v \u3068\u96A3\u308A\u5408\u308F\u306A\u3044 S \u306E\u9802\u70B9\
    \u304B\u3089\u306A\u308B\u72EC\u7ACB\u96C6\u5408\u300D\u306B\u9650\u3063\u3066\
    \u6C42\u3081\u308B\n * \u9802\u70B9\u304C\u306A\u3051\u308C\u3070 0\u3002\u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u304C\u3042\u308C\u3070\u5857\u308C\u306A\u3044\u306E\
    \u3067 -1\n */\ntemplate <typename Cost = long long>\nlong long chromatic_number(const\
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
    \n/**\n * @brief \u9802\u70B9\u96C6\u5408 X \u3092\u3059\u3079\u3066\u542B\u3080\
    \u90E8\u5206\u6728\u306E\u8FBA\u306E\u91CD\u307F\u306E\u7DCF\u548C\u306E\u6700\
    \u5C0F\u5024 O(3^k n + 2^k m log m) (k = |X|)\n * @note \u7121\u5411\u30B0\u30E9\
    \u30D5\u3002X \u304C\u7A7A\u306A\u3089 0\u3002X \u3092\u9023\u7D50\u306B\u3067\
    \u304D\u306A\u3051\u308C\u3070 inf \u3092\u8FD4\u3059\n */\ntemplate <typename\
    \ Cost, typename T>\nCost minimum_steiner_tree(const Graph<Cost>& graph, const\
    \ std::vector<T>& X, Cost inf = std::numeric_limits<Cost>::max() / 4) {\n    if\
    \ (X.empty()) return Cost{};\n    const auto dp = internal_graph_util::steiner_dp(graph,\
    \ X, inf, false).dp;\n    Cost res = inf;\n    for (long long k = 0; k < graph.n;\
    \ k++) {\n        if (dp[k].back() != inf && (res == inf || res > dp[k].back()))\
    \ res = dp[k].back();\n    }\n    return res;\n}\n\n/**\n * @brief \u9802\u70B9\
    \u96C6\u5408 X \u3092\u3059\u3079\u3066\u542B\u3080\u91CD\u307F\u6700\u5C0F\u306E\
    \u90E8\u5206\u6728\u3092 1 \u3064\u6C42\u3081\u3001\u305D\u306E\u8FBA\u306E\u756A\
    \u53F7\u3092\u6607\u9806\u306B\u8FD4\u3059\n * \u8A08\u7B97\u91CF\u306F minimum_steiner_tree\
    \ \u3068\u540C\u3058\n * @note \u7121\u5411\u30B0\u30E9\u30D5\u3002X \u304C\u7A7A\
    \u306A\u3089\u7A7A\u3002X \u306E\u9802\u70B9\u3069\u3046\u3057\u304C\u9023\u7D50\
    \u3067\u306A\u3044\u3068\u304D\u306F\u547C\u3070\u306A\u3044\u3053\u3068\n */\n\
    template <typename Cost, typename T>\nstd::vector<long long> minimum_steiner_tree_restore(const\
    \ Graph<Cost>& graph, const std::vector<T>& X, Cost inf = std::numeric_limits<Cost>::max()\
    \ / 4) {\n    if (X.empty()) return {};\n    const auto [dp, from] = internal_graph_util::steiner_dp(graph,\
    \ X, inf, true);\n    long long root = -1;\n    for (long long k = 0; k < graph.n;\
    \ k++) {\n        if (dp[k].back() != inf && (root == -1 || dp[root].back() >\
    \ dp[k].back())) root = k;\n    }\n    assert(root != -1);\n    // \u8FBA\u306E\
    \u91CD\u307F\u304C 0 \u3060\u3068\u540C\u3058\u8FBA\u3092 2 \u56DE\u4F7F\u3046\
    \u3053\u3068\u304C\u3042\u308B\u306E\u3067\u3001\u6700\u5F8C\u306B\u91CD\u8907\
    \u3092\u9664\u304F\n    std::vector<long long> res;\n    std::vector<std::pair<long\
    \ long, int>> stk = {{root, static_cast<int>(dp[root].size()) - 1}};\n    while\
    \ (!stk.empty()) {\n        auto [k, i] = stk.back();\n        stk.pop_back();\n\
    \        const auto& f = from[k][i];\n        if (f.type == 0) {\n           \
    \ stk.emplace_back(k, static_cast<int>(f.x));\n            stk.emplace_back(k,\
    \ i ^ static_cast<int>(f.x));\n        } else if (f.type == 1) {\n           \
    \ res.push_back(f.id);\n            stk.emplace_back(f.x, i);\n        }\n   \
    \ }\n    std::sort(res.begin(), res.end());\n    res.erase(std::unique(res.begin(),\
    \ res.end()), res.end());\n    return res;\n}\n#line 2 \"src/geometry/vector.hpp\"\
    \n\n/**\n * @file vector.hpp\n * @brief \u5E7E\u4F55\u30D9\u30AF\u30C8\u30EB\n\
    \ */\n\n#line 9 \"src/geometry/vector.hpp\"\n#include <array>\n#line 11 \"src/geometry/vector.hpp\"\
    \n#include <cmath>\n#include <istream>\n#line 15 \"src/geometry/vector.hpp\"\n\
    #include <optional>\n#include <ostream>\n#line 18 \"src/geometry/vector.hpp\"\n\
    #include <type_traits>\n#line 21 \"src/geometry/vector.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
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
    #line 23 \"src/geometry/vector.hpp\"\n\n/**\n * @brief \u5E7E\u4F55\u5B66\u3068\
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
    \ - lhs[1] * rhs[0];\n    return ret;\n}\n\n/**\n * @brief \u7DDA\u5206\u306E\u4EA4\
    \u5DEE\u5224\u5B9A\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\
    \u5916\u7A4D\u3092\u8A08\u7B97\u3059\u308B\u305F\u3081\u3001\u5EA7\u6A19\u306E\
    \u7D76\u5BFE\u5024\u306E2\u4E57\u306E\u6570\u500D\u304CT\u306B\u53CE\u307E\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B91\n * @param p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B9\
    2\n * @param q1 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ q2 2\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\
    \u306E\u578B\n * @return bool \u5171\u6709\u70B9\u3092\u6301\u3064\u304B\n */\n\
    template <typename T>\nconstexpr bool segments_intersect(const Vector<T, 2>& p1,\
    \ const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n\
    \    assert(p1 != p2 && q1 != q2 && \"segments_intersect: degenerate segment\"\
    );\n    auto sign = [](T x) { return (x > 0) - (x < 0); };\n    int q1_section\
    \ = sign(cross(p2 - p1, q1 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int q2_section =\
    \ sign(cross(p2 - p1, q2 - p1));  // \u76F4\u7DDAp1p2\u306B\u5BFE\u3057\u3066\
    q2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p1_section =\
    \ sign(cross(q2 - q1, p1 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p1\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    int p2_section =\
    \ sign(cross(q2 - q1, p2 - q1));  // \u76F4\u7DDAq1q2\u306B\u5BFE\u3057\u3066\
    p2\u304C\u3069\u306E\u4F4D\u7F6E\u306B\u3042\u308B\u304B\n    if (q1_section ==\
    \ 0 && q2_section == 0) {\n        // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\
    \u306B\u3042\u308B\u5834\u5408\n        return dot(q1 - p1, q2 - p1) <= 0 || dot(q1\
    \ - p2, q2 - p2) <= 0 || dot(p1 - q1, p2 - q1) <= 0;\n    }\n    return q1_section\
    \ * q2_section <= 0 && p1_section * p2_section <= 0;\n}\n\n/**\n * @brief \u7DDA\
    \u5206\u306E\u4EA4\u5DEE\u5224\u5B9A\u3068\u5171\u6709\u70B9\u306E\u8A08\u7B97\
    \n *\n * \u5171\u6709\u70B9\u306E\u5EA7\u6A19\u306F\u4E00\u822C\u306B\u6574\u6570\
    \u306B\u306A\u3089\u306A\u3044\u305F\u3081\u3001\u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u578B\u9650\u5B9A\n * \u6574\u6570\u5EA7\u6A19\u3067\u4EA4\u5DEE\u5224\u5B9A\u3060\
    \u3051\u3057\u305F\u3044\u5834\u5408\u306F segments_intersect \u3092\u4F7F\u3046\
    \n *\n * @param p1 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param\
    \ p2 1\u672C\u76EE\u306E\u7DDA\u5206\u306E\u7AEF\u70B92\n * @param q1 2\u672C\u76EE\
    \u306E\u7DDA\u5206\u306E\u7AEF\u70B91\n * @param q2 2\u672C\u76EE\u306E\u7DDA\u5206\
    \u306E\u7AEF\u70B92\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return std::optional<Vector<T,\
    \ 2>> \u5171\u6709\u70B9\u306E1\u4F8B (\u5171\u6709\u70B9\u304C\u306A\u3051\u308C\
    \u3070 std::nullopt)\n */\ntemplate <typename T>\nconstexpr std::optional<Vector<T,\
    \ 2>> segment_intersection(const Vector<T, 2>& p1, const Vector<T, 2>& p2, const\
    \ Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"segment_intersection: T must be a floating point type (use segments_intersect\
    \ for integers)\");\n    if (!segments_intersect(p1, p2, q1, q2)) return std::nullopt;\n\
    \    if (cross(p2 - p1, q1 - p1) == 0 && cross(p2 - p1, q2 - p1) == 0) {\n   \
    \     // 4\u70B9\u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\
    \n        if (dot(q1 - p1, q2 - p1) <= 0) return p1;\n        if (dot(q1 - p2,\
    \ q2 - p2) <= 0) return p2;\n        return q1;\n    }\n    T area = cross(p2\
    \ - p1, q2 - q1);          // 4\u70B9\u3092\u9802\u70B9\u3068\u3059\u308B\u56DB\
    \u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\u9762\u7A4D\n    T partial_area = cross(q2\
    \ - q1, p1 - q1);  // \u4E09\u89D2\u5F62q1q2p1\u306E\u7B26\u53F7\u4ED8\u304D\u9762\
    \u7A4D\n    return p1 + (p2 - p1) * partial_area / area;\n}\n\n/**\n * @brief\
    \ 3\u70B9\u306E\u4F4D\u7F6E\u95A2\u4FC2 (counter-clockwise)\n *\n * \u6574\u6570\
    \u578B\u3067\u3082\u4F7F\u3048\u308B\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\
    \u3067\u306F\u8AA4\u5DEE\u3092\u8003\u3048\u305A\u306B\u6BD4\u8F03\u3059\u308B\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @return int 1: a\u2192b\u2192\
    c \u304C\u53CD\u6642\u8A08\u56DE\u308A, -1: \u6642\u8A08\u56DE\u308A, 2: c, a,\
    \ b \u306E\u9806\u306B\u4E00\u76F4\u7DDA\u4E0A, -2: a, b, c \u306E\u9806\u306B\
    \u4E00\u76F4\u7DDA\u4E0A, 0: c \u304C\u7DDA\u5206 ab \u4E0A\n */\ntemplate <typename\
    \ T>\nconstexpr int ccw(const Vector<T, 2>& a, const Vector<T, 2>& b, const Vector<T,\
    \ 2>& c) {\n    Vector<T, 2> u = b - a, v = c - a;\n    T cr = cross(u, v);\n\
    \    if (cr > 0) return 1;\n    if (cr < 0) return -1;\n    if (dot(u, v) < 0)\
    \ return 2;\n    if (u.squared_norm() < v.squared_norm()) return -2;\n    return\
    \ 0;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u304C\u5E73\
    \u884C\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate\
    \ <typename T>\nconstexpr bool is_parallel(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>& q2) {\n    return cross(p2\
    \ - p1, q2 - q1) == 0;\n}\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA\
    \ q1q2 \u304C\u76F4\u4EA4\u3059\u308B\u304B (\u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B)\n */\ntemplate <typename T>\nconstexpr bool is_orthogonal(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    return dot(p2 - p1, q2 - q1) == 0;\n}\n\n/**\n * @brief \u70B9\
    \ p \u304B\u3089\u76F4\u7DDA p1p2 \u306B\u4E0B\u308D\u3057\u305F\u5782\u7DDA\u306E\
    \u8DB3 (\u5C04\u5F71)\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n\
    \ */\ntemplate <typename T>\nconstexpr Vector<T, 2> projection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& p) {\n    static_assert(std::is_floating_point_v<T>,\
    \ \"projection: T must be a floating point type\");\n    assert(p1 != p2 && \"\
    projection: degenerate line\");\n    Vector<T, 2> d = p2 - p1;\n    return p1\
    \ + d * (dot(p - p1, d) / d.squared_norm());\n}\n/**\n * @brief \u76F4\u7DDA p1p2\
    \ \u306B\u3064\u3044\u3066\u70B9 p \u3068\u5BFE\u79F0\u306A\u70B9 (\u53CD\u5C04\
    )\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n */\ntemplate <typename\
    \ T>\nconstexpr Vector<T, 2> reflection(const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2, const Vector<T, 2>& p) {\n    return projection(p1, p2, p) * T(2) -\
    \ p;\n}\n\n/**\n * @brief \u76F4\u7DDA p1p2 \u3068\u76F4\u7DDA q1q2 \u306E\u4EA4\
    \u70B9\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n * @return std::optional<Vector<T,\
    \ 2>> \u4EA4\u70B9 (\u5E73\u884C\u306A\u3089 std::nullopt)\n */\ntemplate <typename\
    \ T>\nconstexpr std::optional<Vector<T, 2>> line_intersection(const Vector<T,\
    \ 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T, 2>&\
    \ q2) {\n    static_assert(std::is_floating_point_v<T>, \"line_intersection: T\
    \ must be a floating point type\");\n    Vector<T, 2> d = p2 - p1, e = q2 - q1;\n\
    \    T c = cross(e, d);\n    if (c == 0) return std::nullopt;\n    // p1 + d t\
    \ \u304C\u76F4\u7DDA q1q2 \u4E0A\u306B\u3042\u308B t\n    return p1 + d * (cross(e,\
    \ q1 - p1) / c);\n}\n\n/**\n * @brief \u70B9 p \u3068\u76F4\u7DDA p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_line(const Vector<T, 2>& p1, const Vector<T, 2>& p2,\
    \ const Vector<T, 2>& p) {\n    assert(p1 != p2 && \"distance_point_line: degenerate\
    \ line\");\n    return std::abs(static_cast<double>(cross(p2 - p1, p - p1))) /\
    \ (p2 - p1).abs();\n}\n/**\n * @brief \u70B9 p \u3068\u7DDA\u5206 p1p2 \u306E\u8DDD\
    \u96E2 (\u6574\u6570\u578B\u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename\
    \ T>\ndouble distance_point_segment(const Vector<T, 2>& p1, const Vector<T, 2>&\
    \ p2, const Vector<T, 2>& p) {\n    if (p1 == p2) return (p - p1).abs();\n   \
    \ // \u5782\u7DDA\u306E\u8DB3\u304C\u7DDA\u5206\u306E\u5916\u306A\u3089\u3001\u8FD1\
    \u3044\u65B9\u306E\u7AEF\u70B9\u3068\u306E\u8DDD\u96E2\n    if (dot(p2 - p1, p\
    \ - p1) < 0) return (p - p1).abs();\n    if (dot(p1 - p2, p - p2) < 0) return\
    \ (p - p2).abs();\n    return distance_point_line(p1, p2, p);\n}\n/**\n * @brief\
    \ \u7DDA\u5206 p1p2 \u3068\u7DDA\u5206 q1q2 \u306E\u8DDD\u96E2 (\u6574\u6570\u578B\
    \u3067\u3082\u4F7F\u3048\u308B)\n */\ntemplate <typename T>\ndouble distance_segments(const\
    \ Vector<T, 2>& p1, const Vector<T, 2>& p2, const Vector<T, 2>& q1, const Vector<T,\
    \ 2>& q2) {\n    if (p1 != p2 && q1 != q2 && segments_intersect(p1, p2, q1, q2))\
    \ return 0;\n    return std::min({distance_point_segment(p1, p2, q1), distance_point_segment(p1,\
    \ p2, q2),\n                     distance_point_segment(q1, q2, p1), distance_point_segment(q1,\
    \ q2, p2)});\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u4ED8\u304D\
    \u9762\u7A4D\u306E2\u500D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param\
    \ polygon \u9802\u70B9\u306E\u5EA7\u6A19\n * @return T \u9762\u7A4D\u306E2\u500D\
    (\u53CD\u6642\u8A08\u56DE\u308A\u306A\u3089\u6B63\u3001\u6642\u8A08\u56DE\u308A\
    \u306A\u3089\u8CA0)\n */\ntemplate <typename T>\nT polygon_area_doubled(const\
    \ std::vector<Vector<T, 2>>& polygon) {\n    T ret = 0;\n    for (int i = 0; i\
    \ < static_cast<int>(polygon.size()); i++) {\n        int j = i + 1;\n       \
    \ if (j == static_cast<int>(polygon.size())) j = 0;\n        ret += cross(polygon[i],\
    \ polygon[j]);\n    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\
    \u306E\u9762\u7A4D\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon\
    \ \u9802\u70B9\u306E\u5EA7\u6A19(\u9806\u756A\u3001\u53CD\u6642\u8A08\u56DE\u308A\
    \u304B\u6642\u8A08\u56DE\u308A\u304B\u306F\u554F\u308F\u306A\u3044)\n * @return\
    \ double \u9762\u7A4D\n */\ntemplate <typename T>\ndouble polygon_area(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    return std::abs(polygon_area_doubled(polygon)) / 2.;\n\
    }\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u6027\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return true \u51F8\n * @return false \u51F9\
    \n */\ntemplate <typename T>\nbool polygon_is_convex(const std::vector<Vector<T,\
    \ 2>>& polygon) {\n    int n = polygon.size();\n    for (int i = 0; i < n; i++)\
    \ {\n        int j = i + 1;\n        if (j == n) j = 0;\n        int k = j + 1;\n\
    \        if (k == n) k = 0;\n        if (cross(polygon[j] - polygon[i], polygon[k]\
    \ - polygon[j]) < 0) return false;\n    }\n    return true;\n}\n\n/**\n * @brief\
    \ \u70B9\u306E\u591A\u89D2\u5F62\u5185\u5305\u542B\u5224\u5B9A\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u9802\u70B9\u306E\u5EA7\u6A19\
    (\u53CD\u6642\u8A08\u56DE\u308A)\n * @param p \u70B9\u306E\u5EA7\u6A19\n * @return\
    \ int 0: \u5916\u90E8, 1: \u8FBA\u4E0A, 2: \u5185\u90E8\n */\ntemplate <typename\
    \ T>\nint polygon_contains(const std::vector<Vector<T, 2>>& polygon, const Vector<T,\
    \ 2>& p) {\n    bool in = false;\n    for (int i = 0; i < static_cast<int>(polygon.size());\
    \ i++) {\n        int j = i + 1;\n        if (j == static_cast<int>(polygon.size()))\
    \ j = 0;\n        Vector<T> v1 = polygon[i] - p, v2 = polygon[j] - p;\n      \
    \  if (v1[1] > v2[1]) std::swap(v1, v2);\n        T c = cross(v1, v2);\n     \
    \   if (v1[1] <= 0 && v2[1] > 0 && c < 0) in = !in;\n        if (c == 0 && dot(v1,\
    \ v2) <= 0) return 1;\n    }\n    return in ? 2 : 0;\n}\n\n/**\n * @brief \u591A\
    \u89D2\u5F62\u306E\u534A\u51F8\u5305\n * \u4E0E\u3048\u3089\u308C\u305F\u9802\u70B9\
    \u30EA\u30B9\u30C8\u306E\u9806\u756A\u3092\u4FDD\u3063\u3066\u53CD\u6642\u8A08\
    \u56DE\u308A\u306B\u51F8\u5305\u3092\u69CB\u6210\u3059\u308B\n * x\u306E\u6607\
    \u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\u308C\u3070\u4E0B\u51F8\
    \u5305\u3001x\u306E\u964D\u9806\u306B\u30BD\u30FC\u30C8\u3055\u308C\u3066\u3044\
    \u308C\u3070\u4E0A\u51F8\u5305\u304C\u5F97\u3089\u308C\u308B\n *\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n\
    \ * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\u70B9\u3092\
    \u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T, 2>> \u534A\
    \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\u308A\
    )\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> select_convex(const std::vector<Vector<T,\
    \ 2>>& points, bool include_straight = false) {\n    std::vector<Vector<T, 2>>\
    \ ret;\n    for (auto& p : points) {\n        while (static_cast<int>(ret.size())\
    \ >= 2) {\n            T c = cross(ret.back() - ret[static_cast<int>(ret.size())\
    \ - 2], p - ret.back());\n            if (c > 0 || (c == 0 && include_straight))\
    \ break;\n            ret.pop_back();\n        }\n        ret.push_back(p);\n\
    \    }\n    return ret;\n}\n\n/**\n * @brief \u591A\u89D2\u5F62\u306E\u51F8\u5305\
    \n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\
    \u30B9\u30C8\n * @param include_straight \u5185\u89D2\u304C180\u5EA6\u306E\u9802\
    \u70B9\u3092\u542B\u3080\u304B\u3069\u3046\u304B\n * @return std::vector<Vector<T,\
    \ 2>> \u51F8\u5305\u306E\u9802\u70B9\u306E\u5EA7\u6A19(\u53CD\u6642\u8A08\u56DE\
    \u308A)\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_hull(const\
    \ std::vector<Vector<T, 2>>& _points, bool include_straight = false) {\n    std::vector<Vector<T,\
    \ 2>> points = _points;\n    std::sort(points.begin(), points.end());\n    points.erase(std::unique(points.begin(),\
    \ points.end()), points.end());\n    std::vector<Vector<T, 2>> ret = select_convex(points,\
    \ include_straight);\n    std::reverse(points.begin(), points.end());\n    std::vector<Vector<T,\
    \ 2>> tmp = select_convex(points, include_straight);\n    // \u5168\u70B9\u304C\
    \u4E00\u76F4\u7DDA\u4E0A\u306B\u3042\u308B\u5834\u5408\u3001\u4E0B\u5074\u3068\
    \u4E0A\u5074\u304C\u540C\u3058\u70B9\u5217\u306B\u306A\u308B\u306E\u3067\u7247\
    \u65B9\u3060\u3051\u4F7F\u3046\n    if (ret.size() == points.size() && tmp.size()\
    \ == points.size()) return ret;\n    for (int i = 1; i < static_cast<int>(tmp.size())\
    \ - 1; i++) ret.push_back(tmp[i]);\n    return ret;\n}\n\n/**\n * @brief closest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct ClosestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief closest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct ClosestPair\
    \ {\n    double dist;     //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u8FD1\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\u578B\
    \n * @param points \u9802\u70B9\u30EA\u30B9\u30C8\n * @return ClosestPairSquared<T>\
    \ \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57\n\
    \ */\ntemplate <typename T>\nClosestPairSquared<T> closest_point_pair_squared(const\
    \ std::vector<Vector<T, 2>>& points) {\n    std::vector<int> sorted_idx(points.size());\n\
    \    std::iota(sorted_idx.begin(), sorted_idx.end(), 0);\n    std::sort(sorted_idx.begin(),\
    \ sorted_idx.end(), [&](int i, int j) {\n        return points[i][0] < points[j][0];\n\
    \    });\n    std::vector<int> left(1, 0);                                   \
    \     // \u5DE6\u7AEF\n    std::vector<int> right(1, points.size());         \
    \                  // \u53F3\u7AEF\n    std::vector<int> mid(1, points.size()\
    \ / 2);                         // \u4E2D\u592E\n    std::vector<int> par(1, -1);\
    \                                        // \u89AA\n    std::vector<T> min_dist_squared(1,\
    \ std::numeric_limits<T>::max());  // \u6700\u5C0F\u8DDD\u96E2\u306E2\u4E57\n\
    \    std::vector<std::pair<int, int>> min_dist_pair(1, {-1, -1});        // \u6700\
    \u5C0F\u8DDD\u96E2\u306E\u70B9\u5BFE\n    std::stack<int> stk;\n    stk.push(~0);\n\
    \    stk.push(0);\n    while (!stk.empty()) {\n        int u = stk.top();\n  \
    \      stk.pop();\n        if (u >= 0) {\n            // \u884C\u304D\u304C\u3051\
    \n            if (left[u] + 1 < mid[u]) {\n                int v = left.size();\n\
    \                left.push_back(left[u]);\n                right.push_back(mid[u]);\n\
    \                mid.push_back((left[u] + mid[u]) / 2);\n                par.push_back(u);\n\
    \                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n            if (mid[u] + 1 < right[u])\
    \ {\n                int v = left.size();\n                left.push_back(mid[u]);\n\
    \                right.push_back(right[u]);\n                mid.push_back((mid[u]\
    \ + right[u]) / 2);\n                par.push_back(u);\n                min_dist_squared.push_back(std::numeric_limits<T>::max());\n\
    \                min_dist_pair.push_back({-1, -1});\n                stk.push(~v);\n\
    \                stk.push(v);\n            }\n        } else {\n            //\
    \ \u5E30\u308A\u304C\u3051\n            u = ~u;\n            std::vector<int>\
    \ cand;\n            for (int i = left[u]; i < right[u]; i++) {\n            \
    \    T dx = points[sorted_idx[i]][0] - points[sorted_idx[mid[u]]][0];\n      \
    \          if (dx * dx < min_dist_squared[u]) cand.push_back(i);\n           \
    \ }\n            std::sort(cand.begin(), cand.end(), [&](int i, int j) {\n   \
    \             return points[sorted_idx[i]][1] < points[sorted_idx[j]][1];\n  \
    \          });\n            for (int i = 0; i < static_cast<int>(cand.size());\
    \ i++) {\n                for (int j = i + 1; j < static_cast<int>(cand.size());\
    \ j++) {\n                    T dx = points[sorted_idx[cand[j]]][0] - points[sorted_idx[cand[i]]][0];\n\
    \                    T dy = points[sorted_idx[cand[j]]][1] - points[sorted_idx[cand[i]]][1];\n\
    \                    if (dy * dy >= min_dist_squared[u]) break;\n            \
    \        T d = dx * dx + dy * dy;\n                    if (d < min_dist_squared[u])\
    \ {\n                        min_dist_squared[u] = d;\n                      \
    \  min_dist_pair[u] = {sorted_idx[cand[i]], sorted_idx[cand[j]]};\n          \
    \          }\n                }\n            }\n            if (par[u] != -1 &&\
    \ min_dist_squared[u] < min_dist_squared[par[u]]) {\n                min_dist_squared[par[u]]\
    \ = min_dist_squared[u];\n                min_dist_pair[par[u]] = min_dist_pair[u];\n\
    \            }\n        }\n    }\n    return {min_dist_squared[0], min_dist_pair[0].first,\
    \ min_dist_pair[0].second};\n}\n\n/**\n * @brief \u6700\u8FD1\u70B9\u5BFE\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\
    \u30C8\n * @return ClosestPair \u6700\u8FD1\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\
    \u6DFB\u5B57\n */\ntemplate <typename T>\nClosestPair closest_point_pair(const\
    \ std::vector<Vector<T, 2>>& points) {\n    auto [d2, i, j] = closest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief farthest_point_pair_squared\
    \ \u306E\u623B\u308A\u5024\n */\ntemplate <typename T>\nstruct FarthestPairSquared\
    \ {\n    T squared_dist;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u306E\
    2\u4E57\n    long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n\
    };\n/**\n * @brief farthest_point_pair \u306E\u623B\u308A\u5024\n */\nstruct FarthestPair\
    \ {\n    double dist;     //!< \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\n  \
    \  long long i, j;  //!< \u6700\u9060\u70B9\u5BFE\u306E\u6DFB\u5B57\n};\n\n/**\n\
    \ * @brief \u6700\u9060\u70B9\u5BFE (\u51F8\u5305\u3092\u4F5C\u308A\u3001\u56DE\
    \u8EE2\u30AD\u30E3\u30EA\u30D1\u30FC\u6CD5\u3067\u5BFE\u8E60\u70B9\u306E\u7D44\
    \u3092\u8ABF\u3079\u308B) O(n log n)\n *\n * \u6574\u6570\u578B\u3067\u3082\u4F7F\
    \u3048\u308B\u3002\u5EA7\u6A19\u306E\u5DEE\u306E2\u4E57\u306E\u548C\u306E2\u500D\
    \u304C T \u306B\u53CE\u307E\u308B\u5FC5\u8981\u304C\u3042\u308B\n * @tparam T\
    \ \u5EA7\u6A19\u306E\u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\
    \u4EE5\u4E0A)\n * @return FarthestPairSquared<T> \u6700\u9060\u70B9\u5BFE\u306E\
    \u8DDD\u96E2\u306E2\u4E57\u3068\u6DFB\u5B57 (i != j)\n */\ntemplate <typename\
    \ T>\nFarthestPairSquared<T> farthest_point_pair_squared(const std::vector<Vector<T,\
    \ 2>>& points) {\n    const int n = static_cast<int>(points.size());\n    assert(n\
    \ >= 2);\n    // \u51F8\u5305\u306E\u9802\u70B9\u3092\u3001\u3082\u3068\u306E\u6DFB\
    \u5B57\u306B\u623B\u305B\u308B\u3088\u3046\u306B\u3057\u3066\u304A\u304F\n   \
    \ std::vector<std::pair<Vector<T, 2>, int>> sorted(n);\n    for (int i = 0; i\
    \ < n; i++) sorted[i] = {points[i], i};\n    std::sort(sorted.begin(), sorted.end());\n\
    \    auto index_of = [&](const Vector<T, 2>& p) {\n        return std::lower_bound(sorted.begin(),\
    \ sorted.end(), std::make_pair(p, -1))->second;\n    };\n    std::vector<Vector<T,\
    \ 2>> hull = convex_hull(points);\n    const int k = static_cast<int>(hull.size());\n\
    \    if (k == 1) return {T(0), sorted[0].second, sorted[1].second};  // \u3059\
    \u3079\u3066\u540C\u3058\u70B9\n    FarthestPairSquared<T> res{T(0), -1, -1};\n\
    \    auto update = [&](int a, int b) {\n        T d = (hull[a] - hull[b]).squared_norm();\n\
    \        if (res.i == -1 || d > res.squared_dist) res = {d, a, b};\n    };\n \
    \   if (k == 2) {\n        update(0, 1);\n    } else {\n        // \u8FBA i\u2192\
    i+1 \u306B\u5BFE\u3057\u3066\u3001\u6700\u3082\u9060\u3044\u9802\u70B9 j \u3092\
    \u53CD\u6642\u8A08\u56DE\u308A\u306B\u9032\u3081\u3066\u3044\u304F\n        int\
    \ j = 1;\n        for (int i = 0; i < k; i++) {\n            int ni = i + 1 ==\
    \ k ? 0 : i + 1;\n            while (true) {\n                int nj = j + 1 ==\
    \ k ? 0 : j + 1;\n                if (cross(hull[ni] - hull[i], hull[nj] - hull[j])\
    \ > 0)\n                    j = nj;\n                else\n                  \
    \  break;\n            }\n            update(i, j);\n            update(ni, j);\n\
    \        }\n    }\n    return {res.squared_dist, index_of(hull[res.i]), index_of(hull[res.j])};\n\
    }\n\n/**\n * @brief \u6700\u9060\u70B9\u5BFE\n *\n * @tparam T \u5EA7\u6A19\u306E\
    \u578B\n * @param points \u9802\u70B9\u30EA\u30B9\u30C8 (2\u500B\u4EE5\u4E0A)\n\
    \ * @return FarthestPair \u6700\u9060\u70B9\u5BFE\u306E\u8DDD\u96E2\u3068\u6DFB\
    \u5B57\n */\ntemplate <typename T>\nFarthestPair farthest_point_pair(const std::vector<Vector<T,\
    \ 2>>& points) {\n    auto [d2, i, j] = farthest_point_pair_squared(points);\n\
    \    return {std::sqrt(static_cast<double>(d2)), i, j};\n}\n\n/**\n * @brief \u51F8\
    \u591A\u89D2\u5F62\u3092\u76F4\u7DDA p1p2 \u3067\u5207\u308A\u3001\u76F4\u7DDA\
    \u306E\u5DE6\u5074 (p1 \u304B\u3089 p2 \u3092\u898B\u3066\u5DE6) \u306E\u90E8\u5206\
    \u3092\u8FD4\u3059\u3002\u6D6E\u52D5\u5C0F\u6570\u70B9\u578B\u9650\u5B9A\n *\n\
    \ * @tparam T \u5EA7\u6A19\u306E\u578B\n * @param polygon \u51F8\u591A\u89D2\u5F62\
    \u306E\u9802\u70B9\u306E\u5EA7\u6A19 (\u53CD\u6642\u8A08\u56DE\u308A)\n * @return\
    \ std::vector<Vector<T, 2>> \u5DE6\u5074\u306E\u51F8\u591A\u89D2\u5F62\u306E\u9802\
    \u70B9 (\u53CD\u6642\u8A08\u56DE\u308A)\u3002\u76F4\u7DDA\u4E0A\u306E\u9802\u70B9\
    \u3082\u542B\u3080\u3002\u5DE6\u5074\u306B\u4F55\u3082\u306A\u3051\u308C\u3070\
    \u7A7A\n */\ntemplate <typename T>\nstd::vector<Vector<T, 2>> convex_cut(const\
    \ std::vector<Vector<T, 2>>& polygon, const Vector<T, 2>& p1, const Vector<T,\
    \ 2>& p2) {\n    static_assert(std::is_floating_point_v<T>, \"convex_cut: T must\
    \ be a floating point type\");\n    std::vector<Vector<T, 2>> res;\n    const\
    \ int n = static_cast<int>(polygon.size());\n    for (int i = 0; i < n; i++) {\n\
    \        const Vector<T, 2>&a = polygon[i], &b = polygon[i + 1 == n ? 0 : i +\
    \ 1];\n        T ca = cross(p2 - p1, a - p1), cb = cross(p2 - p1, b - p1);\n \
    \       if (ca >= 0) res.push_back(a);\n        // \u8FBA ab \u304C\u76F4\u7DDA\
    \u3092\u307E\u305F\u3050\u306A\u3089\u3001\u4EA4\u70B9\u3092\u5165\u308C\u308B\
    \n        if ((ca > 0 && cb < 0) || (ca < 0 && cb > 0)) res.push_back(a + (b -\
    \ a) * (ca / (ca - cb)));\n    }\n    return res;\n}\n/**\n * @deprecated closest_point_pair_squared\
    \ \u3092\u4F7F\u3046\u3053\u3068(\u7DB4\u308A\u306E\u8AA4\u308A\u3092\u76F4\u3057\
    \u3066\u6539\u540D\u3057\u305F)\n */\ntemplate <typename T>\n[[deprecated(\"use\
    \ closest_point_pair_squared\")]] ClosestPairSquared<T> closest_point_pair_squred(const\
    \ std::vector<Vector<T, 2>>& points) {\n    return closest_point_pair_squared(points);\n\
    }\n#line 15 \"src/geometry/manhattan-mst.hpp\"\n\n/**\n * @brief \u70B9\u306E\u96C6\
    \u5408\u3067\u30012 \u70B9\u3092\u7D50\u3076\u8FBA\u306E\u91CD\u307F\u3092\u30DE\
    \u30F3\u30CF\u30C3\u30BF\u30F3\u8DDD\u96E2 |dx| + |dy| \u3068\u3057\u305F\u5B8C\
    \u5168\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6728 O(n log n)\n *\n\
    \ * \u5404\u70B9 i \u306B\u3064\u3044\u3066\u3001i \u3092\u9802\u70B9\u3068\u3059\
    \u308B 45 \u5EA6\u305A\u3064\u306E 8 \u3064\u306E\u9818\u57DF\u306E\u305D\u308C\
    \u305E\u308C\u3067\u6700\u3082\u8FD1\u3044\u70B9\u3078\u306E\u8FBA\u3060\u3051\
    \u3092\u5019\u88DC\u306B\u3059\u308C\u3070\u3088\u3044\u3002\n * \u5411\u304D\u3092\
    \u5909\u3048\u306A\u304C\u3089 4 \u56DE\u6383\u3044\u3066 O(n) \u672C\u306E\u5019\
    \u88DC\u3092\u4F5C\u308A\u3001Kruskal \u6CD5\u306B\u304B\u3051\u308B\n * @return\
    \ \u6700\u5C0F\u5168\u57DF\u6728 (\u8FBA\u306E src\u3001dst \u306F\u70B9\u306E\
    \u756A\u53F7\u3001cost \u306F\u8DDD\u96E2)\n */\ntemplate <typename T>\nMinimumSpanningTree<T>\
    \ manhattan_mst(std::vector<Vector<T, 2>> p) {\n    const long long n = p.size();\n\
    \    Graph<T> g(n);\n    std::vector<long long> id(n);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n    for (int k = 0; k < 4; k++) {\n        // x + y \u306E\u6607\
    \u9806\u306B\u898B\u3066\u3001x - y \u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u4E2D\u3067 y \u304C\u8FD1\u3044\u70B9\u3092 map \u304B\u3089\u53D6\u308A\u51FA\
    \u3059\n        std::sort(id.begin(), id.end(), [&](long long i, long long j)\
    \ { return p[i][0] + p[i][1] < p[j][0] + p[j][1]; });\n        std::map<T, long\
    \ long> sweep;  // -y -> \u70B9\n        for (long long i : id) {\n          \
    \  for (auto it = sweep.lower_bound(-p[i][1]); it != sweep.end(); it = sweep.erase(it))\
    \ {\n                const long long j = it->second;\n                const T\
    \ dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];\n                if (dy > dx)\
    \ break;\n                g.add_edge(i, j, dx + dy);\n            }\n        \
    \    sweep[-p[i][1]] = i;\n        }\n        // 4 \u3064\u306E\u5411\u304D: (x,\
    \ y) -> (y, x) -> (-y, x) -> (x, -y) \u3068\u5909\u3048\u308B\n        for (auto&\
    \ v : p) {\n            if (k % 2 == 0) {\n                std::swap(v[0], v[1]);\n\
    \            } else {\n                v[0] = -v[0];\n            }\n        }\n\
    \    }\n    return minimum_spanning_tree(g);\n}\n#line 7 \"test/yosupo/geo/manhattanmst.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<Vector<long long, 2>> p(n);\n\
    \    for (auto& v : p) std::cin >> v[0] >> v[1];\n    auto mst = manhattan_mst(p);\n\
    \    std::cout << mst.cost << '\\n';\n    for (const auto& e : mst.edges) std::cout\
    \ << e.src << ' ' << e.dst << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#include \"../../../src/geometry/manhattan-mst.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<Vector<long long, 2>> p(n);\n\
    \    for (auto& v : p) std::cin >> v[0] >> v[1];\n    auto mst = manhattan_mst(p);\n\
    \    std::cout << mst.cost << '\\n';\n    for (const auto& e : mst.edges) std::cout\
    \ << e.src << ' ' << e.dst << '\\n';\n}\n"
  dependsOn:
  - src/geometry/manhattan-mst.hpp
  - src/graph/graph_util.hpp
  - src/data_structures/unionfind.hpp
  - src/graph/graph.hpp
  - src/geometry/vector.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/yosupo/geo/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 19:52:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/geo/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/geo/manhattanmst.test.cpp
- /verify/test/yosupo/geo/manhattanmst.test.cpp.html
title: test/yosupo/geo/manhattanmst.test.cpp
---
