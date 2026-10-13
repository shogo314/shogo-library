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
| `src/data_structures/` | セグメント木各種 (モノイドを渡して使う)、Fenwick Tree、Sparse Table、Union-Find、マージソートツリー、Li Chao Tree、双対セグメント木、Sliding Window Aggregation (スライド最小値)、削除可能な優先度付きキューなど |
| `src/graph/` | グラフ (最短路、全点対間最短路)、木、全方位木 DP、Functional Graph、強連結成分分解、最小全域木、lowlink (関節点・橋)、2-SAT、最大流、最小費用流、二部マッチング、HL 分解 |
| `src/math/` | modint、行列、形式的冪級数、組み合わせ、数論、素数 (素数判定・素因数分解・篩)、無限大を持つ整数 (`infint`)、floor sum、約数・倍数のゼータ変換とメビウス変換 (GCD・LCM 畳み込み)、XOR 基底 |
| `src/string/` | Z-algorithm、KMP、Manacher、Suffix Array と LCP 配列、ローリングハッシュ |
| `src/geometry/` | 幾何 (ベクトル、凸包、偏角ソートなど) |
| `src/others/` | Mo's algorithm、最長増加部分列 (LIS)、転倒数 |
| `test/` | 検証用テスト (ジャッジごとにディレクトリを分けています。`test/unittest/` は問題を使わない単体テスト) |
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
