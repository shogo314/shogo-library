---
title: 円環
documentation_of: //src/data_structures/circular-ring.hpp
---

添字を長さで割った余りでアクセスできる配列です。負の添字も使えます。

```cpp
CircularRing<int> r(std::vector<int>{10, 20, 30});
int a = r[3];    // 10
int b = r[-1];   // 30
r[-1] = 99;      // data = {10, 20, 99}
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CircularRing<T>(v)` | `v` で初期化 | $O(n)$ |
| `CircularRing<T>(n)` | 長さ `n` で、要素は `T()` | $O(n)$ |
| `r[i]` / `r.at(i)` | $i \bmod n$ 番目の要素 (`long long` の添字、負でもよい) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `data` | 中身の `std::vector<T>` |

## 関連

- 途中からループする配列は [おたまじゃくし配列](tadpole-array.hpp)
