---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/aho-corasick.hpp
    title: Aho-Corasick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aho_corasick
    links:
    - https://judge.yosupo.jp/problem/aho_corasick
  bundledCode: "#line 1 \"test/yosupo/string/aho-corasick.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aho_corasick\"\n\n#line 2 \"src/string/aho-corasick.hpp\"\
    \n\n/**\n * @file aho-corasick.hpp\n * @brief Aho-Corasick\n */\n\n#include <array>\n\
    #include <cassert>\n#include <cstddef>\n#include <iterator>\n#include <optional>\n\
    #include <type_traits>\n#include <utility>\n#include <vector>\n\n/**\n * @brief\
    \ Aho-Corasick (\u8907\u6570\u306E\u30D1\u30BF\u30FC\u30F3\u306E\u7167\u5408)\n\
    \ *\n * \u30D1\u30BF\u30FC\u30F3\u3092 add \u3067\u8FFD\u52A0\u3057\u3066\u304B\
    \u3089 build \u3092\u547C\u3076\u3002\u6587\u5B57 c \u306F c - Base \u3068\u3057\
    \u3066 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\n * \u30CE\
    \u30FC\u30C9\u306F Trie \u3068\u540C\u3058\u304F\u3001\u6587\u5B57\u5217\u3092\
    \u8FFD\u52A0\u3057\u305F\u9806\u306B\u4F5C\u3063\u305F\u756A\u53F7\u3092\u6301\
    \u3064\u3002\u6839\u306F\u30CE\u30FC\u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u4F8B\
    :\n * AhoCorasick<26, 'a'> ac;\n * ac.add(\"he\");\n * ac.add(\"she\");\n * ac.build();\n\
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
    \ find_all \u304C\u8FD4\u3059\u3001\u30D1\u30BF\u30FC\u30F3\u304C\u73FE\u308C\u305F\
    \u4F4D\u7F6E\n     */\n    struct Match {\n        long long pos;  //!< \u958B\
    \u59CB\u4F4D\u7F6E\n        long long id;   //!< \u30D1\u30BF\u30FC\u30F3\u306E\
    \u756A\u53F7\n        friend bool operator==(const Match& a, const Match& b) {\
    \ return a.pos == b.pos && a.id == b.id; }\n        friend bool operator!=(const\
    \ Match& a, const Match& b) { return !(a == b); }\n    };\n\n   private:\n   \
    \ template <typename R>\n    class Matches {\n        const AhoCorasick* ac;\n\
    \        R text;\n        using Text = std::remove_reference_t<R>;\n        using\
    \ TextIterator = decltype(std::begin(std::declval<const Text&>()));\n        using\
    \ TextSentinel = decltype(std::end(std::declval<const Text&>()));\n\n       public:\n\
    \        Matches(const AhoCorasick* ac, R&& text) : ac(ac), text(std::forward<R>(text))\
    \ {}\n\n        class iterator {\n            const AhoCorasick* ac = nullptr;\n\
    \            // \u7D42\u7AEF iterator \u306F\u5165\u529B\u3092\u6301\u305F\u306A\
    \u3044\u3002\u5165\u529B iterator \u306E\u30C7\u30D5\u30A9\u30EB\u30C8\u69CB\u7BC9\
    \u306F\u8981\u6C42\u3057\u306A\u3044\u3002\n            std::optional<TextIterator>\
    \ cursor;\n            std::optional<TextSentinel> stop;\n            long long\
    \ pos = 0;\n            int v = 0, u = -1, id = -1;\n\n           public:\n  \
    \          using value_type = Match;\n            using difference_type = std::ptrdiff_t;\n\
    \            using reference = value_type;\n            using pointer = void;\n\
    \            using iterator_category = std::input_iterator_tag;\n\n          \
    \  iterator() = default;\n            iterator(const AhoCorasick* ac, TextIterator\
    \ cursor, TextSentinel stop) : ac(ac), cursor(cursor), stop(stop) { ++*this; }\n\
    \            value_type operator*() const { return {pos - ac->nodes[u].depth,\
    \ id}; }\n            iterator& operator++() {\n                if (id != -1)\
    \ {\n                    id = ac->next_pattern[id];\n                    if (id\
    \ != -1) return *this;\n                    u = ac->nodes[u].out;\n          \
    \          if (u != -1) {\n                        id = ac->nodes[u].head;\n \
    \                       return *this;\n                    }\n               \
    \ }\n                while (*cursor != *stop) {\n                    v = ac->nodes[v].next[index(**cursor)];\n\
    \                    ++*cursor;\n                    ++pos;\n                \
    \    u = ac->nodes[v].head != -1 ? v : ac->nodes[v].out;\n                   \
    \ if (u != -1) {\n                        id = ac->nodes[u].head;\n          \
    \              break;\n                    }\n                }\n            \
    \    return *this;\n            }\n            iterator operator++(int) {\n  \
    \              auto previous = *this;\n                ++*this;\n            \
    \    return previous;\n            }\n            bool operator==(const iterator&\
    \ other) const {\n                if (id == -1 || other.id == -1) return id ==\
    \ other.id;\n                return ac == other.ac && pos == other.pos && id ==\
    \ other.id;\n            }\n            bool operator!=(const iterator& other)\
    \ const { return !(*this == other); }\n        };\n\n        iterator begin()\
    \ const { return iterator(ac, std::begin(std::as_const(text)), std::end(std::as_const(text)));\
    \ }\n        iterator end() const { return iterator(); }\n    };\n\n   public:\n\
    \    /**\n     * @brief \u4E00\u81F4\u3092 Match {pos, id} \u3068\u3057\u3066\u9045\
    \u5EF6\u5217\u6319\u3059\u308B\u3002\u5168\u8D70\u67FB O(|text| + \u51FA\u529B\
    \u306E\u500B\u6570)\u3001\u5217\u6319\u72B6\u614B\u306F O(1)\n     * \u7D42\u4E86\
    \u4F4D\u7F6E\u306E\u6607\u9806\u3002\u540C\u3058\u7D42\u4E86\u4F4D\u7F6E\u306A\
    \u3089\u9577\u3055\u306E\u964D\u9806\u3001\u540C\u3058\u9577\u3055\u306A\u3089\
    \u30D1\u30BF\u30FC\u30F3\u756A\u53F7\u306E\u6607\u9806\n     * \u5DE6\u8FBA\u5024\
    \u306E text \u306F\u53C2\u7167\u3057\u3001\u53F3\u8FBA\u5024\u306F\u6240\u6709\
    \u3059\u308B\n     * @pre \u8D70\u67FB\u304C\u7D42\u308F\u308B\u307E\u3067\u3001\
    \u3053\u306E\u30AA\u30FC\u30C8\u30DE\u30C8\u30F3\u3068\u53C2\u7167\u3059\u308B\
    \u5165\u529B\u3092\u6709\u52B9\u306A\u307E\u307E\u4FDD\u6301\u3059\u308B\u3053\
    \u3068\n     */\n    template <typename R>\n    auto find_all(R&& text) const\
    \ {\n        assert(built);\n        return Matches<R>(this, std::forward<R>(text));\n\
    \    }\n};\n#line 4 \"test/yosupo/string/aho-corasick.test.cpp\"\n\n#include <iostream>\n\
    #include <string>\n#line 8 \"test/yosupo/string/aho-corasick.test.cpp\"\n\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n;\n    std::cin >> n;\n    AhoCorasick<26, 'a'> ac;\n    std::vector<long\
    \ long> id(n);\n    for (int i = 0; i < n; i++) {\n        std::string s;\n  \
    \      std::cin >> s;\n        id[i] = ac.add(s);\n    }\n    ac.build();\n  \
    \  // \u30CE\u30FC\u30C9\u306F\u8FFD\u52A0\u3057\u305F\u9806\u306B\u4F5C\u3089\
    \u308C\u308B\u306E\u3067\u3001\u554F\u984C\u306E\u756A\u53F7\u306E\u4ED8\u3051\
    \u65B9\u3068\u4E00\u81F4\u3059\u308B\n    std::cout << ac.size() << '\\n';\n \
    \   for (long long v = 1; v < ac.size(); v++) std::cout << ac.parent(v) << ' '\
    \ << ac.link(v) << '\\n';\n    for (int i = 0; i < n; i++) std::cout << ac.node(id[i])\
    \ << \" \\n\"[i + 1 == n];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aho_corasick\"\n\n#include\
    \ \"../../../src/string/aho-corasick.hpp\"\n\n#include <iostream>\n#include <string>\n\
    #include <vector>\n\nint main() {\n    std::ios::sync_with_stdio(false);\n   \
    \ std::cin.tie(nullptr);\n    int n;\n    std::cin >> n;\n    AhoCorasick<26,\
    \ 'a'> ac;\n    std::vector<long long> id(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        std::string s;\n        std::cin >> s;\n        id[i] = ac.add(s);\n\
    \    }\n    ac.build();\n    // \u30CE\u30FC\u30C9\u306F\u8FFD\u52A0\u3057\u305F\
    \u9806\u306B\u4F5C\u3089\u308C\u308B\u306E\u3067\u3001\u554F\u984C\u306E\u756A\
    \u53F7\u306E\u4ED8\u3051\u65B9\u3068\u4E00\u81F4\u3059\u308B\n    std::cout <<\
    \ ac.size() << '\\n';\n    for (long long v = 1; v < ac.size(); v++) std::cout\
    \ << ac.parent(v) << ' ' << ac.link(v) << '\\n';\n    for (int i = 0; i < n; i++)\
    \ std::cout << ac.node(id[i]) << \" \\n\"[i + 1 == n];\n}\n"
  dependsOn:
  - src/string/aho-corasick.hpp
  isVerificationFile: true
  path: test/yosupo/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/string/aho-corasick.test.cpp
- /verify/test/yosupo/string/aho-corasick.test.cpp.html
title: test/yosupo/string/aho-corasick.test.cpp
---
