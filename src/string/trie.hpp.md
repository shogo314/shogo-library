---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/alds1-4-c.test.cpp
    title: test/aoj/alds1-4-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/trie.test.cpp
    title: test/unittest/trie.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Trie
    links: []
  bundledCode: "#line 2 \"src/string/trie.hpp\"\n\n/**\n * @file trie.hpp\n * @brief\
    \ Trie\n */\n\n#include <array>\n#include <cassert>\n#include <vector>\n\n/**\n\
    \ * @brief Trie (\u6587\u5B57\u5217\u306E\u96C6\u5408\u3092\u63A5\u982D\u8F9E\u306E\
    \u6728\u3067\u7BA1\u7406\u3059\u308B)\n *\n * \u6587\u5B57 c \u306F c - Base \u3068\
    \u3057\u3066 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\
    \u3002\u6839\u306F\u30CE\u30FC\u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u540C\u3058\
    \u6587\u5B57\u5217\u3092\u4F55\u5EA6\u3082\u8FFD\u52A0\u3067\u304D\u3001\u591A\
    \u91CD\u96C6\u5408\u3068\u3057\u3066\u6271\u3046\n * \u4F8B:\n * Trie<26, 'a'>\
    \ trie;\n * trie.insert(\"abc\");\n * trie.count_prefix(\"ab\");  // 1\n *\n *\
    \ @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\u5C0F\
    \u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\nclass Trie {\n\
    \    struct Node {\n        std::array<int, K> next;\n        int parent, depth;\n\
    \        int prefix_cnt;  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B\
    \ (\u3053\u306E\u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\
    \u306B\u6301\u3064) \u6587\u5B57\u5217\u306E\u500B\u6570\n        int word_cnt;\
    \    // \u3053\u306E\u30CE\u30FC\u30C9\u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\
    \u306E\u500B\u6570\n    };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\
    \u3081\u3001\u30CE\u30FC\u30C9\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\u3002\
    \u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n    std::vector<Node>\
    \ nodes;\n\n    int add_node(int parent, int depth) {\n        Node node;\n  \
    \      node.next.fill(-1);\n        node.parent = parent;\n        node.depth\
    \ = depth;\n        node.prefix_cnt = node.word_cnt = 0;\n        nodes.push_back(node);\n\
    \        return nodes.size() - 1;\n    }\n    static int index(int c) {\n    \
    \    assert(0 <= c - Base && c - Base < K);\n        return c - Base;\n    }\n\
    \    // \u6587\u5B57\u5217 s \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \ (\u306A\u3051\u308C\u3070 -1)\n    template <typename R>\n    int find_node(const\
    \ R& s) const {\n        int v = 0;\n        for (auto c : s) {\n            v\
    \ = nodes[v].next[index(c)];\n            if (v == -1) return -1;\n        }\n\
    \        return v;\n    }\n\n   public:\n    Trie() { add_node(-1, 0); }\n\n \
    \   /**\n     * @brief \u30CE\u30FC\u30C9\u306E\u500B\u6570 (\u6839\u3092\u542B\
    \u3080)\n     */\n    long long size() const { return nodes.size(); }\n\n    /**\n\
    \     * @brief \u6587\u5B57\u5217 s \u3092 1 \u500B\u8FFD\u52A0\u3057\u3001s \u306B\
    \u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u8FD4\u3059 O(|s|)\n     * @param\
    \ s std::string \u3084 std::vector<int> \u306A\u3069\u3001\u8981\u7D20\u3092\u6574\
    \u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n     */\n    template <typename\
    \ R>\n    long long insert(const R& s) {\n        int v = 0;\n        nodes[v].prefix_cnt++;\n\
    \        for (auto c : s) {\n            int i = index(c);\n            if (nodes[v].next[i]\
    \ == -1) {\n                int u = add_node(v, nodes[v].depth + 1);\n       \
    \         nodes[v].next[i] = u;\n            }\n            v = nodes[v].next[i];\n\
    \            nodes[v].prefix_cnt++;\n        }\n        nodes[v].word_cnt++;\n\
    \        return v;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u3092\
    \ 1 \u500B\u53D6\u308A\u9664\u304F\u3002s \u304C\u306A\u3051\u308C\u3070\u4F55\
    \u3082\u305B\u305A false \u3092\u8FD4\u3059 O(|s|)\n     * \u30CE\u30FC\u30C9\u306F\
    \u524A\u9664\u3057\u306A\u3044\u306E\u3067\u3001\u30CE\u30FC\u30C9\u306E\u756A\
    \u53F7\u306F\u5909\u308F\u3089\u306A\u3044\n     */\n    template <typename R>\n\
    \    bool erase(const R& s) {\n        int v = find_node(s);\n        if (v ==\
    \ -1 || nodes[v].word_cnt == 0) return false;\n        nodes[v].word_cnt--;\n\
    \        for (; v != -1; v = nodes[v].parent) nodes[v].prefix_cnt--;\n       \
    \ return true;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306B\u5BFE\
    \u5FDC\u3059\u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1) O(|s|)\n  \
    \   * s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\u5B57\u5217\u3092\u8FFD\
    \u52A0\u3057\u305F\u3053\u3068\u304C\u3042\u308C\u3070\u3001\u53D6\u308A\u9664\
    \u3044\u305F\u5F8C\u3067\u3082\u30CE\u30FC\u30C9\u306F\u6B8B\u308B\n     */\n\
    \    template <typename R>\n    long long find(const R& s) const { return find_node(s);\
    \ }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306E\u500B\u6570 O(|s|)\n\
    \     */\n    template <typename R>\n    long long count(const R& s) const {\n\
    \        int v = find_node(s);\n        return v == -1 ? 0 : nodes[v].word_cnt;\n\
    \    }\n    /**\n     * @brief s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\
    \u5B57\u5217\u306E\u500B\u6570 O(|s|)\n     */\n    template <typename R>\n  \
    \  long long count_prefix(const R& s) const {\n        int v = find_node(s);\n\
    \        return v == -1 ? 0 : nodes[v].prefix_cnt;\n    }\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217\u306E\u500B\u6570 (\u91CD\u8907\u3092\u542B\u3080)\n    \
    \ */\n    long long total() const { return nodes[0].prefix_cnt; }\n\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u304B\u3089\u6587\u5B57 c \u3067\u9032\u3093\
    \u3060\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1)\n     */\n    long long\
    \ child(long long v, int c) const { return nodes[v].next[index(c)]; }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u306E\u89AA (\u6839\u306A\u3089 -1)\n   \
    \  */\n    long long parent(long long v) const { return nodes[v].parent; }\n \
    \   /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u6DF1\u3055 (\u5BFE\u5FDC\u3059\
    \u308B\u6587\u5B57\u5217\u306E\u9577\u3055)\n     */\n    long long depth(long\
    \ long v) const { return nodes[v].depth; }\n    /**\n     * @brief \u30CE\u30FC\
    \u30C9 v \u3092\u901A\u308B (v \u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\
    \u306B\u6301\u3064) \u6587\u5B57\u5217\u306E\u500B\u6570\n     */\n    long long\
    \ count_prefix_at(long long v) const { return nodes[v].prefix_cnt; }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\
    \u306E\u500B\u6570\n     */\n    long long count_at(long long v) const { return\
    \ nodes[v].word_cnt; }\n\n    /**\n     * @brief s \u306E\u63A5\u982D\u8F9E\u306E\
    \u3046\u3061\u3001\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u3069\u308C\
    \u304B\u306E\u63A5\u982D\u8F9E\u306B\u3082\u306A\u3063\u3066\u3044\u308B\u3082\
    \u306E\u306E\u6700\u9577\u306E\u9577\u3055 O(|s|)\n     * \u8FFD\u52A0\u3057\u305F\
    \u6587\u5B57\u5217 (\u53D6\u308A\u9664\u3044\u305F\u3082\u306E\u306F\u9664\u304F\
    ) \u306E\u3069\u308C\u304B\u3068\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055\u306E\u6700\u5927\u5024\u306B\u306A\u308B\n     */\n    template\
    \ <typename R>\n    long long longest_common_prefix(const R& s) const {\n    \
    \    int v = 0;\n        long long len = 0;\n        for (auto c : s) {\n    \
    \        int u = nodes[v].next[index(c)];\n            if (u == -1 || nodes[u].prefix_cnt\
    \ == 0) break;\n            v = u;\n            len++;\n        }\n        return\
    \ len;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file trie.hpp\n * @brief Trie\n */\n\n#include <array>\n\
    #include <cassert>\n#include <vector>\n\n/**\n * @brief Trie (\u6587\u5B57\u5217\
    \u306E\u96C6\u5408\u3092\u63A5\u982D\u8F9E\u306E\u6728\u3067\u7BA1\u7406\u3059\
    \u308B)\n *\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A\
    \ K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\u3002\u6839\u306F\u30CE\u30FC\
    \u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u540C\u3058\u6587\u5B57\u5217\u3092\u4F55\
    \u5EA6\u3082\u8FFD\u52A0\u3067\u304D\u3001\u591A\u91CD\u96C6\u5408\u3068\u3057\
    \u3066\u6271\u3046\n * \u4F8B:\n * Trie<26, 'a'> trie;\n * trie.insert(\"abc\"\
    );\n * trie.count_prefix(\"ab\");  // 1\n *\n * @tparam K \u6587\u5B57\u306E\u7A2E\
    \u985E\u6570\n * @tparam Base \u6700\u5C0F\u306E\u6587\u5B57\n */\ntemplate <int\
    \ K = 26, int Base = 'a'>\nclass Trie {\n    struct Node {\n        std::array<int,\
    \ K> next;\n        int parent, depth;\n        int prefix_cnt;  // \u3053\u306E\
    \u30CE\u30FC\u30C9\u3092\u901A\u308B (\u3053\u306E\u30CE\u30FC\u30C9\u306E\u6587\
    \u5B57\u5217\u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064) \u6587\u5B57\u5217\u306E\
    \u500B\u6570\n        int word_cnt;    // \u3053\u306E\u30CE\u30FC\u30C9\u3067\
    \u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n    };\n    // \u30E1\u30E2\
    \u30EA\u3092\u6291\u3048\u308B\u305F\u3081\u3001\u30CE\u30FC\u30C9\u306E\u4E2D\
    \u8EAB\u306F int \u3067\u6301\u3064\u3002\u5916\u3078\u8FD4\u3059\u3068\u304D\u306B\
    \ long long \u306B\u3059\u308B\n    std::vector<Node> nodes;\n\n    int add_node(int\
    \ parent, int depth) {\n        Node node;\n        node.next.fill(-1);\n    \
    \    node.parent = parent;\n        node.depth = depth;\n        node.prefix_cnt\
    \ = node.word_cnt = 0;\n        nodes.push_back(node);\n        return nodes.size()\
    \ - 1;\n    }\n    static int index(int c) {\n        assert(0 <= c - Base &&\
    \ c - Base < K);\n        return c - Base;\n    }\n    // \u6587\u5B57\u5217 s\
    \ \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1)\n\
    \    template <typename R>\n    int find_node(const R& s) const {\n        int\
    \ v = 0;\n        for (auto c : s) {\n            v = nodes[v].next[index(c)];\n\
    \            if (v == -1) return -1;\n        }\n        return v;\n    }\n\n\
    \   public:\n    Trie() { add_node(-1, 0); }\n\n    /**\n     * @brief \u30CE\u30FC\
    \u30C9\u306E\u500B\u6570 (\u6839\u3092\u542B\u3080)\n     */\n    long long size()\
    \ const { return nodes.size(); }\n\n    /**\n     * @brief \u6587\u5B57\u5217\
    \ s \u3092 1 \u500B\u8FFD\u52A0\u3057\u3001s \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\
    \u30FC\u30C9\u3092\u8FD4\u3059 O(|s|)\n     * @param s std::string \u3084 std::vector<int>\
    \ \u306A\u3069\u3001\u8981\u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\
    \u308B\u5217\n     */\n    template <typename R>\n    long long insert(const R&\
    \ s) {\n        int v = 0;\n        nodes[v].prefix_cnt++;\n        for (auto\
    \ c : s) {\n            int i = index(c);\n            if (nodes[v].next[i] ==\
    \ -1) {\n                int u = add_node(v, nodes[v].depth + 1);\n          \
    \      nodes[v].next[i] = u;\n            }\n            v = nodes[v].next[i];\n\
    \            nodes[v].prefix_cnt++;\n        }\n        nodes[v].word_cnt++;\n\
    \        return v;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u3092\
    \ 1 \u500B\u53D6\u308A\u9664\u304F\u3002s \u304C\u306A\u3051\u308C\u3070\u4F55\
    \u3082\u305B\u305A false \u3092\u8FD4\u3059 O(|s|)\n     * \u30CE\u30FC\u30C9\u306F\
    \u524A\u9664\u3057\u306A\u3044\u306E\u3067\u3001\u30CE\u30FC\u30C9\u306E\u756A\
    \u53F7\u306F\u5909\u308F\u3089\u306A\u3044\n     */\n    template <typename R>\n\
    \    bool erase(const R& s) {\n        int v = find_node(s);\n        if (v ==\
    \ -1 || nodes[v].word_cnt == 0) return false;\n        nodes[v].word_cnt--;\n\
    \        for (; v != -1; v = nodes[v].parent) nodes[v].prefix_cnt--;\n       \
    \ return true;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306B\u5BFE\
    \u5FDC\u3059\u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1) O(|s|)\n  \
    \   * s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\u5B57\u5217\u3092\u8FFD\
    \u52A0\u3057\u305F\u3053\u3068\u304C\u3042\u308C\u3070\u3001\u53D6\u308A\u9664\
    \u3044\u305F\u5F8C\u3067\u3082\u30CE\u30FC\u30C9\u306F\u6B8B\u308B\n     */\n\
    \    template <typename R>\n    long long find(const R& s) const { return find_node(s);\
    \ }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306E\u500B\u6570 O(|s|)\n\
    \     */\n    template <typename R>\n    long long count(const R& s) const {\n\
    \        int v = find_node(s);\n        return v == -1 ? 0 : nodes[v].word_cnt;\n\
    \    }\n    /**\n     * @brief s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\
    \u5B57\u5217\u306E\u500B\u6570 O(|s|)\n     */\n    template <typename R>\n  \
    \  long long count_prefix(const R& s) const {\n        int v = find_node(s);\n\
    \        return v == -1 ? 0 : nodes[v].prefix_cnt;\n    }\n    /**\n     * @brief\
    \ \u6587\u5B57\u5217\u306E\u500B\u6570 (\u91CD\u8907\u3092\u542B\u3080)\n    \
    \ */\n    long long total() const { return nodes[0].prefix_cnt; }\n\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u304B\u3089\u6587\u5B57 c \u3067\u9032\u3093\
    \u3060\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1)\n     */\n    long long\
    \ child(long long v, int c) const { return nodes[v].next[index(c)]; }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u306E\u89AA (\u6839\u306A\u3089 -1)\n   \
    \  */\n    long long parent(long long v) const { return nodes[v].parent; }\n \
    \   /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u6DF1\u3055 (\u5BFE\u5FDC\u3059\
    \u308B\u6587\u5B57\u5217\u306E\u9577\u3055)\n     */\n    long long depth(long\
    \ long v) const { return nodes[v].depth; }\n    /**\n     * @brief \u30CE\u30FC\
    \u30C9 v \u3092\u901A\u308B (v \u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\
    \u306B\u6301\u3064) \u6587\u5B57\u5217\u306E\u500B\u6570\n     */\n    long long\
    \ count_prefix_at(long long v) const { return nodes[v].prefix_cnt; }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\
    \u306E\u500B\u6570\n     */\n    long long count_at(long long v) const { return\
    \ nodes[v].word_cnt; }\n\n    /**\n     * @brief s \u306E\u63A5\u982D\u8F9E\u306E\
    \u3046\u3061\u3001\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u3069\u308C\
    \u304B\u306E\u63A5\u982D\u8F9E\u306B\u3082\u306A\u3063\u3066\u3044\u308B\u3082\
    \u306E\u306E\u6700\u9577\u306E\u9577\u3055 O(|s|)\n     * \u8FFD\u52A0\u3057\u305F\
    \u6587\u5B57\u5217 (\u53D6\u308A\u9664\u3044\u305F\u3082\u306E\u306F\u9664\u304F\
    ) \u306E\u3069\u308C\u304B\u3068\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\
    \u306E\u9577\u3055\u306E\u6700\u5927\u5024\u306B\u306A\u308B\n     */\n    template\
    \ <typename R>\n    long long longest_common_prefix(const R& s) const {\n    \
    \    int v = 0;\n        long long len = 0;\n        for (auto c : s) {\n    \
    \        int u = nodes[v].next[index(c)];\n            if (u == -1 || nodes[u].prefix_cnt\
    \ == 0) break;\n            v = u;\n            len++;\n        }\n        return\
    \ len;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/trie.hpp
  requiredBy: []
  timestamp: '2026-10-15 03:36:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/trie.test.cpp
  - test/aoj/alds1-4-c.test.cpp
documentation_of: src/string/trie.hpp
layout: document
title: Trie
---

文字列の集合 (多重集合) を、接頭辞の木で管理する `Trie<K, Base>` です。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。根はノード 0 で、空文字列に対応します。文字列の操作は、文字列の長さを $L$ として $O(L)$ です。

```cpp
Trie<26, 'a'> trie;                // 英小文字
long long v = trie.insert("abc");  // 追加して、"abc" のノードを返す
trie.insert("abd");
trie.count_prefix("ab");           // 2 ("ab" で始まる文字列の個数)
trie.count("abc");                 // 1
trie.erase("abc");                 // 1 個取り除く
trie.find("x");                    // -1 (ノードがない)
```

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `Trie<K, Base>()` | 空の Trie (根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `insert(s)` | 文字列 `s` を 1 個追加し、`s` のノードを返す。同じ文字列を何度も追加できる | $O(LK)$ (新しいノード 1 つに $O(K)$) |
| `erase(s)` | `s` を 1 個取り除く。`s` がなければ何もせず `false` を返す。ノードは消さない | $O(L)$ |
| `find(s)` | `s` のノード (なければ -1)。`s` を接頭辞に持つ文字列を一度でも追加していればノードがある | $O(L)$ |
| `count(s)` | `s` の個数 | $O(L)$ |
| `count_prefix(s)` | `s` で始まる文字列の個数 (重複を含む) | $O(L)$ |
| `longest_common_prefix(s)` | 追加した文字列のどれかとの最長共通接頭辞の長さの最大値 | $O(L)$ |
| `total()` | 文字列の個数 (重複を含む) | $O(1)$ |
| `size()` | ノードの個数 (根を含む) | $O(1)$ |
| `child(v, c)` | ノード `v` から文字 `c` で進んだノード (なければ -1) | $O(1)$ |
| `parent(v)` | 親 (根なら -1) | $O(1)$ |
| `depth(v)` | 深さ (ノードの文字列の長さ) | $O(1)$ |
| `count_prefix_at(v)` | ノード `v` を通る (`v` の文字列で始まる) 文字列の個数 | $O(1)$ |
| `count_at(v)` | ノード `v` で終わる文字列の個数 | $O(1)$ |

- ノードの番号・個数・深さ・長さは `long long` で返し、ノードの番号も `long long` で受け取ります。文字 `c` は `int` です。
- `s` は `std::string` のほか、`std::vector<int>` などの整数の列でもかまいません (`Trie<10, 0>` に数字の列を入れるなど)。
- ノードは子の番号を `K` 個の配列で持つので、メモリは「ノード数 × (4K + 16) バイト」ほど使います。文字の種類が少ないときは `K` を小さくしてください。
- ノードの番号は追加した順に付き、親の番号は子より小さくなります。そのため、番号の大きい順に処理すれば葉から根へ向かう DP ができます。

## 例: すべての組の最長共通接頭辞の長さの和

文字列の組 $(i, j)$ の最長共通接頭辞の長さは、2 つが共通に通る根以外のノードの個数です。そのため、ノードごとに通る文字列の個数 $c$ から $\binom{c}{2}$ を足せば求められます。

```cpp
long long sum = 0;
for (long long v = 1; v < trie.size(); v++) {
    long long c = trie.count_prefix_at(v);
    sum += c * (c - 1) / 2;
}
```

## 関連

- 整数を 2 進数で入れる Trie は [Binary Trie](../data_structures/binary-trie.hpp)
- 1 つのパターンの検索は [文字列アルゴリズム](string.hpp) の KMP 法
- 複数のパターンを文字列の中から一度に探すなら [Aho-Corasick](aho-corasick.hpp)
