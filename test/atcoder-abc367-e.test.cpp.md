---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/functional-graph.hpp
    title: "\u30D5\u30A1\u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/abc367/tasks/abc367_e
  bundledCode: "#line 1 \"test/atcoder-abc367-e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc367/tasks/abc367_e\"\
    \n#define IGNORE\n\n#include <iostream>\n\n#line 2 \"graph/functional-graph.hpp\"\
    \n\n/**\n * @file functional-graph.hpp\n * @brief \u30D5\u30A1\u30F3\u30AF\u30B7\
    \u30E7\u30CA\u30EB\u30B0\u30E9\u30D5\n */\n#include <algorithm>\n#line 9 \"graph/functional-graph.hpp\"\
    \n#include <numeric>\n#include <set>\n#include <vector>\n\n/**\n * @brief N\u9802\
    \u70B9N\u8FBA\u306E\u6709\u5411\u30B0\u30E9\u30D5\u3067\u3001\u3059\u3079\u3066\
    \u306E\u9802\u70B9\u306E\u51FA\u6B21\u6570\u304C1\n */\nstruct FunctionalGraph\
    \ {\n    int n;                                         //!< \u9802\u70B9\u6570\
    \n    std::vector<int> g;                            //!< \u30B0\u30E9\u30D5\n\
    \    std::vector<bool> is_cycle;                    //!< \u30B5\u30A4\u30AF\u30EB\
    \u4E0A\u306E\u9802\u70B9\u304B\n    std::vector<int> depth;                  \
    \      //!< \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u307E\u3067\u306E\
    \u8DDD\u96E2\n    std::vector<int> root;                         //!< \u6700\u3082\
    \u8FD1\u3044\u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\n    std::vector<std::vector<int>>\
    \ connected_list;  //!< \u5404\u9023\u7D50\u6210\u5206\u306E\u30EA\u30B9\u30C8\
    \n    std::vector<std::vector<int>> cycle_list;      //!< \u5404\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30AF\u30EB\n    std::vector<int> connected_id;     \
    \            //!< \u305D\u306E\u9802\u70B9\u304C\u5C5E\u3059\u308B\u9023\u7D50\
    \u6210\u5206\u306Eindex\n    std::vector<int> root_idx;                     //!<\
    \ root\u306Ecycle_list\u4E0A\u306Eindex\n    std::vector<std::vector<int>> doubling;\
    \        //!< DoublingClimbTree\n\n    void build() {\n        is_cycle.assign(n,\
    \ false);\n        depth.assign(n, 0);\n        root.assign(n, -1);\n        connected_id.assign(n,\
    \ 0);\n        root_idx.assign(n, 0);\n        connected_list.clear();\n     \
    \   cycle_list.clear();\n        std::vector<bool> visited(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (visited[i]) continue;\n            std::vector<int>\
    \ v;\n            int u = i;\n            while (!visited[u]) {\n            \
    \    visited[u] = true;\n                v.push_back(u);\n                u =\
    \ g[u];\n            }\n            if (root[u] == -1) {\n                int\
    \ k = std::find(v.begin(), v.end(), u) - v.begin();\n                cycle_list.push_back({});\n\
    \                connected_list.push_back({});\n                for (int j = 0;\
    \ j < k; j++) {\n                    is_cycle[v[j]] = false;\n               \
    \     root[v[j]] = u;\n                    root_idx[v[j]] = 0;\n             \
    \       connected_id[v[j]] = cycle_list.size() - 1;\n                    depth[v[j]]\
    \ = k - j;\n                    connected_list.back().push_back(v[j]);\n     \
    \           }\n                for (int j = k; j < (int)v.size(); j++) {\n   \
    \                 is_cycle[v[j]] = true;\n                    root[v[j]] = v[j];\n\
    \                    cycle_list.back().push_back(v[j]);\n                    root_idx[v[j]]\
    \ = cycle_list.back().size() - 1;\n                    connected_id[v[j]] = cycle_list.size()\
    \ - 1;\n                    depth[v[j]] = 0;\n                    connected_list.back().push_back(v[j]);\n\
    \                }\n            } else {\n                for (int j = 0; j <\
    \ (int)v.size(); j++) {\n                    is_cycle[v[j]] = false;\n       \
    \             root[v[j]] = root[u];\n                    root_idx[v[j]] = root_idx[u];\n\
    \                    connected_id[v[j]] = connected_id[u];\n                 \
    \   depth[v[j]] = depth[u] + v.size() - j;\n                    connected_list[connected_id[u]].push_back(v[j]);\n\
    \                }\n            }\n        }\n        doubling.assign(n, {});\n\
    \        std::vector<int> tmp;\n        for (int i = 0; i < n; i++) {\n      \
    \      if (is_cycle[i]) continue;\n            tmp.push_back(i);\n           \
    \ doubling[i].push_back(g[i]);\n        }\n        for (int k = 0; !tmp.empty();\
    \ k++) {\n            std::vector<int> next_tmp;\n            for (int i : tmp)\
    \ {\n                if (k < (int)doubling[doubling[i][k]].size()) {\n       \
    \             doubling[i].push_back(doubling[doubling[i][k]][k]);\n          \
    \          next_tmp.push_back(i);\n                }\n            }\n        \
    \    tmp.swap(next_tmp);\n        }\n    }\n\n    /**\n     * @brief \u30C7\u30D5\
    \u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n    FunctionalGraph()\
    \ : n(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit FunctionalGraph(int\
    \ n) : n(n), g(n) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\n     * @param g i -> g[i]\n     */\n    explicit FunctionalGraph(std::vector<int>\
    \ g) : n(g.size()), g(g) {\n        build();\n    }\n    /**\n     * @brief \u8FBA\
    \u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\u53D6\
    \u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param padding \u9802\u70B9\u756A\
    \u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\u304B\
    \ \u7701\u7565\u3057\u305F\u3089-1\n     */\n    void read(int padding = -1) {\n\
    \        for (int i = 0; i < n; i++) {\n            std::cin >> g[i];\n      \
    \      g[i] += padding;\n        }\n        build();\n    }\n    /**\n     * @brief\
    \ \u9802\u70B9x\u304B\u3089k\u56DE\u79FB\u52D5\u3057\u305F\u9802\u70B9\n     *\n\
    \     * @param x 0 <= x < n\n     * @param k 0 <= k\n     * @return int \u9802\
    \u70B9\u756A\u53F7\n     */\n    int hop(int x, long long k) const {\n       \
    \ if (k >= depth[x]) {\n            k -= depth[x];\n            x = root[x];\n\
    \            k %= cycle_list[connected_id[x]].size();\n            int y = root_idx[x]\
    \ + k;\n            if ((int)cycle_list[connected_id[x]].size() <= y) {\n    \
    \            y -= cycle_list[connected_id[x]].size();\n            }\n       \
    \     return cycle_list[connected_id[x]][y];\n        }\n        for (int i =\
    \ 0; k; i++) {\n            if (k & 1) {\n                x = doubling[x][i];\n\
    \            }\n            k >>= 1;\n        }\n        return x;\n    }\n  \
    \  /**\n     * @brief \u9802\u70B9x\u304B\u30890\u56DE\u4EE5\u4E0A\u306E\u79FB\
    \u52D5\u3067\u305F\u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u500B\u6570\
    \n     */\n    int hopable(int x) const {\n        return depth[x] + (int)cycle_list[connected_id[x]].size();\n\
    \    }\n};\n#line 7 \"test/atcoder-abc367-e.test.cpp\"\n\nint main(void) {\n \
    \   int N;\n    long long K;\n    std::cin >> N >> K;\n    FunctionalGraph fg(N);\n\
    \    fg.read();\n    std::vector<int> A(N);\n    for (int& a : A) std::cin >>\
    \ a;\n    for (int i = 0; i < N; i++) {\n        std::cout << A[fg.hop(i, K)];\n\
    \        if (i == N - 1) {\n            std::cout << std::endl;\n        } else\
    \ {\n            std::cout << ' ';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc367/tasks/abc367_e\"\n#define\
    \ IGNORE\n\n#include <iostream>\n\n#include \"../graph/functional-graph.hpp\"\n\
    \nint main(void) {\n    int N;\n    long long K;\n    std::cin >> N >> K;\n  \
    \  FunctionalGraph fg(N);\n    fg.read();\n    std::vector<int> A(N);\n    for\
    \ (int& a : A) std::cin >> a;\n    for (int i = 0; i < N; i++) {\n        std::cout\
    \ << A[fg.hop(i, K)];\n        if (i == N - 1) {\n            std::cout << std::endl;\n\
    \        } else {\n            std::cout << ' ';\n        }\n    }\n}\n"
  dependsOn:
  - graph/functional-graph.hpp
  isVerificationFile: true
  path: test/atcoder-abc367-e.test.cpp
  requiredBy: []
  timestamp: '2026-10-10 12:56:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder-abc367-e.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder-abc367-e.test.cpp
- /verify/test/atcoder-abc367-e.test.cpp.html
title: test/atcoder-abc367-e.test.cpp
---
