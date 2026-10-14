---
title: マクロ (rep など)
documentation_of: //src/base/macro.hpp
---

コンテスト用のマクロです。[型の別名](type_alias.hpp) と、入力用のマクロが使う [入出力](io.hpp) を include し、最適化の `#pragma` (`avx2`、`O3`、`unroll-loops`) も設定します。

```cpp
void solve() {
    LL(n, m);                  // long long n, m; を読む
    VL(a, n);                  // vector<long long> a(n); を読む
    rep(i, n) a[i] += m;
    std::sort(all(a));
    if (a[0] > 0) { Yes }      // "Yes" を出力して return
    No
}
```

## ループ

ループ変数はすべて `long long` です。

| マクロ | 意味 |
|---|---|
| `rep(n)` | `n` 回繰り返す |
| `rep(i, n)` | `i = 0, 1, ..., n-1` |
| `rep(i, a, n)` | `i = a, a+1, ..., n-1` |
| `rep(i, a, n, t)` | `i = a, a+t, ...` (`n` 未満) |
| `repd(i, n)` | `i = n-1, n-2, ..., 0` |
| `repd(i, a, n)` | `i = n-1, n-2, ..., a` |
| `repd(i, a, n, t)` | `i = n-1, n-1-t, ...` (`a` 以上) |
| `rrep(i, n)` | `i = 1, 2, ..., n` |
| `rrepd(i, n)` | `i = n, n-1, ..., 1` |
| `all(v)` | `v.begin(), v.end()` |

## 入力

宣言と読み込みを同時に行います。

| マクロ | 宣言される変数 |
|---|---|
| `LL(a, b, ...)` | `ll a, b, ...;` |
| `STR(s, t, ...)` | `str s, t, ...;` |
| `IN(T, x)` | `T x;` |
| `CHAR(c)` | `char c;` |
| `VL(a, n)` / `VC(a, n)` / `VS(a, n)` / `VPL(a, n)` | 長さ `n` の `vl` / `vc` / `vs` / `vpl` |
| `VVL(a, n, m)` | `n` × `m` の `vvl` |
| `AL(a, k)` / `AAL(a, n, m)` | `al<k>` / `aal<n, m>` |
| `VAL(a, n, k)` | 長さ `n` の `val<k>` |
| `SL(a, n)` | `n` 個読んだ `sl` (`set<ll>`) |

`scan(a, b, ...)` で、宣言済みの変数を読むこともできます。

## 出力して終了

文字列を出力して改行し、`return;` します。戻り値が `void` の関数 (`solve` など) の中で使います。

| マクロ | 出力 |
|---|---|
| `Yes` / `No` | `Yes` / `No` |
| `YES` / `NO` | `YES` / `NO` |
| `Takahashi` / `Aoki` | `Takahashi` / `Aoki` |

## 関連

- マクロで使う型の別名 (`ll`、`vl` など) は [型の別名](type_alias.hpp)
- コンテナの入出力と `print` は [入出力](io.hpp)
