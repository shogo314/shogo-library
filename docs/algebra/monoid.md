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
| `ClampComposite<T>` | `Clamp<T>` | clamp する関数 $f(x) = \min(\max(x, \mathit{lb}), \mathit{ub})$ の合成 $f \circ g$ ($g$ を先に適用) | 恒等写像 |
| `ClampAddComposite<T>` | `ClampAdd<T>` | 足してから clamp する関数 $f(x) = \min(\max(x + \mathit{add}, \mathit{lb}), \mathit{ub})$ の合成 $f \circ g$ ($g$ を先に適用) | 恒等写像 |
| `Mapping<N>` | `std::array<int, N>` | $\lbrace 0, \dots, N-1 \rbrace$ から自分自身への写像の合成 $f \circ g$ ($g$ を先に適用)。全単射でなくてよい | 恒等写像 |
| `Parenthesis` | `Parenthesis::S` | 括弧列の連結 (対応の取れていない `)` と `(` の個数) | 空の括弧列 |
| `MinWith<T, U = long long>` | `pair<T, U>` | 最小値とその位置 (同じ値なら左側) | `{型の最大値, U{}}` |
| `MaxWith<T, U = long long>` | `pair<T, U>` | 最大値とその位置 (同じ値なら左側) | `{型の最小値, U{}}` |
| `MinCount<T, U = long long>` | `pair<T, U>` | 最小値とその個数 | `{型の最大値, 0}` |
| `MaxCount<T, U = long long>` | `pair<T, U>` | 最大値とその個数 | `{型の最小値, 0}` |
| `PrefixSumMax<T>` / `PrefixSumMin<T>` | `PrefixSumMax<T>::S` など | 区間の和 `sum` と、空を含む prefix の和の最大値 `max` (最小値 `min`) | 空の区間 `{0, 0}` |
| `SuffixSumMax<T>` / `SuffixSumMin<T>` | `SuffixSumMax<T>::S` など | 区間の和 `sum` と、空を含む suffix の和の最大値 `max` (最小値 `min`) | 空の区間 `{0, 0}` |
| `MaxSubarraySum<T>` | `MaxSubarraySum<T>::S` | 区間の和 `sum`、空を含む prefix・suffix の和の最大値 `prefix`・`suffix`、空を含む連続部分列の和の最大値 `best` | 空の区間 `{0, 0, 0, 0}` |
| `Reverse<M>` | `M::S` | `M::op(b, a)` (積の順序を逆にする) | `M::e()` |

`Parenthesis::S` は文字 `'('`、`')'` から作れます。`is_valid()` で正しい括弧列かどうかを判定できます。

## prefix・suffix の和と連続部分列の和

`PrefixSumMax<T>`、`PrefixSumMin<T>`、`SuffixSumMax<T>`、`SuffixSumMin<T>`、`MaxSubarraySum<T>` は、区間の和と一緒に prefix の和などの最大値・最小値を持ちます。どれも**空の prefix・suffix・部分列を含めて**数えるので、最大値は 0 以上、最小値は 0 以下になり、単位元は空の区間 (すべて 0) です。値の prefix max ではなく、prefix の**和**の最大値であることに注意してください。

要素は `S(x)` で値 `x` の1要素から作れます。`std::vector<T>` から `std::vector<S>(a.begin(), a.end())` で変換することもできます。`==`、`!=` で比較できます。

```cpp
using M = monoid::PrefixSumMax<long long>;
SegTree<M> seg(std::vector<M::S>(a.begin(), a.end()));
long long m = seg.prod(l, r).max;  // max(0, a[l], a[l] + a[l+1], ..., a[l] + ... + a[r-1])
// l から足していって和が初めて正になる位置 (なければ n)
long long j = seg.max_right(l, [](const M::S& s) { return s.max <= 0; });

SegTree<monoid::MaxSubarraySum<long long>> seg2(n);
seg2.set(i, x);
long long best = seg2.prod(l, r).best;  // [l, r) の連続部分列の和の最大値 (空なら 0)
```

空の部分列を許さない最大値が欲しい場合は、区間の最大値 (`Max<T>`) が負かどうかで場合分けします。

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

## clamp する関数 `Clamp<T>`

`ClampComposite` の要素や、[作用素付きモノイド](acted-monoid.hpp) の `ClampMin`・`ClampMax`・`ClampMinMax` の作用素に使う、$f(x) = \min(\max(x, \mathit{lb}), \mathit{ub})$ の型です。$\mathit{lb} \le \mathit{ub}$ でなければなりません。chmax だけなら `{x, 型の最大値}`、chmin だけなら `{型の最小値, x}`、代入なら `{x, x}` と書けます。

clamp の合成はまた clamp になります ($\mathrm{clamp}(\mathrm{clamp}(x, a, b), c, d) = \mathrm{clamp}(x, \mathrm{clamp}(a, c, d), \mathrm{clamp}(b, c, d))$)。

```cpp
Clamp<long long> f{0, 10};  // f(x) = min(max(x, 0), 10) (省略すると恒等写像 {型の最小値, 型の最大値})
long long y = f(x);         // x を [0, 10] に収めた値
std::cin >> f;              // "lb ub" を読む
std::cout << f;             // "lb ub" を出力

SegTree<monoid::ClampComposite<long long>> seg(n);  // 各要素は恒等写像
seg.set(i, {lb, ub});
long long z = seg.prod(l, r)(x);                    // x に区間 [l, r) の clamp を右から順に適用した値
```

### メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `f(x)` | $\min(\max(x, \mathit{lb}), \mathit{ub})$ | $O(1)$ |
| `==`、`!=` | 比較 | $O(1)$ |
| `is >> f`、`os << f` | `lb` と `ub` を空白区切りで入出力 | $O(1)$ |

### メンバ変数

| 変数 | 説明 |
|---|---|
| `lb` / `ub` | 下限 / 上限 |

## 足してから clamp する関数 `ClampAdd<T>`

`ClampAddComposite` の要素や、[作用素付きモノイド](acted-monoid.hpp) の `ClampAddMin`・`ClampAddMax`・`ClampAddMinMax`、[Beats 用の作用素付きモノイド](beats-acted-monoid.hpp) の `ChminChmaxAddSum` の作用素に使う、$f(x) = \min(\max(x + \mathit{add}, \mathit{lb}), \mathit{ub})$ の型です。加算・chmin・chmax・代入をまとめて表せます。$\mathit{lb} \le \mathit{ub}$ でなければなりません。

`lb` が型の最小値、`ub` が型の最大値のときは、それぞれ下限・上限がないことを表します。合成ではこの値に `add` を足さないので、あふれません。

| 作用 | 書き方 |
|---|---|
| $x \leftarrow x + b$ | `{型の最小値, 型の最大値, b}` |
| $x \leftarrow \min(x, b)$ | `{型の最小値, b, 0}` |
| $x \leftarrow \max(x, b)$ | `{b, 型の最大値, 0}` |
| $x \leftarrow b$ | `{b, b, 0}` |

```cpp
ClampAdd<long long> f{0, 10, 3};  // f(x) = min(max(x + 3, 0), 10) (省略すると恒等写像)
long long y = f(x);
std::cin >> f;                    // "lb ub add" を読む
std::cout << f;                   // "lb ub add" を出力
```

### メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `f(x)` | $\min(\max(x + \mathit{add}, \mathit{lb}), \mathit{ub})$ | $O(1)$ |
| `==`、`!=` | 比較 | $O(1)$ |
| `is >> f`、`os << f` | `lb`、`ub`、`add` を空白区切りで入出力 | $O(1)$ |

### メンバ変数

| 変数 | 説明 |
|---|---|
| `lb` / `ub` | 下限 / 上限 |
| `add` | clamp の前に足す値 |

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

`Composite`、`ClampComposite`、`ClampAddComposite`、`Mapping` の積 `op(f, g)` は、数学の記法どおり $f \circ g$ ($g$ を先に適用) です。区間 $[l, r)$ の積は $f_l(\dots f_{r-1}(x))$ になります。[作用素付きモノイド](acted-monoid.hpp) の `composition(f, g)` も同じ向きです。

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
