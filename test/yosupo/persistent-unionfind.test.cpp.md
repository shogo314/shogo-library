---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-array.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-unionfind.hpp
    title: "\u6C38\u7D9AUnionFind"
  - icon: ':heavy_check_mark:'
    path: src/data_structures/unionfind.hpp
    title: UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent-unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 2 \"src/data_structures/persistent-unionfind.hpp\"\
    \n\n/**\n * @file persistent-unionfind.hpp\n * @brief \u6C38\u7D9AUnionFind\n\
    \ */\n\n#include <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"\
    src/data_structures/persistent-array.hpp\"\n\n/**\n * @file persistent-array.hpp\n\
    \ * @brief \u6C38\u7D9A\u914D\u5217\n */\n\n#include <array>\n#line 10 \"src/data_structures/persistent-array.hpp\"\
    \n#include <memory>\n#include <ostream>\n#line 14 \"src/data_structures/persistent-array.hpp\"\
    \n\n/**\n * @brief \u6C38\u7D9A\u914D\u5217\n *\n * \u66F4\u65B0\u3059\u308B\u3068\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\u306F\u5909\
    \u308F\u3089\u306A\u3044\u3002\u540C\u3058\u914D\u5217\u304B\u3089\u4F5C\u3063\
    \u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\n * \u4F8B\
    :\n * PersistentArray<int> a0(n, -1);\n * auto a1 = a0.set(3, 10);  // a0 \u306F\
    \u305D\u306E\u307E\u307E\n * a1[3];                    // 10\n *\n * @tparam T\
    \ \u8981\u7D20\u306E\u578B\n */\ntemplate <typename T>\nclass PersistentArray\
    \ {\n    // \u3059\u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\
    \u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\u3044\n    struct\
    \ Pool {\n        std::vector<std::array<int, 2>> child;  // \u5185\u90E8\u30CE\
    \u30FC\u30C9\u306E\u5B50 (\u6700\u4E0B\u6BB5\u306E\u5185\u90E8\u30CE\u30FC\u30C9\
    \u3067\u306F\u8449\u306E\u756A\u53F7)\n        std::vector<T> leaf;\n        int\
    \ make_leaf(const T& x) {\n            leaf.push_back(x);\n            return\
    \ static_cast<int>(leaf.size()) - 1;\n        }\n        int make_node(int l,\
    \ int r) {\n            child.push_back({l, r});\n            return static_cast<int>(child.size())\
    \ - 1;\n        }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u8981\u7D20\u6570\
    \ 0 \u306A\u3089 nullptr\n    long long n;\n    int height, root;  // height =\
    \ 0 \u306A\u3089 root \u306F\u8449\u306E\u756A\u53F7\n\n    PersistentArray(std::shared_ptr<Pool>\
    \ pool, long long n, int height, int root) : pool(std::move(pool)), n(n), height(height),\
    \ root(root) {}\n\n    void init_height() {\n        height = 0;\n        while\
    \ ((1LL << height) < n) height++;\n    }\n    // t ([a, a + 2^h)) \u306E [l, r)\
    \ \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\n    int copy_rec(int t, int u,\
    \ long long a, int h, long long l, long long r) const {\n        if (r <= a ||\
    \ a + (1LL << h) <= l) return t;\n        if (l <= a && a + (1LL << h) <= r) return\
    \ u;\n        int lc = copy_rec(pool->child[t][0], pool->child[u][0], a, h - 1,\
    \ l, r);\n        int rc = copy_rec(pool->child[t][1], pool->child[u][1], a +\
    \ (1LL << (h - 1)), h - 1, l, r);\n        return pool->make_node(lc, rc);\n \
    \   }\n    int build(const std::vector<T>& v, long long a, int h) {\n        if\
    \ (h == 0) return pool->make_leaf(a < n ? v[a] : T());\n        int l = build(v,\
    \ a, h - 1);\n        int r = build(v, a + (1LL << (h - 1)), h - 1);\n       \
    \ return pool->make_node(l, r);\n    }\n\n   public:\n    /**\n     * @brief \u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u540C\u3058\u5024\u306E\u90E8\
    \u5206\u6728\u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001n \u304C\u5927\u304D\
    \u304F\u3066\u3082 O(log n) \u3067\u4F5C\u308C\u308B\n     *\n     * @param n\
    \ \u8981\u7D20\u6570\n     * @param x \u521D\u671F\u5024\n     */\n    explicit\
    \ PersistentArray(long long n = 0, const T& x = T()) : pool(nullptr), n(n), height(0),\
    \ root(-1) {\n        assert(0 <= n);\n        if (n == 0) return;\n        pool\
    \ = std::make_shared<Pool>();\n        init_height();\n        root = pool->make_leaf(x);\n\
    \        for (int h = 0; h < height; h++) root = pool->make_node(root, root);\n\
    \    }\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n  \
    \   *\n     * @param v \u521D\u671F\u306E\u8981\u7D20\n     */\n    explicit PersistentArray(const\
    \ std::vector<T>& v) : pool(nullptr), n(v.size()), height(0), root(-1) {\n   \
    \     if (n == 0) return;\n        pool = std::make_shared<Pool>();\n        init_height();\n\
    \        root = build(v, 0, height);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\n     */\n    long long size() const { return n; }\n\n\
    \    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return T \u5024\n     */\n    T get(long long k) const {\n        assert(0\
    \ <= k && k < n);\n        int t = root;\n        for (int h = height - 1; h >=\
    \ 0; h--) t = pool->child[t][k >> h & 1];\n        return pool->leaf[t];\n   \
    \ }\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\
    \u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n     * @return T \u5024\n     */\n    T operator[](long long k) const { return\
    \ get(k); }\n\n    /**\n     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\
    \u306E\u5024\u3092x\u306B\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\
    \n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param\
    \ x \u65B0\u3057\u3044\u5024\n     * @return PersistentArray \u65B0\u3057\u3044\
    \u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentArray\
    \ set(long long k, const T& x) const {\n        assert(0 <= k && k < n);\n   \
    \     std::vector<int> path(height);\n        int t = root;\n        for (int\
    \ h = height - 1; h >= 0; h--) {\n            path[h] = t;\n            t = pool->child[t][k\
    \ >> h & 1];\n        }\n        t = pool->make_leaf(x);\n        for (int h =\
    \ 0; h < height; h++) {\n            std::array<int, 2> c = pool->child[path[h]];\n\
    \            c[k >> h & 1] = t;\n            t = pool->make_node(c[0], c[1]);\n\
    \        }\n        return PersistentArray(pool, n, height, t);\n    }\n    /**\n\
    \     * @brief [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\
    \u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param\
    \ other \u5199\u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u914D\u5217\
    \u304B\u3089\u4F5C\u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\
    \u9593\u306E\u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\
    \u7AEF 0<=l<=r<=n\n     * @return PersistentArray \u65B0\u3057\u3044\u7248 (\u81EA\
    \u8EAB\u3082 other \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentArray\
    \ copy(const PersistentArray& other, long long l, long long r) const {\n     \
    \   assert(pool == other.pool);\n        assert(0 <= l && l <= r && r <= n);\n\
    \        if (l == r) return *this;\n        return PersistentArray(pool, n, height,\
    \ copy_rec(root, other.root, 0, height, l, r));\n    }\n\n    /**\n     * @brief\
    \ \u5185\u5BB9\u3092\u51FA\u529B\u3059\u308B\n     *\n     * @tparam CharT \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits\
    \ \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\
    \n     * @param os \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs\
    \ \u6C38\u7D9A\u914D\u5217\n     * @return std::basic_ostream<CharT, Traits>&\
    \ \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     */\n    template <class CharT,\
    \ class Traits>\n    friend std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT,\
    \ Traits>& os, const PersistentArray& rhs) {\n        for (long long i = 0; i\
    \ < rhs.n; i++) {\n            if (i != 0) os << CharT(' ');\n            os <<\
    \ rhs[i];\n        }\n        return os;\n    }\n\n    /**\n     * @brief \u3059\
    \u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\
    \n     */\n    std::vector<T> to_vector() const {\n        std::vector<T> res(n);\n\
    \        for (long long i = 0; i < n; i++) res[i] = get(i);\n        return res;\n\
    \    }\n};\n#line 2 \"src/data_structures/unionfind.hpp\"\n\n/**\n * @file unionfind.hpp\n\
    \ * @brief UnionFind\n */\n\n#include <algorithm>\n#line 12 \"src/data_structures/unionfind.hpp\"\
    \n\nnamespace internal_unionfind {\n/**\n * @brief \u5404\u8981\u7D20\u306E\u4EE3\
    \u8868\u5143\u304B\u3089\u3001\u9023\u7D50\u6210\u5206\u3054\u3068\u306E\u8981\
    \u7D20\u306E\u30EA\u30B9\u30C8\u3092\u4F5C\u308B\n * @param leader \u8981\u7D20\
    \ a \u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\u95A2\u6570\n */\ntemplate <typename\
    \ F>\nstd::vector<std::vector<long long>> groups(long long n, F leader) {\n  \
    \  std::vector<long long> leader_buf(n), group_size(n);\n    for (long long i\
    \ = 0; i < n; i++) {\n        leader_buf[i] = leader(i);\n        group_size[leader_buf[i]]++;\n\
    \    }\n    std::vector<std::vector<long long>> result(n);\n    for (long long\
    \ i = 0; i < n; i++) {\n        result[i].reserve(group_size[i]);\n    }\n   \
    \ for (long long i = 0; i < n; i++) {\n        result[leader_buf[i]].push_back(i);\n\
    \    }\n    result.erase(std::remove_if(result.begin(), result.end(), [&](const\
    \ std::vector<long long>& v) { return v.empty(); }), result.end());\n    return\
    \ result;\n}\n}  // namespace internal_unionfind\n\n/**\n * @brief \u7121\u5411\
    \u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u300C\u8FBA\u306E\u8FFD\u52A0\u300D\
    \u3001\u300C2\u9802\u70B9\u304C\u9023\u7D50\u304B\u306E\u5224\u5B9A\u300D\u3092\
    \u3059\u308B\n */\nclass UnionFind {\n   protected:\n    long long _n;\n    //\
    \ \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\u306A\u3089\u89AA (\u30E1\
    \u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int \u3067\u6301\u3064)\n   \
    \ std::vector<int> parent_or_size;\n\n   public:\n    /**\n     * @brief merge\
    \ \u306E\u623B\u308A\u5024\n     *\n     * if (uf.merge(a, b)) \u3067\u65B0\u3057\
    \u304F\u7D71\u5408\u3057\u305F\u304B\u3092\u5224\u5B9A\u3067\u304D\u3001\n   \
    \  * auto [r, merged] = uf.merge(a, b); \u3067\u4EE3\u8868\u5143\u3082\u53D7\u3051\
    \u53D6\u308C\u308B\n     */\n    struct MergeResult {\n        long long leader;\
    \  //!< \u7D71\u5408\u5F8C\u306E\u4EE3\u8868\u5143\n        bool merged;     \
    \  //!< \u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B (\u3082\u3068\u3082\u3068\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u306A\u3089 false)\n        explicit operator\
    \ bool() const { return merged; }\n    };\n\n    UnionFind() : _n(0) {}\n    explicit\
    \ UnionFind(long long n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     *\
    \ @brief \u8FBA(a,b)\u3092\u8DB3\u3059\n     * @return \u7D71\u5408\u5F8C\u306E\
    \u4EE3\u8868\u5143\u3068\u3001\u65B0\u3057\u304F\u7D71\u5408\u3057\u305F\u304B\
    \n     */\n    MergeResult merge(long long a, long long b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return {x, false};\n        if (-parent_or_size[x]\
    \ < -parent_or_size[y]) std::swap(x, y);\n        parent_or_size[x] += parent_or_size[y];\n\
    \        parent_or_size[y] = static_cast<int>(x);\n        return {x, true};\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\
    \u304B\n     */\n    bool same(long long a, long long b) {\n        assert(0 <=\
    \ a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a) ==\
    \ leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long leader(long\
    \ long a) {\n        assert(0 <= a && a < _n);\n        if (parent_or_size[a]\
    \ < 0) return a;\n        int x = static_cast<int>(a);\n        while (parent_or_size[x]\
    \ >= 0) {\n            x = parent_or_size[x];\n        }\n        while (parent_or_size[a]\
    \ >= 0) {\n            int t = parent_or_size[a];\n            parent_or_size[a]\
    \ = x;\n            a = t;\n        }\n        return x;\n    }\n    /**\n   \
    \  * @brief \u9802\u70B9a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\n     */\n    long long size(long long a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n\
    \     * @brief \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\
    \u3001\u305D\u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\
    \u30C8\u300D\u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long\
    \ long>> groups() {\n        return internal_unionfind::groups(_n, [&](long long\
    \ a) { return leader(a); });\n    }\n};\n#line 14 \"src/data_structures/persistent-unionfind.hpp\"\
    \n\n/**\n * @brief \u6C38\u7D9AUnionFind\n *\n * \u8FBA\u3092\u8FFD\u52A0\u3059\
    \u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\
    \u306F\u5909\u308F\u3089\u306A\u3044\u3002union by size \u3060\u3051\u3092\u884C\
    \u3044\u3001\u7D4C\u8DEF\u5727\u7E2E\u306F\u3057\u306A\u3044\n * \u4F8B:\n * PersistentUnionFind\
    \ uf0(n);\n * auto uf1 = uf0.merge(0, 1);  // uf0 \u306F\u305D\u306E\u307E\u307E\
    \n * uf1.same(0, 1);              // true\n */\nclass PersistentUnionFind {\n\
    \    long long _n;\n    // \u8CA0\u306A\u3089\u30B5\u30A4\u30BA\u3001\u975E\u8CA0\
    \u306A\u3089\u89AA (\u30E1\u30E2\u30EA\u3092\u6291\u3048\u308B\u305F\u3081 int\
    \ \u3067\u6301\u3064)\n    PersistentArray<int> parent_or_size;\n\n    PersistentUnionFind(long\
    \ long n, PersistentArray<int> parent_or_size) : _n(n), parent_or_size(std::move(parent_or_size))\
    \ {}\n\n   public:\n    PersistentUnionFind() : _n(0) {}\n    explicit PersistentUnionFind(long\
    \ long n) : _n(n), parent_or_size(n, -1) {}\n\n    /**\n     * @brief \u8FBA(a,b)\u3092\
    \u8DB3\u3057\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     * @return PersistentUnionFind\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044\u3002\
    \u3082\u3068\u3082\u3068\u9023\u7D50\u306A\u3089\u540C\u3058\u7248)\n     */\n\
    \    PersistentUnionFind merge(long long a, long long b) const {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        long long x = leader(a),\
    \ y = leader(b);\n        if (x == y) return *this;\n        int sx = parent_or_size[x],\
    \ sy = parent_or_size[y];\n        if (-sx < -sy) std::swap(x, y);\n        return\
    \ PersistentUnionFind(_n, parent_or_size.set(x, sx + sy).set(y, static_cast<int>(x)));\n\
    \    }\n    /**\n     * @brief \u9802\u70B9a,b\u304C\u9023\u7D50\u304B\u3069\u3046\
    \u304B\n     */\n    bool same(long long a, long long b) const {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n    /**\n     * @brief \u9802\u70B9a\u306E\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u4EE3\u8868\u5143\n     */\n    long long\
    \ leader(long long a) const {\n        assert(0 <= a && a < _n);\n        while\
    \ (true) {\n            int p = parent_or_size[a];\n            if (p < 0) return\
    \ a;\n            a = p;\n        }\n    }\n    /**\n     * @brief \u9802\u70B9\
    a\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\n  \
    \   */\n    long long size(long long a) const {\n        assert(0 <= a && a <\
    \ _n);\n        return -parent_or_size[leader(a)];\n    }\n    /**\n     * @brief\
    \ \u30B0\u30E9\u30D5\u3092\u9023\u7D50\u6210\u5206\u306B\u5206\u3051\u3001\u305D\
    \u306E\u60C5\u5831\u3092\u8FD4\u3059\n     * @return \u300C\u4E00\u3064\u306E\u9023\
    \u7D50\u6210\u5206\u306E\u9802\u70B9\u756A\u53F7\u306E\u30EA\u30B9\u30C8\u300D\
    \u306E\u30EA\u30B9\u30C8\n     */\n    std::vector<std::vector<long long>> groups()\
    \ const {\n        return internal_unionfind::groups(_n, [&](long long a) { return\
    \ leader(a); });\n    }\n};\n#line 4 \"test/yosupo/persistent-unionfind.test.cpp\"\
    \n\n#include <iostream>\n#line 7 \"test/yosupo/persistent-unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    std::cin >> n >> q;\n    // uf[i + 1] \u304C\
    \u30AF\u30A8\u30EA i \u306E\u5F8C\u306E\u7248\u3001uf[0] \u304C\u521D\u671F\u306E\
    \u7248\n    std::vector<PersistentUnionFind> uf(q + 1);\n    uf[0] = PersistentUnionFind(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int t, k, u, v;\n        std::cin\
    \ >> t >> k >> u >> v;\n        const PersistentUnionFind& prev = uf[k + 1];\n\
    \        if (t == 0) {\n            uf[i + 1] = prev.merge(u, v);\n        } else\
    \ {\n            uf[i + 1] = prev;\n            std::cout << prev.same(u, v) <<\
    \ '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../src/data_structures/persistent-unionfind.hpp\"\n\n#include\
    \ <iostream>\n#include <vector>\n\nint main() {\n    int n, q;\n    std::cin >>\
    \ n >> q;\n    // uf[i + 1] \u304C\u30AF\u30A8\u30EA i \u306E\u5F8C\u306E\u7248\
    \u3001uf[0] \u304C\u521D\u671F\u306E\u7248\n    std::vector<PersistentUnionFind>\
    \ uf(q + 1);\n    uf[0] = PersistentUnionFind(n);\n    for (int i = 0; i < q;\
    \ i++) {\n        int t, k, u, v;\n        std::cin >> t >> k >> u >> v;\n   \
    \     const PersistentUnionFind& prev = uf[k + 1];\n        if (t == 0) {\n  \
    \          uf[i + 1] = prev.merge(u, v);\n        } else {\n            uf[i +\
    \ 1] = prev;\n            std::cout << prev.same(u, v) << '\\n';\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/data_structures/persistent-unionfind.hpp
  - src/data_structures/persistent-array.hpp
  - src/data_structures/unionfind.hpp
  isVerificationFile: true
  path: test/yosupo/persistent-unionfind.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent-unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent-unionfind.test.cpp
- /verify/test/yosupo/persistent-unionfind.test.cpp.html
title: test/yosupo/persistent-unionfind.test.cpp
---
