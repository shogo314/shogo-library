---
title: ラグランジュ補間
documentation_of: //src/math/lagrange-interpolation.hpp
---

$n - 1$ 次以下の多項式 $f$ について、$f(0), f(1), \dots, f(n - 1)$ から任意の $x$ での値 $f(x)$ を $O(n)$ で求めます。「答えが $N$ の多項式になると分かっているが、$N$ が大きい」ときに、小さい $N$ で愚直に求めた値から答えを求めるのに使います。

```cpp
using mint = modint998244353;
// 1^3 + 2^3 + ... + m^3 は m の 4 次式なので、m = 0, ..., 4 の値から m = 10^12 の値が分かる
std::vector<mint> y(5);
for (int m = 0; m < 5; m++) y[m] = mint(m) * m * m + (m > 0 ? y[m - 1] : mint(0));
mint s = lagrange_interpolation(y, mint(1000000000000LL));
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `lagrange_interpolation(y, x)` | $f(0), \dots, f(n - 1)$ が `y` の $n - 1$ 次以下の多項式 $f$ の $f(x)$。`y` が空なら 0 | $O(n)$ |

- `mint` は体で、$n - 1$ 以下の正の整数が 0 にならないこと (法が $n$ 以上の素数など) が必要です。
- $f(x) = \sum_i y_i \prod_{j \ne i} (x - j) / (i - j)$ を、$(x - j)$ の前後からの積と階乗の逆数で計算します。分母は $i! (n - 1 - i)! (-1)^{n - 1 - i}$ です。$x$ が標本点 ($0$ 以上 $n$ 未満の整数) でも正しく計算できます。

## 関連

- 線形漸化式を満たす数列の遠くの項は [線形漸化式](linear-recurrence.hpp)
- 多くの点での値をまとめて求めるなら [多点評価・多項式補間・標本点のずらし](multipoint.hpp)
