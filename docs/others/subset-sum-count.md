---
title: 部分和の個数
documentation_of: //src/others/subset-sum-count.hpp
---

0 以上の整数の列 `a` から各要素を 1 回まで選ぶとき、和が $s$ になる選び方 (部分集合) の個数を、$s = 0, 1, \dots, t$ について求めます。

```cpp
using mint = modint998244353;
std::vector<long long> a = {1, 2, 3, 5};
auto c = count_subset_sum<mint>(a, 5);   // {1, 1, 1, 2, 1, 2}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `count_subset_sum<mint>(a, t)` | 下の 2 つのうち、計算量が小さい方を選ぶ | |
| `count_subset_sum_dp<T>(a, t)` | DP。`T` は `long long` などでもよい | $O(Nt)$ |
| `count_subset_sum_fps<mint>(a, t)` | $\prod_i (1 + x^{a_i}) = \exp\left(\sum_i \log(1 + x^{a_i})\right)$ を使う。mod は $t$ より大きい素数であること | $O(t \log t)$ |

- 返す列の長さは `t + 1` です。
- 値が 0 の要素は、選ぶか選ばないかで個数が 2 倍になります。
- `count_subset_sum_fps` では、同じ値 $k$ が $c$ 個あると $c \log(1 + x^k) = c \sum_{j \ge 1} (-1)^{j+1} x^{kj} / j$ なので、log の和は調和級数の $O(t \log t)$ で作れます。
- `count_subset_sum` は、$Nt$ と $500\, t \log t$ を比べて選びます (実測で、exp の定数倍が DP の約 500 倍だったため)。

## 関連

- 作れるかどうかの判定と復元は [部分和問題](subset-sum.hpp)
- [形式的冪級数](../math/fps.hpp) の `exp` を使います
