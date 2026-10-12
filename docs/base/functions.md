---
title: 汎用関数 (chmin, chmax, 二分探索など)
documentation_of: //src/base/functions.hpp
---

コンテストでよく使う小さな関数です。

```cpp
long long x = 10;
chmin(x, 3);                                                   // x = 3, true を返す
long long r = binary_search(0, 1000, [](long long m) { return m * m <= 500; });  // 22
double s = binary_search(0.0, 10.0, [](double m) { return m * m <= 2; });        // 1.41421...
if (inrect(i, j, h, w)) { /* グリッドの範囲内 */ }
```

## 関数

| 関数 | 説明 |
|---|---|
| `chmin(a, b)` / `chmax(a, b)` | `a` を `min(a, b)` / `max(a, b)` に更新し、更新したら `true` |
| `binary_search(ok, ng, f)` | `f(ok)` が真、`f(ng)` が偽として、境界で `f` が真になる側の値を返す。整数なら `ok` と `ng` の差が 1 になるまで、浮動小数点数なら 100 回二分する |
| `extgcd(a, b, x, y)` | $ax + by = \gcd(a, b)$ となる `x`、`y` を求め、$\gcd(a, b)$ を返す |
| `argcmp(a, b)` | `std::array<T, 2>` (整数) の偏角ソートの比較関数。x 軸正方向から反時計回り |
| `inrange(x, a)` | $0 \le x < a$ か |
| `inrange(x, a, b)` | $a \le x < b$ か |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) |

`std::abs`、`std::gcd`、`std::lcm`、`std::size` は `using` 宣言してあるので、`std::` なしで使えます。

## 関連

- 幾何ベクトルの偏角ソートは [幾何ベクトル](../geometry/vector.hpp) の `Vector::ArgSortComp`
