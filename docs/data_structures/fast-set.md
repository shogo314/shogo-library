---
title: 64 分木 (FastSet)
documentation_of: //src/data_structures/fast-set.hpp
---

$[0, n)$ の整数の集合を 64 分木で持ちます。挿入・削除・$x$ 以上の最小の要素・$x$ 以下の最大の要素を $O(\log_{64} n)$ で求めます。$n = 10^6$ なら 4 段、$n = 10^9$ でも 5 段なので、`std::set` よりかなり速く動きます。値の範囲が決まっている整数の集合で、`std::set` の `lower_bound` の代わりに使います。

```cpp
FastSet s(n);
s.insert(3);
s.insert(10);
long long a = s.next(4);  // 10 (4 以上の最小)
long long b = s.prev(4);  // 3 (4 以下の最大)
long long c = s.next(11); // -1 (なし)
s.erase(10);
```

各段は 64 bit の配列で、一番下の段の bit が要素を、上の段の bit は 1 つ下の段の 64 bit が 0 でないかを表します。上の段で 0 でない場所を見つけてから下の段へ降りるので、空いている範囲を 64 個ずつ飛ばせます。

## メンバ関数

値は `long long` です。要素がないときは `-1` を返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `FastSet(n = 0)` | $[0, n)$ の空の集合 | $O(n / 64)$ |
| `FastSet(v)` | `std::vector<bool>` `v` で `v[i]` が `true` の `i` からなる集合 ($n$ は `v.size()`) | $O(n)$ |
| `limit()` | 扱える範囲 $[0, n)$ の $n$ | $O(1)$ |
| `size()` / `empty()` | 要素数 / 空か | $O(1)$ |
| `contains(x)` / `count(x)` | `x` が含まれるか / `x` の個数 (0 か 1) | $O(1)$ |
| `insert(x)` | `x` を挿入する。新しく入ったら `true` | $O(\log_{64} n)$ |
| `erase(x)` | `x` を削除する。入っていたら `true` | $O(\log_{64} n)$ |
| `next(x)` | `x` 以上の最小の要素 (なければ `-1`)。`x` は範囲の外 (負や $n$ 以上) でもよい | $O(\log_{64} n)$ |
| `prev(x)` | `x` 以下の最大の要素 (なければ `-1`)。`x` は範囲の外でもよい | $O(\log_{64} n)$ |
| `min()` / `max()` | 最小 / 最大の要素 (空なら `-1`) | $O(\log_{64} n)$ |
| `to_vector()` | 要素を昇順に並べたもの | $O(\mathrm{size} \cdot \log_{64} n)$ |
| `clear()` | すべて削除する | $O(n / 64)$ |

`insert`、`erase`、`contains` に渡す `x` は $0 \le x < n$ である必要があります。メモリは約 $n / 8$ バイトです ($n = 10^9$ で約 125 MB)。

## 関連

- 値の範囲が大きい・負の値がある・重複がある場合は、座標圧縮してから使うか `std::set` / `std::multiset`
- 区間ごとにまとめた集合 (区間の追加・削除) なら [区間の集合](interval-set.hpp)
- 0 以上の整数の集合で mex を求めるなら [mex](mex-update.hpp)
