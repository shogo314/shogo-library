---
title: Cartesian 木
documentation_of: //src/data_structures/cartesian-tree.hpp
---

列 `a` の Cartesian 木を $O(n)$ で作ります。最小の要素を根とし、その左の部分列と右の部分列の Cartesian 木をそれぞれ左と右の子にした二分木です。中間順に並べると元の列になり、区間 $[l, r)$ の最小値の位置は $l$ と $r - 1$ の LCA になります。

```cpp
std::vector<int> a = {3, 1, 4, 1, 5};
auto t = cartesian_tree(a);                        // 最小を根にする
long long r = t.root;                               // 1 (同じ値なら左にあるものが先祖)
long long p = t.parent[2];                          // 3
auto u = cartesian_tree(a, std::greater<int>());    // 最大を根にする
```

同じ値があるときは、左にあるものを先祖にします。

## 関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `cartesian_tree(a, comp = std::less<T>())` | 列 `a` の Cartesian 木 (`CartesianTree`)。`comp` で前に来る要素ほど根に近い | $O(n)$ |

`CartesianTree` は次の 4 つを持ちます。

| 変数 | 説明 |
|---|---|
| `root` | 根 (列が空なら -1) |
| `parent[i]` | 親 (根は -1) |
| `left[i]` | 左の子 (なければ -1) |
| `right[i]` | 右の子 (なければ -1) |

## 関連

- 区間の最小値を $O(1)$ で求めるだけなら [Sparse Table](sparse-table.hpp)
