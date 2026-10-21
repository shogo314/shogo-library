---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/palindromic-tree.test.cpp
    title: test/unittest/string/palindromic-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/eertree.test.cpp
    title: test/yosupo/string/eertree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u56DE\u6587\u6728 (Eertree)"
    links: []
  bundledCode: "#line 2 \"src/string/palindromic-tree.hpp\"\n\n/**\n * @file palindromic-tree.hpp\n\
    \ * @brief \u56DE\u6587\u6728 (Eertree)\n */\n\n#include <array>\n#include <cassert>\n\
    #include <vector>\n\n/**\n * @brief \u56DE\u6587\u6728 (Eertree, Palindromic Tree)\n\
    \ *\n * \u5217\u306E\u7A7A\u3067\u306A\u3044\u56DE\u6587\u306E\u90E8\u5206\u5217\
    \ (\u7A2E\u985E) \u3092\u3059\u3079\u3066\u9802\u70B9\u3068\u3057\u3066\u6301\u3064\
    \u3002\u672B\u5C3E\u306B 1 \u6587\u5B57\u305A\u3064\u8FFD\u52A0\u3067\u304D\u3001\
    \u5168\u4F53\u3067 O(n) (\u6587\u5B57\u306E\u7A2E\u985E\u3092 K \u3068\u3057\u3066\
    \u511F\u5374 O(nK) \u306E\u30E1\u30E2\u30EA)\n * \u9802\u70B9 0 \u306F\u9577\u3055\
    \ -1 \u306E\u6839 (ODD)\u3001\u9802\u70B9 1 \u306F\u9577\u3055 0 \u306E\u6839\
    \ (EVEN)\u3002\u56DE\u6587\u306E\u9802\u70B9\u306F 2 \u304B\u3089\u3001\u521D\u3081\
    \u3066\u73FE\u308C\u305F\u9806 (\u6700\u521D\u306B\u73FE\u308C\u305F\u3068\u304D\
    \u306E\u7D42\u308F\u308A\u306E\u4F4D\u7F6E\u306E\u9806) \u306B\u756A\u53F7\u304C\
    \u4ED8\u304F\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A\
    \ K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\n * \u4F8B:\n * PalindromicTree<26,\
    \ 'a'> pt(\"abacaba\");\n * pt.count_distinct();      // 7 (a, b, c, aba, aca,\
    \ bacab, abacaba)\n * pt.occurrences()[v];      // \u9802\u70B9 v \u306E\u56DE\
    \u6587\u306E\u51FA\u73FE\u56DE\u6570\n * pt.longest_suffix(6);     // \u4F4D\u7F6E\
    \ 6 \u3067\u7D42\u308F\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9802\u70B9 (abacaba)\n\
    \ *\n * @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\
    \u5C0F\u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\nclass PalindromicTree\
    \ {\n    struct Node {\n        std::array<int, K> next;\n        int len;   \
    \     // \u56DE\u6587\u306E\u9577\u3055\n        int link;       // suffix link\
    \ (\u81EA\u5206\u3088\u308A\u77ED\u3044\u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\
    \u8F9E\u306E\u9802\u70B9)\n        int parent;     // \u4E21\u7AEF\u306E 1 \u6587\
    \u5B57\u3092\u9664\u3044\u305F\u56DE\u6587\u306E\u9802\u70B9\n        int cnt;\
    \        // \u3053\u306E\u9802\u70B9\u304C\u6700\u9577\u306E\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306B\u306A\u3063\u305F\u4F4D\u7F6E\u306E\u500B\u6570\n        int\
    \ first_end;  // \u521D\u3081\u3066\u73FE\u308C\u305F\u3068\u304D\u306E\u7D42\u308F\
    \u308A\u306E\u4F4D\u7F6E\n    };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\
    \u305F\u3081\u3001\u9802\u70B9\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\u3002\
    \u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n    std::vector<Node>\
    \ nodes;\n    std::vector<int> s;        // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\
    \ (\u756A\u53F7\u306B\u76F4\u3057\u305F\u3082\u306E)\n    std::vector<int> longest;\
    \  // \u5404\u4F4D\u7F6E\u3067\u7D42\u308F\u308B\u6700\u9577\u306E\u56DE\u6587\
    \u306E\u9802\u70B9\n    int last = 1;              // \u4ECA\u306E\u5217\u306E\
    \u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\u306E\u9802\u70B9\n\n    int\
    \ add_node(int len, int link, int parent, int first_end) {\n        Node node;\n\
    \        node.next.fill(-1);\n        node.len = len, node.link = link, node.parent\
    \ = parent;\n        node.cnt = 0, node.first_end = first_end;\n        nodes.push_back(node);\n\
    \        return nodes.size() - 1;\n    }\n    static int index(int c) {\n    \
    \    assert(0 <= c - Base && c - Base < K);\n        return c - Base;\n    }\n\
    \    // v \u304B\u3089 suffix link \u3092\u305F\u3069\u308A\u3001\u4F4D\u7F6E\
    \ i \u306E\u6587\u5B57 c \u3092\u4E21\u7AEF\u306B\u4ED8\u3051\u3089\u308C\u308B\
    \u6700\u521D\u306E\u9802\u70B9\n    int extendable(int v, int i, int c) const\
    \ {\n        while (true) {\n            int j = i - 1 - nodes[v].len;\n     \
    \       if (j >= 0 && s[j] == c) return v;\n            v = nodes[v].link;\n \
    \       }\n    }\n\n   public:\n    PalindromicTree() {\n        add_node(-1,\
    \ 0, -1, -1);  // ODD (\u9577\u3055 -1\u3001suffix link \u306F\u81EA\u5206\u81EA\
    \u8EAB)\n        add_node(0, 0, -1, -1);   // EVEN (\u9577\u3055 0\u3001suffix\
    \ link \u306F ODD)\n    }\n    /**\n     * @brief \u5217 s \u306E\u56DE\u6587\u6728\
    \ O(|s|)\n     * @param s std::string \u3084 std::vector<int> \u306A\u3069\u3001\
    \u8981\u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n   \
    \  */\n    template <typename R>\n    explicit PalindromicTree(const R& s) : PalindromicTree()\
    \ {\n        for (auto c : s) add(c);\n    }\n\n    /**\n     * @brief \u672B\u5C3E\
    \u306B\u6587\u5B57 c \u3092\u8FFD\u52A0\u3057\u3001\u8FFD\u52A0\u5F8C\u306E\u5217\
    \u306E\u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\u306E\u9802\u70B9\u3092\
    \u8FD4\u3059 \u511F\u5374 O(1) (\u65B0\u3057\u3044\u9802\u70B9\u306B\u306F O(K))\n\
    \     */\n    long long add(int c) {\n        c = index(c);\n        const int\
    \ i = s.size();\n        s.push_back(c);\n        int v = extendable(last, i,\
    \ c);\n        if (nodes[v].next[c] == -1) {\n            // \u65B0\u3057\u3044\
    \u56DE\u6587 c + (v \u306E\u56DE\u6587) + c\u3002suffix link \u3092\u5148\u306B\
    \u6C42\u3081\u3066\u304B\u3089\u8FBA\u3092\u5F35\u308B\n            int len =\
    \ nodes[v].len + 2;\n            int link = len == 1 ? 1 : nodes[extendable(nodes[v].link,\
    \ i, c)].next[c];\n            int u = add_node(len, link, v, i);\n          \
    \  nodes[v].next[c] = u;\n        }\n        last = nodes[v].next[c];\n      \
    \  nodes[last].cnt++;\n        longest.push_back(last);\n        return last;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9\u306E\u500B\u6570 (2 \u3064\u306E\
    \u6839\u3092\u542B\u3080)\n     */\n    long long size() const { return nodes.size();\
    \ }\n    /**\n     * @brief \u7570\u306A\u308B\u7A7A\u3067\u306A\u3044\u56DE\u6587\
    \u306E\u500B\u6570 (\u6839\u3092\u9664\u304F\u9802\u70B9\u306E\u500B\u6570)\n\
    \     */\n    long long count_distinct() const { return nodes.size() - 2; }\n\
    \    /**\n     * @brief \u8FFD\u52A0\u3057\u305F\u5217\u306E\u9577\u3055\n   \
    \  */\n    long long length() const { return s.size(); }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 v \u306E\u56DE\u6587\u306E\u9577\u3055 (ODD \u306F -1\u3001EVEN\
    \ \u306F 0)\n     */\n    long long len(long long v) const { return nodes[v].len;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E suffix link (\u81EA\u5206\u3088\
    \u308A\u77ED\u3044\u6700\u9577\u306E\u7A7A\u3067\u306A\u3044\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306E\u9802\u70B9\u3002\u306A\u3051\u308C\u3070 EVEN = 1)\n     *\
    \ \u6839\u3067\u306F\u3001ODD \u306F 0 (\u81EA\u5206\u81EA\u8EAB)\u3001EVEN \u306F\
    \ 0 (ODD)\n     */\n    long long suffix_link(long long v) const { return nodes[v].link;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u89AA (\u4E21\u7AEF\u306E 1\
    \ \u6587\u5B57\u3092\u9664\u3044\u305F\u56DE\u6587\u306E\u9802\u70B9\u3002\u9577\
    \u3055 1 \u306A\u3089 ODD = 0\u3001\u9577\u3055 2 \u306A\u3089 EVEN = 1\u3001\u6839\
    \u306A\u3089 -1)\n     */\n    long long parent(long long v) const { return nodes[v].parent;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u56DE\u6587\u306E\u4E21\u7AEF\
    \u306B\u6587\u5B57 c \u3092\u4ED8\u3051\u305F\u56DE\u6587\u306E\u9802\u70B9 (\u306A\
    \u3051\u308C\u3070 -1)\n     */\n    long long child(long long v, int c) const\
    \ { return nodes[v].next[index(c)]; }\n    /**\n     * @brief \u9802\u70B9 v \u306E\
    \u56DE\u6587\u304C\u521D\u3081\u3066\u73FE\u308C\u305F\u3068\u304D\u306E\u7D42\
    \u308F\u308A\u306E\u4F4D\u7F6E (0-indexed\u3001\u6839\u306F -1)\n     * \u56DE\
    \u6587\u306F [first_end(v) - len(v) + 1, first_end(v)] \u306B\u73FE\u308C\u308B\
    \n     */\n    long long first_end(long long v) const { return nodes[v].first_end;\
    \ }\n    /**\n     * @brief \u4F4D\u7F6E i (0-indexed) \u3067\u7D42\u308F\u308B\
    \u6700\u9577\u306E\u56DE\u6587\u306E\u9802\u70B9\n     */\n    long long longest_suffix(long\
    \ long i) const {\n        assert(0 <= i && i < static_cast<long long>(longest.size()));\n\
    \        return longest[i];\n    }\n\n    /**\n     * @brief \u5404\u9802\u70B9\
    \u306E\u56DE\u6587\u304C\u5217\u306B\u73FE\u308C\u308B\u56DE\u6570 (\u6839\u306F\
    \ 0) O(size())\n     * \u9802\u70B9 v \u304C\u6700\u9577\u306E\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306B\u306A\u3063\u305F\u56DE\u6570\u3092\u3001suffix link \u306E\
    \u6728\u3067\u8449\u306E\u5074\u304B\u3089\u8DB3\u3057\u5408\u308F\u305B\u308B\
    \n     */\n    std::vector<long long> occurrences() const {\n        std::vector<long\
    \ long> res(nodes.size());\n        for (int v = 0; v < static_cast<int>(nodes.size());\
    \ v++) res[v] = nodes[v].cnt;\n        // suffix link \u306E\u5148\u306F\u81EA\
    \u5206\u3088\u308A\u524D\u306B\u4F5C\u3063\u305F\u9802\u70B9\u306A\u306E\u3067\
    \u3001\u756A\u53F7\u306E\u5927\u304D\u3044\u9806\u306B\u8DB3\u305B\u3070\u3088\
    \u3044\n        for (int v = static_cast<int>(nodes.size()) - 1; v >= 2; v--)\
    \ res[nodes[v].link] += res[v];\n        res[0] = res[1] = 0;\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file palindromic-tree.hpp\n * @brief \u56DE\u6587\
    \u6728 (Eertree)\n */\n\n#include <array>\n#include <cassert>\n#include <vector>\n\
    \n/**\n * @brief \u56DE\u6587\u6728 (Eertree, Palindromic Tree)\n *\n * \u5217\
    \u306E\u7A7A\u3067\u306A\u3044\u56DE\u6587\u306E\u90E8\u5206\u5217 (\u7A2E\u985E\
    ) \u3092\u3059\u3079\u3066\u9802\u70B9\u3068\u3057\u3066\u6301\u3064\u3002\u672B\
    \u5C3E\u306B 1 \u6587\u5B57\u305A\u3064\u8FFD\u52A0\u3067\u304D\u3001\u5168\u4F53\
    \u3067 O(n) (\u6587\u5B57\u306E\u7A2E\u985E\u3092 K \u3068\u3057\u3066\u511F\u5374\
    \ O(nK) \u306E\u30E1\u30E2\u30EA)\n * \u9802\u70B9 0 \u306F\u9577\u3055 -1 \u306E\
    \u6839 (ODD)\u3001\u9802\u70B9 1 \u306F\u9577\u3055 0 \u306E\u6839 (EVEN)\u3002\
    \u56DE\u6587\u306E\u9802\u70B9\u306F 2 \u304B\u3089\u3001\u521D\u3081\u3066\u73FE\
    \u308C\u305F\u9806 (\u6700\u521D\u306B\u73FE\u308C\u305F\u3068\u304D\u306E\u7D42\
    \u308F\u308A\u306E\u4F4D\u7F6E\u306E\u9806) \u306B\u756A\u53F7\u304C\u4ED8\u304F\
    \n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A K \u672A\
    \u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\n * \u4F8B:\n * PalindromicTree<26,\
    \ 'a'> pt(\"abacaba\");\n * pt.count_distinct();      // 7 (a, b, c, aba, aca,\
    \ bacab, abacaba)\n * pt.occurrences()[v];      // \u9802\u70B9 v \u306E\u56DE\
    \u6587\u306E\u51FA\u73FE\u56DE\u6570\n * pt.longest_suffix(6);     // \u4F4D\u7F6E\
    \ 6 \u3067\u7D42\u308F\u308B\u6700\u9577\u306E\u56DE\u6587\u306E\u9802\u70B9 (abacaba)\n\
    \ *\n * @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\
    \u5C0F\u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\nclass PalindromicTree\
    \ {\n    struct Node {\n        std::array<int, K> next;\n        int len;   \
    \     // \u56DE\u6587\u306E\u9577\u3055\n        int link;       // suffix link\
    \ (\u81EA\u5206\u3088\u308A\u77ED\u3044\u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\
    \u8F9E\u306E\u9802\u70B9)\n        int parent;     // \u4E21\u7AEF\u306E 1 \u6587\
    \u5B57\u3092\u9664\u3044\u305F\u56DE\u6587\u306E\u9802\u70B9\n        int cnt;\
    \        // \u3053\u306E\u9802\u70B9\u304C\u6700\u9577\u306E\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306B\u306A\u3063\u305F\u4F4D\u7F6E\u306E\u500B\u6570\n        int\
    \ first_end;  // \u521D\u3081\u3066\u73FE\u308C\u305F\u3068\u304D\u306E\u7D42\u308F\
    \u308A\u306E\u4F4D\u7F6E\n    };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\
    \u305F\u3081\u3001\u9802\u70B9\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\u3002\
    \u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n    std::vector<Node>\
    \ nodes;\n    std::vector<int> s;        // \u8FFD\u52A0\u3057\u305F\u6587\u5B57\
    \ (\u756A\u53F7\u306B\u76F4\u3057\u305F\u3082\u306E)\n    std::vector<int> longest;\
    \  // \u5404\u4F4D\u7F6E\u3067\u7D42\u308F\u308B\u6700\u9577\u306E\u56DE\u6587\
    \u306E\u9802\u70B9\n    int last = 1;              // \u4ECA\u306E\u5217\u306E\
    \u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\u306E\u9802\u70B9\n\n    int\
    \ add_node(int len, int link, int parent, int first_end) {\n        Node node;\n\
    \        node.next.fill(-1);\n        node.len = len, node.link = link, node.parent\
    \ = parent;\n        node.cnt = 0, node.first_end = first_end;\n        nodes.push_back(node);\n\
    \        return nodes.size() - 1;\n    }\n    static int index(int c) {\n    \
    \    assert(0 <= c - Base && c - Base < K);\n        return c - Base;\n    }\n\
    \    // v \u304B\u3089 suffix link \u3092\u305F\u3069\u308A\u3001\u4F4D\u7F6E\
    \ i \u306E\u6587\u5B57 c \u3092\u4E21\u7AEF\u306B\u4ED8\u3051\u3089\u308C\u308B\
    \u6700\u521D\u306E\u9802\u70B9\n    int extendable(int v, int i, int c) const\
    \ {\n        while (true) {\n            int j = i - 1 - nodes[v].len;\n     \
    \       if (j >= 0 && s[j] == c) return v;\n            v = nodes[v].link;\n \
    \       }\n    }\n\n   public:\n    PalindromicTree() {\n        add_node(-1,\
    \ 0, -1, -1);  // ODD (\u9577\u3055 -1\u3001suffix link \u306F\u81EA\u5206\u81EA\
    \u8EAB)\n        add_node(0, 0, -1, -1);   // EVEN (\u9577\u3055 0\u3001suffix\
    \ link \u306F ODD)\n    }\n    /**\n     * @brief \u5217 s \u306E\u56DE\u6587\u6728\
    \ O(|s|)\n     * @param s std::string \u3084 std::vector<int> \u306A\u3069\u3001\
    \u8981\u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n   \
    \  */\n    template <typename R>\n    explicit PalindromicTree(const R& s) : PalindromicTree()\
    \ {\n        for (auto c : s) add(c);\n    }\n\n    /**\n     * @brief \u672B\u5C3E\
    \u306B\u6587\u5B57 c \u3092\u8FFD\u52A0\u3057\u3001\u8FFD\u52A0\u5F8C\u306E\u5217\
    \u306E\u6700\u9577\u306E\u56DE\u6587\u63A5\u5C3E\u8F9E\u306E\u9802\u70B9\u3092\
    \u8FD4\u3059 \u511F\u5374 O(1) (\u65B0\u3057\u3044\u9802\u70B9\u306B\u306F O(K))\n\
    \     */\n    long long add(int c) {\n        c = index(c);\n        const int\
    \ i = s.size();\n        s.push_back(c);\n        int v = extendable(last, i,\
    \ c);\n        if (nodes[v].next[c] == -1) {\n            // \u65B0\u3057\u3044\
    \u56DE\u6587 c + (v \u306E\u56DE\u6587) + c\u3002suffix link \u3092\u5148\u306B\
    \u6C42\u3081\u3066\u304B\u3089\u8FBA\u3092\u5F35\u308B\n            int len =\
    \ nodes[v].len + 2;\n            int link = len == 1 ? 1 : nodes[extendable(nodes[v].link,\
    \ i, c)].next[c];\n            int u = add_node(len, link, v, i);\n          \
    \  nodes[v].next[c] = u;\n        }\n        last = nodes[v].next[c];\n      \
    \  nodes[last].cnt++;\n        longest.push_back(last);\n        return last;\n\
    \    }\n\n    /**\n     * @brief \u9802\u70B9\u306E\u500B\u6570 (2 \u3064\u306E\
    \u6839\u3092\u542B\u3080)\n     */\n    long long size() const { return nodes.size();\
    \ }\n    /**\n     * @brief \u7570\u306A\u308B\u7A7A\u3067\u306A\u3044\u56DE\u6587\
    \u306E\u500B\u6570 (\u6839\u3092\u9664\u304F\u9802\u70B9\u306E\u500B\u6570)\n\
    \     */\n    long long count_distinct() const { return nodes.size() - 2; }\n\
    \    /**\n     * @brief \u8FFD\u52A0\u3057\u305F\u5217\u306E\u9577\u3055\n   \
    \  */\n    long long length() const { return s.size(); }\n\n    /**\n     * @brief\
    \ \u9802\u70B9 v \u306E\u56DE\u6587\u306E\u9577\u3055 (ODD \u306F -1\u3001EVEN\
    \ \u306F 0)\n     */\n    long long len(long long v) const { return nodes[v].len;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E suffix link (\u81EA\u5206\u3088\
    \u308A\u77ED\u3044\u6700\u9577\u306E\u7A7A\u3067\u306A\u3044\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306E\u9802\u70B9\u3002\u306A\u3051\u308C\u3070 EVEN = 1)\n     *\
    \ \u6839\u3067\u306F\u3001ODD \u306F 0 (\u81EA\u5206\u81EA\u8EAB)\u3001EVEN \u306F\
    \ 0 (ODD)\n     */\n    long long suffix_link(long long v) const { return nodes[v].link;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u89AA (\u4E21\u7AEF\u306E 1\
    \ \u6587\u5B57\u3092\u9664\u3044\u305F\u56DE\u6587\u306E\u9802\u70B9\u3002\u9577\
    \u3055 1 \u306A\u3089 ODD = 0\u3001\u9577\u3055 2 \u306A\u3089 EVEN = 1\u3001\u6839\
    \u306A\u3089 -1)\n     */\n    long long parent(long long v) const { return nodes[v].parent;\
    \ }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u56DE\u6587\u306E\u4E21\u7AEF\
    \u306B\u6587\u5B57 c \u3092\u4ED8\u3051\u305F\u56DE\u6587\u306E\u9802\u70B9 (\u306A\
    \u3051\u308C\u3070 -1)\n     */\n    long long child(long long v, int c) const\
    \ { return nodes[v].next[index(c)]; }\n    /**\n     * @brief \u9802\u70B9 v \u306E\
    \u56DE\u6587\u304C\u521D\u3081\u3066\u73FE\u308C\u305F\u3068\u304D\u306E\u7D42\
    \u308F\u308A\u306E\u4F4D\u7F6E (0-indexed\u3001\u6839\u306F -1)\n     * \u56DE\
    \u6587\u306F [first_end(v) - len(v) + 1, first_end(v)] \u306B\u73FE\u308C\u308B\
    \n     */\n    long long first_end(long long v) const { return nodes[v].first_end;\
    \ }\n    /**\n     * @brief \u4F4D\u7F6E i (0-indexed) \u3067\u7D42\u308F\u308B\
    \u6700\u9577\u306E\u56DE\u6587\u306E\u9802\u70B9\n     */\n    long long longest_suffix(long\
    \ long i) const {\n        assert(0 <= i && i < static_cast<long long>(longest.size()));\n\
    \        return longest[i];\n    }\n\n    /**\n     * @brief \u5404\u9802\u70B9\
    \u306E\u56DE\u6587\u304C\u5217\u306B\u73FE\u308C\u308B\u56DE\u6570 (\u6839\u306F\
    \ 0) O(size())\n     * \u9802\u70B9 v \u304C\u6700\u9577\u306E\u56DE\u6587\u63A5\
    \u5C3E\u8F9E\u306B\u306A\u3063\u305F\u56DE\u6570\u3092\u3001suffix link \u306E\
    \u6728\u3067\u8449\u306E\u5074\u304B\u3089\u8DB3\u3057\u5408\u308F\u305B\u308B\
    \n     */\n    std::vector<long long> occurrences() const {\n        std::vector<long\
    \ long> res(nodes.size());\n        for (int v = 0; v < static_cast<int>(nodes.size());\
    \ v++) res[v] = nodes[v].cnt;\n        // suffix link \u306E\u5148\u306F\u81EA\
    \u5206\u3088\u308A\u524D\u306B\u4F5C\u3063\u305F\u9802\u70B9\u306A\u306E\u3067\
    \u3001\u756A\u53F7\u306E\u5927\u304D\u3044\u9806\u306B\u8DB3\u305B\u3070\u3088\
    \u3044\n        for (int v = static_cast<int>(nodes.size()) - 1; v >= 2; v--)\
    \ res[nodes[v].link] += res[v];\n        res[0] = res[1] = 0;\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/palindromic-tree.hpp
  requiredBy: []
  timestamp: '2026-10-20 00:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/palindromic-tree.test.cpp
  - test/yosupo/string/eertree.test.cpp
documentation_of: src/string/palindromic-tree.hpp
layout: document
title: "\u56DE\u6587\u6728 (Eertree)"
---

列に現れる空でない回文 (種類) をすべて頂点として持つ `PalindromicTree<K, Base>` です。末尾に 1 文字ずつ追加でき、長さ $n$ の列全体で $O(n)$ で作れます。異なる回文の個数、各回文の出現回数、各位置で終わる最長の回文などが求められます。文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。

```cpp
PalindromicTree<26, 'a'> pt("abacaba");
pt.count_distinct();                   // 7 (a, b, c, aba, aca, bacab, abacaba)
auto occ = pt.occurrences();           // occ[v] は頂点 v の回文が現れる回数
long long v = pt.longest_suffix(6);    // 位置 6 で終わる最長の回文の頂点
pt.len(v);                             // 7
pt.add('a');                           // 末尾に 'a' を追加 (追加後の最長の回文接尾辞の頂点を返す)
```

頂点 0 は長さ $-1$ の根 (ODD)、頂点 1 は長さ $0$ の根 (EVEN) です。回文の頂点は 2 から、初めて現れた順 (最初に現れたときの終わりの位置の順) に番号が付きます。頂点 $v$ の子は、$v$ の回文の両端に同じ文字を付けた回文です。長さが奇数の回文は ODD の下に、偶数の回文は EVEN の下にぶら下がります。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PalindromicTree<K, Base>()` | 空の列の回文木 (2 つの根だけ)。既定は `K = 26`、`Base = 'a'` | $O(K)$ |
| `PalindromicTree<K, Base>(s)` | 列 `s` の回文木 | $O(\lvert s \rvert K)$ |
| `add(c)` | 末尾に文字 `c` を追加し、追加後の列の最長の回文接尾辞の頂点を返す | 償却 $O(1)$ (新しい頂点には $O(K)$) |
| `size()` | 頂点の個数 (2 つの根を含む) | $O(1)$ |
| `count_distinct()` | 異なる空でない回文の個数 (`size() - 2`) | $O(1)$ |
| `length()` | 追加した列の長さ | $O(1)$ |
| `len(v)` | 頂点 `v` の回文の長さ (ODD は $-1$、EVEN は $0$) | $O(1)$ |
| `suffix_link(v)` | 頂点 `v` の回文より短い、最長の空でない回文接尾辞の頂点。なければ EVEN (1)。ODD と EVEN では 0 | $O(1)$ |
| `parent(v)` | 両端の 1 文字を除いた回文の頂点。長さ 1 なら ODD (0)、長さ 2 なら EVEN (1)、根なら $-1$ | $O(1)$ |
| `child(v, c)` | 頂点 `v` の回文の両端に文字 `c` を付けた回文の頂点 (なければ $-1$) | $O(1)$ |
| `first_end(v)` | 頂点 `v` の回文が初めて現れたときの終わりの位置。回文は `[first_end(v) - len(v) + 1, first_end(v)]` にある (根は $-1$) | $O(1)$ |
| `longest_suffix(i)` | 位置 `i` で終わる最長の回文の頂点 | $O(1)$ |
| `occurrences()` | 各頂点の回文が列に現れる回数の配列 (根は 0) | $O(\mathrm{size}())$ |

- 頂点の番号・長さ・個数・位置は `long long` で返し、頂点の番号も `long long` で受け取ります。文字 `c` は `int` です。
- `s` は `std::string` のほか、`std::vector<int>` などの整数の列でもかまいません (`PalindromicTree<3, 0>` に 0, 1, 2 の列を入れるなど)。
- 頂点は子の番号を `K` 個の配列で持つので、メモリは「頂点数 × (4K + 20) バイト」ほど使います。頂点数は列の長さ + 2 以下です。
- `occurrences()` は、頂点が最長の回文接尾辞になった回数を、suffix link の木で葉の側から足し合わせて求めます。suffix link の先は自分より番号の小さい頂点なので、ほかの値を suffix link の木で集めるときも、番号の大きい順に処理すれば済みます。
- 列の長さ $n$ に対して、異なる回文の個数は $n$ 以下です。

## 例: 回文の部分文字列の個数 (重複を含む)

各位置で終わる回文の個数は、その位置の最長の回文から suffix link をたどって根に着くまでの頂点の数です。頂点ごとに suffix link の木での深さを求めておけば、位置ごとに $O(1)$ で足せます。

```cpp
std::vector<long long> depth(pt.size(), 0);
for (long long v = 2; v < pt.size(); v++) depth[v] = depth[pt.suffix_link(v)] + 1;
long long total = 0;
for (long long i = 0; i < pt.length(); i++) total += depth[pt.longest_suffix(i)];
```

## 関連

- 各位置を中心とする最長の回文の半径は [文字列アルゴリズム](string.hpp) の Manacher のアルゴリズム
- 複数の文字列の接頭辞を扱う木は [Trie](trie.hpp)
