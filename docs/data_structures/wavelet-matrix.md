---
title: Wavelet Matrix
documentation_of: //src/data_structures/wavelet-matrix.hpp
---

静的な列に対して、区間の $k$ 番目に小さい値や、区間内で値が $[\mathit{lower}, \mathit{upper})$ にある要素の個数を $O(\log \sigma)$ で求めます ($\sigma$ は値の種類数)。値は座標圧縮して持つので、負の値や大きい値もそのまま使えます。値の型は `<` で比べられれば何でもかまいません。

```cpp
WaveletMatrix wm(std::vector<long long>{3, 1, 4, 1, 5});
wm.kth_smallest(1, 4, 0);   // 1 ([1, 4, 1] の 0 番目)
wm.kth_largest(0, 5, 0);    // 5
wm.count(0, 5, 1);          // 2 (値が 1 の要素)
wm.count(0, 5, 2, 5);       // 2 (値が [2, 5) の要素: 3 と 4)
wm.prev_value(0, 5, 3);     // 1 (3 未満で最大)
wm.next_value(0, 5, 2);     // 3 (2 以上で最小)

// 重みの和も求める (矩形和: x 座標の順に並べた点の y 座標を値、重さを重みにする)
WeightedWaveletMatrix wm2(ys, ws);
wm2.sum(l, r, d, u);        // x 座標が [l, r) 番目、y 座標が [d, u) の点の重さの和
```

添字・個数は `long long` です。

## `WaveletMatrix<T>` のメンバ関数

$n$ を要素数、$\sigma$ を値の種類数とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `WaveletMatrix(v)` | 列 `v` から作る | $O(n \log \sigma)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `wm[k]` | `k` 番目の値 | $O(\log \sigma)$ |
| `kth_smallest(l, r, k)` | $[l, r)$ を小さい順に並べたときの `k` 番目 (0-indexed) の値 | $O(\log \sigma)$ |
| `kth_largest(l, r, k)` | $[l, r)$ を大きい順に並べたときの `k` 番目 (0-indexed) の値 | $O(\log \sigma)$ |
| `count(l, r, x)` | $[l, r)$ の、値が `x` の要素の個数 | $O(\log \sigma)$ |
| `count(l, r, lower, upper)` | $[l, r)$ の、値が $[\mathit{lower}, \mathit{upper})$ にある要素の個数 | $O(\log \sigma)$ |
| `prev_value(l, r, upper)` | $[l, r)$ の、`upper` 未満で最大の値 (なければ `std::nullopt`) | $O(\log \sigma)$ |
| `next_value(l, r, lower)` | $[l, r)$ の、`lower` 以上で最小の値 (なければ `std::nullopt`) | $O(\log \sigma)$ |

## `WeightedWaveletMatrix<T, W>` のメンバ関数

`WaveletMatrix<T>` の関数に加えて、重みの和を求めます。重みの型 `W` を省くと、`T` が整数なら `long long`、そうでなければ `T` になります。メモリは `WaveletMatrix` より $(\log \sigma + 1)(n + 1)$ 個の `W` だけ多く使います。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `WeightedWaveletMatrix(v)` | 列 `v` から作る。値そのものを重みにする | $O(n \log \sigma)$ |
| `WeightedWaveletMatrix(v, w)` | 列 `v` と各要素の重み `w` から作る | $O(n \log \sigma)$ |
| `sum(l, r)` | $[l, r)$ のすべての要素の重みの和 | $O(1)$ |
| `sum(l, r, lower, upper)` | $[l, r)$ の、値が $[\mathit{lower}, \mathit{upper})$ にある要素の重みの和 | $O(\log \sigma)$ |
| `sum_smallest(l, r, k)` | $[l, r)$ を値の小さい順に並べたときの、先頭 `k` 個の重みの和 (同じ値は前にある要素から数える) | $O(\log \sigma)$ |
| `sum_largest(l, r, k)` | $[l, r)$ を値の大きい順に並べたときの、先頭 `k` 個の重みの和 (同じ値は後ろにある要素から数える) | $O(\log \sigma)$ |

## 関連

- 列を更新したいなら [2次元セグメント木](segtree-2d.hpp) (更新する点を先読みする)
- 区間内の値の範囲の積 (和以外の群) なら [マージソートツリー](merge-sort-tree.hpp) ($O(\log^2 n)$)
- 過去の版を使う問題なら [永続セグメント木](persistent-segtree.hpp)
