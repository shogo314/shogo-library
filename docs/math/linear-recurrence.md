---
title: 線形漸化式 (Bostan-Mori・Berlekamp-Massey)
documentation_of: //src/math/linear-recurrence.hpp
---

線形漸化式 $a_i = c_1 a_{i-1} + c_2 a_{i-2} + \dots + c_d a_{i-d}$ を満たす数列の第 $k$ 項を、$k$ が $10^{18}$ 程度でも $O(d \log d \log k)$ で求めます (Bostan-Mori 法)。また、数列の初めの項から、それを満たす最短の漸化式を求めます (Berlekamp-Massey 法)。2 つを組み合わせると、「初めの数項を愚直に求めて漸化式を見つけ、遠くの項を求める」ことができます。

```cpp
using mint = modint998244353;
std::vector<mint> a = {0, 1}, c = {1, 1};                // フィボナッチ数: a_i = a_{i-1} + a_{i-2}
mint f = linear_recurrence_kth(a, c, 1000000000000LL);  // F_{10^12}

std::vector<mint> first = {1, 1, 2, 3, 5, 8, 13, 21};   // 初めの数項
std::vector<mint> rec = berlekamp_massey(first);        // {1, 1}
mint g = linear_recurrence_kth(std::vector<mint>(first.begin(), first.begin() + rec.size()), rec, 100);
```

## 関数

`mint` は [modint](modint.hpp) などの体の型です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `bostan_mori(P, Q, k)` | 有理式 $P(x) / Q(x)$ の $x^k$ の係数 ($Q_0 \ne 0$)。$P$ の次数が $Q$ 以上でもよい | $O(d \log d \log k)$ ($d$ は $P$、$Q$ の長さ) |
| `linear_recurrence_kth(a, c, k)` | 初めの $d$ 項 `a` ($a_0, \dots, a_{d-1}$) と係数 `c` ($c_1, \dots, c_d$) の漸化式の第 $k$ 項 ($0$-indexed) | $O(d \log d \log k)$ |
| `berlekamp_massey(a)` | 数列 `a` を満たす最短の漸化式の係数 $c_1, \dots, c_d$ ($d \le i < \lvert a \rvert$ で成り立つ) | $O(\lvert a \rvert^2)$ |

- `linear_recurrence_kth` は、母関数 $A(x) = P(x) / Q(x)$ ($Q(x) = 1 - c_1 x - \dots - c_d x^d$、$P(x) = A(x) Q(x) \bmod x^d$) について `bostan_mori` を呼びます。
- `bostan_mori` は $P(x) / Q(x) = P(x) Q(-x) / (Q(x) Q(-x))$ の分母が $x^2$ の多項式になることを使い、$k$ の偶奇で分子の係数を半分に絞って $k$ を半分にします。法が NTT に向く素数 (998244353 など) で長さが 61 以上なら、NTT した値のまま段を進めます (1 段あたり NTT 4 回分ほど、$d = 10^5$、$k = 10^{18}$ で 0.3 秒ほど)。そうでなければ 1 段ごとに [畳み込み](convolution.hpp) の `convolution` を 2 回呼ぶので、法は任意です。
- `berlekamp_massey` は、漸化式の長さが $d$ なら、初めの $2d$ 項以上を渡せば正しく復元できます。足りないと、もっと短い別の漸化式を返すことがあります。

## 関連

- 漸化式を行列で表すなら [行列](matrix.hpp) の `pow`
- 多項式の値から別の点の値を求めるなら [ラグランジュ補間](lagrange-interpolation.hpp)
- 形式的冪級数の演算は [形式的冪級数](fps.hpp)
