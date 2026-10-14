---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/persistent-stack.test.cpp
    title: test/unittest/persistent-stack.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF"
    links: []
  bundledCode: "#line 2 \"src/data_structures/persistent-stack.hpp\"\n\n/**\n * @file\
    \ persistent-stack.hpp\n * @brief \u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\n */\n\n\
    #include <cassert>\n#include <memory>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\n *\n * \u66F4\u65B0\u3059\
    \u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\
    \u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u30B9\u30BF\u30C3\u30AF\
    \u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\
    \u3059\u308B\n * \u4F8B:\n * PersistentStack<int> s0;\n * auto s1 = s0.push(1).push(2);\
    \  // s0 \u306F\u305D\u306E\u307E\u307E\n * s1.top();                      //\
    \ 2\n * s1.pop().top();                // 1\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n */\ntemplate <typename T>\nclass PersistentStack {\n    // \u3059\u3079\
    \u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\
    \u30C9\u306F\u524A\u9664\u3057\u306A\u3044\n    struct Pool {\n        std::vector<T>\
    \ val;\n        std::vector<int> parent;  // 1 \u3064\u4E0B\u306E\u8981\u7D20\u306E\
    \u30CE\u30FC\u30C9 (\u4E00\u756A\u4E0B\u306A\u3089 -1)\n        int make_node(const\
    \ T& x, int p) {\n            val.push_back(x);\n            parent.push_back(p);\n\
    \            return int(val.size()) - 1;\n        }\n    };\n\n    std::shared_ptr<Pool>\
    \ pool;  // \u4E00\u5EA6\u3082 push \u3057\u3066\u3044\u306A\u3051\u308C\u3070\
    \ nullptr\n    int top_node, n;             // \u7A7A\u306A\u3089 top_node = -1\n\
    \n    PersistentStack(std::shared_ptr<Pool> pool, int top_node, int n) : pool(std::move(pool)),\
    \ top_node(top_node), n(n) {}\n\n   public:\n    /**\n     * @brief \u7A7A\u306E\
    \u30B9\u30BF\u30C3\u30AF\u3092\u4F5C\u308B\n     */\n    PersistentStack() : pool(nullptr),\
    \ top_node(-1), n(0) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\n     */\n    int size() const { return n; }\n    /**\n     * @brief \u7A7A\
    \u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool empty() const {\
    \ return n == 0; }\n\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\u7D20\
    \u3092\u8FD4\u3059\n     */\n    T top() const {\n        assert(!empty());\n\
    \        return pool->val[top_node];\n    }\n    /**\n     * @brief x\u3092\u7A4D\
    \u3093\u3060\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param\
    \ x \u7A4D\u3080\u5024\n     * @return PersistentStack \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack\
    \ push(const T& x) const {\n        std::shared_ptr<Pool> p = pool ? pool : std::make_shared<Pool>();\n\
    \        int t = p->make_node(x, top_node);\n        return PersistentStack(std::move(p),\
    \ t, n + 1);\n    }\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\u7D20\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\
    \n     *\n     * @return PersistentStack \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\
    \u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack pop() const\
    \ {\n        assert(!empty());\n        return PersistentStack(pool, pool->parent[top_node],\
    \ n - 1);\n    }\n\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u4E0B\u304B\u3089\u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\
    \n     */\n    std::vector<T> to_vector() const {\n        std::vector<T> res(n);\n\
    \        int t = top_node;\n        for (int i = n - 1; i >= 0; i--) {\n     \
    \       res[i] = pool->val[t];\n            t = pool->parent[t];\n        }\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file persistent-stack.hpp\n * @brief \u6C38\u7D9A\
    \u30B9\u30BF\u30C3\u30AF\n */\n\n#include <cassert>\n#include <memory>\n#include\
    \ <utility>\n#include <vector>\n\n/**\n * @brief \u6C38\u7D9A\u30B9\u30BF\u30C3\
    \u30AF\n *\n * \u66F4\u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\
    \u3057\u3001\u5143\u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\
    \u3058\u30B9\u30BF\u30C3\u30AF\u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\
    \u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\n * \u4F8B:\n * PersistentStack<int>\
    \ s0;\n * auto s1 = s0.push(1).push(2);  // s0 \u306F\u305D\u306E\u307E\u307E\n\
    \ * s1.top();                      // 2\n * s1.pop().top();                //\
    \ 1\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n */\ntemplate <typename T>\nclass\
    \ PersistentStack {\n    // \u3059\u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\
    \u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\
    \n    struct Pool {\n        std::vector<T> val;\n        std::vector<int> parent;\
    \  // 1 \u3064\u4E0B\u306E\u8981\u7D20\u306E\u30CE\u30FC\u30C9 (\u4E00\u756A\u4E0B\
    \u306A\u3089 -1)\n        int make_node(const T& x, int p) {\n            val.push_back(x);\n\
    \            parent.push_back(p);\n            return int(val.size()) - 1;\n \
    \       }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u4E00\u5EA6\u3082 push\
    \ \u3057\u3066\u3044\u306A\u3051\u308C\u3070 nullptr\n    int top_node, n;   \
    \          // \u7A7A\u306A\u3089 top_node = -1\n\n    PersistentStack(std::shared_ptr<Pool>\
    \ pool, int top_node, int n) : pool(std::move(pool)), top_node(top_node), n(n)\
    \ {}\n\n   public:\n    /**\n     * @brief \u7A7A\u306E\u30B9\u30BF\u30C3\u30AF\
    \u3092\u4F5C\u308B\n     */\n    PersistentStack() : pool(nullptr), top_node(-1),\
    \ n(0) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n   \
    \  */\n    int size() const { return n; }\n    /**\n     * @brief \u7A7A\u304B\
    \u3069\u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool empty() const { return\
    \ n == 0; }\n\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\n     */\n    T top() const {\n        assert(!empty());\n      \
    \  return pool->val[top_node];\n    }\n    /**\n     * @brief x\u3092\u7A4D\u3093\
    \u3060\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param x \u7A4D\
    \u3080\u5024\n     * @return PersistentStack \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\
    \u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack push(const\
    \ T& x) const {\n        std::shared_ptr<Pool> p = pool ? pool : std::make_shared<Pool>();\n\
    \        int t = p->make_node(x, top_node);\n        return PersistentStack(std::move(p),\
    \ t, n + 1);\n    }\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\u7D20\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\
    \n     *\n     * @return PersistentStack \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\
    \u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack pop() const\
    \ {\n        assert(!empty());\n        return PersistentStack(pool, pool->parent[top_node],\
    \ n - 1);\n    }\n\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u4E0B\u304B\u3089\u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\
    \n     */\n    std::vector<T> to_vector() const {\n        std::vector<T> res(n);\n\
    \        int t = top_node;\n        for (int i = n - 1; i >= 0; i--) {\n     \
    \       res[i] = pool->val[t];\n            t = pool->parent[t];\n        }\n\
    \        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/persistent-stack.hpp
  requiredBy: []
  timestamp: '2026-10-15 02:10:34+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/persistent-stack.test.cpp
documentation_of: src/data_structures/persistent-stack.hpp
layout: document
title: "\u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF"
---

過去の版を残したまま更新できるスタックです。`push`・`pop` は元の版を変えずに新しい版を返します。ノードを共有する連結リストで、どの操作も $O(1)$ です。

```cpp
PersistentStack<int> s0;
auto s1 = s0.push(1).push(2);   // s0 はそのまま
s1.top();                       // 2
auto s2 = s1.pop();
s2.top();                       // 1
s1.top();                       // 2 (s1 もそのまま)
```

同じスタックから作った版はノードを共有します。ノードは削除しないので、メモリは `push` の回数に比例して増えます。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentStack<T>()` | 空のスタック | $O(1)$ |
| `size()` | 要素数 | $O(1)$ |
| `empty()` | 空か | $O(1)$ |
| `top()` | 一番上の要素 | $O(1)$ |
| `push(x)` | `x` を積んだ新しい版を返す | $O(1)$ |
| `pop()` | 一番上を取り除いた新しい版を返す | $O(1)$ |
| `to_vector()` | すべての要素を下から順に並べた `std::vector<T>` | $O(n)$ |

## 関連

- 先頭から取り出すなら [永続キュー](persistent-queue.hpp)
