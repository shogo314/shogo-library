---
title: 部分集合・上位集合のゼータ変換、メビウス変換とビット演算 (AND・OR・XOR) の畳み込み、部分集合畳み込み
documentation_of: //src/math/bitwise-transform.hpp
---

添字を集合 (ビット列) とみて、部分集合・上位集合について和をとる変換と、その逆変換です。配列 `a` の長さ $N$ は 2 の累乗 ($N = 2^n$) で、添字 $S$ は $n$ 個の要素の集合を表します。値の型 `T` は `+`、`-`、`*` が使えれば何でもよく、`long long` や modint を想定しています。

ビットごとに「$S$ と $S$ からそのビットを除いたもの」の間で足すことを繰り返して計算します。

```cpp
std::vector<long long> a = {1, 2, 3, 4}, b = {5, 6, 7, 8};
auto c = and_convolution(a, b);  // {103, 52, 73, 32}
auto d = or_convolution(a, b);   // {5, 28, 43, 184}
auto e = xor_convolution(a, b);  // {70, 68, 62, 60}
auto f = subset_convolution(a, b);  // {5, 16, 22, 60}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_zeta(a)` | $a_S \leftarrow \sum_{T \subseteq S} a_T$ (その場で書き換える) | $O(N \log N)$ |
| `subset_mobius(a)` | `subset_zeta` の逆変換 | $O(N \log N)$ |
| `superset_zeta(a)` | $a_S \leftarrow \sum_{S \subseteq T} a_T$ (その場で書き換える) | $O(N \log N)$ |
| `superset_mobius(a)` | `superset_zeta` の逆変換 | $O(N \log N)$ |
| `walsh_hadamard(a, inverse = false)` | アダマール変換 $a_S \leftarrow \sum_T (-1)^{\lvert S \cap T \rvert} a_T$。`inverse = true` なら逆変換 (最後に $N$ で割る) | $O(N \log N)$ |
| `and_convolution(a, b)` | $c_k = \sum_{i \mathbin{\&} j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `or_convolution(a, b)` | $c_k = \sum_{i \mid j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `xor_convolution(a, b)` | $c_k = \sum_{i \oplus j = k} a_i b_j$ を返す | $O(N \log N)$ |
| `subset_convolution(a, b)` | $c_k = \sum_{i \mid j = k,\ i \mathbin{\&} j = 0} a_i b_j$ を返す ($k$ を 2 つの交わらない集合に分ける) | 時間 $O(N \log^2 N)$、メモリ $O(N \log N)$ |

- `a` と `b` は同じ長さで、長さが 2 の累乗でないと assert で落ちます。
- `xor_convolution` と `walsh_hadamard(a, true)` は最後に $N$ で割ります。modint や浮動小数点数では $N$ の逆数を掛け、整数型では $N$ で割ります (結果が整数なので割り切れます)。

## 例: 部分集合についての和

bit DP で「$S$ の部分集合 $T$ すべてについての $f(T)$ の和」を、すべての $S$ について求めたいとき、部分集合を列挙すると $O(3^n)$ かかります。`subset_zeta` を使えば $O(n 2^n)$ です。

```cpp
std::vector<long long> f(1 << n);
// f[T] を入れる
subset_zeta(f);  // f[S] = sum_{T ⊆ S} f[T]
```

上位集合についての和は `superset_zeta` です。「ちょうど $S$」の値が欲しいときは、「$S$ の部分集合 (上位集合) すべて」の値を求めてからメビウス変換をします (包除原理)。

## 部分集合畳み込みの仕組み

$i \mathbin{\&} j = 0$ かつ $i \mid j = k$ は、$\lvert i \rvert + \lvert j \rvert = \lvert k \rvert$ かつ $i \mid j = k$ と同じです。そこで、各集合 $S$ について要素数ごとに値を分け (`f[S][|S|] = a[S]`)、要素数ごとに部分集合のゼータ変換をしてから、$S$ ごとに要素数についての多項式として掛けます。最後にメビウス変換をして、$S$ の要素数の位置の値を取り出します (ランク付きゼータ変換)。

$n = 20$ ($N = 2^{20}$) のとき、`T` が 4 バイトの modint なら、内部の表は 2 つで約 180 MB です。

```cpp
// dp[S] = S を交わらない 2 つの集合に分けたときの、cost の積の和
auto dp = subset_convolution(cost, cost);
```

## 関連

- 部分集合や上位集合を 1 つずつ列挙するには [ビット演算](../utility/bit.hpp) の `subsets`、`supersets`
- 添字の約数・倍数についての変換は [約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込み](divisor-transform.hpp)
