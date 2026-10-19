---
title: 平衡二分木 (RBST)
documentation_of: //src/data_structures/rbst.hpp
---

位置で扱う列を、平衡二分木 (RBST、randomized binary search tree) で持ちます。セグメント木と違って、途中への挿入・削除、区間の反転、列の切り分けとつなぎ合わせ (split・merge) ができます。[モノイド](../algebra/monoid.hpp) か [作用素付きモノイド](../algebra/acted-monoid.hpp) を乗せて、区間積や区間作用も求められます。どの操作も期待 $O(\log n)$ です。

```cpp
RBST<acted_monoid::AffineSum<mint>> t(v);  // 区間アフィン変換・区間和
t.insert(2, x);                            // 2 番目の前に x を挿入
t.erase(0);                                // 0 番目を削除
t.reverse(1, 4);                           // [1, 4) を反転
t.apply(0, 3, Affine<mint>{b, c});         // [0, 3) の各値を b * x + c に
mint s = t.prod(1, 3);                     // [1, 3) の和

RBST<monoid::Max<long long>> u(w);  // 作用なし (区間作用以外は使える)
auto back = u.split(5);             // u は先頭 5 個、back は残り
back.reverse(0, back.size());
u.merge(std::move(back));           // 後ろ側を反転してつなぎ直す
```

- 作用素付きモノイドの `mapping` は `(f, x)` か `(f, x, sz)` の形にします。列の位置は挿入・削除で変わるので、`(f, x, l, r)` の形はコンパイルエラーになります。
- 区間反転のために、各頂点に部分木の逆順の積も持ちます。そのため、可換でないモノイド (1 次関数の合成など) を乗せても、反転した区間の積は正しくなります。
- 頂点は、乗せる型ごとに共有する配列に置きます。そのため、同じ型の木どうしで `split`・`merge` できます。削除した頂点や、破棄した木の頂点は再利用します。
- 木をコピーすると、すべての頂点を複製します ($O(n)$)。`split` で切り取った木や `merge` で渡す木は、コピーせずに頂点をそのまま移します。

## メンバ関数

位置・長さは `long long` です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RBST(m = M())` | 空の列 | $O(1)$ |
| `RBST(n, m = M())` | 長さ `n` で、すべて単位元の列 | $O(n)$ |
| `RBST(v, m = M())` | `std::vector` `v` の列 | $O(n)$ |
| `size()` / `empty()` | 長さ / 空か | $O(1)$ |
| `get(k)` / `t[k]` | `k` 番目の値 (`t[k] = x` で代入もできる) | 期待 $O(\log n)$ |
| `set(k, x)` | `k` 番目の値を `x` にする | 期待 $O(\log n)$ |
| `insert(k, x)` | `k` 番目 ($0 \le k \le$ `size()`) に `x` を挿入する。後ろの要素は 1 つずつずれる | 期待 $O(\log n)$ |
| `erase(k)` | `k` 番目を削除して、その値を返す | 期待 $O(\log n)$ |
| `push_front(x)` / `push_back(x)` | 先頭 / 末尾に追加する | 期待 $O(\log n)$ |
| `pop_front()` / `pop_back()` | 先頭 / 末尾を削除して、その値を返す | 期待 $O(\log n)$ |
| `prod(l, r)` | $[l, r)$ の積 | 期待 $O(\log n)$ |
| `all_prod()` | 列全体の積 | $O(1)$ |
| `reverse(l, r)` | $[l, r)$ を反転する | 期待 $O(\log n)$ |
| `apply(l, r, f)` / `apply(k, f)` | $[l, r)$ / `k` 番目の各値に `f` を作用させる (作用素付きモノイドのときだけ) | 期待 $O(\log n)$ |
| `split(k)` | 先頭 `k` 個を残し、残りを切り取って新しい木として返す | 期待 $O(\log n)$ |
| `merge(std::move(other))` | 末尾に `other` をつなげる。`other` は空になる | 期待 $O(\log n)$ |
| `max_right(l, g)` | `g(prod(l, r))` が `true` となる最大の `r` (`g` は単調で、`g(e())` は `true`) | 期待 $O(\log n)$ |
| `min_left(r, g)` | `g(prod(l, r))` が `true` となる最小の `l` | 期待 $O(\log n)$ |
| `to_vector()` | 列を `std::vector` にする | $O(n)$ |
| `os << t` | 値を空白区切りで出力する | $O(n)$ |

`static constexpr bool acted` は、乗せた型が作用素付きモノイドかどうかです。

## 関連

- 挿入・削除・反転が要らなければ [セグメント木](segtree.hpp) や [遅延伝搬セグメント木](lazy-segtree.hpp) のほうが速い
- 値の順に並べた集合で k 番目を求めるなら、座標圧縮して [Fenwick Tree](fenwick-tree.hpp) の二分探索を使う
