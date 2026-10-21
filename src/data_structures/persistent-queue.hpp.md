---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/data_structures/persistent-queue.test.cpp
    title: test/unittest/data_structures/persistent-queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/data_structure/persistent-queue.test.cpp
    title: test/yosupo/data_structure/persistent-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C38\u7D9A\u30AD\u30E5\u30FC"
    links: []
  bundledCode: "#line 2 \"src/data_structures/persistent-queue.hpp\"\n\n/**\n * @file\
    \ persistent-queue.hpp\n * @brief \u6C38\u7D9A\u30AD\u30E5\u30FC\n */\n\n#include\
    \ <cassert>\n#include <memory>\n#include <utility>\n#include <vector>\n\n/**\n\
    \ * @brief \u6C38\u7D9A\u30AD\u30E5\u30FC\n *\n * \u66F4\u65B0\u3059\u308B\u3068\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\u306F\u5909\
    \u308F\u3089\u306A\u3044\u3002\u540C\u3058\u30AD\u30E5\u30FC\u304B\u3089\u4F5C\
    \u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\n * \u8981\
    \u7D20\u3092\u6728\u306E\u6839\u304B\u3089\u672B\u5C3E\u3078\u306E\u30D1\u30B9\
    \u3068\u3057\u3066\u6301\u3061\u3001\u5148\u982D\u306F\u30B8\u30E3\u30F3\u30D7\
    \u30DD\u30A4\u30F3\u30BF\u3067\u7956\u5148\u3092\u305F\u3069\u3063\u3066\u6C42\
    \u3081\u308B\n * \u4F8B:\n * PersistentQueue<int> q0;\n * auto q1 = q0.push(1).push(2);\
    \  // q0 \u306F\u305D\u306E\u307E\u307E\n * q1.front();                    //\
    \ 1\n * q1.pop().front();              // 2\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n */\ntemplate <typename T>\nclass PersistentQueue {\n    // \u3059\u3079\
    \u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\
    \u30C9\u306F\u524A\u9664\u3057\u306A\u3044\u3002\u30CE\u30FC\u30C9 0 \u306F\u6839\
    \ (\u8981\u7D20\u3092\u6301\u305F\u306A\u3044)\n    struct Pool {\n        std::vector<T>\
    \ val;\n        std::vector<int> parent, jump, depth;\n        Pool() : val(1),\
    \ parent{0}, jump{0}, depth{0} {}\n        int make_node(const T& x, int p) {\n\
    \            // \u30B8\u30E3\u30F3\u30D7\u306E\u9577\u3055\u304C 1, 1, 3, 1, 1,\
    \ 3, 7, ... (skew binary) \u306B\u306A\u308B\u3088\u3046\u306B\u5F35\u308B\n \
    \           int j = jump[p];\n            int nj = depth[p] - depth[j] == depth[j]\
    \ - depth[jump[j]] ? jump[j] : p;\n            val.push_back(x);\n           \
    \ parent.push_back(p);\n            jump.push_back(nj);\n            depth.push_back(depth[p]\
    \ + 1);\n            return static_cast<int>(val.size()) - 1;\n        }\n   \
    \     // t \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C d \u306E\u3082\u306E\n \
    \       int ancestor(int t, int d) const {\n            while (depth[t] > d) t\
    \ = depth[jump[t]] >= d ? jump[t] : parent[t];\n            return t;\n      \
    \  }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u4E00\u5EA6\u3082 push \u3057\
    \u3066\u3044\u306A\u3051\u308C\u3070 nullptr\n    int back_node, n;          \
    \  // \u8981\u7D20\u306F back_node \u304B\u3089 n \u500B\u4E0A\u307E\u3067\u306E\
    \u30CE\u30FC\u30C9\n\n    PersistentQueue(std::shared_ptr<Pool> pool, int back_node,\
    \ int n) : pool(std::move(pool)), back_node(back_node), n(n) {}\n\n   public:\n\
    \    /**\n     * @brief \u7A7A\u306E\u30AD\u30E5\u30FC\u3092\u4F5C\u308B\n   \
    \  */\n    PersistentQueue() : pool(nullptr), back_node(0), n(0) {}\n\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size()\
    \ const { return n; }\n    /**\n     * @brief \u7A7A\u304B\u3069\u3046\u304B\u3092\
    \u8FD4\u3059\n     */\n    bool empty() const { return n == 0; }\n\n    /**\n\
    \     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\n     */\n   \
    \ T front() const {\n        assert(!empty());\n        return pool->val[pool->ancestor(back_node,\
    \ pool->depth[back_node] - n + 1)];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306E\u8981\u7D20\u3092\u8FD4\u3059\n     */\n    T back() const {\n        assert(!empty());\n\
    \        return pool->val[back_node];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306Bx\u3092\u52A0\u3048\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param x \u52A0\u3048\u308B\u5024\n     * @return PersistentQueue\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n\
    \     */\n    PersistentQueue push(const T& x) const {\n        std::shared_ptr<Pool>\
    \ p = pool ? pool : std::make_shared<Pool>();\n        int t = p->make_node(x,\
    \ back_node);\n        return PersistentQueue(std::move(p), t, n + 1);\n    }\n\
    \    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u53D6\u308A\u9664\
    \u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @return\
    \ PersistentQueue \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\
    \u306A\u3044)\n     */\n    PersistentQueue pop() const {\n        assert(!empty());\n\
    \        return PersistentQueue(pool, back_node, n - 1);\n    }\n\n    /**\n \
    \    * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5148\u982D\u304B\u3089\
    \u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<T>\
    \ to_vector() const {\n        std::vector<T> res(n);\n        int t = back_node;\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            res[i] = pool->val[t];\n\
    \            t = pool->parent[t];\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file persistent-queue.hpp\n * @brief \u6C38\u7D9A\
    \u30AD\u30E5\u30FC\n */\n\n#include <cassert>\n#include <memory>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u6C38\u7D9A\u30AD\u30E5\u30FC\n *\n * \u66F4\
    \u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\
    \u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u30AD\u30E5\
    \u30FC\u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\
    \u6709\u3059\u308B\n * \u8981\u7D20\u3092\u6728\u306E\u6839\u304B\u3089\u672B\u5C3E\
    \u3078\u306E\u30D1\u30B9\u3068\u3057\u3066\u6301\u3061\u3001\u5148\u982D\u306F\
    \u30B8\u30E3\u30F3\u30D7\u30DD\u30A4\u30F3\u30BF\u3067\u7956\u5148\u3092\u305F\
    \u3069\u3063\u3066\u6C42\u3081\u308B\n * \u4F8B:\n * PersistentQueue<int> q0;\n\
    \ * auto q1 = q0.push(1).push(2);  // q0 \u306F\u305D\u306E\u307E\u307E\n * q1.front();\
    \                    // 1\n * q1.pop().front();              // 2\n *\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n */\ntemplate <typename T>\nclass PersistentQueue\
    \ {\n    // \u3059\u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\
    \u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\u3002\u30CE\
    \u30FC\u30C9 0 \u306F\u6839 (\u8981\u7D20\u3092\u6301\u305F\u306A\u3044)\n   \
    \ struct Pool {\n        std::vector<T> val;\n        std::vector<int> parent,\
    \ jump, depth;\n        Pool() : val(1), parent{0}, jump{0}, depth{0} {}\n   \
    \     int make_node(const T& x, int p) {\n            // \u30B8\u30E3\u30F3\u30D7\
    \u306E\u9577\u3055\u304C 1, 1, 3, 1, 1, 3, 7, ... (skew binary) \u306B\u306A\u308B\
    \u3088\u3046\u306B\u5F35\u308B\n            int j = jump[p];\n            int\
    \ nj = depth[p] - depth[j] == depth[j] - depth[jump[j]] ? jump[j] : p;\n     \
    \       val.push_back(x);\n            parent.push_back(p);\n            jump.push_back(nj);\n\
    \            depth.push_back(depth[p] + 1);\n            return static_cast<int>(val.size())\
    \ - 1;\n        }\n        // t \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C d \u306E\
    \u3082\u306E\n        int ancestor(int t, int d) const {\n            while (depth[t]\
    \ > d) t = depth[jump[t]] >= d ? jump[t] : parent[t];\n            return t;\n\
    \        }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u4E00\u5EA6\u3082 push\
    \ \u3057\u3066\u3044\u306A\u3051\u308C\u3070 nullptr\n    int back_node, n;  \
    \          // \u8981\u7D20\u306F back_node \u304B\u3089 n \u500B\u4E0A\u307E\u3067\
    \u306E\u30CE\u30FC\u30C9\n\n    PersistentQueue(std::shared_ptr<Pool> pool, int\
    \ back_node, int n) : pool(std::move(pool)), back_node(back_node), n(n) {}\n\n\
    \   public:\n    /**\n     * @brief \u7A7A\u306E\u30AD\u30E5\u30FC\u3092\u4F5C\
    \u308B\n     */\n    PersistentQueue() : pool(nullptr), back_node(0), n(0) {}\n\
    \n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long\
    \ long size() const { return n; }\n    /**\n     * @brief \u7A7A\u304B\u3069\u3046\
    \u304B\u3092\u8FD4\u3059\n     */\n    bool empty() const { return n == 0; }\n\
    \n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\n  \
    \   */\n    T front() const {\n        assert(!empty());\n        return pool->val[pool->ancestor(back_node,\
    \ pool->depth[back_node] - n + 1)];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306E\u8981\u7D20\u3092\u8FD4\u3059\n     */\n    T back() const {\n        assert(!empty());\n\
    \        return pool->val[back_node];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306Bx\u3092\u52A0\u3048\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param x \u52A0\u3048\u308B\u5024\n     * @return PersistentQueue\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n\
    \     */\n    PersistentQueue push(const T& x) const {\n        std::shared_ptr<Pool>\
    \ p = pool ? pool : std::make_shared<Pool>();\n        int t = p->make_node(x,\
    \ back_node);\n        return PersistentQueue(std::move(p), t, n + 1);\n    }\n\
    \    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u53D6\u308A\u9664\
    \u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @return\
    \ PersistentQueue \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\
    \u306A\u3044)\n     */\n    PersistentQueue pop() const {\n        assert(!empty());\n\
    \        return PersistentQueue(pool, back_node, n - 1);\n    }\n\n    /**\n \
    \    * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5148\u982D\u304B\u3089\
    \u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<T>\
    \ to_vector() const {\n        std::vector<T> res(n);\n        int t = back_node;\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            res[i] = pool->val[t];\n\
    \            t = pool->parent[t];\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/persistent-queue.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/data_structures/persistent-queue.test.cpp
  - test/yosupo/data_structure/persistent-queue.test.cpp
documentation_of: src/data_structures/persistent-queue.hpp
layout: document
title: "\u6C38\u7D9A\u30AD\u30E5\u30FC"
---

過去の版を残したまま更新できるキューです。`push`・`pop` は元の版を変えずに新しい版を返します。

```cpp
PersistentQueue<int> q0;
auto q1 = q0.push(1).push(2);   // q0 はそのまま
q1.front();                     // 1
auto q2 = q1.pop();
q2.front();                     // 2
q1.front();                     // 1 (q1 もそのまま)

// 版を配列に並べる (クエリ i の後の版を que[i + 1] に置く)
std::vector<PersistentQueue<int>> que(q + 1);
que[i + 1] = que[t + 1].push(x);
```

要素を木の根から末尾へのパスとして持ちます。`pop` は要素数を減らすだけで、`front` は末尾から祖先をたどって求めます。祖先へのジャンプポインタは skew binary の長さで張るので、ノード 1 つあたりのメモリは $O(1)$ で、祖先は $O(\log n)$ でたどれます。

同じキューから作った版はノードを共有します。ノードは削除しないので、メモリは `push` の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentQueue<T>()` | 空のキュー | $O(1)$ |
| `size()` | 要素数 | $O(1)$ |
| `empty()` | 空か | $O(1)$ |
| `front()` | 先頭の要素 | $O(\log n)$ |
| `back()` | 末尾の要素 | $O(1)$ |
| `push(x)` | 末尾に `x` を加えた新しい版を返す | $O(1)$ |
| `pop()` | 先頭を取り除いた新しい版を返す | $O(1)$ |
| `to_vector()` | すべての要素を先頭から順に並べた `std::vector<T>` | $O(n)$ |

$n$ は、これまでに `push` した回数です。

## 関連

- 末尾から取り出すなら [永続スタック](persistent-stack.hpp)
