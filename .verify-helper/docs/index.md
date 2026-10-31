競技プログラミング用の C++ ライブラリです。
ソースコードは [shogo314/shogo-library](https://github.com/shogo314/shogo-library) にあります。

`src/` を include パスに追加して、必要なヘッダを include します。

```cpp
#include "data_structures/segtree.hpp"
#include "math/modint.hpp"
```

C++17 以上の GNU 拡張つき (`-std=gnu++17` など。AtCoder の GCC と同じ) で使うことを前提にしています。`__int128` を整数型として扱うところがあるので、`-std=c++17` のような厳密な規格モードではコンパイルできないことがあります。

`using namespace std;` は使わないでください。このライブラリには `sort`・`max`・`rank` など std と同じ名前のグローバル関数があり、`using namespace std;` があると呼び出しが曖昧になってコンパイルできないことがあります。std のものは `std::` を付けて書きます。

データ構造には `algebra/` のモノイドを渡します。ラムダ式から作ることもできます。

```cpp
SegTree<monoid::Max<int>> seg(n);
SegTree seg2(v, Monoid([](int a, int b) { return a + b; }, 0));
LazySegTree<acted_monoid::AffineSum<mint>> lseg(v);
```
