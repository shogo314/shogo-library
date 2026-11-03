---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/kmp.hpp
    title: "KMP \u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/alds1/alds1-14-b.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #include <iostream>\n#include <string>\n\n#line 2 \"src/string/kmp.hpp\"\n\n/**\n\
    \ * @file kmp.hpp\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570\u3068 KMP \u6CD5\n\
    \ */\n\n#include <iterator>\n#include <vector>\n\n/**\n * @brief \u63A5\u982D\u8F9E\
    \u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\
    \u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\
    \u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\u9577\
    \u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067\
    \ O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n *\
    \ @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n\
    \ * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n\
    \ * @return std::vector<long long> pi\n */\ntemplate <typename It>\nstd::vector<long\
    \ long> prefix_function(It begin, It end) {\n    long long n = end - begin;\n\
    \    std::vector<long long> pi(n);\n    for (long long i = 1; i < n; i++) {\n\
    \        long long j = pi[i - 1];\n        while (j > 0 && !(begin[i] == begin[j]))\
    \ j = pi[j - 1];\n        if (begin[i] == begin[j]) j++;\n        pi[i] = j;\n\
    \    }\n    return pi;\n}\n\n/**\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570 (KMP\
    \ \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\
    \u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\
    \u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\
    \u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam R\
    \ \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long\
    \ long> pi\n */\ntemplate <typename R>\nstd::vector<long long> prefix_function(const\
    \ R& s) {\n    return prefix_function(std::begin(s), std::end(s));\n}\n\n/**\n\
    \ * @brief KMP \u6CD5\u3067 text \u306E\u4E2D\u306E pattern \u306E\u51FA\u73FE\
    \u4F4D\u7F6E (\u958B\u59CB\u4F4D\u7F6E) \u3092\u3059\u3079\u3066\u6607\u9806\u306B\
    \u6C42\u3081\u308B O(N + M)\n * pattern \u304C\u7A7A\u306A\u3089 0, 1, ..., N\
    \ \u3092\u8FD4\u3059\n *\n * @tparam R1 \u914D\u5217\u306E\u578B\n * @tparam R2\
    \ \u914D\u5217\u306E\u578B\n * @param text \u63A2\u3059\u5BFE\u8C61\n * @param\
    \ pattern \u63A2\u3059\u5217\n * @return std::vector<long long> \u51FA\u73FE\u4F4D\
    \u7F6E\n */\ntemplate <typename R1, typename R2>\nstd::vector<long long> kmp_search(const\
    \ R1& text, const R2& pattern) {\n    auto t = std::begin(text);\n    auto p =\
    \ std::begin(pattern);\n    long long n = std::end(text) - t, m = std::end(pattern)\
    \ - p;\n    std::vector<long long> res;\n    if (m == 0) {\n        for (long\
    \ long i = 0; i <= n; i++) res.push_back(i);\n        return res;\n    }\n   \
    \ std::vector<long long> pi = prefix_function(pattern);\n    for (long long i\
    \ = 0, j = 0; i < n; i++) {\n        // pattern[0, j) \u3068 text[i - j, i) \u304C\
    \u4E00\u81F4\u3057\u3066\u3044\u308B\n        while (j > 0 && !(t[i] == p[j]))\
    \ j = pi[j - 1];\n        if (t[i] == p[j]) j++;\n        if (j == m) {\n    \
    \        res.push_back(i - m + 1);\n            j = pi[j - 1];\n        }\n  \
    \  }\n    return res;\n}\n#line 7 \"test/aoj/alds1/alds1-14-b.2.test.cpp\"\n\n\
    int main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string t, p;\n    std::cin >> t >> p;\n    for (long long i : kmp_search(t,\
    \ p)) std::cout << i << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../../../src/string/kmp.hpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    std::string t, p;\n    std::cin >> t >> p;\n    for (long long i : kmp_search(t,\
    \ p)) std::cout << i << '\\n';\n}\n"
  dependsOn:
  - src/string/kmp.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1-14-b.2.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1-14-b.2.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1-14-b.2.test.cpp
- /verify/test/aoj/alds1/alds1-14-b.2.test.cpp.html
title: test/aoj/alds1/alds1-14-b.2.test.cpp
---
