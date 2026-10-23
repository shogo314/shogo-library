---
title: 素数 (素数判定、素因数分解、約数列挙、篩、原始根)
documentation_of: //src/math/prime.hpp
---

素数に関する関数と、最小素因数を前計算する篩 `Sieve` です。

```cpp
is_prime(998244353);                 // true (Miller-Rabin、10^18 程度まで)
auto f = factorize(360);             // {(2, 3), (3, 2), (5, 1)}
auto d = divisors(12);               // {1, 2, 3, 4, 6, 12}
long long phi = totient(10);         // 4
std::vector<long long> ps = enumerate_primes(100);  // {2, 3, 5, ..., 97}

Sieve sv(1000000);                   // 10^6 以下の最小素因数を前計算する
sv.is_prime(x);                      // O(1)
auto g = sv.factorize(x);            // O(log x)
```

## 関数

$d(n)$ は $n$ の約数の個数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `is_prime(n)` | `n` が素数か。64 bit の範囲で決定的な Miller-Rabin。`constexpr` で使える | $O(\log n)$ |
| `factorize(n)` | `n` ($\ge 1$) を素因数分解し、`(素因数, 指数)` を素因数の昇順に並べた `std::vector<std::pair<long long, long long>>` を返す。Pollard の ρ 法 | 期待 $O(n^{1/4})$ 程度 |
| `divisors(n)` | `n` ($\ge 1$) の正の約数を昇順に並べて返す | `factorize(n)` + $O(d(n) \log d(n))$ |
| `totient(n)` | オイラーの $\varphi$ 関数 ($1$ 以上 $n$ 以下で $n$ と互いに素な整数の個数) | `factorize(n)` と同じ |
| `primitive_root(m)` | `m` ($\ge 1$) を法とする最小の原始根。原始根があるのは $m = 1, 2, 4, p^k, 2p^k$ ($p$ は奇素数) のときで、なければ -1 ($m = 1$ なら 0)。$m$ が $10^{18}$ 程度でもよい | `factorize(m)` と `factorize(φ(m))` + 候補ごとに $O(\log^2 m)$ |
| `kth_root_mod(k, a, p)` | 素数 `p` について $x^k \equiv a \pmod p$ となる $x$ を 1 つ (なければ -1)。$0^0 = 1$ とする。$g = \gcd(k, p - 1)$ 乗根を、$g$ の素因数 $q$ ごとに位数 $q^s$ の部分群で Pohlig-Hellman 法を使って求める | `factorize(p - 1)` + $O(\sum_q (s \sqrt{q} + \log^2 p))$ |
| `tetration_mod(a, b, m)` | テトレーション $a \uparrow\uparrow b$ ($a$ を $b$ 個重ねたべき乗、$a \uparrow\uparrow 0 = 1$) を `m` で割った余り。$0^0 = 1$ とする。$x \ge \log_2 m$ なら $a^x \equiv a^{x \bmod \varphi(m) + \varphi(m)}$ を使って `m` を $\varphi(m)$ に置き換えていく。$1 \le m \le 2 \times 10^9$ | $O(\log m \times$ (`factorize(m)` $+ \log m$)$)$ |
| `enumerate_primes(n)` | `n` 以下の素数を昇順に並べた `std::vector<long long>` を返す。奇数だけを区間ごとに篩うので、$n = 5 \times 10^8$ でも 1 秒かからない | $O(n \log \log n)$ |

## `Sieve` のメンバ関数

`Sieve(n)` で `n` 以下の整数の最小素因数を前計算します (線形篩)。引数と戻り値の整数は `long long` です (内部の最小素因数の表だけは、メモリを抑えるため `int` で持ちます)。同じ範囲の数をたくさん素因数分解するときに使います。`n` が $10^7$ を大きく超えるときは、メモリを抑えた `enumerate_primes` を使います。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Sieve(n)` | `n` 以下の最小素因数を前計算する。メモリは `int` が $n + 1$ 個 | $O(n)$ |
| `is_prime(x)` | `x` ($0 \le x \le n$) が素数か | $O(1)$ |
| `min_factor(x)` | `x` ($2 \le x \le n$) の最小素因数 | $O(1)$ |
| `primes()` | `n` 以下の素数を昇順に並べた `std::vector<long long>` (参照を返す) | $O(1)$ |
| `factorize(x)` | `x` ($1 \le x \le n$) を素因数分解する。戻り値の形は `factorize(n)` と同じ | $O(\log x)$ |
| `divisors(x)` | `x` ($1 \le x \le n$) の正の約数を昇順に並べて返す | $O(\log x + d(x) \log d(x))$ |
| `limit()` | 前計算した範囲の上限 `n` | $O(1)$ |

## 関連

- 篩を使わずに大きい $n$ ($10^{11}$ 程度) 以下の素数の個数や和を求めるなら [素数の個数・素数の和](prime-counting.hpp)
- 約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込みは [約数変換](divisor-transform.hpp)
- mod の冪乗・逆元は [mod 演算](modular-arithmetic.hpp)
