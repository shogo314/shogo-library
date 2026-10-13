---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/string.hpp
    title: "\u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001\
      KMP\u3001Manacher)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo/enumerate-palindromes.2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"src/string/string.hpp\"\
    \n\n/**\n * @file string.hpp\n * @brief \u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 (Z-algorithm\u3001KMP\u3001Manacher)\n */\n\n#include <algorithm>\n\
    #include <iterator>\n#line 11 \"src/string/string.hpp\"\n\n/**\n * @brief Z-algorithm\n\
    \ * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404i\u306B\u3064\u3044\
    \u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam It \u914D\u5217\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\
    \u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<int> z\n */\ntemplate <typename\
    \ It>\nstd::vector<int> z_algorithm(It begin, It end) {\n    int n = end - begin;\n\
    \    if (n == 0) return {};\n    std::vector<int> z(n);\n    z[0] = n;\n    for(int\
    \ i = 1, j = 0; i < n;) {\n        // [0, j)\u3068[i, i + j)\u304C\u4E00\u81F4\
    \u3057\u3066\u3044\u308B\n        while(i + j < n && begin[j] == begin[i + j])\
    \ j++;\n        z[i] = j;\n        int k = 1; // [k,)\u3068[i+k,)\u306FLCP\u304C\
    \u7B49\u3057\u3044\u3068\u78BA\u5B9A\u3057\u3066\u3044\u308B\n        for(; k\
    \ < j && k + z[k] < j; k++) {\n            z[i + k] = z[k];\n        }\n     \
    \   i += k;\n        if(j) j -= k;\n    }\n    return z;\n}\n\n/**\n * @brief\
    \ Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404i\u306B\
    \u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam R\
    \ \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<int>\
    \ z\n */\ntemplate <typename R>\nstd::vector<int> z_algorithm(const R& s) {\n\
    \    return z_algorithm(std::begin(s), std::end(s));\n}\n\n/**\n * @brief \u63A5\
    \u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i]\
    \ \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\
    \u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\
    \u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\
    \u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @return std::vector<int> pi\n */\ntemplate <typename It>\nstd::vector<int>\
    \ prefix_function(It begin, It end) {\n    int n = end - begin;\n    std::vector<int>\
    \ pi(n);\n    for (int i = 1; i < n; i++) {\n        int j = pi[i - 1];\n    \
    \    while (j > 0 && !(begin[i] == begin[j])) j = pi[j - 1];\n        if (begin[i]\
    \ == begin[j]) j++;\n        pi[i] = j;\n    }\n    return pi;\n}\n\n/**\n * @brief\
    \ \u63A5\u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n\
    \ * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\
    \u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\
    \u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\
    \u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n *\
    \ @param s \u914D\u5217\n * @return std::vector<int> pi\n */\ntemplate <typename\
    \ R>\nstd::vector<int> prefix_function(const R& s) {\n    return prefix_function(std::begin(s),\
    \ std::end(s));\n}\n\n/**\n * @brief KMP \u6CD5\u3067 text \u306E\u4E2D\u306E\
    \ pattern \u306E\u51FA\u73FE\u4F4D\u7F6E (\u958B\u59CB\u4F4D\u7F6E) \u3092\u3059\
    \u3079\u3066\u6607\u9806\u306B\u6C42\u3081\u308B O(N + M)\n * pattern \u304C\u7A7A\
    \u306A\u3089 0, 1, ..., N \u3092\u8FD4\u3059\n *\n * @tparam R1 \u914D\u5217\u306E\
    \u578B\n * @tparam R2 \u914D\u5217\u306E\u578B\n * @param text \u63A2\u3059\u5BFE\
    \u8C61\n * @param pattern \u63A2\u3059\u5217\n * @return std::vector<int> \u51FA\
    \u73FE\u4F4D\u7F6E\n */\ntemplate <typename R1, typename R2>\nstd::vector<int>\
    \ kmp_search(const R1& text, const R2& pattern) {\n    auto t = std::begin(text);\n\
    \    auto p = std::begin(pattern);\n    int n = std::end(text) - t, m = std::end(pattern)\
    \ - p;\n    std::vector<int> res;\n    if (m == 0) {\n        for (int i = 0;\
    \ i <= n; i++) res.push_back(i);\n        return res;\n    }\n    std::vector<int>\
    \ pi = prefix_function(pattern);\n    for (int i = 0, j = 0; i < n; i++) {\n \
    \       // pattern[0, j) \u3068 text[i - j, i) \u304C\u4E00\u81F4\u3057\u3066\u3044\
    \u308B\n        while (j > 0 && !(t[i] == p[j])) j = pi[j - 1];\n        if (t[i]\
    \ == p[j]) j++;\n        if (j == m) {\n            res.push_back(i - m + 1);\n\
    \            j = pi[j - 1];\n        }\n    }\n    return res;\n}\n\n/**\n * @brief\
    \ Manacher \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\
    \u306E\u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i\
    \ + r[i]) \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\
    \u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n * @return std::vector<int> r\n */\ntemplate <typename It>\nstd::vector<int>\
    \ manacher(It begin, It end) {\n    int n = end - begin;\n    std::vector<int>\
    \ r(n);\n    // [l, rr] \u306F\u3001\u3053\u308C\u307E\u3067\u306B\u898B\u3064\
    \u3051\u305F\u56DE\u6587\u306E\u3046\u3061\u53F3\u7AEF\u304C\u6700\u3082\u53F3\
    \u306B\u3042\u308B\u3082\u306E\n    for (int i = 0, l = 0, rr = -1; i < n; i++)\
    \ {\n        int k = i > rr ? 1 : std::min(r[l + rr - i], rr - i + 1);\n     \
    \   while (0 <= i - k && i + k < n && begin[i - k] == begin[i + k]) k++;\n   \
    \     r[i] = k--;\n        if (i + k > rr) {\n            l = i - k;\n       \
    \     rr = i + k;\n        }\n    }\n    return r;\n}\n\n/**\n * @brief Manacher\
    \ \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\
    \u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i])\
    \ \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B\
    \ \u5168\u4F53\u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param\
    \ s \u914D\u5217\n * @return std::vector<int> r\n */\ntemplate <typename R>\n\
    std::vector<int> manacher(const R& s) {\n    return manacher(std::begin(s), std::end(s));\n\
    }\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u6700\
    \u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067 O(N)\n * \u9577\u3055\
    \ 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002len[2i] \u306F s[i] \u3092\
    \u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i + 1] \u306F s[i] \u3068\
    \ s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u306E\u6700\
    \u9577\u306E\u9577\u3055\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @return std::vector<int> len\n */\ntemplate <typename It>\nstd::vector<int>\
    \ palindrome_lengths(It begin, It end) {\n    int n = end - begin;\n    if (n\
    \ == 0) return {};\n    std::vector<int> odd = manacher(begin, end);\n    // even[i]\
    \ \u306F s[i - 1] \u3068 s[i] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u5076\u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84\n   \
    \ std::vector<int> even(n);\n    for (int i = 0, l = 0, rr = -1; i < n; i++) {\n\
    \        int k = i > rr ? 0 : std::min(even[l + rr - i + 1], rr - i + 1);\n  \
    \      while (0 <= i - k - 1 && i + k < n && begin[i - k - 1] == begin[i + k])\
    \ k++;\n        even[i] = k--;\n        if (i + k > rr) {\n            l = i -\
    \ k - 1;\n            rr = i + k;\n        }\n    }\n    std::vector<int> len(2\
    \ * n - 1);\n    for (int i = 0; i < n; i++) len[2 * i] = 2 * odd[i] - 1;\n  \
    \  for (int i = 0; i + 1 < n; i++) len[2 * i + 1] = 2 * even[i + 1];\n    return\
    \ len;\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067 O(N)\n * \u9577\
    \u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002len[2i] \u306F s[i]\
    \ \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i + 1] \u306F s[i]\
    \ \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\
    \u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam R \u914D\u5217\u306E\u578B\
    \n * @param s \u914D\u5217\n * @return std::vector<int> len\n */\ntemplate <typename\
    \ R>\nstd::vector<int> palindrome_lengths(const R& s) {\n    return palindrome_lengths(std::begin(s),\
    \ std::end(s));\n}\n#line 8 \"test/yosupo/enumerate-palindromes.2.test.cpp\"\n\
    \nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s;\n    std::cin >> s;\n    std::vector<int> len = palindrome_lengths(s);\n\
    \    for (int i = 0; i < (int)len.size(); i++) std::cout << len[i] << \" \\n\"\
    [i + 1 == (int)len.size()];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../src/string/string.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s;\n    std::cin >> s;\n    std::vector<int> len = palindrome_lengths(s);\n\
    \    for (int i = 0; i < (int)len.size(); i++) std::cout << len[i] << \" \\n\"\
    [i + 1 == (int)len.size()];\n}\n"
  dependsOn:
  - src/string/string.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate-palindromes.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 00:42:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate-palindromes.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate-palindromes.2.test.cpp
- /verify/test/yosupo/enumerate-palindromes.2.test.cpp.html
title: test/yosupo/enumerate-palindromes.2.test.cpp
---
