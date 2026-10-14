---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/itp1-1-a.binary-trie.test.cpp
    title: test/aoj/itp1-1-a.binary-trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/binary-trie.test.cpp
    title: test/unittest/binary-trie.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set-xor-min.test.cpp
    title: test/yosupo/set-xor-min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Trie
    links: []
  bundledCode: "#line 2 \"src/data_structures/binary-trie.hpp\"\n\n/**\n * @file binary-trie.hpp\n\
    \ * @brief Binary Trie\n */\n\n#include <cassert>\n#include <limits>\n#include\
    \ <memory>\n#include <utility>\n\n/**\n * @brief \u7B26\u53F7\u306A\u3057\u6574\
    \u6570\u306E\u591A\u91CD\u96C6\u5408\u3092\u7BA1\u7406\u3059\u308B\n * @tparam\
    \ `d` \u6271\u3046\u6574\u6570\u5024\u306E\u30D3\u30C3\u30C8\u5E45\u3002T\u306E\
    \u6841\u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u8ACB\n */\ntemplate\
    \ <unsigned int d, typename T = unsigned long long>\nclass BinaryTrie {\n    static_assert(std::numeric_limits<T>::is_integer);\n\
    \    static_assert(!std::numeric_limits<T>::is_signed);\n    static_assert(d <=\
    \ std::numeric_limits<T>::digits, \"d must be T digits or less\");\n    struct\
    \ BinaryTrieNode {\n        std::shared_ptr<BinaryTrieNode> children[2] = {nullptr,\
    \ nullptr};\n        unsigned int level, subcnt = 0;\n        T xval = 0;\n\n\
    \        BinaryTrieNode(int lvl) : level(lvl) {}\n        bool get_bit(T v) const\
    \ { return ((v >> (level - 1)) & 1) > 0; }\n        bool is_leaf() const { return\
    \ level == 0; }\n        // \u5B50\u306E\u72B6\u614B\u304Cvalid\u304B\u3069\u3046\
    \u304B\n        // 0: xx, 1: xo, 2: ox, 3: oo\n        int state_children() const\
    \ {\n            return ((bool)children[1] << 1) | (bool)children[0];\n      \
    \  }\n        // xor\u306E\u5024\u3092\u5B50\u30CE\u30FC\u30C9\u306B\u4F1D\u64AD\
    \u3059\u308B\n        void affect_xor() {\n            if (get_bit(xval)) {\n\
    \                std::swap(children[0], children[1]);\n            }\n       \
    \     if (children[0])\n                children[0]->xval ^= xval;\n         \
    \   if (children[1])\n                children[1]->xval ^= xval;\n           \
    \ xval = 0;\n        }\n    };\n    using NodePtr = std::shared_ptr<BinaryTrieNode>;\n\
    \    NodePtr root_ptr = std::make_shared<BinaryTrieNode>(d);\n\n   public:\n \
    \   /**\n     * @brief \u96C6\u5408\u306Bn\u3092\u8FFD\u52A0 (O(d))\n     */\n\
    \    void insert(T n) {\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt += 1;\n \
    \           NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n     \
    \       if (!nxt_ptr) {\n                nxt_ptr = std::make_shared<BinaryTrieNode>(cur_ptr->level\
    \ - 1);\n            }\n            cur_ptr = nxt_ptr;\n        }\n        assert(cur_ptr->is_leaf());\n\
    \        cur_ptr->subcnt += 1;\n    }\n\n    int size() const { return root_ptr->subcnt;\
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u691C\u7D22\u3057\
    \u3001\u898B\u3064\u304B\u3063\u305F\u6570\u3092\u6C42\u3081\u308B (O(d))\n  \
    \   */\n    int count(T n) const {\n        NodePtr cur_ptr = root_ptr;\n    \
    \    while (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n     \
    \       NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n         \
    \   if (!nxt_ptr) {\n                return 0;\n            }\n            cur_ptr\
    \ = nxt_ptr;\n        }\n        return (cur_ptr ? cur_ptr->subcnt : 0);\n   \
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u524A\u9664 (O(d))\n\
    \     * @note \u5B58\u5728\u3057\u306A\u3044\u8981\u7D20\u3092\u6307\u5B9A\u3057\
    \u305F\u3068\u304D\u3001\u4F55\u3082\u8D77\u3053\u3089\u306A\u3044\n     */\n\
    \    void erase(T n) {\n        unsigned int cnt = count(n);\n        if (cnt\
    \ == 0)\n            return;\n        NodePtr cur_ptr = root_ptr;\n        while\
    \ (true) {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt -=\
    \ cnt;\n            NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n\
    \            if (nxt_ptr->subcnt == cnt) {\n                nxt_ptr = nullptr;\n\
    \                return;\n            }\n            cur_ptr = nxt_ptr;\n    \
    \    }\n    }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u4E00\u3064\
    \u3060\u3051\u524A\u9664 (O(d))\n     * @note \u5B58\u5728\u3057\u306A\u3044\u8981\
    \u7D20\u3092\u6307\u5B9A\u3057\u305F\u3068\u304D\u3001\u4F55\u3082\u8D77\u3053\
    \u3089\u306A\u3044\n     */\n    void erase_one_element(T n) {\n        if (count(n)\
    \ == 0)\n            return;\n        NodePtr cur_ptr = root_ptr;\n        while\
    \ (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt\
    \ -= 1;\n            NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n\
    \            if (nxt_ptr->subcnt == 1) {\n                nxt_ptr = nullptr;\n\
    \                return;\n            }\n            cur_ptr = nxt_ptr;\n    \
    \    }\n        cur_ptr->subcnt -= 1;\n    }\n\n    /**\n     * @brief \u6607\u9806\
    \u3067n\u756A\u76EE\u306E\u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @note n\u304C\
    trie\u6728\u306E\u30B5\u30A4\u30BA\u4EE5\u4E0A\u306A\u5834\u5408\u3001assert\n\
    \     */\n    T nth_element(int n) const {\n        assert(0 <= n && n < size());\n\
    \        T ret = 0;\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            ret <<= 1;\n            int\
    \ state = cur_ptr->state_children();\n            NodePtr& z_ptr = cur_ptr->children[0];\n\
    \            NodePtr& o_ptr = cur_ptr->children[1];\n            assert(state\
    \ > 0);\n            if (state == 1 || (state == 3 && n < (int)z_ptr->subcnt))\
    \ {\n                cur_ptr = z_ptr;\n            } else {\n                n\
    \ -= (state & 1 ? z_ptr->subcnt : 0);\n                ret |= 1;\n           \
    \     cur_ptr = o_ptr;\n            }\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief n\u4EE5\u4E0A\u306E\u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n\
    \     * @return \u63A2\u7D22\u3057\u305F\u5024\u304C\u6607\u9806\u3067\u4F55\u756A\
    \u76EE\u304B (0-indexed)\u3002\u8A72\u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\
    \u3051\u308C\u3070trie\u6728\u306E\u30B5\u30A4\u30BA\u304C\u8FD4\u308B\n     */\n\
    \    int bisect_left(T n) const {\n        if constexpr (d < std::numeric_limits<T>::digits)\
    \ {\n            if ((n >> d) != 0) return size();\n        }\n        int ret\
    \ = 0;\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            bool b = cur_ptr->get_bit(n);\n\
    \            NodePtr& nxt_ptr = cur_ptr->children[b];\n            NodePtr& z_ptr\
    \ = cur_ptr->children[0];\n            if (b && z_ptr) {\n                ret\
    \ += z_ptr->subcnt;\n            }\n            if (!nxt_ptr) {\n            \
    \    break;\n            }\n            cur_ptr = nxt_ptr;\n        }\n      \
    \  return ret;\n    }\n\n    /**\n     * @brief n\u3088\u308A\u5927\u304D\u306A\
    \u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @return \u63A2\u7D22\u3057\u305F\
    \u5024\u304C\u6607\u9806\u3067\u4F55\u756A\u76EE\u304B (0-indexed)\u3002\u8A72\
    \u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\u3051\u308C\u3070trie\u6728\u306E\u30B5\
    \u30A4\u30BA\u304C\u8FD4\u308B\n     */\n    int bisect_right(T n) const {\n \
    \       return (n < std::numeric_limits<T>::max() ? bisect_left(n + 1) : size());\n\
    \    }\n\n    /**\n     * @brief \u96C6\u5408\u306E\u3059\u3079\u3066\u306E\u8981\
    \u7D20\u306Bxor\u3092\u4F5C\u7528\n     */\n    void apply_xor(T n) { root_ptr->xval\
    \ ^= n; }\n\n    /**\n     * @brief \u8981\u7D20\u3092\u3059\u3079\u3066\u524A\
    \u9664\u3059\u308B\u3002\u78BA\u4FDD\u3057\u305F\u30E1\u30E2\u30EA\u9818\u57DF\
    \u3082\u524A\u9664\u3055\u308C\u308B\n     */\n    void clear() {\n        root_ptr\
    \ = std::make_shared<BinaryTrieNode>(d);\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file binary-trie.hpp\n * @brief Binary Trie\n */\n\
    \n#include <cassert>\n#include <limits>\n#include <memory>\n#include <utility>\n\
    \n/**\n * @brief \u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u591A\u91CD\u96C6\u5408\
    \u3092\u7BA1\u7406\u3059\u308B\n * @tparam `d` \u6271\u3046\u6574\u6570\u5024\u306E\
    \u30D3\u30C3\u30C8\u5E45\u3002T\u306E\u6841\u4EE5\u4E0B\u3067\u3042\u308B\u3053\
    \u3068\u3092\u8981\u8ACB\n */\ntemplate <unsigned int d, typename T = unsigned\
    \ long long>\nclass BinaryTrie {\n    static_assert(std::numeric_limits<T>::is_integer);\n\
    \    static_assert(!std::numeric_limits<T>::is_signed);\n    static_assert(d <=\
    \ std::numeric_limits<T>::digits, \"d must be T digits or less\");\n    struct\
    \ BinaryTrieNode {\n        std::shared_ptr<BinaryTrieNode> children[2] = {nullptr,\
    \ nullptr};\n        unsigned int level, subcnt = 0;\n        T xval = 0;\n\n\
    \        BinaryTrieNode(int lvl) : level(lvl) {}\n        bool get_bit(T v) const\
    \ { return ((v >> (level - 1)) & 1) > 0; }\n        bool is_leaf() const { return\
    \ level == 0; }\n        // \u5B50\u306E\u72B6\u614B\u304Cvalid\u304B\u3069\u3046\
    \u304B\n        // 0: xx, 1: xo, 2: ox, 3: oo\n        int state_children() const\
    \ {\n            return ((bool)children[1] << 1) | (bool)children[0];\n      \
    \  }\n        // xor\u306E\u5024\u3092\u5B50\u30CE\u30FC\u30C9\u306B\u4F1D\u64AD\
    \u3059\u308B\n        void affect_xor() {\n            if (get_bit(xval)) {\n\
    \                std::swap(children[0], children[1]);\n            }\n       \
    \     if (children[0])\n                children[0]->xval ^= xval;\n         \
    \   if (children[1])\n                children[1]->xval ^= xval;\n           \
    \ xval = 0;\n        }\n    };\n    using NodePtr = std::shared_ptr<BinaryTrieNode>;\n\
    \    NodePtr root_ptr = std::make_shared<BinaryTrieNode>(d);\n\n   public:\n \
    \   /**\n     * @brief \u96C6\u5408\u306Bn\u3092\u8FFD\u52A0 (O(d))\n     */\n\
    \    void insert(T n) {\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt += 1;\n \
    \           NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n     \
    \       if (!nxt_ptr) {\n                nxt_ptr = std::make_shared<BinaryTrieNode>(cur_ptr->level\
    \ - 1);\n            }\n            cur_ptr = nxt_ptr;\n        }\n        assert(cur_ptr->is_leaf());\n\
    \        cur_ptr->subcnt += 1;\n    }\n\n    int size() const { return root_ptr->subcnt;\
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u691C\u7D22\u3057\
    \u3001\u898B\u3064\u304B\u3063\u305F\u6570\u3092\u6C42\u3081\u308B (O(d))\n  \
    \   */\n    int count(T n) const {\n        NodePtr cur_ptr = root_ptr;\n    \
    \    while (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n     \
    \       NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n         \
    \   if (!nxt_ptr) {\n                return 0;\n            }\n            cur_ptr\
    \ = nxt_ptr;\n        }\n        return (cur_ptr ? cur_ptr->subcnt : 0);\n   \
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u524A\u9664 (O(d))\n\
    \     * @note \u5B58\u5728\u3057\u306A\u3044\u8981\u7D20\u3092\u6307\u5B9A\u3057\
    \u305F\u3068\u304D\u3001\u4F55\u3082\u8D77\u3053\u3089\u306A\u3044\n     */\n\
    \    void erase(T n) {\n        unsigned int cnt = count(n);\n        if (cnt\
    \ == 0)\n            return;\n        NodePtr cur_ptr = root_ptr;\n        while\
    \ (true) {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt -=\
    \ cnt;\n            NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n\
    \            if (nxt_ptr->subcnt == cnt) {\n                nxt_ptr = nullptr;\n\
    \                return;\n            }\n            cur_ptr = nxt_ptr;\n    \
    \    }\n    }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u4E00\u3064\
    \u3060\u3051\u524A\u9664 (O(d))\n     * @note \u5B58\u5728\u3057\u306A\u3044\u8981\
    \u7D20\u3092\u6307\u5B9A\u3057\u305F\u3068\u304D\u3001\u4F55\u3082\u8D77\u3053\
    \u3089\u306A\u3044\n     */\n    void erase_one_element(T n) {\n        if (count(n)\
    \ == 0)\n            return;\n        NodePtr cur_ptr = root_ptr;\n        while\
    \ (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt\
    \ -= 1;\n            NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n\
    \            if (nxt_ptr->subcnt == 1) {\n                nxt_ptr = nullptr;\n\
    \                return;\n            }\n            cur_ptr = nxt_ptr;\n    \
    \    }\n        cur_ptr->subcnt -= 1;\n    }\n\n    /**\n     * @brief \u6607\u9806\
    \u3067n\u756A\u76EE\u306E\u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @note n\u304C\
    trie\u6728\u306E\u30B5\u30A4\u30BA\u4EE5\u4E0A\u306A\u5834\u5408\u3001assert\n\
    \     */\n    T nth_element(int n) const {\n        assert(0 <= n && n < size());\n\
    \        T ret = 0;\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            ret <<= 1;\n            int\
    \ state = cur_ptr->state_children();\n            NodePtr& z_ptr = cur_ptr->children[0];\n\
    \            NodePtr& o_ptr = cur_ptr->children[1];\n            assert(state\
    \ > 0);\n            if (state == 1 || (state == 3 && n < (int)z_ptr->subcnt))\
    \ {\n                cur_ptr = z_ptr;\n            } else {\n                n\
    \ -= (state & 1 ? z_ptr->subcnt : 0);\n                ret |= 1;\n           \
    \     cur_ptr = o_ptr;\n            }\n        }\n        return ret;\n    }\n\
    \n    /**\n     * @brief n\u4EE5\u4E0A\u306E\u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n\
    \     * @return \u63A2\u7D22\u3057\u305F\u5024\u304C\u6607\u9806\u3067\u4F55\u756A\
    \u76EE\u304B (0-indexed)\u3002\u8A72\u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\
    \u3051\u308C\u3070trie\u6728\u306E\u30B5\u30A4\u30BA\u304C\u8FD4\u308B\n     */\n\
    \    int bisect_left(T n) const {\n        if constexpr (d < std::numeric_limits<T>::digits)\
    \ {\n            if ((n >> d) != 0) return size();\n        }\n        int ret\
    \ = 0;\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            bool b = cur_ptr->get_bit(n);\n\
    \            NodePtr& nxt_ptr = cur_ptr->children[b];\n            NodePtr& z_ptr\
    \ = cur_ptr->children[0];\n            if (b && z_ptr) {\n                ret\
    \ += z_ptr->subcnt;\n            }\n            if (!nxt_ptr) {\n            \
    \    break;\n            }\n            cur_ptr = nxt_ptr;\n        }\n      \
    \  return ret;\n    }\n\n    /**\n     * @brief n\u3088\u308A\u5927\u304D\u306A\
    \u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @return \u63A2\u7D22\u3057\u305F\
    \u5024\u304C\u6607\u9806\u3067\u4F55\u756A\u76EE\u304B (0-indexed)\u3002\u8A72\
    \u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\u3051\u308C\u3070trie\u6728\u306E\u30B5\
    \u30A4\u30BA\u304C\u8FD4\u308B\n     */\n    int bisect_right(T n) const {\n \
    \       return (n < std::numeric_limits<T>::max() ? bisect_left(n + 1) : size());\n\
    \    }\n\n    /**\n     * @brief \u96C6\u5408\u306E\u3059\u3079\u3066\u306E\u8981\
    \u7D20\u306Bxor\u3092\u4F5C\u7528\n     */\n    void apply_xor(T n) { root_ptr->xval\
    \ ^= n; }\n\n    /**\n     * @brief \u8981\u7D20\u3092\u3059\u3079\u3066\u524A\
    \u9664\u3059\u308B\u3002\u78BA\u4FDD\u3057\u305F\u30E1\u30E2\u30EA\u9818\u57DF\
    \u3082\u524A\u9664\u3055\u308C\u308B\n     */\n    void clear() {\n        root_ptr\
    \ = std::make_shared<BinaryTrieNode>(d);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/binary-trie.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/binary-trie.test.cpp
  - test/aoj/itp1-1-a.binary-trie.test.cpp
  - test/yosupo/set-xor-min.test.cpp
documentation_of: src/data_structures/binary-trie.hpp
layout: document
title: Binary Trie
---

$d$ ビットの符号なし整数の多重集合を管理する Binary Trie `BinaryTrie<d, T = unsigned long long>` です。全要素への xor の作用ができます。

```cpp
BinaryTrie<30> bt;
bt.insert(5); bt.insert(3); bt.insert(3); bt.insert(10);
bt.count(3);         // 2
bt.nth_element(0);   // 3 (最小値)
bt.apply_xor(6);     // {5, 5, 3, 12}
bt.nth_element(0);   // 3 (x との xor の最小値は apply_xor(x) してから nth_element(0))
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `insert(x)` | `x` を 1 個追加 | $O(d)$ |
| `erase(x)` | `x` をすべて削除 (なければ何もしない) | $O(d)$ |
| `erase_one_element(x)` | `x` を 1 個削除 (なければ何もしない) | $O(d)$ |
| `count(x)` | `x` の個数 | $O(d)$ |
| `size()` | 要素数 | $O(1)$ |
| `nth_element(k)` | 小さい方から `k` 番目 (0-indexed) の値 | $O(d)$ |
| `bisect_left(x)` | `x` 未満の要素の個数 (`x` 以上の最小の要素が何番目か。なければ `size()`) | $O(d)$ |
| `bisect_right(x)` | `x` 以下の要素の個数 (`x` より大きい最小の要素が何番目か。なければ `size()`) | $O(d)$ |
| `apply_xor(x)` | 全要素を `x` と xor する | $O(1)$ |
| `clear()` | 全要素を削除してメモリを解放 | ノード数に比例 |

## 関連

- XOR で作れる値の集合は [XOR 基底](../math/xor-basis.hpp)
- 文字列の Trie は [Trie](../string/trie.hpp)
