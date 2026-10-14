---
title: floor sum (一次関数の床関数の和)
documentation_of: //src/math/floor-sum.hpp
---

$\displaystyle \sum_{i=0}^{n-1} \left\lfloor \frac{ai + b}{m} \right\rfloor$ を求めます。

```cpp
long long s = floor_sum(4, 10, 6, 3);  // floor(3/10) + floor(9/10) + floor(15/10) + floor(21/10) = 3
long long t = floor_sum(3, 2, -1, 0);  // 0 + (-1) + (-1) = -2
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `floor_sum(n, m, a, b)` | 上の和。$n \ge 0$、$m \ge 1$。`a`、`b` は負でもよい (床関数は $-\infty$ 方向への切り捨て) | $O(\log m)$ |

答えが `long long` に収まることが必要です。途中では、`a`、`b` を $[0, m)$ に直したあと $an + b$ などを `unsigned long long` で計算します (オーバーフローしても、答えが収まっていれば $2^{64}$ で割った余りとして正しくなります)。

格子点の個数 $\lvert \lbrace (x, y) : 0 \le x < n,\ 0 < y \le (ax + b) / m \rbrace \rvert$ を、$x$ と $y$ を入れ替えて数え直すことを、ユークリッドの互除法のように繰り返します。

## 関連

- mod 演算は [mod 演算](modular-arithmetic.hpp)、中国剰余定理は [数論](number-theory.hpp)
- $\lfloor n/i \rfloor$ の値ごとにまとめるには [商の列挙](quotients.hpp)
