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
lltob(5, 4);            // "0101"
msb(12); lsb(12);       // 3, 2
kth_set_bit(0b10110, 1);  // 2
for (long long s : subsets(0b101)) { }       // 5, 4, 1, 0
for (long long i : bits(0b10110)) { }        // 1, 2, 4
for (long long s : combinations_mask(4, 2)) { }  // 3, 5, 6, 9, 10, 12
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
| `has_single_bit(a)` | `a` が 2 の累乗か (`bool`)。C++20 では `std::has_single_bit` を呼ぶ | $O(1)$ |
| `hamming_distance(a, b)` | `a` と `b` でビットが異なる位置の数 (`popcount(a ^ b)`) | $O(1)$ |

### その他の関数

C++20 の `<bit>` にはない関数です。ビットの位置 `i` は $0 \le i < 63$、桁数 `n` は 63 以下です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `msb(a)` | 最上位の立っているビットの位置。0 なら -1 | $O(1)$ |
| `lsb(a)` | 最下位の立っているビットの位置。0 なら -1 | $O(1)$ |
| `lowbit(a)` | 最下位の立っているビットだけを残した値 `a & -a` (位置ではなく値)。0 なら 0 | $O(1)$ |
| `test_bit(a, i)` | `i` ビット目が立っているか (`bool`) | $O(1)$ |
| `set_bit(a, i)` / `reset_bit(a, i)` / `flip_bit(a, i)` | `i` ビット目を 1 にした / 0 にした / 反転した値。`a` そのものは変えない | $O(1)$ |
| `parity(a)` | 立っているビットの数の偶奇 (`popcount(a) % 2`) | $O(1)$ |
| `lltob(a, n = -1, one = '1', zero = '0')` | `a` を $n$ 桁の 2 進数の文字列にする (`btoll` の逆)。`n` を省略すると `bit_width(a)` 桁 (0 なら `"0"`) | $O(n)$ |
| `reverse_bits(a, n)` | 下位 $n$ ビットの並びを逆にする ($a < 2^n$) | $O(n)$ |
| `rotate_left(a, k, n)` / `rotate_right(a, k, n)` | 下位 $n$ ビットを左 / 右に $k$ ビット巡回シフトする ($a < 2^n$、$k$ は負でもよい) | $O(1)$ |
| `gray_code(a)` | グレイコード `a ^ (a >> 1)`。隣り合う整数で 1 ビットだけ変わる | $O(1)$ |
| `inverse_gray_code(g)` | グレイコードから元の値に戻す | $O(\log 64)$ |
| `kth_set_bit(mask, k)` | `mask` の立っているビットのうち、下から $k$ 番目 (0-indexed) の位置 ($k <$ `popcount(mask)`) | $O(\log 64)$ |
| `next_combination_mask(s)` | 立っているビットの数が `s` と同じで、`s` より大きい最小の値 (Gosper's hack)。`long long` に収まらなければ -1。$s > 0$ | $O(1)$ |
| `xor_upto(n)` | $0 \oplus 1 \oplus \cdots \oplus n$ | $O(1)$ |
| `count_bit_upto(n, i)` | $0$ 以上 $n$ 以下の整数のうち、`i` ビット目が立っているものの数 | $O(1)$ |

`xor_upto` を使うと、区間 $[l, r]$ の XOR は `xor_upto(r) ^ xor_upto(l - 1)` ($l \ge 1$) です。`count_bit_upto` は、整数の範囲にわたるビットごとの寄与を数えるのに使えます。

```cpp
// 0 以上 n 以下の整数の popcount の和
long long sum = 0;
for (long long i = 0; i < 63; i++) sum += count_bit_upto(n, i);
```

## 列挙

範囲 for で使える列挙です。値はどれも `long long` で、`constexpr` の中でも使えます。

| 関数 | 列挙するもの | 計算量 (全体) |
|---|---|---|
| `subsets(mask)` | `mask` の部分集合を `mask` から 0 まで降順に (0 と `mask` を含む) | $O(2^{\mathrm{popcount}(mask)})$ |
| `supersets(mask, n)` | $n$ ビットの集合のうち `mask` を含むものを `mask` から昇順に ($2^n - 1$ を含む)。$n \le 62$ | $O(2^{n - \mathrm{popcount}(mask)})$ |
| `bits(mask)` | `mask` の立っているビットの位置を昇順に | $O(\mathrm{popcount}(mask))$ |
| `add_one(mask, n)` | $n$ ビットのうち `mask` に含まれない位置 $i$ を昇順に、$i$ と `mask | 1 << i` の組 (`std::pair<long long, long long>`) で | $O(n - \mathrm{popcount}(mask))$ |
| `remove_one(mask)` | `mask` に含まれる位置 $i$ を昇順に、$i$ と `mask ^ 1 << i` の組 (`std::pair<long long, long long>`) で | $O(\mathrm{popcount}(mask))$ |
| `combinations_mask(n, k)` | $n$ ビットの集合のうち、ちょうど $k$ 個のビットが立つものを昇順に (Gosper's hack)。$n \le 62$、$k > n$ なら何も列挙しない | $O(\binom{n}{k})$ |
| `subsets_of_size(mask, k)` | `mask` の部分集合のうち、ちょうど $k$ 個のビットが立つものを昇順に。$k >$ `popcount(mask)` なら何も列挙しない | $O(k \binom{\mathrm{popcount}(mask)}{k})$ |
| `subset_pairs(n)` | $n$ ビットのすべての集合 $S$ と、その部分集合 $T$ の組 $(S, T)$ (`std::pair<long long, long long>`) を、$S$ は 0 から昇順、各 $S$ の中で $T$ は $S$ から 0 まで降順に。$n \le 62$ | $O(3^n)$ |

`add_one` と `remove_one` は、構造化束縛で位置と集合を受け取れます。巡回セールスマン問題のように、1 つずつ要素を足していく bit DP の遷移に使えます。

```cpp
// dp[S][v] = S を訪れて v にいるときの最小コスト (配る DP)
for (long long S = 0; S < (1LL << n); S++) {
    for (long long v : bits(S)) {
        for (auto [i, T] : add_one(S, n)) chmin(dp[T][i], dp[S][v] + dist[v][i]);
    }
}
```

すべての集合について部分集合を列挙すると、全体で $O(3^n)$ です。

```cpp
// dp[S] = S を 2 つに分けたときの最小値
for (long long S = 0; S < (1LL << n); S++) {
    for (long long T : subsets(S)) chmin(dp[S], cost[T] + cost[S ^ T]);
}
// subset_pairs で 1 重のループにしても同じ
for (auto [S, T] : subset_pairs(n)) chmin(dp[S], cost[T] + cost[S ^ T]);
```

## 関連

- 部分集合・上位集合についての和を $O(n 2^n)$ で求めるには [部分集合・上位集合のゼータ変換、メビウス変換とビット演算の畳み込み](../math/bitwise-transform.hpp)

- 文字列や配列のハミング距離は [文字列アルゴリズム](../string/string.hpp) の `hamming_distance`
- 2 進数以外の桁への変換は [vector に対する演算子と関数](vector_func.hpp) の `radix_convert`
