---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-unionfind.hpp
    title: "\u6C38\u7D9AUnionFind"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unittest/persistent-array.test.cpp
    title: test/unittest/persistent-array.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/unittest/persistent-unionfind.test.cpp
    title: test/unittest/persistent-unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent-unionfind.test.cpp
    title: test/yosupo/persistent-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6C38\u7D9A\u914D\u5217"
    links: []
  bundledCode: "#line 2 \"src/data_structures/persistent-array.hpp\"\n\n/**\n * @file\
    \ persistent-array.hpp\n * @brief \u6C38\u7D9A\u914D\u5217\n */\n\n#include <array>\n\
    #include <cassert>\n#include <memory>\n#include <ostream>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief \u6C38\u7D9A\u914D\u5217\n *\n * \u66F4\u65B0\
    \u3059\u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\
    \u7248\u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u914D\u5217\u304B\
    \u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\
    \u308B\n * \u4F8B:\n * PersistentArray<int> a0(n, -1);\n * auto a1 = a0.set(3,\
    \ 10);  // a0 \u306F\u305D\u306E\u307E\u307E\n * a1[3];                    //\
    \ 10\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n */\ntemplate <typename T>\n\
    class PersistentArray {\n    // \u3059\u3079\u3066\u306E\u7248\u306E\u30CE\u30FC\
    \u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\u306F\u524A\u9664\u3057\u306A\
    \u3044\n    struct Pool {\n        std::vector<std::array<int, 2>> child;  //\
    \ \u5185\u90E8\u30CE\u30FC\u30C9\u306E\u5B50 (\u6700\u4E0B\u6BB5\u306E\u5185\u90E8\
    \u30CE\u30FC\u30C9\u3067\u306F\u8449\u306E\u756A\u53F7)\n        std::vector<T>\
    \ leaf;\n        int make_leaf(const T& x) {\n            leaf.push_back(x);\n\
    \            return int(leaf.size()) - 1;\n        }\n        int make_node(int\
    \ l, int r) {\n            child.push_back({l, r});\n            return int(child.size())\
    \ - 1;\n        }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u8981\u7D20\u6570\
    \ 0 \u306A\u3089 nullptr\n    int n, height, root;         // height = 0 \u306A\
    \u3089 root \u306F\u8449\u306E\u756A\u53F7\n\n    PersistentArray(std::shared_ptr<Pool>\
    \ pool, int n, int height, int root) : pool(std::move(pool)), n(n), height(height),\
    \ root(root) {}\n\n    void init_height() {\n        height = 0;\n        while\
    \ ((1 << height) < n) height++;\n    }\n    // t ([a, a + 2^h)) \u306E [l, r)\
    \ \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\u308B\n    int copy_rec(int t, int u,\
    \ int a, int h, int l, int r) const {\n        if (r <= a || a + (1 << h) <= l)\
    \ return t;\n        if (l <= a && a + (1 << h) <= r) return u;\n        int lc\
    \ = copy_rec(pool->child[t][0], pool->child[u][0], a, h - 1, l, r);\n        int\
    \ rc = copy_rec(pool->child[t][1], pool->child[u][1], a + (1 << (h - 1)), h -\
    \ 1, l, r);\n        return pool->make_node(lc, rc);\n    }\n    int build(const\
    \ std::vector<T>& v, int a, int h) {\n        if (h == 0) return pool->make_leaf(a\
    \ < n ? v[a] : T());\n        int l = build(v, a, h - 1);\n        int r = build(v,\
    \ a + (1 << (h - 1)), h - 1);\n        return pool->make_node(l, r);\n    }\n\n\
    \   public:\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \n     *\n     * \u540C\u3058\u5024\u306E\u90E8\u5206\u6728\u306F\u5171\u6709\u3059\
    \u308B\u306E\u3067\u3001n \u304C\u5927\u304D\u304F\u3066\u3082 O(log n) \u3067\
    \u4F5C\u308C\u308B\n     *\n     * @param n \u8981\u7D20\u6570\n     * @param\
    \ x \u521D\u671F\u5024\n     */\n    explicit PersistentArray(int n = 0, const\
    \ T& x = T()) : pool(nullptr), n(n), height(0), root(-1) {\n        assert(0 <=\
    \ n);\n        if (n == 0) return;\n        pool = std::make_shared<Pool>();\n\
    \        init_height();\n        root = pool->make_leaf(x);\n        for (int\
    \ h = 0; h < height; h++) root = pool->make_node(root, root);\n    }\n    /**\n\
    \     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param\
    \ v \u521D\u671F\u306E\u8981\u7D20\n     */\n    explicit PersistentArray(const\
    \ std::vector<T>& v) : pool(nullptr), n(v.size()), height(0), root(-1) {\n   \
    \     if (n == 0) return;\n        pool = std::make_shared<Pool>();\n        init_height();\n\
    \        root = build(v, 0, height);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\n     */\n    int size() const { return n; }\n\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ T \u5024\n     */\n    T get(int k) const {\n        assert(0 <= k && k < n);\n\
    \        int t = root;\n        for (int h = height - 1; h >= 0; h--) t = pool->child[t][k\
    \ >> h & 1];\n        return pool->leaf[t];\n    }\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n \
    \    * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return T \u5024\n\
    \     */\n    T operator[](int k) const { return get(k); }\n\n    /**\n     *\
    \ @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u3057\
    \u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n   \
    \  * @return PersistentArray \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\
    \u308F\u3089\u306A\u3044)\n     */\n    PersistentArray set(int k, const T& x)\
    \ const {\n        assert(0 <= k && k < n);\n        std::vector<int> path(height);\n\
    \        int t = root;\n        for (int h = height - 1; h >= 0; h--) {\n    \
    \        path[h] = t;\n            t = pool->child[t][k >> h & 1];\n        }\n\
    \        t = pool->make_leaf(x);\n        for (int h = 0; h < height; h++) {\n\
    \            std::array<int, 2> c = pool->child[path[h]];\n            c[k >>\
    \ h & 1] = t;\n            t = pool->make_node(c[0], c[1]);\n        }\n     \
    \   return PersistentArray(pool, n, height, t);\n    }\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\u3057\u305F\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param other \u5199\
    \u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u914D\u5217\u304B\u3089\
    \u4F5C\u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\u306E\
    \u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n\
    \     * @return PersistentArray \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u3082 other\
    \ \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentArray copy(const\
    \ PersistentArray& other, int l, int r) const {\n        assert(pool == other.pool);\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return *this;\n\
    \        return PersistentArray(pool, n, height, copy_rec(root, other.root, 0,\
    \ height, l, r));\n    }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\
    \u3059\u308B\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u6C38\u7D9A\u914D\u5217\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentArray&\
    \ rhs) {\n        for (int i = 0; i < rhs.n; i++) {\n            if (i != 0) os\
    \ << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n \
    \   }\n\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\
    \u3079\u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<T> to_vector()\
    \ const {\n        std::vector<T> res(n);\n        for (int i = 0; i < n; i++)\
    \ res[i] = get(i);\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file persistent-array.hpp\n * @brief \u6C38\u7D9A\
    \u914D\u5217\n */\n\n#include <array>\n#include <cassert>\n#include <memory>\n\
    #include <ostream>\n#include <utility>\n#include <vector>\n\n/**\n * @brief \u6C38\
    \u7D9A\u914D\u5217\n *\n * \u66F4\u65B0\u3059\u308B\u3068\u65B0\u3057\u3044\u7248\
    \u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\u306F\u5909\u308F\u3089\u306A\u3044\
    \u3002\u540C\u3058\u914D\u5217\u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\
    \u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\n * \u4F8B:\n * PersistentArray<int>\
    \ a0(n, -1);\n * auto a1 = a0.set(3, 10);  // a0 \u306F\u305D\u306E\u307E\u307E\
    \n * a1[3];                    // 10\n *\n * @tparam T \u8981\u7D20\u306E\u578B\
    \n */\ntemplate <typename T>\nclass PersistentArray {\n    // \u3059\u3079\u3066\
    \u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\u30C9\
    \u306F\u524A\u9664\u3057\u306A\u3044\n    struct Pool {\n        std::vector<std::array<int,\
    \ 2>> child;  // \u5185\u90E8\u30CE\u30FC\u30C9\u306E\u5B50 (\u6700\u4E0B\u6BB5\
    \u306E\u5185\u90E8\u30CE\u30FC\u30C9\u3067\u306F\u8449\u306E\u756A\u53F7)\n  \
    \      std::vector<T> leaf;\n        int make_leaf(const T& x) {\n           \
    \ leaf.push_back(x);\n            return int(leaf.size()) - 1;\n        }\n  \
    \      int make_node(int l, int r) {\n            child.push_back({l, r});\n \
    \           return int(child.size()) - 1;\n        }\n    };\n\n    std::shared_ptr<Pool>\
    \ pool;  // \u8981\u7D20\u6570 0 \u306A\u3089 nullptr\n    int n, height, root;\
    \         // height = 0 \u306A\u3089 root \u306F\u8449\u306E\u756A\u53F7\n\n \
    \   PersistentArray(std::shared_ptr<Pool> pool, int n, int height, int root) :\
    \ pool(std::move(pool)), n(n), height(height), root(root) {}\n\n    void init_height()\
    \ {\n        height = 0;\n        while ((1 << height) < n) height++;\n    }\n\
    \    // t ([a, a + 2^h)) \u306E [l, r) \u3092 u \u306B\u7F6E\u304D\u63DB\u3048\
    \u308B\n    int copy_rec(int t, int u, int a, int h, int l, int r) const {\n \
    \       if (r <= a || a + (1 << h) <= l) return t;\n        if (l <= a && a +\
    \ (1 << h) <= r) return u;\n        int lc = copy_rec(pool->child[t][0], pool->child[u][0],\
    \ a, h - 1, l, r);\n        int rc = copy_rec(pool->child[t][1], pool->child[u][1],\
    \ a + (1 << (h - 1)), h - 1, l, r);\n        return pool->make_node(lc, rc);\n\
    \    }\n    int build(const std::vector<T>& v, int a, int h) {\n        if (h\
    \ == 0) return pool->make_leaf(a < n ? v[a] : T());\n        int l = build(v,\
    \ a, h - 1);\n        int r = build(v, a + (1 << (h - 1)), h - 1);\n        return\
    \ pool->make_node(l, r);\n    }\n\n   public:\n    /**\n     * @brief \u30B3\u30F3\
    \u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * \u540C\u3058\u5024\u306E\u90E8\u5206\
    \u6728\u306F\u5171\u6709\u3059\u308B\u306E\u3067\u3001n \u304C\u5927\u304D\u304F\
    \u3066\u3082 O(log n) \u3067\u4F5C\u308C\u308B\n     *\n     * @param n \u8981\
    \u7D20\u6570\n     * @param x \u521D\u671F\u5024\n     */\n    explicit PersistentArray(int\
    \ n = 0, const T& x = T()) : pool(nullptr), n(n), height(0), root(-1) {\n    \
    \    assert(0 <= n);\n        if (n == 0) return;\n        pool = std::make_shared<Pool>();\n\
    \        init_height();\n        root = pool->make_leaf(x);\n        for (int\
    \ h = 0; h < height; h++) root = pool->make_node(root, root);\n    }\n    /**\n\
    \     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     *\n     * @param\
    \ v \u521D\u671F\u306E\u8981\u7D20\n     */\n    explicit PersistentArray(const\
    \ std::vector<T>& v) : pool(nullptr), n(v.size()), height(0), root(-1) {\n   \
    \     if (n == 0) return;\n        pool = std::make_shared<Pool>();\n        init_height();\n\
    \        root = build(v, 0, height);\n    }\n\n    /**\n     * @brief \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\n     */\n    int size() const { return n; }\n\n    /**\n\
    \     * @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\
    \u3059\n     *\n     * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return\
    \ T \u5024\n     */\n    T get(int k) const {\n        assert(0 <= k && k < n);\n\
    \        int t = root;\n        for (int h = height - 1; h >= 0; h--) t = pool->child[t][k\
    \ >> h & 1];\n        return pool->leaf[t];\n    }\n    /**\n     * @brief \u6307\
    \u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092\u8FD4\u3059\n     *\n \
    \    * @param k \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n     * @return T \u5024\n\
    \     */\n    T operator[](int k) const { return get(k); }\n\n    /**\n     *\
    \ @brief \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u306E\u5024\u3092x\u306B\u3057\
    \u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param k \u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n     * @param x \u65B0\u3057\u3044\u5024\n   \
    \  * @return PersistentArray \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\
    \u308F\u3089\u306A\u3044)\n     */\n    PersistentArray set(int k, const T& x)\
    \ const {\n        assert(0 <= k && k < n);\n        std::vector<int> path(height);\n\
    \        int t = root;\n        for (int h = height - 1; h >= 0; h--) {\n    \
    \        path[h] = t;\n            t = pool->child[t][k >> h & 1];\n        }\n\
    \        t = pool->make_leaf(x);\n        for (int h = 0; h < height; h++) {\n\
    \            std::array<int, 2> c = pool->child[path[h]];\n            c[k >>\
    \ h & 1] = t;\n            t = pool->make_node(c[0], c[1]);\n        }\n     \
    \   return PersistentArray(pool, n, height, t);\n    }\n    /**\n     * @brief\
    \ [l, r)\u306E\u533A\u9593\u3092\u5225\u306E\u7248\u306E\u5024\u306B\u3057\u305F\
    \u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param other \u5199\
    \u3059\u5143\u306E\u7248 (\u81EA\u8EAB\u3068\u540C\u3058\u914D\u5217\u304B\u3089\
    \u4F5C\u3063\u305F\u3082\u306E)\n     * @param l \u534A\u958B\u533A\u9593\u306E\
    \u958B\u59CB\n     * @param r \u534A\u958B\u533A\u9593\u306E\u7D42\u7AEF 0<=l<=r<=n\n\
    \     * @return PersistentArray \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u3082 other\
    \ \u3082\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentArray copy(const\
    \ PersistentArray& other, int l, int r) const {\n        assert(pool == other.pool);\n\
    \        assert(0 <= l && l <= r && r <= n);\n        if (l == r) return *this;\n\
    \        return PersistentArray(pool, n, height, copy_rec(root, other.root, 0,\
    \ height, l, r));\n    }\n\n    /**\n     * @brief \u5185\u5BB9\u3092\u51FA\u529B\
    \u3059\u308B\n     *\n     * @tparam CharT \u51FA\u529B\u30B9\u30C8\u30EA\u30FC\
    \u30E0\u306E\u6587\u5B57\u578B\n     * @tparam Traits \u51FA\u529B\u30B9\u30C8\
    \u30EA\u30FC\u30E0\u306E\u6587\u5B57\u578B\u7279\u6027\n     * @param os \u51FA\
    \u529B\u30B9\u30C8\u30EA\u30FC\u30E0\n     * @param rhs \u6C38\u7D9A\u914D\u5217\
    \n     * @return std::basic_ostream<CharT, Traits>& \u51FA\u529B\u30B9\u30C8\u30EA\
    \u30FC\u30E0\n     */\n    template <class CharT, class Traits>\n    friend std::basic_ostream<CharT,\
    \ Traits>& operator<<(std::basic_ostream<CharT, Traits>& os, const PersistentArray&\
    \ rhs) {\n        for (int i = 0; i < rhs.n; i++) {\n            if (i != 0) os\
    \ << CharT(' ');\n            os << rhs[i];\n        }\n        return os;\n \
    \   }\n\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u4E26\
    \u3079\u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<T> to_vector()\
    \ const {\n        std::vector<T> res(n);\n        for (int i = 0; i < n; i++)\
    \ res[i] = get(i);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/data_structures/persistent-array.hpp
  requiredBy:
  - src/data_structures/persistent-unionfind.hpp
  timestamp: '2026-10-15 02:28:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unittest/persistent-unionfind.test.cpp
  - test/unittest/persistent-array.test.cpp
  - test/yosupo/persistent-unionfind.test.cpp
documentation_of: src/data_structures/persistent-array.hpp
layout: document
title: "\u6C38\u7D9A\u914D\u5217"
---

過去の版を残したまま更新できる配列です。`set` は元の版を変えずに新しい版を返し、新しく作るノードは $O(\log n)$ 個です。版のコピーは $O(1)$ です。

```cpp
PersistentArray<int> a0(n, -1);
auto a1 = a0.set(3, 10);   // a0 はそのまま
a1[3];                     // 10
a0[3];                     // -1
auto a2 = a0.copy(a1, 2, 5);  // [2, 5) を a1 の値にした版
```

`copy(other, l, r)` の `other` は、自身と同じ配列 (同じコンストラクタの呼び出しから更新して作った版) でなければなりません。ノードを共有するので、区間の長さによらず $O(\log n)$ です。

同じ配列から作った版はノードを共有します。ノードは削除しないので、メモリは更新の回数に比例して増えます。`get` は参照ではなく値を返します。

## メンバ関数

| 関数 | 説明 | 計算量 |
|---|---|---|
| `PersistentArray<T>(n, x = T())` | 要素数 `n`、すべて `x` で初期化 (同じ値の部分木を共有する) | $O(\log n)$ |
| `PersistentArray(v)` | `v` で初期化 | $O(n)$ |
| `size()` | 要素数 | $O(1)$ |
| `get(k)` / `a[k]` | `k` 番目の値 | $O(\log n)$ |
| `set(k, x)` | `k` 番目を `x` にした新しい版を返す | $O(\log n)$ |
| `copy(other, l, r)` | 区間 $[l, r)$ を `other` の値にした新しい版を返す | $O(\log n)$ |
| `to_vector()` | すべての要素を並べた `std::vector<T>` | $O(n \log n)$ |
| `os << a` | 全要素を空白区切りで出力 | $O(n \log n)$ |

## 関連

- 区間の積も必要なら [永続セグメント木](persistent-segtree.hpp)
- これを使った [永続UnionFind](persistent-unionfind.hpp)
