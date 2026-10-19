---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/suffix-automaton.hpp
    title: Suffix Automaton
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/yosupo/number-of-substrings.2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#include <iostream>\n\
    #include <string>\n\n#line 2 \"src/string/suffix-automaton.hpp\"\n\n/**\n * @file\
    \ suffix-automaton.hpp\n * @brief Suffix Automaton\n */\n\n#include <array>\n\
    #include <cassert>\n#include <vector>\n\n/**\n * @brief Suffix Automaton (\u6587\
    \u5B57\u5217\u306E\u3059\u3079\u3066\u306E\u90E8\u5206\u6587\u5B57\u5217\u3092\
    \u53D7\u7406\u3059\u308B\u6700\u5C0F\u306E\u6C7A\u5B9A\u6027\u30AA\u30FC\u30C8\
    \u30DE\u30C8\u30F3)\n *\n * \u72B6\u614B\u306F O(n) \u500B (2n - 1 \u500B\u4EE5\
    \u4E0B) \u3067\u3001\u5404\u72B6\u614B\u306F endpos (\u51FA\u73FE\u3059\u308B\u7D42\
    \u308F\u308A\u306E\u4F4D\u7F6E\u306E\u96C6\u5408) \u304C\u540C\u3058\u90E8\u5206\
    \u6587\u5B57\u5217\u306E\u96C6\u307E\u308A\u3092\u8868\u3059\n * \u6587\u5B57\
    \ c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\
    \u53F7\u306B\u76F4\u3059\u3002\u9077\u79FB\u306F\u5927\u304D\u3055 K \u306E\u914D\
    \u5217\u3067\u6301\u3064\u3002\u521D\u671F\u72B6\u614B\u306F 0 (\u7A7A\u6587\u5B57\
    \u5217)\n * \u4F8B:\n * SuffixAutomaton<26, 'a'> sa(\"abcbc\");\n * sa.count_distinct_substrings();\
    \  // 12\n * sa.count_occurrences(\"bc\");      // 2\n *\n * @tparam K \u6587\u5B57\
    \u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\u5C0F\u306E\u6587\u5B57\n */\n\
    template <int K = 26, int Base = 'a'>\nclass SuffixAutomaton {\n    struct Node\
    \ {\n        std::array<int, K> next;\n        int len;      // \u3053\u306E\u72B6\
    \u614B\u306E\u6700\u9577\u306E\u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\u3055\
    \n        int link;     // suffix link (\u521D\u671F\u72B6\u614B\u306F -1)\n \
    \       bool cloned;  // \u5206\u5272\u306E\u305F\u3081\u306B\u8907\u88FD\u3057\
    \u305F\u72B6\u614B\u304B\n    };\n    // \u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\
    \u305F\u3081\u3001\u72B6\u614B\u306E\u4E2D\u8EAB\u306F int \u3067\u6301\u3064\u3002\
    \u5916\u3078\u8FD4\u3059\u3068\u304D\u306B long long \u306B\u3059\u308B\n    std::vector<Node>\
    \ nodes;\n    int last = 0;  // \u6587\u5B57\u5217\u5168\u4F53\u306B\u5BFE\u5FDC\
    \u3059\u308B\u72B6\u614B\n    long long n = 0;\n    std::vector<long long> occ;\
    \  // \u5404\u72B6\u614B\u306E endpos \u306E\u5927\u304D\u3055 (extend \u3057\u305F\
    \u3089\u4F5C\u308A\u76F4\u3059)\n    bool occ_valid = false;\n\n    int add_node(int\
    \ len, int link, bool cloned) {\n        Node node;\n        node.next.fill(-1);\n\
    \        node.len = len, node.link = link, node.cloned = cloned;\n        nodes.push_back(node);\n\
    \        return nodes.size() - 1;\n    }\n    static int index(int c) {\n    \
    \    assert(0 <= c - Base && c - Base < K);\n        return c - Base;\n    }\n\
    \    template <typename R>\n    int find_node(const R& t) const {\n        int\
    \ v = 0;\n        for (auto c : t) {\n            v = nodes[v].next[index(c)];\n\
    \            if (v == -1) return -1;\n        }\n        return v;\n    }\n  \
    \  void build_occ() {\n        if (occ_valid) return;\n        // \u8907\u88FD\
    \u3067\u306A\u3044\u72B6\u614B\u306F\u3061\u3087\u3046\u3069 1 \u3064\u306E\u7D42\
    \u308F\u308A\u306E\u4F4D\u7F6E\u3092\u6301\u3061\u3001suffix link \u306E\u6728\
    \u306E\u5B50\u5B6B\u306E\u4F4D\u7F6E\u3092\u307E\u3068\u3081\u308B\n        occ.assign(nodes.size(),\
    \ 0);\n        for (size_t v = 1; v < nodes.size(); v++) occ[v] = nodes[v].cloned\
    \ ? 0 : 1;\n        // len \u306E\u964D\u9806\u306B\u3001suffix link \u306E\u5148\
    \u3078\u8DB3\u3059 (\u8A08\u6570\u30BD\u30FC\u30C8)\n        std::vector<int>\
    \ cnt(n + 1, 0), order(nodes.size());\n        for (const auto& node : nodes)\
    \ cnt[node.len]++;\n        for (long long i = 1; i <= n; i++) cnt[i] += cnt[i\
    \ - 1];\n        for (int v = nodes.size() - 1; v >= 0; v--) order[--cnt[nodes[v].len]]\
    \ = v;\n        for (int i = nodes.size() - 1; i > 0; i--) {\n            int\
    \ v = order[i];\n            occ[nodes[v].link] += occ[v];\n        }\n      \
    \  occ_valid = true;\n    }\n\n   public:\n    SuffixAutomaton() { add_node(0,\
    \ -1, false); }\n    /**\n     * @brief \u5217 s \u306E Suffix Automaton O(|s|\
    \ K)\n     * @param s std::string \u3084 std::vector<int> \u306A\u3069\u3001\u8981\
    \u7D20\u3092\u6574\u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n     */\n\
    \    template <typename R>\n    explicit SuffixAutomaton(const R& s) : SuffixAutomaton()\
    \ {\n        for (auto c : s) extend(c);\n    }\n\n    /**\n     * @brief \u672B\
    \u5C3E\u306B\u6587\u5B57 c \u3092\u8FFD\u52A0\u3059\u308B \u306A\u3089\u3057 O(K)\n\
    \     */\n    void extend(int c) {\n        int i = index(c);\n        int cur\
    \ = add_node(nodes[last].len + 1, -1, false);\n        int p = last;\n       \
    \ while (p != -1 && nodes[p].next[i] == -1) {\n            nodes[p].next[i] =\
    \ cur;\n            p = nodes[p].link;\n        }\n        if (p == -1) {\n  \
    \          nodes[cur].link = 0;\n        } else {\n            int q = nodes[p].next[i];\n\
    \            if (nodes[p].len + 1 == nodes[q].len) {\n                nodes[cur].link\
    \ = q;\n            } else {\n                // q \u3092\u3001\u9577\u3055 len(p)\
    \ + 1 \u307E\u3067\u306E\u90E8\u5206 (\u8907\u88FD) \u3068\u6B8B\u308A\u306B\u5206\
    \u3051\u308B\n                int clone = add_node(nodes[p].len + 1, nodes[q].link,\
    \ true);\n                nodes[clone].next = nodes[q].next;\n               \
    \ while (p != -1 && nodes[p].next[i] == q) {\n                    nodes[p].next[i]\
    \ = clone;\n                    p = nodes[p].link;\n                }\n      \
    \          nodes[q].link = nodes[cur].link = clone;\n            }\n        }\n\
    \        last = cur;\n        n++;\n        occ_valid = false;\n    }\n\n    /**\n\
    \     * @brief \u72B6\u614B\u306E\u500B\u6570 (\u521D\u671F\u72B6\u614B\u3092\u542B\
    \u3080)\n     */\n    long long size() const { return nodes.size(); }\n    /**\n\
    \     * @brief \u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\u9577\u3055\n\
    \     */\n    long long length() const { return n; }\n    /**\n     * @brief \u6587\
    \u5B57\u5217\u5168\u4F53\u306B\u5BFE\u5FDC\u3059\u308B\u72B6\u614B\n     */\n\
    \    long long last_state() const { return last; }\n    /**\n     * @brief \u72B6\
    \u614B v \u306E\u6700\u9577\u306E\u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\u3055\
    \n     */\n    long long len(long long v) const { return nodes[v].len; }\n   \
    \ /**\n     * @brief \u72B6\u614B v \u306E suffix link (v \u306E\u6700\u9577\u306E\
    \u90E8\u5206\u6587\u5B57\u5217\u306E\u63A5\u5C3E\u8F9E\u3067\u3001endpos \u304C\
    \u7570\u306A\u308B\u6700\u9577\u306E\u3082\u306E\u306E\u72B6\u614B\u3002\u521D\
    \u671F\u72B6\u614B\u306A\u3089 -1)\n     * \u72B6\u614B v \u304C\u8868\u3059\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u9577\u3055\u306F len(link(v)) + 1 \u4EE5\u4E0A\
    \ len(v) \u4EE5\u4E0B\n     */\n    long long link(long long v) const { return\
    \ nodes[v].link; }\n    /**\n     * @brief \u72B6\u614B v \u304B\u3089\u6587\u5B57\
    \ c \u3067\u9032\u3093\u3060\u72B6\u614B (\u306A\u3051\u308C\u3070 -1)\n     */\n\
    \    long long next(long long v, int c) const { return nodes[v].next[index(c)];\
    \ }\n\n    /**\n     * @brief \u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\u5217\
    \u306E\u500B\u6570 (\u7A7A\u6587\u5B57\u5217\u3092\u9664\u304F) O(\u72B6\u614B\
    \u6570)\n     */\n    long long count_distinct_substrings() const {\n        long\
    \ long res = 0;\n        for (size_t v = 1; v < nodes.size(); v++) res += nodes[v].len\
    \ - nodes[nodes[v].link].len;\n        return res;\n    }\n    /**\n     * @brief\
    \ t \u306B\u5BFE\u5FDC\u3059\u308B\u72B6\u614B (t \u304C\u90E8\u5206\u6587\u5B57\
    \u5217\u3067\u306A\u3051\u308C\u3070 -1) O(|t|)\n     */\n    template <typename\
    \ R>\n    long long find(const R& t) const { return find_node(t); }\n    /**\n\
    \     * @brief t \u304C\u90E8\u5206\u6587\u5B57\u5217\u304B (\u7A7A\u6587\u5B57\
    \u5217\u306F\u90E8\u5206\u6587\u5B57\u5217) O(|t|)\n     */\n    template <typename\
    \ R>\n    bool contains(const R& t) const { return find_node(t) != -1; }\n   \
    \ /**\n     * @brief \u72B6\u614B v \u306E\u90E8\u5206\u6587\u5B57\u5217\u304C\
    \u51FA\u73FE\u3059\u308B\u56DE\u6570 (endpos \u306E\u5927\u304D\u3055\u3002\u521D\
    \u671F\u72B6\u614B\u306A\u3089 length() + 1)\n     * \u6700\u521D\u306B\u547C\u3093\
    \u3060\u3068\u304D (\u3068 extend \u306E\u5F8C) \u306B\u5168\u72B6\u614B\u306E\
    \u5024\u3092 O(\u72B6\u614B\u6570) \u3067\u6C42\u3081\u308B\n     */\n    long\
    \ long occurrences(long long v) {\n        build_occ();\n        return v == 0\
    \ ? n + 1 : occ[v];\n    }\n    /**\n     * @brief t \u304C\u90E8\u5206\u6587\u5B57\
    \u5217\u3068\u3057\u3066\u51FA\u73FE\u3059\u308B\u56DE\u6570 (\u91CD\u306A\u3063\
    \u3066\u3082\u3088\u3044\u3002\u7A7A\u6587\u5B57\u5217\u306A\u3089 length() +\
    \ 1) O(|t|)\n     */\n    template <typename R>\n    long long count_occurrences(const\
    \ R& t) {\n        int v = find_node(t);\n        return v == -1 ? 0 : occurrences(v);\n\
    \    }\n};\n#line 7 \"test/yosupo/number-of-substrings.2.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n    std::string\
    \ s;\n    std::cin >> s;\n    std::cout << SuffixAutomaton<26, 'a'>(s).count_distinct_substrings()\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include <iostream>\n#include <string>\n\n#include \"../../src/string/suffix-automaton.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    std::string s;\n    std::cin >> s;\n    std::cout << SuffixAutomaton<26,\
    \ 'a'>(s).count_distinct_substrings() << '\\n';\n}\n"
  dependsOn:
  - src/string/suffix-automaton.hpp
  isVerificationFile: true
  path: test/yosupo/number-of-substrings.2.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 00:25:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number-of-substrings.2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number-of-substrings.2.test.cpp
- /verify/test/yosupo/number-of-substrings.2.test.cpp.html
title: test/yosupo/number-of-substrings.2.test.cpp
---
