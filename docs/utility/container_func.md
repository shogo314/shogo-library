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
auto odd = indices_if(v, [](int x) { return x % 2 == 1; });  // {0, 1, 3, 4}
```

## 並べ替え

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sorted(c)` / `sorted(c, comp)` / `sorted(c, comp, proj)` | ソートしたコピーを返す。降順は `sorted(c, std::greater<>())`。`proj` を渡すと `comp(proj(a), proj(b))` で比べる (`std::ranges::sort` と同じ。`proj` には `&T::x` のようなメンバポインタも渡せる)。キーだけなら `sorted(c, {}, key)` | $O(n \log n)$ |
| `reversed(c)` | 逆順にしたコピーを返す | $O(n)$ |
| `sort(c)` / `sort(c, comp)` / `sort(c, comp, proj)` | その場でソート。降順は `sort(c, std::greater<>())`。`proj` は `sorted` と同じ。キーだけなら `sort(c, {}, key)` | $O(n \log n)$ |
| `reverse(c)` | その場で逆順にする | $O(n)$ |

## 集計

| 関数 | 説明 | 計算量 |
|---|---|---|
| `max(c)` / `min(c)` | 最大値 / 最小値 (空なら assert で落ちる)。`max({a, b, c})` のように初期化子リストも渡せる | $O(n)$ (`set` などソート済みのコンテナでは $O(1)$) |
| `sum(c)` | 総和 | $O(n)$ |
| `product(c)` | 総積 | $O(n)$ |
| `product_xor(c)` | 総 xor | $O(n)$ |
| `gcd(c)` | 全要素の gcd (空なら 0) | $O(n \log \max)$ |
| `average(c)` | 平均 (`sum(c) / size`、整数型なら 0 方向に切り捨て。空なら assert で落ちる) | $O(n)$ |
| `median(c)` | 中央値 (要素数が偶数なら中央 2 つの平均。空なら assert で落ちる) | $O(n \log n)$ |
| `mex(c)` | 含まれない最小の非負整数 | $O(n)$ |

## 検索

| 関数 | 説明 | 計算量 |
|---|---|---|
| `find(c, x)` | `x` を指すイテレータ (なければ `end()`) | $O(n)$ (`set` などでは $O(\log n)$) |
| `count(c, x)` | `x` の個数 | $O(n)$ (`multiset` などでは $O(\log n + k)$、$k$ は個数) |
| `contains(c, x)` | `x` を含むか | `find` と同じ |
| `index(c, x)` | `x` が最初に現れる位置 (`long long`。なければ `-1`) | $O(n)$ |
| `index_if(c, f)` | `f(x)` が `true` になる最初の位置 (`long long`。なければ `-1`) | $O(n)$ |
| `indices_if(c, f)` | `f(x)` が `true` になる位置を昇順に並べたもの (`std::vector<long long>`) | $O(n)$ |
| `count_if(c, f)` | `f(x)` が `true` になる要素の個数 (`long long`) | $O(n)$ |
| `lower_bound(c, x)` / `upper_bound(c, x)` | イテレータを返す | $O(\log n)$ |
| `bisect_left(c, x)` / `bisect_right(c, x)` | 添字を `long long` で返す (Python の `bisect`) | $O(\log n)$ (`set` などでは位置を数えるので $O(n)$) |

位置は、`set` などでは先頭から数えた順番です。

条件を満たす候補が 1 つだけのときに選ぶ、といった処理は `indices_if` で書けます。

```cpp
// t と長さが同じで 1 文字だけ違う名前が、ちょうど 1 つあればその位置
auto cand = indices_if(names, [&](const std::string& s) { return s.size() == t.size() && hamming_distance(s, t) == 1; });
if (cand.size() == 1) vote[cand[0]]++;
```

## 関連

- `hamming_distance` は [文字列アルゴリズム](../string/string.hpp)
- `std::vector` に対する演算子と関数は [vector に対する演算子と関数](vector_func.hpp)
