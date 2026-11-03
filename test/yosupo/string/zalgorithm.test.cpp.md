---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/z-algorithm.hpp
    title: Z-algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/string/zalgorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <iostream>\n#include\
    \ <string>\n\n#line 2 \"src/string/z-algorithm.hpp\"\n\n/**\n * @file z-algorithm.hpp\n\
    \ * @brief Z-algorithm\n */\n\n#include <iterator>\n#include <vector>\n\n/**\n\
    \ * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404\
    i\u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam\
    \ It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\
    \u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\
    \u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long>\
    \ z\n */\ntemplate <typename It>\nstd::vector<long long> z_algorithm(It begin,\
    \ It end) {\n    long long n = end - begin;\n    if (n == 0) return {};\n    std::vector<long\
    \ long> z(n);\n    z[0] = n;\n    for (long long i = 1, j = 0; i < n;) {\n   \
    \     // [0, j)\u3068[i, i + j)\u304C\u4E00\u81F4\u3057\u3066\u3044\u308B\n  \
    \      while (i + j < n && begin[j] == begin[i + j]) j++;\n        z[i] = j;\n\
    \        long long k = 1;  // [k,)\u3068[i+k,)\u306FLCP\u304C\u7B49\u3057\u3044\
    \u3068\u78BA\u5B9A\u3057\u3066\u3044\u308B\n        for (; k < j && k + z[k] <\
    \ j; k++) {\n            z[i + k] = z[k];\n        }\n        i += k;\n      \
    \  if (j) j -= k;\n    }\n    return z;\n}\n\n/**\n * @brief Z-algorithm\n * s[0:]\u3068\
    s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404i\u306B\u3064\u3044\u3066\u6C42\u3081\
    \u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param\
    \ s \u914D\u5217\n * @return std::vector<long long> z\n */\ntemplate <typename\
    \ R>\nstd::vector<long long> z_algorithm(const R& s) {\n    return z_algorithm(std::begin(s),\
    \ std::end(s));\n}\n#line 7 \"test/yosupo/string/zalgorithm.test.cpp\"\n\nint\
    \ main(void) {\n    std::string s;\n    std::cin >> s;\n    std::vector<long long>\
    \ z = z_algorithm(s);\n    for (long long i = 0; i < static_cast<long long>(z.size());\
    \ i++) {\n        std::cout << z[i] << \" \\n\"[i + 1 == static_cast<long long>(z.size())];\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n\n#include \"../../../src/string/z-algorithm.hpp\"\
    \n\nint main(void) {\n    std::string s;\n    std::cin >> s;\n    std::vector<long\
    \ long> z = z_algorithm(s);\n    for (long long i = 0; i < static_cast<long long>(z.size());\
    \ i++) {\n        std::cout << z[i] << \" \\n\"[i + 1 == static_cast<long long>(z.size())];\n\
    \    }\n}\n"
  dependsOn:
  - src/string/z-algorithm.hpp
  isVerificationFile: true
  path: test/yosupo/string/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/string/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/string/zalgorithm.test.cpp
- /verify/test/yosupo/string/zalgorithm.test.cpp.html
title: test/yosupo/string/zalgorithm.test.cpp
---
