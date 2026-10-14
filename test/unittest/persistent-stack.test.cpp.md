---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/persistent-stack.hpp
    title: "\u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF"
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
  bundledCode: "#line 1 \"test/unittest/persistent-stack.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\n\n//\
    \ PersistentStack \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\u306B\
    \ std::vector \u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\u8F03\
    \u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\u3001\
    \u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\u3092\
    \u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#line 2 \"src/data_structures/persistent-stack.hpp\"\n\n\
    /**\n * @file persistent-stack.hpp\n * @brief \u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\
    \n */\n\n#include <cassert>\n#include <memory>\n#include <utility>\n#include <vector>\n\
    \n/**\n * @brief \u6C38\u7D9A\u30B9\u30BF\u30C3\u30AF\n *\n * \u66F4\u65B0\u3059\
    \u308B\u3068\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3057\u3001\u5143\u306E\u7248\
    \u306F\u5909\u308F\u3089\u306A\u3044\u3002\u540C\u3058\u30B9\u30BF\u30C3\u30AF\
    \u304B\u3089\u4F5C\u3063\u305F\u7248\u306F\u30CE\u30FC\u30C9\u3092\u5171\u6709\
    \u3059\u308B\n * \u4F8B:\n * PersistentStack<int> s0;\n * auto s1 = s0.push(1).push(2);\
    \  // s0 \u306F\u305D\u306E\u307E\u307E\n * s1.top();                      //\
    \ 2\n * s1.pop().top();                // 1\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n */\ntemplate <typename T>\nclass PersistentStack {\n    // \u3059\u3079\
    \u3066\u306E\u7248\u306E\u30CE\u30FC\u30C9\u3092\u6301\u3064\u3002\u30CE\u30FC\
    \u30C9\u306F\u524A\u9664\u3057\u306A\u3044\n    struct Pool {\n        std::vector<T>\
    \ val;\n        std::vector<int> parent;  // 1 \u3064\u4E0B\u306E\u8981\u7D20\u306E\
    \u30CE\u30FC\u30C9 (\u4E00\u756A\u4E0B\u306A\u3089 -1)\n        int make_node(const\
    \ T& x, int p) {\n            val.push_back(x);\n            parent.push_back(p);\n\
    \            return int(val.size()) - 1;\n        }\n    };\n\n    std::shared_ptr<Pool>\
    \ pool;  // \u4E00\u5EA6\u3082 push \u3057\u3066\u3044\u306A\u3051\u308C\u3070\
    \ nullptr\n    int top_node, n;             // \u7A7A\u306A\u3089 top_node = -1\n\
    \n    PersistentStack(std::shared_ptr<Pool> pool, int top_node, int n) : pool(std::move(pool)),\
    \ top_node(top_node), n(n) {}\n\n   public:\n    /**\n     * @brief \u7A7A\u306E\
    \u30B9\u30BF\u30C3\u30AF\u3092\u4F5C\u308B\n     */\n    PersistentStack() : pool(nullptr),\
    \ top_node(-1), n(0) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\n     */\n    long long size() const { return n; }\n    /**\n     * @brief\
    \ \u7A7A\u304B\u3069\u3046\u304B\u3092\u8FD4\u3059\n     */\n    bool empty()\
    \ const { return n == 0; }\n\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\
    \u7D20\u3092\u8FD4\u3059\n     */\n    T top() const {\n        assert(!empty());\n\
    \        return pool->val[top_node];\n    }\n    /**\n     * @brief x\u3092\u7A4D\
    \u3093\u3060\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\n     *\n     * @param\
    \ x \u7A4D\u3080\u5024\n     * @return PersistentStack \u65B0\u3057\u3044\u7248\
    \ (\u81EA\u8EAB\u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack\
    \ push(const T& x) const {\n        std::shared_ptr<Pool> p = pool ? pool : std::make_shared<Pool>();\n\
    \        int t = p->make_node(x, top_node);\n        return PersistentStack(std::move(p),\
    \ t, n + 1);\n    }\n    /**\n     * @brief \u4E00\u756A\u4E0A\u306E\u8981\u7D20\
    \u3092\u53D6\u308A\u9664\u3044\u305F\u65B0\u3057\u3044\u7248\u3092\u8FD4\u3059\
    \n     *\n     * @return PersistentStack \u65B0\u3057\u3044\u7248 (\u81EA\u8EAB\
    \u306F\u5909\u308F\u3089\u306A\u3044)\n     */\n    PersistentStack pop() const\
    \ {\n        assert(!empty());\n        return PersistentStack(pool, pool->parent[top_node],\
    \ n - 1);\n    }\n\n    /**\n     * @brief \u3059\u3079\u3066\u306E\u8981\u7D20\
    \u3092\u4E0B\u304B\u3089\u9806\u306B\u4E26\u3079\u305F\u5217\u3092\u8FD4\u3059\
    \n     */\n    std::vector<T> to_vector() const {\n        std::vector<T> res(n);\n\
    \        int t = top_node;\n        for (int i = n - 1; i >= 0; i--) {\n     \
    \       res[i] = pool->val[t];\n            t = pool->parent[t];\n        }\n\
    \        return res;\n    }\n};\n#line 8 \"test/unittest/persistent-stack.test.cpp\"\
    \n\n#include <iostream>\n#include <random>\n#line 12 \"test/unittest/persistent-stack.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 2000 && ok; rep++) {\n        std::vector<PersistentStack<int>>\
    \ st(1);\n        std::vector<std::vector<int>> naive(1);\n        for (int t\
    \ = 0; t < 60; t++) {\n            int ver = rng() % st.size();\n            int\
    \ op = rng() % 3;\n            if (op == 0 || naive[ver].empty()) {\n        \
    \        int x = rng() % 100;\n                st.push_back(st[ver].push(x));\n\
    \                naive.push_back(naive[ver]);\n                naive.back().push_back(x);\n\
    \            } else if (op == 1) {\n                st.push_back(st[ver].pop());\n\
    \                naive.push_back(naive[ver]);\n                naive.back().pop_back();\n\
    \            } else {\n                if (st[ver].top() != naive[ver].back())\
    \ ok = false;\n            }\n        }\n        // \u3059\u3079\u3066\u306E\u7248\
    \u304C\u3001\u4F5C\u3063\u305F\u3068\u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\
    \u304B\n        for (int i = 0; i < int(st.size()); i++) {\n            const\
    \ auto& v = naive[i];\n            if (st[i].size() != int(v.size()) || st[i].empty()\
    \ != v.empty()) ok = false;\n            if (st[i].to_vector() != v) ok = false;\n\
    \            if (!v.empty() && st[i].top() != v.back()) ok = false;\n        }\n\
    \    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// PersistentStack \u3092\u611A\u76F4\u306A\u5B9F\u88C5 (\u7248\u3054\u3068\
    \u306B std::vector \u3092\u6301\u3064) \u3068\u30E9\u30F3\u30C0\u30E0\u306B\u6BD4\
    \u8F03\u3059\u308B\n// \u53E4\u3044\u7248\u304B\u3089\u66F4\u65B0\u3057\u3066\u3082\
    \u3001\u307B\u304B\u306E\u7248\u304C\u5909\u308F\u3089\u306A\u3044\u3053\u3068\
    \u3092\u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/persistent-stack.hpp\"\
    \n\n#include <iostream>\n#include <random>\n#include <vector>\n\nint main() {\n\
    \    std::mt19937 rng(314);\n    bool ok = true;\n    for (int rep = 0; rep <\
    \ 2000 && ok; rep++) {\n        std::vector<PersistentStack<int>> st(1);\n   \
    \     std::vector<std::vector<int>> naive(1);\n        for (int t = 0; t < 60;\
    \ t++) {\n            int ver = rng() % st.size();\n            int op = rng()\
    \ % 3;\n            if (op == 0 || naive[ver].empty()) {\n                int\
    \ x = rng() % 100;\n                st.push_back(st[ver].push(x));\n         \
    \       naive.push_back(naive[ver]);\n                naive.back().push_back(x);\n\
    \            } else if (op == 1) {\n                st.push_back(st[ver].pop());\n\
    \                naive.push_back(naive[ver]);\n                naive.back().pop_back();\n\
    \            } else {\n                if (st[ver].top() != naive[ver].back())\
    \ ok = false;\n            }\n        }\n        // \u3059\u3079\u3066\u306E\u7248\
    \u304C\u3001\u4F5C\u3063\u305F\u3068\u304D\u306E\u5185\u5BB9\u306E\u307E\u307E\
    \u304B\n        for (int i = 0; i < int(st.size()); i++) {\n            const\
    \ auto& v = naive[i];\n            if (st[i].size() != int(v.size()) || st[i].empty()\
    \ != v.empty()) ok = false;\n            if (st[i].to_vector() != v) ok = false;\n\
    \            if (!v.empty() && st[i].top() != v.back()) ok = false;\n        }\n\
    \    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/persistent-stack.hpp
  isVerificationFile: true
  path: test/unittest/persistent-stack.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 07:35:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/persistent-stack.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/persistent-stack.test.cpp
- /verify/test/unittest/persistent-stack.test.cpp.html
title: test/unittest/persistent-stack.test.cpp
---
