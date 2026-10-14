---
title: コンテナに対する関数 (sorted, max, sum など)
documentation_of: //src/utility/container_func.hpp
---

コンテナ全体を受け取る Python 風の関数です。`begin()`、`end()` を持つコンテナならたいてい使えます。

コンテナが同名のメンバ関数を持つ場合は、そちらを呼びます。そのときの計算量はメンバ関数の計算量になります ([Range](range.hpp) の `sum` は $O(1)$ など)。`find`、`count`、`lower_bound`、`upper_bound` は `std::set` などではメンバ関数を、それ以外では `std::` のアルゴリズムを使います。

```cpp
std::vector<int> v = {3, 1, 4, 1, 5};
auto w = sorted(v);            // {1, 1, 3, 4, 5}
int s = sum(v), mx = max(v);   // 14, 5
long long i = bisect_left(w, 3);  // 2
bool b = contains(v, 4);       // true
```

## 並べ替え

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sorted(c, reverse = false)` / `sorted(c, comp)` | ソートしたコピーを返す | $O(n \log n)$ |
| `reversed(c)` | 逆順にしたコピーを返す | $O(n)$ |
| `sort(c, reverse = false)` / `sort(c, comp)` | その場でソート | $O(n \log n)$ |
| `sort_by_key(c, key)` | `key(x)` の昇順にその場でソート (比較のたびに `key` を呼ぶ) | `key` の呼び出し $O(n \log n)$ 回 |
| `reverse(c)` | その場で逆順にする | $O(n)$ |

## 集計

| 関数 | 説明 | 計算量 |
|---|---|---|
| `max(c)` / `min(c)` | 最大値 / 最小値。`max({a, b, c})` のように初期化子リストも渡せる | $O(n)$ (`set` などソート済みのコンテナでは $O(1)$) |
| `sum(c)` | 総和 | $O(n)$ |
| `product(c)` | 総積 | $O(n)$ |
| `product_xor(c)` | 総 xor | $O(n)$ |
| `gcd(c)` | 全要素の gcd (空なら 0) | $O(n \log \max)$ |
| `average(c)` | 平均 (`sum(c) / size`、整数型なら 0 方向に切り捨て) | $O(n)$ |
| `median(c)` | 中央値 (要素数が偶数なら中央 2 つの平均) | $O(n \log n)$ |
| `mex(c)` | 含まれない最小の非負整数 | $O(n)$ |
| `maximum_subarray(c)` | 空でない連続部分列の和の最大値 | $O(n)$ |
| `maximum_subarray(c, init)` | 空の部分列 (和 `init`) も許した連続部分列の和の最大値 | $O(n)$ |

## 検索

| 関数 | 説明 | 計算量 |
|---|---|---|
| `find(c, x)` | `x` を指すイテレータ (なければ `end()`) | $O(n)$ (`set` などでは $O(\log n)$) |
| `count(c, x)` | `x` の個数 | $O(n)$ (`multiset` などでは $O(\log n + k)$、$k$ は個数) |
| `contains(c, x)` | `x` を含むか | `find` と同じ |
| `index(c, x)` | `x` が最初に現れる位置 (`long long`。なければ `-1`) | $O(n)$ |
| `lower_bound(c, x)` / `upper_bound(c, x)` | イテレータを返す | $O(\log n)$ |
| `bisect_left(c, x)` / `bisect_right(c, x)` | 添字を `long long` で返す (Python の `bisect`) | $O(\log n)$ (`set` などでは位置を数えるので $O(n)$) |

## 関連

- `std::vector` に対する演算子と関数は [vector に対する演算子と関数](vector_func.hpp)
