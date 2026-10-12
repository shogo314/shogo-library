---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/counter-segtree.hpp
    title: "\u533A\u9593\u5185\u306E\u5024\u306E\u500B\u6570\u3092\u6570\u3048\u308B\
      \u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_frequency
    links:
    - https://judge.yosupo.jp/problem/point_set_range_frequency
  bundledCode: "#line 1 \"test/yosupo/point-set-range-frequency.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_frequency\"\n\n#include\
    \ <iostream>\n#include <vector>\n\n#line 2 \"src/data_structures/counter-segtree.hpp\"\
    \n\n/**\n * @file counter-segtree.hpp\n * @brief \u533A\u9593\u5185\u306E\u5024\
    \u306E\u500B\u6570\u3092\u6570\u3048\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n */\n\n#include <cassert>\n#include <map>\n#include <utility>\n#line 12 \"src/data_structures/counter-segtree.hpp\"\
    \n\ntemplate <typename T>\nclass CounterSegTree {\n   public:\n    using key_type\
    \ = T;\n    using mapped_type = int;\n\n   private:\n    int n, sz, height;\n\
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
    \            k >>= 1;\n        }\n    }\n    std::pair<key_type, mapped_type>\
    \ lower_bound(int l, int r, key_type x) const {\n        std::pair<key_type, mapped_type>\
    \ ret = {{}, 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n\
    \            if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n\
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
    \        }\n        return ret;\n    }\n};\n#line 7 \"test/yosupo/point-set-range-frequency.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    int n, q; std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (int&\
    \ x : a) std::cin >> x;\n    CounterSegTree<int> seg(a);\n    while (q--) {\n\
    \        int t; std::cin >> t;\n        if (t == 0) {\n            int k, v; std::cin\
    \ >> k >> v;\n            seg.set(k, v);\n        } else {\n            int l,\
    \ r, x; std::cin >> l >> r >> x;\n            std::cout << seg.find(l, r, x).second\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_frequency\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../../src/data_structures/counter-segtree.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    int n, q; std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (int&\
    \ x : a) std::cin >> x;\n    CounterSegTree<int> seg(a);\n    while (q--) {\n\
    \        int t; std::cin >> t;\n        if (t == 0) {\n            int k, v; std::cin\
    \ >> k >> v;\n            seg.set(k, v);\n        } else {\n            int l,\
    \ r, x; std::cin >> l >> r >> x;\n            std::cout << seg.find(l, r, x).second\
    \ << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structures/counter-segtree.hpp
  isVerificationFile: true
  path: test/yosupo/point-set-range-frequency.test.cpp
  requiredBy: []
  timestamp: '2026-10-12 20:24:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point-set-range-frequency.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point-set-range-frequency.test.cpp
- /verify/test/yosupo/point-set-range-frequency.test.cpp.html
title: test/yosupo/point-set-range-frequency.test.cpp
---
