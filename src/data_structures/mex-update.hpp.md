---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/mex-update.test.cpp
    title: test/unittest/mex-update.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\u5F97"
    links: []
  bundledCode: "#line 2 \"src/data_structures/mex-update.hpp\"\n\n/**\n * @file mex-update.hpp\n\
    \ * @brief 1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\u5F97\n */\n\
    \n#include <cassert>\n#include <limits>\n#include <map>\n#include <set>\n#include\
    \ <type_traits>\n#include <vector>\n\ntemplate <typename T>\nclass MexUpdate {\n\
    \    static_assert(std::is_integral_v<T>, \"MexUpdate: T must be an integer type\"\
    );\n\n   public:\n    using value_type = T;\n\n   private:\n    inline constexpr\
    \ static value_type e = std::numeric_limits<value_type>::max();\n\n    long long\
    \ n;\n    std::vector<value_type> v;\n    std::set<int> s;\n    std::map<int,\
    \ int> m;\n\n    // x \u304C 0 \u4EE5\u4E0A n \u4EE5\u4E0B\u304B (T \u304C\u7B26\
    \u53F7\u306A\u3057\u3067\u3082\u8B66\u544A\u304C\u51FA\u306A\u3044\u3088\u3046\
    \u306B\u6BD4\u3079\u308B)\n    bool in_range(const value_type& x) const {\n  \
    \      if constexpr (std::is_signed_v<value_type>) {\n            if (x < 0) return\
    \ false;\n        }\n        return static_cast<unsigned long long>(x) <= static_cast<unsigned\
    \ long long>(n);\n    }\n\n   public:\n    MexUpdate() = default;\n    explicit\
    \ MexUpdate(long long n) : n(n), v(n, e) {\n        assert(n > 0);\n        assert(static_cast<unsigned\
    \ long long>(n) + 1 < static_cast<unsigned long long>(e));\n        std::set<int>::iterator\
    \ hint = s.end();\n        for (long long i = n; i >= 0; --i) {\n            hint\
    \ = s.emplace_hint(hint, static_cast<int>(i));\n        }\n    }\n    explicit\
    \ MexUpdate(const std::vector<value_type>& init) : n(init.size()), v(init) {\n\
    \        assert(n > 0);\n        assert(static_cast<unsigned long long>(n) + 1\
    \ < static_cast<unsigned long long>(e));\n        std::set<int>::iterator hint\
    \ = s.end();\n        for (long long i = n; i >= 0; --i) {\n            hint =\
    \ s.emplace_hint(hint, static_cast<int>(i));\n        }\n        for (const auto&\
    \ i : init) {\n            if (in_range(i)) {\n                m[i]++;\n     \
    \           s.erase(i);\n            }\n        }\n    }\n    void set(long long\
    \ k, const value_type& x) {\n        assert(0 <= k && k < n);\n        if (in_range(v[k]))\
    \ {\n            int v_k = v[k];\n            auto itr = m.find(v_k);\n      \
    \      if (itr->second > 1) {\n                itr->second--;\n            } else\
    \ {\n                m.erase(itr);\n                s.insert(v_k);\n         \
    \   }\n        }\n        if (in_range(x)) {\n            int xx = x;\n      \
    \      auto itr = m.find(xx);\n            if (itr == m.end()) {\n           \
    \     m[xx]++;\n                s.erase(xx);\n            } else {\n         \
    \       itr->second++;\n            }\n        }\n        v[k] = x;\n    }\n \
    \   value_type mex() const {\n        return *s.begin();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file mex-update.hpp\n * @brief 1\u70B9\u66F4\u65B0\
    \u30FB\u5168\u4F53\u306E mex \u53D6\u5F97\n */\n\n#include <cassert>\n#include\
    \ <limits>\n#include <map>\n#include <set>\n#include <type_traits>\n#include <vector>\n\
    \ntemplate <typename T>\nclass MexUpdate {\n    static_assert(std::is_integral_v<T>,\
    \ \"MexUpdate: T must be an integer type\");\n\n   public:\n    using value_type\
    \ = T;\n\n   private:\n    inline constexpr static value_type e = std::numeric_limits<value_type>::max();\n\
    \n    long long n;\n    std::vector<value_type> v;\n    std::set<int> s;\n   \
    \ std::map<int, int> m;\n\n    // x \u304C 0 \u4EE5\u4E0A n \u4EE5\u4E0B\u304B\
    \ (T \u304C\u7B26\u53F7\u306A\u3057\u3067\u3082\u8B66\u544A\u304C\u51FA\u306A\u3044\
    \u3088\u3046\u306B\u6BD4\u3079\u308B)\n    bool in_range(const value_type& x)\
    \ const {\n        if constexpr (std::is_signed_v<value_type>) {\n           \
    \ if (x < 0) return false;\n        }\n        return static_cast<unsigned long\
    \ long>(x) <= static_cast<unsigned long long>(n);\n    }\n\n   public:\n    MexUpdate()\
    \ = default;\n    explicit MexUpdate(long long n) : n(n), v(n, e) {\n        assert(n\
    \ > 0);\n        assert(static_cast<unsigned long long>(n) + 1 < static_cast<unsigned\
    \ long long>(e));\n        std::set<int>::iterator hint = s.end();\n        for\
    \ (long long i = n; i >= 0; --i) {\n            hint = s.emplace_hint(hint, static_cast<int>(i));\n\
    \        }\n    }\n    explicit MexUpdate(const std::vector<value_type>& init)\
    \ : n(init.size()), v(init) {\n        assert(n > 0);\n        assert(static_cast<unsigned\
    \ long long>(n) + 1 < static_cast<unsigned long long>(e));\n        std::set<int>::iterator\
    \ hint = s.end();\n        for (long long i = n; i >= 0; --i) {\n            hint\
    \ = s.emplace_hint(hint, static_cast<int>(i));\n        }\n        for (const\
    \ auto& i : init) {\n            if (in_range(i)) {\n                m[i]++;\n\
    \                s.erase(i);\n            }\n        }\n    }\n    void set(long\
    \ long k, const value_type& x) {\n        assert(0 <= k && k < n);\n        if\
    \ (in_range(v[k])) {\n            int v_k = v[k];\n            auto itr = m.find(v_k);\n\
    \            if (itr->second > 1) {\n                itr->second--;\n        \
    \    } else {\n                m.erase(itr);\n                s.insert(v_k);\n\
    \            }\n        }\n        if (in_range(x)) {\n            int xx = x;\n\
    \            auto itr = m.find(xx);\n            if (itr == m.end()) {\n     \
    \           m[xx]++;\n                s.erase(xx);\n            } else {\n   \
    \             itr->second++;\n            }\n        }\n        v[k] = x;\n  \
    \  }\n    value_type mex() const {\n        return *s.begin();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/mex-update.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/mex-update.test.cpp
documentation_of: src/data_structures/mex-update.hpp
layout: document
title: "1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\u5F97"
---

長さ $n$ の数列について、1点更新と、全体の mex (含まれない最小の非負整数) の取得を行います。

```cpp
MexUpdate<int> mu(std::vector<int>{0, 1, 3});
int a = mu.mex();     // 2
mu.set(1, 5);         // {0, 5, 3}
int b = mu.mex();     // 1
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MexUpdate<T>(n)` | 長さ `n` で、どの要素もまだ値を持たない (mex は 0) | $O(n)$ |
| `MexUpdate<T>(v)` | `v` で初期化 | $O(n \log n)$ |
| `set(k, x)` | `k` 番目を `x` に更新 | $O(\log n)$ |
| `mex()` | 全体の mex | $O(1)$ |

`T` は整数型です (符号なしの型でもかまいません)。負の値や $n$ より大きい値も入れられます (mex には影響しません)。

## 関連

- 値ごとの個数を数えるなら [Counter](counter.hpp)
