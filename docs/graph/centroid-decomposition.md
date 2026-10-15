---
title: 重心分解
documentation_of: //src/graph/centroid-decomposition.hpp
---

木の重心を取り除き、残った部分木それぞれで同じことをくり返します。取り除いた重心を親子にした木 (重心木) の深さは $O(\log n)$ です。木のパスを「どの重心を通るか」で分けて数える、木の分割統治に使います。

```cpp
Tree<int> tree(n);
tree.read();
CentroidDecomposition cd(tree);
// 重心 c を通るパスを、c の先の部分木ごとに数える
for (long long c : cd.order()) {
    for (const auto& sub : cd.subtrees(tree, c)) {
        for (auto [v, d] : sub) { /* v は c の成分の頂点、d は c からの距離 */ }
    }
}
```

重心 $c$ の成分 ($c$ を取り除く直前に $c$ を含んでいた部分木) は、$c$ から `level` が $c$ より大きい頂点だけをたどって得られます。`subtrees` を使わずに自分でたどるときは、この条件で枝を切ります。

```cpp
// c の成分を DFS する (p は直前の頂点)
auto dfs = [&](auto self, long long v, long long p) -> void {
    for (long long u : tree[v]) {
        if (u == p || cd.level(u) <= cd.level(c)) continue;
        self(self, u, v);
    }
};
```

頂点番号などは `long long` です。前計算は $O(n \log n)$ で、再帰を使いません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `CentroidDecomposition(tree)` | 木 `tree` (`Tree<Cost>`) を重心分解する | $O(n \log n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `root()` | 重心木の根 (最初に取り除いた重心) | $O(1)$ |
| `parent(v)` | 重心木での `v` の親 (根なら -1) | $O(1)$ |
| `level(v)` | 重心木での `v` の深さ (根なら 0)。$\lfloor \log_2 n \rfloor$ 以下 | $O(1)$ |
| `order()` | 重心を取り除いた順に並べた列。重心木の親は子より前にある | $O(1)$ |
| `subtrees(tree, c)` | 重心 `c` の成分から `c` を取り除いた、それぞれの部分木の `(頂点, c からの距離)` の一覧。距離は辺の重みの和 (重みなしで読んだ木なら辺の数) | 成分の大きさ (すべての `c` で合わせて $O(n \log n)$) |

## 関連

- パスや部分木へのクエリをセグメント木などで処理するなら [HL 分解](heavy-light-decomposition.hpp)
- 木の基本的な操作は [木の汎用テンプレート](tree.hpp)
- 距離ごとの組の個数を求めるときの畳み込みは [畳み込み (NTT)](../math/convolution.hpp) の `convolution_ll`
