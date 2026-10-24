---
title: Trie
documentation_of: //src/string/trie.hpp
---

文字列の集合 (多重集合) を、接頭辞の木で管理する `Trie<K, Base>` です。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。根はノード 0 で、空文字列に対応します。文字列の操作は、文字列の長さを $L$ として $O(L)$ です。ノードは jump pointer を持つので、2 つのノードの文字列の辞書順の比較や最長共通接頭辞が、ノード数を $n$ として $O(\log n)$ で求められます。

```cpp
Trie<26, 'a'> trie;                // 英小文字
long long v = trie.insert("abc");  // 追加して、"abc" のノードを返す
trie.insert("abd");
trie.count_prefix("ab");           // 2 ("ab" で始まる文字列の個数)
trie.count("abc");                 // 1
trie.erase("abc");                 // 1 個取り除く
trie.find("x");                    // -1 (ノードがない)

long long a = trie.find("abd"), b = trie.extend(trie.find("ab"), 'a');  // extend は文字列を追加せずにノードを作る
trie.less(b, a);                   // true ("aba" < "abd")
trie.depth(trie.lca(a, b));        // 2 (最長共通接頭辞 "ab" の長さ)
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Trie<K, Base>()` | 空の Trie (根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `insert(s)` | 文字列 `s` を 1 個追加し、`s` のノードを返す。同じ文字列を何度も追加できる | $O(LK)$ (新しいノード 1 つに $O(K)$) |
| `erase(s)` | `s` を 1 個取り除く。`s` がなければ何もせず `false` を返す。ノードは消さない | $O(L)$ |
| `find(s)` | `s` のノード (なければ -1)。`s` を接頭辞に持つ文字列を一度でも追加していればノードがある | $O(L)$ |
| `count(s)` | `s` の個数 | $O(L)$ |
| `count_prefix(s)` | `s` で始まる文字列の個数 (重複を含む) | $O(L)$ |
| `longest_common_prefix(s)` | 追加した文字列のどれかとの最長共通接頭辞の長さの最大値 | $O(L)$ |
| `total()` | 文字列の個数 (重複を含む) | $O(1)$ |
| `size()` | ノードの個数 (根を含む) | $O(1)$ |
| `child(v, c)` | ノード `v` から文字 `c` で進んだノード (なければ -1) | $O(1)$ |
| `extend(v, c)` | ノード `v` から文字 `c` で進んだノード。なければ作る (文字列の個数は変えない) | $O(K)$ |
| `less(u, v)` | ノード `u` の文字列が `v` の文字列より辞書順で小さいか。一方が他方の接頭辞なら短いほうが小さい | $O(\log n)$ |
| `lca(u, v)` | ノード `u`、`v` の最小共通祖先 (2 つの文字列の最長共通接頭辞のノード) | $O(\log n)$ |
| `parent(v)` | 親 (根なら -1) | $O(1)$ |
| `depth(v)` | 深さ (ノードの文字列の長さ) | $O(1)$ |
| `count_prefix_at(v)` | ノード `v` を通る (`v` の文字列で始まる) 文字列の個数 | $O(1)$ |
| `count_at(v)` | ノード `v` で終わる文字列の個数 | $O(1)$ |

- ノードの番号・個数・深さ・長さは `long long` で返し、ノードの番号も `long long` で受け取ります。文字 `c` は `int` です。
- `s` は `std::string` のほか、`std::vector<int>` などの整数の列でもかまいません (`Trie<10, 0>` に数字の列を入れるなど)。
- ノードは子の番号を `K` 個の配列で持つので、メモリは「ノード数 × (4K + 24) バイト」ほど使います。文字の種類が少ないときは `K` を小さくしてください。
- ノードの番号は追加した順に付き、親の番号は子より小さくなります。そのため、番号の大きい順に処理すれば葉から根へ向かう DP ができます。

## 例: すべての組の最長共通接頭辞の長さの和

文字列の組 $(i, j)$ の最長共通接頭辞の長さは、2 つが共通に通る根以外のノードの個数です。そのため、ノードごとに通る文字列の個数 $c$ から $\binom{c}{2}$ を足せば求められます。

```cpp
long long sum = 0;
for (long long v = 1; v < trie.size(); v++) {
    long long c = trie.count_prefix_at(v);
    sum += c * (c - 1) / 2;
}
```

## 例: 辞書順最小の経路

各辺に文字が書かれたグラフで、始点から各頂点への最短路のうち文字列が辞書順最小のものを求めます。BFS の順に、前の層の頂点のノードを `extend` で伸ばし、`less` で最小を選びます (ABC481 F)。

```cpp
auto d = shortest_path(g, 0, false).dist;
Trie<9, 1> trie;  // 文字は 1〜9
std::vector<long long> node(n, -1);
node[0] = 0;
for (long long u : sorted_idx(d)) {
    for (auto& e : g[u]) {
        if (d[e.dst] != d[u] + 1) continue;
        long long v = trie.extend(node[u], e.cost);
        if (node[e.dst] == -1 || trie.less(v, node[e.dst])) node[e.dst] = v;
    }
}
```

## 関連

- 整数を 2 進数で入れる Trie は [Binary Trie](../data_structures/binary-trie.hpp)
- 1 つのパターンの検索は [文字列アルゴリズム](string.hpp) の KMP 法
- 複数のパターンを文字列の中から一度に探すなら [Aho-Corasick](aho-corasick.hpp)
