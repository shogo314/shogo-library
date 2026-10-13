---
title: 部分和問題 (作れる和の判定、S 以下の最大値と復元)
documentation_of: //src/others/subset-sum.hpp
---

0 以上の整数の列 `a` から、各要素を 1 回まで選んで作れる和を求めます。bitset で 64 個ずつまとめて計算するか、半分全列挙を使います。

```cpp
std::vector<long long> a = {3, 5, 9};
std::vector<bool> can = subset_sum(a, 20);   // can[s] は和 s を作れるか。can[14] == true、can[13] == false
auto r = subset_sum_restore(a, 14);          // 和 14 になる添字のリスト {1, 2}
if (!subset_sum_restore(a, 13)) {
    // 作れない
}
long long m = subset_sum_max(a, 13);         // 12 (S 以下の最大値)
auto idx = subset_sum_max_restore(a, 13);    // {0, 2} (3 + 9)
```

## 作れるかの判定

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum(a, S)` | 長さ `S + 1` の `vector<bool>`。`res[s]` は和 `s` を作れるか | $O(NS / 64)$ |
| `subset_sum_restore(a, S)` | 和がちょうど `S` になる選び方を 1 つ求め、添字を昇順に並べたものを `std::optional` で返す。作れなければ `std::nullopt` | $O(NS / 64 + S)$ |

## S 以下の最大値

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum_max(a, S)` | 作れる和のうち `S` 以下の最大値。下の 2 つのうち計算量が小さい方を選ぶ | |
| `subset_sum_max_bitset(a, S)` | bitset で作れる和を求め、`S` から下へ探す | $O(NS / 64)$ |
| `subset_sum_max_meet_in_the_middle(a, S)` | 半分全列挙。$N$ が 40 程度までなら、`S` や要素が大きくてもよい | $O(2^{N/2})$ |
| `subset_sum_max_restore(a, S)` | 和が `S` 以下で最大になる選び方を 1 つ求め、添字を昇順に並べたものを返す。`subset_sum_max` と同じく計算量が小さい方を選ぶ | |

- 何も選ばなければ和は 0 なので、`subset_sum_max` は常に 0 以上の値を返し、`subset_sum_max_restore` は空のリストを返すこともあります。
- 半分全列挙では、前半と後半それぞれの (和, 選んだ要素のビット列) を和の昇順に列挙し、前半の和を小さい順に見ながら後半の添字を後ろから動かします。
- `subset_sum_max` は $(N + 1)(S / 64 + 1)$ と $4 \cdot 2^{\lceil N/2 \rceil}$ を比べて選びます。

## 注意

- `S` を超える要素は使えないので無視します。
- `subset_sum_restore` の結果は、変数に受けてから使います。`for (int i : *subset_sum_restore(a, S))` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。
- bitset での復元では、和 `s` を初めて作れるようになったときに使った要素の添字 `from[s]` を覚えておき、復元する和から逆にたどります。メモリは $O(S)$ です。

## 関連

- 和ごとの選び方の個数は [部分和の個数](subset-sum-count.hpp)
- 価値と重さがあるときは [ナップサック問題](knapsack.hpp)
