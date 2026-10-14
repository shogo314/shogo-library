---
title: 永続配列
documentation_of: //src/data_structures/persistent-array.hpp
---

過去の版を残したまま更新できる配列です。`set` は元の版を変えずに新しい版を返し、新しく作るノードは $O(\log n)$ 個です。版のコピーは $O(1)$ です。

```cpp
PersistentArray<int> a0(n, -1);
auto a1 = a0.set(3, 10);   // a0 はそのまま
a1[3];                     // 10
a0[3];                     // -1
auto a2 = a0.copy(a1, 2, 5);  // [2, 5) を a1 の値にした版
```

`copy(other, l, r)` の `other` は、自身と同じ配列 (同じコンストラクタの呼び出しから更新して作った版) でなければなりません。ノードを共有するので、区間の長さによらず $O(\log n)$ です。

同じ配列から作った版はノードを共有します。ノードは削除しないので、メモリは更新の回数に比例して増えます。`get` は参照ではなく値を返します。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentArray<T>(n, x = T())` | 要素数 `n`、すべて `x` で初期化 (同じ値の部分木を共有する) | $O(\log n)$ |
| `PersistentArray(v)` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `a[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目を `x` にした新しい版を返す | $O(\log n)$ |
| `copy(other, l, r)` | 区間 $[l, r)$ を `other` の値にした新しい版を返す | $O(\log n)$ |
| `to_vector()` | すべての要素を並べた `std::vector<T>` | $O(n \log n)$ |
| `os << a` | 全要素を空白区切りで出力 | $O(n \log n)$ |

## 関連

- 区間の積も必要なら [永続セグメント木](persistent-segtree.hpp)
- これを使った [永続UnionFind](persistent-unionfind.hpp)
