---
title: 数論 (中国剰余定理)
documentation_of: //src/math/number-theory.hpp
---

中国剰余定理の関数です。`modinv`、`modpow` は [mod 演算](modular-arithmetic.hpp) にあり、このファイルからも使えます。

```cpp
auto res = crt({2, 3}, {3, 5});             // res->x == 8, res->lcm == 15
```

## 中国剰余定理

$x \equiv r_i \pmod{m_i}$ をすべて満たす $x$ を求めます。`m` は互いに素でなくてもかまいません。

結果は `std::optional<CRTResult>` で、解がなければ `std::nullopt` です。`CRTResult` は解 `x` と `lcm` を持ち、解の全体は `x + lcm * k` (`k` は整数) です。

```cpp
if (auto res = crt(r, m)) {
    auto [x, lcm] = *res;
} else {
    // 解なし
}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `crt(r, m)` | `x` は最小の非負整数解、`lcm` は `m` の最小公倍数。lcm が `long long` に収まること | $O(k \log \max m)$ |
| `crt(r, m, mod)` | `x` は最小の非負整数解 % `mod`、`lcm` は `m` の最小公倍数 % `mod`。lcm が大きくてもよい | $O(k^2 \log \max m)$ |
| `coprimize_simultaneous_congruence_equation(r1, m1, r2, m2)` | 2 式の連立合同式を、mod が互いに素になるように書き換える。矛盾すれば `false` を返し、引数は変えない | $O(\log^2 \max m)$ |

## 関連

- mod 演算 (`modinv`、`modpow`) は [mod 演算](modular-arithmetic.hpp)
- 畳み込みは [畳み込み](convolution.hpp)
- 二項係数などは [組み合わせ](combinatorics.hpp)
- 一次関数の床関数の和は [floor sum](floor-sum.hpp)
- 約数・倍数のゼータ変換、メビウス変換と GCD・LCM 畳み込みは [約数変換](divisor-transform.hpp)
