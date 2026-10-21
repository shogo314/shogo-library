---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/others/mo.test.cpp
    title: test/unittest/others/mo.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/static-range-inversions-query.test.cpp
    title: test/yosupo/data_structure/static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo's algorithm
    links: []
  bundledCode: "#line 2 \"src/others/mo.hpp\"\n\n/**\n * @file mo.hpp\n * @brief Mo's\
    \ algorithm\n */\n\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <cmath>\n#include <type_traits>\n#include <vector>\n\ntemplate <typename\
    \ U, class ADD_LEFT, class DELETE_LEFT, class ADD_RIGHT = ADD_LEFT, class DELETE_RIGHT\
    \ = DELETE_LEFT>\nclass Mo {\n   private:\n    long long _n;\n    std::vector<std::array<long\
    \ long, 3>> lri;\n    U _e;\n    ADD_LEFT _add_left;\n    DELETE_LEFT _delete_left;\n\
    \    ADD_RIGHT _add_right;\n    DELETE_RIGHT _delete_right;\n\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_LEFT, U&, long long>, \"ADD_LEFT must be callable with (U&, long long)\"\
    );\n    static_assert(std::is_invocable_r_v<void, DELETE_LEFT, U&, long long>,\
    \ \"DELETE_LEFT must be callable with (U&, long long)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_RIGHT, U&, long long>, \"ADD_RIGHT must be callable with (U&, long long)\"\
    );\n    static_assert(std::is_invocable_r_v<void, DELETE_RIGHT, U&, long long>,\
    \ \"DELETE_RIGHT must be callable with (U&, long long)\");\n\n   public:\n   \
    \ Mo(long long n,\n       const U& e,\n       const ADD_LEFT& add_left,\n    \
    \   const DELETE_LEFT& delete_left,\n       const ADD_RIGHT& add_right,\n    \
    \   const DELETE_RIGHT& delete_right) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_right), _delete_right(delete_right)\
    \ {}\n    Mo(long long n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_left), _delete_right(delete_left)\
    \ {}\n    void query(long long l, long long r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        lri.push_back({l, r, static_cast<long long>(lri.size())});\n\
    \    }\n    template <typename T, class F>\n    std::vector<T> solve(const F&\
    \ f) {\n        static_assert(std::is_invocable_r_v<T, F, U&>, \"The function\
    \ passed to solve must be callable with (U&) and return T\");\n\n        const\
    \ long long w = std::max<long long>(1, 1.0 * _n / std::max<double>(1.0, std::sqrt(lri.size()\
    \ * 2.0 / 3.0)));\n        std::sort(lri.begin(), lri.end(), [=](const std::array<long\
    \ long, 3>& a, const std::array<long long, 3>& b) {\n            long long aw\
    \ = a[0] / w;\n            long long bw = b[0] / w;\n            if (aw != bw)\
    \ return aw < bw;\n            if (aw & 1) return a[1] > b[1];\n            return\
    \ a[1] < b[1];\n        });\n        std::vector<T> res(lri.size());\n       \
    \ long long tmpl = 0, tmpr = 0;\n        U tmp = _e;\n        for (auto [l, r,\
    \ i] : lri) {\n            while (tmpl > l) {\n                tmpl--;\n     \
    \           _add_left(tmp, tmpl);\n            }\n            while (tmpr < r)\
    \ {\n                _add_right(tmp, tmpr);\n                tmpr++;\n       \
    \     }\n            while (tmpl < l) {\n                _delete_left(tmp, tmpl);\n\
    \                tmpl++;\n            }\n            while (tmpr > r) {\n    \
    \            tmpr--;\n                _delete_right(tmp, tmpr);\n            }\n\
    \            res[i] = f(tmp);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file mo.hpp\n * @brief Mo's algorithm\n */\n\n#include\
    \ <algorithm>\n#include <array>\n#include <cassert>\n#include <cmath>\n#include\
    \ <type_traits>\n#include <vector>\n\ntemplate <typename U, class ADD_LEFT, class\
    \ DELETE_LEFT, class ADD_RIGHT = ADD_LEFT, class DELETE_RIGHT = DELETE_LEFT>\n\
    class Mo {\n   private:\n    long long _n;\n    std::vector<std::array<long long,\
    \ 3>> lri;\n    U _e;\n    ADD_LEFT _add_left;\n    DELETE_LEFT _delete_left;\n\
    \    ADD_RIGHT _add_right;\n    DELETE_RIGHT _delete_right;\n\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_LEFT, U&, long long>, \"ADD_LEFT must be callable with (U&, long long)\"\
    );\n    static_assert(std::is_invocable_r_v<void, DELETE_LEFT, U&, long long>,\
    \ \"DELETE_LEFT must be callable with (U&, long long)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_RIGHT, U&, long long>, \"ADD_RIGHT must be callable with (U&, long long)\"\
    );\n    static_assert(std::is_invocable_r_v<void, DELETE_RIGHT, U&, long long>,\
    \ \"DELETE_RIGHT must be callable with (U&, long long)\");\n\n   public:\n   \
    \ Mo(long long n,\n       const U& e,\n       const ADD_LEFT& add_left,\n    \
    \   const DELETE_LEFT& delete_left,\n       const ADD_RIGHT& add_right,\n    \
    \   const DELETE_RIGHT& delete_right) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_right), _delete_right(delete_right)\
    \ {}\n    Mo(long long n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_left), _delete_right(delete_left)\
    \ {}\n    void query(long long l, long long r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        lri.push_back({l, r, static_cast<long long>(lri.size())});\n\
    \    }\n    template <typename T, class F>\n    std::vector<T> solve(const F&\
    \ f) {\n        static_assert(std::is_invocable_r_v<T, F, U&>, \"The function\
    \ passed to solve must be callable with (U&) and return T\");\n\n        const\
    \ long long w = std::max<long long>(1, 1.0 * _n / std::max<double>(1.0, std::sqrt(lri.size()\
    \ * 2.0 / 3.0)));\n        std::sort(lri.begin(), lri.end(), [=](const std::array<long\
    \ long, 3>& a, const std::array<long long, 3>& b) {\n            long long aw\
    \ = a[0] / w;\n            long long bw = b[0] / w;\n            if (aw != bw)\
    \ return aw < bw;\n            if (aw & 1) return a[1] > b[1];\n            return\
    \ a[1] < b[1];\n        });\n        std::vector<T> res(lri.size());\n       \
    \ long long tmpl = 0, tmpr = 0;\n        U tmp = _e;\n        for (auto [l, r,\
    \ i] : lri) {\n            while (tmpl > l) {\n                tmpl--;\n     \
    \           _add_left(tmp, tmpl);\n            }\n            while (tmpr < r)\
    \ {\n                _add_right(tmp, tmpr);\n                tmpr++;\n       \
    \     }\n            while (tmpl < l) {\n                _delete_left(tmp, tmpl);\n\
    \                tmpl++;\n            }\n            while (tmpr > r) {\n    \
    \            tmpr--;\n                _delete_right(tmp, tmpr);\n            }\n\
    \            res[i] = f(tmp);\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/others/mo.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/others/mo.test.cpp
  - test/yosupo/data_structure/static-range-inversions-query.test.cpp
documentation_of: src/others/mo.hpp
layout: document
title: Mo's algorithm
---

区間 $[l, r)$ に対するクエリをまとめて先読みし、区間の端を 1 つずつ伸び縮みさせながら答えます。区間に要素を 1 つ追加・削除する操作が速くできるときに使えます。

```cpp
// 各クエリ [l, r) の、区間内の異なる値の個数
std::vector<int> cnt(MAXA);
auto add = [&](int& kinds, long long i) { if (cnt[a[i]]++ == 0) kinds++; };
auto del = [&](int& kinds, long long i) { if (--cnt[a[i]] == 0) kinds--; };
Mo mo(n, 0, add, del);                  // 左右で同じ操作なら 2 つ渡せばよい
for (auto [l, r] : queries) mo.query(l, r);
std::vector<int> ans = mo.solve<int>([](int& kinds) { return kinds; });  // クエリ順の答え
```

## メンバ関数

$q$ はクエリ数です。`solve` の計算量は、操作が $O(1)$ のときのものです。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Mo(n, e, add_left, delete_left, add_right, delete_right)` | 要素数 `n` (`long long`)、状態の初期値 `e` (型 `U`) と 4 つの操作で作る | $O(1)$ |
| `Mo(n, e, add, del)` | 左端と右端で操作が同じ場合 | $O(1)$ |
| `query(l, r)` | クエリ $[l, r)$ を追加する (`l`、`r` は `long long`) | $O(1)$ |
| `solve<T>(f)` | すべてのクエリを処理し、各クエリで `f(state)` が返した値 (型 `T`) を、`query` を呼んだ順に並べて返す | $O(n \sqrt{q} + q \log q)$ |

## 渡す操作

操作はいずれも `(U& state, long long i)` を受け取り、`state` を書き換えます。位置 `i` は `long long` で渡すので、`int i` で受け取る操作も使えます。

| 操作 | 呼ばれるとき |
|---|---|
| `add_left(state, i)` | 区間の左に要素 `i` を追加する |
| `delete_left(state, i)` | 区間の左端の要素 `i` を削除する |
| `add_right(state, i)` | 区間の右に要素 `i` を追加する |
| `delete_right(state, i)` | 区間の右端の要素 `i` を削除する |

## 関連

- 操作に $O(\log n)$ かかる例 (区間の転倒数など) では、状態に [Fenwick Tree](../data_structures/fenwick-tree.hpp) を持たせます

