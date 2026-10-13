---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/tadpole-array.hpp
    title: "\u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217"
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
  bundledCode: "#line 1 \"test/unittest/tadpole-array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ TadpoleArray \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#line 2 \"src/data_structures/tadpole-array.hpp\"\n\n/**\n * @file tadpole-array.hpp\n\
    \ * @brief \u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217\n */\n\n#include\
    \ <cassert>\n#include <cstddef>\n#line 11 \"src/data_structures/tadpole-array.hpp\"\
    \n/**\n * @brief \u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217\n * \u7279\
    \u5B9A\u306E\u4F4D\u7F6E\u3067\u30EB\u30FC\u30D7\u3059\u308B\u69CB\u9020\n * @tparam\
    \ T\n */\ntemplate <typename T>\nstruct TadpoleArray {\n   private:\n    std::vector<T>\
    \ data;\n    std::size_t k;\n\n   public:\n    /**\n     * @brief \u6700\u5F8C\
    \u306E\u6B21\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304Ci\n     */\n    TadpoleArray(const\
    \ std::vector<T>& v, int i) : data(v) {\n        assert(0 <= i and i < static_cast<int>(data.size()));\n\
    \        k = static_cast<std::size_t>(i);\n    }\n    TadpoleArray() = default;\n\
    \    TadpoleArray(const TadpoleArray&) = default;\n    T at(std::size_t i) const\
    \ {\n        if (i < k) return data[i];\n        return data[(i - k) % (data.size()\
    \ - k) + k];\n    }\n    T operator[](std::size_t i) const {\n        return at(i);\n\
    \    }\n};\n#line 11 \"test/unittest/tadpole-array.test.cpp\"\n\nint main() {\n\
    \    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep\
    \ < 2000 && ok; rep++) {\n        int n = rng() % 6 + 1;\n        int k = rng()\
    \ % n;  // \u6700\u5F8C\u306E\u6B21\u306F k \u756A\u76EE\u306B\u623B\u308B\n \
    \       std::vector<int> v(n);\n        for (int& x : v) x = rng() % 100;\n  \
    \      TadpoleArray<int> ta(v, k);\n\n        // \u611A\u76F4: 0 \u304B\u3089\u9806\
    \u306B\u9032\u307F\u3001\u672B\u5C3E\u306E\u6B21\u306F k \u306B\u623B\u308B\n\
    \        int p = 0;\n        for (size_t i = 0; i < 200; i++) {\n            if\
    \ (ta.at(i) != v[p] || ta[i] != v[p]) ok = false;\n            p = (p + 1 < n)\
    \ ? p + 1 : k;\n        }\n        // \u5927\u304D\u306A\u6DFB\u5B57: \u30EB\u30FC\
    \u30D7\u90E8\u5206\u306E\u9577\u3055 n - k \u3054\u3068\u306B\u540C\u3058\u5024\
    \u306B\u306A\u308B\n        for (int t = 0; t < 20; t++) {\n            size_t\
    \ i = k + rng() % 1000000000000ULL;\n            size_t period = n - k;\n    \
    \        if (ta[i] != ta[k + (i - k) % period]) ok = false;\n            if (ta[i]\
    \ != ta[i + period * (rng() % 1000)]) ok = false;\n        }\n        // \u30B3\
    \u30D4\u30FC\u3057\u3066\u3082\u540C\u3058\u5217\u3092\u8868\u3059\n        TadpoleArray<int>\
    \ copy(ta);\n        for (size_t i = 0; i < 50; i++) {\n            if (copy[i]\
    \ != ta[i]) ok = false;\n        }\n    }\n    if (ok) std::cout << \"Hello World\"\
    \ << std::endl;\n    else std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// TadpoleArray \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include <iostream>\n#include <random>\n#include\
    \ <vector>\n\n#include \"../../src/data_structures/tadpole-array.hpp\"\n\nint\
    \ main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n    for (int rep\
    \ = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 6 + 1;\n        int\
    \ k = rng() % n;  // \u6700\u5F8C\u306E\u6B21\u306F k \u756A\u76EE\u306B\u623B\
    \u308B\n        std::vector<int> v(n);\n        for (int& x : v) x = rng() % 100;\n\
    \        TadpoleArray<int> ta(v, k);\n\n        // \u611A\u76F4: 0 \u304B\u3089\
    \u9806\u306B\u9032\u307F\u3001\u672B\u5C3E\u306E\u6B21\u306F k \u306B\u623B\u308B\
    \n        int p = 0;\n        for (size_t i = 0; i < 200; i++) {\n           \
    \ if (ta.at(i) != v[p] || ta[i] != v[p]) ok = false;\n            p = (p + 1 <\
    \ n) ? p + 1 : k;\n        }\n        // \u5927\u304D\u306A\u6DFB\u5B57: \u30EB\
    \u30FC\u30D7\u90E8\u5206\u306E\u9577\u3055 n - k \u3054\u3068\u306B\u540C\u3058\
    \u5024\u306B\u306A\u308B\n        for (int t = 0; t < 20; t++) {\n           \
    \ size_t i = k + rng() % 1000000000000ULL;\n            size_t period = n - k;\n\
    \            if (ta[i] != ta[k + (i - k) % period]) ok = false;\n            if\
    \ (ta[i] != ta[i + period * (rng() % 1000)]) ok = false;\n        }\n        //\
    \ \u30B3\u30D4\u30FC\u3057\u3066\u3082\u540C\u3058\u5217\u3092\u8868\u3059\n \
    \       TadpoleArray<int> copy(ta);\n        for (size_t i = 0; i < 50; i++) {\n\
    \            if (copy[i] != ta[i]) ok = false;\n        }\n    }\n    if (ok)\
    \ std::cout << \"Hello World\" << std::endl;\n    else std::cerr << \"failed\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/tadpole-array.hpp
  isVerificationFile: true
  path: test/unittest/tadpole-array.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 12:42:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/tadpole-array.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/tadpole-array.test.cpp
- /verify/test/unittest/tadpole-array.test.cpp.html
title: test/unittest/tadpole-array.test.cpp
---
