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
| `ClampMinMax<T>` | 区間 clamp | 区間最小値と最大値の組 `{min, max}` | [`Clamp<T>`](monoid.hpp) | |
| `AffineSum<T>` | 区間アフィン変換 $x \leftarrow ax + b$ | 区間和 | [`Affine<T>`](monoid.hpp) | |
| `UpdateComposite<T>` | 区間代入 | 1次関数の合成 (`monoid::Composite`) | `optional<Affine<T>>` | |
| `AddMinWith<T, U = long long>` | 区間加算 | 区間最小値とその位置 | `T` | |
| `AddMaxWith<T, U = long long>` | 区間加算 | 区間最大値とその位置 | `T` | |
| `AddMinCount<T, U = long long>` | 区間加算 | 区間最小値とその個数 | `T` | |
| `AddMaxCount<T, U = long long>` | 区間加算 | 区間最大値とその個数 | `T` | |
| `AddPowerSum<T, K>` | 区間加算 | 区間の 0 乗和から K 乗和 | `T` | |
| `Rearrange<M, N>` | 区間の成分の並べ替え (写像) | 成分ごとのモノイド `M` の積 | `std::array<int, N>` ([`Mapping<N>`](monoid.hpp)) | |

`MulSum<T>::inv` は `T(1) / f` を返します。`T` が `long long` などの整数型だと整数除算になって正しい逆元にならないので、[imos法](../data_structures/imos.hpp) に渡すときは `T` を modint や浮動小数点数などの体の型にしてください。

`ClampMin`・`ClampMax`・`ClampMinMax` の作用素は、chmin (`{型の最小値, x}`)・chmax (`{x, 型の最大値}`)・代入 (`{x, x}`) をまとめて表せます。clamp は単調非減少なので最小値・最大値にはそのまま作用しますが、区間和には作用しません。区間和が欲しい場合は [Beats 用の作用素付きモノイド](beats-acted-monoid.hpp) の `ChminChmaxAddSum` を使います。

`AddPowerSum` の要素は `S(x)` で値 `x` の1要素から作り、`s[i]` で `i` 乗和を取得します。

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
