---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/palindromic-tree.hpp
    title: "\u56DE\u6587\u6728 (Eertree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/eertree
    links:
    - https://judge.yosupo.jp/problem/eertree
  bundledCode: "#line 1 \"test/yosupo/string/eertree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/eertree\"\n\n#include <iostream>\n#include <string>\n\
    \n#line 2 \"src/string/palindromic-tree.hpp\"\n\n/**\n * @file palindromic-tree.hpp\n\
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
    \ res;\n    }\n};\n#line 7 \"test/yosupo/string/eertree.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::string\
    \ s;\n    std::cin >> s;\n    PalindromicTree<26, 'a'> pt(s);\n    // \u554F\u984C\
    \u306E\u756A\u53F7\u306F ODD \u304C -1\u3001EVEN \u304C 0\u3001\u56DE\u6587\u304C\
    \ 1 \u304B\u3089\u3002\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u756A\u53F7\u304B\u3089\
    \ 1 \u3092\u5F15\u3051\u3070\u3088\u3044\n    std::cout << pt.count_distinct()\
    \ << '\\n';\n    for (long long v = 2; v < pt.size(); v++) std::cout << pt.parent(v)\
    \ - 1 << ' ' << pt.suffix_link(v) - 1 << '\\n';\n    for (long long i = 0; i <\
    \ pt.length(); i++) std::cout << pt.longest_suffix(i) - 1 << (i + 1 == pt.length()\
    \ ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/eertree\"\n\n#include <iostream>\n\
    #include <string>\n\n#include \"../../../src/string/palindromic-tree.hpp\"\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s;\n    std::cin >> s;\n    PalindromicTree<26, 'a'> pt(s);\n\
    \    // \u554F\u984C\u306E\u756A\u53F7\u306F ODD \u304C -1\u3001EVEN \u304C 0\u3001\
    \u56DE\u6587\u304C 1 \u304B\u3089\u3002\u30E9\u30A4\u30D6\u30E9\u30EA\u306E\u756A\
    \u53F7\u304B\u3089 1 \u3092\u5F15\u3051\u3070\u3088\u3044\n    std::cout << pt.count_distinct()\
    \ << '\\n';\n    for (long long v = 2; v < pt.size(); v++) std::cout << pt.parent(v)\
    \ - 1 << ' ' << pt.suffix_link(v) - 1 << '\\n';\n    for (long long i = 0; i <\
    \ pt.length(); i++) std::cout << pt.longest_suffix(i) - 1 << (i + 1 == pt.length()\
    \ ? '\\n' : ' ');\n}\n"
  dependsOn:
  - src/string/palindromic-tree.hpp
  isVerificationFile: true
  path: test/yosupo/string/eertree.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:37:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/string/eertree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/string/eertree.test.cpp
- /verify/test/yosupo/string/eertree.test.cpp.html
title: test/yosupo/string/eertree.test.cpp
---
