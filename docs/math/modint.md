---
title: 四則演算において自動で mod を取るクラス
documentation_of: //src/math/modint.hpp
---

四則演算のたびに mod を取る整数型です。法は $2^{31}$ 未満であること。

```cpp
using mint = static_modint<998244353>;   // modint998244353 と同じ
mint a = 3, b = -1;                       // 負の数も剰余で初期化: b = 998244352
mint c = a / 2 + b.pow(10);               // 割り算は逆元を掛ける

modint::set_mod(13);                      // 実行時に法を決める
modint x = 20;                            // 7
```

## 型

| 型 | 説明 |
|---|---|
| `static_modint<Mod>` | コンパイル時に法 `Mod` が決まる |
| `dynamic_modint<ID>` | 実行時に `set_mod(m)` で法を決める (初期値は 998244353)。`ID` ごとに別の法を持てる |
| `modint998244353` | `static_modint<998244353>` |
| `modint1000000007` | `static_modint<1000000007>` |
| `modint` | `dynamic_modint<-1>` |

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `mint(x)` | 整数 `x` の剰余で初期化 (負でもよい) | $O(1)$ |
| `x.val()` | 保持している値 ($0$ 以上 mod 未満) | $O(1)$ |
| `mint::mod()` | 法 | $O(1)$ |
| `mint::set_mod(m)` | 法を設定 (`dynamic_modint` のみ) | $O(1)$ |
| `+`、`-`、`*`、`+=`、`-=`、`*=`、単項 `+` `-`、`++`、`--` | 演算 | $O(1)$ |
| `/`、`/=` | 逆元を掛ける | $O(\log \mathrm{mod})$ |
| `x.pow(n)` | $x^n$ (`n` は非負) | $O(\log n)$ |
| `x.inv()` | 逆元 (存在しなければ assert で落ちる)。`static_modint` で法が素数なら $x^{\mathrm{mod} - 2}$ で求める | $O(\log \mathrm{mod})$ |
| `==`、`!=` | 比較 | $O(1)$ |
| `is >> x`、`os << x` | 入出力 (入力は `long long` として読んで剰余を取る) | $O(1)$ |

## 関連

- `long long` の逆元・累乗は [mod 演算](modular-arithmetic.hpp)、畳み込みは [畳み込み](convolution.hpp)
- 二項係数は [組み合わせ](combinatorics.hpp)
