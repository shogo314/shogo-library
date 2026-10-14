---
title: Suffix Array と LCP 配列
documentation_of: //src/string/suffix-array.hpp
---

接尾辞 `s[i:]` を辞書順に並べたときの開始位置のリスト (Suffix Array) を SA-IS 法で求めます。隣り合う接尾辞の最長共通接頭辞の長さ (LCP 配列) も求められます。

```cpp
std::string s = "abracadabra";
auto sa = suffix_array(s);      // {10, 7, 0, 3, 5, 8, 1, 4, 6, 9, 2}
auto lcp = lcp_array(s, sa);    // {1, 4, 1, 1, 0, 3, 0, 0, 0, 2}
```

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `suffix_array(s)` (`s` は `std::string`) | Suffix Array | $O(n)$ |
| `suffix_array(s, upper)` (`s` は `std::vector<int>`) | 値が $0$ 以上 `upper` 以下の列の Suffix Array | $O(n + \mathrm{upper})$ |
| `suffix_array(s)` (`s` は `std::vector<T>`) | `operator<` で比べられる値の列の Suffix Array。値を座標圧縮してから求める | $O(n \log n)$ |
| `lcp_array(s, sa)` | 長さ $n - 1$ の `lcp`。`lcp[i]` は `s[sa[i]:]` と `s[sa[i + 1]:]` の最長共通接頭辞の長さ (Kasai 法) | $O(n)$ |

`s[sa[i]:]` と `s[sa[j]:]` ($i < j$) の最長共通接頭辞の長さは、`lcp[i], ..., lcp[j - 1]` の最小値です。[Sparse Table](../data_structures/sparse-table.hpp) と組み合わせれば $O(1)$ で求められます。

## 例: 異なる部分文字列の個数

部分文字列は接尾辞の接頭辞なので、全体 $n(n + 1) / 2$ 個から、辞書順で 1 つ前の接尾辞と重なる分を引きます。

```cpp
long long n = s.size(), ans = n * (n + 1) / 2;
for (int h : lcp_array(s, suffix_array(s))) ans -= h;
```

## 関連

- Z-algorithm・KMP・Manacher は [文字列アルゴリズム](string.hpp)
