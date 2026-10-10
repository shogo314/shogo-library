---
title: shogo-library
---

競技プログラミング用の C++ ライブラリです。
ソースコードは [shogo314/shogo-library](https://github.com/shogo314/shogo-library) にあります。

リポジトリのルートを include パスに追加して、必要なヘッダを include します。

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
