---
title: F2 の行列 (mod 2)
documentation_of: //src/math/f2-matrix.hpp
---

成分が 0 か 1 で、足し算が xor、掛け算が and の行列 (mod 2 の行列) です。各行を 64 bit ずつ詰めて持ち、足し算・積・消去を 64 成分ずつまとめて行います。連立一次方程式・ランク・行列式・逆行列は [行列](matrix.hpp) と同じ名前の関数で求められます。ベクトルは `std::vector<bool>` で受け渡します。

```cpp
F2Matrix A(std::vector<std::string>{"110", "011"});  // '0' と '1' の文字列で 1 行ずつ
auto sol = A.solve({true, false});                   // Ax = b
if (sol) {
    sol->x;      // 解の 1 つ
    sol->basis;  // Ax = 0 の解空間の基底。解全体は x と basis の一部の xor
}
long long r = A.rank();
F2Matrix C = A * B;          // 積
std::cout << C << '\n';      // '0' と '1' の文字列で 1 行ずつ出力
```

## メンバ関数

計算量の $n$、$m$ は行数・列数で、$w = 64$ です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `F2Matrix()` / `F2Matrix(n, m)` | 0 行 0 列の行列 / $n$ 行 $m$ 列の零行列 | $O(nm / w)$ |
| `F2Matrix(s)` | `'0'` と `'1'` の文字列の配列 `s` から作る (各文字列が 1 行) | $O(nm)$ |
| `F2Matrix(v)` | `std::vector<std::vector<int>>` から作る (各成分の偶奇) | $O(nm)$ |
| `F2Matrix::identity(n)` | $n$ 次の単位行列 | $O(n^2 / w)$ |
| `get(i, j)` / `set(i, j, x)` | $(i, j)$ 成分を得る / `x` にする | $O(1)$ |
| `A + B`、`+=` | 足し算 (成分ごとの xor) | $O(nm / w)$ |
| `A * B`、`*=` | 積 ($B$ は $m$ 行 $k$ 列) | $O(nmk / w)$ |
| `A * x` | 列ベクトル `x` (`std::vector<bool>`) との積 | $O(nm / w)$ |
| `pow(k)` | $A^k$ (正方行列) | $O(n^3 / w \cdot \log k)$ |
| `transpose()` | 転置 | $O(nm)$ |
| `==`、`!=` | 比較 | $O(nm / w)$ |
| `solve(b)` | 連立一次方程式 $Ax = b$ の解 `Solution` (`x` と `basis`)。解がなければ `std::nullopt` | $O(nm \min(n, m) / w)$ |
| `rank()` | ランク | $O(nm \min(n, m) / w)$ |
| `kernel()` | $Ax = 0$ の解空間の基底 (長さ $m$ のベクトルを $m - \mathrm{rank}$ 個) | $O(nm \min(n, m) / w)$ |
| `reduced_row_echelon()` | 簡約化した行列と、各行の主成分の列 `{R, pivots}` | $O(nm \min(n, m) / w)$ |
| `det()` | 行列式 (`bool`、正方行列)。正則なら `true` | $O(n^3 / w)$ |
| `inv()` | 逆行列 (正方行列)。正則でなければ `std::nullopt` | $O(n^3 / w)$ |
| `to_strings()` / `os << A` | 各行を `'0'` と `'1'` の文字列にしたもの / 改行区切りで出力 | $O(nm)$ |

`n`、`m` は公開メンバ変数です。解の個数は $2^{\lvert basis \rvert}$ です。

## 関連

- mod 2 以外の行列や、mod $p$ の連立一次方程式は [行列](matrix.hpp)
- 整数の集合の xor で作れる値を扱うなら [XOR 基底](xor-basis.hpp)
