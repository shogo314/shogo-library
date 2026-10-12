---
title: vector に対する演算子と関数
documentation_of: //src/base/vector_func.hpp
---

`std::vector` に演算子と便利な関数を追加します。

```cpp
std::vector<int> a = {1, 2, 3};
a--;                              // 0-indexed にする: {0, 1, 2}
auto s = cumulative_sum(a);       // {0, 0, 1, 3}
auto b = a | 2;                   // {0, 1, 2, 0, 1, 2}
auto idx = sorted_idx(a, true);   // 値の降順に並べた添字
```

## 演算子

| 演算子 | 説明 |
|---|---|
| `++v`、`v++`、`--v`、`v--` | 全要素を ±1 (入力の 1-indexed を 0-indexed に直すときなど) |
| `v + x`、`x + v`、`v += x` | 全要素に `x` を足す |
| `v * x`、`x * v`、`v *= x` | 全要素に `x` を掛ける |
| `v + w`、`v += w` | 要素ごとの和 (短い方は 0 で埋める) |
| `v * w`、`v *= w` | 要素ごとの積 (長い方の余りは 0 になる) |
| `v |= w` | `w` を末尾に連結 (`extend` と同じ) |
| `v | k`、`k | v`、`v |= k` | `v` を `k` 回繰り返す |

## 関数

| 関数 | 説明 |
|---|---|
| `sorted_idx(v, reverse = false)` | 値の昇順 (降順) に並べた添字のリスト |
| `cumulative_sum(v)` | 先頭に 0 を付けた累積和 (長さ `size + 1`) |
| `iota(n)` | `{0, 1, ..., n-1}` |
| `unique(v)` | ソートして重複を除いたコピー |
| `abs(v)` | 全要素の絶対値 |
| `extend(v, w)` | `w` を末尾に連結 |
| `assign(v, w)` | `w` の内容で置き換える (型の変換つき) |
| `radix_convert(x, base = 10)` | 整数 `x` を `base` 進数の桁のリスト (上位桁から) にする |

## 関連

- コンテナ全般に使える関数 (`sorted`、`sum`、`bisect_left` など) は [コンテナに対する関数](container_func.hpp)
