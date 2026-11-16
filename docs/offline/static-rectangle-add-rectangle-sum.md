---
title: オフラインの長方形加算・長方形和
documentation_of: //src/offline/static-rectangle-add-rectangle-sum.hpp
---

長方形への加算をすべて適用した後の、各長方形内の総和をオフラインで求めます。平面走査と Fenwick Tree を使います。

```cpp
StaticRectangleAddRectangleSum<> solver;
solver.add(0, 0, 3, 2, 5);  // [0, 3) × [0, 2) に 5 を加算
solver.query(1, 1, 4, 3);
auto answers = solver.solve();  // {10}
```

座標は `long long` で、負の座標も使えます。引数の順は `left, bottom, right, top`、領域は半開で、幅・高さ 0 も許します。初期値はすべて 0 です。整数格子のセルの総和（各加算の重みと重なり面積の積の和）を返します。

加算と問い合わせの登録順にかかわらず、**すべての加算を適用した状態**で答えます。`solve()` は何度でも呼べ、呼んだ後にも登録できます。

`T` は重み・中間計算・答えの型で、既定は `long long` です。座標からの構築、加減乗算が必要です。`modint998244353` や `__int128_t` も使えます。中間計算には座標同士の積が現れるので、最終結果だけでなく中間値も収まる型を指定してください。

## メンバ関数

$n$ は加算数、$q$ は問い合わせ数です。演算を定数時間とした計算量です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `StaticRectangleAddRectangleSum<T>()` | 空の状態で構築 | $O(1)$ |
| `add(l, d, r, u, weight)` | 長方形への加算を登録 | 償却 $O(1)$ |
| `query(l, d, r, u)` | 長方形和の問い合わせを登録 | 償却 $O(1)$ |
| `solve()` | 問い合わせの登録順に `std::vector<T>` を返す | $O((n+q)\log(n+q+1))$ 時間、$O(n+q)$ 領域 |

## 関連

- [長方形](../geometry/rectangle.hpp)
- [Fenwick Tree](../data_structures/fenwick-tree.hpp)
- [Mo's algorithm](mo.hpp)
