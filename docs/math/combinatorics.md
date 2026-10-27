---
title: 組み合わせ
documentation_of: //src/math/combinatorics.hpp
---

階乗・順列・二項係数・重複組合せを mod で求めます。素数 mod なら `Combination<Modint>`、素数でない mod なら `CombinationPQ` と [中国剰余定理](number-theory.hpp) を使います。

```cpp
using mint = static_modint<998244353>;
using C = Combination<mint>;
mint a = C::C(5, 2);                     // 10 (5 個から 2 個を選ぶ)
mint b = C::H(3, 2);                     // 6 (3 種類から重複を許して 2 個を選ぶ)
mint c = C::C_loop(1000000000000LL, 2);  // n が大きくても r が小さければ使える

CombinationPQ cpq(2, 3);                 // mod 2^3 = 8
int d = cpq.C(5, 2);                     // 10 mod 8 = 2
```

## どれを使うか

| 状況 | 使うもの |
|---|---|
| mod が素数で、$n$ が mod 未満 ($10^7$ 程度まで) | `C::C(n, r)` など。何度呼んでも $O(1)$ |
| mod が素数で、$n$ が大きい ($10^{18}$ など) が $r$ は小さい | `C::C_loop(n, r)` ($O(r)$) |
| mod が小さい素数 ($10^6$ 程度まで) で、$n$ が mod 以上 | `C::C_lucas(n, r)` |
| mod が素数でない | mod を素因数分解し、各 $p^q$ で `CombinationPQ` を作って `crt` でまとめる (下の例) |

素数でない mod の例です。$12 = 2^2 \cdot 3$ なので、mod 4 と mod 3 で求めてまとめます。

```cpp
CombinationPQ c4(2, 2), c3(3, 1);
auto res = crt({c4.C(5, 2), c3.C(5, 2)}, {c4.pq, c3.pq});  // res->x = 10 (= 5C2 mod 12)
```

## `Combination<Modint>` のメンバ関数

static メンバ関数だけのクラスで、`Combination<mint>::C(n, r)` のように呼びます。`using C = Combination<mint>;` としておくと短く書けます。引数の `n`、`r` はすべて `long long` です。

階乗とその逆元を、必要になった分だけ前計算して使い回します。前計算は同じ `Modint` のすべての呼び出しで共有します。`dynamic_modint` で mod を変えた場合は前計算をやり直します。

前計算を使う関数 (`factorial`・`inverse_factorial`・`inv`・`P`・`C`・`H`) は、mod が素数で、$n$ が mod 未満であることが前提です。$n$ が mod 以上だと $n!$ が 0 になって逆元がないので、assert で落ちます。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `factorial(n)` | $n!$ ($0 \le n <$ mod) | 初回 $O(n)$、以降 $O(1)$ |
| `inverse_factorial(n)` | $(n!)^{-1}$ ($0 \le n <$ mod) | 初回 $O(n)$、以降 $O(1)$ |
| `inv(n)` | $n^{-1}$ ($1 \le n <$ mod)。1 つだけなら `mint(n).inv()` でよい | 初回 $O(n)$、以降 $O(1)$ |
| `P(n, r)` | 順列の数 ${}_n P_r = \frac{n!}{(n - r)!}$ ($n$ 個から $r$ 個を選んで並べる)。$r < 0$ か $n < r$ なら 0 | 初回 $O(n)$、以降 $O(1)$ |
| `C(n, r)` | 二項係数 ${}_n C_r = \binom{n}{r} = \frac{n!}{r! (n - r)!}$ ($n$ 個から $r$ 個を選ぶ)。$r < 0$ か $n < r$ なら 0 | 初回 $O(n)$、以降 $O(1)$ |
| `H(n, r)` | 重複組合せの数 ${}_n H_r = \binom{n + r - 1}{r}$ ($n$ 種類から重複を許して $r$ 個を選ぶ)。$n < 0$ か $r < 0$ なら 0。$n = 0$ なら、$r = 0$ のとき 1、$r > 0$ のとき 0 | 初回 $O(n + r)$、以降 $O(1)$ |
| `P_loop(n, r)` | ${}_n P_r$ を $n (n - 1) \cdots (n - r + 1)$ と掛けて求める。$n$ は mod 以上でもよい。範囲外なら 0 | $O(r)$ |
| `C_loop(n, r)` | ${}_n C_r$ を ${}_n P_r / r!$ で求める。$n$ は mod 以上でもよい ($\min(r, n - r)$ は mod 未満)。範囲外なら 0 | $O(\min(r, n - r))$ |
| `H_loop(n, r)` | ${}_n H_r$ を `C_loop` で求める。範囲外の扱いは `H` と同じ | $O(\min(r, n - 1))$ |
| `C_lucas(n, r)` | ${}_n C_r$ を Lucas の定理で求める。$n$ は mod 以上でもよい。範囲外なら 0 | 初回 最大 $O(\mathrm{mod})$、以降 $O(\log_{\mathrm{mod}} n)$ |
| `extend(n)` | $n$ ($<$ mod) までの階乗とその逆元を前計算しておく | $O(n)$ |

前計算は必要な分だけ自動で伸びますが、伸びるたびに逆元の計算 ($O(\log \mathrm{mod})$) が入ります。使う最大の $n$ が分かっていれば、最初に `C::extend(n)` を呼んでおくと無駄がありません。

`C_lucas` は $n$、$r$ を mod 進数で表し、桁ごとの二項係数の積を求めます (Lucas の定理)。桁は mod 未満なので、mod までの前計算を使います。mod が $998244353$ のように大きいと前計算が重すぎるので、小さい素数のときに使ってください。

## `CombinationPQ` のメンバ関数

素数 $p$ について、${}_n C_r \bmod p^q$ を求めます。$n$ は大きくてもよく、$p^q$ 未満の数についての前計算だけで済みます (一般化 Lucas の定理)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CombinationPQ(p, q)` | 前計算。$p$ は素数、$q \ge 1$。$p^q$ は $10^7$ 程度まで (`int` の配列を 2 本持つ) | $O(p^q)$ |
| `C(n, r)` | ${}_n C_r \bmod p^q$ を $[0, p^q)$ の `int` で返す。$r < 0$ か $n < r$ なら 0 | $O(\log_p n)$ |

## `CombinationPQ` のメンバ変数

| 変数 | 説明 |
|---|---|
| `p`, `q` | 作るときに渡した $p$、$q$ |
| `pq` | $p^q$ (法) |

## 関連

- mod を表す型は [modint](modint.hpp)、mod の逆元・冪は [mod 演算](modular-arithmetic.hpp)
- `CombinationPQ` の結果をまとめる中国剰余定理 `crt` は [数論](number-theory.hpp)、mod の素因数分解 `factorize` は [素数](prime.hpp)
- 分割数・ベルヌーイ数・スターリング数・ベル数をまとめて求めるなら [分割数・ベルヌーイ数・スターリング数・ベル数](combinatorial-sequences.hpp)
