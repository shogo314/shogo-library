---
title: inf を持つ整数型
documentation_of: //src/math/infint.hpp
---

正の無限大・負の無限大・NaN を持つ符号付き整数型 `infint<T = long long>` です。オーバーフローする演算は無限大に飽和します。最短路の距離など「到達不能」を表したい値に使えます。

```cpp
using I = infint<>;
I a = I::inf(), b = 5;
I c = a + b;               // inf
I d = I::max() + b;        // inf (オーバーフローは飽和する)
I e = a - a;               // nan
std::cout << c << ' ' << -c << ' ' << e << '\n';  // "inf -inf nan"
```

内部では `T` の最大値を正の無限大、最小値 + 1 を負の無限大、最小値を NaN として表します。

## 値の作り方

| 関数 | 説明 | 計算量 |
|---|---|---|
| `infint<T>(x)` | 整数 `x` | $O(1)$ |
| `infint<T>("inf")`、`"plusinf"` / `"minusinf"` / `"nan"` | 正の無限大 / 負の無限大 / NaN (大文字小文字は問わない)。それ以外の文字列は整数として読む | $O(\lvert s \rvert)$ |
| `inf()`、`plus_inf()` / `minus_inf()` / `nan()` | 正の無限大 / 負の無限大 / NaN | $O(1)$ |
| `max()` / `min()` | 無限大でない最大値 / 最小値 | $O(1)$ |

## 演算子

| 演算子 | 説明 | 計算量 |
|---|---|---|
| `+`、`-`、`*` (と複合代入) | 有限の値どうしでオーバーフローすれば ±無限大。$\infty - \infty$、$0 \times \infty$ は NaN | $O(1)$ |
| `/`、`%` | 0 で割ると NaN。無限大どうしは NaN。無限大 ÷ 有限は ±無限大、無限大 % 有限は NaN。有限 ÷ 無限大は 0、有限 % 無限大は元の値 | $O(1)$ |
| 単項 `-` | 符号反転 (無限大は反対の無限大に) | $O(1)$ |
| `<`、`<=`、`>`、`>=` | NaN を含むと常に `false` | $O(1)$ |
| `==`、`!=` | 内部表現の比較 (NaN どうしは等しい) | $O(1)$ |
| `NaN` を含む演算 | 結果は NaN | $O(1)$ |

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `val()` | 内部表現の値 | $O(1)$ |
| `is_finite()` | 有限か | $O(1)$ |
| `is_plus_inf()`、`is_inf()` / `is_minus_inf()` / `is_nan()` | 正の無限大か (`is_inf` も正の無限大のみ) / 負の無限大か / NaN か | $O(1)$ |
| `to_string()`、`os << x` | 文字列にする。無限大などの表記は `set_str_plusinf(s)`、`set_str_minusinf(s)`、`set_str_nan(s)` で変えられる (初期値 `inf`、`-inf`、`nan`) | 桁数に比例 |
| `repr()` | `infint<>{"plusinf"}` のような、コンストラクタにそのまま使える文字列。型の部分は `T` によらず `infint<>` になる | 桁数に比例 |

## 関連

- `repr()` の仕組みは [repr](../utility/repr.hpp)
- 最短路の距離の型として使うときは [グラフ](../graph/graph.hpp)
