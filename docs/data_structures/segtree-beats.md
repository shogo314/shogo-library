---
title: Segment Tree Beats
documentation_of: //src/data_structures/segtree-beats.hpp
---

区間 chmin/chmax などを扱う Segment Tree Beats です。[遅延伝搬セグメント木](lazy-segtree.hpp) と同じ形の作用素付きモノイド ([algebra/acted-monoid.hpp](../algebra/acted-monoid.hpp)) を受け取りますが、`mapping` は `std::pair<bool, S>` (作用に失敗したか, 作用後の値) を返します。失敗を返したノードは、子に作用を伝搬してから値を計算し直します。

ライブラリには Beats 用の作用素付きモノイドは用意していないので、自分で定義します。区間 chmin・区間和の例です。

```cpp
struct Node {
    long long max1, max2, cnt, sum;  // 最大値、2番目の最大値、最大値の個数、和
    Node(long long x = 0) : max1(x), max2(LLONG_MIN), cnt(1), sum(x) {}
};
struct ChminSum {
    using S = Node;
    using F = long long;  // chmin する値
    S op(const S& a, const S& b) const {
        S r; r.sum = a.sum + b.sum;
        if (a.max1 == b.max1) { r.max1 = a.max1; r.cnt = a.cnt + b.cnt; r.max2 = std::max(a.max2, b.max2); }
        else if (a.max1 > b.max1) { r.max1 = a.max1; r.cnt = a.cnt; r.max2 = std::max(a.max2, b.max1); }
        else { r.max1 = b.max1; r.cnt = b.cnt; r.max2 = std::max(a.max1, b.max2); }
        return r;
    }
    S e() const { S r; r.max1 = r.max2 = LLONG_MIN; r.cnt = 0; r.sum = 0; return r; }
    std::pair<bool, S> mapping(F f, const S& x) const {
        if (x.max1 <= f) return {false, x};   // 変化なし
        if (x.max2 < f) {                      // 最大値だけが変わる
            S r = x; r.sum -= (x.max1 - f) * x.cnt; r.max1 = f;
            return {false, r};
        }
        return {true, x};                      // 失敗: 子に伝搬して計算し直す
    }
    F composition(F f, F g) const { return std::min(f, g); }
    F id() const { return LLONG_MAX; }
};

std::vector<Node> v = {5, 2, 8, 3};
SegTreeBeats<ChminSum> seg(v);
seg.apply(0, 4, 4);   // 区間 chmin
seg.prod(0, 4).sum;   // 13
```

`mapping` は `(f, x)`、`(f, x, sz)`、`(f, x, l, r)` のどの形でもかまいません。ラムダ式から作る場合は `ActedMonoid(op, e, mapping, composition, id)` を渡します。区間 chmin・chmax・加算・区間和をまとめて扱う例は、テスト `test/yosupo/range-chmin-chmax-add-range-sum.*.test.cpp` にあります。

## メンバ関数

※ は、作用素付きモノイドが Segment Tree Beats の条件を満たす場合のならし計算量で、区間 chmin・chmax・加算・区間和の場合の値です。作用の伝搬が失敗すると子に降りて計算し直すので、作用を伝搬する操作はすべてこの計算量になります。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SegTreeBeats(n, a = A())` | 要素数 `n`、すべて単位元で初期化 | $O(n)$ |
| `SegTreeBeats(v, a = A())` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `seg[k]` | `k` 番目の値 | 償却 $O(\log^2 n)$ ※ |
| `set(k, x)` / `seg[k] = x` | `k` 番目を `x` に更新 | 償却 $O(\log^2 n)$ ※ |
| `prod(l, r)` | 区間 $[l, r)$ の積 | 償却 $O(\log^2 n)$ ※ |
| `all_prod()` | 全体の積 | $O(1)$ |
| `apply(k, f)` | `k` 番目に `f` を作用 | 償却 $O(\log^2 n)$ ※ |
| `apply(l, r, f)` | 区間 $[l, r)$ に `f` を作用 | 償却 $O(\log^2 n)$ ※ |
| `max_right(l, g)` | `g(prod(l, r))` が真となる最大の `r` (`g` は単調) | 償却 $O(\log^2 n)$ ※ |
| `min_left(r, g)` | `g(prod(l, r))` が真となる最小の `l` (`g` は単調) | 償却 $O(\log^2 n)$ ※ |
| `os << seg` | 全要素を空白区切りで出力 | 償却 $O(\log^2 n)$ ※ の $n$ 倍 |

## 関連

- 作用が常に成功する場合は [遅延伝搬セグメント木](lazy-segtree.hpp)
