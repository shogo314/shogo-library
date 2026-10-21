---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/largest-rectangle.hpp
    title: "\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\
      \u6700\u5927\u9577\u65B9\u5F62\u3068\u6700\u5927\u6B63\u65B9\u5F62"
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
  bundledCode: "#line 1 \"test/unittest/dp/largest-rectangle.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ largest-rectangle.hpp \u306E 3 \u3064\u306E\u95A2\u6570\u3092\u3001\u3059\u3079\
    \u3066\u306E\u9577\u65B9\u5F62\u30FB\u6B63\u65B9\u5F62\u3092\u8ABF\u3079\u305F\
    \u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u554F\u984C\
    \u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\
    \u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/dp/largest-rectangle.hpp\"\
    \n\n/**\n * @file largest-rectangle.hpp\n * @brief \u30D2\u30B9\u30C8\u30B0\u30E9\
    \u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\u6700\u5927\u9577\u65B9\u5F62\u3068\
    \u6700\u5927\u6B63\u65B9\u5F62\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief \u30D2\u30B9\u30C8\u30B0\
    \u30E9\u30E0 (\u5E45 1 \u306E\u68D2\u304C\u4E26\u3093\u3060\u3082\u306E) \u306B\
    \u542B\u307E\u308C\u308B\u9577\u65B9\u5F62\u306E\u9762\u7A4D\u306E\u6700\u5927\
    \u5024 O(n)\n *\n * \u9AD8\u3055\u304C\u5358\u8ABF\u5897\u52A0\u306B\u306A\u308B\
    \u3088\u3046\u306B\u30B9\u30BF\u30C3\u30AF\u3092\u6301\u3061\u3001\u68D2\u304C\
    \u53D6\u308A\u9664\u304B\u308C\u308B\u3068\u304D\u306B\u305D\u306E\u68D2\u306E\
    \u9AD8\u3055\u306E\u9577\u65B9\u5F62\u306E\u5E45\u304C\u6C7A\u307E\u308B\n * @param\
    \ h \u68D2\u306E\u9AD8\u3055 (0 \u4EE5\u4E0A)\n * @return long long \u9762\u7A4D\
    \u306E\u6700\u5927\u5024 (h \u304C\u7A7A\u306A\u3089 0)\n */\ntemplate <typename\
    \ T>\nlong long largest_rectangle_in_histogram(const std::vector<T>& h) {\n  \
    \  const long long n = h.size();\n    long long res = 0;\n    std::vector<std::pair<long\
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
    \        }\n        std::swap(dp, prev);\n    }\n    return res;\n}\n#line 7 \"\
    test/unittest/dp/largest-rectangle.test.cpp\"\n\n#line 9 \"test/unittest/dp/largest-rectangle.test.cpp\"\
    \n#include <iostream>\n#include <random>\n#line 12 \"test/unittest/dp/largest-rectangle.test.cpp\"\
    \n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    if (largest_rectangle_in_histogram(std::vector<int>{})\
    \ != 0) ok = false;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n      \
    \  int n = rng() % 10 + 1;\n        std::vector<int> hist(n);\n        for (auto&\
    \ x : hist) x = rng() % 6;\n        long long best = 0;\n        for (int l =\
    \ 0; l < n; l++) {\n            int mn = hist[l];\n            for (int r = l;\
    \ r < n; r++) {\n                mn = std::min(mn, hist[r]);\n               \
    \ best = std::max(best, static_cast<long long>(mn) * (r - l + 1));\n         \
    \   }\n        }\n        if (largest_rectangle_in_histogram(hist) != best) ok\
    \ = false;\n\n        int h = rng() % 6, w = rng() % 6, p = rng() % 4 + 1;\n \
    \       std::vector<std::vector<bool>> g(h, std::vector<bool>(w));\n        for\
    \ (auto& row : g)\n            for (auto&& x : row) x = rng() % p != 0;\n    \
    \    auto f = [&](long long i, long long j) { return static_cast<bool>(g[i][j]);\
    \ };\n        // \u5DE6\u4E0A\u3068\u53F3\u4E0B\u3092\u3059\u3079\u3066\u8A66\u3059\
    \n        long long rect = 0, square = 0;\n        for (int i1 = 0; i1 < h; i1++)\n\
    \            for (int j1 = 0; j1 < w; j1++)\n                for (int i2 = i1;\
    \ i2 < h; i2++)\n                    for (int j2 = j1; j2 < w; j2++) {\n     \
    \                   bool all = true;\n                        for (int i = i1;\
    \ i <= i2; i++)\n                            for (int j = j1; j <= j2; j++) all\
    \ &= static_cast<bool>(g[i][j]);\n                        if (!all) continue;\n\
    \                        rect = std::max(rect, static_cast<long long>(i2 - i1\
    \ + 1) * (j2 - j1 + 1));\n                        if (i2 - i1 == j2 - j1) square\
    \ = std::max(square, static_cast<long long>(i2 - i1 + 1));\n                 \
    \   }\n        if (largest_rectangle(h, w, f) != rect || largest_square(h, w,\
    \ f) != square) ok = false;\n    }\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// largest-rectangle.hpp \u306E 3 \u3064\u306E\u95A2\u6570\u3092\u3001\u3059\
    \u3079\u3066\u306E\u9577\u65B9\u5F62\u30FB\u6B63\u65B9\u5F62\u3092\u8ABF\u3079\
    \u305F\u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u554F\
    \u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\
    \u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include\
    \ \"../../../src/dp/largest-rectangle.hpp\"\n\n#include <algorithm>\n#include\
    \ <iostream>\n#include <random>\n#include <vector>\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n    bool ok = true;\n    if (largest_rectangle_in_histogram(std::vector<int>{})\
    \ != 0) ok = false;\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n      \
    \  int n = rng() % 10 + 1;\n        std::vector<int> hist(n);\n        for (auto&\
    \ x : hist) x = rng() % 6;\n        long long best = 0;\n        for (int l =\
    \ 0; l < n; l++) {\n            int mn = hist[l];\n            for (int r = l;\
    \ r < n; r++) {\n                mn = std::min(mn, hist[r]);\n               \
    \ best = std::max(best, static_cast<long long>(mn) * (r - l + 1));\n         \
    \   }\n        }\n        if (largest_rectangle_in_histogram(hist) != best) ok\
    \ = false;\n\n        int h = rng() % 6, w = rng() % 6, p = rng() % 4 + 1;\n \
    \       std::vector<std::vector<bool>> g(h, std::vector<bool>(w));\n        for\
    \ (auto& row : g)\n            for (auto&& x : row) x = rng() % p != 0;\n    \
    \    auto f = [&](long long i, long long j) { return static_cast<bool>(g[i][j]);\
    \ };\n        // \u5DE6\u4E0A\u3068\u53F3\u4E0B\u3092\u3059\u3079\u3066\u8A66\u3059\
    \n        long long rect = 0, square = 0;\n        for (int i1 = 0; i1 < h; i1++)\n\
    \            for (int j1 = 0; j1 < w; j1++)\n                for (int i2 = i1;\
    \ i2 < h; i2++)\n                    for (int j2 = j1; j2 < w; j2++) {\n     \
    \                   bool all = true;\n                        for (int i = i1;\
    \ i <= i2; i++)\n                            for (int j = j1; j <= j2; j++) all\
    \ &= static_cast<bool>(g[i][j]);\n                        if (!all) continue;\n\
    \                        rect = std::max(rect, static_cast<long long>(i2 - i1\
    \ + 1) * (j2 - j1 + 1));\n                        if (i2 - i1 == j2 - j1) square\
    \ = std::max(square, static_cast<long long>(i2 - i1 + 1));\n                 \
    \   }\n        if (largest_rectangle(h, w, f) != rect || largest_square(h, w,\
    \ f) != square) ok = false;\n    }\n    if (ok) std::cout << \"Hello World\" <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/dp/largest-rectangle.hpp
  isVerificationFile: true
  path: test/unittest/dp/largest-rectangle.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:47:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/dp/largest-rectangle.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dp/largest-rectangle.test.cpp
- /verify/test/unittest/dp/largest-rectangle.test.cpp.html
title: test/unittest/dp/largest-rectangle.test.cpp
---
