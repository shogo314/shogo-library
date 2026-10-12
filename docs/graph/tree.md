---
title: 木の汎用テンプレート
documentation_of: //src/graph/tree.hpp
---

木は 3 段階のクラスで表します。必要な機能に応じて、根なし木から変換して使います。

```cpp
Tree<long long> t(n);
t.read(-1, true);                      // n-1 本の辺を読む (1-indexed、重み付き)
auto path = t.diameter();              // 直径を構成する辺

RootedTree rt = t.set_root(0);         // 根付き木 (親・子・深さ・部分木サイズなど)
DoublingClimbTree dt = t.build_lca(0); // LCA・k 個上の祖先・2頂点間距離
```

## どのクラスで何ができるか

| 機能 | `Tree` | `RootedTree` | `DoublingClimbTree` |
|---|:-:|:-:|:-:|
| 辺の追加 (`add_edge`)・入力 (`read`) | ✓ | | |
| 直径 (`diameter`) | ✓ | | |
| `g[v]`、`edges()`、`shortest_path` ([グラフ](graph.hpp) と同じ) | ✓ | ✓ | ✓ |
| 親・子・深さ・高さ・部分木サイズ・巡回順 | | ✓ | ✓ |
| `climb`、`lca`、`dist` | | | ✓ |

## `Tree<Cost = int>` (根なし木)

| メンバ | 説明 | 計算量 |
|---|---|---|
| `Tree(n)` | 頂点数 `n` の空の木 | $O(n)$ |
| `add_edge(u, v, w = 1)` | 辺を追加 | $O(1)$ |
| `read(padding = -1, weighted = false)` | 標準入力から `n - 1` 本の辺を読む | $O(n)$ |
| `diameter(weighted = true)` | 直径を構成する辺のリスト (端点から順に) | $O(n \log n)$ |
| `set_root(r)` | 根を `r` にした `RootedTree` を返す | $O(n)$ |
| `build_lca(r)` | 根を `r` にした `DoublingClimbTree` を返す | $O(n \log n)$ |

## `RootedTree<Cost = int>` (根付き木)

`Tree` の `set_root(r)` か、コンストラクタ `RootedTree(tree, r)` で作ります。`RootedTree(par, padding = -1)` で、頂点 1, ..., n-1 の親のリストから根が 0 の木を作ることもできます。構築は $O(n)$ です。

| メンバ変数 | 内容 |
|---|---|
| `root` | 根 |
| `par[v]` | 親へ向かう辺 (根では `dst == -1`) |
| `child[v]` | 子へ向かう辺のリスト |
| `depth[v]` / `unweighted_depth[v]` | 根からの距離 (重み付き / 重みなし) |
| `height[v]` / `unweighted_height[v]` | 部分木の高さ (重み付き / 重みなし) |
| `sz[v]` | 部分木の頂点数 |
| `preorder` / `postorder` | 行きがけ順 / 帰りがけ順 |
| `euler_tour` | オイラーツアー。DFS で通った `(頂点, その頂点を通った回数)` の列 |

`build_lca()` で `DoublingClimbTree` に変換できます。

## `DoublingClimbTree<Cost = int>` (ダブリング済み根付き木)

`Tree` の `build_lca(r)`、`RootedTree` の `build_lca()`、またはコンストラクタ (`RootedTree` から、`Tree` と根から、親のリストから) で作ります。構築は $O(n \log n)$ です。

| メンバ | 説明 | 計算量 |
|---|---|---|
| `climb(u, k)` | `u` から `k` 個上の祖先 (存在しなければ `-1`) | $O(\log n)$ |
| `lca(u, v)` | 最小共通祖先 | $O(\log n)$ |
| `dist(u, v)` | 2頂点間の距離 (重み付き) | $O(\log n)$ |
| `doubling_par[i][v]` | `v` から $2^i$ 個上の祖先 (存在しなければ `-1`) | |

## 関連

- [全方位木DP](rerooting-dp.hpp) は `Tree` を受け取ります
