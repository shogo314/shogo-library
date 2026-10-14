---
title: 整数の平方根
documentation_of: //src/math/sqrt.hpp
---

$\lfloor \sqrt{n} \rfloor$ を浮動小数点の誤差なしで求めます。

```cpp
long long r = sqrtll(1000000000000000000LL);  // 1000000000
long long s = sqrtll(15);                      // 3
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sqrtll(n)` | $\lfloor \sqrt{n} \rfloor$ ($0 \le n < 2^{63}$。負なら assert で落ちる) | $O(\log n)$ |

## 関連

- $\lfloor n/i \rfloor$ の値ごとにまとめるには [商の列挙](quotients.hpp)
- 素数判定・素因数分解は [素数](prime.hpp)
