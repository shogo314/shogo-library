# shogo-library

競技プログラミング用の C++ ライブラリです。
[ou-library](https://github.com/shogo314/ou-library) と [sh-library](https://github.com/shogo314/sh-library) を統合したものです。

## ディレクトリ構成

ライブラリ本体は `src/` 以下にあります。

| ディレクトリ | 内容 |
|---|---|
| `src/base/` | 入出力、型特性、`range`、`repr` (出力をそのままコンストラクタに使える文字列化)、コンテスト用テンプレート (`all` で一括 include) |
| `src/algebra/` | モノイド・群・作用素付きモノイドの定義 |
| `src/data_structures/` | セグメント木各種 (モノイドを渡して使う)、Union-Find、マージソートツリー、Li Chao Tree など |
| `src/graph/` | グラフ、木、全方位木 DP、Functional Graph |
| `src/math/` | modint、行列、形式的冪級数、組み合わせ、数論、多倍長整数 |
| `src/string/` | Z-algorithm、ローリングハッシュ |
| `src/geometry/` | 幾何 (ベクトル、凸包など) |
| `src/others/` | Mo's algorithm |
| `test/` | オンラインジャッジでの検証用テスト (ジャッジごとにディレクトリを分けています) |

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

```sh
g++ -std=c++17 -I /path/to/shogo-library/src main.cpp
```

## 検証

[online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper) で、`test/` 以下のテストを GitHub Actions 上で検証しています。

- yukicoder のテストには `YUKICODER_TOKEN` が必要です。
- `test/atcoder/` には AtCoder の問題で書いたテストを置いています。AtCoder のテストケースは CI で取得できないため、`*.test.cpp` にせず検証の対象外にしています。手元で `oj` を使って確認できます。
