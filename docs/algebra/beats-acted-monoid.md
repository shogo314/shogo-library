---
title: Segment Tree Beats 用の作用素付きモノイド
documentation_of: //src/algebra/beats-acted-monoid.hpp
---

[Segment Tree Beats](../data_structures/segtree-beats.hpp) に渡す作用素付きモノイドです。メンバは [作用素付きモノイド](acted-monoid.hpp) と同じですが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返すので、遅延伝搬セグメント木には渡せません。

```cpp
using A = beats_acted_monoid::ChminChmaxAddSum<long long>;
SegTreeBeats<A> seg(a);  // a は std::vector<long long>
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
| `ChminChmaxAddPowerSum<T, K, U>` | 区間 chmin・chmax・加算・代入 | 区間の 0 乗和から K 乗和・最大値・最小値 | [`ClampAdd<T>`](monoid.hpp) |
| `BitwiseAndOrMinMax<T>` | 区間 bitwise AND・OR | 区間最小値・最大値・bitwise AND・OR | `F{and_mask, or_mask}` |
| `DivUpdateSum<T, U>` | 区間整数除算・代入 | 区間和・最小値・最大値 | `F` |
| `GcdUpdateSum<T, U>` | 区間 gcd・代入 | 区間和・最小値・最大値 | `F` |

追加の 4 種類は `T = long long` が既定です。乗和の最大次数は `K = 2`、集計の型は `U = T` が既定です。

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

## 区間 chmin・chmax・加算・代入と k 乗和

```cpp
using A = beats_acted_monoid::ChminChmaxAddPowerSum<long long, 2, modint998244353>;
SegTreeBeats<A> seg(a);  // a は std::vector<long long>
seg.apply(l, r, A::chmin(10));
seg.apply(l, r, A::add(3));
auto s = seg.prod(l, r);
auto count = s[0];  // 要素数を U で表した値
auto sum = s[1];
auto square_sum = s[2];
```

`S(x)` で 1 要素を作り、`s[j]` で $\sum a_i^j$ を取得します。`min1`・`max1` は元の値の型 `T`、乗和は `U` です。値を比較するため、`T` には符号付き整数を使います。`U` は `T` から構築でき、加減乗算ができる型で、modint や `__int128_t` も使えます。`K = 0` も許します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `chmin(b)` / `chmax(b)` / `add(b)` / `update(b)` | `ChminChmaxAddSum` と同じ作用素を作る | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(K+1)$ |
| `s[j]` | `j` 乗和を取得 (`0 <= j <= K`) | $O(1)$ |
| `op(a, b)` | 2 区間を結合 | $O(K+1)$ |
| `mapping(f, s, sz)` | 成功時に乗和と極値を更新、適用できなければ失敗を返す | 加算なし $O(K+1)$、加算あり $O((K+1)^2)$ |

セグ木のクエリは $O((K+1)\log n)$。更新は、chmin・chmax だけなら償却 $O((K+1)\log n)$、加算も含む場合は償却 $O((K+1)^2\log^2 n)$ です。セグ木の領域は $O(n(K+1))$、二項係数表に追加で $O((K+1)^2)$ を使います。

値と加算途中の値は `T` の最小値・最大値に達しない範囲で使ってください。`U` に整数型を使う場合、乗和とその計算途中の値も収まる必要があります。

## 区間 bitwise AND・OR

```cpp
using A = beats_acted_monoid::BitwiseAndOrMinMax<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::bit_and(7));
seg.apply(l, r, A::bit_or(8));
auto s = seg.prod(l, r);
// s.min, s.max, s.bit_and, s.bit_or, s.size
```

`T` は bool 以外の整数型で、値・マスクは非負です。符号なし整数では最上位ビットも扱えます。`F{and_mask, or_mask}` は $(x\mathbin{\&}\mathrm{and\_mask})\mathbin{|}\mathrm{or\_mask}$ を表します。変更するビットが区間内で共通なら、極値の大小関係を保ってノード全体に作用できます。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `bit_and(b)` | $x\leftarrow x\mathbin{\&}b$ の作用素 | $O(1)$ |
| `bit_or(b)` | $x\leftarrow x\mathbin{|}b$ の作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | $O(1)$ |

有効ビット数を $B$ とすると、セグ木の更新は償却 $O(B\log n)$、クエリは $O(\log n)$、領域は $O(n)$ です。空区間の `min`・`bit_and` は型の最大値、`max`・`bit_or` は 0 です。

## 区間整数除算・代入

```cpp
using A = beats_acted_monoid::DivUpdateSum<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::div(3));     // a[i] <- floor(a[i] / 3)
seg.apply(l, r, A::update(5));
auto s = seg.prod(l, r);       // s.sum, s.min, s.max, s.size
```

`T` は bool 以外の整数型で、値は非負、除数は 1 以上です。区間の最小値と最大値の商が同じなら区間全体を一様な値にし、異なる場合は子に降ります。除数の合成で積が型の最大値を超える場合は 0 の代入にします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `div(d)` | $x\leftarrow\lfloor x/d\rfloor$ の作用素 (`d >= 1`) | $O(1)$ |
| `update(b)` | 非負値 `b` を代入する作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | $O(1)$ |

集計の型 `U` は `T` から構築でき、加算・乗算ができる型です。`sum` と計算途中の値は `U` に収まる必要があります。modint も使えます。空区間では `sum = 0`、`min` は型の最大値、`max = 0`、`size = 0` です。

値の上限を $V$、更新・問い合わせの合計を $q$ とすると、構築を含めて $O((n+q)\log(n+1)\log(V+2))$ 時間、$O(n)$ 領域です。単発の更新は $O(n)$ かかることがあります。クエリは $O(\log n)$ です。

## 区間 gcd・代入

```cpp
using A = beats_acted_monoid::GcdUpdateSum<>;
SegTreeBeats<A> seg(a);
seg.apply(l, r, A::gcd(12));    // a[i] <- gcd(a[i], 12)
seg.apply(l, r, A::update(5));
auto s = seg.prod(l, r);       // s.sum, s.min, s.max, s.size
```

`T` は bool 以外の整数型で、値・gcd の引数は非負です。`gcd(0)` は恒等作用です。集計の型 `U`、空区間の値、計算途中の値に関する条件は `DivUpdateSum` と同じです。

区間が一様なら直接 gcd を計算し、全要素が引数の約数なら変更せずに終了します。それ以外は子に降ります。約数かどうかの判定には LCM を保持し、型に収まらない場合は `lcm_overflow` を立てます。オーバーフロー時の `lcm` は参照しないでください。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `gcd(b)` | $x\leftarrow\gcd(x,b)$ の作用素 | $O(1)$ |
| `update(b)` | 非負値 `b` を代入する作用素 | $O(1)$ |
| `S(x)` | 1 要素を構築 | $O(1)$ |
| `op(a, b)` / `mapping(f, s)` / `composition(f, g)` | 結合・作用・合成 | gcd 計算 $O(1)$ 回 |

整数の gcd を定数時間と数えると、値の上限 $V$、更新・問い合わせの合計 $q$ に対し、構築を含めて $O((n+q)\log(n+1)\log(V+2))$ 時間、$O(n)$ 領域です。単発の更新は $O(n)$ かかることがあります。クエリは gcd 計算 $O(\log n)$ 回です。

## 関連

- これを渡して使うデータ構造は [Segment Tree Beats](../data_structures/segtree-beats.hpp)
- 作用が常に成功する場合は [作用素付きモノイド](acted-monoid.hpp)
