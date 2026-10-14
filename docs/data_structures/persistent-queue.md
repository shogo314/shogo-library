---
title: 永続キュー
documentation_of: //src/data_structures/persistent-queue.hpp
---

過去の版を残したまま更新できるキューです。`push`・`pop` は元の版を変えずに新しい版を返します。

```cpp
PersistentQueue<int> q0;
auto q1 = q0.push(1).push(2);   // q0 はそのまま
q1.front();                     // 1
auto q2 = q1.pop();
q2.front();                     // 2
q1.front();                     // 1 (q1 もそのまま)

// 版を配列に並べる (クエリ i の後の版を que[i + 1] に置く)
std::vector<PersistentQueue<int>> que(q + 1);
que[i + 1] = que[t + 1].push(x);
```

要素を木の根から末尾へのパスとして持ちます。`pop` は要素数を減らすだけで、`front` は末尾から祖先をたどって求めます。祖先へのジャンプポインタは skew binary の長さで張るので、ノード 1 つあたりのメモリは $O(1)$ で、祖先は $O(\log n)$ でたどれます。

同じキューから作った版はノードを共有します。ノードは削除しないので、メモリは `push` の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentQueue<T>()` | 空のキュー | $O(1)$ |
| `size()` | 要素数 | $O(1)$ |
| `empty()` | 空か | $O(1)$ |
| `front()` | 先頭の要素 | $O(\log n)$ |
| `back()` | 末尾の要素 | $O(1)$ |
| `push(x)` | 末尾に `x` を加えた新しい版を返す | $O(1)$ |
| `pop()` | 先頭を取り除いた新しい版を返す | $O(1)$ |
| `to_vector()` | すべての要素を先頭から順に並べた `std::vector<T>` | $O(n)$ |

$n$ は、これまでに `push` した回数です。

## 関連

- 末尾から取り出すなら [永続スタック](persistent-stack.hpp)
