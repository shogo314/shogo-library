---
title: 飽和演算
documentation_of: //src/math/saturating.hpp
---

整数の四則演算と型変換で、結果が型の範囲を超えたら、その型の最大値・最小値に丸める関数です。オーバーフローせずに `INF` 同士を足したいときなどに使います。どれも `constexpr` で、C++26 の `std::add_sat`、`std::sub_sat`、`std::mul_sat`、`std::div_sat`、`std::saturate_cast` と同じ値を返します。

```cpp
saturating_add(2000000000, 2000000000);  // 2147483647
saturating_sub(0u, 1u);                  // 0
saturating_mul(-3000000000LL, 4000000000LL);  // LLONG_MIN
saturating_div(INT_MIN, -1);             // 2147483647
saturating_cast<uint8_t>(300);           // 255
saturating_cast<int>(-5LL);              // -5
```

## 関数

引数と戻り値は、bool と文字型 (`char` など) を除く整数型です。四則演算の 2 つの引数は同じ型でなければなりません (`saturating_add(x, 1)` で `x` が `long long` なら `1LL` と書く)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `saturating_add(x, y)` | $x + y$ を範囲に丸める | $O(1)$ |
| `saturating_sub(x, y)` | $x - y$ を範囲に丸める (符号なしなら下限は 0) | $O(1)$ |
| `saturating_mul(x, y)` | $xy$ を範囲に丸める | $O(1)$ |
| `saturating_div(x, y)` | `x / y` (0 方向に切り捨て)。あふれるのは符号付きの最小値 / -1 だけで、そのときは最大値 ($y \ne 0$) | $O(1)$ |
| `saturating_cast<R>(x)` | `x` を `R` に変換し、範囲外なら `R` の最大値・最小値に丸める (符号の有無が違っても値として比べる) | $O(1)$ |

C++26 では `std::` 版を呼びます。C++17・C++20 では `__builtin_add_overflow` などで実装し、`saturating_cast` の比較には C++20 の `std::cmp_less` を使います (C++17 では同じものを自前で用意しています)。引数の型の制限は、C++20 では `requires`、C++17 では `enable_if` で行うので、整数型でない引数はオーバーロードの候補から外れます。

## 関連

- 整数の切り捨て・切り上げの割り算は [汎用関数](../base/functions.hpp) の `floordiv`、`ceildiv`、`divmod`
