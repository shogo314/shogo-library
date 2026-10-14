---
title: 座標圧縮
documentation_of: //src/utility/compress.hpp
---

値を 0 から始まる番号に置き換える `Compress<T>` です。`T` は `<` で比較できる型 (整数、文字列、`std::pair` など) です。

```cpp
Compress<long long> cp(A);         // A の値を登録して build まで行う
long long i = cp.id(A[0]);         // A[0] の番号 (0 <= i < cp.size())
long long v = cp[i];               // 番号から元の値
std::vector<long long> B = cp.ids(A);  // A の各値を番号に置き換えた列

Compress<long long> cq;            // 複数の列やクエリの値をまとめて登録する場合
cq.add(A);
cq.add(x);
cq.build();
long long l = cq.bisect_left(d), r = cq.bisect_left(u);  // 値が [d, u) の範囲は番号 [l, r)
```

値をすべて登録してから `build` を呼び、そのあとで番号を求めます。`build` の後に `add` したり、`build` の前に番号を求めたりすると assert で落ちます。

## メンバ関数

$n$ は登録した値の個数、$m$ は渡した列の長さです。番号と個数は `long long` で返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Compress()` | 空で作る。`add` で値を登録してから `build` する | $O(1)$ |
| `Compress(v)` | `v` の値を登録して `build` する | $O(n \log n)$ |
| `add(x)` / `add(v)` | 値を 1 つ / 列の値をすべて登録する | $O(1)$ / $O(m)$ |
| `build()` | 登録した値をソートして重複を除く | $O(n \log n)$ |
| `size()` | 異なる値の個数 | $O(1)$ |
| `id(x)` | 値 `x` の番号。登録していない値なら assert で落ちる | $O(\log n)$ |
| `bisect_left(x)` | `x` 以上で最小の値の番号 (なければ `size()`) | $O(\log n)$ |
| `bisect_right(x)` | `x` より大きい最小の値の番号 (なければ `size()`) | $O(\log n)$ |
| `contains(x)` | `x` を登録したか | $O(\log n)$ |
| `cp[i]` | 番号 `i` の値 | $O(1)$ |
| `ids(v)` | `v` の各値を番号に置き換えた列 | $O(m \log n)$ |
| `values()` | ソート済みで重複のない値の列 (参照を返す) | $O(1)$ |

`id` と `bisect_left` の違いに注意してください。圧縮に含めた値の番号は `id` で求めると、登録し忘れた値に気づけます。クエリの範囲の端のように、登録していない値で境界を求めるときは `bisect_left` / `bisect_right` を使います。

## 関連

- `vector` のソートと重複除去だけなら [vector に対する関数](vector_func.hpp) の `unique(v)`、番号を求めるだけなら [コンテナに対する関数](container_func.hpp) の `bisect_left(v, x)`
