---
title: 最大流 (Dinic 法)
documentation_of: //src/graph/max-flow.hpp
---

有向グラフの最大流を Dinic 法で求める `MaxFlow<Cap>` です。`Cap` は容量の型です。計算量は $O(n^2 m)$ ですが、実際にはずっと速いことが多いです。容量がすべて 1 なら $O(m \min(\sqrt{m}, n^{2/3}))$ です。

```cpp
MaxFlow<long long> mf(n);
int id = mf.add_edge(0, 1, 5);      // 0 から 1 へ容量 5 の辺。辺の番号を返す
long long f = mf.flow(s, t);        // s から t へ流せるだけ流す
auto e = mf.get_edge(id);           // e.from, e.to, e.cap, e.flow
std::vector<bool> S = mf.min_cut(s);  // 最小カットの s 側
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `MaxFlow(n)` | 頂点数 `n`、辺のない状態 | $O(n)$ |
| `size()` | 頂点数 | $O(1)$ |
| `add_edge(from, to, cap)` | `from` から `to` へ容量 `cap` の辺を追加し、辺の番号 (追加した順に 0, 1, ...) を返す | ならし $O(1)$ |
| `flow(s, t)` | `s` から `t` へできるだけ流し、流した量を返す | $O(n^2 m)$ |
| `flow(s, t, limit)` | 流す量の上限を `limit` にする | $O(n^2 m)$ |
| `get_edge(i)` | 番号 `i` の辺の `from`、`to`、`cap` (容量)、`flow` (流れている量) | $O(1)$ |
| `edges()` | すべての辺の情報 (追加した順) | $O(m)$ |
| `change_edge(i, new_cap, new_flow)` | 番号 `i` の辺の容量を `new_cap`、流れている量を `new_flow` に変える ($0 \le$ `new_flow` $\le$ `new_cap`)。ほかの辺の流量は変えないので、流量の保存則が崩れることがある | $O(1)$ |
| `min_cut(s)` | 残余グラフで `s` から行ける頂点か。`flow(s, t)` で流しきった後なら、`true` の頂点の集合が最小カットの `s` 側になる | $O(n + m)$ |

`flow` を何度も呼ぶと、前回までの流れに追加して流します。辺を追加してから、もう一度 `flow` を呼ぶこともできます。

流す処理の DFS は再帰を使います。再帰の深さは、`s` から `t` への (容量が残っている辺だけを使った) 最短路の辺の本数までです。

## 関連

- 二部グラフの最大マッチングだけなら、より速い [二部マッチング](bipartite-matching.hpp)
- 辺にコストがあるときは [最小費用流](min-cost-flow.hpp)
