---
title: Convex Hull Trick
documentation_of: //src/data_structures/convex-hull-trick.hpp
---

直線・線分を追加し、ある $x$ での最小値を求める Li Chao Tree `LiChaoTree<T>` です。追加する傾きは単調でなくてもかまいません。

使う $x$ 座標 (最小値を求める $x$ と、線分の両端) を先読みしてソートした配列を渡し、以降は $x$ をその配列の添字で指定します。

```cpp
std::vector<long long> xs = {-2, 0, 1, 5};
LiChaoTree<long long> cht(xs);
cht.add_line(1, 0);             // y = x
cht.add_segment(-1, 3, 1, 3);   // y = -x + 3 (x ∈ [xs[1], xs[3]) = [0, 5))
cht.get_min(2);                 // x = xs[2] = 1 での最小値: 1
```

最大値を求めたい場合は、傾きと切片の符号を反転して追加し、結果の符号を戻します。

## メンバ関数

$n$ を `xs` の長さとします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LiChaoTree(xs)` | ソート済みの $x$ 座標の配列から作る | $O(n)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log n)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [\mathrm{xs}_l, \mathrm{xs}_r)$) を追加 | $O(\log^2 n)$ |
| `get_min(i)` | $x = \mathrm{xs}_i$ での最小値。直線がなければ `std::numeric_limits<T>::max()` | $O(\log n)$ |
