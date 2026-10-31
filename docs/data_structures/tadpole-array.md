---
title: おたまじゃくし配列
documentation_of: //src/data_structures/tadpole-array.hpp
---

途中からループする無限列を表します (ρ 型、おたまじゃくしの形)。長さ $n$ の配列と、末尾の次に戻る位置 $i$ を与えると、`data[0], ..., data[n-1], data[i], ..., data[n-1], data[i], ...` という列になります。Functional Graph をたどったときの頂点列などに使えます。

```cpp
TadpoleArray<int> t(std::vector<int>{1, 2, 3, 4}, 1);  // 1 2 3 4 2 3 4 2 3 4 ...
int a = t[4];                 // 2
int b = t[1000000000000LL];   // 2
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `TadpoleArray<T>(v, i)` | 配列 `v` の末尾の次を `v[i]` にする ($0 \le i < n$) | $O(n)$ |
| `t[k]` / `t.at(k)` | 列の `k` 番目 (`long long` の添字。`k >= 0` で、配列の長さを超えてもよい) | $O(1)$ |

## 関連

- 先頭からループする配列の区間和は [円環上の区間和](circular-sum.hpp)
- [ファンクショナルグラフ](../graph/functional-graph.hpp)
