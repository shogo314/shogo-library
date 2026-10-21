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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/data_structure/static-range-inversions-query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#line 2 \"\
    src/others/mo.hpp\"\n\n/**\n * @file mo.hpp\n * @brief Mo's algorithm\n */\n\n\
    #line 9 \"src/others/mo.hpp\"\n#include <array>\n#include <cassert>\n#include\
    \ <cmath>\n#include <type_traits>\n#line 14 \"src/others/mo.hpp\"\n\ntemplate\
    \ <typename U, class ADD_LEFT, class DELETE_LEFT, class ADD_RIGHT = ADD_LEFT,\
    \ class DELETE_RIGHT = DELETE_LEFT>\nclass Mo {\n   private:\n    long long _n;\n\
    \    std::vector<std::array<long long, 3>> lri;\n    U _e;\n    ADD_LEFT _add_left;\n\
    \    DELETE_LEFT _delete_left;\n    ADD_RIGHT _add_right;\n    DELETE_RIGHT _delete_right;\n\
    \n    static_assert(std::is_invocable_r_v<void, ADD_LEFT, U&, long long>, \"ADD_LEFT\
    \ must be callable with (U&, long long)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_LEFT, U&, long long>, \"DELETE_LEFT must be callable with (U&, long long)\"\
    );\n    static_assert(std::is_invocable_r_v<void, ADD_RIGHT, U&, long long>, \"\
    ADD_RIGHT must be callable with (U&, long long)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_RIGHT, U&, long long>, \"DELETE_RIGHT must be callable with (U&, long\
    \ long)\");\n\n   public:\n    Mo(long long n,\n       const U& e,\n       const\
    \ ADD_LEFT& add_left,\n       const DELETE_LEFT& delete_left,\n       const ADD_RIGHT&\
    \ add_right,\n       const DELETE_RIGHT& delete_right) : _n(n), lri(), _e(e),\
    \ _add_left(add_left), _delete_left(delete_left), _add_right(add_right), _delete_right(delete_right)\
    \ {}\n    Mo(long long n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left) : _n(n), lri(), _e(e), _add_left(add_left),\
    \ _delete_left(delete_left), _add_right(add_left), _delete_right(delete_left)\
    \ {}\n    void query(long long l, long long r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        lri.push_back({l, r, static_cast<long long>(lri.size())});\n\
    \    }\n    template <typename T, class F>\n    std::vector<T> solve(const F&\
    \ f) {\n        static_assert(std::is_invocable_r_v<T, F, U&>, \"The function\
    \ passed to solve must be callable with (U&) and return T\");\n\n        const\
    \ long long w = std::max<long long>(1, 1.0 * _n / std::max<double>(1.0, std::sqrt(lri.size()\
    \ * 2.0 / 3.0)));\n        std::sort(lri.begin(), lri.end(), [=](const std::array<long\
    \ long, 3>& a, const std::array<long long, 3>& b) {\n            long long aw\
    \ = a[0] / w;\n            long long bw = b[0] / w;\n            if (aw != bw)\
    \ return aw < bw;\n            if (aw & 1) return a[1] > b[1];\n            return\
    \ a[1] < b[1];\n        });\n        std::vector<T> res(lri.size());\n       \
    \ long long tmpl = 0, tmpr = 0;\n        U tmp = _e;\n        for (auto [l, r,\
    \ i] : lri) {\n            while (tmpl > l) {\n                tmpl--;\n     \
    \           _add_left(tmp, tmpl);\n            }\n            while (tmpr < r)\
    \ {\n                _add_right(tmp, tmpr);\n                tmpr++;\n       \
    \     }\n            while (tmpl < l) {\n                _delete_left(tmp, tmpl);\n\
    \                tmpl++;\n            }\n            while (tmpr > r) {\n    \
    \            tmpr--;\n                _delete_right(tmp, tmpr);\n            }\n\
    \            res[i] = f(tmp);\n        }\n        return res;\n    }\n};\n#line\
    \ 8 \"test/yosupo/data_structure/static-range-inversions-query.test.cpp\"\n\n\
    int main() {\n    std::cin.tie(nullptr);\n    std::ios_base::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n    std::vector<int> a(n);\n    for (int&\
    \ x : a) std::cin >> x;\n    // \u5EA7\u6A19\u5727\u7E2E\n    std::vector<int>\
    \ xs = a;\n    std::sort(xs.begin(), xs.end());\n    xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    for (int& x : a) x = std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    int m = xs.size();\n\n    // \u533A\u9593\u5185\
    \u306E\u5024\u306E\u500B\u6570\u3092\u6301\u3064 Fenwick Tree\n    std::vector<int>\
    \ bit(m + 1);\n    int total = 0;\n    auto add = [&](int i, int v) {\n      \
    \  total += v;\n        for (i++; i <= m; i += i & -i) bit[i] += v;\n    };\n\
    \    auto count_less = [&](int i) {\n        int ret = 0;\n        for (; i >\
    \ 0; i -= i & -i) ret += bit[i];\n        return ret;\n    };\n    auto count_greater\
    \ = [&](int i) { return total - count_less(i + 1); };\n\n    Mo mo(n, 0LL, [&](long\
    \ long& inv, int i) { inv += count_less(a[i]); add(a[i], 1); }, [&](long long&\
    \ inv, int i) { add(a[i], -1); inv -= count_less(a[i]); }, [&](long long& inv,\
    \ int i) { inv += count_greater(a[i]); add(a[i], 1); }, [&](long long& inv, int\
    \ i) { add(a[i], -1); inv -= count_greater(a[i]); });\n    for (int i = 0; i <\
    \ q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        mo.query(l,\
    \ r);\n    }\n    for (long long ans : mo.solve<long long>([](long long& inv)\
    \ { return inv; })) {\n        std::cout << ans << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <vector>\n\n#include \"\
    ../../../src/others/mo.hpp\"\n\nint main() {\n    std::cin.tie(nullptr);\n   \
    \ std::ios_base::sync_with_stdio(false);\n    int n, q;\n    std::cin >> n >>\
    \ q;\n    std::vector<int> a(n);\n    for (int& x : a) std::cin >> x;\n    //\
    \ \u5EA7\u6A19\u5727\u7E2E\n    std::vector<int> xs = a;\n    std::sort(xs.begin(),\
    \ xs.end());\n    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n   \
    \ for (int& x : a) x = std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n\
    \    int m = xs.size();\n\n    // \u533A\u9593\u5185\u306E\u5024\u306E\u500B\u6570\
    \u3092\u6301\u3064 Fenwick Tree\n    std::vector<int> bit(m + 1);\n    int total\
    \ = 0;\n    auto add = [&](int i, int v) {\n        total += v;\n        for (i++;\
    \ i <= m; i += i & -i) bit[i] += v;\n    };\n    auto count_less = [&](int i)\
    \ {\n        int ret = 0;\n        for (; i > 0; i -= i & -i) ret += bit[i];\n\
    \        return ret;\n    };\n    auto count_greater = [&](int i) { return total\
    \ - count_less(i + 1); };\n\n    Mo mo(n, 0LL, [&](long long& inv, int i) { inv\
    \ += count_less(a[i]); add(a[i], 1); }, [&](long long& inv, int i) { add(a[i],\
    \ -1); inv -= count_less(a[i]); }, [&](long long& inv, int i) { inv += count_greater(a[i]);\
    \ add(a[i], 1); }, [&](long long& inv, int i) { add(a[i], -1); inv -= count_greater(a[i]);\
    \ });\n    for (int i = 0; i < q; i++) {\n        int l, r;\n        std::cin\
    \ >> l >> r;\n        mo.query(l, r);\n    }\n    for (long long ans : mo.solve<long\
    \ long>([](long long& inv) { return inv; })) {\n        std::cout << ans << '\\\
    n';\n    }\n}\n"
  dependsOn:
  - src/others/mo.hpp
  isVerificationFile: true
  path: test/yosupo/data_structure/static-range-inversions-query.test.cpp
  requiredBy: []
  timestamp: '2026-10-21 13:37:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/data_structure/static-range-inversions-query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/data_structure/static-range-inversions-query.test.cpp
- /verify/test/yosupo/data_structure/static-range-inversions-query.test.cpp.html
title: test/yosupo/data_structure/static-range-inversions-query.test.cpp
---
