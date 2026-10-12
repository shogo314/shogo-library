---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"src/data_structures/tadpole-array.hpp\"\n\n/**\n * @file\
    \ tadpole-array.hpp\n * @brief \u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\
    \u5217\n */\n\n#include <cassert>\n#include <vector>\n/**\n * @brief \u304A\u305F\
    \u307E\u3058\u3083\u304F\u3057\u914D\u5217\n * \u7279\u5B9A\u306E\u4F4D\u7F6E\u3067\
    \u30EB\u30FC\u30D7\u3059\u308B\u69CB\u9020\n * @tparam T\n */\ntemplate <typename\
    \ T>\nstruct TadpoleArray {\n   private:\n    std::vector<T> data;\n    size_t\
    \ k;\n\n   public:\n    /**\n     * @brief \u6700\u5F8C\u306E\u6B21\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u304Ci\n     */\n    TadpoleArray(const std::vector<T>&\
    \ v, int i) : data(v) {\n        assert(0 <= i and i < static_cast<int>(data.size()));\n\
    \        k = static_cast<size_t>(i);\n    }\n    TadpoleArray() = default;\n \
    \   TadpoleArray(const TadpoleArray&) = default;\n    T at(size_t i) const {\n\
    \        if (i < k) return data[i];\n        return data[(i - k) % (data.size()\
    \ - k) + k];\n    }\n    T operator[](size_t i) const {\n        return at(i);\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file tadpole-array.hpp\n * @brief \u304A\u305F\u307E\
    \u3058\u3083\u304F\u3057\u914D\u5217\n */\n\n#include <cassert>\n#include <vector>\n\
    /**\n * @brief \u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217\n * \u7279\
    \u5B9A\u306E\u4F4D\u7F6E\u3067\u30EB\u30FC\u30D7\u3059\u308B\u69CB\u9020\n * @tparam\
    \ T\n */\ntemplate <typename T>\nstruct TadpoleArray {\n   private:\n    std::vector<T>\
    \ data;\n    size_t k;\n\n   public:\n    /**\n     * @brief \u6700\u5F8C\u306E\
    \u6B21\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304Ci\n     */\n    TadpoleArray(const\
    \ std::vector<T>& v, int i) : data(v) {\n        assert(0 <= i and i < static_cast<int>(data.size()));\n\
    \        k = static_cast<size_t>(i);\n    }\n    TadpoleArray() = default;\n \
    \   TadpoleArray(const TadpoleArray&) = default;\n    T at(size_t i) const {\n\
    \        if (i < k) return data[i];\n        return data[(i - k) % (data.size()\
    \ - k) + k];\n    }\n    T operator[](size_t i) const {\n        return at(i);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/tadpole-array.hpp
  requiredBy: []
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/tadpole-array.hpp
layout: document
title: "\u304A\u305F\u307E\u3058\u3083\u304F\u3057\u914D\u5217"
---

途中からループする無限列を表します (ρ 型、おたまじゃくしの形)。長さ $n$ の配列と、末尾の次に戻る位置 $i$ を与えると、`data[0], ..., data[n-1], data[i], ..., data[n-1], data[i], ...` という列になります。Functional Graph をたどったときの頂点列などに使えます。

```cpp
TadpoleArray<int> t(std::vector<int>{1, 2, 3, 4}, 1);  // 1 2 3 4 2 3 4 2 3 4 ...
int a = t[4];                 // 2
int b = t[1000000000000LL];   // 2
```

## メンバ

| メンバ | 説明 | 計算量 |
|---|---|---|
| `TadpoleArray<T>(v, i)` | 配列 `v` の末尾の次を `v[i]` にする ($0 \le i < n$) | $O(n)$ |
| `t[k]` / `t.at(k)` | 列の `k` 番目 (`size_t` の添字) | $O(1)$ |

## 関連

- 先頭からループする配列は [円環](circular-ring.hpp)
- [ファンクショナルグラフ](../graph/functional-graph.hpp)
