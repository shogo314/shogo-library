---
title: inf を持つ整数型
documentation_of: //src/math/infint.hpp
---

正の無限大・負の無限大・NaN を持つ符号付き整数型 `infint<T = long long>` です。オーバーフローする演算は無限大に飽和します。最短路の距離など「到達不能」を表したい値に使えます。

```cpp
using I = infint<>;
I a = I::Inf(), b = 5;
I c = a + b;               // inf
I d = I::Max() + b;        // inf (オーバーフローは飽和する)
I e = a - a;               // nan
std::cout << c << ' ' << -c << ' ' << e << '\n';  // "inf -inf nan"
```

内部では `T` の最大値を正の無限大、最小値 + 1 を負の無限大、最小値を NaN として表します。

## 値の作り方

| 書き方 | 値 |
|---|---|
| `infint<T>(x)` | 整数 `x` |
| `infint<T>("inf")`、`"plusinf"` / `"minusinf"` / `"nan"` | 正の無限大 / 負の無限大 / NaN (大文字小文字は問わない)。それ以外の文字列は整数として読む |
| `Inf()`、`PlusInf()` / `MinusInf()` / `NaN()` | 正の無限大 / 負の無限大 / NaN |
| `Max()` / `Min()` | 無限大でない最大値 / 最小値 |

## 演算

| 演算 | 動作 |
|---|---|
| `+`、`-`、`*` (と複合代入) | 有限の値どうしでオーバーフローすれば ±無限大。$\infty - \infty$、$0 \times \infty$ は NaN |
| `/`、`%` | 0 で割ると NaN。無限大どうしは NaN。有限 ÷ 無限大は 0、有限 % 無限大は元の値 |
| 単項 `-` | 符号反転 (無限大は反対の無限大に) |
| `<`、`<=`、`>`、`>=` | NaN を含むと常に `false` |
| `==`、`!=` | 内部表現の比較 (NaN どうしは等しい) |
| `NaN` を含む演算 | 結果は NaN |

## メンバ関数

| 関数 | 説明 |
|---|---|
| `val()` | 内部表現の値 |
| `isfinite()` | 有限か |
| `isPlusInf()`、`isInf()` / `isMinusInf()` / `isNaN()` | 正の無限大か (`isInf` も正の無限大のみ) / 負の無限大か / NaN か |
| `to_string()`、`os << x` | 文字列にする。無限大などの表記は `set_str_plusinf(s)`、`set_str_minusinf(s)`、`set_str_nan(s)` で変えられる (初期値 `inf`、`-inf`、`nan`) |
| `repr()` | `infint<>{"plusinf"}` のような、コンストラクタにそのまま使える文字列 |
