---
title: 可換モノイドを乗せるUnionFind
documentation_of: //src/data_structures/monoid-unionfind.hpp
---

各頂点に値を持たせ、連結成分ごとの値の総積を管理する [UnionFind](unionfind.hpp) です。可換モノイド ([algebra/monoid.hpp](../algebra/monoid.hpp)) を渡して使います。

```cpp
std::vector<long long> w = {1, 2, 3, 4, 5};
MonoidUnionFind<monoid::Sum<long long>> uf(w);
uf.merge(0, 1);
uf.merge(3, 4);
long long s = uf.prod(1);   // 1 + 2 = 3

// ラムダ式から作ったモノイドも渡せる
MonoidUnionFind uf2(v, Monoid([](int a, int b) { return std::min(a, b); }, INF));
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MonoidUnionFind(n, m = M())` | 頂点数 `n`、各頂点の値は単位元 | $O(n)$ |
| `MonoidUnionFind(v, m = M())` | 各頂点の値を `v` で初期化 | $O(n)$ |
| `merge(a, b)` | 辺 $(a, b)$ を追加する。2つの連結成分の値の積が新しい値になる。[UnionFind](unionfind.hpp) と同じ `MergeResult` (代表元と、新しく統合したか) を返す | $O(\alpha(n))$ |
| `prod(a)` | `a` の属する連結成分の値の総積 | $O(\alpha(n))$ |
| `same(a, b)`、`leader(a)`、`size(a)`、`groups()` | [UnionFind](unionfind.hpp) と同じ | $O(\alpha(n))$ (`groups()` は $O(n)$) |

連結後の値は、どちらの成分が親になるかで積の順序が変わります。そのため、モノイドは可換である必要があります。

## 関連

- 値を持たない [UnionFind](unionfind.hpp)
- 頂点間のポテンシャルの差を管理するなら [ポテンシャル付きUnionFind](potentialized-unionfind.hpp)
