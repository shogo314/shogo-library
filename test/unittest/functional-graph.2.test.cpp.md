---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/functional-graph.hpp
    title: "\u30D5\u30A1\u30F3\u30AF\u30B7\u30E7\u30CA\u30EB\u30B0\u30E9\u30D5"
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
  bundledCode: "#line 1 \"test/unittest/functional-graph.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ FunctionalGraph \u306E\u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3001\u9802\u70B9\u6570\u3092\u6E21\u3059\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3068 read() \u3092\u691C\u8A3C\u3059\u308B\n// read()\
    \ \u306F std::cin \u3092\u6587\u5B57\u5217\u306B\u5DEE\u3057\u66FF\u3048\u3066\
    \u8AAD\u307E\u305B\u3001vector \u304B\u3089\u4F5C\u3063\u305F\u3082\u306E\u3068\
    \u7D50\u679C\u3092\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/graph/functional-graph.hpp\"\
    \n\n/**\n * @file functional-graph.hpp\n * @brief \u30D5\u30A1\u30F3\u30AF\u30B7\
    \u30E7\u30CA\u30EB\u30B0\u30E9\u30D5\n */\n#include <algorithm>\n#include <cassert>\n\
    #include <iostream>\n#include <vector>\n\n/**\n * @brief N\u9802\u70B9N\u8FBA\u306E\
    \u6709\u5411\u30B0\u30E9\u30D5\u3067\u3001\u3059\u3079\u3066\u306E\u9802\u70B9\
    \u306E\u51FA\u6B21\u6570\u304C1\n */\nstruct FunctionalGraph {\n    int n;   \
    \                                //!< \u9802\u70B9\u6570\n    std::vector<int>\
    \ g;                      //!< \u30B0\u30E9\u30D5\n    std::vector<bool> is_cycle;\
    \              //!< \u30B5\u30A4\u30AF\u30EB\u4E0A\u306E\u9802\u70B9\u304B\n \
    \   std::vector<int> depth;                  //!< \u30B5\u30A4\u30AF\u30EB\u4E0A\
    \u306E\u9802\u70B9\u307E\u3067\u306E\u8DDD\u96E2\n    std::vector<int> root; \
    \                  //!< \u6700\u3082\u8FD1\u3044\u30B5\u30A4\u30AF\u30EB\u4E0A\
    \u306E\u9802\u70B9\n    std::vector<std::vector<int>> groups;    //!< \u5404\u9023\
    \u7D50\u6210\u5206\u306E\u30EA\u30B9\u30C8\n    std::vector<std::vector<int>>\
    \ cycles;    //!< \u5404\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30AF\u30EB\
    \n    std::vector<int> group_id;               //!< \u305D\u306E\u9802\u70B9\u304C\
    \u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306Eindex\n    std::vector<int> root_index;\
    \             //!< root\u306Ecycles\u4E0A\u306Eindex\n    std::vector<std::vector<int>>\
    \ doubling;  //!< DoublingClimbTree\n\n    void build() {\n        assert((int)g.size()\
    \ == n);\n        for (int i = 0; i < n; i++) assert(0 <= g[i] && g[i] < n);\n\
    \        is_cycle.assign(n, false);\n        depth.assign(n, 0);\n        root.assign(n,\
    \ -1);\n        group_id.assign(n, 0);\n        root_index.assign(n, 0);\n   \
    \     groups.clear();\n        cycles.clear();\n        std::vector<bool> visited(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (visited[i]) continue;\n\
    \            std::vector<int> v;\n            int u = i;\n            while (!visited[u])\
    \ {\n                visited[u] = true;\n                v.push_back(u);\n   \
    \             u = g[u];\n            }\n            if (root[u] == -1) {\n   \
    \             int k = std::find(v.begin(), v.end(), u) - v.begin();\n        \
    \        cycles.push_back({});\n                groups.push_back({});\n      \
    \          for (int j = 0; j < k; j++) {\n                    is_cycle[v[j]] =\
    \ false;\n                    root[v[j]] = u;\n                    root_index[v[j]]\
    \ = 0;\n                    group_id[v[j]] = cycles.size() - 1;\n            \
    \        depth[v[j]] = k - j;\n                    groups.back().push_back(v[j]);\n\
    \                }\n                for (int j = k; j < (int)v.size(); j++) {\n\
    \                    is_cycle[v[j]] = true;\n                    root[v[j]] =\
    \ v[j];\n                    cycles.back().push_back(v[j]);\n                \
    \    root_index[v[j]] = cycles.back().size() - 1;\n                    group_id[v[j]]\
    \ = cycles.size() - 1;\n                    depth[v[j]] = 0;\n               \
    \     groups.back().push_back(v[j]);\n                }\n            } else {\n\
    \                for (int j = 0; j < (int)v.size(); j++) {\n                 \
    \   is_cycle[v[j]] = false;\n                    root[v[j]] = root[u];\n     \
    \               root_index[v[j]] = root_index[u];\n                    group_id[v[j]]\
    \ = group_id[u];\n                    depth[v[j]] = depth[u] + v.size() - j;\n\
    \                    groups[group_id[u]].push_back(v[j]);\n                }\n\
    \            }\n        }\n        doubling.assign(n, {});\n        std::vector<int>\
    \ tmp;\n        for (int i = 0; i < n; i++) {\n            if (is_cycle[i]) continue;\n\
    \            tmp.push_back(i);\n            doubling[i].push_back(g[i]);\n   \
    \     }\n        for (int k = 0; !tmp.empty(); k++) {\n            std::vector<int>\
    \ next_tmp;\n            for (int i : tmp) {\n                if (k < (int)doubling[doubling[i][k]].size())\
    \ {\n                    doubling[i].push_back(doubling[doubling[i][k]][k]);\n\
    \                    next_tmp.push_back(i);\n                }\n            }\n\
    \            tmp.swap(next_tmp);\n        }\n    }\n\n    /**\n     * @brief \u30C7\
    \u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     */\n\
    \    FunctionalGraph() : n(0), g(0) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     * @param n \u9802\u70B9\u6570\n     */\n    explicit\
    \ FunctionalGraph(int n) : n(n), g(n) {}\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     * @param g i -> g[i]\n     */\n    explicit FunctionalGraph(std::vector<int>\
    \ g) : n(g.size()), g(g) {\n        build();\n    }\n    /**\n     * @brief \u9802\
    \u70B9\u6570\n     */\n    int size() const { return n; }\n    /**\n     * @brief\
    \ \u8FBA\u306E\u60C5\u5831\u3092\u6A19\u6E96\u5165\u529B\u304B\u3089\u53D7\u3051\
    \u53D6\u3063\u3066\u8FFD\u52A0\u3059\u308B\n     * @param padding \u9802\u70B9\
    \u756A\u53F7\u3092\u5165\u529B\u304B\u3089\u3044\u304F\u3064\u305A\u3089\u3059\
    \u304B \u7701\u7565\u3057\u305F\u3089-1\n     */\n    void read(int padding =\
    \ -1) {\n        for (int i = 0; i < n; i++) {\n            std::cin >> g[i];\n\
    \            g[i] += padding;\n        }\n        build();\n    }\n    /**\n \
    \    * @brief \u9802\u70B9x\u304B\u3089k\u56DE\u79FB\u52D5\u3057\u305F\u9802\u70B9\
    \n     *\n     * @param x 0 <= x < n\n     * @param k 0 <= k\n     * @return int\
    \ \u9802\u70B9\u756A\u53F7\n     */\n    int hop(int x, long long k) const {\n\
    \        assert(0 <= x && x < n && k >= 0);\n        if (k >= depth[x]) {\n  \
    \          k -= depth[x];\n            x = root[x];\n            k %= cycles[group_id[x]].size();\n\
    \            int y = root_index[x] + k;\n            if ((int)cycles[group_id[x]].size()\
    \ <= y) {\n                y -= cycles[group_id[x]].size();\n            }\n \
    \           return cycles[group_id[x]][y];\n        }\n        for (int i = 0;\
    \ k; i++) {\n            if (k & 1) {\n                x = doubling[x][i];\n \
    \           }\n            k >>= 1;\n        }\n        return x;\n    }\n   \
    \ /**\n     * @brief \u9802\u70B9x\u304B\u30890\u56DE\u4EE5\u4E0A\u306E\u79FB\u52D5\
    \u3067\u305F\u3069\u308A\u7740\u3051\u308B\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    int hopable(int x) const {\n        assert(0 <= x && x < n);\n    \
    \    return depth[x] + (int)cycles[group_id[x]].size();\n    }\n};\n#line 8 \"\
    test/unittest/functional-graph.2.test.cpp\"\n\n#line 10 \"test/unittest/functional-graph.2.test.cpp\"\
    \n#include <random>\n#include <sstream>\n#include <string>\n#line 14 \"test/unittest/functional-graph.2.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n\n    FunctionalGraph\
    \ empty;\n    if (empty.n != 0 || !empty.g.empty()) ok = false;\n\n    std::streambuf*\
    \ original = std::cin.rdbuf();\n    for (int rep = 0; rep < 2000 && ok; rep++)\
    \ {\n        int n = rng() % 12 + 1;\n        std::vector<int> g(n);\n       \
    \ for (int& v : g) v = rng() % n;\n        FunctionalGraph expected(g);\n\n  \
    \      // padding \u306F\u7701\u7565\u6642 -1 (1-indexed \u306E\u5165\u529B) \u3068\
    \u30010 (0-indexed \u306E\u5165\u529B) \u306E\u4E21\u65B9\u3092\u8A66\u3059\n\
    \        for (int padding : {-1, 0}) {\n            std::string input;\n     \
    \       for (int v : g) input += std::to_string(v - padding) + \" \";\n      \
    \      std::istringstream iss(input);\n            std::cin.rdbuf(iss.rdbuf());\n\
    \            FunctionalGraph fg(n);\n            if (fg.n != n || (int)fg.g.size()\
    \ != n) ok = false;\n            if (padding == -1)\n                fg.read();\n\
    \            else\n                fg.read(padding);\n            std::cin.rdbuf(original);\n\
    \n            if (fg.g != g) ok = false;\n            for (int x = 0; x < n; x++)\
    \ {\n                if (fg.is_cycle[x] != expected.is_cycle[x]) ok = false;\n\
    \                if (fg.hopable(x) != expected.hopable(x)) ok = false;\n     \
    \           for (long long k : {0LL, 1LL, (long long)n, (long long)(rng() % 1000000000000LL)})\
    \ {\n                    if (fg.hop(x, k) != expected.hop(x, k)) ok = false;\n\
    \                }\n            }\n        }\n    }\n    std::cin.rdbuf(original);\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// FunctionalGraph \u306E\u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3001\u9802\u70B9\u6570\u3092\u6E21\u3059\u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\u3068 read() \u3092\u691C\u8A3C\u3059\u308B\n// read()\
    \ \u306F std::cin \u3092\u6587\u5B57\u5217\u306B\u5DEE\u3057\u66FF\u3048\u3066\
    \u8AAD\u307E\u305B\u3001vector \u304B\u3089\u4F5C\u3063\u305F\u3082\u306E\u3068\
    \u7D50\u679C\u3092\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/graph/functional-graph.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <sstream>\n#include <string>\n\
    #include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok\
    \ = true;\n\n    FunctionalGraph empty;\n    if (empty.n != 0 || !empty.g.empty())\
    \ ok = false;\n\n    std::streambuf* original = std::cin.rdbuf();\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 12 + 1;\n     \
    \   std::vector<int> g(n);\n        for (int& v : g) v = rng() % n;\n        FunctionalGraph\
    \ expected(g);\n\n        // padding \u306F\u7701\u7565\u6642 -1 (1-indexed \u306E\
    \u5165\u529B) \u3068\u30010 (0-indexed \u306E\u5165\u529B) \u306E\u4E21\u65B9\u3092\
    \u8A66\u3059\n        for (int padding : {-1, 0}) {\n            std::string input;\n\
    \            for (int v : g) input += std::to_string(v - padding) + \" \";\n \
    \           std::istringstream iss(input);\n            std::cin.rdbuf(iss.rdbuf());\n\
    \            FunctionalGraph fg(n);\n            if (fg.n != n || (int)fg.g.size()\
    \ != n) ok = false;\n            if (padding == -1)\n                fg.read();\n\
    \            else\n                fg.read(padding);\n            std::cin.rdbuf(original);\n\
    \n            if (fg.g != g) ok = false;\n            for (int x = 0; x < n; x++)\
    \ {\n                if (fg.is_cycle[x] != expected.is_cycle[x]) ok = false;\n\
    \                if (fg.hopable(x) != expected.hopable(x)) ok = false;\n     \
    \           for (long long k : {0LL, 1LL, (long long)n, (long long)(rng() % 1000000000000LL)})\
    \ {\n                    if (fg.hop(x, k) != expected.hop(x, k)) ok = false;\n\
    \                }\n            }\n        }\n    }\n    std::cin.rdbuf(original);\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/graph/functional-graph.hpp
  isVerificationFile: true
  path: test/unittest/functional-graph.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 16:37:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/functional-graph.2.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/functional-graph.2.test.cpp
- /verify/test/unittest/functional-graph.2.test.cpp.html
title: test/unittest/functional-graph.2.test.cpp
---
