---
title: ローリングハッシュ
documentation_of: //src/string/rolling-hash.hpp
---

mod $2^{61} - 1$ のローリングハッシュです。基数は省略するとランダムに選ばれます。

```cpp
RollingHash rh;
std::string s = "abcabc";
auto h = rh.build(s);                          // 接頭辞のハッシュ
bool eq = rh.query(h, 0, 3) == rh.query(h, 3, 6);  // "abc" == "abc": true

RHString t(rh, "ab"), u(rh, "a");
bool p = (t + u).is_palindrome();              // "aba" は回文: true
```

文字列だけでなく、整数の配列などにも使えます。`char` は 0〜255 として、負の整数は mod で正規化して扱います。

## `RollingHash`

| メンバ | 説明 | 計算量 |
|---|---|---|
| `RollingHash(base = 0)` | 基数を指定して作る (0 ならランダム) | $O(1)$ |
| `build(s)` / `build(first, last)` | 長さ $n + 1$ の配列 `h` (`h[i]` は先頭 `i` 文字のハッシュ) | $O(n)$ |
| `query(h, l, r)` | $[l, r)$ のハッシュ | $O(1)$ (初回は $O(r - l)$) |
| `base` | 基数 | |
| `power` | `power[i]` は `base` の `i` 乗 (mod $2^{61} - 1$)。必要になった分だけ伸ばす | |
| `RollingHash::to_value(x)` | 要素を $[0, 2^{61} - 1)$ の値に変換する (static) | $O(1)$ |

## `RHString`

ハッシュ値と長さだけを持つ文字列型です。連結と比較を $O(1)$ で行えます。同じ `RollingHash` から作ったもの同士でしか演算できません。

| メンバ | 説明 | 計算量 |
|---|---|---|
| `RHString(rh)` | 空文字列 | $O(1)$ |
| `RHString(rh, s)` | 文字列・`vector` などの列、または 1 文字 (`char` や整数) から作る | $O(n)$ |
| `t + u`、`t += u` | 連結 | $O(1)$ (初回は長さ分) |
| `t == u`、`t != u` | 一致判定 | $O(1)$ |
| `t = s`、`t.assign(s)` | 再代入 | $O(n)$ |
| `t.is_palindrome()` | 回文か | $O(1)$ |
| `t.size()`、`t.empty()`、`t.clear()` | 長さ・空か・空にする | $O(1)$ |
