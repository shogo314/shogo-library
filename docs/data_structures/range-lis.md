---
title: 区間の最長増加部分列
documentation_of: //src/data_structures/range-lis.hpp
---

固定した列について、区間 $[l, r)$ の最長増加部分列 (狭義) の長さを、構築 $O(n \log^2 n)$、クエリ $O(\log n)$ でオンラインに答えます。

```cpp
std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6};
RangeLIS rl(a);
long long x = rl.lis(0, 8);  // 4 (例: 1, 4, 5, 9)
long long y = rl.lis(1, 4);  // 2 (1, 4)
```

同じ値を含んでいてもかまいません (狭義の増加列を数えます)。値の型は `<` で比べられれば何でもかまいません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RangeLIS(a)` | 列 `a` から作る | $O(n \log^2 n)$ |
| `size()` | 要素数 | $O(1)$ |
| `lis(l, r)` | `a[l], ..., a[r-1]` の最長増加部分列 (狭義) の長さ | $O(\log n)$ |

- 列を置換に直し (同じ値は後ろのものほど小さくする)、Tiskin の seaweed を求めます。位置を行、値を列とするマス目で、左端と上端から入った線を、値が一致するマスでは交差させず、それ以外では一度も交差していなければ交差させて右下へ流したものです。
- 左端の行 $i$ から入った線が右端の行 $e_i$ から出るとすると、$\mathrm{LIS}(a[l, r)) = (r - l) - \#\lbrace i : l \le i,\ e_i < r \rbrace$ です。これを [Wavelet Matrix](wavelet-matrix.hpp) で数えます。
- seaweed は、値で半分に分けて再帰し、2 つの結果を unit-Monge 行列の積 (分割統治と、境界の階段をたどる操作で $O(n \log n)$) でつないで求めます。$n = 10^5$ で構築は 0.3 秒ほどです。

## 関連

- 列全体の最長増加部分列は [最長増加部分列](../dp/longest-increasing-subsequence.hpp)
