---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/sqrt.hpp
    title: "\u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/yosupo/number_theory/kth-root-integer.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#include\
    \ <iostream>\n\n#line 2 \"src/math/sqrt.hpp\"\n\n/**\n * @file sqrt.hpp\n * @brief\
    \ \u6574\u6570\u306E\u5E73\u65B9\u6839\u30FBk \u4E57\u6839\n */\n\n#include <cassert>\n\
    #include <cmath>\n\n/**\n * @brief floor(sqrt(n))\n * @param n \u5E73\u65B9\u6839\
    \u3092\u6C42\u3081\u305F\u3044\u6574\u6570 long long \u578B\u3067 0 <= n < 2^63\
    \ \u3092\u6E80\u305F\u3059\n * @return long long\n */\ninline long long sqrtll(long\
    \ long n) {\n    assert(n >= 0);\n    // 3037000500 = ceil(sqrt(2^63))\n    long\
    \ long le = 0, ri = 3037000500;\n    while (ri - le > 1) {\n        long long\
    \ mid = (le + ri) / 2;\n        if (mid * mid <= n)\n            le = mid;\n \
    \       else\n            ri = mid;\n    }\n    return le;\n}\n\n/**\n * @brief\
    \ floor(a^(1/k))\n *\n * \u6D6E\u52D5\u5C0F\u6570\u70B9\u3067\u8FD1\u3044\u5024\
    \u3092\u6C42\u3081\u3001\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\u3088\u3046\u306B\u639B\u3051\u7B97\u3067\u78BA\u304B\u3081\u3066\u5408\
    \u308F\u305B\u308B\n * @param a 0 <= a < 2^64\n * @param k 1 \u4EE5\u4E0A\n *\
    \ @return unsigned long long\n */\ninline unsigned long long kth_root(unsigned\
    \ long long a, long long k) {\n    assert(k >= 1);\n    if (k == 1 || a <= 1)\
    \ return a;\n    if (k >= 64) return 1;  // a < 2^64 \u306A\u306E\u3067\n    //\
    \ x^k <= a \u304B\n    auto fits = [&](unsigned long long x) {\n        unsigned\
    \ long long p = 1;\n        for (long long i = 0; i < k; i++) {\n            if\
    \ (p > a / x) return false;\n            p *= x;\n        }\n        return true;\n\
    \    };\n    unsigned long long x = static_cast<unsigned long long>(std::pow(static_cast<long\
    \ double>(a), 1.0L / k));\n    if (x == 0) x = 1;\n    while (!fits(x)) x--;\n\
    \    while (fits(x + 1)) x++;\n    return x;\n}\n#line 6 \"test/yosupo/number_theory/kth-root-integer.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int t;\n    std::cin >> t;\n    while (t--) {\n        unsigned long long\
    \ a;\n        long long k;\n        std::cin >> a >> k;\n        std::cout <<\
    \ kth_root(a, k) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include <iostream>\n\n#include \"../../../src/math/sqrt.hpp\"\n\nint main() {\n\
    \    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int t;\n\
    \    std::cin >> t;\n    while (t--) {\n        unsigned long long a;\n      \
    \  long long k;\n        std::cin >> a >> k;\n        std::cout << kth_root(a,\
    \ k) << '\\n';\n    }\n}\n"
  dependsOn:
  - src/math/sqrt.hpp
  isVerificationFile: true
  path: test/yosupo/number_theory/kth-root-integer.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 04:30:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_theory/kth-root-integer.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_theory/kth-root-integer.test.cpp
- /verify/test/yosupo/number_theory/kth-root-integer.test.cpp.html
title: test/yosupo/number_theory/kth-root-integer.test.cpp
---
