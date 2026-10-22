---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  - icon: ':heavy_check_mark:'
    path: src/graph/minimum-arborescence.hpp
    title: "\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/directedmst
    links:
    - https://judge.yosupo.jp/problem/directedmst
  bundledCode: "#line 1 \"test/yosupo/graph/directedmst.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include <iostream>\n\n#line\
    \ 2 \"src/graph/minimum-arborescence.hpp\"\n\n/**\n * @file minimum-arborescence.hpp\n\
    \ * @brief \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\n */\n\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n\
    \ * @file graph.hpp\n * @brief \u30B0\u30E9\u30D5\n */\n\n#include <cassert>\n\
    #line 11 \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\
    \u7528\u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\
    \u578B \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\
    \u672A\u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\
    \u3044\u3088\u3046\u306B)\n */\ntemplate <typename Cost = long long>\nclass Graph\
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
    \    return res;\n    }\n};\n#line 13 \"src/graph/minimum-arborescence.hpp\"\n\
    \nnamespace internal_minimum_arborescence {\n\n/**\n * @brief \u5168\u4F53\u3078\
    \u306E\u52A0\u7B97\u304C\u3067\u304D\u308B leftist heap (\u30CE\u30FC\u30C9\u306F\
    \u6DFB\u5B57\u3067\u6301\u3064)\n */\ntemplate <typename Cost>\nclass LeftistHeap\
    \ {\n   public:\n    int make(Cost key, long long value) {\n        nodes.push_back({key,\
    \ Cost{}, value, -1, -1, 1});\n        return static_cast<int>(nodes.size()) -\
    \ 1;\n    }\n    int merge(int a, int b) {\n        if (a == -1) return b;\n \
    \       if (b == -1) return a;\n        push(a), push(b);\n        if (nodes[b].key\
    \ < nodes[a].key) std::swap(a, b);\n        nodes[a].r = merge(nodes[a].r, b);\n\
    \        if (rank(nodes[a].l) < rank(nodes[a].r)) std::swap(nodes[a].l, nodes[a].r);\n\
    \        nodes[a].rank = rank(nodes[a].r) + 1;\n        return a;\n    }\n   \
    \ std::pair<Cost, long long> top(int a) {\n        push(a);\n        return {nodes[a].key,\
    \ nodes[a].value};\n    }\n    int pop(int a) {\n        push(a);\n        return\
    \ merge(nodes[a].l, nodes[a].r);\n    }\n    void add(int a, Cost x) { nodes[a].lazy\
    \ += x; }\n\n   private:\n    struct Node {\n        Cost key, lazy;\n       \
    \ long long value;\n        int l, r, rank;\n    };\n    std::vector<Node> nodes;\n\
    \    int rank(int a) const { return a == -1 ? 0 : nodes[a].rank; }\n    void push(int\
    \ a) {\n        if (nodes[a].lazy == Cost{}) return;\n        nodes[a].key +=\
    \ nodes[a].lazy;\n        if (nodes[a].l != -1) nodes[nodes[a].l].lazy += nodes[a].lazy;\n\
    \        if (nodes[a].r != -1) nodes[nodes[a].r].lazy += nodes[a].lazy;\n    \
    \    nodes[a].lazy = Cost{};\n    }\n};\n\n/**\n * @brief \u5DFB\u304D\u623B\u3057\
    \u306E\u3067\u304D\u308B Union-Find (\u7D4C\u8DEF\u5727\u7E2E\u3092\u3057\u306A\
    \u3044)\n */\nclass RollbackUnionFind {\n   public:\n    explicit RollbackUnionFind(long\
    \ long n) : parent_or_size(n, -1) {}\n    long long find(long long x) const {\n\
    \        while (parent_or_size[x] >= 0) x = parent_or_size[x];\n        return\
    \ x;\n    }\n    bool merge(long long x, long long y) {\n        x = find(x),\
    \ y = find(y);\n        if (x == y) return false;\n        if (parent_or_size[x]\
    \ > parent_or_size[y]) std::swap(x, y);\n        history.push_back({x, parent_or_size[x]});\n\
    \        history.push_back({y, parent_or_size[y]});\n        parent_or_size[x]\
    \ += parent_or_size[y];\n        parent_or_size[y] = x;\n        return true;\n\
    \    }\n    long long time() const { return static_cast<long long>(history.size());\
    \ }\n    void rollback(long long t) {\n        while (time() > t) {\n        \
    \    parent_or_size[history.back().first] = history.back().second;\n         \
    \   history.pop_back();\n        }\n    }\n\n   private:\n    std::vector<long\
    \ long> parent_or_size;\n    std::vector<std::pair<long long, long long>> history;\n\
    };\n\n}  // namespace internal_minimum_arborescence\n\n/**\n * @brief \u6700\u5C0F\
    \u5168\u57DF\u6709\u5411\u6728\u306E\u7D50\u679C\n */\ntemplate <typename Cost>\n\
    struct MinimumArborescence {\n    Cost cost;                                 \
    \           //!< \u4F7F\u3063\u305F\u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u7DCF\u548C\
    \n    std::vector<typename Graph<Cost>::Edge> parent_edge;  //!< \u89AA\u304B\u3089\
    \ v \u306B\u5165\u308B\u8FBA (\u6839\u3067\u306F src == -1)\n};\n\n/**\n * @brief\
    \ \u6709\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\
    \ (root \u3092\u6839\u3068\u3057\u3001root \u304B\u3089\u5168\u9802\u70B9\u3078\
    \u5230\u9054\u3067\u304D\u308B\u5168\u57DF\u6728\u3067\u3001\u8FBA\u306E\u30B3\
    \u30B9\u30C8\u306E\u7DCF\u548C\u304C\u6700\u5C0F\u306E\u3082\u306E)\n *\n * Chu-Liu/Edmonds\
    \ \u6CD5\u3092 leftist heap \u3068\u5DFB\u304D\u623B\u3057\u306E\u3067\u304D\u308B\
    \ Union-Find \u3067 O(m log m) \u306B\u3057\u305F\u3082\u306E\n * @param root\
    \ \u6839\n * @return std::optional<MinimumArborescence<Cost>> root \u304B\u3089\
    \u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\u304C\u3042\u308C\u3070 std::nullopt\n\
    \ * @note \u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u8FBA\u304C\u3042\u3063\u3066\u3082\
    \u3088\u3044\u3002\u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u591A\u91CD\u8FBA\u304C\
    \u3042\u3063\u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost = long long>\n\
    std::optional<MinimumArborescence<Cost>> minimum_arborescence(const Graph<Cost>&\
    \ graph, long long root) {\n    using Edge = typename Graph<Cost>::Edge;\n   \
    \ const long long n = graph.n;\n    std::vector<Edge> es;\n    for (long long\
    \ v = 0; v < n; v++) {\n        for (const auto& e : graph[v]) es.push_back(e);\n\
    \    }\n    internal_minimum_arborescence::LeftistHeap<Cost> heap;\n    internal_minimum_arborescence::RollbackUnionFind\
    \ uf(n);\n    std::vector<int> top(n, -1);  // \u5404\u6210\u5206\u306B\u5165\u308B\
    \u8FBA\u306E\u30D2\u30FC\u30D7\n    for (long long i = 0; i < static_cast<long\
    \ long>(es.size()); i++) {\n        top[es[i].dst] = heap.merge(top[es[i].dst],\
    \ heap.make(es[i].cost, i));\n    }\n    struct Cycle {\n        long long u,\
    \ time;\n        std::vector<long long> edges;\n    };\n    std::vector<Cycle>\
    \ cycles;\n    Cost cost{};\n    std::vector<long long> seen(n, -1), path(n),\
    \ queue(n), in(n, -1);\n    seen[root] = root;\n    for (long long s = 0; s <\
    \ n; s++) {\n        long long u = s, qi = 0;\n        // s \u304B\u3089\u5165\
    \u308B\u8FBA\u3092\u9006\u306B\u305F\u3069\u308A\u3001\u9589\u8DEF\u304C\u3067\
    \u304D\u305F\u3089 1 \u3064\u306E\u9802\u70B9\u306B\u7E2E\u3081\u308B\n      \
    \  while (seen[u] < 0) {\n            if (top[u] == -1) return std::nullopt;\n\
    \            auto [w, i] = heap.top(top[u]);\n            heap.add(top[u], -w);\n\
    \            top[u] = heap.pop(top[u]);\n            queue[qi] = i, path[qi++]\
    \ = u, seen[u] = s;\n            cost += w;\n            u = uf.find(es[i].src);\n\
    \            if (seen[u] == s) {\n                int cycle = -1;\n          \
    \      long long end = qi, time = uf.time(), v;\n                do {\n      \
    \              v = path[--qi];\n                    cycle = heap.merge(cycle,\
    \ top[v]);\n                } while (uf.merge(u, v));\n                u = uf.find(u),\
    \ top[u] = cycle, seen[u] = -1;\n                cycles.push_back({u, time, std::vector<long\
    \ long>(queue.begin() + qi, queue.begin() + end)});\n            }\n        }\n\
    \        for (long long i = 0; i < qi; i++) in[uf.find(es[queue[i]].dst)] = queue[i];\n\
    \    }\n    // \u7E2E\u3081\u305F\u9589\u8DEF\u3092\u65B0\u3057\u3044\u3082\u306E\
    \u304B\u3089\u623B\u3057\u3001\u9589\u8DEF\u306E\u4E2D\u306E\u8FBA\u3092\u9078\
    \u3073\u76F4\u3059\n    for (auto it = cycles.rbegin(); it != cycles.rend(); ++it)\
    \ {\n        uf.rollback(it->time);\n        long long in_edge = in[it->u];\n\
    \        for (long long i : it->edges) in[uf.find(es[i].dst)] = i;\n        in[uf.find(es[in_edge].dst)]\
    \ = in_edge;\n    }\n    std::vector<Edge> parent_edge(n);\n    for (long long\
    \ v = 0; v < n; v++) {\n        if (v != root) parent_edge[v] = es[in[v]];\n \
    \   }\n    return MinimumArborescence<Cost>{cost, parent_edge};\n}\n#line 6 \"\
    test/yosupo/graph/directedmst.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m, s;\n    std::cin >> n >>\
    \ m >> s;\n    Graph<long long> g(n);\n    g.read(m, 0, true, true);\n    auto\
    \ res = minimum_arborescence(g, s);\n    std::cout << res->cost << '\\n';\n  \
    \  for (int v = 0; v < n; v++) std::cout << (v == s ? s : res->parent_edge[v].src)\
    \ << \" \\n\"[v == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/directedmst\"\n\n#include\
    \ <iostream>\n\n#include \"../../../src/graph/minimum-arborescence.hpp\"\n\nint\
    \ main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m, s;\n    std::cin >> n >> m >> s;\n    Graph<long long> g(n);\n\
    \    g.read(m, 0, true, true);\n    auto res = minimum_arborescence(g, s);\n \
    \   std::cout << res->cost << '\\n';\n    for (int v = 0; v < n; v++) std::cout\
    \ << (v == s ? s : res->parent_edge[v].src) << \" \\n\"[v == n - 1];\n}\n"
  dependsOn:
  - src/graph/minimum-arborescence.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/yosupo/graph/directedmst.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 13:40:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/directedmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/directedmst.test.cpp
- /verify/test/yosupo/graph/directedmst.test.cpp.html
title: test/yosupo/graph/directedmst.test.cpp
---
