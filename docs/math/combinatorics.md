---
title: 組み合わせ
documentation_of: //src/math/combinatorics.hpp
---

二項係数などを mod で求めます。

```cpp
using mint = static_modint<998244353>;
using C = Combination<mint>;
mint a = C::C(5, 2);                     // 10
mint b = C::H(3, 2);                     // 6
mint c = C::C_loop(1000000000000LL, 2);  // n が大きくても r が小さければ使える

CombinationPQ cpq(2, 3);                 // mod 2^3 = 8
int d = cpq.C(5, 2);                     // 10 mod 8 = 2
```

## `Combination<Modint>`

static メンバ関数だけのクラスです。階乗とその逆元を必要になった分だけ前計算して使い回します。mod は素数で、使う $n$ より大きいこと。`dynamic_modint` で mod を変えた場合は前計算をやり直します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `factorial(n)` | $n!$ | 前計算 $O(n)$、以降 $O(1)$ |
| `inverse_factorial(n)` | $(n!)^{-1}$ | 前計算 $O(n)$、以降 $O(1)$ |
| `inv(n)` | $n^{-1}$ ($n > 0$) | 前計算 $O(n)$、以降 $O(1)$ |
| `P(n, r)` | ${}_n P_r$ (範囲外なら 0) | 前計算 $O(n)$、以降 $O(1)$ |
| `C(n, r)` | ${}_n C_r$ (範囲外なら 0) | 前計算 $O(n)$、以降 $O(1)$ |
| `H(n, r)` | ${}_n H_r = \binom{n+r-1}{r}$ | 前計算 $O(n + r)$、以降 $O(1)$ |
| `P_loop(n, r)` | ${}_n P_r$ を定義どおり計算 (`n` は `long long`) | $O(r)$ |
| `C_loop(n, r)` | ${}_n C_r$ を定義どおり計算 (`n`、`r` は `long long`) | $O(\min(r, n - r))$ |
| `H_loop(n, r)` | ${}_n H_r$ を定義どおり計算 | $O(r)$ |
| `C_lucas(n, r)` | ${}_n C_r$ を Lucas の定理で計算 (`n` が mod 以上でもよい) | 前計算 $O(\mathrm{mod})$、以降 $O(\log n)$ |
| `extend(n)` | $n$ までの階乗を前計算しておく | $O(n)$ |

## `CombinationPQ`

素数 $p$ について、${}_n C_r \bmod p^q$ を求めます。素数でない mod の二項係数は、mod を素因数分解して各 $p^q$ で求め、[中国剰余定理](number-theory.hpp) でまとめます。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CombinationPQ(p, q)` | 前計算 | $O(p^q)$ |
| `C(n, r)` | ${}_n C_r \bmod p^q$ (`int` で返す) | $O(\log n)$ |
