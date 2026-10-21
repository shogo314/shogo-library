---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algebra/group.hpp
    title: "\u7FA4\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/algebra/monoid.hpp
    title: "\u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/link-cut-tree.hpp
    title: Link-Cut Tree
  - icon: ':heavy_check_mark:'
    path: src/math/modint.hpp
    title: "\u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod\
      \ \u3092\u53D6\u308B\u30AF\u30E9\u30B9"
  - icon: ':heavy_check_mark:'
    path: src/utility/traits.hpp
    title: "\u578B\u7279\u6027"
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
  bundledCode: "#line 1 \"test/unittest/data_structures/link-cut-tree.test.cpp\"\n\
    #define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// link-cut-tree.hpp \u306E LinkCutTree \u3068 SubtreeLinkCutTree \u3092\u3001\
    \u68EE\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3067\u611A\u76F4\u306B\u6C42\u3081\
    \u305F\u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// set\
    \ \u3068 apply \u3067\u5024\u3092\u5909\u3048\u308B\u3002LinkCutTree \u306F\u53EF\
    \u63DB\u3067\u306A\u3044\u30E2\u30CE\u30A4\u30C9 (1 \u6B21\u95A2\u6570\u306E\u5408\
    \u6210) \u3067 prod \u306E\u5411\u304D\u3082\u78BA\u304B\u3081\u308B\n// evert\u30FB\
    link\u30FBcut\u30FBprod\u30FBsubtree_prod \u3067\u6839\u304C\u5909\u308F\u308B\
    \u306E\u3067\u3001\u611A\u76F4\u306A\u5074\u3067\u3082\u6839\u3092\u8FFD\u3044\
    \u304B\u3051\u3066 lca\u30FBroot \u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/link-cut-tree.hpp\"\
    \n\n/**\n * @file link-cut-tree.hpp\n * @brief Link-Cut Tree\n */\n\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Link-Cut\
    \ Tree (\u68EE\u3067\u3001\u8FBA\u306E\u8FFD\u52A0\u30FB\u524A\u9664\u3068\u30D1\
    \u30B9\u4E0A\u306E\u5024\u306E\u96C6\u7D04\u304C\u3067\u304D\u308B)\n *\n * \u5404\
    \u64CD\u4F5C\u306F\u306A\u3089\u3057 O(log n)\u3002\u5185\u90E8\u306E\u914D\u5217\
    \u306F int \u3067\u6301\u3064\n * \u4F8B:\n * LinkCutTree<monoid::Sum<long long>>\
    \ lct(a);\n * lct.link(0, 1);\n * long long s = lct.prod(0, 1);\n *\n * @tparam\
    \ M \u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\u3002\u53EF\u63DB\u3067\u306A\
    \u304F\u3066\u3082\u3088\u3044 (prod \u306F u \u304B\u3089 v \u306E\u5411\u304D\
    \u306B\u305F\u305F\u3080)\n */\ntemplate <typename M>\nclass LinkCutTree {\n \
    \   using S = typename M::S;\n    struct Node {\n        int l = -1, r = -1, p\
    \ = -1;\n        bool rev = false;\n        S val, sum, rsum;  // sum \u306F\u5DE6\
    \u304B\u3089\u53F3\u3001rsum \u306F\u53F3\u304B\u3089\u5DE6\u306B\u305F\u305F\u3093\
    \u3060\u3082\u306E\n    };\n    M m;\n    S op(const S& a, const S& b) const {\
    \ return m.op(a, b); }\n    S e() const { return m.e(); }\n    std::vector<Node>\
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
    #line 9 \"test/unittest/data_structures/link-cut-tree.test.cpp\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include <random>\n#line 14 \"test/unittest/data_structures/link-cut-tree.test.cpp\"\
    \n\n#line 2 \"src/algebra/group.hpp\"\n\n/**\n * @file group.hpp\n * @brief \u7FA4\
    \u306E\u5B9A\u7FA9\n *\n * \u7FA4\u306F\u30E2\u30CE\u30A4\u30C9 (algebra/monoid.hpp)\
    \ \u306E\u30E1\u30F3\u30D0\u306B\u52A0\u3048\u3066\u6B21\u306E\u30E1\u30F3\u30D0\
    \u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\u3059\n * - S inv(const S& a):\
    \ \u9006\u5143\n */\n\n#include <array>\n#include <cstddef>\n#line 14 \"src/algebra/group.hpp\"\
    \n\n#line 2 \"src/algebra/monoid.hpp\"\n\n/**\n * @file monoid.hpp\n * @brief\
    \ \u30E2\u30CE\u30A4\u30C9\u306E\u5B9A\u7FA9\n *\n * \u30E2\u30CE\u30A4\u30C9\u306F\
    \u6B21\u306E\u30E1\u30F3\u30D0\u3092\u6301\u3064\u578B\u3068\u3057\u3066\u8868\
    \u3059\n * - using S: \u8981\u7D20\u306E\u578B\n * - S op(const S& a, const S&\
    \ b): \u7A4D (\u7D50\u5408\u7684)\n * - S e(): \u5358\u4F4D\u5143\n * op, e \u306F\
    \ static \u3067\u3082\u975E static \u3067\u3082\u3088\u3044 (\u30C7\u30FC\u30BF\
    \u69CB\u9020\u306F\u30E2\u30CE\u30A4\u30C9\u306E\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\u3092\u4FDD\u6301\u3057\u3066\u547C\u3073\u51FA\u3059)\n */\n\n#line 17\
    \ \"src/algebra/monoid.hpp\"\n#include <istream>\n#include <limits>\n#include\
    \ <numeric>\n#include <optional>\n#include <ostream>\n#include <type_traits>\n\
    #line 24 \"src/algebra/monoid.hpp\"\n\n/**\n * @brief 1\u6B21\u95A2\u6570 f(x)\
    \ = a * x + b\n *\n * monoid::Composite \u306E\u8981\u7D20\u3084 acted_monoid::AffineSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Affine<mint> f{2, 3};\
    \ f(x) \u306F 2x + 3\u3002\u7701\u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF\
    \ {1, 0}\n */\ntemplate <typename T>\nstruct Affine {\n    T a = T(1);  //!< \u50BE\
    \u304D\n    T b = T(0);  //!< \u5207\u7247\n    constexpr T operator()(const T&\
    \ x) const { return a * x + b; }\n    friend constexpr bool operator==(const Affine&\
    \ f, const Affine& g) { return f.a == g.a && f.b == g.b; }\n    friend constexpr\
    \ bool operator!=(const Affine& f, const Affine& g) { return !(f == g); }\n  \
    \  template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Affine& f) {\n  \
    \      return is >> f.a >> f.b;\n    }\n    template <class CharT, class Traits>\n\
    \    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Affine& f) {\n        return os << f.a << CharT(' ') << f.b;\n\
    \    }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 f(x) = min(max(x,\
    \ lb), ub)\n *\n * monoid::ClampComposite \u306E\u8981\u7D20\u3084 acted_monoid::ClampMin\
    \ \u306A\u3069\u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: Clamp<int>\
    \ f{0, 10}; f(x) \u306F x \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\u7565\
    \u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024, \u578B\
    \u306E\u6700\u5927\u5024}\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\
    \u3068\u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057 (\u578B\u306E\u6700\u5C0F\u5024\
    \u30FB\u6700\u5927\u5024) \u306B\u306A\u308B\u3002\u4F8B: Clamp<int>{0, {}} \u306F\
    \ chmax 0\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\u306A\u3089\u306A\u3044\n\
    \ */\ntemplate <typename T>\nstruct Clamp {\n    T lb;  //!< \u4E0B\u9650\n  \
    \  T ub;  //!< \u4E0A\u9650\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr\
    \ Clamp() : lb(std::numeric_limits<T>::lowest()), ub(std::numeric_limits<T>::max())\
    \ {}\n    /// @brief 1 \u3064\u306E\u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\
    \u63DB\u3092\u9632\u3050\u305F\u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\
    \u3059\n    constexpr Clamp(std::optional<T> _lb, std::optional<T> _ub)\n    \
    \    : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()), ub(_ub ? *_ub : std::numeric_limits<T>::max())\
    \ {}\n    constexpr T operator()(const T& x) const { return std::min(std::max(x,\
    \ lb), ub); }\n    friend constexpr bool operator==(const Clamp& f, const Clamp&\
    \ g) { return f.lb == g.lb && f.ub == g.ub; }\n    friend constexpr bool operator!=(const\
    \ Clamp& f, const Clamp& g) { return !(f == g); }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_istream<CharT, Traits>& operator>>(std::basic_istream<CharT,\
    \ Traits>& is, Clamp& f) {\n        return is >> f.lb >> f.ub;\n    }\n    template\
    \ <class CharT, class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Clamp& f) {\n        return os << f.lb << CharT(' ') << f.ub;\n\
    \    }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\u308B\
    \u95A2\u6570 f(x) = min(max(x + add, lb), ub)\n *\n * monoid::ClampAddComposite\
    \ \u306E\u8981\u7D20\u3084 acted_monoid::ClampAddMin\u3001beats_acted_monoid::ChminChmaxAddSum\
    \ \u306E\u4F5C\u7528\u7D20\u306B\u4F7F\u3046\n * \u4F8B: ClampAdd<long long> f{0,\
    \ 10, 3}; f(x) \u306F x + 3 \u3092 [0, 10] \u306B\u53CE\u3081\u308B\u3002\u7701\
    \u7565\u3059\u308B\u3068\u6052\u7B49\u5199\u50CF {\u578B\u306E\u6700\u5C0F\u5024\
    , \u578B\u306E\u6700\u5927\u5024, 0}\n * lb <= ub \u3067\u306A\u3051\u308C\u3070\
    \u306A\u3089\u306A\u3044\u3002lb \u304C\u578B\u306E\u6700\u5C0F\u5024\u3001ub\
    \ \u304C\u578B\u306E\u6700\u5927\u5024\u306E\u3068\u304D\u306F\u3001\u305D\u308C\
    \u305E\u308C\u4E0B\u9650\u30FB\u4E0A\u9650\u304C\u306A\u3044\u3053\u3068\u3092\
    \u8868\u3059\n * lb, ub \u306B {} (std::nullopt) \u3092\u6E21\u3059\u3068\u4E0B\
    \u9650\u30FB\u4E0A\u9650\u306A\u3057\u306B\u306A\u308B\u3002\u4F8B: ClampAdd<long\
    \ long>{{}, {}, 3} \u306F 3 \u3092\u8DB3\u3059\u3001{{}, 5} \u306F chmin 5\n */\n\
    template <typename T>\nstruct ClampAdd {\n    T lb;   //!< \u4E0B\u9650\n    T\
    \ ub;   //!< \u4E0A\u9650\n    T add;  //!< clamp \u306E\u524D\u306B\u8DB3\u3059\
    \u5024\n    /// @brief \u6052\u7B49\u5199\u50CF\n    constexpr ClampAdd() : lb(std::numeric_limits<T>::lowest()),\
    \ ub(std::numeric_limits<T>::max()), add(T(0)) {}\n    /// @brief 1 \u3064\u306E\
    \u5024\u304B\u3089\u306E\u6697\u9ED9\u306E\u5909\u63DB\u3092\u9632\u3050\u305F\
    \u3081\u3001lb \u3068 ub \u306F\u4E21\u65B9\u6E21\u3059\n    constexpr ClampAdd(std::optional<T>\
    \ _lb, std::optional<T> _ub, T _add = T(0))\n        : lb(_lb ? *_lb : std::numeric_limits<T>::lowest()),\
    \ ub(_ub ? *_ub : std::numeric_limits<T>::max()), add(_add) {}\n    constexpr\
    \ T operator()(const T& x) const { return std::min(std::max(x + add, lb), ub);\
    \ }\n    friend constexpr bool operator==(const ClampAdd& f, const ClampAdd& g)\
    \ { return f.lb == g.lb && f.ub == g.ub && f.add == g.add; }\n    friend constexpr\
    \ bool operator!=(const ClampAdd& f, const ClampAdd& g) { return !(f == g); }\n\
    \    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, ClampAdd& f) {\n\
    \        return is >> f.lb >> f.ub >> f.add;\n    }\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const ClampAdd& f) {\n        return os << f.lb << CharT(' ') <<\
    \ f.ub << CharT(' ') << f.add;\n    }\n};\n\nnamespace monoid {\n\n/**\n * @brief\
    \ \u548C\n */\ntemplate <typename T>\nstruct Sum {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return a + b; }\n    static constexpr\
    \ S e() { return S(0); }\n};\n\n/**\n * @brief \u7A4D\n */\ntemplate <typename\
    \ T>\nstruct Prod {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a * b; }\n    static constexpr S e() { return S(1); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5C0F\
    \u5024\n */\ntemplate <typename T>\nstruct Max {\n    using S = T;\n    static\
    \ constexpr S op(const S& a, const S& b) { return std::max(a, b); }\n    static\
    \ constexpr S e() { return std::numeric_limits<S>::lowest(); }\n};\n\n/**\n *\
    \ @brief \u6700\u5C0F\u5024 \u5358\u4F4D\u5143\u306F\u578B\u306E\u6700\u5927\u5024\
    \n */\ntemplate <typename T>\nstruct Min {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return std::min(a, b); }\n    static constexpr\
    \ S e() { return std::numeric_limits<S>::max(); }\n};\n\n/**\n * @brief \u6700\
    \u5C0F\u5024\u3068\u6700\u5927\u5024\u306E\u7D44 {min, max}\n */\ntemplate <typename\
    \ T>\nstruct MinMax {\n    using S = std::pair<T, T>;\n    static constexpr S\
    \ op(const S& a, const S& b) { return {std::min(a.first, b.first), std::max(a.second,\
    \ b.second)}; }\n    static constexpr S e() { return {std::numeric_limits<T>::max(),\
    \ std::numeric_limits<T>::lowest()}; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\
    \u8AD6\u7406\u548C\n */\ntemplate <typename T>\nstruct Xor {\n    using S = T;\n\
    \    static constexpr S op(const S& a, const S& b) { return a ^ b; }\n    static\
    \ constexpr S e() { return S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u7A4D\n\
    \ */\ntemplate <typename T>\nstruct And {\n    using S = T;\n    static constexpr\
    \ S op(const S& a, const S& b) { return a & b; }\n    static constexpr S e() {\
    \ return ~S(0); }\n};\n\n/**\n * @brief \u8AD6\u7406\u548C\n */\ntemplate <typename\
    \ T>\nstruct Or {\n    using S = T;\n    static constexpr S op(const S& a, const\
    \ S& b) { return a | b; }\n    static constexpr S e() { return S(0); }\n};\n\n\
    /**\n * @brief \u6700\u5927\u516C\u7D04\u6570 \u5358\u4F4D\u5143\u306F0\n */\n\
    template <typename T>\nstruct Gcd {\n    static_assert(std::is_integral_v<T>);\n\
    \    using S = T;\n    static constexpr S op(const S& a, const S& b) { return\
    \ std::gcd(a, b); }\n    static constexpr S e() { return S(0); }\n};\n\n/**\n\
    \ * @brief \u6700\u5C0F\u516C\u500D\u6570 \u5358\u4F4D\u5143\u306F1\n */\ntemplate\
    \ <typename T>\nstruct Lcm {\n    static_assert(std::is_integral_v<T>);\n    using\
    \ S = T;\n    static constexpr S op(const S& a, const S& b) { return std::lcm(a,\
    \ b); }\n    static constexpr S e() { return S(1); }\n};\n\n/**\n * @brief {0,\
    \ 1, ..., N-1} \u304B\u3089\u81EA\u5206\u81EA\u8EAB\u3078\u306E\u5199\u50CF\u306E\
    \u5408\u6210 (\u5909\u63DB\u30E2\u30CE\u30A4\u30C9)\n *\n * \u8981\u7D20 f \u306F\
    \ f[x] \u304C x \u306E\u884C\u304D\u5148\u3092\u8868\u3059 std::array<int, N>\u3002\
    \u5168\u5358\u5C04\u3067\u306A\u304F\u3066\u3088\u3044\n * op(f, g) = f\u2218\
    g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\u3002\u533A\u9593 [l, r) \u306E\
    \u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\n * \u5DE6\u304B\u3089\u9806\
    \u306B\u9069\u7528\u3057\u305F\u3044\u5834\u5408\u306F monoid::Reverse<monoid::Mapping<N>>\
    \ \u3092\u4F7F\u3046\n * \u4F8B: SegTree<monoid::Mapping<3>> seg(n); seg.set(i,\
    \ {0, 2, 1});\n * swap(i, j) \u3067 i \u3068 j \u3092\u5165\u308C\u66FF\u3048\u308B\
    \u5199\u50CF\u3092\u4F5C\u308C\u308B\n *\n * @tparam N \u5199\u50CF\u306E\u5B9A\
    \u7FA9\u57DF\u30FB\u5024\u57DF\u306E\u5927\u304D\u3055\n */\ntemplate <std::size_t\
    \ N>\nstruct Mapping {\n    using S = std::array<int, N>;\n    static constexpr\
    \ S op(const S& f, const S& g) {\n        S h{};\n        for (std::size_t x =\
    \ 0; x < N; x++) h[x] = f[g[x]];\n        return h;\n    }\n    static constexpr\
    \ S e() {\n        S h{};\n        for (std::size_t x = 0; x < N; x++) h[x] =\
    \ static_cast<int>(x);\n        return h;\n    }\n    // i \u3068 j \u3092\u5165\
    \u308C\u66FF\u3048\u3001\u307B\u304B\u306F\u52D5\u304B\u3055\u306A\u3044\u5199\
    \u50CF (\u4E92\u63DB)\n    static constexpr S swap(long long i, long long j) {\n\
    \        S h = e();\n        h[i] = static_cast<int>(j);\n        h[j] = static_cast<int>(i);\n\
    \        return h;\n    }\n};\n\n/**\n * @brief 1\u6B21\u95A2\u6570 (Affine) \u306E\
    \u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B\
    )\n * \u533A\u9593 [l, r) \u306E\u7A4D\u306F f_l(...f_{r-1}(x)) \u3092\u8868\u3059\
    \n * \u5DE6\u304B\u3089\u9806\u306B\u9069\u7528\u3057\u305F\u3044 (f_{r-1}(...f_l(x))\
    \ \u3092\u6C42\u3081\u305F\u3044) \u5834\u5408\u306F monoid::Reverse<monoid::Composite<T>>\
    \ \u3092\u4F7F\u3046\n */\ntemplate <typename T>\nstruct Composite {\n    using\
    \ S = Affine<T>;\n    static constexpr S op(const S& f, const S& g) { return {f.a\
    \ * g.a, f.a * g.b + f.b}; }\n    static constexpr S e() { return {T(1), T(0)};\
    \ }\n};\n\n/**\n * @brief clamp \u3059\u308B\u95A2\u6570 (Clamp) \u306E\u5408\u6210\
    \n * op(f, g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n * clamp(clamp(x,\
    \ a, b), c, d) = clamp(x, clamp(a, c, d), clamp(b, c, d)) \u306A\u306E\u3067\u3001\
    \u5408\u6210\u3082 Clamp \u306B\u306A\u308B\n */\ntemplate <typename T>\nstruct\
    \ ClampComposite {\n    using S = Clamp<T>;\n    static constexpr S op(const S&\
    \ f, const S& g) { return {f(g.lb), f(g.ub)}; }\n    static constexpr S e() {\
    \ return {}; }\n};\n\n/**\n * @brief \u8DB3\u3057\u3066\u304B\u3089 clamp \u3059\
    \u308B\u95A2\u6570 (ClampAdd) \u306E\u5408\u6210\n * op(f, g) = f\u2218g (g \u3092\
    \u5148\u306B\u9069\u7528\u3059\u308B)\n * f(g(x)) = clamp(x + g.add + f.add, f(g.lb),\
    \ f(g.ub)) \u306A\u306E\u3067\u3001\u5408\u6210\u3082 ClampAdd \u306B\u306A\u308B\
    \n * \u578B\u306E\u6700\u5C0F\u5024\u30FB\u6700\u5927\u5024\u306E lb\u30FBub \u306F\
    \u4E0B\u9650\u30FB\u4E0A\u9650\u306A\u3057\u3068\u3057\u3066\u6271\u3044\u3001\
    \u8DB3\u3057\u3066\u3082\u3042\u3075\u308C\u306A\u3044\u3088\u3046\u306B\u3059\
    \u308B\n */\ntemplate <typename T>\nstruct ClampAddComposite {\n    using S =\
    \ ClampAdd<T>;\n    static constexpr S op(const S& f, const S& g) {\n        T\
    \ lb = g.lb == std::numeric_limits<T>::lowest() ? f.lb : f(g.lb);\n        T ub\
    \ = g.ub == std::numeric_limits<T>::max() ? f.ub : f(g.ub);\n        return {lb,\
    \ ub, g.add + f.add};\n    }\n    static constexpr S e() { return {}; }\n};\n\n\
    /**\n * @brief \u62EC\u5F27\u5217 \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\u306A\
    \u3044 ')' \u3068 '(' \u306E\u500B\u6570\n */\nstruct Parenthesis {\n    struct\
    \ S {\n        long long close;  // \u5BFE\u5FDC\u306E\u53D6\u308C\u3066\u3044\
    \u306A\u3044 ')' \u306E\u500B\u6570\n        long long open;   // \u5BFE\u5FDC\
    \u306E\u53D6\u308C\u3066\u3044\u306A\u3044 '(' \u306E\u500B\u6570\n        constexpr\
    \ S(char c = 0) : close(c == ')'), open(c == '(') {}\n        constexpr S(long\
    \ long close, long long open) : close(close), open(open) {}\n        /**\n   \
    \      * @brief \u6B63\u3057\u3044\u62EC\u5F27\u5217\u304B\n         */\n    \
    \    constexpr bool is_valid() const { return close == 0 && open == 0; }\n   \
    \ };\n    static constexpr S op(const S& a, const S& b) {\n        if (a.open\
    \ >= b.close) return S(a.close, a.open - b.close + b.open);\n        return S(a.close\
    \ + b.close - a.open, b.open);\n    }\n    static constexpr S e() { return S();\
    \ }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\
    \u3058\u5024\u306A\u3089\u5DE6\u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\
    \u306E\u578B\n * @tparam U \u4F4D\u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\
    \u5024\u306E\u578B\n */\ntemplate <typename T, typename U = long long>\nstruct\
    \ MinWith {\n    using S = std::pair<T, U>;\n    static constexpr S op(const S&\
    \ a, const S& b) { return b.first < a.first ? b : a; }\n    static constexpr S\
    \ e() { return {std::numeric_limits<T>::max(), U{}}; }\n};\n\n/**\n * @brief \u6700\
    \u5927\u5024\u3068\u305D\u306E\u4F4D\u7F6E \u540C\u3058\u5024\u306A\u3089\u5DE6\
    \u5074\u3092\u512A\u5148\n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u4F4D\
    \u7F6E\u306A\u3069\u306E\u4ED8\u968F\u3059\u308B\u5024\u306E\u578B\n */\ntemplate\
    \ <typename T, typename U = long long>\nstruct MaxWith {\n    using S = std::pair<T,\
    \ U>;\n    static constexpr S op(const S& a, const S& b) { return a.first < b.first\
    \ ? b : a; }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U{}}; }\n};\n\n/**\n * @brief \u6700\u5C0F\u5024\u3068\u305D\u306E\u500B\u6570\
    \n *\n * @tparam T \u5024\u306E\u578B\n * @tparam U \u500B\u6570\u306E\u578B\n\
    \ */\ntemplate <typename T, typename U = long long>\nstruct MinCount {\n    using\
    \ S = std::pair<T, U>;\n    static constexpr S op(const S& a, const S& b) {\n\
    \        if (a.first < b.first) return a;\n        if (b.first < a.first) return\
    \ b;\n        return {a.first, a.second + b.second};\n    }\n    static constexpr\
    \ S e() { return {std::numeric_limits<T>::max(), U(0)}; }\n};\n\n/**\n * @brief\
    \ \u6700\u5927\u5024\u3068\u305D\u306E\u500B\u6570\n *\n * @tparam T \u5024\u306E\
    \u578B\n * @tparam U \u500B\u6570\u306E\u578B\n */\ntemplate <typename T, typename\
    \ U = long long>\nstruct MaxCount {\n    using S = std::pair<T, U>;\n    static\
    \ constexpr S op(const S& a, const S& b) {\n        if (a.first < b.first) return\
    \ b;\n        if (b.first < a.first) return a;\n        return {a.first, a.second\
    \ + b.second};\n    }\n    static constexpr S e() { return {std::numeric_limits<T>::lowest(),\
    \ U(0)}; }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\
    \u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024\n * S(x) \u3067\u5024\
    \ x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\
    \u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\n\
    struct PrefixSumMax {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\
    \n        T max;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5927\
    \u5024 (0 \u4EE5\u4E0A)\n        constexpr S() : sum(0), max(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), max(x < T(0) ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& max) : sum(sum), max(max) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.max == b.max;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::max(a.max, a.sum + b.max)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3068\u3001\
    \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x)\
    \ \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\
    \u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate\
    \ <typename T>\nstruct PrefixSumMin {\n    struct S {\n        T sum;  // \u533A\
    \u9593\u306E\u548C\n        T min;  // \u7A7A\u3092\u542B\u3080 prefix \u306E\u548C\
    \u306E\u6700\u5C0F\u5024 (0 \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0)\
    \ {}\n        constexpr S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n\
    \        constexpr S(const T& sum, const T& min) : sum(sum), min(min) {}\n   \
    \     friend constexpr bool operator==(const S& a, const S& b) { return a.sum\
    \ == b.sum && a.min == b.min; }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) { return S(a.sum + b.sum, std::min(a.min, a.sum + b.min));\
    \ }\n    static constexpr S e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\
    \u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMax {\n    struct S {\n\
    \        T sum;  // \u533A\u9593\u306E\u548C\n        T max;  // \u7A7A\u3092\u542B\
    \u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        constexpr\
    \ S() : sum(0), max(0) {}\n        constexpr S(const T& x) : sum(x), max(x < T(0)\
    \ ? T(0) : x) {}\n        constexpr S(const T& sum, const T& max) : sum(sum),\
    \ max(max) {}\n        friend constexpr bool operator==(const S& a, const S& b)\
    \ { return a.sum == b.sum && a.max == b.max; }\n        friend constexpr bool\
    \ operator!=(const S& a, const S& b) { return !(a == b); }\n    };\n    static\
    \ constexpr S op(const S& a, const S& b) { return S(a.sum + b.sum, std::max(b.max,\
    \ a.max + b.sum)); }\n    static constexpr S e() { return S(); }\n};\n\n/**\n\
    \ * @brief \u533A\u9593\u306E\u548C\u3068\u3001\u7A7A\u3092\u542B\u3080 suffix\
    \ \u306E\u548C\u306E\u6700\u5C0F\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\
    \u3092\u8868\u3059\u8981\u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\
    \u7A7A\u306E\u533A\u9593 {0, 0}\n */\ntemplate <typename T>\nstruct SuffixSumMin\
    \ {\n    struct S {\n        T sum;  // \u533A\u9593\u306E\u548C\n        T min;\
    \  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5C0F\u5024 (0\
    \ \u4EE5\u4E0B)\n        constexpr S() : sum(0), min(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), min(T(0) < x ? T(0) : x) {}\n        constexpr S(const\
    \ T& sum, const T& min) : sum(sum), min(min) {}\n        friend constexpr bool\
    \ operator==(const S& a, const S& b) { return a.sum == b.sum && a.min == b.min;\
    \ }\n        friend constexpr bool operator!=(const S& a, const S& b) { return\
    \ !(a == b); }\n    };\n    static constexpr S op(const S& a, const S& b) { return\
    \ S(a.sum + b.sum, std::min(b.min, a.min + b.sum)); }\n    static constexpr S\
    \ e() { return S(); }\n};\n\n/**\n * @brief \u533A\u9593\u306E\u548C\u3001\u7A7A\
    \u3092\u542B\u3080 prefix\u30FBsuffix \u306E\u548C\u306E\u6700\u5927\u5024\u3001\
    \u7A7A\u3092\u542B\u3080\u9023\u7D9A\u90E8\u5206\u5217\u306E\u548C\u306E\u6700\
    \u5927\u5024\n * S(x) \u3067\u5024 x \u306E1\u8981\u7D20\u3092\u8868\u3059\u8981\
    \u7D20\u3092\u4F5C\u308B\u3002\u5358\u4F4D\u5143\u306F\u7A7A\u306E\u533A\u9593\
    \ {0, 0, 0, 0}\n * \u9759\u7684\u306A\u5217\u306B\u5BFE\u3057\u3066\u4E00\u5EA6\
    \u3060\u3051\u6C42\u3081\u308B\u306A\u3089 dp/maximum-subarray.hpp \u306E maximum_subarray\n\
    \ */\ntemplate <typename T>\nstruct MaxSubarraySum {\n    struct S {\n       \
    \ T sum;     // \u533A\u9593\u306E\u548C\n        T prefix;  // \u7A7A\u3092\u542B\
    \u3080 prefix \u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n        T\
    \ suffix;  // \u7A7A\u3092\u542B\u3080 suffix \u306E\u548C\u306E\u6700\u5927\u5024\
    \ (0 \u4EE5\u4E0A)\n        T best;    // \u7A7A\u3092\u542B\u3080\u9023\u7D9A\
    \u90E8\u5206\u5217\u306E\u548C\u306E\u6700\u5927\u5024 (0 \u4EE5\u4E0A)\n    \
    \    constexpr S() : sum(0), prefix(0), suffix(0), best(0) {}\n        constexpr\
    \ S(const T& x) : sum(x), prefix(x < T(0) ? T(0) : x), suffix(prefix), best(prefix)\
    \ {}\n        constexpr S(const T& sum, const T& prefix, const T& suffix, const\
    \ T& best)\n            : sum(sum), prefix(prefix), suffix(suffix), best(best)\
    \ {}\n        friend constexpr bool operator==(const S& a, const S& b) {\n   \
    \         return a.sum == b.sum && a.prefix == b.prefix && a.suffix == b.suffix\
    \ && a.best == b.best;\n        }\n        friend constexpr bool operator!=(const\
    \ S& a, const S& b) { return !(a == b); }\n    };\n    static constexpr S op(const\
    \ S& a, const S& b) {\n        return S(a.sum + b.sum, std::max(a.prefix, a.sum\
    \ + b.prefix), std::max(b.suffix, a.suffix + b.sum),\n                 std::max({a.best,\
    \ b.best, a.suffix + b.prefix}));\n    }\n    static constexpr S e() { return\
    \ S(); }\n};\n\n/**\n * @brief \u7A4D\u306E\u9806\u5E8F\u3092\u9006\u306B\u3057\
    \u305F\u30E2\u30CE\u30A4\u30C9 op(a, b) = M::op(b, a)\n *\n * \u4F8B: SegTree<monoid::Reverse<monoid::Composite<mint>>>\
    \ seg(v); \u306E\u533A\u9593 [l, r) \u306E\u7A4D\u306F f_{r-1}(...f_l(x))\n *\n\
    \ * @tparam M \u3082\u3068\u306E\u30E2\u30CE\u30A4\u30C9\n */\ntemplate <typename\
    \ M>\nstruct Reverse {\n    using S = typename M::S;\n    M m;\n    constexpr\
    \ Reverse() : m() {}\n    constexpr explicit Reverse(M m) : m(std::move(m)) {}\n\
    \    constexpr S op(const S& a, const S& b) const { return m.op(b, a); }\n   \
    \ constexpr S e() const { return m.e(); }\n};\n\n}  // namespace monoid\n\n/**\n\
    \ * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u3068\u5358\u4F4D\u5143\
    \u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\u308B\u30E2\u30CE\u30A4\u30C9\n * \u30E9\
    \u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * \u4F8B: SegTree seg(v, Monoid([](int\
    \ a, int b) { return std::max(a, b); }, -1));\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\
    \u306E\u578B\n */\ntemplate <typename T, typename Op>\nstruct Monoid {\n    using\
    \ S = T;\n    Op op_object;\n    S identity;\n    Monoid() = default;\n    constexpr\
    \ Monoid(Op op, const S& e) : op_object(std::move(op)), identity(e) {}\n    constexpr\
    \ S op(const S& a, const S& b) const { return op_object(a, b); }\n    constexpr\
    \ S e() const { return identity; }\n};\ntemplate <typename Op, typename T>\nMonoid(Op,\
    \ T) -> Monoid<T, Op>;\n#line 16 \"src/algebra/group.hpp\"\n\nnamespace group\
    \ {\n\n/**\n * @brief \u52A0\u6CD5\u7FA4\n */\ntemplate <typename T>\nstruct Sum\
    \ : monoid::Sum<T> {\n    using S = T;\n    static constexpr S inv(const S& a)\
    \ { return -a; }\n};\n\n/**\n * @brief \u4E57\u6CD5\u7FA4 (0\u3092\u542B\u307E\
    \u306A\u3044\u4F53\u306E\u5143\u306A\u3069)\n */\ntemplate <typename T>\nstruct\
    \ Prod : monoid::Prod<T> {\n    using S = T;\n    static constexpr S inv(const\
    \ S& a) { return S(1) / a; }\n};\n\n/**\n * @brief \u6392\u4ED6\u7684\u8AD6\u7406\
    \u548C\n */\ntemplate <typename T>\nstruct Xor : monoid::Xor<T> {\n    using S\
    \ = T;\n    static constexpr S inv(const S& a) { return a; }\n};\n\n/**\n * @brief\
    \ {0, 1, ..., N-1} \u306E\u7F6E\u63DB (\u5168\u5358\u5C04) \u306E\u5408\u6210\n\
    \ *\n * monoid::Mapping<N> \u306B\u9006\u7F6E\u63DB\u3092\u52A0\u3048\u305F\u3082\
    \u306E\u3002\u8981\u7D20\u306F\u7F6E\u63DB\u3067\u3042\u308B\u3053\u3068\n * op(f,\
    \ g) = f\u2218g (g \u3092\u5148\u306B\u9069\u7528\u3059\u308B)\n *\n * @tparam\
    \ N \u7F6E\u63DB\u3059\u308B\u8981\u7D20\u306E\u500B\u6570\n */\ntemplate <std::size_t\
    \ N>\nstruct Permutation : monoid::Mapping<N> {\n    using S = std::array<int,\
    \ N>;\n    static constexpr S inv(const S& f) {\n        S h{};\n        for (std::size_t\
    \ x = 0; x < N; x++) h[f[x]] = static_cast<int>(x);\n        return h;\n    }\n\
    };\n\n}  // namespace group\n\n/**\n * @brief \u95A2\u6570\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\u3068\u5358\u4F4D\u5143\u304B\u3089\u5B9F\u884C\u6642\u306B\u4F5C\
    \u308B\u7FA4\n * \u30E9\u30E0\u30C0\u5F0F\u3092\u4F7F\u3048\u308B\n *\n * @tparam\
    \ T \u8981\u7D20\u306E\u578B\n * @tparam Op \u7A4D\u306E\u95A2\u6570\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u306E\u578B\n * @tparam Inv \u9006\u5143\u306E\u95A2\u6570\
    \u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\u306E\u578B\n */\ntemplate <typename T, typename\
    \ Op, typename Inv>\nstruct Group {\n    using S = T;\n    Op op_object;\n   \
    \ S identity;\n    Inv inv_object;\n    Group() = default;\n    constexpr Group(Op\
    \ op, const S& e, Inv inv) : op_object(std::move(op)), identity(e), inv_object(std::move(inv))\
    \ {}\n    constexpr S op(const S& a, const S& b) const { return op_object(a, b);\
    \ }\n    constexpr S e() const { return identity; }\n    constexpr S inv(const\
    \ S& a) const { return inv_object(a); }\n};\ntemplate <typename Op, typename T,\
    \ typename Inv>\nGroup(Op, T, Inv) -> Group<T, Op, Inv>;\n#line 2 \"src/math/modint.hpp\"\
    \n\n/**\n * @file modint.hpp\n * @brief \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\
    \u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\u30E9\u30B9\n */\n\n#line\
    \ 9 \"src/math/modint.hpp\"\n#include <cstdint>\n#line 14 \"src/math/modint.hpp\"\
    \n\n#line 2 \"src/utility/traits.hpp\"\n\n/**\n * @file traits.hpp\n * @brief\
    \ \u578B\u7279\u6027\n */\n\n#line 9 \"src/utility/traits.hpp\"\n#include <iterator>\n\
    #include <set>\n#line 13 \"src/utility/traits.hpp\"\n\nnamespace internal_traits\
    \ {\nusing std::begin, std::end;\n\ntemplate <class T, class = void>\nstruct is_range_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_range_impl<T, std::void_t<decltype(begin(std::declval<T&>()),\
    \ end(std::declval<T&>()))>> : std::true_type {};\n}  // namespace internal_traits\n\
    \ntemplate <class T>\nstruct is_range : internal_traits::is_range_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_range_v = is_range<T>::value;\n\
    \n#define HAS_METHOD(func_name)                                              \
    \                \\\n    namespace internal_traits {                         \
    \                                   \\\n    template <class T, class = void> \
    \                                                      \\\n    struct has_##func_name##_impl\
    \ : std::false_type {};                                    \\\n    template <class\
    \ T>                                                                     \\\n\
    \    struct has_##func_name##_impl<T, std::void_t<decltype(std::declval<T>().func_name())>>\
    \ \\\n        : std::true_type {};                                           \
    \                    \\\n    }                                               \
    \                                       \\\n    template <class T>           \
    \                                                          \\\n    struct has_##func_name\
    \ : internal_traits::has_##func_name##_impl<T>::type {};          \\\n    template\
    \ <class T>                                                                  \
    \   \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T>::value;\n\
    \n#define HAS_METHOD_ARG(func_name)                                          \
    \                                    \\\n    namespace internal_traits {     \
    \                                                                           \\\
    \n    template <class T, typename U, class = void>                           \
    \                                    \\\n    struct has_##func_name##_impl : std::false_type\
    \ {};                                                        \\\n    template\
    \ <class T, typename U>                                                      \
    \                       \\\n    struct has_##func_name##_impl<T, U, std::void_t<decltype(std::declval<T>().func_name(std::declval<U>()))>>\
    \ \\\n        : std::true_type {};                                           \
    \                                        \\\n    }                           \
    \                                                                            \
    \   \\\n    template <class T, typename U>                                   \
    \                                          \\\n    struct has_##func_name : internal_traits::has_##func_name##_impl<T,\
    \ U>::type {};                           \\\n    template <class T, typename U>\
    \                                                                            \
    \ \\\n    inline constexpr bool has_##func_name##_v = has_##func_name<T, U>::value;\n\
    \nHAS_METHOD(repr)\nHAS_METHOD(type_str)\nHAS_METHOD(initializer_str)\nHAS_METHOD(max)\n\
    HAS_METHOD(min)\nHAS_METHOD(reversed)\nHAS_METHOD(sorted)\nHAS_METHOD(sum)\nHAS_METHOD(product)\n\
    HAS_METHOD(product_xor)\nHAS_METHOD_ARG(count)\nHAS_METHOD_ARG(find)\nHAS_METHOD_ARG(lower_bound)\n\
    HAS_METHOD_ARG(upper_bound)\n\n#define ENABLE_IF_T_IMPL(expr) std::enable_if_t<expr,\
    \ std::nullptr_t> = nullptr\n#define ENABLE_IF_T(...) ENABLE_IF_T_IMPL((__VA_ARGS__))\n\
    \ntemplate <class C>\nusing mem_value_type = typename C::value_type;\ntemplate\
    \ <class C>\nusing mem_difference_type = typename C::difference_type;\n\nnamespace\
    \ internal_traits {\ntemplate <class T, class = void>\nstruct is_sorted_container_impl\
    \ : std::false_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::set<T>>\
    \ : std::true_type {};\ntemplate <class T>\nstruct is_sorted_container_impl<std::multiset<T>>\
    \ : std::true_type {};\n}  // namespace internal_traits\ntemplate <class T>\n\
    struct is_sorted_container : internal_traits::is_sorted_container_impl<T>::type\
    \ {};\ntemplate <class T>\ninline constexpr bool is_sorted_container_v = is_sorted_container<T>::value;\n\
    #line 16 \"src/math/modint.hpp\"\n\nnamespace internal_modint {\n// clang-format\
    \ off\nstatic constexpr std::uint16_t prime32_bases[] {\n    15591,  2018,  166,\
    \ 7429,  8064, 16045, 10503,  4399,  1949,  1295, 2776,  3620,   560,  3128, \
    \ 5212,  2657,\n     2300,  2021, 4652, 1471,  9336,  4018,  2398, 20462, 10277,\
    \  8028, 2213,  6219,   620,  3763,  4852,  5012,\n     3185,  1333, 6227, 5298,\
    \  1074,  2391,  5113,  7061,   803,  1269, 3875,   422,   751,   580,  4729,\
    \ 10239,\n      746,  2951,  556, 2206,  3778,   481,  1522,  3476,   481,  2487,\
    \ 3266,  5633,   488,  3373,  6441,  3344,\n       17, 15105, 1490, 4154,  2036,\
    \  1882,  1813,   467,  3307, 14042, 6371,   658,  1005,   903,   737,  1887,\n\
    \     7447,  1888, 2848, 1784,  7559,  3400,   951, 13969,  4304,   177,   41,\
    \ 19875,  3110, 13221,  8726,   571,\n     7043,  6943, 1199,  352,  6435,   165,\
    \  1169,  3315,   978,   233, 3003,  2562,  2994, 10587, 10030,  2377,\n     1902,\
    \  5354, 4447, 1555,   263, 27027,  2283,   305,   669,  1912,  601,  6186,  \
    \ 429,  1930, 14873,  1784,\n     1661,   524, 3577,  236,  2360,  6146,  2850,\
    \ 55637,  1753,  4178, 8466,   222,  2579,  2743,  2031,  2226,\n     2276,  \
    \ 374, 2132,  813, 23788,  1610,  4422,  5159,  1725,  3597, 3366, 14336,   579,\
    \   165,  1375, 10018,\n    12616,  9816, 1371,  536,  1867, 10864,   857,  2206,\
    \  5788,   434, 8085, 17618,   727,  3639,  1595,  4944,\n     2129,  2029, 8195,\
    \ 8344,  6232,  9183,  8126,  1870,  3296,  7455, 8947, 25017,   541, 19115, \
    \  368,   566,\n     5674,   411,  522, 1027,  8215,  2050,  6544, 10049,   614,\
    \   774, 2333,  3007, 35201,  4706,  1152,  1785,\n     1028,  1540, 3743,  493,\
    \  4474,  2521, 26845,  8354,   864, 18915, 5465,  2447,    42,  4511,  1660,\
    \   166,\n     1249,  6259, 2553,  304,   272,  7286,    73,  6554,   899,  2816,\
    \ 5197, 13330,  7054,  2818,  3199,   811,\n      922,   350, 7514, 4452,  3449,\
    \  2663,  4708,   418,  1621,  1171, 3471,    88, 11345,   412,  1559,   194,\n\
    };\n// clang-format on\n\nstatic constexpr bool is_SPRP(std::uint32_t n, std::uint32_t\
    \ a) noexcept {\n    std::uint32_t d = n - 1;\n    std::uint32_t s = 0;\n    while\
    \ ((d & 1) == 0) {\n        ++s;\n        d >>= 1;\n    }\n    std::uint64_t cur\
    \ = 1;\n    std::uint64_t pw = d;\n    while (pw) {\n        if (pw & 1) cur =\
    \ (cur * a) % n;\n        a = (static_cast<std::uint64_t>(a) * a) % n;\n     \
    \   pw >>= 1;\n    }\n    if (cur == 1) return true;\n    for (std::uint32_t r\
    \ = 0; r < s; ++r) {\n        if (cur == n - 1) return true;\n        cur = (cur\
    \ * cur) % n;\n    }\n    return false;\n}\n\n// 32\u30D3\u30C3\u30C8\u7B26\u53F7\
    \u306A\u3057\u6574\u6570\u306E\u7D20\u6570\u5224\u5B9A\n// \u53C2\u8003: M. Forisek\
    \ and J. Jancina, \u201CFast Primality Testing for Integers That Fit into a Machine\
    \ Word,\u201D presented at the Conference on Current Trends in Theory and Practice\
    \ of Informatics, 2015.\n[[nodiscard]]\nstatic constexpr bool is_prime32(std::uint32_t\
    \ x) noexcept {\n    if (x == 2 || x == 3 || x == 5 || x == 7) return true;\n\
    \    if (x % 2 == 0 || x % 3 == 0 || x % 5 == 0 || x % 7 == 0) return false;\n\
    \    if (x < 121) return (x > 1);\n    std::uint64_t h = x;\n    h = ((h >> 16)\
    \ ^ h) * 0x45d9f3b;\n    h = ((h >> 16) ^ h) * 0x45d9f3b;\n    h = ((h >> 16)\
    \ ^ h) & 0xff;\n    return is_SPRP(x, prime32_bases[h]);\n}\n}  // namespace internal_modint\n\
    \n/// @brief static_modint \u3068 dynamic_modint \u306E\u5B9F\u88C5\u3092 CRTP\
    \ \u306B\u3088\u3063\u3066\u884C\u3046\u305F\u3081\u306E\u30AF\u30E9\u30B9\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\n/// @tparam Modint \u3053\u306E\u30AF\u30E9\u30B9\
    \u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\u3092\u7D99\u627F\u3059\u308B\u30AF\u30E9\
    \u30B9\ntemplate <class Modint>\nclass modint_base {\n   public:\n    /// @brief\
    \ \u4FDD\u6301\u3059\u308B\u5024\u306E\u578B\n    using value_type = std::uint32_t;\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ modint_base() noexcept\n        : m_value{0} {}\n\n    /// @brief @c value \u306E\
    \u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value\
    \ \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral,\
    \ ENABLE_IF_T((std::is_integral_v<SignedIntegral> && std::is_signed_v<SignedIntegral>))>\n\
    \    constexpr modint_base(SignedIntegral value) noexcept\n        : m_value{static_cast<value_type>((static_cast<long\
    \ long>(value) % Modint::mod() + Modint::mod()) % Modint::mod())} {}\n\n    ///\
    \ @brief @c value \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\
    \u3002\n    /// @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template\
    \ <class UnsignedIntegral, ENABLE_IF_T((std::is_integral_v<UnsignedIntegral> &&\
    \ std::is_unsigned_v<UnsignedIntegral>))>\n    constexpr modint_base(UnsignedIntegral\
    \ value) noexcept\n        : m_value{static_cast<value_type>(value % Modint::mod())}\
    \ {}\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092\u53D6\u5F97\
    \u3057\u307E\u3059\u3002\n    /// @return \u4FDD\u6301\u3057\u3066\u3044\u308B\
    \u5024\n    [[nodiscard]]\n    constexpr value_type val() const noexcept {\n \
    \       return m_value;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\
    \u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\u3001\
    \u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n \
    \   constexpr Modint& operator++() noexcept {\n        ++m_value;\n        if\
    \ (m_value == Modint::mod()) {\n            m_value = 0;\n        }\n        return\
    \ static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\
    \u3044\u308B\u5024\u3092\u30A4\u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30A4\
    \u30F3\u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr\
    \ Modint operator++(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        ++*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return @c *this\n\
    \    constexpr Modint& operator--() noexcept {\n        if (m_value == 0) {\n\
    \            m_value = Modint::mod();\n        }\n        --m_value;\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u3092\u30C7\u30AF\u30EA\u30E1\u30F3\u30C8\u3057\u3066\
    \u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @return \u30C7\
    \u30AF\u30EA\u30E1\u30F3\u30C8\u3059\u308B\u524D\u306E\u5024\n    constexpr Modint\
    \ operator--(int) noexcept {\n        auto x = static_cast<const Modint&>(*this);\n\
    \        --*this;\n        return x;\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u8DB3\u3057\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3059\u6570\n    /// @return @c *this\n    constexpr Modint& operator+=(const\
    \ Modint& x) noexcept {\n        m_value += x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value -= Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u304B\u3089 @c x \u306E\u6301\u3064\u5024\u3092\u5F15\
    \u3044\u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304F\u6570\n    /// @return @c *this\n    constexpr Modint& operator-=(const\
    \ Modint& x) noexcept {\n        m_value -= x.m_value;\n        if (m_value >=\
    \ Modint::mod()) {\n            m_value += Modint::mod();\n        }\n       \
    \ return static_cast<Modint&>(*this);\n    }\n\n    /// @brief \u4FDD\u6301\u3057\
    \u3066\u3044\u308B\u5024\u306B @c x \u306E\u6301\u3064\u5024\u3092\u639B\u3051\
    \u3066\u3001\u5270\u4F59\u3092\u53D6\u308A\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u308B\u6570\n    /// @return @c *this\n    constexpr Modint& operator*=(const\
    \ Modint& x) noexcept {\n        m_value = static_cast<value_type>(static_cast<std::uint64_t>(m_value)\
    \ * x.m_value % Modint::mod());\n        return static_cast<Modint&>(*this);\n\
    \    }\n\n    /// @brief \u4FDD\u6301\u3057\u3066\u3044\u308B\u5024\u3092 @c x\
    \ \u306E\u6301\u3064\u5024\u3067\u5272\u3063\u3066\u3001\u5270\u4F59\u3092\u53D6\
    \u308A\u307E\u3059\u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A\
    \ @f$O(\\log x)@f$\n    /// @param x \u5272\u308B\u6570\n    /// @return @c *this\n\
    \    constexpr Modint& operator/=(const Modint& x) noexcept {\n        return\
    \ *this *= x.inv();\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u30B3\u30D4\u30FC\
    \u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @return @c *this\n    [[nodiscard]]\n\
    \    constexpr Modint operator+() const noexcept {\n        return static_cast<const\
    \ Modint&>(*this);\n    }\n\n    /// @brief \u81EA\u8EAB\u306E\u53CD\u6570\u3092\
    \u8FD4\u3057\u307E\u3059\u3002\n    /// @return \u81EA\u8EAB\u306E\u53CD\u6570\
    \n    [[nodiscard]]\n    constexpr Modint operator-() const noexcept {\n     \
    \   return 0 - static_cast<const Modint&>(*this);\n    }\n\n    /// @brief \u81EA\
    \u8EAB\u306E @c n \u4E57\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @remark\
    \ \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log n)@f$\n    /// @param n \u6307\
    \u6570\n    /// @return \u81EA\u8EAB\u306E @c n \u4E57\n    [[nodiscard]]\n  \
    \  constexpr Modint pow(unsigned long long n) const noexcept {\n        Modint\
    \ x = 1;\n        Modint y = static_cast<const Modint&>(*this);\n        while\
    \ (n) {\n            if (n & 1) {\n                x *= y;\n            }\n  \
    \          y *= y;\n            n >>= 1;\n        }\n        return x;\n    }\n\
    \n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\u3002\
    \n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ Modint inv() const noexcept {\n        long long a = Modint::mod();\n      \
    \  long long b = m_value;\n        long long x = 0;\n        long long y = 1;\n\
    \        while (b) {\n            auto t = a / b;\n            auto u = a - t\
    \ * b;\n            a = b;\n            b = u;\n            u = x - t * y;\n \
    \           x = y;\n            y = u;\n        }\n        assert(a == 1 && \"\
    The inverse element does not exist.\");\n        x %= Modint::mod();\n       \
    \ if (x < 0) {\n            x += Modint::mod();\n        }\n        return x;\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u8DB3\u3055\u308C\u308B\u6570\n    /// @param y \u8DB3\u3059\u6570\n    ///\
    \ @return @c x \u306B @c y \u3092\u8DB3\u3057\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator+(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} += y);\n\
    \    }\n\n    /// @brief @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\
    \u30D6\u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param\
    \ x \u5F15\u304B\u308C\u308B\u6570\n    /// @param y \u5F15\u304F\u6570\n    ///\
    \ @return @c x \u304B\u3089 @c y \u3092\u5F15\u3044\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator-(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} -= y);\n\
    \    }\n\n    /// @brief @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u639B\u3051\u3089\u308C\u308B\u6570\n    /// @param y \u639B\u3051\u308B\u6570\
    \n    /// @return @c x \u306B @c y \u3092\u639B\u3051\u305F\u30AA\u30D6\u30B8\u30A7\
    \u30AF\u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator*(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} *= y);\n\
    \    }\n\n    /// @brief @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param x\
    \ \u5272\u3089\u308C\u308B\u6570\n    /// @param y \u5272\u308B\u6570\n    ///\
    \ @return @c x \u3092 @c y \u3067\u5272\u3063\u305F\u30AA\u30D6\u30B8\u30A7\u30AF\
    \u30C8\n    [[nodiscard]]\n    friend constexpr Modint operator/(const Modint&\
    \ x, const Modint& y) noexcept {\n        return std::move(Modint{x} /= y);\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\u307E\u3059\
    \u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\u304C\
    \u7B49\u3057\u3051\u308C\u3070 @c true \u3001\u305D\u3046\u3067\u306A\u3051\u308C\
    \u3070 @c false\n    [[nodiscard]]\n    friend constexpr bool operator==(const\
    \ Modint& x, const Modint& y) noexcept {\n        return x.m_value == y.m_value;\n\
    \    }\n\n    /// @brief @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\u5024\
    \u304C\u7B49\u3057\u304F\u306A\u3044\u304B\u3069\u3046\u304B\u3092\u8ABF\u3079\
    \u307E\u3059\u3002\n    /// @return @c x \u3068 @c y \u306E\u4FDD\u6301\u3059\u308B\
    \u5024\u304C\u7B49\u3057\u3051\u308C\u3070 @c false \u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070 @c true\n    [[nodiscard]]\n    friend constexpr bool operator!=(const\
    \ Modint& x, const Modint& y) noexcept {\n        return !(x == y);\n    }\n\n\
    \    /// @brief \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u304B\u3089\u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u3092\u8AAD\u307F\u53D6\u308A\u3001 @c x \u306B\u683C\
    \u7D0D\u3057\u307E\u3059\u3002\n    /// @tparam CharT \u5165\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n    /// @tparam Traits \u5165\u529B\
    \u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n   \
    \ /// @param is \u5165\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n    /// @param x \u5165\
    \u529B\u3092\u53D7\u3051\u53D6\u308B\u30AA\u30D6\u30B8\u30A7\u30AF\u30C8\n   \
    \ /// @return @c is\n    template <class CharT, class Traits>\n    friend std::basic_istream<CharT,\
    \ Traits>& operator>>(std::basic_istream<CharT, Traits>& is, Modint& x) {\n  \
    \      long long tmp;\n        is >> tmp;\n        x = tmp;\n        return is;\n\
    \    }\n\n    /// @brief \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306B @c x\
    \ \u306E\u4FDD\u6301\u3059\u308B\u5024\u3092\u51FA\u529B\u3057\u307E\u3059\u3002\
    \n    /// @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\
    \u5B57\u578B\n    /// @tparam Traits \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\
    \u306E\u6587\u5B57\u30C8\u30EC\u30A4\u30C8\n    /// @param os \u51FA\u529B\u30B9\
    \u30C8\u30EA\u30FC\u30E0\n    /// @param x \u51FA\u529B\u3059\u308B\u30AA\u30D6\
    \u30B8\u30A7\u30AF\u30C8\n    /// @return @c os\n    template <class CharT, class\
    \ Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const Modint& x) {\n        os << x.val();\n        return os;\n\
    \    }\n\n   protected:\n    value_type m_value;\n};\n\n/// @brief \u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\
    \u56DB\u5247\u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\
    \u308B\u30AF\u30E9\u30B9\n/// @tparam Mod \u6CD5\ntemplate <std::uint32_t Mod>\n\
    class static_modint : public modint_base<static_modint<Mod>> {\n    static_assert(Mod\
    \ > 0 && Mod <= std::numeric_limits<std::uint32_t>::max() / 2);\n\n   private:\n\
    \    using base_type = modint_base<static_modint<Mod>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static constexpr\
    \ value_type mod() noexcept {\n        return Mod;\n    }\n\n    /// @brief 0\
    \ \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr static_modint()\
    \ noexcept\n        : base_type{} {}\n\n    /// @brief @c value \u306E\u5270\u4F59\
    \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    /// @param value \u521D\u671F\
    \u5316\u306B\u4F7F\u3046\u5024\n    template <class SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n\
    \    constexpr static_modint(SignedIntegral value) noexcept\n        : base_type{value}\
    \ {}\n\n    /// @brief \u81EA\u8EAB\u306E\u9006\u6570\u3092\u8FD4\u3057\u307E\u3059\
    \u3002\n    /// @remark \u6642\u9593\u8A08\u7B97\u91CF\uFF1A @f$O(\\log value)@f$\n\
    \    /// @return \u81EA\u8EAB\u306E\u9006\u6570\n    [[nodiscard]]\n    constexpr\
    \ static_modint inv() const noexcept {\n        if constexpr (internal_modint::is_prime32(Mod))\
    \ {\n            assert(this->m_value != 0 && \"The inverse element of zero does\
    \ not exist.\");\n            return this->pow(Mod - 2);\n        } else {\n \
    \           return base_type::inv();\n        }\n    }\n};\n\n/// @brief \u5B9F\
    \u884C\u6642\u306B\u6CD5\u304C\u6C7A\u307E\u308B\u3068\u304D\u3001\u56DB\u5247\
    \u6F14\u7B97\u306B\u304A\u3044\u3066\u81EA\u52D5\u3067 mod \u3092\u53D6\u308B\u30AF\
    \u30E9\u30B9\n/// @tparam ID \u3053\u306EID\u3054\u3068\u306B\u6CD5\u3092\u8A2D\
    \u5B9A\u3059\u308B\u3053\u3068\u304C\u3067\u304D\u307E\u3059\ntemplate <int ID>\n\
    class dynamic_modint : public modint_base<dynamic_modint<ID>> {\n   private:\n\
    \    using base_type = modint_base<dynamic_modint<ID>>;\n\n   public:\n    using\
    \ typename base_type::value_type;\n\n    /// @brief \u6CD5\u3092\u53D6\u5F97\u3057\
    \u307E\u3059\u3002\n    /// @return \u6CD5\n    [[nodiscard]]\n    static value_type\
    \ mod() noexcept {\n        return modulus;\n    }\n\n    /// @brief \u6CD5\u3092\
    \u8A2D\u5B9A\u3057\u307E\u3059\u3002\n    /// @param m \u65B0\u3057\u3044\u6CD5\
    \n    static void set_mod(value_type m) noexcept {\n        assert(m > 0 && m\
    \ <= std::numeric_limits<value_type>::max() / 2);\n        modulus = m;\n    }\n\
    \n    /// @brief 0 \u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    constexpr\
    \ dynamic_modint() noexcept\n        : base_type{} {}\n\n    /// @brief @c value\
    \ \u306E\u5270\u4F59\u3067\u521D\u671F\u5316\u3057\u307E\u3059\u3002\n    ///\
    \ @param value \u521D\u671F\u5316\u306B\u4F7F\u3046\u5024\n    template <class\
    \ SignedIntegral, ENABLE_IF_T(std::is_integral_v<SignedIntegral>)>\n    constexpr\
    \ dynamic_modint(SignedIntegral value) noexcept\n        : base_type{value} {}\n\
    \n   private:\n    inline static value_type modulus = 998244353;\n};\n\nusing\
    \ modint998244353 = static_modint<998244353>;\nusing modint1000000007 = static_modint<1000000007>;\n\
    using modint = dynamic_modint<-1>;\n#line 18 \"test/unittest/data_structures/link-cut-tree.test.cpp\"\
    \n\nusing mint = modint998244353;\n\nstruct Forest {\n    int n;\n    std::vector<std::vector<int>>\
    \ adj;\n    std::vector<int> root;  // \u5404\u9802\u70B9\u3092\u542B\u3080\u6728\
    \u306E\u3001\u4ECA\u306E\u6839\n    explicit Forest(int n) : n(n), adj(n), root(n)\
    \ {\n        for (int i = 0; i < n; i++) root[i] = i;\n    }\n    std::vector<int>\
    \ component(int v) const {\n        std::vector<int> res = {v}, seen(n, 0);\n\
    \        seen[v] = 1;\n        for (int i = 0; i < static_cast<int>(res.size());\
    \ i++) {\n            for (int u : adj[res[i]]) {\n                if (!seen[u])\
    \ seen[u] = 1, res.push_back(u);\n            }\n        }\n        return res;\n\
    \    }\n    void evert(int v) {\n        for (int u : component(v)) root[u] =\
    \ v;\n    }\n    bool connected(int u, int v) const {\n        auto c = component(u);\n\
    \        return std::find(c.begin(), c.end(), v) != c.end();\n    }\n    // u\
    \ \u304B\u3089 v \u3078\u306E\u30D1\u30B9 (u, ..., v)\n    std::vector<int> path(int\
    \ u, int v) const {\n        std::vector<int> par(n, -2), que = {u};\n       \
    \ par[u] = -1;\n        for (int i = 0; i < static_cast<int>(que.size()); i++)\
    \ {\n            for (int w : adj[que[i]]) {\n                if (par[w] == -2)\
    \ par[w] = que[i], que.push_back(w);\n            }\n        }\n        std::vector<int>\
    \ res;\n        for (int x = v; x != -1; x = par[x]) res.push_back(x);\n     \
    \   std::reverse(res.begin(), res.end());\n        return res;\n    }\n    void\
    \ link(int u, int v) {\n        int r = root[v];\n        adj[u].push_back(v),\
    \ adj[v].push_back(u);\n        evert(r);\n    }\n    void cut(int u, int v) {\n\
    \        adj[u].erase(std::find(adj[u].begin(), adj[u].end(), v));\n        adj[v].erase(std::find(adj[v].begin(),\
    \ adj[v].end(), u));\n        evert(u), evert(v);\n    }\n    int lca(int u, int\
    \ v) const {\n        auto pu = path(u, root[u]), pv = path(v, root[v]);\n   \
    \     for (int x : pu) {\n            if (std::find(pv.begin(), pv.end(), x) !=\
    \ pv.end()) return x;\n        }\n        return -1;\n    }\n    // p \u3092\u6839\
    \u3068\u3057\u305F\u3068\u304D\u306E v \u306E\u90E8\u5206\u6728\n    std::vector<int>\
    \ subtree(int v, int p) const {\n        std::vector<int> res;\n        for (int\
    \ x : component(v)) {\n            auto pa = path(p, x);\n            if (std::find(pa.begin(),\
    \ pa.end(), v) != pa.end()) res.push_back(x);\n        }\n        return res;\n\
    \    }\n};\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 10 +\
    \ 1;\n        std::vector<Affine<mint>> f(n);\n        std::vector<long long>\
    \ a(n);\n        for (int i = 0; i < n; i++) f[i] = {mint(rng() % 5 + 1), mint(rng()\
    \ % 5)}, a[i] = rng() % 100;\n        LinkCutTree<monoid::Composite<mint>> lct(f);\n\
    \        SubtreeLinkCutTree<group::Sum<long long>> st(a);\n        Forest fo(n);\n\
    \        for (int q = 0; q < 300 && ok; q++) {\n            int type = rng() %\
    \ 8, u = rng() % n, v = rng() % n;\n            if (type == 0) {\n           \
    \     if (u == v || fo.connected(u, v)) continue;\n                lct.link(u,\
    \ v), st.link(u, v), fo.link(u, v);\n            } else if (type == 1) {\n   \
    \             if (fo.adj[u].empty()) continue;\n                v = fo.adj[u][rng()\
    \ % fo.adj[u].size()];\n                lct.cut(u, v), st.cut(u, v), fo.cut(u,\
    \ v);\n            } else if (type == 2) {\n                Affine<mint> g{mint(rng()\
    \ % 5 + 1), mint(rng() % 5)};\n                long long x = rng() % 100;\n  \
    \              if (rng() % 2) {\n                    f[u] = g, a[u] = x;\n   \
    \                 lct.set(u, g), st.set(u, x);\n                } else {\n   \
    \                 f[u] = monoid::Composite<mint>::op(f[u], g), a[u] += x;\n  \
    \                  lct.apply(u, g), st.apply(u, x);\n                }\n     \
    \           if (lct.get(u) != f[u] || st.get(u) != a[u]) ok = false;\n       \
    \     } else if (type == 3) {\n                if (lct.connected(u, v) != fo.connected(u,\
    \ v) || st.connected(u, v) != fo.connected(u, v)) ok = false;\n              \
    \  if (!fo.connected(u, v)) continue;\n                // u \u5074\u304B\u3089\
    \u9806\u306B\u5408\u6210\u3057\u305F\u3082\u306E f_u\u2218...\u2218f_v\n     \
    \           Affine<mint> g;\n                long long s = 0;\n              \
    \  for (int x : fo.path(u, v)) g = monoid::Composite<mint>::op(g, f[x]), s +=\
    \ a[x];\n                if (lct.prod(u, v) != g || st.prod(u, v) != s) ok = false;\n\
    \                fo.evert(u);\n            } else if (type == 4) {\n         \
    \       if (!fo.connected(u, v)) continue;\n                if (lct.lca(u, v)\
    \ != fo.lca(u, v)) ok = false;\n            } else if (type == 5) {\n        \
    \        if (lct.root(u) != fo.root[u] || st.root(u) != fo.root[u]) ok = false;\n\
    \            } else if (type == 6) {\n                lct.evert(u), st.evert(u),\
    \ fo.evert(u);\n            } else {\n                if (!fo.connected(u, v))\
    \ continue;\n                long long s = 0;\n                for (int x : fo.subtree(v,\
    \ u)) s += a[x];\n                if (st.subtree_prod(v, u) != s) ok = false;\n\
    \                fo.evert(u);\n                // lct \u306E\u6839\u3082 st \u3068\
    \u305D\u308D\u3048\u3066\u304A\u304F\n                lct.evert(u);\n        \
    \    }\n        }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// link-cut-tree.hpp \u306E LinkCutTree \u3068 SubtreeLinkCutTree \u3092\u3001\
    \u68EE\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\u3067\u611A\u76F4\u306B\u6C42\u3081\
    \u305F\u3082\u306E\u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u3079\u308B\n// set\
    \ \u3068 apply \u3067\u5024\u3092\u5909\u3048\u308B\u3002LinkCutTree \u306F\u53EF\
    \u63DB\u3067\u306A\u3044\u30E2\u30CE\u30A4\u30C9 (1 \u6B21\u95A2\u6570\u306E\u5408\
    \u6210) \u3067 prod \u306E\u5411\u304D\u3082\u78BA\u304B\u3081\u308B\n// evert\u30FB\
    link\u30FBcut\u30FBprod\u30FBsubtree_prod \u3067\u6839\u304C\u5909\u308F\u308B\
    \u306E\u3067\u3001\u611A\u76F4\u306A\u5074\u3067\u3082\u6839\u3092\u8FFD\u3044\
    \u304B\u3051\u3066 lca\u30FBroot \u3068\u6BD4\u3079\u308B\n// \u554F\u984C\u306E\
    \u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\
    \u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n#include \"../../../src/data_structures/link-cut-tree.hpp\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \n#include \"../../../src/algebra/group.hpp\"\n#include \"../../../src/algebra/monoid.hpp\"\
    \n#include \"../../../src/math/modint.hpp\"\n\nusing mint = modint998244353;\n\
    \nstruct Forest {\n    int n;\n    std::vector<std::vector<int>> adj;\n    std::vector<int>\
    \ root;  // \u5404\u9802\u70B9\u3092\u542B\u3080\u6728\u306E\u3001\u4ECA\u306E\
    \u6839\n    explicit Forest(int n) : n(n), adj(n), root(n) {\n        for (int\
    \ i = 0; i < n; i++) root[i] = i;\n    }\n    std::vector<int> component(int v)\
    \ const {\n        std::vector<int> res = {v}, seen(n, 0);\n        seen[v] =\
    \ 1;\n        for (int i = 0; i < static_cast<int>(res.size()); i++) {\n     \
    \       for (int u : adj[res[i]]) {\n                if (!seen[u]) seen[u] = 1,\
    \ res.push_back(u);\n            }\n        }\n        return res;\n    }\n  \
    \  void evert(int v) {\n        for (int u : component(v)) root[u] = v;\n    }\n\
    \    bool connected(int u, int v) const {\n        auto c = component(u);\n  \
    \      return std::find(c.begin(), c.end(), v) != c.end();\n    }\n    // u \u304B\
    \u3089 v \u3078\u306E\u30D1\u30B9 (u, ..., v)\n    std::vector<int> path(int u,\
    \ int v) const {\n        std::vector<int> par(n, -2), que = {u};\n        par[u]\
    \ = -1;\n        for (int i = 0; i < static_cast<int>(que.size()); i++) {\n  \
    \          for (int w : adj[que[i]]) {\n                if (par[w] == -2) par[w]\
    \ = que[i], que.push_back(w);\n            }\n        }\n        std::vector<int>\
    \ res;\n        for (int x = v; x != -1; x = par[x]) res.push_back(x);\n     \
    \   std::reverse(res.begin(), res.end());\n        return res;\n    }\n    void\
    \ link(int u, int v) {\n        int r = root[v];\n        adj[u].push_back(v),\
    \ adj[v].push_back(u);\n        evert(r);\n    }\n    void cut(int u, int v) {\n\
    \        adj[u].erase(std::find(adj[u].begin(), adj[u].end(), v));\n        adj[v].erase(std::find(adj[v].begin(),\
    \ adj[v].end(), u));\n        evert(u), evert(v);\n    }\n    int lca(int u, int\
    \ v) const {\n        auto pu = path(u, root[u]), pv = path(v, root[v]);\n   \
    \     for (int x : pu) {\n            if (std::find(pv.begin(), pv.end(), x) !=\
    \ pv.end()) return x;\n        }\n        return -1;\n    }\n    // p \u3092\u6839\
    \u3068\u3057\u305F\u3068\u304D\u306E v \u306E\u90E8\u5206\u6728\n    std::vector<int>\
    \ subtree(int v, int p) const {\n        std::vector<int> res;\n        for (int\
    \ x : component(v)) {\n            auto pa = path(p, x);\n            if (std::find(pa.begin(),\
    \ pa.end(), v) != pa.end()) res.push_back(x);\n        }\n        return res;\n\
    \    }\n};\n\nint main() {\n    std::mt19937_64 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 300 && ok; rep++) {\n        int n = rng() % 10 +\
    \ 1;\n        std::vector<Affine<mint>> f(n);\n        std::vector<long long>\
    \ a(n);\n        for (int i = 0; i < n; i++) f[i] = {mint(rng() % 5 + 1), mint(rng()\
    \ % 5)}, a[i] = rng() % 100;\n        LinkCutTree<monoid::Composite<mint>> lct(f);\n\
    \        SubtreeLinkCutTree<group::Sum<long long>> st(a);\n        Forest fo(n);\n\
    \        for (int q = 0; q < 300 && ok; q++) {\n            int type = rng() %\
    \ 8, u = rng() % n, v = rng() % n;\n            if (type == 0) {\n           \
    \     if (u == v || fo.connected(u, v)) continue;\n                lct.link(u,\
    \ v), st.link(u, v), fo.link(u, v);\n            } else if (type == 1) {\n   \
    \             if (fo.adj[u].empty()) continue;\n                v = fo.adj[u][rng()\
    \ % fo.adj[u].size()];\n                lct.cut(u, v), st.cut(u, v), fo.cut(u,\
    \ v);\n            } else if (type == 2) {\n                Affine<mint> g{mint(rng()\
    \ % 5 + 1), mint(rng() % 5)};\n                long long x = rng() % 100;\n  \
    \              if (rng() % 2) {\n                    f[u] = g, a[u] = x;\n   \
    \                 lct.set(u, g), st.set(u, x);\n                } else {\n   \
    \                 f[u] = monoid::Composite<mint>::op(f[u], g), a[u] += x;\n  \
    \                  lct.apply(u, g), st.apply(u, x);\n                }\n     \
    \           if (lct.get(u) != f[u] || st.get(u) != a[u]) ok = false;\n       \
    \     } else if (type == 3) {\n                if (lct.connected(u, v) != fo.connected(u,\
    \ v) || st.connected(u, v) != fo.connected(u, v)) ok = false;\n              \
    \  if (!fo.connected(u, v)) continue;\n                // u \u5074\u304B\u3089\
    \u9806\u306B\u5408\u6210\u3057\u305F\u3082\u306E f_u\u2218...\u2218f_v\n     \
    \           Affine<mint> g;\n                long long s = 0;\n              \
    \  for (int x : fo.path(u, v)) g = monoid::Composite<mint>::op(g, f[x]), s +=\
    \ a[x];\n                if (lct.prod(u, v) != g || st.prod(u, v) != s) ok = false;\n\
    \                fo.evert(u);\n            } else if (type == 4) {\n         \
    \       if (!fo.connected(u, v)) continue;\n                if (lct.lca(u, v)\
    \ != fo.lca(u, v)) ok = false;\n            } else if (type == 5) {\n        \
    \        if (lct.root(u) != fo.root[u] || st.root(u) != fo.root[u]) ok = false;\n\
    \            } else if (type == 6) {\n                lct.evert(u), st.evert(u),\
    \ fo.evert(u);\n            } else {\n                if (!fo.connected(u, v))\
    \ continue;\n                long long s = 0;\n                for (int x : fo.subtree(v,\
    \ u)) s += a[x];\n                if (st.subtree_prod(v, u) != s) ok = false;\n\
    \                fo.evert(u);\n                // lct \u306E\u6839\u3082 st \u3068\
    \u305D\u308D\u3048\u3066\u304A\u304F\n                lct.evert(u);\n        \
    \    }\n        }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n\
    }\n"
  dependsOn:
  - src/data_structures/link-cut-tree.hpp
  - src/algebra/group.hpp
  - src/algebra/monoid.hpp
  - src/math/modint.hpp
  - src/utility/traits.hpp
  isVerificationFile: true
  path: test/unittest/data_structures/link-cut-tree.test.cpp
  requiredBy: []
  timestamp: '2026-10-22 04:29:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/data_structures/link-cut-tree.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/data_structures/link-cut-tree.test.cpp
- /verify/test/unittest/data_structures/link-cut-tree.test.cpp.html
title: test/unittest/data_structures/link-cut-tree.test.cpp
---
