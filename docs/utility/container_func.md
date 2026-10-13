---
title: コンテナに対する関数 (sorted, max, sum など)
documentation_of: //src/utility/container_func.hpp
---

コンテナ全体を受け取る Python 風の関数です。`begin()`、`end()` を持つコンテナならたいてい使えます。

コンテナが同名のメンバ関数を持つ場合は、そちらを呼びます。`find`、`count`、`lower_bound`、`upper_bound` は `std::set` などではメンバ関数を、それ以外では `std::` のアルゴリズムを使います。

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};
auto w = sorted(v);            // {1, 1, 3, 4, 5}
int s = sum(v), mx = max(v);   // 14, 5
int i = bisect_left(w, 3);     // 2
bool b = contains(v, 4);       // true
```

## 並べ替え

| 関数 | 説明 |
|---|---|
| `sorted(c, reverse = false)` / `sorted(c, comp)` | ソートしたコピーを返す |
| `reversed(c)` | 逆順にしたコピーを返す |
| `sort(c, reverse = false)` / `sort(c, comp)` | その場でソート |
| `sort_by_key(c, key)` | `key(x)` の昇順にその場でソート |
| `reverse(c)` | その場で逆順にする |

## 集計

| 関数 | 説明 |
|---|---|
| `max(c)` / `min(c)` | 最大値 / 最小値 (`set` などソート済みのコンテナでは $O(1)$)。`max({a, b, c})` のように初期化子リストも渡せる |
| `sum(c)` | 総和 |
| `product(c)` | 総積 |
| `product_xor(c)` | 総 xor |
| `gcd(c)` | 全要素の gcd (空なら 0) |
| `average(c)` | 平均 (`sum(c) / size`、整数型なら切り捨て) |
| `median(c)` | 中央値 (要素数が偶数なら中央 2 つの平均) |
| `mex(c)` | 含まれない最小の非負整数 |
| `maximum_subarray(c)` | 空でない連続部分列の和の最大値 |
| `maximum_subarray(c, init)` | 空の部分列 (和 `init`) も許した連続部分列の和の最大値 |

## 検索

| 関数 | 説明 |
|---|---|
| `find(c, x)` | `x` を指すイテレータ |
| `count(c, x)` | `x` の個数 |
| `contains(c, x)` | `x` を含むか |
| `index(c, x)` | `x` が最初に現れる位置 (なければ `-1`) |
| `lower_bound(c, x)` / `upper_bound(c, x)` | イテレータを返す |
| `bisect_left(c, x)` / `bisect_right(c, x)` | 添字を返す (Python の `bisect`) |

## 関連

- `std::vector` に対する演算子と関数は [vector に対する演算子と関数](vector_func.hpp)
