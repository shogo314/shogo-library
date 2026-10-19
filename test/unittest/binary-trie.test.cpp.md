---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/binary-trie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/binary-trie.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n// BinaryTrie\
    \ \u306E clear \u3092\u3001\u64CD\u4F5C\u5217\u306E\u9014\u4E2D\u3067\u547C\u3093\
    \u3067 std::multiset \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u6BD4\
    \u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\
    \u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\
    \u3059\u308B\n\n#line 2 \"src/data_structures/binary-trie.hpp\"\n\n/**\n * @file\
    \ binary-trie.hpp\n * @brief Binary Trie\n */\n\n#include <cassert>\n#include\
    \ <limits>\n#include <memory>\n#include <utility>\n\n/**\n * @brief \u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u591A\u91CD\u96C6\u5408\u3092\u7BA1\u7406\u3059\
    \u308B\n * @tparam `d` \u6271\u3046\u6574\u6570\u5024\u306E\u30D3\u30C3\u30C8\u5E45\
    \u3002T\u306E\u6841\u4EE5\u4E0B\u3067\u3042\u308B\u3053\u3068\u3092\u8981\u8ACB\
    \n */\ntemplate <unsigned int d, typename T = unsigned long long>\nclass BinaryTrie\
    \ {\n    static_assert(std::numeric_limits<T>::is_integer);\n    static_assert(!std::numeric_limits<T>::is_signed);\n\
    \    static_assert(d <= std::numeric_limits<T>::digits, \"d must be T digits or\
    \ less\");\n    struct BinaryTrieNode {\n        std::shared_ptr<BinaryTrieNode>\
    \ children[2] = {nullptr, nullptr};\n        unsigned int level, subcnt = 0;\n\
    \        T xval = 0;\n\n        explicit BinaryTrieNode(int lvl) : level(lvl)\
    \ {}\n        bool get_bit(T v) const { return ((v >> (level - 1)) & 1) > 0; }\n\
    \        bool is_leaf() const { return level == 0; }\n        // \u5B50\u306E\u72B6\
    \u614B\u304Cvalid\u304B\u3069\u3046\u304B\n        // 0: xx, 1: xo, 2: ox, 3:\
    \ oo\n        int state_children() const {\n            return (static_cast<bool>(children[1])\
    \ << 1) | static_cast<bool>(children[0]);\n        }\n        // xor\u306E\u5024\
    \u3092\u5B50\u30CE\u30FC\u30C9\u306B\u4F1D\u64AD\u3059\u308B\n        void affect_xor()\
    \ {\n            if (get_bit(xval)) {\n                std::swap(children[0],\
    \ children[1]);\n            }\n            if (children[0])\n               \
    \ children[0]->xval ^= xval;\n            if (children[1])\n                children[1]->xval\
    \ ^= xval;\n            xval = 0;\n        }\n    };\n    using NodePtr = std::shared_ptr<BinaryTrieNode>;\n\
    \    NodePtr root_ptr = std::make_shared<BinaryTrieNode>(d);\n\n   public:\n \
    \   /**\n     * @brief \u96C6\u5408\u306Bn\u3092\u8FFD\u52A0 (O(d))\n     */\n\
    \    void insert(T n) {\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt += 1;\n \
    \           NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n     \
    \       if (!nxt_ptr) {\n                nxt_ptr = std::make_shared<BinaryTrieNode>(cur_ptr->level\
    \ - 1);\n            }\n            cur_ptr = nxt_ptr;\n        }\n        assert(cur_ptr->is_leaf());\n\
    \        cur_ptr->subcnt += 1;\n    }\n\n    long long size() const { return root_ptr->subcnt;\
    \ }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u691C\u7D22\u3057\
    \u3001\u898B\u3064\u304B\u3063\u305F\u6570\u3092\u6C42\u3081\u308B (O(d))\n  \
    \   */\n    long long count(T n) const {\n        NodePtr cur_ptr = root_ptr;\n\
    \        while (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n \
    \           NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n     \
    \       if (!nxt_ptr) {\n                return 0;\n            }\n          \
    \  cur_ptr = nxt_ptr;\n        }\n        return (cur_ptr ? cur_ptr->subcnt :\
    \ 0);\n    }\n\n    /**\n     * @brief \u96C6\u5408\u304B\u3089n\u3092\u524A\u9664\
    \ (O(d))\n     * @note \u5B58\u5728\u3057\u306A\u3044\u8981\u7D20\u3092\u6307\u5B9A\
    \u3057\u305F\u3068\u304D\u3001\u4F55\u3082\u8D77\u3053\u3089\u306A\u3044\n   \
    \  */\n    void erase(T n) {\n        unsigned int cnt = count(n);\n        if\
    \ (cnt == 0)\n            return;\n        NodePtr cur_ptr = root_ptr;\n     \
    \   while (true) {\n            cur_ptr->affect_xor();\n            cur_ptr->subcnt\
    \ -= cnt;\n            NodePtr& nxt_ptr = cur_ptr->children[cur_ptr->get_bit(n)];\n\
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
    \     */\n    T nth_element(long long n) const {\n        assert(0 <= n && n <\
    \ size());\n        T ret = 0;\n        NodePtr cur_ptr = root_ptr;\n        while\
    \ (!cur_ptr->is_leaf()) {\n            cur_ptr->affect_xor();\n            ret\
    \ <<= 1;\n            int state = cur_ptr->state_children();\n            NodePtr&\
    \ z_ptr = cur_ptr->children[0];\n            NodePtr& o_ptr = cur_ptr->children[1];\n\
    \            assert(state > 0);\n            if (state == 1 || (state == 3 &&\
    \ n < static_cast<long long>(z_ptr->subcnt))) {\n                cur_ptr = z_ptr;\n\
    \            } else {\n                n -= (state & 1 ? z_ptr->subcnt : 0);\n\
    \                ret |= 1;\n                cur_ptr = o_ptr;\n            }\n\
    \        }\n        return ret;\n    }\n\n    /**\n     * @brief n\u4EE5\u4E0A\
    \u306E\u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @return \u63A2\u7D22\u3057\
    \u305F\u5024\u304C\u6607\u9806\u3067\u4F55\u756A\u76EE\u304B (0-indexed)\u3002\
    \u8A72\u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\u3051\u308C\u3070trie\u6728\u306E\
    \u30B5\u30A4\u30BA\u304C\u8FD4\u308B\n     */\n    long long bisect_left(T n)\
    \ const {\n        if constexpr (d < std::numeric_limits<T>::digits) {\n     \
    \       if ((n >> d) != 0) return size();\n        }\n        long long ret =\
    \ 0;\n        NodePtr cur_ptr = root_ptr;\n        while (!cur_ptr->is_leaf())\
    \ {\n            cur_ptr->affect_xor();\n            bool b = cur_ptr->get_bit(n);\n\
    \            NodePtr& nxt_ptr = cur_ptr->children[b];\n            NodePtr& z_ptr\
    \ = cur_ptr->children[0];\n            if (b && z_ptr) {\n                ret\
    \ += z_ptr->subcnt;\n            }\n            if (!nxt_ptr) {\n            \
    \    break;\n            }\n            cur_ptr = nxt_ptr;\n        }\n      \
    \  return ret;\n    }\n\n    /**\n     * @brief n\u3088\u308A\u5927\u304D\u306A\
    \u8981\u7D20\u3092\u63A2\u7D22 (O(d))\n     * @return \u63A2\u7D22\u3057\u305F\
    \u5024\u304C\u6607\u9806\u3067\u4F55\u756A\u76EE\u304B (0-indexed)\u3002\u8A72\
    \u5F53\u3059\u308B\u8981\u7D20\u304C\u306A\u3051\u308C\u3070trie\u6728\u306E\u30B5\
    \u30A4\u30BA\u304C\u8FD4\u308B\n     */\n    long long bisect_right(T n) const\
    \ {\n        return (n < std::numeric_limits<T>::max() ? bisect_left(n + 1) :\
    \ size());\n    }\n\n    /**\n     * @brief \u96C6\u5408\u306E\u3059\u3079\u3066\
    \u306E\u8981\u7D20\u306Bxor\u3092\u4F5C\u7528\n     */\n    void apply_xor(T n)\
    \ { root_ptr->xval ^= n; }\n\n    /**\n     * @brief \u8981\u7D20\u3092\u3059\u3079\
    \u3066\u524A\u9664\u3059\u308B\u3002\u78BA\u4FDD\u3057\u305F\u30E1\u30E2\u30EA\
    \u9818\u57DF\u3082\u524A\u9664\u3055\u308C\u308B\n     */\n    void clear() {\n\
    \        root_ptr = std::make_shared<BinaryTrieNode>(d);\n    }\n};\n#line 7 \"\
    test/unittest/binary-trie.test.cpp\"\n\n#include <iostream>\n#include <random>\n\
    #include <set>\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 2000 && ok; rep++) {\n        BinaryTrie<4, unsigned>\
    \ bt;\n        std::multiset<unsigned> ms;\n        unsigned x_all = 0;  // \u96C6\
    \u5408\u5168\u4F53\u306B\u4F5C\u7528\u3055\u305B\u305F xor\n        for (int t\
    \ = 0; t < 40; t++) {\n            int op = rng() % 10;\n            if (op ==\
    \ 0) {\n                // clear: \u8981\u7D20\u3082\u3001\u305D\u308C\u307E\u3067\
    \u306B\u4F5C\u7528\u3055\u305B\u305F xor \u3082\u6D88\u3048\u308B\n          \
    \      bt.clear();\n                ms.clear();\n                x_all = 0;\n\
    \            } else if (op == 1) {\n                unsigned x = rng() % 16;\n\
    \                bt.apply_xor(x);\n                x_all ^= x;\n            }\
    \ else if (op <= 6) {\n                unsigned x = rng() % 16;\n            \
    \    bt.insert(x);\n                // \u4F5C\u7528\u6E08\u307F\u306E xor \u3092\
    \u6253\u3061\u6D88\u3057\u305F\u5024\u3067\u6301\u3063\u3066\u304A\u304F\n   \
    \             ms.insert(x ^ x_all);\n            } else {\n                unsigned\
    \ x = rng() % 16;\n                bt.erase_one_element(x);\n                auto\
    \ itr = ms.find(x ^ x_all);\n                if (itr != ms.end()) ms.erase(itr);\n\
    \            }\n            if (bt.size() != static_cast<int>(ms.size())) ok =\
    \ false;\n            for (unsigned x = 0; x < 16; x++) {\n                if\
    \ (bt.count(x) != static_cast<int>(ms.count(x ^ x_all))) ok = false;\n       \
    \     }\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\" <<\
    \ std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// BinaryTrie \u306E clear \u3092\u3001\u64CD\u4F5C\u5217\u306E\u9014\u4E2D\
    \u3067\u547C\u3093\u3067 std::multiset \u306B\u3088\u308B\u611A\u76F4\u306A\u5B9F\
    \u88C5\u3068\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\
    \u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World\
    \ \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/binary-trie.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <set>\n\nint main() {\n \
    \   std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 2000\
    \ && ok; rep++) {\n        BinaryTrie<4, unsigned> bt;\n        std::multiset<unsigned>\
    \ ms;\n        unsigned x_all = 0;  // \u96C6\u5408\u5168\u4F53\u306B\u4F5C\u7528\
    \u3055\u305B\u305F xor\n        for (int t = 0; t < 40; t++) {\n            int\
    \ op = rng() % 10;\n            if (op == 0) {\n                // clear: \u8981\
    \u7D20\u3082\u3001\u305D\u308C\u307E\u3067\u306B\u4F5C\u7528\u3055\u305B\u305F\
    \ xor \u3082\u6D88\u3048\u308B\n                bt.clear();\n                ms.clear();\n\
    \                x_all = 0;\n            } else if (op == 1) {\n             \
    \   unsigned x = rng() % 16;\n                bt.apply_xor(x);\n             \
    \   x_all ^= x;\n            } else if (op <= 6) {\n                unsigned x\
    \ = rng() % 16;\n                bt.insert(x);\n                // \u4F5C\u7528\
    \u6E08\u307F\u306E xor \u3092\u6253\u3061\u6D88\u3057\u305F\u5024\u3067\u6301\u3063\
    \u3066\u304A\u304F\n                ms.insert(x ^ x_all);\n            } else\
    \ {\n                unsigned x = rng() % 16;\n                bt.erase_one_element(x);\n\
    \                auto itr = ms.find(x ^ x_all);\n                if (itr != ms.end())\
    \ ms.erase(itr);\n            }\n            if (bt.size() != static_cast<int>(ms.size()))\
    \ ok = false;\n            for (unsigned x = 0; x < 16; x++) {\n             \
    \   if (bt.count(x) != static_cast<int>(ms.count(x ^ x_all))) ok = false;\n  \
    \          }\n        }\n    }\n    if (ok)\n        std::cout << \"Hello World\"\
    \ << std::endl;\n    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/binary-trie.hpp
  isVerificationFile: true
  path: test/unittest/binary-trie.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:08:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/binary-trie.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/binary-trie.test.cpp
- /verify/test/unittest/binary-trie.test.cpp.html
title: test/unittest/binary-trie.test.cpp
---
