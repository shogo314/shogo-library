---
title: 多項式の拡張ユークリッドの互除法と逆元 (Half-GCD)
documentation_of: //src/math/polynomial-gcd.hpp
---

多項式 $f, g$ について、$af + bg = \gcd(f, g)$ となる $a, b$ と、$g$ を法とする $f$ の逆元 ($fh \equiv 1 \pmod g$ となる $h$) を求めます。Half-GCD を使うので $O(n \log^2 n)$ です。

```cpp
using mint = modint998244353;
FPS<mint> f = {1, 1}, g = {1, 0, 1};    // 1 + x, 1 + x^2
FPS<mint> a, b;
FPS<mint> d = extgcd(f, g, a, b);       // d = {1}、a f + b g = 1
std::optional<FPS<mint>> h = modinv(f, g);  // (1 + x) h ≡ 1 (mod 1 + x^2) となる h = (1 - x) / 2
```

## 関数

結果の多項式 (`FPS<mint>`) は、どれも末尾の 0 を取り除いた形です (0 は空)。

| 関数 | 説明 | 条件 | 計算量 |
|---|---|---|---|
| `extgcd(f, g, a, b)` | $af + bg = d$ となる `a`、`b` を求め、$d = \gcd(f, g)$ (最高次の係数が 1) を返す。$f, g$ がともに 0 なら $d = a = b = 0$ | | $O(n \log^2 n)$ |
| `modinv(f, g)` | $fh \equiv 1 \pmod g$ で $\deg h < \deg g$ となる $h$ (`std::optional<FPS<mint>>`)。$\gcd(f, g)$ が定数でなければ `std::nullopt`。$g$ が定数なら $h = 0$ | $g \neq 0$ | $O(n \log^2 n)$ |

- 互除法 $(p, q) \to (q, p \bmod q)$ の変換を $2 \times 2$ の多項式行列で持ちます。長さ $n$ の $p$ に対し、長さが $\lceil n / 2 \rceil$ 以下になるまでの行列を、上位の半分の係数だけを使って再帰的に求めます (Half-GCD)。
- 整数の [`modinv`](modular-arithmetic.hpp) は互いに素でないと assert で止まりますが、多項式の `modinv` は `std::nullopt` を返します。

`mint` は [modint](modint.hpp) で、法は素数であることが必要です。[形式的冪級数](fps.hpp) の `gcd` は素朴な互除法 ($O(n^2 \log n)$) なので、次数が大きいときは `extgcd` の方が速いです。

## 関連

- 多項式の演算と素朴な `gcd` は [形式的冪級数](fps.hpp)
- 整数の拡張ユークリッドの互除法 `extgcd` は [汎用関数](../base/functions.hpp)
