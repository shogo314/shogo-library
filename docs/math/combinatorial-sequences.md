---
title: 分割数・ベルヌーイ数・スターリング数・ベル数・大きい n の階乗
documentation_of: //src/math/combinatorial-sequences.hpp
---

数え上げでよく出る数列を、[形式的冪級数](fps.hpp) を使って $O(n \log n)$ でまとめて求めます。どれも長さ $n + 1$ の `FPS<mint>` を返します。

```cpp
using mint = modint998244353;
auto p = partition_numbers<mint>(100);  // p[100] = 190569292
auto B = bernoulli_numbers<mint>(10);   // B[1] = -1/2
auto s = stirling_first<mint>(5);       // s(5, k): x(x-1)(x-2)(x-3)(x-4) の係数
auto S = stirling_second<mint>(5);      // S(5, k)
auto S3 = stirling_second_column<mint>(10, 3);  // S(n, 3) (n = 0, ..., 10)
auto bell = bell_numbers<mint>(10);     // bell[10] = 115975
mint f = large_factorial<mint>(998244352);  // (p - 1)! ≡ -1 (ウィルソンの定理)
```

## 関数

`mint` は [modint](modint.hpp) で、法は $n$ より大きい素数であること (階乗の逆数を使うため) です。

| 関数 | 説明 | 求め方 | 計算量 |
|---|---|---|---|
| `partition_numbers<mint>(n)` | 分割数 $p(0), \dots, p(n)$ ($k$ を正の整数の和に分ける方法の数。順番は区別しない) | 母関数 $1 / \prod_{k \ge 1} (1 - x^k)$。分母は五角数定理で $\sum_k (-1)^k x^{k(3k-1)/2}$ | $O(n \log n)$ |
| `bernoulli_numbers<mint>(n)` | ベルヌーイ数 $B_0, \dots, B_n$ ($B_1 = -1/2$ の流儀) | 指数型母関数 $x / (e^x - 1)$ | $O(n \log n)$ |
| `stirling_first<mint>(n)` | 符号付き第 1 種スターリング数 $s(n, 0), \dots, s(n, n)$ ($x (x-1) \cdots (x-n+1) = \sum_k s(n, k) x^k$) | 下降階乗を $f_{2m}(x) = f_m(x) f_m(x - m)$ で倍々に作る ([Taylor shift](fps.hpp)) | $O(n \log n)$ |
| `stirling_second<mint>(n)` | 第 2 種スターリング数 $S(n, 0), \dots, S(n, n)$ ($n$ 個の区別できる玉を $k$ 個の区別できない空でない箱に分ける方法の数) | $S(n, k) = \sum_i (-1)^{k-i} i^n / (i! (k-i)!)$ を畳み込みで | $O(n \log n)$ |
| `stirling_first_column<mint>(n, k)` | $k$ を固定した符号付き第 1 種スターリング数の列 $s(0, k), s(1, k), \dots, s(n, k)$ | 指数型母関数 $\log(1 + x)^k / k!$ | $O(n \log n)$ |
| `stirling_second_column<mint>(n, k)` | $k$ を固定した第 2 種スターリング数の列 $S(0, k), S(1, k), \dots, S(n, k)$ | 指数型母関数 $(e^x - 1)^k / k!$ | $O(n \log n)$ |
| `bell_numbers<mint>(n)` | ベル数 $B_0, \dots, B_n$ ($k$ 個の区別できる要素を空でない部分集合に分ける方法の数) | 指数型母関数 $\exp(e^x - 1)$ | $O(n \log n)$ |

- 符号なし第 1 種スターリング数 (順列を $k$ 個の巡回に分ける方法の数) は $\lvert s(n, k) \rvert = (-1)^{n-k} s(n, k)$ です。
- ベル数は $B_n = \sum_k S(n, k)$ でもあります。

## 大きい n の階乗

| 関数 | 説明 | 計算量 |
|---|---|---|
| `large_factorial<mint>(n)` | $n!$ を素数 $p$ (`mint` の法) で割った余り。$0 \le n < p$ で、$n$ が $10^9$ 程度でもよい | $O(\sqrt{n} \log n)$ |

$v$ を 2 のべきで $v (v + 1) > n$ となるようにとり、$g_d(x) = (vx + 1)(vx + 2) \cdots (vx + d)$ の値 $g_d(0), \dots, g_d(d)$ を、$g_{2d}(x) = g_d(x) g_d(x + d / v)$ を使って $d = 1, 2, 4, \dots, v$ と倍にしながら [標本点のずらし](multipoint.hpp) で求めます。$q = \lfloor n / v \rfloor$ として $n! = g_v(0) \cdots g_v(q - 1) \times (qv + 1) \cdots n$ です。$n = 10^9$ 程度で 1 回 30 ミリ秒ほどです。

## 関連

- 前計算した表による階乗・二項係数は [組み合わせ](combinatorics.hpp)
- 母関数の演算は [形式的冪級数](fps.hpp)
