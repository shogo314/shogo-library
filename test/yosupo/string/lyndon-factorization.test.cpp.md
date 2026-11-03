---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/lyndon.hpp
    title: "Lyndon \u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lyndon_factorization
    links:
    - https://judge.yosupo.jp/problem/lyndon_factorization
  bundledCode: "#line 1 \"test/yosupo/string/lyndon-factorization.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n\n#include\
    \ <iostream>\n#include <string>\n\n#line 2 \"src/string/lyndon.hpp\"\n\n/**\n\
    \ * @file lyndon.hpp\n * @brief Lyndon \u5206\u89E3\n */\n\n#include <iterator>\n\
    #include <vector>\n\n/**\n * @brief Lyndon \u5206\u89E3 (Duval \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0) O(N)\n * s \u3092 s = w_1 w_2 ... w_k (\u5404 w_i \u306F\
    \ Lyndon \u6587\u5B57\u5217\u3067\u3001w_1 >= w_2 >= ... >= w_k) \u306B\u5206\u3051\
    \u308B\n * Lyndon \u6587\u5B57\u5217\u306F\u3001\u81EA\u5206\u306E\u3069\u306E\
    \u771F\u306E\u63A5\u5C3E\u8F9E\u3088\u308A\u3082\u8F9E\u66F8\u9806\u3067\u771F\
    \u306B\u5C0F\u3055\u3044\u6587\u5B57\u5217\n *\n * @tparam It \u914D\u5217\u306E\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> \u533A\u5207\u308A\
    \u306E\u4F4D\u7F6E 0 = a_0 < a_1 < ... < a_k = N (w_i = s[a_{i-1}, a_i))\n */\n\
    template <typename It>\nstd::vector<long long> lyndon_factorization(It begin,\
    \ It end) {\n    const long long n = end - begin;\n    std::vector<long long>\
    \ res = {0};\n    long long i = 0;\n    while (i < n) {\n        // s[i, j) \u306F\
    \u3001\u9577\u3055 j - k \u306E Lyndon \u6587\u5B57\u5217\u3092\u4F55\u56DE\u304B\
    \u7E70\u308A\u8FD4\u3057\u305F\u3082\u306E\u3068\u3001\u305D\u306E\u63A5\u982D\
    \u8F9E\u3092\u3064\u306A\u3044\u3060\u3082\u306E\n        long long j = i + 1,\
    \ k = i;\n        while (j < n && !(begin[j] < begin[k])) {\n            k = begin[k]\
    \ < begin[j] ? i : k + 1;\n            j++;\n        }\n        while (i <= k)\
    \ {\n            i += j - k;\n            res.push_back(i);\n        }\n    }\n\
    \    return res;\n}\n\n/**\n * @brief Lyndon \u5206\u89E3 (Duval \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0) O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n *\
    \ @param s \u914D\u5217\n * @return std::vector<long long> \u533A\u5207\u308A\u306E\
    \u4F4D\u7F6E 0 = a_0 < a_1 < ... < a_k = N\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> lyndon_factorization(const R& s) {\n    return lyndon_factorization(std::begin(s),\
    \ std::end(s));\n}\n#line 7 \"test/yosupo/string/lyndon-factorization.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string s;\n    std::cin >> s;\n    auto a = lyndon_factorization(s);\n\
    \    for (int i = 0; i < static_cast<int>(a.size()); i++) std::cout << a[i] <<\
    \ \" \\n\"[i + 1 == static_cast<int>(a.size())];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n\
    \n#include <iostream>\n#include <string>\n\n#include \"../../../src/string/lyndon.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string s;\n    std::cin >> s;\n    auto a = lyndon_factorization(s);\n\
    \    for (int i = 0; i < static_cast<int>(a.size()); i++) std::cout << a[i] <<\
    \ \" \\n\"[i + 1 == static_cast<int>(a.size())];\n}\n"
  dependsOn:
  - src/string/lyndon.hpp
  isVerificationFile: true
  path: test/yosupo/string/lyndon-factorization.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/string/lyndon-factorization.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/string/lyndon-factorization.test.cpp
- /verify/test/yosupo/string/lyndon-factorization.test.cpp.html
title: test/yosupo/string/lyndon-factorization.test.cpp
---
