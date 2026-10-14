---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/counter-segtree.test.cpp
    title: test/unittest/counter-segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point-set-range-frequency.test.cpp
    title: test/yosupo/point-set-range-frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u533A\u9593\u5185\u306E\u5024\u306E\u500B\u6570\u3092\u6570\u3048\
      \u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 2 \"src/data_structures/counter-segtree.hpp\"\n\n/**\n * @file\
    \ counter-segtree.hpp\n * @brief \u533A\u9593\u5185\u306E\u5024\u306E\u500B\u6570\
    \u3092\u6570\u3048\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n */\n\n#include\
    \ <cassert>\n#include <map>\n#include <optional>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <typename T>\nclass CounterSegTree {\n   public:\n    using\
    \ key_type = T;\n    using mapped_type = int;\n\n   private:\n    int n, sz, height;\n\
    \    std::vector<std::map<key_type, mapped_type>> data;\n\n   public:\n    explicit\
    \ CounterSegTree(const std::vector<key_type>& v) {\n        n = v.size();\n  \
    \      sz = 1;\n        height = 0;\n        while (sz < n) {\n            sz\
    \ <<= 1;\n            height++;\n        }\n        data.assign(sz * 2, {});\n\
    \        for (int i = 0; i < n; i++) {\n            data[i + sz][v[i]] = 1;\n\
    \        }\n        for (int i = sz - 1; i > 0; i--) {\n            data[i] =\
    \ data[2 * i];\n            for (auto [s, c] : data[2 * i + 1]) {\n          \
    \      data[i][s] += c;\n            }\n        }\n    }\n    key_type get(int\
    \ k) const {\n        assert(0 <= k and k < n);\n        return data[k + sz].begin()->first;\n\
    \    }\n    void set(int k, const key_type& x) {\n        assert(0 <= k and k\
    \ < n);\n        k += sz;\n        key_type y = data[k].begin()->first;\n    \
    \    while (k > 0) {\n            auto itr = data[k].find(y);\n            if\
    \ (itr->second == 1) {\n                data[k].erase(itr);\n            } else\
    \ {\n                itr->second--;\n            }\n            data[k][x]++;\n\
    \            k >>= 1;\n        }\n    }\n    /**\n     * @brief \u533A\u9593 [l,\
    \ r) \u3067 x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3068\u305D\u306E\u500B\
    \u6570\u3002\u306A\u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<std::pair<key_type,\
    \ mapped_type>> lower_bound(int l, int r, key_type x) const {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        std::pair<key_type, mapped_type> ret =\
    \ {{}, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n    \
    \        if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n  \
    \              if (itr != data[l].end()) {\n                    if (ret.second\
    \ == 0) {\n                        ret = *itr;\n                    } else if\
    \ (itr->first == ret.first) {\n                        ret.second += itr->second;\n\
    \                    } else if (itr->first < ret.first) {\n                  \
    \      ret = *itr;\n                    }\n                }\n               \
    \ ++l;\n            }\n            if (r & 1) {\n                --r;\n      \
    \          auto itr = data[r].lower_bound(x);\n                if (itr != data[r].end())\
    \ {\n                    if (ret.second == 0) {\n                        ret =\
    \ *itr;\n                    } else if (itr->first == ret.first) {\n         \
    \               ret.second += itr->second;\n                    } else if (itr->first\
    \ < ret.first) {\n                        ret = *itr;\n                    }\n\
    \                }\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        if (ret.second == 0) return std::nullopt;\n        return\
    \ ret;\n    }\n    /**\n     * @brief {x, \u533A\u9593 [l, r) \u306E x \u306E\u500B\
    \u6570}\n     */\n    std::pair<key_type, mapped_type> find(int l, int r, key_type\
    \ x) const {\n        assert(0 <= l and l <= r and r <= n);\n        std::pair<key_type,\
    \ mapped_type> ret = {x, 0};\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                auto itr = data[l].find(x);\n\
    \                if (itr != data[l].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n                ++l;\n            }\n     \
    \       if (r & 1) {\n                --r;\n                auto itr = data[r].find(x);\n\
    \                if (itr != data[r].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n            }\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file counter-segtree.hpp\n * @brief \u533A\u9593\
    \u5185\u306E\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\n */\n\n#include <cassert>\n#include <map>\n#include <optional>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T>\nclass CounterSegTree\
    \ {\n   public:\n    using key_type = T;\n    using mapped_type = int;\n\n   private:\n\
    \    int n, sz, height;\n    std::vector<std::map<key_type, mapped_type>> data;\n\
    \n   public:\n    explicit CounterSegTree(const std::vector<key_type>& v) {\n\
    \        n = v.size();\n        sz = 1;\n        height = 0;\n        while (sz\
    \ < n) {\n            sz <<= 1;\n            height++;\n        }\n        data.assign(sz\
    \ * 2, {});\n        for (int i = 0; i < n; i++) {\n            data[i + sz][v[i]]\
    \ = 1;\n        }\n        for (int i = sz - 1; i > 0; i--) {\n            data[i]\
    \ = data[2 * i];\n            for (auto [s, c] : data[2 * i + 1]) {\n        \
    \        data[i][s] += c;\n            }\n        }\n    }\n    key_type get(int\
    \ k) const {\n        assert(0 <= k and k < n);\n        return data[k + sz].begin()->first;\n\
    \    }\n    void set(int k, const key_type& x) {\n        assert(0 <= k and k\
    \ < n);\n        k += sz;\n        key_type y = data[k].begin()->first;\n    \
    \    while (k > 0) {\n            auto itr = data[k].find(y);\n            if\
    \ (itr->second == 1) {\n                data[k].erase(itr);\n            } else\
    \ {\n                itr->second--;\n            }\n            data[k][x]++;\n\
    \            k >>= 1;\n        }\n    }\n    /**\n     * @brief \u533A\u9593 [l,\
    \ r) \u3067 x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3068\u305D\u306E\u500B\
    \u6570\u3002\u306A\u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<std::pair<key_type,\
    \ mapped_type>> lower_bound(int l, int r, key_type x) const {\n        assert(0\
    \ <= l and l <= r and r <= n);\n        std::pair<key_type, mapped_type> ret =\
    \ {{}, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n    \
    \        if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n  \
    \              if (itr != data[l].end()) {\n                    if (ret.second\
    \ == 0) {\n                        ret = *itr;\n                    } else if\
    \ (itr->first == ret.first) {\n                        ret.second += itr->second;\n\
    \                    } else if (itr->first < ret.first) {\n                  \
    \      ret = *itr;\n                    }\n                }\n               \
    \ ++l;\n            }\n            if (r & 1) {\n                --r;\n      \
    \          auto itr = data[r].lower_bound(x);\n                if (itr != data[r].end())\
    \ {\n                    if (ret.second == 0) {\n                        ret =\
    \ *itr;\n                    } else if (itr->first == ret.first) {\n         \
    \               ret.second += itr->second;\n                    } else if (itr->first\
    \ < ret.first) {\n                        ret = *itr;\n                    }\n\
    \                }\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        if (ret.second == 0) return std::nullopt;\n        return\
    \ ret;\n    }\n    /**\n     * @brief {x, \u533A\u9593 [l, r) \u306E x \u306E\u500B\
    \u6570}\n     */\n    std::pair<key_type, mapped_type> find(int l, int r, key_type\
    \ x) const {\n        assert(0 <= l and l <= r and r <= n);\n        std::pair<key_type,\
    \ mapped_type> ret = {x, 0};\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                auto itr = data[l].find(x);\n\
    \                if (itr != data[l].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n                ++l;\n            }\n     \
    \       if (r & 1) {\n                --r;\n                auto itr = data[r].find(x);\n\
    \                if (itr != data[r].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n            }\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/counter-segtree.hpp
  requiredBy: []
  timestamp: '2026-10-14 07:01:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/counter-segtree.test.cpp
  - test/yosupo/point-set-range-frequency.test.cpp
documentation_of: src/data_structures/counter-segtree.hpp
layout: document
title: "\u533A\u9593\u5185\u306E\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\u30BB\
  \u30B0\u30E1\u30F3\u30C8\u6728"
---

各ノードに部分列の値の個数 (`std::map`) を持つセグメント木です。1点更新と、区間内の特定の値の個数・`x` 以上の最小の値を求められます。

```cpp
CounterSegTree<int> cs({3, 1, 3, 2, 3});
cs.find(0, 4, 3);         // {3, 2}: [0, 4) に 3 は 2 個
*cs.lower_bound(1, 5, 2); // {2, 1}: [1, 5) で 2 以上の最小の値は 2 で、1 個
cs.set(2, 5);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CounterSegTree(v)` | 列 `v` から作る | $O(n \log^2 n)$ |
| `get(k)` | `k` 番目の値 | $O(1)$ |
| `set(k, x)` | `k` 番目を `x` に更新 | $O(\log^2 n)$ |
| `find(l, r, x)` | `{x, 区間 [l, r) の x の個数}` | $O(\log^2 n)$ |
| `lower_bound(l, r, x)` | 区間 $[l, r)$ で `x` 以上の最小の値と、その個数の `pair` (`std::optional`)。なければ `std::nullopt` | $O(\log^2 n)$ |

メモリは $O(n \log n)$ 使います。
