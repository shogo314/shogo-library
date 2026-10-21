---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/dp/slope-trick.test.cpp
    title: test/unittest/dp/slope-trick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Slope Trick
    links: []
  bundledCode: "#line 2 \"src/dp/slope-trick.hpp\"\n\n/**\n * @file slope-trick.hpp\n\
    \ * @brief Slope Trick\n */\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <functional>\n#include <limits>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief \u51F8\u306A\u533A\u5206\u7DDA\u5F62\u95A2\u6570\
    \ f \u3092\u3001\u50BE\u304D\u304C\u5909\u308F\u308B\u70B9\u306E\u591A\u91CD\u96C6\
    \u5408\u3068\u3057\u3066\u6301\u3064 (Slope Trick)\n *\n * \u6700\u5C0F\u5024\u3092\
    \u3068\u308B\u533A\u9593\u3088\u308A\u5DE6\u306E\u70B9\u3092 L (\u6700\u5927\u30D2\
    \u30FC\u30D7)\u3001\u53F3\u306E\u70B9\u3092 R (\u6700\u5C0F\u30D2\u30FC\u30D7\
    ) \u306B\u5165\u308C\u3001\u5E73\u884C\u79FB\u52D5\u306F\u307E\u3068\u3081\u3066\
    \u8DB3\u3059\n * \u306F\u3058\u3081\u306F f(x) = 0\n * \u4F8B:\n * SlopeTrick<long\
    \ long> st;\n * for (long long a : A) {\n *     st.prefix_min();  // \u975E\u6E1B\
    \u5C11\u306B\u3059\u308B\u306E\u3067\u3001\u524D\u306E\u5024\u4EE5\u4E0B\u306A\
    \u3089\u3069\u3053\u3067\u3082\u3088\u3044\n *     st.add_abs(a);\n * }\n * long\
    \ long cost = st.min();\n *\n * @tparam T \u5024\u306E\u578B (\u7B26\u53F7\u4ED8\
    \u304D\u6574\u6570)\n */\ntemplate <typename T>\nclass SlopeTrick {\n    T min_f\
    \ = 0, add_l = 0, add_r = 0;\n    std::priority_queue<T> L;\n    std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>> R;\n\n    void push_l(T a) { L.push(a - add_l);\
    \ }\n    void push_r(T a) { R.push(a - add_r); }\n    T top_l() const { return\
    \ L.empty() ? -inf() : L.top() + add_l; }\n    T top_r() const { return R.empty()\
    \ ? inf() : R.top() + add_r; }\n    T pop_l() {\n        T a = top_l();\n    \
    \    L.pop();\n        return a;\n    }\n    T pop_r() {\n        T a = top_r();\n\
    \        R.pop();\n        return a;\n    }\n\n   public:\n    /**\n     * @brief\
    \ \u50BE\u304D\u304C\u5909\u308F\u3089\u306A\u3044\u5074\u306E\u7AEF\u3092\u8868\
    \u3059\u5024 std::numeric_limits<T>::max() / 4\n     */\n    static constexpr\
    \ T inf() { return std::numeric_limits<T>::max() / 4; }\n\n    /**\n     * @brief\
    \ f \u306E\u6700\u5C0F\u5024\n     */\n    T min() const { return min_f; }\n \
    \   /**\n     * @brief f \u304C\u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\
    \ [lower, upper]\u3002\u7AEF\u304C\u306A\u3051\u308C\u3070 -inf()\u3001inf()\n\
    \     */\n    std::pair<T, T> argmin() const { return {top_l(), top_r()}; }\n\
    \    /**\n     * @brief f \u306B\u5B9A\u6570 a \u3092\u8DB3\u3059\n     */\n \
    \   void add_constant(T a) { min_f += a; }\n    /**\n     * @brief f \u306B max(0,\
    \ x - a) \u3092\u8DB3\u3059 O(log n)\n     */\n    void add_x_minus_a(T a) {\n\
    \        min_f += std::max(T(0), top_l() - a);\n        push_l(a);\n        push_r(pop_l());\n\
    \    }\n    /**\n     * @brief f \u306B max(0, a - x) \u3092\u8DB3\u3059 O(log\
    \ n)\n     */\n    void add_a_minus_x(T a) {\n        min_f += std::max(T(0),\
    \ a - top_r());\n        push_r(a);\n        push_l(pop_r());\n    }\n    /**\n\
    \     * @brief f \u306B |x - a| \u3092\u8DB3\u3059 O(log n)\n     */\n    void\
    \ add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n    }\n\
    \    /**\n     * @brief f(x) \u3092 min_{y <= x} f(y) \u306B\u3059\u308B (\u53F3\
    \u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void prefix_min()\
    \ { R = {}; }\n    /**\n     * @brief f(x) \u3092 min_{y >= x} f(y) \u306B\u3059\
    \u308B (\u5DE6\u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void\
    \ suffix_min() { L = {}; }\n    /**\n     * @brief f(x) \u3092 min_{x - b <= y\
    \ <= x - a} f(y) \u306B\u3059\u308B (\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    ) O(1)\n     *\n     * \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3088\u308A\
    \u5DE6\u3092 a\u3001\u53F3\u3092 b \u3060\u3051\u53F3\u306B\u305A\u3089\u3059\u3002\
    a <= b \u3067\u3042\u308B\u3053\u3068\n     */\n    void shift(T a, T b) {\n \
    \       assert(a <= b);\n        add_l += a, add_r += b;\n    }\n    /**\n   \
    \  * @brief f(x) \u3092 f(x - a) \u306B\u3059\u308B (a \u3060\u3051\u53F3\u306B\
    \u305A\u3089\u3059) O(1)\n     */\n    void shift(T a) { shift(a, a); }\n    /**\n\
    \     * @brief f(x) \u306E\u5024 O(n log n)\n     */\n    T get(T x) const {\n\
    \        T res = min_f;\n        for (auto l = L; !l.empty(); l.pop()) res +=\
    \ std::max(T(0), l.top() + add_l - x);\n        for (auto r = R; !r.empty(); r.pop())\
    \ res += std::max(T(0), x - (r.top() + add_r));\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @file slope-trick.hpp\n * @brief Slope Trick\n */\n\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include <limits>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u51F8\
    \u306A\u533A\u5206\u7DDA\u5F62\u95A2\u6570 f \u3092\u3001\u50BE\u304D\u304C\u5909\
    \u308F\u308B\u70B9\u306E\u591A\u91CD\u96C6\u5408\u3068\u3057\u3066\u6301\u3064\
    \ (Slope Trick)\n *\n * \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3088\
    \u308A\u5DE6\u306E\u70B9\u3092 L (\u6700\u5927\u30D2\u30FC\u30D7)\u3001\u53F3\u306E\
    \u70B9\u3092 R (\u6700\u5C0F\u30D2\u30FC\u30D7) \u306B\u5165\u308C\u3001\u5E73\
    \u884C\u79FB\u52D5\u306F\u307E\u3068\u3081\u3066\u8DB3\u3059\n * \u306F\u3058\u3081\
    \u306F f(x) = 0\n * \u4F8B:\n * SlopeTrick<long long> st;\n * for (long long a\
    \ : A) {\n *     st.prefix_min();  // \u975E\u6E1B\u5C11\u306B\u3059\u308B\u306E\
    \u3067\u3001\u524D\u306E\u5024\u4EE5\u4E0B\u306A\u3089\u3069\u3053\u3067\u3082\
    \u3088\u3044\n *     st.add_abs(a);\n * }\n * long long cost = st.min();\n *\n\
    \ * @tparam T \u5024\u306E\u578B (\u7B26\u53F7\u4ED8\u304D\u6574\u6570)\n */\n\
    template <typename T>\nclass SlopeTrick {\n    T min_f = 0, add_l = 0, add_r =\
    \ 0;\n    std::priority_queue<T> L;\n    std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> R;\n\n    void push_l(T a) { L.push(a - add_l); }\n    void\
    \ push_r(T a) { R.push(a - add_r); }\n    T top_l() const { return L.empty() ?\
    \ -inf() : L.top() + add_l; }\n    T top_r() const { return R.empty() ? inf()\
    \ : R.top() + add_r; }\n    T pop_l() {\n        T a = top_l();\n        L.pop();\n\
    \        return a;\n    }\n    T pop_r() {\n        T a = top_r();\n        R.pop();\n\
    \        return a;\n    }\n\n   public:\n    /**\n     * @brief \u50BE\u304D\u304C\
    \u5909\u308F\u3089\u306A\u3044\u5074\u306E\u7AEF\u3092\u8868\u3059\u5024 std::numeric_limits<T>::max()\
    \ / 4\n     */\n    static constexpr T inf() { return std::numeric_limits<T>::max()\
    \ / 4; }\n\n    /**\n     * @brief f \u306E\u6700\u5C0F\u5024\n     */\n    T\
    \ min() const { return min_f; }\n    /**\n     * @brief f \u304C\u6700\u5C0F\u5024\
    \u3092\u3068\u308B\u533A\u9593 [lower, upper]\u3002\u7AEF\u304C\u306A\u3051\u308C\
    \u3070 -inf()\u3001inf()\n     */\n    std::pair<T, T> argmin() const { return\
    \ {top_l(), top_r()}; }\n    /**\n     * @brief f \u306B\u5B9A\u6570 a \u3092\u8DB3\
    \u3059\n     */\n    void add_constant(T a) { min_f += a; }\n    /**\n     * @brief\
    \ f \u306B max(0, x - a) \u3092\u8DB3\u3059 O(log n)\n     */\n    void add_x_minus_a(T\
    \ a) {\n        min_f += std::max(T(0), top_l() - a);\n        push_l(a);\n  \
    \      push_r(pop_l());\n    }\n    /**\n     * @brief f \u306B max(0, a - x)\
    \ \u3092\u8DB3\u3059 O(log n)\n     */\n    void add_a_minus_x(T a) {\n      \
    \  min_f += std::max(T(0), a - top_r());\n        push_r(a);\n        push_l(pop_r());\n\
    \    }\n    /**\n     * @brief f \u306B |x - a| \u3092\u8DB3\u3059 O(log n)\n\
    \     */\n    void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n    /**\n     * @brief f(x) \u3092 min_{y <= x} f(y) \u306B\u3059\u308B\
    \ (\u53F3\u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void prefix_min()\
    \ { R = {}; }\n    /**\n     * @brief f(x) \u3092 min_{y >= x} f(y) \u306B\u3059\
    \u308B (\u5DE6\u5074\u3092\u5E73\u3089\u306B\u3059\u308B) O(1)\n     */\n    void\
    \ suffix_min() { L = {}; }\n    /**\n     * @brief f(x) \u3092 min_{x - b <= y\
    \ <= x - a} f(y) \u306B\u3059\u308B (\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024\
    ) O(1)\n     *\n     * \u6700\u5C0F\u5024\u3092\u3068\u308B\u533A\u9593\u3088\u308A\
    \u5DE6\u3092 a\u3001\u53F3\u3092 b \u3060\u3051\u53F3\u306B\u305A\u3089\u3059\u3002\
    a <= b \u3067\u3042\u308B\u3053\u3068\n     */\n    void shift(T a, T b) {\n \
    \       assert(a <= b);\n        add_l += a, add_r += b;\n    }\n    /**\n   \
    \  * @brief f(x) \u3092 f(x - a) \u306B\u3059\u308B (a \u3060\u3051\u53F3\u306B\
    \u305A\u3089\u3059) O(1)\n     */\n    void shift(T a) { shift(a, a); }\n    /**\n\
    \     * @brief f(x) \u306E\u5024 O(n log n)\n     */\n    T get(T x) const {\n\
    \        T res = min_f;\n        for (auto l = L; !l.empty(); l.pop()) res +=\
    \ std::max(T(0), l.top() + add_l - x);\n        for (auto r = R; !r.empty(); r.pop())\
    \ res += std::max(T(0), x - (r.top() + add_r));\n        return res;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/dp/slope-trick.hpp
  requiredBy: []
  timestamp: '2026-10-22 04:34:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/dp/slope-trick.test.cpp
documentation_of: src/dp/slope-trick.hpp
layout: document
title: Slope Trick
---

凸な区分線形関数 $f$ を、傾きが変わる点の多重集合として持ちます (Slope Trick)。$f$ に $\lvert x - a \rvert$ などを足す操作と、累積の最小値をとる操作・平行移動が速くできるので、値の動かし方を状態にする DP を速くするのに使います。はじめは $f(x) = 0$ です。

```cpp
// 列 A を非減少な列 B に変える最小コスト Σ|A_i - B_i|
SlopeTrick<long long> st;
for (long long a : A) {
    st.prefix_min();  // B_{i-1} 以上なら B_i はどこでもよい: f(x) を min_{y <= x} f(y) にする
    st.add_abs(a);    // |x - A_i| を足す
}
long long cost = st.min();
```

狭義単調増加にしたいときは、$A_i - i$ を非減少にする問題に直して使います。

最小値をとる区間より左の点を最大ヒープ、右の点を最小ヒープに入れ、平行移動の量はまとめて持ちます。$n$ は今までに足した関数の個数です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SlopeTrick<T>()` | $f(x) = 0$ (`T` は符号付き整数) | $O(1)$ |
| `min()` | $f$ の最小値 | $O(1)$ |
| `argmin()` | $f$ が最小値をとる区間 $[\mathit{lower}, \mathit{upper}]$ (`std::pair`)。端がなければ `-inf()`、`inf()` | $O(1)$ |
| `get(x)` | $f(x)$ | $O(n \log n)$ |
| `add_constant(a)` | $f$ に $a$ を足す | $O(1)$ |
| `add_x_minus_a(a)` | $f$ に $\max(0, x - a)$ を足す | $O(\log n)$ |
| `add_a_minus_x(a)` | $f$ に $\max(0, a - x)$ を足す | $O(\log n)$ |
| `add_abs(a)` | $f$ に $\lvert x - a \rvert$ を足す | $O(\log n)$ |
| `prefix_min()` | $f(x)$ を $\min_{y \le x} f(y)$ にする | $O(1)$ |
| `suffix_min()` | $f(x)$ を $\min_{y \ge x} f(y)$ にする | $O(1)$ |
| `shift(a, b)` | $f(x)$ を $\min_{x - b \le y \le x - a} f(y)$ にする ($a \le b$)。最小値をとる区間より左を $a$、右を $b$ だけ右にずらす | $O(1)$ |
| `shift(a)` | $f(x)$ を $f(x - a)$ にする | $O(1)$ |
| `inf()` | 端がないことを表す値 `std::numeric_limits<T>::max() / 4` (static) | $O(1)$ |

## 関連

- 凸関数どうしの (min, +) 畳み込みは [Monge 性を使う DP の高速化](monge.hpp) の `min_plus_convolution_convex_convex`
