---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/dominator-tree.hpp
    title: "\u652F\u914D\u6728"
  - icon: ':heavy_check_mark:'
    path: src/graph/graph.hpp
    title: "\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"test/yosupo/graph/dominatortree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/dominatortree\"\n\n#include <iostream>\n\n\
    #line 2 \"src/graph/dominator-tree.hpp\"\n\n/**\n * @file dominator-tree.hpp\n\
    \ * @brief \u652F\u914D\u6728\n */\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n\
    \ * @brief \u30B0\u30E9\u30D5\n */\n\n#line 11 \"src/graph/graph.hpp\"\n\n/**\n\
    \ * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\u30AF\u30E9\u30B9\n *\n * @tparam\
    \ Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B \u7701\u7565\u3057\u305F\u3089\
    \ long long (\u91CD\u307F\u306E\u548C\u3084\u672A\u5230\u9054\u3092\u8868\u3059\
    \ max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\u3088\u3046\u306B)\n */\n\
    template <typename Cost = long long>\nclass Graph {\n   public:\n    /**\n   \
    \  * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\n     *\n     * operator\
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
    \u30661\u3064\u3060\u3051\u683C\u7D0D\u3055\u308C\u308B\u3002\u305D\u306E src\
    \ \u3068 dst \u306E\u5411\u304D\u306F\u898F\u5B9A\u3057\u306A\u3044\n     * \u6709\
    \u5411\u8FBA\u306F\u8FFD\u52A0\u3057\u305F\u3068\u304D\u306E\u5411\u304D\u306E\
    \u307E\u307E\u683C\u7D0D\u3055\u308C\u308B\n     */\n    std::vector<Edge> edges()\
    \ const {\n        std::vector<Edge> res(m);\n        for (long long i = 0; i\
    \ < n; i++) {\n            for (auto& e : g[i]) {\n                res[e.id] =\
    \ e;\n            }\n        }\n        return res;\n    }\n};\n#line 13 \"src/graph/dominator-tree.hpp\"\
    \n\n/**\n * @brief \u6709\u5411\u30B0\u30E9\u30D5\u306E\u652F\u914D\u6728 (Lengauer\u2013\
    Tarjan) O(m log n)\n *\n * root \u304B\u3089 v \u3078\u306E\u3069\u306E\u9053\u3082\
    \u901A\u308B\u9802\u70B9\u306E\u3046\u3061\u3001v \u4EE5\u5916\u3067 v \u306B\u6700\
    \u3082\u8FD1\u3044\u3082\u306E (\u76F4\u8FD1\u652F\u914D\u70B9) \u3092\u6C42\u3081\
    \u308B\n * @return \u5404\u9802\u70B9\u306E\u76F4\u8FD1\u652F\u914D\u70B9\u3002\
    root \u3068\u3001root \u304B\u3089\u5230\u9054\u3067\u304D\u306A\u3044\u9802\u70B9\
    \u306F -1\n */\ntemplate <typename Cost>\nstd::vector<long long> dominator_tree(const\
    \ Graph<Cost>& graph, long long root) {\n    const long long n = graph.n;\n  \
    \  assert(0 <= root && root < n);\n    std::vector<std::vector<long long>> radj(n);\n\
    \    for (long long u = 0; u < n; u++) {\n        for (const auto& e : graph[u])\
    \ radj[e.dst].push_back(u);\n    }\n    // DFS \u306E\u884C\u304D\u304C\u3051\u9806\
    \u3002\u4EE5\u4E0B\u306F\u9802\u70B9\u3067\u306F\u306A\u304F\u3001\u3053\u306E\
    \u9806\u756A (0 \u304C root) \u3067\u6271\u3046\n    std::vector<long long> ord(n,\
    \ -1), vertex, par;\n    {\n        std::vector<std::pair<long long, long long>>\
    \ stk = {{root, -1}};\n        while (!stk.empty()) {\n            auto [u, p]\
    \ = stk.back();\n            stk.pop_back();\n            if (ord[u] != -1) continue;\n\
    \            ord[u] = vertex.size();\n            vertex.push_back(u);\n     \
    \       par.push_back(p);\n            for (const auto& e : graph[u]) {\n    \
    \            if (ord[e.dst] == -1) stk.emplace_back(e.dst, ord[u]);\n        \
    \    }\n        }\n    }\n    const long long k = vertex.size();\n    // semi:\
    \ \u6E96\u652F\u914D\u70B9\u3001anc\u30FBlabel: \u51E6\u7406\u6E08\u307F\u306E\
    \u68EE (\u7D4C\u8DEF\u5727\u7E2E\u3064\u304D) \u3067 semi \u304C\u6700\u5C0F\u306E\
    \u9802\u70B9\u3092\u6C42\u3081\u308B\u305F\u3081\u306E\u3082\u306E\n    std::vector<long\
    \ long> semi(k), idom(k, -1), anc(k, -1), label(k);\n    std::vector<std::vector<long\
    \ long>> bucket(k);\n    for (long long i = 0; i < k; i++) semi[i] = label[i]\
    \ = i;\n    std::vector<long long> path;\n    // v \u304B\u3089\u68EE\u306E\u6839\
    \u306E\u624B\u524D\u307E\u3067\u3067\u3001semi \u304C\u6700\u5C0F\u306E\u9802\u70B9\
    \n    auto eval = [&](long long v) {\n        if (anc[v] == -1) return v;\n  \
    \      for (long long x = v; anc[anc[x]] != -1; x = anc[x]) path.push_back(x);\n\
    \        // \u6839\u306B\u8FD1\u3044\u65B9\u304B\u3089\u5727\u7E2E\u3059\u308B\
    \n        while (!path.empty()) {\n            long long x = path.back();\n  \
    \          path.pop_back();\n            if (semi[label[anc[x]]] < semi[label[x]])\
    \ label[x] = label[anc[x]];\n            anc[x] = anc[anc[x]];\n        }\n  \
    \      return label[v];\n    };\n    for (long long w = k - 1; w >= 1; w--) {\n\
    \        for (long long u : radj[vertex[w]]) {\n            if (ord[u] == -1)\
    \ continue;\n            semi[w] = std::min(semi[w], semi[eval(ord[u])]);\n  \
    \      }\n        bucket[semi[w]].push_back(w);\n        anc[w] = par[w];\n  \
    \      for (long long v : bucket[par[w]]) {\n            long long u = eval(v);\n\
    \            idom[v] = semi[u] < semi[v] ? u : par[w];\n        }\n        bucket[par[w]].clear();\n\
    \    }\n    for (long long w = 1; w < k; w++) {\n        if (idom[w] != semi[w])\
    \ idom[w] = idom[idom[w]];\n    }\n    std::vector<long long> res(n, -1);\n  \
    \  for (long long w = 1; w < k; w++) res[vertex[w]] = vertex[idom[w]];\n    return\
    \ res;\n}\n#line 6 \"test/yosupo/graph/dominatortree.test.cpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int\
    \ n, m, s;\n    std::cin >> n >> m >> s;\n    Graph<int> g(n);\n    g.read(m,\
    \ 0, false, true);\n    auto idom = dominator_tree(g, s);\n    for (int v = 0;\
    \ v < n; v++) std::cout << (v == s ? s : idom[v]) << \" \\n\"[v == n - 1];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\n\n#include\
    \ <iostream>\n\n#include \"../../../src/graph/dominator-tree.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int\
    \ n, m, s;\n    std::cin >> n >> m >> s;\n    Graph<int> g(n);\n    g.read(m,\
    \ 0, false, true);\n    auto idom = dominator_tree(g, s);\n    for (int v = 0;\
    \ v < n; v++) std::cout << (v == s ? s : idom[v]) << \" \\n\"[v == n - 1];\n}\n"
  dependsOn:
  - src/graph/dominator-tree.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/yosupo/graph/dominatortree.test.cpp
  requiredBy: []
  timestamp: '2026-10-31 18:12:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/dominatortree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/dominatortree.test.cpp
- /verify/test/yosupo/graph/dominatortree.test.cpp.html
title: test/yosupo/graph/dominatortree.test.cpp
---
