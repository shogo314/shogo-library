---
title: モノイドの定義
documentation_of: //src/algebra/monoid.hpp
---

[セグメント木](../data_structures/segtree.hpp) などに渡すモノイドです。

モノイドは次のメンバを持つ型として表します。`op`、`e` は static でも非 static でもかまいません。

- `using S`: 要素の型
- `S op(const S& a, const S& b)`: 積 (結合的)
- `S e()`: 単位元

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
| `Composite<T>` | `Affine<T>` | 1次関数 $f(x) = ax + b$ の合成 (左から順に適用) | 恒等写像 |
| `Parenthesis` | `Parenthesis::S` | 括弧列の連結 (対応の取れていない `)` と `(` の個数) | 空の括弧列 |
| `MinWith<T, U = int>` | `pair<T, U>` | 最小値とその位置 (同じ値なら左側) | |
| `MaxWith<T, U = int>` | `pair<T, U>` | 最大値とその位置 (同じ値なら左側) | |
| `MinCount<T, U = long long>` | `pair<T, U>` | 最小値とその個数 | |
| `MaxCount<T, U = long long>` | `pair<T, U>` | 最大値とその個数 | |

`Parenthesis::S` は文字 `'('`、`')'` から作れます。`is_valid()` で正しい括弧列かどうかを判定できます。

## 1次関数 `Affine<T>`

`Composite` の要素や、[作用素付きモノイド](acted-monoid.hpp) の `AffineSum` の作用素に使う、1次関数 $f(x) = ax + b$ の型です。

```cpp
Affine<mint> f{2, 3};   // f(x) = 2x + 3 (省略すると恒等写像 {1, 0})
mint y = f(x);          // 2x + 3
std::cin >> f;          // "a b" を読む
std::cout << f;         // "a b" を出力
```

| メンバ | 説明 |
|---|---|
| `a` / `b` | 傾き / 切片 |
| `f(x)` | $ax + b$ |
| `==`、`!=` | 比較 |
| `is >> f`、`os << f` | `a` と `b` を空白区切りで入出力 |

## ラムダ式から作る

`Monoid(op, e)` で、関数オブジェクトと単位元からモノイドを作れます。

```cpp
SegTree seg(v, Monoid([](int a, int b) { return std::max(a, b); }, -1));
```

## 関連

- 逆元を持つ場合は [群](group.hpp) (`group::Sum`、`group::Prod`、`group::Xor`、`Group(op, e, inv)`)
- 作用素を加えたものは [作用素付きモノイド](acted-monoid.hpp)
