---
title: 多項式の根 (Cantor-Zassenhaus 法)
documentation_of: //src/math/polynomial-roots.hpp
---

素数 $p$ を法とする多項式 $f$ について、$f(a) \equiv 0 \pmod p$ となる $a$ ($0 \le a < p$) を、相異なるものだけ値の小さい順に求めます。$f$ が $n$ 次なら、期待 $O(n \log^2 n \log p)$ です。

```cpp
using mint = modint998244353;
FPS<mint> f = {6, -5, 1};                // x^2 - 5x + 6 = (x - 2)(x - 3)
std::vector<mint> r = polynomial_roots(f);  // {2, 3}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `polynomial_roots(f)` | `f` ([`FPS<mint>`](fps.hpp)) の根を、相異なるものだけ値の小さい順に並べた `std::vector<mint>`。重根も 1 つだけ入る。`f` は 0 でないこと (0 なら assert で落ちる)。0 でない定数なら空 | 期待 $O(n \log^2 n \log p)$ |

1. 0 が根なら先に取り除きます ($f$ を $x$ で割れるだけ割る)。
2. $g = \gcd(f, x^p - x)$ を求めます。$x^p - x = \prod_{a} (x - a)$ なので、$g$ は $f$ の相異なる根 $a$ についての $(x - a)$ の積です。$x^p \bmod f$ は [`modpow`](fps.hpp) で求めます。
3. ランダムな $a$ について $\gcd(g, (x + a)^{(p-1)/2} - 1)$ を求めます。$(x + a)^{(p-1)/2}$ は、$r + a$ が平方剰余になる根 $r$ では 1、そうでない根では $-1$ になるので、根がおよそ半分ずつに分かれます。1 次になるまで繰り返します。

`mint` は [modint](modint.hpp) で、法は素数であることが必要です。gcd は [形式的冪級数](fps.hpp) の `gcd` (Half-GCD、$O(n \log^2 n)$) を使います。分ける段は期待 $O(\log n)$ 段で、各段の `modpow` と `gcd` の和が $O(n \log n \log p + n \log^2 n)$ です。

## 関連

- 多項式の演算・gcd・`modpow` は [形式的冪級数](fps.hpp)
- 平方剰余の判定と平方根は [mod 演算](modular-arithmetic.hpp) の `sqrt_mod`
