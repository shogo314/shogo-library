---
title: 2-SAT
documentation_of: //src/graph/two-sat.hpp
---

真偽値の変数 $x_0, \dots, x_{n-1}$ について、「($x_i = f$) または ($x_j = g$)」の形の条件をすべて満たす割り当てがあるかを判定し、あれば 1 つ求めます。[強連結成分分解](graph_util.hpp) を使い、$O(n + \text{条件の個数})$ です。

```cpp
TwoSat ts(n);
ts.add_clause(0, true, 1, false);  // x_0 または (not x_1)
ts.add_imply(1, true, 2, true);    // x_1 ならば x_2
ts.add_nand(0, true, 2, true);     // x_0 と x_2 の両方が真ではない
if (auto x = ts.solve()) {
    // (*x)[i] が x_i の値
} else {
    // 満たす割り当てがない
}
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `TwoSat(n)` | 変数が `n` 個で、条件のない状態 | $O(n)$ |
| `size()` | 変数の個数 | $O(1)$ |
| `add_clause(i, f, j, g)` | 条件「($x_i = f$) または ($x_j = g$)」を加える | ならし $O(1)$ |
| `add_imply(i, f, j, g)` | 条件「($x_i = f$) ならば ($x_j = g$)」を加える | ならし $O(1)$ |
| `add_nand(i, f, j, g)` | 条件「($x_i = f$) と ($x_j = g$) の少なくとも一方は成り立たない」を加える | ならし $O(1)$ |
| `add_fix(i, f)` | 条件「$x_i = f$」を加える | ならし $O(1)$ |
| `solve()` | すべての条件を満たす割り当てを 1 つ求め、`std::optional<std::vector<bool>>` で返す。なければ `std::nullopt` | $O(n + m)$ ($m$ は条件の個数) |

変数の番号と個数は `long long` です。

`solve()` を呼んだ後に条件を加えて、もう一度 `solve()` を呼ぶこともできます。

`solve()` の結果は、変数に受けてから使います。`for (bool b : *ts.solve())` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。

## 関連

- 内部で使っている強連結成分分解は [グラフに関する関数](graph_util.hpp) の `strongly_connected_components`
