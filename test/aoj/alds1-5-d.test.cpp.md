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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/aoj/alds1-5-d.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 2 \"src/others/inversion-number.hpp\"\
    \n\n/**\n * @file inversion-number.hpp\n * @brief \u8EE2\u5012\u6570\n */\n\n\
    #include <algorithm>\n#include <functional>\n#include <utility>\n#line 12 \"src/others/inversion-number.hpp\"\
    \n\n/**\n * @brief \u8EE2\u5012\u6570 (i < j \u304B\u3064 comp(a[j], a[i]) \u3068\
    \u306A\u308B\u7D44 (i, j) \u306E\u500B\u6570) \u3092\u6C42\u3081\u308B O(n log\
    \ n)\n *\n * \u30DE\u30FC\u30B8\u30BD\u30FC\u30C8\u3067\u6570\u3048\u308B\u306E\
    \u3067\u3001\u5EA7\u6A19\u5727\u7E2E\u306F\u4E0D\u8981\u3002\u518D\u5E30\u3092\
    \u4F7F\u308F\u306A\u3044\n * @param comp \u5927\u5C0F\u306E\u6BD4\u8F03\u3002\
    std::greater<T>() \u3092\u6E21\u3059\u3068\u3001i < j \u304B\u3064 a[i] < a[j]\
    \ \u3068\u306A\u308B\u7D44\u306E\u500B\u6570\u306B\u306A\u308B\n */\ntemplate\
    \ <typename T, typename Compare = std::less<T>>\nlong long inversion_number(std::vector<T>\
    \ a, Compare comp = Compare()) {\n    int n = a.size();\n    std::vector<T> buf(n);\n\
    \    long long res = 0;\n    for (int w = 1; w < n; w *= 2) {\n        // \u9577\
    \u3055 w \u306E\u30BD\u30FC\u30C8\u6E08\u307F\u306E\u533A\u9593\u3092 2 \u3064\
    \u305A\u3064\u30DE\u30FC\u30B8\u3059\u308B\n        for (int l = 0; l < n; l +=\
    \ 2 * w) {\n            int m = std::min(l + w, n), r = std::min(l + 2 * w, n);\n\
    \            int i = l, j = m, k = l;\n            while (i < m && j < r) {\n\
    \                if (comp(a[j], a[i])) {\n                    // a[j] \u306F\u5DE6\
    \u5074\u306E\u6B8B\u308A a[i, m) \u306E\u3059\u3079\u3066\u3088\u308A\u5C0F\u3055\
    \u3044\n                    res += m - i;\n                    buf[k++] = std::move(a[j++]);\n\
    \                } else {\n                    buf[k++] = std::move(a[i++]);\n\
    \                }\n            }\n            while (i < m) buf[k++] = std::move(a[i++]);\n\
    \            while (j < r) buf[k++] = std::move(a[j++]);\n        }\n        std::swap(a,\
    \ buf);\n    }\n    return res;\n}\n#line 7 \"test/aoj/alds1-5-d.test.cpp\"\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for (auto& x\
    \ : a) std::cin >> x;\n    std::cout << inversion_number(a) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/others/inversion-number.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<int> a(n);\n    for (auto& x\
    \ : a) std::cin >> x;\n    std::cout << inversion_number(a) << '\\n';\n}\n"
  dependsOn:
  - src/others/inversion-number.hpp
  isVerificationFile: true
  path: test/aoj/alds1-5-d.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 01:15:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1-5-d.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1-5-d.test.cpp
- /verify/test/aoj/alds1-5-d.test.cpp.html
title: test/aoj/alds1-5-d.test.cpp
---
