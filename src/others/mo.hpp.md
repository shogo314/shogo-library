---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static-range-inversions-query.test.cpp
    title: test/yosupo/static-range-inversions-query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo's algorithm
    links: []
  bundledCode: "#line 2 \"src/others/mo.hpp\"\n\n/**\n * @file mo.hpp\n * @brief Mo's\
    \ algorithm\n */\n\n#include <vector>\n#include <array>\n#include <type_traits>\n\
    #include <algorithm>\n#include <cmath>\n\ntemplate <typename U, class ADD_LEFT,\
    \ class DELETE_LEFT, class ADD_RIGHT = ADD_LEFT, class DELETE_RIGHT = DELETE_LEFT>\n\
    struct Mo {\n   private:\n    int _n;\n    std::vector<std::array<int, 3>> lri;\n\
    \    U _e;\n    ADD_LEFT _add_left;\n    DELETE_LEFT _delete_left;\n    ADD_RIGHT\
    \ _add_right;\n    DELETE_RIGHT _delete_right;\n\n    static_assert(std::is_invocable_r_v<void,\
    \ ADD_LEFT, U&, int>, \"ADD_LEFT must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_LEFT, U&, int>, \"DELETE_LEFT must be callable with (U&, int)\");\n \
    \   static_assert(std::is_invocable_r_v<void, ADD_RIGHT, U&, int>, \"ADD_RIGHT\
    \ must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_RIGHT, U&, int>, \"DELETE_RIGHT must be callable with (U&, int)\");\n\
    \n   public:\n    Mo(int n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left,\n       const ADD_RIGHT& add_right,\n\
    \       const DELETE_RIGHT delete_right) : _n(n), lri(), _e(e), _add_left(add_left),\
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
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @file mo.hpp\n * @brief Mo's algorithm\n */\n\n#include\
    \ <vector>\n#include <array>\n#include <type_traits>\n#include <algorithm>\n#include\
    \ <cmath>\n\ntemplate <typename U, class ADD_LEFT, class DELETE_LEFT, class ADD_RIGHT\
    \ = ADD_LEFT, class DELETE_RIGHT = DELETE_LEFT>\nstruct Mo {\n   private:\n  \
    \  int _n;\n    std::vector<std::array<int, 3>> lri;\n    U _e;\n    ADD_LEFT\
    \ _add_left;\n    DELETE_LEFT _delete_left;\n    ADD_RIGHT _add_right;\n    DELETE_RIGHT\
    \ _delete_right;\n\n    static_assert(std::is_invocable_r_v<void, ADD_LEFT, U&,\
    \ int>, \"ADD_LEFT must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_LEFT, U&, int>, \"DELETE_LEFT must be callable with (U&, int)\");\n \
    \   static_assert(std::is_invocable_r_v<void, ADD_RIGHT, U&, int>, \"ADD_RIGHT\
    \ must be callable with (U&, int)\");\n    static_assert(std::is_invocable_r_v<void,\
    \ DELETE_RIGHT, U&, int>, \"DELETE_RIGHT must be callable with (U&, int)\");\n\
    \n   public:\n    Mo(int n,\n       const U& e,\n       const ADD_LEFT& add_left,\n\
    \       const DELETE_LEFT& delete_left,\n       const ADD_RIGHT& add_right,\n\
    \       const DELETE_RIGHT delete_right) : _n(n), lri(), _e(e), _add_left(add_left),\
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
    \        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/others/mo.hpp
  requiredBy: []
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static-range-inversions-query.test.cpp
documentation_of: src/others/mo.hpp
layout: document
redirect_from:
- /library/src/others/mo.hpp
- /library/src/others/mo.hpp.html
title: Mo's algorithm
---
