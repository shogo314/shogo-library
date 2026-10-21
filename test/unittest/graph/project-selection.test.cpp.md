---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/max-flow.hpp
    title: "\u6700\u5927\u6D41 (Dinic \u6CD5)"
  - icon: ':heavy_check_mark:'
    path: src/graph/project-selection.hpp
    title: "\u71C3\u3084\u3059\u57CB\u3081\u308B (Project Selection Problem)"
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
  bundledCode: "#line 1 \"test/unittest/graph/project-selection.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// ProjectSelection \u3092\u3001\u3059\u3079\u3066\u306E\u5272\u308A\u5F53\
    \u3066\u3092\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u3079\u308B\n// \u8CA0\u306E\u30B3\u30B9\u30C8\u3001\u52A3\u30E2\
    \u30B8\u30E5\u30E9\u306A 2 \u5909\u6570\u306E\u30B3\u30B9\u30C8\u3001\u7981\u6B62\
    \u3001\u3059\u3079\u3066\u540C\u3058\u306A\u3089\u5229\u5F97 \u3092\u542B\u3080\
    \n// solve() \u306E\u5024\u3068\u3001assignment() \u306E\u5272\u308A\u5F53\u3066\
    \u306E\u30B3\u30B9\u30C8\u304C\u6700\u5C0F\u5024\u3068\u4E00\u81F4\u3059\u308B\
    \u304B\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/project-selection.hpp\"\
    \n\n/**\n * @file project-selection.hpp\n * @brief \u71C3\u3084\u3059\u57CB\u3081\
    \u308B (Project Selection Problem)\n */\n\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"src/graph/max-flow.hpp\"\n\n/**\n * @file max-flow.hpp\n\
    \ * @brief \u6700\u5927\u6D41 (Dinic \u6CD5)\n */\n\n#include <algorithm>\n#line\
    \ 10 \"src/graph/max-flow.hpp\"\n#include <limits>\n#include <queue>\n#line 14\
    \ \"src/graph/max-flow.hpp\"\n\n/**\n * @brief \u6700\u5927\u6D41 (Dinic \u6CD5\
    )\n *\n * O(n^2 m) \u3060\u304C\u3001\u5B9F\u969B\u306B\u306F\u305A\u3063\u3068\
    \u901F\u3044\u3053\u3068\u304C\u591A\u3044\u3002\u5BB9\u91CF\u304C\u3059\u3079\
    \u3066 1 \u306A\u3089 O(m min(m^(1/2), n^(2/3)))\n * \u4F8B:\n * MaxFlow<long\
    \ long> mf(n);\n * mf.add_edge(0, 1, 5);\n * long long f = mf.flow(s, t);\n *\n\
    \ * @tparam Cap \u5BB9\u91CF\u306E\u578B\n */\ntemplate <typename Cap>\nclass\
    \ MaxFlow {\n   public:\n    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\n   \
    \  */\n    struct Edge {\n        long long from, to;\n        Cap cap;   //!<\
    \ \u5BB9\u91CF\n        Cap flow;  //!< \u6D41\u308C\u3066\u3044\u308B\u91CF\n\
    \    };\n\n   private:\n    // \u5185\u90E8\u306E\u8FBA\u3068\u914D\u5217\u306F\
    \ int \u3067\u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long\
    \ long \u306B\u3059\u308B\n    struct InnerEdge {\n        int to, rev;\n    \
    \    Cap cap;  // \u6B8B\u308A\u306E\u5BB9\u91CF\n    };\n    long long n;\n \
    \   std::vector<std::vector<InnerEdge>> g;\n    std::vector<std::pair<int, int>>\
    \ pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\u304C g \u306E\u3069\u3053\u306B\u3042\
    \u308B\u304B\n    std::vector<int> level, iter;\n\n    bool bfs(int s, int t)\
    \ {\n        level.assign(n, -1);\n        level[s] = 0;\n        std::queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (const auto& e : g[v])\
    \ {\n                if (e.cap > 0 && level[e.to] == -1) {\n                 \
    \   level[e.to] = level[v] + 1;\n                    que.push(e.to);\n       \
    \         }\n            }\n        }\n        return level[t] != -1;\n    }\n\
    \    // v \u304B\u3089 t \u3078\u3001up \u3092\u4E0A\u9650\u3068\u3057\u3066\u30EC\
    \u30D9\u30EB\u30B0\u30E9\u30D5\u4E0A\u3067\u6D41\u3059\n    Cap dfs(int v, int\
    \ t, Cap up) {\n        if (v == t) return up;\n        Cap res = 0;\n       \
    \ for (int& i = iter[v]; i < static_cast<int>(g[v].size()); i++) {\n         \
    \   InnerEdge& e = g[v][i];\n            if (e.cap <= 0 || level[e.to] != level[v]\
    \ + 1) continue;\n            Cap d = dfs(e.to, t, std::min(up - res, e.cap));\n\
    \            if (d <= 0) continue;\n            e.cap -= d;\n            g[e.to][e.rev].cap\
    \ += d;\n            res += d;\n            if (res == up) return res;\n     \
    \   }\n        // \u3053\u308C\u4EE5\u4E0A\u6D41\u305B\u306A\u3044\u306E\u3067\
    \u3001\u3053\u306E\u30D5\u30A7\u30FC\u30BA\u3067\u306F\u4F7F\u308F\u306A\u3044\
    \n        level[v] = n;\n        return res;\n    }\n\n   public:\n    explicit\
    \ MaxFlow(long long n = 0) : n(n), g(n) {}\n\n    long long size() const { return\
    \ n; }\n\n    /**\n     * @brief from \u304B\u3089 to \u3078\u306E\u5BB9\u91CF\
    \ cap \u306E\u8FBA\u3092\u8FFD\u52A0\u3057\u3001\u8FBA\u306E\u756A\u53F7 (\u8FFD\
    \u52A0\u3057\u305F\u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059\n     */\n    long\
    \ long add_edge(long long from, long long to, Cap cap) {\n        assert(0 <=\
    \ from && from < n && 0 <= to && to < n && cap >= 0);\n        long long id =\
    \ pos.size();\n        int from_id = g[from].size();\n        int to_id = g[to].size()\
    \ + (from == to);\n        pos.emplace_back(from, from_id);\n        g[from].push_back({static_cast<int>(to),\
    \ to_id, cap});\n        g[to].push_back({static_cast<int>(from), from_id, 0});\n\
    \        return id;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\u3001\
    limit \u3092\u4E0A\u9650\u3068\u3057\u3066\u3067\u304D\u308B\u3060\u3051\u6D41\
    \u3057\u3001\u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n     * \u4F55\u5EA6\u3082\
    \u547C\u3076\u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\
    \u52A0\u3057\u3066\u6D41\u3059\n     */\n    Cap flow(long long s, long long t,\
    \ Cap limit = std::numeric_limits<Cap>::max()) {\n        assert(0 <= s && s <\
    \ n && 0 <= t && t < n && s != t);\n        Cap res = 0;\n        while (res <\
    \ limit && bfs(s, t)) {\n            iter.assign(n, 0);\n            Cap f = dfs(s,\
    \ t, limit - res);\n            if (f == 0) break;\n            res += f;\n  \
    \      }\n        return res;\n    }\n\n    /**\n     * @brief \u756A\u53F7 i\
    \ \u306E\u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long long i) const\
    \ {\n        assert(0 <= i && i < static_cast<long long>(pos.size()));\n     \
    \   const auto& e = g[pos[i].first][pos[i].second];\n        const auto& re =\
    \ g[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n\
    \    }\n    /**\n     * @brief \u756A\u53F7 i \u306E\u8FBA\u306E\u5BB9\u91CF\u3092\
    \ new_cap \u306B\u3001\u6D41\u308C\u3066\u3044\u308B\u91CF\u3092 new_flow \u306B\
    \u5909\u3048\u308B\n     * \u307B\u304B\u306E\u8FBA\u306E\u6D41\u91CF\u306F\u5909\
    \u3048\u306A\u3044\u306E\u3067\u3001\u6D41\u91CF\u306E\u4FDD\u5B58\u5247\u304C\
    \u5D29\u308C\u308B\u3053\u3068\u304C\u3042\u308B\n     */\n    void change_edge(long\
    \ long i, Cap new_cap, Cap new_flow) {\n        assert(0 <= i && i < static_cast<long\
    \ long>(pos.size()) && 0 <= new_flow && new_flow <= new_cap);\n        auto& e\
    \ = g[pos[i].first][pos[i].second];\n        auto& re = g[e.to][e.rev];\n    \
    \    e.cap = new_cap - new_flow;\n        re.cap = new_flow;\n    }\n    /**\n\
    \     * @brief \u3059\u3079\u3066\u306E\u8FBA\u306E\u60C5\u5831 (\u8FFD\u52A0\u3057\
    \u305F\u9806)\n     */\n    std::vector<Edge> edges() const {\n        std::vector<Edge>\
    \ res;\n        for (long long i = 0; i < static_cast<long long>(pos.size());\
    \ i++) res.push_back(get_edge(i));\n        return res;\n    }\n\n    /**\n  \
    \   * @brief \u76F4\u524D\u306E flow(s, t) \u306E\u5F8C\u3067\u3001\u6B8B\u4F59\
    \u30B0\u30E9\u30D5\u3067 s \u304B\u3089\u884C\u3051\u308B\u9802\u70B9\u304B\n\
    \     * flow(s, t) \u3067\u6D41\u3057\u304D\u3063\u3066\u3044\u308C\u3070\u3001\
    true \u306E\u9802\u70B9\u306E\u96C6\u5408\u304C\u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \ s \u5074\u306B\u306A\u308B\n     */\n    std::vector<bool> min_cut(long long\
    \ s) const {\n        std::vector<bool> visited(n);\n        std::vector<long\
    \ long> st = {s};\n        visited[s] = true;\n        while (!st.empty()) {\n\
    \            long long v = st.back();\n            st.pop_back();\n          \
    \  for (const auto& e : g[v]) {\n                if (e.cap > 0 && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    st.push_back(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    };\n#line 13 \"src/graph/project-selection.hpp\"\n\n/**\n * @brief \u71C3\u3084\
    \u3059\u57CB\u3081\u308B (Project Selection Problem)\n *\n * n \u500B\u306E 0/1\
    \ \u5909\u6570 x_0, ..., x_{n-1} \u306B\u3064\u3044\u3066\u3001\u30B3\u30B9\u30C8\
    \u306E\u548C\u306E\u6700\u5C0F\u5024\u3068\u3001\u305D\u306E\u3068\u304D\u306E\
    \u5272\u308A\u5F53\u3066\u3092\u6700\u5C0F\u30AB\u30C3\u30C8\u3067\u6C42\u3081\
    \u308B\n * \u5909\u6570 v \u306F\u3001\u6700\u5C0F\u30AB\u30C3\u30C8\u3067\u59CB\
    \u70B9\u5074\u306A\u3089 x_v = 0\u3001\u7D42\u70B9\u5074\u306A\u3089 x_v = 1\n\
    \ * 2 \u5909\u6570\u306E\u30B3\u30B9\u30C8\u306F\u52A3\u30E2\u30B8\u30E5\u30E9\
    \ (c01 + c10 >= c00 + c11) \u3067\u3042\u308B\u3053\u3068\n * \u4F8B:\n * ProjectSelection<long\
    \ long> ps(n);\n * ps.add_cost(0, 3, 5);           // x_0 = 0 \u306A\u3089\u30B3\
    \u30B9\u30C8 3\u30011 \u306A\u3089\u30B3\u30B9\u30C8 5\n * ps.add_cost_if(0, 1,\
    \ 1, 0, 4);  // x_0 = 1 \u304B\u3064 x_1 = 0 \u306A\u3089\u30B3\u30B9\u30C8 4\n\
    \ * long long c = ps.solve();\n * std::vector<bool> x = ps.assignment();\n *\n\
    \ * @tparam Cost \u30B3\u30B9\u30C8\u306E\u578B\n */\ntemplate <typename Cost\
    \ = long long>\nclass ProjectSelection {\n    long long n;\n    long long aux\
    \ = 0;  // \u88DC\u52A9\u9802\u70B9\u306E\u500B\u6570\n    Cost constant = 0;\n\
    \    std::vector<Cost> cost1;  // x_v = 1 \u306E\u3068\u304D\u306E\u8FFD\u52A0\
    \u306E\u30B3\u30B9\u30C8 (cost0 \u3092\u5F15\u3044\u305F\u5DEE)\n    // \u8FBA\
    \ from -> to (from \u304C 0 \u304B\u3064 to \u304C 1 \u306A\u3089\u30B3\u30B9\u30C8\
    \ cap)\u3002inf \u306A\u3089\u5BB9\u91CF\u306F\u5341\u5206\u5927\u304D\u3044\u5024\
    \u306B\u3059\u308B\n    struct E {\n        long long from, to;\n        Cost\
    \ cap;\n        bool inf;\n    };\n    std::vector<E> es;\n    std::vector<bool>\
    \ result;\n\n    // \u9802\u70B9\u306E\u756A\u53F7: \u5909\u6570 0, ..., n - 1\u3001\
    \u88DC\u52A9\u9802\u70B9 n, ..., n + aux - 1\u3001\u59CB\u70B9 n + aux\u3001\u7D42\
    \u70B9 n + aux + 1\n    void check_var(long long v) const { assert(0 <= v && v\
    \ < n); }\n\n   public:\n    /**\n     * @brief n \u500B\u306E\u5909\u6570\u3067\
    \u3001\u30B3\u30B9\u30C8\u304C\u3059\u3079\u3066 0\n     */\n    explicit ProjectSelection(long\
    \ long n = 0) : n(n), cost1(n, 0) {}\n\n    /**\n     * @brief \u5909\u6570\u306E\
    \u500B\u6570\n     */\n    long long size() const { return n; }\n\n    /**\n \
    \    * @brief \u5B9A\u6570\u306E\u30B3\u30B9\u30C8 c \u3092\u8DB3\u3059\n    \
    \ */\n    void add_constant(Cost c) { constant += c; }\n    /**\n     * @brief\
    \ x_v = 0 \u306A\u3089\u30B3\u30B9\u30C8 c0\u3001x_v = 1 \u306A\u3089\u30B3\u30B9\
    \u30C8 c1 \u3092\u8DB3\u3059 (\u8CA0\u3067\u3082\u3088\u3044)\n     */\n    void\
    \ add_cost(long long v, Cost c0, Cost c1) {\n        check_var(v);\n        constant\
    \ += c0;\n        cost1[v] += c1 - c0;\n    }\n    /**\n     * @brief x_v = a\
    \ \u306A\u3089\u30B3\u30B9\u30C8 c \u3092\u8DB3\u3059 (\u8CA0\u3067\u3082\u3088\
    \u3044)\n     */\n    void add_cost_if(long long v, bool a, Cost c) {\n      \
    \  if (a) {\n            add_cost(v, 0, c);\n        } else {\n            add_cost(v,\
    \ c, 0);\n        }\n    }\n    /**\n     * @brief (x_u, x_v) \u304C (0, 0)\u3001\
    (0, 1)\u3001(1, 0)\u3001(1, 1) \u306E\u3068\u304D\u306E\u30B3\u30B9\u30C8 c00\u3001\
    c01\u3001c10\u3001c11 \u3092\u8DB3\u3059\n     * @pre \u52A3\u30E2\u30B8\u30E5\
    \u30E9: c01 + c10 >= c00 + c11\n     */\n    void add_cost(long long u, long long\
    \ v, Cost c00, Cost c01, Cost c10, Cost c11) {\n        check_var(u), check_var(v);\n\
    \        assert(u != v);\n        assert(c01 + c10 >= c00 + c11 && \"ProjectSelection:\
    \ not submodular\");\n        // c00 + (c10 - c00) x_u + (c11 - c10) x_v + (c01\
    \ + c10 - c00 - c11) [x_u = 0 \u304B\u3064 x_v = 1]\n        constant += c00;\n\
    \        cost1[u] += c10 - c00;\n        cost1[v] += c11 - c10;\n        Cost\
    \ w = c01 + c10 - c00 - c11;\n        if (w > 0) es.push_back({u, v, w, false});\n\
    \    }\n    /**\n     * @brief x_u = a \u304B\u3064 x_v = b \u306A\u3089\u30B3\
    \u30B9\u30C8 c \u3092\u8DB3\u3059\n     * @pre a != b \u306A\u3089 c >= 0\u3001\
    a == b \u306A\u3089 c <= 0 (\u52A3\u30E2\u30B8\u30E5\u30E9\u306B\u306A\u308B\u5834\
    \u5408)\n     */\n    void add_cost_if(long long u, bool a, long long v, bool\
    \ b, Cost c) {\n        Cost cs[2][2] = {{0, 0}, {0, 0}};\n        cs[a][b] =\
    \ c;\n        add_cost(u, v, cs[0][0], cs[0][1], cs[1][0], cs[1][1]);\n    }\n\
    \    /**\n     * @brief x_u = a \u304B\u3064 x_v = !a \u3068\u306A\u308B\u5272\
    \u308A\u5F53\u3066\u3092\u7981\u6B62\u3059\u308B (\u30B3\u30B9\u30C8\u3092\u5341\
    \u5206\u5927\u304D\u304F\u3059\u308B)\n     */\n    void forbid(long long u, bool\
    \ a, long long v) {\n        check_var(u), check_var(v);\n        if (a) {\n \
    \           es.push_back({v, u, 0, true});\n        } else {\n            es.push_back({u,\
    \ v, 0, true});\n        }\n    }\n    /**\n     * @brief vs \u306E\u5909\u6570\
    \u304C\u3059\u3079\u3066 a \u306A\u3089\u5229\u5F97 g \u3092\u5F97\u308B (\u30B3\
    \u30B9\u30C8 -g \u3092\u8DB3\u3059)\n     * \u88DC\u52A9\u9802\u70B9\u3092 1 \u3064\
    \u4F7F\u3046\n     * @pre g >= 0\n     */\n    void add_gain_if_all(const std::vector<long\
    \ long>& vs, bool a, Cost g) {\n        assert(g >= 0);\n        for (long long\
    \ v : vs) check_var(v);\n        long long y = n + aux++;\n        constant -=\
    \ g;\n        if (a) {\n            // y = 0 \u306A\u3089\u30B3\u30B9\u30C8 g\u3001\
    y = 1 \u306F vs \u304C\u3059\u3079\u3066 1 \u306E\u3068\u304D\u3060\u3051\n  \
    \          es.push_back({y, -1, g, false});\n            for (long long v : vs)\
    \ es.push_back({v, y, 0, true});\n        } else {\n            // y = 1 \u306A\
    \u3089\u30B3\u30B9\u30C8 g\u3001y = 0 \u306F vs \u304C\u3059\u3079\u3066 0 \u306E\
    \u3068\u304D\u3060\u3051\n            es.push_back({-1, y, g, false});\n     \
    \       for (long long v : vs) es.push_back({y, v, 0, true});\n        }\n   \
    \ }\n\n    /**\n     * @brief \u30B3\u30B9\u30C8\u306E\u548C\u306E\u6700\u5C0F\
    \u5024\n     */\n    Cost solve() {\n        const long long s = n + aux, t =\
    \ s + 1;\n        MaxFlow<Cost> mf(t + 1);\n        // \u5341\u5206\u5927\u304D\
    \u3044\u5BB9\u91CF: \u6709\u9650\u306E\u5BB9\u91CF\u306E\u548C + 1\n        Cost\
    \ inf = 1;\n        for (long long v = 0; v < n; v++) inf += cost1[v] > 0 ? cost1[v]\
    \ : -cost1[v];\n        for (const auto& e : es) {\n            if (!e.inf) inf\
    \ += e.cap;\n        }\n        Cost base = constant;\n        for (long long\
    \ v = 0; v < n; v++) {\n            if (cost1[v] > 0) {\n                // x_v\
    \ = 1 (\u7D42\u70B9\u5074) \u306A\u3089\u30B3\u30B9\u30C8: \u59CB\u70B9\u304B\u3089\
    \ v \u3078\u306E\u8FBA\n                mf.add_edge(s, v, cost1[v]);\n       \
    \     } else if (cost1[v] < 0) {\n                // x_v = 0 \u306A\u3089 -cost1[v]\
    \ \u591A\u304F\u304B\u304B\u308B\u3068\u8003\u3048\u3001\u5B9A\u6570\u304B\u3089\
    \u5F15\u304F\n                base += cost1[v];\n                mf.add_edge(v,\
    \ t, -cost1[v]);\n            }\n        }\n        for (const auto& e : es) {\n\
    \            // \u88DC\u52A9\u9802\u70B9\u3078\u306E\u8FBA\u306E -1 \u306F\u3001\
    \u59CB\u70B9 (from) \u304B\u7D42\u70B9 (to)\n            long long from = e.from\
    \ == -1 ? s : e.from, to = e.to == -1 ? t : e.to;\n            mf.add_edge(from,\
    \ to, e.inf ? inf : e.cap);\n        }\n        Cost f = mf.flow(s, t);\n    \
    \    std::vector<bool> reach = mf.min_cut(s);\n        result.assign(n, false);\n\
    \        for (long long v = 0; v < n; v++) result[v] = !reach[v];\n        return\
    \ base + f;\n    }\n    /**\n     * @brief \u76F4\u524D\u306E solve() \u3067\u6700\
    \u5C0F\u5024\u3092\u3068\u308B\u5272\u308A\u5F53\u3066 (x_v \u304C 1 \u306A\u3089\
    \ true)\n     */\n    const std::vector<bool>& assignment() const { return result;\
    \ }\n};\n#line 9 \"test/unittest/graph/project-selection.test.cpp\"\n\n#include\
    \ <functional>\n#include <iostream>\n#line 13 \"test/unittest/graph/project-selection.test.cpp\"\
    \n#include <random>\n#line 15 \"test/unittest/graph/project-selection.test.cpp\"\
    \n\nbool ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond\
    \ && ok) std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok =\
    \ false;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n    for (int rep =\
    \ 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n        ProjectSelection<long\
    \ long> ps(n);\n        // \u5272\u308A\u5F53\u3066 x \u306E\u30B3\u30B9\u30C8\
    \ (\u7981\u6B62\u3055\u308C\u305F\u5272\u308A\u5F53\u3066\u306F std::nullopt \u306E\
    \u4EE3\u308F\u308A\u306B\u5927\u304D\u3044\u5024)\n        std::vector<std::function<long\
    \ long(const std::vector<bool>&)>> terms;\n        const long long BIG = std::numeric_limits<long\
    \ long>::max() / 4;\n        auto rnd = [&](int lo, int hi) { return static_cast<long\
    \ long>(lo + static_cast<int>(rng() % (hi - lo + 1))); };\n        int q = rng()\
    \ % 15;\n        for (int i = 0; i < q; i++) {\n            int type = rng() %\
    \ 6;\n            long long u = rng() % n, v = rng() % n;\n            if (type\
    \ == 0) {\n                long long c0 = rnd(-10, 10), c1 = rnd(-10, 10);\n \
    \               ps.add_cost(u, c0, c1);\n                terms.push_back([=](const\
    \ std::vector<bool>& x) { return x[u] ? c1 : c0; });\n            } else if (type\
    \ == 1) {\n                bool a = rng() % 2;\n                long long c =\
    \ rnd(-10, 10);\n                ps.add_cost_if(u, a, c);\n                terms.push_back([=](const\
    \ std::vector<bool>& x) { return x[u] == a ? c : 0; });\n            } else if\
    \ (type == 2 && u != v) {\n                // \u52A3\u30E2\u30B8\u30E5\u30E9\u306B\
    \u306A\u308B\u307E\u3067 c01 \u3092\u5897\u3084\u3059\n                long long\
    \ c00 = rnd(-10, 10), c01 = rnd(-10, 10), c10 = rnd(-10, 10), c11 = rnd(-10, 10);\n\
    \                if (c01 + c10 < c00 + c11) c01 += c00 + c11 - c01 - c10 + rnd(0,\
    \ 3);\n                ps.add_cost(u, v, c00, c01, c10, c11);\n              \
    \  terms.push_back([=](const std::vector<bool>& x) { return x[u] ? (x[v] ? c11\
    \ : c10) : (x[v] ? c01 : c00); });\n            } else if (type == 3 && u != v)\
    \ {\n                bool a = rng() % 2, b = rng() % 2;\n                long\
    \ long c = a != b ? rnd(0, 10) : rnd(-10, 0);\n                ps.add_cost_if(u,\
    \ a, v, b, c);\n                terms.push_back([=](const std::vector<bool>& x)\
    \ { return x[u] == a && x[v] == b ? c : 0; });\n            } else if (type ==\
    \ 4 && u != v) {\n                bool a = rng() % 2;\n                ps.forbid(u,\
    \ a, v);\n                terms.push_back([=](const std::vector<bool>& x) { return\
    \ x[u] == a && x[v] == !a ? BIG : 0; });\n            } else if (type == 5) {\n\
    \                std::vector<long long> vs;\n                for (int k = 0; k\
    \ < n; k++)\n                    if (rng() % 3 == 0) vs.push_back(k);\n      \
    \          bool a = rng() % 2;\n                long long g = rnd(0, 10);\n  \
    \              ps.add_gain_if_all(vs, a, g);\n                terms.push_back([=](const\
    \ std::vector<bool>& x) {\n                    for (long long k : vs)\n      \
    \                  if (x[k] != a) return 0LL;\n                    return -g;\n\
    \                });\n            } else {\n                long long c = rnd(-5,\
    \ 5);\n                ps.add_constant(c);\n                terms.push_back([=](const\
    \ std::vector<bool>&) { return c; });\n            }\n        }\n        auto\
    \ cost = [&](const std::vector<bool>& x) {\n            long long s = 0;\n   \
    \         for (const auto& f : terms) {\n                long long c = f(x);\n\
    \                if (c == BIG) return BIG;\n                s += c;\n        \
    \    }\n            return s;\n        };\n        long long best = BIG;\n   \
    \     for (int mask = 0; mask < (1 << n); mask++) {\n            std::vector<bool>\
    \ x(n);\n            for (int k = 0; k < n; k++) x[k] = mask >> k & 1;\n     \
    \       best = std::min(best, cost(x));\n        }\n        long long got = ps.solve();\n\
    \        check(got == best, \"solve \u306E\u5024\");\n        check(static_cast<long\
    \ long>(ps.assignment().size()) == n && cost(ps.assignment()) == best, \"assignment\
    \ \u306E\u30B3\u30B9\u30C8\");\n    }\n\n    // \u5909\u6570 0 \u500B\n    {\n\
    \        ProjectSelection<long long> ps(0);\n        ps.add_constant(3);\n   \
    \     check(ps.solve() == 3 && ps.assignment().empty(), \"\u5909\u6570\u306A\u3057\
    \");\n    }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// ProjectSelection \u3092\u3001\u3059\u3079\u3066\u306E\u5272\u308A\u5F53\
    \u3066\u3092\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u3079\u308B\n// \u8CA0\u306E\u30B3\u30B9\u30C8\u3001\u52A3\u30E2\
    \u30B8\u30E5\u30E9\u306A 2 \u5909\u6570\u306E\u30B3\u30B9\u30C8\u3001\u7981\u6B62\
    \u3001\u3059\u3079\u3066\u540C\u3058\u306A\u3089\u5229\u5F97 \u3092\u542B\u3080\
    \n// solve() \u306E\u5024\u3068\u3001assignment() \u306E\u5272\u308A\u5F53\u3066\
    \u306E\u30B3\u30B9\u30C8\u304C\u6700\u5C0F\u5024\u3068\u4E00\u81F4\u3059\u308B\
    \u304B\u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/project-selection.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n#include <limits>\n#include <random>\n\
    #include <vector>\n\nbool ok = true;\nvoid check(bool cond, const char* what)\
    \ {\n    if (!cond && ok) std::cerr << \"failed: \" << what << std::endl;\n  \
    \  if (!cond) ok = false;\n}\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10\
    \ + 1;\n        ProjectSelection<long long> ps(n);\n        // \u5272\u308A\u5F53\
    \u3066 x \u306E\u30B3\u30B9\u30C8 (\u7981\u6B62\u3055\u308C\u305F\u5272\u308A\u5F53\
    \u3066\u306F std::nullopt \u306E\u4EE3\u308F\u308A\u306B\u5927\u304D\u3044\u5024\
    )\n        std::vector<std::function<long long(const std::vector<bool>&)>> terms;\n\
    \        const long long BIG = std::numeric_limits<long long>::max() / 4;\n  \
    \      auto rnd = [&](int lo, int hi) { return static_cast<long long>(lo + static_cast<int>(rng()\
    \ % (hi - lo + 1))); };\n        int q = rng() % 15;\n        for (int i = 0;\
    \ i < q; i++) {\n            int type = rng() % 6;\n            long long u =\
    \ rng() % n, v = rng() % n;\n            if (type == 0) {\n                long\
    \ long c0 = rnd(-10, 10), c1 = rnd(-10, 10);\n                ps.add_cost(u, c0,\
    \ c1);\n                terms.push_back([=](const std::vector<bool>& x) { return\
    \ x[u] ? c1 : c0; });\n            } else if (type == 1) {\n                bool\
    \ a = rng() % 2;\n                long long c = rnd(-10, 10);\n              \
    \  ps.add_cost_if(u, a, c);\n                terms.push_back([=](const std::vector<bool>&\
    \ x) { return x[u] == a ? c : 0; });\n            } else if (type == 2 && u !=\
    \ v) {\n                // \u52A3\u30E2\u30B8\u30E5\u30E9\u306B\u306A\u308B\u307E\
    \u3067 c01 \u3092\u5897\u3084\u3059\n                long long c00 = rnd(-10,\
    \ 10), c01 = rnd(-10, 10), c10 = rnd(-10, 10), c11 = rnd(-10, 10);\n         \
    \       if (c01 + c10 < c00 + c11) c01 += c00 + c11 - c01 - c10 + rnd(0, 3);\n\
    \                ps.add_cost(u, v, c00, c01, c10, c11);\n                terms.push_back([=](const\
    \ std::vector<bool>& x) { return x[u] ? (x[v] ? c11 : c10) : (x[v] ? c01 : c00);\
    \ });\n            } else if (type == 3 && u != v) {\n                bool a =\
    \ rng() % 2, b = rng() % 2;\n                long long c = a != b ? rnd(0, 10)\
    \ : rnd(-10, 0);\n                ps.add_cost_if(u, a, v, b, c);\n           \
    \     terms.push_back([=](const std::vector<bool>& x) { return x[u] == a && x[v]\
    \ == b ? c : 0; });\n            } else if (type == 4 && u != v) {\n         \
    \       bool a = rng() % 2;\n                ps.forbid(u, a, v);\n           \
    \     terms.push_back([=](const std::vector<bool>& x) { return x[u] == a && x[v]\
    \ == !a ? BIG : 0; });\n            } else if (type == 5) {\n                std::vector<long\
    \ long> vs;\n                for (int k = 0; k < n; k++)\n                   \
    \ if (rng() % 3 == 0) vs.push_back(k);\n                bool a = rng() % 2;\n\
    \                long long g = rnd(0, 10);\n                ps.add_gain_if_all(vs,\
    \ a, g);\n                terms.push_back([=](const std::vector<bool>& x) {\n\
    \                    for (long long k : vs)\n                        if (x[k]\
    \ != a) return 0LL;\n                    return -g;\n                });\n   \
    \         } else {\n                long long c = rnd(-5, 5);\n              \
    \  ps.add_constant(c);\n                terms.push_back([=](const std::vector<bool>&)\
    \ { return c; });\n            }\n        }\n        auto cost = [&](const std::vector<bool>&\
    \ x) {\n            long long s = 0;\n            for (const auto& f : terms)\
    \ {\n                long long c = f(x);\n                if (c == BIG) return\
    \ BIG;\n                s += c;\n            }\n            return s;\n      \
    \  };\n        long long best = BIG;\n        for (int mask = 0; mask < (1 <<\
    \ n); mask++) {\n            std::vector<bool> x(n);\n            for (int k =\
    \ 0; k < n; k++) x[k] = mask >> k & 1;\n            best = std::min(best, cost(x));\n\
    \        }\n        long long got = ps.solve();\n        check(got == best, \"\
    solve \u306E\u5024\");\n        check(static_cast<long long>(ps.assignment().size())\
    \ == n && cost(ps.assignment()) == best, \"assignment \u306E\u30B3\u30B9\u30C8\
    \");\n    }\n\n    // \u5909\u6570 0 \u500B\n    {\n        ProjectSelection<long\
    \ long> ps(0);\n        ps.add_constant(3);\n        check(ps.solve() == 3 &&\
    \ ps.assignment().empty(), \"\u5909\u6570\u306A\u3057\");\n    }\n\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/project-selection.hpp
  - src/graph/max-flow.hpp
  isVerificationFile: true
  path: test/unittest/graph/project-selection.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/project-selection.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/project-selection.test.cpp
- /verify/test/unittest/graph/project-selection.test.cpp.html
title: test/unittest/graph/project-selection.test.cpp
---
