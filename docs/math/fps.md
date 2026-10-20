---
title: 形式的冪級数
documentation_of: //src/math/fps.hpp
---

`std::vector<mint>` を継承した形式的冪級数 `FPS<mint>` です。`f[i]` が $x^i$ の係数です。掛け算は [畳み込み](convolution.hpp) の `convolution` を使うので、mod は 998244353 以外でもかまいません (998244353 のときが速い)。

```cpp
using mint = static_modint<998244353>;
FPS<mint> f = {1, 1};          // 1 + x
auto g = inv(f, n);            // 1 / (1 + x) の x^n 未満
auto h = pow(f, 10, n);        // (1 + x)^10 の x^n 未満
mint y = f.eval(2);            // f(2)
```

`deg` を取る関数は、結果の $x^{\mathrm{deg}}$ 未満の項を返します。`deg`、`pre(k)` の `k`、シフト量 `k` は `long long` です。`deg` を省略するか負の値を渡すと `f.size()` になります。

## 演算子

| 演算子 | 説明 | 計算量 |
|---|---|---|
| `f + g`、`f - g`、`-f` | 和・差 (結果の末尾の 0 は取り除かれる) | $O(n)$ |
| `f + c`、`f - c` | 定数項に足す・引く | $O(1)$ |
| `f * c`、`f / c` | 定数倍 | $O(n)$ |
| `f * g` | 積 | $O(n \log n)$ |
| `f / g`、`f % g` | 多項式としての商・余り (`g` の最高次の係数は 0 でないこと) | $O(n \log n)$ |
| `f << k` / `f >> k` | $x^k$ を掛ける / $x^k$ で割って低次の項を捨てる (`f >> k` は長さが $k$ 以下なら `{0}` になる) | $O(n)$ |

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `f.pre(k)` | $x^k$ 未満の項 | $O(k)$ |
| `f.rev()` | 係数を逆順にしたもの | $O(n)$ |
| `f.normalize()` | 末尾の 0 を取り除く (その場で) | $O(n)$ |
| `f.eval(a)` | $f(a)$ (const でないメンバ関数なので、const な `FPS` には使えない) | $O(n)$ |

## 関数

| 関数 | 説明 | 条件 | 計算量 |
|---|---|---|---|
| `diff(f)` | 微分 $f'$ | | $O(n)$ |
| `intg(f)` | 積分 $\int f \, dx$ (定数項 0) | | $O(n)$ |
| `inv(f, deg)` | $1 / f$ | $f_0 \neq 0$ | $O(n \log n)$ |
| `log(f, deg)` | $\log f$ | $f_0 = 1$ | $O(n \log n)$ |
| `exp(f, deg)` | $\exp f$ | $f_0 = 0$ | $O(n \log n)$ |
| `pow(f, e, deg)` | $f^e$ | | $O(n \log n)$ |
| `taylor_shift(f, a)` | $f(x + a)$ | $n$ が mod より小さい | $O(n \log n)$ |
| `divmod(f, g)` | `std::pair` で商 `f / g` と余り `f % g` を返す (`/` と `%` を別々に使うより速い) | `g` の最高次の係数が 0 でない | $O(n \log n)$ |
| `gcd(f, g)` | 多項式の gcd | | $O(n^2 \log n)$ |
| `modpow(f, e, m)` | $f^e \bmod m$ (多項式の余り) | | $O(\lvert m \rvert \log \lvert m \rvert \log e)$ |

## 関連

- 積に使う畳み込みは [畳み込み](convolution.hpp)
- 係数の型は [modint](modint.hpp)、`taylor_shift` の階乗は [組み合わせ](combinatorics.hpp)
- 線形漸化式の第 k 項 (Bostan-Mori) や漸化式の復元 (Berlekamp-Massey) は [線形漸化式](linear-recurrence.hpp)
