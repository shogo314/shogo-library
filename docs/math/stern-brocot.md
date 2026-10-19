---
title: Stern–Brocot 木と連分数
documentation_of: //src/math/stern-brocot.hpp
---

正の有理数を Stern–Brocot 木の頂点とみなして、木の上の道・最小共通祖先・祖先・子孫の範囲を求めます。区間に入る最も単純な分数 (分母が最小の分数) や、分母に上限がある中での最良近似、連分数展開も求められます。すべて `namespace stern_brocot` の関数で、有理数は [有理数](rational.hpp) の `Rational<T>` で受け渡します。

```cpp
using Q = Rational<long long>;
auto path = stern_brocot::encode_path(Q(3, 2));                // { {'R', 1}, {'L', 1}} (1/1 → 2/1 → 3/2)
Q x = stern_brocot::decode_path(path);                         // 3/2
Q m = stern_brocot::lca(Q(3, 2), Q(5, 3));                     // 3/2
Q s = stern_brocot::simplest_between(Q(60, 191), Q(11, 35));   // 71/226 (分母が最小の分数)
auto [lo, hi] = stern_brocot::best_approximation(Q(314159, 100000), 10LL);  // 25/8 と 22/7
auto a = stern_brocot::continued_fraction(Q(415, 93));         // {4, 2, 6, 7}

// 分母 10^9 以下の分数で √2 を挟む 2 つ (pred は小さい側で true の単調な関数)
auto [l, h] = stern_brocot::binary_search(1000000000LL, [](const Q& y) { return y.num() * y.num() <= 2 * y.den() * y.den(); });
// l = {1086679440, 768398401}, h = {768398401, 543339720} ({分子, 分母} の組)
```

Stern–Brocot 木は、根が $1/1$ で、頂点 $x$ の子孫がある開区間 $(l, h)$ を覆う二分木です ($l$、$h$ は $0/1$ や $1/0 = +\infty$ を含む分数)。頂点はその区間の両端の分子どうし・分母どうしを足した分数 (中間数) で、左の子は区間 $(l, x)$、右の子は区間 $(x, h)$ の頂点です。正の有理数はすべて、既約分数としてちょうど 1 回ずつ現れます。

## 関数

`x` などの有理数は `Rational<T>` です。道は、左の子へ進む `'L'` と右の子へ進む `'R'` を連長圧縮した `std::vector<std::pair<char, T>>` で表します。計算量の $N$ は分子・分母の最大値です。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `continued_fraction(x)` | 連分数展開 $[a_0; a_1, \dots, a_n]$ ($x = a_0 + 1/(a_1 + 1/(\dots + 1/a_n))$)。$a_0 = \lfloor x \rfloor$ (負でもよい)、$i \ge 1$ では $a_i \ge 1$、$n \ge 1$ なら $a_n \ge 2$ | $O(\log N)$ |
| `from_continued_fraction(a)` | 連分数 $[a_0; a_1, \dots, a_n]$ が表す有理数。最後の項は 1 でもよい | $O(n + \log N)$ |
| `encode_path(x)` | 根 $1/1$ から $x$ への道 ($x > 0$)。同じ文字は続かず、回数は正 | $O(\log N)$ |
| `decode_path(path)` | 根から道 `path` をたどった頂点。同じ文字が続いても、回数が 0 でもよい | $O(\lvert path \rvert + \log N)$ |
| `depth(x)` | $x$ の深さ (根は 0)。値は道の文字数で、$N$ 程度になることもある | $O(\log N)$ |
| `lca(x, y)` | $x$ と $y$ の最小共通祖先 | $O(\log N)$ |
| `ancestor(x, k)` | $x$ の祖先で深さ $k$ の頂点。$k$ が $x$ の深さより大きいと `std::nullopt` | $O(\log N)$ |
| `range(x)` | $x$ の子孫 ($x$ 自身を含む) が覆う開区間 `{ {下端の分子, 分母}, {上端の分子, 分母}}`。下端が 0 なら `{0, 1}`、上端が $+\infty$ なら `{1, 0}` | $O(\log N)$ |
| `simplest_between(lo, hi, include_lo = false, include_hi = false)` | 区間に入る分数のうち、分母が最小で、その中で分子の絶対値が最小のもの。既定は開区間 $(lo, hi)$ で、`include_lo`・`include_hi` を `true` にするとその端を含める。負の区間や 0 をまたぐ区間でもよい | $O(\log N)$ |
| `best_approximation(x, n)` | 分母が $n$ 以下の分数のうち、$x$ 以下で最大のものと $x$ 以上で最小のもの `{lower, upper}`。$x$ の分母が $n$ 以下なら `{x, x}` | $O(\log N)$ |
| `binary_search(max_den, pred, max_num = nullopt)` | 分母が `max_den` 以下 (`max_num` を渡すと分子も `max_num` 以下) の 0 以上の分数の中での、単調な `pred` の境目。`{ {true の最大の分子, 分母}, {false の最小の分子, 分母} }` を返し、false の側がなければ後ろは `{1, 0}` ($+\infty$) | `pred` を $O(\log N)$ 回 |

- `ancestor` と `best_approximation` の `k`、`n` は `T` 型です。`10LL` のように型を合わせて渡します。
- 区間で分母が最小の分数は 1 つに決まり、その分子も最小になります (Stern–Brocot 木で区間に入る頂点のうち最も浅いもの)。
- `simplest_between` は、ユークリッドの互除法のように整数部分を引いて逆数をとることを繰り返します。掛け算を使わないので、入力の分子・分母が $10^{18}$ 程度でもあふれません。答えの分子・分母も `T` に収まる必要があります。
- `binary_search` の `pred` は `Rational<T>` を受け取り、小さい値で `true`、大きい値で `false` となる単調な関数です。`pred(0)` は `true` である必要があります。`max_num` を渡さないなら、`pred` はどこかで `false` になる必要があります (そうでないと上側へ進み続けて終わりません)。Stern–Brocot 木を根から下り、同じ向きに何歩進めるかを、倍々に進めてから二分探索して決めます。浮動小数点の二分探索と違い、誤差なく境目の分数が求まります。`best_approximation(x, n)` は `pred(y) = (y <= x)` の場合にあたります。
- 道は連分数展開から作ります。$x = [a_0; a_1, \dots, a_n]$ への道は $R^{a_0} L^{a_1} R^{a_2} \cdots$ で、最後の項だけ 1 少なくなります。

## 関連

- 有理数の型は [有理数](rational.hpp)
- 床関数の和は [floor sum](floor-sum.hpp)
