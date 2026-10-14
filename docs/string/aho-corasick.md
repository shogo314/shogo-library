---
title: Aho-Corasick
documentation_of: //src/string/aho-corasick.hpp
---

複数のパターンを、文字列の中から一度に探す `AhoCorasick<K, Base>` です。パターンを `add` で追加してから `build` を呼びます。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。

```cpp
AhoCorasick<26, 'a'> ac;
ac.add("he");                 // パターン 0
ac.add("she");                // パターン 1
ac.add("hers");               // パターン 2
ac.build();
ac.count("ushers");           // 3 ("she"、"he"、"hers")
ac.count_each("ushers");      // {1, 1, 1}
ac.find_all("ushers");        // { {1, 1}, {2, 0}, {2, 2} } (開始位置, パターンの番号)

// オートマトンの上の DP: ノードを状態にして、文字を読むたびに next で移る
long long v = 0;
for (char c : text) {
    v = ac.next(v, c);
    if (ac.match_count(v) > 0) { /* ここで終わるパターンがある */ }
}
```

ノードは [Trie](trie.hpp) と同じく、文字列を追加した順に作った番号を持ちます。根はノード 0 (空文字列) です。パターンは空でない文字列に限ります。同じパターンを何度も追加でき、別のパターンとして数えます。

ノードの番号・個数などは `long long` です。ノードの中身は `int` で持つので、メモリはノード 1 つあたり $4K + 24$ バイトです。

$L$ をパターンの長さの合計 (ノード数は $L + 1$ 以下)、$P$ をパターンの個数、$\lvert t \rvert$ を探す文字列の長さとします。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `AhoCorasick<K, Base>()` | 空の状態 (根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `add(s)` | パターン `s` を追加し、パターンの番号 (追加した順に 0, 1, ...) を返す。`build` の前に呼ぶ | $O(\lvert s \rvert K)$ |
| `build()` | 失敗リンクと遷移を作る。パターンを追加し終えてから 1 回だけ呼ぶ | $O(LK)$ |
| `count(t)` | `t` に現れるパターンの個数の合計 (同じパターンの出現もすべて数える) | $O(\lvert t \rvert)$ |
| `count_each(t)` | パターンごとの、`t` に現れる回数の `std::vector<long long>` | $O(\lvert t \rvert + L + P)$ |
| `find_all(t)` | `t` に現れるパターンをすべて `(開始位置, パターンの番号)` の組で返す。終わる位置の順に並び、同じ位置で終わるものは長いパターンから、同じパターンは番号の小さい順に並ぶ | $O(\lvert t \rvert + \text{出力の個数})$ |
| `next(v, c)` | ノード `v` で文字 `c` を読んだときに移るノード | $O(1)$ |
| `match_count(v)` | ノード `v` の文字列の接尾辞になっているパターンの個数 (`v` に着いたときに終わるパターンの個数) | $O(1)$ |
| `link(v)` | 失敗リンク (`v` の文字列の最長の真の接尾辞のうち、ノードのあるもの)。根なら -1 | $O(1)$ |
| `node(i)` | パターン `i` が終わるノード | $O(1)$ |
| `parent(v)` | ノード `v` の親 (根なら -1) | $O(1)$ |
| `depth(v)` | ノード `v` の深さ (対応する文字列の長さ) | $O(1)$ |
| `size()` | ノードの個数 (根を含む) | $O(1)$ |
| `pattern_count()` | パターンの個数 | $O(1)$ |

`count`・`count_each`・`find_all` の文字列や `add` のパターンは、`std::string` のほか `std::vector<int>` など、要素を整数に変換できる列なら何でもかまいません。`next`・`match_count`・`link` と照合の関数は、`build` の後に呼びます。

## 関連

- パターンを増やしたり減らしたりしながら接頭辞を数えるなら [Trie](trie.hpp)
- パターンが 1 つなら [文字列アルゴリズム](string.hpp) の KMP 法や Z-algorithm
