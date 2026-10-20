---
title: 多点評価・多項式補間・標本点のずらし
documentation_of: //src/math/multipoint.hpp
---

多項式の値をたくさんの点でまとめて求める (多点評価)、点と値の組から多項式を求める (補間)、$f(0), \dots, f(n - 1)$ から $f(c), \dots, f(c + m - 1)$ を求める (標本点のずらし) 関数です。

```cpp
using mint = modint998244353;
FPS<mint> f = {1, 2, 3};                                         // 1 + 2x + 3x^2
std::vector<mint> v = multipoint_evaluation(f, {0, 1, 2});       // {1, 6, 17}
std::vector<mint> xs = {0, 1, 2}, ys = {1, 6, 17};
FPS<mint> g = polynomial_interpolation(xs, ys);                  // {1, 2, 3}
std::vector<mint> w = sample_point_shift(ys, mint(100), 3);      // f(100), f(101), f(102)
```

## 関数

`mint` は [modint](modint.hpp) で、法は NTT が使える素数 (998244353 など) を想定しています (畳み込みは [畳み込み](convolution.hpp) の `convolution` なので、他の法でも動きます)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `multipoint_evaluation(f, xs)` | 多項式 `f` ([`FPS<mint>`](fps.hpp)) の、点 `xs` (`std::vector<mint>`) での値。点は重なってもよい | $O((n + m) \log^2 (n + m))$ |
| `polynomial_interpolation(xs, ys)` | 点 $(x_i, y_i)$ をすべて通る $n - 1$ 次以下の多項式 (長さ $n$ の `FPS<mint>`)。$x_i$ は互いに異なること | $O(n \log^2 n)$ |
| `sample_point_shift(ys, c, m)` | $n - 1$ 次以下の多項式 $f$ の $f(0), \dots, f(n - 1)$ (`ys`) から、$f(c), \dots, f(c + m - 1)$。法は $n + m$ より大きい素数であること | $O((n + m) \log (n + m))$ |

- 多点評価は、各点の $(x - x_i)$ の積を木の形に持つ subproduct tree を作り、根から各頂点の多項式で割った余りを下ろしていきます。受け持つ点が 32 個以下になったら、余りを Horner 法で直接計算します。
- 補間は、$g = \prod (x - x_i)$ とすると $f = \sum_i y_i / g'(x_i) \prod_{j \ne i} (x - x_j)$ なので、$g'(x_i)$ を多点評価し、和を subproduct tree の下から組み立てます。
- 標本点のずらしは、ラグランジュ補間の式 $f(c + k) = \left(\prod_{j < n} (c + k - j)\right) \sum_i \frac{a_i}{c + k - i}$ ($a_i = y_i / (i! (n - 1 - i)! (-1)^{n-1-i})$) の和を畳み込みで求めます。$c + k$ が $0$ 以上 $n$ 未満の整数と重なる (法を回って重なる場合も) ところは分母が 0 になるので `ys` をそのまま使い、残りの区間ごとに畳み込みます。

## 関連

- 標本点が $0, \dots, n - 1$ で 1 点だけ求めるなら [ラグランジュ補間](lagrange-interpolation.hpp) の方が軽い ($O(n)$)
- 多項式の演算は [形式的冪級数](fps.hpp)
