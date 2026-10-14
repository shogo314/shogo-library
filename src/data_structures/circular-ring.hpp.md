---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/circular-ring.test.cpp
    title: test/unittest/circular-ring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5186\u74B0"
    links: []
  bundledCode: "#line 2 \"src/data_structures/circular-ring.hpp\"\n\n/**\n * @file\
    \ circular-ring.hpp\n * @brief \u5186\u74B0\n */\n\n#include <cassert>\n#include\
    \ <cstddef>\n#include <vector>\n\n/**\n * @brief \u5186\u74B0\n * @tparam T\n\
    \ */\ntemplate <typename T>\nstruct CircularRing {\n    std::vector<T> data;\n\
    \    explicit CircularRing(const std::vector<T>& v) : data(v) {}\n    CircularRing(const\
    \ CircularRing&) = default;\n    CircularRing() = default;\n    explicit CircularRing(int\
    \ s) : data(s) {}\n    T at(long long i) const {\n        assert(!data.empty());\n\
    \        i %= static_cast<long long>(data.size());\n        if (i < 0) i += static_cast<long\
    \ long>(data.size());\n        return data[i];\n    }\n    T& at(long long i)\
    \ {\n        assert(!data.empty());\n        i %= static_cast<long long>(data.size());\n\
    \        if (i < 0) i += static_cast<long long>(data.size());\n        return\
    \ data[i];\n    }\n    T operator[](long long i) const {\n        return at(i);\n\
    \    }\n    T& operator[](long long i) {\n        return at(i);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file circular-ring.hpp\n * @brief \u5186\u74B0\n\
    \ */\n\n#include <cassert>\n#include <cstddef>\n#include <vector>\n\n/**\n * @brief\
    \ \u5186\u74B0\n * @tparam T\n */\ntemplate <typename T>\nstruct CircularRing\
    \ {\n    std::vector<T> data;\n    explicit CircularRing(const std::vector<T>&\
    \ v) : data(v) {}\n    CircularRing(const CircularRing&) = default;\n    CircularRing()\
    \ = default;\n    explicit CircularRing(int s) : data(s) {}\n    T at(long long\
    \ i) const {\n        assert(!data.empty());\n        i %= static_cast<long long>(data.size());\n\
    \        if (i < 0) i += static_cast<long long>(data.size());\n        return\
    \ data[i];\n    }\n    T& at(long long i) {\n        assert(!data.empty());\n\
    \        i %= static_cast<long long>(data.size());\n        if (i < 0) i += static_cast<long\
    \ long>(data.size());\n        return data[i];\n    }\n    T operator[](long long\
    \ i) const {\n        return at(i);\n    }\n    T& operator[](long long i) {\n\
    \        return at(i);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/circular-ring.hpp
  requiredBy: []
  timestamp: '2026-10-14 16:36:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/circular-ring.test.cpp
documentation_of: src/data_structures/circular-ring.hpp
layout: document
title: "\u5186\u74B0"
---

添字を長さで割った余りでアクセスできる配列です。負の添字も使えます。

```cpp
CircularRing<int> r(std::vector<int>{10, 20, 30});
int a = r[3];    // 10
int b = r[-1];   // 30
r[-1] = 99;      // data = {10, 20, 99}
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CircularRing<T>(v)` | `v` で初期化 | $O(n)$ |
| `CircularRing<T>(n)` | 長さ `n` で、要素は `T()` | $O(n)$ |
| `r[i]` / `r.at(i)` | $i \bmod n$ 番目の要素 (`long long` の添字、負でもよい) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `data` | 中身の `std::vector<T>` |

## 関連

- 途中からループする配列は [おたまじゃくし配列](tadpole-array.hpp)
