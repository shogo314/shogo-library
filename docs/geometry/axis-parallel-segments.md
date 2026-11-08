---
title: 軸に平行な線分の交点の個数
documentation_of: //src/geometry/axis-parallel-segments.hpp
---

水平か垂直な線分だけがあるとき、水平な線分と垂直な線分で共有点を持つ組の個数を、走査線と [Fenwick Tree](../data_structures/fenwick-tree.hpp) で $O(n \log n)$ で数えます。

```cpp
using P = Vector<long long>;
std::vector<Segment<long long>> segs = {
    {P(2, 2), P(2, 5)},  // 垂直
    {P(1, 3), P(5, 3)},  // 水平
};
long long k = axis_parallel_intersection_count(segs);  // 1
```

y の小さい順に走査し、そのときの y をまたいでいる垂直な線分の x を数えておきます。水平な線分に来たら、その x の範囲にある垂直な線分の個数を足します。

- 端点で接する組も数えます。
- 平行な線分どうしの共有点は数えません。
- 長さ 0 の線分は垂直な線分として扱います。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `axis_parallel_intersection_count(segs)` | 共有点を持つ (水平な線分, 垂直な線分) の組の個数 (`long long`)。`segs` は`Segment<T>` のリスト | $O(n \log n)$ |

## 関連

- 一般の 2 本の線分の交差判定は [線分](segment.hpp) の `segments_intersect`
