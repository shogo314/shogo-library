---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/others/inversion-number.hpp
    title: "\u8EE2\u5012\u6570"
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
  bundledCode: "#line 1 \"test/unittest/inversion-number.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ inversion_number \u3092\u3001\u3059\u3079\u3066\u306E\u7D44\u3092\u8ABF\u3079\
    \u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\
    \u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#line 2 \"src/others/inversion-number.hpp\"\n\n/**\n * @file inversion-number.hpp\n\
    \ * @brief \u8EE2\u5012\u6570\n */\n\n#include <algorithm>\n#include <functional>\n\
    #include <utility>\n#include <vector>\n\n/**\n * @brief \u8EE2\u5012\u6570 (i\
    \ < j \u304B\u3064 comp(a[j], a[i]) \u3068\u306A\u308B\u7D44 (i, j) \u306E\u500B\
    \u6570) \u3092\u6C42\u3081\u308B O(n log n)\n *\n * \u30DE\u30FC\u30B8\u30BD\u30FC\
    \u30C8\u3067\u6570\u3048\u308B\u306E\u3067\u3001\u5EA7\u6A19\u5727\u7E2E\u306F\
    \u4E0D\u8981\u3002\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * @param comp \u5927\
    \u5C0F\u306E\u6BD4\u8F03\u3002std::greater<T>() \u3092\u6E21\u3059\u3068\u3001\
    i < j \u304B\u3064 a[i] < a[j] \u3068\u306A\u308B\u7D44\u306E\u500B\u6570\u306B\
    \u306A\u308B\n */\ntemplate <typename T, typename Compare = std::less<T>>\nlong\
    \ long inversion_number(std::vector<T> a, Compare comp = Compare()) {\n    int\
    \ n = a.size();\n    std::vector<T> buf(n);\n    long long res = 0;\n    for (int\
    \ w = 1; w < n; w *= 2) {\n        // \u9577\u3055 w \u306E\u30BD\u30FC\u30C8\u6E08\
    \u307F\u306E\u533A\u9593\u3092 2 \u3064\u305A\u3064\u30DE\u30FC\u30B8\u3059\u308B\
    \n        for (int l = 0; l < n; l += 2 * w) {\n            int m = std::min(l\
    \ + w, n), r = std::min(l + 2 * w, n);\n            int i = l, j = m, k = l;\n\
    \            while (i < m && j < r) {\n                if (comp(a[j], a[i])) {\n\
    \                    // a[j] \u306F\u5DE6\u5074\u306E\u6B8B\u308A a[i, m) \u306E\
    \u3059\u3079\u3066\u3088\u308A\u5C0F\u3055\u3044\n                    res += m\
    \ - i;\n                    buf[k++] = std::move(a[j++]);\n                } else\
    \ {\n                    buf[k++] = std::move(a[i++]);\n                }\n  \
    \          }\n            while (i < m) buf[k++] = std::move(a[i++]);\n      \
    \      while (j < r) buf[k++] = std::move(a[j++]);\n        }\n        std::swap(a,\
    \ buf);\n    }\n    return res;\n}\n#line 7 \"test/unittest/inversion-number.test.cpp\"\
    \n\n#line 9 \"test/unittest/inversion-number.test.cpp\"\n#include <iostream>\n\
    #include <random>\n#include <string>\n#line 13 \"test/unittest/inversion-number.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 40;\n        int\
    \ range = rng() % 10 + 1;\n        std::vector<int> a(n);\n        for (auto&\
    \ v : a) v = rng() % range;\n        long long less = 0, greater = 0;\n      \
    \  for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j < n; j++)\
    \ {\n                less += a[j] < a[i];\n                greater += a[i] < a[j];\n\
    \            }\n        }\n        ok = ok && inversion_number(a) == less && inversion_number(a,\
    \ std::greater<int>()) == greater;\n    }\n\n    // \u4F8B\n    ok = ok && inversion_number(std::vector<int>{3,\
    \ 1, 4, 1, 5}) == 3;\n    ok = ok && inversion_number(std::vector<int>{}) == 0;\n\
    \    ok = ok && inversion_number(std::vector<std::string>{\"c\", \"b\", \"a\"\
    }) == 3;\n    // \u7B54\u3048\u304C int \u306B\u53CE\u307E\u3089\u306A\u3044\n\
    \    std::vector<int> rev(100000);\n    for (int i = 0; i < 100000; i++) rev[i]\
    \ = 100000 - i;\n    ok = ok && inversion_number(rev) == 100000LL * 99999 / 2;\n\
    \n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n\
    \        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// inversion_number \u3092\u3001\u3059\u3079\u3066\u306E\u7D44\u3092\u8ABF\
    \u3079\u308B\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include \"../../src/others/inversion-number.hpp\"\n\n#include\
    \ <functional>\n#include <iostream>\n#include <random>\n#include <string>\n#include\
    \ <vector>\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 40;\n\
    \        int range = rng() % 10 + 1;\n        std::vector<int> a(n);\n       \
    \ for (auto& v : a) v = rng() % range;\n        long long less = 0, greater =\
    \ 0;\n        for (int i = 0; i < n; i++) {\n            for (int j = i + 1; j\
    \ < n; j++) {\n                less += a[j] < a[i];\n                greater +=\
    \ a[i] < a[j];\n            }\n        }\n        ok = ok && inversion_number(a)\
    \ == less && inversion_number(a, std::greater<int>()) == greater;\n    }\n\n \
    \   // \u4F8B\n    ok = ok && inversion_number(std::vector<int>{3, 1, 4, 1, 5})\
    \ == 3;\n    ok = ok && inversion_number(std::vector<int>{}) == 0;\n    ok = ok\
    \ && inversion_number(std::vector<std::string>{\"c\", \"b\", \"a\"}) == 3;\n \
    \   // \u7B54\u3048\u304C int \u306B\u53CE\u307E\u3089\u306A\u3044\n    std::vector<int>\
    \ rev(100000);\n    for (int i = 0; i < 100000; i++) rev[i] = 100000 - i;\n  \
    \  ok = ok && inversion_number(rev) == 100000LL * 99999 / 2;\n\n    if (ok)\n\
    \        std::cout << \"Hello World\" << std::endl;\n    else\n        std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/others/inversion-number.hpp
  isVerificationFile: true
  path: test/unittest/inversion-number.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:33:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/inversion-number.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/inversion-number.test.cpp
- /verify/test/unittest/inversion-number.test.cpp.html
title: test/unittest/inversion-number.test.cpp
---
