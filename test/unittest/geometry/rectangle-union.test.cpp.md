---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/rectangle-union.hpp
    title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D"
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
  bundledCode: "#line 1 \"test/unittest/geometry/rectangle-union.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// rectangle-union.hpp \u306E rectangle_union_area \u3092\u3001\u5358\u4F4D\
    \u6B63\u65B9\u5F62\u3054\u3068\u306B\u8986\u308F\u308C\u3066\u3044\u308B\u304B\
    \u3092\u6570\u3048\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n// \u5E45\u3084\u9AD8\
    \u3055\u304C 0 \u306E\u9577\u65B9\u5F62\u3001\u91CD\u306A\u308B\u9577\u65B9\u5F62\
    \u3001\u7A7A\u306E\u30EA\u30B9\u30C8\u3082\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/geometry/rectangle-union.hpp\"\
    \n\n/**\n * @file rectangle-union.hpp\n * @brief \u9577\u65B9\u5F62\u306E\u548C\
    \u96C6\u5408\u306E\u9762\u7A4D\n */\n\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\n/**\n * @brief \u8EF8\
    \u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62 [l, r) \xD7 [d, u) \u306E\u548C\u96C6\
    \u5408\u306E\u9762\u7A4D (\u8D70\u67FB\u7DDA) O(n log n)\n *\n * x \u306E\u5C0F\
    \u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\u3001y \u65B9\u5411\u306E\u5404\u533A\
    \u9593\u3092\u4F55\u679A\u306E\u9577\u65B9\u5F62\u304C\u8986\u3063\u3066\u3044\
    \u308B\u304B\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u3067\u6301\u3064\u3002\
    \n * \u8986\u3046\u679A\u6570\u304C\u6B63\u306E\u533A\u9593\u3060\u3051\u3092\u9577\
    \u3055\u306B\u6570\u3048\u308B\u306E\u3067\u3001\u9045\u5EF6\u4F1D\u64AD\u306F\
    \u3044\u3089\u306A\u3044\n * @param rects \u9577\u65B9\u5F62 {l, d, r, u} \u306E\
    \u30EA\u30B9\u30C8 (l <= r\u3001d <= u)\n * @return T \u9762\u7A4D\n */\ntemplate\
    \ <typename T>\nT rectangle_union_area(const std::vector<std::array<T, 4>>& rects)\
    \ {\n    std::vector<T> ys;\n    for (const auto& [l, d, r, u] : rects) {\n  \
    \      assert(l <= r && d <= u);\n        ys.push_back(d), ys.push_back(u);\n\
    \    }\n    std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(),\
    \ ys.end()), ys.end());\n    const int m = static_cast<int>(ys.size()) - 1;  //\
    \ y \u65B9\u5411\u306E\u533A\u9593 [ys[i], ys[i+1]) \u306E\u500B\u6570\n    if\
    \ (m <= 0) return T(0);\n    // (x, \u52A0\u3048\u308B\u679A\u6570, y \u306E\u533A\
    \u9593 [lo, hi))\n    std::vector<std::tuple<T, int, int, int>> events;\n    for\
    \ (const auto& [l, d, r, u] : rects) {\n        if (l == r || d == u) continue;\n\
    \        int lo = std::lower_bound(ys.begin(), ys.end(), d) - ys.begin(), hi =\
    \ std::lower_bound(ys.begin(), ys.end(), u) - ys.begin();\n        events.emplace_back(l,\
    \ 1, lo, hi);\n        events.emplace_back(r, -1, lo, hi);\n    }\n    std::sort(events.begin(),\
    \ events.end());\n    int sz = 1;\n    while (sz < m) sz <<= 1;\n    std::vector<int>\
    \ cover(2 * sz, 0);  // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u5168\
    \u4F53\u3092\u8986\u3046\u9577\u65B9\u5F62\u306E\u679A\u6570\n    std::vector<T>\
    \ len(2 * sz, T(0));   // \u305D\u306E\u30CE\u30FC\u30C9\u306E\u533A\u9593\u3067\
    \u8986\u308F\u308C\u3066\u3044\u308B\u9577\u3055\n    // \u30CE\u30FC\u30C9 k\
    \ (\u533A\u9593 [a, b)) \u306B [lo, hi) \u3092 v \u679A\u8DB3\u3059\n    auto\
    \ add = [&](auto&& self, int k, int a, int b, int lo, int hi, int v) -> void {\n\
    \        if (hi <= a || b <= lo) return;\n        if (lo <= a && b <= hi) {\n\
    \            cover[k] += v;\n        } else {\n            int c = (a + b) / 2;\n\
    \            self(self, 2 * k, a, c, lo, hi, v);\n            self(self, 2 * k\
    \ + 1, c, b, lo, hi, v);\n        }\n        if (cover[k] > 0)\n            len[k]\
    \ = ys[std::min(b, m)] - ys[std::min(a, m)];\n        else\n            len[k]\
    \ = k >= sz ? T(0) : len[2 * k] + len[2 * k + 1];\n    };\n    T res = 0;\n  \
    \  for (int i = 0; i < static_cast<int>(events.size()); i++) {\n        auto [x,\
    \ v, lo, hi] = events[i];\n        add(add, 1, 0, sz, lo, hi, v);\n        if\
    \ (i + 1 < static_cast<int>(events.size())) res += len[1] * (std::get<0>(events[i\
    \ + 1]) - x);\n    }\n    return res;\n}\n#line 8 \"test/unittest/geometry/rectangle-union.test.cpp\"\
    \n\n#line 11 \"test/unittest/geometry/rectangle-union.test.cpp\"\n#include <iostream>\n\
    #include <random>\n#line 14 \"test/unittest/geometry/rectangle-union.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    if (rectangle_union_area(std::vector<std::array<long\
    \ long, 4>>{}) != 0) ok = false;\n    for (int rep = 0; rep < 3000 && ok; rep++)\
    \ {\n        int n = rng() % 8 + 1, w = 10;\n        std::vector<std::array<long\
    \ long, 4>> rects(n);\n        std::vector<std::vector<bool>> covered(w, std::vector<bool>(w,\
    \ false));\n        for (auto& [l, d, r, u] : rects) {\n            l = rng()\
    \ % (w + 1), r = rng() % (w + 1), d = rng() % (w + 1), u = rng() % (w + 1);\n\
    \            if (l > r) std::swap(l, r);\n            if (d > u) std::swap(d,\
    \ u);\n            for (long long x = l; x < r; x++)\n                for (long\
    \ long y = d; y < u; y++) covered[x][y] = true;\n        }\n        long long\
    \ expected = 0;\n        for (auto& row : covered) expected += std::count(row.begin(),\
    \ row.end(), true);\n        if (rectangle_union_area(rects) != expected) ok =\
    \ false;\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// rectangle-union.hpp \u306E rectangle_union_area \u3092\u3001\u5358\u4F4D\
    \u6B63\u65B9\u5F62\u3054\u3068\u306B\u8986\u308F\u308C\u3066\u3044\u308B\u304B\
    \u3092\u6570\u3048\u305F\u3082\u306E\u3068\u6BD4\u3079\u308B\n// \u5E45\u3084\u9AD8\
    \u3055\u304C 0 \u306E\u9577\u65B9\u5F62\u3001\u91CD\u306A\u308B\u9577\u65B9\u5F62\
    \u3001\u7A7A\u306E\u30EA\u30B9\u30C8\u3082\u8ABF\u3079\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/geometry/rectangle-union.hpp\"\
    \n\n#include <algorithm>\n#include <array>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok\
    \ = true;\n    if (rectangle_union_area(std::vector<std::array<long long, 4>>{})\
    \ != 0) ok = false;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n      \
    \  int n = rng() % 8 + 1, w = 10;\n        std::vector<std::array<long long, 4>>\
    \ rects(n);\n        std::vector<std::vector<bool>> covered(w, std::vector<bool>(w,\
    \ false));\n        for (auto& [l, d, r, u] : rects) {\n            l = rng()\
    \ % (w + 1), r = rng() % (w + 1), d = rng() % (w + 1), u = rng() % (w + 1);\n\
    \            if (l > r) std::swap(l, r);\n            if (d > u) std::swap(d,\
    \ u);\n            for (long long x = l; x < r; x++)\n                for (long\
    \ long y = d; y < u; y++) covered[x][y] = true;\n        }\n        long long\
    \ expected = 0;\n        for (auto& row : covered) expected += std::count(row.begin(),\
    \ row.end(), true);\n        if (rectangle_union_area(rects) != expected) ok =\
    \ false;\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/geometry/rectangle-union.hpp
  isVerificationFile: true
  path: test/unittest/geometry/rectangle-union.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:51:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/geometry/rectangle-union.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/geometry/rectangle-union.test.cpp
- /verify/test/unittest/geometry/rectangle-union.test.cpp.html
title: test/unittest/geometry/rectangle-union.test.cpp
---
