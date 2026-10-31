---
title: 木の汎用テンプレート
documentation_of: //src/graph/tree.hpp
---

木は 3 段階のクラスで表します。必要な機能に応じて、根なし木から変換して使います。

```cpp
Tree<long long> t(n);
t.read(-1, true);                      // n-1 本の辺を読む (1-indexed、重み付き)

RootedTree rt = t.set_root(0);         // 根付き木 (親・子・深さ・部分木サイズなど)
DoublingClimbTree dt = t.build_lca(0); // LCA・k 個上の祖先・2頂点間距離
```

## どのクラスで何ができるか

| 機能 | `Tree` | `RootedTree` | `DoublingClimbTree` |
|---|:-:|:-:|:-:|
| 辺の追加 (`add_edge`)・入力 (`read`) | ✓ | | |
| `g[v]`、`edges()` ([グラフ](graph.hpp) と同じ) | ✓ | ✓ | ✓ |
| `graph()` (`Graph` として取り出す) | ✓ | ✓ | ✓ |
| 親・子・深さ・高さ・部分木サイズ・巡回順 | | ✓ | ✓ |
| `hop`、`lca`、`dist` | | | ✓ |

## `Tree<Cost = long long>` (根なし木)

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Tree(n)` | 頂点数 `n` の空の木 | $O(n)$ |
| `size()` | 頂点数 (`RootedTree`・`DoublingClimbTree` でも使える) | $O(1)$ |
| `add_edge(u, v, w = 1)` | 辺を追加 | $O(1)$ |
| `read(padding = -1, weighted = false)` | 標準入力から `n - 1` 本の辺を読む | $O(n)$ |
| `graph()` | この木を `const Graph<Cost>&` として返す。`shortest_path` や [グラフに関する関数](graph_util.hpp) など、`Graph` を受け取る関数に渡すときに使う (`RootedTree`・`DoublingClimbTree` でも使える) | $O(1)$ |
| `set_root(r)` | 根を `r` にした `RootedTree` を返す | $O(n)$ |
| `build_lca(r)` | 根を `r` にした `DoublingClimbTree` を返す | $O(n \log n)$ |

木でなくなるので、`Graph` の `add_directed_edge` は使えません。

## `RootedTree<Cost = long long>` (根付き木)

`Tree` の `set_root(r)` か、次のコンストラクタで作ります。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RootedTree(tree, r)` | 木 `tree` の根を `r` にする | $O(n)$ |
| `RootedTree(par, padding = -1)` | 頂点 1, ..., n-1 の親のリスト `par` (`std::vector<long long>` か `std::vector<int>`) から、根が 0 の木を作る。頂点番号に `padding` を足す | $O(n)$ |
| `build_lca()` | `DoublingClimbTree` に変換する | $O(n \log n)$ |

| 変数 | 説明 |
|---|---|
| `root` | 根 |
| `par[v]` | 親へ向かう辺 (根では `dst == -1`) |
| `child[v]` | 子へ向かう辺のリスト |
| `depth[v]` / `unweighted_depth[v]` | 根からの距離 (重み付き / 重みなし) |
| `height[v]` / `unweighted_height[v]` | 部分木の高さ (重み付き / 重みなし) |
| `sz[v]` | 部分木の頂点数 |
| `preorder` / `postorder` | 行きがけ順 / 帰りがけ順 |
| `euler_tour` | オイラーツアー。DFS で通った `(頂点, その頂点を通った回数)` の列 |

`root` と、`unweighted_depth`・`unweighted_height`・`sz`・`preorder`・`postorder`・`euler_tour` の要素は `long long` です。

## `DoublingClimbTree<Cost = long long>` (ダブリング済み根付き木)

`Tree` の `build_lca(r)`、`RootedTree` の `build_lca()`、またはコンストラクタ (`RootedTree` から、`Tree` と根から、親のリストから) で作ります。構築は $O(n \log n)$ です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `hop(u, k)` | `u` から `k` 個上の祖先 (存在しなければ `-1`) | $O(\log n)$ |
| `lca(u, v)` | 最小共通祖先 | $O(\log n)$ |
| `dist(u, v)` | 2頂点間の距離 (重み付き) | $O(\log n)$ |

| 変数 | 説明 |
|---|---|
| `h` | ダブリングの段数 |
| `doubling_par[i][v]` | `v` から $2^i$ 個上の祖先 (存在しなければ `-1`) |

頂点番号・段数は `long long` です。

## 関連

- 直径などの [木に関する関数](tree_util.hpp) は `Tree` を受け取ります
- [全方位木DP](rerooting-dp.hpp) は `Tree` を受け取ります
- パスや部分木へのクエリは [HL 分解](heavy-light-decomposition.hpp)
