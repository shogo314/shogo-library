---
title: モノイドの定義
documentation_of: //src/algebra/monoid.hpp
---

[セグメント木](../data_structures/segtree.hpp) などに渡すモノイドです。

モノイドは次のメンバを持つ型として表します。`op`、`e` は static でも非 static でもかまいません。

- `using S`: 要素の型
- `S op(const S& a, const S& b)`: 積 (結合的)
- `S e()`: 単位元

```cpp
SegTree<monoid::Max<int>> seg(n);                                // 区間最大値
SegTree seg2(v, Monoid([](int a, int b) { return a + b; }, 0));  // ラムダ式から作る
```

## 一覧 (`namespace monoid`)

| モノイド | 要素の型 `S` | 積 | 単位元 |
|---|---|---|---|
| `Sum<T>` | `T` | `a + b` | `0` |
| `Prod<T>` | `T` | `a * b` | `1` |
| `Max<T>` | `T` | `max(a, b)` | 型の最小値 |
| `Min<T>` | `T` | `min(a, b)` | 型の最大値 |
| `MinMax<T>` | `pair<T, T>` | `{min, max}` の組 | `{最大値, 最小値}` |
| `Xor<T>` | `T` | `a ^ b` | `0` |
| `And<T>` | `T` | `a & b` | 全ビット 1 |
| `Or<T>` | `T` | `a | b` | `0` |
| `Gcd<T>` | `T` | `gcd(a, b)` | `0` |
| `Lcm<T>` | `T` | `lcm(a, b)` | `1` |
| `Composite<T>` | `Affine<T>` | 1次関数 $f(x) = ax + b$ の合成 $f \circ g$ ($g$ を先に適用) | 恒等写像 |
| `Mapping<N>` | `std::array<int, N>` | $\lbrace 0, \dots, N-1 \rbrace$ から自分自身への写像の合成 $f \circ g$ ($g$ を先に適用)。全単射でなくてよい | 恒等写像 |
| `Parenthesis` | `Parenthesis::S` | 括弧列の連結 (対応の取れていない `)` と `(` の個数) | 空の括弧列 |
| `MinWith<T, U = int>` | `pair<T, U>` | 最小値とその位置 (同じ値なら左側) | `{型の最大値, U{}}` |
| `MaxWith<T, U = int>` | `pair<T, U>` | 最大値とその位置 (同じ値なら左側) | `{型の最小値, U{}}` |
| `MinCount<T, U = long long>` | `pair<T, U>` | 最小値とその個数 | `{型の最大値, 0}` |
| `MaxCount<T, U = long long>` | `pair<T, U>` | 最大値とその個数 | `{型の最小値, 0}` |
| `Reverse<M>` | `M::S` | `M::op(b, a)` (積の順序を逆にする) | `M::e()` |

`Parenthesis::S` は文字 `'('`、`')'` から作れます。`is_valid()` で正しい括弧列かどうかを判定できます。

## 1次関数 `Affine<T>`

`Composite` の要素や、[作用素付きモノイド](acted-monoid.hpp) の `AffineSum` の作用素に使う、1次関数 $f(x) = ax + b$ の型です。

```cpp
Affine<mint> f{2, 3};   // f(x) = 2x + 3 (省略すると恒等写像 {1, 0})
mint y = f(x);          // 2x + 3
std::cin >> f;          // "a b" を読む
std::cout << f;         // "a b" を出力
```

### メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `f(x)` | $ax + b$ | $O(1)$ |
| `==`、`!=` | 比較 | $O(1)$ |
| `is >> f`、`os << f` | `a` と `b` を空白区切りで入出力 | $O(1)$ |

### メンバ変数

| 変数 | 説明 |
|---|---|
| `a` / `b` | 傾き / 切片 |

## 写像のモノイド `Mapping<N>`

要素 `f` は、`f[x]` が `x` の行き先を表す `std::array<int, N>` です。置換に限らず、どんな写像でもかまいません (変換モノイド)。`op(f, g)` は $f \circ g$、つまり `g` を適用してから `f` を適用した写像で、区間 $[l, r)$ の積は $f_l \circ \dots \circ f_{r-1}$、つまり区間の写像を右から順に適用した結果になります。左から順に適用したい場合は `monoid::Reverse<monoid::Mapping<N>>` を使います。

```cpp
SegTree<monoid::Mapping<3>> seg(n);  // 各要素は恒等写像 (0, 1, 2)
seg.set(i, {0, 2, 1});               // 1 と 2 を入れ替える
int y = seg.prod(l, r)[x];           // x に区間 [l, r) の写像を右から順に適用した行き先
```

`Mapping<N>::swap(i, j)` は、`i` と `j` を入れ替えてほかは動かさない写像 (互換) を返します。上の `{0, 2, 1}` は `monoid::Mapping<3>::swap(1, 2)` と書けます。`group::Permutation<N>::swap(i, j)` でも使えます。

`N` はコンパイル時に決める必要があります。置換に限って逆元も使いたい場合は、[群](group.hpp) の `group::Permutation<N>` を使います。

## 合成の向きと `Reverse<M>`

`Composite` と `Mapping` の積 `op(f, g)` は、数学の記法どおり $f \circ g$ ($g$ を先に適用) です。区間 $[l, r)$ の積は $f_l(\dots f_{r-1}(x))$ になります。[作用素付きモノイド](acted-monoid.hpp) の `composition(f, g)` も同じ向きです。

$f_{r-1}(\dots f_l(x))$ のように左から順に適用したい場合は、積の順序を逆にした `Reverse<M>` を使います。

```cpp
SegTree<monoid::Reverse<monoid::Composite<mint>>> seg(v);
mint y = seg.prod(l, r)(x);  // f_{r-1}(...f_l(x))
```

## ラムダ式から作る

`Monoid(op, e)` で、関数オブジェクトと単位元からモノイドを作れます。

```cpp
SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));
```

## 関連

- 逆元を持つ場合は [群](group.hpp) (`group::Sum`、`group::Prod`、`group::Xor`、`Group(op, e, inv)`)
- 作用素を加えたものは [作用素付きモノイド](acted-monoid.hpp)
