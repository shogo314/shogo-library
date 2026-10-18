---
title: Segment Tree Beats 用の作用素付きモノイド
documentation_of: //src/algebra/beats-acted-monoid.hpp
---

[Segment Tree Beats](../data_structures/segtree-beats.hpp) に渡す作用素付きモノイドです。メンバは [作用素付きモノイド](acted-monoid.hpp) と同じですが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返すので、遅延伝搬セグメント木には渡せません。

```cpp
using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
SegTreeBeats<A> seg(std::vector<A::S>(a.begin(), a.end()));  // a は std::vector<long long>
seg.apply(l, r, A::chmin(x));   // [l, r) を min(a[i], x) に
seg.apply(l, r, A::add(x));     // [l, r) に x を足す
A::S s = seg.prod(l, r);
s.sum; s.max1; s.min1;          // [l, r) の和、最大値、最小値
```

## 一覧 (`namespace beats_acted_monoid`)

| 作用素付きモノイド | 作用 | 取得 | 作用素の型 `F` |
|---|---|---|---|
| `ChminSum<T>` | 区間 chmin | 区間和・最大値 | `T` |
| `ChmaxSum<T>` | 区間 chmax | 区間和・最小値 | `T` |
| `ChminChmaxAddSum<T>` | 区間 chmin・chmax・加算・代入 | 区間和・最大値・最小値 | [`ClampAdd<T>`](monoid.hpp) |

## 区間 chmin `ChminSum<T>`・区間 chmax `ChmaxSum<T>`

作用素は chmin (chmax) する値そのものです。`seg.apply(l, r, x)` で $[l, r)$ の各値を $\min(a_i, x)$ ($\max(a_i, x)$) にします。

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。`ChminSum` のメンバ `sum`、`max1` が区間和・最大値です。ほかに 2 番目の最大値 `max2`、最大値の個数 `max_cnt` を持ちます。`ChmaxSum` は同様に `sum`、`min1`、`min2`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

作用が chmin だけ (chmax だけ) なら、`ChminChmaxAddSum` より 3〜4 倍ほど速く動きます。計算量は償却 $O(\log n)$ です。

## 区間 chmin・chmax・加算・代入 `ChminChmaxAddSum<T>`

作用素 `F` は [`ClampAdd<T>`](monoid.hpp) で、`F{lb, ub, add}` は $x \leftarrow \mathrm{clamp}(x + \mathit{add}, \mathit{lb}, \mathit{ub})$ を表します ($\mathit{lb} \le \mathit{ub}$)。次の static 関数で作ります。

| 関数 | 作用 |
|---|---|
| `chmin(b)` | $x \leftarrow \min(x, b)$ |
| `chmax(b)` | $x \leftarrow \max(x, b)$ |
| `add(b)` | $x \leftarrow x + b$ |
| `update(b)` | $x \leftarrow b$ |

要素 `S` は `S(x)` で値 `x` の 1 要素から作ります。メンバ `sum`、`max1`、`min1` が区間和・最大値・最小値です。ほかに 2 番目の最大値 `max2`、2 番目の最小値 `min2`、最大値・最小値の個数 `max_cnt`、`min_cnt` を持ちます。空の区間では `max1` が `numeric_limits<T>::lowest()`、`min1` が `numeric_limits<T>::max()` です。

- `T` は符号付き整数を想定しています。値に足し続けて `numeric_limits<T>` の端に届くとオーバーフローします。
- 計算量は、作用が chmin・chmax だけなら償却 $O(\log n)$、加算もあると償却 $O(\log^2 n)$ です。

## 関連

- これを渡して使うデータ構造は [Segment Tree Beats](../data_structures/segtree-beats.hpp)
- 作用が常に成功する場合は [作用素付きモノイド](acted-monoid.hpp)
