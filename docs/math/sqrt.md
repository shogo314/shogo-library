---
title: 整数の平方根
documentation_of: //src/math/sqrt.hpp
---

| 関数 | 説明 | 計算量 |
|---|---|---|
| `sqrtll(n)` | $\lfloor \sqrt{n} \rfloor$ ($0 \le n < 2^{63}$)。浮動小数点の誤差なしで求める | $O(\log n)$ |

```cpp
long long r = sqrtll(1000000000000000000LL);  // 1000000000
long long s = sqrtll(15);                      // 3
```
