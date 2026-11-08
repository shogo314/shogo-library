---
title: 値の個数を数える多重集合 (Counter)
documentation_of: //src/data_structures/counter.hpp
---

値ごとの個数を `std::map` で管理する多重集合 `Counter<T>` です (Python の `collections.Counter`)。個数が 0 になった値は自動で取り除かれます。出現回数順の `std::set` も管理し、最頻値を $O(1)$ で取得できます。

```cpp
std::vector<int> v = {3, 1, 3, 2, 3};
Counter<int> c(v);
c[1] += 2;                        // 1 を 2 個追加
long long k = c[3];               // 3
auto [value, count] = *c.mode();  // 最頻値とその個数 (空でない場合)
auto top = c.most_common();       // 個数の多い順
auto top2 = c.most_common(2);     // 上位 2 件 (値, 個数)
for (auto [x, cnt] : c) { }       // 値の昇順に走査
Counter<int> d = c + Counter<int>(3);  // 3 を 1 個足した Counter
```

空の `Counter` の `mode()` は `std::nullopt` を返します。同数なら最小の値を選びます。内部の map は非公開です。個数の変更には `[]`・`set`・`inc` を使います。

## メンバ関数

`n` は異なる値の個数です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Counter<T> c` | 空の Counter | $O(1)$ |
| `Counter<T> c(x)` | 値 `x` が 1 個 | $O(1)$ |
| `Counter<T> c{ {x, k}, ... }` | 値 `x` が `k` 個、… で初期化 | $O(m \log m)$ ($m$ は組の数) |
| `Counter<T> c(v)` | コンテナ `v` の要素を数える | $O(\lvert v \rvert \log n)$ |
| `c[x]` / `c.get(x)` | `x` の個数 (なければ 0) | $O(\log n)$ |
| `c[x] = k` / `c.set(x, k)` | `x` の個数を `k` にする (`k >= 0`) | $O(\log n)$ |
| `c[x] += k`、`c[x] -= k` / `c.inc(x, k)` | `x` の個数を増減する (負になると assert で落ちる) | $O(\log n)$ |
| `c + d`、`c += d` | 個数を足し合わせる | $O(m \log (n + m))$ ($m$ は `d` の異なる値の個数) |
| `c - d`、`c -= d` | 個数を引く (負になると assert で落ちる)。`c -= c` で空になる | $O(m \log n)$ |
| `for (auto [x, cnt] : c)` | `{値, 個数}` を値の昇順に走査 | $O(n)$ |
| `c.lower_bound(x)` / `c.upper_bound(x)` | 値が `x` 以上 / より大きい最初の要素の読み取り専用イテレータ。なければ `end()` | $O(\log n)$ |
| `c.size()` | 異なる値の個数 (重複は数えない) | $O(1)$ |
| `c.total()` | 重複を含めた要素数 (個数の総和。Python の `Counter.total()` と同じ) | $O(n)$ |
| `c.mode()` | 最頻値と個数を `std::optional<Mode>` (`Mode {value, count}`) で返す。同数なら最小の値を選び、空なら `std::nullopt` を返す | $O(1)$ |
| `c.most_common()` | `{値, 個数}` のリスト。個数の降順、同数なら値の昇順 | $O(n)$ |
| `c.most_common(k)` | 同じ順序で上位 `k` 件を返す (`k >= 0`)。`k > n` なら全件、`k = 0` または空なら空のリスト | $O(\min(k, n))$ |

## 関連

- 最大・最小と任意の要素の削除だけなら [削除可能な優先度付きキュー](erasable-priority-queue.hpp)
