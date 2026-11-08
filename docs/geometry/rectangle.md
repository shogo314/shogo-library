---
title: 軸に平行な長方形
documentation_of: //src/geometry/rectangle.hpp
---

軸に平行な半開領域 $[left, right) \times [bottom, top)$ を表す `Rectangle<T>` です。整数座標・浮動小数点座標の両方で使えます。

```cpp
Rectangle rect(0LL, 0LL, 3LL, 4LL);  // Rectangle<long long>
long long s = rect.area();           // 12
bool a = rect.contains(0, 0);        // true (左辺・下辺を含む)
bool b = rect.contains(3, 2);        // false (右辺を含まない)
Rectangle r(0.5, -1.0, 2.0, 1.5);   // Rectangle<double>
```

`T` の既定は `long long` です。4 座標を渡すと共通の型を推論します。`left <= right`、`bottom <= top` が必要で、違反すると assert で落ちます。公開メンバを変更するときもこの条件を保ってください。幅または高さが 0 の長方形は空です。

幅・高さ・面積の計算結果は `T` に収まる必要があります。浮動小数点型の比較では誤差を考慮しません。セルの列挙・添字変換・近傍探索には [Grid](../utility/range.hpp) を使います。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Rectangle<T>()` | 全座標が 0 の空の長方形を作る | $O(1)$ |
| `Rectangle(left, bottom, right, top)` | 4 辺の座標から作る | $O(1)$ |
| `width()` / `height()` | 幅 / 高さ (`T`) | $O(1)$ |
| `area()` | 面積 (`T`) | $O(1)$ |
| `empty()` | 幅または高さが 0 か | $O(1)$ |
| `contains(x, y)` / `contains(p)` | 点を含むか。`p` は `Vector<T, 2>`。左辺・下辺を含み、右辺・上辺を含まない | $O(1)$ |
| `a == b` / `a != b` | 4 辺の座標がすべて等しいか / いずれか異なるか。空でも座標を比較する | $O(1)$ |
| `is >> rect` | `left bottom right top` の順に読み込む | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `left` / `right` | 左辺 / 右辺の x 座標 (`T`) |
| `bottom` / `top` | 下辺 / 上辺の y 座標 (`T`) |

## 関連

- 複数の長方形の面積は [長方形の和集合の面積](rectangle-union.hpp)
- 格子の行・列の範囲は [Range と Grid](../utility/range.hpp)
