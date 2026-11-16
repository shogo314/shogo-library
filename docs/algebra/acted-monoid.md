---
title: 作用素付きモノイドの定義
documentation_of: //src/algebra/acted-monoid.hpp
---

[遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp) などに渡す作用素付きモノイドです。

作用素付きモノイドは、[モノイド](monoid.hpp) のメンバに加えて次のメンバを持つ型として表します。

- `using F`: 作用素の型
- `S mapping(const F& f, const S& x)`: 作用素の適用 $f(x)$。区間の情報が必要な場合は `mapping(f, x, sz)` (`sz` は区間の長さ) や `mapping(f, x, l, r)` (区間 $[l, r)$) でもよい。`sz`、`l`、`r` は `long long` で渡す (動的セグメント木では `int` に収まらないことがある。`int` で受け取る `mapping` もそのまま使える)
- `F composition(const F& f, const F& g)`: 作用素の合成 $f \circ g$ ($g$ を適用した後に $f$ を適用する)
- `F id()`: 恒等写像
- `F inv(const F& f)`: 逆作用素 ([imos法](../data_structures/imos.hpp) で使う場合のみ)

```cpp
LazySegTree<acted_monoid::AddMin<long long>> seg(v);  // 区間加算・区間最小値
seg.apply(l, r, x);                                   // [l, r) に x を足す
long long m = seg.prod(l, r);                         // [l, r) の最小値
```

## 一覧 (`namespace acted_monoid`)

| 作用素付きモノイド | 作用 | 取得 | 作用素の型 `F` | `inv` |
|---|---|---|---|---|
| `AddSum<T>` | 区間加算 | 区間和 | `T` | ✓ |
| `LinearAddSum<T = long long>` | 区間等差数列加算 | 区間和 | `F{constant, slope}` | ✓ |
| `MulSum<T>` | 区間乗算 | 区間和 | `T` | ✓ |
| `AddMin<T>` | 区間加算 | 区間最小値 | `T` | |
| `AddMax<T>` | 区間加算 | 区間最大値 | `T` | |
| `UpdateSum<T>` | 区間代入 | 区間和 | `optional<T>` | |
| `UpdateMin<T>` | 区間代入 | 区間最小値 | `optional<T>` | |
| `UpdateMax<T>` | 区間代入 | 区間最大値 | `optional<T>` | |
| `ChminMin<T>` | 区間 chmin | 区間最小値 | `T` | |
| `ChmaxMax<T>` | 区間 chmax | 区間最大値 | `T` | |
| `ClampMin<T>` | 区間 clamp $x \leftarrow \min(\max(x, \mathit{lb}), \mathit{ub})$ | 区間最小値 | [`Clamp<T>`](monoid.hpp) | |
| `ClampMax<T>` | 区間 clamp | 区間最大値 | [`Clamp<T>`](monoid.hpp) | |
| `ClampMinMax<T>` | 区間 clamp | 区間最小値 `min`・最大値 `max` (`MinMax<T>::S`) | [`Clamp<T>`](monoid.hpp) | |
| `ClampAddMin<T>` | 区間 加算と clamp $x \leftarrow \min(\max(x + \mathit{add}, \mathit{lb}), \mathit{ub})$ | 区間最小値 | [`ClampAdd<T>`](monoid.hpp) | |
| `ClampAddMax<T>` | 区間 加算と clamp | 区間最大値 | [`ClampAdd<T>`](monoid.hpp) | |
| `ClampAddMinMax<T>` | 区間 加算と clamp | 区間最小値 `min`・最大値 `max` (`MinMax<T>::S`) | [`ClampAdd<T>`](monoid.hpp) | |
| `AffineSum<T>` | 区間アフィン変換 $x \leftarrow ax + b$ | 区間和 | [`Affine<T>`](monoid.hpp) | |
| `AffineMinMax<T = long long>` | 区間アフィン変換 | 区間最小値 `min`・最大値 `max` | `Affine<T>` | |
| `AffinePowerSum<T = long long, K = 2>` | 区間アフィン変換 | 区間の 0 乗和から K 乗和 | `Affine<T>` | |
| `AddGcd<T = long long>` | 区間加算 | 区間 gcd (`s.val()`) | `T` | ✓ |
| `AddProductSum<T = long long>` | 2 列それぞれへの区間加算 | 各列の和と要素ごとの積の和 | `std::array<T, 2>` | ✓ |
| `PolynomialAddSum<T = long long, K = 2>` | 区間多項式加算 | 区間和 | `std::array<T, K + 1>` | ✓ |
| `UpdateComposite<T>` | 区間代入 | 1次関数の合成 (`monoid::Composite`) | `optional<Affine<T>>` | |
| `AddMinWith<T, U = long long>` | 区間加算 | 区間最小値とその位置 (空区間では `{型の最大値, -1}`) | `T` | |
| `AddMaxWith<T, U = long long>` | 区間加算 | 区間最大値とその位置 (空区間では `{型の最小値, -1}`) | `T` | |
| `AddMinCount<T, U = long long>` | 区間加算 | 区間最小値とその個数 | `T` | |
| `AddMaxCount<T, U = long long>` | 区間加算 | 区間最大値とその個数 | `T` | |
| `AddPowerSum<T, K>` | 区間加算 | 区間の 0 乗和から K 乗和 | `T` | |
| `Rearrange<M, N>` | 区間の成分の並べ替え (写像) | 成分ごとのモノイド `M` の積 | `std::array<int, N>` ([`Mapping<N>`](monoid.hpp)) | |

`MulSum<T>::inv` は `T(1) / f` を返します。`T` が `long long` などの整数型だと整数除算になって正しい逆元にならないので、[imos法](../data_structures/imos.hpp) に渡すときは `T` を modint や浮動小数点数などの体の型にしてください。

`ClampMin`・`ClampMax`・`ClampMinMax` の作用素は、chmin (`{ {}, x}`)・chmax (`{x, {}}`)・代入 (`{x, x}`) をまとめて表せます。`ClampAddMin`・`ClampAddMax`・`ClampAddMinMax` の作用素は、さらに加算もまとめて表せます (書き方は [`ClampAdd<T>`](monoid.hpp))。どちらも単調非減少なので最小値・最大値にはそのまま作用しますが、区間和には作用しません。区間和が欲しい場合は [Beats 用の作用素付きモノイド](beats-acted-monoid.hpp) の `ChminChmaxAddSum` を使います。

```cpp
LazySegTree<acted_monoid::ClampAddMin<long long>> seg(v);
seg.apply(l, r, { {}, {}, x});  // [l, r) に x を足す
seg.apply(l, r, { {}, x});      // chmin
seg.apply(l, r, {x, {}});       // chmax
seg.apply(l, r, {x, x});        // 代入
```

`AddPowerSum` の要素は `S(x)` で値 `x` の1要素から作り、`s[i]` で `i` 乗和を取得します。

## 区間等差数列加算 `LinearAddSum<T>`

位置 `i` の値に `constant + slope * i` を加えます。`arithmetic_progression(l, first, step)` を使うと、区間の左端 `l` に初項 `first`、公差 `step` の等差数列を加算する作用素を作れます。

```cpp
using A = acted_monoid::LinearAddSum<>;
LazySegTree<A> seg(std::vector<long long>(6, 0));
seg.apply(2, 5, A::arithmetic_progression(2, 3, 4));
// a = {0, 0, 3, 7, 11, 0}
long long sum = seg.prod(2, 5);  // 21
seg.apply(0, 6, {2, 3});        // 各位置 i に 2 + 3*i を加算
```

作用素は絶対位置を基準にするため、`arithmetic_progression` の `l` は加算する区間の左端と合わせてください。`mapping` は `l, r` を受け取ります。添字と長さは非負の `long long` です。

`T` は `long long` から構築でき、加減乗算ができる型です。整数型・modint などを使えます。添字の和は $l n + n(n-1)/2$ ($n=r-l$) として、整数の因子の片方を先に 2 で割り、積を `T` で計算します。2 の逆元を使わないので、法が偶数の modint にも対応します。結果と計算途中の値は `T` に収まる必要があります。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `arithmetic_progression(l, first, step)` | 位置 `l` で初項 `first`、公差 `step` の加算作用素 | $O(1)$ |
| `mapping(f, x, l, r)` | 区間和 `x` に位置ごとの加算を反映 | $O(1)$ |
| `composition(f, g)` | `g` の後に `f` を作用させる合成 | $O(1)$ |
| `id()` | 加算しない作用素 | $O(1)$ |
| `inv(f)` | 加算を取り消す作用素 | $O(1)$ |

遅延セグメント木での区間加算・区間和は $O(\log n)$ です。絶対位置を使うため、要素の挿入・削除・反転で位置が変わる RBST などにはそのまま渡せません。

## アフィン変換と最小値・最大値 `AffineMinMax<T>`

```cpp
using A = acted_monoid::AffineMinMax<>;
LazySegTree<A> seg(std::vector<long long>{2, -3, 5});
seg.apply(0, 3, {-2, 1});  // 各値 x を -2*x + 1 にする
auto s = seg.prod(0, 3);   // s.min = -9, s.max = 7
```

要素は `monoid::MinMax<T>::S` です。`S(x)` で 1 要素、`S()` で空区間を作ります。負の倍率では最小値と最大値を入れ替えます。0 倍による代入も使えます。`T` は大小比較と四則のうち加算・乗算ができる型を使い、値と作用素の合成途中の値が収まる必要があります。modint は使えません。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `mapping(f, s)` | 区間の極値にアフィン変換を反映。空区間はそのまま | $O(1)$ |
| `composition(f, g)` | $f\circ g$ を返す | $O(1)$ |
| `id()` | 恒等変換 `{1, 0}` | $O(1)$ |

遅延セグメント木での更新・取得は $O(\log n)$ です。

## アフィン変換と k 乗和 `AffinePowerSum<T, K>`

```cpp
using A = acted_monoid::AffinePowerSum<modint998244353, 2>;
LazySegTree<A> seg(std::vector<modint998244353>{1, 2, 3});
seg.apply(0, 3, {2, 1});   // {3, 5, 7}
auto s = seg.prod(0, 3);   // s[0] = 3, s[1] = 15, s[2] = 83
```

`S` は `AddPowerSum<T, K>::S` と同じです。`S(x)` で 1 要素を作り、`s[j]` で $\sum a_i^j$ を取得します。`K = 0` も使えます。二項展開を使い、除算はしないので法が偶数の modint でも使えます。整数型では乗和、二項係数、累乗、作用素の合成を含む中間計算が収まる必要があります。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `op(a, b)` | 各次数の和を結合 | $O(K+1)$ |
| `mapping(f, s)` | アフィン変換後の各乗和を計算 | $O((K+1)^2)$ |
| `composition(f, g)` | $f\circ g$ を返す | $O(1)$ |
| `id()` | 恒等変換 `{1, 0}` | $O(1)$ |

遅延セグメント木の更新は $O((K+1)^2\log n)$、取得は $O((K+1)\log n)$、領域は $O(n(K+1))$ です。

## 区間加算と gcd `AddGcd<T>`

```cpp
using A = acted_monoid::AddGcd<>;
LazySegTree<A> seg(std::vector<long long>{6, 10, 14});
seg.apply(0, 3, 2);
long long g = seg.prod(0, 3).val();  // gcd(8, 12, 16) = 4
```

`S(x)` で 1 要素を作ります。`S` は `first`・`last` (区間の両端の値)、`differences_gcd` (隣接差の gcd)、`size` を持ちます。加算では隣接差が変わりません。区間の gcd は `s.val()` で返し、空区間なら 0 です。値は負でも構いません。

`T` は符号付き整数型を使います。値・隣接差・作用素の合成の計算が `T` に収まり、値と差の絶対値も `T` に収まる範囲で使ってください。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `op(a, b)` | 連続する 2 区間を結合 | gcd 計算 $O(1)$ 回 |
| `s.val()` | 区間の gcd | gcd 計算 $O(1)$ 回 |
| `mapping(f, s)` | 両端に `f` を足す | $O(1)$ |
| `composition(f, g)` / `id()` / `inv(f)` | 加算の合成・0・符号反転 | $O(1)$ |

更新・取得には gcd 計算を $O(\log n)$ 回使います。

## 2 列への加算と積の和 `AddProductSum<T>`

```cpp
using A = acted_monoid::AddProductSum<modint998244353>;
std::vector<A::S> values = { {1, 4}, {2, 5}, {3, 6} };
LazySegTree<A> seg(values);
seg.apply(0, 3, {2, 0});  // A 列だけに 2 を足す
seg.apply(1, 3, {0, 3});  // B 列だけに 3 を足す
auto s = seg.prod(0, 3);  // s.sum_a, s.sum_b, s.product_sum
```

`S(a, b)` または `S(std::array<T, 2>{a, b})` で 1 要素を作ります。取得結果の `sum_a` は $\sum a_i$、`sum_b` は $\sum b_i$、`product_sum` は $\sum a_i b_i$ です。空区間ではすべて 0 です。作用素 `{x, y}` は A 列に `x`、B 列に `y` を加えます。

`T` は整数型・modint など、加減乗算ができる型です。整数型では積や和の中間計算も収まる必要があります。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `op(a, b)` | 各列の和と積の和を結合 | $O(1)$ |
| `mapping(f, s, sz)` | 2 列の加算を反映 | $O(1)$ |
| `composition(f, g)` / `id()` / `inv(f)` | 成分ごとの加算・0・符号反転 | $O(1)$ |

遅延セグメント木での更新・取得は $O(\log n)$ です。[ABC357 F](https://atcoder.jp/contests/abc357/tasks/abc357_f) に対応します。

## 多項式加算と和 `PolynomialAddSum<T, K>`

```cpp
using A = acted_monoid::PolynomialAddSum<modint998244353, 2>;
LazySegTree<A> seg(std::vector<modint998244353>(5, 0));
seg.apply(1, 4, {2, 3, 1});  // 位置 i に 2 + 3*i + i*i を足す
auto sum = seg.prod(1, 4);    // 6 + 12 + 20 = 38
```

作用素は定数項から並べた係数 `std::array<T, K + 1>` です。位置は区間の左端からの相対位置ではなく、配列の絶対位置です。`K = 0` も使えます。`T` は `long long` から構築でき、加減乗算と 0 との等値比較ができる型です。

添字の累乗和を、第二種 Stirling 数と二項係数から計算します。二項係数は分子の整数因子を gcd で約分し、積は `T` で計算するため、添字が大きくても整数の大きな積を作りません。`T` での除算・逆元を使わず、法が偶数の modint にも対応します。整数型では区間外も含む prefix の乗和、階乗などの中間計算も `T` に収まる必要があります。

### 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `mapping(f, s, l, r)` | 多項式の区間和を `s` に加算 | $O((K+1)^2)$ 演算・gcd 計算 |
| `composition(f, g)` / `id()` / `inv(f)` | 係数ごとの加算・0・符号反転 | $O(K+1)$ |

gcd 計算を定数時間と数えると、遅延セグメント木の更新・取得は $O((K+1)^2\log n)$、領域は $O(n(K+1))$ です。次数 1 以下では、より軽い `LinearAddSum`・`AddSum` も使えます。位置を使うため、RBST の挿入・削除・反転と組み合わせてそのまま使うことはできません。

## 成分の並べ替え `Rearrange<M, N>`

モノイド `M` の要素を `N` 個並べた `std::array<M::S, N>` を要素とし、積は成分ごとに `M::op` をとります。作用素 `f` は [`monoid::Mapping<N>`](monoid.hpp) の要素で、`mapping(f, x)[i] = x[f[i]]`、つまり成分 `i` に `x` の成分 `f[i]` を持ってきます。積が成分ごとなので、`M` が何でも遅延伝搬セグメント木に乗ります。`M` は `monoid::Sum` などのように `op`、`e` を static に持つ必要があります。

- `f` は全単射でなくてもかまいません。例えば `N = 3` で `f = {1, 1, 2}` は、成分 0 を成分 1 の値で上書きします。
- `swap(i, j)` で成分 `i` と `j` を入れ替える作用素を作れます。
- `composition(f, g)` は他の作用素付きモノイドと同じく「`g` を適用した後に `f` を適用する」作用素で、`Mapping` の積としては $g \circ f$ になります。

```cpp
// 区間の 0 と 1 を反転し、区間の 1 の個数を求める
using A = acted_monoid::Rearrange<monoid::Sum<long long>, 2>;
LazySegTree<A> seg(std::vector<A::S>(n, {1, 0}));  // {0 の個数, 1 の個数}
seg.apply(l, r, A::swap(0, 1));                    // [l, r) を反転
long long c = seg.prod(l, r)[1];                   // [l, r) の 1 の個数
```

## ラムダ式から作る

`ActedMonoid(op, e, mapping, composition, id)` で、関数オブジェクトから作用素付きモノイドを作れます。`mapping` の引数は `(f, x)`、`(f, x, sz)`、`(f, x, l, r)` のいずれでもかまいません。

## 関連

- 作用素を持たないものは [モノイド](monoid.hpp)
- 作用素付きモノイドを渡して使うデータ構造は [遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp)、[双対セグメント木](../data_structures/dual-segtree.hpp)、[imos法](../data_structures/imos.hpp)、[Segment Tree Beats](../data_structures/segtree-beats.hpp)
- Segment Tree Beats に渡すもの (`mapping` が失敗を返せる) は [Beats 用の作用素付きモノイド](beats-acted-monoid.hpp)
