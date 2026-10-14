---
title: 群の定義
documentation_of: //src/algebra/group.hpp
---

[ポテンシャル付きUnionFind](../data_structures/potentialized-unionfind.hpp) や [マージソートツリー](../data_structures/merge-sort-tree.hpp) などに渡す群です。

群は [モノイド](monoid.hpp) のメンバ (`S`、`op`、`e`) に加えて、次のメンバを持つ型として表します。

- `S inv(const S& a)`: 逆元

```cpp
PotentializedUnionFind<group::Sum<long long>> uf(n);  // 差を和の群で管理する
FenwickTree<group::Xor<int>> ft(n);                   // 区間 xor
```

## 一覧 (`namespace group`)

| 群 | 要素の型 `S` | 積 | 単位元 | 逆元 |
|---|---|---|---|---|
| `Sum<T>` | `T` | `a + b` | `0` | `-a` |
| `Prod<T>` | `T` | `a * b` | `1` | `1 / a` (0 を含まない体の元など) |
| `Xor<T>` | `T` | `a ^ b` | `0` | `a` |
| `Permutation<N>` | `std::array<int, N>` | 置換の合成 $f \circ g$ ($g$ を先に適用。[`monoid::Mapping<N>`](monoid.hpp) と同じ) | 恒等置換 | 逆置換 |

いずれも `monoid::Sum<T>` などを継承しているので、モノイドとしても使えます。

## ラムダ式から作る

`Group(op, e, inv)` で、関数オブジェクトと単位元から群を作れます。

```cpp
auto g = Group([](int a, int b) { return a + b; }, 0, [](int a) { return -a; });
PotentializedUnionFind uf(n, g);
```

## 関連

- 逆元を持たない場合は [モノイド](monoid.hpp)
- 群を渡して使うデータ構造は [Fenwick Tree](../data_structures/fenwick-tree.hpp)、[ポテンシャル付きUnionFind](../data_structures/potentialized-unionfind.hpp)、[マージソートツリー](../data_structures/merge-sort-tree.hpp)
