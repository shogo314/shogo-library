---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4E0A\u4F4D K \u500B\u306E\u5024\u3068\u305D\u306E\u500B\u6570"
    links: []
  bundledCode: "#line 2 \"src/data_structures/priority_counter.hpp\"\n\n/**\n * @file\
    \ priority_counter.hpp\n * @brief \u4E0A\u4F4D K \u500B\u306E\u5024\u3068\u305D\
    \u306E\u500B\u6570\n */\n\n#include <array>\n#include <cstddef>\n#include <functional>\n\
    #include <map>\n#include <type_traits>\n#include <utility>\n\ntemplate <typename\
    \ T, size_t K = 1, class Compare = std::less<T>, std::enable_if_t<(K >= 1), std::nullptr_t>\
    \ = nullptr>\nstruct PriorityCounter {\n    using key_type = T;\n    using mapped_type\
    \ = long long;\n    using value_type = std::pair<key_type, mapped_type>;\n   \
    \ inline constexpr static size_t k = K;\n\n    std::array<value_type, K> data;\n\
    \n    constexpr PriorityCounter() {\n        for (size_t i = 0; i < k; i++) {\n\
    \            data[i].second = 0;\n        }\n    }\n    constexpr PriorityCounter(const\
    \ key_type& x) : PriorityCounter() {\n        data[0].first = x;\n        data[0].second\
    \ = 1;\n    }\n\n    constexpr size_t size() const {\n        for (size_t i =\
    \ 0; i < k; i++) {\n            if (data[i].second == 0) {\n                return\
    \ i;\n            }\n        }\n        return k;\n    }\n\n    constexpr void\
    \ inc(const key_type& x, const mapped_type& c = 1) {\n        bool f = false;\n\
    \        key_type pre_key;\n        mapped_type pre_mapped;\n        for (size_t\
    \ i = 0; i < k; i++) {\n            if (f) {\n                std::swap(pre_key,\
    \ data[i].first);\n                std::swap(pre_mapped, data[i].second);\n  \
    \              continue;\n            }\n            if (data[i].second == 0)\
    \ {\n                data[i].first = x;\n                data[i].second += c;\n\
    \                return;\n            }\n            if (Compare()(data[i].first,\
    \ x)) {\n                pre_key = data[i].first;\n                pre_mapped\
    \ = data[i].second;\n                data[i].first = x;\n                data[i].second\
    \ = c;\n                f = true;\n            } else if (not Compare()(x, data[i].first))\
    \ {\n                data[i].second += c;\n                return;\n         \
    \   }\n        }\n    }\n\n    constexpr PriorityCounter& operator+=(const PriorityCounter&\
    \ o) {\n        for (size_t i = 0; i < k; i++) {\n            if (o.data[i].second\
    \ == 0) break;\n            this->inc(o.data[i].first, o.data[i].second);\n  \
    \      }\n        return *this;\n    }\n    constexpr friend PriorityCounter operator+(const\
    \ PriorityCounter& a, const PriorityCounter& b) {\n        PriorityCounter res(a);\n\
    \        return res += b;\n    }\n};\n\ntemplate <typename T, size_t K = 1>\n\
    using MaxCounter = PriorityCounter<T, K>;\n\ntemplate <typename T, size_t K =\
    \ 1>\nusing MinCounter = PriorityCounter<T, K, std::greater<T>>;\n"
  code: "#pragma once\n\n/**\n * @file priority_counter.hpp\n * @brief \u4E0A\u4F4D\
    \ K \u500B\u306E\u5024\u3068\u305D\u306E\u500B\u6570\n */\n\n#include <array>\n\
    #include <cstddef>\n#include <functional>\n#include <map>\n#include <type_traits>\n\
    #include <utility>\n\ntemplate <typename T, size_t K = 1, class Compare = std::less<T>,\
    \ std::enable_if_t<(K >= 1), std::nullptr_t> = nullptr>\nstruct PriorityCounter\
    \ {\n    using key_type = T;\n    using mapped_type = long long;\n    using value_type\
    \ = std::pair<key_type, mapped_type>;\n    inline constexpr static size_t k =\
    \ K;\n\n    std::array<value_type, K> data;\n\n    constexpr PriorityCounter()\
    \ {\n        for (size_t i = 0; i < k; i++) {\n            data[i].second = 0;\n\
    \        }\n    }\n    constexpr PriorityCounter(const key_type& x) : PriorityCounter()\
    \ {\n        data[0].first = x;\n        data[0].second = 1;\n    }\n\n    constexpr\
    \ size_t size() const {\n        for (size_t i = 0; i < k; i++) {\n          \
    \  if (data[i].second == 0) {\n                return i;\n            }\n    \
    \    }\n        return k;\n    }\n\n    constexpr void inc(const key_type& x,\
    \ const mapped_type& c = 1) {\n        bool f = false;\n        key_type pre_key;\n\
    \        mapped_type pre_mapped;\n        for (size_t i = 0; i < k; i++) {\n \
    \           if (f) {\n                std::swap(pre_key, data[i].first);\n   \
    \             std::swap(pre_mapped, data[i].second);\n                continue;\n\
    \            }\n            if (data[i].second == 0) {\n                data[i].first\
    \ = x;\n                data[i].second += c;\n                return;\n      \
    \      }\n            if (Compare()(data[i].first, x)) {\n                pre_key\
    \ = data[i].first;\n                pre_mapped = data[i].second;\n           \
    \     data[i].first = x;\n                data[i].second = c;\n              \
    \  f = true;\n            } else if (not Compare()(x, data[i].first)) {\n    \
    \            data[i].second += c;\n                return;\n            }\n  \
    \      }\n    }\n\n    constexpr PriorityCounter& operator+=(const PriorityCounter&\
    \ o) {\n        for (size_t i = 0; i < k; i++) {\n            if (o.data[i].second\
    \ == 0) break;\n            this->inc(o.data[i].first, o.data[i].second);\n  \
    \      }\n        return *this;\n    }\n    constexpr friend PriorityCounter operator+(const\
    \ PriorityCounter& a, const PriorityCounter& b) {\n        PriorityCounter res(a);\n\
    \        return res += b;\n    }\n};\n\ntemplate <typename T, size_t K = 1>\n\
    using MaxCounter = PriorityCounter<T, K>;\n\ntemplate <typename T, size_t K =\
    \ 1>\nusing MinCounter = PriorityCounter<T, K, std::greater<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/priority_counter.hpp
  requiredBy: []
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/data_structures/priority_counter.hpp
layout: document
title: "\u4E0A\u4F4D K \u500B\u306E\u5024\u3068\u305D\u306E\u500B\u6570"
---

値を追加していき、大きい方から K 種類の値とそれぞれの個数だけを保持します。`+` で2つを合わせられるので、セグメント木に乗せて「区間の最大値とその個数」「区間で2番目に大きい値」などを求めるのに使えます。

```cpp
MaxCounter<int, 2> pc;                 // 大きい方から 2 種類
for (int x : {3, 5, 1, 5, 4}) pc.inc(x);
// pc.data = { {5, 2}, {4, 1} }

MaxCounter<int> a(3), b(3);
auto c = a + b;                        // c.data[0] = {3, 2}
```

## 型

| 型 | 説明 |
|---|---|
| `PriorityCounter<T, K = 1, Compare = std::less<T>>` | `Compare` で大きい方から K 種類を保持 |
| `MaxCounter<T, K = 1>` | 大きい方から K 種類 |
| `MinCounter<T, K = 1>` | 小さい方から K 種類 |

## メンバ

| メンバ | 説明 | 計算量 |
|---|---|---|
| `PriorityCounter()` | 空 | $O(K)$ |
| `PriorityCounter(x)` | 値 `x` が 1 個 | $O(K)$ |
| `inc(x, c = 1)` | 値 `x` を `c` 個追加する。上位 K 種類に入らなければ捨てる | $O(K)$ |
| `a + b`、`a += b` | 合わせる | $O(K^2)$ |
| `size()` | 保持している値の種類数 (K 以下) | $O(K)$ |
| `data[i]` | 上位から `i` 番目の `{値, 個数}`。`i >= size()` では個数が 0 | |

値は追加されるだけなので、上位 K 種類から外れた値が再び上位に入ることはありません。そのため、追加の順番によらず上位 K 種類とその個数は正しく求まります。`c` は正の値にしてください (個数を減らす使い方はできません)。
