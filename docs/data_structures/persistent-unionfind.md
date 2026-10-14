---
title: 永続UnionFind
documentation_of: //src/data_structures/persistent-unionfind.hpp
---

過去の版を残したまま辺を追加できる UnionFind です。`merge` は元の版を変えずに新しい版を返します。[永続配列](persistent-array.hpp) の上で union by size を行い、経路圧縮はしません。版のコピーは $O(1)$ です。

```cpp
PersistentUnionFind uf0(n);
auto uf1 = uf0.merge(0, 1);   // uf0 はそのまま
auto uf2 = uf1.merge(1, 2);
uf2.same(0, 2);               // true
uf1.same(0, 2);               // false

// 版を配列に並べる (クエリ i の後の版を uf[i + 1] に置く)
std::vector<PersistentUnionFind> uf(q + 1);
uf[0] = PersistentUnionFind(n);
uf[i + 1] = uf[k + 1].merge(u, v);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentUnionFind(n)` | 頂点数 `n`、辺なしで初期化 | $O(\log n)$ |
| `merge(a, b)` | 辺 $(a, b)$ を追加した新しい版を返す (もともと連結なら同じ版) | $O(\log^2 n)$ |
| `same(a, b)` | `a` と `b` が連結か | $O(\log^2 n)$ |
| `leader(a)` | `a` の属する連結成分の代表元 | $O(\log^2 n)$ |
| `size(a)` | `a` の属する連結成分の頂点数 | $O(\log^2 n)$ |
| `groups()` | 連結成分ごとの頂点のリスト | $O(n \log^2 n)$ |

`UnionFind` と違い、`merge` は `MergeResult` ではなく新しい版を返します。新しく統合したかを知りたいときは、先に `same(a, b)` で確かめます。

## 関連

- 過去の版が要らないなら [UnionFind](unionfind.hpp)
