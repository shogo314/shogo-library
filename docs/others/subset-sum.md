---
title: 部分和問題 (作れる和の判定と復元)
documentation_of: //src/others/subset-sum.hpp
---

0 以上の整数の列 `a` から、各要素を 1 回まで選んで作れる和を求めます。bitset で 64 個ずつまとめて計算します。

```cpp
std::vector<long long> a = {3, 5, 9};
std::vector<bool> can = subset_sum(a, 20);   // can[s] は和 s を作れるか。can[14] == true、can[13] == false
auto r = subset_sum_restore(a, 14);          // 和 14 になる添字のリスト {1, 2}
if (!subset_sum_restore(a, 13)) {
    // 作れない
}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `subset_sum(a, S)` | 長さ `S + 1` の `vector<bool>`。`res[s]` は和 `s` を作れるか | $O(NS / 64)$ |
| `subset_sum_restore(a, S)` | 和がちょうど `S` になる選び方を 1 つ求め、添字を昇順に並べたものを `std::optional` で返す。作れなければ `std::nullopt` | $O(NS / 64 + S)$ |

- `S` を超える要素は使えないので無視します。
- `subset_sum_restore` の結果は、変数に受けてから使います。`for (int i : *subset_sum_restore(a, S))` と書くと、一時オブジェクトの `std::optional` が先に破棄され、壊れた値を読みます。
- 復元では、和 `s` を初めて作れるようになったときに使った要素の添字 `from[s]` を覚えておき、`S` から逆にたどります。メモリは $O(S)$ です。

## 関連

- 和ごとの選び方の個数は [部分和の個数](subset-sum-count.hpp)
- 価値と重さがあるときは [ナップサック問題](knapsack.hpp)
