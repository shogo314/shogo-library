---
title: 編集距離 (レーベンシュタイン距離)
documentation_of: //src/dp/edit-distance.hpp
---

列 `s` を列 `t` に変えるのに必要な、1 要素の挿入・削除・置換の最小回数を $O(nm)$ で求めます。$n$、$m$ は `s`、`t` の長さです。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
long long d = edit_distance(std::string("kitten"), std::string("sitting"));  // 3
edit_distance(std::vector<int>{1, 2, 3}, std::vector<int>{2, 3, 4});        // 2
```

`edit_distance_restore` は距離と、最小回数の挿入・削除・置換を行う操作列を返します。入力はランダムアクセス可能な列にしてください。最適な操作列が複数ある場合は、そのうち 1 つを返します。

```cpp
std::string s = "kitten", t = "sitting";
auto [distance, operations] = edit_distance_restore(s, t);  // distance == 3
for (const auto& op : operations) {
    if (op.type == EditDistance::Type::Insert) s.insert(s.begin() + op.target_index, t[op.target_index]);
    if (op.type == EditDistance::Type::Erase) s.erase(s.begin() + op.target_index);
    if (op.type == EditDistance::Type::Replace) s[op.target_index] = t[op.target_index];
}
// s == t
```

`source_index` は変更前の元の列の添字で、挿入のときは隙間の位置 `[0, |s|]` です。`target_index` は目標の列の添字で、削除のときは隙間の位置 `[0, |t|]` です。返された順に操作を適用する場合、変更中の列で操作する位置も `target_index` になります。挿入・置換する値は元の目標列の `t[target_index]` から取得してください。値を操作列にコピーしないため、文字列以外の列でも同じ型で結果を受け取れます。

一致した要素を通過する操作は含みません。操作数は距離と等しく、同じ列どうしでは空の操作列になります。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `edit_distance(s, t)` | 編集距離 (`long long`) | 時間 $O(nm)$、メモリ $O(m)$ |
| `edit_distance_restore(s, t)` | 距離と操作列を持つ `EditDistance` を返す | 時間・メモリ $O(nm)$ |

## メンバ変数

| メンバ | 説明 |
|---|---|
| `EditDistance::distance` | 編集距離 (`long long`) |
| `EditDistance::operations` | 順に適用する `Operation` の列 |
| `Operation::type` | `EditDistance::Type::Insert`・`Erase`・`Replace` |
| `Operation::source_index` | 元の列の添字 (挿入では隙間) |
| `Operation::target_index` | 目標の列の添字 (削除では隙間) |

## 関連

- 置換だけを許す場合 (同じ長さの列で異なる位置の数) は [コンテナに対する関数](../utility/container_func.hpp) の `hamming_distance`
- 挿入と削除だけを許す場合の最小回数は、[最長共通部分列 (LCS)](longest-common-subsequence.hpp) の長さ $L$ を使って $n + m - 2L$
