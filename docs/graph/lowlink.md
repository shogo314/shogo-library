---
title: lowlink (関節点、橋、二重辺連結成分分解、二重頂点連結成分分解、Block-Cut Tree)
documentation_of: //src/graph/lowlink.hpp
---

無向の [グラフ](graph.hpp) について、DFS の lowlink を求め、関節点・橋・二重辺連結成分・二重頂点連結成分と Block-Cut Tree を求めます。DFS は再帰を使わないので、深いグラフでもスタックがあふれません。$O(n + m)$ です。

多重辺と自己ループがあってもかまいません。親へ戻る辺は、頂点ではなく辺の番号で区別しています。自己ループは連結性に関係しないので、どの二重頂点連結成分の辺にも入れません。

```cpp
Graph<int> g(n);
g.read(m, 0);
LowLink ll(g);
for (long long v : ll.articulation_points()) { /* 関節点 */ }
for (long long id : ll.bridges()) { auto e = g.edges()[id]; /* 橋 e.src - e.dst */ }
auto groups = ll.two_edge_connected_groups();
auto blocks = ll.two_vertex_connected_groups();  // 二重頂点連結成分ごとの頂点
Tree<int> bct = ll.block_cut_tree();             // 頂点 n + b が成分 b
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `LowLink(g)` | 無向グラフ `g` から求める | $O(n + m)$ |
| `size()` | 頂点数 | $O(1)$ |
| `articulation_points()` | 関節点 (取り除くと連結成分が増える頂点) の番号の昇順のリスト | $O(1)$ |
| `is_articulation_point(v)` | `v` が関節点か | $O(1)$ |
| `bridges()` | 橋 (取り除くと連結成分が増える辺) の辺の番号 (`Edge::id`) の昇順のリスト | $O(1)$ |
| `is_bridge(id)` | 番号 `id` の辺が橋か | $O(1)$ |
| `two_edge_connected_groups()` | 二重辺連結成分 (橋をすべて取り除いたときの連結成分) ごとの頂点のリスト | $O(1)$ |
| `two_edge_connected_group_id(v)` | `v` が属する二重辺連結成分の番号 (`two_edge_connected_groups()` の添字) | $O(1)$ |
| `two_vertex_connected_groups()` | 二重頂点連結成分ごとの頂点のリスト。関節点は複数の成分に入る。ほかの頂点とつながっていない頂点は、それだけで 1 つの成分になる | $O(1)$ |
| `two_vertex_connected_edge_groups()` | 二重頂点連結成分ごとの辺の番号のリスト (`two_vertex_connected_groups()` と同じ順)。自己ループ以外の辺はちょうど 1 つの成分に入る | $O(1)$ |
| `two_vertex_connected_group_id(id)` | 番号 `id` の辺が属する二重頂点連結成分の番号 (自己ループなら -1) | $O(1)$ |
| `block_cut_tree()` | Block-Cut Tree を [`Tree<int>`](tree.hpp) で返す (下を参照) | $O(n + m)$ |

頂点番号・辺の番号・成分の番号は `long long` です。

## メンバ変数

| 変数 | 説明 |
|---|---|
| `ord[v]` | DFS で訪れた順番 |
| `low[v]` | DFS 木の子孫から、木の辺を逆にたどらずに 1 本の後退辺で行ける頂点の `ord` の最小値 (lowlink の値) |

## 二重頂点連結成分と Block-Cut Tree

二重頂点連結成分は、どの頂点を 1 つ取り除いても連結なままの、極大な部分グラフです。どの辺もちょうど 1 つの成分に入り、関節点だけが複数の成分にまたがります。橋は、その辺だけで 1 つの成分になります。

`block_cut_tree()` は、頂点 $0, \dots, n - 1$ を元の頂点、頂点 $n + b$ を成分 $b$ として、元の頂点と、それを含む成分を辺で結んだグラフを返します。元のグラフが連結なら木、そうでなければ森です。森のときは、[HL 分解](heavy-light-decomposition.hpp) などの連結であることを前提とする木の関数には渡せません。

- 元の頂点の次数は、それを含む成分の個数です。次数が 2 以上なのは関節点だけです。
- $u$ から $v$ へのどの道も必ず通る頂点は、Block-Cut Tree 上の $u$ と $v$ を結ぶパスにある元の頂点 (端の $u$、$v$ を除く) です。HL 分解に渡せば、パスの長さなどからクエリに答えられます。
- 頂点 $x$ を取り除いたときに増える連結成分の数は、Block-Cut Tree での $x$ の次数から 1 を引いた数です (ほかの頂点とつながっていない $x$ なら、成分が 1 つ減ります)。

## 関連

- 有向グラフの強連結成分分解は [グラフに関する関数](graph_util.hpp) の `strongly_connected_components`
