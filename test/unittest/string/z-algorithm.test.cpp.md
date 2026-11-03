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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/string/z-algorithm.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ z_algorithm \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/string/z-algorithm.hpp\"\n\n/**\n *\
    \ @file z-algorithm.hpp\n * @brief Z-algorithm\n */\n\n#include <iterator>\n#include\
    \ <vector>\n\n/**\n * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\
    \u3055\u3092\u5404i\u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067\
    O(N)\n *\n * @tparam It \u914D\u5217\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param\
    \ begin \u914D\u5217\u306E\u958B\u59CB\u30A4\u30C6\u30EC\u30FC\u30BF\n * @param\
    \ end \u914D\u5217\u306E\u7D42\u4E86\u30A4\u30C6\u30EC\u30FC\u30BF\n * @return\
    \ std::vector<long long> z\n */\ntemplate <typename It>\nstd::vector<long long>\
    \ z_algorithm(It begin, It end) {\n    long long n = end - begin;\n    if (n ==\
    \ 0) return {};\n    std::vector<long long> z(n);\n    z[0] = n;\n    for (long\
    \ long i = 1, j = 0; i < n;) {\n        // [0, j)\u3068[i, i + j)\u304C\u4E00\u81F4\
    \u3057\u3066\u3044\u308B\n        while (i + j < n && begin[j] == begin[i + j])\
    \ j++;\n        z[i] = j;\n        long long k = 1;  // [k,)\u3068[i+k,)\u306F\
    LCP\u304C\u7B49\u3057\u3044\u3068\u78BA\u5B9A\u3057\u3066\u3044\u308B\n      \
    \  for (; k < j && k + z[k] < j; k++) {\n            z[i + k] = z[k];\n      \
    \  }\n        i += k;\n        if (j) j -= k;\n    }\n    return z;\n}\n\n/**\n\
    \ * @brief Z-algorithm\n * s[0:]\u3068s[i:]\u306ELCP\u306E\u9577\u3055\u3092\u5404\
    i\u306B\u3064\u3044\u3066\u6C42\u3081\u308B \u5168\u4F53\u3067O(N)\n *\n * @tparam\
    \ R \u914D\u5217\u306E\u578B\n * @param s \u914D\u5217\n * @return std::vector<long\
    \ long> z\n */\ntemplate <typename R>\nstd::vector<long long> z_algorithm(const\
    \ R& s) {\n    return z_algorithm(std::begin(s), std::end(s));\n}\n#line 7 \"\
    test/unittest/string/z-algorithm.test.cpp\"\n\n#include <iostream>\n#include <random>\n\
    #include <string>\n#line 12 \"test/unittest/string/z-algorithm.test.cpp\"\n\n\
    int main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep\
    \ = 0; rep < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int k\
    \ = rng() % 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s)\
    \ c = 'a' + rng() % k;\n        std::vector<long long> z(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            while (i + z[i] < n && s[z[i]] == s[i + z[i]])\
    \ z[i]++;\n        }\n        ok = ok && z_algorithm(s) == z && z_algorithm(s.begin(),\
    \ s.end()) == z;\n    }\n    ok = ok && z_algorithm(std::string(\"aabaab\")) ==\
    \ std::vector<long long>{6, 1, 0, 3, 1, 0};\n    ok = ok && z_algorithm(std::vector<int>{}).empty();\n\
    \n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n\
    \        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// z_algorithm \u3092\u611A\u76F4\u306A\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/string/z-algorithm.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <string>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 5000 && ok; rep++) {\n        int n = rng() % 30;\n        int\
    \ k = rng() % 3 + 1;\n        std::string s(n, 'a');\n        for (auto& c : s)\
    \ c = 'a' + rng() % k;\n        std::vector<long long> z(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            while (i + z[i] < n && s[z[i]] == s[i + z[i]])\
    \ z[i]++;\n        }\n        ok = ok && z_algorithm(s) == z && z_algorithm(s.begin(),\
    \ s.end()) == z;\n    }\n    ok = ok && z_algorithm(std::string(\"aabaab\")) ==\
    \ std::vector<long long>{6, 1, 0, 3, 1, 0};\n    ok = ok && z_algorithm(std::vector<int>{}).empty();\n\
    \n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n    else\n\
    \        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/z-algorithm.hpp
  isVerificationFile: true
  path: test/unittest/string/z-algorithm.test.cpp
  requiredBy: []
  timestamp: '2026-11-03 20:20:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/z-algorithm.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/z-algorithm.test.cpp
- /verify/test/unittest/string/z-algorithm.test.cpp.html
title: test/unittest/string/z-algorithm.test.cpp
---
