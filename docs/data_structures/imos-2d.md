---
title: 2 次元のいもす法
documentation_of: //src/data_structures/imos-2d.hpp
---

$h$ 行 $w$ 列のグリッドで、長方形への加算をためておき、最後にまとめて各マスの値を求めます。加算は長方形の 4 隅に足すだけで $O(1)$、`build` で 2 方向の累積和をとって $O(hw)$ です。

```cpp
Imos2D<int> imos(4, 4);
imos.add(Grid({0, 3}, {0, 2}), 1);  // 行 [0, 3)、列 [0, 2) に 1 を足す
imos.add(Grid({2, 4}, {1, 3}), 1);
imos.build();
int x = imos.get(2, 1);   // 2 (2 つの長方形が重なる)
```

`add` は `build` の前に、`get` は `build` の後に呼びます (違えば assert で落ちます)。加算と取得を交互に行いたいなら、[2次元セグメント木](segtree-2d.hpp) などを使います。

`region` は [Grid](../utility/range.hpp) で渡し、行・列の `step` は 1 に限ります。範囲は表の内側で、始点は終点以下である必要があります。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Imos2D<T>(h, w)` | `h` 行 `w` 列で、すべて 0 | $O(hw)$ |
| `height()` / `width()` | 行数 / 列数 | $O(1)$ |
| `add(region, x)` | `Grid` の行・列の範囲のマスに `x` を足す (`build` の前) | $O(1)$ |
| `build()` | 累積和をとって各マスの値を求める (1 回だけ) | $O(hw)$ |
| `get(i, j)` | マス `(i, j)` の値 (`build` の後) | $O(1)$ |

## 関連

- 1 次元は [imos法で区間作用、1点取得](imos.hpp)
- 長方形の和集合の面積は [長方形の和集合の面積](../geometry/rectangle-union.hpp)
