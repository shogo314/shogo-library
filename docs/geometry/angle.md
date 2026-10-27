---
title: 偏角
documentation_of: //src/geometry/angle.hpp
---

2 次元ベクトル $(x, y)$ の偏角を表す `Angle<T>` です。x 軸正方向を 0 として反時計回りに測り、周回数 `turn` と合わせて $2\pi \cdot \mathrm{turn} + [0, 2\pi)$ の値として比べます。零ベクトルは x 軸正方向と同じ偏角として扱います。外積で比べるので、整数型なら誤差なく比べられます。

```cpp
std::vector<Vector<long long>> ps(n);
std::sort(ps.begin(), ps.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

std::vector<std::array<long long, 2>> qs(n);  // std::array や std::pair からも作れる
std::sort(qs.begin(), qs.end(), [](const auto& a, const auto& b) { return Angle(a) < Angle(b); });

Angle a(1, 1), b(-1, 0);
bool c = a < b;          // true (π/4 < π)
double r = b.radian();   // π

// 偏角が [θ_i, θ_i + π) にある点の数 (円環をまたぐ範囲は 2π を足した写しをつなげて数える)
std::vector<Angle<long long>> as(n);
for (auto& p : as) std::cin >> p;  // x y を読む
std::sort(as.begin(), as.end());
for (int i = 0; i < n; i++) as.push_back(as[i].next_turn());
long long cnt = std::lower_bound(as.begin(), as.end(), as[i].opposite()) - as.begin() - i;  // i 番目の点について

Angle d = Angle(0, 1) - Angle(1, 1);  // π/4 から π/2 へ反時計回りに回す角 (π/4)
```

和と差は複素数の積で求めるので、結果の座標は 2 つの座標の積の大きさになります。座標の絶対値が $10^9$ なら `long long` に収まりますが、その結果どうしを比べるには 4 乗が収まる型 (`__int128` など) が要ります。$\pi$ や $2\pi$ をずらすだけなら、座標が大きくならない `opposite()` と `next_turn()` を使います。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Angle()` / `Angle(x, y, turn = 0)` | 零ベクトル (偏角 0) / ベクトル $(x, y)$ の偏角に $2\pi \cdot \mathrm{turn}$ を足したもの | $O(1)$ |
| `Angle(p)` | `p[0]`、`p[1]` (`Vector<T, 2>`、`std::array<T, 2>` など) か `p.first`、`p.second` (`std::pair<T, T>`) から作る | $O(1)$ |
| `is_zero()` | 零ベクトルか | $O(1)$ |
| `half()` | 周回数を除いた偏角が $[0, \pi)$ なら 0、$[\pi, 2\pi)$ なら 1 | $O(1)$ |
| `radian()` | 偏角をラジアンで返す (`double`、$2\pi \cdot \mathrm{turn} + [0, 2\pi)$) | $O(1)$ |
| `next_turn()` | $2\pi$ を足した偏角 | $O(1)$ |
| `opposite()` | $\pi$ を足した偏角 (逆向きのベクトル)。零ベクトルは assert で落ちる | $O(1)$ |
| `-a` | 符号を反転した偏角 (x 軸について折り返したベクトル) | $O(1)$ |
| `a + b`、`a - b`、`+=`、`-=` | 偏角の和・差。`b - a` は a から b へ反時計回りに回す角。零ベクトルは偏角 0 として扱う | $O(1)$ |
| `<`、`<=`、`>`、`>=`、`==`、`!=` | 周回数を含めた偏角で比べる。`==` は偏角が等しいか (向きが同じなら長さが違っても等しい) | $O(1)$ |
| `is >> a` / `os << a` | `x y` を読む (周回数は 0 にする) / 書く (周回数は書かない) | $O(1)$ |

## メンバ変数

| 変数 | 説明 |
|---|---|
| `x` / `y` | ベクトルの座標 |
| `turn` | 周回数 (既定は 0) |

外積を計算するので、座標の絶対値の 2 乗が `T` に収まる必要があります。

## 関連

- 点・ベクトルとその他の幾何の関数は [幾何ベクトル](vector.hpp)
