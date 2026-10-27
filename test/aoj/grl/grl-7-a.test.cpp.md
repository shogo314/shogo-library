---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/bipartite-matching.hpp
    title: "\u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\
      \u30B0 (Hopcroft-Karp \u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/grl/grl-7-a.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n\n#line 2 \"src/graph/bipartite-matching.hpp\"\n\n/**\n\
    \ * @file bipartite-matching.hpp\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\
    \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0 (Hopcroft-Karp \u6CD5)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief \u4E8C\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\
    \u30C3\u30C1\u30F3\u30B0 (Hopcroft-Karp \u6CD5)\n *\n * \u5DE6\u5074\u306E\u9802\
    \u70B9 0, ..., l-1 \u3068\u53F3\u5074\u306E\u9802\u70B9 0, ..., r-1 \u306E\u9593\
    \u306E\u8FBA\u304B\u3089\u3001\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\
    \u6C42\u3081\u308B\n * O(m \u221An)\u3002\u5897\u52A0\u8DEF\u3092\u63A2\u3059\
    \ DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * BipartiteMatching\
    \ bm(l, r);\n * bm.add_edge(0, 1);\n * long long k = bm.solve();\n */\nclass BipartiteMatching\
    \ {\n    long long l, r;\n    // \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\
    \u6301\u3061\u3001\u516C\u958B\u3059\u308B\u95A2\u6570\u3067 long long \u306B\u3059\
    \u308B\n    std::vector<std::vector<int>> g;\n    std::vector<int> match_l, match_r;\n\
    \n    // \u5DE6\u5074\u306E\u81EA\u7531\u306A\u9802\u70B9\u304B\u3089\u306E\u4EA4\
    \u4E92\u8DEF\u306E\u9577\u3055\u3067\u5C64\u3092\u4F5C\u308B\u3002\u5897\u52A0\
    \u8DEF\u304C\u3042\u308C\u3070 true\n    bool bfs(std::vector<int>& dist) const\
    \ {\n        dist.assign(l, -1);\n        std::queue<int> que;\n        for (int\
    \ u = 0; u < l; u++) {\n            if (match_l[u] == -1) {\n                dist[u]\
    \ = 0;\n                que.push(u);\n            }\n        }\n        bool found\
    \ = false;\n        while (!que.empty()) {\n            int u = que.front();\n\
    \            que.pop();\n            for (int v : g[u]) {\n                int\
    \ w = match_r[v];\n                if (w == -1) {\n                    found =\
    \ true;\n                } else if (dist[w] == -1) {\n                    dist[w]\
    \ = dist[u] + 1;\n                    que.push(w);\n                }\n      \
    \      }\n        }\n        return found;\n    }\n\n   public:\n    BipartiteMatching(long\
    \ long l, long long r) : l(l), r(r), g(l), match_l(l, -1), match_r(r, -1) {}\n\
    \n    /**\n     * @brief \u5DE6\u5074\u306E\u9802\u70B9\u6570\n     */\n    long\
    \ long left_size() const { return l; }\n    /**\n     * @brief \u53F3\u5074\u306E\
    \u9802\u70B9\u6570\n     */\n    long long right_size() const { return r; }\n\n\
    \    /**\n     * @brief \u5DE6\u5074\u306E\u9802\u70B9 u \u3068\u53F3\u5074\u306E\
    \u9802\u70B9 v \u306E\u9593\u306B\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\n     */\n\
    \    void add_edge(long long u, long long v) {\n        assert(0 <= u && u < l\
    \ && 0 <= v && v < r);\n        g[u].push_back(v);\n    }\n\n    /**\n     * @brief\
    \ \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u6C42\u3081\u3001\u305D\u306E\
    \u8FBA\u306E\u6570\u3092\u8FD4\u3059\n     * \u8FBA\u3092\u8FFD\u52A0\u3057\u3066\
    \u304B\u3089\u3082\u3046\u4E00\u5EA6\u547C\u3076\u3068\u3001\u524D\u56DE\u306E\
    \u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u5E83\u3052\u308B\n     */\n    long long\
    \ solve() {\n        std::vector<int> dist, iter(l);\n        std::vector<int>\
    \ st;\n        while (bfs(dist)) {\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            for (int s = 0; s < l; s++) {\n                if (match_l[s]\
    \ != -1) continue;\n                // st \u306F s \u304B\u3089\u306E\u4EA4\u4E92\
    \u8DEF\u306E\u5DE6\u5074\u306E\u9802\u70B9\u3002st[k] \u306F g[st[k]][iter[st[k]]]\
    \ \u3092\u901A\u3063\u3066\u6B21\u3078\u9032\u3080\n                st.assign(1,\
    \ s);\n                while (!st.empty()) {\n                    int u = st.back();\n\
    \                    if (iter[u] == static_cast<int>(g[u].size())) {\n       \
    \                 // u \u304B\u3089\u306F\u5897\u52A0\u8DEF\u304C\u306A\u3044\u306E\
    \u3067\u3001\u3053\u306E\u30D5\u30A7\u30FC\u30BA\u3067\u306F\u4F7F\u308F\u306A\
    \u3044\n                        dist[u] = -1;\n                        st.pop_back();\n\
    \                        if (!st.empty()) iter[st.back()]++;\n               \
    \         continue;\n                    }\n                    int v = g[u][iter[u]];\n\
    \                    int w = match_r[v];\n                    if (w == -1) {\n\
    \                        // \u5897\u52A0\u8DEF\u304C\u898B\u3064\u304B\u3063\u305F\
    \u306E\u3067\u3001\u4EA4\u4E92\u8DEF\u306B\u6CBF\u3063\u3066\u30DE\u30C3\u30C1\
    \u30F3\u30B0\u3092\u5165\u308C\u66FF\u3048\u308B\n                        for\
    \ (int x : st) {\n                            int y = g[x][iter[x]];\n       \
    \                     match_l[x] = y;\n                            match_r[y]\
    \ = x;\n                        }\n                        st.clear();\n     \
    \               } else if (dist[w] == dist[u] + 1) {\n                       \
    \ st.push_back(w);\n                    } else {\n                        iter[u]++;\n\
    \                    }\n                }\n            }\n        }\n        long\
    \ long res = 0;\n        for (int u = 0; u < l; u++) res += match_l[u] != -1;\n\
    \        return res;\n    }\n\n    /**\n     * @brief \u5DE6\u5074\u306E\u9802\
    \u70B9 u \u3068\u30DE\u30C3\u30C1\u3057\u305F\u53F3\u5074\u306E\u9802\u70B9 (\u306A\
    \u3051\u308C\u3070 -1)\u3002solve() \u306E\u5F8C\u3067\u4F7F\u3046\n     */\n\
    \    long long left_match(long long u) const {\n        assert(0 <= u && u < l);\n\
    \        return match_l[u];\n    }\n    /**\n     * @brief \u53F3\u5074\u306E\u9802\
    \u70B9 v \u3068\u30DE\u30C3\u30C1\u3057\u305F\u5DE6\u5074\u306E\u9802\u70B9 (\u306A\
    \u3051\u308C\u3070 -1)\u3002solve() \u306E\u5F8C\u3067\u4F7F\u3046\n     */\n\
    \    long long right_match(long long v) const {\n        assert(0 <= v && v <\
    \ r);\n        return match_r[v];\n    }\n    /**\n     * @brief \u30DE\u30C3\u30C1\
    \u30F3\u30B0\u306E\u8FBA (\u5DE6\u5074\u306E\u9802\u70B9, \u53F3\u5074\u306E\u9802\
    \u70B9) \u306E\u30EA\u30B9\u30C8 (\u5DE6\u5074\u306E\u9802\u70B9\u306E\u6607\u9806\
    )\u3002solve() \u306E\u5F8C\u3067\u4F7F\u3046\n     */\n    std::vector<std::pair<long\
    \ long, long long>> matching() const {\n        std::vector<std::pair<long long,\
    \ long long>> res;\n        for (long long u = 0; u < l; u++) {\n            if\
    \ (match_l[u] != -1) res.emplace_back(u, match_l[u]);\n        }\n        return\
    \ res;\n    }\n};\n#line 6 \"test/aoj/grl/grl-7-a.test.cpp\"\n\nint main() {\n\
    \    int x, y, m;\n    std::cin >> x >> y >> m;\n    BipartiteMatching bm(x, y);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        std::cin >> u >>\
    \ v;\n        bm.add_edge(u, v);\n    }\n    std::cout << bm.solve() << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include <iostream>\n\n#include \"../../../src/graph/bipartite-matching.hpp\"\
    \n\nint main() {\n    int x, y, m;\n    std::cin >> x >> y >> m;\n    BipartiteMatching\
    \ bm(x, y);\n    for (int i = 0; i < m; i++) {\n        int u, v;\n        std::cin\
    \ >> u >> v;\n        bm.add_edge(u, v);\n    }\n    std::cout << bm.solve() <<\
    \ '\\n';\n}\n"
  dependsOn:
  - src/graph/bipartite-matching.hpp
  isVerificationFile: true
  path: test/aoj/grl/grl-7-a.test.cpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/grl/grl-7-a.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/grl/grl-7-a.test.cpp
- /verify/test/aoj/grl/grl-7-a.test.cpp.html
title: test/aoj/grl/grl-7-a.test.cpp
---
