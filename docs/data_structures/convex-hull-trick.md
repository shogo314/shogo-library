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
*cht.get_min(2);                // x = xs[2] = 1 での最小値: 1
```

最大値を求めたい場合は、傾きと切片の符号を反転して追加し、結果の符号を戻します。

## メンバ関数

$n$ を `xs` の長さとします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LiChaoTree(xs)` | ソート済みの $x$ 座標の配列から作る | $O(n)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log n)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [\mathrm{xs}_l, \mathrm{xs}_r)$) を追加 | $O(\log^2 n)$ |
| `get_min(i)` | $x = \mathrm{xs}_i$ での最小値 (`std::optional<T>`)。$x = \mathrm{xs}_i$ を含む直線・線分がなければ `std::nullopt` | $O(\log n)$ |

## x 座標を先読みしない `DynamicLiChaoTree<T>`

$x$ を $[lo, hi)$ の整数に限る代わりに、座標を先読みしなくてよい版です。必要になった頂点だけを作るので、範囲が $10^9$ 程度でも使えます。クエリを先に読めない (オンラインの) ときに使います。

```cpp
DynamicLiChaoTree<long long> cht(-1000000000, 1000000001);  // x ∈ [-10^9, 10^9]
cht.add_line(2, 3);             // y = 2x + 3
cht.add_segment(-1, 0, 0, 10);  // y = -x (x ∈ [0, 10))
*cht.get_min(5);                // -5
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DynamicLiChaoTree(lo, hi)` | $x$ が $[lo, hi)$ の整数をとる、直線のない木 | $O(1)$ |
| `add_line(a, b)` | 直線 $y = ax + b$ を追加 | $O(\log W)$ |
| `add_segment(a, b, l, r)` | 線分 $y = ax + b$ ($x \in [l, r)$、$l$、$r$ は $x$ 座標そのもの) を追加 | $O(\log^2 W)$ |
| `get_min(x)` | $x$ での最小値 (`std::optional<T>`)。$x$ を含む直線・線分がなければ `std::nullopt` | $O(\log W)$ |

$W = hi - lo$ です。頂点は、直線 1 本につき 1 個以下、線分 1 本につき $2 \log W$ 個程度増えます。線分を何十万本も足すとメモリと時間が重くなる (範囲 $2 \times 10^9$、線分 $4 \times 10^5$ 本で頂点 1300 万個、5 秒ほど) ので、そのときは座標を先読みする `LiChaoTree` を使います。

## 関連

- 直線ではなく値の区間最小値なら [セグメント木](segtree.hpp)
