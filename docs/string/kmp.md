---
title: KMP 法
documentation_of: //src/string/kmp.hpp
---

接頭辞関数 (KMP 法の失敗関数) と、それを使った列の検索を $O(n)$ で行います。文字列のほか、`vector` などの列にも使えます (要素は `==` で比べます)。

```cpp
auto pi = prefix_function(std::string("aabaaab"));              // {0, 1, 0, 1, 2, 2, 3}
for (long long pos : kmp_search(std::string("aaaa"), std::string("aa"))) {
    // 0, 1, 2 の順
}
```

- 文字列の周期 (`s[i] == s[i + p]` がすべての i で成り立つ最小の `p`) は `n - pi[n - 1]` です。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `prefix_function(s)` / `prefix_function(begin, end)` | 各 $i$ について、`s[0, i]` (両端を含む) の接頭辞であり接尾辞でもある部分のうち、`s[0, i]` 自身を除いた最長の長さ `pi[i]` を並べた `std::vector<long long>` | $O(n)$ |
| `kmp_search(text, pattern)` | `text` の中で `pattern` が現れる開始位置を昇順に遅延列挙する range。$n$、$m$ は `text`、`pattern` の長さ。`pattern` が空なら $0, 1, \dots, n$ | 構築 $O(m)$、全走査 $O(n + m)$ |

`kmp_search` の入力にはランダムアクセス可能な iterator が必要です。返り値は値を返す input iterator を持つ range で、`size()`・添字アクセス・逆順走査はありません。

構築時にパターンの接頭辞関数を計算し、range が保持します。追加領域は $O(m)$ で、同じ range を繰り返し走査しても前計算はやり直しません。入力 `text` の比較は走査時に行い、途中で `break` すると残りの一致を探しません。空パターンでは、末尾の位置 $n$ も含めた $0, 1, \dots, n$ を返します。

両方の入力について、左辺値はコピーせず参照し、右辺値は range が所有します。表の構築時間は入力のムーブ・コピーのコストを除きます。走査中は range と参照している入力を有効なまま保持し、変更しないでください。`std::string_view` などを渡す場合は、その参照先も有効である必要があります。iterator のコピーは独立して進められます。

一致位置を保存して繰り返し使う場合は、明示的に `vector` に変換します。

```cpp
auto matches = kmp_search(text, pattern);
std::vector<long long> saved(matches.begin(), matches.end());
```

## 関連

- Z-algorithm は [Z-algorithm](z-algorithm.hpp)
- 複数のパターンを同時に探すには [Aho-Corasick](aho-corasick.hpp)
- ワイルドカードを含むパターンの検索は [ワイルドカードつきのパターンマッチング](wildcard-matching.hpp)
