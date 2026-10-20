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

## `RollingHash` のメンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RollingHash(base = 0)` | 基数を指定して作る (0 ならランダム) | $O(1)$ |
| `build(s)` / `build(first, last)` | 長さ $n + 1$ の配列 `h` (`h[i]` は先頭 `i` 文字のハッシュ) | $O(n)$ |
| `query(h, l, r)` | $[l, r)$ のハッシュ (`l`、`r` は `long long`) | $O(1)$ (初回は $O(r - l)$) |
| `RollingHash::to_value(x)` | 要素を $[0, 2^{61} - 1)$ の値に変換する (static) | $O(1)$ |

## `RollingHash` のメンバ変数

| 変数 | 説明 |
|---|---|
| `base` | 基数 |
| `power` | `power[i]` は `base` の `i` 乗 (mod $2^{61} - 1$)。必要になった分だけ伸ばす |

## `RHString` のメンバ関数

ハッシュ値と長さだけを持つ文字列型です。連結と比較を $O(1)$ で行えます。同じ `RollingHash` から作ったもの同士でしか演算できません。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `RHString(rh)` | 空文字列 | $O(1)$ |
| `RHString(rh, s)` | 文字列・`vector` などの列、または 1 文字 (`char` や整数) から作る | $O(n)$ |
| `t + u`、`t += u` | 連結 | $O(1)$ (初回は長さ分) |
| `t == u`、`t != u` | 一致判定 | $O(1)$ |
| `t = s`、`t.assign(s)` | 再代入 | $O(n)$ |
| `t.remove_prefix(x)` / `t.remove_suffix(x)` | 先頭 / 末尾の `x` を取り除く。`x` は `RHString` か、`RHString` を作れるもの (文字列や 1 文字)。端が本当に `x` であること (ハッシュからは確かめられず、違うと値が壊れる) | $O(1)$ (初回は長さ分) |
| `t.is_palindrome()` | 回文か | $O(1)$ |
| `t.size()`、`t.empty()`、`t.clear()` | 長さ (`long long`)・空か・空にする | $O(1)$ |

`remove_prefix`・`remove_suffix` は、連結の式を逆にたどって残りのハッシュを求めます。片方のハッシュは基数の逆元の累乗で割る必要があるので、初めて使うときに逆元を求めます (法 $2^{61} - 1$ は素数なので必ずある)。1 文字ずつ `+=` と `remove_prefix` をすれば、長さ $k$ の窓をずらしながらハッシュを持てます。

```cpp
RHString w(rh);
for (int i = 0; i < n; i++) {
    w += RHString(rh, s[i]);
    if (i >= k) w.remove_prefix(s[i - k]);  // w は s[i - k + 1, i]
}
```

## `RHString` のメンバ変数

| 変数 | 説明 |
|---|---|
| `rh` | 使う `RollingHash` への参照 |
| `sz` | 長さ (`long long`) |
| `hash1` | 正順のハッシュ |
| `hash2` | 逆順のハッシュ (回文判定に使う) |

## 関連

- ハッシュを使わずに文字列を探すには [文字列アルゴリズム](string.hpp) の KMP 法・Z-algorithm
- 接尾辞の辞書順や LCP は [Suffix Array と LCP 配列](suffix-array.hpp)
