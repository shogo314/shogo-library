---
title: 半開区間の集合
documentation_of: //src/data_structures/interval-set.hpp
---

半開区間 $[l, r)$ の和集合を、重ならない区間の集合として管理します。区間を追加すると、重なる区間や接する区間は1つにまとめられます。

```cpp
IntervalSet<long long> s;
s.insert(1, 3); s.insert(3, 5); s.insert(7, 9);  // {[1, 5), [7, 9)}
s.erase(2, 4);                                  // {[1, 2), [4, 5), [7, 9)}
s.covered_by(8);                                // [7, 9)
s.covered_by(5);                                // なし (std::nullopt)
```

整数の $a$ 以上 $b$ 以下を表す場合は、$[a, b + 1)$ として追加します。

## メンバ関数

`IntervalSet<T = long long, Compare = std::less<T>>` です。$n$ を区間の個数とします。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `insert(l, r)` | $[l, r)$ を追加 ($l < r$) | ならし $O(\log n)$ |
| `erase(l, r)` | $[l, r)$ を取り除く ($l < r$) | ならし $O(\log n)$ |
| `covered_by(k)` | `k` を含む区間 (`std::optional<std::pair<T, T>>`) | $O(\log n)$ |
| `covered_by(l, r)` | $[l, r)$ を丸ごと含む区間 (`std::optional`) | $O(\log n)$ |
| `size()` | 区間の個数 | $O(1)$ |
| `to_vector()` | 区間の一覧 (左端の昇順) | $O(n)$ |
