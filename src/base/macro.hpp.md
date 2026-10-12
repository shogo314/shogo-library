---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/base/type_alias.hpp
    title: "\u578B\u306E\u5225\u540D"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
    links: []
  bundledCode: "#line 2 \"src/base/macro.hpp\"\n\n/**\n * @file macro.hpp\n * @brief\
    \ \u30DE\u30AF\u30ED (rep \u306A\u3069)\n */\n\n#line 2 \"src/base/type_alias.hpp\"\
    \n\n/**\n * @file type_alias.hpp\n * @brief \u578B\u306E\u5225\u540D\n */\n\n\
    #include <bits/stdc++.h>\n\nusing ll = long long;\nusing ull = unsigned long long;\n\
    using ld = long double;\n\ntemplate <typename T>\nusing vec = std::vector<T>;\n\
    template <typename T, int N>\nusing ary = std::array<T, N>;\nusing str = std::string;\n\
    using std::deque;\nusing std::list;\nusing std::map;\nusing std::multimap;\nusing\
    \ std::multiset;\nusing std::pair;\nusing std::set;\n\nusing pl = pair<ll, ll>;\n\
    using pd = pair<ld, ld>;\n\ntemplate <typename T>\nusing vv = vec<vec<T>>;\ntemplate\
    \ <typename T>\nusing vvv = vec<vec<vec<T>>>;\nusing vl = vec<ll>;\nusing vvl\
    \ = vv<ll>;\nusing vvvl = vvv<ll>;\nusing vs = vec<str>;\nusing vc = vec<char>;\n\
    using vi = vec<int>;\nusing vb = vec<bool>;\n\ntemplate <typename T1, typename\
    \ T2>\nusing vp = vec<pair<T1, T2>>;\nusing vpl = vec<pl>;\nusing vvpl = vv<pl>;\n\
    using vd = vec<ld>;\nusing vpd = vec<pd>;\n\ntemplate <int N>\nusing al = ary<ll,\
    \ N>;\ntemplate <int N1, int N2>\nusing aal = ary<ary<ll, N2>, N1>;\ntemplate\
    \ <int N>\nusing val = vec<al<N>>;\ntemplate <int N>\nusing avl = ary<vl,N>;\n\
    \ntemplate <typename T>\nusing ml = std::map<ll, T>;\nusing mll = std::map<ll,\
    \ ll>;\nusing sl = std::set<ll>;\nusing spl = set<pl>;\ntemplate <int N>\nusing\
    \ sal = set<al<N>>;\ntemplate <int N>\nusing asl = ary<sl,N>;\n\ntemplate <typename\
    \ T>\nusing heap_max = std::priority_queue<T, std::vector<T>, std::less<T>>;\n\
    template <typename T>\nusing heap_min = std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>>;\n#line 9 \"src/base/macro.hpp\"\n\n#pragma GCC target(\"avx2\"\
    )\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#define\
    \ all(obj) (obj).begin(), (obj).end()\n\n#define CONCAT_IMPL2(x, y) x##y\n#define\
    \ CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)\n#define UNIQUE_ID(base) CONCAT_IMPL(base,\
    \ __COUNTER__)\n\n#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME\n\n#define\
    \ rep4(i, a, n, t) for (long long i = static_cast<long long>(a), i##_loop_end\
    \ = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t); i <\
    \ i##_loop_end; i += i##_loop_step)\n#define rep3(i, a, n) for (long long i =\
    \ static_cast<long long>(a), i##_loop_end = static_cast<long long>(n); i < i##_loop_end;\
    \ ++i)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep1(n) rep2(UNIQUE_ID(loop_counter_),\
    \ n)\n#define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1,\
    \ i##_loop_end = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t);\
    \ i >= i##_loop_end; i -= i##_loop_step)\n#define repd3(i, a, n) for (long long\
    \ i = static_cast<long long>(n) - 1, i##_loop_end = static_cast<long long>(a);\
    \ i >= i##_loop_end; --i)\n#define repd2(i, n) repd3(i, 0, n)\n#define repd(...)\
    \ GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)\n\n#define rrep(i,\
    \ n) rep(i, 1, (n) + 1)\n#define rrepd(i, n) repd(i, 1, (n) + 1)\n\ninline void\
    \ scan(){}\ntemplate<class Head,class... Tail>\ninline void scan(Head&head,Tail&...\
    \ tail){std::cin>>head;scan(tail...);}\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)\n#define IN(a, x) a x; std::cin\
    \ >> x;\n#define CHAR(x) char x; std::cin >> x;\n#define VL(a,n) vl a(n); std::cin\
    \ >> a;\n#define AL(a,k) al<k> a; std::cin >> a;\n#define AAL(a,n,m) aal<n,m>\
    \ a; std::cin >> a;\n#define VC(a,n) vc a(n); std::cin >> a;\n#define VS(a,n)\
    \ vs a(n); std::cin >> a;\n#define VPL(a,n) vpl a(n); std::cin >> a;\n#define\
    \ VAL(a,n,k) val<k> a(n); std::cin >> a;\n#define VVL(a,n,m) vvl a(n,vl(m)); std::cin\
    \ >> a;\n#define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}\n\n#define NO std::cout\
    \ << \"NO\" << std::endl; return;\n#define YES std::cout << \"YES\" << std::endl;\
    \ return;\n#define No std::cout << \"No\" << std::endl; return;\n#define Yes std::cout\
    \ << \"Yes\" << std::endl; return;\n#define Takahashi std::cout << \"Takahashi\"\
    \ << std::endl; return;\n#define Aoki std::cout << \"Aoki\" << std::endl; return;\n"
  code: "#pragma once\n\n/**\n * @file macro.hpp\n * @brief \u30DE\u30AF\u30ED (rep\
    \ \u306A\u3069)\n */\n\n#include \"type_alias.hpp\"\n\n#pragma GCC target(\"avx2\"\
    )\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#define\
    \ all(obj) (obj).begin(), (obj).end()\n\n#define CONCAT_IMPL2(x, y) x##y\n#define\
    \ CONCAT_IMPL(x, y) CONCAT_IMPL2(x, y)\n#define UNIQUE_ID(base) CONCAT_IMPL(base,\
    \ __COUNTER__)\n\n#define GET_MACRO(_1, _2, _3, _4, NAME, ...) NAME\n\n#define\
    \ rep4(i, a, n, t) for (long long i = static_cast<long long>(a), i##_loop_end\
    \ = static_cast<long long>(n), i##_loop_step = static_cast<long long>(t); i <\
    \ i##_loop_end; i += i##_loop_step)\n#define rep3(i, a, n) for (long long i =\
    \ static_cast<long long>(a), i##_loop_end = static_cast<long long>(n); i < i##_loop_end;\
    \ ++i)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep1(n) rep2(UNIQUE_ID(loop_counter_),\
    \ n)\n#define rep(...) GET_MACRO(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)\n\
    \n#define repd4(i, a, n, t) for (long long i = static_cast<long long>(n) - 1,\
    \ i##_loop_end = static_cast<long long>(a), i##_loop_step = static_cast<long long>(t);\
    \ i >= i##_loop_end; i -= i##_loop_step)\n#define repd3(i, a, n) for (long long\
    \ i = static_cast<long long>(n) - 1, i##_loop_end = static_cast<long long>(a);\
    \ i >= i##_loop_end; --i)\n#define repd2(i, n) repd3(i, 0, n)\n#define repd(...)\
    \ GET_MACRO(__VA_ARGS__, repd4, repd3, repd2)(__VA_ARGS__)\n\n#define rrep(i,\
    \ n) rep(i, 1, (n) + 1)\n#define rrepd(i, n) repd(i, 1, (n) + 1)\n\ninline void\
    \ scan(){}\ntemplate<class Head,class... Tail>\ninline void scan(Head&head,Tail&...\
    \ tail){std::cin>>head;scan(tail...);}\n#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)\n\
    #define STR(...) str __VA_ARGS__;scan(__VA_ARGS__)\n#define IN(a, x) a x; std::cin\
    \ >> x;\n#define CHAR(x) char x; std::cin >> x;\n#define VL(a,n) vl a(n); std::cin\
    \ >> a;\n#define AL(a,k) al<k> a; std::cin >> a;\n#define AAL(a,n,m) aal<n,m>\
    \ a; std::cin >> a;\n#define VC(a,n) vc a(n); std::cin >> a;\n#define VS(a,n)\
    \ vs a(n); std::cin >> a;\n#define VPL(a,n) vpl a(n); std::cin >> a;\n#define\
    \ VAL(a,n,k) val<k> a(n); std::cin >> a;\n#define VVL(a,n,m) vvl a(n,vl(m)); std::cin\
    \ >> a;\n#define SL(a,n) sl a;{VL(b,n);a=sl(all(b));}\n\n#define NO std::cout\
    \ << \"NO\" << std::endl; return;\n#define YES std::cout << \"YES\" << std::endl;\
    \ return;\n#define No std::cout << \"No\" << std::endl; return;\n#define Yes std::cout\
    \ << \"Yes\" << std::endl; return;\n#define Takahashi std::cout << \"Takahashi\"\
    \ << std::endl; return;\n#define Aoki std::cout << \"Aoki\" << std::endl; return;\n"
  dependsOn:
  - src/base/type_alias.hpp
  isVerificationFile: false
  path: src/base/macro.hpp
  requiredBy: []
  timestamp: '2026-10-12 19:23:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/base/macro.hpp
layout: document
redirect_from:
- /library/src/base/macro.hpp
- /library/src/base/macro.hpp.html
title: "\u30DE\u30AF\u30ED (rep \u306A\u3069)"
---
