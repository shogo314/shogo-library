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
hamming_distance(5, 3);  // 2 (101 と 011)
```

## 関数

戻り値はどれも `long long` です。C++17 では `__builtin_*` で実装し、C++20 では `<bit>` の `std::` 版を呼びます。どちらでも同じ値を返し、0 を渡したときも C++20 の `std::` 版と同じです (`countl_zero(0)` と `countr_zero(0)` は 64、`bit_width(0)` は 0、`bit_ceil(0)` は 1、`bit_floor(0)` は 0)。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `btoll(s, one = '1')` | 2 進数の文字列を `long long` にする。文字 `one` を 1、それ以外を 0 とみなす | $O(\lvert s \rvert)$ |
| `popcount(a)` | 立っているビットの数 | $O(1)$ |
| `countl_zero(a)` | 上位 (64 ビット中) から連続する 0 の数 | $O(1)$ |
| `countr_zero(a)` | 下位から連続する 0 の数 | $O(1)$ |
| `countl_one(a)` | 上位から連続する 1 の数 (`a` は 0 以上なので常に 0) | $O(1)$ |
| `countr_one(a)` | 下位から連続する 1 の数 | $O(1)$ |
| `bit_ceil(a)` | `a` 以上の最小の 2 の累乗 (`a` は $2^{62}$ 以下) | $O(1)$ |
| `bit_floor(a)` | `a` 以下の最大の 2 の累乗 | $O(1)$ |
| `bit_width(a)` | `a` を表すのに必要なビット数 | $O(1)$ |
| `hamming_distance(a, b)` | `a` と `b` でビットが異なる位置の数 (`popcount(a ^ b)`) | $O(1)$ |

## 関連

- 文字列や配列のハミング距離は [文字列アルゴリズム](../string/string.hpp) の `hamming_distance`
- 2 進数以外の桁への変換は [vector に対する演算子と関数](vector_func.hpp) の `radix_convert`
