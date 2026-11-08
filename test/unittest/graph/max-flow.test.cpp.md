---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/max-flow.hpp
    title: "\u6700\u5927\u6D41 (Dinic \u6CD5)"
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
  bundledCode: "#line 1 \"test/unittest/graph/max-flow.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ MaxFlow \u3092\u3001\u9802\u70B9\u306E\u5206\u3051\u65B9\u3092\u3059\u3079\u3066\
    \u8A66\u3057\u3066\u6C42\u3081\u305F\u6700\u5C0F\u30AB\u30C3\u30C8\u3068\u6BD4\
    \u3079\u308B\u3002change_edge \u3082\u78BA\u304B\u3081\u308B\n// \u578B\u3092\u7701\
    \u3044\u305F\u3068\u304D\u306B long long \u306B\u306A\u308B\u3053\u3068\u3082\
    \ static_assert \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/max-flow.hpp\"\
    \n\n/**\n * @file max-flow.hpp\n * @brief \u6700\u5927\u6D41 (Dinic \u6CD5)\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u6700\u5927\
    \u6D41 (Dinic \u6CD5)\n *\n * O(n^2 m) \u3060\u304C\u3001\u5B9F\u969B\u306B\u306F\
    \u305A\u3063\u3068\u901F\u3044\u3053\u3068\u304C\u591A\u3044\u3002\u5BB9\u91CF\
    \u304C\u3059\u3079\u3066 1 \u306A\u3089 O(m min(m^(1/2), n^(2/3)))\n * \u4F8B\
    :\n * MaxFlow<long long> mf(n);\n * mf.add_edge(0, 1, 5);\n * long long f = mf.flow(s,\
    \ t);\n *\n * @tparam Cap \u5BB9\u91CF\u306E\u578B \u7701\u7565\u3057\u305F\u3089\
    \ long long\n */\ntemplate <typename Cap = long long>\nclass MaxFlow {\n   public:\n\
    \    /**\n     * @brief \u8FBA\u306E\u60C5\u5831\n     */\n    struct Edge {\n\
    \        long long from, to;\n        Cap cap;   //!< \u5BB9\u91CF\n        Cap\
    \ flow;  //!< \u6D41\u308C\u3066\u3044\u308B\u91CF\n    };\n\n   private:\n  \
    \  // \u5185\u90E8\u306E\u8FBA\u3068\u914D\u5217\u306F int \u3067\u6301\u3061\u3001\
    \u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\u308B\n    struct\
    \ InnerEdge {\n        int to, rev;\n        Cap cap;  // \u6B8B\u308A\u306E\u5BB9\
    \u91CF\n    };\n    long long n;\n    std::vector<std::vector<InnerEdge>> g;\n\
    \    std::vector<std::pair<int, int>> pos;  // \u8FFD\u52A0\u3057\u305F\u8FBA\u304C\
    \ g \u306E\u3069\u3053\u306B\u3042\u308B\u304B\n    std::vector<int> level, iter;\n\
    \    struct DfsFrame {\n        int v;\n        Cap up, flow;\n    };\n    std::vector<DfsFrame>\
    \ dfs_stack;\n\n    bool bfs(int s, int t) {\n        level.assign(n, -1);\n \
    \       level[s] = 0;\n        std::queue<int> que;\n        que.push(s);\n  \
    \      while (!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for (const auto& e : g[v]) {\n                if (e.cap > 0 && level[e.to]\
    \ == -1) {\n                    level[e.to] = level[v] + 1;\n                \
    \    que.push(e.to);\n                }\n            }\n        }\n        return\
    \ level[t] != -1;\n    }\n    // \u518D\u5E30 DFS \u306E\u547C\u3073\u51FA\u3057\
    \u3068\u3001\u5404\u9802\u70B9\u304B\u3089\u8FD4\u3059\u6D41\u91CF\u3092\u660E\
    \u793A\u7684\u306A\u30B9\u30BF\u30C3\u30AF\u3067\u7BA1\u7406\u3059\u308B\u3002\
    \n    Cap dfs(int s, int t, Cap up) {\n        dfs_stack.clear();\n        dfs_stack.push_back({s,\
    \ up, 0});\n        while (!dfs_stack.empty()) {\n            auto& frame = dfs_stack.back();\n\
    \            const int v = frame.v;\n            if (v != t && frame.flow < frame.up)\
    \ {\n                int& i = iter[v];\n                while (i < static_cast<int>(g[v].size()))\
    \ {\n                    const auto& e = g[v][i];\n                    if (e.cap\
    \ > 0 && level[e.to] == level[v] + 1) break;\n                    ++i;\n     \
    \           }\n                if (i < static_cast<int>(g[v].size())) {\n    \
    \                const auto& e = g[v][i];\n                    Cap next_up = std::min(frame.up\
    \ - frame.flow, e.cap);\n                    dfs_stack.push_back({e.to, next_up,\
    \ 0});\n                    continue;\n                }\n                // \u3053\
    \u308C\u4EE5\u4E0A\u6D41\u305B\u306A\u3044\u306E\u3067\u3001\u3053\u306E\u30D5\
    \u30A7\u30FC\u30BA\u3067\u306F\u4F7F\u308F\u306A\u3044\u3002\n               \
    \ level[v] = n;\n            }\n            const Cap pushed = v == t ? frame.up\
    \ : frame.flow;\n            dfs_stack.pop_back();\n            if (dfs_stack.empty())\
    \ return pushed;\n            auto& parent = dfs_stack.back();\n            auto&\
    \ e = g[parent.v][iter[parent.v]];\n            e.cap -= pushed;\n           \
    \ g[v][e.rev].cap += pushed;\n            parent.flow += pushed;\n           \
    \ if (parent.flow < parent.up) ++iter[parent.v];\n        }\n        return 0;\n\
    \    }\n\n   public:\n    explicit MaxFlow(long long n = 0) : n(n), g(n) {}\n\n\
    \    long long size() const { return n; }\n\n    /**\n     * @brief from \u304B\
    \u3089 to \u3078\u306E\u5BB9\u91CF cap \u306E\u8FBA\u3092\u8FFD\u52A0\u3057\u3001\
    \u8FBA\u306E\u756A\u53F7 (\u8FFD\u52A0\u3057\u305F\u9806\u306B 0, 1, ...) \u3092\
    \u8FD4\u3059\n     */\n    long long add_edge(long long from, long long to, Cap\
    \ cap) {\n        assert(0 <= from && from < n && 0 <= to && to < n && cap >=\
    \ 0);\n        long long id = pos.size();\n        int from_id = g[from].size();\n\
    \        int to_id = g[to].size() + (from == to);\n        pos.emplace_back(from,\
    \ from_id);\n        g[from].push_back({static_cast<int>(to), to_id, cap});\n\
    \        g[to].push_back({static_cast<int>(from), from_id, 0});\n        return\
    \ id;\n    }\n\n    /**\n     * @brief s \u304B\u3089 t \u3078\u3001limit \u3092\
    \u4E0A\u9650\u3068\u3057\u3066\u3067\u304D\u308B\u3060\u3051\u6D41\u3057\u3001\
    \u6D41\u3057\u305F\u91CF\u3092\u8FD4\u3059\n     * \u4F55\u5EA6\u3082\u547C\u3076\
    \u3068\u3001\u524D\u56DE\u307E\u3067\u306E\u6D41\u308C\u306B\u8FFD\u52A0\u3057\
    \u3066\u6D41\u3059\n     */\n    Cap flow(long long s, long long t, Cap limit\
    \ = std::numeric_limits<Cap>::max()) {\n        assert(0 <= s && s < n && 0 <=\
    \ t && t < n && s != t);\n        Cap res = 0;\n        while (res < limit &&\
    \ bfs(s, t)) {\n            iter.assign(n, 0);\n            Cap f = dfs(s, t,\
    \ limit - res);\n            if (f == 0) break;\n            res += f;\n     \
    \   }\n        return res;\n    }\n\n    /**\n     * @brief \u756A\u53F7 i \u306E\
    \u8FBA\u306E\u60C5\u5831\n     */\n    Edge get_edge(long long i) const {\n  \
    \      assert(0 <= i && i < static_cast<long long>(pos.size()));\n        const\
    \ auto& e = g[pos[i].first][pos[i].second];\n        const auto& re = g[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n    }\n    /**\n\
    \     * @brief \u756A\u53F7 i \u306E\u8FBA\u306E\u5BB9\u91CF\u3092 new_cap \u306B\
    \u3001\u6D41\u308C\u3066\u3044\u308B\u91CF\u3092 new_flow \u306B\u5909\u3048\u308B\
    \n     * \u307B\u304B\u306E\u8FBA\u306E\u6D41\u91CF\u306F\u5909\u3048\u306A\u3044\
    \u306E\u3067\u3001\u6D41\u91CF\u306E\u4FDD\u5B58\u5247\u304C\u5D29\u308C\u308B\
    \u3053\u3068\u304C\u3042\u308B\n     */\n    void change_edge(long long i, Cap\
    \ new_cap, Cap new_flow) {\n        assert(0 <= i && i < static_cast<long long>(pos.size())\
    \ && 0 <= new_flow && new_flow <= new_cap);\n        auto& e = g[pos[i].first][pos[i].second];\n\
    \        auto& re = g[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n   \
    \     re.cap = new_flow;\n    }\n    /**\n     * @brief \u3059\u3079\u3066\u306E\
    \u8FBA\u306E\u60C5\u5831 (\u8FFD\u52A0\u3057\u305F\u9806)\n     */\n    std::vector<Edge>\
    \ edges() const {\n        std::vector<Edge> res;\n        for (long long i =\
    \ 0; i < static_cast<long long>(pos.size()); i++) res.push_back(get_edge(i));\n\
    \        return res;\n    }\n\n    /**\n     * @brief \u76F4\u524D\u306E flow(s,\
    \ t) \u306E\u5F8C\u3067\u3001\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 s \u304B\u3089\
    \u884C\u3051\u308B\u9802\u70B9\u304B\n     * flow(s, t) \u3067\u6D41\u3057\u304D\
    \u3063\u3066\u3044\u308C\u3070\u3001true \u306E\u9802\u70B9\u306E\u96C6\u5408\u304C\
    \u6700\u5C0F\u30AB\u30C3\u30C8\u306E s \u5074\u306B\u306A\u308B\n     */\n   \
    \ std::vector<bool> min_cut(long long s) const {\n        std::vector<bool> visited(n);\n\
    \        std::vector<long long> st = {s};\n        visited[s] = true;\n      \
    \  while (!st.empty()) {\n            long long v = st.back();\n            st.pop_back();\n\
    \            for (const auto& e : g[v]) {\n                if (e.cap > 0 && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    st.push_back(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    };\n#line 8 \"test/unittest/graph/max-flow.test.cpp\"\n\n#include <iostream>\n\
    #include <random>\n#include <tuple>\n#include <type_traits>\n#line 14 \"test/unittest/graph/max-flow.test.cpp\"\
    \n\nstatic_assert(std::is_same_v<decltype(MaxFlow(3)), MaxFlow<long long>>);\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    // \u518D\
    \u5E30\u3067\u306F\u30B9\u30BF\u30C3\u30AF\u304C\u8DB3\u308A\u306A\u304F\u306A\
    \u308B\u6DF1\u3044\u4E00\u672C\u9053\u3002\n    {\n        constexpr int N = 200000;\n\
    \        MaxFlow<> mf(N);\n        for (int i = 0; i + 1 < N; i++) mf.add_edge(i,\
    \ i + 1, 3);\n        if (mf.flow(0, N - 1, 1) != 1 || mf.flow(0, N - 1) != 2)\
    \ ok = false;\n        for (const auto& e : mf.edges()) {\n            if (e.flow\
    \ != 3) ok = false;\n        }\n    }\n    // \u9577\u3044\u5171\u901A\u7D4C\u8DEF\
    \u306E\u5148\u306B\u591A\u6570\u306E\u5206\u5C90\u304C\u3042\u308B\u3002\u5171\
    \u901A\u7D4C\u8DEF\u3092\u5897\u52A0\u8DEF\u3054\u3068\u306B\u305F\u3069\u308A\
    \u76F4\u3055\u306A\u3044\u3002\n    {\n        constexpr int DEPTH = 150000, BRANCHES\
    \ = 50000, SINK = DEPTH + BRANCHES;\n        MaxFlow<> mf(SINK + 1);\n       \
    \ for (int i = 0; i + 1 < DEPTH; i++) mf.add_edge(i, i + 1, BRANCHES);\n     \
    \   for (int i = 0; i < BRANCHES; i++) {\n            mf.add_edge(DEPTH - 1, DEPTH\
    \ + i, 1);\n            mf.add_edge(DEPTH + i, SINK, 1);\n        }\n        if\
    \ (mf.flow(0, SINK) != BRANCHES || mf.flow(0, SINK) != 0) ok = false;\n    }\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 7 +\
    \ 2, m = rng() % 15;\n        int s = rng() % n, t = rng() % (n - 1);\n      \
    \  if (t >= s) t++;\n        std::vector<std::tuple<int, int, long long>> es;\n\
    \        MaxFlow<long long> mf(n);\n        for (int i = 0; i < m; i++) {\n  \
    \          int u = rng() % n, v = rng() % n;  // \u81EA\u5DF1\u30EB\u30FC\u30D7\
    \u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n            long long c = rng() %\
    \ 10;\n            es.emplace_back(u, v, c);\n            if (mf.add_edge(u, v,\
    \ c) != i) ok = false;\n        }\n        // \u6700\u5C0F\u30AB\u30C3\u30C8:\
    \ s \u3092\u542B\u307F t \u3092\u542B\u307E\u306A\u3044\u9802\u70B9\u96C6\u5408\
    \ S \u304B\u3089\u51FA\u308B\u8FBA\u306E\u5BB9\u91CF\u306E\u548C\u306E\u6700\u5C0F\
    \u5024\n        long long best = -1;\n        for (int mask = 0; mask < (1 <<\
    \ n); mask++) {\n            if (!(mask >> s & 1) || (mask >> t & 1)) continue;\n\
    \            long long cut = 0;\n            for (auto [u, v, c] : es) {\n   \
    \             if ((mask >> u & 1) && !(mask >> v & 1)) cut += c;\n           \
    \ }\n            if (best == -1 || cut < best) best = cut;\n        }\n      \
    \  // \u4E0A\u9650\u3064\u304D\u3067 2 \u56DE\u306B\u5206\u3051\u3066\u6D41\u3057\
    \u3066\u3082\u3001\u5408\u8A08\u306F\u540C\u3058\n        long long limit = rng()\
    \ % (best + 1);\n        long long f = mf.flow(s, t, limit);\n        if (f !=\
    \ limit) ok = false;\n        f += mf.flow(s, t);\n        if (f != best) ok =\
    \ false;\n\n        // \u5404\u8FBA\u306E\u6D41\u91CF\u304C\u5BB9\u91CF\u4EE5\u4E0B\
    \u3067\u3001s \u3068 t \u4EE5\u5916\u3067\u6D41\u91CF\u304C\u4FDD\u5B58\u3055\u308C\
    \u308B\n        std::vector<long long> balance(n);\n        auto edges = mf.edges();\n\
    \        for (int i = 0; i < m; i++) {\n            auto [u, v, c] = es[i];\n\
    \            auto e = mf.get_edge(i);\n            if (e.from != u || e.to !=\
    \ v || e.cap != c || e.flow < 0 || e.flow > c) ok = false;\n            if (edges[i].flow\
    \ != e.flow) ok = false;\n            balance[u] -= e.flow;\n            balance[v]\
    \ += e.flow;\n        }\n        for (int v = 0; v < n; v++) {\n            if\
    \ (v == s && balance[v] != -f) ok = false;\n            if (v == t && balance[v]\
    \ != f) ok = false;\n            if (v != s && v != t && balance[v] != 0) ok =\
    \ false;\n        }\n        // min_cut \u306E\u9802\u70B9\u96C6\u5408\u304C\u6700\
    \u5C0F\u30AB\u30C3\u30C8\u306B\u306A\u3063\u3066\u3044\u308B\n        auto cut\
    \ = mf.min_cut(s);\n        long long cap = 0;\n        for (auto [u, v, c] :\
    \ es) {\n            if (cut[u] && !cut[v]) cap += c;\n        }\n        if (!cut[s]\
    \ || cut[t] || cap != f) ok = false;\n\n        // change_edge \u3067\u6D41\u91CF\
    \u3092 0 \u306B\u623B\u3059\u3068\u3001\u3082\u3046\u4E00\u5EA6\u540C\u3058\u3060\
    \u3051\u6D41\u305B\u308B\n        for (int i = 0; i < m; i++) mf.change_edge(i,\
    \ std::get<2>(es[i]), 0);\n        for (int i = 0; i < m; i++) {\n           \
    \ if (mf.get_edge(i).flow != 0) ok = false;\n        }\n        if (mf.flow(s,\
    \ t) != best) ok = false;\n        // \u5BB9\u91CF\u3092 0 \u306B\u3057\u305F\u8FBA\
    \u306B\u306F\u6D41\u308C\u306A\u3044\n        int k = m == 0 ? -1 : static_cast<int>(rng()\
    \ % m);\n        if (k != -1) {\n            mf.change_edge(k, 0, 0);\n      \
    \      if (mf.get_edge(k).cap != 0 || mf.get_edge(k).flow != 0) ok = false;\n\
    \        }\n    }\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else {\n        std::cerr << \"failed\" << std::endl;\n        return 1;\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// MaxFlow \u3092\u3001\u9802\u70B9\u306E\u5206\u3051\u65B9\u3092\u3059\u3079\
    \u3066\u8A66\u3057\u3066\u6C42\u3081\u305F\u6700\u5C0F\u30AB\u30C3\u30C8\u3068\
    \u6BD4\u3079\u308B\u3002change_edge \u3082\u78BA\u304B\u3081\u308B\n// \u578B\u3092\
    \u7701\u3044\u305F\u3068\u304D\u306B long long \u306B\u306A\u308B\u3053\u3068\u3082\
    \ static_assert \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\
    \u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089\
    \ Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/graph/max-flow.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <tuple>\n#include <type_traits>\n\
    #include <vector>\n\nstatic_assert(std::is_same_v<decltype(MaxFlow(3)), MaxFlow<long\
    \ long>>);\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    // \u518D\u5E30\u3067\u306F\u30B9\u30BF\u30C3\u30AF\u304C\u8DB3\u308A\u306A\
    \u304F\u306A\u308B\u6DF1\u3044\u4E00\u672C\u9053\u3002\n    {\n        constexpr\
    \ int N = 200000;\n        MaxFlow<> mf(N);\n        for (int i = 0; i + 1 < N;\
    \ i++) mf.add_edge(i, i + 1, 3);\n        if (mf.flow(0, N - 1, 1) != 1 || mf.flow(0,\
    \ N - 1) != 2) ok = false;\n        for (const auto& e : mf.edges()) {\n     \
    \       if (e.flow != 3) ok = false;\n        }\n    }\n    // \u9577\u3044\u5171\
    \u901A\u7D4C\u8DEF\u306E\u5148\u306B\u591A\u6570\u306E\u5206\u5C90\u304C\u3042\
    \u308B\u3002\u5171\u901A\u7D4C\u8DEF\u3092\u5897\u52A0\u8DEF\u3054\u3068\u306B\
    \u305F\u3069\u308A\u76F4\u3055\u306A\u3044\u3002\n    {\n        constexpr int\
    \ DEPTH = 150000, BRANCHES = 50000, SINK = DEPTH + BRANCHES;\n        MaxFlow<>\
    \ mf(SINK + 1);\n        for (int i = 0; i + 1 < DEPTH; i++) mf.add_edge(i, i\
    \ + 1, BRANCHES);\n        for (int i = 0; i < BRANCHES; i++) {\n            mf.add_edge(DEPTH\
    \ - 1, DEPTH + i, 1);\n            mf.add_edge(DEPTH + i, SINK, 1);\n        }\n\
    \        if (mf.flow(0, SINK) != BRANCHES || mf.flow(0, SINK) != 0) ok = false;\n\
    \    }\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng()\
    \ % 7 + 2, m = rng() % 15;\n        int s = rng() % n, t = rng() % (n - 1);\n\
    \        if (t >= s) t++;\n        std::vector<std::tuple<int, int, long long>>\
    \ es;\n        MaxFlow<long long> mf(n);\n        for (int i = 0; i < m; i++)\
    \ {\n            int u = rng() % n, v = rng() % n;  // \u81EA\u5DF1\u30EB\u30FC\
    \u30D7\u3068\u591A\u91CD\u8FBA\u3082\u542B\u3080\n            long long c = rng()\
    \ % 10;\n            es.emplace_back(u, v, c);\n            if (mf.add_edge(u,\
    \ v, c) != i) ok = false;\n        }\n        // \u6700\u5C0F\u30AB\u30C3\u30C8\
    : s \u3092\u542B\u307F t \u3092\u542B\u307E\u306A\u3044\u9802\u70B9\u96C6\u5408\
    \ S \u304B\u3089\u51FA\u308B\u8FBA\u306E\u5BB9\u91CF\u306E\u548C\u306E\u6700\u5C0F\
    \u5024\n        long long best = -1;\n        for (int mask = 0; mask < (1 <<\
    \ n); mask++) {\n            if (!(mask >> s & 1) || (mask >> t & 1)) continue;\n\
    \            long long cut = 0;\n            for (auto [u, v, c] : es) {\n   \
    \             if ((mask >> u & 1) && !(mask >> v & 1)) cut += c;\n           \
    \ }\n            if (best == -1 || cut < best) best = cut;\n        }\n      \
    \  // \u4E0A\u9650\u3064\u304D\u3067 2 \u56DE\u306B\u5206\u3051\u3066\u6D41\u3057\
    \u3066\u3082\u3001\u5408\u8A08\u306F\u540C\u3058\n        long long limit = rng()\
    \ % (best + 1);\n        long long f = mf.flow(s, t, limit);\n        if (f !=\
    \ limit) ok = false;\n        f += mf.flow(s, t);\n        if (f != best) ok =\
    \ false;\n\n        // \u5404\u8FBA\u306E\u6D41\u91CF\u304C\u5BB9\u91CF\u4EE5\u4E0B\
    \u3067\u3001s \u3068 t \u4EE5\u5916\u3067\u6D41\u91CF\u304C\u4FDD\u5B58\u3055\u308C\
    \u308B\n        std::vector<long long> balance(n);\n        auto edges = mf.edges();\n\
    \        for (int i = 0; i < m; i++) {\n            auto [u, v, c] = es[i];\n\
    \            auto e = mf.get_edge(i);\n            if (e.from != u || e.to !=\
    \ v || e.cap != c || e.flow < 0 || e.flow > c) ok = false;\n            if (edges[i].flow\
    \ != e.flow) ok = false;\n            balance[u] -= e.flow;\n            balance[v]\
    \ += e.flow;\n        }\n        for (int v = 0; v < n; v++) {\n            if\
    \ (v == s && balance[v] != -f) ok = false;\n            if (v == t && balance[v]\
    \ != f) ok = false;\n            if (v != s && v != t && balance[v] != 0) ok =\
    \ false;\n        }\n        // min_cut \u306E\u9802\u70B9\u96C6\u5408\u304C\u6700\
    \u5C0F\u30AB\u30C3\u30C8\u306B\u306A\u3063\u3066\u3044\u308B\n        auto cut\
    \ = mf.min_cut(s);\n        long long cap = 0;\n        for (auto [u, v, c] :\
    \ es) {\n            if (cut[u] && !cut[v]) cap += c;\n        }\n        if (!cut[s]\
    \ || cut[t] || cap != f) ok = false;\n\n        // change_edge \u3067\u6D41\u91CF\
    \u3092 0 \u306B\u623B\u3059\u3068\u3001\u3082\u3046\u4E00\u5EA6\u540C\u3058\u3060\
    \u3051\u6D41\u305B\u308B\n        for (int i = 0; i < m; i++) mf.change_edge(i,\
    \ std::get<2>(es[i]), 0);\n        for (int i = 0; i < m; i++) {\n           \
    \ if (mf.get_edge(i).flow != 0) ok = false;\n        }\n        if (mf.flow(s,\
    \ t) != best) ok = false;\n        // \u5BB9\u91CF\u3092 0 \u306B\u3057\u305F\u8FBA\
    \u306B\u306F\u6D41\u308C\u306A\u3044\n        int k = m == 0 ? -1 : static_cast<int>(rng()\
    \ % m);\n        if (k != -1) {\n            mf.change_edge(k, 0, 0);\n      \
    \      if (mf.get_edge(k).cap != 0 || mf.get_edge(k).flow != 0) ok = false;\n\
    \        }\n    }\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else {\n        std::cerr << \"failed\" << std::endl;\n        return 1;\n\
    \    }\n}\n"
  dependsOn:
  - src/graph/max-flow.hpp
  isVerificationFile: true
  path: test/unittest/graph/max-flow.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 23:01:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/graph/max-flow.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/graph/max-flow.test.cpp
- /verify/test/unittest/graph/max-flow.test.cpp.html
title: test/unittest/graph/max-flow.test.cpp
---
