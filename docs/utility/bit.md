---
title: ビット演算
documentation_of: //src/utility/bit.hpp
---

ビット演算の関数です。引数は `long long` で、負の値を渡すと assert で落ちます。そのため、最上位ビット (63 ビット目) が立った 64 ビットの値 (`unsigned long long` のビット集合など) は直接渡せません。

```cpp
btoll("1011");          // 11
btoll("#.#", '#');      // 5 ('#' を 1 とみなす)
popcount(13);           // 3
countl_zero(1);         // 63
countr_zero(8);         // 3
```

## 関数

| 関数 | 説明 | C++17 | C++20 | 計算量 |
|---|---|:-:|:-:|---|
| `btoll(s, one = '1')` | 2 進数の文字列を `long long` にする。文字 `one` を 1、それ以外を 0 とみなす | ✓ | ✓ | $O(\lvert s \rvert)$ |
| `popcount(a)` | 立っているビットの数 | ✓ | ✓ | $O(1)$ |
| `countl_zero(a)` | 上位 (64 ビット中) から連続する 0 の数 | ✓ | ✓ | $O(1)$ |
| `countr_zero(a)` | 下位から連続する 0 の数 | ✓ | ✓ | $O(1)$ |
| `countl_one(a)` | 上位から連続する 1 の数 | | ✓ | $O(1)$ |
| `countr_one(a)` | 下位から連続する 1 の数 | | ✓ | $O(1)$ |
| `bit_ceil(a)` | `a` 以上の最小の 2 の累乗 | | ✓ | $O(1)$ |
| `bit_floor(a)` | `a` 以下の最大の 2 の累乗 | | ✓ | $O(1)$ |
| `bit_width(a)` | `a` を表すのに必要なビット数 | | ✓ | $O(1)$ |

C++17 では `__builtin_*` で実装しているので、`countl_zero(0)` と `countr_zero(0)` は未定義動作です。C++20 では `<bit>` の `std::` 版を呼びます。戻り値の型は C++17 では `int`、C++20 では `long long` です (`btoll` はどちらも `long long`)。

## 関連

- 2 進数以外の桁への変換は [vector に対する演算子と関数](vector_func.hpp) の `radix_convert`
