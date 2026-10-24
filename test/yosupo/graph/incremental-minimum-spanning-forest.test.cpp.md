---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/link-cut-tree.hpp
    title: Link-Cut Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/incremental_minimum_spanning_forest
    links:
    - https://judge.yosupo.jp/problem/incremental_minimum_spanning_forest
  bundledCode: "#line 1 \"test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/incremental_minimum_spanning_forest\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#line 2 \"src/data_structures/link-cut-tree.hpp\"\n\n/**\n * @file link-cut-tree.hpp\n\
    \ * @brief Link-Cut Tree\n */\n\n#include <cassert>\n#line 11 \"src/data_structures/link-cut-tree.hpp\"\
    \n\n/**\n * @brief Link-Cut Tree (\u68EE\u3067\u3001\u8FBA\u306E\u8FFD\u52A0\u30FB\
    \u524A\u9664\u3068\u30D1\u30B9\u4E0A\u306E\u5024\u306E\u96C6\u7D04\u304C\u3067\
    \u304D\u308B)\n *\n * \u5404\u64CD\u4F5C\u306F\u306A\u3089\u3057 O(log n)\u3002\
    \u5185\u90E8\u306E\u914D\u5217\u306F int \u3067\u6301\u3064\n * \u4F8B:\n * LinkCutTree<monoid::Sum<long\
    \ long>> lct(a);\n * lct.link(0, 1);\n * long long s = lct.prod(0, 1);\n *\n *\
    \ @tparam M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\u3002\u53EF\u63DB\u3067\
    \u306A\u304F\u3066\u3082\u3088\u3044 (prod \u306F u \u304B\u3089 v \u306E\u5411\
    \u304D\u306B\u305F\u305F\u3080)\n */\ntemplate <typename M>\nclass LinkCutTree\
    \ {\n    using S = typename M::S;\n    struct Node {\n        int l = -1, r =\
    \ -1, p = -1;\n        bool rev = false;\n        S val, sum, rsum;  // sum \u306F\
    \u5DE6\u304B\u3089\u53F3\u3001rsum \u306F\u53F3\u304B\u3089\u5DE6\u306B\u305F\u305F\
    \u3093\u3060\u3082\u306E\n    };\n    M m;\n    S op(const S& a, const S& b) const\
    \ { return m.op(a, b); }\n    S e() const { return m.e(); }\n    std::vector<Node>\
    \ t;\n    std::vector<int> stk;\n\n    bool is_root(int x) const {\n        int\
    \ p = t[x].p;\n        return p == -1 || (t[p].l != x && t[p].r != x);\n    }\n\
    \    S sum(int x) const { return x == -1 ? e() : t[x].sum; }\n    S rsum(int x)\
    \ const { return x == -1 ? e() : t[x].rsum; }\n    void update(int x) {\n    \
    \    t[x].sum = op(op(sum(t[x].l), t[x].val), sum(t[x].r));\n        t[x].rsum\
    \ = op(op(rsum(t[x].r), t[x].val), rsum(t[x].l));\n    }\n    void toggle(int\
    \ x) {\n        if (x == -1) return;\n        std::swap(t[x].l, t[x].r);\n   \
    \     std::swap(t[x].sum, t[x].rsum);\n        t[x].rev = !t[x].rev;\n    }\n\
    \    void push(int x) {\n        if (!t[x].rev) return;\n        toggle(t[x].l);\n\
    \        toggle(t[x].r);\n        t[x].rev = false;\n    }\n    void rotate(int\
    \ x) {\n        int p = t[x].p, g = t[p].p;\n        if (t[p].l == x) {\n    \
    \        t[p].l = t[x].r;\n            if (t[x].r != -1) t[t[x].r].p = p;\n  \
    \          t[x].r = p;\n        } else {\n            t[p].r = t[x].l;\n     \
    \       if (t[x].l != -1) t[t[x].l].p = p;\n            t[x].l = p;\n        }\n\
    \        t[p].p = x, t[x].p = g;\n        if (g != -1) {\n            if (t[g].l\
    \ == p) t[g].l = x;\n            if (t[g].r == p) t[g].r = x;\n        }\n   \
    \     update(p), update(x);\n    }\n    void splay(int x) {\n        for (int\
    \ y = x;; y = t[y].p) {\n            stk.push_back(y);\n            if (is_root(y))\
    \ break;\n        }\n        while (!stk.empty()) push(stk.back()), stk.pop_back();\n\
    \        while (!is_root(x)) {\n            int p = t[x].p;\n            if (!is_root(p))\
    \ rotate((t[t[p].p].l == p) == (t[p].l == x) ? p : x);\n            rotate(x);\n\
    \        }\n    }\n    // x \u304B\u3089\u6839\u307E\u3067\u306E\u30D1\u30B9\u3092\
    \ 1 \u672C\u306E splay \u6728\u306B\u3057\u3001x \u3092\u305D\u306E\u6839\u306B\
    \u3059\u308B\u3002\u6700\u5F8C\u306B splay \u3057\u305F\u9802\u70B9\u3092\u8FD4\
    \u3059\n    int access(int x) {\n        int last = -1;\n        for (int y =\
    \ x; y != -1; y = t[y].p) {\n            splay(y);\n            t[y].r = last;\n\
    \            update(y);\n            last = y;\n        }\n        splay(x);\n\
    \        return last;\n    }\n\n   public:\n    /**\n     * @brief \u9802\u70B9\
    \u6570 n\u3001\u8FBA\u306A\u3057\u3001\u5024\u306F\u3059\u3079\u3066\u5358\u4F4D\
    \u5143\n     *\n     * @param m \u30E2\u30CE\u30A4\u30C9\n     */\n    explicit\
    \ LinkCutTree(long long n = 0, M m = M()) : m(std::move(m)) {\n        Node x;\n\
    \        x.val = x.sum = x.rsum = e();\n        t.assign(n, x);\n    }\n    /**\n\
    \     * @brief \u9802\u70B9 i \u306E\u5024\u304C a[i]\u3001\u8FBA\u306A\u3057\n\
    \     */\n    explicit LinkCutTree(const std::vector<S>& a, M m = M()) : LinkCutTree(a.size(),\
    \ std::move(m)) {\n        for (int i = 0; i < static_cast<int>(a.size()); i++)\
    \ t[i].val = t[i].sum = t[i].rsum = a[i];\n    }\n    /**\n     * @brief \u9802\
    \u70B9\u6570\n     */\n    long long size() const { return static_cast<long long>(t.size());\
    \ }\n    /**\n     * @brief v \u3092\u6839\u306B\u3059\u308B\n     */\n    void\
    \ evert(long long v) {\n        access(v);\n        toggle(v);\n        push(v);\n\
    \    }\n    /**\n     * @brief \u8FBA (u, v) \u3092\u8FFD\u52A0\u3059\u308B\u3002\
    u \u3068 v \u306F\u5225\u306E\u6728\u306B\u3042\u308B\u3053\u3068\n     */\n \
    \   void link(long long u, long long v) {\n        assert(!connected(u, v));\n\
    \        evert(u);\n        t[u].p = static_cast<int>(v);\n    }\n    /**\n  \
    \   * @brief \u8FBA (u, v) \u3092\u524A\u9664\u3059\u308B\u3002\u8FBA (u, v) \u304C\
    \u3042\u308B\u3053\u3068\n     */\n    void cut(long long u, long long v) {\n\
    \        evert(u);\n        access(v);\n        assert(t[v].l == u && t[u].r ==\
    \ -1);\n        t[v].l = t[u].p = -1;\n        update(v);\n    }\n    /**\n  \
    \   * @brief v \u3092\u542B\u3080\u6728\u306E\u6839\n     */\n    long long root(long\
    \ long v) {\n        access(v);\n        int x = static_cast<int>(v);\n      \
    \  while (push(x), t[x].l != -1) x = t[x].l;\n        splay(x);\n        return\
    \ x;\n    }\n    /**\n     * @brief u \u3068 v \u304C\u540C\u3058\u6728\u306B\u3042\
    \u308B\u304B\n     */\n    bool connected(long long u, long long v) { return u\
    \ == v || root(u) == root(v); }\n    /**\n     * @brief u \u3068 v \u306E\u6700\
    \u5C0F\u5171\u901A\u7956\u5148 (\u6839\u306F\u6700\u5F8C\u306B evert \u3057\u305F\
    \u9802\u70B9\u306A\u3069\u3001\u4ECA\u306E\u6839)\u3002u \u3068 v \u306F\u540C\
    \u3058\u6728\u306B\u3042\u308B\u3053\u3068\n     */\n    long long lca(long long\
    \ u, long long v) {\n        assert(connected(u, v));\n        access(u);\n  \
    \      return access(v);\n    }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u5024\
    \u3092 x \u306B\u3059\u308B\n     */\n    void set(long long v, const S& x) {\n\
    \        access(v);\n        t[v].val = x;\n        update(v);\n    }\n    /**\n\
    \     * @brief \u9802\u70B9 v \u306E\u5024\n     */\n    S get(long long v) const\
    \ { return t[v].val; }\n    /**\n     * @brief \u9802\u70B9 v \u306E\u5024\u3092\
    \ op(get(v), x) \u306B\u3059\u308B\n     */\n    void apply(long long v, const\
    \ S& x) { set(v, op(t[v].val, x)); }\n    /**\n     * @brief u \u304B\u3089 v\
    \ \u3078\u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9 (\u7AEF\u70B9\u3092\u542B\u3080\
    ) \u306E\u5024\u3092\u3001u \u306E\u5074\u304B\u3089\u9806\u306B\u305F\u305F\u3093\
    \u3060\u3082\u306E\u3002u \u3068 v \u306F\u540C\u3058\u6728\u306B\u3042\u308B\u3053\
    \u3068\n     *\n     * u \u304C\u6839\u306B\u306A\u308B\n     */\n    S prod(long\
    \ long u, long long v) {\n        assert(connected(u, v));\n        evert(u);\n\
    \        access(v);\n        return t[v].sum;\n    }\n};\n\n/**\n * @brief \u90E8\
    \u5206\u6728\u306E\u5024\u306E\u96C6\u7D04\u3082\u3067\u304D\u308B Link-Cut Tree\n\
    \ *\n * \u30D1\u30B9\u306B\u542B\u307E\u308C\u306A\u3044\u5B50\u306E\u90E8\u5206\
    \u6728\u306E\u5024 (virtual) \u3092\u6301\u3064\u3002\u5404\u64CD\u4F5C\u306F\u306A\
    \u3089\u3057 O(log n)\n * \u4F8B:\n * SubtreeLinkCutTree<group::Sum<long long>>\
    \ lct(a);\n * lct.link(0, 1);\n * long long s = lct.subtree_prod(1, 0);  // 0\
    \ \u3092\u89AA\u3068\u3057\u305F\u3068\u304D\u306E 1 \u306E\u90E8\u5206\u6728\u306E\
    \u548C\n *\n * @tparam G \u53EF\u63DB\u306A\u7FA4 (algebra/group.hpp)\n */\n\n\
    template <typename M>\nLinkCutTree(long long, M) -> LinkCutTree<M>;\ntemplate\
    \ <typename M>\nLinkCutTree(std::vector<typename M::S>, M) -> LinkCutTree<M>;\n\
    \ntemplate <typename G>\nclass SubtreeLinkCutTree {\n    using S = typename G::S;\n\
    \    struct Node {\n        int l = -1, r = -1, p = -1;\n        bool rev = false;\n\
    \        S val, path, virt, sum;  // path \u306F\u30D1\u30B9\u4E0A\u3001sum \u306F\
    \ virtual \u3082\u542B\u3081\u305F\u548C\n    };\n    G g;\n    S op(const S&\
    \ a, const S& b) const { return g.op(a, b); }\n    S e() const { return g.e();\
    \ }\n    S inv(const S& a) const { return g.inv(a); }\n    std::vector<Node> t;\n\
    \    std::vector<int> stk;\n\n    bool is_root(int x) const {\n        int p =\
    \ t[x].p;\n        return p == -1 || (t[p].l != x && t[p].r != x);\n    }\n  \
    \  S path(int x) const { return x == -1 ? e() : t[x].path; }\n    S sum(int x)\
    \ const { return x == -1 ? e() : t[x].sum; }\n    void update(int x) {\n     \
    \   t[x].path = op(op(path(t[x].l), t[x].val), path(t[x].r));\n        t[x].sum\
    \ = op(op(sum(t[x].l), op(t[x].val, t[x].virt)), sum(t[x].r));\n    }\n    void\
    \ toggle(int x) {\n        if (x == -1) return;\n        std::swap(t[x].l, t[x].r);\n\
    \        t[x].rev = !t[x].rev;\n    }\n    void push(int x) {\n        if (!t[x].rev)\
    \ return;\n        toggle(t[x].l);\n        toggle(t[x].r);\n        t[x].rev\
    \ = false;\n    }\n    void rotate(int x) {\n        int p = t[x].p, g = t[p].p;\n\
    \        if (t[p].l == x) {\n            t[p].l = t[x].r;\n            if (t[x].r\
    \ != -1) t[t[x].r].p = p;\n            t[x].r = p;\n        } else {\n       \
    \     t[p].r = t[x].l;\n            if (t[x].l != -1) t[t[x].l].p = p;\n     \
    \       t[x].l = p;\n        }\n        t[p].p = x, t[x].p = g;\n        if (g\
    \ != -1) {\n            if (t[g].l == p) t[g].l = x;\n            if (t[g].r ==\
    \ p) t[g].r = x;\n        }\n        update(p), update(x);\n    }\n    void splay(int\
    \ x) {\n        for (int y = x;; y = t[y].p) {\n            stk.push_back(y);\n\
    \            if (is_root(y)) break;\n        }\n        while (!stk.empty()) push(stk.back()),\
    \ stk.pop_back();\n        while (!is_root(x)) {\n            int p = t[x].p;\n\
    \            if (!is_root(p)) rotate((t[t[p].p].l == p) == (t[p].l == x) ? p :\
    \ x);\n            rotate(x);\n        }\n    }\n    int access(int x) {\n   \
    \     int last = -1;\n        for (int y = x; y != -1; y = t[y].p) {\n       \
    \     splay(y);\n            // \u4ECA\u306E\u53F3\u306E\u5B50\u306F virtual \u306B\
    \u306A\u308A\u3001last \u306F virtual \u3067\u306A\u304F\u306A\u308B\n       \
    \     t[y].virt = op(op(t[y].virt, sum(t[y].r)), inv(sum(last)));\n          \
    \  t[y].r = last;\n            update(y);\n            last = y;\n        }\n\
    \        splay(x);\n        return last;\n    }\n\n   public:\n    explicit SubtreeLinkCutTree(long\
    \ long n = 0, G g = G()) : g(std::move(g)) {\n        Node x;\n        x.val =\
    \ x.path = x.virt = x.sum = e();\n        t.assign(n, x);\n    }\n    explicit\
    \ SubtreeLinkCutTree(const std::vector<S>& a, G g = G()) : SubtreeLinkCutTree(a.size(),\
    \ std::move(g)) {\n        for (int i = 0; i < static_cast<int>(a.size()); i++)\
    \ t[i].val = t[i].path = t[i].sum = a[i];\n    }\n    long long size() const {\
    \ return static_cast<long long>(t.size()); }\n    void evert(long long v) {\n\
    \        access(v);\n        toggle(v);\n        push(v);\n    }\n    void link(long\
    \ long u, long long v) {\n        assert(!connected(u, v));\n        evert(u);\n\
    \        access(v);\n        t[u].p = static_cast<int>(v);\n        t[v].virt\
    \ = op(t[v].virt, t[u].sum);\n        update(v);\n    }\n    void cut(long long\
    \ u, long long v) {\n        evert(u);\n        access(v);\n        assert(t[v].l\
    \ == u && t[u].r == -1);\n        t[v].l = t[u].p = -1;\n        update(v);\n\
    \    }\n    long long root(long long v) {\n        access(v);\n        int x =\
    \ static_cast<int>(v);\n        while (push(x), t[x].l != -1) x = t[x].l;\n  \
    \      splay(x);\n        return x;\n    }\n    bool connected(long long u, long\
    \ long v) { return u == v || root(u) == root(v); }\n    long long lca(long long\
    \ u, long long v) {\n        assert(connected(u, v));\n        access(u);\n  \
    \      return access(v);\n    }\n    void set(long long v, const S& x) {\n   \
    \     access(v);\n        t[v].val = x;\n        update(v);\n    }\n    S get(long\
    \ long v) const { return t[v].val; }\n    void apply(long long v, const S& x)\
    \ { set(v, op(t[v].val, x)); }\n    /**\n     * @brief u \u304B\u3089 v \u3078\
    \u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9 (\u7AEF\u70B9\u3092\u542B\u3080) \u306E\
    \u5024\u306E\u548C\u3002u \u3068 v \u306F\u540C\u3058\u6728\u306B\u3042\u308B\u3053\
    \u3068\n     */\n    S prod(long long u, long long v) {\n        assert(connected(u,\
    \ v));\n        evert(u);\n        access(v);\n        return t[v].path;\n   \
    \ }\n    /**\n     * @brief p \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\
    \ v \u306E\u90E8\u5206\u6728\u306E\u5024\u306E\u548C (p == v \u306A\u3089\u6728\
    \u5168\u4F53)\u3002v \u3068 p \u306F\u540C\u3058\u6728\u306B\u3042\u308B\u3053\
    \u3068\n     *\n     * p \u304C\u6839\u306B\u306A\u308B\n     */\n    S subtree_prod(long\
    \ long v, long long p) {\n        assert(connected(v, p));\n        evert(p);\n\
    \        access(v);\n        return op(t[v].val, t[v].virt);\n    }\n};\n\ntemplate\
    \ <typename G>\nSubtreeLinkCutTree(long long, G) -> SubtreeLinkCutTree<G>;\ntemplate\
    \ <typename G>\nSubtreeLinkCutTree(std::vector<typename G::S>, G) -> SubtreeLinkCutTree<G>;\n\
    #line 9 \"test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp\"\n\n\
    // (\u91CD\u307F, \u8FBA\u306E\u756A\u53F7) \u306E\u6700\u5927\u3002\u8FBA\u306E\
    \u306A\u3044\u9802\u70B9\u306F (-1, -1)\nstruct MaxEdge {\n    using S = std::pair<long\
    \ long, int>;\n    static S op(const S& a, const S& b) { return std::max(a, b);\
    \ }\n    static S e() { return {-1, -1}; }\n};\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    // \u9802\u70B9 0..n-1 \u3068\u3001\u8FBA i \u3092\u8868\u3059\u9802\u70B9\
    \ n + i \u3092\u6301\u3061\u3001\u8FBA i \u306F u - (n + i) - v \u3068\u3064\u306A\
    \u3050\n    LinkCutTree<MaxEdge> lct(n + m);\n    std::vector<int> eu(m), ev(m);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        long long w;\n\
    \        std::cin >> u >> v >> w;\n        eu[i] = u, ev[i] = v;\n        lct.set(n\
    \ + i, {w, i});\n        int removed = -1;\n        if (u == v) {\n          \
    \  removed = i;\n        } else if (lct.connected(u, v)) {\n            // u \u3068\
    \ v \u3092\u7D50\u3076\u30D1\u30B9\u4E0A\u306E\u6700\u3082\u91CD\u3044\u8FBA\u3088\
    \u308A\u8EFD\u3051\u308C\u3070\u5165\u308C\u66FF\u3048\u308B\n            auto\
    \ [mw, j] = lct.prod(u, v);\n            if (mw < w) {\n                removed\
    \ = i;\n            } else {\n                lct.cut(eu[j], n + j);\n       \
    \         lct.cut(n + j, ev[j]);\n                removed = j;\n            }\n\
    \        }\n        if (removed != i) {\n            lct.link(u, n + i);\n   \
    \         lct.link(n + i, v);\n        }\n        std::cout << removed << (i +\
    \ 1 < m ? ' ' : '\\n');\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/incremental_minimum_spanning_forest\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <utility>\n#include <vector>\n\
    \n#include \"../../../src/data_structures/link-cut-tree.hpp\"\n\n// (\u91CD\u307F\
    , \u8FBA\u306E\u756A\u53F7) \u306E\u6700\u5927\u3002\u8FBA\u306E\u306A\u3044\u9802\
    \u70B9\u306F (-1, -1)\nstruct MaxEdge {\n    using S = std::pair<long long, int>;\n\
    \    static S op(const S& a, const S& b) { return std::max(a, b); }\n    static\
    \ S e() { return {-1, -1}; }\n};\n\nint main() {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n    int n, m;\n    std::cin >> n >> m;\n\
    \    // \u9802\u70B9 0..n-1 \u3068\u3001\u8FBA i \u3092\u8868\u3059\u9802\u70B9\
    \ n + i \u3092\u6301\u3061\u3001\u8FBA i \u306F u - (n + i) - v \u3068\u3064\u306A\
    \u3050\n    LinkCutTree<MaxEdge> lct(n + m);\n    std::vector<int> eu(m), ev(m);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        long long w;\n\
    \        std::cin >> u >> v >> w;\n        eu[i] = u, ev[i] = v;\n        lct.set(n\
    \ + i, {w, i});\n        int removed = -1;\n        if (u == v) {\n          \
    \  removed = i;\n        } else if (lct.connected(u, v)) {\n            // u \u3068\
    \ v \u3092\u7D50\u3076\u30D1\u30B9\u4E0A\u306E\u6700\u3082\u91CD\u3044\u8FBA\u3088\
    \u308A\u8EFD\u3051\u308C\u3070\u5165\u308C\u66FF\u3048\u308B\n            auto\
    \ [mw, j] = lct.prod(u, v);\n            if (mw < w) {\n                removed\
    \ = i;\n            } else {\n                lct.cut(eu[j], n + j);\n       \
    \         lct.cut(n + j, ev[j]);\n                removed = j;\n            }\n\
    \        }\n        if (removed != i) {\n            lct.link(u, n + i);\n   \
    \         lct.link(n + i, v);\n        }\n        std::cout << removed << (i +\
    \ 1 < m ? ' ' : '\\n');\n    }\n}\n"
  dependsOn:
  - src/data_structures/link-cut-tree.hpp
  isVerificationFile: true
  path: test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp
  requiredBy: []
  timestamp: '2026-10-24 03:58:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp
- /verify/test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp.html
title: test/yosupo/graph/incremental-minimum-spanning-forest.test.cpp
---
