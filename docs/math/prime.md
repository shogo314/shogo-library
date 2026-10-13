---
title: 素数 (素数判定、素因数分解、約数列挙、篩)
documentation_of: //src/math/prime.hpp
---

素数に関する関数と、最小素因数を前計算する篩 `Sieve` です。

```cpp
is_prime(998244353);                 // true (Miller-Rabin、10^18 程度まで)
auto f = factorize(360);             // {(2, 3), (3, 2), (5, 1)}
auto d = divisors(12);               // {1, 2, 3, 4, 6, 12}
long long phi = totient(10);         // 4
std::vector<int> ps = enumerate_primes(100);  // {2, 3, 5, ..., 97}

Sieve sv(1000000);                   // 10^6 以下の最小素因数を前計算する
sv.is_prime(x);                      // O(1)
auto g = sv.factorize(x);            // O(log x)
```

## 関数

| 関数 | 説明 |
|---|---|
| `is_prime(n)` | `n` が素数か。64 bit の範囲で決定的な Miller-Rabin。`constexpr` で使える。$O(\log n)$ |
| `factorize(n)` | `n` ($\ge 1$) を素因数分解し、`(素因数, 指数)` を素因数の昇順に並べた `std::vector<std::pair<long long, int>>` を返す。Pollard の ρ 法。期待 $O(n^{1/4})$ 程度 |
| `divisors(n)` | `n` ($\ge 1$) の正の約数を昇順に並べて返す |
| `totient(n)` | オイラーの $\varphi$ 関数 ($1$ 以上 $n$ 以下で $n$ と互いに素な整数の個数) |
| `enumerate_primes(n)` | `n` 以下の素数を昇順に並べて返す。奇数だけを区間ごとに篩うので、$n = 5 \times 10^8$ でも 1 秒かからない。$O(n \log \log n)$ |

## `Sieve`

`Sieve(n)` で `n` 以下の整数の最小素因数を前計算します (線形篩、$O(n)$)。同じ範囲の数をたくさん素因数分解するときに使います。

| メンバ | 説明 |
|---|---|
| `Sieve(n)` | `n` 以下の最小素因数を前計算する。メモリは `int` が $n + 1$ 個 |
| `is_prime(x)` | `x` ($0 \le x \le n$) が素数か。$O(1)$ |
| `min_factor(x)` | `x` ($2 \le x \le n$) の最小素因数。$O(1)$ |
| `primes()` | `n` 以下の素数を昇順に並べたもの |
| `factorize(x)` | `x` ($1 \le x \le n$) を素因数分解する。戻り値の形は `factorize(n)` と同じ (型は `int`)。$O(\log x)$ |
| `divisors(x)` | `x` ($1 \le x \le n$) の正の約数を昇順に並べて返す |
| `limit()` | 前計算した範囲の上限 `n` |

`n` が $10^7$ を大きく超えるときは、メモリを抑えた `enumerate_primes` を使います。
