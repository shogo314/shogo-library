---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/rollback-unionfind.hpp
    title: "\u5DFB\u304D\u623B\u3057\u306E\u3067\u304D\u308B UnionFind"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/rollback-unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#line 2 \"src/data_structures/rollback-unionfind.hpp\"\n\n/**\n * @file rollback-unionfind.hpp\n\
    \ * @brief \u5DFB\u304D\u623B\u3057\u306E\u3067\u304D\u308B UnionFind\n */\n\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"src/data_structures/unionfind.hpp\"\
    \n\n/**\n * @file unionfind.hpp\n * @brief UnionFind\n */\n\n#include <algorithm>\n\
    #line 12 \"src/data_structures/unionfind.hpp\"\n\nnamespace internal_unionfind\
    \ {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\u8868\u5143\u304B\u3089\u3001\
    \u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\u7D20\u306E\u30EA\u30B9\u30C8\
    \u3092\u4F5C\u308B\n * @param leader \u8981\u7D20 a \u306E\u4EE3\u8868\u5143\u3092\
    \u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename F>\nstd::vector<std::vector<long\
    \ long>> groups(long long n, F leader) {\n    std::vector<long long> leader_buf(n),\
    \ group_size(n);\n    for (long long i = 0; i < n; i++) {\n        leader_buf[i]\
    \ = leader(i);\n        group_size[leader_buf[i]]++;\n    }\n    std::vector<std::vector<long\
    \ long>> result(n);\n    for (long long i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n\
    \    }\n    for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
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
    \ a) { return leader(a); });\n    }\n};\n#line 13 \"src/data_structures/rollback-unionfind.hpp\"\
    \n\n/**\n * @brief union by size \u3092\u4F7F\u3044\u3001\u7D4C\u8DEF\u5727\u7E2E\
    \u3092\u305B\u305A\u306B\u66F4\u65B0\u5C65\u6B74\u3092\u6B8B\u3059 UnionFind\n\
    \ */\nclass RollbackUnionFind : private UnionFind {\n    struct Change {\n   \
    \     int x, y, size_x, size_y;\n    };\n    std::vector<Change> history;\n\n\
    \   public:\n    using MergeResult = UnionFind::MergeResult;\n\n    explicit RollbackUnionFind(long\
    \ long n = 0) : UnionFind(n) { assert(n >= 0); }\n\n    long long leader(long\
    \ long a) const {\n        assert(0 <= a && a < _n);\n        while (parent_or_size[a]\
    \ >= 0) a = parent_or_size[a];\n        return a;\n    }\n    bool same(long long\
    \ a, long long b) const { return leader(a) == leader(b); }\n    long long size(long\
    \ long a) const { return -parent_or_size[leader(a)]; }\n\n    MergeResult merge(long\
    \ long a, long long b) {\n        long long x = leader(a), y = leader(b);\n  \
    \      if (x == y) return {x, false};\n        if (-parent_or_size[x] < -parent_or_size[y])\
    \ std::swap(x, y);\n        history.push_back({static_cast<int>(x), static_cast<int>(y),\
    \ parent_or_size[x], parent_or_size[y]});\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = static_cast<int>(x);\n        return {x, true};\n\
    \    }\n\n    /** @brief \u73FE\u5728\u306E\u5C65\u6B74\u306E\u4F4D\u7F6E\u3002\
    \u540C\u3058\u6210\u5206\u3092 merge \u3057\u3066\u3082\u5897\u3048\u306A\u3044\
    \ */\n    long long snapshot() const { return static_cast<long long>(history.size());\
    \ }\n    /** @brief \u73FE\u5728\u306E\u5C65\u6B74\u4E0A\u306E\u3001snapshot \u3067\
    \u53D6\u5F97\u3057\u305F\u4F4D\u7F6E\u307E\u3067\u5DFB\u304D\u623B\u3059 */\n\
    \    void rollback(long long t) {\n        assert(0 <= t && t <= snapshot());\n\
    \        while (snapshot() > t) {\n            const auto c = history.back();\n\
    \            history.pop_back();\n            parent_or_size[c.x] = c.size_x;\n\
    \            parent_or_size[c.y] = c.size_y;\n        }\n    }\n    std::vector<std::vector<long\
    \ long>> groups() const {\n        return internal_unionfind::groups(_n, [&](long\
    \ long a) { return leader(a); });\n    }\n};\n#line 4 \"test/unittest/data_structures/rollback-unionfind.test.cpp\"\
    \n\n#line 6 \"test/unittest/data_structures/rollback-unionfind.test.cpp\"\n#include\
    \ <iostream>\n#include <random>\n#line 9 \"test/unittest/data_structures/rollback-unionfind.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    RollbackUnionFind empty;\n \
    \   empty.rollback(0);\n    if (empty.snapshot() != 0 || !empty.groups().empty())\
    \ return 1;\n    for (int rep = 0; rep < 300; ++rep) {\n        int n = rng()\
    \ % 20 + 1;\n        RollbackUnionFind uf(n);\n        std::vector<UnionFind>\
    \ states{UnionFind(n)};\n        for (int q = 0; q < 150; ++q) {\n           \
    \ if (rng() % 3 != 0) {\n                int a = rng() % n, b = rng() % n;\n \
    \               auto next = states.back();\n                auto expect = next.merge(a,\
    \ b);\n                auto [root, merged] = uf.merge(a, b);\n               \
    \ if (merged != expect.merged || root != uf.leader(a)) return 1;\n           \
    \     if (merged) states.push_back(std::move(next));\n            } else {\n \
    \               long long t = rng() % states.size();\n                uf.rollback(t);\n\
    \                states.resize(t + 1);\n            }\n            if (uf.snapshot()\
    \ != static_cast<long long>(states.size()) - 1) return 1;\n            const auto&\
    \ current = uf;\n            for (int a = 0; a < n; ++a) {\n                if\
    \ (current.size(a) != states.back().size(a)) return 1;\n                for (int\
    \ b = 0; b < n; ++b) {\n                    if (current.same(a, b) != states.back().same(a,\
    \ b)) return 1;\n                }\n            }\n            auto groups = current.groups(),\
    \ expected = states.back().groups();\n            std::sort(groups.begin(), groups.end());\n\
    \            std::sort(expected.begin(), expected.end());\n            if (groups\
    \ != expected) return 1;\n        }\n        auto copy = uf;\n        copy.rollback(0);\n\
    \        if (uf.snapshot() != static_cast<long long>(states.size()) - 1) return\
    \ 1;\n        for (int a = 0; a < n; ++a)\n            if (copy.size(a) != 1)\
    \ return 1;\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n#include \"../../../src/data_structures/rollback-unionfind.hpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <random>\n#include <vector>\n\nint\
    \ main() {\n    std::mt19937 rng(314);\n    RollbackUnionFind empty;\n    empty.rollback(0);\n\
    \    if (empty.snapshot() != 0 || !empty.groups().empty()) return 1;\n    for\
    \ (int rep = 0; rep < 300; ++rep) {\n        int n = rng() % 20 + 1;\n       \
    \ RollbackUnionFind uf(n);\n        std::vector<UnionFind> states{UnionFind(n)};\n\
    \        for (int q = 0; q < 150; ++q) {\n            if (rng() % 3 != 0) {\n\
    \                int a = rng() % n, b = rng() % n;\n                auto next\
    \ = states.back();\n                auto expect = next.merge(a, b);\n        \
    \        auto [root, merged] = uf.merge(a, b);\n                if (merged !=\
    \ expect.merged || root != uf.leader(a)) return 1;\n                if (merged)\
    \ states.push_back(std::move(next));\n            } else {\n                long\
    \ long t = rng() % states.size();\n                uf.rollback(t);\n         \
    \       states.resize(t + 1);\n            }\n            if (uf.snapshot() !=\
    \ static_cast<long long>(states.size()) - 1) return 1;\n            const auto&\
    \ current = uf;\n            for (int a = 0; a < n; ++a) {\n                if\
    \ (current.size(a) != states.back().size(a)) return 1;\n                for (int\
    \ b = 0; b < n; ++b) {\n                    if (current.same(a, b) != states.back().same(a,\
    \ b)) return 1;\n                }\n            }\n            auto groups = current.groups(),\
    \ expected = states.back().groups();\n            std::sort(groups.begin(), groups.end());\n\
    \            std::sort(expected.begin(), expected.end());\n            if (groups\
    \ != expected) return 1;\n        }\n        auto copy = uf;\n        copy.rollback(0);\n\
    \        if (uf.snapshot() != static_cast<long long>(states.size()) - 1) return\
    \ 1;\n        for (int a = 0; a < n; ++a)\n            if (copy.size(a) != 1)\
    \ return 1;\n    }\n    std::cout << \"Hello World\\n\";\n}\n"
  dependsOn:
  - src/data_structures/rollback-unionfind.hpp
  - src/data_structures/unionfind.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/rollback-unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-11-08 23:19:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/rollback-unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/rollback-unionfind.test.cpp
- /verify/test/unittest/data_structures/rollback-unionfind.test.cpp.html
title: test/unittest/data_structures/rollback-unionfind.test.cpp
---
