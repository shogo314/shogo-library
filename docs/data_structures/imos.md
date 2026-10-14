---
title: imos法で区間作用、1点取得
documentation_of: //src/data_structures/imos.hpp
---

区間作用と1点取得を imos 法で行います。作用と取得を交互に行ってもかまいません。

```cpp
Imos<acted_monoid::AddSum<long long>> imos(5);
imos.apply(1, 4, 10);
imos.apply(2, 5, 1);
imos.get(2);  // 11
Imos imos2(5, acted_monoid::AddSum<long long>());  // 作用素付きモノイドの値から型を推論する
```

作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡します。作用素はアーベル群 (可換群) をなし、逆作用素 `inv` を持つ必要があります (`AddSum`、`MulSum` など)。値のモノイドの演算 (`op`、`e`) は使いません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Imos(n, a = A())` | 要素数 `n`、各要素は `S()` で初期化 | $O(n)$ |
| `Imos(n, value, a = A())` | 要素数 `n`、各要素は `value` | $O(n)$ |
| `Imos(v, a = A())` | `v` で初期化 | $O(n)$ |
| `apply(k, f)` | `k` 番目に `f` を作用 | $O(1)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用 | $O(1)$ |
| `get(k)` | `k` 番目の値 | 下を参照 |

`get(k)` は、まだ反映していない作用を左から `k` 番目まで反映します。`get` の添字が増えていく間は全体で $O(n)$ です。区間作用で左端 `l` より右がすでに反映済みだった場合は、次の `get` で `l` から反映し直すので、最悪 $O(n)$ かかります。

## 関連

- 区間取得も必要なら [遅延伝搬セグメント木](lazy-segtree.hpp)
- 作用素が逆元を持たない (区間 chmin、区間代入など) ときは [双対セグメント木](dual-segtree.hpp)
