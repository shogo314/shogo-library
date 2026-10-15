---
title: 1点更新・全体の mex 取得
documentation_of: //src/data_structures/mex-update.hpp
---

長さ $n$ の数列について、1点更新と、全体の mex (含まれない最小の非負整数) の取得を行います。

```cpp
MexUpdate<int> mu(std::vector<int>{0, 1, 3});
int a = mu.mex();     // 2
mu.set(1, 5);         // {0, 5, 3}
int b = mu.mex();     // 1
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MexUpdate<T>(n)` | 長さ `n` で、どの要素もまだ値を持たない (mex は 0) | $O(n)$ |
| `MexUpdate<T>(v)` | `v` で初期化 | $O(n \log n)$ |
| `set(k, x)` | `k` 番目を `x` に更新 | $O(\log n)$ |
| `mex()` | 全体の mex | $O(1)$ |

`T` は整数型です (符号なしの型でもかまいません)。負の値や $n$ より大きい値も入れられます (mex には影響しません)。

## 関連

- 値ごとの個数を数えるなら [Counter](counter.hpp)
