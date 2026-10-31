---
title: 木に関する関数
documentation_of: //src/graph/tree_util.hpp
---

[木](tree.hpp) `Tree<Cost>` を受け取る関数です。

```cpp
Tree<long long> t(n);
t.read(-1, true);
auto path = tree_diameter(t);  // 直径を構成する辺 (端点から順に)
auto c = tree_center(t);       // 中心 (1 つか 2 つ)
auto groups = tree_diameter_endpoint_groups(t); // 異なるグループの 2 点 ⇔ 直径の両端
auto id = rooted_tree_isomorphism(t, 0); // 0 を根として、id[u] == id[v] なら u と v を根とする部分木は同型
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `tree_diameter(tree, weighted = true)` | 直径を構成する辺のリスト (`std::vector<Edge>`、端点から順に)。頂点が 1 つなら空。`weighted = false` なら辺の本数で測る | $O(n)$ |
| `tree_center(tree)` | 中心 (最も遠い頂点までの辺の本数が最小の頂点) のリスト (`std::vector<long long>`)。1 つか 2 つで、2 つなら隣接していて小さい順。辺の本数で測る | $O(n)$ |
| `tree_diameter_endpoint_groups(tree)` | 直径の端点を分けたグループのリスト (`std::vector<std::vector<long long>>`)。2 点 $u, v$ の距離が直径に等しいのは、$u, v$ が異なるグループにあるとき、かつそのときに限る。グループはどれも空でなく 2 つ以上 (頂点数 1 なら `{ {0} }`)。辺の本数で測る | $O(n)$ |
| `rooted_tree_isomorphism(tree, root)` | `root` を根とする根付き木で、各頂点を根とする部分木の分類番号 (`std::vector<long long>`)。同型なとき、かつそのときに限り同じ番号で、番号は 0 から隙間なく振る。ハッシュではないので衝突しない | $O(n \log n)$ |

`tree_diameter` は辺の重みが非負であることを仮定します。

直径はすべて中心を通るので、`tree_diameter_endpoint_groups` は直径の長さが偶数なら中心からその長さの半分の距離にある頂点を中心のどの隣接頂点の側にあるかで分け、奇数なら中心の 2 頂点を結ぶ辺のどちら側にあるかで 2 つに分けます。直径の両端になる組を、グループの大きさから数えられます (同じ色の組を数えるなら、色ごとに全体の組から同じグループ内の組を引く)。

番号は呼び出しごとに振り直すので、別々に呼んだ結果どうしは比べられません。2 つの根付き木を比べるときは、新しい頂点を 1 つ足して両方の根をその子にした 1 つの木で呼び、2 つの根の番号を比べます。根のない木どうしなら、それぞれの中心 (`tree_center`) を根にして同じことをします。

## 関連

- 各頂点から最も遠い頂点までの距離 (`farthest_node_dist`) や距離の和 (`distance_sums`) は [全方位木DP](rerooting-dp.hpp) にあります
- `Graph` を受け取る関数は [グラフに関する関数](graph_util.hpp)
