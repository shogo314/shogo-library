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

| 関数 | 説明 | 計算量 |
|---|---|---|
| `binary_search(ok, ng, f)` | `f(ok)` が真、`f(ng)` が偽として、境界で `f` が真になる側の値を返す。整数なら `ok` と `ng` の差が 1 になるまで、浮動小数点数なら 100 回二分する | `f` の呼び出し $O(\log \lvert ok - ng \rvert)$ 回 (浮動小数点数なら 100 回) |

`ok` と `ng` はどちらが大きくてもかまいません。型が違う場合は `std::common_type_t` にそろえます。整数では差を符号なしで求め、中点を [汎用関数](../base/functions.hpp) の `midpoint` で求めるので、`LLONG_MIN` と `LLONG_MAX` や `0` と `ULLONG_MAX` のように型の全範囲を渡してもあふれません。

## 関連

- ソート済みの列で値を探すなら [コンテナに対する関数](container_func.hpp) の `bisect_left(c, x)` / `lower_bound(c, x)`
- 区間を伸び縮みさせて探すなら [尺取り法](two-pointers.hpp)
