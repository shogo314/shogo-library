---
title: 型の別名
documentation_of: //src/base/type_alias.hpp
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
| `int128_t` / `uint128_t` | `__int128_t` / `__uint128_t` (GNU 拡張) |
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
