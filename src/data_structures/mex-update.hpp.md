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
    \n#include <cassert>\n#include <cstddef>\n#include <limits>\n#include <map>\n\
    #include <set>\n#include <vector>\n\ntemplate <typename T>\nstruct MexUpdate {\n\
    \    using value_type = T;\n\n   private:\n    inline constexpr static value_type\
    \ e = std::numeric_limits<value_type>::max();\n\n    int n;\n    std::vector<value_type>\
    \ v;\n    std::set<int> s;\n    std::map<int, std::size_t> m;\n\n   public:\n\
    \    MexUpdate() = default;\n    MexUpdate(int n) : n(n), v(n, e) {\n        assert(n\
    \ > 0);\n        assert(n + 1 < e);\n        std::set<int>::iterator hint = s.end();\n\
    \        for (int i = n; i >= 0; --i) {\n            hint = s.emplace_hint(hint,\
    \ i);\n        }\n    }\n    MexUpdate(const std::vector<value_type>& init) :\
    \ n(init.size()), v(init) {\n        assert(n > 0);\n        assert(n + 1 < e);\n\
    \        std::set<int>::iterator hint = s.end();\n        for (int i = n; i >=\
    \ 0; --i) {\n            hint = s.emplace_hint(hint, i);\n        }\n        for\
    \ (const auto& i : init) {\n            if (0 <= i and i <= n) {\n           \
    \     m[i]++;\n                s.erase(i);\n            }\n        }\n    }\n\
    \    void set(int k, const value_type& x) {\n        assert(0 <= k and k < n);\n\
    \        if (0 <= v[k] and v[k] <= n) {\n            int v_k = v[k];\n       \
    \     auto itr = m.find(v_k);\n            if (itr->second > 1) {\n          \
    \      itr->second--;\n            } else {\n                m.erase(itr);\n \
    \               s.insert(v_k);\n            }\n        }\n        if (0 <= x and\
    \ x <= n) {\n            int xx = x;\n            auto itr = m.find(xx);\n   \
    \         if (itr == m.end()) {\n                m[xx]++;\n                s.erase(xx);\n\
    \            } else {\n                itr->second++;\n            }\n       \
    \ }\n        v[k] = x;\n    }\n    value_type prod() const {\n        return *s.begin();\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @file mex-update.hpp\n * @brief 1\u70B9\u66F4\u65B0\
    \u30FB\u5168\u4F53\u306E mex \u53D6\u5F97\n */\n\n#include <cassert>\n#include\
    \ <cstddef>\n#include <limits>\n#include <map>\n#include <set>\n#include <vector>\n\
    \ntemplate <typename T>\nstruct MexUpdate {\n    using value_type = T;\n\n   private:\n\
    \    inline constexpr static value_type e = std::numeric_limits<value_type>::max();\n\
    \n    int n;\n    std::vector<value_type> v;\n    std::set<int> s;\n    std::map<int,\
    \ std::size_t> m;\n\n   public:\n    MexUpdate() = default;\n    MexUpdate(int\
    \ n) : n(n), v(n, e) {\n        assert(n > 0);\n        assert(n + 1 < e);\n \
    \       std::set<int>::iterator hint = s.end();\n        for (int i = n; i >=\
    \ 0; --i) {\n            hint = s.emplace_hint(hint, i);\n        }\n    }\n \
    \   MexUpdate(const std::vector<value_type>& init) : n(init.size()), v(init) {\n\
    \        assert(n > 0);\n        assert(n + 1 < e);\n        std::set<int>::iterator\
    \ hint = s.end();\n        for (int i = n; i >= 0; --i) {\n            hint =\
    \ s.emplace_hint(hint, i);\n        }\n        for (const auto& i : init) {\n\
    \            if (0 <= i and i <= n) {\n                m[i]++;\n             \
    \   s.erase(i);\n            }\n        }\n    }\n    void set(int k, const value_type&\
    \ x) {\n        assert(0 <= k and k < n);\n        if (0 <= v[k] and v[k] <= n)\
    \ {\n            int v_k = v[k];\n            auto itr = m.find(v_k);\n      \
    \      if (itr->second > 1) {\n                itr->second--;\n            } else\
    \ {\n                m.erase(itr);\n                s.insert(v_k);\n         \
    \   }\n        }\n        if (0 <= x and x <= n) {\n            int xx = x;\n\
    \            auto itr = m.find(xx);\n            if (itr == m.end()) {\n     \
    \           m[xx]++;\n                s.erase(xx);\n            } else {\n   \
    \             itr->second++;\n            }\n        }\n        v[k] = x;\n  \
    \  }\n    value_type prod() const {\n        return *s.begin();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/mex-update.hpp
  requiredBy: []
  timestamp: '2026-10-13 12:42:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/mex-update.test.cpp
documentation_of: src/data_structures/mex-update.hpp
layout: document
title: "1\u70B9\u66F4\u65B0\u30FB\u5168\u4F53\u306E mex \u53D6\u5F97"
---

長さ $n$ の数列について、1点更新と、全体の mex (含まれない最小の非負整数) の取得を行います。

```cpp
MexUpdate<int> mex(std::vector<int>{0, 1, 3});
int a = mex.prod();   // 2
mex.set(1, 5);        // {0, 5, 3}
int b = mex.prod();   // 1
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MexUpdate<T>(n)` | 長さ `n` で、どの要素もまだ値を持たない (mex は 0) | $O(n)$ |
| `MexUpdate<T>(v)` | `v` で初期化 | $O(n \log n)$ |
| `set(k, x)` | `k` 番目を `x` に更新 | $O(\log n)$ |
| `prod()` | 全体の mex | $O(1)$ |

負の値や $n$ より大きい値も入れられます (mex には影響しません)。
