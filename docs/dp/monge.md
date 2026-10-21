---
title: Monge 性を使う DP の高速化 (monotone minima・(min, +) 畳み込み・Alien DP・Knuth–Yao)
documentation_of: //src/dp/monge.hpp
---

Monge 性や凸性を使って DP を速くする道具です。

- `monotone_minima`: 各行の最小値の位置が単調な行列について、各行の最小値の位置を $O((H + W) \log H)$ で求めます。DP の遷移 $\mathrm{dp}_i = \min_j (\ldots)$ の最適な $j$ が $i$ について単調なときに使います。
- `min_plus_convolution_*`: $c_k = \min_{i + j = k} (a_i + b_j)$ を、片方が凸なら $O((N + M) \log (N + M))$、両方が凸なら $O(N + M)$ で求めます。
- `alien_dp`: 「ちょうど $k$ 個選ぶ」という制約のある最小化を、答えが $k$ について凸なら、1 個選ぶごとにペナルティ $\lambda$ を足した制約のない問題に直して、$\lambda$ を二分探索して解きます (Alien DP、Lagrange 緩和)。

```cpp
// 各行の最小値の位置 (Monge な行列)
auto arg = monotone_minima(H, W, [&](long long i, long long j) { return cost(i, j); });

// (min, +) 畳み込み (a は凸、b は任意)
std::vector<long long> c = min_plus_convolution_convex_arbitrary(a, b);

// 配列を連続するちょうど k 個の区間に分け、区間ごとのコストの和を最小にする (答えが k について凸のとき)
long long ans = alien_dp(k, -1000000000000LL, 1000000000000LL, [&](long long lambda) {
    // 区間 1 つにつき lambda を足し、区間の個数は自由にした DP。{最小値, 最小値をとる区間の個数のうち最小} を返す
    std::vector<std::pair<long long, long long>> e(n + 1, {INF, 0});
    e[0] = {0, 0};
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++) e[i] = std::min(e[i], {e[j].first + cost(j, i) + lambda, e[j].second + 1});
    return e[n];
});
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `monotone_minima(H, W, f)` | $H$ 行 $W$ 列の行列 (成分は `f(i, j)`) の各行の最小値の位置 (同じ値なら最も左) を `std::vector<long long>` で返す。最小値の位置が行について単調非減少であること (Monge な行列ならよい) | $O((H + W) \log H)$ 回の `f` |
| `monotone_minima_select(H, W, select)` | 上と同じだが、比べ方を `select(i, j, k)` ($j < k$、行 $i$ で列 $k$ が列 $j$ より真に小さいなら `true`) で渡す。範囲外の成分を「選ばない」としたいときに使う | 同上 |
| `min_plus_convolution_convex_arbitrary(a, b)` | $c_k = \min_{i + j = k} (a_i + b_j)$。`a` が凸 ($a_{i+1} - a_i$ が単調非減少) で、`b` は任意 | $O((N + M) \log (N + M))$ |
| `min_plus_convolution_convex_convex(a, b)` | 同じ $c$。`a`、`b` がともに凸。差分を小さい順に併合する | $O(N + M)$ |
| `alien_dp(k, lo, hi, solve)` | ちょうど $k$ 個選ぶときの最小値 $f(k)$ ($f$ は凸で、$f(x+1) - f(x)$ は整数) | `solve` を $O(\log (hi - lo))$ 回 |
| `knuth_yao(n, base, w)` | 区間 DP $\mathit{dp}[i][j] = \min_{i < k < j} (\mathit{dp}[i][k] + \mathit{dp}[k][j]) + w(i, j)$、$\mathit{dp}[i][i+1] = \mathit{base}(i)$ の表 ($0 \le i < j \le n$) を返す。$w$ が quadrangle inequality と単調性を満たすこと | $O(n^2)$ |

- Monge な行列とは、$i < i'$、$j < j'$ について $f(i, j) + f(i', j') \le f(i, j') + f(i', j)$ を満たすものです。例えば、凸関数 $g$ について $g(x_i - y_j)$ ($x$、$y$ は昇順) や、$a_{i-j}$ ($a$ は凸) は Monge です。
- `alien_dp` の `solve(lambda)` は、$\min_x (f(x) + \lambda x)$ と、その最小値をとる $x$ のうち最小のものの組 `{値, x}` を返します。$\lambda$ は $[lo, hi]$ の整数から二分探索するので、$f$ の傾き $f(x+1) - f(x)$ がすべて $[-hi, -lo]$ に入るようにとります。$\lambda k$ や `solve` の値があふれないように注意します。最大化なら $f$ の符号を反転して使います。
- `alien_dp` は、$x_{\min}(\lambda) \le k$ となる最小の $\lambda$ を探します。傾きが整数なら、そのとき $k$ は最小値をとる $x$ の範囲 $[x_{\min}(\lambda), x_{\min}(\lambda - 1)]$ に入るので、$f(k) = (\text{最小値}) - \lambda k$ です。
- `knuth_yao` の $w$ の条件は、$a \le b \le c \le d$ について $w(a, c) + w(b, d) \le w(a, d) + w(b, c)$ (quadrangle inequality) と $w(b, c) \le w(a, d)$ (単調性) です。このとき最適な $k$ が $\mathit{opt}[i][j-1] \le \mathit{opt}[i][j] \le \mathit{opt}[i+1][j]$ を満たすので、その範囲だけを調べます。非負の数列の区間和や、その 2 乗は条件を満たします。$\mathit{base}$ の値は最適な $k$ に影響しません。
- 石を隣どうし併合するコストの最小化 (区間和の $w$) や、最適二分探索木 (ダミーの鍵を葉とした区間の DP) に使えます。

```cpp
// 石の併合: 隣り合う山を併合するとき、2 つの山の石の個数の和だけコストがかかる
auto dp = knuth_yao(n, [](long long) { return 0LL; }, [&](long long i, long long j) { return s[j] - s[i]; });  // s は累積和
long long cost = dp[0][n];
```

## 関連

- 直線の集合の最小値で遷移するなら [Convex Hull Trick](../data_structures/convex-hull-trick.hpp)
