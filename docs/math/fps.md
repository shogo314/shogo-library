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

`deg` を取る関数は、結果の $x^{\mathrm{deg}}$ 未満の項を返します。`deg`、`pre(k)` の `k`、シフト量 `k` は `long long` です。`inv`・`log`・`exp`・`pow`・`sqrt` は、`deg` を省略するか負の値を渡すと `deg = f.size()` になります。

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
| `sqrt(f, deg)` | $g^2 = f$ となる $g$ の先頭 `deg` 項 (`std::optional<FPS>`)。$f = 0$ なら 0。最初の 0 でない項が奇数次か、その係数が平方非剰余なら、平方根がないので `deg` によらず `std::nullopt` | 法は素数 | $O(n \log n)$ |
| `taylor_shift(f, a)` | $f(x + a)$ | $n$ が mod より小さい | $O(n \log n)$ |
| `divmod(f, g)` | `std::pair` で商 `f / g` と余り `f % g` を返す (`/` と `%` を別々に使うより速い) | `g` の最高次の係数が 0 でない | $O(n \log n)$ |
| `gcd(f, g)` | 多項式の gcd (最高次の係数が 1。$f, g$ がともに 0 なら 0 (空)) | | $O(n \log^2 n)$ |
| `extgcd(f, g, a, b)` | $af + bg = \gcd(f, g)$ となる `a`、`b` (末尾の 0 を取り除いた形) を求め、`gcd(f, g)` を返す。$f, g$ がともに 0 なら `a`、`b` も 0 | | $O(n \log^2 n)$ |
| `modinv(f, g)` | $fh \equiv 1 \pmod g$ で $\deg h < \deg g$ となる $h$ (`std::optional<FPS>`)。$\gcd(f, g)$ が定数でなければ `std::nullopt`。$g$ が定数なら $h = 0$ (空) | $g \neq 0$ | $O(n \log^2 n)$ |
| `modpow(f, e, m)` | $f^e \bmod m$ (多項式の余り) | | $O(\lvert m \rvert \log \lvert m \rvert \log e)$ |
| `polynomial_product(fs)` | 多項式の列 `fs` (`std::vector<FPS>`) の積。次数の小さいものから 2 つずつ掛ける。`fs` が空なら 1 | | $O(N \log^2 N)$ ($N$ は次数の和) |
| `sum_of_fractions(nums, dens)` | 分数の和 $\sum_i \mathit{nums}_i / \mathit{dens}_i$ を 1 つの分数にまとめ、`std::pair` で {分子, 分母} を返す。分母は `dens` の積。半分ずつに分けて $a/b + c/d = (ad + cb)/bd$ とまとめる。空なら $0 / 1$ | | $O(N \log^2 N)$ ($N$ は長さの和) |

法が NTT に向く素数 (998244353 など) なら、`inv` と `exp` は NTT した値を使い回して倍々に伸ばします (`inv` は 1 段あたり長さ $2m$ の NTT 5 回、`exp` は $\exp f$ と $1 / \exp f$ を同時に伸ばす)。`log`・`pow`・`sqrt` もこれらを通して速くなり、$n = 5 \times 10^5$ の `exp` は 0.2 秒ほどです。それ以外の法では畳み込みを繰り返す実装を使います。

`gcd`・`extgcd`・`modinv` は Half-GCD を使います。互除法 $(p, q) \to (q, p \bmod q)$ の変換を $2 \times 2$ の多項式行列で持ち、長さ $n$ の $p$ に対して、長さが $\lceil n / 2 \rceil$ 以下になるまでの行列を上位の半分の係数だけから再帰的に求めます。法は素数であることが必要です。整数の [`modinv`](modular-arithmetic.hpp) は互いに素でないと assert で止まりますが、多項式の `modinv` は `std::nullopt` を返します。

## 関連

- 積に使う畳み込みは [畳み込み](convolution.hpp)
- 係数の型は [modint](modint.hpp)、`taylor_shift` の階乗は [組み合わせ](combinatorics.hpp)
- 線形漸化式の第 k 項 (Bostan-Mori) や漸化式の復元 (Berlekamp-Massey) は [線形漸化式](linear-recurrence.hpp)
- 0 でない項が少ない $f$ の `inv`・`log`・`exp`・`pow`・`sqrt` は [疎な形式的冪級数](sparse-fps.hpp) の方が速い
- 多点評価・多項式補間 (等比数列の点も)・標本点のずらしは [多点評価・多項式補間](multipoint.hpp)
- 分割数・ベルヌーイ数・スターリング数・ベル数は [分割数・ベルヌーイ数・スターリング数・ベル数](combinatorial-sequences.hpp)
- 整数の拡張ユークリッドの互除法 `extgcd` は [汎用関数](../base/functions.hpp)
- 有限体上の多項式の根は [多項式の根](polynomial-roots.hpp)
- 合成 $f(g(x))$ と合成についての逆関数は [形式的冪級数の合成と逆関数](fps-composition.hpp)
