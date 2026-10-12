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

| メンバ | 説明 |
|---|---|
| `Matrix({ {a, b}, {c, d} })` | 初期化子リストから作る |
| `Matrix(v)` | `vector<vector<T>>` や `vector<string>` から作る |
| `Matrix(n, m, val = 0)` | `n` 行 `m` 列で、要素はすべて `val` |
| `n` / `m` | 行数 / 列数 |
| `A[i][j]` | 要素 |
| `for (auto& row : A)` | 各行を走査 |
| `A.col(j)` | `j` 列目 |
| `A.str(i)` / `A.vstr()` | `i` 行目を `string` で / 全体を `vector<string>` で返す |
| `==`、`!=` | 比較 |

## 線形代数

| メンバ | 説明 | 計算量 |
|---|---|---|
| `A + B`、`A - B`、`+=`、`-=` | 和・差 | $O(nm)$ |
| `A * B`、`*=` | 積 | $O(nmp)$ |
| `A * x` / `x * A` | 列ベクトル / 行ベクトルとの積 (`vector<T>` を返す) | $O(nm)$ |
| `A.pow(k)` | $A^k$ | $O(n^3 \log k)$ |
| `A.det()` | 行列式 | $O(n^3)$ |
| `A.inv()` | 逆行列 (正則でなければ assert で落ちる) | $O(n^3)$ |

`det`、`inv` は浮動小数点型なら部分ピボット選択を行い、絶対値が $10^{-9}$ 未満を 0 とみなします。

## グリッド操作

いずれも新しい行列を返します。

| メンバ | 説明 |
|---|---|
| `A.transpose()` | 転置 |
| `A.rev_lr()` / `A.rev_ud()` | 左右反転 / 上下反転 |
| `A.rotate(k)` | 時計回りに 90 度を `k` 回 (負なら反時計回り) |
| `A.shift(dy, dx)` | $(i, j)$ を $((i + dy) \bmod n, (j + dx) \bmod m)$ に巡回シフト |
| `A.shift_l(k)`、`shift_r(k)`、`shift_u(k)`、`shift_d(k)` | 左・右・上・下に `k` 回巡回シフト |
