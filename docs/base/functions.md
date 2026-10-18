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

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chmin(a, b)` / `chmax(a, b)` | `a` を `min(a, b)` / `max(a, b)` に更新し、更新したら `true` | $O(1)$ |
| `extgcd(a, b, x, y)` | $ax + by = \gcd(a, b)$ となる `x`、`y` を求め、$\gcd(a, b)$ を返す | $O(\log \max(\lvert a \rvert, \lvert b \rvert))$ |
| `floordiv(a, b)` / `ceildiv(a, b)` | $\lfloor a / b \rfloor$ / $\lceil a / b \rceil$ ($b \ne 0$、負の数も可) | $O(1)$ |
| `divmod(a, b)` | `std::pair` で $\lfloor a / b \rfloor$ と $a - b \lfloor a / b \rfloor$ を返す ($b \ne 0$、負の数も可。余りは 0 か $b$ と同じ符号) | $O(1)$ |
| `inrange(x, a)` | $0 \le x < a$ か | $O(1)$ |
| `inrange(x, a, b)` | $a \le x < b$ か | $O(1)$ |
| `inrect(x, y, a, b)` | $0 \le x < a$ かつ $0 \le y < b$ か | $O(1)$ |
| `max(a, b)` / `min(a, b)` | `long long` に揃えて比較する (`int` と `long long` を混ぜて渡せる) | $O(1)$ |
| `abs(x)` | `std::abs` | $O(1)$ |
| `gcd(a, b)` / `lcm(a, b)` | `std::gcd` / `std::lcm` | $O(\log \max(\lvert a \rvert, \lvert b \rvert))$ |
| `size(c)` | `std::size` (コンテナや配列の要素数) | $O(1)$ |
| `midpoint(a, b)` | `std::midpoint`。$a$ と $b$ の中点をあふれずに求める (整数は $a$ の側に丸める)。ポインタも可 | $O(1)$ |

`abs`、`gcd`、`lcm`、`size`、`midpoint` は `std::` 版を `using` 宣言したものなので、`std::` なしで使えます。`std::midpoint` は C++20 からなので、C++17 では同じ値を返すものを自前で用意しています。

## 関連

- 二分探索 `binary_search` は [二分探索](../utility/binary-search.hpp)
- 偏角ソートは [偏角](../geometry/angle.hpp) の `Angle`
