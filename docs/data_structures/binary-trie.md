---
title: Binary Trie
documentation_of: //src/data_structures/binary-trie.hpp
---

$d$ ビットの符号なし整数の多重集合を管理する Binary Trie `BinaryTrie<d, T = unsigned long long>` です。全要素への xor の作用ができます。

```cpp
BinaryTrie<30> bt;
bt.insert(5); bt.insert(3); bt.insert(3); bt.insert(10);
bt.count(3);         // 2
bt.nth_element(0);   // 3 (最小値)
bt.apply_xor(6);     // {5, 5, 3, 12}
bt.nth_element(0);   // 3 (x との xor の最小値は apply_xor(x) してから nth_element(0))
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `insert(x)` | `x` を 1 個追加 | $O(d)$ |
| `erase(x)` | `x` をすべて削除 (なければ何もしない) | $O(d)$ |
| `erase_one_element(x)` | `x` を 1 個削除 (なければ何もしない) | $O(d)$ |
| `count(x)` | `x` の個数 | $O(d)$ |
| `size()` | 要素数 | $O(1)$ |
| `nth_element(k)` | 小さい方から `k` 番目 (0-indexed) の値 | $O(d)$ |
| `bisect_left(x)` | `x` 未満の要素の個数 (`x` 以上の最小の要素が何番目か。なければ `size()`) | $O(d)$ |
| `bisect_right(x)` | `x` 以下の要素の個数 (`x` より大きい最小の要素が何番目か。なければ `size()`) | $O(d)$ |
| `apply_xor(x)` | 全要素を `x` と xor する | $O(1)$ |
| `clear()` | 全要素を削除してメモリを解放 | ノード数に比例 |

## 関連

- XOR で作れる値の集合は [XOR 基底](../math/xor-basis.hpp)
- 文字列の Trie は [Trie](../string/trie.hpp)
