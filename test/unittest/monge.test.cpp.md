---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/monge.hpp
    title: "Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\u5316 (monotone minima\u30FB\
      (min, +) \u7573\u307F\u8FBC\u307F\u30FBAlien DP)"
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
  bundledCode: "#line 1 \"test/unittest/monge.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monge.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// monotone_minima \u306F Monge \u306A\
    \u884C\u5217\u3067\u3001(min, +) \u7573\u307F\u8FBC\u307F\u306F\u51F8\u5217\u3067\
    \u3001alien_dp \u306F\u51F8\u95A2\u6570\u3068\u3001\u533A\u9593\u306B\u5206\u3051\
    \u308B DP \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\
    \u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello\
    \ World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/dp/monge.hpp\"\n\n/**\n\
    \ * @file monge.hpp\n * @brief Monge \u6027\u3092\u4F7F\u3046 DP \u306E\u9AD8\u901F\
    \u5316 (monotone minima\u3001(min, +) \u7573\u307F\u8FBC\u307F\u3001Alien DP)\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E\
    \ (\u6700\u3082\u5DE6\u306E\u3082\u306E) \u304C\u884C\u306B\u3064\u3044\u3066\u5358\
    \u8ABF\u975E\u6E1B\u5C11\u306A H \u884C W \u5217\u306E\u884C\u5217\u306E\u3001\
    \u5404\u884C\u306E\u6700\u5C0F\u5024\u306E\u4F4D\u7F6E O((H + W) log H)\n * select(i,\
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
    \ \u304C\u72ED\u3044\");\n    return val - lo * k;\n}\n#line 8 \"test/unittest/monge.test.cpp\"\
    \n\n#line 10 \"test/unittest/monge.test.cpp\"\n#include <iostream>\n#include <limits>\n\
    #include <random>\n#line 15 \"test/unittest/monge.test.cpp\"\n\nbool ok = true;\n\
    void check(bool cond, const char* what) {\n    if (!cond && ok) std::cerr << \"\
    failed: \" << what << std::endl;\n    if (!cond) ok = false;\n}\n\nint main()\
    \ {\n    std::mt19937_64 rng(314);\n    auto convex = [&](int n, long long range)\
    \ {\n        // \u5DEE\u5206\u3092\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u3066\
    \u304B\u3089\u8DB3\u3057\u3066\u3044\u304F\u3068\u51F8\u5217\u306B\u306A\u308B\
    \n        std::vector<long long> d(n), a(n);\n        for (auto& x : d) x = static_cast<long\
    \ long>(rng() % (2 * range + 1)) - range;\n        std::sort(d.begin(), d.end());\n\
    \        a[0] = static_cast<long long>(rng() % 100);\n        for (int i = 1;\
    \ i < n; i++) a[i] = a[i - 1] + d[i];\n        return a;\n    };\n\n    // monotone_minima:\
    \ (x_i - y_j)^2 + p_i + q_j (x, y \u306F\u6607\u9806) \u306F Monge\u3002\u6700\
    \u5C0F\u306E\u4F4D\u7F6E (\u6700\u3082\u5DE6) \u3092\u611A\u76F4\u306B\u6C42\u3081\
    \u3066\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n \
    \       int h = rng() % 12, w = rng() % 12 + 1;\n        std::vector<long long>\
    \ x(h), y(w), p(h), q(w);\n        for (auto& v : x) v = rng() % 10;  // \u5024\
    \u306E\u7BC4\u56F2\u3092\u72ED\u304F\u3057\u3066\u3001\u540C\u3058\u5024\u3082\
    \u3088\u304F\u51FA\u308B\u3088\u3046\u306B\u3059\u308B\n        for (auto& v :\
    \ y) v = rng() % 10;\n        for (auto& v : p) v = rng() % 5;\n        for (auto&\
    \ v : q) v = rng() % 5;\n        std::sort(x.begin(), x.end());\n        std::sort(y.begin(),\
    \ y.end());\n        auto f = [&](long long i, long long j) { return (x[i] - y[j])\
    \ * (x[i] - y[j]) + p[i] + q[j]; };\n        auto res = monotone_minima(h, w,\
    \ f);\n        for (int i = 0; i < h; i++) {\n            long long best = 0;\n\
    \            for (int j = 1; j < w; j++)\n                if (f(i, j) < f(i, best))\
    \ best = j;\n            check(res[i] == best, \"monotone_minima\");\n       \
    \ }\n    }\n\n    // (min, +) \u7573\u307F\u8FBC\u307F: \u3059\u3079\u3066\u306E\
    \u7D44\u3092\u8A66\u3057\u3066\u6BD4\u3079\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 10 + 1, m = rng() % 10 + 1;\n\
    \        std::vector<long long> a = convex(n, 20), b = convex(m, 20), c(m);\n\
    \        for (auto& v : c) v = rng() % 100;  // \u4EFB\u610F\u306E\u5217\n   \
    \     auto naive = [&](const std::vector<long long>& s, const std::vector<long\
    \ long>& t) {\n            std::vector<long long> r(s.size() + t.size() - 1, std::numeric_limits<long\
    \ long>::max());\n            for (size_t i = 0; i < s.size(); i++)\n        \
    \        for (size_t j = 0; j < t.size(); j++) r[i + j] = std::min(r[i + j], s[i]\
    \ + t[j]);\n            return r;\n        };\n        check(min_plus_convolution_convex_arbitrary(a,\
    \ c) == naive(a, c), \"convex_arbitrary\");\n        check(min_plus_convolution_convex_convex(a,\
    \ b) == naive(a, b), \"convex_convex\");\n    }\n\n    // alien_dp: \u51F8\u95A2\
    \u6570 f \u306B\u3064\u3044\u3066\u3001solve(lambda) \u3092\u611A\u76F4\u306B\u4F5C\
    \u3063\u3066 f(k) \u304C\u6C42\u307E\u308B\u304B\n    for (int rep = 0; rep <\
    \ 1000 && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long\
    \ long> f = convex(n, 30);\n        auto solve = [&](long long lambda) {\n   \
    \         std::pair<long long, long long> best = {f[0], 0};\n            for (int\
    \ x = 1; x < n; x++)\n                if (f[x] + lambda * x < best.first) best\
    \ = {f[x] + lambda * x, x};\n            return best;\n        };\n        for\
    \ (int k = 0; k < n; k++) check(alien_dp(k, -100, 100, solve) == f[k], \"alien_dp\
    \ \u51F8\u95A2\u6570\");\n    }\n    // alien_dp \u306E\u4F8B: \u914D\u5217\u3092\
    \u9023\u7D9A\u3059\u308B k \u500B\u306E\u533A\u9593\u306B\u5206\u3051\u3001\u533A\
    \u9593\u306E\u548C\u306E 2 \u4E57\u306E\u5408\u8A08\u3092\u6700\u5C0F\u306B\u3059\
    \u308B (k \u306B\u3064\u3044\u3066\u51F8)\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 10 + 1;\n        std::vector<long long>\
    \ v(n), s(n + 1, 0);\n        for (auto& x : v) x = rng() % 10;\n        for (int\
    \ i = 0; i < n; i++) s[i + 1] = s[i] + v[i];\n        auto cost = [&](int l, int\
    \ r) { return (s[r] - s[l]) * (s[r] - s[l]); };\n        const long long INF =\
    \ std::numeric_limits<long long>::max() / 4;\n        // \u611A\u76F4: dp[k][i]\
    \ = \u5148\u982D i \u500B\u3092 k \u500B\u306E\u533A\u9593\u306B\u5206\u3051\u308B\
    \u3068\u304D\u306E\u6700\u5C0F\n        std::vector<std::vector<long long>> dp(n\
    \ + 1, std::vector<long long>(n + 1, INF));\n        dp[0][0] = 0;\n        for\
    \ (int k = 1; k <= n; k++)\n            for (int i = 1; i <= n; i++)\n       \
    \         for (int j = 0; j < i; j++)\n                    if (dp[k - 1][j] <\
    \ INF) dp[k][i] = std::min(dp[k][i], dp[k - 1][j] + cost(j, i));\n        // \u533A\
    \u9593 1 \u3064\u306B\u3064\u304D lambda \u3092\u8DB3\u3057\u3001\u533A\u9593\u306E\
    \u500B\u6570\u306E\u5236\u7D04\u3092\u5916\u3057\u305F DP (\u540C\u3058\u5024\u306A\
    \u3089\u533A\u9593\u306E\u5C11\u306A\u3044\u65B9)\n        auto solve = [&](long\
    \ long lambda) {\n            std::vector<std::pair<long long, long long>> e(n\
    \ + 1, {INF, 0});\n            e[0] = {0, 0};\n            for (int i = 1; i <=\
    \ n; i++)\n                for (int j = 0; j < i; j++) e[i] = std::min(e[i], {e[j].first\
    \ + cost(j, i) + lambda, e[j].second + 1});\n            return e[n];\n      \
    \  };\n        for (int k = 1; k <= n; k++) check(alien_dp(k, -10000, 10000, solve)\
    \ == dp[k][n], \"alien_dp \u533A\u9593\u306B\u5206\u3051\u308B\");\n    }\n\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// monge.hpp \u306E\u95A2\u6570\u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\
    \u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// monotone_minima \u306F Monge \u306A\
    \u884C\u5217\u3067\u3001(min, +) \u7573\u307F\u8FBC\u307F\u306F\u51F8\u5217\u3067\
    \u3001alien_dp \u306F\u51F8\u95A2\u6570\u3068\u3001\u533A\u9593\u306B\u5206\u3051\
    \u308B DP \u3067\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\
    \u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello\
    \ World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/dp/monge.hpp\"\n\
    \n#include <algorithm>\n#include <iostream>\n#include <limits>\n#include <random>\n\
    #include <utility>\n#include <vector>\n\nbool ok = true;\nvoid check(bool cond,\
    \ const char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n    if (!cond) ok = false;\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n    auto convex = [&](int n, long long range) {\n        // \u5DEE\
    \u5206\u3092\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3079\u3066\u304B\u3089\u8DB3\
    \u3057\u3066\u3044\u304F\u3068\u51F8\u5217\u306B\u306A\u308B\n        std::vector<long\
    \ long> d(n), a(n);\n        for (auto& x : d) x = static_cast<long long>(rng()\
    \ % (2 * range + 1)) - range;\n        std::sort(d.begin(), d.end());\n      \
    \  a[0] = static_cast<long long>(rng() % 100);\n        for (int i = 1; i < n;\
    \ i++) a[i] = a[i - 1] + d[i];\n        return a;\n    };\n\n    // monotone_minima:\
    \ (x_i - y_j)^2 + p_i + q_j (x, y \u306F\u6607\u9806) \u306F Monge\u3002\u6700\
    \u5C0F\u306E\u4F4D\u7F6E (\u6700\u3082\u5DE6) \u3092\u611A\u76F4\u306B\u6C42\u3081\
    \u3066\u6BD4\u3079\u308B\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n \
    \       int h = rng() % 12, w = rng() % 12 + 1;\n        std::vector<long long>\
    \ x(h), y(w), p(h), q(w);\n        for (auto& v : x) v = rng() % 10;  // \u5024\
    \u306E\u7BC4\u56F2\u3092\u72ED\u304F\u3057\u3066\u3001\u540C\u3058\u5024\u3082\
    \u3088\u304F\u51FA\u308B\u3088\u3046\u306B\u3059\u308B\n        for (auto& v :\
    \ y) v = rng() % 10;\n        for (auto& v : p) v = rng() % 5;\n        for (auto&\
    \ v : q) v = rng() % 5;\n        std::sort(x.begin(), x.end());\n        std::sort(y.begin(),\
    \ y.end());\n        auto f = [&](long long i, long long j) { return (x[i] - y[j])\
    \ * (x[i] - y[j]) + p[i] + q[j]; };\n        auto res = monotone_minima(h, w,\
    \ f);\n        for (int i = 0; i < h; i++) {\n            long long best = 0;\n\
    \            for (int j = 1; j < w; j++)\n                if (f(i, j) < f(i, best))\
    \ best = j;\n            check(res[i] == best, \"monotone_minima\");\n       \
    \ }\n    }\n\n    // (min, +) \u7573\u307F\u8FBC\u307F: \u3059\u3079\u3066\u306E\
    \u7D44\u3092\u8A66\u3057\u3066\u6BD4\u3079\u308B\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 10 + 1, m = rng() % 10 + 1;\n\
    \        std::vector<long long> a = convex(n, 20), b = convex(m, 20), c(m);\n\
    \        for (auto& v : c) v = rng() % 100;  // \u4EFB\u610F\u306E\u5217\n   \
    \     auto naive = [&](const std::vector<long long>& s, const std::vector<long\
    \ long>& t) {\n            std::vector<long long> r(s.size() + t.size() - 1, std::numeric_limits<long\
    \ long>::max());\n            for (size_t i = 0; i < s.size(); i++)\n        \
    \        for (size_t j = 0; j < t.size(); j++) r[i + j] = std::min(r[i + j], s[i]\
    \ + t[j]);\n            return r;\n        };\n        check(min_plus_convolution_convex_arbitrary(a,\
    \ c) == naive(a, c), \"convex_arbitrary\");\n        check(min_plus_convolution_convex_convex(a,\
    \ b) == naive(a, b), \"convex_convex\");\n    }\n\n    // alien_dp: \u51F8\u95A2\
    \u6570 f \u306B\u3064\u3044\u3066\u3001solve(lambda) \u3092\u611A\u76F4\u306B\u4F5C\
    \u3063\u3066 f(k) \u304C\u6C42\u307E\u308B\u304B\n    for (int rep = 0; rep <\
    \ 1000 && ok; rep++) {\n        int n = rng() % 12 + 1;\n        std::vector<long\
    \ long> f = convex(n, 30);\n        auto solve = [&](long long lambda) {\n   \
    \         std::pair<long long, long long> best = {f[0], 0};\n            for (int\
    \ x = 1; x < n; x++)\n                if (f[x] + lambda * x < best.first) best\
    \ = {f[x] + lambda * x, x};\n            return best;\n        };\n        for\
    \ (int k = 0; k < n; k++) check(alien_dp(k, -100, 100, solve) == f[k], \"alien_dp\
    \ \u51F8\u95A2\u6570\");\n    }\n    // alien_dp \u306E\u4F8B: \u914D\u5217\u3092\
    \u9023\u7D9A\u3059\u308B k \u500B\u306E\u533A\u9593\u306B\u5206\u3051\u3001\u533A\
    \u9593\u306E\u548C\u306E 2 \u4E57\u306E\u5408\u8A08\u3092\u6700\u5C0F\u306B\u3059\
    \u308B (k \u306B\u3064\u3044\u3066\u51F8)\n    for (int rep = 0; rep < 300 &&\
    \ ok; rep++) {\n        int n = rng() % 10 + 1;\n        std::vector<long long>\
    \ v(n), s(n + 1, 0);\n        for (auto& x : v) x = rng() % 10;\n        for (int\
    \ i = 0; i < n; i++) s[i + 1] = s[i] + v[i];\n        auto cost = [&](int l, int\
    \ r) { return (s[r] - s[l]) * (s[r] - s[l]); };\n        const long long INF =\
    \ std::numeric_limits<long long>::max() / 4;\n        // \u611A\u76F4: dp[k][i]\
    \ = \u5148\u982D i \u500B\u3092 k \u500B\u306E\u533A\u9593\u306B\u5206\u3051\u308B\
    \u3068\u304D\u306E\u6700\u5C0F\n        std::vector<std::vector<long long>> dp(n\
    \ + 1, std::vector<long long>(n + 1, INF));\n        dp[0][0] = 0;\n        for\
    \ (int k = 1; k <= n; k++)\n            for (int i = 1; i <= n; i++)\n       \
    \         for (int j = 0; j < i; j++)\n                    if (dp[k - 1][j] <\
    \ INF) dp[k][i] = std::min(dp[k][i], dp[k - 1][j] + cost(j, i));\n        // \u533A\
    \u9593 1 \u3064\u306B\u3064\u304D lambda \u3092\u8DB3\u3057\u3001\u533A\u9593\u306E\
    \u500B\u6570\u306E\u5236\u7D04\u3092\u5916\u3057\u305F DP (\u540C\u3058\u5024\u306A\
    \u3089\u533A\u9593\u306E\u5C11\u306A\u3044\u65B9)\n        auto solve = [&](long\
    \ long lambda) {\n            std::vector<std::pair<long long, long long>> e(n\
    \ + 1, {INF, 0});\n            e[0] = {0, 0};\n            for (int i = 1; i <=\
    \ n; i++)\n                for (int j = 0; j < i; j++) e[i] = std::min(e[i], {e[j].first\
    \ + cost(j, i) + lambda, e[j].second + 1});\n            return e[n];\n      \
    \  };\n        for (int k = 1; k <= n; k++) check(alien_dp(k, -10000, 10000, solve)\
    \ == dp[k][n], \"alien_dp \u533A\u9593\u306B\u5206\u3051\u308B\");\n    }\n\n\
    \    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/monge.hpp
  isVerificationFile: true
  path: test/unittest/monge.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 02:56:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/monge.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/monge.test.cpp
- /verify/test/unittest/monge.test.cpp.html
title: test/unittest/monge.test.cpp
---
