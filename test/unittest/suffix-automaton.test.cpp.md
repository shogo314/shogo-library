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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/suffix-automaton.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ SuffixAutomaton \u3092\u3001\u3059\u3079\u3066\u306E\u90E8\u5206\u6587\u5B57\
    \u5217\u3092\u6570\u3048\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\
    \u5217\u306E\u500B\u6570\u3001contains\u3001\u51FA\u73FE\u56DE\u6570\u3001\u72B6\
    \u614B\u6570\u306E\u4E0A\u9650\u3001len\u30FBlink\u30FBnext \u306E\u6027\u8CEA\
    \u3001\u6574\u6570\u306E\u5217\u3001match_lengths\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/string/suffix-automaton.hpp\"\
    \n\n/**\n * @file suffix-automaton.hpp\n * @brief Suffix Automaton\n */\n\n#include\
    \ <array>\n#include <cassert>\n#include <vector>\n\n/**\n * @brief Suffix Automaton\
    \ (\u6587\u5B57\u5217\u306E\u3059\u3079\u3066\u306E\u90E8\u5206\u6587\u5B57\u5217\
    \u3092\u53D7\u7406\u3059\u308B\u6700\u5C0F\u306E\u6C7A\u5B9A\u6027\u30AA\u30FC\
    \u30C8\u30DE\u30C8\u30F3)\n *\n * \u72B6\u614B\u306F O(n) \u500B (2n - 1 \u500B\
    \u4EE5\u4E0B) \u3067\u3001\u5404\u72B6\u614B\u306F endpos (\u51FA\u73FE\u3059\u308B\
    \u7D42\u308F\u308A\u306E\u4F4D\u7F6E\u306E\u96C6\u5408) \u304C\u540C\u3058\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u96C6\u307E\u308A\u3092\u8868\u3059\n * \u6587\u5B57\
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
    \        }\n        return res;\n    }\n};\n#line 8 \"test/unittest/suffix-automaton.test.cpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <random>\n\
    #include <string>\n#line 15 \"test/unittest/suffix-automaton.test.cpp\"\n\nbool\
    \ ok = true;\nvoid check(bool cond, const char* what) {\n    if (!cond && ok)\
    \ std::cerr << \"failed: \" << what << std::endl;\n    if (!cond) ok = false;\n\
    }\n\n// \u90E8\u5206\u6587\u5B57\u5217\u3054\u3068\u306E\u51FA\u73FE\u56DE\u6570\
    \nstd::map<std::string, long long> naive_counts(const std::string& s) {\n    std::map<std::string,\
    \ long long> res;\n    for (size_t i = 0; i < s.size(); i++)\n        for (size_t\
    \ j = i + 1; j <= s.size(); j++) res[s.substr(i, j - i)]++;\n    return res;\n\
    }\n\nint main() {\n    std::mt19937_64 rng(314);\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        int n = rng() % 15, k = rng() % 3 + 1;\n     \
    \   std::string s;\n        for (int i = 0; i < n; i++) s += static_cast<char>('a'\
    \ + rng() % k);\n        // \u4E00\u5EA6\u306B\u4F5C\u308B\u5834\u5408\u3068\u3001\
    1 \u6587\u5B57\u305A\u3064 extend \u3057\u9014\u4E2D\u3067\u3082\u78BA\u304B\u3081\
    \u308B\u5834\u5408\n        SuffixAutomaton<26, 'a'> sa(s), inc;\n        std::string\
    \ pre;\n        for (char c : s) {\n            inc.extend(c);\n            pre\
    \ += c;\n            auto cnt = naive_counts(pre);\n            check(inc.count_distinct_substrings()\
    \ == static_cast<long long>(cnt.size()), \"extend \u306E\u9014\u4E2D\u306E\u7570\
    \u306A\u308B\u90E8\u5206\u6587\u5B57\u5217\u306E\u500B\u6570\");\n           \
    \ for (const auto& [t, c2] : cnt) check(inc.count_occurrences(t) == c2, \"extend\
    \ \u306E\u9014\u4E2D\u306E\u51FA\u73FE\u56DE\u6570\");\n        }\n        auto\
    \ cnt = naive_counts(s);\n        check(sa.length() == n && inc.length() == n,\
    \ \"length\");\n        check(sa.count_distinct_substrings() == static_cast<long\
    \ long>(cnt.size()), \"\u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\u5217\u306E\u500B\
    \u6570\");\n        check(sa.size() <= std::max(2 * n, 1), \"\u72B6\u614B\u6570\
    \");\n        // \u9577\u3055 0 \u304B\u3089 n + 1 \u306E\u6587\u5B57\u5217\u3092\
    \u3044\u304F\u3064\u304B\u8A66\u3059 (\u90E8\u5206\u6587\u5B57\u5217\u306E\u3082\
    \u306E\u3082\u3001\u305D\u3046\u3067\u306A\u3044\u3082\u306E\u3082)\n        for\
    \ (int q = 0; q < 30; q++) {\n            std::string t;\n            if (n >\
    \ 0 && rng() % 2) {\n                int i = rng() % n, j = i + rng() % (n - i)\
    \ + 1;\n                t = s.substr(i, j - i);\n            } else {\n      \
    \          int len = rng() % (n + 2);\n                for (int i = 0; i < len;\
    \ i++) t += static_cast<char>('a' + rng() % k);\n            }\n            long\
    \ long e = t.empty() ? n + 1 : (cnt.count(t) ? cnt[t] : 0);\n            check(sa.contains(t)\
    \ == (e > 0), \"contains\");\n            check(sa.count_occurrences(t) == e,\
    \ \"count_occurrences\");\n            check(inc.count_occurrences(t) == e, \"\
    extend \u3067\u4F5C\u3063\u305F count_occurrences\");\n            check((sa.find(t)\
    \ == -1) == (e == 0), \"find\");\n        }\n        // \u5404\u72B6\u614B\u306E\
    \u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\u3055\u306F len(link(v)) + 1 \u4EE5\
    \u4E0A len(v) \u4EE5\u4E0B\n        for (const auto& [t, c] : cnt) {\n       \
    \     long long v = sa.find(t);\n            check(sa.len(sa.link(v)) < static_cast<long\
    \ long>(t.size()) && static_cast<long long>(t.size()) <= sa.len(v), \"len \u3068\
    \ link\");\n            check(sa.occurrences(v) == c, \"occurrences(v)\");\n \
    \       }\n        check(sa.link(0) == -1 && sa.len(0) == 0, \"\u521D\u671F\u72B6\
    \u614B\");\n        check(sa.len(sa.last_state()) == n, \"last_state\");\n   \
    \     if (n > 0) check(sa.next(0, s[0]) == sa.find(s.substr(0, 1)), \"next\");\n\
    \    }\n    // \u6574\u6570\u306E\u5217 (Base = 0)\n    {\n        std::vector<int>\
    \ v = {3, 1, 3, 1, 3};\n        SuffixAutomaton<4, 0> sa(v);\n        check(sa.count_distinct_substrings()\
    \ == 9, \"\u6574\u6570\u306E\u5217\u306E\u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\
    \u5217\u306E\u500B\u6570\");\n        check(sa.count_occurrences(std::vector<int>{3,\
    \ 1, 3}) == 2, \"\u6574\u6570\u306E\u5217\u306E\u51FA\u73FE\u56DE\u6570\");\n\
    \    }\n    // docs \u306E\u4F8B\n    {\n        SuffixAutomaton<26, 'a'> sa(std::string(\"\
    abcbc\"));\n        check(sa.count_distinct_substrings() == 12 && sa.count_occurrences(std::string(\"\
    bc\")) == 2, \"docs \u306E\u4F8B\");\n    }\n    // \u9577\u3044\u6587\u5B57\u5217\
    \u3067\u3082\u72B6\u614B\u6570\u306F 2n - 1 \u4EE5\u4E0B\n    {\n        std::string\
    \ s;\n        for (int i = 0; i < 200000; i++) s += static_cast<char>('a' + rng()\
    \ % 2);\n        SuffixAutomaton<26, 'a'> sa(s);\n        check(sa.size() <= 2\
    \ * 200000 - 1, \"\u9577\u3044\u6587\u5B57\u5217\u306E\u72B6\u614B\u6570\");\n\
    \        check(sa.count_occurrences(std::string(\"a\")) + sa.count_occurrences(std::string(\"\
    b\")) == 200000, \"\u9577\u3044\u6587\u5B57\u5217\u306E\u51FA\u73FE\u56DE\u6570\
    \");\n    }\n    // match_lengths: t \u306E\u5404\u4F4D\u7F6E\u3067\u7D42\u308F\
    \u308B\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001s \u306E\u90E8\u5206\u6587\u5B57\
    \u5217\u3067\u3042\u308B\u6700\u9577\u306E\u9577\u3055\u3092\u611A\u76F4\u306B\
    \u6C42\u3081\u3066\u6BD4\u3079\u308B\n    // \u7BC4\u56F2\u5916\u306E\u6587\u5B57\
    \ (K = 3 \u3067 'd') \u306F\u3001\u3069\u306E\u90E8\u5206\u6587\u5B57\u5217\u306B\
    \u3082\u542B\u307E\u308C\u306A\u3044\n    for (int rep = 0; rep < 2000 && ok;\
    \ rep++) {\n        int n = rng() % 15, m = rng() % 15;\n        std::string s,\
    \ t;\n        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() %\
    \ 3);\n        for (int i = 0; i < m; i++) t += static_cast<char>('a' + rng()\
    \ % 4);\n        SuffixAutomaton<3, 'a'> sa(s);\n        auto counts = naive_counts(s);\n\
    \        auto res = sa.match_lengths(t);\n        check(static_cast<int>(res.size())\
    \ == m, \"match_lengths \u306E\u9577\u3055\");\n        long long best = 0;\n\
    \        for (int i = 0; i < m && ok; i++) {\n            long long l = 0;\n \
    \           while (l < i + 1 && counts.count(t.substr(i - l, l + 1))) l++;\n \
    \           check(res[i] == l, \"match_lengths\");\n            best = std::max(best,\
    \ l);\n        }\n        // \u6700\u5927\u5024\u306F\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u9577\u3055\n        long long lcs = 0;\n     \
    \   for (int i = 0; i < m; i++)\n            for (int j = i + 1; j <= m; j++)\n\
    \                if (counts.count(t.substr(i, j - i))) lcs = std::max(lcs, static_cast<long\
    \ long>(j - i));\n        check(best == lcs, \"match_lengths \u306E\u6700\u5927\
    \u5024\");\n    }\n    // \u6574\u6570\u306E\u5217\u3067\u3082\u4F7F\u3048\u308B\
    \n    {\n        SuffixAutomaton<5, 0> sa(std::vector<int>{1, 2, 3, 2, 3});\n\
    \        check((sa.match_lengths(std::vector<int>{2, 3, 4, 2, 3, 2}) == std::vector<long\
    \ long>{1, 2, 0, 1, 2, 3}), \"match_lengths \u6574\u6570\u306E\u5217\");\n   \
    \ }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// SuffixAutomaton \u3092\u3001\u3059\u3079\u3066\u306E\u90E8\u5206\u6587\u5B57\
    \u5217\u3092\u6570\u3048\u308B\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\
    \u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// \u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\
    \u5217\u306E\u500B\u6570\u3001contains\u3001\u51FA\u73FE\u56DE\u6570\u3001\u72B6\
    \u614B\u6570\u306E\u4E0A\u9650\u3001len\u30FBlink\u30FBnext \u306E\u6027\u8CEA\
    \u3001\u6574\u6570\u306E\u5217\u3001match_lengths\n// \u554F\u984C\u306E\u5165\
    \u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\
    \u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../src/string/suffix-automaton.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <map>\n#include <random>\n\
    #include <string>\n#include <vector>\n\nbool ok = true;\nvoid check(bool cond,\
    \ const char* what) {\n    if (!cond && ok) std::cerr << \"failed: \" << what\
    \ << std::endl;\n    if (!cond) ok = false;\n}\n\n// \u90E8\u5206\u6587\u5B57\u5217\
    \u3054\u3068\u306E\u51FA\u73FE\u56DE\u6570\nstd::map<std::string, long long> naive_counts(const\
    \ std::string& s) {\n    std::map<std::string, long long> res;\n    for (size_t\
    \ i = 0; i < s.size(); i++)\n        for (size_t j = i + 1; j <= s.size(); j++)\
    \ res[s.substr(i, j - i)]++;\n    return res;\n}\n\nint main() {\n    std::mt19937_64\
    \ rng(314);\n    for (int rep = 0; rep < 2000 && ok; rep++) {\n        int n =\
    \ rng() % 15, k = rng() % 3 + 1;\n        std::string s;\n        for (int i =\
    \ 0; i < n; i++) s += static_cast<char>('a' + rng() % k);\n        // \u4E00\u5EA6\
    \u306B\u4F5C\u308B\u5834\u5408\u3068\u30011 \u6587\u5B57\u305A\u3064 extend \u3057\
    \u9014\u4E2D\u3067\u3082\u78BA\u304B\u3081\u308B\u5834\u5408\n        SuffixAutomaton<26,\
    \ 'a'> sa(s), inc;\n        std::string pre;\n        for (char c : s) {\n   \
    \         inc.extend(c);\n            pre += c;\n            auto cnt = naive_counts(pre);\n\
    \            check(inc.count_distinct_substrings() == static_cast<long long>(cnt.size()),\
    \ \"extend \u306E\u9014\u4E2D\u306E\u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\u5217\
    \u306E\u500B\u6570\");\n            for (const auto& [t, c2] : cnt) check(inc.count_occurrences(t)\
    \ == c2, \"extend \u306E\u9014\u4E2D\u306E\u51FA\u73FE\u56DE\u6570\");\n     \
    \   }\n        auto cnt = naive_counts(s);\n        check(sa.length() == n &&\
    \ inc.length() == n, \"length\");\n        check(sa.count_distinct_substrings()\
    \ == static_cast<long long>(cnt.size()), \"\u7570\u306A\u308B\u90E8\u5206\u6587\
    \u5B57\u5217\u306E\u500B\u6570\");\n        check(sa.size() <= std::max(2 * n,\
    \ 1), \"\u72B6\u614B\u6570\");\n        // \u9577\u3055 0 \u304B\u3089 n + 1 \u306E\
    \u6587\u5B57\u5217\u3092\u3044\u304F\u3064\u304B\u8A66\u3059 (\u90E8\u5206\u6587\
    \u5B57\u5217\u306E\u3082\u306E\u3082\u3001\u305D\u3046\u3067\u306A\u3044\u3082\
    \u306E\u3082)\n        for (int q = 0; q < 30; q++) {\n            std::string\
    \ t;\n            if (n > 0 && rng() % 2) {\n                int i = rng() % n,\
    \ j = i + rng() % (n - i) + 1;\n                t = s.substr(i, j - i);\n    \
    \        } else {\n                int len = rng() % (n + 2);\n              \
    \  for (int i = 0; i < len; i++) t += static_cast<char>('a' + rng() % k);\n  \
    \          }\n            long long e = t.empty() ? n + 1 : (cnt.count(t) ? cnt[t]\
    \ : 0);\n            check(sa.contains(t) == (e > 0), \"contains\");\n       \
    \     check(sa.count_occurrences(t) == e, \"count_occurrences\");\n          \
    \  check(inc.count_occurrences(t) == e, \"extend \u3067\u4F5C\u3063\u305F count_occurrences\"\
    );\n            check((sa.find(t) == -1) == (e == 0), \"find\");\n        }\n\
    \        // \u5404\u72B6\u614B\u306E\u90E8\u5206\u6587\u5B57\u5217\u306E\u9577\
    \u3055\u306F len(link(v)) + 1 \u4EE5\u4E0A len(v) \u4EE5\u4E0B\n        for (const\
    \ auto& [t, c] : cnt) {\n            long long v = sa.find(t);\n            check(sa.len(sa.link(v))\
    \ < static_cast<long long>(t.size()) && static_cast<long long>(t.size()) <= sa.len(v),\
    \ \"len \u3068 link\");\n            check(sa.occurrences(v) == c, \"occurrences(v)\"\
    );\n        }\n        check(sa.link(0) == -1 && sa.len(0) == 0, \"\u521D\u671F\
    \u72B6\u614B\");\n        check(sa.len(sa.last_state()) == n, \"last_state\");\n\
    \        if (n > 0) check(sa.next(0, s[0]) == sa.find(s.substr(0, 1)), \"next\"\
    );\n    }\n    // \u6574\u6570\u306E\u5217 (Base = 0)\n    {\n        std::vector<int>\
    \ v = {3, 1, 3, 1, 3};\n        SuffixAutomaton<4, 0> sa(v);\n        check(sa.count_distinct_substrings()\
    \ == 9, \"\u6574\u6570\u306E\u5217\u306E\u7570\u306A\u308B\u90E8\u5206\u6587\u5B57\
    \u5217\u306E\u500B\u6570\");\n        check(sa.count_occurrences(std::vector<int>{3,\
    \ 1, 3}) == 2, \"\u6574\u6570\u306E\u5217\u306E\u51FA\u73FE\u56DE\u6570\");\n\
    \    }\n    // docs \u306E\u4F8B\n    {\n        SuffixAutomaton<26, 'a'> sa(std::string(\"\
    abcbc\"));\n        check(sa.count_distinct_substrings() == 12 && sa.count_occurrences(std::string(\"\
    bc\")) == 2, \"docs \u306E\u4F8B\");\n    }\n    // \u9577\u3044\u6587\u5B57\u5217\
    \u3067\u3082\u72B6\u614B\u6570\u306F 2n - 1 \u4EE5\u4E0B\n    {\n        std::string\
    \ s;\n        for (int i = 0; i < 200000; i++) s += static_cast<char>('a' + rng()\
    \ % 2);\n        SuffixAutomaton<26, 'a'> sa(s);\n        check(sa.size() <= 2\
    \ * 200000 - 1, \"\u9577\u3044\u6587\u5B57\u5217\u306E\u72B6\u614B\u6570\");\n\
    \        check(sa.count_occurrences(std::string(\"a\")) + sa.count_occurrences(std::string(\"\
    b\")) == 200000, \"\u9577\u3044\u6587\u5B57\u5217\u306E\u51FA\u73FE\u56DE\u6570\
    \");\n    }\n    // match_lengths: t \u306E\u5404\u4F4D\u7F6E\u3067\u7D42\u308F\
    \u308B\u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001s \u306E\u90E8\u5206\u6587\u5B57\
    \u5217\u3067\u3042\u308B\u6700\u9577\u306E\u9577\u3055\u3092\u611A\u76F4\u306B\
    \u6C42\u3081\u3066\u6BD4\u3079\u308B\n    // \u7BC4\u56F2\u5916\u306E\u6587\u5B57\
    \ (K = 3 \u3067 'd') \u306F\u3001\u3069\u306E\u90E8\u5206\u6587\u5B57\u5217\u306B\
    \u3082\u542B\u307E\u308C\u306A\u3044\n    for (int rep = 0; rep < 2000 && ok;\
    \ rep++) {\n        int n = rng() % 15, m = rng() % 15;\n        std::string s,\
    \ t;\n        for (int i = 0; i < n; i++) s += static_cast<char>('a' + rng() %\
    \ 3);\n        for (int i = 0; i < m; i++) t += static_cast<char>('a' + rng()\
    \ % 4);\n        SuffixAutomaton<3, 'a'> sa(s);\n        auto counts = naive_counts(s);\n\
    \        auto res = sa.match_lengths(t);\n        check(static_cast<int>(res.size())\
    \ == m, \"match_lengths \u306E\u9577\u3055\");\n        long long best = 0;\n\
    \        for (int i = 0; i < m && ok; i++) {\n            long long l = 0;\n \
    \           while (l < i + 1 && counts.count(t.substr(i - l, l + 1))) l++;\n \
    \           check(res[i] == l, \"match_lengths\");\n            best = std::max(best,\
    \ l);\n        }\n        // \u6700\u5927\u5024\u306F\u6700\u9577\u5171\u901A\u90E8\
    \u5206\u6587\u5B57\u5217\u306E\u9577\u3055\n        long long lcs = 0;\n     \
    \   for (int i = 0; i < m; i++)\n            for (int j = i + 1; j <= m; j++)\n\
    \                if (counts.count(t.substr(i, j - i))) lcs = std::max(lcs, static_cast<long\
    \ long>(j - i));\n        check(best == lcs, \"match_lengths \u306E\u6700\u5927\
    \u5024\");\n    }\n    // \u6574\u6570\u306E\u5217\u3067\u3082\u4F7F\u3048\u308B\
    \n    {\n        SuffixAutomaton<5, 0> sa(std::vector<int>{1, 2, 3, 2, 3});\n\
    \        check((sa.match_lengths(std::vector<int>{2, 3, 4, 2, 3, 2}) == std::vector<long\
    \ long>{1, 2, 0, 1, 2, 3}), \"match_lengths \u6574\u6570\u306E\u5217\");\n   \
    \ }\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/string/suffix-automaton.hpp
  isVerificationFile: true
  path: test/unittest/suffix-automaton.test.cpp
  requiredBy: []
  timestamp: '2026-10-20 16:28:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/suffix-automaton.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/suffix-automaton.test.cpp
- /verify/test/unittest/suffix-automaton.test.cpp.html
title: test/unittest/suffix-automaton.test.cpp
---
