---
title: 偏角ソートの比較関数
documentation_of: //src/geometry/argcmp.hpp
---

`std::array<T, 2>` (`T` は整数型) の点を偏角で比べる関数です。

```cpp
std::vector<std::array<long long, 2>> ps(n);
std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return argcmp(a, b); });
```

## 関数

| 関数 | 説明 |
|---|---|
| `argcmp(a, b)` | `a` の偏角が `b` の偏角より小さいか。x 軸正方向を 0 として反時計回りに $[0, 2\pi)$ で比べ、零ベクトルは x 軸正方向と同じ偏角として扱う |

外積を計算するので、座標の絶対値の 2 乗が `T` に収まる必要があります。

## 関連

- [幾何ベクトル](vector.hpp) の `Vector` を使う場合は `Vector::ArgSortComp`
