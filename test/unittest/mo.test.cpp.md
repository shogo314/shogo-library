---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/others/mo.hpp
    title: Mo's algorithm
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
  bundledCode: "#line 1 \"test/unittest/mo.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Mo \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u5DE6\u7AEF\u3068\u53F3\u7AEF\u3067\u5225\u306E\u64CD\
    \u4F5C\u3092\u6E21\u3059\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF (6 \u5F15\u6570\
    ) \u3092\u3001\u533A\u9593\u3092 deque \u306E\u307E\u307E\u6301\u3064\u5F62\u3067\
    \u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include <deque>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#line 2 \"src/others/mo.hpp\"\n\n/**\n * @file mo.hpp\n *\
    \ @brief Mo's algorithm\n */\n\n#line 9 \"src/others/mo.hpp\"\n#include <array>\n\
    #include <type_traits>\n#include <algorithm>\n#include <cmath>\n\ntemplate <typename\
    \ U, class ADD_LEFT, class DELETE_LEFT, class ADD_RIGHT = ADD_LEFT, class DELETE_RIGHT\
    \ = DELETE_LEFT>\nstruct Mo {\n   private:\n    int _n;\n    std::vector<std::array<int,\
    \ 3>> lri;\n    U _e;\n    ADD_LEFT _add_left;\n    DELETE_LEFT _delete_left;\n\
    \    ADD_RIGHT _add_right;\n    DELETE_RIGHT _delete_right;\n\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_LEFT, U&, int>, \"ADD_LEFT must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_LEFT, U&, int>, \"DELETE_LEFT must be callable with (U&, int)\");\n \
    \   static_assert(std::is_invocable_r_v<void, ADD_RIGHT, U&, int>, \"ADD_RIGHT\
    \ must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_RIGHT, U&, int>, \"DELETE_RIGHT must be callable with (U&, int)\");\n\
    \n   public:\n    Mo(int n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left,\n       const ADD_RIGHT& add_right,\n\
    \       const DELETE_RIGHT& delete_right) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_right), _delete_right(delete_right)\
    \ {}\n    Mo(int n,\n       const U& e,\n       const ADD_LEFT& add_left,\n  \
    \     const DELETE_LEFT& delete_left) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_left), _delete_right(delete_left)\
    \ {}\n    void query(int l, int r) {\n        lri.push_back({l, r, (int)lri.size()});\n\
    \    }\n    template <typename T, class F>\n    std::vector<T> solve(const F&\
    \ f) {\n        static_assert(std::is_invocable_r_v<T, F, U&>, \"The function\
    \ passed to solve must be callable with (U&) and return T\");\n        \n    \
    \    const int w = std::max<int>(1, 1.0 * _n / std::max<double>(1.0, std::sqrt(lri.size()\
    \ * 2.0 / 3.0)));\n        std::sort(lri.begin(), lri.end(), [=](const std::array<int,\
    \ 3>& a, const std::array<int, 3>& b) {\n            int aw = a[0] / w;\n    \
    \        int bw = b[0] / w;\n            if (aw != bw) return aw < bw;\n     \
    \       if (aw & 1) return a[1] > b[1];\n            return a[1] < b[1];\n   \
    \     });\n        std::vector<T> res(lri.size());\n        long long tmpl = 0,\
    \ tmpr = 0;\n        U tmp = _e;\n        for (auto [l, r, i] : lri) {\n     \
    \       while (tmpl > l) {\n                tmpl--;\n                _add_left(tmp,\
    \ tmpl);\n            }\n            while (tmpr < r) {\n                _add_right(tmp,\
    \ tmpr);\n                tmpr++;\n            }\n            while (tmpl < l)\
    \ {\n                _delete_left(tmp, tmpl);\n                tmpl++;\n     \
    \       }\n            while (tmpr > r) {\n                tmpr--;\n         \
    \       _delete_right(tmp, tmpr);\n            }\n            res[i] = f(tmp);\n\
    \        }\n        return res;\n    }\n};\n#line 13 \"test/unittest/mo.test.cpp\"\
    \n\n// \u533A\u9593\u306E\u8981\u7D20\u3092\u9806\u756A\u8FBC\u307F\u3067\u533A\
    \u5225\u3059\u308B\u30CF\u30C3\u30B7\u30E5\nlong long ordered_hash(const std::deque<int>&\
    \ d) {\n    long long h = 0;\n    for (int x : d) h = (h * 1000003 + x + 1) %\
    \ 998244353;\n    return h;\n}\n\nint main() {\n    std::mt19937 rng(314);\n \
    \   bool ok = true;\n    for (int rep = 0; rep < 500 && ok; rep++) {\n       \
    \ int n = rng() % 30 + 1;\n        std::vector<int> a(n);\n        for (int& x\
    \ : a) x = rng() % 1000;\n        // \u5DE6\u306B\u8DB3\u3059\u3068\u304D\u306F\
    \u5148\u982D\u3001\u53F3\u306B\u8DB3\u3059\u3068\u304D\u306F\u672B\u5C3E\u306B\
    \u5165\u308C\u308B\u3002\u5DE6\u53F3\u3092\u53D6\u308A\u9055\u3048\u308B\u3068\
    \u9806\u756A\u304C\u5D29\u308C\u308B\n        auto add_left = [&](std::deque<int>&\
    \ d, int i) { d.push_front(a[i]); };\n        auto delete_left = [&](std::deque<int>&\
    \ d, int i) {\n            if (d.front() != a[i]) ok = false;\n            d.pop_front();\n\
    \        };\n        auto add_right = [&](std::deque<int>& d, int i) { d.push_back(a[i]);\
    \ };\n        auto delete_right = [&](std::deque<int>& d, int i) {\n         \
    \   if (d.back() != a[i]) ok = false;\n            d.pop_back();\n        };\n\
    \        Mo mo(n, std::deque<int>(), add_left, delete_left, add_right, delete_right);\n\
    \        int q = rng() % 30 + 1;\n        std::vector<std::pair<int, int>> qs(q);\n\
    \        for (auto& [l, r] : qs) {\n            l = rng() % (n + 1);\n       \
    \     r = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n        \
    \    mo.query(l, r);\n        }\n        auto res = mo.solve<long long>([](std::deque<int>&\
    \ d) { return ordered_hash(d); });\n        for (int i = 0; i < q; i++) {\n  \
    \          auto [l, r] = qs[i];\n            std::deque<int> expect(a.begin()\
    \ + l, a.begin() + r);\n            if (res[i] != ordered_hash(expect)) ok = false;\n\
    \        }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n  \
    \  else std::cerr << \"failed\" << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A\"\
    \n\n// Mo \u3092\u611A\u76F4\u306A\u5B9F\u88C5\u3068\u30E9\u30F3\u30C0\u30E0\u306B\
    \u6BD4\u8F03\u3059\u308B\n// \u5DE6\u7AEF\u3068\u53F3\u7AEF\u3067\u5225\u306E\u64CD\
    \u4F5C\u3092\u6E21\u3059\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF (6 \u5F15\u6570\
    ) \u3092\u3001\u533A\u9593\u3092 deque \u306E\u307E\u307E\u6301\u3064\u5F62\u3067\
    \u78BA\u304B\u3081\u308B\n// \u554F\u984C\u306E\u5165\u529B\u306F\u4F7F\u308F\u305A\
    \u3001\u3059\u3079\u3066\u4E00\u81F4\u3057\u305F\u3089 Hello World \u3092\u51FA\
    \u529B\u3059\u308B\n\n#include <deque>\n#include <iostream>\n#include <random>\n\
    #include <vector>\n\n#include \"../../src/others/mo.hpp\"\n\n// \u533A\u9593\u306E\
    \u8981\u7D20\u3092\u9806\u756A\u8FBC\u307F\u3067\u533A\u5225\u3059\u308B\u30CF\
    \u30C3\u30B7\u30E5\nlong long ordered_hash(const std::deque<int>& d) {\n    long\
    \ long h = 0;\n    for (int x : d) h = (h * 1000003 + x + 1) % 998244353;\n  \
    \  return h;\n}\n\nint main() {\n    std::mt19937 rng(314);\n    bool ok = true;\n\
    \    for (int rep = 0; rep < 500 && ok; rep++) {\n        int n = rng() % 30 +\
    \ 1;\n        std::vector<int> a(n);\n        for (int& x : a) x = rng() % 1000;\n\
    \        // \u5DE6\u306B\u8DB3\u3059\u3068\u304D\u306F\u5148\u982D\u3001\u53F3\
    \u306B\u8DB3\u3059\u3068\u304D\u306F\u672B\u5C3E\u306B\u5165\u308C\u308B\u3002\
    \u5DE6\u53F3\u3092\u53D6\u308A\u9055\u3048\u308B\u3068\u9806\u756A\u304C\u5D29\
    \u308C\u308B\n        auto add_left = [&](std::deque<int>& d, int i) { d.push_front(a[i]);\
    \ };\n        auto delete_left = [&](std::deque<int>& d, int i) {\n          \
    \  if (d.front() != a[i]) ok = false;\n            d.pop_front();\n        };\n\
    \        auto add_right = [&](std::deque<int>& d, int i) { d.push_back(a[i]);\
    \ };\n        auto delete_right = [&](std::deque<int>& d, int i) {\n         \
    \   if (d.back() != a[i]) ok = false;\n            d.pop_back();\n        };\n\
    \        Mo mo(n, std::deque<int>(), add_left, delete_left, add_right, delete_right);\n\
    \        int q = rng() % 30 + 1;\n        std::vector<std::pair<int, int>> qs(q);\n\
    \        for (auto& [l, r] : qs) {\n            l = rng() % (n + 1);\n       \
    \     r = rng() % (n + 1);\n            if (l > r) std::swap(l, r);\n        \
    \    mo.query(l, r);\n        }\n        auto res = mo.solve<long long>([](std::deque<int>&\
    \ d) { return ordered_hash(d); });\n        for (int i = 0; i < q; i++) {\n  \
    \          auto [l, r] = qs[i];\n            std::deque<int> expect(a.begin()\
    \ + l, a.begin() + r);\n            if (res[i] != ordered_hash(expect)) ok = false;\n\
    \        }\n    }\n    if (ok) std::cout << \"Hello World\" << std::endl;\n  \
    \  else std::cerr << \"failed\" << std::endl;\n}\n"
  dependsOn:
  - src/others/mo.hpp
  isVerificationFile: true
  path: test/unittest/mo.test.cpp
  requiredBy: []
  timestamp: '2026-10-13 06:02:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/unittest/mo.test.cpp
layout: document
redirect_from:
- /verify/test/unittest/mo.test.cpp
- /verify/test/unittest/mo.test.cpp.html
title: test/unittest/mo.test.cpp
---
