---
title: 約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込み
documentation_of: //src/math/divisor-transform.hpp
---

添字の約数・倍数の関係で和をとる変換と、その逆変換です。配列 `a` の添字 $1, \dots, N$ ($N$ = `a.size() - 1`) を使い、`a[0]` は使いません。値の型 `T` は `+`、`-`、`*` が使えれば何でもよく、`long long` や modint を想定しています。

素数 $p$ ごとに「$i$ と $ip$ の間で足す」ことを繰り返して計算します。

```cpp
std::vector<long long> a = {0, 1, 2, 3, 4}, b = {0, 5, 6, 7, 8};
auto g = gcd_convolution(a, b);  // {0, 155, 52, 21, 32}
auto l = lcm_convolution(a, b);  // {0, 5, 28, 43, 100}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `divisor_zeta(a)` | $a_n \leftarrow \sum_{d \mid n} a_d$ (その場で書き換える) | $O(N \log \log N)$ |
| `divisor_mobius(a)` | `divisor_zeta` の逆変換 | $O(N \log \log N)$ |
| `multiple_zeta(a)` | $a_n \leftarrow \sum_{n \mid m,\ m \le N} a_m$ (その場で書き換える) | $O(N \log \log N)$ |
| `multiple_mobius(a)` | `multiple_zeta` の逆変換 | $O(N \log \log N)$ |
| `gcd_convolution(a, b)` | $c_k = \sum_{\gcd(i, j) = k} a_i b_j$ ($1 \le i, j \le N$) を返す。`a` と `b` は同じ長さ | $O(N \log \log N)$ |
| `lcm_convolution(a, b)` | $c_k = \sum_{\mathrm{lcm}(i, j) = k} a_i b_j$ ($k \le N$) を返す。lcm が $N$ を超える組は数えない | $O(N \log \log N)$ |

## 例: gcd が k の組の個数

$1 \le x, y \le N$ で $\gcd(x, y) = k$ となる組の個数は、`cnt[d]` を「$d$ の倍数の組の個数」$\lfloor N / d \rfloor^2$ にしてから、倍数のメビウス変換をすると求められます。

```cpp
std::vector<long long> cnt(n + 1);
for (int d = 1; d <= n; d++) cnt[d] = (long long)(n / d) * (n / d);
multiple_mobius(cnt);  // cnt[k] = gcd(x, y) = k となる組の個数
```

配列の値の gcd についても同じで、値ごとの個数を `cnt` に入れて `multiple_zeta` すると、`cnt[d]` は $d$ の倍数の個数になります。

## 関連

- 素数の列挙や素因数分解は [素数](prime.hpp)
