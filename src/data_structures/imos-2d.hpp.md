---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl/dsl-5-b.test.cpp
    title: test/aoj/dsl/dsl-5-b.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/imos-2d.test.cpp
    title: test/unittest/data_structures/imos-2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5"
    links: []
  bundledCode: "#line 2 \"src/data_structures/imos-2d.hpp\"\n\n/**\n * @file imos-2d.hpp\n\
    \ * @brief 2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5\n */\n\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @brief 2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5\
    \ (\u9577\u65B9\u5F62\u3078\u306E\u52A0\u7B97\u3092\u305F\u3081\u3066\u304A\u304D\
    \u3001\u6700\u5F8C\u306B\u307E\u3068\u3081\u3066\u5404\u30DE\u30B9\u306E\u5024\
    \u3092\u6C42\u3081\u308B)\n *\n * add \u306F 4 \u9685\u306B\u8DB3\u3059\u3060\u3051\
    \u3067 O(1)\u3001build \u3067 2 \u65B9\u5411\u306E\u7D2F\u7A4D\u548C\u3092\u3068\
    \u3063\u3066 O(hw)\u3002build \u306E\u5F8C\u306F get \u3067\u5024\u3092\u8AAD\u3080\
    \n * \u4F8B:\n * Imos2D<int> imos(h, w);\n * imos.add(0, 0, 3, 2, 1);  // \u884C\
    \ [0, 3)\u3001\u5217 [0, 2) \u306B 1 \u3092\u8DB3\u3059\n * imos.build();\n *\
    \ int x = imos.get(1, 1);\n *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate\
    \ <typename T>\nclass Imos2D {\n    long long h, w;\n    std::vector<std::vector<T>>\
    \ a;  // (h + 1) \xD7 (w + 1)\n    bool built = false;\n\n   public:\n    /**\n\
    \     * @brief h \u884C w \u5217\u3067\u3001\u3059\u3079\u3066 0\n     */\n  \
    \  Imos2D(long long h, long long w) : h(h), w(w), a(h + 1, std::vector<T>(w +\
    \ 1, T(0))) {}\n    /**\n     * @brief \u884C\u6570\n     */\n    long long height()\
    \ const { return h; }\n    /**\n     * @brief \u5217\u6570\n     */\n    long\
    \ long width() const { return w; }\n    /**\n     * @brief \u884C [i1, i2)\u3001\
    \u5217 [j1, j2) \u306E\u30DE\u30B9\u306B x \u3092\u8DB3\u3059 O(1)\u3002build\
    \ \u306E\u524D\u306B\u9650\u308B\n     */\n    void add(long long i1, long long\
    \ j1, long long i2, long long j2, const T& x) {\n        assert(!built);\n   \
    \     assert(0 <= i1 && i1 <= i2 && i2 <= h && 0 <= j1 && j1 <= j2 && j2 <= w);\n\
    \        a[i1][j1] += x, a[i1][j2] -= x, a[i2][j1] -= x, a[i2][j2] += x;\n   \
    \ }\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u3092\u3068\u308A\u3001\u5404\u30DE\
    \u30B9\u306E\u5024\u3092\u6C42\u3081\u308B O(hw)\u30021 \u56DE\u3060\u3051\u547C\
    \u3076\n     */\n    void build() {\n        assert(!built);\n        built =\
    \ true;\n        for (long long i = 0; i <= h; i++)\n            for (long long\
    \ j = 1; j <= w; j++) a[i][j] += a[i][j - 1];\n        for (long long i = 1; i\
    \ <= h; i++)\n            for (long long j = 0; j <= w; j++) a[i][j] += a[i -\
    \ 1][j];\n    }\n    /**\n     * @brief \u30DE\u30B9 (i, j) \u306E\u5024 O(1)\u3002\
    build \u306E\u5F8C\u306B\u9650\u308B\n     */\n    T get(long long i, long long\
    \ j) const {\n        assert(built);\n        assert(0 <= i && i < h && 0 <= j\
    \ && j < w);\n        return a[i][j];\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file imos-2d.hpp\n * @brief 2 \u6B21\u5143\u306E\
    \u3044\u3082\u3059\u6CD5\n */\n\n#include <cassert>\n#include <vector>\n\n/**\n\
    \ * @brief 2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5 (\u9577\u65B9\u5F62\u3078\
    \u306E\u52A0\u7B97\u3092\u305F\u3081\u3066\u304A\u304D\u3001\u6700\u5F8C\u306B\
    \u307E\u3068\u3081\u3066\u5404\u30DE\u30B9\u306E\u5024\u3092\u6C42\u3081\u308B\
    )\n *\n * add \u306F 4 \u9685\u306B\u8DB3\u3059\u3060\u3051\u3067 O(1)\u3001build\
    \ \u3067 2 \u65B9\u5411\u306E\u7D2F\u7A4D\u548C\u3092\u3068\u3063\u3066 O(hw)\u3002\
    build \u306E\u5F8C\u306F get \u3067\u5024\u3092\u8AAD\u3080\n * \u4F8B:\n * Imos2D<int>\
    \ imos(h, w);\n * imos.add(0, 0, 3, 2, 1);  // \u884C [0, 3)\u3001\u5217 [0, 2)\
    \ \u306B 1 \u3092\u8DB3\u3059\n * imos.build();\n * int x = imos.get(1, 1);\n\
    \ *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename T>\nclass Imos2D\
    \ {\n    long long h, w;\n    std::vector<std::vector<T>> a;  // (h + 1) \xD7\
    \ (w + 1)\n    bool built = false;\n\n   public:\n    /**\n     * @brief h \u884C\
    \ w \u5217\u3067\u3001\u3059\u3079\u3066 0\n     */\n    Imos2D(long long h, long\
    \ long w) : h(h), w(w), a(h + 1, std::vector<T>(w + 1, T(0))) {}\n    /**\n  \
    \   * @brief \u884C\u6570\n     */\n    long long height() const { return h; }\n\
    \    /**\n     * @brief \u5217\u6570\n     */\n    long long width() const { return\
    \ w; }\n    /**\n     * @brief \u884C [i1, i2)\u3001\u5217 [j1, j2) \u306E\u30DE\
    \u30B9\u306B x \u3092\u8DB3\u3059 O(1)\u3002build \u306E\u524D\u306B\u9650\u308B\
    \n     */\n    void add(long long i1, long long j1, long long i2, long long j2,\
    \ const T& x) {\n        assert(!built);\n        assert(0 <= i1 && i1 <= i2 &&\
    \ i2 <= h && 0 <= j1 && j1 <= j2 && j2 <= w);\n        a[i1][j1] += x, a[i1][j2]\
    \ -= x, a[i2][j1] -= x, a[i2][j2] += x;\n    }\n    /**\n     * @brief \u7D2F\u7A4D\
    \u548C\u3092\u3068\u308A\u3001\u5404\u30DE\u30B9\u306E\u5024\u3092\u6C42\u3081\
    \u308B O(hw)\u30021 \u56DE\u3060\u3051\u547C\u3076\n     */\n    void build()\
    \ {\n        assert(!built);\n        built = true;\n        for (long long i\
    \ = 0; i <= h; i++)\n            for (long long j = 1; j <= w; j++) a[i][j] +=\
    \ a[i][j - 1];\n        for (long long i = 1; i <= h; i++)\n            for (long\
    \ long j = 0; j <= w; j++) a[i][j] += a[i - 1][j];\n    }\n    /**\n     * @brief\
    \ \u30DE\u30B9 (i, j) \u306E\u5024 O(1)\u3002build \u306E\u5F8C\u306B\u9650\u308B\
    \n     */\n    T get(long long i, long long j) const {\n        assert(built);\n\
    \        assert(0 <= i && i < h && 0 <= j && j < w);\n        return a[i][j];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/imos-2d.hpp
  requiredBy: []
  timestamp: '2026-10-22 05:52:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/imos-2d.test.cpp
  - test/aoj/dsl/dsl-5-b.test.cpp
documentation_of: src/data_structures/imos-2d.hpp
layout: document
title: "2 \u6B21\u5143\u306E\u3044\u3082\u3059\u6CD5"
---

$h$ 行 $w$ 列のグリッドで、長方形への加算をためておき、最後にまとめて各マスの値を求めます。加算は長方形の 4 隅に足すだけで $O(1)$、`build` で 2 方向の累積和をとって $O(hw)$ です。

```cpp
Imos2D<int> imos(4, 4);
imos.add(0, 0, 3, 2, 1);  // 行 [0, 3)、列 [0, 2) に 1 を足す
imos.add(2, 1, 4, 3, 1);
imos.build();
int x = imos.get(2, 1);   // 2 (2 つの長方形が重なる)
```

`add` は `build` の前に、`get` は `build` の後に呼びます (違えば assert で落ちます)。加算と取得を交互に行いたいなら、[2次元セグメント木](segtree-2d.hpp) などを使います。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Imos2D<T>(h, w)` | `h` 行 `w` 列で、すべて 0 | $O(hw)$ |
| `height()` / `width()` | 行数 / 列数 | $O(1)$ |
| `add(i1, j1, i2, j2, x)` | 行 $[i_1, i_2)$、列 $[j_1, j_2)$ のマスに `x` を足す (`build` の前) | $O(1)$ |
| `build()` | 累積和をとって各マスの値を求める (1 回だけ) | $O(hw)$ |
| `get(i, j)` | マス `(i, j)` の値 (`build` の後) | $O(1)$ |

## 関連

- 1 次元は [imos法で区間作用、1点取得](imos.hpp)
- 長方形の和集合の面積は [長方形の和集合の面積](../geometry/rectangle-union.hpp)
