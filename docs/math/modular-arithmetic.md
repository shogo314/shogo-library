---
title: mod 演算 (積、冪乗、逆元)
documentation_of: //src/math/modular-arithmetic.hpp
---

`long long` の値どうしの mod 演算です。法 `m` は $1 \le m < 2^{63}$ で、途中の積は `__int128` で計算するのであふれません。どれも `constexpr` です。

```cpp
long long x = modinv(3, 7);         // 5
long long y = modpow(2, 10, 1000);  // 24
long long z = modmul(1LL << 62, 4, 1000000007);
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `modmul(a, b, m)` | $ab \bmod m$ (`a`、`b` は負でもよい。結果は $[0, m)$) | $O(1)$ |
| `modinv(a, m)` | $a^{-1} \bmod m$ (`a` と `m` が互いに素でなければ assert で落ちる) | $O(\log m)$ |
| `modpow(a, n, m)` | $a^n \bmod m$ (`n` は負でもよく、そのときは `a` と `m` が互いに素であること) | $O(\log \lvert n \rvert)$ |

## 関連

- `modint` のメンバ関数 `pow`、`inv` は [modint](modint.hpp)
- 中国剰余定理は [数論](number-theory.hpp)
- 素数判定・素因数分解は [素数](prime.hpp)
