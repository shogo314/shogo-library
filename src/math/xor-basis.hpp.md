---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/xor-basis.test.cpp
    title: test/unittest/xor-basis.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)"
    links: []
  bundledCode: "#line 2 \"src/math/xor-basis.hpp\"\n\n/**\n * @file xor-basis.hpp\n\
    \ * @brief XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)\n */\n\n\
    #include <cassert>\n#include <limits>\n#include <type_traits>\n#include <vector>\n\
    \n/**\n * @brief XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)\n\
    \ *\n * \u8FFD\u52A0\u3057\u305F\u5024\u306E XOR \u3067\u4F5C\u308C\u308B\u5024\
    \u306E\u96C6\u5408 (\u7DDA\u5F62\u7A7A\u9593) \u3092\u7BA1\u7406\u3059\u308B\u3002\
    \u5404\u64CD\u4F5C O(B) (B \u306F T \u306E\u30D3\u30C3\u30C8\u6570)\n * \u57FA\
    \u5E95\u306F\u3001\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C\u3059\u3079\u3066\
    \u7570\u306A\u308A\u3001\u5404\u57FA\u5E95\u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\
    \u30C8\u304C\u307B\u304B\u306E\u57FA\u5E95\u3067 0 \u306B\u306A\u308B\u5F62 (\u7C21\
    \u7D04\u3055\u308C\u305F\u5F62) \u306B\u4FDD\u3064\n * \u4F8B:\n * XorBasis<>\
    \ xb;\n * xb.add(5); xb.add(3);\n * xb.contains(6);  // true\n * xb.max();   \
    \     // 6\n *\n * @tparam T 64 \u30D3\u30C3\u30C8\u4EE5\u4E0B\u306E\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u578B\n */\ntemplate <typename T = unsigned long long>\n\
    class XorBasis {\n    static_assert(std::is_unsigned_v<T>, \"XorBasis: T must\
    \ be unsigned\");\n    static constexpr int B = std::numeric_limits<T>::digits;\n\
    \    static_assert(B <= 64, \"XorBasis: T must be at most 64 bits\");\n    T b[B]\
    \ = {};  // b[i] \u306F\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u306E\u57FA\
    \u5E95 (\u306A\u3051\u308C\u3070 0)\n    int r = 0;\n\npublic:\n    XorBasis()\
    \ = default;\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\u3002\
    x \u304C\u4ECA\u306E\u7A7A\u9593\u306B\u542B\u307E\u308C\u3066\u3044\u306A\u3051\
    \u308C\u3070 (\u57FA\u5E95\u304C\u5897\u3048\u308C\u3070) true\n     */\n    bool\
    \ add(T x) {\n        for (int i = B - 1; i >= 0; i--) {\n            if ((x >>\
    \ i & 1) && b[i]) x ^= b[i];\n        }\n        if (x == 0) return false;\n \
    \       int t = B - 1;\n        while (!(x >> t & 1)) t--;\n        // \u307B\u304B\
    \u306E\u57FA\u5E95\u304B\u3089\u3001\u30D3\u30C3\u30C8 t \u3092\u6D88\u3059\n\
    \        for (int i = t + 1; i < B; i++) {\n            if (b[i] >> t & 1) b[i]\
    \ ^= x;\n        }\n        b[t] = x;\n        r++;\n        return true;\n  \
    \  }\n\n    /**\n     * @brief \u57FA\u5E95\u306E\u500B\u6570 (\u7A7A\u9593\u306E\
    \u6B21\u5143)\u3002\u4F5C\u308C\u308B\u5024\u306F 2^rank() \u500B\n     */\n \
    \   int rank() const { return r; }\n\n    /**\n     * @brief x \u3092\u4F5C\u308C\
    \u308B\u304B\n     */\n    bool contains(T x) const { return min(x) == 0; }\n\n\
    \    /**\n     * @brief \u4F5C\u308C\u308B\u5024 y \u306B\u3064\u3044\u3066 x\
    \ ^ y \u306E\u6700\u5927\u5024 (x = 0 \u306A\u3089\u4F5C\u308C\u308B\u5024\u306E\
    \u6700\u5927\u5024)\n     */\n    T max(T x = 0) const {\n        for (int i =\
    \ B - 1; i >= 0; i--) {\n            if (b[i] && !(x >> i & 1)) x ^= b[i];\n \
    \       }\n        return x;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\
    \u5024 y \u306B\u3064\u3044\u3066 x ^ y \u306E\u6700\u5C0F\u5024 (x = 0 \u306A\
    \u3089 0)\n     */\n    T min(T x) const {\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            if (x >> i & 1) x ^= b[i];\n        }\n        return x;\n\
    \    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\u3046\u3061\u3001\
    \u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\u3002\
    k < 2^rank() \u3067\u3042\u308B\u3053\u3068\n     */\n    T kth(unsigned long\
    \ long k) const {\n        assert(r >= 64 || k < (1ULL << r));\n        T res\
    \ = 0;\n        for (int i = 0; i < B && k; i++) {\n            if (!b[i]) continue;\n\
    \            if (k & 1) res ^= b[i];\n            k >>= 1;\n        }\n      \
    \  return res;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\
    \u3046\u3061\u3001x \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306E\u500B\u6570\
    \ (kth \u306E\u9006)\n     */\n    unsigned long long count_less(T x) const {\n\
    \        // \u4F5C\u308C\u308B\u5024 y \u3092\u4E0A\u306E\u30D3\u30C3\u30C8\u304B\
    \u3089 x \u3068\u6BD4\u3079\u308B\u3002j \u306F\u307E\u3060\u9078\u3093\u3067\u3044\
    \u306A\u3044\u57FA\u5E95 (\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u672A\u6E80\
    ) \u306E\u500B\u6570\n        unsigned long long res = 0;\n        int j = r;\n\
    \        T y = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            if\
    \ (b[i]) {\n                // \u7C21\u7D04\u3055\u308C\u305F\u5F62\u306A\u306E\
    \u3067\u3001y \u306E\u30D3\u30C3\u30C8 i \u306F b[i] \u3092\u4F7F\u3046\u304B\u3069\
    \u3046\u304B\u3060\u3051\u3067\u6C7A\u307E\u308B\n                j--;\n     \
    \           if ((y >> i & 1) != (x >> i & 1)) y ^= b[i];\n                // \u30D3\
    \u30C3\u30C8 i \u3092 0 \u306B\u3057\u305F\u5074\u306E 2^j \u500B\u306F\u3001\u3059\
    \u3079\u3066 x \u3088\u308A\u5C0F\u3055\u3044\n                if (x >> i & 1)\
    \ res += 1ULL << j;\n            } else if ((y >> i & 1) != (x >> i & 1)) {\n\
    \                // \u30D3\u30C3\u30C8 i \u306F\u4E0A\u306E\u30D3\u30C3\u30C8\u306E\
    \u9078\u3073\u65B9\u3067\u6C7A\u307E\u3063\u3066\u3044\u3066\u3001\u3053\u3053\
    \u3067\u5927\u5C0F\u304C\u6C7A\u307E\u308B\n                if (x >> i & 1) res\
    \ += 1ULL << j;\n                return res;\n            }\n        }\n     \
    \   return res;\n    }\n\n    /**\n     * @brief \u57FA\u5E95 (\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u306E\u964D\u9806)\n     */\n    std::vector<T> basis() const\
    \ {\n        std::vector<T> res;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            if (b[i]) res.push_back(b[i]);\n        }\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file xor-basis.hpp\n * @brief XOR \u57FA\u5E95 (F2\
    \ \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)\n */\n\n#include <cassert>\n#include <limits>\n\
    #include <type_traits>\n#include <vector>\n\n/**\n * @brief XOR \u57FA\u5E95 (F2\
    \ \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)\n *\n * \u8FFD\u52A0\u3057\u305F\u5024\
    \u306E XOR \u3067\u4F5C\u308C\u308B\u5024\u306E\u96C6\u5408 (\u7DDA\u5F62\u7A7A\
    \u9593) \u3092\u7BA1\u7406\u3059\u308B\u3002\u5404\u64CD\u4F5C O(B) (B \u306F\
    \ T \u306E\u30D3\u30C3\u30C8\u6570)\n * \u57FA\u5E95\u306F\u3001\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u304C\u3059\u3079\u3066\u7570\u306A\u308A\u3001\u5404\u57FA\
    \u5E95\u306E\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C\u307B\u304B\u306E\u57FA\
    \u5E95\u3067 0 \u306B\u306A\u308B\u5F62 (\u7C21\u7D04\u3055\u308C\u305F\u5F62\
    ) \u306B\u4FDD\u3064\n * \u4F8B:\n * XorBasis<> xb;\n * xb.add(5); xb.add(3);\n\
    \ * xb.contains(6);  // true\n * xb.max();        // 6\n *\n * @tparam T 64 \u30D3\
    \u30C3\u30C8\u4EE5\u4E0B\u306E\u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n */\n\
    template <typename T = unsigned long long>\nclass XorBasis {\n    static_assert(std::is_unsigned_v<T>,\
    \ \"XorBasis: T must be unsigned\");\n    static constexpr int B = std::numeric_limits<T>::digits;\n\
    \    static_assert(B <= 64, \"XorBasis: T must be at most 64 bits\");\n    T b[B]\
    \ = {};  // b[i] \u306F\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u306E\u57FA\
    \u5E95 (\u306A\u3051\u308C\u3070 0)\n    int r = 0;\n\npublic:\n    XorBasis()\
    \ = default;\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\u3002\
    x \u304C\u4ECA\u306E\u7A7A\u9593\u306B\u542B\u307E\u308C\u3066\u3044\u306A\u3051\
    \u308C\u3070 (\u57FA\u5E95\u304C\u5897\u3048\u308C\u3070) true\n     */\n    bool\
    \ add(T x) {\n        for (int i = B - 1; i >= 0; i--) {\n            if ((x >>\
    \ i & 1) && b[i]) x ^= b[i];\n        }\n        if (x == 0) return false;\n \
    \       int t = B - 1;\n        while (!(x >> t & 1)) t--;\n        // \u307B\u304B\
    \u306E\u57FA\u5E95\u304B\u3089\u3001\u30D3\u30C3\u30C8 t \u3092\u6D88\u3059\n\
    \        for (int i = t + 1; i < B; i++) {\n            if (b[i] >> t & 1) b[i]\
    \ ^= x;\n        }\n        b[t] = x;\n        r++;\n        return true;\n  \
    \  }\n\n    /**\n     * @brief \u57FA\u5E95\u306E\u500B\u6570 (\u7A7A\u9593\u306E\
    \u6B21\u5143)\u3002\u4F5C\u308C\u308B\u5024\u306F 2^rank() \u500B\n     */\n \
    \   int rank() const { return r; }\n\n    /**\n     * @brief x \u3092\u4F5C\u308C\
    \u308B\u304B\n     */\n    bool contains(T x) const { return min(x) == 0; }\n\n\
    \    /**\n     * @brief \u4F5C\u308C\u308B\u5024 y \u306B\u3064\u3044\u3066 x\
    \ ^ y \u306E\u6700\u5927\u5024 (x = 0 \u306A\u3089\u4F5C\u308C\u308B\u5024\u306E\
    \u6700\u5927\u5024)\n     */\n    T max(T x = 0) const {\n        for (int i =\
    \ B - 1; i >= 0; i--) {\n            if (b[i] && !(x >> i & 1)) x ^= b[i];\n \
    \       }\n        return x;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\
    \u5024 y \u306B\u3064\u3044\u3066 x ^ y \u306E\u6700\u5C0F\u5024 (x = 0 \u306A\
    \u3089 0)\n     */\n    T min(T x) const {\n        for (int i = B - 1; i >= 0;\
    \ i--) {\n            if (x >> i & 1) x ^= b[i];\n        }\n        return x;\n\
    \    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\u3046\u3061\u3001\
    \u5C0F\u3055\u3044\u65B9\u304B\u3089 k \u756A\u76EE (0-indexed) \u306E\u5024\u3002\
    k < 2^rank() \u3067\u3042\u308B\u3053\u3068\n     */\n    T kth(unsigned long\
    \ long k) const {\n        assert(r >= 64 || k < (1ULL << r));\n        T res\
    \ = 0;\n        for (int i = 0; i < B && k; i++) {\n            if (!b[i]) continue;\n\
    \            if (k & 1) res ^= b[i];\n            k >>= 1;\n        }\n      \
    \  return res;\n    }\n\n    /**\n     * @brief \u4F5C\u308C\u308B\u5024\u306E\
    \u3046\u3061\u3001x \u3088\u308A\u5C0F\u3055\u3044\u3082\u306E\u306E\u500B\u6570\
    \ (kth \u306E\u9006)\n     */\n    unsigned long long count_less(T x) const {\n\
    \        // \u4F5C\u308C\u308B\u5024 y \u3092\u4E0A\u306E\u30D3\u30C3\u30C8\u304B\
    \u3089 x \u3068\u6BD4\u3079\u308B\u3002j \u306F\u307E\u3060\u9078\u3093\u3067\u3044\
    \u306A\u3044\u57FA\u5E95 (\u6700\u4E0A\u4F4D\u30D3\u30C3\u30C8\u304C i \u672A\u6E80\
    ) \u306E\u500B\u6570\n        unsigned long long res = 0;\n        int j = r;\n\
    \        T y = 0;\n        for (int i = B - 1; i >= 0; i--) {\n            if\
    \ (b[i]) {\n                // \u7C21\u7D04\u3055\u308C\u305F\u5F62\u306A\u306E\
    \u3067\u3001y \u306E\u30D3\u30C3\u30C8 i \u306F b[i] \u3092\u4F7F\u3046\u304B\u3069\
    \u3046\u304B\u3060\u3051\u3067\u6C7A\u307E\u308B\n                j--;\n     \
    \           if ((y >> i & 1) != (x >> i & 1)) y ^= b[i];\n                // \u30D3\
    \u30C3\u30C8 i \u3092 0 \u306B\u3057\u305F\u5074\u306E 2^j \u500B\u306F\u3001\u3059\
    \u3079\u3066 x \u3088\u308A\u5C0F\u3055\u3044\n                if (x >> i & 1)\
    \ res += 1ULL << j;\n            } else if ((y >> i & 1) != (x >> i & 1)) {\n\
    \                // \u30D3\u30C3\u30C8 i \u306F\u4E0A\u306E\u30D3\u30C3\u30C8\u306E\
    \u9078\u3073\u65B9\u3067\u6C7A\u307E\u3063\u3066\u3044\u3066\u3001\u3053\u3053\
    \u3067\u5927\u5C0F\u304C\u6C7A\u307E\u308B\n                if (x >> i & 1) res\
    \ += 1ULL << j;\n                return res;\n            }\n        }\n     \
    \   return res;\n    }\n\n    /**\n     * @brief \u57FA\u5E95 (\u6700\u4E0A\u4F4D\
    \u30D3\u30C3\u30C8\u306E\u964D\u9806)\n     */\n    std::vector<T> basis() const\
    \ {\n        std::vector<T> res;\n        for (int i = B - 1; i >= 0; i--) {\n\
    \            if (b[i]) res.push_back(b[i]);\n        }\n        return res;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/xor-basis.hpp
  requiredBy: []
  timestamp: '2026-10-14 01:43:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/xor-basis.test.cpp
documentation_of: src/math/xor-basis.hpp
layout: document
title: "XOR \u57FA\u5E95 (F2 \u4E0A\u306E\u7DDA\u5F62\u57FA\u5E95)"
---

追加した値をいくつか選んで XOR したときに作れる値の集合 (F2 上の線形空間) を管理する `XorBasis<T>` です。`T` は 64 ビット以下の符号なし整数型で、省略すると `unsigned long long` です。$B$ を `T` のビット数として、各操作は $O(B)$ です。

```cpp
XorBasis<> xb;
xb.add(5);           // true (基底が増えた)
xb.add(3);           // true
xb.add(6);           // false (5 ^ 3 なので作れる)
xb.contains(6);      // true
xb.rank();           // 2 (作れる値は 2^2 = 4 個: 0, 3, 5, 6)
xb.max();            // 6
xb.max(1);           // 7 (1 ^ 6)
xb.kth(2);           // 5 (小さい方から 0-indexed で 2 番目)
```

## メンバ

| メンバ | 説明 |
|---|---|
| `XorBasis<T>()` | 空の状態 (作れる値は 0 だけ) |
| `add(x)` | `x` を追加する。`x` がまだ作れない値なら (基底が増えたら) `true` |
| `rank()` | 基底の個数。作れる値は $2^{\mathrm{rank}}$ 個 (0 を含む) |
| `contains(x)` | `x` を作れるか |
| `max(x = 0)` | 作れる値 `y` についての `x ^ y` の最大値。`x = 0` なら作れる値の最大値 |
| `min(x)` | 作れる値 `y` についての `x ^ y` の最小値 |
| `kth(k)` | 作れる値のうち小さい方から `k` 番目 (0-indexed) の値。$k < 2^{\mathrm{rank}}$ であること |
| `count_less(x)` | 作れる値のうち `x` より小さいものの個数 (`kth` の逆) |
| `basis()` | 基底を最上位ビットの降順に並べたもの |

基底は、最上位ビットがすべて異なり、各基底の最上位ビットがほかの基底では 0 になる形 (簡約された形) に保っています。このため `kth(k)` は、`k` の $i$ ビット目が立っていれば最上位ビットが小さい方から $i$ 番目の基底を XOR したものになります。

- 「空でない部分集合の XOR」を考える問題では、`add` が `false` を返した (従属な値があった) かどうかで 0 を作れるかが変わることに注意してください。
- 符号付きの値を渡すときは `XorBasis<unsigned long long>` などにして、非負の値を渡します。
