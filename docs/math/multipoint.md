---
title: 多点評価・多項式補間・標本点のずらし (等比数列の点も)
documentation_of: //src/math/multipoint.hpp
---

多項式の値をたくさんの点でまとめて求める (多点評価)、点と値の組から多項式を求める (補間)、$f(0), \dots, f(n - 1)$ から $f(c), \dots, f(c + m - 1)$ を求める (標本点のずらし) 関数です。点が等比数列 $a, ar, ar^2, \dots$ のときは、より速い chirp-z 変換の版があります。

```cpp
using mint = modint998244353;
FPS<mint> f = {1, 2, 3};                                         // 1 + 2x + 3x^2
std::vector<mint> v = multipoint_evaluation(f, {0, 1, 2});       // {1, 6, 17}
std::vector<mint> xs = {0, 1, 2}, ys = {1, 6, 17};
FPS<mint> g = polynomial_interpolation(xs, ys);                  // {1, 2, 3}
std::vector<mint> w = sample_point_shift(ys, mint(100), 3);      // f(100), f(101), f(102)
std::vector<mint> u = multipoint_evaluation_geometric(f, mint(1), mint(2), 3);  // f(1), f(2), f(4) = {6, 17, 57}
FPS<mint> h = polynomial_interpolation_geometric(mint(1), mint(2), u);  // {1, 2, 3}
```

## 関数

`mint` は [modint](modint.hpp) で、法は NTT が使える素数 (998244353 など) を想定しています (畳み込みは [畳み込み](convolution.hpp) の `convolution` なので、他の法でも動きます)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `multipoint_evaluation(f, xs)` | 多項式 `f` ([`FPS<mint>`](fps.hpp)) の、点 `xs` (`std::vector<mint>`) での値。点は重なってもよい | $O((n + m) \log^2 (n + m))$ |
| `polynomial_interpolation(xs, ys)` | 点 $(x_i, y_i)$ をすべて通る $n - 1$ 次以下の多項式 (長さ $n$ の `FPS<mint>`)。$x_i$ は互いに異なること | $O(n \log^2 n)$ |
| `sample_point_shift(ys, c, m)` | $n - 1$ 次以下の多項式 $f$ の $f(0), \dots, f(n - 1)$ (`ys`) から、$f(c), \dots, f(c + m - 1)$。法は $n + m$ より大きい素数であること | $O((n + m) \log (n + m))$ |
| `multipoint_evaluation_geometric(f, a, r, m)` | 等比数列の点 $a r^i$ ($0 \le i < m$) での `f` の値。$a$、$r$ は 0 でもよい | $O((n + m) \log (n + m))$ |
| `polynomial_interpolation_geometric(a, r, ys)` | 点 $(a r^i, y_i)$ ($0 \le i < n$) をすべて通る $n - 1$ 次以下の多項式 (長さ $n$)。$a r^i$ は互いに異なること | $O(n \log n)$ |
| `weighted_power_sums(xs, ws, n)` | 重み付きの累乗和 $s_k = \sum_i w_i x_i^k$ ($0 \le k < n$) を `std::vector<mint>` で返す。$\sum_k s_k t^k = \sum_i w_i / (1 - x_i t)$ を [`sum_of_fractions`](fps.hpp) でまとめて求める (多点評価の転置)。点は重なってもよい | $O(m \log^2 m + n \log n)$ ($m$ は点の個数) |

- 多点評価は、各点の $(x - x_i)$ の積を木の形に持つ subproduct tree を作り、根から各頂点の多項式で割った余りを下ろしていきます。受け持つ点が 32 個以下になったら、余りを Horner 法で直接計算します。
- 補間は、$g = \prod (x - x_i)$ とすると $f = \sum_i y_i / g'(x_i) \prod_{j \ne i} (x - x_j)$ なので、$g'(x_i)$ を多点評価し、和を subproduct tree の下から組み立てます。
- 標本点のずらしは、ラグランジュ補間の式 $f(c + k) = \left(\prod_{j < n} (c + k - j)\right) \sum_i \frac{a_i}{c + k - i}$ ($a_i = y_i / (i! (n - 1 - i)! (-1)^{n-1-i})$) の和を畳み込みで求めます。$c + k$ が $0$ 以上 $n$ 未満の整数と重なる (法を回って重なる場合も) ところは分母が 0 になるので `ys` をそのまま使い、残りの区間ごとに畳み込みます。
- 等比数列の点での多点評価は、$ij = \binom{i+j}{2} - \binom{i}{2} - \binom{j}{2}$ を使うと $f(ar^i) = r^{-\binom{i}{2}} \sum_j \left(f_j a^j r^{-\binom{j}{2}}\right) r^{\binom{i+j}{2}}$ となるので、畳み込み 1 回で求まります (chirp-z 変換)。
- 等比数列の点での補間は、$M = \prod_j (x - x_j)$、$w_i = y_i / \prod_{j \ne i} (x_i - x_j)$ として $f = M \sum_i w_i / (x - x_i)$ を使います。$\prod_{j \ne i} (x_i - x_j)$ は $\prod_{t=1}^{k} (r^t - 1)$ の形の積で $O(n)$ で求まり、和の $x^k$ の係数 $-a^{-(k+1)} \sum_i w_i r^{-i(k+1)}$ は等比数列の点 $r^{-(k+1)}$ での多点評価です。$M$ は前半から後半を $\prod_{j<k} (x - ar^{j+k}) = r^{k^2} M_k(x r^{-k})$ で作って倍々に求めます。

## 関連

- 標本点が $0, \dots, n - 1$ で 1 点だけ求めるなら [ラグランジュ補間](lagrange-interpolation.hpp) の方が軽い ($O(n)$)
- 多項式の演算は [形式的冪級数](fps.hpp)
- `weighted_power_sums` は、$\sum_t c_t e^{tx}$ の係数を求めるのにも使える ($k! [x^k] = \sum_t c_t t^k$)。$H(e^x - 1)$ は $P(z) = H(z - 1)$ (`taylor_shift`) として $P(e^x)$ に直せる
