---
title: 整数の平方根・k 乗根
documentation_of: //src/math/sqrt.hpp
---

$\lfloor \sqrt{n} \rfloor$ と $\lfloor a^{1/k} \rfloor$ を浮動小数点の誤差なしで求めます。

```cpp
long long r = sqrtll(1000000000000000000LL);  // 1000000000
long long s = sqrtll(15);                      // 3
unsigned long long c = kth_root(27, 3);        // 3
unsigned long long d = kth_root(18446744073709551615ULL, 2);  // 4294967295
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sqrtll(n)` | $\lfloor \sqrt{n} \rfloor$ ($0 \le n < 2^{63}$。負なら assert で落ちる) | $O(\log n)$ |
| `kth_root(a, k)` | $\lfloor a^{1/k} \rfloor$ (`unsigned long long`、$0 \le a < 2^{64}$、$k \ge 1$) | $O(k)$ |

## 関連

- $\lfloor n/i \rfloor$ の値ごとにまとめるには [商の列挙](quotients.hpp)
- 素数判定・素因数分解は [素数](prime.hpp)
