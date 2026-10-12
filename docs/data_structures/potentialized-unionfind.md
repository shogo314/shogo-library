---
title: ポテンシャル付きUnionFind
documentation_of: //src/data_structures/potentialized-unionfind.hpp
---

各頂点のポテンシャル $p$ について「$p_b - p_a = w$」という情報を追加しながら、同じ連結成分の2頂点のポテンシャルの差を求めます。ポテンシャルは群 ([algebra/group.hpp](../algebra/group.hpp)) で、非可換でもかまいません。

```cpp
PotentializedUnionFind<group::Sum<long long>> uf(n);
uf.merge(0, 1, 3);           // p[1] - p[0] = 3
uf.merge(1, 2, -5);          // p[2] - p[1] = -5
long long d = uf.diff(0, 2); // p[2] - p[0] = -2
```

非可換な群では、「$p_b - p_a$」は $p_a^{-1} \cdot p_b$ を表します。つまり `merge(a, b, w)` は $p_b = p_a \cdot w$ という情報です。

## メンバ関数

計算量の $\alpha(n)$ はアッカーマン関数の逆関数で、実質定数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PotentializedUnionFind(n, g = G())` | 頂点数 `n` で初期化 | $O(n)$ |
| `merge(a, b, w)` | $p_b - p_a = w$ を追加する。[UnionFind](unionfind.hpp) と同じ `MergeResult` (代表元と、新しく統合したか) を返す。すでに連結なら何もしない (矛盾していても検出しない) | $O(\alpha(n))$ |
| `diff(a, b)` | $p_b - p_a$ (`a` と `b` は連結であること) | $O(\alpha(n))$ |
| `same(a, b)` | `a` と `b` が連結か | $O(\alpha(n))$ |
| `leader(a)` | `a` の属する連結成分の代表元 | $O(\alpha(n))$ |
| `size(a)` | `a` の属する連結成分の頂点数 | $O(\alpha(n))$ |
| `groups()` | 連結成分ごとの頂点のリスト | $O(n)$ |

矛盾を検出したい場合は、`merge` が統合しなかったとき (すでに連結だったとき) に `diff(a, b) == w` かどうかを見ます。

```cpp
if (!uf.merge(a, b, w) && uf.diff(a, b) != w) { /* 矛盾 */ }
```

## 関連

- ポテンシャルがない場合は [UnionFind](unionfind.hpp)
