---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/erasable-priority-queue.test.cpp
    title: test/unittest/erasable-priority-queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/double-ended-priority-queue.test.cpp
    title: test/yosupo/double-ended-priority-queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\
      \u30E5\u30FC"
    links: []
  bundledCode: "#line 2 \"src/data_structures/erasable-priority-queue.hpp\"\n\n/**\n\
    \ * @file erasable-priority-queue.hpp\n * @brief \u524A\u9664\u53EF\u80FD\u306A\
    \u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n */\n\n#include <cassert>\n\
    #include <functional>\n#include <queue>\n#include <vector>\n\n/**\n * @brief \u524A\
    \u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n *\n\
    \ * std::priority_queue \u3068\u540C\u3058\u304F\u3001\u65E2\u5B9A\u3067\u306F\
    \u6700\u5927\u306E\u8981\u7D20\u3092\u53D6\u308A\u51FA\u3059\n * \u524A\u9664\u3059\
    \u308B\u8981\u7D20\u3092\u5225\u306E\u30D2\u30FC\u30D7\u306B\u5165\u308C\u3066\
    \u304A\u304D\u3001\u5148\u982D\u306B\u6765\u305F\u3068\u304D\u306B\u53D6\u308A\
    \u9664\u304F\u3002\u5404\u64CD\u4F5C\u306F\u511F\u5374 O(log n)\n * \u4F8B:\n\
    \ * ErasablePriorityQueue<int> pq;\n * pq.push(3); pq.push(5); pq.erase(5); pq.top();\
    \  // 3\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Compare \u6BD4\u8F03\
    \u95A2\u6570\u3002std::greater<T> \u306B\u3059\u308B\u3068\u6700\u5C0F\u306E\u8981\
    \u7D20\u3092\u53D6\u308A\u51FA\u3059\n */\ntemplate <typename T, typename Compare\
    \ = std::less<T>>\nclass ErasablePriorityQueue {\n    std::priority_queue<T, std::vector<T>,\
    \ Compare> que, del;\n    Compare comp;\n\n    bool equivalent(const T& x, const\
    \ T& y) const { return !comp(x, y) && !comp(y, x); }\n    // \u5148\u982D\u304C\
    \u524A\u9664\u4E88\u5B9A\u306A\u3089\u53D6\u308A\u9664\u304F\n    void normalize()\
    \ {\n        while (!del.empty() && equivalent(que.top(), del.top())) {\n    \
    \        que.pop();\n            del.pop();\n        }\n    }\n\n   public:\n\
    \    explicit ErasablePriorityQueue(Compare comp = Compare()) : que(comp), del(comp),\
    \ comp(comp) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\n     */\n    int\
    \ size() const { return que.size() - del.size(); }\n    bool empty() const { return\
    \ size() == 0; }\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\n\
    \     */\n    void push(const T& x) {\n        que.push(x);\n        normalize();\n\
    \    }\n    /**\n     * @brief x \u3092 1 \u3064\u524A\u9664\u3059\u308B\u3002\
    x \u306F\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068 (\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\u3068\u58CA\u308C\
    \u308B)\n     * \u6BD4\u8F03\u95A2\u6570\u3067\u7B49\u3057\u3044\u8981\u7D20\u306F\
    \u533A\u5225\u3057\u306A\u3044\n     */\n    void erase(const T& x) {\n      \
    \  del.push(x);\n        normalize();\n    }\n    /**\n     * @brief \u5148\u982D\
    \ (\u65E2\u5B9A\u3067\u306F\u6700\u5927) \u306E\u8981\u7D20\n     */\n    const\
    \ T& top() const {\n        assert(!empty());\n        return que.top();\n   \
    \ }\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\
    \u308B\n     */\n    void pop() {\n        assert(!empty());\n        que.pop();\n\
    \        normalize();\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file erasable-priority-queue.hpp\n * @brief \u524A\
    \u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n */\n\
    \n#include <cassert>\n#include <functional>\n#include <queue>\n#include <vector>\n\
    \n/**\n * @brief \u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\
    \u30E5\u30FC\n *\n * std::priority_queue \u3068\u540C\u3058\u304F\u3001\u65E2\u5B9A\
    \u3067\u306F\u6700\u5927\u306E\u8981\u7D20\u3092\u53D6\u308A\u51FA\u3059\n * \u524A\
    \u9664\u3059\u308B\u8981\u7D20\u3092\u5225\u306E\u30D2\u30FC\u30D7\u306B\u5165\
    \u308C\u3066\u304A\u304D\u3001\u5148\u982D\u306B\u6765\u305F\u3068\u304D\u306B\
    \u53D6\u308A\u9664\u304F\u3002\u5404\u64CD\u4F5C\u306F\u511F\u5374 O(log n)\n\
    \ * \u4F8B:\n * ErasablePriorityQueue<int> pq;\n * pq.push(3); pq.push(5); pq.erase(5);\
    \ pq.top();  // 3\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Compare\
    \ \u6BD4\u8F03\u95A2\u6570\u3002std::greater<T> \u306B\u3059\u308B\u3068\u6700\
    \u5C0F\u306E\u8981\u7D20\u3092\u53D6\u308A\u51FA\u3059\n */\ntemplate <typename\
    \ T, typename Compare = std::less<T>>\nclass ErasablePriorityQueue {\n    std::priority_queue<T,\
    \ std::vector<T>, Compare> que, del;\n    Compare comp;\n\n    bool equivalent(const\
    \ T& x, const T& y) const { return !comp(x, y) && !comp(y, x); }\n    // \u5148\
    \u982D\u304C\u524A\u9664\u4E88\u5B9A\u306A\u3089\u53D6\u308A\u9664\u304F\n   \
    \ void normalize() {\n        while (!del.empty() && equivalent(que.top(), del.top()))\
    \ {\n            que.pop();\n            del.pop();\n        }\n    }\n\n   public:\n\
    \    explicit ErasablePriorityQueue(Compare comp = Compare()) : que(comp), del(comp),\
    \ comp(comp) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\n     */\n    int\
    \ size() const { return que.size() - del.size(); }\n    bool empty() const { return\
    \ size() == 0; }\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\n\
    \     */\n    void push(const T& x) {\n        que.push(x);\n        normalize();\n\
    \    }\n    /**\n     * @brief x \u3092 1 \u3064\u524A\u9664\u3059\u308B\u3002\
    x \u306F\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068 (\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\u3068\u58CA\u308C\
    \u308B)\n     * \u6BD4\u8F03\u95A2\u6570\u3067\u7B49\u3057\u3044\u8981\u7D20\u306F\
    \u533A\u5225\u3057\u306A\u3044\n     */\n    void erase(const T& x) {\n      \
    \  del.push(x);\n        normalize();\n    }\n    /**\n     * @brief \u5148\u982D\
    \ (\u65E2\u5B9A\u3067\u306F\u6700\u5927) \u306E\u8981\u7D20\n     */\n    const\
    \ T& top() const {\n        assert(!empty());\n        return que.top();\n   \
    \ }\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\
    \u308B\n     */\n    void pop() {\n        assert(!empty());\n        que.pop();\n\
    \        normalize();\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/erasable-priority-queue.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/erasable-priority-queue.test.cpp
  - test/yosupo/double-ended-priority-queue.test.cpp
documentation_of: src/data_structures/erasable-priority-queue.hpp
layout: document
title: "\u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC"
---

任意の要素を削除できる優先度付きキュー `ErasablePriorityQueue<T, Compare = std::less<T>>` です。`std::priority_queue` と同じく、既定では最大の要素を取り出します。

削除する要素を別のヒープに入れておき、それが先頭に来たときに取り除きます。`std::multiset` より定数倍が軽いです。

```cpp
ErasablePriorityQueue<int> pq;                        // 最大を取り出す
ErasablePriorityQueue<int, std::greater<int>> pq2;    // 最小を取り出す
pq.push(3);
pq.push(5);
pq.erase(5);
pq.top();  // 3
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `ErasablePriorityQueue(comp = Compare())` | 空のキューを作る | $O(1)$ |
| `push(x)` | `x` を追加 | 償却 $O(\log n)$ |
| `erase(x)` | `x` を 1 つ削除。`x` はキューに含まれていること (含まれていない要素を削除すると壊れる) | 償却 $O(\log n)$ |
| `top()` | 先頭 (既定では最大) の要素 | $O(1)$ |
| `pop()` | 先頭の要素を削除 | 償却 $O(\log n)$ |
| `size()`、`empty()` | 要素数、空か | $O(1)$ |

`Compare` で等しい要素 (`!comp(x, y) && !comp(y, x)`) は区別しません。

最大と最小の両方を取り出したいときは、`std::less` と `std::greater` の 2 つを持ち、片方から取り出した要素をもう片方から `erase` します。

```cpp
ErasablePriorityQueue<int> max_q;
ErasablePriorityQueue<int, std::greater<int>> min_q;
int x = min_q.top();  // 最小を取り出す
min_q.pop();
max_q.erase(x);
```

## 関連

- 値ごとの個数を数える多重集合は [Counter](counter.hpp)
