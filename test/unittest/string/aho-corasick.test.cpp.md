---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/aho-corasick.hpp
    title: Aho-Corasick
  - icon: ':heavy_check_mark:'
    path: src/utility/range.hpp
    title: "Python \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\
      \u305D\u306E\u76F4\u7A4D\u306E Grid"
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
  bundledCode: "#line 1 \"test/unittest/string/aho-corasick.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ AhoCorasick \u3092\u3001\u6587\u5B57\u5217\u3092\u611A\u76F4\u306B\u6BD4\u3079\
    \u308B\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\u308B\
    \n// \u540C\u3058\u30D1\u30BF\u30FC\u30F3\u3092\u8907\u6570\u56DE\u8FFD\u52A0\u3059\
    \u308B\u5834\u5408\u3084\u3001\u6587\u5B57\u306E\u7A2E\u985E\u304C\u5C11\u306A\
    \u304F\u3066\u91CD\u306A\u308A\u304C\u591A\u3044\u5834\u5408\u3082\u8A66\u3059\
    \n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/string/aho-corasick.hpp\"\n\n/**\n * @file aho-corasick.hpp\n *\
    \ @brief Aho-Corasick\n */\n\n#include <array>\n#include <cassert>\n#include <cstddef>\n\
    #include <iterator>\n#include <optional>\n#include <type_traits>\n#include <utility>\n\
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
    \    }\n};\n#line 8 \"test/unittest/string/aho-corasick.test.cpp\"\n\n#include\
    \ <algorithm>\n#include <forward_list>\n#include <iostream>\n#include <random>\n\
    #include <string>\n#include <tuple>\n#line 17 \"test/unittest/string/aho-corasick.test.cpp\"\
    \n\n#line 2 \"src/utility/range.hpp\"\n\n/**\n * @file range.hpp\n * @brief Python\
    \ \u306E range \u306E\u3088\u3046\u306A\u6574\u6570\u5217\u3068\u3001\u305D\u306E\
    \u76F4\u7A4D\u306E Grid\n */\n\n#line 15 \"src/utility/range.hpp\"\n\nstruct Range\
    \ {\n   public:\n    using value_type = long long;\n    using const_reference\
    \ = const value_type&;\n    using size_type = long long;\n    using difference_type\
    \ = std::ptrdiff_t;\n\n    const value_type start;\n    const value_type stop;\n\
    \    const value_type step;\n\n   private:\n    const value_type norm_stop;\n\n\
    \    constexpr static value_type normalize(value_type _start, value_type _stop,\
    \ value_type _step) {\n        assert(_step != 0);\n        if (_step > 0) {\n\
    \            if (_start >= _stop) {\n                return _start;\n        \
    \    } else {\n                return _start + (_stop - _start + _step - 1) /\
    \ _step * _step;\n            }\n        } else {\n            if (_start <= _stop)\
    \ {\n                return _start;\n            } else {\n                return\
    \ _start - (_start - _stop - _step - 1) / _step * _step;\n            }\n    \
    \    }\n    }\n\n    constexpr Range(value_type _start, value_type _stop, value_type\
    \ _step, value_type _norm_stop)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(_norm_stop) {\n    }\n\n   public:\n    /**\n     * @brief start \u304B\
    \u3089 stop \u306E\u624B\u524D\u307E\u3067 step \u305A\u3064\u9032\u3080\u6574\
    \u6570\u5217\n     * @pre step != 0\n     */\n    constexpr Range(value_type _start,\
    \ value_type _stop, value_type _step)\n        : start(_start), stop(_stop), step(_step),\
    \ norm_stop(normalize(_start, _stop, _step)) {\n    }\n    constexpr Range(value_type\
    \ _start, value_type _stop)\n        : start(_start), stop(_stop), step(1), norm_stop(normalize(_start,\
    \ _stop, 1)) {}\n    explicit constexpr Range(value_type _stop)\n        : start(0),\
    \ stop(_stop), step(1), norm_stop(normalize(0, _stop, 1)) {}\n    constexpr Range()\n\
    \        : start(0), stop(0), step(1), norm_stop(0) {\n    }\n    constexpr Range(const\
    \ Range& o) = default;\n    Range& operator=(const Range& o) = delete;\n\n   \
    \ struct const_iterator {\n       public:\n        using difference_type = Range::difference_type;\n\
    \        using value_type = Range::value_type;\n        using pointer = const\
    \ Range::value_type*;\n        using reference = const Range::value_type&;\n \
    \       using iterator_category = std::random_access_iterator_tag;\n\n       private:\n\
    \        const Range& range;\n        value_type value;\n\n        constexpr bool\
    \ same_range(const const_iterator& o) const noexcept {\n            return range.start\
    \ == o.range.start && range.stop == o.range.stop && range.step == o.range.step;\n\
    \        }\n\n       public:\n        constexpr const_iterator(const Range& _range,\
    \ value_type _value) noexcept\n            : range(_range), value(_value) {}\n\
    \        constexpr const_iterator(const const_iterator& o) noexcept\n        \
    \    : range(o.range), value(o.value) {}\n        constexpr reference base() const\
    \ noexcept {\n            return value;\n        }\n        constexpr const_iterator&\
    \ operator=(const const_iterator& o) {\n            assert(same_range(o));\n \
    \           value = o.value;\n            return *this;\n        };\n        constexpr\
    \ const_iterator& operator++() noexcept {\n            value += range.step;\n\
    \            return *this;\n        }\n        constexpr const_iterator operator++(int)\
    \ noexcept {\n            const_iterator ret(*this);\n            value += range.step;\n\
    \            return ret;\n        }\n        constexpr const_iterator& operator+=(difference_type\
    \ _n) noexcept {\n            value += _n * range.step;\n            return *this;\n\
    \        }\n        constexpr friend const_iterator operator+(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret += _n;\n            return ret;\n        }\n        constexpr friend\
    \ const_iterator operator+(difference_type _n, const const_iterator& i) noexcept\
    \ {\n            const_iterator ret(i);\n            ret += _n;\n            return\
    \ ret;\n        }\n        constexpr const_iterator& operator--() noexcept {\n\
    \            value -= range.step;\n            return *this;\n        }\n    \
    \    constexpr const_iterator operator--(int) noexcept {\n            const_iterator\
    \ ret(*this);\n            value -= range.step;\n            return ret;\n   \
    \     }\n        constexpr const_iterator& operator-=(difference_type _n) noexcept\
    \ {\n            value -= _n * range.step;\n            return *this;\n      \
    \  }\n        constexpr friend const_iterator operator-(const const_iterator&\
    \ i, difference_type _n) noexcept {\n            const_iterator ret(i);\n    \
    \        ret -= _n;\n            return ret;\n        }\n        constexpr reference\
    \ operator*() const noexcept {\n            return value;\n        }\n       \
    \ constexpr friend bool operator!=(const const_iterator& a, const const_iterator&\
    \ b) noexcept {\n            return !a.same_range(b) || a.value != b.value;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return !(a != b);\n       \
    \ }\n        constexpr friend difference_type operator-(const const_iterator&\
    \ a, const const_iterator& b) {\n            assert(a.same_range(b));\n      \
    \      if (a.range.step > 0) {\n                return (a.value - b.value) / a.range.step;\n\
    \            } else {\n                return (b.value - a.value) / (-a.range.step);\n\
    \            }\n        }\n    };\n\n    constexpr const_iterator begin() const\
    \ noexcept {\n        return {*this, start};\n    }\n    constexpr const_iterator\
    \ end() const noexcept {\n        return {*this, norm_stop};\n    }\n    /**\n\
    \     * @brief x \u306E\u500B\u6570 (0 \u304B 1)\n     */\n    constexpr size_type\
    \ count(value_type x) const noexcept {\n        // step \u304C\u30B3\u30F3\u30D1\
    \u30A4\u30EB\u6642\u306B\u5206\u304B\u3089\u306A\u3044\u3068\u304D\u3082\u3001\
    \u3088\u304F\u4F7F\u3046 step = 1 \u3067\u306F\u5272\u308A\u7B97\u3092\u3057\u306A\
    \u3044\n        if (step == 1) return start <= x && x < stop;\n        if (step\
    \ > 0) {\n            if (start <= x && x < stop) {\n                if ((x -\
    \ start) % step == 0) {\n                    return 1;\n                }\n  \
    \          }\n        } else {\n            if (stop < x && x <= start) {\n  \
    \              if ((start - x) % (-step) == 0) {\n                    return 1;\n\
    \                }\n            }\n        }\n        return 0;\n    }\n    /**\n\
    \     * @brief x \u304C\u542B\u307E\u308C\u308B\u304B\n     */\n    constexpr\
    \ bool contains(value_type x) const noexcept {\n        return count(x) != 0;\n\
    \    }\n    /**\n     * @brief x \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n\
    \     * x \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n\
    \    constexpr size_type index(value_type x) const {\n        assert(contains(x));\n\
    \        if (step == 1) return x - start;\n        return (x - start) / step;\n\
    \    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u306E\u30A4\u30C6\u30EC\u30FC\
    \u30BF\n     * x \u304C\u542B\u307E\u308C\u306A\u3044\u3068 end() \u3092\u8FD4\
    \u3059\n     */\n    constexpr const_iterator find(value_type x) const noexcept\
    \ {\n        if (contains(x)) {\n            return {*this, x};\n        } else\
    \ {\n            return {*this, norm_stop};\n        }\n    }\n    /**\n     *\
    \ @brief \u8981\u7D20\u304C x \u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u30A4\u30C6\
    \u30EC\u30FC\u30BF\n     * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\
    \u30FC\n     */\n    constexpr const_iterator lower_bound(value_type x) const\
    \ {\n        assert(step > 0);\n        if (norm_stop <= x) {\n            return\
    \ end();\n        } else if (x < start) {\n            return begin();\n     \
    \   } else {\n            return {*this, start + (x - start + step - 1) / step\
    \ * step};\n        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C x \u3088\
    \u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u30A4\u30C6\u30EC\u30FC\u30BF\n   \
    \  * step > 0 \u3058\u3083\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ const_iterator upper_bound(value_type x) const {\n        assert(step > 0);\n\
    \        if (norm_stop <= x) {\n            return end();\n        } else if (x\
    \ < start) {\n            return begin();\n        } else {\n            return\
    \ {*this, start + (x - start + step) / step * step};\n        }\n    }\n    /**\n\
    \     * @brief \u30B3\u30F3\u30C6\u30CA\u306E\u8981\u7D20\u6570\n     */\n   \
    \ constexpr size_type size() const noexcept {\n        if (step > 0) {\n     \
    \       return (norm_stop - start) / step;\n        } else {\n            return\
    \ (start - norm_stop) / (-step);\n        }\n    }\n    constexpr value_type at(size_type\
    \ i) const {\n        assert(0 <= i && i < size());\n        return start + i\
    \ * step;\n    }\n    constexpr value_type operator[](size_type i) const {\n \
    \       return at(i);\n    }\n    constexpr bool empty() const noexcept {\n  \
    \      return start == norm_stop;\n    }\n    constexpr value_type sum() const\
    \ noexcept {\n        return size() * (norm_stop - step + start) / 2;\n    }\n\
    \    /**\n     * @brief \u6700\u5C0F\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\
    \u30FC\n     */\n    constexpr value_type min() const {\n        assert(!empty());\n\
    \        if (step > 0) {\n            return start;\n        } else {\n      \
    \      return norm_stop - step;\n        }\n    }\n    /**\n     * @brief \u6700\
    \u5927\u5024\n     * \u7A7A\u3060\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr\
    \ value_type max() const {\n        assert(!empty());\n        if (step > 0) {\n\
    \            return norm_stop - step;\n        } else {\n            return start;\n\
    \        }\n    }\n    /**\n     * @brief \u7DCF xor\n     * \u8CA0\u3092\u542B\
    \u3080\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr value_type product_xor()\
    \ const noexcept {\n        if (empty()) return 0;\n        assert(min() >= 0);\n\
    \        Range sorted_range(sorted());\n        value_type res = 0;\n        std::make_unsigned_t<value_type>\
    \ t = 1;\n        while (t <= static_cast<std::make_unsigned_t<value_type>>(max()))\
    \ {\n            std::make_unsigned_t<value_type> tmp = 0, n = size(), m = t,\
    \ a = sorted_range.step, b = sorted_range.start;\n            while (true) {\n\
    \                if (a >= m) {\n                    tmp += n * (n - 1) / 2 * (a\
    \ / m);\n                    a %= m;\n                }\n                if (b\
    \ >= m) {\n                    tmp += n * (b / m);\n                    b %= m;\n\
    \                }\n                std::make_unsigned_t<value_type> y_max = a\
    \ * n + b;\n                if (y_max < m) break;\n                n = y_max /\
    \ m;\n                b = y_max % m;\n                std::swap(m, a);\n     \
    \       }\n            if (tmp % 2 == 1) {\n                res += t;\n      \
    \      }\n            t <<= 1;\n        }\n        return res;\n    }\n    /**\n\
    \     * @brief \u9006\u9806\u306B\u3057\u305F\u3082\u306E\n     */\n    constexpr\
    \ Range reversed() const noexcept {\n        return {norm_stop - step, start -\
    \ step, -step, start - step};\n    }\n    /**\n     * @brief step > 0 \u3060\u3068\
    \u305D\u306E\u307E\u307E step < 0 \u3060\u3068\u9006\u9806\u306B\u3057\u305F\u3082\
    \u306E\n     */\n    constexpr Range sorted() const noexcept {\n        if (step\
    \ > 0) {\n            return {start, norm_stop, step, norm_stop};\n        } else\
    \ {\n            return {norm_stop - step, start - step, -step, start - step};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u304C [l, r) \u3067\u3042\
    \u308B\u7BC4\u56F2\u3092\u8FD4\u3059\n     */\n    constexpr Range clipped(value_type\
    \ l, value_type r) const {\n        if (l >= r) return {};\n        r--;  // \u4EE5\
    \u4E0B\u3067\u306F r \u3092\u542B\u3080 [l, r] \u3068\u3057\u3066\u6271\u3046\n\
    \        if (step > 0) {\n            value_type _start = [&] {\n            \
    \    if (norm_stop <= l) {\n                    return norm_stop;\n          \
    \      } else if (l < start) {\n                    return start;\n          \
    \      } else {\n                    return start + (l - start + step - 1) / step\
    \ * step;\n                }\n            }();\n            value_type _stop =\
    \ [&] {\n                if (norm_stop <= r) {\n                    return norm_stop;\n\
    \                } else if (r < start) {\n                    return start;\n\
    \                } else {\n                    return start + (r - start + step)\
    \ / step * step;\n                }\n            }();\n            return {_start,\
    \ _stop, step, _stop};\n        } else {\n            value_type _start = [&]\
    \ {\n                if (start - step <= r) {\n                    return start;\n\
    \                } else if (r < norm_stop - step) {\n                    return\
    \ norm_stop;\n                } else {\n                    return norm_stop +\
    \ (r - norm_stop) / step * step;\n                }\n            }();\n      \
    \      value_type _stop = [&] {\n                if (start - step <= l) {\n  \
    \                  return start;\n                } else if (l < norm_stop - step)\
    \ {\n                    return norm_stop;\n                } else {\n       \
    \             return norm_stop + (l - norm_stop - 1) / step * step;\n        \
    \        }\n            }();\n            return {_start, _stop, step, _stop};\n\
    \        }\n    }\n    /**\n     * @brief \u8981\u7D20\u3092 Range \u3067\u6307\
    \u5B9A\u3057\u305F\u30B3\u30F3\u30C6\u30CA\n     */\n    constexpr Range slice(const\
    \ Range& r) const {\n        if (r.empty()) return {};\n        if (r.max() <\
    \ 0) return {};\n        if (r.min() >= size()) return {};\n        Range trimmed_range(r.clipped(0,\
    \ size()));\n        if (trimmed_range.empty()) return {};\n        value_type\
    \ _step = step * trimmed_range.step;\n        value_type _start = at(trimmed_range.start);\n\
    \        value_type _stop = _start + _step * trimmed_range.size();\n        return\
    \ {_start, _stop, _step, _stop};\n    }\n\n    static std::string type_str() {\n\
    \        return \"Range\";\n    }\n    std::string initializer_str() const {\n\
    \        return \"{\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \"}\";\n    }\n    std::string repr() const\
    \ {\n        return \"Range(\" + std::to_string(start) + \", \" + std::to_string(stop)\
    \ + \", \" + std::to_string(step) + \")\";\n    }\n\n    std::vector<value_type>\
    \ to_vector() const {\n        std::vector<value_type> ret;\n        ret.reserve(size());\n\
    \        if (step > 0) {\n            for (value_type x = start; x < stop; x +=\
    \ step) {\n                ret.push_back(x);\n            }\n        } else {\n\
    \            for (value_type x = start; x > stop; x += step) {\n             \
    \   ret.push_back(x);\n            }\n        }\n        return ret;\n    }\n\
    \    constexpr friend bool operator==(const Range& a, const Range& b) noexcept\
    \ {\n        if (a.empty() && b.empty()) return true;\n        if (a.size() !=\
    \ b.size()) return false;\n        if (a.start != b.start) return false;\n   \
    \     if (a.size() == 1) return true;\n        if (a.step != b.step) return false;\n\
    \        return true;\n    }\n    constexpr friend bool operator!=(const Range&\
    \ a, const Range& b) noexcept {\n        return !(a == b);\n    }\n};\n\n/**\n\
    \ * @brief 2 \u3064\u306E Range \u306E\u76F4\u7A4D rows \xD7 cols\n * (i, j) \u3092\
    \ i \u306E\u6607\u9806\u3001\u540C\u3058 i \u3067\u306F j \u306E\u6607\u9806 (\u884C\
    \u512A\u5148) \u306B\u4E26\u3079\u305F\u3082\u306E\u3068\u3057\u3066\u6271\u3046\
    \n */\nstruct Grid {\n   public:\n    using value_type = std::pair<long long,\
    \ long long>;\n    using size_type = long long;\n    using difference_type = std::ptrdiff_t;\n\
    \n    const Range rows;\n    const Range cols;\n\n   private:\n    const long\
    \ long width;  // cols.size() (index \u3084 at \u3067\u6BCE\u56DE\u5272\u308A\u7B97\
    \u3057\u306A\u3044\u3088\u3046\u306B\u6301\u3063\u3066\u304A\u304F)\n\n   public:\n\
    \    /**\n     * @brief [0, h) \xD7 [0, w)\n     */\n    constexpr Grid(long long\
    \ h, long long w) : rows(h), cols(w), width(cols.size()) {}\n    constexpr Grid(const\
    \ Range& _rows, const Range& _cols) : rows(_rows), cols(_cols), width(cols.size())\
    \ {}\n    constexpr Grid(const Grid& o) = default;\n    Grid& operator=(const\
    \ Grid& o) = delete;\n\n    struct const_iterator {\n       public:\n        using\
    \ difference_type = Grid::difference_type;\n        using value_type = Grid::value_type;\n\
    \        using pointer = void;\n        using reference = value_type;\n      \
    \  using iterator_category = std::forward_iterator_tag;\n\n       private:\n \
    \       const Grid* rect = nullptr;\n        long long w = 0;   // cols.size()\n\
    \        long long ic = 0;  // rows \u306E\u4F55\u756A\u76EE\u304B\n        long\
    \ long jc = 0;  // cols \u306E\u4F55\u756A\u76EE\u304B\n\n       public:\n   \
    \     constexpr const_iterator() noexcept = default;\n        constexpr const_iterator(const\
    \ Grid* _rect, long long _w, long long _ic, long long _jc) noexcept\n        \
    \    : rect(_rect), w(_w), ic(_ic), jc(_jc) {}\n        constexpr value_type operator*()\
    \ const noexcept {\n            return {rect->rows.start + ic * rect->rows.step,\
    \ rect->cols.start + jc * rect->cols.step};\n        }\n        constexpr const_iterator&\
    \ operator++() noexcept {\n            if (++jc == w) {\n                jc =\
    \ 0;\n                ++ic;\n            }\n            return *this;\n      \
    \  }\n        constexpr const_iterator operator++(int) noexcept {\n          \
    \  const_iterator ret(*this);\n            ++*this;\n            return ret;\n\
    \        }\n        constexpr friend bool operator==(const const_iterator& a,\
    \ const const_iterator& b) noexcept {\n            return a.ic == b.ic && a.jc\
    \ == b.jc;\n        }\n        constexpr friend bool operator!=(const const_iterator&\
    \ a, const const_iterator& b) noexcept {\n            return !(a == b);\n    \
    \    }\n    };\n\n    constexpr const_iterator begin() const noexcept {\n    \
    \    return {this, width, width == 0 ? rows.size() : 0, 0};\n    }\n    constexpr\
    \ const_iterator end() const noexcept {\n        return {this, width, rows.size(),\
    \ 0};\n    }\n    /**\n     * @brief \u8981\u7D20\u6570 rows.size() * cols.size()\n\
    \     */\n    constexpr size_type size() const noexcept {\n        return rows.size()\
    \ * width;\n    }\n    constexpr bool empty() const noexcept {\n        return\
    \ rows.empty() || cols.empty();\n    }\n    /**\n     * @brief (i, j) \u304C\u542B\
    \u307E\u308C\u308B\u304B\n     */\n    constexpr bool contains(long long i, long\
    \ long j) const noexcept {\n        return rows.contains(i) && cols.contains(j);\n\
    \    }\n    constexpr bool contains(const value_type& p) const noexcept {\n  \
    \      return contains(p.first, p.second);\n    }\n    /**\n     * @brief (i,\
    \ j) \u306E\u884C\u512A\u5148\u3067\u306E\u4F4D\u7F6E (\u30B0\u30EA\u30C3\u30C9\
    \u306E\u9802\u70B9\u756A\u53F7\u306B\u4F7F\u3046)\n     * (i, j) \u304C\u542B\u307E\
    \u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n    constexpr size_type index(long\
    \ long i, long long j) const {\n        assert(contains(i, j));\n        return\
    \ rows.index(i) * width + cols.index(j);\n    }\n    constexpr size_type index(const\
    \ value_type& p) const {\n        return index(p.first, p.second);\n    }\n  \
    \  /**\n     * @brief \u884C\u512A\u5148\u3067 k \u756A\u76EE\u306E\u8981\u7D20\
    \ (index \u306E\u9006)\n     */\n    constexpr value_type at(size_type k) const\
    \ {\n        assert(0 <= k && k < size());\n        return {rows[k / width], cols[k\
    \ % width]};\n    }\n    constexpr value_type operator[](size_type k) const {\n\
    \        return at(k);\n    }\n\n   private:\n    // \u8FD1\u508D\u306E\u65B9\u5411\
    \ (rows\u30FBcols \u306E\u4E2D\u3067\u306E\u4F4D\u7F6E\u306E\u5DEE) \u3092 Grid\
    \ \u306E\u9806\u306B\u4E26\u3079\u305F\u3082\u306E\u3002\u5148\u982D 4 \u3064\u306F\
    \u4E0A\u4E0B\u5DE6\u53F3\u3060\u3051\u3092\u4E26\u3079\u305F\u5225\u306E\u8868\
    \n    // 4 \u8FD1\u508D\u3068 8 \u8FD1\u508D\u306E\u5883\u76EE\u304C\u5206\u304B\
    \u308B\u3088\u3046\u306B 2 \u884C\u306B\u5206\u3051\u3066\u3044\u308B\u306E\u3067\
    \u6574\u5F62\u3057\u306A\u3044\n    // clang-format off\n    static constexpr\
    \ int neighbor_dirs[12][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0},\n            \
    \                                     {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0,\
    \ 1}, {1, -1}, {1, 0}, {1, 1}};\n    // clang-format on\n\n   public:\n    /**\n\
    \     * @brief neighbors4 / neighbors8 \u306E\u623B\u308A\u5024 (\u7BC4\u56F2\
    \ for \u3067\u4F7F\u3046)\n     * \u4F5C\u308B\u3068\u304D\u306B Grid \u306B\u542B\
    \u307E\u308C\u308B\u65B9\u5411\u3092\u30D3\u30C3\u30C8\u3067\u6301\u3063\u3066\
    \u304A\u304D\u3001\u7ACB\u3063\u3066\u3044\u308B\u30D3\u30C3\u30C8\u3092\u9806\
    \u306B\u8FD4\u3059\n     */\n    struct Neighbors {\n        long long i, j, row_step,\
    \ col_step;\n        int first;      // neighbor_dirs[first + k] \u304C\u30D3\u30C3\
    \u30C8 k \u306E\u65B9\u5411\n        unsigned mask;  // Grid \u306B\u542B\u307E\
    \u308C\u308B\u65B9\u5411\n\n        struct iterator {\n            using difference_type\
    \ = std::ptrdiff_t;\n            using value_type = Grid::value_type;\n      \
    \      using pointer = void;\n            using reference = value_type;\n    \
    \        using iterator_category = std::forward_iterator_tag;\n\n            const\
    \ Neighbors* nb = nullptr;\n            unsigned rest = 0;  // \u307E\u3060\u8FD4\
    \u3057\u3066\u3044\u306A\u3044\u65B9\u5411\n\n            constexpr value_type\
    \ operator*() const noexcept {\n                const int k = nb->first + __builtin_ctz(rest);\n\
    \                return {nb->i + neighbor_dirs[k][0] * nb->row_step, nb->j + neighbor_dirs[k][1]\
    \ * nb->col_step};\n            }\n            constexpr iterator& operator++()\
    \ noexcept {\n                rest &= rest - 1;\n                return *this;\n\
    \            }\n            constexpr iterator operator++(int) noexcept {\n  \
    \              iterator ret(*this);\n                ++*this;\n              \
    \  return ret;\n            }\n            constexpr friend bool operator==(const\
    \ iterator& a, const iterator& b) noexcept { return a.rest == b.rest; }\n    \
    \        constexpr friend bool operator!=(const iterator& a, const iterator& b)\
    \ noexcept { return a.rest != b.rest; }\n        };\n        constexpr iterator\
    \ begin() const noexcept { return {this, mask}; }\n        constexpr iterator\
    \ end() const noexcept { return {this, 0}; }\n        constexpr long long size()\
    \ const noexcept { return __builtin_popcount(mask); }\n        constexpr bool\
    \ empty() const noexcept { return mask == 0; }\n    };\n\n   private:\n    constexpr\
    \ Neighbors neighbors(long long i, long long j, int first, int last) const {\n\
    \        assert(contains(i, j));\n        unsigned mask = 0;\n        for (int\
    \ k = first; k < last; k++) {\n            if (contains(i + neighbor_dirs[k][0]\
    \ * rows.step, j + neighbor_dirs[k][1] * cols.step)) mask |= 1u << (k - first);\n\
    \        }\n        return {i, j, rows.step, cols.step, first, mask};\n    }\n\
    \n   public:\n    /**\n     * @brief (i, j) \u306E\u4E0A\u4E0B\u5DE6\u53F3\u306E\
    \u3046\u3061 Grid \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\
    \u9806\u306B\u8FD4\u3059\n     * \u96A3\u306F rows\u30FBcols \u306E\u4E2D\u3067\
    \u96A3\u308A\u5408\u3046\u8981\u7D20 (i \xB1 rows.step \u306A\u3069)\u3002(i,\
    \ j) \u304C\u542B\u307E\u308C\u306A\u3044\u3068\u30A8\u30E9\u30FC\n     */\n \
    \   constexpr Neighbors neighbors4(long long i, long long j) const {\n       \
    \ return neighbors(i, j, 0, 4);\n    }\n    constexpr Neighbors neighbors4(const\
    \ value_type& p) const {\n        return neighbors4(p.first, p.second);\n    }\n\
    \    /**\n     * @brief (i, j) \u3092\u56F2\u3080 8 \u3064\u306E\u3046\u3061 Grid\
    \ \u306B\u542B\u307E\u308C\u308B\u3082\u306E\u3092\u3001Grid \u306E\u9806\u306B\
    \u8FD4\u3059\n     */\n    constexpr Neighbors neighbors8(long long i, long long\
    \ j) const {\n        return neighbors(i, j, 4, 12);\n    }\n    constexpr Neighbors\
    \ neighbors8(const value_type& p) const {\n        return neighbors8(p.first,\
    \ p.second);\n    }\n\n    static std::string type_str() {\n        return \"\
    Grid\";\n    }\n    std::string initializer_str() const {\n        return \"{\"\
    \ + rows.initializer_str() + \", \" + cols.initializer_str() + \"}\";\n    }\n\
    \    std::string repr() const {\n        return \"Grid(\" + rows.repr() + \",\
    \ \" + cols.repr() + \")\";\n    }\n\n    constexpr friend bool operator==(const\
    \ Grid& a, const Grid& b) noexcept {\n        if (a.empty() && b.empty()) return\
    \ true;\n        return a.rows == b.rows && a.cols == b.cols;\n    }\n    constexpr\
    \ friend bool operator!=(const Grid& a, const Grid& b) noexcept {\n        return\
    \ !(a == b);\n    }\n};\n#line 19 \"test/unittest/string/aho-corasick.test.cpp\"\
    \n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nbool ok = true;\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\nint\
    \ main() {\n    std::mt19937 rng(314);\n    for (int rep = 0; rep < 3000 && ok;\
    \ rep++) {\n        int sigma = rng() % 3 + 1;\n        auto random_string = [&](int\
    \ max_len) {\n            std::string s(rng() % max_len + 1, 'a');\n         \
    \   for (char& c : s) c = 'a' + rng() % sigma;\n            return s;\n      \
    \  };\n        int m = rng() % 6 + 1;\n        std::vector<std::string> pats;\n\
    \        AhoCorasick<3, 'a'> ac;\n        for (int i = 0; i < m; i++) {\n    \
    \        std::string p = !pats.empty() && rng() % 4 == 0 ? pats[rng() % pats.size()]\
    \ : random_string(4);\n            pats.push_back(p);\n            check(ac.add(p)\
    \ == i, \"add \u306E\u756A\u53F7\");\n        }\n        ac.build();\n       \
    \ check(ac.pattern_count() == m, \"pattern_count\");\n\n        // \u30CE\u30FC\
    \u30C9\u306E\u69CB\u9020: \u5404\u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\u3092\
    \u89AA\u304B\u3089\u305F\u3069\u3063\u3066\u4F5C\u308A\u3001\u5931\u6557\u30EA\
    \u30F3\u30AF\u30FB\u9077\u79FB\u30FBmatch_count \u3092\u78BA\u304B\u3081\u308B\
    \n        std::vector<std::string> str(ac.size());\n        for (long long v =\
    \ 1; v < ac.size(); v++) {\n            long long p = ac.parent(v);\n        \
    \    check(0 <= p && p < v, \"\u89AA\u306F\u5148\u306B\u4F5C\u3089\u308C\u3066\
    \u3044\u308B\");\n            for (int c = 0; c < 3; c++) {\n                if\
    \ (ac.next(p, 'a' + c) == v) str[v] = str[p] + static_cast<char>('a' + c);\n \
    \           }\n            check(ac.depth(v) == static_cast<long long>(str[v].size()),\
    \ \"depth\");\n        }\n        check(ac.parent(0) == -1 && ac.link(0) == -1\
    \ && ac.depth(0) == 0, \"\u6839\");\n        auto find_node = [&](const std::string&\
    \ s) -> long long {\n            for (long long v = 0; v < ac.size(); v++) {\n\
    \                if (str[v] == s) return v;\n            }\n            return\
    \ -1;\n        };\n        for (int i = 0; i < m; i++) check(str[ac.node(i)] ==\
    \ pats[i], \"node\");\n        for (long long v = 0; v < ac.size(); v++) {\n \
    \           const std::string& s = str[v];\n            // \u5931\u6557\u30EA\u30F3\
    \u30AF: \u30CE\u30FC\u30C9\u306E\u3042\u308B\u6700\u9577\u306E\u771F\u306E\u63A5\
    \u5C3E\u8F9E\n            if (v > 0) {\n                long long expect = 0;\n\
    \                for (size_t len = s.size() - 1; len > 0; len--) {\n         \
    \           long long u = find_node(s.substr(s.size() - len));\n             \
    \       if (u != -1) {\n                        expect = u;\n                \
    \        break;\n                    }\n                }\n                check(ac.link(v)\
    \ == expect, \"link\");\n            }\n            // \u9077\u79FB: s + c \u306E\
    \u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001\u30CE\u30FC\u30C9\u306E\u3042\u308B\
    \u6700\u9577\u306E\u3082\u306E\n            for (int c = 0; c < 3; c++) {\n  \
    \              std::string t = s + static_cast<char>('a' + c);\n             \
    \   long long expect = 0;\n                for (size_t len = t.size(); len > 0;\
    \ len--) {\n                    long long u = find_node(t.substr(t.size() - len));\n\
    \                    if (u != -1) {\n                        expect = u;\n   \
    \                     break;\n                    }\n                }\n     \
    \           check(ac.next(v, 'a' + c) == expect, \"next\");\n            }\n \
    \           long long mc = 0;\n            for (const auto& p : pats) mc += p.size()\
    \ <= s.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;\n         \
    \   check(ac.match_count(v) == mc, \"match_count\");\n        }\n\n        //\
    \ \u7167\u5408: \u611A\u76F4\u306B\u5168\u4F4D\u7F6E\u3067\u6BD4\u3079\u308B\n\
    \        for (int t = 0; t < 5; t++) {\n            std::string text = rng() %\
    \ 5 == 0 ? std::string() : random_string(30);\n            std::vector<long long>\
    \ each(m, 0);\n            std::vector<decltype(ac)::Match> all;             \
    \               // (\u958B\u59CB\u4F4D\u7F6E, \u756A\u53F7)\n            std::vector<std::tuple<long\
    \ long, long long, long long>> order;  // (\u7D42\u308F\u308B\u4F4D\u7F6E, -\u9577\
    \u3055, \u756A\u53F7) \u306E\u9806\u306B\u4E26\u3079\u308B\n            for (long\
    \ long end = 1; end <= static_cast<long long>(text.size()); end++) {\n       \
    \         for (int i = 0; i < m; i++) {\n                    long long len = pats[i].size();\n\
    \                    if (len <= end && text.compare(end - len, len, pats[i]) ==\
    \ 0) {\n                        each[i]++;\n                        order.emplace_back(end,\
    \ -len, i);\n                    }\n                }\n            }\n       \
    \     std::sort(order.begin(), order.end());\n            for (auto [end, neg_len,\
    \ i] : order) all.push_back({end + neg_len, i});\n            long long total\
    \ = 0;\n            for (long long x : each) total += x;\n            check(ac.count(text)\
    \ == total, \"count\");\n            check(ac.count_each(text) == each, \"count_each\"\
    );\n            const auto matches = ac.find_all(text);\n            check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) == all, \"find_all\");\n        }\n    }\n    // std::vector<int>\
    \ \u306E\u6587\u5B57\u5217\u3068\u3001\u5225\u306E\u6587\u5B57\u306E\u7BC4\u56F2\
    \n    {\n        AhoCorasick<10, 0> ac;\n        ac.add(std::vector<int>{1, 2});\n\
    \        ac.add(std::vector<int>{2});\n        ac.build();\n        std::vector<int>\
    \ text = {1, 2, 2, 1, 2};\n        check(ac.count(text) == 5 && ac.count_each(text)\
    \ == std::vector<long long>{2, 3}, \"std::vector<int>\");\n        const auto\
    \ matches = ac.find_all(text);\n        check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) ==\n                  std::vector<decltype(ac)::Match>{{0, 0},\
    \ {1, 1}, {2, 1}, {3, 0}, {4, 1}},\n              \"std::vector<int> \u306E\u5217\
    \u6319\");\n    }\n    // \u4E00\u81F4\u306E\u9806\u5E8F\u3001\u72EC\u7ACB\u3057\
    \u305F\u8D70\u67FB\u3001\u53F3\u8FBA\u5024\u306E\u6240\u6709\u3001\u30B3\u30D4\
    \u30FC\u30FB\u79FB\u52D5\u5F8C\u306E\u5BFF\u547D\u3002\n    {\n        AhoCorasick<>\
    \ ac;\n        ac.add(std::string(\"a\"));\n        ac.add(std::string(\"aa\"\
    ));\n        ac.add(std::string(\"a\"));\n        ac.build();\n        using Match\
    \ = decltype(ac)::Match;\n        const std::vector<Match> expected = {{0, 0},\
    \ {0, 2}, {0, 1}, {1, 0}, {1, 2}};\n        auto make_matches = [&] { return ac.find_all(std::string(\"\
    aa\")); };\n        const auto matches = make_matches();\n        auto copy =\
    \ matches;\n        auto moved = std::move(copy);\n        for (int rep = 0; rep\
    \ < 2; rep++) {\n            check(std::vector<Match>(matches.begin(), matches.end())\
    \ == expected, \"\u53F3\u8FBA\u5024\u3068\u7E70\u308A\u8FD4\u3057\u8D70\u67FB\"\
    );\n            check(std::vector<Match>(moved.begin(), moved.end()) == expected,\
    \ \"range \u306E\u30B3\u30D4\u30FC\u30FB\u79FB\u52D5\");\n        }\n        auto\
    \ it = matches.begin(), independent = it;\n        check(*it++ == expected[0]\
    \ && *it == expected[1] && *independent == expected[0], \"iterator \u306E\u30B3\
    \u30D4\u30FC\u3068\u5F8C\u7F6E increment\");\n        long long pairs = 0;\n \
    \       for (auto x : matches) {\n            for (auto y : matches) pairs +=\
    \ x.id == y.id;\n        }\n        check(pairs == 9, \"\u5165\u308C\u5B50\u306E\
    \u8D70\u67FB\");\n        std::forward_list<char> text = {'a', 'a'};\n       \
    \ const auto linked = ac.find_all(text);\n        check(std::vector<Match>(linked.begin(),\
    \ linked.end()) == expected, \"\u975E\u30E9\u30F3\u30C0\u30E0\u30A2\u30AF\u30BB\
    \u30B9\u5165\u529B\");\n        auto empty = ac.find_all(std::string());\n   \
    \     check(empty.begin() == empty.end(), \"\u7A7A\u306E\u5165\u529B\");\n#if\
    \ __cplusplus >= 202002L\n        static_assert(std::ranges::input_range<decltype(matches)>);\n\
    #endif\n    }\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u69CB\u7BC9\u3067\u304D\u306A\
    \u3044 iterator \u3082\u53D7\u3051\u53D6\u308C\u308B\u3002\n    {\n        AhoCorasick<3,\
    \ 0> ac;\n        ac.add(std::vector<int>{0, 1});\n        ac.build();\n     \
    \   const auto matches = ac.find_all(Range(3));\n        check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) ==\n                  std::vector<decltype(ac)::Match>{{0, 0}},\n\
    \              \"Range \u306E\u5165\u529B\");\n    }\n    // \u5165\u529B\u306E\
    \u30B3\u30D4\u30FC\u3092\u8981\u6C42\u305B\u305A\u3001\u6700\u521D\u306E\u4E00\
    \u81F4\u3088\u308A\u5F8C\u3092\u8AAD\u307E\u306A\u3044\u3002\n    {\n        struct\
    \ Character {\n            long long* reads;\n            operator int() const\
    \ {\n                ++*reads;\n                return 'a';\n            }\n \
    \       };\n        struct Text {\n            std::vector<Character> chars;\n\
    \            explicit Text(long long* reads) : chars(100, Character{reads}) {}\n\
    \            Text(const Text&) = delete;\n            auto begin() const { return\
    \ chars.begin(); }\n            auto end() const { return chars.end(); }\n   \
    \     };\n        AhoCorasick<> ac;\n        ac.add(std::string(\"a\"));\n   \
    \     ac.build();\n        long long reads = 0;\n        Text text(&reads);\n\
    \        const auto matches = ac.find_all(text);\n        check(reads == 0, \"\
    \u69CB\u7BC9\u6642\u306F\u5165\u529B\u3092\u8AAD\u307E\u306A\u3044\");\n     \
    \   for (auto match : matches) {\n            check(match.pos == 0 && match.id\
    \ == 0, \"\u6700\u521D\u306E\u4E00\u81F4\");\n            break;\n        }\n\
    \        check(reads == 1, \"\u9014\u4E2D\u7D42\u4E86\");\n    }\n    {\n    \
    \    AhoCorasick<> ac;\n        ac.build();\n        const auto matches = ac.find_all(std::string(\"\
    aaa\"));\n        check(matches.begin() == matches.end(), \"\u30D1\u30BF\u30FC\
    \u30F3\u306A\u3057\");\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// AhoCorasick \u3092\u3001\u6587\u5B57\u5217\u3092\u611A\u76F4\u306B\u6BD4\
    \u3079\u308B\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\u3059\
    \u308B\n// \u540C\u3058\u30D1\u30BF\u30FC\u30F3\u3092\u8907\u6570\u56DE\u8FFD\u52A0\
    \u3059\u308B\u5834\u5408\u3084\u3001\u6587\u5B57\u306E\u7A2E\u985E\u304C\u5C11\
    \u306A\u304F\u3066\u91CD\u306A\u308A\u304C\u591A\u3044\u5834\u5408\u3082\u8A66\
    \u3059\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../../src/string/aho-corasick.hpp\"\n\n#include <algorithm>\n\
    #include <forward_list>\n#include <iostream>\n#include <random>\n#include <string>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n\n#include \"../../../src/utility/range.hpp\"\
    \n#if __cplusplus >= 202002L\n#include <ranges>\n#endif\n\nbool ok = true;\nvoid\
    \ check(bool cond, const char* what) {\n    if (!cond) {\n        if (ok) std::cerr\
    \ << \"failed: \" << what << std::endl;\n        ok = false;\n    }\n}\n\nint\
    \ main() {\n    std::mt19937 rng(314);\n    for (int rep = 0; rep < 3000 && ok;\
    \ rep++) {\n        int sigma = rng() % 3 + 1;\n        auto random_string = [&](int\
    \ max_len) {\n            std::string s(rng() % max_len + 1, 'a');\n         \
    \   for (char& c : s) c = 'a' + rng() % sigma;\n            return s;\n      \
    \  };\n        int m = rng() % 6 + 1;\n        std::vector<std::string> pats;\n\
    \        AhoCorasick<3, 'a'> ac;\n        for (int i = 0; i < m; i++) {\n    \
    \        std::string p = !pats.empty() && rng() % 4 == 0 ? pats[rng() % pats.size()]\
    \ : random_string(4);\n            pats.push_back(p);\n            check(ac.add(p)\
    \ == i, \"add \u306E\u756A\u53F7\");\n        }\n        ac.build();\n       \
    \ check(ac.pattern_count() == m, \"pattern_count\");\n\n        // \u30CE\u30FC\
    \u30C9\u306E\u69CB\u9020: \u5404\u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\u3092\
    \u89AA\u304B\u3089\u305F\u3069\u3063\u3066\u4F5C\u308A\u3001\u5931\u6557\u30EA\
    \u30F3\u30AF\u30FB\u9077\u79FB\u30FBmatch_count \u3092\u78BA\u304B\u3081\u308B\
    \n        std::vector<std::string> str(ac.size());\n        for (long long v =\
    \ 1; v < ac.size(); v++) {\n            long long p = ac.parent(v);\n        \
    \    check(0 <= p && p < v, \"\u89AA\u306F\u5148\u306B\u4F5C\u3089\u308C\u3066\
    \u3044\u308B\");\n            for (int c = 0; c < 3; c++) {\n                if\
    \ (ac.next(p, 'a' + c) == v) str[v] = str[p] + static_cast<char>('a' + c);\n \
    \           }\n            check(ac.depth(v) == static_cast<long long>(str[v].size()),\
    \ \"depth\");\n        }\n        check(ac.parent(0) == -1 && ac.link(0) == -1\
    \ && ac.depth(0) == 0, \"\u6839\");\n        auto find_node = [&](const std::string&\
    \ s) -> long long {\n            for (long long v = 0; v < ac.size(); v++) {\n\
    \                if (str[v] == s) return v;\n            }\n            return\
    \ -1;\n        };\n        for (int i = 0; i < m; i++) check(str[ac.node(i)] ==\
    \ pats[i], \"node\");\n        for (long long v = 0; v < ac.size(); v++) {\n \
    \           const std::string& s = str[v];\n            // \u5931\u6557\u30EA\u30F3\
    \u30AF: \u30CE\u30FC\u30C9\u306E\u3042\u308B\u6700\u9577\u306E\u771F\u306E\u63A5\
    \u5C3E\u8F9E\n            if (v > 0) {\n                long long expect = 0;\n\
    \                for (size_t len = s.size() - 1; len > 0; len--) {\n         \
    \           long long u = find_node(s.substr(s.size() - len));\n             \
    \       if (u != -1) {\n                        expect = u;\n                \
    \        break;\n                    }\n                }\n                check(ac.link(v)\
    \ == expect, \"link\");\n            }\n            // \u9077\u79FB: s + c \u306E\
    \u63A5\u5C3E\u8F9E\u306E\u3046\u3061\u3001\u30CE\u30FC\u30C9\u306E\u3042\u308B\
    \u6700\u9577\u306E\u3082\u306E\n            for (int c = 0; c < 3; c++) {\n  \
    \              std::string t = s + static_cast<char>('a' + c);\n             \
    \   long long expect = 0;\n                for (size_t len = t.size(); len > 0;\
    \ len--) {\n                    long long u = find_node(t.substr(t.size() - len));\n\
    \                    if (u != -1) {\n                        expect = u;\n   \
    \                     break;\n                    }\n                }\n     \
    \           check(ac.next(v, 'a' + c) == expect, \"next\");\n            }\n \
    \           long long mc = 0;\n            for (const auto& p : pats) mc += p.size()\
    \ <= s.size() && s.compare(s.size() - p.size(), p.size(), p) == 0;\n         \
    \   check(ac.match_count(v) == mc, \"match_count\");\n        }\n\n        //\
    \ \u7167\u5408: \u611A\u76F4\u306B\u5168\u4F4D\u7F6E\u3067\u6BD4\u3079\u308B\n\
    \        for (int t = 0; t < 5; t++) {\n            std::string text = rng() %\
    \ 5 == 0 ? std::string() : random_string(30);\n            std::vector<long long>\
    \ each(m, 0);\n            std::vector<decltype(ac)::Match> all;             \
    \               // (\u958B\u59CB\u4F4D\u7F6E, \u756A\u53F7)\n            std::vector<std::tuple<long\
    \ long, long long, long long>> order;  // (\u7D42\u308F\u308B\u4F4D\u7F6E, -\u9577\
    \u3055, \u756A\u53F7) \u306E\u9806\u306B\u4E26\u3079\u308B\n            for (long\
    \ long end = 1; end <= static_cast<long long>(text.size()); end++) {\n       \
    \         for (int i = 0; i < m; i++) {\n                    long long len = pats[i].size();\n\
    \                    if (len <= end && text.compare(end - len, len, pats[i]) ==\
    \ 0) {\n                        each[i]++;\n                        order.emplace_back(end,\
    \ -len, i);\n                    }\n                }\n            }\n       \
    \     std::sort(order.begin(), order.end());\n            for (auto [end, neg_len,\
    \ i] : order) all.push_back({end + neg_len, i});\n            long long total\
    \ = 0;\n            for (long long x : each) total += x;\n            check(ac.count(text)\
    \ == total, \"count\");\n            check(ac.count_each(text) == each, \"count_each\"\
    );\n            const auto matches = ac.find_all(text);\n            check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) == all, \"find_all\");\n        }\n    }\n    // std::vector<int>\
    \ \u306E\u6587\u5B57\u5217\u3068\u3001\u5225\u306E\u6587\u5B57\u306E\u7BC4\u56F2\
    \n    {\n        AhoCorasick<10, 0> ac;\n        ac.add(std::vector<int>{1, 2});\n\
    \        ac.add(std::vector<int>{2});\n        ac.build();\n        std::vector<int>\
    \ text = {1, 2, 2, 1, 2};\n        check(ac.count(text) == 5 && ac.count_each(text)\
    \ == std::vector<long long>{2, 3}, \"std::vector<int>\");\n        const auto\
    \ matches = ac.find_all(text);\n        check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) ==\n                  std::vector<decltype(ac)::Match>{{0, 0},\
    \ {1, 1}, {2, 1}, {3, 0}, {4, 1}},\n              \"std::vector<int> \u306E\u5217\
    \u6319\");\n    }\n    // \u4E00\u81F4\u306E\u9806\u5E8F\u3001\u72EC\u7ACB\u3057\
    \u305F\u8D70\u67FB\u3001\u53F3\u8FBA\u5024\u306E\u6240\u6709\u3001\u30B3\u30D4\
    \u30FC\u30FB\u79FB\u52D5\u5F8C\u306E\u5BFF\u547D\u3002\n    {\n        AhoCorasick<>\
    \ ac;\n        ac.add(std::string(\"a\"));\n        ac.add(std::string(\"aa\"\
    ));\n        ac.add(std::string(\"a\"));\n        ac.build();\n        using Match\
    \ = decltype(ac)::Match;\n        const std::vector<Match> expected = {{0, 0},\
    \ {0, 2}, {0, 1}, {1, 0}, {1, 2}};\n        auto make_matches = [&] { return ac.find_all(std::string(\"\
    aa\")); };\n        const auto matches = make_matches();\n        auto copy =\
    \ matches;\n        auto moved = std::move(copy);\n        for (int rep = 0; rep\
    \ < 2; rep++) {\n            check(std::vector<Match>(matches.begin(), matches.end())\
    \ == expected, \"\u53F3\u8FBA\u5024\u3068\u7E70\u308A\u8FD4\u3057\u8D70\u67FB\"\
    );\n            check(std::vector<Match>(moved.begin(), moved.end()) == expected,\
    \ \"range \u306E\u30B3\u30D4\u30FC\u30FB\u79FB\u52D5\");\n        }\n        auto\
    \ it = matches.begin(), independent = it;\n        check(*it++ == expected[0]\
    \ && *it == expected[1] && *independent == expected[0], \"iterator \u306E\u30B3\
    \u30D4\u30FC\u3068\u5F8C\u7F6E increment\");\n        long long pairs = 0;\n \
    \       for (auto x : matches) {\n            for (auto y : matches) pairs +=\
    \ x.id == y.id;\n        }\n        check(pairs == 9, \"\u5165\u308C\u5B50\u306E\
    \u8D70\u67FB\");\n        std::forward_list<char> text = {'a', 'a'};\n       \
    \ const auto linked = ac.find_all(text);\n        check(std::vector<Match>(linked.begin(),\
    \ linked.end()) == expected, \"\u975E\u30E9\u30F3\u30C0\u30E0\u30A2\u30AF\u30BB\
    \u30B9\u5165\u529B\");\n        auto empty = ac.find_all(std::string());\n   \
    \     check(empty.begin() == empty.end(), \"\u7A7A\u306E\u5165\u529B\");\n#if\
    \ __cplusplus >= 202002L\n        static_assert(std::ranges::input_range<decltype(matches)>);\n\
    #endif\n    }\n    // \u30C7\u30D5\u30A9\u30EB\u30C8\u69CB\u7BC9\u3067\u304D\u306A\
    \u3044 iterator \u3082\u53D7\u3051\u53D6\u308C\u308B\u3002\n    {\n        AhoCorasick<3,\
    \ 0> ac;\n        ac.add(std::vector<int>{0, 1});\n        ac.build();\n     \
    \   const auto matches = ac.find_all(Range(3));\n        check(std::vector<decltype(ac)::Match>(matches.begin(),\
    \ matches.end()) ==\n                  std::vector<decltype(ac)::Match>{{0, 0}},\n\
    \              \"Range \u306E\u5165\u529B\");\n    }\n    // \u5165\u529B\u306E\
    \u30B3\u30D4\u30FC\u3092\u8981\u6C42\u305B\u305A\u3001\u6700\u521D\u306E\u4E00\
    \u81F4\u3088\u308A\u5F8C\u3092\u8AAD\u307E\u306A\u3044\u3002\n    {\n        struct\
    \ Character {\n            long long* reads;\n            operator int() const\
    \ {\n                ++*reads;\n                return 'a';\n            }\n \
    \       };\n        struct Text {\n            std::vector<Character> chars;\n\
    \            explicit Text(long long* reads) : chars(100, Character{reads}) {}\n\
    \            Text(const Text&) = delete;\n            auto begin() const { return\
    \ chars.begin(); }\n            auto end() const { return chars.end(); }\n   \
    \     };\n        AhoCorasick<> ac;\n        ac.add(std::string(\"a\"));\n   \
    \     ac.build();\n        long long reads = 0;\n        Text text(&reads);\n\
    \        const auto matches = ac.find_all(text);\n        check(reads == 0, \"\
    \u69CB\u7BC9\u6642\u306F\u5165\u529B\u3092\u8AAD\u307E\u306A\u3044\");\n     \
    \   for (auto match : matches) {\n            check(match.pos == 0 && match.id\
    \ == 0, \"\u6700\u521D\u306E\u4E00\u81F4\");\n            break;\n        }\n\
    \        check(reads == 1, \"\u9014\u4E2D\u7D42\u4E86\");\n    }\n    {\n    \
    \    AhoCorasick<> ac;\n        ac.build();\n        const auto matches = ac.find_all(std::string(\"\
    aaa\"));\n        check(matches.begin() == matches.end(), \"\u30D1\u30BF\u30FC\
    \u30F3\u306A\u3057\");\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/string/aho-corasick.hpp
  - src/utility/range.hpp
  isVerificationFile: true
  path: test/unittest/string/aho-corasick.test.cpp
  requiredBy: []
  timestamp: '2026-11-10 03:47:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/string/aho-corasick.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/string/aho-corasick.test.cpp
- /verify/test/unittest/string/aho-corasick.test.cpp.html
title: test/unittest/string/aho-corasick.test.cpp
---
