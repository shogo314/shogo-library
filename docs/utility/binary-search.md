---
title: 二分探索
documentation_of: //src/utility/binary-search.hpp
---

答えで二分探索をするための関数です。

```cpp
long long r = binary_search(0, 1000, [](long long m) { return m * m <= 500; });  // 22
double s = binary_search(0.0, 10.0, [](double m) { return m * m <= 2; });        // 1.41421...
```

## 関数

| 関数 | 説明 |
|---|---|
| `binary_search(ok, ng, f)` | `f(ok)` が真、`f(ng)` が偽として、境界で `f` が真になる側の値を返す。整数なら `ok` と `ng` の差が 1 になるまで、浮動小数点数なら 100 回二分する |

`ok` と `ng` はどちらが大きくてもかまいません。型が違う場合は `std::common_type_t` にそろえます。
