---
title: 値の個数を数える多重集合 (Counter)
documentation_of: //src/data_structures/counter.hpp
---

値ごとの個数を `std::map` で管理する多重集合 `Counter<T>` です (Python の `collections.Counter`)。個数が 0 になった値は自動で取り除かれます。

```cpp
std::vector<int> v = {3, 1, 3, 2, 3};
Counter<int> c(v);
c[1] += 2;                        // 1 を 2 個追加
long long k = c[3];               // 3
auto top = c.most_common();       // 個数の多い順
for (auto [x, cnt] : c) { }       // 値の昇順に走査
Counter<int> d = c + Counter<int>(3);  // 3 を 1 個足した Counter
```

## メンバ

`n` は異なる値の個数です。

| メンバ | 説明 | 計算量 |
|---|---|---|
| `Counter<T> c` | 空の Counter | $O(1)$ |
| `Counter<T> c(x)` | 値 `x` が 1 個 | $O(1)$ |
| `Counter<T> c{ {x, k}, ... }` | 値 `x` が `k` 個、… で初期化 | |
| `Counter<T> c(v)` | コンテナ `v` の要素を数える | $O(\lvert v \rvert \log n)$ |
| `c[x]` / `c.get(x)` | `x` の個数 (なければ 0) | $O(\log n)$ |
| `c[x] = k` / `c.set(x, k)` | `x` の個数を `k` にする (`k >= 0`) | $O(\log n)$ |
| `c[x] += k`、`c[x] -= k` / `c.inc(x, k)` | `x` の個数を増減する (負になると assert で落ちる) | $O(\log n)$ |
| `c + d`、`c += d` | 個数を足し合わせる | $O(m \log (n + m))$ ($m$ は `d` の異なる値の個数) |
| `c - d`、`c -= d` | 個数を引く (負になると assert で落ちる)。`c -= c` で空になる | $O(m \log n)$ |
| `for (auto [x, cnt] : c)` | `{値, 個数}` を値の昇順に走査 | $O(n)$ |
| `c.size()` | 異なる値の個数 (重複を含めた要素数ではない。重複を含めた個数は個数の総和で、必要なら別に数えておく) | $O(1)$ |
| `c.most_common()` | `{値, 個数}` のリスト。個数の降順、同数なら値の昇順 | $O(n \log n)$ |
| `c.data` | 中身の `std::map<T, long long>` (値の昇順に走査できる) | |
