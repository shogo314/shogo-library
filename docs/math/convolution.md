---
title: 畳み込み (NTT)
documentation_of: //src/math/convolution.hpp
---

$c_k = \sum_{i + j = k} a_i b_j$ を求めます。短い方の長さが 60 以下なら愚直に計算します。

```cpp
auto c = convolution(a, b);                 // a, b は std::vector<mint>
auto d = convolution_ll({1, 2}, {3, 4});    // {3, 10, 8}
auto e = convolution_u64(x, y);            // x, y は std::vector<unsigned long long>、2^64 で割った余り
```

NTT は AtCoder Library と同じ作りです。回転因子を法ごとに一度だけ表にし、基数 4 のバタフライで、ビット反転の並べ替えをせずに変換します (順変換の結果はビット反転した順に並び、逆変換でもとに戻ります)。同じ配列どうしの畳み込み (`convolution(a, a)`) では、変換を 1 回省きます。

`convolution` の法による違いは次のとおりです。

- `static_modint` で、法が素数で、$\mathrm{mod} - 1$ が畳み込みの長さ以上の 2 のべき乗で割り切れる (998244353、469762049、167772161、754974721 など) なら、その法で直接 NTT します。
- それ以外 (1000000007、`dynamic_modint`、素数でない法、長さが足りないとき) は、754974721・167772161・469762049 の 3 つの法で NTT し、中国剰余定理で復元します。直接の場合のおよそ 4 倍の時間がかかります。

長さ $5 \times 10^5$ どうしの畳み込みは、998244353 で約 0.03 秒、1000000007 で約 0.12 秒です。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `convolution(a, b)` | `std::vector<mint>` の畳み込み。法は任意 (上を参照) | $O(n \log n)$ |
| `convolution_ll(a, b)` | `std::vector<long long>` の畳み込み。3 つの法と中国剰余定理で求めるので、結果の各値の絶対値が約 $3 \times 10^{25}$ 未満で、`long long` に収まること | $O(n \log n)$ |
| `convolution_u64(a, b)` | `std::vector<unsigned long long>` の畳み込みを $2^{64}$ で割った余りで求める。各値を 32 ビットずつ 2 つに分け、下位どうしの積の和と、上位と下位の積の和だけを 3 つの法と中国剰余定理で求める (NTT 18 回)。$\min(\lvert a \rvert, \lvert b \rvert) \le 10^6$ であること。長さ $5 \times 10^5$ どうしで約 0.2 秒 | $O(n \log n)$ |

## 関連

- 多項式・形式的冪級数の演算は [形式的冪級数](fps.hpp)
- GCD・LCM 畳み込みは [約数変換](divisor-transform.hpp)
