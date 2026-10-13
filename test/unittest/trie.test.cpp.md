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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A
  bundledCode: "#line 1 \"test/unittest/trie.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Trie \u3092\u3001\u6587\u5B57\u5217\u306E\u591A\u91CD\u96C6\u5408\u3092\
    \u611A\u76F4\u306B\u8ABF\u3079\u308B\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <map>\n#include <random>\n#include <string>\n#include <vector>\n\n#line 2 \"\
    src/string/trie.hpp\"\n\n/**\n * @file trie.hpp\n * @brief Trie\n */\n\n#include\
    \ <array>\n#include <cassert>\n#line 11 \"src/string/trie.hpp\"\n\n/**\n * @brief\
    \ Trie (\u6587\u5B57\u5217\u306E\u96C6\u5408\u3092\u63A5\u982D\u8F9E\u306E\u6728\
    \u3067\u7BA1\u7406\u3059\u308B)\n *\n * \u6587\u5B57 c \u306F c - Base \u3068\u3057\
    \u3066 0 \u4EE5\u4E0A K \u672A\u6E80\u306E\u756A\u53F7\u306B\u76F4\u3059\u3002\
    \u6839\u306F\u30CE\u30FC\u30C9 0 (\u7A7A\u6587\u5B57\u5217)\n * \u540C\u3058\u6587\
    \u5B57\u5217\u3092\u4F55\u5EA6\u3082\u8FFD\u52A0\u3067\u304D\u3001\u591A\u91CD\
    \u96C6\u5408\u3068\u3057\u3066\u6271\u3046\n * \u4F8B:\n * Trie<26, 'a'> trie;\n\
    \ * trie.insert(\"abc\");\n * trie.count_prefix(\"ab\");  // 1\n *\n * @tparam\
    \ K \u6587\u5B57\u306E\u7A2E\u985E\u6570\n * @tparam Base \u6700\u5C0F\u306E\u6587\
    \u5B57\n */\ntemplate <int K = 26, int Base = 'a'>\nclass Trie {\n    struct Node\
    \ {\n        std::array<int, K> next;\n        int parent, depth;\n        int\
    \ prefix_cnt;  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B (\u3053\u306E\
    \u30CE\u30FC\u30C9\u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\u306B\u6301\
    \u3064) \u6587\u5B57\u5217\u306E\u500B\u6570\n        int word_cnt;    // \u3053\
    \u306E\u30CE\u30FC\u30C9\u3067\u7D42\u308F\u308B\u6587\u5B57\u5217\u306E\u500B\
    \u6570\n    };\n    std::vector<Node> nodes;\n\n    int add_node(int parent, int\
    \ depth) {\n        Node node;\n        node.next.fill(-1);\n        node.parent\
    \ = parent;\n        node.depth = depth;\n        node.prefix_cnt = node.word_cnt\
    \ = 0;\n        nodes.push_back(node);\n        return nodes.size() - 1;\n   \
    \ }\n    static int index(int c) {\n        assert(0 <= c - Base && c - Base <\
    \ K);\n        return c - Base;\n    }\n\npublic:\n    Trie() { add_node(-1, 0);\
    \ }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9\u306E\u500B\u6570 (\u6839\u3092\
    \u542B\u3080)\n     */\n    int size() const { return nodes.size(); }\n\n    /**\n\
    \     * @brief \u6587\u5B57\u5217 s \u3092 1 \u500B\u8FFD\u52A0\u3057\u3001s \u306B\
    \u5BFE\u5FDC\u3059\u308B\u30CE\u30FC\u30C9\u3092\u8FD4\u3059 O(|s|)\n     * @param\
    \ s std::string \u3084 std::vector<int> \u306A\u3069\u3001\u8981\u7D20\u3092\u6574\
    \u6570\u306B\u5909\u63DB\u3067\u304D\u308B\u5217\n     */\n    template <typename\
    \ R>\n    int insert(const R& s) {\n        int v = 0;\n        nodes[v].prefix_cnt++;\n\
    \        for (auto c : s) {\n            int i = index(c);\n            if (nodes[v].next[i]\
    \ == -1) {\n                int u = add_node(v, nodes[v].depth + 1);\n       \
    \         nodes[v].next[i] = u;\n            }\n            v = nodes[v].next[i];\n\
    \            nodes[v].prefix_cnt++;\n        }\n        nodes[v].word_cnt++;\n\
    \        return v;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u3092\
    \ 1 \u500B\u53D6\u308A\u9664\u304F\u3002s \u304C\u306A\u3051\u308C\u3070\u4F55\
    \u3082\u305B\u305A false \u3092\u8FD4\u3059 O(|s|)\n     * \u30CE\u30FC\u30C9\u306F\
    \u524A\u9664\u3057\u306A\u3044\u306E\u3067\u3001\u30CE\u30FC\u30C9\u306E\u756A\
    \u53F7\u306F\u5909\u308F\u3089\u306A\u3044\n     */\n    template <typename R>\n\
    \    bool erase(const R& s) {\n        int v = find(s);\n        if (v == -1 ||\
    \ nodes[v].word_cnt == 0) return false;\n        nodes[v].word_cnt--;\n      \
    \  for (; v != -1; v = nodes[v].parent) nodes[v].prefix_cnt--;\n        return\
    \ true;\n    }\n\n    /**\n     * @brief \u6587\u5B57\u5217 s \u306B\u5BFE\u5FDC\
    \u3059\u308B\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1) O(|s|)\n     * s\
    \ \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\u5B57\u5217\u3092\u8FFD\u52A0\
    \u3057\u305F\u3053\u3068\u304C\u3042\u308C\u3070\u3001\u53D6\u308A\u9664\u3044\
    \u305F\u5F8C\u3067\u3082\u30CE\u30FC\u30C9\u306F\u6B8B\u308B\n     */\n    template\
    \ <typename R>\n    int find(const R& s) const {\n        int v = 0;\n       \
    \ for (auto c : s) {\n            v = nodes[v].next[index(c)];\n            if\
    \ (v == -1) return -1;\n        }\n        return v;\n    }\n\n    /**\n     *\
    \ @brief \u6587\u5B57\u5217 s \u306E\u500B\u6570 O(|s|)\n     */\n    template\
    \ <typename R>\n    int count(const R& s) const {\n        int v = find(s);\n\
    \        return v == -1 ? 0 : nodes[v].word_cnt;\n    }\n    /**\n     * @brief\
    \ s \u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064\u6587\u5B57\u5217\u306E\u500B\u6570\
    \ O(|s|)\n     */\n    template <typename R>\n    int count_prefix(const R& s)\
    \ const {\n        int v = find(s);\n        return v == -1 ? 0 : nodes[v].prefix_cnt;\n\
    \    }\n    /**\n     * @brief \u6587\u5B57\u5217\u306E\u500B\u6570 (\u91CD\u8907\
    \u3092\u542B\u3080)\n     */\n    int total() const { return nodes[0].prefix_cnt;\
    \ }\n\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u304B\u3089\u6587\u5B57 c\
    \ \u3067\u9032\u3093\u3060\u30CE\u30FC\u30C9 (\u306A\u3051\u308C\u3070 -1)\n \
    \    */\n    int child(int v, int c) const { return nodes[v].next[index(c)]; }\n\
    \    /**\n     * @brief \u30CE\u30FC\u30C9 v \u306E\u89AA (\u6839\u306A\u3089\
    \ -1)\n     */\n    int parent(int v) const { return nodes[v].parent; }\n    /**\n\
    \     * @brief \u30CE\u30FC\u30C9 v \u306E\u6DF1\u3055 (\u5BFE\u5FDC\u3059\u308B\
    \u6587\u5B57\u5217\u306E\u9577\u3055)\n     */\n    int depth(int v) const { return\
    \ nodes[v].depth; }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u3092\u901A\u308B\
    \ (v \u306E\u6587\u5B57\u5217\u3092\u63A5\u982D\u8F9E\u306B\u6301\u3064) \u6587\
    \u5B57\u5217\u306E\u500B\u6570\n     */\n    int prefix_count(int v) const { return\
    \ nodes[v].prefix_cnt; }\n    /**\n     * @brief \u30CE\u30FC\u30C9 v \u3067\u7D42\
    \u308F\u308B\u6587\u5B57\u5217\u306E\u500B\u6570\n     */\n    int word_count(int\
    \ v) const { return nodes[v].word_cnt; }\n\n    /**\n     * @brief s \u306E\u63A5\
    \u982D\u8F9E\u306E\u3046\u3061\u3001\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\
    \u306E\u3069\u308C\u304B\u306E\u63A5\u982D\u8F9E\u306B\u3082\u306A\u3063\u3066\
    \u3044\u308B\u3082\u306E\u306E\u6700\u9577\u306E\u9577\u3055 O(|s|)\n     * \u8FFD\
    \u52A0\u3057\u305F\u6587\u5B57\u5217 (\u53D6\u308A\u9664\u3044\u305F\u3082\u306E\
    \u306F\u9664\u304F) \u306E\u3069\u308C\u304B\u3068\u306E\u6700\u9577\u5171\u901A\
    \u63A5\u982D\u8F9E\u306E\u9577\u3055\u306E\u6700\u5927\u5024\u306B\u306A\u308B\
    \n     */\n    template <typename R>\n    int longest_common_prefix(const R& s)\
    \ const {\n        int v = 0, len = 0;\n        for (auto c : s) {\n         \
    \   int u = nodes[v].next[index(c)];\n            if (u == -1 || nodes[u].prefix_cnt\
    \ == 0) break;\n            v = u;\n            len++;\n        }\n        return\
    \ len;\n    }\n};\n#line 14 \"test/unittest/trie.test.cpp\"\n\nint main() {\n\
    \    std::mt19937 rng(314);\n    bool ok = true;\n    auto random_string = [&](int\
    \ max_len) {\n        std::string s(rng() % (max_len + 1), 'a');\n        for\
    \ (auto& c : s) c = 'a' + rng() % 3;\n        return s;\n    };\n    for (int\
    \ rep = 0; rep < 300 && ok; rep++) {\n        Trie<3, 'a'> trie;\n        std::map<std::string,\
    \ int> ms;  // \u6587\u5B57\u5217 -> \u500B\u6570\n        std::map<std::string,\
    \ int> node_of = {{\"\", 0}};  // \u30CE\u30FC\u30C9\u304C\u3042\u308B\u6587\u5B57\
    \u5217 (\u6839\u3068\u3001\u4E00\u5EA6\u3067\u3082\u8FFD\u52A0\u3057\u305F\u6587\
    \u5B57\u5217\u306E\u63A5\u982D\u8F9E)\n        for (int q = 0; q < 200 && ok;\
    \ q++) {\n            std::string s = random_string(5);\n            int type\
    \ = rng() % 3;\n            if (type == 0) {\n                int v = trie.insert(s);\n\
    \                ms[s]++;\n                for (int len = 0; len <= (int)s.size();\
    \ len++) node_of.emplace(s.substr(0, len), -1);\n                ok = ok && trie.depth(v)\
    \ == (int)s.size();\n            } else if (type == 1) {\n                bool\
    \ expected = ms.count(s) && ms[s] > 0;\n                ok = ok && trie.erase(s)\
    \ == expected;\n                if (expected) ms[s]--;\n            }\n      \
    \      // \u3059\u3079\u3066\u306E\u554F\u3044\u5408\u308F\u305B\u3092\u611A\u76F4\
    \u306A\u7D50\u679C\u3068\u6BD4\u3079\u308B\n            std::string t = random_string(5);\n\
    \            int cnt = ms.count(t) ? ms[t] : 0, pre = 0, total = 0, lcp = 0;\n\
    \            for (auto& [u, c] : ms) {\n                total += c;\n        \
    \        if (u.compare(0, t.size(), t) == 0 && u.size() >= t.size()) pre += c;\n\
    \                if (c > 0) {\n                    int l = 0;\n              \
    \      while (l < (int)std::min(u.size(), t.size()) && u[l] == t[l]) l++;\n  \
    \                  lcp = std::max(lcp, l);\n                }\n            }\n\
    \            int v = trie.find(t);\n            ok = ok && (v != -1) == (node_of.count(t)\
    \ > 0);\n            ok = ok && trie.count(t) == cnt && trie.count_prefix(t) ==\
    \ pre && trie.total() == total;\n            ok = ok && trie.longest_common_prefix(t)\
    \ == lcp;\n            if (v != -1) {\n                ok = ok && trie.word_count(v)\
    \ == cnt && trie.prefix_count(v) == pre && trie.depth(v) == (int)t.size();\n \
    \           }\n        }\n        // \u30CE\u30FC\u30C9\u306E\u6570\u3068\u3001\
    \u89AA\u5B50\u30FB\u6DF1\u3055\u306E\u95A2\u4FC2\n        ok = ok && trie.size()\
    \ == (int)node_of.size();\n        for (auto& [u, x] : node_of) {\n          \
    \  int v = trie.find(u);\n            if (u.empty()) {\n                ok = ok\
    \ && v == 0 && trie.parent(v) == -1;\n            } else {\n                int\
    \ p = trie.find(u.substr(0, u.size() - 1));\n                ok = ok && trie.parent(v)\
    \ == p && trie.child(p, u.back()) == v && trie.depth(v) == (int)u.size();\n  \
    \          }\n        }\n    }\n\n    // \u4F8B: \u3059\u3079\u3066\u306E\u7D44\
    \u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u306E\u548C\
    \u306F\u3001\u6839\u4EE5\u5916\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B\u6587\
    \u5B57\u5217\u306E\u7D44\u306E\u500B\u6570\u306E\u548C\n    Trie<26, 'a'> trie;\n\
    \    std::vector<std::string> words = {\"ab\", \"abc\", \"arc\"};\n    for (auto&\
    \ w : words) trie.insert(w);\n    long long sum = 0;\n    for (int v = 1; v <\
    \ trie.size(); v++) sum += (long long)trie.prefix_count(v) * (trie.prefix_count(v)\
    \ - 1) / 2;\n    ok = ok && sum == 4;  // lcp(ab, abc) = 2, lcp(ab, arc) = 1,\
    \ lcp(abc, arc) = 1\n    // vector<int> \u3082\u8FFD\u52A0\u3067\u304D\u308B\n\
    \    Trie<10, 0> digits;\n    digits.insert(std::vector<int>{3, 1, 4});\n    ok\
    \ = ok && digits.count_prefix(std::vector<int>{3, 1}) == 1 && digits.find(std::vector<int>{1})\
    \ == -1;\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n    else std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Trie \u3092\u3001\u6587\u5B57\u5217\u306E\u591A\u91CD\u96C6\u5408\u3092\
    \u611A\u76F4\u306B\u8ABF\u3079\u308B\u65B9\u6CD5\u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include <algorithm>\n#include <iostream>\n#include\
    \ <map>\n#include <random>\n#include <string>\n#include <vector>\n\n#include \"\
    ../../src/string/trie.hpp\"\n\nint main() {\n    std::mt19937 rng(314);\n    bool\
    \ ok = true;\n    auto random_string = [&](int max_len) {\n        std::string\
    \ s(rng() % (max_len + 1), 'a');\n        for (auto& c : s) c = 'a' + rng() %\
    \ 3;\n        return s;\n    };\n    for (int rep = 0; rep < 300 && ok; rep++)\
    \ {\n        Trie<3, 'a'> trie;\n        std::map<std::string, int> ms;  // \u6587\
    \u5B57\u5217 -> \u500B\u6570\n        std::map<std::string, int> node_of = {{\"\
    \", 0}};  // \u30CE\u30FC\u30C9\u304C\u3042\u308B\u6587\u5B57\u5217 (\u6839\u3068\
    \u3001\u4E00\u5EA6\u3067\u3082\u8FFD\u52A0\u3057\u305F\u6587\u5B57\u5217\u306E\
    \u63A5\u982D\u8F9E)\n        for (int q = 0; q < 200 && ok; q++) {\n         \
    \   std::string s = random_string(5);\n            int type = rng() % 3;\n   \
    \         if (type == 0) {\n                int v = trie.insert(s);\n        \
    \        ms[s]++;\n                for (int len = 0; len <= (int)s.size(); len++)\
    \ node_of.emplace(s.substr(0, len), -1);\n                ok = ok && trie.depth(v)\
    \ == (int)s.size();\n            } else if (type == 1) {\n                bool\
    \ expected = ms.count(s) && ms[s] > 0;\n                ok = ok && trie.erase(s)\
    \ == expected;\n                if (expected) ms[s]--;\n            }\n      \
    \      // \u3059\u3079\u3066\u306E\u554F\u3044\u5408\u308F\u305B\u3092\u611A\u76F4\
    \u306A\u7D50\u679C\u3068\u6BD4\u3079\u308B\n            std::string t = random_string(5);\n\
    \            int cnt = ms.count(t) ? ms[t] : 0, pre = 0, total = 0, lcp = 0;\n\
    \            for (auto& [u, c] : ms) {\n                total += c;\n        \
    \        if (u.compare(0, t.size(), t) == 0 && u.size() >= t.size()) pre += c;\n\
    \                if (c > 0) {\n                    int l = 0;\n              \
    \      while (l < (int)std::min(u.size(), t.size()) && u[l] == t[l]) l++;\n  \
    \                  lcp = std::max(lcp, l);\n                }\n            }\n\
    \            int v = trie.find(t);\n            ok = ok && (v != -1) == (node_of.count(t)\
    \ > 0);\n            ok = ok && trie.count(t) == cnt && trie.count_prefix(t) ==\
    \ pre && trie.total() == total;\n            ok = ok && trie.longest_common_prefix(t)\
    \ == lcp;\n            if (v != -1) {\n                ok = ok && trie.word_count(v)\
    \ == cnt && trie.prefix_count(v) == pre && trie.depth(v) == (int)t.size();\n \
    \           }\n        }\n        // \u30CE\u30FC\u30C9\u306E\u6570\u3068\u3001\
    \u89AA\u5B50\u30FB\u6DF1\u3055\u306E\u95A2\u4FC2\n        ok = ok && trie.size()\
    \ == (int)node_of.size();\n        for (auto& [u, x] : node_of) {\n          \
    \  int v = trie.find(u);\n            if (u.empty()) {\n                ok = ok\
    \ && v == 0 && trie.parent(v) == -1;\n            } else {\n                int\
    \ p = trie.find(u.substr(0, u.size() - 1));\n                ok = ok && trie.parent(v)\
    \ == p && trie.child(p, u.back()) == v && trie.depth(v) == (int)u.size();\n  \
    \          }\n        }\n    }\n\n    // \u4F8B: \u3059\u3079\u3066\u306E\u7D44\
    \u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E\u306E\u9577\u3055\u306E\u548C\
    \u306F\u3001\u6839\u4EE5\u5916\u306E\u30CE\u30FC\u30C9\u3092\u901A\u308B\u6587\
    \u5B57\u5217\u306E\u7D44\u306E\u500B\u6570\u306E\u548C\n    Trie<26, 'a'> trie;\n\
    \    std::vector<std::string> words = {\"ab\", \"abc\", \"arc\"};\n    for (auto&\
    \ w : words) trie.insert(w);\n    long long sum = 0;\n    for (int v = 1; v <\
    \ trie.size(); v++) sum += (long long)trie.prefix_count(v) * (trie.prefix_count(v)\
    \ - 1) / 2;\n    ok = ok && sum == 4;  // lcp(ab, abc) = 2, lcp(ab, arc) = 1,\
    \ lcp(abc, arc) = 1\n    // vector<int> \u3082\u8FFD\u52A0\u3067\u304D\u308B\n\
    \    Trie<10, 0> digits;\n    digits.insert(std::vector<int>{3, 1, 4});\n    ok\
    \ = ok && digits.count_prefix(std::vector<int>{3, 1}) == 1 && digits.find(std::vector<int>{1})\
    \ == -1;\n\n    if (ok) std::cout << \"Hello World\" << std::endl;\n    else std::cerr\
    \ << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/string/trie.hpp
  isVerificationFile: true
  path: test/unittest/trie.test.cpp
  requiredBy: []
  timestamp: '2026-10-14 01:43:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/trie.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/trie.test.cpp
- /verify/test/unittest/trie.test.cpp.html
title: test/unittest/trie.test.cpp
---
