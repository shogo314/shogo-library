---
title: 区間内の異なる値の個数
documentation_of: //src/data_structures/range-count-distinct.hpp
---

固定した列について、区間 $[l, r)$ に現れる異なる値の個数を、クエリごとに $O(\log n)$ で答えます。クエリを先読みしないので、オンラインで使えます。

```cpp
std::vector<int> a = {1, 2, 1, 3, 2};
RangeCountDistinct rcd(a);
long long k = rcd.count(0, 3);  // {1, 2} の 2
long long m = rcd.count(1, 5);  // {1, 2, 3} の 3
```

位置 $i$ より前に同じ値が現れた最後の位置を $\mathit{prev}_i$ (なければ $-1$) とすると、$[l, r)$ の異なる値の個数は $l \le i < r$ かつ $\mathit{prev}_i < l$ となる $i$ の個数です。$\mathit{prev}$ を [Wavelet Matrix](wavelet-matrix.hpp) に載せて数えます。

値の型は `operator<` で比べられれば何でもかまいません (`std::string` なども使えます)。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RangeCountDistinct(a)` | 列 `a` から作る | $O(n \log n)$ |
| `size()` | 要素数 | $O(1)$ |
| `count(l, r)` | `a[l], ..., a[r-1]` に現れる異なる値の個数 | $O(\log n)$ |

## 関連

- 区間の $k$ 番目や、値が範囲に入る要素の個数は [Wavelet Matrix](wavelet-matrix.hpp)
- クエリを先読みしてよく、区間を伸び縮みさせて数えたいなら [Mo's algorithm](../others/mo.hpp)
