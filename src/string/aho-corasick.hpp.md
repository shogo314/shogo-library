---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/volume28/2873.test.cpp
    title: test/aoj/volume28/2873.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/aho-corasick.test.cpp
    title: test/unittest/string/aho-corasick.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/aho-corasick.test.cpp
    title: test/yosupo/string/aho-corasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Aho-Corasick
    links: []
  bundledCode: "#line 2 \"src/string/aho-corasick.hpp\"\n\n/**\n * @file aho-corasick.hpp\n\
    \ * @brief Aho-Corasick\n */\n\n#include <array>\n#include <cassert>\n#include\
    \ <iterator>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Aho-Corasick\
    \ (\u8907\u6570\u306E\u30D1\u30BF\u30FC\u30F3\u306E\u7167\u5408)\n *\n * \u30D1\
    \u30BF\u30FC\u30F3\u3092 add \u3067\u8FFD\u52A0\u3057\u3066\u304B\u3089 build\
    \ \u3092\u547C\u3076\u3002\u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066 0\
    \ \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\n * \u30CE\u30FC\
    \u30C9\u306F Trie \u3068\u540C\u3058\u304F\u3001\u6587\u5B57\u5217\u3092\u8FFD\
    \u52A0\u3057\u305F\u9806\u306B\u4F5C\u3063\u305F\u756A\u53F7\u3092\u6301\u3064\
    \u3002\u6839\u306F\u30CE\u30FC\u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u4F8B:\n\
    \ * AhoCorasick<26, 'a'> ac;\n * ac.add(\"he\");\n * ac.add(\"she\");\n * ac.build();\n\
    \ * ac.count(\"ushers\");  // 2 (\"she\" \u3068 \"he\")\n *\n * @tparam K \u6587\
    \u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\u5C0F\u306E\u6587\u5B57\
    \n */\ntemplate <int K = 26, int Base = 'a'>\nclass AhoCorasick {\n    struct\
    \ Node {\n        std::array<int, K> next;  // build \u524D\u306F Trie \u306E\u5B50\
    \ (\u306A\u3051\u308C\u3070 -1)\u3001build \u5F8C\u306F\u6587\u5B57\u3092\u8AAD\
    \u3093\u3060\u3068\u304D\u306E\u9077\u79FB\u5148\n        int parent, depth;\n\
    \        int link;         // \u5931\u6557\u30EA\u30F3\u30AF (\u3053\u306E\u30CE\
    \u30FC\u30C9\u306E\u6587\u5B57\u5217\u306E\u3001\u6700\u9577\u306E\u771F\u306E\
    \u63A5\u5C3E\u8F9E\u306E\u30CE\u30FC\u30C9)\n        int out;          // \u5931\
    \u6557\u30EA\u30F3\u30AF\u3092\u305F\u3069\u3063\u3066\u6700\u521D\u306B\u7740\
    \u304F\u3001\u30D1\u30BF\u30FC\u30F3\u304C\u7D42\u308F\u308B\u30CE\u30FC\u30C9\
    \ (\u306A\u3051\u308C\u3070 -1)\n        int head;         // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3067\u7D42\u308F\u308B\u30D1\u30BF\u30FC\u30F3\u306E\u756A\u53F7\
    \u306E\u30EA\u30B9\u30C8\u306E\u5148\u982D (\u306A\u3051\u308C\u3070 -1)\n   \
    \     int match_count;  // \u3053\u306E\u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\
    \u306E\u63A5\u5C3E\u8F9E\u306B\u306A\u3063\u3066\u3044\u308B\u30D1\u30BF\u30FC\
    \u30F3\u306E\u500B\u6570\n    };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\
    \u305F\u3081\u3001\u30CE\u30FC\u30C9\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\
    \u3002\u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n\
    \    std::vector<Node> nodes;\n    std::vector<int> pattern_node, next_pattern;\
    \  // \u30D1\u30BF\u30FC\u30F3\u306E\u7D42\u308F\u308B\u30CE\u30FC\u30C9\u3068\
    \u3001\u540C\u3058\u30CE\u30FC\u30C9\u3067\u7D42\u308F\u308B\u6B21\u306E\u30D1\
    \u30BF\u30FC\u30F3\n    std::vector<int> bfs_order;\n    bool built = false;\n\
    \n    int add_node(int parent, int depth) {\n        Node node;\n        node.next.fill(-1);\n\
    \        node.parent = parent;\n        node.depth = depth;\n        node.link\
    \ = 0;\n        node.out = node.head = -1;\n        node.match_count = 0;\n  \
    \      nodes.push_back(node);\n        return nodes.size() - 1;\n    }\n    static\
    \ int index(int c) {\n        assert(0 <= c - Base && c - Base < K);\n       \
    \ return c - Base;\n    }\n\n   public:\n    AhoCorasick() { add_node(-1, 0);\
    \ }\n\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3 s \u3092\u8FFD\u52A0\u3057\
    \u3001\u30D1\u30BF\u30FC\u30F3\u306E\u756A\u53F7 (\u8FFD\u52A0\u3057\u305F\u9806\
    \u306B 0, 1, ...) \u3092\u8FD4\u3059 O(|s|)\n     * \u7A7A\u3067\u306A\u3044\u6587\
    \u5B57\u5217\u306B\u9650\u308B\u3002\u540C\u3058\u30D1\u30BF\u30FC\u30F3\u3092\
    \u4F55\u5EA6\u3082\u8FFD\u52A0\u3067\u304D\u3001\u5225\u306E\u30D1\u30BF\u30FC\
    \u30F3\u3068\u3057\u3066\u6570\u3048\u308B\n     * @param s std::string \u3084\
    \ std::vector<int> \u306A\u3069\u3001\u8981\u7D20\u3092\u6574\u6570\u306B\u5909\
    \u63DB\u3067\u304D\u308B\u5217\n     */\n    template <typename R>\n    long long\
    \ add(const R& s) {\n        assert(!built);\n        assert(std::begin(s) !=\
    \ std::end(s));\n        int v = 0;\n        for (auto c : s) {\n            int\
    \ i = index(c);\n            if (nodes[v].next[i] == -1) {\n                int\
    \ u = add_node(v, nodes[v].depth + 1);\n                nodes[v].next[i] = u;\n\
    \            }\n            v = nodes[v].next[i];\n        }\n        int id =\
    \ pattern_node.size();\n        pattern_node.push_back(v);\n        next_pattern.push_back(nodes[v].head);\n\
    \        nodes[v].head = id;\n        return id;\n    }\n\n    /**\n     * @brief\
    \ \u5931\u6557\u30EA\u30F3\u30AF\u3068\u9077\u79FB\u3092\u4F5C\u308B\u3002\u30D1\
    \u30BF\u30FC\u30F3\u3092\u8FFD\u52A0\u3057\u7D42\u3048\u3066\u304B\u3089 1 \u56DE\
    \u3060\u3051\u547C\u3076 O(K * \u30CE\u30FC\u30C9\u6570)\n     */\n    void build()\
    \ {\n        assert(!built);\n        built = true;\n        for (int v = 0; v\
    \ < static_cast<int>(nodes.size()); v++) {\n            // \u540C\u3058\u30CE\u30FC\
    \u30C9\u3067\u7D42\u308F\u308B\u30D1\u30BF\u30FC\u30F3\u306E\u30EA\u30B9\u30C8\
    \u3092\u3001\u8FFD\u52A0\u3057\u305F\u9806\u306B\u4E26\u3079\u76F4\u3059\n   \
    \         int rev = -1;\n            for (int id = nodes[v].head; id != -1;) {\n\
    \                int nx = next_pattern[id];\n                next_pattern[id]\
    \ = rev;\n                rev = id;\n                id = nx;\n              \
    \  nodes[v].match_count++;\n            }\n            nodes[v].head = rev;\n\
    \        }\n        bfs_order.reserve(nodes.size());\n        bfs_order.push_back(0);\n\
    \        for (int i = 0; i < static_cast<int>(bfs_order.size()); i++) {\n    \
    \        int v = bfs_order[i];\n            for (int c = 0; c < K; c++) {\n  \
    \              int u = nodes[v].next[c];\n                // \u307E\u3060 -1 \u306A\
    \u3089 Trie \u306E\u5B50\u306F\u306A\u3044\u3002\u5931\u6557\u30EA\u30F3\u30AF\
    \u5148\u304B\u3089\u306E\u9077\u79FB\u3092\u4F7F\u3046\n                if (u\
    \ == -1) {\n                    nodes[v].next[c] = v == 0 ? 0 : nodes[nodes[v].link].next[c];\n\
    \                    continue;\n                }\n                int l = v ==\
    \ 0 ? 0 : nodes[nodes[v].link].next[c];\n                nodes[u].link = l;\n\
    \                nodes[u].out = nodes[l].head != -1 ? l : nodes[l].out;\n    \
    \            nodes[u].match_count += nodes[l].match_count;\n                bfs_order.push_back(u);\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9\u306E\
    \u500B\u6570 (\u6839\u3092\u542B\u3080)\n     */\n    long long size() const {\
    \ return nodes.size(); }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3\u306E\
    \u500B\u6570\n     */\n    long long pattern_count() const { return pattern_node.size();\
    \ }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3 i \u304C\u7D42\u308F\u308B\
    \u30CE\u30FC\u30C9\n     */\n    long long node(long long i) const {\n       \
    \ assert(0 <= i && i < pattern_count());\n        return pattern_node[i];\n  \
    \  }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u89AA (\u6839\u306A\u3089\
    \ -1)\n     */\n    long long parent(long long v) const { return nodes[v].parent;\
    \ }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u6DF1\u3055 (\u5BFE\u5FDC\
    \u3059\u308B\u6587\u5B57\u5217\u306E\u9577\u3055)\n     */\n    long long depth(long\
    \ long v) const { return nodes[v].depth; }\n\n    /**\n     * @brief \u30CE\u30FC\
    \u30C9 v \u306E\u5931\u6557\u30EA\u30F3\u30AF (v \u306E\u6587\u5B57\u5217\u306E\
    \u6700\u9577\u306E\u771F\u306E\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001\u30CE\
    \u30FC\u30C9\u306E\u3042\u308B\u3082\u306E)\u3002\u6839\u306A\u3089 -1\n     */\n\
    \    long long link(long long v) const {\n        assert(built);\n        return\
    \ v == 0 ? -1 : nodes[v].link;\n    }\n    /**\n     * @brief \u30CE\u30FC\u30C9\
    \ v \u3067\u6587\u5B57 c \u3092\u8AAD\u3093\u3060\u3068\u304D\u306B\u79FB\u308B\
    \u30CE\u30FC\u30C9\n     */\n    long long next(long long v, int c) const {\n\
    \        assert(built);\n        return nodes[v].next[index(c)];\n    }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u306E\u6587\u5B57\u5217\u306E\u63A5\u5C3E\
    \u8F9E\u306B\u306A\u3063\u3066\u3044\u308B\u30D1\u30BF\u30FC\u30F3\u306E\u500B\
    \u6570 (v \u306B\u7740\u3044\u305F\u3068\u304D\u306B\u7D42\u308F\u308B\u30D1\u30BF\
    \u30FC\u30F3\u306E\u500B\u6570)\n     */\n    long long match_count(long long\
    \ v) const {\n        assert(built);\n        return nodes[v].match_count;\n \
    \   }\n\n    /**\n     * @brief text \u306B\u73FE\u308C\u308B\u30D1\u30BF\u30FC\
    \u30F3\u306E\u500B\u6570\u306E\u5408\u8A08 (\u540C\u3058\u30D1\u30BF\u30FC\u30F3\
    \u304C\u4F55\u56DE\u73FE\u308C\u3066\u3082\u3001\u3059\u3079\u3066\u6570\u3048\
    \u308B) O(|text|)\n     */\n    template <typename R>\n    long long count(const\
    \ R& text) const {\n        assert(built);\n        long long res = 0;\n     \
    \   int v = 0;\n        for (auto c : text) {\n            v = nodes[v].next[index(c)];\n\
    \            res += nodes[v].match_count;\n        }\n        return res;\n  \
    \  }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3\u3054\u3068\u306B\u3001\
    text \u306B\u73FE\u308C\u308B\u56DE\u6570\u3092\u8FD4\u3059 O(|text| + \u30CE\u30FC\
    \u30C9\u6570 + \u30D1\u30BF\u30FC\u30F3\u6570)\n     */\n    template <typename\
    \ R>\n    std::vector<long long> count_each(const R& text) const {\n        assert(built);\n\
    \        std::vector<long long> visit(nodes.size());\n        int v = 0;\n   \
    \     for (auto c : text) {\n            v = nodes[v].next[index(c)];\n      \
    \      visit[v]++;\n        }\n        // \u5931\u6557\u30EA\u30F3\u30AF\u306E\
    \u6728\u3067\u3001\u8449\u306E\u65B9\u304B\u3089\u56DE\u6570\u3092\u8DB3\u3057\
    \u4E0A\u3052\u308B\n        for (int i = static_cast<int>(bfs_order.size()) -\
    \ 1; i > 0; i--) {\n            int u = bfs_order[i];\n            visit[nodes[u].link]\
    \ += visit[u];\n        }\n        std::vector<long long> res(pattern_node.size());\n\
    \        for (int i = 0; i < static_cast<int>(pattern_node.size()); i++) res[i]\
    \ = visit[pattern_node[i]];\n        return res;\n    }\n    /**\n     * @brief\
    \ text \u306B\u73FE\u308C\u308B\u30D1\u30BF\u30FC\u30F3\u3092\u3059\u3079\u3066\
    \ (\u958B\u59CB\u4F4D\u7F6E, \u30D1\u30BF\u30FC\u30F3\u306E\u756A\u53F7) \u306E\
    \u7D44\u3067\u8FD4\u3059 O(|text| + \u51FA\u529B\u306E\u500B\u6570)\n     * \u7D42\
    \u308F\u308B\u4F4D\u7F6E\u306E\u9806\u306B\u4E26\u3073\u3001\u540C\u3058\u4F4D\
    \u7F6E\u3067\u7D42\u308F\u308B\u3082\u306E\u306F\u9577\u3044\u30D1\u30BF\u30FC\
    \u30F3\u304B\u3089\u3001\u540C\u3058\u30D1\u30BF\u30FC\u30F3\u306F\u756A\u53F7\
    \u306E\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n     */\n    template <typename\
    \ R>\n    std::vector<std::pair<long long, long long>> find_all(const R& text)\
    \ const {\n        assert(built);\n        std::vector<std::pair<long long, long\
    \ long>> res;\n        int v = 0;\n        long long pos = 0;\n        for (auto\
    \ c : text) {\n            v = nodes[v].next[index(c)];\n            pos++;\n\
    \            for (int u = nodes[v].head != -1 ? v : nodes[v].out; u != -1; u =\
    \ nodes[u].out) {\n                for (int id = nodes[u].head; id != -1; id =\
    \ next_pattern[id]) res.emplace_back(pos - nodes[u].depth, id);\n            }\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file aho-corasick.hpp\n * @brief Aho-Corasick\n\
    \ */\n\n#include <array>\n#include <cassert>\n#include <iterator>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief Aho-Corasick (\u8907\u6570\u306E\u30D1\u30BF\
    \u30FC\u30F3\u306E\u7167\u5408)\n *\n * \u30D1\u30BF\u30FC\u30F3\u3092 add \u3067\
    \u8FFD\u52A0\u3057\u3066\u304B\u3089 build \u3092\u547C\u3076\u3002\u6587\u5B57\
    \ c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\
    \u53F7\u306B\u76F4\u3059\n * \u30CE\u30FC\u30C9\u306F Trie \u3068\u540C\u3058\u304F\
    \u3001\u6587\u5B57\u5217\u3092\u8FFD\u52A0\u3057\u305F\u9806\u306B\u4F5C\u3063\
    \u305F\u756A\u53F7\u3092\u6301\u3064\u3002\u6839\u306F\u30CE\u30FC\u30C9 0 (\u7A7A\
    \u6587\u5B57\u5217)\n * \u4F8B:\n * AhoCorasick<26, 'a'> ac;\n * ac.add(\"he\"\
    );\n * ac.add(\"she\");\n * ac.build();\n * ac.count(\"ushers\");  // 2 (\"she\"\
    \ \u3068 \"he\")\n *\n * @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam\
    \ Base \u6700\u5C0F\u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\n\
    class AhoCorasick {\n    struct Node {\n        std::array<int, K> next;  // build\
    \ \u524D\u306F Trie \u306E\u5B50 (\u306A\u3051\u308C\u3070 -1)\u3001build \u5F8C\
    \u306F\u6587\u5B57\u3092\u8AAD\u3093\u3060\u3068\u304D\u306E\u9077\u79FB\u5148\
    \n        int parent, depth;\n        int link;         // \u5931\u6557\u30EA\u30F3\
    \u30AF (\u3053\u306E\u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\u306E\u3001\u6700\
    \u9577\u306E\u771F\u306E\u63A5\u5C3E\u8F9E\u306E\u30CE\u30FC\u30C9)\n        int\
    \ out;          // \u5931\u6557\u30EA\u30F3\u30AF\u3092\u305F\u3069\u3063\u3066\
    \u6700\u521D\u306B\u7740\u304F\u3001\u30D1\u30BF\u30FC\u30F3\u304C\u7D42\u308F\
    \u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1)\n        int head;    \
    \     // \u3053\u306E\u30CE\u30FC\u30C9\u3067\u7D42\u308F\u308B\u30D1\u30BF\u30FC\
    \u30F3\u306E\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u306E\u5148\u982D (\u306A\u3051\
    \u308C\u3070 -1)\n        int match_count;  // \u3053\u306E\u30CE\u30FC\u30C9\u306E\
    \u6587\u5B57\u5217\u306E\u63A5\u5C3E\u8F9E\u306B\u306A\u3063\u3066\u3044\u308B\
    \u30D1\u30BF\u30FC\u30F3\u306E\u500B\u6570\n    };\n    // \u30E1\u30E2\u30EA\u3092\
    \u6291\u3048\u308B\u305F\u3081\u3001\u30CE\u30FC\u30C9\u306E\u4E2D\u8EAB\u306F\
    \ int \u3067\u6301\u3064\u3002\u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long\
    \ long \u306B\u3059\u308B\n    std::vector<Node> nodes;\n    std::vector<int>\
    \ pattern_node, next_pattern;  // \u30D1\u30BF\u30FC\u30F3\u306E\u7D42\u308F\u308B\
    \u30CE\u30FC\u30C9\u3068\u3001\u540C\u3058\u30CE\u30FC\u30C9\u3067\u7D42\u308F\
    \u308B\u6B21\u306E\u30D1\u30BF\u30FC\u30F3\n    std::vector<int> bfs_order;\n\
    \    bool built = false;\n\n    int add_node(int parent, int depth) {\n      \
    \  Node node;\n        node.next.fill(-1);\n        node.parent = parent;\n  \
    \      node.depth = depth;\n        node.link = 0;\n        node.out = node.head\
    \ = -1;\n        node.match_count = 0;\n        nodes.push_back(node);\n     \
    \   return nodes.size() - 1;\n    }\n    static int index(int c) {\n        assert(0\
    \ <= c - Base && c - Base < K);\n        return c - Base;\n    }\n\n   public:\n\
    \    AhoCorasick() { add_node(-1, 0); }\n\n    /**\n     * @brief \u30D1\u30BF\
    \u30FC\u30F3 s \u3092\u8FFD\u52A0\u3057\u3001\u30D1\u30BF\u30FC\u30F3\u306E\u756A\
    \u53F7 (\u8FFD\u52A0\u3057\u305F\u9806\u306B 0, 1, ...) \u3092\u8FD4\u3059 O(|s|)\n\
    \     * \u7A7A\u3067\u306A\u3044\u6587\u5B57\u5217\u306B\u9650\u308B\u3002\u540C\
    \u3058\u30D1\u30BF\u30FC\u30F3\u3092\u4F55\u5EA6\u3082\u8FFD\u52A0\u3067\u304D\
    \u3001\u5225\u306E\u30D1\u30BF\u30FC\u30F3\u3068\u3057\u3066\u6570\u3048\u308B\
    \n     * @param s std::string \u3084 std::vector<int> \u306A\u3069\u3001\u8981\
    \u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n     */\n\
    \    template <typename R>\n    long long add(const R& s) {\n        assert(!built);\n\
    \        assert(std::begin(s) != std::end(s));\n        int v = 0;\n        for\
    \ (auto c : s) {\n            int i = index(c);\n            if (nodes[v].next[i]\
    \ == -1) {\n                int u = add_node(v, nodes[v].depth + 1);\n       \
    \         nodes[v].next[i] = u;\n            }\n            v = nodes[v].next[i];\n\
    \        }\n        int id = pattern_node.size();\n        pattern_node.push_back(v);\n\
    \        next_pattern.push_back(nodes[v].head);\n        nodes[v].head = id;\n\
    \        return id;\n    }\n\n    /**\n     * @brief \u5931\u6557\u30EA\u30F3\u30AF\
    \u3068\u9077\u79FB\u3092\u4F5C\u308B\u3002\u30D1\u30BF\u30FC\u30F3\u3092\u8FFD\
    \u52A0\u3057\u7D42\u3048\u3066\u304B\u3089 1 \u56DE\u3060\u3051\u547C\u3076 O(K\
    \ * \u30CE\u30FC\u30C9\u6570)\n     */\n    void build() {\n        assert(!built);\n\
    \        built = true;\n        for (int v = 0; v < static_cast<int>(nodes.size());\
    \ v++) {\n            // \u540C\u3058\u30CE\u30FC\u30C9\u3067\u7D42\u308F\u308B\
    \u30D1\u30BF\u30FC\u30F3\u306E\u30EA\u30B9\u30C8\u3092\u3001\u8FFD\u52A0\u3057\
    \u305F\u9806\u306B\u4E26\u3079\u76F4\u3059\n            int rev = -1;\n      \
    \      for (int id = nodes[v].head; id != -1;) {\n                int nx = next_pattern[id];\n\
    \                next_pattern[id] = rev;\n                rev = id;\n        \
    \        id = nx;\n                nodes[v].match_count++;\n            }\n  \
    \          nodes[v].head = rev;\n        }\n        bfs_order.reserve(nodes.size());\n\
    \        bfs_order.push_back(0);\n        for (int i = 0; i < static_cast<int>(bfs_order.size());\
    \ i++) {\n            int v = bfs_order[i];\n            for (int c = 0; c < K;\
    \ c++) {\n                int u = nodes[v].next[c];\n                // \u307E\
    \u3060 -1 \u306A\u3089 Trie \u306E\u5B50\u306F\u306A\u3044\u3002\u5931\u6557\u30EA\
    \u30F3\u30AF\u5148\u304B\u3089\u306E\u9077\u79FB\u3092\u4F7F\u3046\n         \
    \       if (u == -1) {\n                    nodes[v].next[c] = v == 0 ? 0 : nodes[nodes[v].link].next[c];\n\
    \                    continue;\n                }\n                int l = v ==\
    \ 0 ? 0 : nodes[nodes[v].link].next[c];\n                nodes[u].link = l;\n\
    \                nodes[u].out = nodes[l].head != -1 ? l : nodes[l].out;\n    \
    \            nodes[u].match_count += nodes[l].match_count;\n                bfs_order.push_back(u);\n\
    \            }\n        }\n    }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9\u306E\
    \u500B\u6570 (\u6839\u3092\u542B\u3080)\n     */\n    long long size() const {\
    \ return nodes.size(); }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3\u306E\
    \u500B\u6570\n     */\n    long long pattern_count() const { return pattern_node.size();\
    \ }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3 i \u304C\u7D42\u308F\u308B\
    \u30CE\u30FC\u30C9\n     */\n    long long node(long long i) const {\n       \
    \ assert(0 <= i && i < pattern_count());\n        return pattern_node[i];\n  \
    \  }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u89AA (\u6839\u306A\u3089\
    \ -1)\n     */\n    long long parent(long long v) const { return nodes[v].parent;\
    \ }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u6DF1\u3055 (\u5BFE\u5FDC\
    \u3059\u308B\u6587\u5B57\u5217\u306E\u9577\u3055)\n     */\n    long long depth(long\
    \ long v) const { return nodes[v].depth; }\n\n    /**\n     * @brief \u30CE\u30FC\
    \u30C9 v \u306E\u5931\u6557\u30EA\u30F3\u30AF (v \u306E\u6587\u5B57\u5217\u306E\
    \u6700\u9577\u306E\u771F\u306E\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001\u30CE\
    \u30FC\u30C9\u306E\u3042\u308B\u3082\u306E)\u3002\u6839\u306A\u3089 -1\n     */\n\
    \    long long link(long long v) const {\n        assert(built);\n        return\
    \ v == 0 ? -1 : nodes[v].link;\n    }\n    /**\n     * @brief \u30CE\u30FC\u30C9\
    \ v \u3067\u6587\u5B57 c \u3092\u8AAD\u3093\u3060\u3068\u304D\u306B\u79FB\u308B\
    \u30CE\u30FC\u30C9\n     */\n    long long next(long long v, int c) const {\n\
    \        assert(built);\n        return nodes[v].next[index(c)];\n    }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u306E\u6587\u5B57\u5217\u306E\u63A5\u5C3E\
    \u8F9E\u306B\u306A\u3063\u3066\u3044\u308B\u30D1\u30BF\u30FC\u30F3\u306E\u500B\
    \u6570 (v \u306B\u7740\u3044\u305F\u3068\u304D\u306B\u7D42\u308F\u308B\u30D1\u30BF\
    \u30FC\u30F3\u306E\u500B\u6570)\n     */\n    long long match_count(long long\
    \ v) const {\n        assert(built);\n        return nodes[v].match_count;\n \
    \   }\n\n    /**\n     * @brief text \u306B\u73FE\u308C\u308B\u30D1\u30BF\u30FC\
    \u30F3\u306E\u500B\u6570\u306E\u5408\u8A08 (\u540C\u3058\u30D1\u30BF\u30FC\u30F3\
    \u304C\u4F55\u56DE\u73FE\u308C\u3066\u3082\u3001\u3059\u3079\u3066\u6570\u3048\
    \u308B) O(|text|)\n     */\n    template <typename R>\n    long long count(const\
    \ R& text) const {\n        assert(built);\n        long long res = 0;\n     \
    \   int v = 0;\n        for (auto c : text) {\n            v = nodes[v].next[index(c)];\n\
    \            res += nodes[v].match_count;\n        }\n        return res;\n  \
    \  }\n    /**\n     * @brief \u30D1\u30BF\u30FC\u30F3\u3054\u3068\u306B\u3001\
    text \u306B\u73FE\u308C\u308B\u56DE\u6570\u3092\u8FD4\u3059 O(|text| + \u30CE\u30FC\
    \u30C9\u6570 + \u30D1\u30BF\u30FC\u30F3\u6570)\n     */\n    template <typename\
    \ R>\n    std::vector<long long> count_each(const R& text) const {\n        assert(built);\n\
    \        std::vector<long long> visit(nodes.size());\n        int v = 0;\n   \
    \     for (auto c : text) {\n            v = nodes[v].next[index(c)];\n      \
    \      visit[v]++;\n        }\n        // \u5931\u6557\u30EA\u30F3\u30AF\u306E\
    \u6728\u3067\u3001\u8449\u306E\u65B9\u304B\u3089\u56DE\u6570\u3092\u8DB3\u3057\
    \u4E0A\u3052\u308B\n        for (int i = static_cast<int>(bfs_order.size()) -\
    \ 1; i > 0; i--) {\n            int u = bfs_order[i];\n            visit[nodes[u].link]\
    \ += visit[u];\n        }\n        std::vector<long long> res(pattern_node.size());\n\
    \        for (int i = 0; i < static_cast<int>(pattern_node.size()); i++) res[i]\
    \ = visit[pattern_node[i]];\n        return res;\n    }\n    /**\n     * @brief\
    \ text \u306B\u73FE\u308C\u308B\u30D1\u30BF\u30FC\u30F3\u3092\u3059\u3079\u3066\
    \ (\u958B\u59CB\u4F4D\u7F6E, \u30D1\u30BF\u30FC\u30F3\u306E\u756A\u53F7) \u306E\
    \u7D44\u3067\u8FD4\u3059 O(|text| + \u51FA\u529B\u306E\u500B\u6570)\n     * \u7D42\
    \u308F\u308B\u4F4D\u7F6E\u306E\u9806\u306B\u4E26\u3073\u3001\u540C\u3058\u4F4D\
    \u7F6E\u3067\u7D42\u308F\u308B\u3082\u306E\u306F\u9577\u3044\u30D1\u30BF\u30FC\
    \u30F3\u304B\u3089\u3001\u540C\u3058\u30D1\u30BF\u30FC\u30F3\u306F\u756A\u53F7\
    \u306E\u5C0F\u3055\u3044\u9806\u306B\u4E26\u3076\n     */\n    template <typename\
    \ R>\n    std::vector<std::pair<long long, long long>> find_all(const R& text)\
    \ const {\n        assert(built);\n        std::vector<std::pair<long long, long\
    \ long>> res;\n        int v = 0;\n        long long pos = 0;\n        for (auto\
    \ c : text) {\n            v = nodes[v].next[index(c)];\n            pos++;\n\
    \            for (int u = nodes[v].head != -1 ? v : nodes[v].out; u != -1; u =\
    \ nodes[u].out) {\n                for (int id = nodes[u].head; id != -1; id =\
    \ next_pattern[id]) res.emplace_back(pos - nodes[u].depth, id);\n            }\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/aho-corasick.hpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/aho-corasick.test.cpp
  - test/aoj/volume28/2873.test.cpp
  - test/yosupo/string/aho-corasick.test.cpp
documentation_of: src/string/aho-corasick.hpp
layout: document
title: Aho-Corasick
---

複数のパターンを、文字列の中から一度に探す `AhoCorasick<K, Base>` です。パターンを `add` で追加してから `build` を呼びます。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。

```cpp
AhoCorasick<26, 'a'> ac;
ac.add("he");                 // パターン 0
ac.add("she");                // パターン 1
ac.add("hers");               // パターン 2
ac.build();
ac.count("ushers");           // 3 ("she"、"he"、"hers")
ac.count_each("ushers");      // {1, 1, 1}
ac.find_all("ushers");        // { {1, 1}, {2, 0}, {2, 2} } (開始位置, パターンの番号)

// オートマトンの上の DP: ノードを状態にして、文字を読むたびに next で移る
long long v = 0;
for (char c : text) {
    v = ac.next(v, c);
    if (ac.match_count(v) > 0) { /* ここで終わるパターンがある */ }
}
```

ノードは [Trie](trie.hpp) と同じく、文字列を追加した順に作った番号を持ちます。根はノード 0 (空文字列) です。パターンは空でない文字列に限ります。同じパターンを何度も追加でき、別のパターンとして数えます。

ノードの番号・個数などは `long long` です。ノードの中身は `int` で持つので、メモリはノード 1 つあたり $4K + 24$ バイトです。

$L$ をパターンの長さの合計 (ノード数は $L + 1$ 以下)、$P$ をパターンの個数、$\lvert t \rvert$ を探す文字列の長さとします。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `AhoCorasick<K, Base>()` | 空の状態 (根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `add(s)` | パターン `s` を追加し、パターンの番号 (追加した順に 0, 1, ...) を返す。`build` の前に呼ぶ | $O(\lvert s \rvert K)$ |
| `build()` | 失敗リンクと遷移を作る。パターンを追加し終えてから 1 回だけ呼ぶ | $O(LK)$ |
| `count(t)` | `t` に現れるパターンの個数の合計 (同じパターンの出現もすべて数える) | $O(\lvert t \rvert)$ |
| `count_each(t)` | パターンごとの、`t` に現れる回数の `std::vector<long long>` | $O(\lvert t \rvert + L + P)$ |
| `find_all(t)` | `t` に現れるパターンをすべて `(開始位置, パターンの番号)` の組で返す。終わる位置の順に並び、同じ位置で終わるものは長いパターンから、同じパターンは番号の小さい順に並ぶ | $O(\lvert t \rvert + \text{出力の個数})$ |
| `next(v, c)` | ノード `v` で文字 `c` を読んだときに移るノード | $O(1)$ |
| `match_count(v)` | ノード `v` の文字列の接尾辞になっているパターンの個数 (`v` に着いたときに終わるパターンの個数) | $O(1)$ |
| `link(v)` | 失敗リンク (`v` の文字列の最長の真の接尾辞のうち、ノードのあるもの)。根なら -1 | $O(1)$ |
| `node(i)` | パターン `i` が終わるノード | $O(1)$ |
| `parent(v)` | ノード `v` の親 (根なら -1) | $O(1)$ |
| `depth(v)` | ノード `v` の深さ (対応する文字列の長さ) | $O(1)$ |
| `size()` | ノードの個数 (根を含む) | $O(1)$ |
| `pattern_count()` | パターンの個数 | $O(1)$ |

`count`・`count_each`・`find_all` の文字列や `add` のパターンは、`std::string` のほか `std::vector<int>` など、要素を整数に変換できる列なら何でもかまいません。`next`・`match_count`・`link` と照合の関数は、`build` の後に呼びます。

## 関連

- パターンを増やしたり減らしたりしながら接頭辞を数えるなら [Trie](trie.hpp)
- パターンが 1 つなら [文字列アルゴリズム](string.hpp) の KMP 法や Z-algorithm
