---
title: ガウス整数と二平方和
documentation_of: //src/math/gaussian-integer.hpp
---

ガウス整数 $a + bi$ ($a, b$ は整数) の四則演算と最大公約数、および $n = a^2 + b^2$ となる組 $(a, b)$ の列挙です。

```cpp
using G = GaussianInteger<long long>;
G g = gaussian_gcd(G(5, 0), G(3, 1));  // 単数倍を除いて 2 - i (ノルム 5)
auto v = two_square_sum(25);           // {(0, 5), (3, 4), (4, 3), (5, 0)}
```

## `GaussianInteger<T>`

成分の型 `T` は、積やノルムで成分の 2 乗程度の値を扱うので、それがあふれない型にします (`long long` なら成分の絶対値は $10^9$ 程度まで)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `GaussianInteger<T>(a, b = 0)` | $a + bi$ | $O(1)$ |
| `x.a`, `x.b` | 実部と虚部 | $O(1)$ |
| `x.norm()` | ノルム $a^2 + b^2$ | $O(1)$ |
| `x.conj()` | 共役 $a - bi$ | $O(1)$ |
| `x + y`, `x - y`, `x * y` | 足し算・引き算・掛け算 | $O(1)$ |
| `x / y`, `x % y` | $x / y$ の実部と虚部をそれぞれ最も近い整数に丸めた商と、その余り。余りのノルムは `y` のノルムの半分以下 | $O(1)$ |
| `x == y`, `x != y` | 比較 | $O(1)$ |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `gaussian_gcd(x, y)` | 最大公約数の 1 つ (単数 $\pm 1, \pm i$ 倍の違いを除いて決まる)。両方 0 なら 0 | $O(\log \text{ノルム})$ |
| `two_square_sum(n)` | $n = a^2 + b^2$ となる 0 以上の整数の組 $(a, b)$ を $a$ の昇順にすべて (`std::vector<std::pair<long long, long long>>`)。$0 \le n \le 10^{18}$ | `factorize(n)` + 素因数ごとに $O(\log^2 n)$ + 組の個数 |

`two_square_sum` は $n$ を素因数分解し、4 で割って 1 余る素数 $p$ を $p = \pi \bar{\pi}$ と分けて (−1 の平方根 $t$ を使い $\pi = \gcd(p, t + i)$)、それぞれの素因数の選び方をすべて試します。4 で割って 3 余る素数が奇数乗で含まれていれば、表せません。

## 関連

- 素因数分解は [素数](prime.hpp)、mod の平方根は [mod 演算](modular-arithmetic.hpp)
