---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/monge.hpp
    title: "Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\u5316 (monotone minima\u30FB\
      (min, +) \u7573\u307F\u8FBC\u307F\u30FBAlien DP\u30FBKnuth\u2013Yao)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
  bundledCode: "#line 1 \"test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/dp/monge.hpp\"\n\n\
    /**\n * @file monge.hpp\n * @brief Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\
    \u901F\u5316 (monotone minima\u3001(min, +) \u7573\u307F\u8FBC\u307F\u3001Alien\
    \ DP\u3001Knuth\u2013Yao)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <type_traits>\n#include <utility>\n#line 13 \"src/dp/monge.hpp\"\n\n/**\n *\
    \ @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E (\u6700\u3082\u5DE6\
    \u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\u8ABF\u975E\u6E1B\
    \u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\u5404\u884C\u306E\
    \u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * select(i, j, k) (j <\
    \ k) \u306F\u3001\u884C i \u3067\u5217 k \u306E\u5024\u304C\u5217 j \u306E\u5024\
    \u3088\u308A\u771F\u306B\u5C0F\u3055\u3044\u306A\u3089 true \u3092\u8FD4\u3059\
    \n * (\u5024\u3092\u8FD4\u3059\u95A2\u6570\u304C\u3042\u308B\u306A\u3089 monotone_minima\
    \ \u3092\u4F7F\u3046\u3002\u7BC4\u56F2\u5916\u306E\u5217\u3092\u300C\u9078\u3070\
    \u306A\u3044\u300D\u3068\u6C7A\u3081\u305F\u3044\u3068\u304D\u306F\u3053\u3061\
    \u3089\u3067\u6BD4\u3079\u65B9\u3092\u66F8\u304F)\n */\ntemplate <typename Select>\n\
    std::vector<long long> monotone_minima_select(long long H, long long W, Select\
    \ select) {\n    assert(H >= 0 && W >= 1);\n    std::vector<long long> res(H);\n\
    \    // \u884C [top, bottom) \u306E\u6700\u5C0F\u306E\u4F4D\u7F6E\u304C\u5217\
    \ [left, right] \u306B\u3042\u308B\u3068\u3057\u3066\u3001\u771F\u3093\u4E2D\u306E\
    \u884C\u304B\u3089\u6C7A\u3081\u308B\n    auto rec = [&](auto&& self, long long\
    \ top, long long bottom, long long left, long long right) -> void {\n        if\
    \ (top >= bottom) return;\n        const long long mid = (top + bottom) / 2;\n\
    \        long long best = left;\n        for (long long j = left + 1; j <= right;\
    \ j++)\n            if (select(mid, best, j)) best = j;\n        res[mid] = best;\n\
    \        self(self, top, mid, left, best);\n        self(self, mid + 1, bottom,\
    \ best, right);\n    };\n    rec(rec, 0, H, 0, W - 1);\n    return res;\n}\n\n\
    /**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E (\u6700\u3082\
    \u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\u8ABF\u975E\
    \u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\u5404\u884C\
    \u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * f(i, j) \u306F\
    \ (i, j) \u6210\u5206\u306E\u5024\u3002Monge \u306A\u884C\u5217 (f(i, j) + f(i',\
    \ j') <= f(i, j') + f(i', j)\u3001i < i'\u3001j < j') \u306A\u3089\u3053\u306E\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\n */\ntemplate <typename F>\nstd::vector<long\
    \ long> monotone_minima(long long H, long long W, F f) {\n    return monotone_minima_select(H,\
    \ W, [&](long long i, long long j, long long k) { return f(i, k) < f(i, j); });\n\
    }\n\n/**\n * @brief c_k = min_{i + j = k} (a_i + b_j) \u3092\u3001a \u304C\u51F8\
    \ (a_{i+1} - a_i \u304C\u5358\u8ABF\u975E\u6E1B\u5C11) \u306E\u3068\u304D\u306B\
    \u6C42\u3081\u308B O((N + M) log (N + M))\n * b \u306F\u4EFB\u610F\u3002a, b \u306F\
    \u7A7A\u3067\u306A\u3044\u3053\u3068\n */\ntemplate <typename T>\nstd::vector<T>\
    \ min_plus_convolution_convex_arbitrary(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    const long long n = a.size(), m = b.size();\n    assert(n >= 1 &&\
    \ m >= 1);\n    // \u884C k\u3001\u5217 j \u306E\u5024\u306F a_{k-j} + b_j\u3002\
    k - j \u304C [0, n) \u306E\u5916\u306E\u5217\u306F\u9078\u3070\u306A\u3044\n \
    \   auto select = [&](long long k, long long j1, long long j2) {\n        if (k\
    \ < j2) return false;      // j2 \u306F\u5927\u304D\u3059\u304E\u308B (k - j2\
    \ < 0)\n        if (k - j1 >= n) return true;  // j1 \u306F\u5C0F\u3055\u3059\u304E\
    \u308B (k - j1 >= n)\n        return a[k - j2] + b[j2] < a[k - j1] + b[j1];\n\
    \    };\n    std::vector<long long> arg = monotone_minima_select(n + m - 1, m,\
    \ select);\n    std::vector<T> c(n + m - 1);\n    for (long long k = 0; k < n\
    \ + m - 1; k++) c[k] = a[k - arg[k]] + b[arg[k]];\n    return c;\n}\n\n/**\n *\
    \ @brief c_k = min_{i + j = k} (a_i + b_j) \u3092\u3001a, b \u304C\u3068\u3082\
    \u306B\u51F8\u306E\u3068\u304D\u306B\u6C42\u3081\u308B O(N + M)\n * \u5DEE\u5206\
    \ (\u50BE\u304D) \u3092\u5C0F\u3055\u3044\u9806\u306B\u4F75\u5408\u3059\u308C\u3070\
    \u3088\u3044\u3002a, b \u306F\u7A7A\u3067\u306A\u3044\u3053\u3068\n */\ntemplate\
    \ <typename T>\nstd::vector<T> min_plus_convolution_convex_convex(const std::vector<T>&\
    \ a, const std::vector<T>& b) {\n    const long long n = a.size(), m = b.size();\n\
    \    assert(n >= 1 && m >= 1);\n    std::vector<T> c(n + m - 1);\n    c[0] = a[0]\
    \ + b[0];\n    for (long long k = 1, i = 0, j = 0; k < n + m - 1; k++) {\n   \
    \     // \u6B21\u306B\u9032\u3081\u308B\u65B9\u306F\u3001\u5897\u3048\u65B9 (\u5DEE\
    \u5206) \u306E\u5C0F\u3055\u3044\u65B9\n        if (j == m - 1 || (i < n - 1 &&\
    \ a[i + 1] - a[i] < b[j + 1] - b[j])) {\n            c[k] = c[k - 1] + (a[i +\
    \ 1] - a[i]), i++;\n        } else {\n            c[k] = c[k - 1] + (b[j + 1]\
    \ - b[j]), j++;\n        }\n    }\n    return c;\n}\n\n/**\n * @brief Alien DP\
    \ (Lagrange \u7DE9\u548C): \u3061\u3087\u3046\u3069 k \u500B\u9078\u3076\u3068\
    \u304D\u306E\u6700\u5C0F\u5024 f(k) \u3092\u3001f \u304C\u51F8 (f(x+1) - f(x)\
    \ \u304C\u5358\u8ABF\u975E\u6E1B\u5C11\u306A\u6574\u6570) \u306E\u3068\u304D\u306B\
    \u6C42\u3081\u308B\n * solve(lambda) \u306F {min_x (f(x) + lambda x), \u305D\u306E\
    \u6700\u5C0F\u5024\u3092\u3068\u308B x \u306E\u3046\u3061\u6700\u5C0F\u306E\u3082\
    \u306E} \u3092\u8FD4\u3059\u3053\u3068\n * lambda \u306F [lo, hi] \u306E\u6574\
    \u6570\u306E\u4E2D\u304B\u3089\u4E8C\u5206\u63A2\u7D22\u3059\u308B\u3002-lo, -hi\
    \ \u306F f \u306E\u50BE\u304D\u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024\u3092\
    \u542B\u3080\u3088\u3046\u306B\u3068\u308B (f(x+1) - f(x) \u304C [-hi, -lo] \u306B\
    \u5165\u308B)\n * solve \u3092\u547C\u3076\u56DE\u6570\u306F O(log (hi - lo))\u3002\
    \u6700\u5927\u5316\u306A\u3089 f \u306E\u7B26\u53F7\u3092\u53CD\u8EE2\u3057\u3066\
    \u4F7F\u3046\n */\ntemplate <typename Solve>\nlong long alien_dp(long long k,\
    \ long long lo, long long hi, Solve solve) {\n    assert(lo <= hi);\n    // x_min(lambda)\
    \ \u306F lambda \u306B\u3064\u3044\u3066\u5358\u8ABF\u975E\u5897\u52A0\u3002x_min(lambda)\
    \ <= k \u3068\u306A\u308B\u6700\u5C0F\u306E lambda \u3092\u63A2\u3059\n    //\
    \ \u305D\u306E\u3068\u304D k \u306F\u6700\u5C0F\u5024\u3092\u3068\u308B x \u306E\
    \u7BC4\u56F2 [x_min(lambda), x_min(lambda - 1)] \u306B\u5165\u308B\u306E\u3067\
    \u3001f(k) = \u6700\u5C0F\u5024 - lambda k\n    while (lo < hi) {\n        long\
    \ long mid = lo + (hi - lo) / 2;\n        if (solve(mid).second <= k) {\n    \
    \        hi = mid;\n        } else {\n            lo = mid + 1;\n        }\n \
    \   }\n    auto [val, x] = solve(lo);\n    assert(x <= k && \"alien_dp: [lo, hi]\
    \ \u304C\u72ED\u3044\");\n    return val - lo * k;\n}\n\n/**\n * @brief \u533A\
    \u9593 DP dp[i][j] = min_{i < k < j} (dp[i][k] + dp[k][j]) + w(i, j) (j - i >=\
    \ 2)\u3001dp[i][i+1] = base(i) \u3092\n * Knuth\u2013Yao \u306E\u9AD8\u901F\u5316\
    \u3067\u6C42\u3081\u308B O(n^2)\n *\n * w \u304C quadrangle inequality (a <= b\
    \ <= c <= d \u3067 w(a, c) + w(b, d) <= w(a, d) + w(b, c)) \u3068\n * \u5358\u8ABF\
    \u6027 (w(b, c) <= w(a, d)) \u3092\u6E80\u305F\u305B\u3070\u3001\u6700\u9069\u306A\
    \ k \u306F opt[i][j-1] <= opt[i][j] <= opt[i+1][j] \u3092\u6E80\u305F\u3059\u306E\
    \u3067\u3001\u305D\u306E\u7BC4\u56F2\u3060\u3051\u3092\u8ABF\u3079\u308B\n * (base\
    \ \u306E\u5024\u306F\u6700\u9069\u306A k \u306B\u5F71\u97FF\u3057\u306A\u3044\u3002\
    \u533A\u9593\u306E base \u306E\u548C\u3092\u5F15\u3051\u3070 base = 0 \u306E\u5834\
    \u5408\u306B\u306A\u308B\u305F\u3081)\n * @param n \u533A\u9593\u306E\u7AEF\u306E\
    \u500B\u6570 - 1 (0 <= i < j <= n)\n * @return std::vector<std::vector<T>> dp[i][j]\
    \ (0 <= i < j <= n\u3001\u305D\u308C\u4EE5\u5916\u306F\u4F7F\u308F\u306A\u3044\
    )\n */\ntemplate <typename Base, typename W, typename T = std::decay_t<std::invoke_result_t<Base,\
    \ long long>>>\nstd::vector<std::vector<T>> knuth_yao(long long n, Base base,\
    \ W w) {\n    std::vector<std::vector<T>> dp(n + 1, std::vector<T>(n + 1, T{}));\n\
    \    std::vector<std::vector<long long>> opt(n + 1, std::vector<long long>(n +\
    \ 1, 0));\n    for (long long i = 0; i + 1 <= n; i++) dp[i][i + 1] = base(i),\
    \ opt[i][i + 1] = i + 1;\n    for (long long len = 2; len <= n; len++) {\n   \
    \     for (long long i = 0; i + len <= n; i++) {\n            long long j = i\
    \ + len;\n            // opt[i][j-1] <= k <= opt[i+1][j] (\u9577\u3055 2 \u306A\
    \u3089 k = i + 1 \u3060\u3051)\n            long long lo = std::max(i + 1, opt[i][j\
    \ - 1]), hi = std::min(j - 1, opt[i + 1][j]);\n            T best{};\n       \
    \     long long arg = -1;\n            for (long long k = lo; k <= hi; k++) {\n\
    \                T v = dp[i][k] + dp[k][j];\n                if (arg == -1 ||\
    \ v < best) best = v, arg = k;\n            }\n            assert(arg != -1 &&\
    \ \"knuth_yao: w \u304C\u6761\u4EF6\u3092\u6E80\u305F\u3055\u306A\u3044\");\n\
    \            dp[i][j] = best + w(i, j);\n            opt[i][j] = arg;\n      \
    \  }\n    }\n    return dp;\n}\n#line 7 \"test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector<long long> a(n), b(m);\n\
    \    for (auto& x : a) std::cin >> x;\n    for (auto& x : b) std::cin >> x;\n\
    \    auto c = min_plus_convolution_convex_convex(a, b);\n    for (size_t i = 0;\
    \ i < c.size(); i++) std::cout << c[i] << (i + 1 == c.size() ? '\\n' : ' ');\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../../src/dp/monge.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, m;\n    std::cin >> n >> m;\n    std::vector<long long> a(n), b(m);\n\
    \    for (auto& x : a) std::cin >> x;\n    for (auto& x : b) std::cin >> x;\n\
    \    auto c = min_plus_convolution_convex_convex(a, b);\n    for (size_t i = 0;\
    \ i < c.size(); i++) std::cout << c[i] << (i + 1 == c.size() ? '\\n' : ' ');\n\
    }\n"
  dependsOn:
  - src/dp/monge.hpp
  isVerificationFile: true
  path: test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 05:49:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
- /verify/test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp.html
title: test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
---
