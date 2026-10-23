---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/string.hpp
    title: "\u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Z-algorithm\u3001\
      KMP\u3001Manacher\u3001Lyndon \u5206\u89E3)"
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
  bundledCode: "#line 1 \"test/unittest/string/string.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ z_algorithm\u3001prefix_function\u3001kmp_search\u3001manacher\u3001palindrome_lengths\u3001\
    hamming_distance\u3001lyndon_factorization \u3092\u611A\u76F4\u306A\u65B9\u6CD5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/string/string.hpp\"\
    \n\n/**\n * @file string.hpp\n * @brief \u6587\u5B57\u5217\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 (Z-algorithm\u3001KMP\u3001Manacher\u3001Lyndon \u5206\u89E3)\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <iterator>\n#include <vector>\n\
    \n/**\n * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\
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
    \ res;\n}\n\n/**\n * @brief Lyndon \u5206\u89E3 (Duval \u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0) O(N)\n * s \u3092 s = w_1 w_2 ... w_k (\u5404 w_i \u306F Lyndon\
    \ \u6587\u5B57\u5217\u3067\u3001w_1 >= w_2 >= ... >= w_k) \u306B\u5206\u3051\u308B\
    \n * Lyndon \u6587\u5B57\u5217\u306F\u3001\u81EA\u5206\u306E\u3069\u306E\u771F\
    \u306E\u63A5\u5C3E\u8F9E\u3088\u308A\u3082\u8F9E\u66F8\u9806\u3067\u771F\u306B\
    \u5C0F\u3055\u3044\u6587\u5B57\u5217\n *\n * @tparam It \u914D\u5217\u306E\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\u958B\u59CB\u30A4\
    \u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n * @return std::vector<long long> \u533A\u5207\u308A\u306E\
    \u4F4D\u7F6E 0 = a_0 < a_1 < ... < a_k = N (w_i = s[a_{i-1}, a_i))\n */\ntemplate\
    \ <typename It>\nstd::vector<long long> lyndon_factorization(It begin, It end)\
    \ {\n    const long long n = end - begin;\n    std::vector<long long> res = {0};\n\
    \    long long i = 0;\n    while (i < n) {\n        // s[i, j) \u306F\u3001\u9577\
    \u3055 j - k \u306E Lyndon \u6587\u5B57\u5217\u3092\u4F55\u56DE\u304B\u7E70\u308A\
    \u8FD4\u3057\u305F\u3082\u306E\u3068\u3001\u305D\u306E\u63A5\u982D\u8F9E\u3092\
    \u3064\u306A\u3044\u3060\u3082\u306E\n        long long j = i + 1, k = i;\n  \
    \      while (j < n && !(begin[j] < begin[k])) {\n            k = begin[k] < begin[j]\
    \ ? i : k + 1;\n            j++;\n        }\n        while (i <= k) {\n      \
    \      i += j - k;\n            res.push_back(i);\n        }\n    }\n    return\
    \ res;\n}\n\n/**\n * @brief Lyndon \u5206\u89E3 (Duval \u306E\u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0) O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param\
    \ s \u914D\u5217\n * @return std::vector<long long> \u533A\u5207\u308A\u306E\u4F4D\
    \u7F6E 0 = a_0 < a_1 < ... < a_k = N\n */\ntemplate <typename R>\nstd::vector<long\
    \ long> lyndon_factorization(const R& s) {\n    return lyndon_factorization(std::begin(s),\
    \ std::end(s));\n}\n#line 7 \"test/unittest/string/string.test.cpp\"\n\n#line\
    \ 9 \"test/unittest/string/string.test.cpp\"\n#include <iostream>\n#include <random>\n\
    #include <string>\n#line 13 \"test/unittest/string/string.test.cpp\"\n\nbool is_palindrome(const\
    \ std::string& s, int l, int r) {\n    for (int i = l, j = r - 1; i < j; i++,\
    \ j--) {\n        if (s[i] != s[j]) return false;\n    }\n    return true;\n}\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int\
    \ k = rng() % 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s)\
    \ c = 'a' + rng() % k;\n\n        std::vector<long long> z(n), pi(n), r(n), len(std::max(2\
    \ * n - 1, 0));\n        for (int i = 0; i < n; i++) {\n            while (i +\
    \ z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;\n            for (int l = 1; l <=\
    \ i; l++) {\n                if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i]\
    \ = l;\n            }\n            while (i - r[i] >= 0 && i + r[i] < n && is_palindrome(s,\
    \ i - r[i], i + r[i] + 1)) r[i]++;\n        }\n        for (int c = 0; c < 2 *\
    \ n - 1; c++) {\n            // \u4E2D\u5FC3 c / 2 \u306E\u56DE\u6587 [l, rr)\n\
    \            for (int l = c / 2, rr = (c + 1) / 2 + 1; 0 <= l && rr <= n && is_palindrome(s,\
    \ l, rr); l--, rr++) {\n                len[c] = rr - l;\n            }\n    \
    \    }\n        ok = ok && z_algorithm(s) == z && prefix_function(s) == pi;\n\
    \        ok = ok && manacher(s) == r && palindrome_lengths(s) == len;\n      \
    \  ok = ok && prefix_function(s.begin(), s.end()) == pi && manacher(s.begin(),\
    \ s.end()) == r;\n\n        int m = rng() % 4;\n        std::string p(m, 'a');\n\
    \        for (auto& c : p) c = 'a' + rng() % k;\n        std::vector<long long>\
    \ occ;\n        for (int i = 0; i + m <= n; i++) {\n            if (s.substr(i,\
    \ m) == p) occ.push_back(i);\n        }\n        ok = ok && kmp_search(s, p) ==\
    \ occ;\n\n        std::string u(n, 'a');\n        for (auto& c : u) c = 'a' +\
    \ rng() % k;\n        long long hd = 0;\n        for (int i = 0; i < n; i++) hd\
    \ += s[i] != u[i];\n        ok = ok && hamming_distance(s, u) == hd;\n    }\n\n\
    \    // lyndon_factorization: \u6700\u9577\u306E Lyndon \u6587\u5B57\u5217\u3067\
    \u3042\u308B\u63A5\u982D\u8F9E\u3092\u7E70\u308A\u8FD4\u3057\u5207\u308A\u51FA\
    \u3057\u305F\u3082\u306E (Lyndon \u5206\u89E3\u306E\u6700\u521D\u306E\u6210\u5206\
    \u306F\u3053\u308C\u306B\u306A\u308B) \u3068\u6BD4\u3079\u308B\n    auto is_lyndon\
    \ = [](const std::string& w) {\n        for (size_t i = 1; i < w.size(); i++)\n\
    \            if (!(w < w.substr(i))) return false;\n        return !w.empty();\n\
    \    };\n    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng()\
    \ % 13;\n        std::string s;\n        for (int i = 0; i < n; i++) s += static_cast<char>('a'\
    \ + rng() % 3);\n        std::vector<long long> expect = {0};\n        for (int\
    \ i = 0; i < n;) {\n            int len = 1;\n            for (int l = 1; i +\
    \ l <= n; l++)\n                if (is_lyndon(s.substr(i, l))) len = l;\n    \
    \        i += len;\n            expect.push_back(i);\n        }\n        ok =\
    \ ok && lyndon_factorization(s) == expect;\n        std::vector<int> v(s.begin(),\
    \ s.end());\n        ok = ok && lyndon_factorization(v) == expect;\n    }\n\n\
    \    // \u4F8B\n    ok = ok && lyndon_factorization(std::string(\"abracadabra\"\
    )) == std::vector<long long>{0, 7, 10, 11};\n    ok = ok && prefix_function(std::string(\"\
    aabaaab\")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\")) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1}) ==\
    \ std::vector<long long>{0, 2};\n    ok = ok && manacher(std::string(\"abaaba\"\
    )) == std::vector<long long>{1, 2, 1, 1, 2, 1};\n    ok = ok && hamming_distance(std::string(\"\
    karolin\"), std::string(\"kathrin\")) == 3;\n    ok = ok && hamming_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{1, 0, 3}) == 1;\n    ok = ok && hamming_distance(std::string(\"\
    \"), std::string(\"\")) == 0;\n    ok = ok && palindrome_lengths(std::string(\"\
    abaaba\")) == std::vector<long long>{1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1};\n\n   \
    \ if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n    \
    \    std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// z_algorithm\u3001prefix_function\u3001kmp_search\u3001manacher\u3001palindrome_lengths\u3001\
    hamming_distance\u3001lyndon_factorization \u3092\u611A\u76F4\u306A\u65B9\u6CD5\
    \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/string.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #include <vector>\n\nbool is_palindrome(const std::string& s, int l, int r) {\n\
    \    for (int i = l, j = r - 1; i < j; i++, j--) {\n        if (s[i] != s[j])\
    \ return false;\n    }\n    return true;\n}\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 5000 && ok; rep++)\
    \ {\n        int n = rng() % 30;\n        int k = rng() % 3 + 1;\n        std::string\
    \ s(n, 'a');\n        for (auto& c : s) c = 'a' + rng() % k;\n\n        std::vector<long\
    \ long> z(n), pi(n), r(n), len(std::max(2 * n - 1, 0));\n        for (int i =\
    \ 0; i < n; i++) {\n            while (i + z[i] < n && s[z[i]] == s[i + z[i]])\
    \ z[i]++;\n            for (int l = 1; l <= i; l++) {\n                if (s.substr(0,\
    \ l) == s.substr(i + 1 - l, l)) pi[i] = l;\n            }\n            while (i\
    \ - r[i] >= 0 && i + r[i] < n && is_palindrome(s, i - r[i], i + r[i] + 1)) r[i]++;\n\
    \        }\n        for (int c = 0; c < 2 * n - 1; c++) {\n            // \u4E2D\
    \u5FC3 c / 2 \u306E\u56DE\u6587 [l, rr)\n            for (int l = c / 2, rr =\
    \ (c + 1) / 2 + 1; 0 <= l && rr <= n && is_palindrome(s, l, rr); l--, rr++) {\n\
    \                len[c] = rr - l;\n            }\n        }\n        ok = ok &&\
    \ z_algorithm(s) == z && prefix_function(s) == pi;\n        ok = ok && manacher(s)\
    \ == r && palindrome_lengths(s) == len;\n        ok = ok && prefix_function(s.begin(),\
    \ s.end()) == pi && manacher(s.begin(), s.end()) == r;\n\n        int m = rng()\
    \ % 4;\n        std::string p(m, 'a');\n        for (auto& c : p) c = 'a' + rng()\
    \ % k;\n        std::vector<long long> occ;\n        for (int i = 0; i + m <=\
    \ n; i++) {\n            if (s.substr(i, m) == p) occ.push_back(i);\n        }\n\
    \        ok = ok && kmp_search(s, p) == occ;\n\n        std::string u(n, 'a');\n\
    \        for (auto& c : u) c = 'a' + rng() % k;\n        long long hd = 0;\n \
    \       for (int i = 0; i < n; i++) hd += s[i] != u[i];\n        ok = ok && hamming_distance(s,\
    \ u) == hd;\n    }\n\n    // lyndon_factorization: \u6700\u9577\u306E Lyndon \u6587\
    \u5B57\u5217\u3067\u3042\u308B\u63A5\u982D\u8F9E\u3092\u7E70\u308A\u8FD4\u3057\
    \u5207\u308A\u51FA\u3057\u305F\u3082\u306E (Lyndon \u5206\u89E3\u306E\u6700\u521D\
    \u306E\u6210\u5206\u306F\u3053\u308C\u306B\u306A\u308B) \u3068\u6BD4\u3079\u308B\
    \n    auto is_lyndon = [](const std::string& w) {\n        for (size_t i = 1;\
    \ i < w.size(); i++)\n            if (!(w < w.substr(i))) return false;\n    \
    \    return !w.empty();\n    };\n    for (int rep = 0; rep < 3000 && ok; rep++)\
    \ {\n        int n = rng() % 13;\n        std::string s;\n        for (int i =\
    \ 0; i < n; i++) s += static_cast<char>('a' + rng() % 3);\n        std::vector<long\
    \ long> expect = {0};\n        for (int i = 0; i < n;) {\n            int len\
    \ = 1;\n            for (int l = 1; i + l <= n; l++)\n                if (is_lyndon(s.substr(i,\
    \ l))) len = l;\n            i += len;\n            expect.push_back(i);\n   \
    \     }\n        ok = ok && lyndon_factorization(s) == expect;\n        std::vector<int>\
    \ v(s.begin(), s.end());\n        ok = ok && lyndon_factorization(v) == expect;\n\
    \    }\n\n    // \u4F8B\n    ok = ok && lyndon_factorization(std::string(\"abracadabra\"\
    )) == std::vector<long long>{0, 7, 10, 11};\n    ok = ok && prefix_function(std::string(\"\
    aabaaab\")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\")) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1}) ==\
    \ std::vector<long long>{0, 2};\n    ok = ok && manacher(std::string(\"abaaba\"\
    )) == std::vector<long long>{1, 2, 1, 1, 2, 1};\n    ok = ok && hamming_distance(std::string(\"\
    karolin\"), std::string(\"kathrin\")) == 3;\n    ok = ok && hamming_distance(std::vector<int>{1,\
    \ 2, 3}, std::vector<long long>{1, 0, 3}) == 1;\n    ok = ok && hamming_distance(std::string(\"\
    \"), std::string(\"\")) == 0;\n    ok = ok && palindrome_lengths(std::string(\"\
    abaaba\")) == std::vector<long long>{1, 0, 3, 0, 1, 6, 1, 0, 3, 0, 1};\n\n   \
    \ if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n    \
    \    std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/string.hpp
  isVerificationFile: true
  path: test/unittest/string/string.test.cpp
  requiredBy: []
  timestamp: '2026-10-23 19:16:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/string.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/string.test.cpp
- /verify/test/unittest/string/string.test.cpp.html
title: test/unittest/string/string.test.cpp
---
