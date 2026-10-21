---
title: 形式的冪級数の合成と逆関数
documentation_of: //src/math/fps-composition.hpp
---

形式的冪級数の合成 $f(g(x))$ と、合成についての逆関数 ($f(h(x)) = x$ となる $h$) を求めます。どちらも $O(n^2)$ 程度なので、$n$ は数千〜1 万程度までです。

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
| `composition(f, g, deg)` | $f(g(x))$。`deg` を省略するか負の値を渡すと $\max(\lvert f \rvert, \lvert g \rvert)$ | $f$ は多項式として扱うので、$g_0 \neq 0$ でもよい | $O(n^2 + n \sqrt n \log n)$ ($n = \max(\lvert f \rvert, \mathrm{deg})$) |
| `compositional_inverse(f, deg)` | $f(h(x)) = x$ となる $h$ ($h(f(x)) = x$ でもある)。`deg` を省略するか負の値を渡すと $\lvert f \rvert$ | $f_0 = 0$、$f_1 \neq 0$ | $O(n^2)$ ($n = \mathrm{deg}$) |

- 合成は、$k = \lceil \sqrt{\lvert f \rvert} \rceil$ として $f = \sum_j \left(\sum_{i < k} f_{jk+i} x^i\right) x^{jk}$ と分けます。$g^0, \dots, g^k$ を求めておき、内側の和を $g^i$ の定数倍の和で、外側を $g^k$ を使う Horner 法で求めます。
- 逆関数は、ニュートン法で $h \leftarrow h - \frac{f(h) - x}{f'(h)}$ と、正しい項の数を倍にしていきます。$h_0 = 0$ なので、$x^{2m}$ 未満を求めるときは $f$ も $x^{2m}$ 未満だけ使います。

`mint` は [modint](modint.hpp) です。積は [畳み込み](convolution.hpp) の `convolution` なので、998244353 以外の法でも動きます。Library Checker の Large 版 ($N \le 131072$) には、$O(n \log^2 n)$ の別の方法 (Kinoshita–Li) が要ります。

## 関連

- 形式的冪級数の演算は [形式的冪級数](fps.hpp)
- $g$ が $x + a$ のとき ($f(x + a)$) は [形式的冪級数](fps.hpp) の `taylor_shift` が $O(n \log n)$ で速い
