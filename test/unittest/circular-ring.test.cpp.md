---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/circular-ring.hpp
    title: "\u5186\u74B0"
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
  bundledCode: "#line 1 \"test/unittest/circular-ring.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ CircularRing \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/circular-ring.hpp\"\n\
    \n/**\n * @file circular-ring.hpp\n * @brief \u5186\u74B0\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <vector>\n\n/**\n * @brief \u5186\u74B0\n * @tparam\
    \ T\n */\ntemplate <typename T>\nstruct CircularRing {\n    std::vector<T> data;\n\
    \    explicit CircularRing(const std::vector<T>& v) : data(v) {}\n    CircularRing(const\
    \ CircularRing&) = default;\n    CircularRing() = default;\n    explicit CircularRing(long\
    \ long s) : data(s) {}\n    T at(long long i) const {\n        assert(!data.empty());\n\
    \        i %= static_cast<long long>(data.size());\n        if (i < 0) i += static_cast<long\
    \ long>(data.size());\n        return data[i];\n    }\n    T& at(long long i)\
    \ {\n        assert(!data.empty());\n        i %= static_cast<long long>(data.size());\n\
    \        if (i < 0) i += static_cast<long long>(data.size());\n        return\
    \ data[i];\n    }\n    T operator[](long long i) const {\n        return at(i);\n\
    \    }\n    T& operator[](long long i) {\n        return at(i);\n    }\n};\n#line\
    \ 7 \"test/unittest/circular-ring.test.cpp\"\n\n#include <iostream>\n#include\
    \ <random>\n#line 11 \"test/unittest/circular-ring.test.cpp\"\n\n// i \u3092 n\
    \ \u3067\u5272\u3063\u305F\u975E\u8CA0\u306E\u4F59\u308A\nlong long pos(long long\
    \ i, long long n) {\n    long long r = i % n;\n    return r < 0 ? r + n : r;\n\
    }\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 6 + 1;\n \
    \       std::vector<int> v(n);\n        for (int& x : v) x = rng() % 100;\n  \
    \      CircularRing<int> ring(v);\n        // \u30B5\u30A4\u30BA\u3092\u6307\u5B9A\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306F\u5024\u521D\u671F\
    \u5316\u3055\u308C\u305F\u8981\u7D20\u3092\u6301\u3064\n        CircularRing<int>\
    \ zeros(static_cast<size_t>(n));\n        const CircularRing<int>& cring = ring;\n\
    \        for (int t = 0; t < 30 && ok; t++) {\n            // \u8CA0\u306E\u6DFB\
    \u5B57\u3084\u5927\u304D\u306A\u6DFB\u5B57\u3082\u4F7F\u3046\n            long\
    \ long i;\n            switch (rng() % 3) {\n                case 0:\n       \
    \             i = static_cast<long long>(rng() % 20) - 10;\n                 \
    \   break;\n                case 1:\n                    i = static_cast<long\
    \ long>(rng() >> 2);\n                    break;\n                default:\n \
    \                   i = -static_cast<long long>(rng() >> 2);\n               \
    \     break;\n            }\n            long long p = pos(i, n);\n          \
    \  if (cring.at(i) != v[p] || cring[i] != v[p] || ring.at(i) != v[p] || ring[i]\
    \ != v[p]) ok = false;\n            if (zeros[i] != 0) ok = false;\n         \
    \   // \u53C2\u7167\u3092\u8FD4\u3059 at / [] \u3067\u66F8\u304D\u63DB\u3048\u308B\
    \u3068\u3001\u540C\u3058\u4F4D\u7F6E\u306E\u3059\u3079\u3066\u306E\u6DFB\u5B57\
    \u306B\u53CD\u6620\u3055\u308C\u308B\n            int x = rng() % 100;\n     \
    \       if (rng() % 2)\n                ring[i] = x;\n            else\n     \
    \           ring.at(i) = x;\n            v[p] = x;\n            if (ring[i + n]\
    \ != x || ring[i - 3LL * n] != x) ok = false;\n            if (ring.data != v)\
    \ ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// CircularRing \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/circular-ring.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <vector>\n\n// i \u3092 n\
    \ \u3067\u5272\u3063\u305F\u975E\u8CA0\u306E\u4F59\u308A\nlong long pos(long long\
    \ i, long long n) {\n    long long r = i % n;\n    return r < 0 ? r + n : r;\n\
    }\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for\
    \ (int rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 6 + 1;\n \
    \       std::vector<int> v(n);\n        for (int& x : v) x = rng() % 100;\n  \
    \      CircularRing<int> ring(v);\n        // \u30B5\u30A4\u30BA\u3092\u6307\u5B9A\
    \u3059\u308B\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306F\u5024\u521D\u671F\
    \u5316\u3055\u308C\u305F\u8981\u7D20\u3092\u6301\u3064\n        CircularRing<int>\
    \ zeros(static_cast<size_t>(n));\n        const CircularRing<int>& cring = ring;\n\
    \        for (int t = 0; t < 30 && ok; t++) {\n            // \u8CA0\u306E\u6DFB\
    \u5B57\u3084\u5927\u304D\u306A\u6DFB\u5B57\u3082\u4F7F\u3046\n            long\
    \ long i;\n            switch (rng() % 3) {\n                case 0:\n       \
    \             i = static_cast<long long>(rng() % 20) - 10;\n                 \
    \   break;\n                case 1:\n                    i = static_cast<long\
    \ long>(rng() >> 2);\n                    break;\n                default:\n \
    \                   i = -static_cast<long long>(rng() >> 2);\n               \
    \     break;\n            }\n            long long p = pos(i, n);\n          \
    \  if (cring.at(i) != v[p] || cring[i] != v[p] || ring.at(i) != v[p] || ring[i]\
    \ != v[p]) ok = false;\n            if (zeros[i] != 0) ok = false;\n         \
    \   // \u53C2\u7167\u3092\u8FD4\u3059 at / [] \u3067\u66F8\u304D\u63DB\u3048\u308B\
    \u3068\u3001\u540C\u3058\u4F4D\u7F6E\u306E\u3059\u3079\u3066\u306E\u6DFB\u5B57\
    \u306B\u53CD\u6620\u3055\u308C\u308B\n            int x = rng() % 100;\n     \
    \       if (rng() % 2)\n                ring[i] = x;\n            else\n     \
    \           ring.at(i) = x;\n            v[p] = x;\n            if (ring[i + n]\
    \ != x || ring[i - 3LL * n] != x) ok = false;\n            if (ring.data != v)\
    \ ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/circular-ring.hpp
  isVerificationFile: true
  path: test/unittest/circular-ring.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 07:35:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/circular-ring.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/circular-ring.test.cpp
- /verify/test/unittest/circular-ring.test.cpp.html
title: test/unittest/circular-ring.test.cpp
---
