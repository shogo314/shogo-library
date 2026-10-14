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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/yosupo/double-ended-priority-queue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n\n\
    #include <functional>\n#include <iostream>\n\n#line 2 \"src/data_structures/erasable-priority-queue.hpp\"\
    \n\n/**\n * @file erasable-priority-queue.hpp\n * @brief \u524A\u9664\u53EF\u80FD\
    \u306A\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n */\n\n#include <cassert>\n\
    #line 10 \"src/data_structures/erasable-priority-queue.hpp\"\n#include <queue>\n\
    #include <vector>\n\n/**\n * @brief \u524A\u9664\u53EF\u80FD\u306A\u512A\u5148\
    \u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\n *\n * std::priority_queue \u3068\u540C\u3058\
    \u304F\u3001\u65E2\u5B9A\u3067\u306F\u6700\u5927\u306E\u8981\u7D20\u3092\u53D6\
    \u308A\u51FA\u3059\n * \u524A\u9664\u3059\u308B\u8981\u7D20\u3092\u5225\u306E\u30D2\
    \u30FC\u30D7\u306B\u5165\u308C\u3066\u304A\u304D\u3001\u5148\u982D\u306B\u6765\
    \u305F\u3068\u304D\u306B\u53D6\u308A\u9664\u304F\u3002\u5404\u64CD\u4F5C\u306F\
    \u511F\u5374 O(log n)\n * \u4F8B:\n * ErasablePriorityQueue<int> pq;\n * pq.push(3);\
    \ pq.push(5); pq.erase(5); pq.top();  // 3\n *\n * @tparam T \u8981\u7D20\u306E\
    \u578B\n * @tparam Compare \u6BD4\u8F03\u95A2\u6570\u3002std::greater<T> \u306B\
    \u3059\u308B\u3068\u6700\u5C0F\u306E\u8981\u7D20\u3092\u53D6\u308A\u51FA\u3059\
    \n */\ntemplate <typename T, typename Compare = std::less<T>>\nclass ErasablePriorityQueue\
    \ {\n    std::priority_queue<T, std::vector<T>, Compare> que, del;\n    Compare\
    \ comp;\n\n    bool equivalent(const T& x, const T& y) const { return !comp(x,\
    \ y) && !comp(y, x); }\n    // \u5148\u982D\u304C\u524A\u9664\u4E88\u5B9A\u306A\
    \u3089\u53D6\u308A\u9664\u304F\n    void normalize() {\n        while (!del.empty()\
    \ && equivalent(que.top(), del.top())) {\n            que.pop();\n           \
    \ del.pop();\n        }\n    }\n\n   public:\n    explicit ErasablePriorityQueue(Compare\
    \ comp = Compare()) : que(comp), del(comp), comp(comp) {}\n\n    /**\n     * @brief\
    \ \u8981\u7D20\u6570\n     */\n    long long size() const { return que.size()\
    \ - del.size(); }\n    bool empty() const { return size() == 0; }\n\n    /**\n\
    \     * @brief x \u3092\u8FFD\u52A0\u3059\u308B\n     */\n    void push(const\
    \ T& x) {\n        que.push(x);\n        normalize();\n    }\n    /**\n     *\
    \ @brief x \u3092 1 \u3064\u524A\u9664\u3059\u308B\u3002x \u306F\u542B\u307E\u308C\
    \u3066\u3044\u308B\u3053\u3068 (\u542B\u307E\u308C\u3066\u3044\u306A\u3044\u8981\
    \u7D20\u3092\u524A\u9664\u3059\u308B\u3068\u58CA\u308C\u308B)\n     * \u6BD4\u8F03\
    \u95A2\u6570\u3067\u7B49\u3057\u3044\u8981\u7D20\u306F\u533A\u5225\u3057\u306A\
    \u3044\n     */\n    void erase(const T& x) {\n        del.push(x);\n        normalize();\n\
    \    }\n    /**\n     * @brief \u5148\u982D (\u65E2\u5B9A\u3067\u306F\u6700\u5927\
    ) \u306E\u8981\u7D20\n     */\n    const T& top() const {\n        assert(!empty());\n\
    \        return que.top();\n    }\n    /**\n     * @brief \u5148\u982D\u306E\u8981\
    \u7D20\u3092\u524A\u9664\u3059\u308B\n     */\n    void pop() {\n        assert(!empty());\n\
    \        que.pop();\n        normalize();\n    }\n};\n#line 7 \"test/yosupo/double-ended-priority-queue.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    // \u6700\u5927\u5024\u7528\u3068\
    \u6700\u5C0F\u5024\u7528\u306E 2 \u3064\u3092\u6301\u3061\u3001\u7247\u65B9\u304B\
    \u3089\u53D6\u308A\u51FA\u3057\u305F\u3089\u3082\u3046\u7247\u65B9\u304B\u3089\
    \u3082\u524A\u9664\u3059\u308B\n    ErasablePriorityQueue<int> max_q;\n    ErasablePriorityQueue<int,\
    \ std::greater<int>> min_q;\n    for (int i = 0; i < n; i++) {\n        int x;\n\
    \        std::cin >> x;\n        max_q.push(x);\n        min_q.push(x);\n    }\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int x;\n            std::cin >> x;\n            max_q.push(x);\n\
    \            min_q.push(x);\n        } else if (t == 1) {\n            int x =\
    \ min_q.top();\n            min_q.pop();\n            max_q.erase(x);\n      \
    \      std::cout << x << '\\n';\n        } else {\n            int x = max_q.top();\n\
    \            max_q.pop();\n            min_q.erase(x);\n            std::cout\
    \ << x << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <functional>\n#include <iostream>\n\n#include \"../../src/data_structures/erasable-priority-queue.hpp\"\
    \n\nint main() {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    // \u6700\u5927\u5024\u7528\u3068\
    \u6700\u5C0F\u5024\u7528\u306E 2 \u3064\u3092\u6301\u3061\u3001\u7247\u65B9\u304B\
    \u3089\u53D6\u308A\u51FA\u3057\u305F\u3089\u3082\u3046\u7247\u65B9\u304B\u3089\
    \u3082\u524A\u9664\u3059\u308B\n    ErasablePriorityQueue<int> max_q;\n    ErasablePriorityQueue<int,\
    \ std::greater<int>> min_q;\n    for (int i = 0; i < n; i++) {\n        int x;\n\
    \        std::cin >> x;\n        max_q.push(x);\n        min_q.push(x);\n    }\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int x;\n            std::cin >> x;\n            max_q.push(x);\n\
    \            min_q.push(x);\n        } else if (t == 1) {\n            int x =\
    \ min_q.top();\n            min_q.pop();\n            max_q.erase(x);\n      \
    \      std::cout << x << '\\n';\n        } else {\n            int x = max_q.top();\n\
    \            max_q.pop();\n            min_q.erase(x);\n            std::cout\
    \ << x << '\\n';\n        }\n    }\n}\n"
  dependsOn:
  - src/data_structures/erasable-priority-queue.hpp
  isVerificationFile: true
  path: test/yosupo/double-ended-priority-queue.test.cpp
  requiredBy: []
  timestamp: '2026-10-15 07:35:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/double-ended-priority-queue.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/double-ended-priority-queue.test.cpp
- /verify/test/yosupo/double-ended-priority-queue.test.cpp.html
title: test/yosupo/double-ended-priority-queue.test.cpp
---
