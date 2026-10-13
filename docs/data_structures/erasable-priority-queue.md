---
title: 削除可能な優先度付きキュー
documentation_of: //src/data_structures/erasable-priority-queue.hpp
---

任意の要素を削除できる優先度付きキュー `ErasablePriorityQueue<T, Compare = std::less<T>>` です。`std::priority_queue` と同じく、既定では最大の要素を取り出します。

削除する要素を別のヒープに入れておき、それが先頭に来たときに取り除きます。各操作は償却 $O(\log n)$ で、`std::multiset` より定数倍が軽いです。

```cpp
ErasablePriorityQueue<int> pq;                        // 最大を取り出す
ErasablePriorityQueue<int, std::greater<int>> pq2;    // 最小を取り出す
pq.push(3);
pq.push(5);
pq.erase(5);
pq.top();  // 3
```

| 関数 | 説明 |
|---|---|
| `push(x)` | `x` を追加 |
| `erase(x)` | `x` を 1 つ削除。`x` はキューに含まれていること (含まれていない要素を削除すると壊れる) |
| `top()` | 先頭 (既定では最大) の要素 |
| `pop()` | 先頭の要素を削除 |
| `size()`、`empty()` | 要素数、空か |

`Compare` で等しい要素 (`!comp(x, y) && !comp(y, x)`) は区別しません。

最大と最小の両方を取り出したいときは、`std::less` と `std::greater` の 2 つを持ち、片方から取り出した要素をもう片方から `erase` します。

```cpp
ErasablePriorityQueue<int> max_q;
ErasablePriorityQueue<int, std::greater<int>> min_q;
int x = min_q.top();  // 最小を取り出す
min_q.pop();
max_q.erase(x);
```

## 関連

- 値ごとの個数を数える多重集合は [Counter](counter.hpp)
