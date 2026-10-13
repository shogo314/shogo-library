---
title: 汎用関数 (chmin, chmax など)
documentation_of: //src/base/functions.hpp
---

コンテストでよく使う小さな関数です。

```cpp
long long x = 10;
chmin(x, 3);  // x = 3, true を返す
if (inrect(i, j, h, w)) { /* グリッドの範囲内 */ }
```

## 関数

| 関数 | 説明 |
|---|---|
| `chmin(a, b)` / `chmax(a, b)` | `a` を `min(a, b)` / `max(a, b)` に更新し、更新したら `true` |
| `extgcd(a, b, x, y)` | $ax + by = \gcd(a, b)$ となる `x`、`y` を求め、$\gcd(a, b)$ を返す |
| `inrange(x, a)` | $0 \le x < a$ か |
| `inrange(x, a, b)` | $a \le x < b$ か |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) |

`std::abs`、`std::gcd`、`std::lcm`、`std::size` は `using` 宣言してあるので、`std::` なしで使えます。

## 関連

- 二分探索 `binary_search` は [二分探索](../utility/binary-search.hpp)
- 偏角ソートは [偏角](../geometry/angle.hpp) の `Angle`
