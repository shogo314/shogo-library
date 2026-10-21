---
title: 集合の分割 (使ってよい集合に分ける最小個数)
documentation_of: //src/dp/set-partition.hpp
---

$\lbrace 0, \dots, n - 1 \rbrace$ を、「使ってよい集合」いくつかに重ならないように分けるときの最小個数を $O(3^n)$ で求めます。$n$ は 16 程度まで (3^16 ≈ 4 × 10^7) です。

```cpp
// 品物を、重さの和が C 以下の組に分ける (瓶詰め問題と同じ)
std::vector<bool> feasible(1 << n);
for (int S = 0; S < (1 << n); S++) {
    long long sum = 0;
    for (int i = 0; i < n; i++) if (S >> i & 1) sum += w[i];
    feasible[S] = sum <= C;
}
long long k = min_set_partition(n, feasible);
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `min_set_partition(n, feasible)` | `feasible[T]` (大きさ $2^n$ の `std::vector<bool>`) が `true` の集合 $T$ に、全体を重ならないように分けるときの最小個数。分けられなければ -1、$n = 0$ なら 0 | $O(3^n)$ |

- $\mathrm{dp}_S = \min (\mathrm{dp}_{S \setminus T} + 1)$ を、$T$ を「$S$ の最小の要素を含む $S$ の部分集合」に限って求めます。どの分け方でも最小の要素を含む組はちょうど 1 つなので、こう限っても答えは変わらず、列挙は半分になります。
- 使ってよい集合族が部分集合について閉じている (使ってよい集合の部分集合も使ってよい) なら、重なりを許して覆うときの最小個数とも一致します。
- 包除原理で「覆う $k$ 個組の数」を数えれば $O(2^n n)$ にできますが、数が大きくなるので素数の mod で数える必要があり、まれに誤ります。ここでは誤りのない $O(3^n)$ の方法にしています。$O(2^n n)$ の方法は [集合の被覆](set-cover.hpp) の `min_set_cover` です。

## 関連

- 重なりを許して覆う最小個数を包除原理で $O(2^n n)$ で求めるなら [集合の被覆](set-cover.hpp)
- 彩色数は [グラフに関する関数](../graph/graph_util.hpp) の `chromatic_number` (隣り合わない頂点に絞って速くしたもの)
- 瓶詰め問題は [瓶詰め問題](bin-packing.hpp) の方が速い ($O(2^n n)$)
- 部分集合の和の変換は [ビット演算の畳み込み](../math/bitwise-transform.hpp)
