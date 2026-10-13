---
title: 最小費用流 (primal-dual 法)
documentation_of: //src/graph/min-cost-flow.hpp
---

有向グラフの最小費用流を求める `MinCostFlow<Cap, Cost>` です。`Cap` は容量の型、`Cost` はコストの型です。辺のコストは 0 以上とします。

ポテンシャルを使い、残余グラフの最短路を Dijkstra 法で求めては流します。最短路 1 本ごとに $O((n + m) \log m)$ かかり、最短路の本数は流量 $F$ 以下なので、全体で $O(F (n + m) \log m)$ です。

```cpp
MinCostFlow<int, long long> mcf(n);
int id = mcf.add_edge(0, 1, 5, 3);      // 0 から 1 へ容量 5、コスト 3 の辺。辺の番号を返す
auto [f, c] = mcf.flow(s, t, limit);   // limit を上限として流量が最大になるまで流す。f は流量、c は最小コスト
auto e = mcf.get_edge(id);              // e.from, e.to, e.cap, e.flow, e.cost
```

## メンバ

| メンバ | 説明 |
|---|---|
| `MinCostFlow(n)` | 頂点数 `n`、辺のない状態 |
| `size()` | 頂点数 |
| `add_edge(from, to, cap, cost)` | `from` から `to` へ容量 `cap`、1 あたりのコスト `cost` (0 以上) の辺を追加し、辺の番号 (追加した順に 0, 1, ...) を返す |
| `flow(s, t)` / `flow(s, t, limit)` | `s` から `t` へ、流量が最大になるまで (`limit` があればそれを上限として) 流し、(流量, そのときの最小コスト) を返す |
| `slope(s, t)` / `slope(s, t, limit)` | `flow` と同じように流し、流量とコストの関係を表す折れ線の頂点 (流量, コスト) を並べたものを返す |
| `get_edge(i)` | 番号 `i` の辺の `from`、`to`、`cap` (容量)、`flow` (流れている量)、`cost` |
| `edges()` | すべての辺の情報 (追加した順) |

- `slope` の返す折れ線は (0, 0) から始まり、傾きが変わる点だけを並べます。流量 $x$ を流すときの最小コストは、折れ線の $x$ での値です。傾き (1 あたりのコスト) は単調に増えます。
- `flow` と `slope` は何度も呼べます。前回までの流れに追加して流し、返す値はその呼び出しの中で流した量とコストです。`s` と `t` が前回と違ってもかまいません。
- `flow` や `slope` を呼んだ後に `add_edge` はできません。

## 例

流量をちょうど $F$ にしたいときは、`limit` を $F$ にして、流量が $F$ になったかを確かめます。

```cpp
auto [f, c] = mcf.flow(s, t, F);
if (f < F) {
    // F だけ流すことはできない
}
```

流量を自由に選んでコストを最小にしたいとき (コストが負の辺を含む問題を変形した場合など) は、`slope` の頂点のうちコストが最小のものを選びます。

## 関連

- コストのない最大流は [最大流](max-flow.hpp)
