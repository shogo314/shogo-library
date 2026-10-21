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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/aoj/dpl/dpl-3-c.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/dp/largest-rectangle.hpp\"\
    \n\n/**\n * @file largest-rectangle.hpp\n * @brief \u30D2\u30B9\u30C8\u30B0\u30E9\
    \u30E0\u30FB\u30B0\u30EA\u30C3\u30C9\u306E\u6700\u5927\u9577\u65B9\u5F62\u3068\
    \u6700\u5927\u6B63\u65B9\u5F62\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <utility>\n#line 12 \"src/dp/largest-rectangle.hpp\"\n\n/**\n * @brief\
    \ \u30D2\u30B9\u30C8\u30B0\u30E9\u30E0 (\u5E45 1 \u306E\u68D2\u304C\u4E26\u3093\
    \u3060\u3082\u306E) \u306B\u542B\u307E\u308C\u308B\u9577\u65B9\u5F62\u306E\u9762\
    \u7A4D\u306E\u6700\u5927\u5024 O(n)\n *\n * \u9AD8\u3055\u304C\u5358\u8ABF\u5897\
    \u52A0\u306B\u306A\u308B\u3088\u3046\u306B\u30B9\u30BF\u30C3\u30AF\u3092\u6301\
    \u3061\u3001\u68D2\u304C\u53D6\u308A\u9664\u304B\u308C\u308B\u3068\u304D\u306B\
    \u305D\u306E\u68D2\u306E\u9AD8\u3055\u306E\u9577\u65B9\u5F62\u306E\u5E45\u304C\
    \u6C7A\u307E\u308B\n * @param h \u68D2\u306E\u9AD8\u3055 (0 \u4EE5\u4E0A)\n *\
    \ @return long long \u9762\u7A4D\u306E\u6700\u5927\u5024 (h \u304C\u7A7A\u306A\
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
    }\n#line 7 \"test/aoj/dpl/dpl-3-c.test.cpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin >> n;\n    std::vector<long\
    \ long> h(n);\n    for (auto& x : h) std::cin >> x;\n    std::cout << largest_rectangle_in_histogram(h)\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/dp/largest-rectangle.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<long long> h(n);\n    for (auto&\
    \ x : h) std::cin >> x;\n    std::cout << largest_rectangle_in_histogram(h) <<\
    \ '\\n';\n}\n"
  dependsOn:
  - src/dp/largest-rectangle.hpp
  isVerificationFile: true
  path: test/aoj/dpl/dpl-3-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:47:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dpl/dpl-3-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dpl/dpl-3-c.test.cpp
- /verify/test/aoj/dpl/dpl-3-c.test.cpp.html
title: test/aoj/dpl/dpl-3-c.test.cpp
---
