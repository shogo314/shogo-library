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
    path: src/graph/graph_util.hpp
    title: "\u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\u95A2\u6570"
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
  bundledCode: "#line 1 \"test/yosupo/graph/enumerate-triangles.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"src/graph/graph_util.hpp\"\n\n/**\n\
    \ * @file graph_util.hpp\n * @brief \u30B0\u30E9\u30D5\u306B\u95A2\u3059\u308B\
    \u95A2\u6570\n */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <limits>\n#include <optional>\n#include <queue>\n#include <stack>\n#include\
    \ <utility>\n#line 17 \"src/graph/graph_util.hpp\"\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
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
    \ = e;\n            }\n        }\n        return res;\n    }\n};\n#line 20 \"\
    src/graph/graph_util.hpp\"\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\
    \u3064\u3044\u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\u30890\u30681\u306B\
    \u5F69\u8272\u3057\u305F\u7D50\u679C\u3092\u3072\u3068\u3064\u8FD4\u3057\u3001\
    \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089std::nullopt\u3092\
    \u8FD4\u3059\u3002\n * \u9023\u7D50\u6210\u5206\u306E\u3046\u3061\u3001\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306E\u6700\u3082\u5C0F\u3055\u3044\u3082\u306E\u3092\
    0\u306B\u3059\u308B\u3002\n * @return std::optional<std::vector<int>> \u5404\u9802\
    \u70B9\u306E\u5F69\u8272\u7D50\u679C\n */\ntemplate <typename Cost = long long>\n\
    std::optional<std::vector<int>> bipartite_coloring(const Graph<Cost>& graph) {\n\
    \    std::vector<int> color(graph.n, -1);\n    for (long long i = 0; i < graph.n;\
    \ i++) {\n        if (color[i] != -1) continue;\n        std::stack<long long>\
    \ stk;\n        stk.push(i);\n        color[i] = 0;\n        while (!stk.empty())\
    \ {\n            long long u = stk.top();\n            stk.pop();\n          \
    \  for (long long v : graph[u]) {\n                if (color[v] == -1) {\n   \
    \                 color[v] = color[u] ^ 1;\n                    stk.push(v);\n\
    \                } else {\n                    if (color[u] == color[v]) return\
    \ std::nullopt;\n                }\n            }\n        }\n    }\n    return\
    \ color;\n}\n\n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\
    \u3066\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u304B\u3069\u3046\u304B\u3092\u5224\
    \u5B9A\u3059\u308B\u3002\n * @return bool \u4E8C\u90E8\u30B0\u30E9\u30D5\u306A\
    \u3089true\u3001\u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u3044\u306A\u3089false\u3092\
    \u8FD4\u3059\u3002\n */\ntemplate <typename Cost = long long>\nbool is_bipartite(const\
    \ Graph<Cost>& graph) {\n    return bipartite_coloring(graph).has_value();\n}\n\
    \n/**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u9023\
    \u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\u3002\n * @return std::vector<std::vector<long\
    \ long>> \u300C\u540C\u3058\u9023\u7D50\u6210\u5206\u3068\u306A\u308B\u9802\u70B9\
    \u306E\u30EA\u30B9\u30C8\u300D\u306E\u30EA\u30B9\u30C8\n */\ntemplate <typename\
    \ Cost = long long>\nstd::vector<std::vector<long long>> connected_components(const\
    \ Graph<Cost>& graph) {\n    std::vector<std::vector<long long>> groups;\n   \
    \ std::vector<bool> visited(graph.n);\n    for (long long i = 0; i < graph.n;\
    \ i++) {\n        if (visited[i]) continue;\n        std::stack<long long> stk;\n\
    \        stk.push(i);\n        visited[i] = true;\n        groups.push_back({i});\n\
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
    \ res.end()), res.end());\n    return res;\n}\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line\
    \ 9 \"src/math/modint.hpp\"\n#include <cstdint>\n#line 12 \"src/math/modint.hpp\"\
    \n#include <type_traits>\n#line 14 \"src/math/modint.hpp\"\n\n#line 2 \"src/utility/traits.hpp\"\
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
    using modint = dynamic_modint<-1>;\n#line 8 \"test/yosupo/graph/enumerate-triangles.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint>\
    \ x(n);\n    for (auto& v : x) std::cin >> v;\n    Graph<int> g(n);\n    g.read(m,\
    \ 0);\n    mint ans = 0;\n    enumerate_triangles(g, [&](long long a, long long\
    \ b, long long c) { ans += x[a] * x[b] * x[c]; });\n    std::cout << ans << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../../src/graph/graph_util.hpp\"\
    \n#include \"../../../src/math/modint.hpp\"\n\nusing mint = modint998244353;\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector<mint> x(n);\n    for\
    \ (auto& v : x) std::cin >> v;\n    Graph<int> g(n);\n    g.read(m, 0);\n    mint\
    \ ans = 0;\n    enumerate_triangles(g, [&](long long a, long long b, long long\
    \ c) { ans += x[a] * x[b] * x[c]; });\n    std::cout << ans << '\\n';\n}\n"
  dependsOn:
  - src/graph/graph_util.hpp
  - src/data_structures/unionfind.hpp
  - src/graph/graph.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/yosupo/graph/enumerate-triangles.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/enumerate-triangles.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/enumerate-triangles.test.cpp
- /verify/test/yosupo/graph/enumerate-triangles.test.cpp.html
title: test/yosupo/graph/enumerate-triangles.test.cpp
---
