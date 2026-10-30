---
title: vector に対する演算子と関数
documentation_of: //src/utility/vector_func.hpp
---

`std::vector` に演算子と便利な関数を追加します。計算量の $n$ は `v` の長さ、$m$ は `w` の長さです。

```cpp
std::vector<int> a = {1, 2, 3};
a--;                              // 0-indexed にする: {0, 1, 2}
auto s = cumulative_sum(a);       // {0, 0, 1, 3}
auto b = a | 2;                   // {0, 1, 2, 0, 1, 2}
auto idx = argsort(a, std::greater<>());  // 値の降順に並べた添字: {2, 1, 0}
auto c = select(a, idx);          // {2, 1, 0}
```

## 順位の求め方

`p = argsort(v)` は「`k` 番目に小さい要素の添字が `p[k]`」という置換です。これをもう一度 `argsort` すると逆置換になり、「`v[i]` が何番目に小さいか」が得られます (APL の ⍋⍋)。`argsort` は安定なので、同率は添字の小さい順に別の順位になり、結果は必ず $0, \ldots, n-1$ の置換です。転倒数に渡すときなど、置換がほしいときはこれを使います。

同率の扱いで、次の 3 つを使い分けます。

| 書き方 | `{20, 10, 20, 30}` の結果 | 同率の扱い |
|---|---|---|
| `argsort(argsort(v))` | `{1, 0, 2, 3}` | 添字の小さい順に別の順位を付ける (置換になる) |
| `rank(v)` | `{1, 0, 1, 3}` | 同じ順位にして、次の順位を飛ばす |
| `Compress(v).ids(v)` | `{1, 0, 1, 2}` | 同じ番号にして、詰める ([座標圧縮](compress.hpp)) |

## 演算子

| 演算子 | 説明 | 計算量 |
|---|---|---|
| `++v`、`v++`、`--v`、`v--` | 全要素を ±1 (入力の 1-indexed を 0-indexed に直すときなど) | $O(n)$ |
| `v + x`、`x + v`、`v += x` | 全要素に `x` を足す | $O(n)$ |
| `v * x`、`x * v`、`v *= x` | 全要素に `x` を掛ける | $O(n)$ |
| `v + w`、`v += w` | 要素ごとの和 (短い方は 0 で埋める) | $O(\max(n, m))$ |
| `v * w`、`v *= w` | 要素ごとの積 (長い方の余りは 0 になる) | $O(\max(n, m))$ |
| `v |= w` | `w` を末尾に連結 (`extend` と同じ) | $O(m)$ |
| `v | k`、`k | v`、`v |= k` | `v` を `k` 回繰り返す (`k` は 0 以上。負なら assert で落ちる) | $O(nk)$ |

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `argsort(v)` / `argsort(v, comp)` | 値を昇順 (`comp` の順) に安定ソートしたときの添字のリスト (`std::vector<long long>`)。APL の grade up。降順は `argsort(v, std::greater<>())`。`argsort(argsort(v))` は各要素の順位 (同率は添字の小さい順に別の順位を付けた置換) | $O(n \log n)$ |
| `rank(v)` / `rank(v, comp)` | 各要素の順位 (`v[i]` より前に来る要素の個数)。同率は同じ順位で、次の順位は飛ばす (`{30, 10, 30, 20}` なら `{2, 0, 2, 1}`)。飛ばさずに詰めるなら [座標圧縮](compress.hpp) の `Compress(v).ids(v)` | $O(n \log n)$ |
| `select(v, idx)` | `{v[idx[0]], v[idx[1]], ...}`。`idx` は整数型の `vector` で、範囲外なら assert で落ちる。`select(a, argsort(b))` で `b` の昇順に `a` を並べる | $O(\lvert \mathit{idx} \rvert)$ |
| `cumulative_sum(v)` | 先頭に 0 を付けた累積和 (長さ `size + 1`) | $O(n)$ |
| `iota(n)` | `{0, 1, ..., n-1}` | $O(n)$ |
| `unique(v)` | ソートして重複を除いたコピー | $O(n \log n)$ |
| `abs(v)` | 全要素の絶対値 | $O(n)$ |
| `hamming_distance(v, w)` | 同じ長さの `v` と `w` で要素が異なる位置の数 (長さが違うと assert で落ちる) | $O(n)$ |
| `extend(v, w)` | `w` を末尾に連結 | $O(m)$ |
| `assign(v, w)` | `w` の内容で置き換える (型の変換つき) | $O(m)$ |
| `radix_convert(x, base = 10)` | 整数 `x` を `base` 進数の桁のリスト (上位桁から) にする。`x = 0` なら空のリスト。`x >= 0`、`base >= 2` でなければ assert で落ちる | $O(\log_{base} x)$ |
| `radix_convert(digits, base = 10)` | `base` 進数の桁のリスト (上位桁から) を整数に戻す。`base >= 2` で、各桁が $[0, \mathit{base})$ になければ assert で落ちる | 桁数に比例 |

## 関連

- 文字列などの列のハミング距離は [文字列アルゴリズム](../string/string.hpp)、整数のハミング距離は [ビット演算](bit.hpp) の `hamming_distance`
- コンテナ全般に使える関数 (`sorted`、`sum`、`bisect_left` など) は [コンテナに対する関数](container_func.hpp)
