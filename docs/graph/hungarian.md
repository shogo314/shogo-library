---
title: 割当問題 (ハンガリアン法)
documentation_of: //src/graph/hungarian.hpp
---

$n \times m$ ($n \le m$) のコスト行列 `a` で、各行に異なる列を 1 つずつ割り当てるときの、コストの総和の最小値と割り当て方を求めます。重み付きの二部グラフの最小重み完全マッチングと同じです。ポテンシャルを使うハンガリアン法で $O(n^2 m)$ です。

```cpp
std::vector<std::vector<long long>> a(n, std::vector<long long>(n));
auto res = hungarian(a);
long long cost = res.cost; // コストの総和の最小値
long long j = res.match[i]; // 行 i に割り当てた列
```

コストは負でもかまいません。最大化したいときは、符号を反転したコストで呼びます。

途中でコストの総和程度の値を扱い、`std::numeric_limits<T>::max() / 4` を無限大として使います。`int` では足りなくなりやすいので、`T` は `long long` にしてください。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `hungarian(a)` | 割当問題を解き、`Assignment<T>` を返す。`a` の行の長さはそろっていて、行の数が列の数以下であること | $O(n^2 m)$ |

`Assignment<T>` は次の 2 つを持ちます。

| 変数 | 説明 |
|---|---|
| `cost` | コストの総和 |
| `match[i]` | 行 `i` に割り当てた列 |

## 関連

- 重みのない二部グラフの最大マッチングは [二部マッチング](bipartite-matching.hpp)
- 1 つの列に複数の行を割り当てるなど、容量のあるものは [最小費用流](min-cost-flow.hpp)
