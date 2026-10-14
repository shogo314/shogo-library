---
title: 部分和の個数
documentation_of: //src/dp/subset-sum-count.hpp
---

0 以上の整数の列 `a` から各要素を 1 回まで選ぶとき、和が $s$ になる選び方 (部分集合) の個数を、$s = 0, 1, \dots, S$ について求めます。

```cpp
using mint = modint998244353;
std::vector<long long> a = {1, 2, 3, 5};
auto c = subset_sum_count<mint>(a, 5);   // {1, 1, 1, 2, 1, 2}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum_count<mint>(a, S)` | 下の 2 つのうち、計算量が小さい方を選ぶ | $O(\min(NS, S \log S))$ |
| `subset_sum_count_dp<T>(a, S)` | DP。`T` は `long long` などでもよい | $O(NS)$ |
| `subset_sum_count_fps<mint>(a, S)` | $\prod_i (1 + x^{a_i}) = \exp\left(\sum_i \log(1 + x^{a_i})\right)$ を使う。mod は $S$ より大きい素数であること | $O(S \log S)$ |

- 返す列の長さは `S + 1` です。
- 値が 0 の要素は、選ぶか選ばないかで個数が 2 倍になります。
- `subset_sum_count_fps` では、同じ値 $k$ が $c$ 個あると $c \log(1 + x^k) = c \sum_{j \ge 1} (-1)^{j+1} x^{kj} / j$ なので、log の和は調和級数の $O(S \log S)$ で作れます。
- `subset_sum_count` は、$NS$ と $500\, S \log S$ を比べて選びます (実測で、exp の定数倍が DP の約 500 倍だったため)。

## 関連

- 作れるかどうかの判定と復元は [部分和問題](subset-sum.hpp)
- [形式的冪級数](../math/fps.hpp) の `exp` を使います
