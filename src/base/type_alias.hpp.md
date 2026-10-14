---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/base/macro.hpp
    title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1160.test.cpp
    title: test/aoj/1160.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/macro.test.cpp
    title: test/unittest/macro.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u578B\u306E\u5225\u540D"
    links: []
  bundledCode: "#line 2 \"src/base/type_alias.hpp\"\n\n/**\n * @file type_alias.hpp\n\
    \ * @brief \u578B\u306E\u5225\u540D\n */\n\n#include <array>\n#include <cstddef>\n\
    #include <deque>\n#include <functional>\n#include <list>\n#include <map>\n#include\
    \ <queue>\n#include <set>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \nusing ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    \ntemplate <typename T>\nusing vec = std::vector<T>;\ntemplate <typename T, std::size_t\
    \ N>\nusing ary = std::array<T, N>;\nusing str = std::string;\nusing std::deque;\n\
    using std::list;\nusing std::map;\nusing std::multimap;\nusing std::multiset;\n\
    using std::pair;\nusing std::set;\n\nusing pl = pair<ll, ll>;\nusing pd = pair<ld,\
    \ ld>;\n\ntemplate <typename T>\nusing vv = vec<vec<T>>;\ntemplate <typename T>\n\
    using vvv = vec<vec<vec<T>>>;\nusing vl = vec<ll>;\nusing vvl = vv<ll>;\nusing\
    \ vvvl = vvv<ll>;\nusing vs = vec<str>;\nusing vc = vec<char>;\nusing vi = vec<int>;\n\
    using vb = vec<bool>;\n\ntemplate <typename T1, typename T2>\nusing vp = vec<pair<T1,\
    \ T2>>;\nusing vpl = vec<pl>;\nusing vvpl = vv<pl>;\nusing vd = vec<ld>;\nusing\
    \ vpd = vec<pd>;\n\ntemplate <std::size_t N>\nusing al = ary<ll, N>;\ntemplate\
    \ <std::size_t N1, std::size_t N2>\nusing aal = ary<ary<ll, N2>, N1>;\ntemplate\
    \ <std::size_t N>\nusing val = vec<al<N>>;\ntemplate <std::size_t N>\nusing avl\
    \ = ary<vl, N>;\n\ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing mll\
    \ = std::map<ll, ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate\
    \ <std::size_t N>\nusing sal = set<al<N>>;\ntemplate <std::size_t N>\nusing asl\
    \ = ary<sl, N>;\n\ntemplate <typename T>\nusing heap_max = std::priority_queue<T,\
    \ std::vector<T>, std::less<T>>;\ntemplate <typename T>\nusing heap_min = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n"
  code: "#pragma once\n\n/**\n * @file type_alias.hpp\n * @brief \u578B\u306E\u5225\
    \u540D\n */\n\n#include <array>\n#include <cstddef>\n#include <deque>\n#include\
    \ <functional>\n#include <list>\n#include <map>\n#include <queue>\n#include <set>\n\
    #include <string>\n#include <utility>\n#include <vector>\n\nusing ll = long long;\n\
    using ull = unsigned long long;\nusing ld = long double;\n\ntemplate <typename\
    \ T>\nusing vec = std::vector<T>;\ntemplate <typename T, std::size_t N>\nusing\
    \ ary = std::array<T, N>;\nusing str = std::string;\nusing std::deque;\nusing\
    \ std::list;\nusing std::map;\nusing std::multimap;\nusing std::multiset;\nusing\
    \ std::pair;\nusing std::set;\n\nusing pl = pair<ll, ll>;\nusing pd = pair<ld,\
    \ ld>;\n\ntemplate <typename T>\nusing vv = vec<vec<T>>;\ntemplate <typename T>\n\
    using vvv = vec<vec<vec<T>>>;\nusing vl = vec<ll>;\nusing vvl = vv<ll>;\nusing\
    \ vvvl = vvv<ll>;\nusing vs = vec<str>;\nusing vc = vec<char>;\nusing vi = vec<int>;\n\
    using vb = vec<bool>;\n\ntemplate <typename T1, typename T2>\nusing vp = vec<pair<T1,\
    \ T2>>;\nusing vpl = vec<pl>;\nusing vvpl = vv<pl>;\nusing vd = vec<ld>;\nusing\
    \ vpd = vec<pd>;\n\ntemplate <std::size_t N>\nusing al = ary<ll, N>;\ntemplate\
    \ <std::size_t N1, std::size_t N2>\nusing aal = ary<ary<ll, N2>, N1>;\ntemplate\
    \ <std::size_t N>\nusing val = vec<al<N>>;\ntemplate <std::size_t N>\nusing avl\
    \ = ary<vl, N>;\n\ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing mll\
    \ = std::map<ll, ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate\
    \ <std::size_t N>\nusing sal = set<al<N>>;\ntemplate <std::size_t N>\nusing asl\
    \ = ary<sl, N>;\n\ntemplate <typename T>\nusing heap_max = std::priority_queue<T,\
    \ std::vector<T>, std::less<T>>;\ntemplate <typename T>\nusing heap_min = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base/type_alias.hpp
  requiredBy:
  - src/base/macro.hpp
  timestamp: '2026-10-15 03:13:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/macro.test.cpp
  - test/aoj/1160.test.cpp
documentation_of: src/base/type_alias.hpp
layout: document
title: "\u578B\u306E\u5225\u540D"
---

コンテスト用の短い型名です。使う標準ヘッダ (`<vector>`、`<map>`、`<queue>` など) だけを include します。標準ライブラリをまとめて使う場合は `base/all` を include します。

```cpp
vl a(n);                    // std::vector<long long>
vvl dp(h, vl(w));           // 2次元
heap_min<pl> pq;            // 小さい順に取り出す priority_queue
al<3> t;                    // std::array<long long, 3>
```

## 基本

| 別名 | 実体 |
|---|---|
| `ll` / `ull` / `ld` | `long long` / `unsigned long long` / `long double` |
| `str` | `std::string` |
| `vec<T>` / `vv<T>` / `vvv<T>` | 1 / 2 / 3 次元の `std::vector<T>` |
| `ary<T, N>` | `std::array<T, N>` |
| `pl` / `pd` | `pair<ll, ll>` / `pair<ld, ld>` |
| `heap_max<T>` / `heap_min<T>` | 大きい順 / 小さい順に取り出す `std::priority_queue<T>` |

`deque`、`list`、`map`、`multimap`、`multiset`、`pair`、`set` は `std::` なしで使えます。

## vector

| 別名 | 実体 |
|---|---|
| `vl` / `vvl` / `vvvl` | `ll` の 1 / 2 / 3 次元 vector |
| `vi` / `vc` / `vb` / `vs` / `vd` | `int` / `char` / `bool` / `str` / `ld` の vector |
| `vp<T1, T2>` / `vpl` / `vvpl` / `vpd` | `pair` の vector |
| `val<N>` | `vec<al<N>>` |

## array・map・set

| 別名 | 実体 |
|---|---|
| `al<N>` / `aal<N1, N2>` | `ary<ll, N>` / `ary<ary<ll, N2>, N1>` |
| `avl<N>` / `asl<N>` | `ary<vl, N>` / `ary<sl, N>` |
| `ml<T>` / `mll` | `map<ll, T>` / `map<ll, ll>` |
| `sl` / `spl` / `sal<N>` | `set<ll>` / `set<pl>` / `set<al<N>>` |

## 関連

- これらの別名で変数を宣言して読み込むマクロ (`LL`、`VL` など) は [マクロ](macro.hpp)
