---
title: q 二項係数
documentation_of: //src/math/q-binomial.hpp
---

q 二項係数 $\binom{n}{k}_q = \dfrac{[n]_q!}{[k]_q! [n-k]_q!}$ を素数 $p$ で割った余りを、前計算 $O(n_{\max})$、問い合わせ $O(1)$ で求めます。ここで $[i]_q = 1 + q + \dots + q^{i-1}$、$[n]_q! = [1]_q [2]_q \cdots [n]_q$ です。$q = 1$ なら普通の二項係数になります。

```cpp
QBinomial qb(2, 998244353, 10000000);  // q = 2、法 998244353、n は 10^7 まで
long long a = qb(4, 2);                // [4]_2! / ([2]_2! [2]_2!) = 35
```

法 $p$ と $q$ は実行時に決められます (`modint` は使いません)。

## `QBinomial`

| 関数 | 説明 | 計算量 |
|---|---|---|
| `QBinomial(q, p, n_max)` | 前計算する。$0 \le q < p$、$p$ は $2^{31}$ 以下の素数、$0 \le n_{\max} < p$ | $O(n_{\max} + \log p)$ |
| `qb(n, k)` | $\binom{n}{k}_q \bmod p$ ($n \le n_{\max}$)。$k < 0$ や $k > n$ なら 0 | $O(1)$ |

- $q$ の位数を $r$ ($q^r \equiv 1$ となる最小の $r \ge 1$) とすると、$[i]_q \equiv 0$ となるのは $i$ が $r$ の倍数のときだけです。q-Lucas の定理 $\binom{n}{k}_q \equiv \binom{\lfloor n / r \rfloor}{\lfloor k / r \rfloor} \binom{n \bmod r}{k \bmod r}_q$ を使い、どちらも前計算した階乗の表で求めます。
- 表は 32 ビットの整数で持ちます。$n_{\max} = 10^7$ で、表は 80 MB ほど、前計算の途中は 120 MB ほどになります。

## 関連

- 普通の二項係数は [組み合わせ](combinatorics.hpp)
