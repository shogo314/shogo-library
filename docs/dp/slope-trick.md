---
title: Slope Trick
documentation_of: //src/dp/slope-trick.hpp
---

凸な区分線形関数 $f$ を、傾きが変わる点の多重集合として持ちます (Slope Trick)。$f$ に $\lvert x - a \rvert$ などを足す操作と、累積の最小値をとる操作・平行移動が速くできるので、値の動かし方を状態にする DP を速くするのに使います。はじめは $f(x) = 0$ です。

```cpp
// 列 A を非減少な列 B に変える最小コスト Σ|A_i - B_i|
SlopeTrick<long long> st;
for (long long a : A) {
    st.prefix_min();  // B_{i-1} 以上なら B_i はどこでもよい: f(x) を min_{y <= x} f(y) にする
    st.add_abs(a);    // |x - A_i| を足す
}
long long cost = st.min();
```

狭義単調増加にしたいときは、$A_i - i$ を非減少にする問題に直して使います。

最小値をとる区間より左の点を最大ヒープ、右の点を最小ヒープに入れ、平行移動の量はまとめて持ちます。$n$ は今までに足した関数の個数です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SlopeTrick<T>()` | $f(x) = 0$ (`T` は符号付き整数) | $O(1)$ |
| `min()` | $f$ の最小値 | $O(1)$ |
| `argmin()` | $f$ が最小値をとる区間 $[\mathit{lower}, \mathit{upper}]$ (`std::pair`)。端がなければ `-inf()`、`inf()` | $O(1)$ |
| `get(x)` | $f(x)$ | $O(n \log n)$ |
| `add_constant(a)` | $f$ に $a$ を足す | $O(1)$ |
| `add_x_minus_a(a)` | $f$ に $\max(0, x - a)$ を足す | $O(\log n)$ |
| `add_a_minus_x(a)` | $f$ に $\max(0, a - x)$ を足す | $O(\log n)$ |
| `add_abs(a)` | $f$ に $\lvert x - a \rvert$ を足す | $O(\log n)$ |
| `prefix_min()` | $f(x)$ を $\min_{y \le x} f(y)$ にする | $O(1)$ |
| `suffix_min()` | $f(x)$ を $\min_{y \ge x} f(y)$ にする | $O(1)$ |
| `shift(a, b)` | $f(x)$ を $\min_{x - b \le y \le x - a} f(y)$ にする ($a \le b$)。最小値をとる区間より左を $a$、右を $b$ だけ右にずらす | $O(1)$ |
| `shift(a)` | $f(x)$ を $f(x - a)$ にする | $O(1)$ |
| `inf()` | 端がないことを表す値 `std::numeric_limits<T>::max() / 4` (static) | $O(1)$ |

## 関連

- 凸関数どうしの (min, +) 畳み込みは [Monge 性を使う DP の高速化](monge.hpp) の `min_plus_convolution_convex_convex`
