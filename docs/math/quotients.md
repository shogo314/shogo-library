---
title: 商の列挙
documentation_of: //src/math/quotients.hpp
---

$\lfloor n / i \rfloor$、または $\lfloor (ax+b)/m \rfloor$ が同じ値になる最大の半開区間を列挙します。$\lfloor n / i \rfloor$ がとる値は $O(\sqrt{n})$ 種類しかないので (区間の個数は $2\sqrt{n}$ 以下)、$\sum_{i=1}^{n} f(\lfloor n/i \rfloor)$ のような和を、区間ごとにまとめて $O(\sqrt{n})$ で計算できます。

例えば $n = 10$ では、次の 5 つの区間に分かれます。

| 商 `q` | 10 | 5 | 3 | 2 | 1 |
|---|---|---|---|---|---|
| 区間 `[l, r)` | [1, 2) | [2, 3) | [3, 4) | [4, 6) | [6, 11) |

```cpp
// sum_{i=1}^{n} floor(n / i) (= 約数の個数の和 d(1) + ... + d(n))
long long sum = 0;
for_each_quotient(n, [&](long long q, long long l, long long r) { sum += q * (r - l); });

for (auto [q, l, r] : enumerate_quotients(10)) {
    // (10, 1, 2), (5, 2, 3), (3, 3, 4), (2, 4, 6), (1, 6, 11) の順
}

// floor(x / 3) が同じになる区間 (0 <= x < 10)
for (auto [q, l, r] : enumerate_quotients_linear(10, 3, 1, 0)) {
    // (0, 0, 3), (1, 3, 6), (2, 6, 9), (3, 9, 10) の順
}

// sum_{x=0}^{n-1} floor((a*x+b)/m)
long long linear_sum = 0;
for_each_quotient_linear(n, m, a, b, [&](long long q, long long l, long long r) { linear_sum += q * (r - l); });
```

`_linear` 版の引数順は `floor_sum(n, m, a, b)` と同じです。対象は `0 <= x < n` で、`a`、`b` は負でもよく、床関数は負の無限大方向への切り捨てです。`n >= 0`、`m >= 1`、各商が `long long` に収まることが前提です。中間計算には `__int128` を使います。

どちらの版も添字の昇順に列挙し、`n = 0` では区間を返しません。`_linear` 版の商は `a > 0` なら昇順、`a < 0` なら降順です。`a = 0` で `n > 0` なら全域を 1 区間として返します。以下では `_linear` 版の出力区間数を $K$ とします。

返される range は区間を走査時に生成します。`size()`・添字アクセス・逆順走査はありません。イテレータは値を返す input iterator で、それぞれ独立した状態を持ち、同じ range を繰り返し走査できます。途中で `break` すると残りの区間は生成しません。

保存や逆順走査が必要な場合は、明示的に `vector` に変換します。

```cpp
auto ranges = enumerate_quotients(n);
std::vector<QuotientRange> saved(ranges.begin(), ranges.end());
```

`_linear` 版の `a = 1` は、最初の商と余りを求めた後、境界と商を加算だけで進めます。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `for_each_quotient(n, f)` | 区間ごとに `f(q, l, r)` を呼ぶ。$l \le i < r$ なら $\lfloor n/i \rfloor = q$ | $O(\sqrt{n})$ |
| `enumerate_quotients(n)` | 区間を `QuotientRange` (メンバ `q`、`l`、`r`) として遅延列挙する range を返す | 構築 $O(1)$、全走査 $O(\sqrt{n})$ |
| `for_each_quotient_linear(n, m, a, b, f)` | $\lfloor (ax+b)/m \rfloor$ が一定の区間ごとに `f(q, l, r)` を呼ぶ | $O(K)$ |
| `enumerate_quotients_linear(n, m, a, b)` | 上の区間を遅延列挙する range を返す | 構築 $O(1)$、全走査 $O(K)$ |

- 区間 `[l, r)` は右端を含まない半開区間です。区間の長さは `r - l` です。
- $\lfloor n/i \rfloor$ の版の前提は `0 <= n < std::numeric_limits<long long>::max()` です。商は降順に並びます。商の昇順が欲しいときは `vector` に格納して逆にたどります。
- $\lfloor n/i \rfloor$ の区間の右端は $r = \lfloor n / \lfloor n/l \rfloor \rfloor + 1$ で求めています。
- `_linear` 版は $K \le n$ ですが、平方根程度になる保証はありません。両方の列挙 API の追加領域は $O(1)$ です (コールバックの時間・領域は除く)。
- `a = 1, b = 0` のとき区間数は $\lceil n/m\rceil$ です。異なる正整数の `m` を $D$ 個処理する総区間数は $O(D+n\log(D+1))$ になります。

## 使い方の例

- $\sum_{i=1}^{n} i \lfloor n/i \rfloor$ (約数の和の総和): 区間ごとに $q \cdot (l + \dots + (r-1))$ を足します。
- $\sum_{i=1}^{n} (n \bmod i)$: $n \bmod i = n - i \lfloor n/i \rfloor$ なので、$n^2$ から上の和を引きます。

## 関連

- 一次関数の床関数の和 $\sum \lfloor (ai + b)/m \rfloor$ は [floor sum](floor-sum.hpp)
- すべての $\lfloor n / k \rfloor$ について素数の個数・和を求めるには [素数の個数・素数の和](prime-counting.hpp)
