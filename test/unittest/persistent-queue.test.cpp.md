---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-queue.hpp
    title: "\u6C38\u7D9A\u30AD\u30E5\u30FC"
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
  bundledCode: "#line 1 \"test/unittest/persistent-queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ PersistentQueue \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\u306B\
    \ std::deque \u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\
    \u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\u3001\
    \u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\u3092\
    \u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/data_structures/persistent-queue.hpp\"\n\n\
    /**\n * @file persistent-queue.hpp\n * @brief \u6C38\u7D9A\u30AD\u30E5\u30FC\n\
    \ */\n\n#include <cassert>\n#include <memory>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u6C38\u7D9A\u30AD\u30E5\u30FC\n *\n * \u66F4\u65B0\u3059\u308B\
    \u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\u306F\
    \u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u30AD\u30E5\u30FC\u304B\u3089\
    \u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\u3059\u308B\
    \n * \u8981\u7D20\u3092\u6728\u306E\u6839\u304B\u3089\u672B\u5C3E\u3078\u306E\u30D1\
    \u30B9\u3068\u3057\u3066\u6301\u3061\u3001\u5148\u982D\u306F\u30B8\u30E3\u30F3\
    \u30D7\u30DD\u30A4\u30F3\u30BF\u3067\u7956\u5148\u3092\u305F\u3069\u3063\u3066\
    \u6C42\u3081\u308B\n * \u4F8B:\n * PersistentQueue<int> q0;\n * auto q1 = q0.push(1).push(2);\
    \  // q0 \u306F\u305D\u306E\u307E\u307E\n * q1.front();                    //\
    \ 1\n * q1.pop().front();              // 2\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n */\ntemplate <typename T>\nclass PersistentQueue {\n    // \u3059\u3079\
    \u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\
    \u30C9\u306F\u524A\u9664\u3057\u306A\u3044\u3002\u30CE\u30FC\u30C9 0 \u306F\u6839\
    \ (\u8981\u7D20\u3092\u6301\u305F\u306A\u3044)\n    struct Pool {\n        std::vector<T>\
    \ val;\n        std::vector<int> parent, jump, depth;\n        Pool() : val(1),\
    \ parent{0}, jump{0}, depth{0} {}\n        int make_node(const T& x, int p) {\n\
    \            // \u30B8\u30E3\u30F3\u30D7\u306E\u9577\u3055\u304C 1, 1, 3, 1, 1,\
    \ 3, 7, ... (skew binary) \u306B\u306A\u308B\u3088\u3046\u306B\u5F35\u308B\n \
    \           int j = jump[p];\n            int nj = depth[p] - depth[j] == depth[j]\
    \ - depth[jump[j]] ? jump[j] : p;\n            val.push_back(x);\n           \
    \ parent.push_back(p);\n            jump.push_back(nj);\n            depth.push_back(depth[p]\
    \ + 1);\n            return static_cast<int>(val.size()) - 1;\n        }\n   \
    \     // t \u306E\u7956\u5148\u3067\u6DF1\u3055\u304C d \u306E\u3082\u306E\n \
    \       int ancestor(int t, int d) const {\n            while (depth[t] > d) t\
    \ = depth[jump[t]] >= d ? jump[t] : parent[t];\n            return t;\n      \
    \  }\n    };\n\n    std::shared_ptr<Pool> pool;  // \u4E00\u5EA6\u3082 push \u3057\
    \u3066\u3044\u306A\u3051\u308C\u3070 nullptr\n    int back_node, n;          \
    \  // \u8981\u7D20\u306F back_node \u304B\u3089 n \u500B\u4E0A\u307E\u3067\u306E\
    \u30CE\u30FC\u30C9\n\n    PersistentQueue(std::shared_ptr<Pool> pool, int back_node,\
    \ int n) : pool(std::move(pool)), back_node(back_node), n(n) {}\n\n   public:\n\
    \    /**\n     * @brief \u7A7A\u306E\u30AD\u30E5\u30FC\u3092\u4F5C\u308B\n   \
    \  */\n    PersistentQueue() : pool(nullptr), back_node(0), n(0) {}\n\n    /**\n\
    \     * @brief \u8981\u7D20\u6570\u3092\u8FD4\u3059\n     */\n    long long size()\
    \ const { return n; }\n    /**\n     * @brief \u7A7A\u304B\u3069\u3046\u304B\u3092\
    \u8FD4\u3059\n     */\n    bool empty() const { return n == 0; }\n\n    /**\n\
    \     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u8FD4\u3059\n     */\n   \
    \ T front() const {\n        assert(!empty());\n        return pool->val[pool->ancestor(back_node,\
    \ pool->depth[back_node] - n + 1)];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306E\u8981\u7D20\u3092\u8FD4\u3059\n     */\n    T back() const {\n        assert(!empty());\n\
    \        return pool->val[back_node];\n    }\n    /**\n     * @brief \u672B\u5C3E\
    \u306Bx\u3092\u52A0\u3048\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n  \
    \   *\n     * @param x \u52A0\u3048\u308B\u5024\n     * @return PersistentQueue\
    \ \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n\
    \     */\n    PersistentQueue push(const T& x) const {\n        std::shared_ptr<Pool>\
    \ p = pool ? pool : std::make_shared<Pool>();\n        int t = p->make_node(x,\
    \ back_node);\n        return PersistentQueue(std::move(p), t, n + 1);\n    }\n\
    \    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u53D6\u308A\u9664\
    \u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @return\
    \ PersistentQueue \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\u306F\u5909\u308F\u3089\
    \u306A\u3044)\n     */\n    PersistentQueue pop() const {\n        assert(!empty());\n\
    \        return PersistentQueue(pool, back_node, n - 1);\n    }\n\n    /**\n \
    \    * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\u3092\u5148\u982D\u304B\u3089\
    \u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\n     */\n    std::vector<T>\
    \ to_vector() const {\n        std::vector<T> res(n);\n        int t = back_node;\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            res[i] = pool->val[t];\n\
    \            t = pool->parent[t];\n        }\n        return res;\n    }\n};\n\
    #line 8 \"test/unittest/persistent-queue.test.cpp\"\n\n#include <deque>\n#include\
    \ <iostream>\n#include <random>\n#line 13 \"test/unittest/persistent-queue.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        std::vector<PersistentQueue<int>>\
    \ que(1);\n        std::vector<std::deque<int>> naive(1);\n        for (int t\
    \ = 0; t < 60; t++) {\n            int ver = rng() % que.size();\n           \
    \ int op = rng() % 3;\n            if (op == 0 || naive[ver].empty()) {\n    \
    \            int x = rng() % 100;\n                que.push_back(que[ver].push(x));\n\
    \                naive.push_back(naive[ver]);\n                naive.back().push_back(x);\n\
    \            } else if (op == 1) {\n                que.push_back(que[ver].pop());\n\
    \                naive.push_back(naive[ver]);\n                naive.back().pop_front();\n\
    \            } else {\n                if (que[ver].front() != naive[ver].front()\
    \ || que[ver].back() != naive[ver].back()) ok = false;\n            }\n      \
    \  }\n        // \u3059\u3079\u3066\u306E\u7248\u304C\u3001\u4F5C\u3063\u305F\u3068\
    \u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\u304B\n        for (int i = 0; i <\
    \ int(que.size()); i++) {\n            const auto& d = naive[i];\n           \
    \ if (que[i].size() != int(d.size()) || que[i].empty() != d.empty()) ok = false;\n\
    \            if (que[i].to_vector() != std::vector<int>(d.begin(), d.end())) ok\
    \ = false;\n            if (!d.empty() && (que[i].front() != d.front() || que[i].back()\
    \ != d.back())) ok = false;\n        }\n    }\n\n    // \u9577\u3044\u30AD\u30E5\
    \u30FC\u3067\u3001\u5148\u982D\u3092 1 \u3064\u305A\u3064\u53D6\u308A\u9664\u304D\
    \u306A\u304C\u3089\u78BA\u304B\u3081\u308B\n    {\n        const int n = 200000;\n\
    \        PersistentQueue<int> q;\n        for (int i = 0; i < n; i++) q = q.push(i);\n\
    \        PersistentQueue<int> full = q;\n        for (int i = 0; i < n; i++) {\n\
    \            if (q.front() != i) ok = false;\n            q = q.pop();\n     \
    \   }\n        if (!q.empty() || full.size() != n || full.front() != 0 || full.back()\
    \ != n - 1) ok = false;\n        // \u7A7A\u306B\u306A\u3063\u305F\u7248\u306B\
    \u3082 push \u3067\u304D\u308B\n        q = q.push(-1);\n        if (q.front()\
    \ != -1 || q.size() != 1) ok = false;\n    }\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PersistentQueue \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\
    \u306B std::deque \u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\
    \u8F03\u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\
    \u3001\u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/persistent-queue.hpp\"\
    \n\n#include <deque>\n#include <iostream>\n#include <random>\n#include <vector>\n\
    \nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        std::vector<PersistentQueue<int>>\
    \ que(1);\n        std::vector<std::deque<int>> naive(1);\n        for (int t\
    \ = 0; t < 60; t++) {\n            int ver = rng() % que.size();\n           \
    \ int op = rng() % 3;\n            if (op == 0 || naive[ver].empty()) {\n    \
    \            int x = rng() % 100;\n                que.push_back(que[ver].push(x));\n\
    \                naive.push_back(naive[ver]);\n                naive.back().push_back(x);\n\
    \            } else if (op == 1) {\n                que.push_back(que[ver].pop());\n\
    \                naive.push_back(naive[ver]);\n                naive.back().pop_front();\n\
    \            } else {\n                if (que[ver].front() != naive[ver].front()\
    \ || que[ver].back() != naive[ver].back()) ok = false;\n            }\n      \
    \  }\n        // \u3059\u3079\u3066\u306E\u7248\u304C\u3001\u4F5C\u3063\u305F\u3068\
    \u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\u304B\n        for (int i = 0; i <\
    \ int(que.size()); i++) {\n            const auto& d = naive[i];\n           \
    \ if (que[i].size() != int(d.size()) || que[i].empty() != d.empty()) ok = false;\n\
    \            if (que[i].to_vector() != std::vector<int>(d.begin(), d.end())) ok\
    \ = false;\n            if (!d.empty() && (que[i].front() != d.front() || que[i].back()\
    \ != d.back())) ok = false;\n        }\n    }\n\n    // \u9577\u3044\u30AD\u30E5\
    \u30FC\u3067\u3001\u5148\u982D\u3092 1 \u3064\u305A\u3064\u53D6\u308A\u9664\u304D\
    \u306A\u304C\u3089\u78BA\u304B\u3081\u308B\n    {\n        const int n = 200000;\n\
    \        PersistentQueue<int> q;\n        for (int i = 0; i < n; i++) q = q.push(i);\n\
    \        PersistentQueue<int> full = q;\n        for (int i = 0; i < n; i++) {\n\
    \            if (q.front() != i) ok = false;\n            q = q.pop();\n     \
    \   }\n        if (!q.empty() || full.size() != n || full.front() != 0 || full.back()\
    \ != n - 1) ok = false;\n        // \u7A7A\u306B\u306A\u3063\u305F\u7248\u306B\
    \u3082 push \u3067\u304D\u308B\n        q = q.push(-1);\n        if (q.front()\
    \ != -1 || q.size() != 1) ok = false;\n    }\n\n    if (ok) std::cout << \"Hello\
    \ World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/persistent-queue.hpp
  isVerificationFile: true
  path: test/unittest/persistent-queue.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 05:13:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/persistent-queue.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/persistent-queue.test.cpp
- /verify/test/unittest/persistent-queue.test.cpp.html
title: test/unittest/persistent-queue.test.cpp
---
