---
title: Python の range のような整数列と、その直積の Rect
documentation_of: //src/utility/range.hpp
---

Python の `range` のような、等差数列を表す `Range` です。要素を実際には持たないので、長い列でもメモリを使いません。

```cpp
for (long long i : Range(2, 10, 3)) { /* 2, 5, 8 */ }
Range r(10, 0, -3);       // 10, 7, 4, 1
r.size();                 // 4
r.sum();                  // 22
r.contains(4);            // true
r.index(4);               // 2
Range(10).product_xor();  // 0 ^ 1 ^ ... ^ 9 = 1
```

`sum`、`max` などのメンバ関数を持つので、[コンテナに対する関数](container_func.hpp) の `sum(r)`、`max(r)` などから呼ぶと $O(1)$ で計算されます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Range(stop)` | `0, 1, ..., stop-1` | $O(1)$ |
| `Range(start, stop)` | `start, start+1, ..., stop-1` | $O(1)$ |
| `Range(start, stop, step)` | `start, start+step, ...` (`stop` の手前まで)。`step` は負でもよいが 0 は不可 | $O(1)$ |
| `begin()` / `end()` | ランダムアクセスイテレータ | $O(1)$ |
| `size()` / `empty()` | 要素数 (`long long`) / 空か | $O(1)$ |
| `r[i]` / `at(i)` | `i` 番目の要素 (`i` は `long long`) | $O(1)$ |
| `count(x)` / `contains(x)` | `x` の個数 (0 か 1) / `x` を含むか (`step` が 1 なら割り算をしない) | $O(1)$ |
| `index(x)` | `x` の位置 (`long long`。含まなければ assert で落ちる。`step` が 1 なら割り算をしない) | $O(1)$ |
| `find(x)` | `x` を指すイテレータ (なければ `end()`) | $O(1)$ |
| `lower_bound(x)` / `upper_bound(x)` | `x` 以上 / `x` より大きい最初の要素 (`step > 0` のみ) | $O(1)$ |
| `sum()` | 総和 | $O(1)$ |
| `min()` / `max()` | 最小値 / 最大値 (空なら assert で落ちる) | $O(1)$ |
| `product_xor()` | 総 xor (要素は非負) | $O(\log^2 \max)$ |
| `reversed()` | 逆順の `Range` | $O(1)$ |
| `sorted()` | 昇順の `Range` | $O(1)$ |
| `clipped(l, r)` | 要素のうち `l` 以上 `r` 未満のものの `Range` | $O(1)$ |
| `slice(s)` | 位置を `Range` `s` で選んだ `Range` (Python の `r[a:b:c]`) | $O(1)$ |
| `to_vector()` | `std::vector<long long>` にする | $O(n)$ |
| `==`、`!=` | 要素の列として等しいか (`Range(0, 5, 2) == Range(0, 6, 2)`) | $O(1)$ |
| `repr()` | `"Range(start, stop, step)"` ([repr](repr.hpp) 用) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `start` / `stop` / `step` | コンストラクタに渡した値 (`const` なので読むだけ) |

## Rect

2 つの `Range` の直積 `rows × cols` です。`(i, j)` を `i` の昇順、同じ `i` では `j` の昇順 (行優先) に並べた列として扱います。グリッドの走査や範囲内の判定、頂点番号への変換に使います。

```cpp
for (auto [i, j] : Rect(h, w)) { /* (0, 0), (0, 1), ..., (h-1, w-1) */ }
const Rect grid(h, w);
grid.contains(ni, nj);    // 0 <= ni < h かつ 0 <= nj < w か (inrect と同じ)
grid.index(i, j);         // i * w + j
grid[k];                  // index の逆 (k / w, k % w)
for (auto [ni, nj] : grid.neighbors4(i, j)) { /* 範囲内の上下左右 */ }
Rect({1, 4}, {10, 0, -5}) // {1, 2, 3} × {10, 5}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Rect(h, w)` | $[0, h) \times [0, w)$ | $O(1)$ |
| `Rect(rows, cols)` | `Range` 2 つの直積。`Rect({1, 4}, {0, 10, 2})` のように `Range` の初期化子を直接書ける | $O(1)$ |
| `begin()` / `end()` | 前方向イテレータ。要素は `std::pair<long long, long long>` で、`auto [i, j]` で受け取れる | $O(1)$ |
| `size()` / `empty()` | 要素数 (`long long`) / 空か | $O(1)$ |
| `contains(i, j)` / `contains(p)` | `(i, j)` を含むか | $O(1)$ |
| `index(i, j)` / `index(p)` | 行優先での位置 (含まなければ assert で落ちる) | $O(1)$ |
| `r[k]` / `at(k)` | 行優先で `k` 番目の要素 | $O(1)$ |
| `neighbors4(i, j)` / `neighbors4(p)` | `(i, j)` の上下左右のうち `Rect` に含まれるもの (`(i, j)` は含まれていること) | $O(1)$ |
| `neighbors8(i, j)` / `neighbors8(p)` | `(i, j)` を囲む 8 つのうち `Rect` に含まれるもの | $O(1)$ |
| `==`、`!=` | 要素の列として等しいか | $O(1)$ |
| `repr()` | `"Rect(Range(...), Range(...))"` ([repr](repr.hpp) 用) | $O(1)$ |
| `rows` / `cols` | 行と列の `Range` (`const` なので読むだけ) | |

`neighbors4` / `neighbors8` は範囲 for で回せるもの (`size()`、`empty()` もある) を返し、要素は `Rect` の順 (行優先) に並びます。隣は `rows`・`cols` の中で隣り合う要素なので、`step` が 1 でなければ `i ± rows.step` などになります。

その場で作った `Rect(h, w).contains(i, j)` は `inrect(i, j, h, w)` と同じ速さです。変数に入れた `Rect` でも、`step` が 1 なら割り算をしないので、ほぼ同じ速さになります。`for (auto [i, j] : Rect(h, w))` は、ループの中身がごく軽いと 2 重ループより 3 割ほど遅くなります。`neighbors4` を使ったグリッドの BFS も、`dx`、`dy` の配列と `inrect` で書いたものより 3 割ほど遅くなります。C++20 では `std::ranges::forward_range` と `sized_range` を満たします。ただし `Range` と同じく代入できないので、`views` に渡すときは一時オブジェクトではなく変数を渡します。

## 関連

- `sum(r)`、`max(r)` などのコンテナ全般の関数は [コンテナに対する関数](container_func.hpp)
- `repr(r)` で文字列にするなら [repr](repr.hpp)
- 範囲内の判定だけなら [汎用関数](../base/functions.hpp) の `inrange`、`inrect`
