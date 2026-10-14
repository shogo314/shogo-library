---
title: Mo's algorithm
documentation_of: //src/others/mo.hpp
---

区間 $[l, r)$ に対するクエリをまとめて先読みし、区間の端を 1 つずつ伸び縮みさせながら答えます。区間に要素を 1 つ追加・削除する操作が速くできるときに使えます。

```cpp
// 各クエリ [l, r) の、区間内の異なる値の個数
std::vector<int> cnt(MAXA);
auto add = [&](int& kinds, long long i) { if (cnt[a[i]]++ == 0) kinds++; };
auto del = [&](int& kinds, long long i) { if (--cnt[a[i]] == 0) kinds--; };
Mo mo(n, 0, add, del);                  // 左右で同じ操作なら 2 つ渡せばよい
for (auto [l, r] : queries) mo.query(l, r);
std::vector<int> ans = mo.solve<int>([](int& kinds) { return kinds; });  // クエリ順の答え
```

## メンバ関数

$q$ はクエリ数です。`solve` の計算量は、操作が $O(1)$ のときのものです。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Mo(n, e, add_left, delete_left, add_right, delete_right)` | 要素数 `n` (`long long`)、状態の初期値 `e` (型 `U`) と 4 つの操作で作る | $O(1)$ |
| `Mo(n, e, add, del)` | 左端と右端で操作が同じ場合 | $O(1)$ |
| `query(l, r)` | クエリ $[l, r)$ を追加する (`l`、`r` は `long long`) | $O(1)$ |
| `solve<T>(f)` | すべてのクエリを処理し、各クエリで `f(state)` が返した値 (型 `T`) を、`query` を呼んだ順に並べて返す | $O(n \sqrt{q} + q \log q)$ |

## 渡す操作

操作はいずれも `(U& state, long long i)` を受け取り、`state` を書き換えます。位置 `i` は `long long` で渡すので、`int i` で受け取る操作も使えます。

| 操作 | 呼ばれるとき |
|---|---|
| `add_left(state, i)` | 区間の左に要素 `i` を追加する |
| `delete_left(state, i)` | 区間の左端の要素 `i` を削除する |
| `add_right(state, i)` | 区間の右に要素 `i` を追加する |
| `delete_right(state, i)` | 区間の右端の要素 `i` を削除する |

## 関連

- 操作に $O(\log n)$ かかる例 (区間の転倒数など) では、状態に [Fenwick Tree](../data_structures/fenwick-tree.hpp) を持たせます

