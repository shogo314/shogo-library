---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1/alds1-14-b.2.test.cpp
    title: test/aoj/alds1/alds1-14-b.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/string.test.cpp
    title: test/unittest/string/string.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/enumerate-palindromes.2.test.cpp
    title: test/yosupo/string/enumerate-palindromes.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/zalgorithm.test.cpp
    title: test/yosupo/string/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001\
      KMP\u3001Manacher)"
    links: []
  bundledCode: "#line 2 \"src/string/string.hpp\"\n\n/**\n * @file string.hpp\n *\
    \ @brief \u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001\
    KMP\u3001Manacher)\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <iterator>\n#include <vector>\n\n/**\n * @brief Z-algorithm\n * s[0:]\u3068\
    s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404i\u306B\u3064\u3044\u3066\u6C42\u3081\
    \u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\
    \u30FC\u30BF\n * @return std::vector<long long> z\n */\ntemplate <typename It>\n\
    std::vector<long long> z_algorithm(It begin, It end) {\n    long long n = end\
    \ - begin;\n    if (n == 0) return {};\n    std::vector<long long> z(n);\n   \
    \ z[0] = n;\n    for (long long i = 1, j = 0; i < n;) {\n        // [0, j)\u3068\
    [i, i + j)\u304C\u4E00\u81F4\u3057\u3066\u3044\u308B\n        while (i + j < n\
    \ && begin[j] == begin[i + j]) j++;\n        z[i] = j;\n        long long k =\
    \ 1;  // [k,)\u3068[i+k,)\u306FLCP\u304C\u7B49\u3057\u3044\u3068\u78BA\u5B9A\u3057\
    \u3066\u3044\u308B\n        for (; k < j && k + z[k] < j; k++) {\n           \
    \ z[i + k] = z[k];\n        }\n        i += k;\n        if (j) j -= k;\n    }\n\
    \    return z;\n}\n\n/**\n * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\
    \u9577\u3055\u3092\u5404i\u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\
    \u3067O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\
    \n * @return std::vector<long long> z\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> z_algorithm(const R& s) {\n    return z_algorithm(std::begin(s), std::end(s));\n\
    }\n\n/**\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\
    \u95A2\u6570)\n * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\
    \u8F9E\u3067\u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F\
    ) \u306E\u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\
    \u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @return std::vector<long long> pi\n */\ntemplate <typename\
    \ It>\nstd::vector<long long> prefix_function(It begin, It end) {\n    long long\
    \ n = end - begin;\n    std::vector<long long> pi(n);\n    for (long long i =\
    \ 1; i < n; i++) {\n        long long j = pi[i - 1];\n        while (j > 0 &&\
    \ !(begin[i] == begin[j])) j = pi[j - 1];\n        if (begin[i] == begin[j]) j++;\n\
    \        pi[i] = j;\n    }\n    return pi;\n}\n\n/**\n * @brief \u63A5\u982D\u8F9E\
    \u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\
    \u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\
    \u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\u9577\
    \u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067\
    \ O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n\
    \ * @return std::vector<long long> pi\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> prefix_function(const R& s) {\n    return prefix_function(std::begin(s),\
    \ std::end(s));\n}\n\n/**\n * @brief KMP \u6CD5\u3067 text \u306E\u4E2D\u306E\
    \ pattern \u306E\u51FA\u73FE\u4F4D\u7F6E (\u958B\u59CB\u4F4D\u7F6E) \u3092\u3059\
    \u3079\u3066\u6607\u9806\u306B\u6C42\u3081\u308B O(N + M)\n * pattern \u304C\u7A7A\
    \u306A\u3089 0, 1, ..., N \u3092\u8FD4\u3059\n *\n * @tparam R1 \u914D\u5217\u306E\
    \u578B\n * @tparam R2 \u914D\u5217\u306E\u578B\n * @param text \u63A2\u3059\u5BFE\
    \u8C61\n * @param pattern \u63A2\u3059\u5217\n * @return std::vector<long long>\
    \ \u51FA\u73FE\u4F4D\u7F6E\n */\ntemplate <typename R1, typename R2>\nstd::vector<long\
    \ long> kmp_search(const R1& text, const R2& pattern) {\n    auto t = std::begin(text);\n\
    \    auto p = std::begin(pattern);\n    long long n = std::end(text) - t, m =\
    \ std::end(pattern) - p;\n    std::vector<long long> res;\n    if (m == 0) {\n\
    \        for (long long i = 0; i <= n; i++) res.push_back(i);\n        return\
    \ res;\n    }\n    std::vector<long long> pi = prefix_function(pattern);\n   \
    \ for (long long i = 0, j = 0; i < n; i++) {\n        // pattern[0, j) \u3068\
    \ text[i - j, i) \u304C\u4E00\u81F4\u3057\u3066\u3044\u308B\n        while (j\
    \ > 0 && !(t[i] == p[j])) j = pi[j - 1];\n        if (t[i] == p[j]) j++;\n   \
    \     if (j == m) {\n            res.push_back(i - m + 1);\n            j = pi[j\
    \ - 1];\n        }\n    }\n    return res;\n}\n\n/**\n * @brief Manacher \u6CD5\
    \n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u56DE\u6587\
    \u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i]) \u304C\u56DE\
    \u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\
    \u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n\
    \ * @return std::vector<long long> r\n */\ntemplate <typename It>\nstd::vector<long\
    \ long> manacher(It begin, It end) {\n    long long n = end - begin;\n    std::vector<long\
    \ long> r(n);\n    // [l, rr] \u306F\u3001\u3053\u308C\u307E\u3067\u306B\u898B\
    \u3064\u3051\u305F\u56DE\u6587\u306E\u3046\u3061\u53F3\u7AEF\u304C\u6700\u3082\
    \u53F3\u306B\u3042\u308B\u3082\u306E\n    for (long long i = 0, l = 0, rr = -1;\
    \ i < n; i++) {\n        long long k = i > rr ? 1 : std::min(r[l + rr - i], rr\
    \ - i + 1);\n        while (0 <= i - k && i + k < n && begin[i - k] == begin[i\
    \ + k]) k++;\n        r[i] = k--;\n        if (i + k > rr) {\n            l =\
    \ i - k;\n            rr = i + k;\n        }\n    }\n    return r;\n}\n\n/**\n\
    \ * @brief Manacher \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\
    \u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i -\
    \ r[i] + 1, i + r[i]) \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\
    \u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\
    \u578B\n * @param s \u914D\u5217\n * @return std::vector<long long> r\n */\ntemplate\
    \ <typename R>\nstd::vector<long long> manacher(const R& s) {\n    return manacher(std::begin(s),\
    \ std::end(s));\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam It \u914D\u5217\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\
    \u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> len\n */\ntemplate\
    \ <typename It>\nstd::vector<long long> palindrome_lengths(It begin, It end) {\n\
    \    long long n = end - begin;\n    if (n == 0) return {};\n    std::vector<long\
    \ long> odd = manacher(begin, end);\n    // even[i] \u306F s[i - 1] \u3068 s[i]\
    \ \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u56DE\
    \u6587\u306E\u6700\u5927\u306E\u534A\u5F84\n    std::vector<long long> even(n);\n\
    \    for (long long i = 0, l = 0, rr = -1; i < n; i++) {\n        long long k\
    \ = i > rr ? 0 : std::min(even[l + rr - i + 1], rr - i + 1);\n        while (0\
    \ <= i - k - 1 && i + k < n && begin[i - k - 1] == begin[i + k]) k++;\n      \
    \  even[i] = k--;\n        if (i + k > rr) {\n            l = i - k - 1;\n   \
    \         rr = i + k;\n        }\n    }\n    std::vector<long long> len(2 * n\
    \ - 1);\n    for (long long i = 0; i < n; i++) len[2 * i] = 2 * odd[i] - 1;\n\
    \    for (long long i = 0; i + 1 < n; i++) len[2 * i + 1] = 2 * even[i + 1];\n\
    \    return len;\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam R \u914D\u5217\
    \u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long long> len\n\
    \ */\ntemplate <typename R>\nstd::vector<long long> palindrome_lengths(const R&\
    \ s) {\n    return palindrome_lengths(std::begin(s), std::end(s));\n}\n\n/**\n\
    \ * @brief \u540C\u3058\u9577\u3055\u306E 2 \u3064\u306E\u5217\u306E\u30CF\u30DF\
    \u30F3\u30B0\u8DDD\u96E2 (\u8981\u7D20\u304C\u7570\u306A\u308B\u4F4D\u7F6E\u306E\
    \u6570) O(N)\n *\n * @tparam R1 \u914D\u5217\u306E\u578B\n * @tparam R2 \u914D\
    \u5217\u306E\u578B\n * @param s \u914D\u5217\n * @param t \u914D\u5217 (s \u3068\
    \u540C\u3058\u9577\u3055)\n * @return long long \u30CF\u30DF\u30F3\u30B0\u8DDD\
    \u96E2\n */\ntemplate <typename R1, typename R2>\nauto hamming_distance(const\
    \ R1& s, const R2& t) -> decltype(std::begin(s), std::begin(t), 0LL) {\n    auto\
    \ a = std::begin(s);\n    auto b = std::begin(t);\n    long long n = std::end(s)\
    \ - a;\n    assert(n == std::end(t) - b);\n    long long res = 0;\n    for (long\
    \ long i = 0; i < n; i++) {\n        if (!(a[i] == b[i])) res++;\n    }\n    return\
    \ res;\n}\n"
  code: "#pragma once\n\n/**\n * @file string.hpp\n * @brief \u6587\u5B57\u5217\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001KMP\u3001Manacher)\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <iterator>\n#include <vector>\n\n\
    /**\n * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\
    \u5404i\u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n\
    \ * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin\
    \ \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end\
    \ \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long\
    \ long> z\n */\ntemplate <typename It>\nstd::vector<long long> z_algorithm(It\
    \ begin, It end) {\n    long long n = end - begin;\n    if (n == 0) return {};\n\
    \    std::vector<long long> z(n);\n    z[0] = n;\n    for (long long i = 1, j\
    \ = 0; i < n;) {\n        // [0, j)\u3068[i, i + j)\u304C\u4E00\u81F4\u3057\u3066\
    \u3044\u308B\n        while (i + j < n && begin[j] == begin[i + j]) j++;\n   \
    \     z[i] = j;\n        long long k = 1;  // [k,)\u3068[i+k,)\u306FLCP\u304C\u7B49\
    \u3057\u3044\u3068\u78BA\u5B9A\u3057\u3066\u3044\u308B\n        for (; k < j &&\
    \ k + z[k] < j; k++) {\n            z[i + k] = z[k];\n        }\n        i +=\
    \ k;\n        if (j) j -= k;\n    }\n    return z;\n}\n\n/**\n * @brief Z-algorithm\n\
    \ * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404i\u306B\u3064\u3044\
    \u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam R \u914D\u5217\
    \u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long long> z\n\
    \ */\ntemplate <typename R>\nstd::vector<long long> z_algorithm(const R& s) {\n\
    \    return z_algorithm(std::begin(s), std::end(s));\n}\n\n/**\n * @brief \u63A5\
    \u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i]\
    \ \u306E\u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\
    \u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\
    \u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\
    \u4F53\u3067 O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\
    \n * @return std::vector<long long> pi\n */\ntemplate <typename It>\nstd::vector<long\
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
    \  }\n    return res;\n}\n\n/**\n * @brief Manacher \u6CD5\n * s[i] \u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u56DE\u6587\u306E\u6700\u5927\
    \u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i]) \u304C\u56DE\u6587) \u3092\u5404\
    \ i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n *\
    \ @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin\
    \ \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end\
    \ \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long\
    \ long> r\n */\ntemplate <typename It>\nstd::vector<long long> manacher(It begin,\
    \ It end) {\n    long long n = end - begin;\n    std::vector<long long> r(n);\n\
    \    // [l, rr] \u306F\u3001\u3053\u308C\u307E\u3067\u306B\u898B\u3064\u3051\u305F\
    \u56DE\u6587\u306E\u3046\u3061\u53F3\u7AEF\u304C\u6700\u3082\u53F3\u306B\u3042\
    \u308B\u3082\u306E\n    for (long long i = 0, l = 0, rr = -1; i < n; i++) {\n\
    \        long long k = i > rr ? 1 : std::min(r[l + rr - i], rr - i + 1);\n   \
    \     while (0 <= i - k && i + k < n && begin[i - k] == begin[i + k]) k++;\n \
    \       r[i] = k--;\n        if (i + k > rr) {\n            l = i - k;\n     \
    \       rr = i + k;\n        }\n    }\n    return r;\n}\n\n/**\n * @brief Manacher\
    \ \u6CD5\n * s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\
    \u56DE\u6587\u306E\u6700\u5927\u306E\u534A\u5F84 r[i] (s[i - r[i] + 1, i + r[i])\
    \ \u304C\u56DE\u6587) \u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B\
    \ \u5168\u4F53\u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param\
    \ s \u914D\u5217\n * @return std::vector<long long> r\n */\ntemplate <typename\
    \ R>\nstd::vector<long long> manacher(const R& s) {\n    return manacher(std::begin(s),\
    \ std::end(s));\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam It \u914D\u5217\
    \u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\
    \u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\
    \u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> len\n */\ntemplate\
    \ <typename It>\nstd::vector<long long> palindrome_lengths(It begin, It end) {\n\
    \    long long n = end - begin;\n    if (n == 0) return {};\n    std::vector<long\
    \ long> odd = manacher(begin, end);\n    // even[i] \u306F s[i - 1] \u3068 s[i]\
    \ \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u56DE\
    \u6587\u306E\u6700\u5927\u306E\u534A\u5F84\n    std::vector<long long> even(n);\n\
    \    for (long long i = 0, l = 0, rr = -1; i < n; i++) {\n        long long k\
    \ = i > rr ? 0 : std::min(even[l + rr - i + 1], rr - i + 1);\n        while (0\
    \ <= i - k - 1 && i + k < n && begin[i - k - 1] == begin[i + k]) k++;\n      \
    \  even[i] = k--;\n        if (i + k > rr) {\n            l = i - k - 1;\n   \
    \         rr = i + k;\n        }\n    }\n    std::vector<long long> len(2 * n\
    \ - 1);\n    for (long long i = 0; i < n; i++) len[2 * i] = 2 * odd[i] - 1;\n\
    \    for (long long i = 0; i + 1 < n; i++) len[2 * i + 1] = 2 * even[i + 1];\n\
    \    return len;\n}\n\n/**\n * @brief \u5404\u4F4D\u7F6E\u3092\u4E2D\u5FC3\u3068\
    \u3059\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9577\u3055 \u5168\u4F53\u3067\
    \ O(N)\n * \u9577\u3055 2N - 1 \u306E\u914D\u5217 len \u3092\u8FD4\u3059\u3002\
    len[2i] \u306F s[i] \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u3001len[2i\
    \ + 1] \u306F s[i] \u3068 s[i + 1] \u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u56DE\u6587\u306E\u6700\u9577\u306E\u9577\u3055\n *\n * @tparam R \u914D\u5217\
    \u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long long> len\n\
    \ */\ntemplate <typename R>\nstd::vector<long long> palindrome_lengths(const R&\
    \ s) {\n    return palindrome_lengths(std::begin(s), std::end(s));\n}\n\n/**\n\
    \ * @brief \u540C\u3058\u9577\u3055\u306E 2 \u3064\u306E\u5217\u306E\u30CF\u30DF\
    \u30F3\u30B0\u8DDD\u96E2 (\u8981\u7D20\u304C\u7570\u306A\u308B\u4F4D\u7F6E\u306E\
    \u6570) O(N)\n *\n * @tparam R1 \u914D\u5217\u306E\u578B\n * @tparam R2 \u914D\
    \u5217\u306E\u578B\n * @param s \u914D\u5217\n * @param t \u914D\u5217 (s \u3068\
    \u540C\u3058\u9577\u3055)\n * @return long long \u30CF\u30DF\u30F3\u30B0\u8DDD\
    \u96E2\n */\ntemplate <typename R1, typename R2>\nauto hamming_distance(const\
    \ R1& s, const R2& t) -> decltype(std::begin(s), std::begin(t), 0LL) {\n    auto\
    \ a = std::begin(s);\n    auto b = std::begin(t);\n    long long n = std::end(s)\
    \ - a;\n    assert(n == std::end(t) - b);\n    long long res = 0;\n    for (long\
    \ long i = 0; i < n; i++) {\n        if (!(a[i] == b[i])) res++;\n    }\n    return\
    \ res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/string.hpp
  requiredBy: []
  timestamp: '2026-10-17 23:17:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/string.test.cpp
  - test/aoj/alds1/alds1-14-b.2.test.cpp
  - test/yosupo/string/enumerate-palindromes.2.test.cpp
  - test/yosupo/string/zalgorithm.test.cpp
documentation_of: src/string/string.hpp
layout: document
title: "\u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001\
  KMP\u3001Manacher)"
---

Z-algorithm・KMP 法・Manacher 法を $O(n)$ で行います。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。結果は `hamming_distance` だけ `long long`、ほかは `std::vector<long long>` で返します。

```cpp
auto z = z_algorithm(std::string("aabaab"));        // {6, 1, 0, 3, 1, 0}
auto pi = prefix_function(std::string("aabaaab"));  // {0, 1, 0, 1, 2, 2, 3}
auto pos = kmp_search(std::string("aaaa"), std::string("aa"));  // {0, 1, 2}
auto r = manacher(std::string("abaaba"));           // {1, 2, 1, 1, 2, 1}
auto len = palindrome_lengths(std::string("abaaba"));  // {1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1}
long long d = hamming_distance(std::string("karolin"), std::string("kathrin"));  // 3
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `z_algorithm(s)` / `z_algorithm(begin, end)` | 各 $i$ について、`s` と `s[i:]` の最長共通接頭辞の長さ `z[i]` を並べた `vector<long long>` (`z[0]` は `s` の長さ) | $O(n)$ |
| `prefix_function(s)` / `prefix_function(begin, end)` | 各 $i$ について、`s[0, i]` (両端を含む) の接頭辞であり接尾辞でもある部分のうち、`s[0, i]` 自身を除いた最長の長さ `pi[i]` (KMP 法の失敗関数) | $O(n)$ |
| `kmp_search(text, pattern)` | `text` の中で `pattern` が現れる開始位置を昇順に並べたもの (KMP 法)。$n$、$m$ は `text`、`pattern` の長さ。`pattern` が空なら $0, 1, \dots, n$ | $O(n + m)$ |
| `manacher(s)` / `manacher(begin, end)` | 各 $i$ について、`s[i]` を中心とする奇数長の回文の最大の半径 `r[i]` (`s[i - r[i] + 1, i + r[i])` が回文、長さは `2 * r[i] - 1`) | $O(n)$ |
| `palindrome_lengths(s)` / `palindrome_lengths(begin, end)` | 長さ $2n - 1$ の `len`。`len[2 * i]` は `s[i]` を中心とする最長の回文の長さ、`len[2 * i + 1]` は `s[i]` と `s[i + 1]` の間を中心とする最長の回文の長さ (なければ 0) | $O(n)$ |
| `hamming_distance(s, t)` | 同じ長さの `s` と `t` で要素が異なる位置の数 (長さが違うと assert で落ちる) | $O(n)$ |

- `s[l, r)` が回文かどうかは、`palindrome_lengths(s)[l + r - 1] >= r - l` で判定できます。
- 文字列の周期 (`s[i] == s[i + p]` がすべての i で成り立つ最小の `p`) は `n - pi[n - 1]` です。

## 関連

- 接尾辞を辞書順に並べるには [Suffix Array と LCP 配列](suffix-array.hpp)
- 部分文字列の一致判定をハッシュで行うには [ローリングハッシュ](rolling-hash.hpp)
- 複数の文字列の接頭辞を扱うには [Trie](trie.hpp)
- 2 つの列の最長共通部分文字列は [最長共通部分文字列](longest-common-substring.hpp)
- 異なる回文の種類や、各回文の出現回数を求めるには [回文木 (Eertree)](palindromic-tree.hpp)
- 整数のハミング距離は [ビット演算](../utility/bit.hpp) の `hamming_distance`
