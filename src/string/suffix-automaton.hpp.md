---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/string/suffix-automaton.test.cpp
    title: test/unittest/string/suffix-automaton.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/string/number-of-substrings.2.test.cpp
    title: test/yosupo/string/number-of-substrings.2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Suffix Automaton
    links: []
  bundledCode: "#line 2 \"src/string/suffix-automaton.hpp\"\n\n/**\n * @file suffix-automaton.hpp\n\
    \ * @brief Suffix Automaton\n */\n\n#include <array>\n#include <cassert>\n#include\
    \ <vector>\n\n/**\n * @brief Suffix Automaton (\u6587\u5B57\u5217\u306E\u3059\u3079\
    \u3066\u306E\u90E8\u5206\u6587\u5B57\u5217\u3092\u53D7\u7406\u3059\u308B\u6700\
    \u5C0F\u306E\u6C7A\u5B9A\u6027\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3)\n *\n * \u72B6\
    \u614B\u306F O(n) \u500B (2n - 1 \u500B\u4EE5\u4E0B) \u3067\u3001\u5404\u72B6\u614B\
    \u306F endpos (\u51FA\u73FE\u3059\u308B\u7D42\u308F\u308A\u306E\u4F4D\u7F6E\u306E\
    \u96C6\u5408) \u304C\u540C\u3058\u90E8\u5206\u6587\u5B57\u5217\u306E\u96C6\u307E\
    \u308A\u3092\u8868\u3059\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066\
    \ 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\u3002\u9077\
    \u79FB\u306F\u5927\u304D\u3055 K \u306E\u914D\u5217\u3067\u6301\u3064\u3002\u521D\
    \u671F\u72B6\u614B\u306F 0 (\u7A7A\u6587\u5B57\u5217)\n * \u4F8B:\n * SuffixAutomaton<26,\
    \ 'a'> sa(\"abcbc\");\n * sa.count_distinct_substrings();  // 12\n * sa.count_occurrences(\"\
    bc\");      // 2\n *\n * @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam\
    \ Base \u6700\u5C0F\u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\n\
    class SuffixAutomaton {\n    struct Node {\n        std::array<int, K> next;\n\
    \        int len;      // \u3053\u306E\u72B6\u614B\u306E\u6700\u9577\u306E\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u9577\u3055\n        int link;     // suffix link\
    \ (\u521D\u671F\u72B6\u614B\u306F -1)\n        bool cloned;  // \u5206\u5272\u306E\
    \u305F\u3081\u306B\u8907\u88FD\u3057\u305F\u72B6\u614B\u304B\n    };\n    // \u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081\u3001\u72B6\u614B\u306E\u4E2D\
    \u8EAB\u306F int \u3067\u6301\u3064\u3002\u5916\u3078\u8FD4\u3059\u3068\u304D\u306B\
    \ long long \u306B\u3059\u308B\n    std::vector<Node> nodes;\n    int last = 0;\
    \  // \u6587\u5B57\u5217\u5168\u4F53\u306B\u5BFE\u5FDC\u3059\u308B\u72B6\u614B\
    \n    long long n = 0;\n    std::vector<long long> occ;  // \u5404\u72B6\u614B\
    \u306E endpos \u306E\u5927\u304D\u3055 (extend \u3057\u305F\u3089\u4F5C\u308A\u76F4\
    \u3059)\n    bool occ_valid = false;\n\n    int add_node(int len, int link, bool\
    \ cloned) {\n        Node node;\n        node.next.fill(-1);\n        node.len\
    \ = len, node.link = link, node.cloned = cloned;\n        nodes.push_back(node);\n\
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
    \    }\n    /**\n     * @brief t \u306E\u5404\u4F4D\u7F6E i \u306B\u3064\u3044\
    \u3066\u3001t[0, i] \u306E\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u90E8\u5206\u6587\
    \u5B57\u5217\u3067\u3042\u308B\u3082\u306E\u306E\u6700\u9577\u306E\u9577\u3055\
    \ O(|t|)\n     * \u6700\u5927\u5024\u304C t \u3068\u306E\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\u3055\u306B\u306A\u308B\n     * \u7BC4\
    \u56F2\u5916\u306E\u6587\u5B57 (c - Base \u304C 0 \u4EE5\u4E0A K \u672A\u6E80\u3067\
    \u306A\u3044) \u306F\u3001\u3069\u306E\u90E8\u5206\u6587\u5B57\u5217\u306B\u3082\
    \u542B\u307E\u308C\u306A\u3044\u6587\u5B57\u3068\u3057\u3066\u6271\u3046\n   \
    \  */\n    template <typename R>\n    std::vector<long long> match_lengths(const\
    \ R& t) const {\n        std::vector<long long> res;\n        // \u4ECA\u306E\u4F4D\
    \u7F6E\u3067\u7D42\u308F\u308A\u3001\u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\
    \u308B\u6700\u9577\u306E\u6587\u5B57\u5217\u3092\u3001\u72B6\u614B v \u3068\u9577\
    \u3055 l \u3067\u6301\u3064\n        int v = 0;\n        long long l = 0;\n  \
    \      for (auto c : t) {\n            const int k = static_cast<int>(c) - Base;\n\
    \            if (k < 0 || K <= k) {\n                v = 0, l = 0;\n         \
    \   } else {\n                // c \u3067\u9032\u3081\u306A\u3044\u9593\u306F\u3001\
    \u524D\u3092\u524A\u3063\u3066 endpos \u304C\u5897\u3048\u308B\u77ED\u3044\u63A5\
    \u5C3E\u8F9E\u306E\u72B6\u614B\u306B\u623B\u308B\n                // (\u521D\u671F\
    \u72B6\u614B\u307E\u3067\u623B\u3063\u305F\u3068\u304D\u306F l = 0 \u306B\u306A\
    \u3063\u3066\u3044\u3066\u3001c \u3067\u9032\u3081\u306A\u3051\u308C\u3070\u305D\
    \u306E\u307E\u307E)\n                while (v != 0 && nodes[v].next[k] == -1)\
    \ v = nodes[v].link, l = nodes[v].len;\n                if (nodes[v].next[k] !=\
    \ -1) v = nodes[v].next[k], l++;\n            }\n            res.push_back(l);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file suffix-automaton.hpp\n * @brief Suffix Automaton\n\
    \ */\n\n#include <array>\n#include <cassert>\n#include <vector>\n\n/**\n * @brief\
    \ Suffix Automaton (\u6587\u5B57\u5217\u306E\u3059\u3079\u3066\u306E\u90E8\u5206\
    \u6587\u5B57\u5217\u3092\u53D7\u7406\u3059\u308B\u6700\u5C0F\u306E\u6C7A\u5B9A\
    \u6027\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3)\n *\n * \u72B6\u614B\u306F O(n) \u500B\
    \ (2n - 1 \u500B\u4EE5\u4E0B) \u3067\u3001\u5404\u72B6\u614B\u306F endpos (\u51FA\
    \u73FE\u3059\u308B\u7D42\u308F\u308A\u306E\u4F4D\u7F6E\u306E\u96C6\u5408) \u304C\
    \u540C\u3058\u90E8\u5206\u6587\u5B57\u5217\u306E\u96C6\u307E\u308A\u3092\u8868\
    \u3059\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\u3066 0 \u4EE5\u4E0A K\
    \ \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\u3002\u9077\u79FB\u306F\u5927\
    \u304D\u3055 K \u306E\u914D\u5217\u3067\u6301\u3064\u3002\u521D\u671F\u72B6\u614B\
    \u306F 0 (\u7A7A\u6587\u5B57\u5217)\n * \u4F8B:\n * SuffixAutomaton<26, 'a'> sa(\"\
    abcbc\");\n * sa.count_distinct_substrings();  // 12\n * sa.count_occurrences(\"\
    bc\");      // 2\n *\n * @tparam K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam\
    \ Base \u6700\u5C0F\u306E\u6587\u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\n\
    class SuffixAutomaton {\n    struct Node {\n        std::array<int, K> next;\n\
    \        int len;      // \u3053\u306E\u72B6\u614B\u306E\u6700\u9577\u306E\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u9577\u3055\n        int link;     // suffix link\
    \ (\u521D\u671F\u72B6\u614B\u306F -1)\n        bool cloned;  // \u5206\u5272\u306E\
    \u305F\u3081\u306B\u8907\u88FD\u3057\u305F\u72B6\u614B\u304B\n    };\n    // \u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081\u3001\u72B6\u614B\u306E\u4E2D\
    \u8EAB\u306F int \u3067\u6301\u3064\u3002\u5916\u3078\u8FD4\u3059\u3068\u304D\u306B\
    \ long long \u306B\u3059\u308B\n    std::vector<Node> nodes;\n    int last = 0;\
    \  // \u6587\u5B57\u5217\u5168\u4F53\u306B\u5BFE\u5FDC\u3059\u308B\u72B6\u614B\
    \n    long long n = 0;\n    std::vector<long long> occ;  // \u5404\u72B6\u614B\
    \u306E endpos \u306E\u5927\u304D\u3055 (extend \u3057\u305F\u3089\u4F5C\u308A\u76F4\
    \u3059)\n    bool occ_valid = false;\n\n    int add_node(int len, int link, bool\
    \ cloned) {\n        Node node;\n        node.next.fill(-1);\n        node.len\
    \ = len, node.link = link, node.cloned = cloned;\n        nodes.push_back(node);\n\
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
    \    }\n    /**\n     * @brief t \u306E\u5404\u4F4D\u7F6E i \u306B\u3064\u3044\
    \u3066\u3001t[0, i] \u306E\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u90E8\u5206\u6587\
    \u5B57\u5217\u3067\u3042\u308B\u3082\u306E\u306E\u6700\u9577\u306E\u9577\u3055\
    \ O(|t|)\n     * \u6700\u5927\u5024\u304C t \u3068\u306E\u6700\u9577\u5171\u901A\
    \u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\u3055\u306B\u306A\u308B\n     * \u7BC4\
    \u56F2\u5916\u306E\u6587\u5B57 (c - Base \u304C 0 \u4EE5\u4E0A K \u672A\u6E80\u3067\
    \u306A\u3044) \u306F\u3001\u3069\u306E\u90E8\u5206\u6587\u5B57\u5217\u306B\u3082\
    \u542B\u307E\u308C\u306A\u3044\u6587\u5B57\u3068\u3057\u3066\u6271\u3046\n   \
    \  */\n    template <typename R>\n    std::vector<long long> match_lengths(const\
    \ R& t) const {\n        std::vector<long long> res;\n        // \u4ECA\u306E\u4F4D\
    \u7F6E\u3067\u7D42\u308F\u308A\u3001\u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\
    \u308B\u6700\u9577\u306E\u6587\u5B57\u5217\u3092\u3001\u72B6\u614B v \u3068\u9577\
    \u3055 l \u3067\u6301\u3064\n        int v = 0;\n        long long l = 0;\n  \
    \      for (auto c : t) {\n            const int k = static_cast<int>(c) - Base;\n\
    \            if (k < 0 || K <= k) {\n                v = 0, l = 0;\n         \
    \   } else {\n                // c \u3067\u9032\u3081\u306A\u3044\u9593\u306F\u3001\
    \u524D\u3092\u524A\u3063\u3066 endpos \u304C\u5897\u3048\u308B\u77ED\u3044\u63A5\
    \u5C3E\u8F9E\u306E\u72B6\u614B\u306B\u623B\u308B\n                // (\u521D\u671F\
    \u72B6\u614B\u307E\u3067\u623B\u3063\u305F\u3068\u304D\u306F l = 0 \u306B\u306A\
    \u3063\u3066\u3044\u3066\u3001c \u3067\u9032\u3081\u306A\u3051\u308C\u3070\u305D\
    \u306E\u307E\u307E)\n                while (v != 0 && nodes[v].next[k] == -1)\
    \ v = nodes[v].link, l = nodes[v].len;\n                if (nodes[v].next[k] !=\
    \ -1) v = nodes[v].next[k], l++;\n            }\n            res.push_back(l);\n\
    \        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/suffix-automaton.hpp
  requiredBy: []
  timestamp: '2026-10-20 16:28:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/string/suffix-automaton.test.cpp
  - test/yosupo/string/number-of-substrings.2.test.cpp
documentation_of: src/string/suffix-automaton.hpp
layout: document
title: Suffix Automaton
---

文字列のすべての部分文字列を受理する最小の決定性オートマトンです。状態は $2n - 1$ 個以下で、各状態は「出現する終わりの位置の集合 (endpos) が同じ部分文字列」の集まりを表します。異なる部分文字列の個数、部分文字列の判定、出現回数、別の文字列との最長共通部分文字列を求められます。末尾に 1 文字ずつ追加することもできます。

```cpp
SuffixAutomaton<26, 'a'> sa(std::string("abcbc"));
sa.count_distinct_substrings();  // 12
sa.contains(std::string("cb"));  // true
sa.count_occurrences(std::string("bc"));  // 2
sa.extend('a');                  // 末尾に 'a' を追加して "abcbca" にする

// t の各位置で終わる接尾辞のうち、部分文字列である最長の長さ。最大値が最長共通部分文字列の長さ
auto ml = sa.match_lengths(std::string("cbx"));  // {1, 2, 0}
```

- 文字 `c` は `c - Base` として $0$ 以上 $K$ 未満の番号に直します。英小文字なら `SuffixAutomaton<26, 'a'>`、$0$ 以上 $K$ 未満の整数の列なら `SuffixAutomaton<K, 0>` です。
- 遷移は大きさ $K$ の配列で持ちます。$O(1)$ でたどれる代わりに、メモリは状態数 $\times K$ に比例します。文字の種類が多いときは座標圧縮してから渡します。
- 初期状態 (空文字列) は 0 です。状態 $v$ の部分文字列は、長さが `len(link(v)) + 1` 以上 `len(v)` 以下の、`len(v)` の部分文字列の接尾辞たちです。

## メンバ関数

状態・長さ・個数は `long long` です。$n$ は文字列の長さです。

| 関数 | 説明 | 計算量 |
|---|---|---|
| `SuffixAutomaton()` | 空文字列 | $O(K)$ |
| `SuffixAutomaton(s)` | 列 `s` (`std::string` や `std::vector<int>` など) | $O(nK)$ |
| `extend(c)` | 末尾に文字 `c` を追加する | ならし $O(K)$ |
| `size()` | 状態の個数 (初期状態を含む) | $O(1)$ |
| `length()` | 文字列の長さ | $O(1)$ |
| `last_state()` | 文字列全体に対応する状態 | $O(1)$ |
| `len(v)` | 状態 `v` の最長の部分文字列の長さ | $O(1)$ |
| `link(v)` | 状態 `v` の suffix link (初期状態なら -1) | $O(1)$ |
| `next(v, c)` | 状態 `v` から文字 `c` で進んだ状態 (なければ -1) | $O(1)$ |
| `count_distinct_substrings()` | 異なる部分文字列の個数 (空文字列を除く) | $O(n)$ |
| `find(t)` | `t` に対応する状態 (部分文字列でなければ -1) | $O(\lvert t \rvert)$ |
| `contains(t)` | `t` が部分文字列か (空文字列は部分文字列) | $O(\lvert t \rvert)$ |
| `occurrences(v)` | 状態 `v` の部分文字列が出現する回数 (endpos の大きさ。初期状態なら $n + 1$) | 初回と `extend` の後は $O(n)$、ほかは $O(1)$ |
| `count_occurrences(t)` | `t` が出現する回数 (重なってもよい。空文字列なら $n + 1$) | $O(\lvert t \rvert)$ (+ `occurrences` の計算) |
| `match_lengths(t)` | `t` の各位置 $i$ について、`t[0, i]` の接尾辞のうち部分文字列であるものの最長の長さ (`std::vector<long long>`)。範囲外の文字はどの部分文字列にも含まれない文字として扱う | $O(\lvert t \rvert)$ |

出現回数は、複製でない状態にそれぞれ 1 つの終わりの位置を割り当て、suffix link の木で子孫の分を足し合わせて求めます。

`match_lengths` は、`t` を 1 文字ずつ読みながら、今の位置で終わる部分文字列の最長のものを状態と長さで持ちます。次の文字で進めなければ suffix link をたどって前を削ります。同じ状態の文字列は endpos が同じで次に続ける文字も同じなので、削るのは endpos が増える長さまでまとめて飛ばせます。1 つの文字列 `s` を固定して多くの `t` との最長共通部分文字列を求める場合などに、`s` の Suffix Automaton を 1 回作れば、各 `t` に $O(\lvert t \rvert)$ で答えられます。

## 関連

- 接尾辞を辞書順に並べるなら [Suffix Array](suffix-array.hpp)
- 2 つの文字列の最長共通部分文字列の位置まで求めるなら [最長共通部分文字列](longest-common-substring.hpp)
- 複数のパターンをまとめて探すなら [Aho-Corasick](aho-corasick.hpp)
