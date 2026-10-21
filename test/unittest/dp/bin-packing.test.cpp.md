---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/dp/bin-packing.hpp
    title: "\u74F6\u8A70\u3081\u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\u30F3\u30B0\
      )"
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
  bundledCode: "#line 1 \"test/unittest/dp/bin-packing.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ bin_packing \u3092\u3001\u54C1\u7269\u3092\u3069\u306E\u74F6\u306B\u5165\u308C\
    \u308B\u304B\u3092\u3059\u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\u88C5\
    \u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/dp/bin-packing.hpp\"\n\n/**\n * @file bin-packing.hpp\n\
    \ * @brief \u74F6\u8A70\u3081\u554F\u984C (\u30D3\u30F3\u30D1\u30C3\u30AD\u30F3\
    \u30B0) \u306E\u6700\u5C0F\u306E\u74F6\u306E\u6570 (\u54C1\u7269\u304C 20 \u500B\
    \u7A0B\u5EA6\u307E\u3067)\n */\n\n#include <utility>\n#include <vector>\n\n/**\n\
    \ * @brief \u5BB9\u91CF C \u306E\u74F6\u306B\u91CD\u3055 w_i \u306E\u54C1\u7269\
    \u3092\u3059\u3079\u3066\u8A70\u3081\u308B\u306E\u306B\u5FC5\u8981\u306A\u74F6\
    \u306E\u6700\u5C0F\u500B\u6570 (\u5165\u3089\u306A\u3044\u54C1\u7269\u304C\u3042\
    \u308C\u3070 -1) O(2^n n)\n * \u54C1\u7269\u3092 1 \u3064\u305A\u3064\u5165\u308C\
    \u308B\u9806\u756A\u3092\u3059\u3079\u3066\u8A66\u3057\u3001\u300C\u6700\u5F8C\
    \u306E\u74F6\u306B\u5165\u308B\u306A\u3089\u5165\u308C\u3001\u5165\u3089\u306A\
    \u3051\u308C\u3070\u65B0\u3057\u3044\u74F6\u3092\u958B\u3051\u308B\u300D\u3068\
    \u3059\u308B\n * \u6700\u9069\u306A\u8A70\u3081\u65B9\u3082\u74F6\u3054\u3068\u306B\
    \u9806\u306B\u5165\u308C\u308C\u3070\u518D\u73FE\u3067\u304D\u308B\u306E\u3067\
    \u3001\u54C1\u7269\u306E\u96C6\u5408\u3054\u3068\u306B (\u74F6\u306E\u6570, \u6700\
    \u5F8C\u306E\u74F6\u306E\u91CD\u3055) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\u3092\
    \u6301\u3066\u3070\u3088\u3044\n */\ninline long long bin_packing(const std::vector<long\
    \ long>& w, long long C) {\n    const int n = w.size();\n    for (long long x\
    \ : w)\n        if (x > C) return -1;\n    // dp[S] = \u96C6\u5408 S \u3092\u8A70\
    \u3081\u305F\u3068\u304D\u306E (\u74F6\u306E\u6570, \u6700\u5F8C\u306E\u74F6\u306B\
    \u5165\u3063\u3066\u3044\u308B\u91CD\u3055) \u306E\u8F9E\u66F8\u9806\u6700\u5C0F\
    \u3002\u6700\u521D\u306F\u6700\u5F8C\u306E\u74F6\u304C\u6E80\u676F\u3068\u307F\
    \u306A\u3059\n    std::vector<std::pair<int, long long>> dp(1 << n, {n + 1, 0});\n\
    \    dp[0] = {0, C};\n    for (int S = 0; S < (1 << n); S++) {\n        auto [bins,\
    \ fill] = dp[S];\n        if (bins > n) continue;\n        for (int i = 0; i <\
    \ n; i++) {\n            if (S >> i & 1) continue;\n            std::pair<int,\
    \ long long> next = fill + w[i] <= C ? std::make_pair(bins, fill + w[i]) : std::make_pair(bins\
    \ + 1, w[i]);\n            if (next < dp[S | 1 << i]) dp[S | 1 << i] = next;\n\
    \        }\n    }\n    return dp[(1 << n) - 1].first;\n}\n#line 7 \"test/unittest/dp/bin-packing.test.cpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#line 12 \"\
    test/unittest/dp/bin-packing.test.cpp\"\n\nint main() {\n    std::mt19937_64 rng(314);\n\
    \    bool ok = true;\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n     \
    \   int n = rng() % 8;\n        long long C = rng() % 15 + 1;\n        std::vector<long\
    \ long> w(n);\n        for (auto& x : w) x = rng() % (C + 2) + 1;  // C \u3092\
    \u8D85\u3048\u308B\u54C1\u7269\u3082\u305F\u307E\u306B\u4F5C\u308B\n        long\
    \ long expect = -1;\n        if (std::all_of(w.begin(), w.end(), [&](long long\
    \ x) { return x <= C; })) {\n            // \u54C1\u7269 i \u3092\u74F6 b[i] (<\
    \ n) \u306B\u5165\u308C\u308B\u5272\u308A\u5F53\u3066\u3092\u3059\u3079\u3066\u8A66\
    \u3059\n            expect = n;\n            std::vector<int> b(n, 0);\n     \
    \       while (true) {\n                std::vector<long long> load(n, 0);\n \
    \               for (int i = 0; i < n; i++) load[b[i]] += w[i];\n            \
    \    if (std::all_of(load.begin(), load.end(), [&](long long x) { return x <=\
    \ C; }))\n                    expect = std::min<long long>(expect, std::count_if(load.begin(),\
    \ load.end(), [](long long x) { return x > 0; }));\n                int i = 0;\n\
    \                while (i < n && ++b[i] == n) b[i++] = 0;\n                if\
    \ (i == n) break;\n            }\n        }\n        if (bin_packing(w, C) !=\
    \ expect) ok = false, std::cerr << \"bin_packing\" << std::endl;\n    }\n    if\
    \ (bin_packing({}, 5) != 0) ok = false;\n    // \u540C\u3058\u74F6\u306E\u6570\
    \u306A\u3089\u6700\u5F8C\u306E\u74F6\u304C\u8EFD\u3044\u65B9\u3092\u6B8B\u3055\
    \u306A\u3044\u3068\u8AA4\u308B\u4F8B (\u30E9\u30F3\u30C0\u30E0\u3067\u306F\u51FA\
    \u306B\u304F\u3044\u306E\u3067\u6C7A\u3081\u6253\u3061\u3067\u78BA\u304B\u3081\
    \u308B)\n    if (bin_packing({3, 4, 4, 4, 2, 9, 2}, 10) != 3) ok = false, std::cerr\
    \ << \"bin_packing \u91CD\u3055\u306E\u6BD4\u8F03\" << std::endl;\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// bin_packing \u3092\u3001\u54C1\u7269\u3092\u3069\u306E\u74F6\u306B\u5165\
    \u308C\u308B\u304B\u3092\u3059\u3079\u3066\u8A66\u3059\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../../src/dp/bin-packing.hpp\"\n\n#include\
    \ <algorithm>\n#include <iostream>\n#include <random>\n#include <vector>\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int rep\
    \ = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 8;\n        long long\
    \ C = rng() % 15 + 1;\n        std::vector<long long> w(n);\n        for (auto&\
    \ x : w) x = rng() % (C + 2) + 1;  // C \u3092\u8D85\u3048\u308B\u54C1\u7269\u3082\
    \u305F\u307E\u306B\u4F5C\u308B\n        long long expect = -1;\n        if (std::all_of(w.begin(),\
    \ w.end(), [&](long long x) { return x <= C; })) {\n            // \u54C1\u7269\
    \ i \u3092\u74F6 b[i] (< n) \u306B\u5165\u308C\u308B\u5272\u308A\u5F53\u3066\u3092\
    \u3059\u3079\u3066\u8A66\u3059\n            expect = n;\n            std::vector<int>\
    \ b(n, 0);\n            while (true) {\n                std::vector<long long>\
    \ load(n, 0);\n                for (int i = 0; i < n; i++) load[b[i]] += w[i];\n\
    \                if (std::all_of(load.begin(), load.end(), [&](long long x) {\
    \ return x <= C; }))\n                    expect = std::min<long long>(expect,\
    \ std::count_if(load.begin(), load.end(), [](long long x) { return x > 0; }));\n\
    \                int i = 0;\n                while (i < n && ++b[i] == n) b[i++]\
    \ = 0;\n                if (i == n) break;\n            }\n        }\n       \
    \ if (bin_packing(w, C) != expect) ok = false, std::cerr << \"bin_packing\" <<\
    \ std::endl;\n    }\n    if (bin_packing({}, 5) != 0) ok = false;\n    // \u540C\
    \u3058\u74F6\u306E\u6570\u306A\u3089\u6700\u5F8C\u306E\u74F6\u304C\u8EFD\u3044\
    \u65B9\u3092\u6B8B\u3055\u306A\u3044\u3068\u8AA4\u308B\u4F8B (\u30E9\u30F3\u30C0\
    \u30E0\u3067\u306F\u51FA\u306B\u304F\u3044\u306E\u3067\u6C7A\u3081\u6253\u3061\
    \u3067\u78BA\u304B\u3081\u308B)\n    if (bin_packing({3, 4, 4, 4, 2, 9, 2}, 10)\
    \ != 3) ok = false, std::cerr << \"bin_packing \u91CD\u3055\u306E\u6BD4\u8F03\"\
    \ << std::endl;\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/dp/bin-packing.hpp
  isVerificationFile: true
  path: test/unittest/dp/bin-packing.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/dp/bin-packing.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/dp/bin-packing.test.cpp
- /verify/test/unittest/dp/bin-packing.test.cpp.html
title: test/unittest/dp/bin-packing.test.cpp
---
