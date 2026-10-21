---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-4-a.3.test.cpp
    title: test/aoj/dsl/dsl-4-a.3.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/geometry/rectangle-union.test.cpp
    title: test/unittest/geometry/rectangle-union.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
    title: test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D"
    links: []
  bundledCode: "#line 2 \"src/geometry/rectangle-union.hpp\"\n\n/**\n * @file rectangle-union.hpp\n\
    \ * @brief \u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D\n */\n\
    \n#include <algorithm>\n#include <array>\n#include <cassert>\n#include <tuple>\n\
    #include <vector>\n\n/**\n * @brief \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\
    \u5F62 [l, r) \xD7 [d, u) \u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (\u8D70\u67FB\
    \u7DDA) O(n log n)\n *\n * x \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\
    \u3001y \u65B9\u5411\u306E\u5404\u533A\u9593\u3092\u4F55\u679A\u306E\u9577\u65B9\
    \u5F62\u304C\u8986\u3063\u3066\u3044\u308B\u304B\u3092\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\u3067\u6301\u3064\u3002\n * \u8986\u3046\u679A\u6570\u304C\u6B63\u306E\
    \u533A\u9593\u3060\u3051\u3092\u9577\u3055\u306B\u6570\u3048\u308B\u306E\u3067\
    \u3001\u9045\u5EF6\u4F1D\u64AD\u306F\u3044\u3089\u306A\u3044\n * @param rects\
    \ \u9577\u65B9\u5F62 {l, d, r, u} \u306E\u30EA\u30B9\u30C8 (l <= r\u3001d <= u)\n\
    \ * @return T \u9762\u7A4D\n */\ntemplate <typename T>\nT rectangle_union_area(const\
    \ std::vector<std::array<T, 4>>& rects) {\n    std::vector<T> ys;\n    for (const\
    \ auto& [l, d, r, u] : rects) {\n        assert(l <= r && d <= u);\n        ys.push_back(d),\
    \ ys.push_back(u);\n    }\n    std::sort(ys.begin(), ys.end());\n    ys.erase(std::unique(ys.begin(),\
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
    \ + 1]) - x);\n    }\n    return res;\n}\n"
  code: "#pragma once\n\n/**\n * @file rectangle-union.hpp\n * @brief \u9577\u65B9\
    \u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D\n */\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <tuple>\n#include <vector>\n\n\
    /**\n * @brief \u8EF8\u306B\u5E73\u884C\u306A\u9577\u65B9\u5F62 [l, r) \xD7 [d,\
    \ u) \u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D (\u8D70\u67FB\u7DDA) O(n log n)\n\
    \ *\n * x \u306E\u5C0F\u3055\u3044\u9806\u306B\u8D70\u67FB\u3057\u3001y \u65B9\
    \u5411\u306E\u5404\u533A\u9593\u3092\u4F55\u679A\u306E\u9577\u65B9\u5F62\u304C\
    \u8986\u3063\u3066\u3044\u308B\u304B\u3092\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u3067\u6301\u3064\u3002\n * \u8986\u3046\u679A\u6570\u304C\u6B63\u306E\u533A\u9593\
    \u3060\u3051\u3092\u9577\u3055\u306B\u6570\u3048\u308B\u306E\u3067\u3001\u9045\
    \u5EF6\u4F1D\u64AD\u306F\u3044\u3089\u306A\u3044\n * @param rects \u9577\u65B9\
    \u5F62 {l, d, r, u} \u306E\u30EA\u30B9\u30C8 (l <= r\u3001d <= u)\n * @return\
    \ T \u9762\u7A4D\n */\ntemplate <typename T>\nT rectangle_union_area(const std::vector<std::array<T,\
    \ 4>>& rects) {\n    std::vector<T> ys;\n    for (const auto& [l, d, r, u] : rects)\
    \ {\n        assert(l <= r && d <= u);\n        ys.push_back(d), ys.push_back(u);\n\
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
    \ + 1]) - x);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/rectangle-union.hpp
  requiredBy: []
  timestamp: '2026-10-22 05:51:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/geometry/rectangle-union.test.cpp
  - test/aoj/dsl/dsl-4-a.3.test.cpp
  - test/yosupo/data_structure/area-of-union-of-rectangles.3.test.cpp
documentation_of: src/geometry/rectangle-union.hpp
layout: document
title: "\u9577\u65B9\u5F62\u306E\u548C\u96C6\u5408\u306E\u9762\u7A4D"
---

軸に平行な長方形 $[l, r) \times [d, u)$ がいくつか与えられたとき、その和集合の面積を走査線で $O(n \log n)$ で求めます。

```cpp
std::vector<std::array<long long, 4>> rects = { {0, 0, 3, 4}, {1, 2, 4, 3} };  // {l, d, r, u}
long long s = rectangle_union_area(rects);  // 12 + 3 - 2 = 13
```

x の小さい順に走査し、y 方向の各区間を何枚の長方形が覆っているかをセグメント木で持ちます。覆う枚数が正のノードはその区間全体を覆われているとし、そうでなければ子の長さを足します。枚数を子に伝える必要がないので、遅延伝播は使いません。

長方形は `{l, d, r, u}` ($l \le r$、$d \le u$) で渡します。幅か高さが 0 の長方形は無視します。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `rectangle_union_area(rects)` | 長方形 `{l, d, r, u}` (`std::array<T, 4>`) の和集合の面積 (`T`) | $O(n \log n)$ |

## 関連

- 長方形の重なりの枚数の最大値は [2 次元のいもす法](../data_structures/imos-2d.hpp)
- 区間加算・区間最小値とその個数の遅延セグメント木でも同じことができる ([遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp) と `acted_monoid::AddMinCount`)
