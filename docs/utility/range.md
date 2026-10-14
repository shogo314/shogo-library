---
title: Python の range のような整数列
documentation_of: //src/utility/range.hpp
---

Python の `range` のような、等差数列を表す `Range` です。要素を実際には持たないので、長い列でもメモリを使いません。

```cpp
for (long long i : Range(2, 10, 3)) { /* 2, 5, 8 */ }
Range r(10, 0, -3);       // 10, 7, 4, 1
r.size();                 // 4
r.sum();                  // 22
r.contains(4);            // true
r.index(4);               // 2
Range(10).product_xor();  // 0 ^ 1 ^ ... ^ 9 = 1
```

`sum`、`max` などのメンバ関数を持つので、[コンテナに対する関数](container_func.hpp) の `sum(r)`、`max(r)` などから呼ぶと $O(1)$ で計算されます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Range(stop)` | `0, 1, ..., stop-1` | $O(1)$ |
| `Range(start, stop)` | `start, start+1, ..., stop-1` | $O(1)$ |
| `Range(start, stop, step)` | `start, start+step, ...` (`stop` の手前まで)。`step` は負でもよいが 0 は不可 | $O(1)$ |
| `begin()` / `end()` | ランダムアクセスイテレータ | $O(1)$ |
| `size()` / `empty()` | 要素数 / 空か | $O(1)$ |
| `r[i]` / `at(i)` | `i` 番目の要素 | $O(1)$ |
| `count(x)` / `contains(x)` | `x` の個数 (0 か 1) / `x` を含むか | $O(1)$ |
| `index(x)` | `x` の位置 (含まなければ assert で落ちる) | $O(1)$ |
| `find(x)` | `x` を指すイテレータ (なければ `end()`) | $O(1)$ |
| `lower_bound(x)` / `upper_bound(x)` | `x` 以上 / `x` より大きい最初の要素 (`step > 0` のみ) | $O(1)$ |
| `sum()` | 総和 | $O(1)$ |
| `min()` / `max()` | 最小値 / 最大値 (空なら assert で落ちる) | $O(1)$ |
| `product_xor()` | 総 xor (要素は非負) | $O(\log^2 \max)$ |
| `reversed()` | 逆順の `Range` | $O(1)$ |
| `sorted()` | 昇順の `Range` | $O(1)$ |
| `clipped(l, r)` | 要素のうち `l` 以上 `r` 未満のものの `Range` | $O(1)$ |
| `slice(s)` | 位置を `Range` `s` で選んだ `Range` (Python の `r[a:b:c]`) | $O(1)$ |
| `to_vector()` | `std::vector<long long>` にする | $O(n)$ |
| `==`、`!=` | 要素の列として等しいか (`Range(0, 5, 2) == Range(0, 6, 2)`) | $O(1)$ |
| `repr()` | `"Range(start, stop, step)"` ([repr](repr.hpp) 用) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `start` / `stop` / `step` | コンストラクタに渡した値 (`const` なので読むだけ) |

## 関連

- `sum(r)`、`max(r)` などのコンテナ全般の関数は [コンテナに対する関数](container_func.hpp)
- `repr(r)` で文字列にするなら [repr](repr.hpp)
