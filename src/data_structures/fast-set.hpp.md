---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/fast-set.test.cpp
    title: test/unittest/data_structures/fast-set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/predecessor-problem.test.cpp
    title: test/yosupo/data_structure/predecessor-problem.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u306E\u96C6\u5408\
      \ (FastSet)"
    links: []
  bundledCode: "#line 2 \"src/data_structures/fast-set.hpp\"\n\n/**\n * @file fast-set.hpp\n\
    \ * @brief 64 \u5206\u6728\u306B\u3088\u308B\u6574\u6570\u306E\u96C6\u5408 (FastSet)\n\
    \ */\n\n#include <cassert>\n#include <cstdint>\n#include <vector>\n\n/**\n * @brief\
    \ [0, n) \u306E\u6574\u6570\u306E\u96C6\u5408\u3092 64 \u5206\u6728\u3067\u6301\
    \u3064\n *\n * \u5404\u6BB5\u306F 64 bit \u306E\u914D\u5217\u3067\u3001\u4E0A\u306E\
    \u6BB5\u306E bit \u306F\u4E0B\u306E\u6BB5\u306E 64 bit \u304C 0 \u3067\u306A\u3044\
    \u304B\u3092\u8868\u3059\n * \u633F\u5165\u30FB\u524A\u9664\u30FBx \u4EE5\u4E0A\
    \u306E\u6700\u5C0F\u30FBx \u4EE5\u4E0B\u306E\u6700\u5927\u3092 O(log_64 n) \u3067\
    \u884C\u3046 (n = 10^9 \u3067\u3082 5 \u6BB5\u7A0B\u5EA6)\n * \u4F8B:\n * FastSet\
    \ s(n);\n * s.insert(3); s.insert(10);\n * s.next(4);  // 10\n * s.prev(4);  //\
    \ 3\n */\nclass FastSet {\n    long long n, cnt = 0;\n    std::vector<std::vector<std::uint64_t>>\
    \ seg;  // seg[0] \u304C\u8981\u7D20\u306E bit\u3001seg[h + 1] \u306F seg[h] \u306E\
    \u5404 64 bit \u304C 0 \u3067\u306A\u3044\u304B\n\n    void build_levels() {\n\
    \        // 1 \u3064\u306E 64 bit \u306B\u53CE\u307E\u308B\u307E\u3067\u6BB5\u3092\
    \u91CD\u306D\u308B\n        do {\n            long long m = seg.empty() ? n :\
    \ static_cast<long long>(seg.back().size());\n            seg.emplace_back((m\
    \ + 63) / 64, 0);\n        } while (seg.back().size() > 1);\n    }\n\n   public:\n\
    \    /**\n     * @brief [0, n) \u306E\u7A7A\u306E\u96C6\u5408\n     */\n    explicit\
    \ FastSet(long long n = 0) : n(n) {\n        assert(n >= 0);\n        build_levels();\n\
    \    }\n    /**\n     * @brief v[i] \u304C true \u306E i \u304B\u3089\u306A\u308B\
    \u96C6\u5408 O(n)\n     */\n    explicit FastSet(const std::vector<bool>& v) :\
    \ FastSet(static_cast<long long>(v.size())) {\n        for (long long i = 0; i\
    \ < n; i++) {\n            if (v[i]) seg[0][i >> 6] |= std::uint64_t(1) << (i\
    \ & 63), cnt++;\n        }\n        for (int h = 0; h + 1 < static_cast<int>(seg.size());\
    \ h++) {\n            for (long long i = 0; i < static_cast<long long>(seg[h].size());\
    \ i++) {\n                if (seg[h][i]) seg[h + 1][i >> 6] |= std::uint64_t(1)\
    \ << (i & 63);\n            }\n        }\n    }\n\n    /**\n     * @brief \u6271\
    \u3048\u308B\u6574\u6570\u306E\u7BC4\u56F2 [0, n) \u306E n\n     */\n    long\
    \ long limit() const { return n; }\n    /**\n     * @brief \u8981\u7D20\u6570\n\
    \     */\n    long long size() const { return cnt; }\n    /**\n     * @brief \u7A7A\
    \u304B\n     */\n    bool empty() const { return cnt == 0; }\n\n    /**\n    \
    \ * @brief x \u304C\u542B\u307E\u308C\u308B\u304B O(1)\n     */\n    bool contains(long\
    \ long x) const {\n        assert(0 <= x && x < n);\n        return seg[0][x >>\
    \ 6] >> (x & 63) & 1;\n    }\n    /**\n     * @brief x \u306E\u500B\u6570 (0 \u304B\
    \ 1) O(1)\n     */\n    long long count(long long x) const { return contains(x);\
    \ }\n    /**\n     * @brief x \u3092\u633F\u5165\u3059\u308B\u3002\u65B0\u3057\
    \u304F\u5165\u3063\u305F\u3089 true O(log_64 n)\n     */\n    bool insert(long\
    \ long x) {\n        assert(0 <= x && x < n);\n        if (contains(x)) return\
    \ false;\n        cnt++;\n        for (auto& level : seg) {\n            level[x\
    \ >> 6] |= std::uint64_t(1) << (x & 63);\n            x >>= 6;\n        }\n  \
    \      return true;\n    }\n    /**\n     * @brief x \u3092\u524A\u9664\u3059\u308B\
    \u3002\u5165\u3063\u3066\u3044\u305F\u3089 true O(log_64 n)\n     */\n    bool\
    \ erase(long long x) {\n        assert(0 <= x && x < n);\n        if (!contains(x))\
    \ return false;\n        cnt--;\n        for (auto& level : seg) {\n         \
    \   level[x >> 6] &= ~(std::uint64_t(1) << (x & 63));\n            // \u540C\u3058\
    \ 64 bit \u306B\u4ED6\u306E\u8981\u7D20\u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\
    \u3001\u4E0A\u306E\u6BB5\u306F\u5909\u308F\u3089\u306A\u3044\n            if (level[x\
    \ >> 6]) break;\n            x >>= 6;\n        }\n        return true;\n    }\n\
    \n    /**\n     * @brief x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u306A\
    \u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long next(long long x) const\
    \ {\n        if (x < 0) x = 0;\n        if (x >= n) return -1;\n        for (int\
    \ h = 0; h < static_cast<int>(seg.size()); h++) {\n            if ((x >> 6) ==\
    \ static_cast<long long>(seg[h].size())) break;\n            std::uint64_t d =\
    \ seg[h][x >> 6] >> (x & 63);\n            if (!d) {\n                x = (x >>\
    \ 6) + 1;\n                continue;\n            }\n            // \u3053\u306E\
    \u6BB5\u3067\u898B\u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\
    \u3067\u306F\u6700\u3082\u5C0F\u3055\u3044 bit \u3092\u305F\u3069\u308B\n    \
    \        x += __builtin_ctzll(d);\n            for (int g = h - 1; g >= 0; g--)\
    \ {\n                x <<= 6;\n                x += __builtin_ctzll(seg[g][x >>\
    \ 6]);\n            }\n            return x;\n        }\n        return -1;\n\
    \    }\n    /**\n     * @brief x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20\
    \ (\u306A\u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long prev(long\
    \ long x) const {\n        if (x >= n) x = n - 1;\n        if (x < 0) return -1;\n\
    \        for (int h = 0; h < static_cast<int>(seg.size()); h++) {\n          \
    \  if (x == -1) break;\n            std::uint64_t d = seg[h][x >> 6] << (63 -\
    \ (x & 63));\n            if (!d) {\n                x = (x >> 6) - 1;\n     \
    \           continue;\n            }\n            // \u3053\u306E\u6BB5\u3067\u898B\
    \u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\
    \u3082\u5927\u304D\u3044 bit \u3092\u305F\u3069\u308B\n            x -= __builtin_clzll(d);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n  \
    \              x += 63 - __builtin_clzll(seg[g][x >> 6]);\n            }\n   \
    \         return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief\
    \ \u6700\u5C0F\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n\
    \    long long min() const { return next(0); }\n    /**\n     * @brief \u6700\u5927\
    \u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long long\
    \ max() const { return prev(n - 1); }\n\n    /**\n     * @brief \u8981\u7D20\u3092\
    \u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E O(size() log_64 n)\n     */\n\
    \    std::vector<long long> to_vector() const {\n        std::vector<long long>\
    \ res;\n        res.reserve(cnt);\n        for (long long x = next(0); x != -1;\
    \ x = next(x + 1)) res.push_back(x);\n        return res;\n    }\n    /**\n  \
    \   * @brief \u3059\u3079\u3066\u524A\u9664\u3059\u308B O(n / 64)\n     */\n \
    \   void clear() {\n        for (auto& level : seg) level.assign(level.size(),\
    \ 0);\n        cnt = 0;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file fast-set.hpp\n * @brief 64 \u5206\u6728\u306B\
    \u3088\u308B\u6574\u6570\u306E\u96C6\u5408 (FastSet)\n */\n\n#include <cassert>\n\
    #include <cstdint>\n#include <vector>\n\n/**\n * @brief [0, n) \u306E\u6574\u6570\
    \u306E\u96C6\u5408\u3092 64 \u5206\u6728\u3067\u6301\u3064\n *\n * \u5404\u6BB5\
    \u306F 64 bit \u306E\u914D\u5217\u3067\u3001\u4E0A\u306E\u6BB5\u306E bit \u306F\
    \u4E0B\u306E\u6BB5\u306E 64 bit \u304C 0 \u3067\u306A\u3044\u304B\u3092\u8868\u3059\
    \n * \u633F\u5165\u30FB\u524A\u9664\u30FBx \u4EE5\u4E0A\u306E\u6700\u5C0F\u30FB\
    x \u4EE5\u4E0B\u306E\u6700\u5927\u3092 O(log_64 n) \u3067\u884C\u3046 (n = 10^9\
    \ \u3067\u3082 5 \u6BB5\u7A0B\u5EA6)\n * \u4F8B:\n * FastSet s(n);\n * s.insert(3);\
    \ s.insert(10);\n * s.next(4);  // 10\n * s.prev(4);  // 3\n */\nclass FastSet\
    \ {\n    long long n, cnt = 0;\n    std::vector<std::vector<std::uint64_t>> seg;\
    \  // seg[0] \u304C\u8981\u7D20\u306E bit\u3001seg[h + 1] \u306F seg[h] \u306E\
    \u5404 64 bit \u304C 0 \u3067\u306A\u3044\u304B\n\n    void build_levels() {\n\
    \        // 1 \u3064\u306E 64 bit \u306B\u53CE\u307E\u308B\u307E\u3067\u6BB5\u3092\
    \u91CD\u306D\u308B\n        do {\n            long long m = seg.empty() ? n :\
    \ static_cast<long long>(seg.back().size());\n            seg.emplace_back((m\
    \ + 63) / 64, 0);\n        } while (seg.back().size() > 1);\n    }\n\n   public:\n\
    \    /**\n     * @brief [0, n) \u306E\u7A7A\u306E\u96C6\u5408\n     */\n    explicit\
    \ FastSet(long long n = 0) : n(n) {\n        assert(n >= 0);\n        build_levels();\n\
    \    }\n    /**\n     * @brief v[i] \u304C true \u306E i \u304B\u3089\u306A\u308B\
    \u96C6\u5408 O(n)\n     */\n    explicit FastSet(const std::vector<bool>& v) :\
    \ FastSet(static_cast<long long>(v.size())) {\n        for (long long i = 0; i\
    \ < n; i++) {\n            if (v[i]) seg[0][i >> 6] |= std::uint64_t(1) << (i\
    \ & 63), cnt++;\n        }\n        for (int h = 0; h + 1 < static_cast<int>(seg.size());\
    \ h++) {\n            for (long long i = 0; i < static_cast<long long>(seg[h].size());\
    \ i++) {\n                if (seg[h][i]) seg[h + 1][i >> 6] |= std::uint64_t(1)\
    \ << (i & 63);\n            }\n        }\n    }\n\n    /**\n     * @brief \u6271\
    \u3048\u308B\u6574\u6570\u306E\u7BC4\u56F2 [0, n) \u306E n\n     */\n    long\
    \ long limit() const { return n; }\n    /**\n     * @brief \u8981\u7D20\u6570\n\
    \     */\n    long long size() const { return cnt; }\n    /**\n     * @brief \u7A7A\
    \u304B\n     */\n    bool empty() const { return cnt == 0; }\n\n    /**\n    \
    \ * @brief x \u304C\u542B\u307E\u308C\u308B\u304B O(1)\n     */\n    bool contains(long\
    \ long x) const {\n        assert(0 <= x && x < n);\n        return seg[0][x >>\
    \ 6] >> (x & 63) & 1;\n    }\n    /**\n     * @brief x \u306E\u500B\u6570 (0 \u304B\
    \ 1) O(1)\n     */\n    long long count(long long x) const { return contains(x);\
    \ }\n    /**\n     * @brief x \u3092\u633F\u5165\u3059\u308B\u3002\u65B0\u3057\
    \u304F\u5165\u3063\u305F\u3089 true O(log_64 n)\n     */\n    bool insert(long\
    \ long x) {\n        assert(0 <= x && x < n);\n        if (contains(x)) return\
    \ false;\n        cnt++;\n        for (auto& level : seg) {\n            level[x\
    \ >> 6] |= std::uint64_t(1) << (x & 63);\n            x >>= 6;\n        }\n  \
    \      return true;\n    }\n    /**\n     * @brief x \u3092\u524A\u9664\u3059\u308B\
    \u3002\u5165\u3063\u3066\u3044\u305F\u3089 true O(log_64 n)\n     */\n    bool\
    \ erase(long long x) {\n        assert(0 <= x && x < n);\n        if (!contains(x))\
    \ return false;\n        cnt--;\n        for (auto& level : seg) {\n         \
    \   level[x >> 6] &= ~(std::uint64_t(1) << (x & 63));\n            // \u540C\u3058\
    \ 64 bit \u306B\u4ED6\u306E\u8981\u7D20\u304C\u6B8B\u3063\u3066\u3044\u308C\u3070\
    \u3001\u4E0A\u306E\u6BB5\u306F\u5909\u308F\u3089\u306A\u3044\n            if (level[x\
    \ >> 6]) break;\n            x >>= 6;\n        }\n        return true;\n    }\n\
    \n    /**\n     * @brief x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20 (\u306A\
    \u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long next(long long x) const\
    \ {\n        if (x < 0) x = 0;\n        if (x >= n) return -1;\n        for (int\
    \ h = 0; h < static_cast<int>(seg.size()); h++) {\n            if ((x >> 6) ==\
    \ static_cast<long long>(seg[h].size())) break;\n            std::uint64_t d =\
    \ seg[h][x >> 6] >> (x & 63);\n            if (!d) {\n                x = (x >>\
    \ 6) + 1;\n                continue;\n            }\n            // \u3053\u306E\
    \u6BB5\u3067\u898B\u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\
    \u3067\u306F\u6700\u3082\u5C0F\u3055\u3044 bit \u3092\u305F\u3069\u308B\n    \
    \        x += __builtin_ctzll(d);\n            for (int g = h - 1; g >= 0; g--)\
    \ {\n                x <<= 6;\n                x += __builtin_ctzll(seg[g][x >>\
    \ 6]);\n            }\n            return x;\n        }\n        return -1;\n\
    \    }\n    /**\n     * @brief x \u4EE5\u4E0B\u306E\u6700\u5927\u306E\u8981\u7D20\
    \ (\u306A\u3051\u308C\u3070 -1) O(log_64 n)\n     */\n    long long prev(long\
    \ long x) const {\n        if (x >= n) x = n - 1;\n        if (x < 0) return -1;\n\
    \        for (int h = 0; h < static_cast<int>(seg.size()); h++) {\n          \
    \  if (x == -1) break;\n            std::uint64_t d = seg[h][x >> 6] << (63 -\
    \ (x & 63));\n            if (!d) {\n                x = (x >> 6) - 1;\n     \
    \           continue;\n            }\n            // \u3053\u306E\u6BB5\u3067\u898B\
    \u3064\u304B\u3063\u305F\u306E\u3067\u3001\u4E0B\u306E\u6BB5\u3067\u306F\u6700\
    \u3082\u5927\u304D\u3044 bit \u3092\u305F\u3069\u308B\n            x -= __builtin_clzll(d);\n\
    \            for (int g = h - 1; g >= 0; g--) {\n                x <<= 6;\n  \
    \              x += 63 - __builtin_clzll(seg[g][x >> 6]);\n            }\n   \
    \         return x;\n        }\n        return -1;\n    }\n    /**\n     * @brief\
    \ \u6700\u5C0F\u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n\
    \    long long min() const { return next(0); }\n    /**\n     * @brief \u6700\u5927\
    \u306E\u8981\u7D20 (\u7A7A\u306A\u3089 -1) O(log_64 n)\n     */\n    long long\
    \ max() const { return prev(n - 1); }\n\n    /**\n     * @brief \u8981\u7D20\u3092\
    \u6607\u9806\u306B\u4E26\u3079\u305F\u3082\u306E O(size() log_64 n)\n     */\n\
    \    std::vector<long long> to_vector() const {\n        std::vector<long long>\
    \ res;\n        res.reserve(cnt);\n        for (long long x = next(0); x != -1;\
    \ x = next(x + 1)) res.push_back(x);\n        return res;\n    }\n    /**\n  \
    \   * @brief \u3059\u3079\u3066\u524A\u9664\u3059\u308B O(n / 64)\n     */\n \
    \   void clear() {\n        for (auto& level : seg) level.assign(level.size(),\
    \ 0);\n        cnt = 0;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/fast-set.hpp
  requiredBy: []
  timestamp: '2026-10-20 00:24:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/fast-set.test.cpp
  - test/yosupo/data_structure/predecessor-problem.test.cpp
documentation_of: src/data_structures/fast-set.hpp
layout: document
title: "64 \u5206\u6728 (FastSet)"
---

$[0, n)$ の整数の集合を 64 分木で持ちます。挿入・削除・$x$ 以上の最小の要素・$x$ 以下の最大の要素を $O(\log_{64} n)$ で求めます。$n = 10^6$ なら 4 段、$n = 10^9$ でも 5 段なので、`std::set` よりかなり速く動きます。値の範囲が決まっている整数の集合で、`std::set` の `lower_bound` の代わりに使います。

```cpp
FastSet s(n);
s.insert(3);
s.insert(10);
long long a = s.next(4);  // 10 (4 以上の最小)
long long b = s.prev(4);  // 3 (4 以下の最大)
long long c = s.next(11); // -1 (なし)
s.erase(10);
```

各段は 64 bit の配列で、一番下の段の bit が要素を、上の段の bit は 1 つ下の段の 64 bit が 0 でないかを表します。上の段で 0 でない場所を見つけてから下の段へ降りるので、空いている範囲を 64 個ずつ飛ばせます。

## メンバ関数

値は `long long` です。要素がないときは `-1` を返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `FastSet(n = 0)` | $[0, n)$ の空の集合 | $O(n / 64)$ |
| `FastSet(v)` | `std::vector<bool>` `v` で `v[i]` が `true` の `i` からなる集合 ($n$ は `v.size()`) | $O(n)$ |
| `limit()` | 扱える範囲 $[0, n)$ の $n$ | $O(1)$ |
| `size()` / `empty()` | 要素数 / 空か | $O(1)$ |
| `contains(x)` / `count(x)` | `x` が含まれるか / `x` の個数 (0 か 1) | $O(1)$ |
| `insert(x)` | `x` を挿入する。新しく入ったら `true` | $O(\log_{64} n)$ |
| `erase(x)` | `x` を削除する。入っていたら `true` | $O(\log_{64} n)$ |
| `next(x)` | `x` 以上の最小の要素 (なければ `-1`)。`x` は範囲の外 (負や $n$ 以上) でもよい | $O(\log_{64} n)$ |
| `prev(x)` | `x` 以下の最大の要素 (なければ `-1`)。`x` は範囲の外でもよい | $O(\log_{64} n)$ |
| `min()` / `max()` | 最小 / 最大の要素 (空なら `-1`) | $O(\log_{64} n)$ |
| `to_vector()` | 要素を昇順に並べたもの | $O(\mathrm{size} \cdot \log_{64} n)$ |
| `clear()` | すべて削除する | $O(n / 64)$ |

`insert`、`erase`、`contains` に渡す `x` は $0 \le x < n$ である必要があります。メモリは約 $n / 8$ バイトです ($n = 10^9$ で約 125 MB)。

## 関連

- 値の範囲が大きい・負の値がある・重複がある場合は、座標圧縮してから使うか `std::set` / `std::multiset`
- 区間ごとにまとめた集合 (区間の追加・削除) なら [区間の集合](interval-set.hpp)
- 0 以上の整数の集合で mex を求めるなら [mex](mex-update.hpp)
