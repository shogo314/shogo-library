---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line-add-get-min.test.cpp
    title: test/yosupo/line-add-get-min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment-add-get-min.test.cpp
    title: test/yosupo/segment-add-get-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 2 \"src/data_structures/convex-hull-trick.hpp\"\n\n/**\n * @file\
    \ convex-hull-trick.hpp\n * @brief Convex Hull Trick\n *\n * \u4E00\u6B21\u95A2\
    \u6570\u3067\u8868\u3055\u308C\u308B\u76F4\u7DDA\u307E\u305F\u306F\u7DDA\u5206\
    \u306E\u96C6\u5408\u3092\u7BA1\u7406\u3057\u3001\u3042\u308Bx\u306B\u5BFE\u3059\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n */\n\n#include <cassert>\n\
    #include <cstddef>\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u8FFD\u52A0\u3055\u308C\u308B\u50BE\u304D\
    \u304C\u5358\u8ABF\u3068\u306F\u9650\u3089\u306A\u3044\u5834\u5408\u306EConvex\
    \ Hull Trick\n *\n * @tparam T \u5024\u306E\u578B\n */\ntemplate <typename T,\
    \ std::enable_if_t<std::is_scalar_v<T>, std::nullptr_t> = nullptr>\nclass LiChaoTree\
    \ {\n    int n, sz, height;\n    std::vector<T> xs, as, bs;\n    std::vector<bool>\
    \ exist;  // \u30CE\u30FC\u30C9\u304C\u76F4\u7DDA\u3092\u6301\u3064\u304B\n\n\
    \    void update(T a, T b, int k, int h) {\n        int l = (k << h) & (sz - 1);\n\
    \        int r = l + (1 << h);\n        \n        while(1) {\n            if(!exist[k])\
    \ {\n                as[k] = a, bs[k] = b, exist[k] = true;\n                return;\n\
    \            }\n            int m = (l + r) >> 1;\n            T xl = xs[l], xm\
    \ = xs[m];\n            bool l_update = a*xl + b < as[k]*xl + bs[k];\n       \
    \     bool m_update = a*xm + b < as[k]*xm + bs[k];\n\n            if(m_update)\
    \ {\n                std::swap(as[k], a);\n                std::swap(bs[k], b);\n\
    \            }\n            if(h == 0) break;\n            if(l_update != m_update)\
    \ {\n                k = k*2;\n                r = m;\n            } else {\n\
    \                k = k*2+1;\n                l = m;\n            }\n         \
    \   h--;\n        }\n    }\n\npublic:\n    /**\n     * @brief \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF\n     *\n     * @param xs \u6700\u5C0F\u5024\u30AF\u30A8\
    \u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\
    \u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\
    \u30C8\u3057\u305F\u914D\u5217\n     */\n    LiChaoTree(const std::vector<T>&\
    \ xs) : n(xs.size()), xs(xs) {\n        assert(!xs.empty());\n        sz = 1,\
    \ height = 0;\n        while(sz < (int)xs.size()) {\n            sz <<= 1;\n \
    \           height++;\n        }\n        this->xs.resize(sz, xs.back());\n  \
    \      as.assign(sz*2, 0);\n        bs.assign(sz*2, 0);\n        exist.assign(sz*2,\
    \ false);\n    }\n\n    /**\n     * @brief \u76F4\u7DDAy=ax+b\u306E\u8FFD\u52A0\
    \n     *\n     * @param a \u50BE\u304D\n     * @param b \u5207\u7247\n     */\n\
    \    void add_line(T a, T b) {\n        update(a, b, 1, height);\n    }\n    /**\n\
    \     * @brief \u7DDA\u5206y=ax+b , x\u2208[xs[l],xs[r])\u306E\u8FFD\u52A0\n \
    \    *\n     * @param a \u50BE\u304D\n     * @param b \u5207\u7247\n     * @param\
    \ l \u5DE6\u7AEF(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n     * @param\
    \ r x\u306E\u4E0A\u9650(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n     */\n\
    \    void add_segment(T a, T b, int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= n);\n        if(l == r) return;\n        l += sz, r += sz;\n     \
    \   int h = 0;\n        while(l < r) {\n            if(l & 1) update(a, b, l++,\
    \ h);\n            if(r & 1) update(a, b, --r, h);\n            l >>= 1, r >>=\
    \ 1, h++;\n        }\n    }\n\n    /**\n     * @brief x=xs[i]\u306B\u304A\u3051\
    \u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n     *\n     * @param i x\u5EA7\
    \u6A19(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n     * @return std::optional<T>\
    \ \u6700\u5C0F\u5024\u3002\u76F4\u7DDA\u304C\u306A\u3051\u308C\u3070 std::nullopt\n\
    \     */\n    std::optional<T> get_min(int i) const {\n        assert(0 <= i &&\
    \ i < n);\n        T x = xs[i];\n        std::optional<T> res;\n        for(int\
    \ k = i + sz; k >= 1; k >>= 1) {\n            if(!exist[k]) continue;\n      \
    \      T tmp = as[k]*x + bs[k];\n            if(!res || tmp < *res) res = tmp;\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file convex-hull-trick.hpp\n * @brief Convex Hull\
    \ Trick\n *\n * \u4E00\u6B21\u95A2\u6570\u3067\u8868\u3055\u308C\u308B\u76F4\u7DDA\
    \u307E\u305F\u306F\u7DDA\u5206\u306E\u96C6\u5408\u3092\u7BA1\u7406\u3057\u3001\
    \u3042\u308Bx\u306B\u5BFE\u3059\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\
    \n */\n\n#include <cassert>\n#include <cstddef>\n#include <optional>\n#include\
    \ <type_traits>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u8FFD\
    \u52A0\u3055\u308C\u308B\u50BE\u304D\u304C\u5358\u8ABF\u3068\u306F\u9650\u3089\
    \u306A\u3044\u5834\u5408\u306EConvex Hull Trick\n *\n * @tparam T \u5024\u306E\
    \u578B\n */\ntemplate <typename T, std::enable_if_t<std::is_scalar_v<T>, std::nullptr_t>\
    \ = nullptr>\nclass LiChaoTree {\n    int n, sz, height;\n    std::vector<T> xs,\
    \ as, bs;\n    std::vector<bool> exist;  // \u30CE\u30FC\u30C9\u304C\u76F4\u7DDA\
    \u3092\u6301\u3064\u304B\n\n    void update(T a, T b, int k, int h) {\n      \
    \  int l = (k << h) & (sz - 1);\n        int r = l + (1 << h);\n        \n   \
    \     while(1) {\n            if(!exist[k]) {\n                as[k] = a, bs[k]\
    \ = b, exist[k] = true;\n                return;\n            }\n            int\
    \ m = (l + r) >> 1;\n            T xl = xs[l], xm = xs[m];\n            bool l_update\
    \ = a*xl + b < as[k]*xl + bs[k];\n            bool m_update = a*xm + b < as[k]*xm\
    \ + bs[k];\n\n            if(m_update) {\n                std::swap(as[k], a);\n\
    \                std::swap(bs[k], b);\n            }\n            if(h == 0) break;\n\
    \            if(l_update != m_update) {\n                k = k*2;\n          \
    \      r = m;\n            } else {\n                k = k*2+1;\n            \
    \    l = m;\n            }\n            h--;\n        }\n    }\n\npublic:\n  \
    \  /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n   \
    \  * @param xs \u6700\u5C0F\u5024\u30AF\u30A8\u30EA\u306Ex\u5EA7\u6A19\u3084\u7DDA\
    \u5206\u8FFD\u52A0\u30AF\u30A8\u30EA\u306E\u4E21\u7AEF\u306Ex\u5EA7\u6A19\u3092\
    \u5148\u8AAD\u307F\u3057\u3066\u30BD\u30FC\u30C8\u3057\u305F\u914D\u5217\n   \
    \  */\n    LiChaoTree(const std::vector<T>& xs) : n(xs.size()), xs(xs) {\n   \
    \     assert(!xs.empty());\n        sz = 1, height = 0;\n        while(sz < (int)xs.size())\
    \ {\n            sz <<= 1;\n            height++;\n        }\n        this->xs.resize(sz,\
    \ xs.back());\n        as.assign(sz*2, 0);\n        bs.assign(sz*2, 0);\n    \
    \    exist.assign(sz*2, false);\n    }\n\n    /**\n     * @brief \u76F4\u7DDA\
    y=ax+b\u306E\u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param\
    \ b \u5207\u7247\n     */\n    void add_line(T a, T b) {\n        update(a, b,\
    \ 1, height);\n    }\n    /**\n     * @brief \u7DDA\u5206y=ax+b , x\u2208[xs[l],xs[r])\u306E\
    \u8FFD\u52A0\n     *\n     * @param a \u50BE\u304D\n     * @param b \u5207\u7247\
    \n     * @param l \u5DE6\u7AEF(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n\
    \     * @param r x\u306E\u4E0A\u9650(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    )\n     */\n    void add_segment(T a, T b, int l, int r) {\n        assert(0 <=\
    \ l && l <= r && r <= n);\n        if(l == r) return;\n        l += sz, r += sz;\n\
    \        int h = 0;\n        while(l < r) {\n            if(l & 1) update(a, b,\
    \ l++, h);\n            if(r & 1) update(a, b, --r, h);\n            l >>= 1,\
    \ r >>= 1, h++;\n        }\n    }\n\n    /**\n     * @brief x=xs[i]\u306B\u304A\
    \u3051\u308B\u6700\u5C0F\u5024\u3092\u6C42\u3081\u308B\n     *\n     * @param\
    \ i x\u5EA7\u6A19(xs\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9)\n     * @return\
    \ std::optional<T> \u6700\u5C0F\u5024\u3002\u76F4\u7DDA\u304C\u306A\u3051\u308C\
    \u3070 std::nullopt\n     */\n    std::optional<T> get_min(int i) const {\n  \
    \      assert(0 <= i && i < n);\n        T x = xs[i];\n        std::optional<T>\
    \ res;\n        for(int k = i + sz; k >= 1; k >>= 1) {\n            if(!exist[k])\
    \ continue;\n            T tmp = as[k]*x + bs[k];\n            if(!res || tmp\
    \ < *res) res = tmp;\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/convex-hull-trick.hpp
  requiredBy: []
  timestamp: '2026-10-14 07:01:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment-add-get-min.test.cpp
  - test/yosupo/line-add-get-min.test.cpp
documentation_of: src/data_structures/convex-hull-trick.hpp
layout: document
title: Convex Hull Trick
---

直線・線分を追加し、ある $x$ での最小値を求める Li Chao Tree `LiChaoTree<T>` です。追加する傾きは単調でなくてもかまいません。

使う $x$ 座標 (最小値を求める $x$ と、線分の両端) を先読みしてソートした配列を渡し、以降は $x$ をその配列の添字で指定します。

```cpp
std::vector<long long> xs = {-2, 0, 1, 5};
LiChaoTree<long long> cht(xs);
cht.add_line(1, 0);             // y = x
cht.add_segment(-1, 3, 1, 3);   // y = -x + 3 (x ∈ [xs[1], xs[3]) = [0, 5))
*cht.get_min(2);                // x = xs[2] = 1 での最小値: 1
```

最大値を求めたい場合は、傾きと切片の符号を反転して追加し、結果の符号を戻します。

## メンバ関数

$n$ を `xs` の長さとします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LiChaoTree(xs)` | ソート済みの $x$ 座標の配列から作る | $O(n)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log n)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [\mathrm{xs}_l, \mathrm{xs}_r)$) を追加 | $O(\log^2 n)$ |
| `get_min(i)` | $x = \mathrm{xs}_i$ での最小値 (`std::optional<T>`)。$x = \mathrm{xs}_i$ を含む直線・線分がなければ `std::nullopt` | $O(\log n)$ |
