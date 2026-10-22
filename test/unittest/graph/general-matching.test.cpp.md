---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/general-matching.hpp
    title: "\u4E00\u822C\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0"
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/graph/general-matching.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// general-matching.hpp \u306E general_matching \u3092\u3001\u9802\u70B9\u96C6\
    \u5408\u306E bit DP \u3067\u6C42\u3081\u305F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u306E\u5927\u304D\u3055\u3068\u6BD4\u3079\u308B\n// \u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u30FB\u591A\u91CD\u8FBA\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3001\
    \u8FD4\u3063\u305F\u8FBA\u304C\u5B9F\u969B\u306B\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3082\u8ABF\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/general-matching.hpp\"\
    \n\n/**\n * @file general-matching.hpp\n * @brief \u4E00\u822C\u30B0\u30E9\u30D5\
    \u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\n */\n\n#include <queue>\n#include\
    \ <vector>\n\n#line 2 \"src/graph/graph.hpp\"\n\n/**\n * @file graph.hpp\n * @brief\
    \ \u30B0\u30E9\u30D5\n */\n\n#include <cassert>\n#include <iostream>\n#line 11\
    \ \"src/graph/graph.hpp\"\n\n/**\n * @brief \u30B0\u30E9\u30D5\u306E\u6C4E\u7528\
    \u30AF\u30E9\u30B9\n *\n * @tparam Cost \u8FBA\u306E\u30B3\u30B9\u30C8\u306E\u578B\
    \ \u7701\u7565\u3057\u305F\u3089 long long (\u91CD\u307F\u306E\u548C\u3084\u672A\
    \u5230\u9054\u3092\u8868\u3059 max / 4 \u304C\u3042\u3075\u308C\u306B\u304F\u3044\
    \u3088\u3046\u306B)\n */\ntemplate <typename Cost = long long>\nclass Graph {\n\
    \   public:\n    /**\n     * @brief \u6709\u5411\u8FBA\u306E\u69CB\u9020\u4F53\
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
    \    return res;\n    }\n};\n#line 12 \"src/graph/general-matching.hpp\"\n\nnamespace\
    \ internal_general_matching {\n\n/**\n * @brief Edmonds \u306E\u82B1\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\n *\n * \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\
    \u6301\u3064\n */\ntemplate <typename Cost>\nclass Blossom {\n   public:\n   \
    \ explicit Blossom(const Graph<Cost>& graph) : graph(graph), n(static_cast<int>(graph.n)),\
    \ match(n, -1), p(n), base(n), used(n), in_blossom(n) {}\n\n    std::vector<int>\
    \ solve() {\n        // \u8CAA\u6B32\u306B\u4F5C\u3063\u305F\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u304B\u3089\u59CB\u3081\u308B\n        for (int v = 0; v < n; v++)\
    \ {\n            if (match[v] != -1) continue;\n            for (long long u :\
    \ graph[v]) {\n                if (u != v && match[u] == -1) {\n             \
    \       match[u] = v, match[v] = static_cast<int>(u);\n                    break;\n\
    \                }\n            }\n        }\n        for (int v = 0; v < n; v++)\
    \ {\n            if (match[v] != -1) continue;\n            // \u898B\u3064\u304B\
    \u3063\u305F\u5897\u52A0\u8DEF\u306B\u6CBF\u3063\u3066\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3092\u5165\u308C\u66FF\u3048\u308B\n            for (int t = find_path(v);\
    \ t != -1;) {\n                int pt = p[t], next = match[pt];\n            \
    \    match[t] = pt, match[pt] = t;\n                t = next;\n            }\n\
    \        }\n        return match;\n    }\n\n   private:\n    const Graph<Cost>&\
    \ graph;\n    int n;\n    std::vector<int> match, p, base;\n    std::vector<bool>\
    \ used, in_blossom;\n\n    // \u4EA4\u4E92\u6728\u306E\u4E0A\u3067 a \u3068 b\
    \ \u306E (\u82B1\u3092\u7E2E\u3081\u305F\u5F8C\u306E) \u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n    int lca(int a, int b) const {\n        std::vector<bool> seen(n,\
    \ false);\n        while (true) {\n            a = base[a];\n            seen[a]\
    \ = true;\n            if (match[a] == -1) break;\n            a = p[match[a]];\n\
    \        }\n        while (true) {\n            b = base[b];\n            if (seen[b])\
    \ return b;\n            b = p[match[b]];\n        }\n    }\n    void mark_path(int\
    \ v, int b, int child) {\n        while (base[v] != b) {\n            in_blossom[base[v]]\
    \ = in_blossom[base[match[v]]] = true;\n            p[v] = child;\n          \
    \  child = match[v];\n            v = p[match[v]];\n        }\n    }\n    // root\
    \ \u304B\u3089\u5897\u52A0\u8DEF\u3092\u63A2\u3057\u3001\u898B\u3064\u304B\u308C\
    \u3070\u305D\u306E\u7D42\u70B9 (\u30DE\u30C3\u30C1\u3057\u3066\u3044\u306A\u3044\
    \u9802\u70B9) \u3092\u8FD4\u3059\u3002\u306A\u3051\u308C\u3070 -1\n    int find_path(int\
    \ root) {\n        used.assign(n, false);\n        p.assign(n, -1);\n        for\
    \ (int i = 0; i < n; i++) base[i] = i;\n        used[root] = true;\n        std::queue<int>\
    \ que;\n        que.push(root);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (long long to_ : graph[v])\
    \ {\n                int to = static_cast<int>(to_);\n                if (base[v]\
    \ == base[to] || match[v] == to) continue;\n                if (to == root ||\
    \ (match[to] != -1 && p[match[to]] != -1)) {\n                    // \u5947\u9589\
    \u8DEF (\u82B1) \u304C\u3067\u304D\u305F\u306E\u3067\u30011 \u3064\u306E\u9802\
    \u70B9\u306B\u7E2E\u3081\u308B\n                    int b = lca(v, to);\n    \
    \                in_blossom.assign(n, false);\n                    mark_path(v,\
    \ b, to);\n                    mark_path(to, b, v);\n                    for (int\
    \ i = 0; i < n; i++) {\n                        if (!in_blossom[base[i]]) continue;\n\
    \                        base[i] = b;\n                        if (!used[i]) {\n\
    \                            used[i] = true;\n                            que.push(i);\n\
    \                        }\n                    }\n                } else if (p[to]\
    \ == -1) {\n                    p[to] = v;\n                    if (match[to]\
    \ == -1) return to;\n                    used[match[to]] = true;\n           \
    \         que.push(match[to]);\n                }\n            }\n        }\n\
    \        return -1;\n    }\n};\n\n}  // namespace internal_general_matching\n\n\
    /**\n * @brief \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0 (Edmonds \u306E\u82B1\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0) O(n^3)\n\
    \ *\n * @return std::vector<Edge> \u30DE\u30C3\u30C1\u30F3\u30B0\u306B\u4F7F\u3063\
    \u305F\u8FBA\u306E\u30EA\u30B9\u30C8 (\u5404\u8FBA\u306F src < dst \u306E\u5411\
    \u304D\u3067 1 \u56DE\u305A\u3064\u3001src \u306E\u6607\u9806)\n * @note \u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u306F\u7121\u8996\u3059\u308B\u3002\u591A\u91CD\u8FBA\
    \u304C\u3042\u3063\u3066\u3082\u3088\u3044\n */\ntemplate <typename Cost = long\
    \ long>\nstd::vector<typename Graph<Cost>::Edge> general_matching(const Graph<Cost>&\
    \ graph) {\n    std::vector<int> match = internal_general_matching::Blossom<Cost>(graph).solve();\n\
    \    std::vector<typename Graph<Cost>::Edge> res;\n    for (long long v = 0; v\
    \ < graph.n; v++) {\n        if (match[v] <= v) continue;\n        for (const\
    \ auto& e : graph[v]) {\n            if (e.dst == match[v]) {\n              \
    \  res.push_back(e);\n                break;\n            }\n        }\n    }\n\
    \    return res;\n}\n#line 8 \"test/unittest/graph/general-matching.test.cpp\"\
    \n\n#include <algorithm>\n#line 11 \"test/unittest/graph/general-matching.test.cpp\"\
    \n#include <random>\n#line 13 \"test/unittest/graph/general-matching.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 12 + 1, m\
    \ = rng() % (n * 2 + 1);\n        Graph<int> g(n);\n        std::vector<std::vector<bool>>\
    \ adj(n, std::vector<bool>(n, false));\n        for (int i = 0; i < m; i++) {\n\
    \            int u = rng() % n, v = rng() % n;\n            g.add_edge(u, v);\n\
    \            adj[u][v] = adj[v][u] = true;\n        }\n        // dp[S]: \u9802\
    \u70B9\u96C6\u5408 S \u306E\u4E2D\u3067\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3002S \u306E\u6700\u5C0F\u306E\u9802\u70B9\u3092\u4F7F\u308F\u306A\u3044\
    \u304B\u3001\u8AB0\u304B\u3068\u7D44\u307E\u305B\u308B\n        std::vector<int>\
    \ dp(1 << n, 0);\n        for (int S = 1; S < (1 << n); S++) {\n            int\
    \ v = __builtin_ctz(S);\n            int T = S & ~(1 << v);\n            dp[S]\
    \ = dp[T];\n            for (int u = v + 1; u < n; u++) {\n                if\
    \ ((T >> u & 1) && adj[v][u]) dp[S] = std::max(dp[S], dp[T & ~(1 << u)] + 1);\n\
    \            }\n        }\n        auto matching = general_matching(g);\n    \
    \    if (static_cast<int>(matching.size()) != dp[(1 << n) - 1]) ok = false;\n\
    \        std::vector<bool> used_vertex(n, false), used_edge(m, false);\n     \
    \   for (int i = 0; i < static_cast<int>(matching.size()); i++) {\n          \
    \  const auto& e = matching[i];\n            if (e.src >= e.dst || e.id < 0 ||\
    \ e.id >= m || used_edge[e.id]) {\n                ok = false;\n             \
    \   break;\n            }\n            if (i > 0 && matching[i - 1].src >= e.src)\
    \ ok = false;\n            if (used_vertex[e.src] || used_vertex[e.dst]) ok =\
    \ false;\n            used_vertex[e.src] = used_vertex[e.dst] = used_edge[e.id]\
    \ = true;\n            // \u8FBA\u306E\u756A\u53F7\u304C\u6307\u3059\u8FBA\u3068\
    \u7AEF\u70B9\u304C\u4E00\u81F4\u3059\u308B\n            bool found = false;\n\
    \            for (const auto& f : g[e.src]) found |= f.id == e.id && f.dst ==\
    \ e.dst;\n            if (!found) ok = false;\n        }\n    }\n    if (ok) std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// general-matching.hpp \u306E general_matching \u3092\u3001\u9802\u70B9\u96C6\
    \u5408\u306E bit DP \u3067\u6C42\u3081\u305F\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u306E\u5927\u304D\u3055\u3068\u6BD4\u3079\u308B\n// \u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u30FB\u591A\u91CD\u8FBA\u3092\u542B\u3080\u30B0\u30E9\u30D5\u3067\u3001\
    \u8FD4\u3063\u305F\u8FBA\u304C\u5B9F\u969B\u306B\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306B\u306A\u3063\u3066\u3044\u308B\u304B\u3082\u8ABF\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/general-matching.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 12 + 1, m = rng()\
    \ % (n * 2 + 1);\n        Graph<int> g(n);\n        std::vector<std::vector<bool>>\
    \ adj(n, std::vector<bool>(n, false));\n        for (int i = 0; i < m; i++) {\n\
    \            int u = rng() % n, v = rng() % n;\n            g.add_edge(u, v);\n\
    \            adj[u][v] = adj[v][u] = true;\n        }\n        // dp[S]: \u9802\
    \u70B9\u96C6\u5408 S \u306E\u4E2D\u3067\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
    \u30B0\u3002S \u306E\u6700\u5C0F\u306E\u9802\u70B9\u3092\u4F7F\u308F\u306A\u3044\
    \u304B\u3001\u8AB0\u304B\u3068\u7D44\u307E\u305B\u308B\n        std::vector<int>\
    \ dp(1 << n, 0);\n        for (int S = 1; S < (1 << n); S++) {\n            int\
    \ v = __builtin_ctz(S);\n            int T = S & ~(1 << v);\n            dp[S]\
    \ = dp[T];\n            for (int u = v + 1; u < n; u++) {\n                if\
    \ ((T >> u & 1) && adj[v][u]) dp[S] = std::max(dp[S], dp[T & ~(1 << u)] + 1);\n\
    \            }\n        }\n        auto matching = general_matching(g);\n    \
    \    if (static_cast<int>(matching.size()) != dp[(1 << n) - 1]) ok = false;\n\
    \        std::vector<bool> used_vertex(n, false), used_edge(m, false);\n     \
    \   for (int i = 0; i < static_cast<int>(matching.size()); i++) {\n          \
    \  const auto& e = matching[i];\n            if (e.src >= e.dst || e.id < 0 ||\
    \ e.id >= m || used_edge[e.id]) {\n                ok = false;\n             \
    \   break;\n            }\n            if (i > 0 && matching[i - 1].src >= e.src)\
    \ ok = false;\n            if (used_vertex[e.src] || used_vertex[e.dst]) ok =\
    \ false;\n            used_vertex[e.src] = used_vertex[e.dst] = used_edge[e.id]\
    \ = true;\n            // \u8FBA\u306E\u756A\u53F7\u304C\u6307\u3059\u8FBA\u3068\
    \u7AEF\u70B9\u304C\u4E00\u81F4\u3059\u308B\n            bool found = false;\n\
    \            for (const auto& f : g[e.src]) found |= f.id == e.id && f.dst ==\
    \ e.dst;\n            if (!found) ok = false;\n        }\n    }\n    if (ok) std::cout\
    \ << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/general-matching.hpp
  - src/graph/graph.hpp
  isVerificationFile: true
  path: test/unittest/graph/general-matching.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 13:40:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/general-matching.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/general-matching.test.cpp
- /verify/test/unittest/graph/general-matching.test.cpp.html
title: test/unittest/graph/general-matching.test.cpp
---
