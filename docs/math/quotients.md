---
title: 商の列挙
documentation_of: //src/math/quotients.hpp
---

$i = 1, 2, \dots, n$ を、商 $\lfloor n / i \rfloor$ が同じ値になる区間に分けます。商がとる値は $O(\sqrt{n})$ 種類しかないので (区間の個数は $2\sqrt{n}$ 以下)、$\sum_{i=1}^{n} f(\lfloor n/i \rfloor)$ のような和を、区間ごとにまとめて $O(\sqrt{n})$ で計算できます。

例えば $n = 10$ では、次の 5 つの区間に分かれます。

| 商 `q` | 10 | 5 | 3 | 2 | 1 |
|---|---|---|---|---|---|
| 区間 `[l, r]` | [1, 1] | [2, 2] | [3, 3] | [4, 5] | [6, 10] |

```cpp
// sum_{i=1}^{n} floor(n / i) (= 約数の個数の和 d(1) + ... + d(n))
long long sum = 0;
for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l + 1); });

for (auto [q, l, r] : enumerate_quotients(10)) {
    // (10, 1, 1), (5, 2, 2), (3, 3, 3), (2, 4, 5), (1, 6, 10) の順
}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `for_each_quotient(n, f)` | 区間ごとに `f(q, l, r)` を呼ぶ。$l \le i \le r$ なら $\lfloor n/i \rfloor = q$ | $O(\sqrt{n})$ |
| `enumerate_quotients(n)` | 区間を `QuotientRange` (メンバ `q`、`l`、`r`) のリストで返す | $O(\sqrt{n})$ |

- 区間 `[l, r]` は右端を含む閉区間です (このライブラリの他の区間は半開区間 `[l, r)` ですが、ここでは $r = \lfloor n/q \rfloor$ がそのまま求まるので閉区間にしています)。区間の長さは `r - l + 1` です。
- どちらも $i$ の昇順 (商の降順) に並びます。商の昇順が欲しいときは逆にたどります。
- 区間の右端は $r = \lfloor n / \lfloor n/l \rfloor \rfloor$ で求めています。

## 使い方の例

- $\sum_{i=1}^{n} i \lfloor n/i \rfloor$ (約数の和の総和): 区間ごとに $q \cdot (l + \dots + r)$ を足します。
- $\sum_{i=1}^{n} (n \bmod i)$: $n \bmod i = n - i \lfloor n/i \rfloor$ なので、$n^2$ から上の和を引きます。

## 関連

- 一次関数の床関数の和 $\sum \lfloor (ai + b)/m \rfloor$ は [floor sum](floor-sum.hpp)
