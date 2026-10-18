---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/knapsack.hpp
    title: "\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\u984C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B
  bundledCode: "#line 1 \"test/aoj/dpl-1-b.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/dp/knapsack.hpp\"\n\
    \n/**\n * @file knapsack.hpp\n * @brief \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u554F\
    \u984C\n */\n\n#include <algorithm>\n#include <cassert>\n#include <deque>\n#include\
    \ <limits>\n#include <utility>\n#line 14 \"src/dp/knapsack.hpp\"\n\n/*\n * \u54C1\
    \u7269 i \u306F\u4FA1\u5024 v[i] \u3068\u91CD\u3055 w[i] \u3092\u6301\u3061 (\u3069\
    \u3061\u3089\u3082 0 \u4EE5\u4E0A)\u3001\u91CD\u3055\u306E\u548C\u304C W \u4EE5\
    \u4E0B\u306B\u306A\u308B\u3088\u3046\u306B\u9078\u3093\u3067\u3001\u4FA1\u5024\
    \u306E\u548C\u306E\u6700\u5927\u5024\u3092\u6C42\u3081\u308B\n * \u7B54\u3048\
    \ (\u4FA1\u5024\u306E\u548C\u306E\u6700\u5927\u5024) \u306F long long \u306B\u53CE\
    \u307E\u308B\u3053\u3068\n */\n\nnamespace internal_knapsack {\ninline void check(const\
    \ std::vector<long long>& v, const std::vector<long long>& w, long long W) {\n\
    \    assert(v.size() == w.size() && W >= 0);\n    for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) assert(v[i] >= 0 && w[i] >= 0);\n}\n\n// \u5404\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u306E\u8A08\u7B97\u91CF\u306E\u898B\u7A4D\u3082\u308A (\u5927\u304D\
    \u3059\u304E\u308B\u3082\u306E\u306F inf)\ninline long double cost_by_weight(int\
    \ n, long long W) { return static_cast<long double>(n + 1) * (static_cast<long\
    \ double>(W) + 1); }\ninline long double cost_by_value(int n, long double value_sum)\
    \ { return static_cast<long double>(n + 1) * (value_sum + 1); }\ninline long double\
    \ cost_meet_in_the_middle(int n) {\n    if (n > 80) return std::numeric_limits<long\
    \ double>::infinity();\n    return static_cast<long double>(n + 1) * static_cast<long\
    \ double>(1ULL << ((n + 1) / 2));\n}\n\n// \u500B\u6570\u5236\u9650\u4ED8\u304D\
    \u306E\u54C1\u7269\u3092\u3001\u500B\u6570 1, 2, 4, ..., \u6B8B\u308A \u306E\u7D44\
    \u306B\u5206\u3051\u3066 0/1 \u306E\u54C1\u7269\u306B\u3059\u308B\ninline void\
    \ binary_split(const std::vector<long long>& v, const std::vector<long long>&\
    \ w, const std::vector<long long>& m,\n                         long long W, std::vector<long\
    \ long>& v2, std::vector<long long>& w2) {\n    for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) {\n        long long c = m[i];\n        // W \u3092\u8D85\u3048\u308B\u500B\
    \u6570\u306F\u4F7F\u3048\u306A\u3044\n        if (w[i] > 0) c = std::min(c, W\
    \ / w[i]);\n        for (long long k = 1; c > 0; k *= 2) {\n            long long\
    \ t = std::min(k, c);\n            v2.push_back(v[i] * t);\n            w2.push_back(w[i]\
    \ * t);\n            c -= t;\n        }\n    }\n}\n}  // namespace internal_knapsack\n\
    \n/**\n * @brief 0/1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF (\u91CD\u3055\u306B\u3064\
    \u3044\u3066\u306E DP) O(N W)\n */\ninline long long knapsack_by_weight(const\
    \ std::vector<long long>& v, const std::vector<long long>& w, long long W) {\n\
    \    internal_knapsack::check(v, w, W);\n    // dp[j] \u306F\u91CD\u3055\u306E\
    \u548C\u304C j \u4EE5\u4E0B\u306E\u3068\u304D\u306E\u4FA1\u5024\u306E\u548C\u306E\
    \u6700\u5927\u5024\n    std::vector<long long> dp(W + 1, 0);\n    for (int i =\
    \ 0; i < static_cast<int>(v.size()); i++) {\n        if (w[i] > W) continue;\n\
    \        for (long long j = W; j >= w[i]; j--) dp[j] = std::max(dp[j], dp[j -\
    \ w[i]] + v[i]);\n    }\n    return dp[W];\n}\n\n/**\n * @brief 0/1 \u30CA\u30C3\
    \u30D7\u30B5\u30C3\u30AF (\u4FA1\u5024\u306B\u3064\u3044\u3066\u306E DP) O(N V)\
    \ (V \u306F\u4FA1\u5024\u306E\u548C)\n */\ninline long long knapsack_by_value(const\
    \ std::vector<long long>& v, const std::vector<long long>& w, long long W) {\n\
    \    internal_knapsack::check(v, w, W);\n    long long value_sum = 0;\n    for\
    \ (long long x : v) value_sum += x;\n    // dp[s] \u306F\u4FA1\u5024\u306E\u548C\
    \u304C\u3061\u3087\u3046\u3069 s \u306E\u3068\u304D\u306E\u91CD\u3055\u306E\u548C\
    \u306E\u6700\u5C0F\u5024 (W \u3092\u8D85\u3048\u308B\u3082\u306E\u306F INF)\n\
    \    const long long INF = std::numeric_limits<long long>::max();\n    std::vector<long\
    \ long> dp(value_sum + 1, INF);\n    dp[0] = 0;\n    for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) {\n        if (w[i] > W) continue;\n        for (long long s = value_sum;\
    \ s >= v[i]; s--) {\n            long long prev = dp[s - v[i]];\n            if\
    \ (prev != INF && prev <= W - w[i]) dp[s] = std::min(dp[s], prev + w[i]);\n  \
    \      }\n    }\n    for (long long s = value_sum;; s--) {\n        if (dp[s]\
    \ <= W) return s;\n    }\n}\n\n/**\n * @brief 0/1 \u30CA\u30C3\u30D7\u30B5\u30C3\
    \u30AF (\u534A\u5206\u5168\u5217\u6319) O(2^(N/2) N)\n * N \u304C 40 \u7A0B\u5EA6\
    \u307E\u3067\u306A\u3089\u3001\u91CD\u3055\u3084\u4FA1\u5024\u304C\u5927\u304D\
    \u304F\u3066\u3082\u3088\u3044\n */\ninline long long knapsack_meet_in_the_middle(const\
    \ std::vector<long long>& v, const std::vector<long long>& w, long long W) {\n\
    \    internal_knapsack::check(v, w, W);\n    int n = v.size();\n    // \u54C1\u7269\
    \ [l, r) \u306E\u90E8\u5206\u96C6\u5408\u306E\u3046\u3061\u91CD\u3055\u306E\u548C\
    \u304C W \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u3001(\u91CD\u3055, \u4FA1\u5024\
    ) \u306E\u91CD\u3055\u306E\u6607\u9806\u3067\u5217\u6319\u3059\u308B\n    auto\
    \ enumerate = [&](int l, int r) {\n        std::vector<std::pair<long long, long\
    \ long>> res = {{0, 0}}, add, merged;\n        for (int i = l; i < r; i++) {\n\
    \            add.clear();\n            for (auto [x, y] : res) {\n           \
    \     if (w[i] <= W - x) add.emplace_back(x + w[i], y + v[i]);\n            }\n\
    \            merged.resize(res.size() + add.size());\n            std::merge(res.begin(),\
    \ res.end(), add.begin(), add.end(), merged.begin());\n            std::swap(res,\
    \ merged);\n        }\n        return res;\n    };\n    auto a = enumerate(0,\
    \ n / 2), b = enumerate(n / 2, n);\n    // b \u306E\u4FA1\u5024\u3092\u3001\u91CD\
    \u3055\u304C\u305D\u308C\u4EE5\u4E0B\u306E\u3082\u306E\u306E\u6700\u5927\u5024\
    \u306B\u7F6E\u304D\u63DB\u3048\u308B\n    for (int i = 1; i < static_cast<int>(b.size());\
    \ i++) b[i].second = std::max(b[i].second, b[i - 1].second);\n    long long res\
    \ = 0;\n    int j = b.size() - 1;\n    for (auto [x, y] : a) {\n        while\
    \ (j >= 0 && b[j].first > W - x) j--;\n        if (j < 0) break;\n        res\
    \ = std::max(res, y + b[j].second);\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ 0/1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u3002\u5165\u529B\u306E\u5927\u304D\
    \u3055\u304B\u3089\u3001\u8A08\u7B97\u91CF\u304C\u6700\u3082\u5C0F\u3055\u3044\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3092\u9078\u3076\n *\n * knapsack_by_weight\
    \ O(N W)\u3001knapsack_by_value O(N V)\u3001knapsack_meet_in_the_middle O(2^(N/2)\
    \ N) \u306E\u3044\u305A\u308C\u304B\n */\ninline long long knapsack(const std::vector<long\
    \ long>& v, const std::vector<long long>& w, long long W) {\n    using namespace\
    \ internal_knapsack;\n    int n = v.size();\n    long double value_sum = 0;\n\
    \    for (long long x : v) value_sum += x;\n    long double cw = cost_by_weight(n,\
    \ W), cv = cost_by_value(n, value_sum), cm = cost_meet_in_the_middle(n);\n   \
    \ if (cw <= cv && cw <= cm) return knapsack_by_weight(v, w, W);\n    if (cv <=\
    \ cm) return knapsack_by_value(v, w, W);\n    return knapsack_meet_in_the_middle(v,\
    \ w, W);\n}\n\n/**\n * @brief \u500B\u6570\u5236\u9650\u306A\u3057\u30CA\u30C3\
    \u30D7\u30B5\u30C3\u30AF (\u540C\u3058\u54C1\u7269\u3092\u4F55\u500B\u3067\u3082\
    \u9078\u3079\u308B) O(N W)\n */\ninline long long unbounded_knapsack(const std::vector<long\
    \ long>& v, const std::vector<long long>& w, long long W) {\n    internal_knapsack::check(v,\
    \ w, W);\n    for (int i = 0; i < static_cast<int>(v.size()); i++) assert((w[i]\
    \ > 0 || v[i] == 0) && \"unbounded_knapsack: infinite value\");\n    std::vector<long\
    \ long> dp(W + 1, 0);\n    for (int i = 0; i < static_cast<int>(v.size()); i++)\
    \ {\n        if (w[i] == 0 || w[i] > W) continue;\n        for (long long j =\
    \ w[i]; j <= W; j++) dp[j] = std::max(dp[j], dp[j - w[i]] + v[i]);\n    }\n  \
    \  return dp[W];\n}\n\n/**\n * @brief \u500B\u6570\u5236\u9650\u4ED8\u304D\u30CA\
    \u30C3\u30D7\u30B5\u30C3\u30AF (\u54C1\u7269 i \u306F m[i] \u500B\u307E\u3067\u9078\
    \u3079\u308B\u3001\u91CD\u3055\u306B\u3064\u3044\u3066\u306E DP) O(N W)\n * \u91CD\
    \u3055\u3092 w[i] \u3067\u5272\u3063\u305F\u4F59\u308A\u3054\u3068\u306B\u3001\
    \u30B9\u30E9\u30A4\u30C9\u6700\u5927\u5024\u3092\u4F7F\u3046\n */\ninline long\
    \ long bounded_knapsack_by_weight(const std::vector<long long>& v, const std::vector<long\
    \ long>& w,\n                                            const std::vector<long\
    \ long>& m, long long W) {\n    internal_knapsack::check(v, w, W);\n    assert(m.size()\
    \ == v.size());\n    std::vector<long long> dp(W + 1, 0), cur;\n    std::deque<std::pair<long\
    \ long, long long>> dq;  // (t, dp[r + t w] - t v) \u3067\u3001\u5024\u304C\u6E1B\
    \u5C11\u3059\u308B\u9806\n    for (int i = 0; i < static_cast<int>(v.size());\
    \ i++) {\n        assert(m[i] >= 0);\n        if (w[i] == 0) {\n            for\
    \ (auto& x : dp) x += v[i] * m[i];\n            continue;\n        }\n       \
    \ if (w[i] > W) continue;\n        for (long long r = 0; r < w[i]; r++) {\n  \
    \          // j = r + k w \u306B\u3064\u3044\u3066 dp[j] = max_{k - m <= t <=\
    \ k} (dp[r + t w] - t v) + k v\n            cur.clear();\n            for (long\
    \ long j = r; j <= W; j += w[i]) cur.push_back(dp[j]);\n            dq.clear();\n\
    \            for (long long k = 0; k < static_cast<long long>(cur.size()); k++)\
    \ {\n                long long val = cur[k] - k * v[i];\n                while\
    \ (!dq.empty() && dq.back().second <= val) dq.pop_back();\n                dq.emplace_back(k,\
    \ val);\n                if (dq.front().first < k - m[i]) dq.pop_front();\n  \
    \              dp[r + k * w[i]] = dq.front().second + k * v[i];\n            }\n\
    \        }\n    }\n    return dp[W];\n}\n\n/**\n * @brief \u500B\u6570\u5236\u9650\
    \u4ED8\u304D\u30CA\u30C3\u30D7\u30B5\u30C3\u30AF (\u4E8C\u9032\u5206\u5272\u3067\
    \ 0/1 \u30CA\u30C3\u30D7\u30B5\u30C3\u30AF\u306B\u3057\u3066\u3001\u4FA1\u5024\
    \u306B\u3064\u3044\u3066\u306E DP) O(V sum log m[i]) (V \u306F v[i] m[i] \u306E\
    \u548C)\n */\ninline long long bounded_knapsack_by_value(const std::vector<long\
    \ long>& v, const std::vector<long long>& w,\n                               \
    \            const std::vector<long long>& m, long long W) {\n    internal_knapsack::check(v,\
    \ w, W);\n    assert(m.size() == v.size());\n    std::vector<long long> v2, w2;\n\
    \    internal_knapsack::binary_split(v, w, m, W, v2, w2);\n    return knapsack_by_value(v2,\
    \ w2, W);\n}\n\n/**\n * @brief \u500B\u6570\u5236\u9650\u4ED8\u304D\u30CA\u30C3\
    \u30D7\u30B5\u30C3\u30AF\u3002\u5165\u529B\u306E\u5927\u304D\u3055\u304B\u3089\
    \u3001\u8A08\u7B97\u91CF\u304C\u6700\u3082\u5C0F\u3055\u3044\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\u3092\u9078\u3076\n *\n * bounded_knapsack_by_weight O(N W)\u3001\
    \u4E8C\u9032\u5206\u5272\u3057\u305F\u5F8C\u306E 0/1 \u30CA\u30C3\u30D7\u30B5\u30C3\
    \u30AF\u306E\u4FA1\u5024\u306B\u3064\u3044\u3066\u306E DP \u304B\u534A\u5206\u5168\
    \u5217\u6319\u306E\u3044\u305A\u308C\u304B\n */\ninline long long bounded_knapsack(const\
    \ std::vector<long long>& v, const std::vector<long long>& w,\n              \
    \                    const std::vector<long long>& m, long long W) {\n    using\
    \ namespace internal_knapsack;\n    check(v, w, W);\n    assert(m.size() == v.size());\n\
    \    int n = v.size();\n    // \u4E8C\u9032\u5206\u5272\u3057\u305F\u5F8C\u306E\
    \u54C1\u7269\u306E\u500B\u6570\u3068\u4FA1\u5024\u306E\u548C\n    long double\
    \ pieces = 0, value_sum = 0;\n    for (int i = 0; i < n; i++) {\n        long\
    \ long c = m[i];\n        if (w[i] > 0) c = std::min(c, W / w[i]);\n        for\
    \ (long long k = 1, rest = c; rest > 0; k *= 2) {\n            pieces++;\n   \
    \         rest -= std::min(k, rest);\n        }\n        value_sum += static_cast<long\
    \ double>(v[i]) * c;\n    }\n    long double cw = cost_by_weight(n, W);\n    long\
    \ double cv = pieces > 1e9 ? std::numeric_limits<long double>::infinity() : cost_by_value(static_cast<int>(pieces),\
    \ value_sum);\n    long double cm = pieces > 80 ? std::numeric_limits<long double>::infinity()\
    \ : cost_meet_in_the_middle(static_cast<int>(pieces));\n    if (cw <= cv && cw\
    \ <= cm) return bounded_knapsack_by_weight(v, w, m, W);\n    std::vector<long\
    \ long> v2, w2;\n    binary_split(v, w, m, W, v2, w2);\n    if (cv <= cm) return\
    \ knapsack_by_value(v2, w2, W);\n    return knapsack_meet_in_the_middle(v2, w2,\
    \ W);\n}\n#line 7 \"test/aoj/dpl-1-b.test.cpp\"\n\nint main() {\n    int n;\n\
    \    long long W;\n    std::cin >> n >> W;\n    std::vector<long long> v(n), w(n);\n\
    \    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i];\n    std::cout << knapsack_by_weight(v,\
    \ w, W) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/dp/knapsack.hpp\"\
    \n\nint main() {\n    int n;\n    long long W;\n    std::cin >> n >> W;\n    std::vector<long\
    \ long> v(n), w(n);\n    for (int i = 0; i < n; i++) std::cin >> v[i] >> w[i];\n\
    \    std::cout << knapsack_by_weight(v, w, W) << '\\n';\n}\n"
  dependsOn:
  - src/dp/knapsack.hpp
  isVerificationFile: true
  path: test/aoj/dpl-1-b.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/dpl-1-b.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/dpl-1-b.test.cpp
- /verify/test/aoj/dpl-1-b.test.cpp.html
title: test/aoj/dpl-1-b.test.cpp
---
