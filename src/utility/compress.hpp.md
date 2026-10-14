---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/dsl-4-a.2.test.cpp
    title: test/aoj/dsl-4-a.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/compress.test.cpp
    title: test/unittest/compress.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle-sum.3.test.cpp
    title: test/yosupo/rectangle-sum.3.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E"
    links: []
  bundledCode: "#line 2 \"src/utility/compress.hpp\"\n\n/**\n * @file compress.hpp\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n */\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @brief \u5EA7\u6A19\u5727\u7E2E\n *\n * \u5024\u3092\
    \ add \u3067\u767B\u9332\u3057\u3001build \u3067\u30BD\u30FC\u30C8\u3068\u91CD\
    \u8907\u9664\u53BB\u3092\u3057\u3066\u304B\u3089\u4F7F\u3046\n * \u4F8B:\n * Compress<long\
    \ long> cp(A);  // A \u3092\u767B\u9332\u3057\u3066 build \u307E\u3067\u884C\u3046\
    \n * long long i = cp.id(A[0]);  // 0 <= i < cp.size()\n *\n * @tparam T \u5024\
    \u306E\u578B (< \u3067\u6BD4\u8F03\u3067\u304D\u308B\u3053\u3068)\n */\ntemplate\
    \ <typename T>\nclass Compress {\n    std::vector<T> xs;\n    bool built = false;\n\
    \n   public:\n    Compress() = default;\n    /**\n     * @brief v \u306E\u5024\
    \u3092\u767B\u9332\u3057\u3066 build \u3059\u308B\n     */\n    explicit Compress(const\
    \ std::vector<T>& v) : xs(v) { build(); }\n\n    /**\n     * @brief \u5024\u3092\
    \ 1 \u3064\u767B\u9332\u3059\u308B\u3002build \u306E\u524D\u306B\u547C\u3076\n\
    \     */\n    void add(const T& x) {\n        assert(!built);\n        xs.push_back(x);\n\
    \    }\n    /**\n     * @brief v \u306E\u5024\u3092\u3059\u3079\u3066\u767B\u9332\
    \u3059\u308B\u3002build \u306E\u524D\u306B\u547C\u3076\n     */\n    void add(const\
    \ std::vector<T>& v) {\n        assert(!built);\n        xs.insert(xs.end(), v.begin(),\
    \ v.end());\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024\u3092\
    \u30BD\u30FC\u30C8\u3057\u3066\u91CD\u8907\u3092\u9664\u304F O(n log n)\n    \
    \ */\n    void build() {\n        assert(!built);\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        built = true;\n    }\n\n    /**\n     * @brief \u7570\u306A\u308B\u5024\
    \u306E\u500B\u6570\n     */\n    long long size() const {\n        assert(built);\n\
    \        return xs.size();\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\
    \u5024 x \u306E\u756A\u53F7 O(log n)\u3002\u767B\u9332\u3057\u3066\u3044\u306A\
    \u3044\u5024\u306A\u3089 assert \u3067\u843D\u3061\u308B\n     */\n    long long\
    \ id(const T& x) const {\n        const long long i = bisect_left(x);\n      \
    \  assert(i < size() && !(x < xs[i]));\n        return i;\n    }\n    /**\n  \
    \   * @brief x \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log\
    \ n)\u3002\u306A\u3051\u308C\u3070 size()\n     */\n    long long bisect_left(const\
    \ T& x) const {\n        assert(built);\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n    /**\n     * @brief x \u3088\u308A\u5927\
    \u304D\u3044\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\
    \u308C\u3070 size()\n     */\n    long long bisect_right(const T& x) const {\n\
    \        assert(built);\n        return std::upper_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n    }\n    /**\n     * @brief x \u3092\u767B\u9332\u3057\u305F\
    \u304B O(log n)\n     */\n    bool contains(const T& x) const {\n        const\
    \ long long i = bisect_left(x);\n        return i < size() && !(x < xs[i]);\n\
    \    }\n    /**\n     * @brief \u756A\u53F7 i \u306E\u5024\n     */\n    const\
    \ T& operator[](long long i) const {\n        assert(built && 0 <= i && i < size());\n\
    \        return xs[i];\n    }\n    /**\n     * @brief v \u306E\u5404\u5024\u3092\
    \u756A\u53F7\u306B\u7F6E\u304D\u63DB\u3048\u305F\u5217\n     */\n    std::vector<long\
    \ long> ids(const std::vector<T>& v) const {\n        std::vector<long long> res(v.size());\n\
    \        for (long long i = 0; i < (long long)v.size(); i++) res[i] = id(v[i]);\n\
    \        return res;\n    }\n    /**\n     * @brief \u30BD\u30FC\u30C8\u6E08\u307F\
    \u3067\u91CD\u8907\u306E\u306A\u3044\u5024\u306E\u5217\n     */\n    const std::vector<T>&\
    \ values() const {\n        assert(built);\n        return xs;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file compress.hpp\n * @brief \u5EA7\u6A19\u5727\u7E2E\
    \n */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\n/**\n\
    \ * @brief \u5EA7\u6A19\u5727\u7E2E\n *\n * \u5024\u3092 add \u3067\u767B\u9332\
    \u3057\u3001build \u3067\u30BD\u30FC\u30C8\u3068\u91CD\u8907\u9664\u53BB\u3092\
    \u3057\u3066\u304B\u3089\u4F7F\u3046\n * \u4F8B:\n * Compress<long long> cp(A);\
    \  // A \u3092\u767B\u9332\u3057\u3066 build \u307E\u3067\u884C\u3046\n * long\
    \ long i = cp.id(A[0]);  // 0 <= i < cp.size()\n *\n * @tparam T \u5024\u306E\u578B\
    \ (< \u3067\u6BD4\u8F03\u3067\u304D\u308B\u3053\u3068)\n */\ntemplate <typename\
    \ T>\nclass Compress {\n    std::vector<T> xs;\n    bool built = false;\n\n  \
    \ public:\n    Compress() = default;\n    /**\n     * @brief v \u306E\u5024\u3092\
    \u767B\u9332\u3057\u3066 build \u3059\u308B\n     */\n    explicit Compress(const\
    \ std::vector<T>& v) : xs(v) { build(); }\n\n    /**\n     * @brief \u5024\u3092\
    \ 1 \u3064\u767B\u9332\u3059\u308B\u3002build \u306E\u524D\u306B\u547C\u3076\n\
    \     */\n    void add(const T& x) {\n        assert(!built);\n        xs.push_back(x);\n\
    \    }\n    /**\n     * @brief v \u306E\u5024\u3092\u3059\u3079\u3066\u767B\u9332\
    \u3059\u308B\u3002build \u306E\u524D\u306B\u547C\u3076\n     */\n    void add(const\
    \ std::vector<T>& v) {\n        assert(!built);\n        xs.insert(xs.end(), v.begin(),\
    \ v.end());\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\u5024\u3092\
    \u30BD\u30FC\u30C8\u3057\u3066\u91CD\u8907\u3092\u9664\u304F O(n log n)\n    \
    \ */\n    void build() {\n        assert(!built);\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \        built = true;\n    }\n\n    /**\n     * @brief \u7570\u306A\u308B\u5024\
    \u306E\u500B\u6570\n     */\n    long long size() const {\n        assert(built);\n\
    \        return xs.size();\n    }\n    /**\n     * @brief \u767B\u9332\u3057\u305F\
    \u5024 x \u306E\u756A\u53F7 O(log n)\u3002\u767B\u9332\u3057\u3066\u3044\u306A\
    \u3044\u5024\u306A\u3089 assert \u3067\u843D\u3061\u308B\n     */\n    long long\
    \ id(const T& x) const {\n        const long long i = bisect_left(x);\n      \
    \  assert(i < size() && !(x < xs[i]));\n        return i;\n    }\n    /**\n  \
    \   * @brief x \u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log\
    \ n)\u3002\u306A\u3051\u308C\u3070 size()\n     */\n    long long bisect_left(const\
    \ T& x) const {\n        assert(built);\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n    /**\n     * @brief x \u3088\u308A\u5927\
    \u304D\u3044\u6700\u5C0F\u306E\u5024\u306E\u756A\u53F7 O(log n)\u3002\u306A\u3051\
    \u308C\u3070 size()\n     */\n    long long bisect_right(const T& x) const {\n\
    \        assert(built);\n        return std::upper_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin();\n    }\n    /**\n     * @brief x \u3092\u767B\u9332\u3057\u305F\
    \u304B O(log n)\n     */\n    bool contains(const T& x) const {\n        const\
    \ long long i = bisect_left(x);\n        return i < size() && !(x < xs[i]);\n\
    \    }\n    /**\n     * @brief \u756A\u53F7 i \u306E\u5024\n     */\n    const\
    \ T& operator[](long long i) const {\n        assert(built && 0 <= i && i < size());\n\
    \        return xs[i];\n    }\n    /**\n     * @brief v \u306E\u5404\u5024\u3092\
    \u756A\u53F7\u306B\u7F6E\u304D\u63DB\u3048\u305F\u5217\n     */\n    std::vector<long\
    \ long> ids(const std::vector<T>& v) const {\n        std::vector<long long> res(v.size());\n\
    \        for (long long i = 0; i < (long long)v.size(); i++) res[i] = id(v[i]);\n\
    \        return res;\n    }\n    /**\n     * @brief \u30BD\u30FC\u30C8\u6E08\u307F\
    \u3067\u91CD\u8907\u306E\u306A\u3044\u5024\u306E\u5217\n     */\n    const std::vector<T>&\
    \ values() const {\n        assert(built);\n        return xs;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/utility/compress.hpp
  requiredBy: []
  timestamp: '2026-10-15 07:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/compress.test.cpp
  - test/aoj/dsl-4-a.2.test.cpp
  - test/yosupo/rectangle-sum.3.test.cpp
documentation_of: src/utility/compress.hpp
layout: document
title: "\u5EA7\u6A19\u5727\u7E2E"
---

値を 0 から始まる番号に置き換える `Compress<T>` です。`T` は `<` で比較できる型 (整数、文字列、`std::pair` など) です。

```cpp
Compress<long long> cp(A);         // A の値を登録して build まで行う
long long i = cp.id(A[0]);         // A[0] の番号 (0 <= i < cp.size())
long long v = cp[i];               // 番号から元の値
std::vector<long long> B = cp.ids(A);  // A の各値を番号に置き換えた列

Compress<long long> cq;            // 複数の列やクエリの値をまとめて登録する場合
cq.add(A);
cq.add(x);
cq.build();
long long l = cq.bisect_left(d), r = cq.bisect_left(u);  // 値が [d, u) の範囲は番号 [l, r)
```

値をすべて登録してから `build` を呼び、そのあとで番号を求めます。`build` の後に `add` したり、`build` の前に番号を求めたりすると assert で落ちます。

## メンバ関数

$n$ は登録した値の個数、$m$ は渡した列の長さです。番号と個数は `long long` で返します。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Compress()` | 空で作る。`add` で値を登録してから `build` する | $O(1)$ |
| `Compress(v)` | `v` の値を登録して `build` する | $O(n \log n)$ |
| `add(x)` / `add(v)` | 値を 1 つ / 列の値をすべて登録する | $O(1)$ / $O(m)$ |
| `build()` | 登録した値をソートして重複を除く | $O(n \log n)$ |
| `size()` | 異なる値の個数 | $O(1)$ |
| `id(x)` | 値 `x` の番号。登録していない値なら assert で落ちる | $O(\log n)$ |
| `bisect_left(x)` | `x` 以上で最小の値の番号 (なければ `size()`) | $O(\log n)$ |
| `bisect_right(x)` | `x` より大きい最小の値の番号 (なければ `size()`) | $O(\log n)$ |
| `contains(x)` | `x` を登録したか | $O(\log n)$ |
| `cp[i]` | 番号 `i` の値 | $O(1)$ |
| `ids(v)` | `v` の各値を番号に置き換えた列 | $O(m \log n)$ |
| `values()` | ソート済みで重複のない値の列 (参照を返す) | $O(1)$ |

`id` と `bisect_left` の違いに注意してください。圧縮に含めた値の番号は `id` で求めると、登録し忘れた値に気づけます。クエリの範囲の端のように、登録していない値で境界を求めるときは `bisect_left` / `bisect_right` を使います。

## 関連

- `vector` のソートと重複除去だけなら [vector に対する関数](vector_func.hpp) の `unique(v)`、番号を求めるだけなら [コンテナに対する関数](container_func.hpp) の `bisect_left(v, x)`
