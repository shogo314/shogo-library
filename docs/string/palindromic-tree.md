---
title: 回文木 (Eertree)
documentation_of: //src/string/palindromic-tree.hpp
---

列に現れる空でない回文 (種類) をすべて頂点として持つ `PalindromicTree<K, Base>` です。末尾に 1 文字ずつ追加でき、長さ $n$ の列全体で $O(n)$ で作れます。異なる回文の個数、各回文の出現回数、各位置で終わる最長の回文などが求められます。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。

```cpp
PalindromicTree<26, 'a'> pt("abacaba");
pt.count_distinct();                   // 7 (a, b, c, aba, aca, bacab, abacaba)
auto occ = pt.occurrences();           // occ[v] は頂点 v の回文が現れる回数
long long v = pt.longest_suffix(6);    // 位置 6 で終わる最長の回文の頂点
pt.len(v);                             // 7
pt.add('a');                           // 末尾に 'a' を追加 (追加後の最長の回文接尾辞の頂点を返す)
```

頂点 0 は長さ $-1$ の根 (ODD)、頂点 1 は長さ $0$ の根 (EVEN) です。回文の頂点は 2 から、初めて現れた順 (最初に現れたときの終わりの位置の順) に番号が付きます。頂点 $v$ の子は、$v$ の回文の両端に同じ文字を付けた回文です。長さが奇数の回文は ODD の下に、偶数の回文は EVEN の下にぶら下がります。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PalindromicTree<K, Base>()` | 空の列の回文木 (2 つの根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `PalindromicTree<K, Base>(s)` | 列 `s` の回文木 | $O(\lvert s \rvert K)$ |
| `add(c)` | 末尾に文字 `c` を追加し、追加後の列の最長の回文接尾辞の頂点を返す | 償却 $O(1)$ (新しい頂点には $O(K)$) |
| `size()` | 頂点の個数 (2 つの根を含む) | $O(1)$ |
| `count_distinct()` | 異なる空でない回文の個数 (`size() - 2`) | $O(1)$ |
| `length()` | 追加した列の長さ | $O(1)$ |
| `len(v)` | 頂点 `v` の回文の長さ (ODD は $-1$、EVEN は $0$) | $O(1)$ |
| `suffix_link(v)` | 頂点 `v` の回文より短い、最長の空でない回文接尾辞の頂点。なければ EVEN (1)。ODD と EVEN では 0 | $O(1)$ |
| `parent(v)` | 両端の 1 文字を除いた回文の頂点。長さ 1 なら ODD (0)、長さ 2 なら EVEN (1)、根なら $-1$ | $O(1)$ |
| `child(v, c)` | 頂点 `v` の回文の両端に文字 `c` を付けた回文の頂点 (なければ $-1$) | $O(1)$ |
| `first_end(v)` | 頂点 `v` の回文が初めて現れたときの終わりの位置。回文は `[first_end(v) - len(v) + 1, first_end(v)]` にある (根は $-1$) | $O(1)$ |
| `longest_suffix(i)` | 位置 `i` で終わる最長の回文の頂点 | $O(1)$ |
| `occurrences()` | 各頂点の回文が列に現れる回数の配列 (根は 0) | $O(\mathrm{size}())$ |

- 頂点の番号・長さ・個数・位置は `long long` で返し、頂点の番号も `long long` で受け取ります。文字 `c` は `int` です。
- `s` は `std::string` のほか、`std::vector<int>` などの整数の列でもかまいません (`PalindromicTree<3, 0>` に 0, 1, 2 の列を入れるなど)。
- 頂点は子の番号を `K` 個の配列で持つので、メモリは「頂点数 × (4K + 20) バイト」ほど使います。頂点数は列の長さ + 2 以下です。
- `occurrences()` は、頂点が最長の回文接尾辞になった回数を、suffix link の木で葉の側から足し合わせて求めます。suffix link の先は自分より番号の小さい頂点なので、ほかの値を suffix link の木で集めるときも、番号の大きい順に処理すれば済みます。
- 列の長さ $n$ に対して、異なる回文の個数は $n$ 以下です。

## 例: 回文の部分文字列の個数 (重複を含む)

各位置で終わる回文の個数は、その位置の最長の回文から suffix link をたどって根に着くまでの頂点の数です。頂点ごとに suffix link の木での深さを求めておけば、位置ごとに $O(1)$ で足せます。

```cpp
std::vector<long long> depth(pt.size(), 0);
for (long long v = 2; v < pt.size(); v++) depth[v] = depth[pt.suffix_link(v)] + 1;
long long total = 0;
for (long long i = 0; i < pt.length(); i++) total += depth[pt.longest_suffix(i)];
```

## 関連

- 各位置を中心とする最長の回文の半径は [文字列アルゴリズム](string.hpp) の Manacher のアルゴリズム
- 複数の文字列の接頭辞を扱う木は [Trie](trie.hpp)
