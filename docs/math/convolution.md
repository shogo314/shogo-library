---
title: 畳み込み (NTT)
documentation_of: //src/math/convolution.hpp
---

$c_k = \sum_{i + j = k} a_i b_j$ を求めます。短い方の長さが 30 未満なら愚直に計算します。

```cpp
auto c = convolution(a, b);                 // a, b は std::vector<mint>
auto d = convolution_ll({1, 2}, {3, 4});    // {3, 10, 8}
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `convolution(a, b)` | `std::vector<mint>` の畳み込み。mod は任意 (998244353 なら NTT 1 回、それ以外は 3 つの mod の NTT と CRT) | $O(n \log n)$ |
| `convolution_ll(a, b)` | `std::vector<long long>` の畳み込み。結果の各値が `long long` に収まること | $O(n \log n)$ |

## 関連

- 多項式・形式的冪級数の演算は [形式的冪級数](fps.hpp)
- GCD・LCM 畳み込みは [約数変換](divisor-transform.hpp)
