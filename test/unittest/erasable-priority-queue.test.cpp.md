---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/data_structures/erasable-priority-queue.hpp
    title: "\u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\
      \u30FC"
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
  bundledCode: "#line 1 \"test/unittest/erasable-priority-queue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// ErasablePriorityQueue \u3092 std::multiset \u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#line 2 \"src/data_structures/erasable-priority-queue.hpp\"\
    \n\n/**\n * @file erasable-priority-queue.hpp\n * @brief \u524A\u9664\u53EF\u80FD\
    \u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n */\n\n#include <cassert>\n\
    #include <functional>\n#include <queue>\n#include <vector>\n\n/**\n * @brief \u524A\
    \u9664\u53EF\u80FD\u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n *\n\
    \ * std::priority_queue \u3068\u540C\u3058\u304F\u3001\u65E2\u5B9A\u3067\u306F\
    \u6700\u5927\u306E\u8981\u7D20\u3092\u53D6\u308A\u51FA\u3059\n * \u524A\u9664\u3059\
    \u308B\u8981\u7D20\u3092\u5225\u306E\u30D2\u30FC\u30D7\u306B\u5165\u308C\u3066\
    \u304A\u304D\u3001\u5148\u982D\u306B\u6765\u305F\u3068\u304D\u306B\u53D6\u308A\
    \u9664\u304F\u3002\u5404\u64CD\u4F5C\u306F\u511F\u5374 O(log n)\n * \u4F8B:\n\
    \ * ErasablePriorityQueue<int> pq;\n * pq.push(3); pq.push(5); pq.erase(5); pq.top();\
    \  // 3\n *\n * @tparam T \u8981\u7D20\u306E\u578B\n * @tparam Compare \u6BD4\u8F03\
    \u95A2\u6570\u3002std::greater<T> \u306B\u3059\u308B\u3068\u6700\u5C0F\u306E\u8981\
    \u7D20\u3092\u53D6\u308A\u51FA\u3059\n */\ntemplate <typename T, typename Compare\
    \ = std::less<T>>\nclass ErasablePriorityQueue {\n    std::priority_queue<T, std::vector<T>,\
    \ Compare> que, del;\n    Compare comp;\n\n    bool equivalent(const T& x, const\
    \ T& y) const { return !comp(x, y) && !comp(y, x); }\n    // \u5148\u982D\u304C\
    \u524A\u9664\u4E88\u5B9A\u306A\u3089\u53D6\u308A\u9664\u304F\n    void normalize()\
    \ {\n        while (!del.empty() && equivalent(que.top(), del.top())) {\n    \
    \        que.pop();\n            del.pop();\n        }\n    }\n\n   public:\n\
    \    explicit ErasablePriorityQueue(Compare comp = Compare()) : que(comp), del(comp),\
    \ comp(comp) {}\n\n    /**\n     * @brief \u8981\u7D20\u6570\n     */\n    long\
    \ long size() const { return que.size() - del.size(); }\n    bool empty() const\
    \ { return size() == 0; }\n\n    /**\n     * @brief x \u3092\u8FFD\u52A0\u3059\
    \u308B\n     */\n    void push(const T& x) {\n        que.push(x);\n        normalize();\n\
    \    }\n    /**\n     * @brief x \u3092 1 \u3064\u524A\u9664\u3059\u308B\u3002\
    x \u306F\u542B\u307E\u308C\u3066\u3044\u308B\u3053\u3068 (\u542B\u307E\u308C\u3066\
    \u3044\u306A\u3044\u8981\u7D20\u3092\u524A\u9664\u3059\u308B\u3068\u58CA\u308C\
    \u308B)\n     * \u6BD4\u8F03\u95A2\u6570\u3067\u7B49\u3057\u3044\u8981\u7D20\u306F\
    \u533A\u5225\u3057\u306A\u3044\n     */\n    void erase(const T& x) {\n      \
    \  del.push(x);\n        normalize();\n    }\n    /**\n     * @brief \u5148\u982D\
    \ (\u65E2\u5B9A\u3067\u306F\u6700\u5927) \u306E\u8981\u7D20\n     */\n    const\
    \ T& top() const {\n        assert(!empty());\n        return que.top();\n   \
    \ }\n    /**\n     * @brief \u5148\u982D\u306E\u8981\u7D20\u3092\u524A\u9664\u3059\
    \u308B\n     */\n    void pop() {\n        assert(!empty());\n        que.pop();\n\
    \        normalize();\n    }\n};\n#line 7 \"test/unittest/erasable-priority-queue.test.cpp\"\
    \n\n#line 9 \"test/unittest/erasable-priority-queue.test.cpp\"\n#include <iostream>\n\
    #include <iterator>\n#include <random>\n#include <set>\n#line 14 \"test/unittest/erasable-priority-queue.test.cpp\"\
    \n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n    for (int\
    \ rep = 0; rep < 1000 && ok; rep++) {\n        ErasablePriorityQueue<int> max_q;\n\
    \        ErasablePriorityQueue<int, std::greater<int>> min_q;\n        std::multiset<int>\
    \ st;\n        for (int t = 0; t < 100; t++) {\n            int op = rng() % 4;\n\
    \            if (op <= 1 || st.empty()) {\n                int x = rng() % 10;\n\
    \                max_q.push(x);\n                min_q.push(x);\n            \
    \    st.insert(x);\n            } else if (op == 2) {\n                // \u542B\
    \u307E\u308C\u3066\u3044\u308B\u8981\u7D20\u3092\u30E9\u30F3\u30C0\u30E0\u306B\
    \u9078\u3093\u3067\u524A\u9664\u3059\u308B\n                auto it = std::next(st.begin(),\
    \ rng() % st.size());\n                max_q.erase(*it);\n                min_q.erase(*it);\n\
    \                st.erase(it);\n            } else {\n                if (rng()\
    \ % 2) {\n                    max_q.pop();\n                    min_q.erase(*st.rbegin());\n\
    \                    st.erase(std::prev(st.end()));\n                } else {\n\
    \                    min_q.pop();\n                    max_q.erase(*st.begin());\n\
    \                    st.erase(st.begin());\n                }\n            }\n\
    \            if (max_q.size() != static_cast<int>(st.size()) || min_q.size() !=\
    \ static_cast<int>(st.size())) ok = false;\n            if (max_q.empty() != st.empty()\
    \ || min_q.empty() != st.empty()) ok = false;\n            if (!st.empty() &&\
    \ (max_q.top() != *st.rbegin() || min_q.top() != *st.begin())) ok = false;\n \
    \       }\n    }\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// ErasablePriorityQueue \u3092 std::multiset \u3068\u30E9\u30F3\u30C0\u30E0\
    \u306B\u6BD4\u8F03\u3059\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\
    \u305A\u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\
    \u51FA\u529B\u3059\u308B\n\n#include \"../../src/data_structures/erasable-priority-queue.hpp\"\
    \n\n#include <functional>\n#include <iostream>\n#include <iterator>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nint main() {\n    std::mt19937\
    \ rng(314);\n    bool ok = true;\n    for (int rep = 0; rep < 1000 && ok; rep++)\
    \ {\n        ErasablePriorityQueue<int> max_q;\n        ErasablePriorityQueue<int,\
    \ std::greater<int>> min_q;\n        std::multiset<int> st;\n        for (int\
    \ t = 0; t < 100; t++) {\n            int op = rng() % 4;\n            if (op\
    \ <= 1 || st.empty()) {\n                int x = rng() % 10;\n               \
    \ max_q.push(x);\n                min_q.push(x);\n                st.insert(x);\n\
    \            } else if (op == 2) {\n                // \u542B\u307E\u308C\u3066\
    \u3044\u308B\u8981\u7D20\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u9078\u3093\u3067\
    \u524A\u9664\u3059\u308B\n                auto it = std::next(st.begin(), rng()\
    \ % st.size());\n                max_q.erase(*it);\n                min_q.erase(*it);\n\
    \                st.erase(it);\n            } else {\n                if (rng()\
    \ % 2) {\n                    max_q.pop();\n                    min_q.erase(*st.rbegin());\n\
    \                    st.erase(std::prev(st.end()));\n                } else {\n\
    \                    min_q.pop();\n                    max_q.erase(*st.begin());\n\
    \                    st.erase(st.begin());\n                }\n            }\n\
    \            if (max_q.size() != static_cast<int>(st.size()) || min_q.size() !=\
    \ static_cast<int>(st.size())) ok = false;\n            if (max_q.empty() != st.empty()\
    \ || min_q.empty() != st.empty()) ok = false;\n            if (!st.empty() &&\
    \ (max_q.top() != *st.rbegin() || min_q.top() != *st.begin())) ok = false;\n \
    \       }\n    }\n\n    if (ok)\n        std::cout << \"Hello World\" << std::endl;\n\
    \    else\n        std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/data_structures/erasable-priority-queue.hpp
  isVerificationFile: true
  path: test/unittest/erasable-priority-queue.test.cpp
  requiredBy: []
  timestamp: '2026-10-19 12:08:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/erasable-priority-queue.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/erasable-priority-queue.test.cpp
- /verify/test/unittest/erasable-priority-queue.test.cpp.html
title: test/unittest/erasable-priority-queue.test.cpp
---
