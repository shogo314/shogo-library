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
if (ts.satisfiable()) {
    const std::vector<bool>& x = ts.answer();
}
```

## メンバ

| メンバ | 説明 |
|---|---|
| `TwoSat(n)` | 変数が `n` 個で、条件のない状態 |
| `size()` | 変数の個数 |
| `add_clause(i, f, j, g)` | 条件「($x_i = f$) または ($x_j = g$)」を加える |
| `add_imply(i, f, j, g)` | 条件「($x_i = f$) ならば ($x_j = g$)」を加える |
| `add_nand(i, f, j, g)` | 条件「($x_i = f$) と ($x_j = g$) の少なくとも一方は成り立たない」を加える |
| `add_fix(i, f)` | 条件「$x_i = f$」を加える |
| `satisfiable()` | すべての条件を満たす割り当てがあるか |
| `answer()` | 直前の `satisfiable()` が `true` のとき、条件を満たす割り当ての 1 つ |

`satisfiable()` を呼んだ後に条件を加えて、もう一度 `satisfiable()` を呼ぶこともできます。
