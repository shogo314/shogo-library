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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/string/kmp.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// prefix_function\u3001\
    kmp_search \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/string/kmp.hpp\"\n\n/**\n * @file kmp.hpp\n\
    \ * @brief \u63A5\u982D\u8F9E\u95A2\u6570\u3068 KMP \u6CD5\n */\n\n#include <iterator>\n\
    #include <vector>\n\n/**\n * @brief \u63A5\u982D\u8F9E\u95A2\u6570 (KMP \u6CD5\
    \u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\u63A5\u982D\u8F9E\u3067\u3042\
    \u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\u90E8\u5206 (s[0, i] \u81EA\u8EAB\
    \u3092\u9664\u304F) \u306E\u6700\u9577\u306E\u9577\u3055\u3092\u5404 i \u306B\u3064\
    \u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067 O(N)\n *\n * @tparam It \u914D\
    \u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param begin \u914D\u5217\u306E\
    \u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param end \u914D\u5217\u306E\u7D42\
    \u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return std::vector<long long> pi\n */\n\
    template <typename It>\nstd::vector<long long> prefix_function(It begin, It end)\
    \ {\n    long long n = end - begin;\n    std::vector<long long> pi(n);\n    for\
    \ (long long i = 1; i < n; i++) {\n        long long j = pi[i - 1];\n        while\
    \ (j > 0 && !(begin[i] == begin[j])) j = pi[j - 1];\n        if (begin[i] == begin[j])\
    \ j++;\n        pi[i] = j;\n    }\n    return pi;\n}\n\n/**\n * @brief \u63A5\u982D\
    \u8F9E\u95A2\u6570 (KMP \u6CD5\u306E\u5931\u6557\u95A2\u6570)\n * s[0, i] \u306E\
    \u63A5\u982D\u8F9E\u3067\u3042\u308A\u63A5\u5C3E\u8F9E\u3067\u3082\u3042\u308B\
    \u90E8\u5206 (s[0, i] \u81EA\u8EAB\u3092\u9664\u304F) \u306E\u6700\u9577\u306E\
    \u9577\u3055\u3092\u5404 i \u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\
    \u3067 O(N)\n *\n * @tparam R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\
    \n * @return std::vector<long long> pi\n */\ntemplate <typename R>\nstd::vector<long\
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
    \ - 1];\n        }\n    }\n    return res;\n}\n#line 7 \"test/unittest/string/kmp.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <string>\n#line 12 \"test/unittest/string/kmp.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int\
    \ k = rng() % 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s)\
    \ c = 'a' + rng() % k;\n\n        std::vector<long long> pi(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int l = 1; l <= i; l++) {\n         \
    \       if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;\n           \
    \ }\n        }\n        ok = ok && prefix_function(s) == pi && prefix_function(s.begin(),\
    \ s.end()) == pi;\n\n        int m = rng() % 4;\n        std::string p(m, 'a');\n\
    \        for (auto& c : p) c = 'a' + rng() % k;\n        std::vector<long long>\
    \ occ;\n        for (int i = 0; i + m <= n; i++) {\n            if (s.substr(i,\
    \ m) == p) occ.push_back(i);\n        }\n        ok = ok && kmp_search(s, p) ==\
    \ occ;\n    }\n\n    // \u4F8B\n    ok = ok && prefix_function(std::string(\"\
    aabaaab\")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\")) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1}) ==\
    \ std::vector<long long>{0, 2};\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// prefix_function\u3001kmp_search \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\
    \u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/kmp.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <string>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int\
    \ k = rng() % 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s)\
    \ c = 'a' + rng() % k;\n\n        std::vector<long long> pi(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int l = 1; l <= i; l++) {\n         \
    \       if (s.substr(0, l) == s.substr(i + 1 - l, l)) pi[i] = l;\n           \
    \ }\n        }\n        ok = ok && prefix_function(s) == pi && prefix_function(s.begin(),\
    \ s.end()) == pi;\n\n        int m = rng() % 4;\n        std::string p(m, 'a');\n\
    \        for (auto& c : p) c = 'a' + rng() % k;\n        std::vector<long long>\
    \ occ;\n        for (int i = 0; i + m <= n; i++) {\n            if (s.substr(i,\
    \ m) == p) occ.push_back(i);\n        }\n        ok = ok && kmp_search(s, p) ==\
    \ occ;\n    }\n\n    // \u4F8B\n    ok = ok && prefix_function(std::string(\"\
    aabaaab\")) == std::vector<long long>{0, 1, 0, 1, 2, 2, 3};\n    ok = ok && kmp_search(std::string(\"\
    aaaa\"), std::string(\"aa\")) == std::vector<long long>{0, 1, 2};\n    ok = ok\
    \ && kmp_search(std::vector<int>{1, 2, 1, 2, 1}, std::vector<int>{1, 2, 1}) ==\
    \ std::vector<long long>{0, 2};\n\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/kmp.hpp
  isVerificationFile: true
  path: test/unittest/string/kmp.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/kmp.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/kmp.test.cpp
- /verify/test/unittest/string/kmp.test.cpp.html
title: test/unittest/string/kmp.test.cpp
---
