---
title: Sliding Window Aggregation (キューと両端キュー) とスライド最小値
documentation_of: //src/data_structures/sliding-window-aggregation.hpp
---

## Sliding Window Aggregation

モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を乗せたキューです。末尾への追加、先頭の削除、全体の積の取得を償却 $O(1)$ で行います。モノイドは可換でなくてもよく、逆元もいりません。

```cpp
// Composite の積は f∘g なので、先頭から順に適用するには Reverse で積の順序を逆にする
SlidingWindowAggregation<monoid::Reverse<monoid::Composite<mint>>> swag;
swag.push(Affine<mint>{2, 3});
swag.push(Affine<mint>{1, 5});
mint y = swag.prod()(x);  // 先頭から順に適用した結果 (2x + 3) + 5
swag.pop();               // 先頭を削除
SlidingWindowAggregation swag2(Monoid([](int a, int b) { return std::min(a, b); }, INF));  // ラムダ式から作る
```

キューを 2 つのスタックで表し、前半のスタックには先頭側からの積を持たせます。前半が空のときに `pop` すると、後半をまとめて前半へ移します。

### メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SlidingWindowAggregation<M>()` | 空のキュー | $O(1)$ |
| `push(x)` | 末尾に `x` を追加 | $O(1)$ |
| `pop()` | 先頭を削除 | 償却 $O(1)$ |
| `front()` | 先頭の要素 | $O(1)$ |
| `prod()` | 先頭から末尾までの積 (空なら単位元) | $O(1)$ |
| `size()`、`empty()` | 要素数、空か | $O(1)$ |
| `clear()` | すべて削除 | $O(n)$ |

## 両端キュー (DequeAggregation)

モノイドを乗せた両端キューです。先頭と末尾への追加・削除、全体の積の取得を償却 $O(1)$ で行います。

```cpp
DequeAggregation<monoid::Reverse<monoid::Composite<mint>>> dq;
dq.push_front(Affine<mint>{2, 3});
dq.push_back(Affine<mint>{1, 5});
mint y = dq.prod()(x);  // 先頭から順に適用した結果
dq.pop_back();
```

前半と後半を 2 つのスタックで持ち、それぞれに積を持たせます。空の側から取り出すときは、もう一方を半分に分けて作り直します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DequeAggregation<M>()` | 空の両端キュー | $O(1)$ |
| `push_front(x)`、`push_back(x)` | 先頭、末尾に `x` を追加 | $O(1)$ |
| `pop_front()`、`pop_back()` | 先頭、末尾を削除 | 償却 $O(1)$ |
| `front()`、`back()` | 先頭、末尾の要素 | $O(1)$ |
| `prod()` | 先頭から末尾までの積 (空なら単位元) | $O(1)$ |
| `size()`、`empty()` | 要素数、空か | $O(1)$ |
| `clear()` | すべて削除 | $O(n)$ |

## スライド最小値

配列 `a` の長さ `k` の各区間 $[i, i + k)$ の最小値・最大値を、単調な deque で求めます。返り値の長さは $n - k + 1$ です ($1 \le k \le n$)。

```cpp
std::vector<int> a = {1, 7, 7, 4, 8, 1, 6};
auto mn = sliding_window_min(a, 3);  // {1, 4, 4, 1, 1}
auto mx = sliding_window_max(a, 3);  // {7, 7, 8, 8, 8}
```

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sliding_window_min(a, k, comp = std::less<T>())` | 各区間の最小値。`comp` を渡すとその順序での最小値 | $O(n)$ |
| `sliding_window_max(a, k)` | 各区間の最大値 | $O(n)$ |

## 関連

- 区間が自由に動くなら [Sparse Table](sparse-table.hpp) や [セグメント木](segtree.hpp)
