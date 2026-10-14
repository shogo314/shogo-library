---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/grl-5-d.test.cpp
    title: test/aoj/grl-5-d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/heavy-light-decomposition.test.cpp
    title: test/unittest/heavy-light-decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/jump-on-tree.2.test.cpp
    title: test/yosupo/jump-on-tree.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.5.test.cpp
    title: test/yosupo/lca.5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex-add-path-sum.test.cpp
    title: test/yosupo/vertex-add-path-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex-add-subtree-sum.2.test.cpp
    title: test/yosupo/vertex-add-subtree-sum.2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex-set-path-composite.test.cpp
    title: test/yosupo/vertex-set-path-composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
    links: []
  bundledCode: "#line 2 \"src/graph/heavy-light-decomposition.hpp\"\n\n/**\n * @file\
    \ heavy-light-decomposition.hpp\n * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\n/**\n * @brief HL \u5206\u89E3 (Heavy-Light Decomposition)\n *\n\
    \ * \u6728\u306E\u9802\u70B9\u3092\u3001\u3069\u306E\u30D1\u30B9\u3082 O(log n)\
    \ \u500B\u306E\u533A\u9593\u306B\u5206\u304B\u308C\u3001\u3069\u306E\u90E8\u5206\
    \u6728\u3082 1 \u3064\u306E\u533A\u9593\u306B\u306A\u308B\u3088\u3046\u306B\u4E26\
    \u3079\u66FF\u3048\u308B\n * \u9802\u70B9 v \u306F\u5217\u306E index(v) \u756A\
    \u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u3002\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    \u306A\u3069\u3068\u7D44\u307F\u5408\u308F\u305B\u3066\u3001\u30D1\u30B9\u3084\
    \u90E8\u5206\u6728\u3078\u306E\u30AF\u30A8\u30EA\u3092\u884C\u3046\n * \u524D\u8A08\
    \u7B97 O(n)\u3002DFS \u306F\u518D\u5E30\u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B\
    :\n * HeavyLightDecomposition hld(g, root);\n * for (auto [a, b] : hld.path(u,\
    \ v)) sum += seg.prod(std::min(a, b), std::max(a, b) + 1);\n * auto [l, r] = hld.subtree(v);\
    \  // \u90E8\u5206\u6728\u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition\
    \ {\n    int n, root;\n    std::vector<int> par, dep, sz, heavy, head, in, order;\n\
    \n   public:\n    /**\n     * @brief \u6728 tree \u3092\u6839 root \u3067 HL \u5206\
    \u89E3\u3059\u308B\n     * @param tree Graph\u3001Tree\u3001RootedTree \u306A\u3069\
    \u3002tree.n \u304C\u9802\u70B9\u6570\u3001for (int u : tree[v]) \u3067 v \u306B\
    \u96A3\u63A5\u3059\u308B\u9802\u70B9\u3092\u5217\u6319\u3067\u304D\u308B\u3053\
    \u3068\n     */\n    template <typename G>\n    explicit HeavyLightDecomposition(const\
    \ G& tree, int root = 0)\n        : n(tree.n), root(root), par(n, -1), dep(n,\
    \ 0), sz(n, 1), heavy(n, -1), head(n), in(n), order(n) {\n        assert(0 <=\
    \ root && root < n);\n        // \u6839\u304B\u3089\u306E BFS \u9806\u3067\u89AA\
    \u3068\u6DF1\u3055\u3092\u6C7A\u3081\u308B\n        std::vector<int> bfs = {root};\n\
    \        bfs.reserve(n);\n        for (int i = 0; i < (int)bfs.size(); i++) {\n\
    \            int v = bfs[i];\n            for (int u : tree[v]) {\n          \
    \      if (u == par[v]) continue;\n                assert(u != root && par[u]\
    \ == -1 && \"HeavyLightDecomposition: not a tree\");\n                par[u] =\
    \ v;\n                dep[u] = dep[v] + 1;\n                bfs.push_back(u);\n\
    \            }\n        }\n        assert((int)bfs.size() == n && \"HeavyLightDecomposition:\
    \ not connected\");\n        // \u8449\u306E\u5074\u304B\u3089\u90E8\u5206\u6728\
    \u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u3001\u6700\u3082\u5927\u304D\u3044\
    \u5B50\u3092 heavy \u306B\u3059\u308B\n        for (int i = n - 1; i > 0; i--)\
    \ {\n            int v = bfs[i], p = par[v];\n            sz[p] += sz[v];\n  \
    \          if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;\n       \
    \ }\n        // heavy \u306A\u5B50\u3092\u6700\u5F8C\u306B\u7A4D\u3080\u3068\u3001\
    \u6B21\u306B\u53D6\u308A\u51FA\u3055\u308C\u3066 index \u304C\u9023\u7D9A\u3059\
    \u308B\n        std::vector<int> st = {root};\n        head[root] = root;\n  \
    \      int k = 0;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = k;\n            order[k++] =\
    \ v;\n            for (int u : tree[v]) {\n                if (u == par[v] ||\
    \ u == heavy[v]) continue;\n                head[u] = u;\n                st.push_back(u);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int size() const { return n; }\n    /**\n     * @brief \u9802\
    \u70B9 v \u306E\u5217\u3067\u306E\u4F4D\u7F6E\n     */\n    int index(int v) const\
    \ { return in[v]; }\n    /**\n     * @brief \u5217\u306E i \u756A\u76EE\u306E\u9802\
    \u70B9 (index \u306E\u9006)\n     */\n    int vertex(int i) const { return order[i];\
    \ }\n    /**\n     * @brief v \u306E\u89AA (\u6839\u306A\u3089 -1)\n     */\n\
    \    int parent(int v) const { return par[v]; }\n    /**\n     * @brief v \u306E\
    \u6DF1\u3055 (\u6839\u306F 0\u3001\u8FBA\u306E\u672C\u6570)\n     */\n    int\
    \ depth(int v) const { return dep[v]; }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    int subtree_size(int v) const { return sz[v]; }\n    /**\n     * @brief\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u533A\u9593 [l, r)\n     */\n    std::pair<int, int> subtree(int\
    \ v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n     * @brief u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n     */\n    int lca(int\
    \ u, int v) const {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n   \
    \     while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            u = par[head[u]];\n        }\n        return dep[u]\
    \ < dep[v] ? u : v;\n    }\n    /**\n     * @brief u \u3068 v \u306E\u9593\u306E\
    \u8FBA\u306E\u672C\u6570 O(log n)\n     */\n    int dist(int u, int v) const {\
    \ return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n    /**\n     * @brief v \u304B\
    \u3089\u6839\u306E\u65B9\u3078 k \u672C\u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\
    \u70B9 (k > depth(v) \u306A\u3089 -1) O(log n)\n     */\n    int hop(int v, int\
    \ k) const {\n        assert(0 <= v && v < n && k >= 0);\n        if (k > dep[v])\
    \ return -1;\n        while (true) {\n            int h = head[v];\n         \
    \   if (in[v] - in[h] >= k) return order[in[v] - k];\n            k -= in[v] -\
    \ in[h] + 1;\n            v = par[h];\n        }\n    }\n    /**\n     * @brief\
    \ u \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089 k \u672C\
    \u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\u3089\
    \ -1) O(log n)\n     */\n    int jump(int u, int v, int k) const {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n && k >= 0);\n        int w = lca(u, v);\n \
    \       int du = dep[u] - dep[w], dv = dep[v] - dep[w];\n        if (k <= du)\
    \ return hop(u, k);\n        if (k <= du + dv) return hop(v, du + dv - k);\n \
    \       return -1;\n    }\n\n    /**\n     * @brief u \u304B\u3089 v \u3078\u306E\
    \u30D1\u30B9\u3092\u3001\u5217\u306E\u533A\u9593\u306B\u5206\u3051\u3066 u \u5074\
    \u304B\u3089\u9806\u306B\u4E26\u3079\u308B O(log n)\n     *\n     * \u5404\u8981\
    \u7D20 (a, b) \u306F\u3001\u5217\u306E a \u756A\u76EE\u304B\u3089 b \u756A\u76EE\
    \u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u3092\u3001a \u304B\u3089 b \u306E\
    \u5411\u304D\u306B\u305F\u3069\u308B\u3053\u3068\u3092\u8868\u3059\n     * \u5411\
    \u304D\u3092\u8868\u3059\u305F\u3081\u3001\u3053\u306E\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306E\u4ED6\u306E\u533A\u9593 (\u534A\u958B\u533A\u9593 [l, r)) \u3068\u9055\
    \u3063\u3066\u9589\u533A\u9593\u306B\u306A\u3063\u3066\u3044\u308B\n     * a >\
    \ b \u306A\u3089 index \u304C\u6E1B\u308B\u5411\u304D (\u6839\u306B\u8FD1\u3065\
    \u304F\u5411\u304D) \u306B\u305F\u3069\u308B\n     * \u4EA4\u63DB\u6CD5\u5247\u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044\u6F14\u7B97\u3067\u306F\u3001a > b \u306E\
    \u533A\u9593\u306F\u9006\u9806\u306E\u7A4D\u3092\u4F7F\u3046\n     * @param edge\
    \ true \u306A\u3089\u8FBA\u306B\u3064\u3044\u3066\u306E\u30D1\u30B9\u306B\u3059\
    \u308B\u3002\u8FBA (parent(v), v) \u3092 index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\
    \u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\u3092\u542B\u3081\u306A\u3044\n     */\n\
    \    std::vector<std::pair<int, int>> path(int u, int v, bool edge = false) const\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        std::vector<std::pair<int,\
    \ int>> up, down;\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ >= dep[head[v]]) {\n                up.emplace_back(in[u], in[head[u]]);\n \
    \               u = par[head[u]];\n            } else {\n                down.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   if (dep[u] >= dep[v]) {\n            // v \u304C lca\n            int l =\
    \ in[v] + edge;\n            if (l <= in[u]) up.emplace_back(in[u], l);\n    \
    \    } else {\n            // u \u304C lca\n            int l = in[u] + edge;\n\
    \            if (l <= in[v]) down.emplace_back(l, in[v]);\n        }\n       \
    \ up.insert(up.end(), down.rbegin(), down.rend());\n        return up;\n    }\n\
    };\n"
  code: "#pragma once\n\n/**\n * @file heavy-light-decomposition.hpp\n * @brief HL\
    \ \u5206\u89E3 (Heavy-Light Decomposition)\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\n/**\n * @brief HL \u5206\
    \u89E3 (Heavy-Light Decomposition)\n *\n * \u6728\u306E\u9802\u70B9\u3092\u3001\
    \u3069\u306E\u30D1\u30B9\u3082 O(log n) \u500B\u306E\u533A\u9593\u306B\u5206\u304B\
    \u308C\u3001\u3069\u306E\u90E8\u5206\u6728\u3082 1 \u3064\u306E\u533A\u9593\u306B\
    \u306A\u308B\u3088\u3046\u306B\u4E26\u3079\u66FF\u3048\u308B\n * \u9802\u70B9\
    \ v \u306F\u5217\u306E index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\u3059\u308B\u3002\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\u306A\u3069\u3068\u7D44\u307F\u5408\u308F\
    \u305B\u3066\u3001\u30D1\u30B9\u3084\u90E8\u5206\u6728\u3078\u306E\u30AF\u30A8\
    \u30EA\u3092\u884C\u3046\n * \u524D\u8A08\u7B97 O(n)\u3002DFS \u306F\u518D\u5E30\
    \u3092\u4F7F\u308F\u306A\u3044\n * \u4F8B:\n * HeavyLightDecomposition hld(g,\
    \ root);\n * for (auto [a, b] : hld.path(u, v)) sum += seg.prod(std::min(a, b),\
    \ std::max(a, b) + 1);\n * auto [l, r] = hld.subtree(v);  // \u90E8\u5206\u6728\
    \u306F\u533A\u9593 [l, r)\n */\nclass HeavyLightDecomposition {\n    int n, root;\n\
    \    std::vector<int> par, dep, sz, heavy, head, in, order;\n\n   public:\n  \
    \  /**\n     * @brief \u6728 tree \u3092\u6839 root \u3067 HL \u5206\u89E3\u3059\
    \u308B\n     * @param tree Graph\u3001Tree\u3001RootedTree \u306A\u3069\u3002\
    tree.n \u304C\u9802\u70B9\u6570\u3001for (int u : tree[v]) \u3067 v \u306B\u96A3\
    \u63A5\u3059\u308B\u9802\u70B9\u3092\u5217\u6319\u3067\u304D\u308B\u3053\u3068\
    \n     */\n    template <typename G>\n    explicit HeavyLightDecomposition(const\
    \ G& tree, int root = 0)\n        : n(tree.n), root(root), par(n, -1), dep(n,\
    \ 0), sz(n, 1), heavy(n, -1), head(n), in(n), order(n) {\n        assert(0 <=\
    \ root && root < n);\n        // \u6839\u304B\u3089\u306E BFS \u9806\u3067\u89AA\
    \u3068\u6DF1\u3055\u3092\u6C7A\u3081\u308B\n        std::vector<int> bfs = {root};\n\
    \        bfs.reserve(n);\n        for (int i = 0; i < (int)bfs.size(); i++) {\n\
    \            int v = bfs[i];\n            for (int u : tree[v]) {\n          \
    \      if (u == par[v]) continue;\n                assert(u != root && par[u]\
    \ == -1 && \"HeavyLightDecomposition: not a tree\");\n                par[u] =\
    \ v;\n                dep[u] = dep[v] + 1;\n                bfs.push_back(u);\n\
    \            }\n        }\n        assert((int)bfs.size() == n && \"HeavyLightDecomposition:\
    \ not connected\");\n        // \u8449\u306E\u5074\u304B\u3089\u90E8\u5206\u6728\
    \u306E\u5927\u304D\u3055\u3092\u6C42\u3081\u3001\u6700\u3082\u5927\u304D\u3044\
    \u5B50\u3092 heavy \u306B\u3059\u308B\n        for (int i = n - 1; i > 0; i--)\
    \ {\n            int v = bfs[i], p = par[v];\n            sz[p] += sz[v];\n  \
    \          if (heavy[p] == -1 || sz[v] > sz[heavy[p]]) heavy[p] = v;\n       \
    \ }\n        // heavy \u306A\u5B50\u3092\u6700\u5F8C\u306B\u7A4D\u3080\u3068\u3001\
    \u6B21\u306B\u53D6\u308A\u51FA\u3055\u308C\u3066 index \u304C\u9023\u7D9A\u3059\
    \u308B\n        std::vector<int> st = {root};\n        head[root] = root;\n  \
    \      int k = 0;\n        while (!st.empty()) {\n            int v = st.back();\n\
    \            st.pop_back();\n            in[v] = k;\n            order[k++] =\
    \ v;\n            for (int u : tree[v]) {\n                if (u == par[v] ||\
    \ u == heavy[v]) continue;\n                head[u] = u;\n                st.push_back(u);\n\
    \            }\n            if (heavy[v] != -1) {\n                head[heavy[v]]\
    \ = head[v];\n                st.push_back(heavy[v]);\n            }\n       \
    \ }\n    }\n\n    int size() const { return n; }\n    /**\n     * @brief \u9802\
    \u70B9 v \u306E\u5217\u3067\u306E\u4F4D\u7F6E\n     */\n    int index(int v) const\
    \ { return in[v]; }\n    /**\n     * @brief \u5217\u306E i \u756A\u76EE\u306E\u9802\
    \u70B9 (index \u306E\u9006)\n     */\n    int vertex(int i) const { return order[i];\
    \ }\n    /**\n     * @brief v \u306E\u89AA (\u6839\u306A\u3089 -1)\n     */\n\
    \    int parent(int v) const { return par[v]; }\n    /**\n     * @brief v \u306E\
    \u6DF1\u3055 (\u6839\u306F 0\u3001\u8FBA\u306E\u672C\u6570)\n     */\n    int\
    \ depth(int v) const { return dep[v]; }\n    /**\n     * @brief v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306E\u500B\u6570\n   \
    \  */\n    int subtree_size(int v) const { return sz[v]; }\n    /**\n     * @brief\
    \ v \u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u9802\u70B9\u306B\u5BFE\
    \u5FDC\u3059\u308B\u533A\u9593 [l, r)\n     */\n    std::pair<int, int> subtree(int\
    \ v) const { return {in[v], in[v] + sz[v]}; }\n\n    /**\n     * @brief u \u3068\
    \ v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148 O(log n)\n     */\n    int lca(int\
    \ u, int v) const {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n   \
    \     while (head[u] != head[v]) {\n            if (dep[head[u]] < dep[head[v]])\
    \ std::swap(u, v);\n            u = par[head[u]];\n        }\n        return dep[u]\
    \ < dep[v] ? u : v;\n    }\n    /**\n     * @brief u \u3068 v \u306E\u9593\u306E\
    \u8FBA\u306E\u672C\u6570 O(log n)\n     */\n    int dist(int u, int v) const {\
    \ return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }\n    /**\n     * @brief v \u304B\
    \u3089\u6839\u306E\u65B9\u3078 k \u672C\u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\
    \u70B9 (k > depth(v) \u306A\u3089 -1) O(log n)\n     */\n    int hop(int v, int\
    \ k) const {\n        assert(0 <= v && v < n && k >= 0);\n        if (k > dep[v])\
    \ return -1;\n        while (true) {\n            int h = head[v];\n         \
    \   if (in[v] - in[h] >= k) return order[in[v] - k];\n            k -= in[v] -\
    \ in[h] + 1;\n            v = par[h];\n        }\n    }\n    /**\n     * @brief\
    \ u \u304B\u3089 v \u3078\u306E\u30D1\u30B9\u3067\u3001u \u304B\u3089 k \u672C\
    \u306E\u8FBA\u3092\u9032\u3093\u3060\u9802\u70B9 (k > dist(u, v) \u306A\u3089\
    \ -1) O(log n)\n     */\n    int jump(int u, int v, int k) const {\n        assert(0\
    \ <= u && u < n && 0 <= v && v < n && k >= 0);\n        int w = lca(u, v);\n \
    \       int du = dep[u] - dep[w], dv = dep[v] - dep[w];\n        if (k <= du)\
    \ return hop(u, k);\n        if (k <= du + dv) return hop(v, du + dv - k);\n \
    \       return -1;\n    }\n\n    /**\n     * @brief u \u304B\u3089 v \u3078\u306E\
    \u30D1\u30B9\u3092\u3001\u5217\u306E\u533A\u9593\u306B\u5206\u3051\u3066 u \u5074\
    \u304B\u3089\u9806\u306B\u4E26\u3079\u308B O(log n)\n     *\n     * \u5404\u8981\
    \u7D20 (a, b) \u306F\u3001\u5217\u306E a \u756A\u76EE\u304B\u3089 b \u756A\u76EE\
    \u307E\u3067 (\u4E21\u7AEF\u3092\u542B\u3080) \u3092\u3001a \u304B\u3089 b \u306E\
    \u5411\u304D\u306B\u305F\u3069\u308B\u3053\u3068\u3092\u8868\u3059\n     * \u5411\
    \u304D\u3092\u8868\u3059\u305F\u3081\u3001\u3053\u306E\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u306E\u4ED6\u306E\u533A\u9593 (\u534A\u958B\u533A\u9593 [l, r)) \u3068\u9055\
    \u3063\u3066\u9589\u533A\u9593\u306B\u306A\u3063\u3066\u3044\u308B\n     * a >\
    \ b \u306A\u3089 index \u304C\u6E1B\u308B\u5411\u304D (\u6839\u306B\u8FD1\u3065\
    \u304F\u5411\u304D) \u306B\u305F\u3069\u308B\n     * \u4EA4\u63DB\u6CD5\u5247\u304C\
    \u6210\u308A\u7ACB\u305F\u306A\u3044\u6F14\u7B97\u3067\u306F\u3001a > b \u306E\
    \u533A\u9593\u306F\u9006\u9806\u306E\u7A4D\u3092\u4F7F\u3046\n     * @param edge\
    \ true \u306A\u3089\u8FBA\u306B\u3064\u3044\u3066\u306E\u30D1\u30B9\u306B\u3059\
    \u308B\u3002\u8FBA (parent(v), v) \u3092 index(v) \u756A\u76EE\u306B\u5BFE\u5FDC\
    \u3055\u305B\u3001lca \u306E\u4F4D\u7F6E\u3092\u542B\u3081\u306A\u3044\n     */\n\
    \    std::vector<std::pair<int, int>> path(int u, int v, bool edge = false) const\
    \ {\n        assert(0 <= u && u < n && 0 <= v && v < n);\n        std::vector<std::pair<int,\
    \ int>> up, down;\n        while (head[u] != head[v]) {\n            if (dep[head[u]]\
    \ >= dep[head[v]]) {\n                up.emplace_back(in[u], in[head[u]]);\n \
    \               u = par[head[u]];\n            } else {\n                down.emplace_back(in[head[v]],\
    \ in[v]);\n                v = par[head[v]];\n            }\n        }\n     \
    \   if (dep[u] >= dep[v]) {\n            // v \u304C lca\n            int l =\
    \ in[v] + edge;\n            if (l <= in[u]) up.emplace_back(in[u], l);\n    \
    \    } else {\n            // u \u304C lca\n            int l = in[u] + edge;\n\
    \            if (l <= in[v]) down.emplace_back(l, in[v]);\n        }\n       \
    \ up.insert(up.end(), down.rbegin(), down.rend());\n        return up;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/heavy-light-decomposition.hpp
  requiredBy: []
  timestamp: '2026-10-14 11:44:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/heavy-light-decomposition.test.cpp
  - test/aoj/grl-5-d.test.cpp
  - test/yosupo/vertex-add-path-sum.test.cpp
  - test/yosupo/vertex-set-path-composite.test.cpp
  - test/yosupo/vertex-add-subtree-sum.2.test.cpp
  - test/yosupo/lca.5.test.cpp
  - test/yosupo/jump-on-tree.2.test.cpp
documentation_of: src/graph/heavy-light-decomposition.hpp
layout: document
title: "HL \u5206\u89E3 (Heavy-Light Decomposition)"
---

木の頂点を一列に並べ替えて、どのパスも $O(\log n)$ 個の区間に、どの部分木も 1 つの区間になるようにします。頂点 `v` は列の `index(v)` 番目に対応します。[セグメント木](../data_structures/segtree.hpp)・[遅延伝搬セグメント木](../data_structures/lazy-segtree.hpp)・[Fenwick Tree](../data_structures/fenwick-tree.hpp) と組み合わせて、パスや部分木への更新とクエリを行います。前計算は $O(n)$ で、DFS は再帰を使いません。

```cpp
HeavyLightDecomposition hld(g, root);  // Graph、Tree、RootedTree から作れる
std::vector<long long> init(n);
for (int v = 0; v < n; v++) init[hld.index(v)] = a[v];
FenwickTree<group::Sum<long long>> ft(init);

ft.apply(hld.index(v), x);             // 頂点 v に x を足す
long long sum = 0;                     // u から v へのパスの和
for (auto [l, r] : hld.path(u, v)) sum += ft.prod(std::min(l, r), std::max(l, r) + 1);
auto [l, r] = hld.subtree(v);          // 部分木の和は ft.prod(l, r)
```

## パスの分解 `path(u, v, edge = false)`

`u` から `v` へのパスを列の区間に分け、`u` 側から順に並べたリストを返します。各要素 `(a, b)` は、列の `a` 番目から `b` 番目まで (両端を含む) を `a` から `b` の向きにたどることを表します。向きを表すため、`subtree` などの半開区間 `[l, r)` と違って **閉区間** です。`a > b` なら index が減る向き、つまり根に近づく向きにたどります。

1 次関数の合成のように交換法則が成り立たない演算では、向きを区別します。index の昇順に適用するセグメント木と、降順に適用するセグメント木の 2 本を用意します。`monoid::Composite` の積は $f \circ g$ ($g$ を先に適用) なので、昇順に適用する側は積の順序を逆にした `monoid::Reverse` を使います。

```cpp
SegTree<monoid::Reverse<monoid::Composite<mint>>> forward(init);
SegTree<monoid::Composite<mint>> backward(init);
for (auto [a, b] : hld.path(u, v)) x = a <= b ? forward.prod(a, b + 1)(x) : backward.prod(b, a + 1)(x);
```

`edge = true` にすると辺についてのパスになります。辺 (`parent(v)`, `v`) の値を `index(v)` 番目に置き、`lca` の位置を含めません。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `HeavyLightDecomposition(tree, root = 0)` | 木 `tree` を根 `root` で分解する。`tree.n` が頂点数で、`for (int u : tree[v])` で隣接する頂点を列挙できればよい | $O(n)$ |
| `index(v)` / `vertex(i)` | 頂点 `v` の列での位置 / 列の `i` 番目の頂点 | $O(1)$ |
| `parent(v)` / `depth(v)` / `subtree_size(v)` | 親 (根は `-1`) / 深さ (辺の本数) / 部分木の頂点数 | $O(1)$ |
| `subtree(v)` | `v` の部分木に対応する区間 `[l, r)` | $O(1)$ |
| `path(u, v, edge = false)` | `u` から `v` へのパスに対応する閉区間 `[a, b]` のリスト (上の説明を参照) | $O(\log n)$ |
| `lca(u, v)` | 最小共通祖先 | $O(\log n)$ |
| `dist(u, v)` | `u` と `v` の間の辺の本数 | $O(\log n)$ |
| `hop(v, k)` | `v` から根の方へ `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |
| `jump(u, v, k)` | `u` から `v` へのパスで、`u` から `k` 本進んだ頂点 (なければ `-1`) | $O(\log n)$ |

## 関連

- LCA やダブリングだけなら [木の汎用テンプレート](tree.hpp) の `DoublingClimbTree`
