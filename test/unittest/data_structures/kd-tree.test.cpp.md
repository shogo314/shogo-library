---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/kd-tree.hpp
    title: kd-tree
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
  bundledCode: "#line 1 \"test/unittest/data_structures/kd-tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// kd-tree.hpp \u306E KDTree \u306E enumerate \u3068 count \u3092\u3001\u3059\
    \u3079\u3066\u306E\u70B9\u3092\u8ABF\u3079\u305F\u3082\u306E\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u540C\u3058\u5EA7\u6A19\u306E\u70B9\u3001\
    \u7A7A\u306E\u96C6\u5408\u3001\u7A7A\u306E\u9577\u65B9\u5F62\u3082\u8ABF\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#line 2 \"src/data_structures/kd-tree.hpp\"\n\n/**\n * @file kd-tree.hpp\n\
    \ * @brief kd-tree\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <numeric>\n#include <utility>\n#include <vector>\n\n/**\n * @brief 2 \u6B21\u5143\
    \u306E\u70B9\u306E\u96C6\u5408 (\u9759\u7684) \u306B\u3064\u3044\u3066\u3001\u9577\
    \u65B9\u5F62\u9818\u57DF\u306B\u5165\u308B\u70B9\u3092\u5217\u6319\u3059\u308B\
    \ kd-tree\n *\n * x \u3068 y \u3067\u4EA4\u4E92\u306B\u4E2D\u592E\u5024\u3067\u5206\
    \u3051\u3001\u5404\u90E8\u5206\u6728\u306E\u70B9\u3092\u56F2\u3080\u9577\u65B9\
    \u5F62\u3092\u6301\u3064\u3002\u69CB\u7BC9 O(n log n)\u3001\n * \u5217\u6319\u306F\
    \ O(\u221An + \u5217\u6319\u3059\u308B\u500B\u6570)\u3001\u500B\u6570\u3092\u6570\
    \u3048\u308B\u306E\u3082 O(\u221An)\n * \u4F8B:\n * KDTree<long long> kd(points);\
    \  // points[i] = {x, y}\n * auto ids = kd.enumerate(xl, xr, yl, yr);  // xl <=\
    \ x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\u306E\u6DFB\u5B57\n *\n * @tparam\
    \ T \u5EA7\u6A19\u306E\u578B\n */\ntemplate <typename T>\nclass KDTree {\n   \
    \ long long n;\n    std::vector<long long> ord;  // \u6728\u306E\u9806\u306B\u4E26\
    \u3079\u305F\u70B9\u306E\u6DFB\u5B57\n    std::vector<T> x, y;         // \u6728\
    \u306E\u9806\u306B\u4E26\u3079\u305F\u5EA7\u6A19\n    // [l, r) \u306E\u90E8\u5206\
    \u6728\u306E\u70B9\u3092\u56F2\u3080\u9577\u65B9\u5F62\u3092\u3001\u4E2D\u592E\
    \ m = (l + r) / 2 \u306E\u4F4D\u7F6E\u306B\u6301\u3064\n    std::vector<T> min_x,\
    \ max_x, min_y, max_y;\n\n    void build(long long l, long long r, bool by_x,\
    \ const std::vector<std::pair<T, T>>& points) {\n        if (l >= r) return;\n\
    \        long long m = (l + r) / 2;\n        std::nth_element(ord.begin() + l,\
    \ ord.begin() + m, ord.begin() + r, [&](long long i, long long j) {\n        \
    \    return by_x ? points[i].first < points[j].first : points[i].second < points[j].second;\n\
    \        });\n        build(l, m, !by_x, points);\n        build(m + 1, r, !by_x,\
    \ points);\n        min_x[m] = max_x[m] = points[ord[m]].first;\n        min_y[m]\
    \ = max_y[m] = points[ord[m]].second;\n        // \u5B50\u306E\u90E8\u5206\u6728\
    \u304C\u7A7A\u3067\u306A\u3051\u308C\u3070\u3001\u305D\u306E\u9577\u65B9\u5F62\
    \u3092\u5408\u308F\u305B\u308B\n        for (long long c : {l < m ? (l + m) /\
    \ 2 : -1, m + 1 < r ? (m + 1 + r) / 2 : -1}) {\n            if (c == -1) continue;\n\
    \            min_x[m] = std::min(min_x[m], min_x[c]), max_x[m] = std::max(max_x[m],\
    \ max_x[c]);\n            min_y[m] = std::min(min_y[m], min_y[c]), max_y[m] =\
    \ std::max(max_y[m], max_y[c]);\n        }\n    }\n    // \u9577\u65B9\u5F62\u306B\
    \u5165\u308B\u70B9\u3092\u30011 \u70B9\u305A\u3064 point(i) \u3067\u3001\u90E8\
    \u5206\u6728\u3054\u3068\u5165\u308B\u306A\u3089 range(l, r) \u3067\u5831\u544A\
    \u3059\u308B (i, l, r \u306F\u6728\u306E\u9806\u306E\u4F4D\u7F6E)\n    template\
    \ <typename F, typename G>\n    void query(long long l, long long r, T xl, T xr,\
    \ T yl, T yr, const F& point, const G& range) const {\n        if (l >= r) return;\n\
    \        long long m = (l + r) / 2;\n        if (max_x[m] < xl || xr <= min_x[m]\
    \ || max_y[m] < yl || yr <= min_y[m]) return;\n        if (xl <= min_x[m] && max_x[m]\
    \ < xr && yl <= min_y[m] && max_y[m] < yr) {\n            range(l, r);\n     \
    \       return;\n        }\n        if (xl <= x[m] && x[m] < xr && yl <= y[m]\
    \ && y[m] < yr) point(m);\n        query(l, m, xl, xr, yl, yr, point, range);\n\
    \        query(m + 1, r, xl, xr, yl, yr, point, range);\n    }\n\n   public:\n\
    \    /**\n     * @brief \u70B9 i \u306E\u5EA7\u6A19\u304C points[i] = {x, y} \u306E\
    \ kd-tree \u3092\u4F5C\u308B\n     */\n    explicit KDTree(const std::vector<std::pair<T,\
    \ T>>& points)\n        : n(points.size()), ord(n), x(n), y(n), min_x(n), max_x(n),\
    \ min_y(n), max_y(n) {\n        std::iota(ord.begin(), ord.end(), 0);\n      \
    \  build(0, n, true, points);\n        for (long long i = 0; i < n; i++) x[i]\
    \ = points[ord[i]].first, y[i] = points[ord[i]].second;\n    }\n    /**\n    \
    \ * @brief \u70B9\u306E\u500B\u6570\n     */\n    long long size() const { return\
    \ n; }\n    /**\n     * @brief xl <= x < xr \u304B\u3064 yl <= y < yr \u306E\u70B9\
    \u306E\u6DFB\u5B57 (\u9806\u4E0D\u540C)\n     */\n    std::vector<long long> enumerate(T\
    \ xl, T xr, T yl, T yr) const {\n        std::vector<long long> res;\n       \
    \ query(0, n, xl, xr, yl, yr, [&](long long i) { res.push_back(ord[i]); }, [&](long\
    \ long l, long long r) { res.insert(res.end(), ord.begin() + l, ord.begin() +\
    \ r); });\n        return res;\n    }\n    /**\n     * @brief xl <= x < xr \u304B\
    \u3064 yl <= y < yr \u306E\u70B9\u306E\u500B\u6570\n     */\n    long long count(T\
    \ xl, T xr, T yl, T yr) const {\n        long long res = 0;\n        query(0,\
    \ n, xl, xr, yl, yr, [&](long long) { res++; }, [&](long long l, long long r)\
    \ { res += r - l; });\n        return res;\n    }\n};\n#line 8 \"test/unittest/data_structures/kd-tree.test.cpp\"\
    \n\n#line 10 \"test/unittest/data_structures/kd-tree.test.cpp\"\n#include <iostream>\n\
    #include <random>\n#line 14 \"test/unittest/data_structures/kd-tree.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 40, w = rng()\
    \ % 2 ? 4 : 100;\n        std::vector<std::pair<long long, long long>> p(n);\n\
    \        for (auto& [x, y] : p) x = static_cast<long long>(rng() % (2 * w + 1))\
    \ - w, y = static_cast<long long>(rng() % (2 * w + 1)) - w;\n        KDTree<long\
    \ long> kd(p);\n        if (kd.size() != n) ok = false;\n        for (int q =\
    \ 0; q < 30 && ok; q++) {\n            long long xl = static_cast<long long>(rng()\
    \ % (2 * w + 3)) - w - 1, xr = static_cast<long long>(rng() % (2 * w + 3)) - w\
    \ - 1;\n            long long yl = static_cast<long long>(rng() % (2 * w + 3))\
    \ - w - 1, yr = static_cast<long long>(rng() % (2 * w + 3)) - w - 1;\n       \
    \     if (rng() % 4 && xl > xr) std::swap(xl, xr);\n            if (rng() % 4\
    \ && yl > yr) std::swap(yl, yr);\n            std::vector<long long> expected;\n\
    \            for (int i = 0; i < n; i++) {\n                if (xl <= p[i].first\
    \ && p[i].first < xr && yl <= p[i].second && p[i].second < yr) expected.push_back(i);\n\
    \            }\n            auto ids = kd.enumerate(xl, xr, yl, yr);\n       \
    \     std::sort(ids.begin(), ids.end());\n            if (ids != expected || kd.count(xl,\
    \ xr, yl, yr) != static_cast<long long>(expected.size())) ok = false;\n      \
    \  }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// kd-tree.hpp \u306E KDTree \u306E enumerate \u3068 count \u3092\u3001\u3059\
    \u3079\u3066\u306E\u70B9\u3092\u8ABF\u3079\u305F\u3082\u306E\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u540C\u3058\u5EA7\u6A19\u306E\u70B9\u3001\
    \u7A7A\u306E\u96C6\u5408\u3001\u7A7A\u306E\u9577\u65B9\u5F62\u3082\u8ABF\u3079\
    \u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/data_structures/kd-tree.hpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#include <utility>\n#include <vector>\n\
    \nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 40, w = rng() %\
    \ 2 ? 4 : 100;\n        std::vector<std::pair<long long, long long>> p(n);\n \
    \       for (auto& [x, y] : p) x = static_cast<long long>(rng() % (2 * w + 1))\
    \ - w, y = static_cast<long long>(rng() % (2 * w + 1)) - w;\n        KDTree<long\
    \ long> kd(p);\n        if (kd.size() != n) ok = false;\n        for (int q =\
    \ 0; q < 30 && ok; q++) {\n            long long xl = static_cast<long long>(rng()\
    \ % (2 * w + 3)) - w - 1, xr = static_cast<long long>(rng() % (2 * w + 3)) - w\
    \ - 1;\n            long long yl = static_cast<long long>(rng() % (2 * w + 3))\
    \ - w - 1, yr = static_cast<long long>(rng() % (2 * w + 3)) - w - 1;\n       \
    \     if (rng() % 4 && xl > xr) std::swap(xl, xr);\n            if (rng() % 4\
    \ && yl > yr) std::swap(yl, yr);\n            std::vector<long long> expected;\n\
    \            for (int i = 0; i < n; i++) {\n                if (xl <= p[i].first\
    \ && p[i].first < xr && yl <= p[i].second && p[i].second < yr) expected.push_back(i);\n\
    \            }\n            auto ids = kd.enumerate(xl, xr, yl, yr);\n       \
    \     std::sort(ids.begin(), ids.end());\n            if (ids != expected || kd.count(xl,\
    \ xr, yl, yr) != static_cast<long long>(expected.size())) ok = false;\n      \
    \  }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/kd-tree.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/kd-tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:42:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/kd-tree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/kd-tree.test.cpp
- /verify/test/unittest/data_structures/kd-tree.test.cpp.html
title: test/unittest/data_structures/kd-tree.test.cpp
---
