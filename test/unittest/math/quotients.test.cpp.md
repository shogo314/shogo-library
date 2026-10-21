---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/quotients.hpp
    title: "\u5546\u306E\u5217\u6319"
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
  bundledCode: "#line 1 \"test/unittest/math/quotients.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ enumerate_quotients \u3068 for_each_quotient \u3092\u3001i \u3054\u3068\u306B\
    \u5546\u3092\u8A08\u7B97\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u6BD4\
    \u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\
    \u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\
    \u308B\n\n#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n\
    \ * @brief \u5546\u306E\u5217\u6319 (floor(n / i) \u304C\u540C\u3058\u5024\u306B\
    \u306A\u308B i \u306E\u533A\u9593)\n */\n\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief \u5546 q = floor(n / i) \u3068\u3001\u305D\u308C\u3092\u3068\u308B\
    \ i \u306E\u533A\u9593 [l, r]\n */\nstruct QuotientRange {\n    long long q; \
    \ //!< \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\u3080\
    )\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u3080)\n};\n\n\
    /**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\u9593\
    \u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806) \u306B\
    \ f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i <= r \u306A\u3089 floor(n\
    \ / i) == q\n */\ntemplate <typename F>\nvoid for_each_quotient(long long n, F\
    \ f) {\n    assert(n >= 0);\n    for (long long l = 1; l <= n;) {\n        long\
    \ long q = n / l, r = n / q;\n        f(q, l, r);\n        l = r + 1;\n    }\n\
    }\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\u6607\u9806\u3001\u3064\u307E\
    \u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\u9593\u306E\u500B\u6570\u306F\
    \ 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange> enumerate_quotients(long\
    \ long n) {\n    std::vector<QuotientRange> res;\n    for_each_quotient(n, [&](long\
    \ long q, long long l, long long r) { res.push_back({q, l, r}); });\n    return\
    \ res;\n}\n#line 7 \"test/unittest/math/quotients.test.cpp\"\n\n#include <iostream>\n\
    #line 10 \"test/unittest/math/quotients.test.cpp\"\n\nint main() {\n    bool ok\
    \ = true;\n    for (long long n = 0; n <= 3000 && ok; n++) {\n        auto qs\
    \ = enumerate_quotients(n);\n        // \u533A\u9593\u304C 1 \u304B\u3089 n \u307E\
    \u3067\u3092\u9699\u9593\u306A\u304F\u8986\u3044\u3001\u533A\u9593\u306E\u4E2D\
    \u3067\u5546\u304C q \u306B\u7B49\u3057\u304F\u3001\u96A3\u306E\u533A\u9593\u3068\
    \u306F\u5546\u304C\u7570\u306A\u308B\n        long long next = 1;\n        for\
    \ (int k = 0; k < static_cast<int>(qs.size()); k++) {\n            auto [q, l,\
    \ r] = qs[k];\n            if (l != next || l > r) ok = false;\n            if\
    \ (n / l != q || n / r != q) ok = false;\n            if (k > 0 && qs[k - 1].q\
    \ <= q) ok = false;\n            next = r + 1;\n        }\n        if (next !=\
    \ n + 1) ok = false;\n        // \u533A\u9593\u306E\u500B\u6570\u306F 2 sqrt(n)\
    \ \u4EE5\u4E0B\n        long long k = qs.size();\n        if (k * k > 4 * n) ok\
    \ = false;\n        // \u7D04\u6570\u306E\u500B\u6570\u306E\u548C sum_{k <= n}\
    \ d(k) = sum_{i <= n} floor(n / i)\n        long long expected = 0, sum = 0;\n\
    \        for (long long i = 1; i <= n; i++) expected += n / i;\n        for_each_quotient(n,\
    \ [&](long long q, long long l, long long r) { sum += q * (r - l + 1); });\n \
    \       ok = ok && sum == expected;\n    }\n\n    // \u4F8B\n    auto qs = enumerate_quotients(10);\n\
    \    std::vector<long long> q, l, r;\n    for (auto x : qs) q.push_back(x.q),\
    \ l.push_back(x.l), r.push_back(x.r);\n    ok = ok && q == std::vector<long long>{10,\
    \ 5, 3, 2, 1} && l == std::vector<long long>{1, 2, 3, 4, 6};\n    ok = ok && r\
    \ == std::vector<long long>{1, 2, 3, 5, 10};\n    // \u5927\u304D\u3044 n \u3067\
    \u3082\u533A\u9593\u306E\u500B\u6570\u306F 2 sqrt(n) \u7A0B\u5EA6\n    ok = ok\
    \ && enumerate_quotients(1000000000000LL).size() == 1999999;\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// enumerate_quotients \u3068 for_each_quotient \u3092\u3001i \u3054\u3068\
    \u306B\u5546\u3092\u8A08\u7B97\u3059\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u6BD4\u3079\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#include \"../../../src/math/quotients.hpp\"\n\n#include <iostream>\n\
    #include <vector>\n\nint main() {\n    bool ok = true;\n    for (long long n =\
    \ 0; n <= 3000 && ok; n++) {\n        auto qs = enumerate_quotients(n);\n    \
    \    // \u533A\u9593\u304C 1 \u304B\u3089 n \u307E\u3067\u3092\u9699\u9593\u306A\
    \u304F\u8986\u3044\u3001\u533A\u9593\u306E\u4E2D\u3067\u5546\u304C q \u306B\u7B49\
    \u3057\u304F\u3001\u96A3\u306E\u533A\u9593\u3068\u306F\u5546\u304C\u7570\u306A\
    \u308B\n        long long next = 1;\n        for (int k = 0; k < static_cast<int>(qs.size());\
    \ k++) {\n            auto [q, l, r] = qs[k];\n            if (l != next || l\
    \ > r) ok = false;\n            if (n / l != q || n / r != q) ok = false;\n  \
    \          if (k > 0 && qs[k - 1].q <= q) ok = false;\n            next = r +\
    \ 1;\n        }\n        if (next != n + 1) ok = false;\n        // \u533A\u9593\
    \u306E\u500B\u6570\u306F 2 sqrt(n) \u4EE5\u4E0B\n        long long k = qs.size();\n\
    \        if (k * k > 4 * n) ok = false;\n        // \u7D04\u6570\u306E\u500B\u6570\
    \u306E\u548C sum_{k <= n} d(k) = sum_{i <= n} floor(n / i)\n        long long\
    \ expected = 0, sum = 0;\n        for (long long i = 1; i <= n; i++) expected\
    \ += n / i;\n        for_each_quotient(n, [&](long long q, long long l, long long\
    \ r) { sum += q * (r - l + 1); });\n        ok = ok && sum == expected;\n    }\n\
    \n    // \u4F8B\n    auto qs = enumerate_quotients(10);\n    std::vector<long\
    \ long> q, l, r;\n    for (auto x : qs) q.push_back(x.q), l.push_back(x.l), r.push_back(x.r);\n\
    \    ok = ok && q == std::vector<long long>{10, 5, 3, 2, 1} && l == std::vector<long\
    \ long>{1, 2, 3, 4, 6};\n    ok = ok && r == std::vector<long long>{1, 2, 3, 5,\
    \ 10};\n    // \u5927\u304D\u3044 n \u3067\u3082\u533A\u9593\u306E\u500B\u6570\
    \u306F 2 sqrt(n) \u7A0B\u5EA6\n    ok = ok && enumerate_quotients(1000000000000LL).size()\
    \ == 1999999;\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/math/quotients.hpp
  isVerificationFile: true
  path: test/unittest/math/quotients.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:32:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/math/quotients.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/math/quotients.test.cpp
- /verify/test/unittest/math/quotients.test.cpp.html
title: test/unittest/math/quotients.test.cpp
---
