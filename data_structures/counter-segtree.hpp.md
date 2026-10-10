---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structures/counter-segtree.hpp\"\n#include <cassert>\n\
    #include <map>\n#include <vector>\n\ntemplate <typename T>\nclass CounterSegTree\
    \ {\n    using key_type = T;\n    using mapped_type = int;\n\n    int n, sz, height;\n\
    \    std::vector<std::map<key_type, mapped_type>> data;\n\n   public:\n    explicit\
    \ CounterSegTree(const std::vector<key_type>& v) {\n        n = v.size();\n  \
    \      sz = 1;\n        height = 0;\n        while (sz < n) {\n            sz\
    \ <<= 1;\n            height++;\n        }\n        data.assign(sz * 2, {});\n\
    \        for (int i = 0; i < n; i++) {\n            data[i + sz][v[i]] = 1;\n\
    \        }\n        for (int i = sz - 1; i > 0; i--) {\n            data[i] =\
    \ data[2 * i];\n            for (auto [s, c] : data[2 * i + 1]) {\n          \
    \      data[i][s] += c;\n            }\n        }\n    }\n    key_type get(int\
    \ k) const {\n        assert(0 <= k and k < n);\n        return data[k + sz].begin()->first;\n\
    \    }\n    void set(int k, const key_type& x) {\n        k += sz;\n        key_type\
    \ y = data[k].begin()->first;\n        while (k > 0) {\n            auto itr =\
    \ data[k].find(y);\n            if (itr->second == 1) {\n                data[k].erase(itr);\n\
    \            } else {\n                itr->second++;\n            }\n       \
    \     data[k][x]++;\n            k >>= 1;\n        }\n    }\n    std::pair<key_type,\
    \ mapped_type> lower_bound(int l, int r, key_type x) const {\n        std::pair<key_type,\
    \ mapped_type> ret = {{}, 0};\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n\
    \                if (itr != data[l].end()) {\n                    if (ret.second\
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
    \        }\n        return ret;\n    }\n    std::pair<key_type, mapped_type> find(int\
    \ l, int r, key_type x) const {\n        std::pair<key_type, mapped_type> ret\
    \ = {x, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n   \
    \         if (l & 1) {\n                auto itr = data[l].find(x);\n        \
    \        if (itr != data[l].end()) {\n                    ret.second += itr->second;\n\
    \                }\n                ++l;\n            }\n            if (r & 1)\
    \ {\n                --r;\n                auto itr = data[r].find(x);\n     \
    \           if (itr != data[r].end()) {\n                    ret.second += itr->second;\n\
    \                }\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <vector>\n\ntemplate\
    \ <typename T>\nclass CounterSegTree {\n    using key_type = T;\n    using mapped_type\
    \ = int;\n\n    int n, sz, height;\n    std::vector<std::map<key_type, mapped_type>>\
    \ data;\n\n   public:\n    explicit CounterSegTree(const std::vector<key_type>&\
    \ v) {\n        n = v.size();\n        sz = 1;\n        height = 0;\n        while\
    \ (sz < n) {\n            sz <<= 1;\n            height++;\n        }\n      \
    \  data.assign(sz * 2, {});\n        for (int i = 0; i < n; i++) {\n         \
    \   data[i + sz][v[i]] = 1;\n        }\n        for (int i = sz - 1; i > 0; i--)\
    \ {\n            data[i] = data[2 * i];\n            for (auto [s, c] : data[2\
    \ * i + 1]) {\n                data[i][s] += c;\n            }\n        }\n  \
    \  }\n    key_type get(int k) const {\n        assert(0 <= k and k < n);\n   \
    \     return data[k + sz].begin()->first;\n    }\n    void set(int k, const key_type&\
    \ x) {\n        k += sz;\n        key_type y = data[k].begin()->first;\n     \
    \   while (k > 0) {\n            auto itr = data[k].find(y);\n            if (itr->second\
    \ == 1) {\n                data[k].erase(itr);\n            } else {\n       \
    \         itr->second++;\n            }\n            data[k][x]++;\n         \
    \   k >>= 1;\n        }\n    }\n    std::pair<key_type, mapped_type> lower_bound(int\
    \ l, int r, key_type x) const {\n        std::pair<key_type, mapped_type> ret\
    \ = {{}, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n  \
    \          if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n\
    \                if (itr != data[l].end()) {\n                    if (ret.second\
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
    \        }\n        return ret;\n    }\n    std::pair<key_type, mapped_type> find(int\
    \ l, int r, key_type x) const {\n        std::pair<key_type, mapped_type> ret\
    \ = {x, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n   \
    \         if (l & 1) {\n                auto itr = data[l].find(x);\n        \
    \        if (itr != data[l].end()) {\n                    ret.second += itr->second;\n\
    \                }\n                ++l;\n            }\n            if (r & 1)\
    \ {\n                --r;\n                auto itr = data[r].find(x);\n     \
    \           if (itr != data[r].end()) {\n                    ret.second += itr->second;\n\
    \                }\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structures/counter-segtree.hpp
  requiredBy: []
  timestamp: '2026-10-09 19:25:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structures/counter-segtree.hpp
layout: document
redirect_from:
- /library/data_structures/counter-segtree.hpp
- /library/data_structures/counter-segtree.hpp.html
title: data_structures/counter-segtree.hpp
---
