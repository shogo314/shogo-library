---
title: 集合の被覆 (使ってよい集合で覆う最小個数、包除原理)
documentation_of: //src/dp/set-cover.hpp
---

$\lbrace 0, \dots, n - 1 \rbrace$ を、「使ってよい集合」いくつかで (重なりを許して) 覆うときの最小個数を、包除原理で $O(2^n n)$ で求めます。$n$ は 20 程度まで使えます。数を素数の mod で数えるので、まれに誤ります (下を参照)。

```cpp
// 彩色数: 独立集合で頂点全体を覆う最小個数
std::vector<bool> indep(1 << n);
indep[0] = true;
for (int S = 1; S < (1 << n); S++) {
    int v = __builtin_ctz(S), rest = S & (S - 1);
    indep[S] = indep[rest] && !(adj[v] & rest);  // adj[v] は v と隣り合う頂点の集合
}
long long k = min_set_cover(n, indep);
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `min_set_cover(n, feasible)` | `feasible[T]` (大きさ $2^n$ の `std::vector<bool>`) が `true` の集合 $T$ いくつかで、全体を重なりを許して覆うときの最小個数。覆えなければ -1、$n = 0$ なら 0 | $O(2^n n)$ |

- $f(S)$ を「$S$ に含まれる使ってよい集合の数」とすると (部分集合についてのゼータ変換)、和集合が全体になる $k$ 個組 $(T_1, \dots, T_k)$ の数は、包除原理により $\sum_S (-1)^{n - \lvert S \rvert} f(S)^k$ です。これが 0 でない最小の $k$ が答えです。覆えるなら $k \le n$ なので、$k = 1, \dots, n$ と $f(S)^k$ を順に掛けて調べます。
- 組の数は大きくなるので、998244353 と 1000000007 の 2 つの素数の mod で数えます。本当は 0 でないのに両方の mod で 0 になると、答えを大きく誤ります。
- 使ってよい集合族が部分集合について閉じている (彩色数の独立集合など) なら、[集合の分割](set-partition.hpp) の `min_set_partition` と答えが一致します。誤りがあってはいけないときや、$n$ が小さいときは、そちらの $O(3^n)$ の方法も使えます。

## 関連

- 重ならないように分ける最小個数 (誤りのない $O(3^n)$) は [集合の分割](set-partition.hpp)
- 彩色数は [グラフに関する関数](../graph/graph_util.hpp) の `chromatic_number` (誤りのない方法)
- 部分集合についてのゼータ変換は [ビット演算の畳み込み](../math/bitwise-transform.hpp)
