---
title: 双対セグメント木 (区間作用、1点取得)
documentation_of: //src/data_structures/dual-segtree.hpp
---

作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を渡して使う双対セグメント木です。区間作用・1点取得を $O(\log n)$ で行います。

[遅延伝搬セグメント木](lazy-segtree.hpp) と同じ作用素付きモノイドを使えますが、区間積は求めないので、値のモノイドの演算 (`op`、`e`) は使いません。作用素は可換でなくてもよく、区間 chmin や区間代入、アフィン変換も扱えます。

```cpp
DualSegTree<acted_monoid::AffineSum<mint>> seg(v);
seg.apply(l, r, Affine<mint>{b, c});  // [l, r) の各値を b * x + c にする
mint x = seg.get(i);

DualSegTree<acted_monoid::ChminMin<int>> seg2(n, INF);  // 区間 chmin、1点取得
seg2.apply(l, r, 5);
DualSegTree seg3(n, acted_monoid::AddSum<long long>());  // 作用素付きモノイドの値から型を推論する
```

`mapping` が区間の長さを使う作用素付きモノイド (`AddSum` など) では、各要素に長さ 1 の区間として作用します。

## 別名

| 別名 | 実体 | 作用 |
|---|---|---|
| `RAddQ<S>` | `DualSegTree<acted_monoid::AddMin<S>>` | 区間加算 |
| `RUpdateQ<S>` | `DualSegTree<acted_monoid::UpdateMin<S>>` | 区間代入 |
| `RChminQ<S>` | `DualSegTree<acted_monoid::ChminMin<S>>` | 区間 chmin |
| `RChmaxQ<S>` | `DualSegTree<acted_monoid::ChmaxMax<S>>` | 区間 chmax |
| `RAffineQ<S>` | `DualSegTree<acted_monoid::AffineSum<S>>` | 区間アフィン変換 |

`op`、`e` を使わないので、遅延伝搬セグメント木の別名 (`RAddSumQ` など) と違って取得の部分を名前に含めません。

実体には、`mapping` が区間の長さを使わない `Min` 系を選んでいます。`AddSum`、`UpdateSum` の `mapping` は `S(sz)` との掛け算を使うので、`std::string` や `Vector` のような型では使えません。`Min` 系の `op`、`e` (`std::min`、`numeric_limits`) は呼ばれないので、値の型に順序がなくてもかまいません。`RAffineQ` だけは `S(1)` との掛け算を使うので、数の型で使います。

```cpp
RUpdateQ<std::string> seg(n, "");
seg.apply(l, r, "abc");  // [l, r) を "abc" にする
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `DualSegTree<A>(n)` | 要素数 `n`。各要素は `S()` で初期化 | $O(n)$ |
| `DualSegTree<A>(n, x)` | 要素数 `n`。各要素を `x` で初期化 | $O(n)$ |
| `DualSegTree<A>(v)` | `std::vector<S>` から作る | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `apply(l, r, f)` | 区間 $[l, r)$ の各値に `f` を作用 | $O(\log n)$ |
| `apply(k, f)` | `k` 番目の値に `f` を作用 | $O(\log n)$ |
| `get(k)` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目の値を `x` にする | $O(\log n)$ |
| `to_vector()` | すべての値を並べた `std::vector<S>` | $O(n)$ |

## 関連

- 区間積も必要なら [遅延伝搬セグメント木](lazy-segtree.hpp)
- 作用素が逆元を持ち、`get` の添字がおおむね増えていくなら [imos 法](imos.hpp) の方が速い
