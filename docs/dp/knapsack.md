---
title: ナップサック問題
documentation_of: //src/dp/knapsack.hpp
---

品物 $i$ は価値 `v[i]` と重さ `w[i]` を持ちます (どちらも 0 以上)。重さの和が `W` 以下になるように品物を選んで、価値の和の最大値を求めます。答えは `long long` に収まる必要があります。

アルゴリズムを指定する関数と、入力の大きさから計算量が最も小さいアルゴリズムを選ぶ関数 (ラッパー) があります。迷ったらラッパーを使います。

```cpp
std::vector<long long> v = {4, 5, 2, 8}, w = {2, 2, 1, 3};
long long a = knapsack(v, w, 5);                 // 13 (0/1 ナップサック)
long long b = unbounded_knapsack(v, w, 8);       // 21 (何個でも選べる)
std::vector<long long> m = {2, 1, 4, 2};
long long c = bounded_knapsack(v, w, m, 8);      // 21 (品物 i は m[i] 個まで)
```

## 0/1 ナップサック (各品物は 1 個まで)

$N$ は品物の個数、$V$ は価値の和です。

| 関数 | 計算量 | 向いている入力 |
|---|---|---|
| `knapsack(v, w, W)` | 下の 3 つのうち最小 | 迷ったらこれ |
| `knapsack_by_weight(v, w, W)` | $O(NW)$ | `W` が小さい |
| `knapsack_by_value(v, w, W)` | $O(NV)$ | 価値の和が小さい (重さは大きくてよい) |
| `knapsack_meet_in_the_middle(v, w, W)` | $O(2^{N/2} N)$ | $N$ が 40 程度まで (重さも価値も大きくてよい) |

`knapsack` は、$(N + 1)(W + 1)$、$(N + 1)(V + 1)$、$(N + 1) 2^{\lceil N/2 \rceil}$ を比べて最も小さいものを選びます。$N > 80$ のときは半分全列挙を候補から外します。

## 個数制限なし (同じ品物を何個でも選べる)

| 関数 | 計算量 |
|---|---|
| `unbounded_knapsack(v, w, W)` | $O(NW)$ |

重さ 0 で価値が正の品物があると答えが無限大になるので、assert で止めます。

## 個数制限付き (品物 i は m[i] 個まで)

| 関数 | 計算量 | 向いている入力 |
|---|---|---|
| `bounded_knapsack(v, w, m, W)` | 下のうち最小 | 迷ったらこれ |
| `bounded_knapsack_by_weight(v, w, m, W)` | $O(NW)$ | `W` が小さい。`m[i]` は大きくてよい |
| `bounded_knapsack_by_value(v, w, m, W)` | $O(V' \sum_i \log m_i)$ ($V' = \sum_i v_i m_i$) | 価値の和が小さい |

- `bounded_knapsack_by_weight` は、重さを `w[i]` で割った余りごとにスライド最大値を使います。
- `bounded_knapsack_by_value` は、品物を個数 $1, 2, 4, \dots$ (と残り) の組に分けて 0/1 ナップサックにします (二進分割)。`W / w[i]` を超える個数は使えないので、先に `m[i]` をそこまで減らします。
- `bounded_knapsack` は、重さについての DP と、二進分割した後の価値についての DP・半分全列挙のうち、計算量が最も小さいものを選びます。

## 関連

- 価値を考えずに作れる和だけを求めるなら [部分和問題](subset-sum.hpp)
