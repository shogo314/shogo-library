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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/counter-segtree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ CounterSegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/counter-segtree.hpp\"\
    \n\n/**\n * @file counter-segtree.hpp\n * @brief \u533A\u9593\u5185\u306E\u5024\
    \u306E\u500B\u6570\u3092\u6570\u3048\u308B\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \n */\n\n#include <cassert>\n#include <map>\n#include <optional>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T>\nclass CounterSegTree {\n   public:\n\
    \    using key_type = T;\n    using mapped_type = int;\n\n   private:\n    int\
    \ n, sz, height;\n    std::vector<std::map<key_type, mapped_type>> data;\n\n \
    \  public:\n    explicit CounterSegTree(const std::vector<key_type>& v) {\n  \
    \      n = v.size();\n        sz = 1;\n        height = 0;\n        while (sz\
    \ < n) {\n            sz <<= 1;\n            height++;\n        }\n        data.assign(sz\
    \ * 2, {});\n        for (int i = 0; i < n; i++) {\n            data[i + sz][v[i]]\
    \ = 1;\n        }\n        for (int i = sz - 1; i > 0; i--) {\n            data[i]\
    \ = data[2 * i];\n            for (auto [s, c] : data[2 * i + 1]) {\n        \
    \        data[i][s] += c;\n            }\n        }\n    }\n    key_type get(int\
    \ k) const {\n        assert(0 <= k && k < n);\n        return data[k + sz].begin()->first;\n\
    \    }\n    void set(int k, const key_type& x) {\n        assert(0 <= k && k <\
    \ n);\n        k += sz;\n        key_type y = data[k].begin()->first;\n      \
    \  while (k > 0) {\n            auto itr = data[k].find(y);\n            if (itr->second\
    \ == 1) {\n                data[k].erase(itr);\n            } else {\n       \
    \         itr->second--;\n            }\n            data[k][x]++;\n         \
    \   k >>= 1;\n        }\n    }\n    /**\n     * @brief \u533A\u9593 [l, r) \u3067\
    \ x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3068\u305D\u306E\u500B\u6570\u3002\
    \u306A\u3051\u308C\u3070 std::nullopt\n     */\n    std::optional<std::pair<key_type,\
    \ mapped_type>> lower_bound(int l, int r, key_type x) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        std::pair<key_type, mapped_type> ret = {{},\
    \ 0};\n        l += sz;\n        r += sz;\n        while (l < r) {\n         \
    \   if (l & 1) {\n                auto itr = data[l].lower_bound(x);\n       \
    \         if (itr != data[l].end()) {\n                    if (ret.second == 0)\
    \ {\n                        ret = *itr;\n                    } else if (itr->first\
    \ == ret.first) {\n                        ret.second += itr->second;\n      \
    \              } else if (itr->first < ret.first) {\n                        ret\
    \ = *itr;\n                    }\n                }\n                ++l;\n  \
    \          }\n            if (r & 1) {\n                --r;\n               \
    \ auto itr = data[r].lower_bound(x);\n                if (itr != data[r].end())\
    \ {\n                    if (ret.second == 0) {\n                        ret =\
    \ *itr;\n                    } else if (itr->first == ret.first) {\n         \
    \               ret.second += itr->second;\n                    } else if (itr->first\
    \ < ret.first) {\n                        ret = *itr;\n                    }\n\
    \                }\n            }\n            l >>= 1;\n            r >>= 1;\n\
    \        }\n        if (ret.second == 0) return std::nullopt;\n        return\
    \ ret;\n    }\n    /**\n     * @brief {x, \u533A\u9593 [l, r) \u306E x \u306E\u500B\
    \u6570}\n     */\n    std::pair<key_type, mapped_type> find(int l, int r, key_type\
    \ x) const {\n        assert(0 <= l && l <= r && r <= n);\n        std::pair<key_type,\
    \ mapped_type> ret = {x, 0};\n        l += sz;\n        r += sz;\n        while\
    \ (l < r) {\n            if (l & 1) {\n                auto itr = data[l].find(x);\n\
    \                if (itr != data[l].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n                ++l;\n            }\n     \
    \       if (r & 1) {\n                --r;\n                auto itr = data[r].find(x);\n\
    \                if (itr != data[r].end()) {\n                    ret.second +=\
    \ itr->second;\n                }\n            }\n            l >>= 1;\n     \
    \       r >>= 1;\n        }\n        return ret;\n    }\n};\n#line 7 \"test/unittest/counter-segtree.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#line 12 \"test/unittest/counter-segtree.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 9 + 1;\n      \
    \  std::vector<int> v(n);\n        for (int& x : v) x = rng() % 6;\n        CounterSegTree<int>\
    \ seg(v);\n        // key_type / mapped_type \u306F\u5916\u304B\u3089\u4F7F\u3048\
    \u308B\n        static_assert(std::is_same_v<CounterSegTree<int>::key_type, int>);\n\
    \        static_assert(std::is_same_v<CounterSegTree<int>::mapped_type, int>);\n\
    \        for (int t = 0; t < 20; t++) {\n            if (rng() % 2) {\n      \
    \          int k = rng() % n, x = rng() % 6;\n                seg.set(k, x);\n\
    \                v[k] = x;\n            }\n            for (int k = 0; k < n;\
    \ k++) {\n                if (seg.get(k) != v[k]) ok = false;\n            }\n\
    \            int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l\
    \ > r) std::swap(l, r);\n            int x = rng() % 7;\n            // lower_bound:\
    \ [l, r) \u306B\u3042\u308B x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3068\
    \u305D\u306E\u500B\u6570 (\u306A\u3051\u308C\u3070 std::nullopt)\n           \
    \ int best = -1, cnt = 0, same = 0;\n            for (int i = l; i < r; i++) {\n\
    \                if (v[i] >= x && (best == -1 || v[i] < best)) best = v[i];\n\
    \                if (v[i] == x) same++;\n            }\n            for (int i\
    \ = l; i < r; i++) {\n                if (v[i] == best) cnt++;\n            }\n\
    \            auto lb = seg.lower_bound(l, r, x);\n            if (cnt == 0) {\n\
    \                if (lb) ok = false;\n            } else {\n                if\
    \ (!lb || lb->first != best || lb->second != cnt) ok = false;\n            }\n\
    \            // find: [l, r) \u306B\u3042\u308B x \u306E\u500B\u6570\n       \
    \     auto f = seg.find(l, r, x);\n            if (f.first != x || f.second !=\
    \ same) ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello\
    \ World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// CounterSegTree \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\
    \u30E0\u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/counter-segtree.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <utility>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        int n = rng() % 9 + 1;\n      \
    \  std::vector<int> v(n);\n        for (int& x : v) x = rng() % 6;\n        CounterSegTree<int>\
    \ seg(v);\n        // key_type / mapped_type \u306F\u5916\u304B\u3089\u4F7F\u3048\
    \u308B\n        static_assert(std::is_same_v<CounterSegTree<int>::key_type, int>);\n\
    \        static_assert(std::is_same_v<CounterSegTree<int>::mapped_type, int>);\n\
    \        for (int t = 0; t < 20; t++) {\n            if (rng() % 2) {\n      \
    \          int k = rng() % n, x = rng() % 6;\n                seg.set(k, x);\n\
    \                v[k] = x;\n            }\n            for (int k = 0; k < n;\
    \ k++) {\n                if (seg.get(k) != v[k]) ok = false;\n            }\n\
    \            int l = rng() % (n + 1), r = rng() % (n + 1);\n            if (l\
    \ > r) std::swap(l, r);\n            int x = rng() % 7;\n            // lower_bound:\
    \ [l, r) \u306B\u3042\u308B x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\u3068\
    \u305D\u306E\u500B\u6570 (\u306A\u3051\u308C\u3070 std::nullopt)\n           \
    \ int best = -1, cnt = 0, same = 0;\n            for (int i = l; i < r; i++) {\n\
    \                if (v[i] >= x && (best == -1 || v[i] < best)) best = v[i];\n\
    \                if (v[i] == x) same++;\n            }\n            for (int i\
    \ = l; i < r; i++) {\n                if (v[i] == best) cnt++;\n            }\n\
    \            auto lb = seg.lower_bound(l, r, x);\n            if (cnt == 0) {\n\
    \                if (lb) ok = false;\n            } else {\n                if\
    \ (!lb || lb->first != best || lb->second != cnt) ok = false;\n            }\n\
    \            // find: [l, r) \u306B\u3042\u308B x \u306E\u500B\u6570\n       \
    \     auto f = seg.find(l, r, x);\n            if (f.first != x || f.second !=\
    \ same) ok = false;\n        }\n    }\n    if (ok)\n        std::cout << \"Hello\
    \ World\" << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/counter-segtree.hpp
  isVerificationFile: true
  path: test/unittest/counter-segtree.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/counter-segtree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/counter-segtree.test.cpp
- /verify/test/unittest/counter-segtree.test.cpp.html
title: test/unittest/counter-segtree.test.cpp
---
