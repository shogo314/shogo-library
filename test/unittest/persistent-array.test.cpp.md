---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-array.hpp
    title: "\u6C38\u7D9A\u914D\u5217"
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
  bundledCode: "#line 1 \"test/unittest/persistent-array.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ PersistentArray \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\u306B\
    \u914D\u5217\u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\
    \u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\u3001\
    \u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\u3092\
    \u78BA\u304B\u3081\u308B (\u533A\u9593\u30B3\u30D4\u30FC\u3092\u542B\u3080)\n\
    // \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\u3066\
    \u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\n\n\
    #line 2 \"src/data_structures/persistent-array.hpp\"\n\n/**\n * @file persistent-array.hpp\n\
    \ * @brief \u6C38\u7D9A\u914D\u5217\n */\n\n#include <array>\n#include <cassert>\n\
    #include <memory>\n#include <ostream>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u6C38\u7D9A\u914D\u5217\n *\n * \u66F4\u65B0\u3059\u308B\u3068\
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
    \    }\n};\n#line 8 \"test/unittest/persistent-array.test.cpp\"\n\n#include <iostream>\n\
    #include <random>\n#include <sstream>\n#include <string>\n#line 15 \"test/unittest/persistent-array.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 20 + 1;\n     \
    \   std::vector<std::vector<std::string>> naive;\n        std::vector<PersistentArray<std::string>>\
    \ arr;\n        switch (rep % 3) {\n            case 0:\n                arr.emplace_back(n);\n\
    \                naive.emplace_back(n);\n                break;\n            case\
    \ 1:\n                arr.emplace_back(n, \"x\");\n                naive.emplace_back(n,\
    \ \"x\");\n                break;\n            default: {\n                std::vector<std::string>\
    \ v(n);\n                for (auto& s : v) s = std::to_string(rng() % 100);\n\
    \                arr.emplace_back(v);\n                naive.push_back(v);\n \
    \               break;\n            }\n        }\n        for (int t = 0; t <\
    \ 40; t++) {\n            int ver = rng() % arr.size();\n            int k = rng()\
    \ % n;\n            int op = rng() % 3;\n            if (op == 0) {\n        \
    \        std::string x = std::to_string(rng() % 100);\n                arr.push_back(arr[ver].set(k,\
    \ x));\n                naive.push_back(naive[ver]);\n                naive.back()[k]\
    \ = x;\n            } else if (op == 1) {\n                int src = rng() % arr.size();\n\
    \                int l = rng() % (n + 1), r = rng() % (n + 1);\n             \
    \   if (l > r) std::swap(l, r);\n                arr.push_back(arr[ver].copy(arr[src],\
    \ l, r));\n                naive.push_back(naive[ver]);\n                for (int\
    \ i = l; i < r; i++) naive.back()[i] = naive[src][i];\n            } else {\n\
    \                if (arr[ver].get(k) != naive[ver][k] || arr[ver][k] != naive[ver][k])\
    \ ok = false;\n            }\n        }\n        // \u3059\u3079\u3066\u306E\u7248\
    \u304C\u3001\u4F5C\u3063\u305F\u3068\u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\
    \u304B\n        for (int i = 0; i < static_cast<int>(arr.size()); i++) {\n   \
    \         if (arr[i].size() != n) ok = false;\n            if (arr[i].to_vector()\
    \ != naive[i]) ok = false;\n        }\n        std::ostringstream os, expect;\n\
    \        os << arr.back();\n        for (int i = 0; i < n; i++) expect << (i ?\
    \ \" \" : \"\") << naive.back()[i];\n        if (os.str() != expect.str()) ok\
    \ = false;\n    }\n\n    // \u8981\u7D20\u6570\u304C\u5927\u304D\u304F\u3066\u3082\
    \u540C\u3058\u5024\u306E\u6728\u306F O(log n) \u3067\u4F5C\u308C\u308B\n    {\n\
    \        PersistentArray<int> big(1000000000, 7);\n        auto b1 = big.set(123456789,\
    \ 1);\n        if (big[123456789] != 7 || b1[123456789] != 1 || b1[123456788]\
    \ != 7 || b1.size() != 1000000000) ok = false;\n        auto b2 = big.set(5, 0).copy(b1,\
    \ 0, 1000000000);\n        if (b2[5] != 7 || b2[123456789] != 1) ok = false;\n\
    \        PersistentArray<int> empty;\n        if (empty.size() != 0 || !empty.to_vector().empty())\
    \ ok = false;\n        PersistentArray<int> empty2(std::vector<int>{});\n    \
    \    if (empty2.size() != 0 || !empty2.to_vector().empty()) ok = false;\n    }\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PersistentArray \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\
    \u306B\u914D\u5217\u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\
    \u8F03\u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\
    \u3001\u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u3092\u78BA\u304B\u3081\u308B (\u533A\u9593\u30B3\u30D4\u30FC\u3092\u542B\u3080\
    )\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\u3001\u3059\u3079\
    \u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\u529B\u3059\u308B\
    \n\n#include \"../../src/data_structures/persistent-array.hpp\"\n\n#include <iostream>\n\
    #include <random>\n#include <sstream>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 3000 && ok; rep++) {\n        int n = rng() % 20\
    \ + 1;\n        std::vector<std::vector<std::string>> naive;\n        std::vector<PersistentArray<std::string>>\
    \ arr;\n        switch (rep % 3) {\n            case 0:\n                arr.emplace_back(n);\n\
    \                naive.emplace_back(n);\n                break;\n            case\
    \ 1:\n                arr.emplace_back(n, \"x\");\n                naive.emplace_back(n,\
    \ \"x\");\n                break;\n            default: {\n                std::vector<std::string>\
    \ v(n);\n                for (auto& s : v) s = std::to_string(rng() % 100);\n\
    \                arr.emplace_back(v);\n                naive.push_back(v);\n \
    \               break;\n            }\n        }\n        for (int t = 0; t <\
    \ 40; t++) {\n            int ver = rng() % arr.size();\n            int k = rng()\
    \ % n;\n            int op = rng() % 3;\n            if (op == 0) {\n        \
    \        std::string x = std::to_string(rng() % 100);\n                arr.push_back(arr[ver].set(k,\
    \ x));\n                naive.push_back(naive[ver]);\n                naive.back()[k]\
    \ = x;\n            } else if (op == 1) {\n                int src = rng() % arr.size();\n\
    \                int l = rng() % (n + 1), r = rng() % (n + 1);\n             \
    \   if (l > r) std::swap(l, r);\n                arr.push_back(arr[ver].copy(arr[src],\
    \ l, r));\n                naive.push_back(naive[ver]);\n                for (int\
    \ i = l; i < r; i++) naive.back()[i] = naive[src][i];\n            } else {\n\
    \                if (arr[ver].get(k) != naive[ver][k] || arr[ver][k] != naive[ver][k])\
    \ ok = false;\n            }\n        }\n        // \u3059\u3079\u3066\u306E\u7248\
    \u304C\u3001\u4F5C\u3063\u305F\u3068\u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\
    \u304B\n        for (int i = 0; i < static_cast<int>(arr.size()); i++) {\n   \
    \         if (arr[i].size() != n) ok = false;\n            if (arr[i].to_vector()\
    \ != naive[i]) ok = false;\n        }\n        std::ostringstream os, expect;\n\
    \        os << arr.back();\n        for (int i = 0; i < n; i++) expect << (i ?\
    \ \" \" : \"\") << naive.back()[i];\n        if (os.str() != expect.str()) ok\
    \ = false;\n    }\n\n    // \u8981\u7D20\u6570\u304C\u5927\u304D\u304F\u3066\u3082\
    \u540C\u3058\u5024\u306E\u6728\u306F O(log n) \u3067\u4F5C\u308C\u308B\n    {\n\
    \        PersistentArray<int> big(1000000000, 7);\n        auto b1 = big.set(123456789,\
    \ 1);\n        if (big[123456789] != 7 || b1[123456789] != 1 || b1[123456788]\
    \ != 7 || b1.size() != 1000000000) ok = false;\n        auto b2 = big.set(5, 0).copy(b1,\
    \ 0, 1000000000);\n        if (b2[5] != 7 || b2[123456789] != 1) ok = false;\n\
    \        PersistentArray<int> empty;\n        if (empty.size() != 0 || !empty.to_vector().empty())\
    \ ok = false;\n        PersistentArray<int> empty2(std::vector<int>{});\n    \
    \    if (empty2.size() != 0 || !empty2.to_vector().empty()) ok = false;\n    }\n\
    \n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/persistent-array.hpp
  isVerificationFile: true
  path: test/unittest/persistent-array.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:08:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/persistent-array.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/persistent-array.test.cpp
- /verify/test/unittest/persistent-array.test.cpp.html
title: test/unittest/persistent-array.test.cpp
---
