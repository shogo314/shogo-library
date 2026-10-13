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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/yosupo/enumerate-quotients.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#include <iostream>\n\
    #include <vector>\n\n#line 2 \"src/math/quotients.hpp\"\n\n/**\n * @file quotients.hpp\n\
    \ * @brief \u5546\u306E\u5217\u6319 (floor(n / i) \u304C\u540C\u3058\u5024\u306B\
    \u306A\u308B i \u306E\u533A\u9593)\n */\n\n#include <cassert>\n#line 10 \"src/math/quotients.hpp\"\
    \n\n/**\n * @brief \u5546 q = floor(n / i) \u3068\u3001\u305D\u308C\u3092\u3068\
    \u308B i \u306E\u533A\u9593 [l, r]\n */\nstruct QuotientRange {\n    long long\
    \ q;  //!< \u5546\n    long long l;  //!< \u533A\u9593\u306E\u5DE6\u7AEF (\u542B\
    \u3080)\n    long long r;  //!< \u533A\u9593\u306E\u53F3\u7AEF (\u542B\u3080)\n\
    };\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\u533A\
    \u9593\u306B\u5206\u3051\u3001i \u306E\u6607\u9806 (\u5546\u306E\u964D\u9806)\
    \ \u306B f(q, l, r) \u3092\u547C\u3076 O(sqrt(n))\n * l <= i <= r \u306A\u3089\
    \ floor(n / i) == q\n */\ntemplate <typename F>\nvoid for_each_quotient(long long\
    \ n, F f) {\n    assert(n >= 0);\n    for (long long l = 1; l <= n;) {\n     \
    \   long long q = n / l, r = n / q;\n        f(q, l, r);\n        l = r + 1;\n\
    \    }\n}\n\n/**\n * @brief i = 1, ..., n \u3092 floor(n / i) \u306E\u5024\u3067\
    \u533A\u9593\u306B\u5206\u3051\u305F\u3082\u306E (i \u306E\u6607\u9806\u3001\u3064\
    \u307E\u308A\u5546\u306E\u964D\u9806) O(sqrt(n))\n * \u533A\u9593\u306E\u500B\u6570\
    \u306F 2 sqrt(n) \u4EE5\u4E0B\n */\ninline std::vector<QuotientRange> enumerate_quotients(long\
    \ long n) {\n    std::vector<QuotientRange> res;\n    for_each_quotient(n, [&](long\
    \ long q, long long l, long long r) { res.push_back({q, l, r}); });\n    return\
    \ res;\n}\n#line 7 \"test/yosupo/enumerate-quotients.2.test.cpp\"\n\nint main()\
    \ {\n    long long n;\n    std::cin >> n;\n    auto qs = enumerate_quotients(n);\n\
    \    // \u5546\u306E\u6607\u9806\u306B\u51FA\u529B\u3059\u308B\n    std::cout\
    \ << qs.size() << '\\n';\n    for (int i = (int)qs.size() - 1; i >= 0; i--) std::cout\
    \ << qs[i].q << \" \\n\"[i == 0];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include <iostream>\n#include <vector>\n\n#include \"../../src/math/quotients.hpp\"\
    \n\nint main() {\n    long long n;\n    std::cin >> n;\n    auto qs = enumerate_quotients(n);\n\
    \    // \u5546\u306E\u6607\u9806\u306B\u51FA\u529B\u3059\u308B\n    std::cout\
    \ << qs.size() << '\\n';\n    for (int i = (int)qs.size() - 1; i >= 0; i--) std::cout\
    \ << qs[i].q << \" \\n\"[i == 0];\n}\n"
  dependsOn:
  - src/math/quotients.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate-quotients.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 03:19:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate-quotients.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate-quotients.2.test.cpp
- /verify/test/yosupo/enumerate-quotients.2.test.cpp.html
title: test/yosupo/enumerate-quotients.2.test.cpp
---
