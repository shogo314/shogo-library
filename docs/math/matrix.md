---
title: 行列
documentation_of: //src/math/matrix.hpp
---

行列 `Matrix<T, OperatorProperty>` です。線形代数の行列としても、文字のグリッド (`Matrix<char>`) としても使えます。

```cpp
Matrix<mint> A({ {1, 1}, {1, 0} });
auto F = A.pow(n);                    // フィボナッチ数列の行列累乗

std::vector<std::string> s(h);        // グリッドを読み込んで回転する
Matrix<char> g(s);
auto t = g.rotate(1).vstr();          // 時計回りに 90 度回して vector<string> に戻す
```

`OperatorProperty` には要素の演算 (`zero`、`add`、`neg`、`one`、`mul`、`inv`) を定義した型を渡します。省略すると通常の `+`、`*` になります。xor と and の環など、別の演算を使う場合は自分で定義します。使わない演算は定義しなくてもかまいません。

## コンストラクタ・アクセス

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Matrix({ {a, b}, {c, d} })` | 初期化子リストから作る | $O(nm)$ |
| `Matrix(v)` | `vector<vector<T>>` や `vector<string>` から作る | $O(nm)$ |
| `Matrix(n, m, val = 0)` | `n` 行 `m` 列で、要素はすべて `val` | $O(nm)$ |
| `A.size()` | 行数 (`long long`) | $O(1)$ |
| `A[i][j]` | 要素 | $O(1)$ |
| `for (auto& row : A)` | 各行を走査 | $O(n)$ |
| `A.col(j)` | `j` 列目 | $O(n)$ |
| `A.str(i)` / `A.vstr()` | `i` 行目を `string` で / 全体を `vector<string>` で返す | $O(m)$ / $O(nm)$ |
| `==`、`!=` | 比較 | $O(nm)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `n` / `m` | 行数 / 列数 (`long long`) |

## 線形代数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A + B`、`A - B`、`+=`、`-=` | 和・差 | $O(nm)$ |
| `A * B`、`*=` | 積 | $O(nmp)$ |
| `A * x` / `x * A` | 列ベクトル / 行ベクトルとの積 (`vector<T>` を返す) | $O(nm)$ |
| `A.pow(k)` | $A^k$ | $O(n^3 \log k)$ |
| `A.det()` | 行列式 | $O(n^3)$ |
| `A.inv()` | 逆行列 (正則でなければ assert で落ちる) | $O(n^3)$ |

`det`、`inv` は掃き出し法で割り算を使うので、要素は体 (`modint` や浮動小数点型など) である必要があります。`int` や `long long` のような整数型では割り算が切り捨てになり、正しい値になりません (例: `Matrix<long long>({ {2, 1}, {1, 1} }).det()` は 1 ではなく 2 を返す)。整数の行列の行列式は、十分大きい素数を法とする `modint` で計算してください。

浮動小数点型なら部分ピボット選択を行い、絶対値が $10^{-9}$ 未満を 0 とみなします。

## 連立一次方程式

```cpp
Matrix<mint> A(n, m);       // n 本の式、m 個の変数
std::vector<mint> b(n);
auto sol = A.solve(b);      // Ax = b
if (!sol) { /* 解なし */ }
sol->x;                     // 解の 1 つ (特殊解)
sol->basis;                 // Ax = 0 の解空間の基底。解全体は x + (basis の一次結合)
long long r = A.rank();
auto [R, pivots] = A.reduced_row_echelon();
```

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A.solve(b)` | 連立一次方程式 $Ax = b$ の解 `Solution` (`x` と `basis`)。解がなければ `std::nullopt` | $O(nm \min(n, m))$ |
| `A.rank()` | ランク | $O(nm \min(n, m))$ |
| `A.kernel()` | $Ax = 0$ の解空間の基底 (長さ $m$ のベクトルを $m - \mathrm{rank}$ 個) | $O(nm \min(n, m))$ |
| `A.reduced_row_echelon()` | 簡約化した行列 (各行の主成分が 1 で、主成分のある列の他の成分が 0) と、各行の主成分の列 `{R, pivots}`。`pivots` の個数がランクで、0 だけの行は下にまとまる | $O(nm \min(n, m))$ |

- 解は、主成分のない列 (自由変数) を 0 にした特殊解と、自由変数を 1 つだけ 1 にした基底で表します。mod $p$ なら解の個数は $p^{\lvert basis \rvert}$ で、解が 1 つに決まるのは `basis` が空のときです。
- 要素は体である必要があり、`modint` を想定しています。浮動小数点型では 0 かどうかを `==` で判定するので、誤差のある計算には使えません。
- mod 2 の連立一次方程式は、64 要素ずつまとめて計算する [F2 の行列](f2-matrix.hpp) のほうが速いです。

## グリッド操作

いずれも新しい行列を返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `A.transpose()` | 転置 | $O(nm)$ |
| `A.rev_lr()` / `A.rev_ud()` | 左右反転 / 上下反転 | $O(nm)$ |
| `A.rotate(k)` | 時計回りに 90 度を `k` 回 (負なら反時計回り) | $O(nm)$ |
| `A.shift(dy, dx)` | $(i, j)$ を $((i + dy) \bmod n, (j + dx) \bmod m)$ に巡回シフト | $O(nm)$ |
| `A.shift_l(k)`、`shift_r(k)`、`shift_u(k)`、`shift_d(k)` | 左・右・上・下に `k` 回巡回シフト | $O(nm)$ |

## 関連

- `det`、`inv`、`solve` で使う体の要素は [modint](modint.hpp)
- mod 2 の行列は [F2 の行列](f2-matrix.hpp)
- 行列累乗の代わりに漸化式を多項式で扱うなら [形式的冪級数](fps.hpp)
