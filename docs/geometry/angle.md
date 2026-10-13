---
title: 偏角
documentation_of: //src/geometry/angle.hpp
---

2 次元ベクトル $(x, y)$ の偏角を表す `Angle<T>` です。x 軸正方向を 0 として反時計回りに $[0, 2\pi)$ で比べます。零ベクトルは x 軸正方向と同じ偏角として扱います。外積で比べるので、整数型なら誤差なく比べられます。

```cpp
std::vector<Vector<long long>> ps(n);
std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

std::vector<std::array<long long, 2>> qs(n);  // std::array や std::pair からも作れる
std::sort(qs.begin(), qs.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

Angle a(1, 1), b(-1, 0);
bool c = a < b;          // true (π/4 < π)
double r = b.radian();   // π
```

## メンバ

| メンバ | 説明 | 計算量 |
|---|---|---|
| `Angle()` / `Angle(x, y)` | 零ベクトル (偏角 0) / ベクトル $(x, y)$ の偏角 | $O(1)$ |
| `Angle(p)` | `p[0]`、`p[1]` (`Vector<T, 2>`、`std::array<T, 2>` など) か `p.first`、`p.second` (`std::pair<T, T>`) から作る | $O(1)$ |
| `x` / `y` | 座標 | |
| `is_zero()` | 零ベクトルか | $O(1)$ |
| `half()` | 偏角が $[0, \pi)$ なら 0、$[\pi, 2\pi)$ なら 1 | $O(1)$ |
| `radian()` | 偏角を $[0, 2\pi)$ のラジアンで返す (`double`) | $O(1)$ |
| `<`、`<=`、`>`、`>=`、`==`、`!=` | 偏角で比べる。`==` は偏角が等しいか (向きが同じなら長さが違っても等しい) | $O(1)$ |

外積を計算するので、座標の絶対値の 2 乗が `T` に収まる必要があります。

## 関連

- 点・ベクトルとその他の幾何の関数は [幾何ベクトル](vector.hpp)
