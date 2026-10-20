---
title: mod 演算 (積、冪乗、逆元、離散対数、平方根)
documentation_of: //src/math/modular-arithmetic.hpp
---

`long long` の値どうしの mod 演算です。法 `m` は $1 \le m < 2^{63}$ で、途中の積は `__int128` で計算するのであふれません。どれも `constexpr` です。

```cpp
long long x = modinv(3, 7);         // 5
long long y = modpow(2, 10, 1000);  // 24
long long z = modmul(1LL << 62, 4, 1000000007);
long long k = discrete_log(3, 13, 17);  // 3^k ≡ 13 (mod 17) となる最小の k = 4
long long r = sqrt_mod(2, 7);           // r^2 ≡ 2 (mod 7) となる小さい方の r = 3
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `modmul(a, b, m)` | $ab \bmod m$ (`a`、`b` は負でもよい。結果は $[0, m)$) | $O(1)$ |
| `modinv(a, m)` | $a^{-1} \bmod m$ (`a` と `m` が互いに素でなければ assert で落ちる) | $O(\log m)$ |
| `modpow(a, n, m)` | $a^n \bmod m$ (`n` は負でもよく、そのときは `a` と `m` が互いに素であること) | $O(\log \lvert n \rvert)$ |
| `discrete_log(a, b, m)` | $a^x \equiv b \pmod m$ となる最小の $x \ge 0$ (なければ -1)。`a` と `m` は互いに素でなくてもよい。Baby-step Giant-step | $O(\sqrt m)$ (メモリも) |
| `sqrt_mod(a, p)` | 素数 `p` について $x^2 \equiv a \pmod p$ となる $x$ のうち小さい方 (なければ -1)。もう一方は $p - x$。Tonelli-Shanks | $O(\log^2 p)$ |

`discrete_log` は、`a` と `m` が互いに素になるまで両辺を $\gcd$ で割り (その途中で答えが見つかることもある)、残りを $x = np - q$ ($n = \lceil \sqrt m \rceil$) と書いて、$b a^q$ の表と $a^{np}$ を突き合わせます。`m` が $10^{12}$ 程度を超えると、時間とメモリが足りなくなります。

## 関連

- `modint` のメンバ関数 `pow`、`inv` は [modint](modint.hpp)
- 中国剰余定理は [数論](number-theory.hpp)
- 素数判定・素因数分解・原始根は [素数](prime.hpp)
