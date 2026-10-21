---
title: 形式的冪級数の合成と逆関数 (Kinoshita–Li)
documentation_of: //src/math/fps-composition.hpp
---

形式的冪級数の合成 $f(g(x))$ と、合成についての逆関数 ($f(h(x)) = x$ となる $h$) を、Kinoshita–Li の方法で $O(n \log^2 n)$ で求めます。

```cpp
using mint = modint998244353;
FPS<mint> f = {1, 2, 3}, g = {0, 1, 1};
FPS<mint> c = composition(f, g, 4);              // 1 + 2(x + x^2) + 3(x + x^2)^2 = {1, 2, 5, 6}
FPS<mint> h = compositional_inverse(FPS<mint>{0, 1, 1, 1, 1});  // x / (1 - x) の逆関数 x / (1 + x) = {0, 1, -1, 1, -1}
```

## 関数

`deg` を渡すと、結果の $x^{\mathrm{deg}}$ 未満の項 (長さ `deg`) を返します。

| 関数 | 説明 | 条件 | 計算量 |
|---|---|---|---|
| `composition(f, g, deg)` | $f(g(x))$。`deg` を省略するか負の値を渡すと $\max(\lvert f \rvert, \lvert g \rvert)$ | $f$ は多項式として扱うので、$g_0 \neq 0$ でもよい (そのときは $\lvert f \rvert$ が法より小さいこと) | $O(n \log^2 n)$ ($n = \mathrm{deg}$。$g_0 \neq 0$ なら $O(\lvert f \rvert \log \lvert f \rvert)$ を足す) |
| `compositional_inverse(f, deg)` | $f(h(x)) = x$ となる $h$ ($h(f(x)) = x$ でもある)。`deg` を省略するか負の値を渡すと $\lvert f \rvert$ | $f_0 = 0$、$f_1 \neq 0$、`deg` が法より小さい | $O(n \log^2 n)$ ($n = \mathrm{deg}$) |

- $g$ の累乗の重み付き和 $\sum_k w_k [x^k] g^i$ ($i = 0, 1, \dots$) は、$[x^{n-1}] \frac{W(x)}{1 - y g(x)}$ ($W(x) = \sum_k w_k x^{n-1-k}$) の $y$ の係数です。分母と分子に $Q(-x, y)$ を掛けて $x$ の偶数次・奇数次を取り出すと $x$ の次数が半分になる (Bostan-Mori 法) ので、$O(n \log^2 n)$ で求まります。$x$ の項数が半分になるたびに $y$ の項数が倍になるので、各段の大きさは $O(n)$ です。
- 合成 $\sum_i f_i g^i$ は、この計算 ($w$ から $(\sum_k w_k [x^k] g^i)_i$ への線形写像) の転置です。分母の列を先に求め、各段の計算を逆向きに、転置してたどります (積の転置は、両方向を反転した多項式との畳み込みの中央部分)。$g_0 \neq 0$ のときは、$f(x + g_0)$ と $g - g_0$ の合成に直します。
- 逆関数は、$N = \mathrm{deg} - 1$ として、ラグランジュの反転公式 $[x^N] f^k = \frac{k}{N} [x^{N-k}] \left(\frac{x}{h}\right)^N$ を使います。上の計算で $[x^N] f^k$ ($k \le N$) を求めると $(x / h)^N$ がわかり、$N$ 乗根 ($\exp$ と $\log$) と逆数で $h$ が求まります。

2 変数多項式の積は、$y$ の係数を十分な幅で並べて 1 次元の畳み込みにします。`mint` は [modint](modint.hpp) です。積は [畳み込み](convolution.hpp) の `convolution` なので、998244353 以外の法でも動きます。$N = 131072$ で、手元では合成が 3.2 秒、逆関数が 2.7 秒ほどです。

## 関連

- 形式的冪級数の演算は [形式的冪級数](fps.hpp)
- $g$ が $x + a$ のとき ($f(x + a)$) は [形式的冪級数](fps.hpp) の `taylor_shift` が $O(n \log n)$ で速い
- 1 変数の Bostan-Mori 法は [線形漸化式](linear-recurrence.hpp)
