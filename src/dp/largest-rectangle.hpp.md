---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/dpl-3-a.test.cpp
    title: test/aoj/dpl/dpl-3-a.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/dpl-3-b.test.cpp
    title: test/aoj/dpl/dpl-3-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/dpl/dpl-3-c.test.cpp
    title: test/aoj/dpl/dpl-3-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/largest-rectangle.test.cpp
    title: test/unittest/dp/largest-rectangle.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\
      \u306E\u6700\u5927\u9577\u65B9\u5F62\u3068\u6700\u5927\u6B63\u65B9\u5F62"
    links: []
  bundledCode: "#line 2 \"src/dp/largest-rectangle.hpp\"\n\n/**\n * @file largest-rectangle.hpp\n\
    \ * @brief \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\
    \u6700\u5927\u9577\u65B9\u5F62\u3068\u6700\u5927\u6B63\u65B9\u5F62\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\n/**\n\
    \ * @brief \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0 (\u5E45 1 \u306E\u68D2\u304C\u4E26\
    \u3093\u3060\u3082\u306E) \u306B\u542B\u307E\u308C\u308B\u9577\u65B9\u5F62\u306E\
    \u9762\u7A4D\u306E\u6700\u5927\u5024 O(n)\n *\n * \u9AD8\u3055\u304C\u5358\u8ABF\
    \u5897\u52A0\u306B\u306A\u308B\u3088\u3046\u306B\u30B9\u30BF\u30C3\u30AF\u3092\
    \u6301\u3061\u3001\u68D2\u304C\u53D6\u308A\u9664\u304B\u308C\u308B\u3068\u304D\
    \u306B\u305D\u306E\u68D2\u306E\u9AD8\u3055\u306E\u9577\u65B9\u5F62\u306E\u5E45\
    \u304C\u6C7A\u307E\u308B\n * @param h \u68D2\u306E\u9AD8\u3055 (0 \u4EE5\u4E0A\
    )\n * @return long long \u9762\u7A4D\u306E\u6700\u5927\u5024 (h \u304C\u7A7A\u306A\
    \u3089 0)\n */\ntemplate <typename T>\nlong long largest_rectangle_in_histogram(const\
    \ std::vector<T>& h) {\n    const long long n = h.size();\n    long long res =\
    \ 0;\n    std::vector<std::pair<long long, T>> st;  // (\u5DE6\u7AEF, \u9AD8\u3055\
    )\n    for (long long i = 0; i <= n; i++) {\n        T x = i < n ? h[i] : T(0);\n\
    \        assert(x >= 0);\n        long long left = i;\n        while (!st.empty()\
    \ && st.back().second >= x) {\n            res = std::max(res, static_cast<long\
    \ long>(st.back().second) * (i - st.back().first));\n            left = st.back().first;\n\
    \            st.pop_back();\n        }\n        st.emplace_back(left, x);\n  \
    \  }\n    return res;\n}\n\n/**\n * @brief h \u884C w \u5217\u306E\u30B0\u30EA\
    \u30C3\u30C9\u3067\u3001f(i, j) \u304C\u771F\u306E\u30DE\u30B9\u3060\u3051\u304B\
    \u3089\u306A\u308B\u9577\u65B9\u5F62\u306E\u30DE\u30B9\u306E\u500B\u6570\u306E\
    \u6700\u5927\u5024 O(hw)\n *\n * \u5404\u884C\u3092\u5E95\u8FBA\u3068\u3057\u3066\
    \u3001\u4E0A\u306B\u7D9A\u304F\u771F\u306E\u30DE\u30B9\u306E\u500B\u6570\u3092\
    \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306B\u3059\u308B\n * @param f \u30DE\u30B9\
    \ (i, j) \u3092\u4F7F\u3048\u308B\u304B\n */\ntemplate <typename F>\nlong long\
    \ largest_rectangle(long long h, long long w, const F& f) {\n    std::vector<long\
    \ long> height(w, 0);\n    long long res = 0;\n    for (long long i = 0; i < h;\
    \ i++) {\n        for (long long j = 0; j < w; j++) height[j] = f(i, j) ? height[j]\
    \ + 1 : 0;\n        res = std::max(res, largest_rectangle_in_histogram(height));\n\
    \    }\n    return res;\n}\n\n/**\n * @brief h \u884C w \u5217\u306E\u30B0\u30EA\
    \u30C3\u30C9\u3067\u3001f(i, j) \u304C\u771F\u306E\u30DE\u30B9\u3060\u3051\u304B\
    \u3089\u306A\u308B\u6B63\u65B9\u5F62\u306E\u8FBA\u306E\u9577\u3055\u306E\u6700\
    \u5927\u5024 O(hw)\n *\n * dp[i][j] = (i, j) \u3092\u53F3\u4E0B\u3068\u3059\u308B\
    \u6B63\u65B9\u5F62\u306E\u8FBA\u306E\u9577\u3055\u306E\u6700\u5927\u5024 = min(\u4E0A\
    , \u5DE6, \u5DE6\u4E0A) + 1\n * @param f \u30DE\u30B9 (i, j) \u3092\u4F7F\u3048\
    \u308B\u304B\n */\ntemplate <typename F>\nlong long largest_square(long long h,\
    \ long long w, const F& f) {\n    std::vector<long long> dp(w + 1, 0), prev(w\
    \ + 1, 0);\n    long long res = 0;\n    for (long long i = 0; i < h; i++) {\n\
    \        for (long long j = 0; j < w; j++) {\n            dp[j + 1] = f(i, j)\
    \ ? std::min({prev[j + 1], dp[j], prev[j]}) + 1 : 0;\n            res = std::max(res,\
    \ dp[j + 1]);\n        }\n        std::swap(dp, prev);\n    }\n    return res;\n\
    }\n"
  code: "#pragma once\n\n/**\n * @file largest-rectangle.hpp\n * @brief \u30D2\u30B9\
    \u30C8\u30B0\u30E9\u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\u6700\u5927\u9577\
    \u65B9\u5F62\u3068\u6700\u5927\u6B63\u65B9\u5F62\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u30D2\
    \u30B9\u30C8\u30B0\u30E9\u30E0 (\u5E45 1 \u306E\u68D2\u304C\u4E26\u3093\u3060\u3082\
    \u306E) \u306B\u542B\u307E\u308C\u308B\u9577\u65B9\u5F62\u306E\u9762\u7A4D\u306E\
    \u6700\u5927\u5024 O(n)\n *\n * \u9AD8\u3055\u304C\u5358\u8ABF\u5897\u52A0\u306B\
    \u306A\u308B\u3088\u3046\u306B\u30B9\u30BF\u30C3\u30AF\u3092\u6301\u3061\u3001\
    \u68D2\u304C\u53D6\u308A\u9664\u304B\u308C\u308B\u3068\u304D\u306B\u305D\u306E\
    \u68D2\u306E\u9AD8\u3055\u306E\u9577\u65B9\u5F62\u306E\u5E45\u304C\u6C7A\u307E\
    \u308B\n * @param h \u68D2\u306E\u9AD8\u3055 (0 \u4EE5\u4E0A)\n * @return long\
    \ long \u9762\u7A4D\u306E\u6700\u5927\u5024 (h \u304C\u7A7A\u306A\u3089 0)\n */\n\
    template <typename T>\nlong long largest_rectangle_in_histogram(const std::vector<T>&\
    \ h) {\n    const long long n = h.size();\n    long long res = 0;\n    std::vector<std::pair<long\
    \ long, T>> st;  // (\u5DE6\u7AEF, \u9AD8\u3055)\n    for (long long i = 0; i\
    \ <= n; i++) {\n        T x = i < n ? h[i] : T(0);\n        assert(x >= 0);\n\
    \        long long left = i;\n        while (!st.empty() && st.back().second >=\
    \ x) {\n            res = std::max(res, static_cast<long long>(st.back().second)\
    \ * (i - st.back().first));\n            left = st.back().first;\n           \
    \ st.pop_back();\n        }\n        st.emplace_back(left, x);\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief h \u884C w \u5217\u306E\u30B0\u30EA\u30C3\u30C9\u3067\
    \u3001f(i, j) \u304C\u771F\u306E\u30DE\u30B9\u3060\u3051\u304B\u3089\u306A\u308B\
    \u9577\u65B9\u5F62\u306E\u30DE\u30B9\u306E\u500B\u6570\u306E\u6700\u5927\u5024\
    \ O(hw)\n *\n * \u5404\u884C\u3092\u5E95\u8FBA\u3068\u3057\u3066\u3001\u4E0A\u306B\
    \u7D9A\u304F\u771F\u306E\u30DE\u30B9\u306E\u500B\u6570\u3092\u30D2\u30B9\u30C8\
    \u30B0\u30E9\u30E0\u306B\u3059\u308B\n * @param f \u30DE\u30B9 (i, j) \u3092\u4F7F\
    \u3048\u308B\u304B\n */\ntemplate <typename F>\nlong long largest_rectangle(long\
    \ long h, long long w, const F& f) {\n    std::vector<long long> height(w, 0);\n\
    \    long long res = 0;\n    for (long long i = 0; i < h; i++) {\n        for\
    \ (long long j = 0; j < w; j++) height[j] = f(i, j) ? height[j] + 1 : 0;\n   \
    \     res = std::max(res, largest_rectangle_in_histogram(height));\n    }\n  \
    \  return res;\n}\n\n/**\n * @brief h \u884C w \u5217\u306E\u30B0\u30EA\u30C3\u30C9\
    \u3067\u3001f(i, j) \u304C\u771F\u306E\u30DE\u30B9\u3060\u3051\u304B\u3089\u306A\
    \u308B\u6B63\u65B9\u5F62\u306E\u8FBA\u306E\u9577\u3055\u306E\u6700\u5927\u5024\
    \ O(hw)\n *\n * dp[i][j] = (i, j) \u3092\u53F3\u4E0B\u3068\u3059\u308B\u6B63\u65B9\
    \u5F62\u306E\u8FBA\u306E\u9577\u3055\u306E\u6700\u5927\u5024 = min(\u4E0A, \u5DE6\
    , \u5DE6\u4E0A) + 1\n * @param f \u30DE\u30B9 (i, j) \u3092\u4F7F\u3048\u308B\u304B\
    \n */\ntemplate <typename F>\nlong long largest_square(long long h, long long\
    \ w, const F& f) {\n    std::vector<long long> dp(w + 1, 0), prev(w + 1, 0);\n\
    \    long long res = 0;\n    for (long long i = 0; i < h; i++) {\n        for\
    \ (long long j = 0; j < w; j++) {\n            dp[j + 1] = f(i, j) ? std::min({prev[j\
    \ + 1], dp[j], prev[j]}) + 1 : 0;\n            res = std::max(res, dp[j + 1]);\n\
    \        }\n        std::swap(dp, prev);\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/largest-rectangle.hpp
  requiredBy: []
  timestamp: '2026-10-22 05:47:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/largest-rectangle.test.cpp
  - test/aoj/dpl/dpl-3-a.test.cpp
  - test/aoj/dpl/dpl-3-b.test.cpp
  - test/aoj/dpl/dpl-3-c.test.cpp
documentation_of: src/dp/largest-rectangle.hpp
layout: document
title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\u6700\
  \u5927\u9577\u65B9\u5F62\u3068\u6700\u5927\u6B63\u65B9\u5F62"
---

ヒストグラムに含まれる長方形の最大面積と、グリッドで使えるマスだけからなる長方形・正方形の最大の大きさを求めます。

```cpp
long long a = largest_rectangle_in_histogram(std::vector<int>{2, 1, 3, 5, 3, 4, 2, 1});  // 12

std::vector<std::string> g = {"..#..", "#....", "...#.", "...#."};
auto f = [&](long long i, long long j) { return g[i][j] == '.'; };
long long r = largest_rectangle(4, 5, f);  // 6
long long s = largest_square(4, 5, f);     // 2 (2 × 2)
```

- `largest_rectangle_in_histogram` は、高さが単調増加になるようにスタックを持ちます。棒が取り除かれるとき、その棒の高さの長方形の幅が決まります。
- `largest_rectangle` は、各行を底辺として、上に続く使えるマスの個数をヒストグラムにします。
- `largest_square` は、各マスを右下とする正方形の辺の長さの最大値を DP で求めます (上・左・左上の最小値 + 1)。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `largest_rectangle_in_histogram(h)` | 高さ `h[i]` (0 以上) の幅 1 の棒が並んだヒストグラムに含まれる長方形の面積の最大値 (`long long`) | $O(n)$ |
| `largest_rectangle(h, w, f)` | `h` 行 `w` 列のグリッドで、`f(i, j)` が真のマスだけからなる長方形のマスの個数の最大値 | $O(hw)$ |
| `largest_square(h, w, f)` | 同じく、正方形の辺の長さの最大値 (面積はその 2 乗) | $O(hw)$ |

## 関連

- グリッドの近傍をたどるには [Python の range のような整数列と、その直積の Rect](../utility/range.hpp) の `Rect`
