---
title: 尺取り法
documentation_of: //src/utility/two-pointers.hpp
---

尺取り法で、各 $l$ について区間 $[l, r)$ を右に伸ばせるだけ伸ばした $r$ を求めます。区間の状態は、加える・取り除くときに呼ばれる関数で更新します。

```cpp
std::vector<long long> a = {1, 2, 3, 2, 1, 4};

// 各 l から、和が 5 以下のまま右に伸ばせる r
long long s = 0;
auto r = two_pointers(
    a.size(), [&](long long l, long long r) { return s + a[r] <= 5; },  // [l, r) に r を加えてよいか
    [&](long long r) { s += a[r]; },                                     // r を加えた
    [&](long long l) { s -= a[l]; });                                    // l を取り除いた
// r = {2, 3, 4, 5, 6, 6}

// 状態を持たないなら can_add だけでよい (ソートした列で差が 2 以下)
std::vector<long long> b = {1, 2, 4, 5, 6};
auto r2 = two_pointers(b.size(), [&](long long l, long long r) { return b[r] - b[l] <= 2; });  // {2, 3, 5, 5, 5}

// 円環は 1 周ずらした写しを後ろにつなげ、l < n の分を見る (周の長さ 10 で、時計回りに幅 3 未満にある点の数)
std::vector<long long> c = {0, 4, 8, 9};
int n = c.size();
for (int i = 0; i < n; i++) c.push_back(c[i] + 10);
auto r3 = two_pointers(2 * n, [&](long long l, long long r) { return c[r] - c[l] < 3; });
// r3[l] - l = {1, 1, 3, 2}
```

- [l, r) に r を加えてよいなら [l + 1, r) にも加えてよい (区間を左から縮めても条件が崩れない) ことが必要です。
- `can_add(l, l)` が偽なら区間は空のまま $r = l$ になります。空の区間からは何も取り除きません。
- 円環で写しをつなげるとき、区間の幅が 1 周未満になる条件にすれば、同じ要素を二重に数えることはありません。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `two_pointers(n, can_add, add, erase)` | 長さ `n` の列で、各 $l$ について $[l, r)$ を伸ばし終えたときの $r$ を並べた長さ `n` の列を返す。`can_add(l, r)` は $[l, r)$ に $r$ を加えてよいか、`add(r)`・`erase(l)` は加えた・取り除いたときに呼ばれる | `can_add` が $O(n)$ 回、`add`・`erase` が $n$ 回以下 |
| `two_pointers(n, can_add)` | 状態を持たない版 (`can_add(l, r)` が $l$ と $r$ だけで決まるとき) | `can_add` が $O(n)$ 回 |

## 関連

- 和が条件を満たす区間の個数は [和が条件を満たす区間の個数](../others/subarray-sum.hpp)
- 答えで二分探索をするなら [二分探索](binary-search.hpp)
