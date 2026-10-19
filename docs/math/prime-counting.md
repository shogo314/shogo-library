---
title: 素数の個数・素数の和 (Lucy DP)
documentation_of: //src/math/prime-counting.hpp
---

$n$ 以下の素数の個数 $\pi(n)$ を、篩を使わずに $O(n^{3/4} / \log n)$ で求めます ($n = 10^{11}$ で 0.2 秒程度)。同じ計算で、すべての $v = \lfloor n / k \rfloor$ について「$v$ 以下の素数の個数」や「$v$ 以下の素数 $p$ の $g(p)$ の和」($g$ は完全乗法的) をまとめて求めた表も作れます。乗法的関数の和を求めるときの土台になります。

```cpp
long long c = prime_count(100000000000LL);  // π(10^11) = 4118054813

auto t = prime_count_table(n);  // すべての floor(n / k) についての π
t(n);                           // π(n)
t(n / 3);                       // π(floor(n / 3))

// 素数の和 (g(p) = p)。prefix(v) は 2 以上 v 以下の整数すべての g の和
PrimeSumTable<__int128> s(n, [](long long v) { return (__int128)v * (v + 1) / 2 - 1; },
                             [](long long p) { return (__int128)p; });
s(n);                           // n 以下の素数の和
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `prime_count(n)` | $n$ 以下の素数の個数 $\pi(n)$ ($n \ge 0$) | $O(n^{3/4} / \log n)$ |
| `prime_count_table(n)` | すべての $v = \lfloor n / k \rfloor$ について $\pi(v)$ を求めた `PrimeSumTable<long long>` ($n \ge 1$) | $O(n^{3/4} / \log n)$ |

## `PrimeSumTable<T>`

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PrimeSumTable<T>(n, prefix, g)` | すべての $v = \lfloor n / k \rfloor$ について $\sum_{p \le v,\ p \text{ は素数}} g(p)$ を求める ($n \ge 1$)。`g` は完全乗法的 ($g(ab) = g(a) g(b)$) な関数で、`prefix(v)` は $g(2) + g(3) + \dots + g(v)$ (2 以上 $v$ 以下の整数すべての和) を返す関数 | $O(n^{3/4} / \log n)$、メモリ $O(\sqrt{n})$ |
| `t(v)` | $v$ 以下の素数 $p$ の $g(p)$ の和。$v$ は $\lfloor n / k \rfloor$ の形 (または 0) であること | $O(1)$ |
| `values()` | $\lfloor n / k \rfloor$ のとる値を昇順に並べたもの | $O(1)$ |

- `T` は `long long`、`__int128`、`modint` など、足し算・引き算・掛け算ができる型です。素数の和は $n = 10^{11}$ で $10^{20}$ を超えるので、`__int128` か `modint` を使います。
- 2 以上 $v$ 以下の整数すべての和から始めて、小さい素数 $p$ から順に「最小素因数が $p$ の合成数」の分を引いていきます (Lucy DP)。$p^2 \le v$ の値だけを更新するので、計算量が $O(n^{3/4} / \log n)$ になります。
- $g(p) = p^k$ の表をいくつか組み合わせれば、$p$ の多項式で表される $g(p)$ の和も求められます。

## 関連

- 小さい $n$ までの素数の列挙や素因数分解は [素数](prime.hpp)
- $\lfloor n / k \rfloor$ の値ごとの区間は [商の列挙](quotients.hpp)
