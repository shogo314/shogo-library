# shogo-library

競技プログラミング用の C++ ライブラリです。
[ou-library](https://github.com/shogo314/ou-library) と [sh-library](https://github.com/shogo314/sh-library) を統合したものです。

## ディレクトリ構成

| ディレクトリ | 内容 |
|---|---|
| `base/` | 入出力、型特性、関数オブジェクト、コンテスト用テンプレート (`all` で一括 include) |
| `data_structures/` | セグメント木各種、Union-Find、マージソートツリー、Li Chao Tree など |
| `graph/` | グラフ、木、全方位木 DP、Functional Graph |
| `math/` | modint、行列、形式的冪級数、組み合わせ、数論、多倍長整数 |
| `string/` | Z-algorithm、ローリングハッシュ |
| `geometry/` | 幾何 (ベクトル、凸包など) |
| `others/` | Mo's algorithm |
| `py/` | Python 風の `range` や `repr` |
| `test/` | オンラインジャッジでの検証用テスト |

## 使い方

リポジトリのルートを include パスに追加して、必要なヘッダを include します。

```cpp
#include "data_structures/segtree.hpp"
#include "math/modint.hpp"
```

```sh
g++ -std=c++17 -I /path/to/shogo-library main.cpp
```

## 検証

[online-judge-tools/verification-helper](https://github.com/online-judge-tools/verification-helper) で、`test/` 以下のテストを GitHub Actions 上で検証しています。

- AtCoder のテストケースは Dropbox から取得するため、secrets に `DROPBOX_APP_KEY` / `DROPBOX_APP_SECRET` / `DROPBOX_REFRESH_TOKEN` が必要です。
- yukicoder のテストには `YUKICODER_TOKEN` が必要です。
