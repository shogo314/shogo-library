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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/string/lyndon.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ lyndon_factorization \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/string/lyndon.hpp\"\n\n/**\n\
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
    \ std::end(s));\n}\n#line 7 \"test/unittest/string/lyndon.test.cpp\"\n\n#include\
    \ <iostream>\n#include <random>\n#include <string>\n#line 12 \"test/unittest/string/lyndon.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\n    // \u6700\
    \u9577\u306E Lyndon \u6587\u5B57\u5217\u3067\u3042\u308B\u63A5\u982D\u8F9E\u3092\
    \u7E70\u308A\u8FD4\u3057\u5207\u308A\u51FA\u3057\u305F\u3082\u306E (Lyndon \u5206\
    \u89E3\u306E\u6700\u521D\u306E\u6210\u5206\u306F\u3053\u308C\u306B\u306A\u308B\
    ) \u3068\u6BD4\u3079\u308B\n    auto is_lyndon = [](const std::string& w) {\n\
    \        for (size_t i = 1; i < w.size(); i++)\n            if (!(w < w.substr(i)))\
    \ return false;\n        return !w.empty();\n    };\n    for (int rep = 0; rep\
    \ < 3000 && ok; rep++) {\n        int n = rng() % 13;\n        std::string s;\n\
    \        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() % 3);\n\
    \        std::vector<long long> expect = {0};\n        for (int i = 0; i < n;)\
    \ {\n            int len = 1;\n            for (int l = 1; i + l <= n; l++)\n\
    \                if (is_lyndon(s.substr(i, l))) len = l;\n            i += len;\n\
    \            expect.push_back(i);\n        }\n        ok = ok && lyndon_factorization(s)\
    \ == expect;\n        std::vector<int> v(s.begin(), s.end());\n        ok = ok\
    \ && lyndon_factorization(v) == expect;\n    }\n\n    // \u4F8B\n    ok = ok &&\
    \ lyndon_factorization(std::string(\"abracadabra\")) == std::vector<long long>{0,\
    \ 7, 10, 11};\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// lyndon_factorization \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\
    \u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello\
    \ World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/lyndon.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <string>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\n    // \u6700\
    \u9577\u306E Lyndon \u6587\u5B57\u5217\u3067\u3042\u308B\u63A5\u982D\u8F9E\u3092\
    \u7E70\u308A\u8FD4\u3057\u5207\u308A\u51FA\u3057\u305F\u3082\u306E (Lyndon \u5206\
    \u89E3\u306E\u6700\u521D\u306E\u6210\u5206\u306F\u3053\u308C\u306B\u306A\u308B\
    ) \u3068\u6BD4\u3079\u308B\n    auto is_lyndon = [](const std::string& w) {\n\
    \        for (size_t i = 1; i < w.size(); i++)\n            if (!(w < w.substr(i)))\
    \ return false;\n        return !w.empty();\n    };\n    for (int rep = 0; rep\
    \ < 3000 && ok; rep++) {\n        int n = rng() % 13;\n        std::string s;\n\
    \        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() % 3);\n\
    \        std::vector<long long> expect = {0};\n        for (int i = 0; i < n;)\
    \ {\n            int len = 1;\n            for (int l = 1; i + l <= n; l++)\n\
    \                if (is_lyndon(s.substr(i, l))) len = l;\n            i += len;\n\
    \            expect.push_back(i);\n        }\n        ok = ok && lyndon_factorization(s)\
    \ == expect;\n        std::vector<int> v(s.begin(), s.end());\n        ok = ok\
    \ && lyndon_factorization(v) == expect;\n    }\n\n    // \u4F8B\n    ok = ok &&\
    \ lyndon_factorization(std::string(\"abracadabra\")) == std::vector<long long>{0,\
    \ 7, 10, 11};\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/lyndon.hpp
  isVerificationFile: true
  path: test/unittest/string/lyndon.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/lyndon.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/lyndon.test.cpp
- /verify/test/unittest/string/lyndon.test.cpp.html
title: test/unittest/string/lyndon.test.cpp
---
