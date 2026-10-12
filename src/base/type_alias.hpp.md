---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/base/macro.hpp
    title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u578B\u306E\u5225\u540D"
    links: []
  bundledCode: "#line 2 \"src/base/type_alias.hpp\"\n\n/**\n * @file type_alias.hpp\n\
    \ * @brief \u578B\u306E\u5225\u540D\n */\n\n#include <bits/stdc++.h>\n\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\n\
    template <typename T>\nusing vec = std::vector<T>;\ntemplate <typename T, int\
    \ N>\nusing ary = std::array<T, N>;\nusing str = std::string;\nusing std::deque;\n\
    using std::list;\nusing std::map;\nusing std::multimap;\nusing std::multiset;\n\
    using std::pair;\nusing std::set;\n\nusing pl = pair<ll, ll>;\nusing pd = pair<ld,\
    \ ld>;\n\ntemplate <typename T>\nusing vv = vec<vec<T>>;\ntemplate <typename T>\n\
    using vvv = vec<vec<vec<T>>>;\nusing vl = vec<ll>;\nusing vvl = vv<ll>;\nusing\
    \ vvvl = vvv<ll>;\nusing vs = vec<str>;\nusing vc = vec<char>;\nusing vi = vec<int>;\n\
    using vb = vec<bool>;\n\ntemplate <typename T1, typename T2>\nusing vp = vec<pair<T1,\
    \ T2>>;\nusing vpl = vec<pl>;\nusing vvpl = vv<pl>;\nusing vd = vec<ld>;\nusing\
    \ vpd = vec<pd>;\n\ntemplate <int N>\nusing al = ary<ll, N>;\ntemplate <int N1,\
    \ int N2>\nusing aal = ary<ary<ll, N2>, N1>;\ntemplate <int N>\nusing val = vec<al<N>>;\n\
    template <int N>\nusing avl = ary<vl,N>;\n\ntemplate <typename T>\nusing ml =\
    \ std::map<ll, T>;\nusing mll = std::map<ll, ll>;\nusing sl = std::set<ll>;\n\
    using spl = set<pl>;\ntemplate <int N>\nusing sal = set<al<N>>;\ntemplate <int\
    \ N>\nusing asl = ary<sl,N>;\n\ntemplate <typename T>\nusing heap_max = std::priority_queue<T,\
    \ std::vector<T>, std::less<T>>;\ntemplate <typename T>\nusing heap_min = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n"
  code: "#pragma once\n\n/**\n * @file type_alias.hpp\n * @brief \u578B\u306E\u5225\
    \u540D\n */\n\n#include <bits/stdc++.h>\n\nusing ll = long long;\nusing ull =\
    \ unsigned long long;\nusing ld = long double;\n\ntemplate <typename T>\nusing\
    \ vec = std::vector<T>;\ntemplate <typename T, int N>\nusing ary = std::array<T,\
    \ N>;\nusing str = std::string;\nusing std::deque;\nusing std::list;\nusing std::map;\n\
    using std::multimap;\nusing std::multiset;\nusing std::pair;\nusing std::set;\n\
    \nusing pl = pair<ll, ll>;\nusing pd = pair<ld, ld>;\n\ntemplate <typename T>\n\
    using vv = vec<vec<T>>;\ntemplate <typename T>\nusing vvv = vec<vec<vec<T>>>;\n\
    using vl = vec<ll>;\nusing vvl = vv<ll>;\nusing vvvl = vvv<ll>;\nusing vs = vec<str>;\n\
    using vc = vec<char>;\nusing vi = vec<int>;\nusing vb = vec<bool>;\n\ntemplate\
    \ <typename T1, typename T2>\nusing vp = vec<pair<T1, T2>>;\nusing vpl = vec<pl>;\n\
    using vvpl = vv<pl>;\nusing vd = vec<ld>;\nusing vpd = vec<pd>;\n\ntemplate <int\
    \ N>\nusing al = ary<ll, N>;\ntemplate <int N1, int N2>\nusing aal = ary<ary<ll,\
    \ N2>, N1>;\ntemplate <int N>\nusing val = vec<al<N>>;\ntemplate <int N>\nusing\
    \ avl = ary<vl,N>;\n\ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing\
    \ mll = std::map<ll, ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate\
    \ <int N>\nusing sal = set<al<N>>;\ntemplate <int N>\nusing asl = ary<sl,N>;\n\
    \ntemplate <typename T>\nusing heap_max = std::priority_queue<T, std::vector<T>,\
    \ std::less<T>>;\ntemplate <typename T>\nusing heap_min = std::priority_queue<T,\
    \ std::vector<T>, std::greater<T>>;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base/type_alias.hpp
  requiredBy:
  - src/base/macro.hpp
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/base/type_alias.hpp
layout: document
redirect_from:
- /library/src/base/type_alias.hpp
- /library/src/base/type_alias.hpp.html
title: "\u578B\u306E\u5225\u540D"
---
