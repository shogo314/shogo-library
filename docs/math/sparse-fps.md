---
title: 疎な形式的冪級数 (inv・log・exp・pow・sqrt)
documentation_of: //src/math/sparse-fps.hpp
---

0 でない項が $K$ 個しかない形式的冪級数 $f$ について、$1/f$、$\log f$、$\exp f$、$f^e$、$\sqrt f$ の先頭 $n$ 項を $O(nK)$ で求めます。$K$ が小さい (例えば $f = 1 - x - x^2$ のような短い多項式) なら、[形式的冪級数](fps.hpp) の $O(n \log n)$ の関数より速く、NTT の使えない法でも使えます。

```cpp
using mint = modint998244353;
FPS<mint> f(n);
f[0] = 1, f[1] = -1, f[2] = -1;          // 1 - x - x^2
FPS<mint> fib = sparse_inv(f, n);       // 1 / (1 - x - x^2) (フィボナッチ数)
FPS<mint> g = sparse_pow(f, 1000000000000000000LL, n);
std::optional<FPS<mint>> h = sparse_sqrt(f, n);
```

## 関数

$f$ は [`FPS<mint>`](fps.hpp) で渡し、0 でない項を集めて使います。

| 関数 | 説明 | 条件 | 計算量 |
|---|---|---|---|
| `sparse_inv(f, n)` | $1 / f$ の先頭 $n$ 項 | $f_0 \ne 0$ | $O(nK)$ |
| `sparse_log(f, n)` | $\log f$ の先頭 $n$ 項 | $f_0 = 1$ | $O(nK)$ |
| `sparse_exp(f, n)` | $\exp f$ の先頭 $n$ 項 | $f_0 = 0$ | $O(nK)$ |
| `sparse_pow(f, e, n)` | $f^e$ の先頭 $n$ 項 ($e \ge 0$、$10^{18}$ 程度でもよい) | | $O(nK)$ |
| `sparse_sqrt(f, n)` | $\sqrt f$ の先頭 $n$ 項 (`std::optional`。平方根がなければ `std::nullopt`) | 法は素数 | $O(nK)$ |

求める級数 $g$ が満たす微分方程式の係数を比べて、1 項ずつ求めます。例えば $g = f^e$ なら $f g' = e f' g$ から、$f_0 k g_k = \sum_{i \ge 1} f_i g_{k-i} (e i - (k - i))$ です。`sparse_sqrt` は $e = 1/2$ として同じ式を使います。`sparse_pow`・`sparse_sqrt` は、$f$ の最初の 0 でない項 $f_d x^d$ を外して $f_0 \ne 0$ の場合に直します。

## 関連

- 0 でない項が多いときは [形式的冪級数](fps.hpp) の `inv`・`log`・`exp`・`pow`・`sqrt`
