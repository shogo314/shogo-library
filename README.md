# shogo-library

競技プログラミング用の C++ ライブラリです。
[ou-library](https://github.com/shogo314/ou-library) と [sh-library](https://github.com/shogo314/sh-library) を統合したものです。

ドキュメント: <https://shogo314.github.io/shogo-library/>

## ディレクトリ構成

ライブラリ本体は `src/` 以下にあります。

| ディレクトリ | 内容 |
|---|---|
| `src/base/` | コンテスト用テンプレート (型の別名、マクロ、入出力、`chmin` などの汎用関数)。`all` で一括 include。提出サイズを抑えるため最小限にしている |
| `src/utility/` | コンテナ・`vector` 用の関数、二分探索、座標圧縮、ビット演算、型特性、`range`、`repr` (出力をそのままコンストラクタに使える文字列化)。必要なものだけ include する |
| `src/algebra/` | モノイド・群・作用素付きモノイドの定義 |
| `src/data_structures/` | セグメント木各種 (モノイドを渡して使う)、Fenwick Tree、Sparse Table、Union-Find、マージソートツリー、Li Chao Tree (x 座標を先読みしない動的版も)、双対セグメント木、Sliding Window Aggregation (スライド最小値)、削除可能な優先度付きキュー、動的セグメント木 (要素数が大きいもの)、Wavelet Matrix、Cartesian 木、区間の最頻値、FastSet (64 分木による整数の集合)、平衡二分木 (RBST: 列への挿入・削除・区間反転・split/merge)、永続データ構造 (セグメント木・遅延伝搬セグメント木・配列・Union-Find・スタック・キュー) など |
| `src/graph/` | グラフ (最短路、全点対間最短路)、木 (直径、根付き木の同型判定)、全方位木 DP、Functional Graph、強連結成分分解、閉路の検出と復元、最小全域木、彩色数、最大独立集合、三角形の列挙、補グラフの連結成分、lowlink (関節点・橋・二重辺連結成分・二重頂点連結成分・Block-Cut Tree)、2-SAT、最大流、最小費用流、二部マッチング、燃やす埋める (Project Selection)、HL 分解、重心分解、Auxiliary Tree (虚树)、支配木、割当問題 (ハンガリアン法) |
| `src/math/` | modint、mod 演算 (冪乗・逆元・離散対数・平方根)、畳み込み、行列 (連立一次方程式・ランク・特性多項式・任意 mod の行列式)、F2 の行列 (mod 2 の連立一次方程式・逆行列・積)、形式的冪級数 (疎なものの演算も・合成と逆関数・Half-GCD による gcd と多項式を法とする逆元)、線形漸化式 (Bostan-Mori・Berlekamp-Massey)、ラグランジュ補間、Σ r^i f(i)、多点評価・多項式補間 (等比数列の点での chirp-z も)・標本点のずらし、多項式の根、組み合わせ、q 二項係数、分割数・ベルヌーイ数・スターリング数・ベル数・大きい n の階乗、中国剰余定理、素数 (素数判定・素因数分解・篩・原始根・mod p の k 乗根・テトレーション)、素数の個数・素数の和 (Lucy DP)・乗法的関数の和 (min_25 篩)、無限大を持つ整数 (`infint`)、floor sum、商の列挙、有理数、約数・倍数のゼータ変換とメビウス変換 (GCD・LCM 畳み込み)、XOR 基底、ガウス整数と二平方和、Stern–Brocot 木と連分数 (区間で最も単純な分数・最良近似・分母に上限がある分数での二分探索) |
| `src/string/` | Z-algorithm、KMP、Manacher、Lyndon 分解、ワイルドカードつきのパターンマッチング、Suffix Array と LCP 配列、ローリングハッシュ、Trie、Aho-Corasick、Suffix Automaton、回文木 (Eertree) |
| `src/geometry/` | 幾何 (ベクトル、凸包、偏角ソート、ccw、射影・反射、直線の交点、点・線分の距離、円の交点・接線・内接円・外接円など) |
| `src/dp/` | 動的計画法 (ナップサック問題、部分和問題 (判定・S 以下の最大値・復元・個数)、最長増加部分列 (LIS)、連続部分列の和の最大値)、瓶詰め問題、集合の分割 (使ってよい集合に分ける最小個数)、集合の被覆 (包除原理で覆う最小個数)、Monge 性を使う高速化 (monotone minima・(min, +) 畳み込み・Alien DP) |
| `src/others/` | Mo's algorithm、転倒数 |
| `test/` | 検証用テスト。ジャッジごとにディレクトリを分け、その中をサイトでの分類で分けています (`yosupo/` は Library Checker のカテゴリ、`aoj/` はコース名か `volume<番号÷100>`、`atcoder/` は `abc/` とそれ以外、`yukicoder/` は分けない)。`test/unittest/` は問題を使わない単体テストで、`src/` と同じ分類で分けています |
| `docs/` | ドキュメントの各ページに埋め込む機能一覧 (`documentation_of` でヘッダに対応付け) |

## 使い方

`src/` を include パスに追加して、必要なヘッダを include します。

```cpp
#include "data_structures/segtree.hpp"
#include "math/modint.hpp"
```

データ構造には `algebra/` のモノイドを渡します。ラムダ式から作ることもできます。

```cpp
SegTree<monoid::Max<int>> seg(n);
SegTree seg2(v, Monoid([](int a, int b) { return a + b; }, 0));
LazySegTree<acted_monoid::AffineSum<mint>> lseg(v);
```

よく使うものには `RMinQ<S>` (= `SegTree<monoid::Min<S>>`) や `RAddMinQ<S>` (= `LazySegTree<acted_monoid::AddMin<S>>`) などの別名があります。

```sh
g++ -std=c++17 -I /path/to/shogo-library/src main.cpp
```

### 作者の使い方

作者は [cpp_include](https://github.com/shogo314/cpp_include) で管理しています。`update.py` がこのリポジトリの `src/` だけを `cpp_include/shogo-library/` に展開し、`cpp_include` を `CPLUS_INCLUDE_PATH` に設定して、AC Library (`atcoder/`) と並べて使っています。

```cpp
#include <atcoder/all>
#include "shogo-library/math/modint.hpp"
```

## 検証

[online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper) で、`test/` 以下のテストを GitHub Actions 上で検証しています。CI は `ubuntu-24.04` に固定しています。

ライブラリのすべての関数を、CI のテストのどれかから呼ぶようにしています (`test/atcoder/` は数えない)。

- ジャッジの問題 (Library Checker・AOJ・yukicoder) で検証できるものは、問題を解くテストで検証します。同じ問題を別の機能で解き直すテストは `.1`・`.2` のように番号を付けます。
- 合う問題がないものは `test/unittest/` で検証します。問題 (AOJ ITP1_1_A) の入力は使わず、愚直な実装とのランダムな比較や期待値との比較がすべて一致したときだけ `Hello World` を出力します。

- yukicoder のテストには `YUKICODER_TOKEN` が必要です。
- `test/atcoder/` には AtCoder の問題で書いたテストを置いています。AtCoder のテストケースは CI で取得できないため、`*.test.cpp` にせず検証の対象外にしています。手元で `oj` を使って確認できます。
