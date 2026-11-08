---
title: 巻き戻しのできる UnionFind
documentation_of: //src/data_structures/rollback-unionfind.hpp
---

連結成分の統合を、保存した履歴の位置まで巻き戻せる UnionFind です。union by size を使い、経路圧縮はしません。

```cpp
RollbackUnionFind uf(4);
uf.merge(0, 1);
long long t = uf.snapshot();
uf.merge(1, 2);
uf.rollback(t);
uf.same(0, 1);  // true
uf.same(0, 2);  // false
```

`snapshot()` は現在の履歴の位置を返し、もともと同じ成分への `merge` では増えません。`rollback(t)` には現在の履歴上の祖先の位置を渡してください。巻き戻した後に別の統合を行うと、捨てた側の履歴は復元できません。コピーは履歴も含めて独立し、時間・追加メモリは頂点数と履歴の長さに比例します。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RollbackUnionFind(n = 0)` | `n` 頂点、統合なしで初期化 | $O(n)$ |
| `merge(a, b)` | 統合後の代表元 `leader` と、新しく統合したか `merged` を返す。`if (uf.merge(a, b))` でも判定可能 | $O(\log n)$ |
| `leader(a)` | `a` の代表元 | $O(\log n)$ |
| `same(a, b)` | 同じ成分か | $O(\log n)$ |
| `size(a)` | `a` の成分の頂点数 | $O(\log n)$ |
| `snapshot()` | 現在の履歴の位置 | $O(1)$ |
| `rollback(t)` | 保存した位置 `t` まで巻き戻す | 戻す統合数に比例 |
| `groups()` | 連結成分ごとの頂点の列 | $O(n\log n)$ |

## 関連

- 巻き戻しが不要なら [UnionFind](unionfind.hpp)
- 複数の過去の版を残すなら [永続 UnionFind](persistent-unionfind.hpp)
