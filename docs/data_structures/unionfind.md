---
title: UnionFind
documentation_of: //src/data_structures/unionfind.hpp
---

無向グラフに辺を追加しながら、2頂点が連結かどうかを判定します。経路圧縮と union by size を行います。

```cpp
UnionFind uf(n);
uf.merge(0, 1);
uf.merge(1, 2);
bool b = uf.same(0, 2);   // true
int s = uf.size(0);       // 3
auto g = uf.groups();     // 連結成分ごとの頂点のリスト
```

## メンバ関数

計算量の $\alpha(n)$ はアッカーマン関数の逆関数で、実質定数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `UnionFind(n)` | 頂点数 `n`、辺なしで初期化 | $O(n)$ |
| `merge(a, b)` | 辺 $(a, b)$ を追加し、つながった連結成分の代表元を返す | $O(\alpha(n))$ |
| `same(a, b)` | `a` と `b` が連結か | $O(\alpha(n))$ |
| `leader(a)` | `a` の属する連結成分の代表元 | $O(\alpha(n))$ |
| `size(a)` | `a` の属する連結成分の頂点数 | $O(\alpha(n))$ |
| `groups()` | 連結成分ごとの頂点のリスト | $O(n)$ |

## 関連

- 連結成分ごとに値 (和・最小値など) を持つなら [可換モノイドを乗せるUnionFind](monoid-unionfind.hpp)
- 頂点間のポテンシャルの差を管理するなら [ポテンシャル付きUnionFind](potentialized-unionfind.hpp)
