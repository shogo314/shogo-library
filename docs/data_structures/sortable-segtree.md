---
title: 区間ソートのできるセグメント木
documentation_of: //src/data_structures/sortable-segtree.hpp
---

各位置にキーと値を持つ列で、1 点の変更・区間の積・区間をキーで並べ替える操作を行います。値は [モノイド](../algebra/monoid.hpp) `M` の要素で、積は列の順番にとります。

```cpp
// キーは 0 以上 2^30 未満で、すべて異なること
SortableSegTree<monoid::Sum<long long>> st(keys, values, 1LL << 30);
st.sort(l, r);              // [l, r) をキーの昇順に並べ替える
st.sort(l, r, true);        // 降順に並べ替える
st.set(i, key, x);          // 位置 i のキーと値を変える
long long s = st.prod(l, r);
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SortableSegTree<M>(keys, values, key_limit, m = M())` | キーと値の列から作る。キーは $0$ 以上 `key_limit` 未満で、すべて異なること | $O(n \log K)$ |
| `size()` | 要素数 | $O(1)$ |
| `set(i, key, x)` | 位置 `i` のキーと値を変える (キーは今あるどのキーとも異なること) | ならし $O(\log K + \log n)$ |
| `prod(l, r)` | `a[l], ..., a[r-1]` の値の積 | ならし $O(\log K + \log n)$ |
| `sort(l, r, reverse = false)` | `[l, r)` をキーの昇順 (`reverse` なら降順) に並べ替える | ならし $O(\log K + \log n)$ |

$K$ は `key_limit` です。メモリは $O((n + q) \log K)$ です。

- 並べ替えた区間ごとに、その要素をキーの二分トライ (動的セグメント木) で持ち、キーの昇順と降順の積をそれぞれ保ちます。区間の先頭の位置に「区間の向きに合わせた積」を置いた [セグメント木](segtree.hpp) で区間の積を求めます。
- 並べ替えはトライの併合、区間の境目はトライを個数で 2 つに分けることで作ります。併合で消えるトライの頂点の数で抑えると、全体でならし $O((n + q) \log K)$ になります。
- `prod` も区間の境目を作るので、`const` ではありません。

## 関連

- 並べ替えがなければ [セグメント木](segtree.hpp)
- 区間の先頭の管理には [FastSet](fast-set.hpp) を使っています
