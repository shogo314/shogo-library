---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C
  bundledCode: "#line 1 \"test/aoj/alds1/alds1-4-c.test.cpp\"\n#define PROBLEM \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\n#line 2 \"src/string/trie.hpp\"\
    \n\n/**\n * @file trie.hpp\n * @brief Trie\n */\n\n#include <algorithm>\n#include\
    \ <array>\n#include <cassert>\n#include <string_view>\n#include <type_traits>\n\
    #include <utility>\n#line 15 \"src/string/trie.hpp\"\n\n/**\n * @brief Trie (\u6587\
    \u5B57\u5217\u306E\u96C6\u5408\u3092\u63A5\u982D\u8F9E\u306E\u6728\u3067\u7BA1\
    \u7406\u3059\u308B)\n *\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066\
    \ 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\u3002\u6839\
    \u306F\u30CE\u30FC\u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u540C\u3058\u6587\u5B57\
    \u5217\u3092\u4F55\u5EA6\u3082\u8FFD\u52A0\u3067\u304D\u3001\u591A\u91CD\u96C6\
    \u5408\u3068\u3057\u3066\u6271\u3046\n * \u30CE\u30FC\u30C9\u306F jump pointer\
    \ \u3092\u6301\u3061\u30012 \u3064\u306E\u30CE\u30FC\u30C9\u306E\u6700\u5C0F\u5171\
    \u901A\u7956\u5148\u3084\u6587\u5B57\u5217\u306E\u8F9E\u66F8\u9806\u306E\u6BD4\
    \u8F03\u304C O(log n) \u3067\u3067\u304D\u308B\n * \u4F8B:\n * Trie<26, 'a'> trie;\n\
    \ * trie.insert(\"abc\");\n * trie.count_prefix(\"ab\");  // 1\n *\n * @tparam\
    \ K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\u5C0F\u306E\u6587\
    \u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\nclass Trie {\n    struct Node\
    \ {\n        std::array<int, K> next;\n        int parent, depth;\n        int\
    \ ch;          // \u89AA\u304B\u3089\u6765\u305F\u8FBA\u306E\u6587\u5B57\u306E\
    \u756A\u53F7 (\u6839\u306F -1)\n        int jump;        // \u7956\u5148\u3078\
    \u306E\u98DB\u3073\u5148 (\u6DF1\u3055\u306E\u5DEE\u304C 1, 1, 3, 1, 1, 3, 7,\
    \ ... \u3068\u306A\u308B skew-binary \u306E\u98DB\u3073\u65B9)\n        int prefix_cnt;\
    \  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B (\u3053\u306E\u30CE\u30FC\
    \u30C9\u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064) \u6587\
    \u5B57\u5217\u306E\u500B\u6570\n        int word_cnt;    // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n   \
    \ };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081\u3001\u30CE\
    \u30FC\u30C9\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\u3002\u5916\u3078\u8FD4\
    \u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n    std::vector<Node> nodes;\n\
    \n    int add_node(int parent, int ch) {\n        Node node;\n        node.next.fill(-1);\n\
    \        node.parent = parent;\n        node.ch = ch;\n        node.prefix_cnt\
    \ = node.word_cnt = 0;\n        if (parent == -1) {\n            node.depth =\
    \ 0;\n            node.jump = 0;\n        } else {\n            node.depth = nodes[parent].depth\
    \ + 1;\n            // \u89AA\u306E\u98DB\u3073\u5148 2 \u3064\u306E\u6DF1\u3055\
    \u306E\u5DEE\u304C\u7B49\u3057\u3051\u308C\u3070\u30012 \u3064\u3092\u307E\u3068\
    \u3081\u3066\u98DB\u3076\n            int j = nodes[parent].jump, jj = nodes[j].jump;\n\
    \            node.jump = nodes[parent].depth - nodes[j].depth == nodes[j].depth\
    \ - nodes[jj].depth ? jj : parent;\n        }\n        nodes.push_back(node);\n\
    \        return nodes.size() - 1;\n    }\n    // v \u306E\u5B50 i (\u306A\u3051\
    \u308C\u3070\u4F5C\u308B)\n    int extend_node(int v, int i) {\n        if (nodes[v].next[i]\
    \ == -1) {\n            int u = add_node(v, i);\n            nodes[v].next[i]\
    \ = u;\n        }\n        return nodes[v].next[i];\n    }\n    // v \u306E\u6DF1\
    \u3055 d \u306E\u7956\u5148\n    int ancestor(int v, int d) const {\n        while\
    \ (nodes[v].depth > d) v = nodes[nodes[v].jump].depth >= d ? nodes[v].jump : nodes[v].parent;\n\
    \        return v;\n    }\n    // \u6DF1\u3055\u304C\u7B49\u3057\u304F\u7570\u306A\
    \u308B u, v \u3092\u3001\u89AA\u304C\u4E00\u81F4\u3059\u308B\u76F4\u524D\u307E\
    \u3067\u6301\u3061\u4E0A\u3052\u308B (\u98DB\u3073\u5148\u306F\u6DF1\u3055\u3060\
    \u3051\u3067\u6C7A\u307E\u308B\u306E\u3067\u3001\u305D\u308D\u3063\u3066\u98DB\
    \u3079\u308B)\n    std::pair<int, int> below_lca(int u, int v) const {\n     \
    \   while (nodes[u].parent != nodes[v].parent) {\n            if (nodes[u].jump\
    \ != nodes[v].jump) {\n                u = nodes[u].jump, v = nodes[v].jump;\n\
    \            } else {\n                u = nodes[u].parent, v = nodes[v].parent;\n\
    \            }\n        }\n        return {u, v};\n    }\n    // \u6587\u5B57\u5217\
    \u30EA\u30C6\u30E9\u30EB (\"abc\" \u306F char[4]) \u3092\u672B\u5C3E\u306E '\\\
    0' \u307E\u3067\u8AAD\u307E\u306A\u3044\u3088\u3046\u3001\u6587\u5B57\u5217\u306F\
    \ string_view \u306B\u3059\u308B\n    template <typename R>\n    static decltype(auto)\
    \ as_range(const R& s) {\n        if constexpr (std::is_convertible_v<const R&,\
    \ std::string_view>) {\n            return std::string_view(s);\n        } else\
    \ {\n            return (s);\n        }\n    }\n    static int index(int c) {\n\
    \        assert(0 <= c - Base && c - Base < K);\n        return c - Base;\n  \
    \  }\n    // \u6587\u5B57\u5217 s \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\
    \ (\u306A\u3051\u308C\u3070 -1)\n    template <typename R>\n    int find_node(const\
    \ R& s) const {\n        int v = 0;\n        for (auto c : as_range(s)) {\n  \
    \          v = nodes[v].next[index(c)];\n            if (v == -1) return -1;\n\
    \        }\n        return v;\n    }\n\n   public:\n    Trie() { add_node(-1,\
    \ -1); }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9\u306E\u500B\u6570 (\u6839\
    \u3092\u542B\u3080)\n     */\n    long long size() const { return nodes.size();\
    \ }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u3092 1 \u500B\u8FFD\u52A0\
    \u3057\u3001s \u306B\u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u8FD4\u3059\
    \ O(|s|)\n     * @param s std::string \u3084 std::vector<int> \u306A\u3069\u3001\
    \u8981\u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n   \
    \  */\n    template <typename R>\n    long long insert(const R& s) {\n       \
    \ int v = 0;\n        nodes[v].prefix_cnt++;\n        for (auto c : as_range(s))\
    \ {\n            v = extend_node(v, index(c));\n            nodes[v].prefix_cnt++;\n\
    \        }\n        nodes[v].word_cnt++;\n        return v;\n    }\n\n    /**\n\
    \     * @brief \u6587\u5B57\u5217 s \u3092 1 \u500B\u53D6\u308A\u9664\u304F\u3002\
    s \u304C\u306A\u3051\u308C\u3070\u4F55\u3082\u305B\u305A false \u3092\u8FD4\u3059\
    \ O(|s|)\n     * \u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\u306E\u3067\
    \u3001\u30CE\u30FC\u30C9\u306E\u756A\u53F7\u306F\u5909\u308F\u3089\u306A\u3044\
    \n     */\n    template <typename R>\n    bool erase(const R& s) {\n        int\
    \ v = find_node(s);\n        if (v == -1 || nodes[v].word_cnt == 0) return false;\n\
    \        nodes[v].word_cnt--;\n        for (; v != -1; v = nodes[v].parent) nodes[v].prefix_cnt--;\n\
    \        return true;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306B\
    \u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1) O(|s|)\n\
    \     * s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\u5B57\u5217\u3092\u8FFD\
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
    \     * @brief \u30CE\u30FC\u30C9 v \u304B\u3089\u6587\u5B57 c \u3067\u9032\u3093\
    \u3060\u30CE\u30FC\u30C9\u3002\u306A\u3051\u308C\u3070\u4F5C\u308B (\u6587\u5B57\
    \u5217\u306E\u500B\u6570\u306F\u5909\u3048\u306A\u3044) O(K)\n     */\n    long\
    \ long extend(long long v, int c) { return extend_node(v, index(c)); }\n    /**\n\
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
    \ nodes[v].word_cnt; }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9 u, v \u306E\
    \u6700\u5C0F\u5171\u901A\u7956\u5148 (2 \u3064\u306E\u6587\u5B57\u5217\u306E\u6700\
    \u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u30CE\u30FC\u30C9) O(log n)\n     */\n\
    \    long long lca(long long u, long long v) const {\n        int d = std::min(nodes[u].depth,\
    \ nodes[v].depth);\n        int a = ancestor(u, d), b = ancestor(v, d);\n    \
    \    if (a == b) return a;\n        return nodes[below_lca(a, b).first].parent;\n\
    \    }\n    /**\n     * @brief \u30CE\u30FC\u30C9 u \u306E\u6587\u5B57\u5217\u304C\
    \ v \u306E\u6587\u5B57\u5217\u3088\u308A\u8F9E\u66F8\u9806\u3067\u5C0F\u3055\u3044\
    \u304B O(log n)\n     * \u4E00\u65B9\u304C\u4ED6\u65B9\u306E\u63A5\u982D\u8F9E\
    \u306A\u3089\u3001\u77ED\u3044\u307B\u3046\u304C\u5C0F\u3055\u3044\n     */\n\
    \    bool less(long long u, long long v) const {\n        int d = std::min(nodes[u].depth,\
    \ nodes[v].depth);\n        int a = ancestor(u, d), b = ancestor(v, d);\n    \
    \    if (a == b) return nodes[u].depth < nodes[v].depth;\n        auto [x, y]\
    \ = below_lca(a, b);\n        return nodes[x].ch < nodes[y].ch;\n    }\n\n   \
    \ /**\n     * @brief s \u306E\u63A5\u982D\u8F9E\u306E\u3046\u3061\u3001\u8FFD\u52A0\
    \u3057\u305F\u6587\u5B57\u5217\u306E\u3069\u308C\u304B\u306E\u63A5\u982D\u8F9E\
    \u306B\u3082\u306A\u3063\u3066\u3044\u308B\u3082\u306E\u306E\u6700\u9577\u306E\
    \u9577\u3055 O(|s|)\n     * \u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217 (\u53D6\
    \u308A\u9664\u3044\u305F\u3082\u306E\u306F\u9664\u304F) \u306E\u3069\u308C\u304B\
    \u3068\u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u306E\
    \u6700\u5927\u5024\u306B\u306A\u308B\n     */\n    template <typename R>\n   \
    \ long long longest_common_prefix(const R& s) const {\n        int v = 0;\n  \
    \      long long len = 0;\n        for (auto c : as_range(s)) {\n            int\
    \ u = nodes[v].next[index(c)];\n            if (u == -1 || nodes[u].prefix_cnt\
    \ == 0) break;\n            v = u;\n            len++;\n        }\n        return\
    \ len;\n    }\n};\n#line 8 \"test/aoj/alds1/alds1-4-c.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    int\
    \ n;\n    std::cin >> n;\n    // \u6587\u5B57\u306F A, C, G, T \u3060\u3051\u306A\
    \u306E\u3067\u30010, 1, 2, 3 \u306B\u76F4\u3057\u3066\u30CE\u30FC\u30C9\u3092\u5C0F\
    \u3055\u304F\u3059\u308B\n    Trie<4, 0> trie;\n    auto convert = [](const std::string&\
    \ s) {\n        std::vector<int> res;\n        for (char c : s) res.push_back(c\
    \ == 'A' ? 0 : c == 'C' ? 1\n                                                \
    \  : c == 'G'   ? 2\n                                                        \
    \       : 3);\n        return res;\n    };\n    while (n--) {\n        std::string\
    \ op, s;\n        std::cin >> op >> s;\n        if (op == \"insert\")\n      \
    \      trie.insert(convert(s));\n        else\n            std::cout << (trie.count(convert(s))\
    \ > 0 ? \"yes\" : \"no\") << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_C\"\
    \n\n#include <iostream>\n#include <string>\n#include <vector>\n\n#include \"../../../src/string/trie.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n;\n    std::cin >> n;\n    // \u6587\u5B57\u306F A, C, G, T \u3060\u3051\
    \u306A\u306E\u3067\u30010, 1, 2, 3 \u306B\u76F4\u3057\u3066\u30CE\u30FC\u30C9\u3092\
    \u5C0F\u3055\u304F\u3059\u308B\n    Trie<4, 0> trie;\n    auto convert = [](const\
    \ std::string& s) {\n        std::vector<int> res;\n        for (char c : s) res.push_back(c\
    \ == 'A' ? 0 : c == 'C' ? 1\n                                                \
    \  : c == 'G'   ? 2\n                                                        \
    \       : 3);\n        return res;\n    };\n    while (n--) {\n        std::string\
    \ op, s;\n        std::cin >> op >> s;\n        if (op == \"insert\")\n      \
    \      trie.insert(convert(s));\n        else\n            std::cout << (trie.count(convert(s))\
    \ > 0 ? \"yes\" : \"no\") << '\\n';\n    }\n}\n"
  dependsOn:
  - src/string/trie.hpp
  isVerificationFile: true
  path: test/aoj/alds1/alds1-4-c.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 23:32:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/alds1/alds1-4-c.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/alds1/alds1-4-c.test.cpp
- /verify/test/aoj/alds1/alds1-4-c.test.cpp.html
title: test/aoj/alds1/alds1-4-c.test.cpp
---
