---
title: Σ r^i f(i) (指数関数と多項式の積の和)
documentation_of: //src/math/sum-of-exp-times-poly.hpp
---

$f$ を $d$ 次以下の多項式として、$\sum_{i=0}^{n-1} r^i f(i)$ と、その無限和 $\sum_{i=0}^{\infty} r^i f(i)$ ($r$ を $-1 < r < 1$ の有理数とみなす) を $O(d)$ で求めます。$n$ は $10^{18}$ 程度でもかまいません。

```cpp
using mint = modint998244353;
mint a = sum_of_exp_times_poly(mint(2), 3, 1000000000000LL);  // Σ_{i<10^12} 2^i i^3
mint b = sum_of_exp_times_poly_limit(mint(2).inv(), 1);        // Σ i / 2^i = 2
std::vector<mint> f = {1, 3, 7};                                // f(0), f(1), f(2) (f(x) = x^2 + x + 1)
mint c = sum_of_exp_times_poly(mint(5), f, 100);                // Σ_{i<100} 5^i f(i)
```

## 関数

`mint` は [modint](modint.hpp) で、法は $d + 2$ より大きい素数であることが必要です。$0^0 = 1$ とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sum_of_exp_times_poly(r, d, n)` | $\sum_{i=0}^{n-1} r^i i^d$ | $O(d)$ |
| `sum_of_exp_times_poly(r, f, n)` | $\sum_{i=0}^{n-1} r^i f(i)$。`f` は $f(0), \dots, f(d)$ (`std::vector<mint>`) | $O(d)$ |
| `sum_of_exp_times_poly_limit(r, d)` | $\sum_{i=0}^{\infty} r^i i^d$ ($r \ne 1$) | $O(d)$ |
| `sum_of_exp_times_poly_limit(r, f)` | $\sum_{i=0}^{\infty} r^i f(i)$ ($r \ne 1$) | $O(d)$ |

- $r = 1$ のとき、$\sum_{i<n} f(i)$ は $n$ の $d + 1$ 次以下の多項式なので、$n = 0, \dots, d + 1$ での値から [ラグランジュ補間](lagrange-interpolation.hpp) で求めます。
- $r \ne 1$ のとき、$\sum_{i<n} r^i f(i) = c - r^n g(n)$ ($g$ は $d$ 次以下の多項式) の形になります。$s_k = \sum_{i<k} r^i f(i)$ ($k = 0, \dots, d + 1$) を求めると $g(k) = (c - s_k) r^{-k}$ です。$g$ の $d + 1$ 階差分が 0 になることから、定数 $c$ を 1 次方程式で求め、$g(n)$ をラグランジュ補間で求めます。無限和は $c$ そのものです。
- $i^d$ ($i = 0, \dots, d + 1$) は、素数では累乗、合成数では最小素因数の値との積で求めるので、累乗の計算は素数の個数回だけです。

## 関連

- 標本点が $0, \dots, n - 1$ の多項式の値は [ラグランジュ補間](lagrange-interpolation.hpp)
- 最小素因数の篩は [素数](prime.hpp) の `Sieve`
