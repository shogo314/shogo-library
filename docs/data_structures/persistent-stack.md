---
title: 永続スタック
documentation_of: //src/data_structures/persistent-stack.hpp
---

過去の版を残したまま更新できるスタックです。`push`・`pop` は元の版を変えずに新しい版を返します。ノードを共有する連結リストで、どの操作も $O(1)$ です。

```cpp
PersistentStack<int> s0;
auto s1 = s0.push(1).push(2);   // s0 はそのまま
s1.top();                       // 2
auto s2 = s1.pop();
s2.top();                       // 1
s1.top();                       // 2 (s1 もそのまま)
```

同じスタックから作った版はノードを共有します。ノードは削除しないので、メモリは `push` の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentStack<T>()` | 空のスタック | $O(1)$ |
| `size()` | 要素数 | $O(1)$ |
| `empty()` | 空か | $O(1)$ |
| `top()` | 一番上の要素 | $O(1)$ |
| `push(x)` | `x` を積んだ新しい版を返す | $O(1)$ |
| `pop()` | 一番上を取り除いた新しい版を返す | $O(1)$ |
| `to_vector()` | すべての要素を下から順に並べた `std::vector<T>` | $O(n)$ |

## 関連

- 先頭から取り出すなら [永続キュー](persistent-queue.hpp)
