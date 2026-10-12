---
title: 数論 (逆元、中国剰余定理、畳み込みなど)
documentation_of: //src/math/number-theory.hpp
---

mod 演算・中国剰余定理・畳み込みの関数です。

```cpp
long long x = modinv(3, 7);                 // 5
long long y = modpow(2, 10, 1000);          // 24
auto [r, l] = crt({2, 3}, {3, 5});          // {8, 15}
auto c = convolution(a, b);                 // a, b は std::vector<mint>
auto d = convolution_ll({1, 2}, {3, 4});    // {3, 10, 8}
```

## mod 演算

| 関数 | 説明 | 計算量 |
|---|---|---|
| `modinv(a, mod)` | $a^{-1} \bmod \mathrm{mod}$ (`a` と `mod` は互いに素) | $O(\log \mathrm{mod})$ |
| `modpow(a, n, mod)` | $a^n \bmod \mathrm{mod}$ (`n` は負でもよい) | $O(\log n)$ |

## 中国剰余定理

$x \equiv r_i \pmod{m_i}$ をすべて満たす $x$ を求めます。`m` は互いに素でなくてもかまいません。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `crt(r, m)` | `{最小の非負整数解, lcm(m)}`。解がなければ `{-1, -1}`。lcm が `long long` に収まること | $O(k \log \max m)$ |
| `crt(r, m, mod)` | `{最小の非負整数解 % mod, lcm(m) % mod}`。lcm が大きくてもよい | $O(k^2 \log \max m)$ |
| `coprimize_simulaneous_congruence_equation(r1, m1, r2, m2)` | 2 式の連立合同式を、mod が互いに素になるように書き換える (矛盾すればすべて -1) | $O(\log^2 \max m)$ |

## 畳み込み

$c_k = \sum_{i + j = k} a_i b_j$ を求めます。短い方の長さが 30 未満なら愚直に計算します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `convolution(a, b)` | `std::vector<mint>` の畳み込み。mod は任意 (998244353 なら NTT 1 回、それ以外は 3 つの mod の NTT と CRT) | $O(n \log n)$ |
| `convolution_ll(a, b)` | `std::vector<long long>` の畳み込み。結果の各値が `long long` に収まること | $O(n \log n)$ |

## 関連

- 多項式・形式的冪級数の演算は [形式的冪級数](fps.hpp)
- 二項係数などは [組み合わせ](combinatorics.hpp)
