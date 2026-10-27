---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-10-d.test.cpp
    title: test/aoj/alds1/alds1-10-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/monge.test.cpp
    title: test/unittest/dp/monge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution/min-plus-convolution-convex-arbitrary.test.cpp
    title: test/yosupo/convolution/min-plus-convolution-convex-arbitrary.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
    title: test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\u5316 (monotone\
      \ minima\u3001(min, +) \u7573\u307F\u8FBC\u307F\u3001Alien DP\u3001Knuth\u2013\
      Yao)"
    links: []
  bundledCode: "#line 2 \"src/dp/monge.hpp\"\n\n/**\n * @file monge.hpp\n * @brief\
    \ Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\u5316 (monotone minima\u3001\
    (min, +) \u7573\u307F\u8FBC\u307F\u3001Alien DP\u3001Knuth\u2013Yao)\n */\n\n\
    #include <algorithm>\n#include <cassert>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\
    \u4F4D\u7F6E (\u6700\u3082\u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\
    \u3066\u5358\u8ABF\u975E\u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\
    \u306E\u3001\u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log\
    \ H)\n * select(i, j, k) (j < k) \u306F\u3001\u884C i \u3067\u5217 k \u306E\u5024\
    \u304C\u5217 j \u306E\u5024\u3088\u308A\u771F\u306B\u5C0F\u3055\u3044\u306A\u3089\
    \ true \u3092\u8FD4\u3059\n * (\u5024\u3092\u8FD4\u3059\u95A2\u6570\u304C\u3042\
    \u308B\u306A\u3089 monotone_minima \u3092\u4F7F\u3046\u3002\u7BC4\u56F2\u5916\u306E\
    \u5217\u3092\u300C\u9078\u3070\u306A\u3044\u300D\u3068\u6C7A\u3081\u305F\u3044\
    \u3068\u304D\u306F\u3053\u3061\u3089\u3067\u6BD4\u3079\u65B9\u3092\u66F8\u304F\
    )\n */\ntemplate <typename Select>\nstd::vector<long long> monotone_minima_select(long\
    \ long H, long long W, Select select) {\n    assert(H >= 0 && W >= 1);\n    std::vector<long\
    \ long> res(H);\n    // \u884C [top, bottom) \u306E\u6700\u5C0F\u306E\u4F4D\u7F6E\
    \u304C\u5217 [left, right] \u306B\u3042\u308B\u3068\u3057\u3066\u3001\u771F\u3093\
    \u4E2D\u306E\u884C\u304B\u3089\u6C7A\u3081\u308B\n    auto rec = [&](auto&& self,\
    \ long long top, long long bottom, long long left, long long right) -> void {\n\
    \        if (top >= bottom) return;\n        const long long mid = (top + bottom)\
    \ / 2;\n        long long best = left;\n        for (long long j = left + 1; j\
    \ <= right; j++)\n            if (select(mid, best, j)) best = j;\n        res[mid]\
    \ = best;\n        self(self, top, mid, left, best);\n        self(self, mid +\
    \ 1, bottom, best, right);\n    };\n    rec(rec, 0, H, 0, W - 1);\n    return\
    \ res;\n}\n\n/**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E\
    \ (\u6700\u3082\u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\
    \u8ABF\u975E\u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\
    \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * f(i,\
    \ j) \u306F (i, j) \u6210\u5206\u306E\u5024\u3002Monge \u306A\u884C\u5217 (f(i,\
    \ j) + f(i', j') <= f(i, j') + f(i', j)\u3001i < i'\u3001j < j') \u306A\u3089\u3053\
    \u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\n */\ntemplate <typename F>\nstd::vector<long\
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
    \u4F7F\u3046\n * @note k \u306F\u3061\u3087\u3046\u3069 k \u500B\u9078\u3079\u308B\
    \ (f(k) \u304C\u5B9A\u7FA9\u3055\u308C\u308B) \u5024\u3067\u3042\u308B\u3053\u3068\
    \u3002\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u7D50\u679C\u306F\u610F\u5473\
    \u3092\u6301\u305F\u306A\u3044\n */\ntemplate <typename Solve>\nlong long alien_dp(long\
    \ long k, long long lo, long long hi, Solve solve) {\n    assert(lo <= hi);\n\
    \    // x_min(lambda) \u306F lambda \u306B\u3064\u3044\u3066\u5358\u8ABF\u975E\
    \u5897\u52A0\u3002x_min(lambda) <= k \u3068\u306A\u308B\u6700\u5C0F\u306E lambda\
    \ \u3092\u63A2\u3059\n    // \u305D\u306E\u3068\u304D k \u306F\u6700\u5C0F\u5024\
    \u3092\u3068\u308B x \u306E\u7BC4\u56F2 [x_min(lambda), x_min(lambda - 1)] \u306B\
    \u5165\u308B\u306E\u3067\u3001f(k) = \u6700\u5C0F\u5024 - lambda k\n    while\
    \ (lo < hi) {\n        long long mid = lo + (hi - lo) / 2;\n        if (solve(mid).second\
    \ <= k) {\n            hi = mid;\n        } else {\n            lo = mid + 1;\n\
    \        }\n    }\n    auto [val, x] = solve(lo);\n    assert(x <= k && \"alien_dp:\
    \ [lo, hi] \u304C\u72ED\u3044\");\n    return val - lo * k;\n}\n\n/**\n * @brief\
    \ \u533A\u9593 DP dp[i][j] = min_{i < k < j} (dp[i][k] + dp[k][j]) + w(i, j) (j\
    \ - i >= 2)\u3001dp[i][i+1] = base(i) \u3092\n * Knuth\u2013Yao \u306E\u9AD8\u901F\
    \u5316\u3067\u6C42\u3081\u308B O(n^2)\n *\n * w \u304C quadrangle inequality (a\
    \ <= b <= c <= d \u3067 w(a, c) + w(b, d) <= w(a, d) + w(b, c)) \u3068\n * \u5358\
    \u8ABF\u6027 (w(b, c) <= w(a, d)) \u3092\u6E80\u305F\u305B\u3070\u3001\u6700\u9069\
    \u306A k \u306F opt[i][j-1] <= opt[i][j] <= opt[i+1][j] \u3092\u6E80\u305F\u3059\
    \u306E\u3067\u3001\u305D\u306E\u7BC4\u56F2\u3060\u3051\u3092\u8ABF\u3079\u308B\
    \n * (base \u306E\u5024\u306F\u6700\u9069\u306A k \u306B\u5F71\u97FF\u3057\u306A\
    \u3044\u3002\u533A\u9593\u306E base \u306E\u548C\u3092\u5F15\u3051\u3070 base\
    \ = 0 \u306E\u5834\u5408\u306B\u306A\u308B\u305F\u3081)\n * @param n \u533A\u9593\
    \u306E\u7AEF\u306E\u500B\u6570 - 1 (0 <= i < j <= n)\n * @return std::vector<std::vector<T>>\
    \ dp[i][j] (0 <= i < j <= n\u3001\u305D\u308C\u4EE5\u5916\u306F\u4F7F\u308F\u306A\
    \u3044)\n */\ntemplate <typename Base, typename W, typename T = std::decay_t<std::invoke_result_t<Base,\
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
    \  }\n    }\n    return dp;\n}\n"
  code: "#pragma once\n\n/**\n * @file monge.hpp\n * @brief Monge \u6027\u3092\u4F7F\
    \u3046 DP \u306E\u9AD8\u901F\u5316 (monotone minima\u3001(min, +) \u7573\u307F\
    \u8FBC\u307F\u3001Alien DP\u3001Knuth\u2013Yao)\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <type_traits>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E (\u6700\
    \u3082\u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\u8ABF\
    \u975E\u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\u5404\
    \u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * select(i,\
    \ j, k) (j < k) \u306F\u3001\u884C i \u3067\u5217 k \u306E\u5024\u304C\u5217 j\
    \ \u306E\u5024\u3088\u308A\u771F\u306B\u5C0F\u3055\u3044\u306A\u3089 true \u3092\
    \u8FD4\u3059\n * (\u5024\u3092\u8FD4\u3059\u95A2\u6570\u304C\u3042\u308B\u306A\
    \u3089 monotone_minima \u3092\u4F7F\u3046\u3002\u7BC4\u56F2\u5916\u306E\u5217\u3092\
    \u300C\u9078\u3070\u306A\u3044\u300D\u3068\u6C7A\u3081\u305F\u3044\u3068\u304D\
    \u306F\u3053\u3061\u3089\u3067\u6BD4\u3079\u65B9\u3092\u66F8\u304F)\n */\ntemplate\
    \ <typename Select>\nstd::vector<long long> monotone_minima_select(long long H,\
    \ long long W, Select select) {\n    assert(H >= 0 && W >= 1);\n    std::vector<long\
    \ long> res(H);\n    // \u884C [top, bottom) \u306E\u6700\u5C0F\u306E\u4F4D\u7F6E\
    \u304C\u5217 [left, right] \u306B\u3042\u308B\u3068\u3057\u3066\u3001\u771F\u3093\
    \u4E2D\u306E\u884C\u304B\u3089\u6C7A\u3081\u308B\n    auto rec = [&](auto&& self,\
    \ long long top, long long bottom, long long left, long long right) -> void {\n\
    \        if (top >= bottom) return;\n        const long long mid = (top + bottom)\
    \ / 2;\n        long long best = left;\n        for (long long j = left + 1; j\
    \ <= right; j++)\n            if (select(mid, best, j)) best = j;\n        res[mid]\
    \ = best;\n        self(self, top, mid, left, best);\n        self(self, mid +\
    \ 1, bottom, best, right);\n    };\n    rec(rec, 0, H, 0, W - 1);\n    return\
    \ res;\n}\n\n/**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E\
    \ (\u6700\u3082\u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\
    \u8ABF\u975E\u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\
    \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * f(i,\
    \ j) \u306F (i, j) \u6210\u5206\u306E\u5024\u3002Monge \u306A\u884C\u5217 (f(i,\
    \ j) + f(i', j') <= f(i, j') + f(i', j)\u3001i < i'\u3001j < j') \u306A\u3089\u3053\
    \u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\n */\ntemplate <typename F>\nstd::vector<long\
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
    \u4F7F\u3046\n * @note k \u306F\u3061\u3087\u3046\u3069 k \u500B\u9078\u3079\u308B\
    \ (f(k) \u304C\u5B9A\u7FA9\u3055\u308C\u308B) \u5024\u3067\u3042\u308B\u3053\u3068\
    \u3002\u305D\u3046\u3067\u306A\u3051\u308C\u3070\u7D50\u679C\u306F\u610F\u5473\
    \u3092\u6301\u305F\u306A\u3044\n */\ntemplate <typename Solve>\nlong long alien_dp(long\
    \ long k, long long lo, long long hi, Solve solve) {\n    assert(lo <= hi);\n\
    \    // x_min(lambda) \u306F lambda \u306B\u3064\u3044\u3066\u5358\u8ABF\u975E\
    \u5897\u52A0\u3002x_min(lambda) <= k \u3068\u306A\u308B\u6700\u5C0F\u306E lambda\
    \ \u3092\u63A2\u3059\n    // \u305D\u306E\u3068\u304D k \u306F\u6700\u5C0F\u5024\
    \u3092\u3068\u308B x \u306E\u7BC4\u56F2 [x_min(lambda), x_min(lambda - 1)] \u306B\
    \u5165\u308B\u306E\u3067\u3001f(k) = \u6700\u5C0F\u5024 - lambda k\n    while\
    \ (lo < hi) {\n        long long mid = lo + (hi - lo) / 2;\n        if (solve(mid).second\
    \ <= k) {\n            hi = mid;\n        } else {\n            lo = mid + 1;\n\
    \        }\n    }\n    auto [val, x] = solve(lo);\n    assert(x <= k && \"alien_dp:\
    \ [lo, hi] \u304C\u72ED\u3044\");\n    return val - lo * k;\n}\n\n/**\n * @brief\
    \ \u533A\u9593 DP dp[i][j] = min_{i < k < j} (dp[i][k] + dp[k][j]) + w(i, j) (j\
    \ - i >= 2)\u3001dp[i][i+1] = base(i) \u3092\n * Knuth\u2013Yao \u306E\u9AD8\u901F\
    \u5316\u3067\u6C42\u3081\u308B O(n^2)\n *\n * w \u304C quadrangle inequality (a\
    \ <= b <= c <= d \u3067 w(a, c) + w(b, d) <= w(a, d) + w(b, c)) \u3068\n * \u5358\
    \u8ABF\u6027 (w(b, c) <= w(a, d)) \u3092\u6E80\u305F\u305B\u3070\u3001\u6700\u9069\
    \u306A k \u306F opt[i][j-1] <= opt[i][j] <= opt[i+1][j] \u3092\u6E80\u305F\u3059\
    \u306E\u3067\u3001\u305D\u306E\u7BC4\u56F2\u3060\u3051\u3092\u8ABF\u3079\u308B\
    \n * (base \u306E\u5024\u306F\u6700\u9069\u306A k \u306B\u5F71\u97FF\u3057\u306A\
    \u3044\u3002\u533A\u9593\u306E base \u306E\u548C\u3092\u5F15\u3051\u3070 base\
    \ = 0 \u306E\u5834\u5408\u306B\u306A\u308B\u305F\u3081)\n * @param n \u533A\u9593\
    \u306E\u7AEF\u306E\u500B\u6570 - 1 (0 <= i < j <= n)\n * @return std::vector<std::vector<T>>\
    \ dp[i][j] (0 <= i < j <= n\u3001\u305D\u308C\u4EE5\u5916\u306F\u4F7F\u308F\u306A\
    \u3044)\n */\ntemplate <typename Base, typename W, typename T = std::decay_t<std::invoke_result_t<Base,\
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
    \  }\n    }\n    return dp;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/monge.hpp
  requiredBy: []
  timestamp: '2026-10-27 20:28:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/monge.test.cpp
  - test/aoj/alds1/alds1-10-d.test.cpp
  - test/yosupo/convolution/min-plus-convolution-convex-arbitrary.test.cpp
  - test/yosupo/convolution/min-plus-convolution-convex-convex.test.cpp
documentation_of: src/dp/monge.hpp
layout: document
title: "Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\u5316 (monotone minima\u30FB\
  (min, +) \u7573\u307F\u8FBC\u307F\u30FBAlien DP\u30FBKnuth\u2013Yao)"
---

Monge 性や凸性を使って DP を速くする道具です。

- `monotone_minima`: 各行の最小値の位置が単調な行列について、各行の最小値の位置を $O((H + W) \log H)$ で求めます。DP の遷移 $\mathrm{dp}_i = \min_j (\ldots)$ の最適な $j$ が $i$ について単調なときに使います。
- `min_plus_convolution_*`: $c_k = \min_{i + j = k} (a_i + b_j)$ を、片方が凸なら $O((N + M) \log (N + M))$、両方が凸なら $O(N + M)$ で求めます。
- `alien_dp`: 「ちょうど $k$ 個選ぶ」という制約のある最小化を、答えが $k$ について凸なら、1 個選ぶごとにペナルティ $\lambda$ を足した制約のない問題に直して、$\lambda$ を二分探索して解きます (Alien DP、Lagrange 緩和)。

```cpp
// 各行の最小値の位置 (Monge な行列)
auto arg = monotone_minima(H, W, [&](long long i, long long j) { return cost(i, j); });

// (min, +) 畳み込み (a は凸、b は任意)
std::vector<long long> c = min_plus_convolution_convex_arbitrary(a, b);

// 配列を連続するちょうど k 個の区間に分け、区間ごとのコストの和を最小にする (答えが k について凸のとき)
long long ans = alien_dp(k, -1000000000000LL, 1000000000000LL, [&](long long lambda) {
    // 区間 1 つにつき lambda を足し、区間の個数は自由にした DP。{最小値, 最小値をとる区間の個数のうち最小} を返す
    std::vector<std::pair<long long, long long>> e(n + 1, {INF, 0});
    e[0] = {0, 0};
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++) e[i] = std::min(e[i], {e[j].first + cost(j, i) + lambda, e[j].second + 1});
    return e[n];
});
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `monotone_minima(H, W, f)` | $H$ 行 $W$ 列の行列 (成分は `f(i, j)`) の各行の最小値の位置 (同じ値なら最も左) を `std::vector<long long>` で返す。最小値の位置が行について単調非減少であること (Monge な行列ならよい) | $O((H + W) \log H)$ 回の `f` |
| `monotone_minima_select(H, W, select)` | 上と同じだが、比べ方を `select(i, j, k)` ($j < k$、行 $i$ で列 $k$ が列 $j$ より真に小さいなら `true`) で渡す。範囲外の成分を「選ばない」としたいときに使う | 同上 |
| `min_plus_convolution_convex_arbitrary(a, b)` | $c_k = \min_{i + j = k} (a_i + b_j)$。`a` が凸 ($a_{i+1} - a_i$ が単調非減少) で、`b` は任意 | $O((N + M) \log (N + M))$ |
| `min_plus_convolution_convex_convex(a, b)` | 同じ $c$。`a`、`b` がともに凸。差分を小さい順に併合する | $O(N + M)$ |
| `alien_dp(k, lo, hi, solve)` | ちょうど $k$ 個選ぶときの最小値 $f(k)$ ($f$ は凸で、$f(x+1) - f(x)$ は整数) | `solve` を $O(\log (hi - lo))$ 回 |
| `knuth_yao(n, base, w)` | 区間 DP $\mathit{dp}[i][j] = \min_{i < k < j} (\mathit{dp}[i][k] + \mathit{dp}[k][j]) + w(i, j)$、$\mathit{dp}[i][i+1] = \mathit{base}(i)$ の表 ($0 \le i < j \le n$) を返す。$w$ が quadrangle inequality と単調性を満たすこと | $O(n^2)$ |

- Monge な行列とは、$i < i'$、$j < j'$ について $f(i, j) + f(i', j') \le f(i, j') + f(i', j)$ を満たすものです。例えば、凸関数 $g$ について $g(x_i - y_j)$ ($x$、$y$ は昇順) や、$a_{i-j}$ ($a$ は凸) は Monge です。
- `alien_dp` の `k` は、ちょうど $k$ 個選ぶことができる (実行可能な) 値であることを前提にします。実行不可能な $k$ を渡したときの結果は意味を持ちません (判定はしません)。
- `alien_dp` の `solve(lambda)` は、$\min_x (f(x) + \lambda x)$ と、その最小値をとる $x$ のうち最小のものの組 `{値, x}` を返します。$\lambda$ は $[lo, hi]$ の整数から二分探索するので、$f$ の傾き $f(x+1) - f(x)$ がすべて $[-hi, -lo]$ に入るようにとります。$\lambda k$ や `solve` の値があふれないように注意します。最大化なら $f$ の符号を反転して使います。
- `alien_dp` は、$x_{\min}(\lambda) \le k$ となる最小の $\lambda$ を探します。傾きが整数なら、そのとき $k$ は最小値をとる $x$ の範囲 $[x_{\min}(\lambda), x_{\min}(\lambda - 1)]$ に入るので、$f(k) = (\text{最小値}) - \lambda k$ です。
- `knuth_yao` の $w$ の条件は、$a \le b \le c \le d$ について $w(a, c) + w(b, d) \le w(a, d) + w(b, c)$ (quadrangle inequality) と $w(b, c) \le w(a, d)$ (単調性) です。このとき最適な $k$ が $\mathit{opt}[i][j-1] \le \mathit{opt}[i][j] \le \mathit{opt}[i+1][j]$ を満たすので、その範囲だけを調べます。非負の数列の区間和や、その 2 乗は条件を満たします。$\mathit{base}$ の値は最適な $k$ に影響しません。
- 石を隣どうし併合するコストの最小化 (区間和の $w$) や、最適二分探索木 (ダミーの鍵を葉とした区間の DP) に使えます。

```cpp
// 石の併合: 隣り合う山を併合するとき、2 つの山の石の個数の和だけコストがかかる
auto dp = knuth_yao(n, [](long long) { return 0LL; }, [&](long long i, long long j) { return s[j] - s[i]; });  // s は累積和
long long cost = dp[0][n];
```

## 関連

- 直線の集合の最小値で遷移するなら [Convex Hull Trick](../data_structures/convex-hull-trick.hpp)
