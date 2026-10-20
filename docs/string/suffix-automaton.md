---
title: Suffix Automaton
documentation_of: //src/string/suffix-automaton.hpp
---

文字列のすべての部分文字列を受理する最小の決定性オートマトンです。状態は $2n - 1$ 個以下で、各状態は「出現する終わりの位置の集合 (endpos) が同じ部分文字列」の集まりを表します。異なる部分文字列の個数、部分文字列の判定、出現回数、別の文字列との最長共通部分文字列を求められます。末尾に 1 文字ずつ追加することもできます。

```cpp
SuffixAutomaton<26, 'a'> sa(std::string("abcbc"));
sa.count_distinct_substrings();  // 12
sa.contains(std::string("cb"));  // true
sa.count_occurrences(std::string("bc"));  // 2
sa.extend('a');                  // 末尾に 'a' を追加して "abcbca" にする

// t の各位置で終わる接尾辞のうち、部分文字列である最長の長さ。最大値が最長共通部分文字列の長さ
auto ml = sa.match_lengths(std::string("cbx"));  // {1, 2, 0}
```

- 文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。英小文字なら `SuffixAutomaton<26, 'a'>`、$0$ 以上 $K$ 未満の整数の列なら `SuffixAutomaton<K, 0>` です。
- 遷移は大きさ $K$ の配列で持ちます。$O(1)$ でたどれる代わりに、メモリは状態数 $\times K$ に比例します。文字の種類が多いときは座標圧縮してから渡します。
- 初期状態 (空文字列) は 0 です。状態 $v$ の部分文字列は、長さが `len(link(v)) + 1` 以上 `len(v)` 以下の、`len(v)` の部分文字列の接尾辞たちです。

## メンバ関数

状態・長さ・個数は `long long` です。$n$ は文字列の長さです。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SuffixAutomaton()` | 空文字列 | $O(K)$ |
| `SuffixAutomaton(s)` | 列 `s` (`std::string` や `std::vector<int>` など) | $O(nK)$ |
| `extend(c)` | 末尾に文字 `c` を追加する | ならし $O(K)$ |
| `size()` | 状態の個数 (初期状態を含む) | $O(1)$ |
| `length()` | 文字列の長さ | $O(1)$ |
| `last_state()` | 文字列全体に対応する状態 | $O(1)$ |
| `len(v)` | 状態 `v` の最長の部分文字列の長さ | $O(1)$ |
| `link(v)` | 状態 `v` の suffix link (初期状態なら -1) | $O(1)$ |
| `next(v, c)` | 状態 `v` から文字 `c` で進んだ状態 (なければ -1) | $O(1)$ |
| `count_distinct_substrings()` | 異なる部分文字列の個数 (空文字列を除く) | $O(n)$ |
| `find(t)` | `t` に対応する状態 (部分文字列でなければ -1) | $O(\lvert t \rvert)$ |
| `contains(t)` | `t` が部分文字列か (空文字列は部分文字列) | $O(\lvert t \rvert)$ |
| `occurrences(v)` | 状態 `v` の部分文字列が出現する回数 (endpos の大きさ。初期状態なら $n + 1$) | 初回と `extend` の後は $O(n)$、ほかは $O(1)$ |
| `count_occurrences(t)` | `t` が出現する回数 (重なってもよい。空文字列なら $n + 1$) | $O(\lvert t \rvert)$ (+ `occurrences` の計算) |
| `match_lengths(t)` | `t` の各位置 $i$ について、`t[0, i]` の接尾辞のうち部分文字列であるものの最長の長さ (`std::vector<long long>`)。範囲外の文字はどの部分文字列にも含まれない文字として扱う | $O(\lvert t \rvert)$ |

出現回数は、複製でない状態にそれぞれ 1 つの終わりの位置を割り当て、suffix link の木で子孫の分を足し合わせて求めます。

`match_lengths` は、`t` を 1 文字ずつ読みながら、今の位置で終わる部分文字列の最長のものを状態と長さで持ちます。次の文字で進めなければ suffix link をたどって前を削ります。同じ状態の文字列は endpos が同じで次に続ける文字も同じなので、削るのは endpos が増える長さまでまとめて飛ばせます。1 つの文字列 `s` を固定して多くの `t` との最長共通部分文字列を求める場合などに、`s` の Suffix Automaton を 1 回作れば、各 `t` に $O(\lvert t \rvert)$ で答えられます。

## 関連

- 接尾辞を辞書順に並べるなら [Suffix Array](suffix-array.hpp)
- 2 つの文字列の最長共通部分文字列の位置まで求めるなら [最長共通部分文字列](longest-common-substring.hpp)
- 複数のパターンをまとめて探すなら [Aho-Corasick](aho-corasick.hpp)
