---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
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
  bundledCode: "#line 1 \"test/unittest/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// UnionFind \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u9023\u7D50\u6210\u5206\
    \u306E\u756A\u53F7\u3092\u4ED8\u3051\u76F4\u3059) \u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/unionfind.hpp\"\n\n\
    /**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u7121\
    \u5411\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\
    \u300D\u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\
    \u3092\u3059\u308B\n */\nclass UnionFind {\n   protected:\n    int _n;\n    //\
    \ \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA\n \
    \   std::vector<int> parent_or_size;\n\n   public:\n    /**\n     * @brief merge\
    \ \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b)) \u3067\u65B0\u3057\
    \u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\u304D\u3001\n   \
    \  * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct MergeResult {\n        int leader;   //!<\
    \ \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool merged;  //!< \u65B0\
    \u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\u3082\u3068\u540C\u3058\
    \u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit operator bool()\
    \ const { return merged; }\n    };\n\n    UnionFind() : _n(0) {}\n    explicit\
    \ UnionFind(int n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     * @brief\
    \ \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\u306E\u4EE3\
    \u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\n   \
    \  */\n    MergeResult merge(int a, int b) {\n        assert(0 <= a && a < _n);\n\
    \        assert(0 <= b && b < _n);\n        int x = leader(a), y = leader(b);\n\
    \        if (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return {x, true};\n    }\n    /**\n     * @brief \u9802\u70B9\
    a,b\u304C\u9023\u7D50\u304B\u3069\u3046\u304B\n     */\n    bool same(int a, int\
    \ b) {\n        assert(0 <= a && a < _n);\n        assert(0 <= b && b < _n);\n\
    \        return leader(a) == leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9\
    a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n  \
    \   */\n    int leader(int a) {\n        assert(0 <= a && a < _n);\n        if\
    \ (parent_or_size[a] < 0) return a;\n        int x = a;\n        while (parent_or_size[x]\
    \ >= 0) {\n            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    int size(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\u3001\u305D\
    \u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\u306E\u9023\
    \u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u300D\
    \u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> leader_buf(_n), group_size(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n            group_size[leader_buf[i]]++;\n\
    \        }\n        std::vector<std::vector<int>> result(_n);\n        for (int\
    \ i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n     \
    \   }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\
    };\n#line 7 \"test/unittest/unionfind.test.cpp\"\n\n#line 9 \"test/unittest/unionfind.test.cpp\"\
    \n#include <iostream>\n#include <random>\n#line 12 \"test/unittest/unionfind.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n     \
    \   // \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u3067\u4F5C\u3063\u3066\u304B\u3089\u4EE3\u5165\u3059\u308B\n        UnionFind\
    \ uf;\n        uf = UnionFind(n);\n        std::vector<int> comp(n);\n       \
    \ for (int i = 0; i < n; i++) comp[i] = i;\n        for (int t = 0; t < 15; t++)\
    \ {\n            int a = rng() % n, b = rng() % n;\n            auto res = uf.merge(a,\
    \ b);\n            bool expect_merged = comp[a] != comp[b];\n            if (res.merged\
    \ != expect_merged || static_cast<bool>(res) != expect_merged) ok = false;\n \
    \           int ca = comp[a], cb = comp[b];\n            for (int& c : comp) {\n\
    \                if (c == cb) c = ca;\n            }\n            if (uf.leader(a)\
    \ != res.leader) ok = false;\n            for (int x = 0; x < n; x++) {\n    \
    \            // size: \u540C\u3058\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u6570\
    \n                if (uf.size(x) != (int)std::count(comp.begin(), comp.end(),\
    \ comp[x])) ok = false;\n            }\n            // groups: \u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8 (\u5404\u30EA\u30B9\
    \u30C8\u306F\u6607\u9806)\n            std::vector<std::vector<int>> expect;\n\
    \            std::vector<int> seen(n, -1);\n            for (int x = 0; x < n;\
    \ x++) {\n                if (seen[comp[x]] == -1) {\n                    seen[comp[x]]\
    \ = expect.size();\n                    expect.push_back({});\n              \
    \  }\n                expect[seen[comp[x]]].push_back(x);\n            }\n   \
    \         auto g = uf.groups();\n            std::sort(g.begin(), g.end());\n\
    \            std::sort(expect.begin(), expect.end());\n            if (g != expect)\
    \ ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// UnionFind \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u9023\u7D50\u6210\u5206\
    \u306E\u756A\u53F7\u3092\u4ED8\u3051\u76F4\u3059) \u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/unionfind.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 10 + 1;\n     \
    \   // \u30C7\u30D5\u30A9\u30EB\u30C8\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \u3067\u4F5C\u3063\u3066\u304B\u3089\u4EE3\u5165\u3059\u308B\n        UnionFind\
    \ uf;\n        uf = UnionFind(n);\n        std::vector<int> comp(n);\n       \
    \ for (int i = 0; i < n; i++) comp[i] = i;\n        for (int t = 0; t < 15; t++)\
    \ {\n            int a = rng() % n, b = rng() % n;\n            auto res = uf.merge(a,\
    \ b);\n            bool expect_merged = comp[a] != comp[b];\n            if (res.merged\
    \ != expect_merged || static_cast<bool>(res) != expect_merged) ok = false;\n \
    \           int ca = comp[a], cb = comp[b];\n            for (int& c : comp) {\n\
    \                if (c == cb) c = ca;\n            }\n            if (uf.leader(a)\
    \ != res.leader) ok = false;\n            for (int x = 0; x < n; x++) {\n    \
    \            // size: \u540C\u3058\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u6570\
    \n                if (uf.size(x) != (int)std::count(comp.begin(), comp.end(),\
    \ comp[x])) ok = false;\n            }\n            // groups: \u9023\u7D50\u6210\
    \u5206\u3054\u3068\u306E\u9802\u70B9\u306E\u30EA\u30B9\u30C8 (\u5404\u30EA\u30B9\
    \u30C8\u306F\u6607\u9806)\n            std::vector<std::vector<int>> expect;\n\
    \            std::vector<int> seen(n, -1);\n            for (int x = 0; x < n;\
    \ x++) {\n                if (seen[comp[x]] == -1) {\n                    seen[comp[x]]\
    \ = expect.size();\n                    expect.push_back({});\n              \
    \  }\n                expect[seen[comp[x]]].push_back(x);\n            }\n   \
    \         auto g = uf.groups();\n            std::sort(g.begin(), g.end());\n\
    \            std::sort(expect.begin(), expect.end());\n            if (g != expect)\
    \ ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/unionfind.hpp
  isVerificationFile: true
  path: test/unittest/unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/unionfind.test.cpp
- /verify/test/unittest/unionfind.test.cpp.html
title: test/unittest/unionfind.test.cpp
---
