---
title: 文字列盤面のグリッドグラフ
documentation_of: //src/graph/grid-graph.hpp
---

文字列盤面の壁以外のマスを頂点とする、4近傍・重み1の無向グラフです。元の盤面と座標対応を保持し、既存のグラフアルゴリズムをそのまま使えます。

```cpp
std::vector<std::string> board = {"S..#.", ".#...", "...G."};
GridGraph maze(board);  // 既定の壁文字は '#'
long long start = maze.find('S'), goal = maze.find('G');
assert(start != -1 && goal != -1);
auto result = shortest_path_bfs(maze.graph(), start);
long long distance = result.dist[goal];  // 5

for (long long v : maze[start]) {
    auto [i, j] = maze.cell(v);
    char c = maze.label(v);
}

for (long long v : maze.find_all('a')) {
    // ワープ文字など、同じ文字の頂点を行優先で列挙する
}
GridGraph other(board, 'X');  // 壁文字を変える。'#' も通行可能になる
```

盤面は内部に所有します。各行の長さが等しいことが前提で、空の盤面や幅0の盤面も使えます。空の盤面の高さ・幅はどちらも0です。壁文字は1種類で、指定した文字以外はすべて通行可能です。

頂点番号は通行可能なマスに行優先で `0, 1, ...` と付けます。壁のマスには頂点を作らず、`index(i, j)` は−1を返します。`index` に範囲外の座標を渡すことや、`cell`・`label`・`operator[]` に不正な頂点番号を渡すことは前提違反です。

`board()` と `graph()` は読み取り専用の参照を返します。最短路・連結成分分解などには `maze.graph()` を渡してください。最短路の頂点列も頂点番号なので、必要なら `cell(v)` で座標へ変換します。

`find`・`find_all` は通行可能なマスだけを検索し、見つからないときはそれぞれ−1・空のrangeを返します。`find_all` は値を返すiteratorを持つ遅延rangeで、途中で `break` すると残りを検索しません。C++20以降では `forward_range` として使えます。走査中は元の `GridGraph` を有効なまま保持し、変更しないでください。

以下で $H$・$W$ は盤面の高さ・幅、$V$ は通行可能なマス数です。構築の時間・領域は $O(HW)$ で、グラフの辺数は $O(V)$ です。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `GridGraph(board, wall = '#')` | 盤面を所有し、4近傍・重み1の無向グラフを構築する | $O(HW)$ |
| `graph()` | 内部の `Graph<long long>` の読み取り専用参照 | $O(1)$ |
| `size()` | 通行可能なマス数＝頂点数 | $O(1)$ |
| `height()` / `width()` | 元の盤面の高さ・幅 | $O(1)$ |
| `maze[v]` | 頂点 `v` の隣接辺の読み取り専用参照。形式は `Graph` と同じ | $O(1)$ |
| `board()` | 元の `std::vector<std::string>` の読み取り専用参照 | $O(1)$ |
| `index(i, j)` | 座標に対応する頂点番号。壁なら−1 | $O(1)$ |
| `cell(v)` | 頂点番号に対応する座標 `(i, j)` | $O(1)$ |
| `label(v)` | 頂点に対応する文字 | $O(1)$ |
| `find(c)` | 文字 `c` の最初の頂点番号。なければ−1 | $O(V)$ |
| `find_all(c)` | 文字 `c` の頂点番号を行優先で遅延列挙する | 構築 $O(1)$、全走査 $O(V)$、追加領域 $O(1)$ |

## 関連

- 座標・添字変換と幾何的な近傍は [Range・Grid](../utility/range.hpp)
- グラフの表現は [Graph](graph.hpp)
- BFSなどの最短路は [最短路](shortest-path.hpp)
