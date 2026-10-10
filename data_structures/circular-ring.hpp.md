---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5186\u74B0"
    links: []
  bundledCode: "#line 2 \"data_structures/circular-ring.hpp\"\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @brief \u5186\u74B0\n * @tparam T \n */\ntemplate\
    \ <typename T>\nstruct CircularRing {\n    std::vector<T> data;\n    CircularRing(const\
    \ std::vector<T>& v) : data(v) {}\n    CircularRing(const CircularRing&) = default;\n\
    \    CircularRing() = default;\n    CircularRing(size_t s) : data(s) {}\n    T\
    \ at(long long i) const {\n        assert(!data.empty());\n        i %= static_cast<long\
    \ long>(data.size());\n        if (i < 0) i += static_cast<long long>(data.size());\n\
    \        return data[i];\n    }\n    T& at(long long i) {\n        assert(!data.empty());\n\
    \        i %= static_cast<long long>(data.size());\n        if (i < 0) i += static_cast<long\
    \ long>(data.size());\n        return data[i];\n    }\n    T operator[](long long\
    \ i) const {\n        return at(i);\n    }\n    T& operator[](long long i) {\n\
    \        return at(i);\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\n/**\n * @brief \u5186\
    \u74B0\n * @tparam T \n */\ntemplate <typename T>\nstruct CircularRing {\n   \
    \ std::vector<T> data;\n    CircularRing(const std::vector<T>& v) : data(v) {}\n\
    \    CircularRing(const CircularRing&) = default;\n    CircularRing() = default;\n\
    \    CircularRing(size_t s) : data(s) {}\n    T at(long long i) const {\n    \
    \    assert(!data.empty());\n        i %= static_cast<long long>(data.size());\n\
    \        if (i < 0) i += static_cast<long long>(data.size());\n        return\
    \ data[i];\n    }\n    T& at(long long i) {\n        assert(!data.empty());\n\
    \        i %= static_cast<long long>(data.size());\n        if (i < 0) i += static_cast<long\
    \ long>(data.size());\n        return data[i];\n    }\n    T operator[](long long\
    \ i) const {\n        return at(i);\n    }\n    T& operator[](long long i) {\n\
    \        return at(i);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/circular-ring.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/circular-ring.hpp
layout: document
redirect_from:
- /library/data_structures/circular-ring.hpp
- /library/data_structures/circular-ring.hpp.html
title: "\u5186\u74B0"
---
